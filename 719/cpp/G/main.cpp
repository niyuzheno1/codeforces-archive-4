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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
struct dimcomp2{
  int B;
  dimcomp2(){
  }
  dimcomp2(int b){
    B = b;
  }
  dimcomp2(int a, int b){
    B = b;
  }
  inline void set(int b){
    B = b;
  }
  inline void set(int a, int b){
    B = b;
  }
  inline int mask(int a, int b){
    return a * B + b;
  }
  inline int operator()(int a, int b){
    return a * B + b;
  }
  inline void para(int mask, int &a, int &b){
    a = mask / B;
    b = mask % B;
  }
  inline void operator()(int mask, int &a, int &b){
    a = mask / B;
    b = mask % B;
  }
}
;
int n;
int m;
long long w;
long long a[2000+10][2000+10];
long long f[2][2000+10][2000+10];
bool within(int x, int y){
  return (0 <= x  &&  x < n) && (0 <= y  &&  y < m) && a[x][y] != -1;
}
int q[(2000+10)*(2000+10)];
int qed;
int main(){
  int i, k;
  rd(n);
  rd(m);
  rd(w);
  {
    int PiIOrLma;
    int AuJVIghY;
    for(PiIOrLma=(0);PiIOrLma<(n);PiIOrLma++){
      for(AuJVIghY=(0);AuJVIghY<(m);AuJVIghY++){
        rd(a[PiIOrLma][AuJVIghY]);
      }
    }
  }
  memset(f, 0xff, sizeof(f));
  dimcomp2 dim(n,m);
  int tot = n*m+1;
  long long res = 4611686016279904256LL;
  for(k=(0);k<(2);k++){
    int C3F7XFP2;
    int sx = k > 0 ? n - 1 : 0;
    int sy = k > 0 ? m - 1 : 0;
    qed = 0;
    q[qed++] = dim(sx, sy);
    f[k][sx][sy] = 0;
    for(C3F7XFP2=(0);C3F7XFP2<(qed);C3F7XFP2++){
      auto&i = q[C3F7XFP2];
      int _x;
      int _y;
      dim(i, _x, _y);
      for(i=(-1);i<(2);i++){
        int j;
        for(j=(-1);j<(2);j++){
          if(abs(i)+abs(j) != 1){
            continue;
          }
          int nx;
          int ny;
          nx = _x + i;
          ny = _y + j;
          if(!within(nx,ny)){
            continue;
          }
          if(f[k][nx][ny]  == -1 || f[k][nx][ny] > f[k][_x][_y] + w){
            f[k][nx][ny] = f[k][_x][_y] + w;
            q[qed++] = dim(nx,ny);
          }
        }
      }
    }
  }
  long long ans[2];
  ans[0] = ans[1] = 4611686016279904256LL;
  if(f[1][0][0] >= 0){
    res = f[1][0][0];
  }
  for(i=(0);i<(n);i++){
    int j;
    for(j=(0);j<(m);j++){
      for(k=(0);k<(2);k++){
        if(a[i][j] > 0 && f[k][i][j] >= 0){
          chmin(ans[k], f[k][i][j]+a[i][j]);
        }
      }
    }
  }
  chmin(res, ans[0] + ans[1]);
  if(res == 4611686016279904256LL){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n, m;
// ll w;
// ll a[2d3+10][2d3+10];
// ll f[2][2d3+10][2d3+10];
// bool within(int x, int y){
//     return (0 <= x < n) && (0 <= y < m) && a[x][y] != -1;
// }
// int q[(2d3+10)*(2d3+10)], qed;
// { 
//     rd(n, m, w, a(n, m));
//     memset(f, 0xff, sizeof(f));
//     dimcomp2 dim(n,m);
//     int tot = n*m+1;
//     ll res = ll_inf;
//     rep(k, 2){
//         int sx = k > 0 ? n - 1 : 0;
//         int sy = k > 0 ? m - 1 : 0;
//         qed = 0;
//         q[qed++] = dim(sx, sy);
//         f[k][sx][sy] = 0;
//         rep[q](i, qed){
//             int _x, _y;
//             dim(i, _x, _y);
//             rep(i, -1, 2) rep(j, -1, 2){
//                 if(abs(i)+abs(j) != 1) continue;
//                 int nx, ny;
//                 nx = _x + i; ny = _y + j;
//                 if(!within(nx,ny)) continue;
//                 if(f[k][nx][ny]  == -1 || f[k][nx][ny] > f[k][_x][_y] + w){
//                     f[k][nx][ny] = f[k][_x][_y] + w;
//                     q[qed++] = dim(nx,ny);
//                 }
//             }
//         }
//     }
//     ll ans[2];
//     ans[0] = ans[1] = ll_inf;
//     if(f[1][0][0] >= 0) res = f[1][0][0];
//     rep(i, n) rep(j, m) rep(k, 2) if(a[i][j] > 0 && f[k][i][j] >= 0) ans[k] <?= f[k][i][j]+a[i][j];
//     res <?= ans[0] + ans[1];
//     if(res == ll_inf) wt(-1), return 0;
//     wt(res);
// }
