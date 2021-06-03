#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class T> struct cLtraits_identity{
  using type = T;
}
;
template<class T> using cLtraits_try_make_signed =
  typename conditional<
    is_integral<T>::value,
    make_signed<T>,
    cLtraits_identity<T>
    >::type;
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
template<class T, class U> inline T GCD_L(T a, U b){
  T r;
  while(b){
    r=a;
    a=b;
    b=r%a;
  }
  return a;
}
int n;
int asz;
long long a[1000000];
long long ans[1000000][4];
void push(int x, int y, int z, int w){
  ans[asz][0] = x;
  ans[asz][1] = y;
  ans[asz][2] = z;
  ans[asz][3] = w;
  ++asz;
}
int main(){
  int PiIOrLma;
  int AuJVIghY = rd_int();
  for(PiIOrLma=(0);PiIOrLma<(AuJVIghY);PiIOrLma++){
    int i;
    asz = 0;
    rd(n);
    {
      int djQeACzd;
      for(djQeACzd=(0);djQeACzd<(n);djQeACzd++){
        rd(a[djQeACzd]);
      }
    }
    int C3F7XFP2;
    remove_reference<decltype(a[C3F7XFP2])>::type EZ0PmQmu;
    int zxsUT70f = 0;
    int VL854U43;
    if((0) > ((n)-1)){
      EZ0PmQmu = 0;
    }
    else{
      for(C3F7XFP2 = 0; C3F7XFP2 <= (n)-1; C3F7XFP2++){
        if(zxsUT70f == 0){
          EZ0PmQmu = a[C3F7XFP2];
          VL854U43 = C3F7XFP2;
          zxsUT70f = 1;
          continue;
        }
        const auto Yd8JT4OW = a[C3F7XFP2];
        if(EZ0PmQmu > Yd8JT4OW){
          EZ0PmQmu = Yd8JT4OW;
          VL854U43 = C3F7XFP2;
        }
      }
    }
    int idx = VL854U43;
    for(i=(idx)-1;i>=(0);i--){
      auto g =GCD_L(a[i], a[i+1]);
      if(g != 1){
        push(i+1, idx+1, a[i+1]+1, a[idx]);
        a[i] = a[i+1]+1;
      }
    }
    for(i=(idx+1);i<(n);i++){
      if(GCD_L(a[i], a[i-1])!= 1){
        push(i+1, idx+1, a[i-1]+1, a[idx]);
        a[i] = a[i-1]+1;
      }
    }
    wt_L(asz);
    wt_L('\n');
    for(i=(0);i<(asz);i++){
      {
        int a3PBjchb;
        if(4==0){
          wt_L('\n');
        }
        else{
          for(a3PBjchb=(0);a3PBjchb<(4-1);a3PBjchb++){
            wt_L(ans[i][a3PBjchb]);
            wt_L(' ');
          }
          wt_L(ans[i][a3PBjchb]);
          wt_L('\n');
        }
      }
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n, asz;
// ll a[1d6], ans[1d6][4];
// 
// 
// 
// void push(int x, int y, int z, int w){
//     ans[asz][0] = x;
//     ans[asz][1] = y;
//     ans[asz][2] = z;
//     ans[asz][3] = w;
//     ++asz;
// }
// 
// { 
//     REP(rd_int()){
//         asz = 0;
//         rd(n, a(n));
//         int idx = argmin(a(n));
//         rrep(i, idx){
//             auto g = gcd(a[i], a[i+1]);
//             if(g != 1){
//                 push(i+1, idx+1, a[i+1]+1, a[idx]);
//                 a[i] = a[i+1]+1;
//             }
//         }
//         rep(i, idx+1, n){
//             if(gcd(a[i], a[i-1]) != 1){
//                 push(i+1, idx+1, a[i-1]+1, a[idx]);
//                 a[i] = a[i-1]+1;
//             }
//         }
//         wt(asz);
//         rep(i,asz){
//             wt(ans[i](4));
//         }
//     }
// }
