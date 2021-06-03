#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
const int dbg = 0;
const int seed = 671242145;
#include <random>
int n;
int t;
int k;
int target;
vector<int> hid;
vector<int> ori;
void init(){
  if(!dbg){
    rd(n);
    rd(t);
  }
  else{
    n = 6;
    t = 1;
  }
}
const int arr[] = {1, 0, 1, 1, 0 ,1};
void init_k(){
  if(!dbg){
    rd(k);
  }
  else{
    int i;
    for(i=(0);i<(6);i++){
      hid.push_back(arr[i]);
    }
    for(i=(0);i<(6);i++){
      ori.push_back(arr[i]);
    }
    k = 2;
    target = 5;
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
    exit(0);
  }
  else{
    int k = 0;
    if(x == target){
      cout << "accepted" <<endl;
      return;
    }
    else{
      cout << "wrong answer " << x << ":" << target <<endl;
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
int main(){
  int tcases;
  init();
  int rbGYC8dh = t;
  for(tcases=(0);tcases<(rbGYC8dh);tcases++){
    init_k();
    int ans=findans(0, n-1, k, 0);
    answer(ans+1);
  }
  return 0;
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
// void init(){
//     if(!dbg){
//         rd(n,t);
//     }else{
//         //n = 20, t = 1;
//         n = 6, t = 1;
//     }
// }
// const int arr[] = {1, 0, 1, 1, 0 ,1};
// void init_k(){
//     if(!dbg){
//         rd(k);
//     }
//     else{
//         rep(i , 6) hid.push_back(arr[i]);
//         rep(i , 6) ori.push_back(arr[i]);
//         k = 2;
//         target = 5;
//         // srand(seed);
//         // rep(i, n) hid.push_back(rand()%2);
//         // ori = hid;
//         // int kk = 0;
//         // rep(i, n) if(hid[i] == 0) ++kk;
//         // k = rand()%kk;
//         // kk = 0;
//         // rep(i, n) {
//         //     if(hid[i] == 0){
//         //         if(kk == k) target = i + 1;
//         //         ++kk;
//         //     }
//         // }
//         // ++k;
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
//         exit(0);
//     }else{
//         int k = 0;
//         if(x == target){
//             cout << "accepted" <<endl;
//             return;
//         }else{
//             cout << "wrong answer " << x << ":" << target <<endl;
//         }
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
// { 
//   init();
//   REP(tcases, t){
//       init_k();
//       int ans=findans(0, n-1, k, 0);
//       answer(ans+1);
//   }
// }
