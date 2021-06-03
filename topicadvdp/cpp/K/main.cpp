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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class SVAL, class SFUN> struct segtree_rh{
  int N;
  int logN;
  int trueN;
  SVAL*val;
  SFUN*fun;
  char*dofun;
  void malloc(int maxN, int once = 0);
  void walloc(int maxN, int once = 0, void **mem = &wmem);
  void free(void);
  SVAL& operator[](int i);
  void setN(int n, int zerofill = 1, int dobuild = 1);
  void build(void);
  inline void push_one(int a);
  inline void push(int a);
  inline void build(int a);
  inline void change(int a, int b, SFUN f);
  inline SVAL get(int a, int b);
  template<bool (*f)(SVAL)> int max_right(int a, int mx);
  template<bool (*f)(SVAL)> int max_right(int a);
  template<bool (*f)(SVAL)> int min_left(int b, int mn);
  template<bool (*f)(SVAL)> int min_left(int b);
}
;
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
bool init = true;
dynamic_hull_min cht[400000+10];
int chtsz;
struct em{
  int id;
  em(){
    id = -1;
  }
  em(int x){
    id = x;
  }
}
;
long long fans;
long long X;
em segtree_rh_merge(em a, em b){
  if(init){
    if(a.id == -1 && b.id == -1){
      return em(-1);
    }
    if(a.id == -1 || b.id == -1){
      int cid = ((a.id == -1)? b.id : a.id);
      for(auto x : cht[cid].cht){
        cht[chtsz].cht.insert_line(x.m, x.b);
      }
    }
    else{
      for(auto x : cht[a.id].cht){
        cht[chtsz].cht.insert_line(x.m, x.b);
      }
      for(auto x : cht[b.id].cht){
        cht[chtsz].cht.insert_line(x.m, x.b);
      }
    }
    return em(chtsz++);
  }
  else{
    if(a.id == -1 && b.id == -1){
      return em(-1);
    }
    if(a.id == -1 || b.id == -1){
      int cid = ((a.id == -1)? b.id : a.id);
      chmin(fans, cht[cid].eval(X));
    }
    else{
      chmin(fans, cht[a.id].eval(X));
      chmin(fans, cht[b.id].eval(X));
    }
    return em(-1);
  }
}
em segtree_rh_apply(int f, em a){
  return a;
}
int segtree_rh_compose(int f, int g){
  return 0;
}
segtree_rh<em, int> t;
int n;
int a[100000+10];
int m;
int x[100000+10];
int y[100000+10];
int p[100000+10];
int main(){
  int i;
  wmem = memarr;
  rd(n);
  {
    int rbGYC8dh;
    for(rbGYC8dh=(0);rbGYC8dh<(n);rbGYC8dh++){
      rd(a[rbGYC8dh]);
    }
  }
  rd(m);
  {
    int EZ0PmQmu;
    for(EZ0PmQmu=(0);EZ0PmQmu<(m);EZ0PmQmu++){
      rd(x[EZ0PmQmu]);
      rd(y[EZ0PmQmu]);y[EZ0PmQmu] += (-1);
    }
  }
  for(i=(0);i<(n);i++){
    p[i] = a[i] + ((i > 0) ? p[i-1] : 0);
  }
  t.walloc(n);
  t.setN(n, 1, 0);
  int u = 0;
  for(u=1;u<n;u*=2){
    ;
  }
  for(i=(0);i<((u<<1));i++){
    t.val[i] = em(-1);
  }
  for(i=(0);i<(n);i++){
    t[i] = chtsz;
    cht[chtsz].insert_line(a[i], -p[i] + a[i] * i);
    ++chtsz;
  }
  t.build();
  init = 0;
  for(i=(0);i<(m);i++){
    int ans = p[y[i]];
    fans = 4611686016279904256LL;
    X = x[i]-y[i];
    auto u = t.get(max_L(0, y[i]-x[i]+1), y[i]+1);
    if(u.id != -1){
      chmin(fans, cht[u.id].eval(X));
    }
    ans += fans;
    wt_L(ans);
    wt_L('\n');
  }
  return 0;
}
template<class SVAL, class SFUN> void segtree_rh<SVAL, SFUN>::malloc(int maxN, int once /*= 0*/){
  int i;
  for(i=1;i<maxN;i*=2){
    ;
  }
  val = new SVAL[2*i];
  fun = new SFUN[i];
  dofun = new char[i];
  if(once){
    setN(maxN);
  }
}
template<class SVAL, class SFUN> void segtree_rh<SVAL, SFUN>::walloc(int maxN, int once /*= 0*/, void **mem /*= &wmem*/){
  int i;
  for(i=1;i<maxN;i*=2){
    ;
  }
  walloc1d(&val, 2*i, mem);
  walloc1d(&fun, i, mem);
  walloc1d(&dofun, i, mem);
  if(once){
    setN(maxN);
  }
}
template<class SVAL, class SFUN> void segtree_rh<SVAL, SFUN>::free(void){
  delete [] val;
  delete [] fun;
}
template<class SVAL, class SFUN> SVAL& segtree_rh<SVAL, SFUN>::operator[](int i){
  return val[N+i];
}
template<class SVAL, class SFUN> void segtree_rh<SVAL, SFUN>::setN(int n, int zerofill /*= 1*/, int dobuild /*= 1*/){
  int i;
  for(i=1,logN=0;i<n;i*=2,logN++){
    ;
  }
  trueN = n;
  N = i;
  if(dobuild){
    build();
  }
}
template<class SVAL, class SFUN> void segtree_rh<SVAL, SFUN>::build(void){
  int i;
  for(i=N-1;i;i--){
    val[i] = segtree_rh_merge(val[2*i], val[2*i+1]);
  }
  int MkOXm_kt = N;
  for(i=(1);i<(MkOXm_kt);i++){
    dofun[i] = 0;
  }
}
template<class SVAL, class SFUN> inline void segtree_rh<SVAL, SFUN>::push_one(int a){
  if(dofun[a]){
    if(2*a < N){
      if(dofun[2*a]){
        fun[2*a] = segtree_rh_compose(fun[a], fun[2*a]);
      }
      else{
        fun[2*a] = fun[a];
        dofun[2*a] = 1;
      }
    }
    val[2*a] = segtree_rh_apply(fun[a], val[2*a]);
    if(2*a+1 < N){
      if(dofun[2*a+1]){
        fun[2*a+1] = segtree_rh_compose(fun[a], fun[2*a+1]);
      }
      else{
        fun[2*a+1] = fun[a];
        dofun[2*a+1] = 1;
      }
    }
    val[2*a+1] = segtree_rh_apply(fun[a], val[2*a+1]);
    dofun[a] = 0;
  }
}
template<class SVAL, class SFUN> inline void segtree_rh<SVAL, SFUN>::push(int a){
  int i;
  for(i=logN;i;i--){
    push_one(a>>i);
  }
}
template<class SVAL, class SFUN> inline void segtree_rh<SVAL, SFUN>::build(int a){
  while(a > 1){
    a /= 2;
    val[a] = segtree_rh_merge(val[2*a], val[2*a+1]);
    if(dofun[a]){
      val[a] = segtree_rh_apply(fun[a], val[a]);
    }
  }
}
template<class SVAL, class SFUN> inline void segtree_rh<SVAL, SFUN>::change(int a, int b, SFUN f){
  int aa;
  int bb;
  if(a >= b){
    return;
  }
  aa = (a += N);
  bb = (b += N);
  push(a);
  push(b-1);
  if(a%2){
    val[a] = segtree_rh_apply(f, val[a]);
    a++;
  }
  if(b%2){
    b--;
    val[b] = segtree_rh_apply(f, val[b]);
  }
  a /= 2;
  b /= 2;
  while(a < b){
    if(a%2){
      val[a] = segtree_rh_apply(f, val[a]);
      if(dofun[a]){
        fun[a] = segtree_rh_compose(f, fun[a]);
      }
      else{
        fun[a] = f;
        dofun[a] = 1;
      }
      a++;
    }
    if(b%2){
      b--;
      val[b] = segtree_rh_apply(f, val[b]);
      if(dofun[b]){
        fun[b] = segtree_rh_compose(f, fun[b]);
      }
      else{
        fun[b] = f;
        dofun[b] = 1;
      }
    }
    a /= 2;
    b /= 2;
  }
  build(aa);
  build(bb-1);
}
template<class SVAL, class SFUN> inline SVAL segtree_rh<SVAL, SFUN>::get(int a, int b){
  SVAL res;
  SVAL tmp;
  int fga = 0;
  int fgb = 0;
  a += N;
  b += N;
  push(a);
  push(b-1);
  while(a < b){
    if(a%2){
      if(fga){
        res = segtree_rh_merge(res, val[a]);
      }
      else{
        res = val[a];
        fga = 1;
      }
      a++;
    }
    if(b%2){
      b--;
      if(fgb){
        tmp = segtree_rh_merge(val[b], tmp);
      }
      else{
        tmp = val[b];
        fgb = 1;
      }
    }
    a /= 2;
    b /= 2;
  }
  if(fga==1 && fgb==0){
    return res;
  }
  if(fga==0 && fgb==1){
    return tmp;
  }
  if(fga==1 && fgb==1){
    return segtree_rh_merge(res, tmp);
  }
  return res;
}
template<class SVAL, class SFUN> template<bool (*f)(SVAL)> int segtree_rh<SVAL, SFUN>::max_right(int a, int mx){
  int fg = 0;
  int ta = a;
  int sz = 1;
  SVAL cur;
  SVAL tmp;
  if(a>=mx){
    return mx;
  }
  a += N;
  push(a);
  for(;;){
    while(a%2==0){
      a /= 2;
      sz *= 2;
    }
    if(ta + sz <= mx){
      if(fg==0){
        tmp = val[a];
      }
      else{
        tmp = segtree_rh_merge(cur, val[a]);
      }
    }
    if(ta + sz > mx || !f(tmp)){
      while(a < N){
        push_one(a);
        a *= 2;
        sz /= 2;
        if(ta + sz <= mx){
          if(fg==0){
            tmp = val[a];
          }
          else{
            tmp = segtree_rh_merge(cur, val[a]);
          }
        }
        if(ta + sz <= mx && f(tmp)){
          fg = 1;
          cur = tmp;
          a++;
          ta += sz;
        }
      }
      return a - N;
    }
    fg = 1;
    cur = tmp;
    if((a & (a+1)) == 0){
      break;
    }
    a++;
    ta += sz;
  }
  return mx;
}
template<class SVAL, class SFUN> template<bool (*f)(SVAL)> int segtree_rh<SVAL, SFUN>::max_right(int a){
  return max_right<f>(a, trueN);
}
template<class SVAL, class SFUN> template<bool (*f)(SVAL)> int segtree_rh<SVAL, SFUN>::min_left(int b, int mn){
  int fg = 0;
  int tb = b;
  int sz = 1;
  SVAL cur;
  SVAL tmp;
  if(b <= mn){
    return mn;
  }
  b += N;
  push(b-1);
  for(;;){
    while(b%2==0){
      b /= 2;
      sz *= 2;
    }
    if(tb - sz >= mn){
      if(fg==0){
        tmp = val[b-1];
      }
      else{
        tmp = segtree_rh_merge(val[b-1], cur);
      }
    }
    if(tb - sz < mn || !f(tmp)){
      while(b-1 < N){
        push_one(b-1);
        b *= 2;
        sz /= 2;
        if(tb - sz >= mn){
          if(fg==0){
            tmp = val[b-1];
          }
          else{
            tmp = segtree_rh_merge(val[b-1], cur);
          }
        }
        if(tb - sz >= mn && f(tmp)){
          fg = 1;
          cur = tmp;
          b--;
          tb -= sz;
        }
      }
      return b - N;
    }
    fg = 1;
    cur = tmp;
    b--;
    tb -= sz;
    if(tb <= mn){
      break;
    }
  }
  return mn;
}
template<class SVAL, class SFUN> template<bool (*f)(SVAL)> int segtree_rh<SVAL, SFUN>::min_left(int b){
  return min_left<f>(b, 0);
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// bool init = true;
// dynamic_hull_min cht[4d5+10];
// int chtsz;
// struct em{
//     int id;
//     em(){
//         id = -1;
//     }
//     em(int x){
//         id = x;
//     }
// };
// ll fans, X; 
// em segtree_rh_merge(em a, em b){ 
//     if(init){
//         if(a.id == -1 && b.id == -1) return em(-1);
//         if(a.id == -1 || b.id == -1){
//             int cid = ((a.id == -1)? b.id : a.id);  
//             for(auto x : cht[cid].cht){
//                 cht[chtsz].cht.insert_line(x.m, x.b);
//             }
//         }else{
//             for(auto x : cht[a.id].cht){
//                 cht[chtsz].cht.insert_line(x.m, x.b);
//             }
//             for(auto x : cht[b.id].cht){
//                 cht[chtsz].cht.insert_line(x.m, x.b);
//             }
//         }
//         return em(chtsz++);
//     }else{
//         if(a.id == -1 && b.id == -1) return em(-1);
//         if(a.id == -1 || b.id == -1){
//             int cid = ((a.id == -1)? b.id : a.id);  
//             fans <?= cht[cid].eval(X);
//         }else{
//             fans <?= cht[a.id].eval(X);
//             fans <?= cht[b.id].eval(X);
//         }
//         return em(-1);
//     }
//     
// }
// em segtree_rh_apply(int f, em a){ 
//     return a;
// }
// int segtree_rh_compose(int f, int g){ 
//     return 0;
// }
// segtree_rh<em, int> t;
// 
// int n, a[1d5+10], m, x[], y[], p[];
// 
// { 
//     rd(n, a(n), m, (x,y--)(m));
//     rep(i, n) p[i] = a[i] + ((i > 0) ? p[i-1] : 0);
//     t.walloc(n);
//     t.setN(n, 1, 0);
//     int u = 0;
//     for(u=1;u<n;u*=2){
//         ;
//     }
//     rep(i, (u<<1)) t.val[i] = em(-1);
//     rep(i,n){
//         t[i] = chtsz;
//         cht[chtsz].insert_line(a[i], -p[i] + a[i] * i);
//         ++chtsz;
//     }
//     t.build();
//     init = 0;
//     rep(i, m){
//         int ans = p[y[i]];
//         fans = ll_inf;
//         X = x[i]-y[i];
//         auto u = t.get(max(0, y[i]-x[i]+1), y[i]+1);
//         if(u.id != -1) fans <?= cht[u.id].eval(X);
//         ans += fans;
//         wt(ans);
//     }
// }
