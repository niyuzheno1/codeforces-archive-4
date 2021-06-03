#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
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
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
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
inline void wt_L(unsigned x){
  int s=0;
  char f[10];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
inline void wt_L(long long x){
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
inline void wt_L(unsigned long long x){
  int s=0;
  char f[21];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
int WRITER_DOUBLE_DIGIT = 15;
inline int writerDigit_double(){
  return WRITER_DOUBLE_DIGIT;
}
inline void writerDigit_double(int d){
  WRITER_DOUBLE_DIGIT = d;
}
inline void wt_L(double x){
  const int d = WRITER_DOUBLE_DIGIT;
  int k;
  int r;
  double v;
  if(x!=x || (x==x+1 && x==2*x)){
    my_putchar('E');
    my_putchar('r');
    my_putchar('r');
    return;
  }
  if(x < 0){
    my_putchar('-');
    x = -x;
  }
  x += 0.5 * pow(0.1, d);
  r = 0;
  v = 1;
  while(x >= 10*v){
    v *= 10;
    r++;
  }
  while(r >= 0){
    r--;
    k = floor(x / v);
    if(k >= 10){
      k = 9;
    }
    if(k <= -1){
      k = 0;
    }
    x -= k * v;
    v *= 0.1;
    my_putchar(k + '0');
  }
  if(d > 0){
    my_putchar('.');
    v = 1;
    for(r=(0);r<(d);r++){
      v *= 0.1;
      k = floor(x / v);
      if(k >= 10){
        k = 9;
      }
      if(k <= -1){
        k = 0;
      }
      x -= k * v;
      my_putchar(k + '0');
    }
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    my_putchar(x[i]);
  }
}
struct unionFind{
  int*d;
  int N;
  int M;
  inline void malloc(const int n){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
  }
  inline void malloc(const int n, const int fg){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
    if(fg){
      init(n);
    }
  }
  inline void free(void){
    std::free(d);
  }
  inline void walloc(const int n, void **mem=&wmem){
    walloc1d(&d, n, mem);
    M = n;
  }
  inline void walloc(const int n, const int fg, void **mem=&wmem){
    walloc1d(&d, n, mem);
    M = n;
    if(fg){
      init(n);
    }
  }
  inline void init(const int n){
    int i;
    N = n;
    for(i=(0);i<(n);i++){
      d[i] = -1;
    }
  }
  inline void init(void){
    init(M);
  }
  inline int get(int a){
    int t = a;
    int k;
    while(d[t]>=0){
      t=d[t];
    }
    while(d[a]>=0){
      k=d[a];
      d[a]=t;
      a=k;
    }
    return a;
  }
  inline int connect(int a, int b){
    if(d[a]>=0){
      a=get(a);
    }
    if(d[b]>=0){
      b=get(b);
    }
    if(a==b){
      return 0;
    }
    if(d[a] < d[b]){
      d[a] += d[b];
      d[b] = a;
    }
    else{
      d[b] += d[a];
      d[a] = b;
    }
    return 1;
  }
  inline int operator()(int a){
    return get(a);
  }
  inline int operator()(int a, int b){
    return connect(a,b);
  }
  inline int& operator[](const int a){
    return d[a];
  }
  inline int size(int a){
    a = get(a);
    return -d[a];
  }
  inline int sizeList(int res[]){
    int i;
    int sz=0;
    for(i=(0);i<(N);i++){
      if(d[i]<0){
        res[sz++] = -d[i];
      }
    }
    return sz;
  }
}
;
struct graph{
  int N;
  int*es;
  int**edge;
  void setDirectEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    walloc1d(&edge[0], M, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
    }
  }
}
;
const int dbg = 0;
int totalcases;
int n;
int k;
int m;
int w[5000+10];
int u[5000+10];
int A[5000+10];
int B[5000+10];
int marked[5000+10];
int backmarked[5000+10];
int ans[5000+10];
int asz;
int rsz;
int in[5000+10];
int out[5000+10];
int vis[5000+10];
map<int, vector<int>> regions;
graph g;
int dep[5000+10];
int vx[5000+10];
int pa[5000+10];
void dfs(int x, int cdep, int par){
  int PiIOrLma;
  if(vis[x]){
    return;
  }
  vis[x] = 1;
  dep[x] = cdep;
  pa[x] = par;
  for(PiIOrLma=(0);PiIOrLma<(g.es[x]);PiIOrLma++){
    auto&i = g.edge[x][PiIOrLma];
    dfs(i, cdep+1, x);
  }
}
bool mark(int x){
  if(x == -1){
    return false;
  }
  return marked[x] || backmarked[x];
}
int main(){
  int tcases;
  wmem = memarr;
  rd(totalcases);
  for(tcases=(0);tcases<(totalcases);tcases++){
    int Q7E_c5bj, i, xkgQFmt1;
    if(dbg){
      wt_L("Case ");
      wt_L(' ');
      wt_L(tcases);
      wt_L(' ');
      wt_L(":");
      wt_L('\n');
    }
    rsz =0;
    asz = 0;
    memset(vis,0, sizeof(vis));
    memset(pa, 0, sizeof(pa));
    memset(vx, 0, sizeof(vx));
    memset(w, 0, sizeof(w));
    memset(u, 0, sizeof(u));
    memset(vx, 0, sizeof(vx));
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    memset(ans, 0, sizeof(ans));
    memset(marked, 0, sizeof(marked));
    memset(backmarked, 0, sizeof(backmarked));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    memset(dep, 0, sizeof(dep));
    regions.clear();
    rd(n);
    {
      int Z8lEHcvz;
      for(Z8lEHcvz=(0);Z8lEHcvz<(n);Z8lEHcvz++){
        rd(w[Z8lEHcvz]);
      }
    }
    rd(k);
    {
      int C3F7XFP2;
      for(C3F7XFP2=(0);C3F7XFP2<(k);C3F7XFP2++){
        rd(u[C3F7XFP2]);u[C3F7XFP2] += (-1);
      }
    }
    rd(m);
    {
      int VL854U43;
      for(VL854U43=(0);VL854U43<(m);VL854U43++){
        rd(A[VL854U43]);A[VL854U43] += (-1);
        rd(B[VL854U43]);B[VL854U43] += (-1);
      }
    }
    g.setDirectEdge(n, m, A, B);
    for(i=(0);i<(m);i++){
      ++out[A[i]];
      ++in[B[i]];
    }
    dfs(0, 0, -1);
    for(i=(0);i<(k);i++){
      marked[u[i]] = 1;
    }
    for(i=(0);i<(n);i++){
      vx[i] = i;
    }
    sortA_L(n, dep, vx);
    for(Q7E_c5bj=(0);Q7E_c5bj<(n);Q7E_c5bj++){
      auto&i = vx[Q7E_c5bj];
      if(pa[i] != -1 && in[i] == 1 && out[i] == 1 && out[pa[i]] != 1 && !mark(i) ){
        backmarked[i] = 1;
      }
    }
    for(i=(0);i<(n);i++){
      if((in[i] != 1 || out[i] != 1) && !mark(i)){
        backmarked[i] = 1;
      }
    }
    for(i=(0);i<(n);i++){
      if(mark(i)){
        regions[i].push_back(i);
      }
    }
    for(xkgQFmt1=(0);xkgQFmt1<(n);xkgQFmt1++){
      auto&i = vx[xkgQFmt1];
      if(pa[i] != -1 && in[i] == 1 && out[i] == 1){
        if(mark(i)){
          continue;
        }
        int u = i;
        int prev = -1;
        while(!mark(prev) && out[u] == 1){
          prev = u;
          u = pa[u];
        }
        pa[u] = prev;
        if(prev != -1 && !mark(prev)){
          backmarked[prev] = 1;
        }
        regions[prev].push_back(i);
      }
    }
    for(i=(0);i<(n);i++){
      if(backmarked[i]){
        ans[asz++] = i;
      }
    }
    for(i=(0);i<(asz);i++){
      ++ans[i];
    }
    wt_L(asz);
    wt_L(' ');
    {
      int cq90pge_;
      if(asz==0){
        wt_L('\n');
      }
      else{
        for(cq90pge_=(0);cq90pge_<(asz-1);cq90pge_++){
          wt_L(ans[cq90pge_]);
          wt_L(' ');
        }
        wt_L(ans[cq90pge_]);
        wt_L('\n');
      }
    }
    wt_L(regions.size());
    wt_L('\n');
    for(auto & x : regions){
      vector<int>& y = x.second;
      asz = 0;
      for(i=(0);i<(y.size());i++){
        ans[asz++] = y[i]+1;
      }
      wt_L(asz);
      wt_L(' ');
      {
        int CJfDDKIC;
        if(asz==0){
          wt_L('\n');
        }
        else{
          for(CJfDDKIC=(0);CJfDDKIC<(asz-1);CJfDDKIC++){
            wt_L(ans[CJfDDKIC]);
            wt_L(' ');
          }
          wt_L(ans[CJfDDKIC]);
          wt_L('\n');
        }
      }
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// const int dbg = 0;
// int totalcases, n, k, m;
// int w[5d3+10], u[], A[], B[], marked[], backmarked[], ans[], asz, rsz, in[], out[], vis[];
// map<int, VI> regions;
// graph g;
// int dep[], vx[], pa[];
// void dfs(int x, int cdep, int par){
//     if(vis[x]) return;
//     vis[x] = 1;
//     dep[x] = cdep;// update here when you are going into a subtree/graph
//     pa[x] = par;
//     rep[g.edge[x]](i, g.es[x]) dfs(i, cdep+1, x);
//     // update here when you are going out of a subtree/graph
// }
// bool mark(int x){
//     if(x == -1) return false;
//     return marked[x] || backmarked[x];
// }
// 
// { 
//     rd(totalcases);
//     rep(tcases, totalcases){
//         if(dbg) wt("Case ", tcases, ":")
//         // unionFind dsu;
//         // dsu.walloc(n+1);
//         // dsu.init(n+1);
//         rsz =0;
//         asz = 0;
//         memset(vis,0, sizeof(vis));
//         memset(pa, 0, sizeof(pa)); memset(vx, 0, sizeof(vx));
//         memset(w, 0, sizeof(w)); memset(u, 0, sizeof(u));  memset(vx, 0, sizeof(vx));
//         memset(A, 0, sizeof(A)); memset(B, 0, sizeof(B)); memset(ans, 0, sizeof(ans));
//         memset(marked, 0, sizeof(marked)); memset(backmarked, 0, sizeof(backmarked));
//         memset(in, 0, sizeof(in)); memset(out, 0, sizeof(out));memset(dep, 0, sizeof(dep));
//         regions.clear();
//         rd(n, w(n), k, (u--)(k), m, (A--,B--)(m) );
//         
//         g.setDirectEdge(n, m, A, B);
//         rep(i, m) ++out[A[i]], ++in[B[i]];
//         dfs(0, 0, -1);
//         rep(i, k) marked[u[i]] = 1;
//         rep(i, n) vx[i] = i;
//         sortA(n, dep, vx);
//         rep[vx](i, n) if(pa[i] != -1 && in[i] == 1 && out[i] == 1 && out[pa[i]] != 1 && !mark(i) ) backmarked[i] = 1; /**&& !mark(par(i)) */
//         rep(i,n) if((in[i] != 1 || out[i] != 1) && !mark(i)) backmarked[i] = 1;
//         rep(i, n) if(mark(i)) regions[i].push_back(i);
//         rep[vx](i, n) {
//             if(pa[i] != -1 && in[i] == 1 && out[i] == 1){
//                 if(mark(i)) continue;
//                 int u = i, prev = -1;
//                 while(!mark(prev) && out[u] == 1){
//                     prev = u;
//                     u = pa[u];
//                 }
//                 pa[u] = prev;
//                 if(prev != -1 && !mark(prev)){
//                     backmarked[prev] = 1;
//                 }
//                 regions[prev].push_back(i);
//             }
//         }
//         rep(i, n) if(backmarked[i]) ans[asz++] = i;
//         rep(i, asz) ++ans[i];
//         wt(asz, ans(asz));
//         wt(regions.size());
//         for(auto & x : regions){
//             VI & y = x.second;
//             asz = 0;
//             rep(i, y.size()){
//                 ans[asz++] = y[i]+1;
//             }
//             wt(asz, ans(asz));
//         }
//     }
// }