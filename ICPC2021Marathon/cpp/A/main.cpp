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
int totalcases;
int w[5000+10];
int u[5000+10];
int A[5000+10];
int B[5000+10];
int marked[5000+10];
int ans[5000+10];
int asz;
int main(){
  int PiIOrLma;
  rd(totalcases);
  for(PiIOrLma=(0);PiIOrLma<(totalcases);PiIOrLma++){
    int i;
    asz = 0;
    int n;
    rd(n);
    {
      int GIHf_YD2;
      for(GIHf_YD2=(0);GIHf_YD2<(n);GIHf_YD2++){
        rd(w[GIHf_YD2]);
      }
    }
    int k;
    rd(k);
    {
      int rbGYC8dh;
      for(rbGYC8dh=(0);rbGYC8dh<(k);rbGYC8dh++){
        rd(u[rbGYC8dh]);
      }
    }
    int m;
    rd(m);
    {
      int EZ0PmQmu;
      for(EZ0PmQmu=(0);EZ0PmQmu<(m);EZ0PmQmu++){
        rd(A[EZ0PmQmu]);A[EZ0PmQmu] += (-1);
        rd(B[EZ0PmQmu]);B[EZ0PmQmu] += (-1);
      }
    }
    for(i=(0);i<(5009);i++){
      marked[i] = 0;
    }
    for(i=(0);i<(k);i++){
      marked[u[i]] = 1;
    }
    for(i=(1);i<(n+1);i++){
      if(!marked[i]){
        ans[asz++] = i;
      }
    }
    wt_L(asz);
    wt_L(' ');
    {
      int vAq4Dd79;
      if(asz==0){
        wt_L('\n');
      }
      else{
        for(vAq4Dd79=(0);vAq4Dd79<(asz-1);vAq4Dd79++){
          wt_L(ans[vAq4Dd79]);
          wt_L(' ');
        }
        wt_L(ans[vAq4Dd79]);
        wt_L('\n');
      }
    }
    wt_L(n);
    wt_L('\n');
    for(i=(1);i<(n+1);i++){
      wt_L(1);
      wt_L(' ');
      wt_L(i);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int totalcases, w[5d3+10], u[];
// int A[], B[], marked[];
// int ans[], asz;
// { 
//     rd(totalcases);
//     rep(totalcases){
//         asz = 0;
//         int @n;
//         rd(w(n));
//         int @k;
//         rd(u(k));
//         int @m;
//         rd((A--,B--)(m));
//         rep(i, 5009) marked[i] = 0;
//         rep(i, k) marked[u[i]] = 1;
//         rep(i, 1, n+1) if(!marked[i]) ans[asz++] = i;
//         wt(asz, ans(asz));
//         wt(n);
//         rep(i, 1, n+1) wt(1, i);
//     }
// }
