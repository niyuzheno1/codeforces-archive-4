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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int n;
int x;
int w[110];
int main(){
  int PiIOrLma;
  int AuJVIghY = rd_int();
  for(PiIOrLma=(0);PiIOrLma<(AuJVIghY);PiIOrLma++){
    int i;
    rd(n);
    rd(x);
    {
      int djQeACzd;
      for(djQeACzd=(0);djQeACzd<(n);djQeACzd++){
        rd(w[djQeACzd]);
      }
    }
    for(i=(0);i<(n);i++){
      int j;
      int addv = 0;
      for(j=(0);j<(i+1);j++){
        addv += w[j];
      }
      if(addv == x){
        if(i+1 < n){
          swap(w[i], w[i+1]);
        }
        else{
          swap(w[i], w[0]);
        }
      }
    }
    int addv = 0;
    for(i=(0);i<(n);i++){
      addv += w[i];
      if(addv == x){
        wt_L("NO");
        wt_L('\n');
        goto FJNsjZ7B;
      }
    }
    wt_L("YES");
    wt_L('\n');
    {
      int GN2MVvSr;
      if(n==0){
        wt_L('\n');
      }
      else{
        for(GN2MVvSr=(0);GN2MVvSr<(n-1);GN2MVvSr++){
          wt_L(w[GN2MVvSr]);
          wt_L(' ');
        }
        wt_L(w[GN2MVvSr]);
        wt_L('\n');
      }
    }
    FJNsjZ7B:;
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n, x, w[110];
// { 
//   REP(rd_int()){
//     rd(n, x, w(n));
//     rep(i, n){
//         int addv = 0;
//         rep(j, 0, i+1){
//             addv += w[j];
//         }
//         if(addv == x){
//             if(i+1 < n){
//                 swap(w[i], w[i+1]);
//             }else{
//                 swap(w[i], w[0]);
//             }
//         }
//     }
//     int addv = 0;
//     rep(i, n){
//         addv += w[i];
//         if(addv == x){
//             wt("NO");
//             break_continue;
//         }
//     }
//     wt("YES");
//     wt(w(n));
//   }
// }
