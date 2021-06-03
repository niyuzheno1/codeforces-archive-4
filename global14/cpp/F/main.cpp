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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
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
  void setEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
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
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
      edge[B[i]][es[B[i]]++] = A[i];
    }
  }
}
;
template<class T> struct wgraph{
  int N;
  int*es;
  int**edge;
  T**cost;
  graph g;
  void setEdge(int N__, int M, int A[], int B[], T C[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    walloc1d(&edge, N, mem);
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    walloc1d(&cost, N, mem);
    for(i=(0);i<(N);i++){
      walloc1d(&cost[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]] = B[i];
      edge[B[i]][es[B[i]]] = A[i];
      cost[A[i]][es[A[i]]++] = C[i];
      cost[B[i]][es[B[i]]++] = C[i];
    }
    g.N = N;
    g.es = es;
    g.edge = edge;
  }
}
;
long long n;
long long m ;
long long X;
long long a[300000+10];
long long ans[300000+10];
long long ahe;
long long asz;
long long ta[300000+10];
int A[300000+10];
int B[300000+10];
int C[300000+10];
wgraph<int> g;
void dfs(int x, int b, int id){
  int i;
  for(i=(0);i<(g.es[x]);i++){
    int y = g.edge[x][i];
    int yid = g.cost[x][i];
    if(y == b){
      continue;
    }
    dfs(y, x, yid);
  }
  if(id != -1){
    if(a[x] >= X){
      a[b] += a[x] - X;
      ans[ahe++] = id;
    }
    else{
      ans[asz--] = id;
    }
  }
}
int main(){
  int i;
  wmem = memarr;
  unionFind uf;
  rd(n);
  rd(m);
  rd(X);
  {
    int FJNsjZ7B;
    for(FJNsjZ7B=(0);FJNsjZ7B<(n);FJNsjZ7B++){
      rd(a[FJNsjZ7B]);
    }
  }
  {
    int Z8lEHcvz;
    for(Z8lEHcvz=(0);Z8lEHcvz<(m);Z8lEHcvz++){
      rd(A[Z8lEHcvz]);A[Z8lEHcvz] += (-1);
      rd(B[Z8lEHcvz]);B[Z8lEHcvz] += (-1);
    }
  }
  ahe = 0;
  asz = n-2;
  iota(C, C+m, 1);
  int C3F7XFP2;
  long long EZ0PmQmu;
  if(n==0){
    EZ0PmQmu = 0;
  }
  else{
    EZ0PmQmu = a[0];
    for(C3F7XFP2=(1);C3F7XFP2<(n);C3F7XFP2++){
      EZ0PmQmu += a[C3F7XFP2];
    }
  }
  long long ve = EZ0PmQmu;
  if(ve < (n-1)*X){
    wt_L("NO");
    wt_L('\n');
    exit(0);
  }
  uf.walloc(n);
  uf.init(n);
  int k = 0;
  for(i=(0);i<(m);i++){
    if(uf(A[i], B[i])){
      auto OUHHcm5g = ((A[i]));
      auto o8AZ1iEn = (( B[i]));
      auto Btiq50RC = (( C[i]));
      A[k]=OUHHcm5g;
      B[k]=o8AZ1iEn;
      C[k]=Btiq50RC;
      ++k;
    }
  }
  g.setEdge(n, n-1, A, B, C);
  dfs(0, -1, -1);
  wt_L("YES");
  wt_L('\n');
  for(i=(0);i<(n-1);i++){
    wt_L(ans[i]);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// ll n, m , X, a[3d5+10],  ans[], ahe, asz, ta[];
// int A[], B[],C[];
// wgraph<int> g;
// 
// void dfs(int x, int b, int id){
//     rep(i, g.es[x]){
//         int y = g.edge[x][i];
//         int yid = g.cost[x][i];
//         if(y == b) continue;
//         dfs(y, x, yid);
//     }
// 
//     if(id != -1){
//         if(a[x] >= X){
//             a[b] += a[x] - X;
//             ans[ahe++] = id;
//         }else{
//             ans[asz--] = id;
//         }
//     }
// }
// 
// 
// {
//     unionFind uf;
//     rd(n, m, X, a(n), (A--,B--)(m));
//     ahe = 0;
//     asz = n-2;
//     iota(C, C+m, 1);
//     ll ve = sum(a(n));
//     if(ve < (n-1)*X) wt("NO"), exit(0);
//     uf.walloc(n);
//     uf.init(n);
//     int k = 0;
//     rep(i, m) if(uf(A[i], B[i])) (A[k], B[k], C[k]) = (A[i], B[i], C[i]), ++k;
//     g.setEdge(n, n-1, A, B, C);
//     dfs(0, -1, -1);
//     wt("YES");
//     rep(i, n-1) wt(ans[i]);
// }