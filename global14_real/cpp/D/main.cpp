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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
int n;
int l;
int r;
int c[200000+10];
int d[200000+10];
int idc(int x){
  if(x > 0){
    return 1;
  }
  else{
    return -1;
  }
}
int nidc(int x){
  if(x % 2 == 0){
    return 0;
  }
  return idc(x);
}
int oneway(){
  int i;
  for(i=(0);i<(n);i++){
    int p1 = 0;
    if( i < l){
      p1 = 1;
    }
    else{
      p1 = -1;
    }
    d[c[i]] += p1;
  }
  sortA_L(n+1, d);
  int pos = n;
  int pre = 0;
  int cost = 0;
  while(pre < pos){
    if(d[pre] >= 0 || d[pos] <= 0){
      break;
    }
    int delta =min_L(abs(d[pre]), abs(d[pos]));
    cost += delta;
    d[pos] -= delta;
    d[pre] += delta;
    if(d[pos] == 0){
      --pos;
    }
    if(d[pre] == 0){
      ++pre;
    }
  }
  for(i=(0);i<(n+2);i++){
    if(d[i] == 0){
      continue;
    }
    if(d[i] == idc(d[i])){
      continue;
    }
    cost += abs(d[i])/2;
    d[i] = nidc(d[i]);
  }
  int C3F7XFP2;
  int EZ0PmQmu;
  if(n+2==0){
    EZ0PmQmu = 0;
  }
  else{
    EZ0PmQmu = d[0];
    for(C3F7XFP2=(1);C3F7XFP2<(n+2);C3F7XFP2++){
      EZ0PmQmu += d[C3F7XFP2];
    }
  }
  int u = EZ0PmQmu;
  return (cost + abs(u));
}
int otherway(){
  int i;
  for(i=(0);i<(n);i++){
    int p1 = 0;
    if( i < l){
      p1 = 1;
    }
    else{
      p1 = -1;
    }
    d[c[i]] += p1;
  }
  int pos = n;
  int pre = 0;
  int cost = 0;
  for(i=(0);i<(n+2);i++){
    if(d[i] == 0){
      continue;
    }
    if(d[i] == idc(d[i])){
      continue;
    }
    cost += abs(d[i])/2;
    d[i] = nidc(d[i]);
  }
  sortA_L(n+1, d);
  while(pre < pos){
    if(d[pre] >= 0 || d[pos] <= 0){
      break;
    }
    int delta =min_L(abs(d[pre]), abs(d[pos]));
    cost += delta;
    d[pos] -= delta;
    d[pre] += delta;
    if(d[pos] == 0){
      --pos;
    }
    if(d[pre] == 0){
      ++pre;
    }
  }
  int Q7E_c5bj;
  int oGwDY68s;
  if(n+2==0){
    oGwDY68s = 0;
  }
  else{
    oGwDY68s = d[0];
    for(Q7E_c5bj=(1);Q7E_c5bj<(n+2);Q7E_c5bj++){
      oGwDY68s += d[Q7E_c5bj];
    }
  }
  int u = oGwDY68s;
  return (cost + abs(u));
}
int main(){
  int a3PBjchb;
  wmem = memarr;
  int j4Ja_un4 = rd_int();
  for(a3PBjchb=(0);a3PBjchb<(j4Ja_un4);a3PBjchb++){
    int i;
    rd(n);
    rd(l);
    rd(r);
    {
      int maNdQo4J;
      for(maNdQo4J=(0);maNdQo4J<(n);maNdQo4J++){
        rd(c[maNdQo4J]);
      }
    }
    wt_L(oneway());
    wt_L('\n');
    for(i=(0);i<(n + 10);i++){
      d[i] = 0;
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n, l, r, c[2d5+10], d[];
// int idc(int x){
//     if(x > 0) return 1;
//     else return -1;
// }
// int nidc(int x){
//     if(x % 2 == 0) return 0;
//     return idc(x);
// }
// 
// int oneway(){
//       rep(i, n){
//           int p1 = 0;
//           if( i < l) p1 = 1;
//           else p1 = -1;
//           d[c[i]] += p1;
//       }
//       sortA(n+1, d);
//       int pos = n;
//       int pre = 0;
//       int cost = 0;
// 
//       while(pre < pos){
//           if(d[pre] >= 0 || d[pos] <= 0) break;
//           int delta = min(abs(d[pre]), abs(d[pos]));
//           cost += delta;
//           d[pos] -= delta;
//           d[pre] += delta;
//           if(d[pos] == 0) --pos;
//           if(d[pre] == 0) ++pre;
//       }
//       rep(i, n+2){
//           if(d[i] == 0) continue;
//           if(d[i] == idc(d[i])) continue;
//           cost += abs(d[i])/2;
//           d[i] = nidc(d[i]);
//       }
//       int u = sum(d(n+2));      
//       return (cost + abs(u));
// 
// }
// 
// int otherway(){
//       rep(i, n){
//           int p1 = 0;
//           if( i < l) p1 = 1;
//           else p1 = -1;
//           d[c[i]] += p1;
//       }
//       int pos = n;
//       int pre = 0;
//       int cost = 0;
//       rep(i, n+2){
//           if(d[i] == 0) continue;
//           if(d[i] == idc(d[i])) continue;
//           cost += abs(d[i])/2;
//           d[i] = nidc(d[i]);
//       }
//       sortA(n+1, d);
// 
//       while(pre < pos){
//           if(d[pre] >= 0 || d[pos] <= 0) break;
//           int delta = min(abs(d[pre]), abs(d[pos]));
//           cost += delta;
//           d[pos] -= delta;
//           d[pre] += delta;
//           if(d[pos] == 0) --pos;
//           if(d[pre] == 0) ++pre;
//       }
//       
//       int u = sum(d(n+2));      
//       return (cost + abs(u));
// 
// }
// 
// { 
//   REP(rd_int()){
//       rd(n, l, r, c(n));
//       wt(oneway());
//       rep(i, 0, n + 10) d[i] = 0;
//   }
// }
