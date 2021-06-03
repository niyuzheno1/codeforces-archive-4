#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define MD (1000000007U)
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
void*wmem;
char memarr[96000000];
template<class S, class T> inline auto min_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a <= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
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
struct mint{
  static unsigned md;
  static unsigned W;
  static unsigned R;
  static unsigned Rinv;
  static unsigned mdninv;
  static unsigned RR;
  unsigned val;
  mint(){
    val=0;
  }
  mint(int a){
    val = mulR(a);
  }
  mint(unsigned a){
    val = mulR(a);
  }
  mint(long long a){
    val = mulR(a);
  }
  mint(unsigned long long a){
    val = mulR(a);
  }
  int get_inv(long long a, int md){
    long long t=a;
    long long s=md;
    long long u=1;
    long long v=0;
    long long e;
    while(s){
      e=t/s;
      t-=e*s;
      u-=e*v;
      swap(t,s);
      swap(u,v);
    }
    if(u<0){
      u+=md;
    }
    return u;
  }
  void setmod(unsigned m){
    int i;
    unsigned t;
    W = 32;
    md = m;
    R = (1ULL << W) % md;
    RR = (unsigned long long)R*R % md;
    switch(m){
      case 104857601:
      Rinv = 2560000;
      mdninv = 104857599;
      break;
      case 998244353:
      Rinv = 232013824;
      mdninv = 998244351;
      break;
      case 1000000007:
      Rinv = 518424770;
      mdninv = 2226617417U;
      break;
      case 1000000009:
      Rinv = 171601999;
      mdninv = 737024967;
      break;
      case 1004535809:
      Rinv = 234947584;
      mdninv = 1004535807;
      break;
      case 1007681537:
      Rinv = 236421376;
      mdninv = 1007681535;
      break;
      case 1012924417:
      Rinv = 238887936;
      mdninv = 1012924415;
      break;
      case 1045430273:
      Rinv = 254466304;
      mdninv = 1045430271;
      break;
      case 1051721729:
      Rinv = 257538304;
      mdninv = 1051721727;
      break;
      default:
      Rinv = get_inv(R, md);
      mdninv = 0;
      t = 0;
      for(i=(0);i<((int)W);i++){
        if(t%2==0){
          t+=md;
          mdninv |= (1U<<i);
        }
        t /= 2;
      }
    }
  }
  unsigned mulR(unsigned a){
    return (unsigned long long)a*R%md;
  }
  unsigned mulR(int a){
    if(a < 0){
      a = a%((int)md)+(int)md;
    }
    return mulR((unsigned)a);
  }
  unsigned mulR(unsigned long long a){
    return mulR((unsigned)(a%md));
  }
  unsigned mulR(long long a){
    a %= (int)md;
    if(a < 0){
      a += md;
    }
    return mulR((unsigned)a);
  }
  unsigned reduce(unsigned T){
    unsigned m = T * mdninv;
    unsigned t = (unsigned)((T + (unsigned long long)m*md) >> W);
    if(t >= md){
      t -= md;
    }
    return t;
  }
  unsigned reduce(unsigned long long T){
    unsigned m = (unsigned)T * mdninv;
    unsigned t = (unsigned)((T + (unsigned long long)m*md) >> W);
    if(t >= md){
      t -= md;
    }
    return t;
  }
  unsigned get(){
    return reduce(val);
  }
  inline mint &operator++(){
    (*this) += 1;
    return *this;
  }
  inline mint &operator--(){
    (*this) -= 1;
    return *this;
  }
  inline mint operator++(int a){
    mint res(*this);
    (*this) += 1;
    return res;
  }
  inline mint operator--(int a){
    mint res(*this);
    (*this) -= 1;
    return res;
  }
  mint &operator+=(mint a){
    val += a.val;
    if(val >= md){
      val -= md;
    }
    return *this;
  }
  mint &operator-=(mint a){
    if(val < a.val){
      val = val + md - a.val;
    }
    else{
      val -= a.val;
    }
    return *this;
  }
  mint &operator*=(mint a){
    val = reduce((unsigned long long)val*a.val);
    return *this;
  }
  mint &operator/=(mint a){
    return *this *= a.inverse();
  }
  mint operator+(mint a){
    return mint(*this)+=a;
  }
  mint operator-(mint a){
    return mint(*this)-=a;
  }
  mint operator*(mint a){
    return mint(*this)*=a;
  }
  mint operator/(mint a){
    return mint(*this)/=a;
  }
  mint operator+(int a){
    return mint(*this)+=mint(a);
  }
  mint operator-(int a){
    return mint(*this)-=mint(a);
  }
  mint operator*(int a){
    return mint(*this)*=mint(a);
  }
  mint operator/(int a){
    return mint(*this)/=mint(a);
  }
  mint operator+(long long a){
    return mint(*this)+=mint(a);
  }
  mint operator-(long long a){
    return mint(*this)-=mint(a);
  }
  mint operator*(long long a){
    return mint(*this)*=mint(a);
  }
  mint operator/(long long a){
    return mint(*this)/=mint(a);
  }
  mint operator-(void){
    mint res;
    if(val){
      res.val=md-val;
    }
    else{
      res.val=0;
    }
    return res;
  }
  operator bool(void){
    return val!=0;
  }
  operator int(void){
    return get();
  }
  operator long long(void){
    return get();
  }
  mint inverse(){
    int a = val;
    int b = md;
    int u = 1;
    int v = 0;
    int t;
    mint res;
    while(b){
      t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    if(u < 0){
      u += md;
    }
    res.val = (unsigned long long)u*RR % md;
    return res;
  }
  mint pw(unsigned long long b){
    mint a(*this);
    mint res;
    res.val = R;
    while(b){
      if(b&1){
        res *= a;
      }
      b >>= 1;
      a *= a;
    }
    return res;
  }
  bool operator==(int a){
    return mulR(a)==val;
  }
  bool operator!=(int a){
    return mulR(a)!=val;
  }
}
;
unsigned mint::md;
unsigned mint::W;
unsigned mint::R;
unsigned mint::Rinv;
unsigned mint::mdninv;
unsigned mint::RR;
mint operator+(int a, mint b){
  return mint(a)+=b;
}
mint operator-(int a, mint b){
  return mint(a)-=b;
}
mint operator*(int a, mint b){
  return mint(a)*=b;
}
mint operator/(int a, mint b){
  return mint(a)/=b;
}
mint operator+(long long a, mint b){
  return mint(a)+=b;
}
mint operator-(long long a, mint b){
  return mint(a)-=b;
}
mint operator*(long long a, mint b){
  return mint(a)*=b;
}
mint operator/(long long a, mint b){
  return mint(a)/=b;
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
inline void wt_L(mint x){
  int i;
  i = (int)x;
  wt_L(i);
}
int Prime_L(int N, int res[], void *mem=wmem){
  int i;
  int a;
  int b;
  int sz = 1;
  const int r = 23000;
  bool*isprime;
  int*sf;
  int ss = 1;
  walloc1d(&isprime, r, &mem);
  walloc1d(&sf, r, &mem);
  N /= 2;
  res[0] = 2;
  b =min_L(r, N);
  for(i=(1);i<(b);i++){
    isprime[i] = 1;
  }
  for(i=(1);i<(b);i++){
    if(isprime[i]){
      res[sz++] = 2*i+1;
      sf[ss] = 2*i*(i+1);
      if(sf[ss] < N){
        while(sf[ss] < r){
          isprime[sf[ss]] = 0;
          sf[ss] += res[ss];
        }
        ss++;
      }
    }
  }
  for(a=r; a<N; a+=r){
    b =min_L(a + r, N);
    isprime -= r;
    for(i=(a);i<(b);i++){
      isprime[i] = 1;
    }
    for(i=(1);i<(ss);i++){
      while(sf[i] < b){
        isprime[sf[i]] = 0;
        sf[i] += res[i];
      }
    }
    for(i=(a);i<(b);i++){
      if(isprime[i]){
        res[sz++] = 2*i+1;
      }
    }
  }
  return sz;
}
struct combination_mint{
  mint*fac;
  mint*ifac;
  void init(int n, void **mem = &wmem){
    int i;
    walloc1d(&fac, n, mem);
    walloc1d(&ifac, n, mem);
    fac[0] = 1;
    for(i=(1);i<(n);i++){
      fac[i] = fac[i-1] * i;
    }
    ifac[n-1] = 1 / fac[n-1];
    for(i=n-2;i>=0;i--){
      ifac[i] = ifac[i+1] * (i+1);
    }
  }
  mint C(int a, int b){
    if(b < 0 || b > a){
      return 0;
    }
    return fac[a]*ifac[b]*ifac[a-b];
  }
  mint P(int a, int b){
    if(b < 0 || b > a){
      return 0;
    }
    return fac[a]*ifac[a-b];
  }
  mint H(int a, int b){
    if(a==0 && b==0){
      return 1;
    }
    if(a<=0 || b<0){
      return 0;
    }
    return C(a+b-1, b);
  }
}
;
const int mxn =  1<<19;
int n;
int a[100000+10];
int b[72];
int pr[72];
int psz;
int cnt[72];
mint dp[mxn];
mint new_dp[mxn];
int main(){
  int i;
  wmem = memarr;
  {
    mint x;
    x.setmod(MD);
  }
  rd(n);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(n);PiIOrLma++){
      rd(a[PiIOrLma]);
    }
  }
  for(i=(0);i<(n);i++){
    cnt[a[i]]++;
  }
  psz =Prime_L(70, pr);
  for(i=(0);i<(psz);i++){
    b[pr[i]] = i;
  }
  combination_mint comb;
  comb.init(100000+10);
  dp[0] = 1;
  for(i=(1);i<(70+1);i++){
    int j;
    if(cnt[i] == 0){
      continue;
    }
    int tmp = i;
    int mask = 0;
    while(tmp > 1){
      int j;
      for(j=(0);j<(psz);j++){
        while(tmp % pr[j] == 0){
          tmp /= pr[j];
          mask ^= (1<<b[pr[j]]);
        }
      }
    }
    mint addeven = 0;
    mint addodd = 0;
    for(j=(0);j<(cnt[i]+1);j+=(2)){
      addeven += comb.C(cnt[i], j);
    }
    for(j=(1);j<(cnt[i]+1);j+=(2)){
      addodd += comb.C(cnt[i], j);
    }
    for(j=(0);j<(mxn);j++){
      new_dp[j] = addeven * dp[j];
    }
    for(j=(0);j<(mxn);j++){
      new_dp[j^mask] += addodd * dp[j];
    }
    memcpy(dp, new_dp, sizeof(dp));
  }
  wt_L(dp[0]-1);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// const int mxn =  1<<19;
// int n, a[1d5+10], b[72], pr[], psz, cnt[];
// mint dp[mxn], new_dp[];
// { 
//     rd(n, a(n));
//     rep(i, n) cnt[a[i]]++;
//     psz = Prime(70, pr);
//     rep(i, psz) b[pr[i]] = i;
//     combination_mint  comb;
//     comb.init(1d5+10);
//     dp[0] = 1;
//     rep(i, 1, 70+1){
//         if(cnt[i] == 0) continue;
//         int tmp = i, mask = 0;
//         while(tmp > 1){
//             rep(j, psz) while(tmp % pr[j] == 0) tmp /= pr[j], mask ^= (1<<b[pr[j]]);
//         }
//         mint addeven = 0, addodd = 0;
//         rep(j, 0, cnt[i]+1, 2) addeven += comb.C(cnt[i], j);
//         rep(j, 1, cnt[i]+1, 2) addodd += comb.C(cnt[i], j);
//         rep(j, 0, mxn) new_dp[j] = addeven * dp[j];
//         rep(j, 0, mxn) new_dp[j^mask] += addodd * dp[j];
//         
//         memcpy(dp, new_dp, sizeof(dp));
//     }
//     wt(dp[0]-1);
// }
