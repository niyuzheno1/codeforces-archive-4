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
  int bipartite(int res[] = NULL, void *mem = wmem){
    int i;
    int j;
    int k;
    int x;
    int*st;
    int sts;
    if(res==NULL){
      walloc1d(&res, N, &mem);
    }
    walloc1d(&st, N, &mem);
    for(i=(0);i<(N);i++){
      res[i] = -1;
    }
    for(x=(0);x<(N);x++){
      if(res[x]==-1){
        res[x] = 0;
        sts = 0;
        st[sts++] = x;
        while(sts){
          i = st[--sts];
          for(j=(0);j<(es[i]);j++){
            k = edge[i][j];
            if(res[k]==-1){
              res[k] = 1 - res[i];
              st[sts++] = k;
            }
            if(res[i] + res[k] != 1){
              return 0;
            }
          }
        }
      }
    }
    return 1;
  }
}
;
int n;
int m;
int A[100000+10];
int B[100000+10];
int esz;
int res[100000+10];
vector<int> p;
vector<int> a;
void add_edge(int x, int y){
  arrInsert(esz, esz, A, x, B, y);
}
graph g;
int main(){
  wmem = memarr;
  rd(n);
  rd(esz);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(esz);PiIOrLma++){
      rd(A[PiIOrLma]);A[PiIOrLma] += (-1);
      rd(B[PiIOrLma]);B[PiIOrLma] += (-1);
    }
  }
  g.setEdge(n, esz, A, B);
  if(g.bipartite(res) == 0){
    wt_L(-1);
    wt_L('\n');
    exit(0);
  }
  else{
    int i;
    for(i=(0);i<(n);i++){
      if(res[i] == 0){
        p.push_back(i+1);
      }
      else{
        a.push_back(i+1);
      }
    }
    wt_L(p.size());
    wt_L('\n');
    {
      int Z8lEHcvz;
      if(p.size()==0){
        wt_L('\n');
      }
      else{
        for(Z8lEHcvz=(0);Z8lEHcvz<(p.size()-1);Z8lEHcvz++){
          wt_L(p[Z8lEHcvz]);
          wt_L(' ');
        }
        wt_L(p[Z8lEHcvz]);
        wt_L('\n');
      }
    }
    wt_L(a.size());
    wt_L('\n');
    {
      int C3F7XFP2;
      if(a.size()==0){
        wt_L('\n');
      }
      else{
        for(C3F7XFP2=(0);C3F7XFP2<(a.size()-1);C3F7XFP2++){
          wt_L(a[C3F7XFP2]);
          wt_L(' ');
        }
        wt_L(a[C3F7XFP2]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n, m;
// int A[1d5+10], B[], esz, res[];
// VI p, a;
// 
// void add_edge(int x, int y){
//     arrInsert(esz, esz, A, x, B, y);
// }
// graph g;
// 
// { 
//   rd(n, esz, (A--, B--)(esz));
//   g.setEdge(n, esz, A, B);
//   if(g.bipartite(res) == 0){
//       wt(-1);
//       exit(0);
//   }else{
//     rep(i, n){
//         if(res[i] == 0){
//             p.push_back(i+1);
//         }else{
//             a.push_back(i+1);
//         }
//     }
//     wt(p.size());
//     wt(p(p.size()));
//     wt(a.size());
//     wt(a(a.size()));
//   }
// }
