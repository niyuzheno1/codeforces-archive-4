#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class T> struct cLtraits_identity{
  using type = T;
}
;
template<class T> using cLtraits_try_make_signed =
  typename conditional<
    is_integral<T>::value,
    make_signed<T>,
    cLtraits_identity<T>
    >::type;
template <class S, class T> struct cLtraits_common_type{
  using tS = typename cLtraits_try_make_signed<S>::type;
  using tT = typename cLtraits_try_make_signed<T>::type;
  using type = typename common_type<tS,tT>::type;
}
;
template<class S, class T> inline auto min_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a <= (typename cLtraits_common_type<S,T>::type) b ? a : b;
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
int n;
int a[110];
int b[110];
int main(){
  int PiIOrLma;
  int AuJVIghY = rd_int();
  for(PiIOrLma=(0);PiIOrLma<(AuJVIghY);PiIOrLma++){
    int i;
    rd(n);
    {
      int djQeACzd;
      for(djQeACzd=(0);djQeACzd<(n);djQeACzd++){
        rd(a[djQeACzd]);
      }
    }
    for(i=(0);i<(105);i++){
      b[i] = 0;
    }
    for(i=(0);i<(n);i++){
      ++b[a[i]];
    }
    int VL854U43;
    int Yd8JT4OW;
    if(n==0){
      Yd8JT4OW = 0;
    }
    else{
      Yd8JT4OW = a[0];
      for(VL854U43=(1);VL854U43<(n);VL854U43++){
        Yd8JT4OW = min_L(Yd8JT4OW, a[VL854U43]);
      }
    }
    int u = Yd8JT4OW;
    wt_L(n-b[u]);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n, a[110], b[110];
// { 
//     REP(rd_int()){
//         rd(n, a(n));
//         rep(i, 105) b[i] = 0;
//         rep(i, n) ++b[a[i]];
//         int u = min(a(n));
//         wt(n-b[u]);
//     }
// }
