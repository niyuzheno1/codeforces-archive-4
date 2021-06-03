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
  int tcases = 5000;
  wt_L(tcases);
  wt_L('\n');
  for(i=(0);i<(tcases);i++){
    int a;
    int b;
    a = rnd.next(1,7);
    b = rnd.next(1,7);
    wt_L(a);
    wt_L(' ');
    wt_L(b);
    wt_L('\n');
  }
}
// cLay version 20210405-1

// --- original code ---
// #include "random_array.hpp"
// 
// //wt(rnd.next("one|two|three"));
// int main(int argc, char ** argv){
//     registerGen(argc, argv, 1);
//     int tcases = 5000;
//     wt(tcases);
//     rep(i, tcases){
//         int a,b;
//         a = rnd.next(1,7);
//         b = rnd.next(1,7);
//         wt(a, b);
//     }
// }
