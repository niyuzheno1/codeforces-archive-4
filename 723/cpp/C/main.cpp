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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
long long f[2100];
long long g[2100];
int n;
long long a[2100];
const long long myinf = 2010LL * (long long)1000000000;
int main(){
  int i;
  for(i=(0);i<(2100);i++){
    f[i] = -myinf;
  }
  rd(n);
  {
    int FJNsjZ7B;
    for(FJNsjZ7B=(0);FJNsjZ7B<(n);FJNsjZ7B++){
      rd(a[FJNsjZ7B]);
    }
  }
  f[0] = 0;
  int ans = 0;
  for(i=(0);i<(n);i++){
    int j;
    for(j=(1);j<(i+2);j++){
      g[j] = -myinf;
    }
    for(j=(1);j<(i+2);j++){
      if(f[j-1] + a[i] >= 0){
        g[j] = f[j-1] + a[i];
      }
    }
    for(j=(1);j<(i+2);j++){
      chmax(f[j], g[j]);
      if(f[j] >= 0){
        chmax(ans, j);
      }
    }
    wt_L(a[i]);
    wt_L(' ');
    wt_L(":");
    wt_L(' ');
    {
      int GN2MVvSr;
      if(n==0){
        wt_L('\n');
      }
      else{
        for(GN2MVvSr=(0);GN2MVvSr<(n-1);GN2MVvSr++){
          wt_L(f[GN2MVvSr]);
          wt_L(' ');
        }
        wt_L(f[GN2MVvSr]);
        wt_L('\n');
      }
    }
  }
  wt_L(ans);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// ll f[2100], g[];
// int n;
// ll a[2100];
// const ll myinf = 2010LL * (ll)1d9;
// { 
//     rep(i, 0, 2100) f[i] = -myinf;
//     rd(n, a(n));
//     f[0] = 0;
//     int ans = 0;
//     rep(i, 0, n){
//         rep(j, 1, i+2) g[j] = -myinf;
//         rep(j, 1, i+2) if(f[j-1] + a[i] >= 0) g[j] = f[j-1] + a[i];
//         rep(j, 1, i+2) {
//             f[j] >?= g[j];
//             if(f[j] >= 0) ans >?= j;
//         }
//         wt(a[i], ":",f(n));
//     }
//     wt(ans);
// }
