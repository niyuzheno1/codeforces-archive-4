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
template<class T> struct Heap{
  int size;
  T*val;
  void malloc(const int N){
    val = (T*) std::malloc(N*sizeof(T));
    size = 0;
  }
  void walloc(const int N, void **mem = &wmem){
    walloc1d(&val, N, mem);
    size = 0;
  }
  void free(){
    std::free(val);
  }
  void init(){
    size = 0;
  }
  void up(){
    int n = size - 1;
    int m;
    while(n){
      m = (n-1) / 2;
      if(val[m] <= val[n]){
        break;
      }
      swap(val[m], val[n]);
      n = m;
    }
  }
  void down(){
    int n = 0;
    int m;
    for(;;){
      m=2*n+1;
      if(m>=size){
        break;
      }
      if(m+1<size && val[m] > val[m+1]){
        m++;
      }
      if(val[m] >= val[n]){
        break;
      }
      swap(val[m], val[n]);
      n = m;
    }
  }
  T top(){
    return val[0];
  }
  T pop(){
    T res = val[0];
    size--;
    if(size > 0){
      val[0] = val[size];
      down();
    }
    return res;
  }
  T push(const T x){
    val[size++] = x;
    up();
    return x;
  }
}
;
int n;
long long a[200000+10];
int main(){
  int i;
  wmem = memarr;
  rd(n);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(n);PiIOrLma++){
      rd(a[PiIOrLma]);
    }
  }
  long long curval = 0;
  Heap<long long> h;
  h.walloc(200000+10);
  h.init();
  int cnt = 0;
  for(i=(0);i<(n);i++){
    if(a[i] + curval >= 0){
      h.push(a[i]);
      ++cnt;
      curval += a[i];
    }
    else{
      if(h.size == 0){
        continue;
      }
      if(a[i] > h.top()){
        curval -= h.top();
        h.pop();
        curval += a[i];
        h.push(a[i]);
      }
    }
  }
  wt_L(cnt);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n;
// ll a[2d5+10];
// { 
//     rd(n, a(n));
//     ll curval = 0;
//     Heap<ll> h;
//     h.walloc(2d5+10);
//     h.init();
//     int cnt = 0;
//     rep(i, n){
//         if(a[i] + curval >= 0){
//             h.push(a[i]); ++cnt;
//             curval += a[i];
//         }else{
//             if(h.size == 0) continue;
//             if(a[i] > h.top()){
//                 curval -= h.top();
//                 h.pop();
//                 curval += a[i];
//                 h.push(a[i]);
//             }
//         }
//     }
//     wt(cnt);
// }
