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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
long long n;
long long k;
long long s;
int ans[200000+10];
int asz;
int main(){
  int x;
  bool okay = false;
  rd(n);
  rd(k);
  rd(s);
  for(x=(0);x<(k+1);x++){
    if(okay){
      break;
    }
    long long y = k - x;
    if(x + (n-1)*y == s){
      int i;
      okay = true;
      int curx = 1;
      for(i=(0);i<(y);i++){
        curx = curx == 1? n : 1 ;
        ans[asz++] = curx;
      }
      for(i=(0);i<(x);i++){
        if(curx == 1){
          if(i % 2 == 0){
            ans[asz++] = curx+1;
          }
          else{
            ans[asz++] = curx;
          }
        }
        else{
          if(i % 2 == 0){
            ans[asz++] = curx-1;
          }
          else{
            ans[asz++] = curx;
          }
        }
      }
    }
  }
  if(!okay){
    for(x=(0);x<(k+1);x++){
      long long y = k - x - 1;
      if(okay){
        break;
      }
      if(y < 0){
        continue;
      }
      long long tmp =  s-(x+(n-1)*y);
      if(1 <= tmp  &&  tmp <= n-1){
        int i;
        okay = true;
        int curx = 1;
        for(i=(0);i<(y);i++){
          curx = curx == 1? n : 1 ;
          ans[asz++] = curx;
        }
        if(curx == 1){
          curx = curx + tmp;
          ans[asz++] = curx;
        }
        else{
          curx = curx - tmp;
          ans[asz++] = curx;
        }
        for(i=(0);i<(x);i++){
          if(curx == 1){
            curx = curx + 1;
            ans[asz++] = curx;
          }
          else{
            curx = curx-1;
            ans[asz++] = curx;
          }
        }
      }
    }
  }
  if(!okay){
    wt_L("NO");
    wt_L('\n');
  }
  else{
    wt_L("YES");
    wt_L('\n');
    {
      int Yd8JT4OW;
      if(asz==0){
        wt_L('\n');
      }
      else{
        for(Yd8JT4OW=(0);Yd8JT4OW<(asz-1);Yd8JT4OW++){
          wt_L(ans[Yd8JT4OW]);
          wt_L(' ');
        }
        wt_L(ans[Yd8JT4OW]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// ll n, k, s;
// int ans[2d5+10], asz;
// { 
//     bool okay = false;
//     rd(n,k,s);
//     rep(x, k+1){
//         if(okay) break;
//         ll y = k - x;
//         if(x + (n-1)*y == s){
//             okay = true;
//             int curx = 1;
//             rep(i, y){
//                 curx = curx == 1? n : 1 ;
//                 ans[asz++] = curx;
//             }
//             rep(i, x){
//                 if(curx == 1){
//                     if(i % 2 == 0){
//                         ans[asz++] = curx+1;
//                     }else{
//                         ans[asz++] = curx;
//                     }
//                 }else{
//                     if(i % 2 == 0){
//                         ans[asz++] = curx-1;
//                     }else{
//                         ans[asz++] = curx;
//                     }
//                 }             
//             }
//         }
//     }
//     if(!okay){
//         rep(x, k+1){
//             ll y = k - x - 1;
//             if(okay) break;
//             if(y < 0) continue;
//             ll tmp =  s-(x+(n-1)*y);
//             if(1 <= tmp <= n-1){
//                 okay = true;
//                 int curx = 1;
//                 rep(i, y){
//                     curx = curx == 1? n : 1 ;
//                     ans[asz++] = curx;
//                 }
//                 if(curx == 1){
//                     curx = curx + tmp;
//                     ans[asz++] = curx;
//                 }else{
//                     curx = curx - tmp;
//                     ans[asz++] = curx;
//                 }
//                 rep(i, x){
//                     if(curx == 1){
//                         curx = curx + 1;
//                         ans[asz++] = curx;
//                     }else{
//                         curx = curx-1;
//                         ans[asz++] = curx;
//                     }
//                 }
//             }
//         }
//     }
//     if(!okay) wt("NO");
//     else{
//         wt("YES");
//         wt(ans(asz));
//     }
// }
