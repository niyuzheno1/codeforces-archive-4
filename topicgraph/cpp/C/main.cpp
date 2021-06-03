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
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
}
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
int n;
int m;
int A[500000+10];
int B[500000+10];
int esz;
int vis[1000000+10];
int osz;
int a[1000000+10];
int ans[1000000+10];
void add_edge(int x, int y){
  arrInsert(esz, esz, A, x, B, y);
}
graph g;
int dfs(int x){
  int PiIOrLma;
  if(vis[x]){
    return 0;
  }
  a[osz++] = x;
  vis[x] = 1;
  int ret = 0;
  if(x >= n){
    ret = 0;
  }
  else{
    ret = 1;
  }
  for(PiIOrLma=(0);PiIOrLma<(g.es[x]);PiIOrLma++){
    auto&i = g.edge[x][PiIOrLma];
    auto tmp = dfs(i);
    ret += tmp;
  }
  return ret;
}
int main(){
  int i;
  wmem = memarr;
  rd(n);
  rd(m);
  for(i=(0);i<(m);i++){
    int j;
    int gid = i + n;
    int k;
    rd(k);
    for(j=(0);j<(k);j++){
      int x;
      rd(x);
      --x;
      add_edge(x, gid);
    }
  }
  g.setEdge(n+m, esz, A, B);
  for(i=(0);i<(n);i++){
    if(!vis[i]){
      int j;
      osz = 0;
      int res = dfs(i);
      for(j=(0);j<(osz);j++){
        ans[a[j]] = res;
      }
    }
  }
  {
    int VL854U43;
    if(n==0){
      wt_L('\n');
    }
    else{
      for(VL854U43=(0);VL854U43<(n-1);VL854U43++){
        wt_L(ans[VL854U43]);
        wt_L(' ');
      }
      wt_L(ans[VL854U43]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n, m;
// int A[5d5+10], B[], esz, vis[1d6+10], osz, a[], ans[];
// 
// void add_edge(int x, int y){
//     arrInsert(esz, esz, A, x, B, y);
// }
// graph g;
// 
// 
// int dfs(int x){
//     if(vis[x]){
//         return 0;
//     }
//     a[osz++] = x;
//     vis[x] = 1;
//     int ret = 0;
//     if(x >= n) ret = 0;
//     else ret = 1;
//     rep[g.edge[x]](i, g.es[x]) {
//         auto tmp = dfs(i);
//         ret += tmp;
//     }
//     return ret;
// }
// 
// 
// { 
//     rd(n, m);
//     rep(i, m){
//         int gid = i + n;
//         int k; rd(k);
//         rep(j, k){
//             int x; rd(x);
//             --x;
//             add_edge(x, gid);
//         }
//     }
//     g.setEdge(n+m, esz, A, B);
//     rep(i, n){
//         if(!vis[i]){
//             osz = 0;
//             int res = dfs(i);
//             rep(j, osz) ans[a[j]] = res;
//         }
//     }
//     wt(ans(n));
// }
