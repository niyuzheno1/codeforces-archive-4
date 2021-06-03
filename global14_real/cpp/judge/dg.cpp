#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline void my_putchar_unlocked(const int k){
  putchar_unlocked(k);
}
inline void wt_L(char a){
  my_putchar_unlocked(a);
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
    my_putchar_unlocked('-');
  }
  while(s--){
    my_putchar_unlocked(f[s]+'0');
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar_unlocked(c[i]);
  }
}
#include<random>
int main(){
  int i;
  srand (time(NULL));
  bool ac = true;
  for(i=(0);i<(100);i++){
    int tt;
    auto uu = ".\\testset\\testsetD.exe "+to_string(rand() % 100000)+" < ins.txt > input.txt";
    system(uu.c_str());
    system(".\\D\\main.exe < .\\input.txt > .\\output.txt");
    system(".\\DP\\main.exe < .\\input.txt > .\\answer.txt");
    ifstream fin("input.txt");
    ifstream fout("output.txt");
    ifstream fans("answer.txt");
    int tcases;
    fin >> tcases;
    for(tt=(0);tt<(tcases);tt++){
      int u;
      int v;
      fout >> u;
      fans >> v;
      if(u > v){
        ac = false;
        wt_L("Test case wrong on :");
        wt_L(' ');
        wt_L(tt);
        wt_L('\n');
        goto AuJVIghY;
      }
    }
    if(ac){
      cout << "Successfully Pass All the Test Cases!" <<endl;
    }
    fin.close();
    fout.close();
    fans.close();
  }
  AuJVIghY:;
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// #include<random>
// 
// {
//     srand (time(NULL));
//     
//     bool ac = true;
//     rep(i, 100){
//         auto uu = ".\\testset\\testsetD.exe "+to_string(rand() % 100000)+" < ins.txt > input.txt";
//         system(uu.c_str());
//         system(".\\D\\main.exe < .\\input.txt > .\\output.txt");
//         system(".\\DP\\main.exe < .\\input.txt > .\\answer.txt");
//         ifstream fin("input.txt");
//         ifstream fout("output.txt");
//         ifstream fans("answer.txt");
//         int tcases;
//         fin >> tcases;
//         rep(tt, tcases){
//             int u,v;
//             fout >> u;
//             fans >> v;
//             if(u > v){
//                 ac = false;
//                 wt("Test case wrong on :", tt);
//                 break_break;
//             }
//         }
//         if(ac) cout << "Successfully Pass All the Test Cases!" <<endl;
//         fin.close();
//         fout.close();
//         fans.close();
//     }
//     
//     
//     return 0;
// }
