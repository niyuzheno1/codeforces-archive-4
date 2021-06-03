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
int a[4];
char grid[52][52];
bool frontier[52];
int n;
int main(){
  int i, l;
  n = 50;
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(4);PiIOrLma++){
      rd(a[PiIOrLma]);a[PiIOrLma] += (-1);
    }
  }
  char x = 'A';
  for(l=(0);l<(48);l+=(12)){
    int i;
    for(i=(0);i<(n);i++){
      int j;
      for(j=(0);j<(n);j++){
        if(l <= i  &&  i < l + 12){
          grid[i][j] = x;
        }
      }
    }
    ++x;
  }
  for(i=(0);i<(n);i++){
    int j;
    for(j=(0);j<(n);j++){
      if(grid[i][j] == 0){
        grid[i][j] = 'D';
      }
    }
  }
  for(i=(0);i<(n);i++){
    frontier[i] = false;
  }
  for(i=(0);i<(n);i++){
    if(i == 0){
      continue;
    }
    if(frontier[i-1] == false){
      frontier[i] = true;
    }
    if(grid[i-1][0] != grid[i][0]){
      frontier[i] = true;
    }
    if(i == n-1){
      continue;
    }
    if(grid[i][0] != grid[i+1][0]){
      frontier[i] = true;
    }
  }
  for(i=(0);i<(n);i++){
    if(!frontier[i]){
      int j;
      for(j=(0);j<(n);j++){
        if(j % 2 == 0){
          int k;
          for(k=(0);k<(4);k++){
            if(a[k] != 0 && (k+'A') != grid[i][j]){
              --a[k];
              grid[i][j] = 'A'+k;
              break;
            }
          }
        }
      }
    }
  }
  wt_L(n);
  wt_L(' ');
  wt_L(n);
  wt_L('\n');
  for(i=(0);i<(n);i++){
    wt_L(grid[i]);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int a[4];
// char grid[52][52];
// bool frontier[52];
// int n;
// {   
//     n = 50;
//     rd((a--)(4));
//     char x = 'A'; 
//     rep(l, 0, 48, 12){
//         rep(i, n) rep(j, n) if(l <= i < l + 12) {grid[i][j] = x; }
//         ++x;
//     } 
//     rep(i,n) rep(j,n) if(grid[i][j] == 0) grid[i][j] = 'D';
//     rep(i, n) frontier[i] = false;
//     rep(i, n){
//         if(i == 0) continue;
//         if(frontier[i-1] == false) frontier[i] = true;
//         if(grid[i-1][0] != grid[i][0]) frontier[i] = true;
//         if(i == n-1) continue;
//         if(grid[i][0] != grid[i+1][0]) frontier[i] = true;
//     }
//     rep(i, n){
//         if(!frontier[i]){
//             rep(j, n){
//                 if(j % 2 == 0){
//                     rep(k, 4) if(a[k] != 0 && (k+'A') != grid[i][j]){
//                         --a[k];
//                         grid[i][j] = 'A'+k;
//                         break;
//                     }
//                 }
//             }
//         }
//     }
//     wt(n,n);
//     //rep(i,n) if(!frontier[i]) wt(1+i);
//     rep(i,n) wt(grid[i]);
// }
