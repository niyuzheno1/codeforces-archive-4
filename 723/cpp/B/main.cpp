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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int n;
long long x;
int dp[1000000];
bool dfs(long long x){
  int i;
  if(x < 1000000 && dp[x] != -1){
    return dp[x];
  }
  if(x <= 0){
    if(x < 0){
      return 0;
    }
    else{
      return 1;
    }
  }
  bool ret = false;
  long long cur = 11;
  long long prev = -1;
  for(i=(0);i<(12);i++){
    if(cur > x){
      break;
    }
    prev = cur;
    cur *= 10;
    cur += 1;
  }
  if(prev == -1){
    return false;
  }
  ret = ret || dfs(x % prev);
  int u = (x % prev) + cur;
  if(u < x){
    ret = ret || dfs(u);
  }
  if(x < 1000000){
    dp[x] = ret;
  }
  return ret;
}
int main(){
  int djQeACzd, i;
  memset(dp, 0xff, sizeof(dp));
  for(i=(0);i<(1000000);i++){
    dfs(i);
  }
  rd(n);
  for(djQeACzd=(0);djQeACzd<(n);djQeACzd++){
    rd(x);
    if(dfs(x)){
      wt_L("YES");
      wt_L('\n');
    }
    else{
      wt_L("NO");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n;
// ll x;
// 
// int dp[1d6];
// 
// bool dfs(ll x){
//     if(x < 1d6 && dp[x] != -1){
//         return dp[x];
//     }
//     if(x <= 0){
//         return if[x < 0, 0, 1];
//     }
//     bool ret = false;
//     ll cur = 11, prev = -1;
//     rep(i, 0, 12){
//         if(cur > x){
//             break;
//         }
//         prev = cur;
//         cur *= 10; cur += 1;
//     }
//     if(prev == -1) return false;
//     ret = ret || dfs(x % prev);
//     int u = (x % prev) + cur;
//     if(u < x) ret = ret || dfs(u);
//     if(x < 1d6){
//         dp[x] = ret;
//     }
//     return ret;
// }
// 
// 
// { 
//     memset(dp, 0xff, sizeof(dp));
//     rep(i, 1d6) dfs(i);
//     rd(n);
//     rep(n){
//         rd(x);
//         wt(if[dfs(x), "YES", "NO"]);
//     }
//   
// }
