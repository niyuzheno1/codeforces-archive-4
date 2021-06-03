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
      fwrite_unlocked(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar_unlocked(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite_unlocked(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a){
  my_putchar_unlocked(a);
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
    my_putchar_unlocked('-');
  }
  while(s--){
    my_putchar_unlocked(f[s]+'0');
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
    my_putchar_unlocked('E');
    my_putchar_unlocked('r');
    my_putchar_unlocked('r');
    return;
  }
  if(x < 0){
    my_putchar_unlocked('-');
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
    my_putchar_unlocked(k + '0');
  }
  if(d > 0){
    my_putchar_unlocked('.');
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
      my_putchar_unlocked(k + '0');
    }
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar_unlocked(c[i]);
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
#include<random>
void runcmd(string a, string b, string c){
  string cmd;
  cmd += a;
  cmd += b;
  cmd += c;
  system(cmd.c_str());
}
ifstream fin;
ifstream fout;
int n;
int w[5000+10];
int k;
int u[5000+10];
int m;
int A[5000+10];
int B[5000+10];
int marked[5000+10];
int reg[5000+10];
int wh[5000+10];
int regsz;
int vis[5000+10];
int visreg[5000+10];
graph g;
vector<int> regions[5000+10];
int min_w_rp[5000+10];
int max_w_rp[5000+10];
bool dfs(int x){
  int djQeACzd;
  ++vis[x];
  ++visreg[reg[x]];
  wh[reg[x]] += w[x];
  if(x == n-1){
    int i;
    for(i=(0);i<(regsz);i++){
      int j;
      if(visreg[i] == 0){
        continue;
      }
      for(j=(0);j<(regions[i].size());j++){
        if(marked[regions[i][j]] && vis[regions[i][j]] <= 0){
          return false;
        }
      }
      if(wh[i] < min_w_rp[i]){
        min_w_rp[i] = wh[i];
      }
      if(wh[i] > max_w_rp[i]){
        max_w_rp[i] = wh[i];
      }
    }
    --vis[x];
    --visreg[reg[x]];
    wh[reg[x]] -= w[x];
    return true;
  }
  bool ret = true;
  for(djQeACzd=(0);djQeACzd<(g.es[x]);djQeACzd++){
    auto&i = g.edge[x][djQeACzd];
    auto tmpret = dfs(i);
    ret = ret && tmpret;
  }
  --vis[x];
  --visreg[reg[x]];
  wh[reg[x]] -= w[x];
  return ret;
}
bool process(){
  int i;
  for(i=(0);i<(5000+9);i++){
    regions[i].clear();
  }
  memset(visreg, 0, sizeof(visreg));
  memset(min_w_rp, 0x7f, sizeof(min_w_rp));
  memset(max_w_rp, 0, sizeof(max_w_rp));
  memset(w, 0, sizeof(w));
  memset(u, 0, sizeof(u));
  memset(A, 0, sizeof(A));
  memset(B, 0, sizeof(B));
  memset(marked, 0, sizeof(marked));
  memset(reg, 0xff, sizeof(reg));
  memset(wh, 0, sizeof(wh));
  memset(vis, 0, sizeof(vis));
  fin >> n;
  for(i=(0);i<(n);i++){
    fin >> w[i];
  }
  fin >> k;
  for(i=(0);i<(k);i++){
    fin >> u[i];
    --u[i];
  }
  fin >> m;
  for(i=(0);i<(m);i++){
    fin >> A[i] >> B[i];
    --A[i];
    --B[i];
  }
  g.setDirectEdge(n, m, A, B);
  for(i=(0);i<(k);i++){
    ++marked[u[i]];
  }
  int q;
  fout >> q;
  for(i=(0);i<(q);i++){
    int x;
    fout >> x;
    --x;
    ++marked[x];
  }
  for(i=(0);i<(n);i++){
    if(marked[i] > 1){
      return false;
    }
  }
  fout >> regsz;
  for(i=(0);i<(regsz);i++){
    int j;
    int sn;
    fout >> sn;
    bool flag = false;
    for(j=(0);j<(sn);j++){
      int x;
      fout >> x;
      --x;
      regions[i].push_back(x);
      if(marked[x]){
        flag = true;
      }
      if(reg[x] != -1){
        return false;
      }
      reg[x] = i;
    }
    if(!flag){
      return false;
    }
  }
  for(i=(0);i<(n);i++){
    if(reg[i] == -1){
      return false;
    }
  }
  auto res = dfs(0);
  if(res == false){
    return false;
  }
  for(i=(0);i<(regsz);i++){
    double scorex = min_w_rp[i];
    double scorey = max_w_rp[i];
    if(scorex/scorey < 0.9){
      return false;
    }
    wt_L("metadata: ");
    wt_L(' ');
    wt_L(scorex/scorey);
    wt_L('\n');
  }
  return true;
}
int main(){
  int LiLe88qh;
  wmem = memarr;
  int totalcases = 100;
  srand (12304);
  for(LiLe88qh=(0);LiLe88qh<(totalcases);LiLe88qh++){
    int tcase;
    int seed = rand()%10000;
    wt_L("seeds");
    wt_L(' ');
    wt_L(seed);
    wt_L('\n');
    bool ac = true;
    string cmd1;
    runcmd("C:\\Users\\zachn\\OneDrive\\Documents\\codeforces\\ICPC2021Marathon\\cpp\\testset\\testsetA.exe " , to_string(seed), "  < ins.txt > input.txt " );
    runcmd("C:\\Users\\zachn\\OneDrive\\Documents\\codeforces\\ICPC2021Marathon\\cpp\\F\\main.exe < input.txt > output.txt" , "" ,"");
    fin = ifstream("input.txt");
    fout= ifstream("output.txt");
    int totalcases;
    fin >> totalcases;
    for(tcase=(0);tcase<(totalcases);tcase++){
      if(!process()){
        wt_L("Case:");
        wt_L(' ');
        wt_L(tcase+1);
        wt_L('\n');
        ac = false;
        break;
      }
    }
    if(ac){
      wt_L("Successfully Pass All the Test Cases!");
      wt_L('\n');
    }
    else{
      {
        int uiJcr1yF;
        if(n==0){
          wt_L('\n');
        }
        else{
          for(uiJcr1yF=(0);uiJcr1yF<(n-1);uiJcr1yF++){
            wt_L(w[uiJcr1yF]);
            wt_L(' ');
          }
          wt_L(w[uiJcr1yF]);
          wt_L('\n');
        }
      }
      wt_L("wrong answer");
      wt_L('\n');
      exit(0);
    }
    fin.close();
    fout.close();
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// #include<random>
// 
// 
// void runcmd(string a, string b, string c){
//     string cmd;
//     cmd += a; cmd += b; cmd += c;
//     system(cmd.c_str());
// }
// 
// ifstream fin;
// ifstream fout;
// 
// int n, w[5d3+10], k, u[], m, A[], B[], marked[], reg[], wh[], regsz, vis[], visreg[];
// graph g;
// VI regions[];
// int min_w_rp[], max_w_rp[];
// bool dfs(int x){
//     ++vis[x];
//     ++visreg[reg[x]];
//     wh[reg[x]] += w[x];
//     if(x == n-1){
//         rep(i, regsz){
//             if(visreg[i] == 0) continue;
//             rep(j, regions[i].size()) if(marked[regions[i][j]] && vis[regions[i][j]] <= 0)  return false;
//             // compute the min and max
//             if(wh[i] < min_w_rp[i]) min_w_rp[i] = wh[i];
//             if(wh[i] > max_w_rp[i]) max_w_rp[i] = wh[i];
//         }
//         --vis[x];
//         --visreg[reg[x]];
//         wh[reg[x]] -= w[x];
//         return true;
//     }
//     bool ret = true;
//     rep[g.edge[x]](i, g.es[x]){
//         auto tmpret = dfs(i);
//         ret = ret && tmpret;
//     }
//     --vis[x];
//     --visreg[reg[x]];
//     wh[reg[x]] -= w[x];
//     return ret;
// }
// 
// bool process(){
//     rep(i, 5d3+9) regions[i].clear();
//     memset(visreg, 0, sizeof(visreg));
//     memset(min_w_rp, 0x7f, sizeof(min_w_rp));
//     memset(max_w_rp, 0, sizeof(max_w_rp));
//     memset(w, 0, sizeof(w)); memset(u, 0, sizeof(u)); memset(A, 0, sizeof(A)); memset(B, 0, sizeof(B)); memset(marked, 0, sizeof(marked));
//     memset(reg, 0xff, sizeof(reg)); memset(wh, 0, sizeof(wh)); memset(vis, 0, sizeof(vis));
//     fin >> n; rep(i, n) fin >> w[i]; fin >> k;
//     rep(i, k) fin >> u[i], --u[i];
//     fin >> m; rep(i, m) fin >> A[i] >> B[i], --A[i], --B[i];
//     g.setDirectEdge(n, m, A, B);
//     rep(i, k) ++marked[u[i]];
//     int q; fout >> q;
//     rep(i, q){
//         int x; 
//         fout >> x; --x;
//         ++marked[x];
//     }
//     rep(i, n) if(marked[i] > 1) return false;
//     fout >> regsz;
//     rep(i, regsz){
//         int sn; 
//         fout >> sn;
//         bool flag = false;
//         rep(j, sn){ int x;  fout >> x; --x; regions[i].push_back(x); 
//             if(marked[x]) flag = true;
//             if(reg[x] != -1) return false; //two region intersect
//             reg[x] = i; 
//         }
//         if(!flag) return false; // at least one marked node
//     }
//     rep(i, n) if(reg[i] == -1) return false;
//     auto res = dfs(0); //enumerate all the full path
//     if(res == false){
//         return false;
//     }
//     rep(i, regsz){
//         double scorex = min_w_rp[i];
//         double scorey = max_w_rp[i];
//         if(scorex/scorey < 0.9){
//             return false;
//         }
//         wt("metadata: ", scorex/scorey );
//     }
//     return true;
// }
// 
// {
//     int totalcases = 100;
//     srand (12304);
//     rep(totalcases){
//         int seed = rand()%10000;
//         wt("seeds", seed);
//         bool ac = true;
//         string cmd1; 
//         runcmd("C:\\Users\\zachn\\OneDrive\\Documents\\codeforces\\ICPC2021Marathon\\cpp\\testset\\testsetA.exe " , to_string(seed), "  < ins.txt > input.txt " );
//         runcmd("C:\\Users\\zachn\\OneDrive\\Documents\\codeforces\\ICPC2021Marathon\\cpp\\F\\main.exe < input.txt > output.txt" , "" ,"");
//         fin = ifstream("input.txt");
//         fout= ifstream("output.txt");
//         int totalcases;
//         fin >> totalcases;
//         rep(tcase, totalcases){
//             if(!process()){
//                 wt("Case:", tcase+1);
//                 ac = false;
//                 break;
//             }
//         }
//         if(ac) wt( "Successfully Pass All the Test Cases!");
//         else{
//             wt(w(n));
//             wt("wrong answer");
//             exit(0);
//         }
//         fin.close();
//         fout.close();
//     }
//     
// 
//     return 0;
// }
