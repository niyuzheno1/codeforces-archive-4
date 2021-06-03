#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline int my_getchar(){
  return getchar();
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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
}
inline void my_putchar(const int k){
  putchar(k);
  if(k=='\n'){
    fflush(stdout);
  }
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
inline void wt_L(unsigned x){
  int s=0;
  char f[10];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
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
inline void wt_L(unsigned long long x){
  int s=0;
  char f[21];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
int WRITER_DOUBLE_DIGIT = 15;
inline int writerDigit_double(){
  return WRITER_DOUBLE_DIGIT;
}
inline void writerDigit_double(int d){
  WRITER_DOUBLE_DIGIT = d;
}
inline void wt_L(double x){
  const int d = WRITER_DOUBLE_DIGIT;
  int k;
  int r;
  double v;
  if(x!=x || (x==x+1 && x==2*x)){
    my_putchar('E');
    my_putchar('r');
    my_putchar('r');
    return;
  }
  if(x < 0){
    my_putchar('-');
    x = -x;
  }
  x += 0.5 * pow(0.1, d);
  r = 0;
  v = 1;
  while(x >= 10*v){
    v *= 10;
    r++;
  }
  while(r >= 0){
    r--;
    k = floor(x / v);
    if(k >= 10){
      k = 9;
    }
    if(k <= -1){
      k = 0;
    }
    x -= k * v;
    v *= 0.1;
    my_putchar(k + '0');
  }
  if(d > 0){
    my_putchar('.');
    v = 1;
    for(r=(0);r<(d);r++){
      v *= 0.1;
      k = floor(x / v);
      if(k >= 10){
        k = 9;
      }
      if(k <= -1){
        k = 0;
      }
      x -= k * v;
      my_putchar(k + '0');
    }
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    my_putchar(x[i]);
  }
}
int n;
char resp[5];
int good[510][510];
int ask(int r1, int c1, int r2, int c2){
  wt_L("?");
  wt_L(' ');
  wt_L(r1);
  wt_L(' ');
  wt_L(c1);
  wt_L(' ');
  wt_L(r2);
  wt_L(' ');
  wt_L(c2);
  wt_L('\n');
  rd(resp);
  if(resp[0] == 'Y'){
    return 1;
  }
  return 0;
}
int fh(int x, int y){
  return ask(x, y, n, n);
}
int sh(int x, int y){
  return ask( 1, 1, x, y);
}
int offdiagnoal(int x, int y){
  return x+y == n+1;
}
int main(){
  rd(n);
  good[1][1] = 1;
  good[n][n] = 1;
  int curx;
  int cury;
  auto PiIOrLma = ((1));
  auto AuJVIghY = ((1));
  curx=PiIOrLma;
  cury=AuJVIghY;
  while(!offdiagnoal(curx, cury)){
    if(cury < n && fh(curx, cury + 1)){
      cury = cury+1;
    }
    else{
      curx = curx + 1;
    }
    good[curx][cury] = 1;
  }
  auto djQeACzd = ((n));
  auto Z8lEHcvz = ((n));
  curx=djQeACzd;
  cury=Z8lEHcvz;
  while(!offdiagnoal(curx, cury)){
    if(curx > 1 && sh(curx-1, cury)){
      curx = curx-1;
    }
    else{
      cury = cury - 1;
    }
    good[curx][cury] = 1;
  }
  auto C3F7XFP2 = ((1));
  auto EZ0PmQmu = ((1));
  curx=C3F7XFP2;
  cury=EZ0PmQmu;
  string ans = "";
  while( curx != n || cury != n){
    if(cury < n && good[curx][cury+1]){
      cury = cury + 1;
      ans += "R";
    }
    else{
      curx = curx + 1;
      ans += "D";
    }
  }
  wt_L("!");
  wt_L(' ');
  wt_L(ans.c_str());
  wt_L('\n');
  exit(0);
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// //interactive
// int n;
// char resp[5];
// int good[510][510];
// int ask(int r1, int c1, int r2, int c2){
//     wt("?", r1, c1, r2, c2);
//     rd(resp);
//     if(resp[0] == 'Y') return 1;
//     return 0;
// }
// int fh(int x, int y){
//     return ask(x, y, n, n);
// }
// int sh(int x, int y){
//     return ask( 1, 1, x, y);
// }
// int offdiagnoal(int x, int y){
//     return x+y == n+1;
// }
// { 
//     rd(n);
//     good[1][1] = 1;
//     good[n][n] = 1;
//     //fh
//     int curx, cury;
//     (curx, cury) = (1,1);
//     while(!offdiagnoal(curx, cury)){
//         if(cury < n && fh(curx, cury + 1)){
//             cury = cury+1;
//         }else{
//             curx = curx + 1;
//         }
//         good[curx][cury] = 1;
//     }
//     (curx, cury) = (n,n);
//     while(!offdiagnoal(curx, cury)){
//         if(curx > 1 && sh(curx-1, cury)){
//             curx = curx-1;
//         }else{
//             cury = cury - 1;
//         }
//         good[curx][cury] = 1;
//     }
//     //print the path by going from top left to bottom right
//     (curx, cury) = (1,1);
//     string ans = "";
//     while( curx != n || cury != n){
//         if(cury < n && good[curx][cury+1])
//             cury = cury + 1, ans += "R";
//         else
//             curx = curx + 1, ans += "D";
//     }
//     wt("!", ans.c_str());
//     exit(0);
// }
