#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
template<class T, class S> inline T pow_L(T a, S b){
  T res = 1;
  res = 1;
  for(;;){
    if(b&1){
      res *= a;
    }
    b >>= 1;
    if(b==0){
      break;
    }
    a *= a;
  }
  return res;
}
inline double pow_L(double a, double b){
  return pow(a,b);
}
int n;
int K;
long long L[1000+10];
long long R[1000+10];
double P[1000+10];
double dp[1000+10][1000+10];
long long getones(long long x){
  int i;
  if(x == 0){
    return 0;
  }
  long long ret = 0;
  auto s = to_string(x);
  int n = s.length();
  for(i=(1);i<(n);i++){
    ret +=(pow_L(10LL,(i-1)));
  }
  if(s[0] == '1'){
    auto t = s.substr(1);
    t = '0' + t;
    ret += stoll(t)+1;
  }
  else{
    ret +=(pow_L(10LL,(n-1)));
  }
  return ret;
}
int main(){
  int i;
  rd(n);
  if(n == -1){
    return 0;
  }
  {
    int FJNsjZ7B;
    for(FJNsjZ7B=(0);FJNsjZ7B<(n);FJNsjZ7B++){
      rd(L[FJNsjZ7B]);
      rd(R[FJNsjZ7B]);
    }
  }
  rd(K);
  for(i=(0);i<(n);i++){
    auto delta = getones(R[i])-getones(L[i]-1);
    double prob = delta;
    prob /= double(R[i]-L[i]+1);
    P[i] = prob;
  }
  dp[0][0] = 1;
  for(i=(0);i<(n+1);i++){
    int j;
    for(j=(0);j<(n+1);j++){
      dp[i+1][j+1] += dp[i][j] * P[i];
      dp[i+1][j] += dp[i][j] * (1.0 - P[i]);
    }
  }
  double ans = 0;
  for(i=(0);i<(n+1);i++){
    if(i * 100 >= K * n){
      ans += dp[n][i];
    }
  }
  wt_L(ans);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n, K;
// ll L[1d3+10], R[];
// double P[], dp[1d3+10][1d3+10];
// ll getones(ll x){
//     if(x == 0) return 0;
//     ll ret = 0;
//     auto s = to_string(x);
//     int n = s.length();
//     rep(i, 1, n){
//         ret += 10LL ** (i-1);
//     }
//     if(s[0] == '1'){
//         auto t = s.substr(1);
//         t = '0' + t;
//         ret += stoll(t)+1;
//     }else{
//         ret += 10LL ** (n-1);
//     }
//     return ret;
// }
// { 
//     rd(n);
//     if(n == -1) return 0;
//     rd((L,R)(n), K);
//     rep(i, n){
//         auto delta = getones(R[i])-getones(L[i]-1);
//         double prob = delta;
//         prob /= double(R[i]-L[i]+1);
//         P[i] = prob;
//     }
//     dp[0][0] = 1;
//     rep(i, n+1){
//         rep(j, n+1){
//             dp[i+1][j+1] += dp[i][j] * P[i];
//             dp[i+1][j] += dp[i][j] * (1.0 - P[i]);
//         }
//     }
//     double ans = 0;
//     rep(i, n+1){
//         if(i * 100 >= K * n) ans += dp[n][i];
//     }
//     wt(ans);
// }
