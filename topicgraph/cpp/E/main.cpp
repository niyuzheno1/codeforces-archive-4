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
int n;
int m;
int A[150010];
int B[150010];
long long es[150010];
long long vs[150010];
unionFind dsu;
set<int> s;
int main(){
  int i;
  wmem = memarr;
  rd(n);
  rd(m);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(m);PiIOrLma++){
      rd(A[PiIOrLma]);A[PiIOrLma] += (-1);
      rd(B[PiIOrLma]);B[PiIOrLma] += (-1);
    }
  }
  dsu.walloc(n+1);
  dsu.init(n+1);
  for(i=(0);i<(m);i++){
    dsu(A[i], B[i]);
  }
  for(i=(0);i<(n);i++){
    ++vs[dsu(i)];
    s.insert(dsu(i));
  }
  for(i=(0);i<(m);i++){
    ++es[dsu(A[i])];
  }
  bool flag = true;
  for(auto x: s){
    if(vs[x]*(vs[x]-1LL)/2LL != es[x]){
      flag = false;
    }
  }
  if(flag){
    wt_L("YES");
    wt_L('\n');
  }
  else{
    wt_L("NO");
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n, m, A[150010], B[];
// ll es[], vs[]; 
// unionFind dsu;
// set<int> s;
// {
//     rd(n, m, (A--,B--)(m));
//     dsu.walloc(n+1);
//     dsu.init(n+1);
//     rep(i, m) dsu(A[i], B[i]);
//     rep(i, n) ++vs[dsu(i)], s.insert(dsu(i));
//     rep(i, m) ++es[dsu(A[i])];
//     bool flag = true;
//     for(auto x: s){
//         if(vs[x]*(vs[x]-1LL)/2LL != es[x]){
//             flag = false;
//         }
//     }
//     wt(if[flag, "YES", "NO"]);
//     
//     
// }
