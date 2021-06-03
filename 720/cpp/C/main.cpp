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
template<class S, class T> inline auto min_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a <= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
template<class S, class T> inline auto max_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a >= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
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
ofstream sf("transcript.txt");
const int dbg = 0;
const int human = 0;
int Tcases;
int n;
void init(){
  if(!dbg){
    rd(Tcases);
  }
  else{
    Tcases = 3;
    sf << Tcases <<endl;
  }
}
int ires[310];
const int len[] = {4,5, 6};
const int aas[3][6] = {{3,1,4,2,0, 0},{2,5,3,4,1, 0}, {6,2,4,3,1,5}};
int curcase = 0;
void init_n(){
  if(!dbg){
    rd(n);
    if(n == -1){
      exit(0);
    }
  }
  else{
    int i;
    n =  100;
    sf << n <<endl;
    for(i=(0);i<(100);i++){
      ires[i] = i+1;
    }
    ++curcase;
    random_shuffle(ires, ires+n);
    wt_L("Hint:");
    wt_L(' ');
    {
      int FJNsjZ7B;
      if(n==0){
        wt_L('\n');
      }
      else{
        for(FJNsjZ7B=(0);FJNsjZ7B<(n-1);FJNsjZ7B++){
          wt_L(ires[FJNsjZ7B]);
          wt_L(' ');
        }
        wt_L(ires[FJNsjZ7B]);
        wt_L('\n');
      }
    }
  }
}
int ask_upperbound;
int asktimes = 0;
int ask(int t, int i, int j , int x){
  if(!dbg){
    wt_L("?");
    wt_L(' ');
    wt_L(t);
    wt_L(' ');
    wt_L(i);
    wt_L(' ');
    wt_L(j);
    wt_L(' ');
    wt_L(x);
    wt_L('\n');
    int y;
    rd(y);
    if(y == -1){
      exit(0);
    }
    return y;
  }
  else{
    if(!human){
      wt_L("?");
      wt_L(' ');
      wt_L(t);
      wt_L(' ');
      wt_L(i);
      wt_L(' ');
      wt_L(j);
      wt_L(' ');
      wt_L(x);
      wt_L('\n');
    }
    int res = 0;
    int* p = ires - 1;
    if(t == 1){
      res =max_L(min_L(x, p[i]),min_L(x+1, p[j]));
    }
    else{
      res =min_L(max_L(x, p[i]),max_L(x+1, p[j]));
    }
    sf << res <<endl;
    return res;
  }
}
int ask_2(int t, int i, int j , int x){
  ++asktimes;
  if(i == j){
    return -1;
  }
  return ask(t, i, j, x);
}
void answer(int n, int * ans){
  if(!dbg){
    wt_L("!");
    wt_L(' ');
    {
      int VL854U43;
      if(n==0){
        wt_L('\n');
      }
      else{
        for(VL854U43=(0);VL854U43<(n-1);VL854U43++){
          wt_L(ans[VL854U43]);
          wt_L(' ');
        }
        wt_L(ans[VL854U43]);
        wt_L('\n');
      }
    }
  }
  else{
    int i;
    bool good = true;
    for(i=(0);i<(n);i++){
      if(ires[i] != ans[i]){
        good = false;
        wt_L("Wrong answer");
        wt_L('\n');
        exit(0);
      }
    }
  }
}
int ans[1000000];
int vis[1000000];
int rin[1000000][2];
set<int> cur[1000000];
int curid[1000000];
int main(){
  int Btiq50RC;
  init();
  int lo08wcHZ = Tcases;
  for(Btiq50RC=(0);Btiq50RC<(lo08wcHZ);Btiq50RC++){
    init_n();
    if(dbg && human){
      int i;
      wt_L(((3*n)/2)+30);
      wt_L('\n');
      for(i=(0);i<(((3*n)/2)+30);i++){
        int x;
        int y;
        int z;
        int w;
        rd(x);
        rd(y);
        rd(z);
        rd(w);
        wt_L(ask(x,y,z,w));
        wt_L('\n');
      }
    }
    if(!human){
      int i;
      ask_upperbound =  ((3*n)/2)+30;
      asktimes = 0 ;
      for(i=(0);i<(n+1);i++){
        cur[i].clear();
      }
      int csz = 0;
      for(i=(1);i<(n);i+=(2)){
        int gmax1 = ask_2(1, i, i+1, n-1);
        int gmax3 = ask_2(2, i,i+1,  1);
        cur[csz].insert(gmax1);
        cur[csz].insert(gmax3);
        rin[csz][0] = i;
        rin[csz][1] = i+1;
        curid[i]= csz;
        curid[i+1]= csz;
        ++csz;
      }
      int oneset[3];
      int osz =0;
      for(i=(0);i<(csz);i++){
        if(cur[i].find(1) != cur[i].end()){
          oneset[osz] = i;
          ++osz;
        }
        if(cur[i].find(2) != cur[i].end()){
          oneset[osz] = i;
          ++osz;
        }
      }
      if(osz == 1){
        oneset[osz] = csz;
        rin[csz][0] = n;
        rin[csz][1] = n;
        ++csz;
      }
      int oneind = 0;
      if(dbg){
        {
          int maNdQo4J;
          if(2==0){
            wt_L('\n');
          }
          else{
            for(maNdQo4J=(0);maNdQo4J<(2-1);maNdQo4J++){
              wt_L(oneset[maNdQo4J]);
              wt_L(' ');
            }
            wt_L(oneset[maNdQo4J]);
            wt_L('\n');
          }
        }
      }
      for(i=(0);i<(2);i++){
        int j;
        for(j=(0);j<(2);j++){
          if(ask_2(1, rin[oneset[0]][i],rin[oneset[1]][j], 1 ) == 1){
            oneind = rin[oneset[1]][j];
            break;
          }
          if(ask_2(1,rin[oneset[1]][j], rin[oneset[0]][i], 1 ) == 1){
            oneind = rin[oneset[0]][i];
            break;
          }
        }
      }
      if(dbg){
        wt_L(oneind);
        wt_L('\n');
      }
      ans[oneind] = 1;
      for(i=(1);i<(n+1);i++){
        vis[i] = 0;
      }
      int kid = 0;
      for(i=(1);i<(n+1);i++){
        if(i == oneind || vis[i]){
          continue;
        }
        ans[i] = ask_2(1, oneind, i, n-1);
        vis[i] = 1;
        int uuid = curid[i];
        if(i % 2== 0 || cur[uuid].find(n-1) != cur[uuid].end()){
          continue;
        }
        for(auto & x : cur[uuid]){
          if(x != ans[i]){
            ans[i+1] = x;
            vis[i+1] = 1;
          }
        }
      }
      ans[oneind] = 1;
      if(dbg){
        wt_L(asktimes);
        wt_L(' ');
        wt_L(ask_upperbound);
        wt_L('\n');
      }
      int* tmp = ans+1;
      if(dbg){
        {
          int YOSCSEHU;
          if(n==0){
            wt_L('\n');
          }
          else{
            for(YOSCSEHU=(0);YOSCSEHU<(n-1);YOSCSEHU++){
              wt_L(tmp[YOSCSEHU]);
              wt_L(' ');
            }
            wt_L(tmp[YOSCSEHU]);
            wt_L('\n');
          }
        }
      }
      answer(n, tmp);
    }
  }
  exit(0);
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// //interactive
// ofstream sf("transcript.txt");
// 
// const int dbg = 0;
// const int human = 0;
// int Tcases, n;
// void init(){
//     if(!dbg){
//         rd(Tcases);
//     }else{
//         Tcases = 3;
//         sf << Tcases <<endl;
// 
//     }
// }
// int ires[310];
// const int len[] = {4,5, 6};
// const int aas[3][6] = {{3,1,4,2,0, 0},{2,5,3,4,1, 0}, {6,2,4,3,1,5}};
// 
// int curcase = 0;
// void init_n(){
//     if(!dbg){
//         rd(n);
//         if(n == -1) exit(0);
// 
//     }else{
//         n =  100;
//         sf << n <<endl;
//         // rep(i, len[curcase] ) ires[i] = aas[curcase][i];
//         rep(i, 100 ) ires[i] = i+1;
//         ++curcase;
//         random_shuffle(ires, ires+n);
//         wt("Hint:", ires(n));
//     }
// }
// int ask_upperbound; 
// int asktimes = 0;
// 
// int ask(int t, int i, int j , int x){
//     if(!dbg){
//         wt("?", t, i, j,  x);
//         int y;
//         rd(y);
//         if(y == -1) exit(0);
//         return y;
//     }else{
//         // keeping the transcript so that we can use human intelligence 
//         if(!human) wt("?", t, i, j,  x);
//         int res = 0;
//         int * p = ires - 1;
//         if(t == 1){
//             res = max(min(x, p[i]), min(x+1, p[j]));
//         }else{
//             res = min(max(x, p[i]), max(x+1, p[j]));
//         }
//         sf << res <<endl;
//         
//         return res;
//     }
// }
// int ask_2(int t, int i, int j , int x){
//     ++asktimes;
//     if(i == j){
//         return -1;
//     }
//     return ask(t, i, j, x);
// }
// void answer(int n, int * ans){
//     if(!dbg){
//         wt("!", ans(n));
//     }else{
//         bool good = true;
//         rep(i, n){
//             if(ires[i] != ans[i]){
//                 good = false;
//                 wt("Wrong answer");
//                 exit(0);
//             }
//         }
//     }
// }
// int ans[1d6];
// int vis[1d6];
// int rin[1d6][2];
// 
// set<int> cur[1d6];
// int curid[1d6];
// 
// { 
//     init();
//     REP(Tcases){
//         init_n();
//         if(dbg && human){
//             wt(((3*n)/2)+30);
//             rep(i, ((3*n)/2)+30){
//                 int x,y,z,w;
//                 rd(x,y,z,w);
//                 wt(ask(x,y,z,w));
//             }
//         }
//         if(!human){
//             ask_upperbound =  ((3*n)/2)+30;            
//             asktimes = 0 ;
//             rep(i, 0, n+1){
//                 cur[i].clear();
//             }
//             int csz = 0;
//             rep(i, 1, n, 2){
//                 int gmax1 = ask_2(1, i, i+1, n-1);
//                 int gmax3 = ask_2(2, i,i+1,  1);
//                 cur[csz].insert(gmax1);
//                 cur[csz].insert(gmax3);
//                 rin[csz][0] = i;
//                 rin[csz][1] = i+1;
//                 curid[i]= csz;
//                 curid[i+1]= csz;
//                 ++csz;
//             }
//             int oneset[3], osz =0;
//             rep(i, csz){
//                 if(cur[i].find(1) != cur[i].end()){
//                     oneset[osz] = i;
//                     ++osz;
//                 }
//                 if(cur[i].find(2) != cur[i].end()){
//                     oneset[osz] = i;
//                     ++osz;
//                 }
//             }
//             if(osz == 1){
//                 oneset[osz] = csz;
//                 rin[csz][0] = n;
//                 rin[csz][1] = n;
//                 ++csz;
//             }
//             int oneind = 0;
//             if(dbg) wt(oneset(2));
//             rep(i, 2) rep(j, 2) {
//                 if(ask_2(1, rin[oneset[0]][i],rin[oneset[1]][j], 1 ) == 1){
//                     oneind = rin[oneset[1]][j];
//                     break;
//                 }
//                 if(ask_2(1,rin[oneset[1]][j], rin[oneset[0]][i], 1 ) == 1){
//                     oneind = rin[oneset[0]][i];
//                     break;
//                 }
//             }
//             if(dbg) wt(oneind);
//             ans[oneind] = 1;
//             rep(i, 1, n+1) vis[i] = 0;
//             int kid = 0;
//             rep(i, 1, n+1){
//                 if(i == oneind || vis[i]) continue; 
//                 ans[i] = ask_2(1, oneind, i, n-1);
//                 vis[i] = 1;
//                 int uuid = curid[i];
//                 if(i % 2== 0 || cur[uuid].find(n-1) != cur[uuid].end())  continue;
//                 for(auto & x : cur[uuid]){
//                     if(x != ans[i]) {
//                         ans[i+1] = x;
//                         vis[i+1] = 1;
//                     }
//                 }
//             }
//             ans[oneind] = 1;
//             if(dbg) wt(asktimes, ask_upperbound);
//             int * tmp = ans+1;
//             if(dbg) wt(tmp(n));
//             answer(n, tmp);
//         }
//     }
// 
//     exit(0);
// }
