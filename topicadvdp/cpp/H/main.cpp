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
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> >*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
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
const long long is_query_G = -(1LL<<62);
struct line_G{
  long long m;
  long long b;
  mutable function<const line_G*()> succ;
}
;
bool operator<(const line_G& lhs, const line_G& rhs){
  if (rhs.b != is_query_G){
    return lhs.m < rhs.m;
  }
  const line_G* s = lhs.succ();
  if (!s){
    return 0;
  }
  long long x = rhs.m;
  return lhs.b - s->b < (s->m - lhs.m) * x;
}
struct dynamic_hull_max : public multiset<line_G>{
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
    long long v1 = (x->b - y->b);
    if (y->m == x->m){
      v1 = x->b > y->b ? inf : -inf;
    }
    else{
      v1 /= (y->m - x->m);
    }
    long long v2 = (y->b - z->b);
    if (z->m == y->m){
      v2 = y->b > z->b ? inf : -inf;
    }
    else{
      v2 /= (z->m - y->m);
    }
    return v1 >= v2;
  }
  void insert_line(long long m, long long b){
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
  long long eval(long long x){
    line_G tmp;
    tmp.b = is_query_G;
    tmp.m = x;
    auto l = *lower_bound(tmp);
    return l.m * x + l.b;
  }
}
;
struct dynamic_hull_min{
  dynamic_hull_max cht;
  void insert_line(long long m, long long b){
    cht.insert_line(-m, -b);
  }
  long long eval(long long x){
    return -cht.eval(x);
  }
}
;
int n;
long long x[1000000+10];
long long y[1000000+10];
long long a[1000000+10];
long long f[1000000+10];
dynamic_hull_max cht;
int main(){
  int i;
  wmem = memarr;
  rd(n);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(n);PiIOrLma++){
      rd(x[PiIOrLma]);
      rd(y[PiIOrLma]);
      rd(a[PiIOrLma]);
    }
  }
  sortA_L(n, x, y, a);
  cht.insert_line(0,0);
  for(i=(0);i<(n);i++){
    f[i] = cht.eval(y[i]) + x[i]*y[i] - a[i];
    cht.insert_line(-x[i], f[i]);
  }
  int Z8lEHcvz;
  cLtraits_try_make_signed<remove_reference<decltype((*((long long*)NULL)))>::type>::type rbGYC8dh;
  if(n==0){
    rbGYC8dh = 0;
  }
  else{
    rbGYC8dh = f[0];
    for(Z8lEHcvz=(1);Z8lEHcvz<(n);Z8lEHcvz++){
      rbGYC8dh = max_L(rbGYC8dh, f[Z8lEHcvz]);
    }
  }
  wt_L(rbGYC8dh);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n;
// ll x[1d6+10], y[], a[], f[];
// dynamic_hull_max cht;
// {
//     rd(n, (x,y,a)(n));
//     sortA(n, x, y, a);
//     cht.insert_line(0,0);
//     rep(i, n){
//         f[i] = cht.eval(y[i]) + x[i]*y[i] - a[i];
//         cht.insert_line(-x[i], f[i]);
//     }
//     wt(max(f(n)));
// }
