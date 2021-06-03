#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
const int MN = 100000+10;
dynamic_hull_min cht;
long long n;
long long a[MN];
long long b[MN];
long long f[MN];
int main(){
  int i;
  rd(n);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(n);PiIOrLma++){
      rd(a[PiIOrLma]);
    }
  }
  {
    int GIHf_YD2;
    for(GIHf_YD2=(0);GIHf_YD2<(n);GIHf_YD2++){
      rd(b[GIHf_YD2]);
    }
  }
  cht.insert_line(b[0], 0);
  for(i=(1);i<(n);i++){
    f[i] = cht.eval(a[i]);
    cht.insert_line(b[i], f[i]);
  }
  wt_L(f[n-1]);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// const int MN = 1d5+10;
// dynamic_hull_min cht;
// 
// ll n, a[MN], b[], f[];
// { 
//     rd(n, a(n), b(n));
//     cht.insert_line(b[0], 0);
//     rep(i, 1, n){
//         f[i] = cht.eval(a[i]);
//         cht.insert_line(b[i], f[i]);
//     }
//     wt(f[n-1]);
// }
