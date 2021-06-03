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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T> int coordcomp_L(int n, T arr[], int res[] = NULL, void *mem = wmem){
  int i;
  int k = 0;
  pair<T,int>*r;
  walloc1d(&r, n, &mem);
  for(i=(0);i<(n);i++){
    r[i].first = arr[i];
    r[i].second = i;
  }
  sort(r, r+n);
  if(res != NULL){
    for(i=(0);i<(n);i++){
      if(i && r[i].first != r[i-1].first){
        k++;
      }
      res[r[i].second] = k;
    }
  }
  else{
    for(i=(0);i<(n);i++){
      if(i && r[i].first != r[i-1].first){
        k++;
      }
      arr[r[i].second] = k;
    }
  }
  return k+1;
}
template<class T> int coordcomp_L(int n1, T arr1[], int n2, T arr2[], int res1[] = NULL, int res2[] = NULL, void *mem = wmem){
  int i;
  int k = 0;
  pair<T,int>*r;
  walloc1d(&r, n1+n2, &mem);
  for(i=(0);i<(n1);i++){
    r[i].first = arr1[i];
    r[i].second = i;
  }
  for(i=(0);i<(n2);i++){
    r[n1+i].first = arr2[i];
    r[n1+i].second = n1+i;
  }
  sort(r, r+n1+n2);
  for(i=(0);i<(n1+n2);i++){
    if(i && r[i].first != r[i-1].first){
      k++;
    }
    if(r[i].second < n1){
      if(res1!=NULL){
        res1[r[i].second] = k;
      }
      else{
        arr1[r[i].second] = k;
      }
    }
    else{
      if(res2!=NULL){
        res2[r[i].second-n1] = k;
      }
      else{
        arr2[r[i].second-n1] = k;
      }
    }
  }
  return k+1;
}
template<class T> struct segtree{
  int N;
  int logN;
  T*sum;
  T*mn;
  int*mnind;
  T*fixval;
  char*fixed;
  T*addval;
  void malloc(int maxN, int once = 0){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    sum = new T[2*i];
    mn = new T[2*i];
    mnind = new int[2*i];
    fixval = new T[i];
    addval = new T[i];
    fixed = new char[i];
    if(once){
      setN(maxN);
    }
  }
  void walloc(int maxN, int once = 0, void **mem = &wmem){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    walloc1d(&sum, 2*i, mem);
    walloc1d(&mn, 2*i, mem);
    walloc1d(&mnind, 2*i, mem);
    walloc1d(&fixval, i, mem);
    walloc1d(&addval, i, mem);
    walloc1d(&fixed, i, mem);
    if(once){
      setN(maxN);
    }
  }
  void free(void){
    delete [] sum;
    delete [] mn;
    delete [] mnind;
    delete [] fixval;
    delete [] addval;
    delete [] fixed;
  }
  T& operator[](int i){
    return sum[N+i];
  }
  void setN(int n, int zerofill = 1, int dobuild = 1){
    int i;
    for(i=1,logN=0;i<n;i*=2,logN++){
      ;
    }
    N = i;
    if(zerofill){
      for(i=(0);i<(N);i++){
        sum[N+i] = 0;
      }
    }
    if(dobuild){
      build();
    }
  }
  void build(void){
    int i;
    for(i=(0);i<(N);i++){
      mn[N+i] = sum[N+i];
      mnind[N+i] = i;
    }
    for(i=N-1;i;i--){
      sum[i] = sum[2*i] + sum[2*i+1];
      if(mn[2*i] <= mn[2*i+1]){
        mn[i] = mn[2*i];
        mnind[i] = mnind[2*i];
      }
      else{
        mn[i] = mn[2*i+1];
        mnind[i] = mnind[2*i+1];
      }
    }
    int d47fOnox = N;
    for(i=(1);i<(d47fOnox);i++){
      fixed[i] = 0;
    }
    int hFCgbKbG = N;
    for(i=(1);i<(hFCgbKbG);i++){
      addval[i] = 0;
    }
  }
  inline void push_one(int a, int sz, int st){
    if(fixed[a]){
      if(sz > 1){
        fixed[a*2] = fixed[a*2+1] = 1;
        fixval[a*2] = fixval[a*2+1] = fixval[a];
        sum[a*2] = sum[a*2+1] = sz * fixval[a];
        mn[a*2] = mn[a*2+1] = fixval[a];
        mnind[a*2] = st;
        mnind[a*2+1] = st + sz;
      }
      else{
        sum[a*2] = sum[a*2+1] = sz * fixval[a];
        mn[a*2] = mn[a*2+1] = fixval[a];
        mnind[a*2] = st;
        mnind[a*2+1] = st + sz;
      }
      fixed[a] = 0;
      addval[a] = 0;
      return;
    }
    if(addval[a] != 0){
      if(sz > 1){
        if(fixed[a*2]){
          fixval[a*2] += addval[a];
        }
        else{
          addval[a*2] += addval[a];
        }
        if(fixed[a*2+1]){
          fixval[a*2+1] += addval[a];
        }
        else{
          addval[a*2+1] += addval[a];
        }
        sum[a*2] += sz * addval[a];
        sum[a*2+1] += sz * addval[a];
        mn[a*2] += addval[a];
        mn[a*2+1] += addval[a];
      }
      else{
        sum[a*2] += sz * addval[a];
        sum[a*2+1] += sz * addval[a];
        mn[a*2] += addval[a];
        mn[a*2+1] += addval[a];
      }
      addval[a] = 0;
      return;
    }
  }
  inline void push(int a){
    int i;
    int aa = a - N;
    int nd;
    int sz;
    int st;
    for(i=logN;i;i--){
      nd = a>>i;
      sz = 1<<(i-1);
      st = 2 * sz * (aa>>i);
      push_one(nd, sz, st);
    }
  }
  inline void build(int a){
    int sz = 1;
    int st = a - N;
    while(a > 1){
      if(a%2){
        st += sz;
      }
      a /= 2;
      sz *= 2;
      if(fixed[a]){
        sum[a] = sz * fixval[a];
        mn[a] = fixval[a];
      }
      else{
        sum[a] = sum[a*2] + sum[a*2+1];
        if(mn[a*2] <= mn[a*2+1]){
          mn[a] = mn[a*2];
          mnind[a] = mnind[a*2];
        }
        else{
          mn[a] = mn[a*2+1];
          mnind[a] = mnind[a*2+1];
        }
        if(addval[a] != 0){
          mn[a] += addval[a];
          sum[a] += sz * addval[a];
        }
      }
    }
  }
  inline void change(int a, int b, T val){
    int sz = 1;
    int aa;
    int bb;
    int st_a = a;
    int st_b = b;
    if(a >= b){
      return;
    }
    aa = (a += N);
    bb = (b += N);
    push(a);
    push(b-1);
    if(a%2){
      sum[a] = mn[a] = val;
      a++;
      st_a += sz;
    }
    if(b%2){
      b--;
      st_b -= sz;
      sum[b] = mn[b] = val;
    }
    a /= 2;
    b /= 2;
    while(a < b){
      sz *= 2;
      if(a%2){
        fixed[a]=1;
        fixval[a]=val;
        sum[a] = sz * val;
        mn[a] = val;
        mnind[a] = st_a;
        a++;
        st_a += sz;
      }
      if(b%2){
        b--;
        st_b -= sz;
        fixed[b]=1;
        fixval[b]=val;
        sum[b] = sz * val;
        mn[b] = val;
        mnind[b] = st_b;
      }
      a /= 2;
      b /= 2;
    }
    build(aa);
    build(bb-1);
  }
  inline void add(int a, int b, T val){
    int sz = 1;
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
      sum[a] += val;
      mn[a] += val;
      a++;
    }
    if(b%2){
      b--;
      sum[b] += val;
      mn[b] += val;
    }
    a /= 2;
    b /= 2;
    while(a < b){
      sz *= 2;
      if(a%2){
        if(fixed[a]){
          fixval[a] += val;
        }
        else{
          addval[a] += val;
        }
        sum[a] += sz * val;
        mn[a] += val;
        a++;
      }
      if(b%2){
        b--;
        if(fixed[b]){
          fixval[b] += val;
        }
        else{
          addval[b] += val;
        }
        sum[b] += sz * val;
        mn[b] += val;
      }
      a /= 2;
      b /= 2;
    }
    build(aa);
    build(bb-1);
  }
  inline pair<T,int> getMin(int a, int b){
    pair<T,int> res;
    pair<T,int> tmp;
    int fga = 0;
    int fgb = 0;
    a += N;
    b += N;
    push(a);
    push(b-1);
    while(a < b){
      if(a%2){
        if(fga){
          res =min_L(res, make_pair(mn[a], mnind[a]));
        }
        else{
          res = make_pair(mn[a], mnind[a]);
          fga = 1;
        }
        a++;
      }
      if(b%2){
        b--;
        if(fgb){
          tmp =min_L(make_pair(mn[b], mnind[b]), tmp);
        }
        else{
          tmp = make_pair(mn[b], mnind[b]);
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
      res =min_L(res, tmp);
      return res;
    }
    return res;
  }
  inline T getMinVal(int a, int b){
    T res;
    T tmp;
    int fga = 0;
    int fgb = 0;
    a += N;
    b += N;
    push(a);
    push(b-1);
    while(a < b){
      if(a%2){
        if(fga){
          res =min_L(res, mn[a]);
        }
        else{
          res = mn[a];
          fga = 1;
        }
        a++;
      }
      if(b%2){
        b--;
        if(fgb){
          tmp =min_L(mn[b], tmp);
        }
        else{
          tmp = mn[b];
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
      res =min_L(res, tmp);
      return res;
    }
    return res;
  }
  inline int getMinInd(int a, int b){
    return getMin(a,b).second;
  }
  inline T getSum(int a, int b){
    T res;
    T tmp;
    int fga = 0;
    int fgb = 0;
    a += N;
    b += N;
    push(a);
    push(b-1);
    while(a < b){
      if(a%2){
        if(fga){
          res = res + sum[a];
        }
        else{
          res = sum[a];
          fga = 1;
        }
        a++;
      }
      if(b%2){
        b--;
        if(fgb){
          tmp = sum[b] + tmp;
        }
        else{
          tmp = sum[b];
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
      res = res + tmp;
      return res;
    }
    return res;
  }
}
;
int n;
int a[100000+10];
int b[100000+10];
int h[100000+10];
segtree<long long> t;
int main(){
  int i;
  wmem = memarr;
  rd(n);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(n);PiIOrLma++){
      rd(a[PiIOrLma]);
      rd(b[PiIOrLma]);
      rd(h[PiIOrLma]);
    }
  }
  int dis =coordcomp_L(n, b, n, a);
  for(i=(0);i<(n);i++){
    auto Z8lEHcvz = ((-b[i]));
    auto rbGYC8dh = (( -a[i]));
    b[i]=Z8lEHcvz;
    a[i]=rbGYC8dh;
  }
  t.walloc(dis+20);
  t.setN(dis+20);
  t.build();
  sortA_L(n, b, a, h);
  for(i=(0);i<(n);i++){
    auto EZ0PmQmu = ((-b[i]));
    auto zxsUT70f = (( -a[i]));
    b[i]=EZ0PmQmu;
    a[i]=zxsUT70f;
  }
  for(i=(0);i<(n);i++){
    ++a[i];
    ++b[i];
  }
  long long ans = 1;
  for(i=(0);i<(n);i++){
    long long tmp = 1;
    chmax(tmp, -t.getMinVal(1 , b[i])+h[i]);
    chmax(ans, tmp);
    auto tmp2 = -t.getSum(a[i],a[i]+1);
    if(tmp2 < tmp){
      t.change(a[i], a[i]+1 , -tmp);
    }
  }
  wt_L(ans);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n, a[1d5+10], b[], h[];
// segtree<ll> t;
// 
// { 
//     rd(n, (a,b,h)(n));
//     int dis = coordcomp(n, b, n, a);
//     rep(i, n) (b[i], a[i]) = (-b[i], -a[i]);
//     t.walloc(dis+20);
//     t.setN(dis+20);
//     t.build();
//     sortA(n, b, a, h);
//     rep(i, n) (b[i], a[i]) = (-b[i], -a[i]);
//     rep(i, n) ++a[i], ++b[i];
// 
//     ll ans = 1;
//     rep(i, n){
//         ll tmp = 1;
//         tmp >?= -t.getMinVal(1 , b[i])+h[i];
//         ans >?= tmp;
//         auto tmp2 = -t.getSum(a[i],a[i]+1);
//         if(tmp2 < tmp) t.change(a[i], a[i]+1 , -tmp);
//     }
//     wt(ans);
// }
