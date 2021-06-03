#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
}
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
struct graph{
  int N;
  int*es;
  int**edge;
  void setDirectEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    walloc1d(&edge[0], M, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
    }
  }
}
;
const int dbg = 0;
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
int in[5000+10];
int out[5000+10];
int reg[5000+10];
vector<int> regions[5000+10];
graph g;
int dep[5000+10];
int vx[5000+10];
int pa[5000+10];
bool vis[5000+10];
bool mark(int x){
  if(x == -1){
    return false;
  }
  return marked[x] || backmarked[x];
}
void dfs(int x, int par){
  int PiIOrLma;
  if(vis[x]){
    return;
  }
  vis[x] = 1;
  int nx = par;
  if(par == -1){
    nx = x;
  }
  if(out[nx] > 1){
    nx = -1;
  }
  bool flag = false;
  if(nx != -1){
    if(!mark(nx)){
      backmarked[nx] = 1;
      regions[rsz].push_back(nx);
      reg[nx] = rsz++;
      flag = true;
    }
    else{
      if(in[x] == 1 && out[x] == 1 && nx != x){
        regions[reg[nx]].push_back(x);
        flag = true;
      }
    }
  }
  if(!flag){
    if(mark(x)){
      regions[rsz].push_back(x);
      reg[x] = rsz++;
    }
    if(mark(x)){
      nx = x;
    }
    if(out[nx] > 1){
      nx = -1;
    }
  }
  for(PiIOrLma=(0);PiIOrLma<(g.es[x]);PiIOrLma++){
    auto&i = g.edge[x][PiIOrLma];
    dfs(i, nx);
  }
}
int main(){
  int tcases;
  wmem = memarr;
  rd(totalcases);
  for(tcases=(0);tcases<(totalcases);tcases++){
    int i;
    if(dbg){
      wt_L("Case ");
      wt_L(' ');
      wt_L(tcases);
      wt_L(' ');
      wt_L(":");
      wt_L('\n');
    }
    for(i=(0);i<(rsz);i++){
      regions[i].clear();
    }
    for(i=(0);i<(n);i++){
      pa[i] = vx[i] = w[i] = u[i] = vx[i] = A[i] = B[i] = ans[i] =  marked[i] = backmarked[i] = in[i] = out[i]= dep[i] = vis[i] =  reg[i] =  0;
    }
    rsz =0;
    asz = 0;
    rd(n);
    {
      int EZ0PmQmu;
      for(EZ0PmQmu=(0);EZ0PmQmu<(n);EZ0PmQmu++){
        rd(w[EZ0PmQmu]);
      }
    }
    rd(k);
    {
      int Yd8JT4OW;
      for(Yd8JT4OW=(0);Yd8JT4OW<(k);Yd8JT4OW++){
        rd(u[Yd8JT4OW]);u[Yd8JT4OW] += (-1);
      }
    }
    rd(m);
    {
      int o8AZ1iEn;
      for(o8AZ1iEn=(0);o8AZ1iEn<(m);o8AZ1iEn++){
        rd(A[o8AZ1iEn]);A[o8AZ1iEn] += (-1);
        rd(B[o8AZ1iEn]);B[o8AZ1iEn] += (-1);
      }
    }
    g.setDirectEdge(n, m, A, B);
    for(i=(0);i<(m);i++){
      ++out[A[i]];
      ++in[B[i]];
    }
    for(i=(0);i<(k);i++){
      ++marked[u[i]];
    }
    for(i=(0);i<(n);i++){
      if((in[i] != 1 || out[i] != 1) && !mark(i)){
        backmarked[i] = 1;
      }
    }
    dfs(0, -1);
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
      int maNdQo4J;
      if(asz==0){
        wt_L('\n');
      }
      else{
        for(maNdQo4J=(0);maNdQo4J<(asz-1);maNdQo4J++){
          wt_L(ans[maNdQo4J]);
          wt_L(' ');
        }
        wt_L(ans[maNdQo4J]);
        wt_L('\n');
      }
    }
    wt_L(rsz);
    wt_L('\n');
    for(i=(0);i<(rsz);i++){
      int j;
      vector<int>& y = regions[i];
      asz = 0;
      for(j=(0);j<(y.size());j++){
        ans[asz++] = y[j]+1;
      }
      wt_L(asz);
      wt_L(' ');
      {
        int zjTyjRzb;
        if(asz==0){
          wt_L('\n');
        }
        else{
          for(zjTyjRzb=(0);zjTyjRzb<(asz-1);zjTyjRzb++){
            wt_L(ans[zjTyjRzb]);
            wt_L(' ');
          }
          wt_L(ans[zjTyjRzb]);
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
// const int dbg = 0;
// int totalcases, n, k, m;
// int w[5d3+10], u[], A[], B[], marked[], backmarked[], ans[], asz, rsz, in[], out[], reg[];
// VI regions[];
// graph g;
// int dep[], vx[], pa[];
// bool vis[];
// bool mark(int x){
//     if(x == -1) return false;
//     return marked[x] || backmarked[x];
// }
// void dfs(int x, int par){
//     if(vis[x]) return;
//     vis[x] = 1;
//     int nx = par;
//     if(par == -1){
//         nx = x;
//     }
//     if(out[nx] > 1){
//         nx = -1;
//     }
//     bool flag = false;
//     if(nx != -1){
//         if(!mark(nx)){
//             backmarked[nx] = 1;
//             regions[rsz].push_back(nx), reg[nx] = rsz++;
//             flag = true;
//         }else{
//             if(in[x] == 1 && out[x] == 1 && nx != x){
//                 regions[reg[nx]].push_back(x);
//                 flag = true;
//             }
//         }
//     }
//     if(!flag){
//         if(mark(x)) {
//             regions[rsz].push_back(x), reg[x] = rsz++;
//         }
//         if(mark(x)){
//             nx = x;
//         }
//         if(out[nx] > 1){
//             nx = -1;
//         }
//     }   
//     rep[g.edge[x]](i, g.es[x]) dfs(i, nx);
//     // update here when you are going out of a subtree/graph
// }
// 
// 
// { 
//     rd(totalcases);
//     rep(tcases, totalcases){
//         if(dbg) wt("Case ", tcases, ":");
//         rep(i, rsz) regions[i].clear();
//         rep(i, n) pa[i] = vx[i] = w[i] = u[i] = vx[i] = A[i] = B[i] = ans[i] =  marked[i] = backmarked[i] = in[i] = out[i]= dep[i] = vis[i] =  reg[i] =  0;
//         rsz =0;
//         asz = 0;
//         rd(n, w(n), k, (u--)(k), m, (A--,B--)(m) );
//         g.setDirectEdge(n, m, A, B);
//         rep(i, m) ++out[A[i]], ++in[B[i]];
//         rep(i, k) ++marked[u[i]];
//         rep(i,n) if((in[i] != 1 || out[i] != 1) && !mark(i)) backmarked[i] = 1;
//         //rep(i, n) if(mark(i)) regions[rsz].push_back(i), reg[i] = rsz++;
//         dfs(0, -1);
//         rep(i, n) if(backmarked[i]) ans[asz++] = i;
//         rep(i, asz) ++ans[i];
//         wt(asz, ans(asz));
//         wt(rsz);
//         rep(i,rsz){
//             VI & y = regions[i];
//             asz = 0;
//             rep(j, y.size()){
//                 ans[asz++] = y[j]+1;
//             }
//             wt(asz, ans(asz));
//         }
//     }
// }
