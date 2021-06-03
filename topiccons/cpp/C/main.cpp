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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
char s[1000+10];
int n;
int main(){
  int i;
  n = rd(s);
  int curone = 0;
  int curzero = 0;
  for(i=(0);i<(n);i++){
    if(s[i] == '0'){
      wt_L(3);
      wt_L(' ');
      wt_L(curzero + 1);
      wt_L('\n');
      curzero = curzero + 1;
      curzero %= 4;
    }
    else{
      wt_L(1);
      wt_L(' ');
      wt_L(curone + 1);
      wt_L('\n');
      curone = curone + 2;
      curone %= 4;
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// char s[1d3+10];
// int n;
// { 
//   rd(s@n);
//   int curone = 0;
//   int curzero = 0;
//   rep(i, n){
//       if(s[i] == '0'){
//         wt(3, curzero + 1);
//         curzero = curzero + 1;
//         curzero %= 4;
//       }else{
//         wt(1, curone + 1);
//         curone = curone + 2;
//         curone %= 4;
//       }
//   }
// }
