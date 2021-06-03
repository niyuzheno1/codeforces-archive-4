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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
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
  int TopologicalSort(int res[], void *mem=wmem){
    int i;
    int j;
    int k;
    int rs;
    int*deg;
    int*q;
    int qs = 0;
    int qe = 0;
    walloc1d(&deg, N, &mem);
    walloc1d(&q, N, &mem);
    rs = 0;
    for(i=(0);i<(N);i++){
      deg[i] = 0;
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(es[i]);j++){
        deg[edge[i][j]]++;
      }
    }
    for(i=(0);i<(N);i++){
      if(deg[i]==0){
        q[qe++] = i;
      }
    }
    while(qs < qe){
      i = q[qs++];
      res[rs++] = i;
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        deg[k]--;
        if(deg[k]==0){
          q[qe++] = k;
        }
      }
    }
    if(rs==N){
      return 1;
    }
    return 0;
  }
}
;
int n;
int m;
int f[300000+10][28];
int A[300000+10];
int B[300000+10];
char s[300000+10];
graph g;
int res[300000+10];
int main(){
  int Z8lEHcvz, i;
  wmem = memarr;
  rd(n);
  rd(m);
  rd(s);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(m);PiIOrLma++){
      rd(A[PiIOrLma]);A[PiIOrLma] += (-1);
      rd(B[PiIOrLma]);B[PiIOrLma] += (-1);
    }
  }
  for(i=(0);i<(n);i++){
    s[i] -= 'a';
  }
  g.setDirectEdge(n, m, A, B);
  int ret =  g.TopologicalSort(res);
  if(ret == 0){
    wt_L(-1);
    wt_L('\n');
    exit(0);
  }
  int ans = 0;
  for(Z8lEHcvz=(0);Z8lEHcvz<(n);Z8lEHcvz++){
    int C3F7XFP2;
    auto&i = res[Z8lEHcvz];
    ++f[i][s[i]];
    chmax(ans, f[i][s[i]]);
    for(C3F7XFP2=(0);C3F7XFP2<(g.es[i]);C3F7XFP2++){
      int k;
      auto&j = g.edge[i][C3F7XFP2];
      for(k=(0);k<(28);k++){
        chmax(f[j][k], f[i][k]);
        chmax(ans, f[j][k]);
      }
    }
  }
  wt_L(ans);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n, m;
// int f[3d5+10][28], A[3d5+10], B[3d5+10];
// char s[3d5+10];
// graph g;
// int res[];
// { 
//     rd(n, m, s, (A--,B--)(m));
//     rep(i, n) s[i] -= 'a';
//     g.setDirectEdge(n, m, A, B);
//     int ret =  g.TopologicalSort(res);
//     if(ret == 0){
//         wt(-1);
//         exit(0);
//     }
//     int ans = 0;
//     rep[res](i, n){
//         ++f[i][s[i]];
//         ans >?= f[i][s[i]];
//         rep[g.edge[i]](j, g.es[i]){
//             rep(k, 28){
//                 f[j][k] >?= f[i][k];
//                 ans >?= f[j][k]; 
//             }
//         }
//     }
//     wt(ans);
// }
