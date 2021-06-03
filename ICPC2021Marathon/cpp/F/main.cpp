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
int firstfilled[5000+10];
vector<int> regions[5000+10];
graph g;
int dep[5000+10];
int vx[5000+10];
int pa[5000+10];
bool vis[5000+10];
int vis2[5000+10];
int timestamp;
int treenodes[5000+10];
int tsz;
set<int> disdist;
int coverage = 0;
void breakpoint(){
  if(dbg){
  }
}
bool mark(int x){
  if(x == -1){
    return false;
  }
  return marked[x] || backmarked[x];
}
void dfs(int x, int par){
  int PiIOrLma;
  if(x == 7){
    breakpoint();
  }
  if(vis[x]){
    return;
  }
  vis[x] = 1;
  int nx = par;
  if(par == -1 || firstfilled[par] == 1){
    nx = x;
  }
  if(out[nx] > 1){
    nx = -1;
  }
  bool flag = false;
  if(nx != -1){
    if(!mark(nx) && reg[nx] == -1){
      backmarked[nx] = 1;
      regions[rsz].push_back(nx);
      reg[nx] = rsz++;
      flag = true;
    }
    else{
      if(reg[x] != -1){
        nx = -1;
      }
      if(in[x] == 1 && out[x] == 1 && nx != x && reg[x] == -1){
        regions[reg[nx]].push_back(x);
        reg[x] = reg[nx];
        flag = true;
      }
    }
  }
  if(!flag){
    if(reg[x] == -1){
      if((in[x] != 1 || out[x] != 1) && !mark(x)){
        backmarked[x] = 1;
      }
      if(mark(x)){
        regions[rsz].push_back(x);
        reg[x] = rsz++;
      }
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
void dfs3(int x, int dis){
  int GIHf_YD2;
  if(mark(x) || in[x] > 1){
    return;
  }
  if(vis2[x] == timestamp){
    return;
  }
  treenodes[tsz++] = x;
  disdist.insert(dis);
  vis2[x] = timestamp;
  for(GIHf_YD2=(0);GIHf_YD2<(g.es[x]);GIHf_YD2++){
    auto&i = g.edge[x][GIHf_YD2];
    dfs3(i, dis+w[i]);
  }
}
bool dfs4(int x, int dis, double midist, double madist){
  int rbGYC8dh;
  if(vis2[x] != timestamp){
    return false;
  }
  bool ret = false;
  bool ret2 = false;
  if(midist+0.001 <= double(dis)  &&  double(dis) <= madist-0.02){
    ret2 = true;
  }
  int cnt = 0;
  for(rbGYC8dh=(0);rbGYC8dh<(g.es[x]);rbGYC8dh++){
    auto&i = g.edge[x][rbGYC8dh];
    ++cnt;
    if(cnt == 1){
      ret = true;
    }
    auto xxx = dfs4(i, dis+w[i], midist, madist);
    if(xxx != true){
      ret = false;
    }
  }
  if(ret || ret2){
    ++coverage;
  }
  return ret || ret2;
}
bool markall(int x ,int dis, double midist, double madist, int rx){
  int EZ0PmQmu;
  if(vis2[x] != timestamp){
    return false;
  }
  bool ret = false;
  bool ret2 = false;
  if(midist+0.001 <= double(dis)  &&  double(dis) <= madist-0.02){
    ret2 = true;
  }
  int cnt = 0;
  for(EZ0PmQmu=(0);EZ0PmQmu<(g.es[x]);EZ0PmQmu++){
    auto&i = g.edge[x][EZ0PmQmu];
    ++cnt;
    if(cnt == 1){
      ret = true;
    }
    auto xxx = markall(i, dis+w[i], midist, madist, rx);
    if(xxx != true){
      ret = false;
    }
  }
  if(ret || ret2){
    regions[rx].push_back(x);
    reg[x] = rx;
  }
  return ret || ret2;
}
void dfs2(int x){
  int OUHHcm5g;
  if(vis[x]){
    return;
  }
  vis[x] = 1;
  if(reg[x] == -1){
    ++timestamp;
    tsz = 0;
    disdist.clear();
    dfs3(x, w[x]);
    int bestcoverage = 0;
    int yz = 0;
    for(auto & y : disdist){
      double madist = double(y);
      double midist = madist * 0.9;
      coverage = 0;
      auto res =  dfs4(x, w[x], midist, madist);
      if(res && coverage > bestcoverage){
        yz = y;
        bestcoverage = coverage;
      }
    }
    if(yz > 0){
      if(!mark(x)){
        backmarked[x] = 1;
      }
      double madist = double(yz);
      double midist = madist * 0.9;
      reg[x] = rsz++;
      markall(x, w[x], midist, madist, reg[x]);
    }
  }
  for(OUHHcm5g=(0);OUHHcm5g<(g.es[x]);OUHHcm5g++){
    auto&i = g.edge[x][OUHHcm5g];
    dfs2(i);
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
    memset(firstfilled, 0, sizeof(firstfilled));
    memset(reg, 0xff, sizeof(reg));
    memset(vis2, 0, sizeof(vis2));
    rsz =0;
    asz = 0;
    rd(n);
    {
      int cDHiUAlz;
      for(cDHiUAlz=(0);cDHiUAlz<(n);cDHiUAlz++){
        rd(w[cDHiUAlz]);
      }
    }
    rd(k);
    {
      int waYUWM6f;
      for(waYUWM6f=(0);waYUWM6f<(k);waYUWM6f++){
        rd(u[waYUWM6f]);u[waYUWM6f] += (-1);
      }
    }
    rd(m);
    {
      int LiLe88qh;
      for(LiLe88qh=(0);LiLe88qh<(m);LiLe88qh++){
        rd(A[LiLe88qh]);A[LiLe88qh] += (-1);
        rd(B[LiLe88qh]);B[LiLe88qh] += (-1);
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
    dfs2(0);
    for(i=(0);i<(n);i++){
      vis[i] = 0;
    }
    for(i=(0);i<(n);i++){
      if(reg[i] != -1){
        firstfilled[i] = 1;
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
      int MkOXm_kt;
      if(asz==0){
        wt_L('\n');
      }
      else{
        for(MkOXm_kt=(0);MkOXm_kt<(asz-1);MkOXm_kt++){
          wt_L(ans[MkOXm_kt]);
          wt_L(' ');
        }
        wt_L(ans[MkOXm_kt]);
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
        int PeoeJQFI;
        if(asz==0){
          wt_L('\n');
        }
        else{
          for(PeoeJQFI=(0);PeoeJQFI<(asz-1);PeoeJQFI++){
            wt_L(ans[PeoeJQFI]);
            wt_L(' ');
          }
          wt_L(ans[PeoeJQFI]);
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
// int firstfilled[];
// VI regions[];
// graph g;
// int dep[], vx[], pa[];
// bool vis[];
// int vis2[], timestamp;
// int treenodes[], tsz;
// set<int> disdist;
// int coverage = 0;
// 
// void breakpoint(){
//     if(dbg){
//         //__asm int 3;
//     }
// }
// 
// bool mark(int x){
//     if(x == -1) return false;
//     return marked[x] || backmarked[x];
// }
// 
// void dfs(int x, int par){
//     if(x == 7) breakpoint();
//     if(vis[x]) return;
//     vis[x] = 1;
//     int nx = par;
//     if(par == -1 || firstfilled[par] == 1) nx = x;
//     if(out[nx] > 1) nx = -1;
//     bool flag = false;
//     if(nx != -1){
//         if(!mark(nx) && reg[nx] == -1){
//             backmarked[nx] = 1;
//             regions[rsz].push_back(nx), reg[nx] = rsz++;
//             flag = true;
//         }else{
//             if(reg[x] != -1) nx = -1;
//             if(in[x] == 1 && out[x] == 1 && nx != x && reg[x] == -1){
//                 regions[reg[nx]].push_back(x);
//                 reg[x] = reg[nx];
//                 flag = true;
//             }
//         }
//     }
//     if(!flag){
//         if(reg[x] == -1){
//             if((in[x] != 1 || out[x] != 1) && !mark(x)) backmarked[x] = 1;
//             if(mark(x))   regions[rsz].push_back(x), reg[x] = rsz++;
//         }
//         if(mark(x))   nx = x;
//         if(out[nx] > 1)   nx = -1;
//         
//     }   
//     rep[g.edge[x]](i, g.es[x]) dfs(i, nx);
// }
// 
// // we are going to build a tree based on the vertices that are unmarked and all the vertices have indegree 1
// // we will mark our vertices accordinly instead of rep(i,n) if((in[i] != 1 || out[i] != 1) && !mark(i)) backmarked[i] = 1;
// 
// //get the tree
// void dfs3(int x, int dis){
//     if(mark(x) || in[x] > 1) return;
//     if(vis2[x] == timestamp) return;
//     treenodes[tsz++] = x;
//     disdist.insert(dis);
//     vis2[x] = timestamp;
//     rep[g.edge[x]](i, g.es[x]) dfs3(i, dis+w[i]);
// }
// 
// bool dfs4(int x, int dis, double midist, double madist){
//     if(vis2[x] != timestamp) return false;
//     bool ret = false, ret2 = false;
//     if(midist+0.001 <= double(dis) <= madist-0.02){
//         ret2 = true;
//     }
//     int cnt = 0;
//     rep[g.edge[x]](i, g.es[x]){
//         ++cnt;
//         if(cnt == 1) ret = true;
//        auto xxx = dfs4(i, dis+w[i], midist, madist);
//        if(xxx != true){
//            ret = false;
//        }
//     } 
//     if(ret || ret2){
//         ++coverage;
//     }
//     return ret || ret2;
// }
// 
// bool markall(int x ,int dis, double midist, double madist, int rx){
//     if(vis2[x] != timestamp) return false;
//     bool ret = false, ret2 = false;
//     if(midist+0.001 <= double(dis) <= madist-0.02){
//         ret2 = true;
//     }
//     int cnt = 0;
//     rep[g.edge[x]](i, g.es[x]){
//         ++cnt;
//         if(cnt == 1) ret = true;
//         auto xxx = markall(i, dis+w[i], midist, madist, rx);
//         if(xxx != true){
//             ret = false;
//         }
//      } 
//      if(ret || ret2){
//         regions[rx].push_back(x);
//         reg[x] = rx;
//      }
//      return ret || ret2;
// }
// 
// 
// void dfs2(int x){
//     if(vis[x]) return;
//     vis[x] = 1;
//     if(reg[x] == -1){
//         ++timestamp;
//         tsz = 0;
//         disdist.clear();
//         dfs3(x, w[x]);
//         int bestcoverage = 0;
//         int yz = 0;
//         for(auto & y : disdist){
//             double madist = double(y);
//             double midist = madist * 0.9;
//             coverage = 0;
//             auto res =  dfs4(x, w[x], midist, madist);
//             if(res && coverage > bestcoverage) yz = y, bestcoverage = coverage;
//         }
//         if(yz > 0){
//             if(!mark(x)) backmarked[x] = 1;
//             double madist = double(yz);
//             double midist = madist * 0.9;
//             reg[x] = rsz++;
//             markall(x, w[x], midist, madist, reg[x]);
//         }
//     }
//     rep[g.edge[x]](i, g.es[x]) dfs2(i);
// }
// 
// 
// { 
//     rd(totalcases);
//     rep(tcases, totalcases){
//         if(dbg) wt("Case ", tcases, ":");
//         rep(i, rsz) regions[i].clear();        
//         rep(i, n) pa[i] = vx[i] = w[i] = u[i] = vx[i] = A[i] = B[i] = ans[i] =  marked[i] = backmarked[i] = in[i] = out[i]= dep[i] = vis[i] =  reg[i] =  0;
//         memset(firstfilled, 0, sizeof(firstfilled));
//         memset(reg, 0xff, sizeof(reg));
//         memset(vis2, 0, sizeof(vis2));
//         rsz =0;
//         asz = 0;
//         rd(n, w(n), k, (u--)(k), m, (A--,B--)(m) );
//         g.setDirectEdge(n, m, A, B);
//         rep(i, m) ++out[A[i]], ++in[B[i]];
//         rep(i, k) ++marked[u[i]];
//         dfs2(0);
//         rep(i, n) vis[i] = 0;
//         rep(i, n) if(reg[i] != -1) firstfilled[i] = 1;
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