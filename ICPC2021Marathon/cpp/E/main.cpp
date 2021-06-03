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
template <class S, class T> struct cLtraits_common_type{
  using tS = typename cLtraits_try_make_signed<S>::type;
  using tT = typename cLtraits_try_make_signed<T>::type;
  using type = typename common_type<tS,tT>::type;
}
;
void*wmem;
char memarr[96000000];
template<class S, class T> inline auto min_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a <= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
template<class S, class T> inline auto max_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a >= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
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
    if(mark(x) && reg[x] == -1){
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
void dfs2(int x){
  int maNdQo4J;
  if(vis[x]){
    return;
  }
  vis[x] = 1;
  if(reg[x] == -1){
    if((in[x] != 1 || out[x] != 1)){
      int GIHf_YD2, i;
      vector<int> nvx;
      vector<int> stopped;
      vector<int> best;
      vector<int> csum;
      for(GIHf_YD2=(0);GIHf_YD2<(g.es[x]);GIHf_YD2++){
        auto&i = g.edge[x][GIHf_YD2];
        nvx.push_back(i);
      }
      int n = nvx.size();
      regions[rsz].push_back(x);
      reg[x] = rsz++;
      stopped.resize(n, 0);
      csum.resize(n, 0);
      best.resize(n, -1);
      priority_queue<pair<int,int>> pq;
      for(i=(0);i<(n);i++){
        pq.push(make_pair(i, csum[i]));
      }
      while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int idx = x.first;
        int v = nvx[idx];
        int val = x.second;
        if(in[v] > 1 || out[v] > 1 || mark(v)){
          stopped[idx] = 1;
        }
        if(stopped[idx]){
          continue;
        }
        csum[idx] += w[v];
        nvx[idx] = g.edge[v][0];
        pq.push(make_pair(idx, csum[idx]));
        int zxsUT70f;
        int VL854U43;
        if(n==0){
          VL854U43 = 0;
        }
        else{
          VL854U43 = csum[0];
          for(zxsUT70f=(1);zxsUT70f<(n);zxsUT70f++){
            VL854U43 = max_L(VL854U43, csum[zxsUT70f]);
          }
        }
        int umax = VL854U43;
        int OUHHcm5g;
        int o8AZ1iEn;
        if(n==0){
          o8AZ1iEn = 0;
        }
        else{
          o8AZ1iEn = csum[0];
          for(OUHHcm5g=(1);OUHHcm5g<(n);OUHHcm5g++){
            o8AZ1iEn = min_L(o8AZ1iEn, csum[OUHHcm5g]);
          }
        }
        int umin = o8AZ1iEn;
        if(double(umin)/ double(umax) > 0.9){
          for(i=(0);i<(n);i++){
            best[i] = nvx[i];
          }
        }
      }
      bool good = true;
      for(i=(0);i<(n);i++){
        if(best[i] == -1){
          good = false;
        }
      }
      if(good){
        for(i=(0);i<(g.es[x]);i++){
          nvx[i] = g.edge[x][i];
        }
        for(i=(0);i<(n);i++){
          int t = nvx[i];
          while(t != best[i]){
            regions[reg[x]].push_back(t);
            reg[t] = reg[x];
            t = g.edge[t][0];
          }
        }
      }
    }
  }
  for(maNdQo4J=(0);maNdQo4J<(g.es[x]);maNdQo4J++){
    auto&i = g.edge[x][maNdQo4J];
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
    rsz =0;
    asz = 0;
    rd(n);
    {
      int jmr1fsLB;
      for(jmr1fsLB=(0);jmr1fsLB<(n);jmr1fsLB++){
        rd(w[jmr1fsLB]);
      }
    }
    rd(k);
    {
      int HXvIelve;
      for(HXvIelve=(0);HXvIelve<(k);HXvIelve++){
        rd(u[HXvIelve]);u[HXvIelve] += (-1);
      }
    }
    rd(m);
    {
      int CJfDDKIC;
      for(CJfDDKIC=(0);CJfDDKIC<(m);CJfDDKIC++){
        rd(A[CJfDDKIC]);A[CJfDDKIC] += (-1);
        rd(B[CJfDDKIC]);B[CJfDDKIC] += (-1);
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
      int EnswEVQX;
      if(asz==0){
        wt_L('\n');
      }
      else{
        for(EnswEVQX=(0);EnswEVQX<(asz-1);EnswEVQX++){
          wt_L(ans[EnswEVQX]);
          wt_L(' ');
        }
        wt_L(ans[EnswEVQX]);
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
        int bttSHapQ;
        if(asz==0){
          wt_L('\n');
        }
        else{
          for(bttSHapQ=(0);bttSHapQ<(asz-1);bttSHapQ++){
            wt_L(ans[bttSHapQ]);
            wt_L(' ');
          }
          wt_L(ans[bttSHapQ]);
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
//         if(mark(x) && reg[x] == -1)   regions[rsz].push_back(x), reg[x] = rsz++;
//         if(mark(x))   nx = x;
//         if(out[nx] > 1)   nx = -1;
//         
//     }   
//     rep[g.edge[x]](i, g.es[x]) dfs(i, nx);
// }
// 
// void dfs2(int x){
//     if(vis[x]) return;
//     vis[x] = 1;
//     if(reg[x] == -1){
//         if((in[x] != 1 || out[x] != 1)){
//             // do the fan-outs
//             vector<int> nvx;
//             vector<int> stopped;
//             vector<int> best;
//             vector<int> csum;
//             rep[g.edge[x]](i, g.es[x]) nvx.push_back(i);
//             int n = nvx.size();
//             regions[rsz].push_back(x), reg[x] = rsz++;
//             stopped.resize(n, 0); csum.resize(n, 0); best.resize(n, -1);
//             priority_queue<pair<int,int>> pq;
//             rep(i, n) pq.push(make_pair(i, csum[i]));
//             while(!pq.empty()){
//                 auto x = pq.top(); pq.pop();
//                 int idx = x.first;
//                 int v = nvx[idx]; int val = x.second;
//                 if(in[v] > 1 || out[v] > 1 || mark(v)) stopped[idx] = 1;
//                 if(stopped[idx]) continue;
//                 csum[idx] += w[v];
//                 nvx[idx] = g.edge[v][0]; // next vertex
//                 pq.push(make_pair(idx, csum[idx]));
//                 int umax = max(csum(n));
//                 int umin = min(csum(n));
//                 if(double(umin)/ double(umax) > 0.9) { rep(i, n) best[i] = nvx[i];}
//             }
//             bool good = true;
//             rep(i, n) if(best[i] == -1) good = false;
//             if(good){
//                 rep(i, g.es[x]) nvx[i] = g.edge[x][i];
//                 rep(i, n){
//                     int t = nvx[i];
//                     while(t != best[i]){
//                         regions[reg[x]].push_back(t); reg[t] = reg[x];
//                         t = g.edge[t][0];
//                     }
//                 } 
//             }
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
//         rsz =0;
//         asz = 0;
//         rd(n, w(n), k, (u--)(k), m, (A--,B--)(m) );
//         g.setDirectEdge(n, m, A, B);
//         rep(i, m) ++out[A[i]], ++in[B[i]];
//         rep(i, k) ++marked[u[i]];
//         rep(i,n) if((in[i] != 1 || out[i] != 1) && !mark(i)) backmarked[i] = 1;
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