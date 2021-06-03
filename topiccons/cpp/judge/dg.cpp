#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#include<random>
int seed = 51000213;
int main(){
  int tc;
  srand (seed);
  int tcases = 1000;
  for(tc=(0);tc<(tcases);tc++){
    bool ac = true;
    string s = ".\\testset\\testsetF.exe "+to_string(rand()% (100000000)) +"  < ins.txt > input.txt";
    system(s.c_str());
    system(".\\I\\main.exe < input.txt > answer.txt");
    system(".\\F\\main.exe < input.txt > output.txt");
    int x;
    int y;
    ifstream fin("input.txt");
    ifstream fout("output.txt");
    ifstream fans("answer.txt");
    fout >> x;
    fans >> y;
    if(x != y){
      ac = false;
    }
    if(ac){
      cout << "Successfully Pass All the Test Cases!"  << endl;
    }
    else{
      cout << ("Test Failed") << endl;
      ;
      break;
    }
    fin.close();
    fout.close();
    fans.close();
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// #include<random>
// 
// int seed = 51000213;
// {
//     srand (seed);
//     int tcases = 1d3;
//     rep(tc, tcases){
//         bool ac = true;
//         string s = ".\\testset\\testsetF.exe "+to_string(rand()% (1d8)) +"  < ins.txt > input.txt";
//         system(s.c_str());
//         system(".\\I\\main.exe < input.txt > answer.txt");
//         system(".\\F\\main.exe < input.txt > output.txt");
//         int x, y;
//         ifstream fin("input.txt");
//         ifstream fout("output.txt");
//         ifstream fans("answer.txt");
//         fout >> x; fans >> y;
//         if(x != y) ac = false;
// 
//         if(ac) cout << "Successfully Pass All the Test Cases!"  << endl;
//         else {
//             cout << ("Test Failed") << endl;;
//             break;
//         }
//         fin.close();
//         fout.close();
//         fans.close();
//     }
//    
//     
//     return 0;
// }
