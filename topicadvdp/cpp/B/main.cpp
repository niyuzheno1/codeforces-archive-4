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
const long long is_query = -(1LL<<62);
struct line{
  long long m;
  long long b;
  mutable function<const line*()> succ;
}
;
bool operator<(const line& lhs, const line& rhs){
  if (rhs.b != is_query){
    return lhs.m < rhs.m;
  }
  const line* s = lhs.succ();
  if (!s){
    return 0;
  }
  long long x = rhs.m;
  return lhs.b - s->b < (s->m - lhs.m) * x;
}
struct dynamic_hull : public multiset<line>{
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
    line tmp;
    tmp.b = is_query;
    tmp.m = x;
    auto l = *lower_bound(tmp);
    return l.m * x + l.b;
  }
}
;
int n;
long long a[200000+10];
long long b[200000+10];
long long p[200000+10];
long long pre(int x){
  if(x < 0){
    return 0;
  }
  return p[x];
}
dynamic_hull cht;
long long f[200000+10];
int main(){
  int i;
  rd(n);
  {
    int djQeACzd;
    for(djQeACzd=(0);djQeACzd<(n);djQeACzd++){
      rd(a[djQeACzd]);
    }
  }
  {
    int NN9wFlop;
    for(NN9wFlop=(0);NN9wFlop<(n);NN9wFlop++){
      rd(b[NN9wFlop]);
    }
  }
  for(i=(0);i<(n);i++){
    if(i == 0){
      p[i] =0+ a[i];
    }
    else{
      p[i] =p[i-1]+ a[i];
    }
  }
  cht.insert_line(0, 0);
  for(i=(1);i<(n);i++){
    f[i] = b[i] * pre(i) - cht.eval(b[i]);
    cht.insert_line(pre(i-1), -f[i]);
  }
  {
    int OUHHcm5g;
    if(n==0){
      wt_L('\n');
    }
    else{
      for(OUHHcm5g=(0);OUHHcm5g<(n-1);OUHHcm5g++){
        wt_L(f[OUHHcm5g]);
        wt_L(' ');
      }
      wt_L(f[OUHHcm5g]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// 
// const ll is_query = -(1LL<<62);
// struct line {
//     ll m, b;
//     mutable function<const line*()> succ;
//     
// };
// 
// bool operator<(const line& lhs, const line& rhs)  {
//     if (rhs.b != is_query) return lhs.m < rhs.m;
//     const line* s = lhs.succ();
//     if (!s) return 0;
//     ll x = rhs.m;
//     return lhs.b - s->b < (s->m - lhs.m) * x;
// }
// 
// struct dynamic_hull : public multiset<line> { // will maintain upper hull for maximum
//     const ll inf = LLONG_MAX;
//     bool bad(void * yy) {
//         iterator * u = (iterator *)yy;
//         iterator y = *u;
//         auto z = next(y);
//         if (y == begin()) {
//             if (z == end()) return 0;
//             return y->m == z->m && y->b <= z->b;
//         }
//         auto x = prev(y);
//         if (z == end()) return y->m == x->m && y->b <= x->b;
// 
// 		/* compare two lines by slope, make sure denominator is not 0 */
//         ll v1 = (x->b - y->b);
//         if (y->m == x->m) v1 = x->b > y->b ? inf : -inf;
//         else v1 /= (y->m - x->m);
//         ll v2 = (y->b - z->b);
//         if (z->m == y->m) v2 = y->b > z->b ? inf : -inf;
//         else v2 /= (z->m - y->m);
//         return v1 >= v2;
//     }
//     void insert_line(ll m, ll b) {
//         auto y = insert({ m, b });
//         y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
//         if (bad((void*)&y)) { erase(y); return; }
//         while (next(y) != end()){
//             auto yy = next(y);
//             if(bad((void*)&yy)){
//                 erase(next(y));
//             }else{
//                 break;
//             }
//         }
//         while (y != begin()) {
//             auto yy = prev(y);
//             if(bad((void*)&yy)){
//                 erase(prev(y));
//             }else{
//                 break;
//             }
//         }
//     }
//     ll eval(ll x) {
//         line tmp;//(line) { x, is_query }
//         tmp.b = is_query;
//         tmp.m = x;
//         auto l = *lower_bound(tmp);
//         return l.m * x + l.b;
//     }
// };
// int n;
// ll a[2d5+10], b[2d5+10], p[];
// ll pre(int x){
//     if(x < 0) return 0;
//     return p[x];
// }
// dynamic_hull cht;
// ll f[];
// { 
//     rd(n, a(n), b(n));
//     rep(i, n) p[i] = if[i == 0, 0, p[i-1]] + a[i];
//     cht.insert_line(0, 0);
//     rep(i, 1, n){
//         f[i] = b[i] * pre(i) - cht.eval(b[i]);
//         cht.insert_line(pre(i-1), -f[i]);
//     }
//     wt(f(n));
// }
