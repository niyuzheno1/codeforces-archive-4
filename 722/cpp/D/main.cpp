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
int n;
int f[1000+10][1000+10];
int g[1000000+10];
int main(){
  int i;
  rd(n);
  f[0][0] = 1;
  g[0] = 1;
  f[2][1] = 1;
  g[2] = 1;
  for(i=(4);i<(2*n+1);i+=(2)){
    int x;
    for(x=(1);x<(i);x++){
      auto r  = i-2*x + 1;
      if(r > 1){
        f[i][x] = f[i-2*x][x];
      }
      else{
        f[i][x] = g[1-r];
      }
    }
    for(x=(1);x<(i);x++){
      g[i] += f[i][x];
    }
  }
  for(i=(2);i<(2*n+1);i+=(2)){
    wt_L(i);
    wt_L(' ');
    wt_L(g[i]);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n;
// int f[1d3+10][1d3+10], g[1d6+10];
// { 
//     rd(n);
//     f[0][0] = 1;
//     g[0] = 1;
//     f[2][1] = 1;
//     g[2] = 1;
//     rep(i, 4, 2*n+1, 2){
//         rep(x, 1, i){
//             auto r  = i-2*x + 1;
//             if(r > 1){
//                 f[i][x] = f[i-2*x][x];
//             }else{
//                 f[i][x] = g[1-r];
//             }
//         }
//         rep(x, 1, i){
//             g[i] += f[i][x];
//         }
//     }
//     rep(i, 2, 2*n+1, 2){
//         wt(i, g[i]);
//     }
//     
// }
