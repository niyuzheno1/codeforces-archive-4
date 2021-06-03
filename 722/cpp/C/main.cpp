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
inline void rd(long long &x){
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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
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
int t;
graph g;
long long l[100000+10];
long long r[100000+10];
int u[100000+10];
int v[100000+10];
int n;
long long f[100000+10][2];
int vis[100000+10][2];
int ts;
long long dfs(int x, int w){
  int PiIOrLma;
  if(g.es[x] == 0){
    return 0;
  }
  int tg = (w==1)?w:0;
  if(vis[x][tg] == ts){
    return f[x][tg];
  }
  vis[x][tg] = ts;
  long long& ret = f[x][tg];
  ret = 0;
  long long curx = 0;
  if(w==1){
    curx =l[x];
  }
  else{
    curx =r[x];
  }
  for(PiIOrLma=(0);PiIOrLma<(g.es[x]);PiIOrLma++){
    int j;
    auto&i = g.edge[x][PiIOrLma];
    long long retmax = 0;
    for(j=(-1);j<(2);j++){
      if(j == 0){
        continue;
      }
      auto tmp = dfs(i, j);
      int cury = 0;
      if(j==1){
        cury =l[i];
      }
      else{
        cury =r[i];
      }
      chmax(retmax, tmp + abs(curx - cury));
    }
    ret += retmax;
  }
  return ret;
}
int main(){
  int Z8lEHcvz;
  wmem = memarr;
  int rbGYC8dh = rd_int();
  for(Z8lEHcvz=(0);Z8lEHcvz<(rbGYC8dh);Z8lEHcvz++){
    int i;
    ++ts;
    rd(n);
    {
      int EZ0PmQmu;
      for(EZ0PmQmu=(0);EZ0PmQmu<(n);EZ0PmQmu++){
        rd(l[EZ0PmQmu]);
        rd(r[EZ0PmQmu]);
      }
    }
    {
      int Yd8JT4OW;
      for(Yd8JT4OW=(0);Yd8JT4OW<(n-1);Yd8JT4OW++){
        rd(u[Yd8JT4OW]);u[Yd8JT4OW] += (-1);
        rd(v[Yd8JT4OW]);v[Yd8JT4OW] += (-1);
      }
    }
    g.setEdgeRootedTree(n,n-1, u, v);
    long long ans = 0;
    for(i=(-1);i<(2);i++){
      if(i == 0){
        continue;
      }
      chmax(ans, dfs(0, i));
    }
    wt_L(ans);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int t;
// graph g;
// ll l[1d5+10], r[];
// int  u[], v[], n;
// ll f[1d5+10][2];
// int vis[1d5+10][2], ts;
// 
// ll dfs(int x, int w){
//     if(g.es[x] == 0){
//         return 0;
//     }
//     int tg = (w==1)?w:0;
//     if(vis[x][tg] == ts) return f[x][tg];
//     vis[x][tg] = ts;
//     ll & ret = f[x][tg];
//     ret = 0;
//     ll curx = 0;
//     curx = if[w==1, l[x], r[x]];
//     rep[g.edge[x]](i, g.es[x]) {
//         ll retmax = 0;
//         rep(j,-1, 2){
//             if(j == 0) continue;
//             auto tmp = dfs(i, j);
//             int cury = 0;
//             cury = if[j==1, l[i], r[i]];
//             retmax >?= tmp + abs(curx - cury); 
//         }
//         ret += retmax;
//     }
//     return ret;
// }
// 
// 
// { 
//     REP(rd_int()){
//         ++ts;
//         rd(n, (l,r)(n), (u--,v--)(n-1));
//         g.setEdgeRootedTree(n,n-1, u, v);
//         ll ans = 0;
//         rep(i, -1, 2){
//             if(i == 0) continue;
//             ans >?= dfs(0, i);
//         }
//         wt(ans);
//     }
// }
