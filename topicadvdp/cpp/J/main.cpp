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
inline void rd(long long &x){
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
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
const long long is_query_G = -(1LL<<62);
template<class T> struct line_G{
  T m;
  T b;
  mutable function<const line_G*()> succ;
}
;
template<class T> bool operator<(const line_G<T> & lhs, const line_G<T> & rhs){
  if (rhs.b != is_query_G){
    return lhs.m < rhs.m;
  }
  const line_G<T>* s = lhs.succ();
  if (!s){
    return 0;
  }
  T x = rhs.m;
  return lhs.b - s->b < (s->m - lhs.m) * x;
}
template<class T> struct dynamic_hull_max : public multiset<line_G<T>>{
  const long long inf = LLONG_MAX;
  bool bad(void * yy){
    iterator * u = (iterator *)yy;
    iterator y = *u;
    auto z = next(y);
    if (y == begin()){
      if (z == end()){
        return 0;
      }
      return y->m == z->m && y->b <= z->b;
    }
    auto x = prev(y);
    if (z == end()){
      return y->m == x->m && y->b <= x->b;
    }
    T v1 = (x->b - y->b);
    if (y->m == x->m){
      v1 = x->b > y->b ? inf : -inf;
    }
    else{
      v1 /= (y->m - x->m);
    }
    T v2 = (y->b - z->b);
    if (z->m == y->m){
      v2 = y->b > z->b ? inf : -inf;
    }
    else{
      v2 /= (z->m - y->m);
    }
    return v1 >= v2;
  }
  void insert_line(T m, T b){
    auto y = insert({ m, b });
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad((void*)&y)){
      erase(y);
      return;
    }
    while (next(y) != end()){
      auto yy = next(y);
      if(bad((void*)&yy)){
        erase(next(y));
      }
      else{
        break;
      }
    }
    while (y != begin()){
      auto yy = prev(y);
      if(bad((void*)&yy)){
        erase(prev(y));
      }
      else{
        break;
      }
    }
  }
  T eval(T x){
    line_G<T> tmp;
    tmp.b = is_query_G;
    tmp.m = x;
    auto l = *lower_bound(tmp);
    return l.m * x + l.b;
  }
}
;
template<class T> struct dynamic_hull_min{
  dynamic_hull_max<T> cht;
  void insert_line(T m, T b){
    cht.insert_line(-m, -b);
  }
  T eval(T x){
    return -cht.eval(x);
  }
}
;
int n;
long long s;
int v[200000+10];
int c[200000+10];
dynamic_hull_max<long long> cht;
long long dp[200000+10];
int main(){
  int i;
  wmem = memarr;
  rd(n);
  rd(s);
  {
    int djQeACzd;
    for(djQeACzd=(0);djQeACzd<(n);djQeACzd++){
      rd(v[djQeACzd]);
      rd(c[djQeACzd]);
    }
  }
  sortA_L(n, c, v);
  if(c[0] != 0){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  cht.insert_line(v[0],0);
  long long ans =(divup_L(s,v[0]));
  for(i=(1);i<(n);i++){
    long long EZ0PmQmu;
    long long zxsUT70f;
    long long VL854U43;
    EZ0PmQmu = dp[i-1];
    zxsUT70f = s+10;
    while(EZ0PmQmu < zxsUT70f){
      if((EZ0PmQmu + zxsUT70f)%2==0){
        VL854U43 = (EZ0PmQmu + zxsUT70f) / 2;
      }
      else{
        VL854U43 = (EZ0PmQmu + zxsUT70f - 1) / 2;
      }
      if(cht.eval(VL854U43) >= c[i]){
        zxsUT70f = VL854U43;
      }
      else{
        EZ0PmQmu = VL854U43 + 1;
      }
    }
    auto xx =zxsUT70f;
    dp[i] = xx;
    auto mi = cht.eval(xx) - c[i];
    cht.insert_line(v[i], -dp[i]*v[i] + mi);
    chmin(ans, xx +(divup_L((s-mi),(v[i]))));
  }
  wt_L(ans);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// const long long is_query_G = -(1LL<<62);
// 
// template<class T> struct line_G{
//   T m;
//   T b;
//   mutable function<const line_G*()> succ;
// }
// ;
// template<class T> bool operator<(const line_G<T> & lhs, const line_G<T> & rhs){
//   if (rhs.b != is_query_G){
//     return lhs.m < rhs.m;
//   }
//   const line_G<T> * s = lhs.succ();
//   if (!s){
//     return 0;
//   }
//   T x = rhs.m;
//   return lhs.b - s->b < (s->m - lhs.m) * x;
// }
// template<class T> 
// struct dynamic_hull_max : public multiset<line_G<T>>{
//   const long long inf = LLONG_MAX;
//   bool bad(void * yy){
//     iterator * u = (iterator *)yy;
//     iterator y = *u;
//     auto z = next(y);
//     if (y == begin()){
//       if (z == end()){
//         return 0;
//       }
//       return y->m == z->m && y->b <= z->b;
//     }
//     auto x = prev(y);
//     if (z == end()){
//       return y->m == x->m && y->b <= x->b;
//     }
//     T v1 = (x->b - y->b);
//     if (y->m == x->m){
//       v1 = x->b > y->b ? inf : -inf;
//     }
//     else{
//       v1 /= (y->m - x->m);
//     }
//     T v2 = (y->b - z->b);
//     if (z->m == y->m){
//       v2 = y->b > z->b ? inf : -inf;
//     }
//     else{
//       v2 /= (z->m - y->m);
//     }
//     return v1 >= v2;
//   }
//   void insert_line(T m, T b){
//     auto y = insert({ m, b });
//     y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
//     if (bad((void*)&y)){
//       erase(y);
//       return;
//     }
//     while (next(y) != end()){
//       auto yy = next(y);
//       if(bad((void*)&yy)){
//         erase(next(y));
//       }
//       else{
//         break;
//       }
//     }
//     while (y != begin()){
//       auto yy = prev(y);
//       if(bad((void*)&yy)){
//         erase(prev(y));
//       }
//       else{
//         break;
//       }
//     }
//   }
//   T eval(T x){
//     line_G<T> tmp;
//     tmp.b = is_query_G;
//     tmp.m = x;
//     auto l = *lower_bound(tmp);
//     return l.m * x + l.b;
//   }
// }
// ;
// template<class T> 
// struct dynamic_hull_min{
//   dynamic_hull_max<T> cht;
//   void insert_line(T m, T b){
//     cht.insert_line(-m, -b);
//   }
//   T eval(T x){
//     return -cht.eval(x);
//   }
// }
// ;
// int n;
// ll s;
// int v[2d5+10], c[];
// dynamic_hull_max<ll> cht;
// ll dp[];
// { 
//     rd(n, s, (v,c)(n));
//     sortA(n, c, v);
//     if(c[0] != 0){
//         wt(-1);
//         return 0;
//     }
//     cht.insert_line(v[0],0);
//     ll ans = s/+v[0];
//     rep(i, 1, n){
//         auto xx = bsearch_min[ll, T, dp[i-1], s+10](cht.eval(T) >= c[i]);
//         dp[i] = xx;
//         auto mi = cht.eval(xx) - c[i];
//         cht.insert_line(v[i], -dp[i]*v[i] + mi);
//         ans <?= xx + (s-mi) /+ (v[i]);
//     }
//     wt(ans);
// }
