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
      fwrite_unlocked(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar_unlocked(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite_unlocked(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a){
  my_putchar_unlocked(a);
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
    my_putchar_unlocked('-');
  }
  while(s--){
    my_putchar_unlocked(f[s]+'0');
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
#include "random_array.hpp"
int A[5000+10];
int B[5000+10];
int C[5000+10];
int esz;
int in[5000+10];
int out[5000+10];
int w[5000+10];
int u[5000+10];
int k;
int curv = 1;
vector<int> prevx;
vector<int> curx;
void generatecase(){
  int i;
  esz = 0;
  memset(in, 0, sizeof(in));
  memset(out, 0, sizeof(out));
  memset(A, 0, sizeof(A));
  memset(B, 0, sizeof(B));
  memset(C, 0, sizeof(C));
  memset(w, 0, sizeof(w));
  memset(u, 0, sizeof(u));
  k = 0;
  curx.clear();
  prevx.clear();
  curv = 1;
  int n = 10;
  int m = n;
  for(i=(0);i<(1000000000);i++){
    int j;
    if(n == 0){
      break;
    }
    int delta = rnd.next(1,n);
    for(j=(0);j<(delta);j++){
      curx.push_back(j + curv);
    }
    for(i=(0);i<(prevx.size());i++){
      for(j=(0);j<(curx.size());j++){
        int X = prevx[i];
        int Y = curx[j];
        if( rnd.next(1,10) < 5){
          arrInsert(esz, esz, A, X, B, Y);
        }
      }
    }
    prevx = curx;
    curx.clear();
    n -= delta;
    curv += delta;
  }
  int source = 0;
  int sink = m+1;
  for(i=(0);i<(esz);i++){
    ++in[B[i]];
  }
  for(i=(0);i<(esz);i++){
    ++out[A[i]];
  }
  for(i=(1);i<(m+1);i++){
    if(in[i] == 0){
      arrInsert(esz, esz, A, source, B, i);
    }
    if(out[i] == 0){
      arrInsert(esz, esz, A, i, B, sink);
    }
  }
  sortA_L(esz, A, B);
  for(i=(0);i<(esz);i++){
    ++A[i];
    ++B[i];
  }
  n = 0;
  for(i=(0);i<(esz);i++){
    chmax(n, A[i]);
    chmax(n, B[i]);
  }
  for(i=(0);i<(n);i++){
    w[i] = rnd.next(1, 5000);
  }
  for(i=(0);i<(n);i++){
    if(rnd.next(1, 10) < 5){
      u[k++] = i+1;
    }
  }
  wt_L(n);
  wt_L(' ');
  {
    int WpmOCj1U;
    if(n==0){
      wt_L('\n');
    }
    else{
      for(WpmOCj1U=(0);WpmOCj1U<(n-1);WpmOCj1U++){
        wt_L(w[WpmOCj1U]);
        wt_L(' ');
      }
      wt_L(w[WpmOCj1U]);
      wt_L('\n');
    }
  }
  wt_L(k);
  wt_L(' ');
  {
    int j4Ja_un4;
    if(k==0){
      wt_L('\n');
    }
    else{
      for(j4Ja_un4=(0);j4Ja_un4<(k-1);j4Ja_un4++){
        wt_L(u[j4Ja_un4]);
        wt_L(' ');
      }
      wt_L(u[j4Ja_un4]);
      wt_L('\n');
    }
  }
  wt_L(esz);
  wt_L('\n');
  for(i=(0);i<(esz);i++){
    wt_L(A[i]);
    wt_L(' ');
    wt_L(B[i]);
    wt_L('\n');
  }
}
int main(int argc, char ** argv){
  int gYUVurHt;
  wmem = memarr;
  registerGen(argc, argv, 1);
  int totalcases = 10;
  wt_L(totalcases);
  wt_L('\n');
  for(gYUVurHt=(0);gYUVurHt<(totalcases);gYUVurHt++){
    generatecase();
  }
}
// cLay version 20210405-1

// --- original code ---
// #include "random_array.hpp"
// //generator one
// //wt(rnd.next("one|two|three"));
// int A[5d3+10], B[], C[], esz;
// int in[], out[], w[], u[], k;
// int curv = 1;
// VI prevx, curx;
// 
// void generatecase(){
//     esz = 0;
//     memset(in, 0, sizeof(in)); memset(out, 0, sizeof(out)); memset(A, 0, sizeof(A)); memset(B, 0, sizeof(B)); memset(C, 0, sizeof(C));
//     memset(w, 0, sizeof(w));memset(u, 0, sizeof(u));
//     k = 0;
//     curx.clear(); prevx.clear();
//     curv = 1;
//     int n = 10;
//     int m = n;
//     rep(i, 1d9){
//         if(n == 0) break;
//         int delta = rnd.next(1,n);
//         // bug at intellisense 
//         rep(j, delta) curx.push_back(j + curv);
//         rep(i, prevx.size()){
//             rep(j, curx.size()){
//                 int X = prevx[i];
//                 int Y = curx[j];
//                 if( rnd.next(1,10) < 5){
//                     arrInsert(esz, esz, A, X, B, Y);
//                 }
//             }
//         }
//         prevx = curx;
//         curx.clear();
//         n -= delta;
//         curv += delta;
//     }
//     int source = 0, sink = m+1;
//     rep(i, esz) ++in[B[i]];
//     rep(i, esz) ++out[A[i]];
//     rep(i, 1, m+1) {
//         if(in[i] == 0){
//             arrInsert(esz, esz, A, source, B, i);
//         }
//         if(out[i] == 0){
//             arrInsert(esz, esz, A, i, B, sink);
//         }
//     }
//     sortA(esz, A, B);
//     rep(i, esz) ++A[i], ++B[i];
//     n = 0;    
//     rep(i, esz) n>?=A[i], n>?=B[i];
//     rep(i, n) w[i] = rnd.next(1, 5000);
//     rep(i, n) if(rnd.next(1, 10) < 5) u[k++] = i+1;
//     wt(n, w(n));
//     wt(k, u(k));
//     wt(esz);
//     rep(i, esz) wt(A[i], B[i]);
// }
// int main(int argc, char ** argv){
//     registerGen(argc, argv, 1);
//     int totalcases = 10;
//     wt(totalcases);
//     rep(totalcases){
//         generatecase();
//     }   
// }
