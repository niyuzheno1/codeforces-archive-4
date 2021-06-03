#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
      fwrite_unlocked(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar_unlocked(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite_unlocked(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a){
  my_putchar_unlocked(a);
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
    my_putchar_unlocked('-');
  }
  while(s--){
    my_putchar_unlocked(f[s]+'0');
  }
}
#include "random_array.hpp"
int main(int argc, char ** argv){
  int i;
  registerGen(argc, argv, 1);
  int tcases = 100;
  wt_L(tcases);
  wt_L('\n');
  for(i=(0);i<(tcases);i++){
    int n = rnd.next(1, 10);
    n = n*2;
    int l = rnd.next(0, n);
    int r = n-l;
    wt_L(n);
    wt_L(' ');
    wt_L(l);
    wt_L(' ');
    wt_L(r);
    wt_L('\n');
    int* u = getarray(n, 1, n);
    {
      int FJNsjZ7B;
      if(n==0){
        wt_L('\n');
      }
      else{
        for(FJNsjZ7B=(0);FJNsjZ7B<(n-1);FJNsjZ7B++){
          wt_L(u[FJNsjZ7B]);
          wt_L(' ');
        }
        wt_L(u[FJNsjZ7B]);
        wt_L('\n');
      }
    }
  }
}
// cLay version 20210405-1

// --- original code ---
// #include "random_array.hpp"
// 
// //wt(rnd.next("one|two|three"));
// int main(int argc, char ** argv){
//     registerGen(argc, argv, 1);
//     int tcases = 100;
//     wt(tcases);
//     rep(i, tcases){
//         int n = rnd.next(1, 10);
//         n = n*2;
//         int l = rnd.next(0, n);
//         int r = n-l;
//         wt(n,l,r);
//         int * u = getarray(n, 1, n);
//         wt(u(n));
//     }
// }
