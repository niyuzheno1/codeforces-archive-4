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
template<class T, class U> inline T GCD_L(T a, U b){
  T r;
  while(b){
    r=a;
    a=b;
    b=r%a;
  }
  return a;
}
int m;
int s[1000+10];
int b[1000000+10];
int n;
int ans[4000+10];
int main(){
  int i;
  rd(m);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(m);PiIOrLma++){
      rd(s[PiIOrLma]);
    }
  }
  bool sol = true;
  for(i=(0);i<(m);i++){
    b[s[i]] = 1;
  }
  for(i=(0);i<(m);i++){
    int j;
    for(j=(0);j<(m);j++){
      if(b[GCD_L(s[i], s[j])] ==0 ){
        sol = false;
        wt_L(s[i]);
        wt_L(' ');
        wt_L(s[j]);
        wt_L('\n');
        break;
      }
    }
    if(!sol){
      break;
    }
  }
  if(sol){
    wt_L(1);
    wt_L('\n');
  }
  else{
    wt_L(-1);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int m,s[1d3+10];
// int b[1d6+10];
// int n, ans[4d3+10];
// { 
//     rd(m, s(m));
//     bool sol = true;
//     rep(i,m) b[s[i]] = 1;
//     rep(i, m){
//         rep(j, m){
//             if(b[gcd(s[i], s[j])] ==0 ){
//                 sol = false;
//                 wt(s[i], s[j]);
//                 break;
//             }
//         }
//         if(!sol){
//             break;
//         }
//     }
//     if(sol){
//         wt(1);
//     }else{
//         wt(-1);
//     }
// }