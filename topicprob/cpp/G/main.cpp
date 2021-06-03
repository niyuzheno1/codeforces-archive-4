#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define MD (1000000007U)
struct modint{
  static unsigned md;
  unsigned val;
  modint(){
    val=0;
  }
  modint(int a){
    val = ord(a);
  }
  modint(unsigned a){
    val = ord(a);
  }
  modint(long long a){
    val = ord(a);
  }
  modint(unsigned long long a){
    val = ord(a);
  }
  void setmod(unsigned m){
    md = m;
  }
  unsigned ord(unsigned a){
    return a%md;
  }
  unsigned ord(int a){
    a %= (int)md;
    if(a < 0){
      a += md;
    }
    return a;
  }
  unsigned ord(unsigned long long a){
    return a%md;
  }
  unsigned ord(long long a){
    a %= (int)md;
    if(a < 0){
      a += md;
    }
    return a;
  }
  unsigned get(){
    return val;
  }
  inline modint &operator++(){
    val++;
    if(val >= md){
      val -= md;
    }
    return *this;
  }
  inline modint &operator--(){
    if(val == 0){
      val = md - 1;
    }
    else{
      --val;
    }
    return *this;
  }
  inline modint operator++(int a){
    modint res(*this);
    val++;
    if(val >= md){
      val -= md;
    }
    return res;
  }
  inline modint operator--(int a){
    modint res(*this);
    if(val == 0){
      val = md - 1;
    }
    else{
      --val;
    }
    return res;
  }
  modint &operator+=(modint a){
    val += a.val;
    if(val >= md){
      val -= md;
    }
    return *this;
  }
  modint &operator-=(modint a){
    if(val < a.val){
      val = val + md - a.val;
    }
    else{
      val -= a.val;
    }
    return *this;
  }
  modint &operator*=(modint a){
    val = ((unsigned long long)val*a.val)%md;
    return *this;
  }
  modint &operator/=(modint a){
    return *this *= a.inverse();
  }
  modint operator+(modint a){
    return modint(*this)+=a;
  }
  modint operator-(modint a){
    return modint(*this)-=a;
  }
  modint operator*(modint a){
    return modint(*this)*=a;
  }
  modint operator/(modint a){
    return modint(*this)/=a;
  }
  modint operator+(int a){
    return modint(*this)+=modint(a);
  }
  modint operator-(int a){
    return modint(*this)-=modint(a);
  }
  modint operator*(int a){
    return modint(*this)*=modint(a);
  }
  modint operator/(int a){
    return modint(*this)/=modint(a);
  }
  modint operator+(long long a){
    return modint(*this)+=modint(a);
  }
  modint operator-(long long a){
    return modint(*this)-=modint(a);
  }
  modint operator*(long long a){
    return modint(*this)*=modint(a);
  }
  modint operator/(long long a){
    return modint(*this)/=modint(a);
  }
  modint operator-(void){
    modint res;
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
  modint inverse(){
    int a = val;
    int b = md;
    int u = 1;
    int v = 0;
    int t;
    modint res;
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
    res.val = u;
    return res;
  }
  modint pw(unsigned long long b){
    modint a(*this);
    modint res;
    res.val = 1;
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
    return ord(a)==val;
  }
  bool operator!=(int a){
    return ord(a)!=val;
  }
}
;
unsigned modint::md;
modint operator+(int a, modint b){
  return modint(a)+=b;
}
modint operator-(int a, modint b){
  return modint(a)-=b;
}
modint operator*(int a, modint b){
  return modint(a)*=b;
}
modint operator/(int a, modint b){
  return modint(a)/=b;
}
modint operator+(long long a, modint b){
  return modint(a)+=b;
}
modint operator-(long long a, modint b){
  return modint(a)-=b;
}
modint operator*(long long a, modint b){
  return modint(a)*=b;
}
modint operator/(long long a, modint b){
  return modint(a)/=b;
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
inline void wt_L(modint x){
  int i;
  i = (int)x;
  wt_L(i);
}
template<class T> int Moebius_L(T n){
  T i;
  int res = 1;
  if(n%4==0){
    return 0;
  }
  if(n%2==0){
    n /= 2;
    res = -res;
  }
  for(i=3;i*i<=n;i+=2){
    if(n%i==0){
      n /= i;
      res = -res;
    }
    if(n%i==0){
      return 0;
    }
  }
  if(n > 1){
    res = -res;
  }
  return res;
}
int n;
int a[100010];
int dis[100010];
modint g[100010];
modint f[100010];
void standard(){
  int i;
  rd(n);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(n);PiIOrLma++){
      rd(a[PiIOrLma]);
    }
  }
  for(i=(0);i<(n);i++){
    ++dis[a[i]];
  }
  for(i=(2);i<(100000+1);i++){
    int j;
    int cnt = 0;
    for(j=(i);j<(100000+1);j+=(i)){
      cnt += dis[j];
    }
    modint tmp;
    tmp = 2;
    tmp = tmp.pw(cnt);
    --tmp;
    g[i] = tmp;
    f[i] = tmp;
  }
  for(i=(100000+1)-1;i>=(2);i--){
    int j;
    f[i] = g[i];
    for(j=(i*2);j<(100000+1);j+=(i)){
      f[i] -= f[j];
    }
  }
  modint ans;
  ans = 2;
  ans = ans.pw(n);
  --ans;
  int GN2MVvSr;
  modint OUHHcm5g;
  if(100000+1==0){
    OUHHcm5g = 0;
  }
  else{
    OUHHcm5g = f[0];
    for(GN2MVvSr=(1);GN2MVvSr<(100000+1);GN2MVvSr++){
      OUHHcm5g += f[GN2MVvSr];
    }
  }
  modint su = OUHHcm5g;
  ans -= su;
  wt_L(ans);
  wt_L('\n');
}
int main(){
  int i;
  {
    modint x;
    x.setmod(MD);
  }
  rd(n);
  {
    int lo08wcHZ;
    for(lo08wcHZ=(0);lo08wcHZ<(n);lo08wcHZ++){
      rd(a[lo08wcHZ]);
    }
  }
  for(i=(0);i<(n);i++){
    ++dis[a[i]];
  }
  for(i=(2);i<(100000+1);i++){
    int j;
    int cnt = 0;
    for(j=(i);j<(100000+1);j+=(i)){
      cnt += dis[j];
    }
    modint tmp;
    tmp = 2;
    tmp = tmp.pw(cnt);
    --tmp;
    g[i] = tmp;
    f[i] = tmp;
  }
  modint su = 0;
  for(i=(2);i<(100000+1);i++){
    su +=Moebius_L(i)* g[i];
  }
  modint ans;
  ans = 2;
  ans = ans.pw(n);
  --ans;
  ans += su;
  wt_L(ans);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n, a[100010],  dis[];
// modint g[], f[];
// 
// void standard(){ 
//   rd(n, a(n));
//   rep(i, n) ++dis[a[i]];
//   rep(i, 2, 1d5+1){
//       int cnt = 0;
//       rep(j, i, 1d5+1, i) cnt += dis[j];
//       modint tmp;
//       tmp = 2;
//       tmp = tmp.pw(cnt);
//       --tmp;
//       g[i] = tmp;
//       f[i] = tmp;
//   }
//   rrep(i, 2, 1d5+1){
//       f[i] = g[i];
//       rep(j, i*2, 1d5+1, i) f[i] -= f[j];
//   }
//   modint ans;
//   ans = 2;
//   ans = ans.pw(n); --ans;
//   modint su = sum(f(1d5+1));
//   ans -= su;
//   wt(ans);
// }
// 
// 
// 
// { 
//   rd(n, a(n));
//   rep(i, n) ++dis[a[i]];
//   rep(i, 2, 1d5+1){
//       int cnt = 0;
//       rep(j, i, 1d5+1, i) cnt += dis[j];
//       modint tmp;
//       tmp = 2;
//       tmp = tmp.pw(cnt);
//       --tmp;
//       g[i] = tmp;
//       f[i] = tmp;
//   }
//   modint su = 0;
//   rep(i, 2, 1d5+1){
//     su += Moebius(i) * g[i];      
//   }
// 
//   modint ans;
//   ans = 2;
//   ans = ans.pw(n); --ans;
//   ans += su;
//   wt(ans);
// }
