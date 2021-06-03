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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int n;
char s[1000000+10];
long long pre[1000000+10];
long long cnt[1000000+10];
long long sa[1000000+10];
long long getidx(int l, int r){
  if(l > r){
    return 0;
  }
  if(l == 0){
    return pre[r];
  }
  return pre[r] - pre[l-1];
}
long long getcnt(int l, int r){
  if(l > r){
    return 0;
  }
  if(l == 0){
    return cnt[r];
  }
  return cnt[r] - cnt[l-1];
}
int main(){
  int FJNsjZ7B, i;
  sa[0] = 0;
  for(i=(1);i<(1000000+9);i++){
    sa[i] = sa[i-1] + i;
  }
  int GIHf_YD2 = rd_int();
  for(FJNsjZ7B=(0);FJNsjZ7B<(GIHf_YD2);FJNsjZ7B++){
    rd(n);
    rd(s);
    for(i=(0);i<(n +2);i++){
      pre[i] = 0;
      cnt[i] = 0;
    }
    for(i=(0);i<(n);i++){
      if(s[i] == '*'){
        pre[i] = i;
        cnt[i] = 1;
      }
    }
    for(i=(1);i<(n);i++){
      pre[i] += pre[i-1];
      cnt[i] += cnt[i-1] ;
    }
    if(getcnt(0, n-1) == 0){
      wt_L(0);
      wt_L('\n');
      continue;
    }
    long long ans = 4611686016279904256LL;
    for(i=(0);i<(n);i++){
      long long xi = i;
      if(s[i] == '*'){
        auto ct = getcnt(0, i-1);
        auto ct2 = getcnt(i+1, n-1);
        auto leftpart = (xi*ct-sa[ct]) - getidx(0,i-1);
        auto rightpart =  getidx(i+1, n-1) - (xi*ct2+sa[ct2]);
        chmin(ans, leftpart + rightpart);
      }
      else{
        auto ct = getcnt(0, i-1);
        auto ct2 = getcnt(i+1, n-1);
        if(ct > 0){
          auto leftpart = xi*ct-sa[ct-1] - getidx(0,i-1);
          auto rightpart = getidx(i+1, n-1) - (xi*ct2 + sa[ct2]);
          chmin(ans, leftpart + rightpart);
        }
        if(ct2 > 0){
          auto leftpart = xi*ct - sa[ct] - getidx(0, i-1);
          auto rightpart = getidx(i+1, n-1) - (xi * ct2 + sa[ct2-1]);
          chmin(ans, leftpart + rightpart);
        }
      }
    }
    wt_L(ans);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n;
// char s[1d6+10];
// ll pre[1d6+10];
// ll cnt[1d6+10];
// ll sa[1d6+10];
// ll getidx(int l, int r){
//     if(l > r) return 0;
//     if(l == 0) return pre[r];
//     return pre[r] - pre[l-1];
// }
// ll getcnt(int l, int r){
//     if(l > r) return 0;
//     if(l == 0) return cnt[r];
//     return cnt[r] - cnt[l-1];
// }
// { 
//     sa[0] = 0;
//     rep(i, 1, 1d6+9) sa[i] = sa[i-1] + i;
//     REP(rd_int()){
//         
//         rd(n, s);
//         rep(i, n +2) pre[i] = 0, cnt[i] = 0;
//         rep(i, n) if(s[i] == '*') pre[i] = i, cnt[i] = 1;
//         rep(i, 1, n) pre[i] += pre[i-1], cnt[i] += cnt[i-1] ;
//         if(getcnt(0, n-1) == 0) wt(0), continue;
//         ll ans = ll_inf;
//         rep(i, n){
//             ll xi = i;
//             if(s[i] == '*'){
//                 auto ct = getcnt(0, i-1);
//                 auto ct2 = getcnt(i+1, n-1);
//                 auto leftpart = (xi*ct-sa[ct]) - getidx(0,i-1);
//                 auto rightpart =  getidx(i+1, n-1) - (xi*ct2+sa[ct2]);
//                 ans <?= leftpart + rightpart;
//             }else{
//                 auto ct = getcnt(0, i-1);
//                 auto ct2 = getcnt(i+1, n-1);
//                 if(ct > 0){
//                     auto leftpart = xi*ct-sa[ct-1] - getidx(0,i-1);
//                     auto rightpart = getidx(i+1, n-1) - (xi*ct2 + sa[ct2]);
//                     ans <?= leftpart + rightpart;
//                 }
//                 if(ct2 > 0){
//                     auto leftpart = xi*ct - sa[ct] - getidx(0, i-1);
//                     auto rightpart = getidx(i+1, n-1) - (xi * ct2 + sa[ct2-1]);
//                     ans <?= leftpart + rightpart;
//                 }
//             }
//         }
//         wt(ans);
//     }
// }
