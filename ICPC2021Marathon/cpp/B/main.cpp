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
int n;
int k;
int m;
int w[5000+10];
int u[5000+10];
int A[5000+10];
int B[5000+10];
int marked[5000+10];
int backmarked[5000+10];
int ans[5000+10];
int asz;
int rsz;
vector<int> regions[5000+10];
int main(){
  int PiIOrLma;
  rd(totalcases);
  for(PiIOrLma=(0);PiIOrLma<(totalcases);PiIOrLma++){
    int i;
    rsz =0;
    asz = 0;
    memset(w, 0, sizeof(w));
    memset(u, 0, sizeof(u));
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    memset(marked, 0, sizeof(marked));
    memset(backmarked, 0, sizeof(backmarked));
    memset(ans, 0, sizeof(ans));
    for(i=(0);i<(5000+10);i++){
      regions[i].clear();
    }
    rd(n);
    {
      int Z8lEHcvz;
      for(Z8lEHcvz=(0);Z8lEHcvz<(n);Z8lEHcvz++){
        rd(w[Z8lEHcvz]);
      }
    }
    rd(k);
    {
      int C3F7XFP2;
      for(C3F7XFP2=(0);C3F7XFP2<(k);C3F7XFP2++){
        rd(u[C3F7XFP2]);u[C3F7XFP2] += (-1);
      }
    }
    rd(m);
    {
      int VL854U43;
      for(VL854U43=(0);VL854U43<(m);VL854U43++){
        rd(A[VL854U43]);A[VL854U43] += (-1);
        rd(B[VL854U43]);B[VL854U43] += (-1);
      }
    }
    for(i=(0);i<(k);i++){
      marked[u[i]] = 1;
    }
    for(i=(0);i<(n-1);i++){
      if(!marked[i]){
        backmarked[i] = 1;
      }
    }
    for(i=(0);i<(n);i++){
      if(backmarked[i]){
        ans[asz++] = i;
      }
    }
    for(i=(0);i<(asz);i++){
      ++ans[i];
    }
    wt_L(asz);
    wt_L(' ');
    {
      int WpmOCj1U;
      if(asz==0){
        wt_L('\n');
      }
      else{
        for(WpmOCj1U=(0);WpmOCj1U<(asz-1);WpmOCj1U++){
          wt_L(ans[WpmOCj1U]);
          wt_L(' ');
        }
        wt_L(ans[WpmOCj1U]);
        wt_L('\n');
      }
    }
    for(i=(1);i<(n);i++){
      if(marked[i] || backmarked[i]){
        regions[rsz++].push_back(i);
      }
    }
    for(i=(1);i<(n);i++){
      if(!marked[i] && !backmarked[i]){
        regions[rsz].push_back(i);
      }
    }
    regions[rsz++].push_back(0);
    wt_L(rsz);
    wt_L('\n');
    for(i=(0);i<(rsz);i++){
      int j;
      int m = regions[i].size();
      for(j=(0);j<(m);j++){
        ++regions[i][j];
      }
      wt_L(m);
      wt_L(' ');
      {
        int P51deDDa;
        if(m==0){
          wt_L('\n');
        }
        else{
          for(P51deDDa=(0);P51deDDa<(m-1);P51deDDa++){
            wt_L(regions[i][P51deDDa]);
            wt_L(' ');
          }
          wt_L(regions[i][P51deDDa]);
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
// int totalcases, n, k, m;
// int w[5d3+10], u[], A[], B[], marked[], backmarked[], ans[], asz, rsz;
// vector<int> regions[];
// 
// { 
//     rd(totalcases);
//     rep(totalcases){
//         rsz =0;
//         asz = 0;
//         memset(w, 0, sizeof(w)); memset(u, 0, sizeof(u));
//         memset(A, 0, sizeof(A)); memset(B, 0, sizeof(B));
//         memset(marked, 0, sizeof(marked)); memset(backmarked, 0, sizeof(backmarked));
//         memset(ans, 0, sizeof(ans));
//         rep(i, 5d3+10) regions[i].clear();
//         rd(n, w(n), k, (u--)(k), m, (A--,B--)(m) );
//         rep(i, k) marked[u[i]] = 1;
//         rep(i, n-1) if(!marked[i]) backmarked[i] = 1;
//         rep(i, n) if(backmarked[i]) ans[asz++] = i;
//         rep(i, asz) ++ans[i];
//         wt(asz, ans(asz));
//         rep(i, 1, n) if(marked[i] || backmarked[i]) regions[rsz++].push_back(i);
//         rep(i, 1, n) if(!marked[i] && !backmarked[i]) regions[rsz].push_back(i);
//         regions[rsz++].push_back(0);
//         
//         wt(rsz);
//         rep(i, rsz){
//             int m = regions[i].size();
//             rep(j, m) ++regions[i][j];
//             wt(m, (regions[i])(m));
//         }
//     }
// }
