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
  for(i=(0);i<(20);i++){
    int ca;
    string cmdl = ".\\testset\\testsetA.exe " +to_string(rand()%20000)+" < ins.txt > input.txt";
    system(cmdl.c_str());
    system(".\\A\\main.exe < input.txt > output.txt");
    ifstream fin("input.txt");
    ifstream fout("output.txt");
    ifstream fans("answer.txt");
    int tcases;
    fin>>tcases;
    for(ca=(0);ca<(tcases);ca++){
      long long a;
      long long b;
      fin >> a >> b;
      string ans;
      fout >> ans;
      if(ans == "NO"){
        cout << a << "," << b << endl;
      }
      else{
        long long x;
        long long y;
        long long z;
        fout >> x >> y >> z;
        if(x != y && y != z && x != z){
          if(x % b == 0 || y % b == 0){
            wt_L("Wrong answer at case");
            wt_L(' ');
            wt_L(ca);
            wt_L('\n');
            exit(0);
          }
        }
        else{
          wt_L("Wrong answer at case");
          wt_L(' ');
          wt_L(ca);
          wt_L('\n');
          exit(0);
        }
      }
    }
    if(ac){
      cout << "Successfully Pass All the Test Cases!" <<endl;
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// #include<random>
// 
// {
//     
//     srand (time(NULL));
//     
//     bool ac = true;
//     rep(i, 20){
//         string cmdl = ".\\testset\\testsetA.exe " +to_string(rand()%20000)+" < ins.txt > input.txt";
//         system(cmdl.c_str());
//         system(".\\A\\main.exe < input.txt > output.txt");
//         ifstream fin("input.txt");
//         ifstream fout("output.txt");
//         ifstream fans("answer.txt");
//         int tcases;
//         fin>>tcases;
//         rep(ca, tcases){
//             ll a, b;
//             fin >> a >> b;
//             string ans;
//             fout >> ans;
//             if(ans == "NO"){
//                 cout << a << "," << b << endl;
//             }else{
//                 ll x, y, z;
//                 fout >> x >> y >> z;
//                 if(x != y && y != z && x != z){
//                     if(x % b == 0 || y % b == 0){
//                       wt("Wrong answer at case", ca);
//                       exit(0);  
//                     }
//                 }else{
//                     wt("Wrong answer at case", ca);
//                     exit(0);
//                 }
//             }
//         }
//         if(ac) cout << "Successfully Pass All the Test Cases!" <<endl;
//     }
//     return 0;
// }
