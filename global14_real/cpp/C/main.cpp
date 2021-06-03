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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int pre[100000+10];
int m ;
int n;
int X;
int idx[100000+10];
int a[100000+10];
int ans[100000+10];
int v[100000+10];
#define pii pair<int,int>
#define val first
#define sid second
#define mp make_pair
#define pq_type priority_queue<pii>
int main(){
  int PiIOrLma;
  wmem = memarr;
  int AuJVIghY = rd_int();
  for(PiIOrLma=(0);PiIOrLma<(AuJVIghY);PiIOrLma++){
    int i;
    rd(n);
    rd(m);
    rd(X);
    {
      int djQeACzd;
      for(djQeACzd=(0);djQeACzd<(n);djQeACzd++){
        rd(a[djQeACzd]);
      }
    }
    for(i=(0);i<(n);i++){
      idx[i] = i;
    }
    sortA_L(n, a, idx);
    pq_type pq;
    for(i=(0);i<(m);i++){
      pq.push(mp(0, i+1));
    }
    for(i=(0);i<(n);i++){
      auto u = pq.top();
      pq.pop();
      ans[idx[i]] = u.sid;
      pq.push(mp(u.val-a[i], u.sid));
    }
    int vsz = 0;
    while(!pq.empty()){
      v[vsz++] = -pq.top().val;
      pq.pop();
    }
    sortA_L(vsz, v);
    bool flag = true;
    int gt = 0;
    int lt = 1073709056;
    for(i=(0);i<(vsz);i++){
      gt =max_L(v[i]-X, gt);
      lt =min_L(v[i]+X, lt);
    }
    if(lt < gt){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    wt_L("YES");
    wt_L('\n');
    {
      int Y0H_suZr;
      if(n==0){
        wt_L('\n');
      }
      else{
        for(Y0H_suZr=(0);Y0H_suZr<(n-1);Y0H_suZr++){
          wt_L(ans[Y0H_suZr]);
          wt_L(' ');
        }
        wt_L(ans[Y0H_suZr]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int pre[1d5+10], m , n, X;
// int idx[], a[], ans[], v[];
// #define pii pair<int,int>
// #define val first
// #define sid second
// #define mp make_pair
// #define pq_type priority_queue<pii>
// 
// { 
//   REP(rd_int()){
//     rd(n,m , X, a(n));
//     rep(i, n) idx[i] = i;
//     sortA(n, a, idx);
//     pq_type pq;
//     rep(i, m){
//         pq.push(mp(0, i+1));
//     }
//     rep(i, n){
//         auto u = pq.top(); pq.pop();
//         ans[idx[i]] = u.sid;
//         pq.push(mp(u.val-a[i], u.sid));
//     }
//     int vsz = 0;
//     while(!pq.empty()){
//         v[vsz++] = -pq.top().val; pq.pop();
//     }
//     sortA(vsz, v);
//     bool flag = true;
//     int gt = 0, lt = int_inf;
//     rep(i, vsz){
//         gt = max(v[i]-X, gt);
//         lt = min(v[i]+X, lt);
//     }
//     if(lt < gt){
//         wt("NO"); continue;
//     }
//     wt("YES");
//     wt(ans(n));
//   }
// }
