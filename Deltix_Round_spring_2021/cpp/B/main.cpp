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
int ops[7];
int n;
int a[10000];
int* b;
int ansx[5000+10];
int ansy[5000+10];
int ansz[5000+10];
int asz;
int main(){
  int PiIOrLma;
  ops[0] = 1;
  ops[1] = 2;
  ops[2] = 1;
  ops[3] = 1;
  ops[4] = 2;
  ops[5] = 1;
  int AuJVIghY = rd_int();
  for(PiIOrLma=(0);PiIOrLma<(AuJVIghY);PiIOrLma++){
    int i;
    b = &a[1];
    rd(n);
    {
      int djQeACzd;
      for(djQeACzd=(0);djQeACzd<(n);djQeACzd++){
        rd(b[djQeACzd]);
      }
    }
    asz = 0;
    for(i=(1);i<(n+1);i+=(2)){
      int j;
      for(j=(0);j<(6);j++){
        ansx[asz] = ops[j];
        ansy[asz] = i;
        ansz[asz] = i+1;
        ++asz;
      }
    }
    wt_L(asz);
    wt_L('\n');
    for(i=(0);i<(asz);i++){
      wt_L(ansx[i]);
      wt_L(' ');
      wt_L(ansy[i]);
      wt_L(' ');
      wt_L(ansz[i]);
      wt_L('\n');
    }
    for(i=(0);i<(asz);i++){
      if(ansx[i] == 1){
        a[ansy[i]] = a[ansy[i]]  +a[ansz[i]];
      }
      else{
        a[ansz[i]] = a[ansz[i]] - a[ansy[i]]  ;
      }
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// 
// int ops[7];
// int n, a[1d4];
// int * b;
// int ansx[5d3+10], ansy[5d3+10], ansz[5d3+10], asz;
// { 
//     ops[0] = 1; ops[1] = 2; ops[2] = 1; ops[3] = 1; ops[4] = 2; ops[5] = 1; 
//     REP(rd_int()){
//         b = &a[1];
//         rd(n, b(n));
//         asz = 0;
//         rep(i, 1, n+1, 2){
//             rep(j, 6){
//                 ansx[asz] = ops[j];
//                 ansy[asz] = i;
//                 ansz[asz] = i+1;
//                 ++asz;
//             }
//         }
//         wt(asz);
//         rep(i, asz)  wt(ansx[i], ansy[i], ansz[i]);
//         rep(i, asz){
//             if(ansx[i] == 1){
//                 a[ansy[i]] = a[ansy[i]]  +a[ansz[i]];
//             }else{
//                 a[ansz[i]] = a[ansz[i]] - a[ansy[i]]  ;
//             }
//         }
//         //wt(b(n));
//     }
// }
