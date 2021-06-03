#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned __int128)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
}
inline int my_getchar(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = my_getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void rd(__int128 &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = my_getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a){
  my_putchar(a);
}
inline void wt_L(__int128 x){
  int s=0;
  int m=0;
  char f[20];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
struct graph{
  int N;
  int*es;
  int**edge;
  void setEdgeRootedTree(int N__, int M, int A[], int B[], int root=0, int reorder=0, int cnv[] = NULL, void **mem = &wmem){
    int i;
    int j;
    int k;
    int*dist;
    int*q;
    int qs;
    int qe;
    int*ind;
    void*tmem;
    N = N__;
    tmem = ((char*)(*mem)) + (sizeof(int) * N + 15) + (sizeof(int*) * N + 15) + (sizeof(int) * M + 15 * N);
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], &tmem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
      edge[B[i]][es[B[i]]++] = A[i];
    }
    walloc1d(&dist, N, &tmem);
    walloc1d(&q, N, &tmem);
    walloc1d(&ind, N, &tmem);
    if(cnv==NULL){
      walloc1d(&cnv, N, &tmem);
    }
    for(i=(0);i<(N);i++){
      dist[i] = -1;
    }
    dist[root] = 0;
    qs = qe = 0;
    q[qe++] = root;
    while(qs < qe){
      i = q[qs++];
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(dist[k]==-1){
          dist[k] = dist[i] + 1;
          q[qe++] = k;
        }
      }
    }
    if(reorder == 0){
      for(i=(0);i<(N);i++){
        cnv[i] = i;
      }
      for(i=(0);i<(N);i++){
        ind[i] = i;
      }
    }
    else{
      for(i=(0);i<(N);i++){
        cnv[i] = q[i];
      }
      for(i=(0);i<(N);i++){
        ind[cnv[i]] = i;
      }
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      j = A[i];
      k = B[i];
      if(dist[j] > dist[k]){
        swap(j, k);
      }
      es[ind[j]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      j = A[i];
      k = B[i];
      if(dist[j] > dist[k]){
        swap(j, k);
      }
      j = ind[j];
      k = ind[k];
      edge[j][es[j]++] = k;
    }
  }
}
;
const __int128 is_query_G = -(1LL<<62);
struct line_G{
  __int128 m;
  __int128 b;
  mutable function<const line_G*()> succ;
}
;
bool operator<(const line_G& lhs, const line_G& rhs){
  if (rhs.b != is_query_G){
    return lhs.m < rhs.m;
  }
  const line_G* s = lhs.succ();
  if (!s){
    return 0;
  }
  __int128 x = rhs.m;
  return lhs.b - s->b < (s->m - lhs.m) * x;
}
struct dynamic_hull_max : public multiset<line_G>{
  const __int128 inf = LLONG_MAX;
  bool bad(void * yy){
    iterator * u = (iterator *)yy;
    iterator y = *u;
    auto z = next(y);
    if (y == begin()){
      if (z == end()){
        return 0;
      }
      return y->m == z->m && y->b <= z->b;
    }
    auto x = prev(y);
    if (z == end()){
      return y->m == x->m && y->b <= x->b;
    }
    __int128 v1 = (x->b - y->b);
    if (y->m == x->m){
      v1 = x->b > y->b ? inf : -inf;
    }
    else{
      v1 /= (y->m - x->m);
    }
    __int128 v2 = (y->b - z->b);
    if (z->m == y->m){
      v2 = y->b > z->b ? inf : -inf;
    }
    else{
      v2 /= (z->m - y->m);
    }
    return v1 >= v2;
  }
  void insert_line(__int128 m, __int128 b){
    auto y = insert({ m, b });
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad((void*)&y)){
      erase(y);
      return;
    }
    while (next(y) != end()){
      auto yy = next(y);
      if(bad((void*)&yy)){
        erase(next(y));
      }
      else{
        break;
      }
    }
    while (y != begin()){
      auto yy = prev(y);
      if(bad((void*)&yy)){
        erase(prev(y));
      }
      else{
        break;
      }
    }
  }
  __int128 eval(__int128 x){
    line_G tmp;
    tmp.b = is_query_G;
    tmp.m = x;
    auto l = *lower_bound(tmp);
    return l.m * x + l.b;
  }
}
;
struct dynamic_hull_min{
  dynamic_hull_max cht;
  void insert_line(__int128 m, __int128 b){
    cht.insert_line(-m, -b);
  }
  __int128 eval(__int128 x){
    return -cht.eval(x);
  }
}
;
int n;
int u[100000+10];
int v[100000+10];
__int128 a[100000+10];
__int128 b[100000+10];
__int128 dp[100000+10];
graph t;
dynamic_hull_min cht[100000+10];
int chtsz;
int dfs(int x){
  int PiIOrLma, i;
  if(t.es[x] == 0){
    cht[chtsz].insert_line(b[x],0);
    return chtsz++;
  }
  vector<int> chi;
  for(PiIOrLma=(0);PiIOrLma<(t.es[x]);PiIOrLma++){
    auto&i = t.edge[x][PiIOrLma];
    chi.push_back(dfs(i));
  }
  sort(chi.begin(), chi.end(), [&](const int &xx, const int& yy){
        return cht[xx].cht.size() > cht[yy].cht.size();
    } );
  for(i=(1);i<(chi.size());i++){
    for(auto & x : cht[chi[i]].cht){
      cht[chi[0]].cht.insert_line(x.m, x.b);
    }
  }
  dp[x] = cht[chi[0]].eval(a[x]);
  cht[chi[0]].insert_line(b[x], dp[x]);
  return chi[0];
}
int main(){
  wmem = memarr;
  rd(n);
  {
    int NN9wFlop;
    for(NN9wFlop=(0);NN9wFlop<(n);NN9wFlop++){
      rd(a[NN9wFlop]);
    }
  }
  {
    int zxsUT70f;
    for(zxsUT70f=(0);zxsUT70f<(n);zxsUT70f++){
      rd(b[zxsUT70f]);
    }
  }
  {
    int GN2MVvSr;
    for(GN2MVvSr=(0);GN2MVvSr<(n-1);GN2MVvSr++){
      rd(u[GN2MVvSr]);u[GN2MVvSr] += (-1);
      rd(v[GN2MVvSr]);v[GN2MVvSr] += (-1);
    }
  }
  t.setEdgeRootedTree(n, n-1, u, v);
  dfs(0);
  {
    int Btiq50RC;
    if(n==0){
      wt_L('\n');
    }
    else{
      for(Btiq50RC=(0);Btiq50RC<(n-1);Btiq50RC++){
        wt_L(dp[Btiq50RC]);
        wt_L(' ');
      }
      wt_L(dp[Btiq50RC]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n, u[1d5+10], v[];
// ll a[1d5+10], b[], dp[];
// graph t;
// dynamic_hull_min cht[1d5+10];
// int chtsz;
// int dfs(int x){
//     if(t.es[x] == 0){
//         cht[chtsz].insert_line(b[x],0);
//         return chtsz++;
//     }
//     // update here when you are going into a subtree/graph
//     vector<int> chi;
//     rep[t.edge[x]](i, t.es[x]) chi.push_back(dfs(i));
//     sort(chi.begin(), chi.end(), [&](const int &xx, const int& yy){
//         return cht[xx].cht.size() > cht[yy].cht.size();
//     } );
//     
//     rep(i, 1, chi.size()){
//         for(auto & x : cht[chi[i]].cht){
//             cht[chi[0]].cht.insert_line(x.m, x.b);
//         }
//     }
//     dp[x] = cht[chi[0]].eval(a[x]);
//     cht[chi[0]].insert_line(b[x], dp[x]);
//     return chi[0];
//     // update here when you are going out of a subtree/graph
// }
// 
// { 
//     rd(n, a(n), b(n), (u--,v--)(n-1));
//     t.setEdgeRootedTree(n, n-1, u, v);
//     dfs(0);
//     wt(dp(n));
// }
