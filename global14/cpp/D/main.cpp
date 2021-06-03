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
int A[200000+40];
int B[200000+40];
int n;
int l;
int r;
int main(){
  int PiIOrLma;
  int AuJVIghY = rd_int();
  for(PiIOrLma=(0);PiIOrLma<(AuJVIghY);PiIOrLma++){
    int i;
    rd(n);
    rd(l);
    rd(r);
    for(i=(0);i<(n);i++){
      A[i] = B[i] = 0;
    }
    for(i=(0);i<(l);i++){
      ++A[rd_int()-1];
    }
    for(i=(0);i<(r);i++){
      ++B[rd_int()-1];
    }
    int ans = 0;
    for(i=(0);i<(n);i++){
      int k =min_L(A[i], B[i]);
      auto OUHHcm5g = (k);
      l-=OUHHcm5g;
      r-=OUHHcm5g;
      A[i]-=OUHHcm5g;
      B[i]-=OUHHcm5g;
    }
    for(i=(0);i<(n);i++){
      while(l > r && A[i] >= 2){
        ++ans;
        auto Y0H_suZr = (2);
        l-=Y0H_suZr;
        A[i]-=Y0H_suZr;
      }
    }
    for(i=(0);i<(n);i++){
      while(l < r && B[i] >= 2){
        ++ans;
        auto a3PBjchb = (2);
        r-=a3PBjchb;
        B[i]-=a3PBjchb;
      }
    }
    int k =min_L(l, r);
    auto xkgQFmt1 = (k);
    l-=xkgQFmt1;
    r-=xkgQFmt1;
    ans += k;
    ans += (l+r);
    wt_L(ans);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int A[2d5+40], B[], n, l, r;
// { 
//   REP(rd_int()){
//       rd(n, l, r);
//       rep(i, n) A[i] = B[i] = 0;
//       rep(i, l) ++A[rd_int()-1];
//       rep(i, r) ++B[rd_int()-1];
//       int ans = 0;
//       //match the same color and left and right
//       rep(i, n){ int k = min(A[i],B[i]);  (l, r, A[i], B[i]) -= k; }
//       //reorient the socks and match the color if we have l > r 
//       rep(i,n) while(l > r && A[i] >= 2) ++ans, (l, A[i]) -= 2;
//       rep(i,n) while(l < r && B[i] >= 2) ++ans, (r, B[i]) -= 2;
//       // recoloring the socks so that they match 
//       int k =  min(l, r);
//       (l,r) -= k;
//       ans += k;
//       //everything else
//       ans += (l+r);
//       wt(ans);
//   }
// }
