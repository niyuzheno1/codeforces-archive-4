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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class T> struct fenwick{
  int size;
  int memory;
  T*data;
  void malloc(int mem);
  void malloc(int mem, int fg);
  void walloc(int mem, void **workMemory = &wmem);
  void walloc(int mem, int fg, void **workMemory = &wmem);
  void free(void);
  void init(int N);
  void add(int k, T val);
  T get(int k);
  T range(int a, int b);
  int kth(T k);
}
;
const int dbg = 0;
const int seed = 671242145;
#include <random>
int n;
int t;
int k;
int target;
vector<int> hid;
vector<int> ori;
int gettarget(){
  int i;
  int kk = 0;
  for(i=(0);i<(n);i++){
    if(hid[i] == 0){
      ++kk;
    }
  }
  k = rand()%kk;
  kk = 0;
  for(i=(0);i<(n);i++){
    if(hid[i] == 0){
      if(kk == k){
        target = i + 1;
      }
      ++kk;
    }
  }
  ++k;
  return kk;
}
const int arr[] = {1, 0, 1, 1, 0 ,1};
void init(){
  if(!dbg){
    rd(n);
    rd(t);
  }
  else{
    int i;
    n = 6;
    t = 2;
    for(i=(0);i<(6);i++){
      hid.push_back(arr[i]);
    }
    for(i=(0);i<(6);i++){
      ori.push_back(arr[i]);
    }
    target = 5;
  }
}
void init_k(){
  if(!dbg){
    rd(k);
  }
  else{
    gettarget();
  }
}
int ask(int l, int r){
  if(!dbg){
    wt_L("?");
    wt_L(' ');
    wt_L(l);
    wt_L(' ');
    wt_L(r);
    wt_L('\n');
    int x;
    rd(x);
    if(x == -1){
      exit(0);
    }
    return x;
  }
  else{
    int i;
    --l;
    int cnt = 0;
    for(i=(l);i<(r);i++){
      cnt += hid[i];
    }
    return cnt;
  }
}
void answer(int x){
  if(!dbg){
    wt_L("!");
    wt_L(' ');
    wt_L(x);
    wt_L('\n');
  }
  else{
    int k = 0;
    hid[target-1] = 1;
    if(x == target){
      cout << "accepted" << target <<endl;
      return;
    }
    else{
      cout << "wrong answer " << x << ":" << target <<endl;
      exit(0);
    }
  }
}
int len(int x, int y){
  return y-x+1;
}
int findans(int l, int r, int k, int flipped){
  if(l == r){
    return l;
  }
  int md = (l+r)>>1;
  int x = ask(l+1, md+1);
  int leftpart = flipped ?  x: (len(l+1, md+1) - x);
  if( leftpart >= k){
    return findans(l, md, k, flipped);
  }
  else{
    return findans(md+1, r, k-leftpart, flipped);
  }
}
fenwick<int> tr;
int preprocess(){
  int i;
  tr.walloc(200000);
  tr.init(200000);
  for(i=(0);i<(n);i+=(10)){
    int next =min_L(n-1, i + 10 -1);
    tr.add(i/10, len(i, next)-ask(i+1, next+1));
    if(next == n-1){
      return i/10;
    }
  }
}
int main(){
  int tcases;
  wmem = memarr;
  init();
  int upperbnd = 0;
  int OUHHcm5g = t;
  for(tcases=(0);tcases<(OUHHcm5g);tcases++){
    init_k();
    if(tcases == 0){
      upperbnd = preprocess();
    }
    int lo08wcHZ;
    int vAq4Dd79;
    int Y0H_suZr;
    lo08wcHZ = 0;
    vAq4Dd79 = upperbnd;
    while(lo08wcHZ < vAq4Dd79){
      if((lo08wcHZ + vAq4Dd79)%2==0){
        Y0H_suZr = (lo08wcHZ + vAq4Dd79) / 2;
      }
      else{
        Y0H_suZr = (lo08wcHZ + vAq4Dd79 + 1) / 2;
      }
      if(tr.get(Y0H_suZr) < k){
        lo08wcHZ = Y0H_suZr;
      }
      else{
        vAq4Dd79 = Y0H_suZr - 1;
      }
    }
    int mn =vAq4Dd79;
    mn =max_L(mn-2, 0);
    while(mn * 10 < n&& tr.get(mn) < k){
      ++ mn;
    }
    --mn;
    auto part1 = 0;
    if(mn >= 0){
      part1= tr.get(mn);
    }
    auto part2 =min_L(n-1, (mn+2) * 10-1);
    int ans=findans((mn+1)*10, part2, k-part1, 0);
    answer(ans+1);
    tr.add((mn+1), -1);
  }
  exit(0);
  return 0;
}
template<class T> void fenwick<T>::malloc(int mem){
  memory = mem;
  data = (T*)std::malloc(sizeof(T)*mem);
}
template<class T> void fenwick<T>::malloc(int mem, int fg){
  memory = mem;
  data = (T*)std::malloc(sizeof(T)*mem);
  if(fg){
    init(mem);
  }
}
template<class T> void fenwick<T>::walloc(int mem, void **workMemory /* = &wmem*/){
  memory = mem;
  walloc1d(&data, mem, workMemory);
}
template<class T> void fenwick<T>::walloc(int mem, int fg, void **workMemory /* = &wmem*/){
  memory = mem;
  walloc1d(&data, mem, workMemory);
  if(fg){
    init(mem);
  }
}
template<class T> void fenwick<T>::free(void){
  memory = 0;
  free(data);
}
template<class T> void fenwick<T>::init(int N){
  size = N;
  memset(data,0,sizeof(T)*N);
}
template<class T> void fenwick<T>::add(int k, T val){
  while(k < size){
    data[k] += val;
    k |= k+1;
  }
}
template<class T> T fenwick<T>::get(int k){
  T res = 0;
  while(k>=0){
    res += data[k];
    k = (k&(k+1))-1;
  }
  return res;
}
template<class T> T fenwick<T>::range(int a, int b){
  if(b==-1){
    b=size-1;
  }
  return get(b) - get(a-1);
}
template<class T> int fenwick<T>::kth(T k){
  int i=0;
  int j=size;
  int c;
  T v;
  while(i<j){
    c = (i+j)/2;
    v = get(c);
    if(v <= k){
      i=c+1;
    }
    else{
      j=c;
    }
  }
  return i==size?-1:i;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// //interactive
// const int dbg = 0;
// const int seed = 671242145;
// #include <random>
// int n, t, k;
// int target;
// vector<int> hid;
// vector<int> ori;
// int gettarget(){
//         int kk = 0;
//         rep(i, n) if(hid[i] == 0) ++kk;
//         k = rand()%kk;
//         kk = 0;
//         rep(i, n) {
//             if(hid[i] == 0){
//                 if(kk == k) target = i + 1;
//                 ++kk;
//             }
//         }
//         ++k;
//         return kk;
// }
// const int arr[] = {1, 0, 1, 1, 0 ,1};
// 
// void init(){
//     if(!dbg){
//         rd(n,t);
//     }else{
//         // n = 2d5, t = 1;
//         // srand(seed);
//         // rep(i, n) hid.push_back(rand()%2);
//         // ori = hid;
//         // t = min(1d4,gettarget());
//         n = 6, t = 2;
//         rep(i , 6) hid.push_back(arr[i]);
//         rep(i , 6) ori.push_back(arr[i]);
//         target = 5;
//     }
// }
// 
// 
// 
// void init_k(){
//     if(!dbg){
//         rd(k);
//     }
//     else{
//         gettarget();
//         //k = 2;
// 
//     }
// }
// 
// int ask(int l, int r){
//     if(!dbg){
//         wt("?", l, r);
//         int x;
//         rd(x);
//         if(x == -1) exit(0);
//         return x;
//     }else{
//         --l;
//         int cnt = 0;
//         rep(i, l, r){
//             cnt += hid[i];
//         }
//         
//         return cnt;
//     }
// }
// 
// void answer(int x){
//     if(!dbg){
//         wt("!", x);
//     }else{
//         int k = 0;
//         hid[target-1] = 1;
//         if(x == target){
//             cout << "accepted" << target <<endl;
//             return;
//         }else{
//             cout << "wrong answer " << x << ":" << target <<endl;
//             exit(0);
//         }
//         
//     }
// }
// 
// int len(int x, int y){
//     return y-x+1;
// }
// 
// int findans(int l, int r, int k, int flipped){
//     if(l == r) return l;
//     int md = (l+r)>>1;
//     int x = ask(l+1, md+1);
//     int leftpart = flipped ?  x: (len(l+1, md+1) - x);
//     if( leftpart >= k) return findans(l, md, k, flipped);
//     else return findans(md+1, r, k-leftpart, flipped);
// }
// 
// fenwick<int> tr;
// 
// int preprocess(){
//     tr.walloc(2d5);
//     tr.init(2d5);
//     rep(i, 0, n, 10){
//         int next = min(n-1, i + 10 -1);
//         tr.add(i/10, len(i, next)-ask(i+1, next+1));
//         if(next == n-1){
//             return i/10;
//         }
//     }
// }
// 
// { 
//   init();
//   int upperbnd = 0;
//   REP(tcases, t){
//       init_k();
//       if(tcases == 0){
//           upperbnd = preprocess();
//       }
//       int mn = bsearch_max[int, x, 0, upperbnd](tr.get(x) < k);
//       mn = max(mn-2, 0);
//       while(mn * 10 < n&& tr.get(mn) < k) ++ mn;
//       --mn;
//       auto part1 = 0;
//       if(mn >= 0) part1= tr.get(mn);
//       auto part2 = min(n-1, (mn+2) * 10-1);
//       //auto part3 = len(1, (mn+1)*10) - ask(1, (mn+1)*10);
//       int ans=findans((mn+1)*10, part2, k-part1, 0);
//       answer(ans+1);
//       tr.add((mn+1), -1);
//   }
//   exit(0);
// }
