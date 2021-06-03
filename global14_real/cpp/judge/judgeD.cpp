#include<random>

{
    srand (time(NULL));
    
    bool ac = true;
    rep(i, 100){
        auto uu = ".\\testset\\testsetD.exe "+to_string(rand() % 100000)+" < ins.txt > input.txt";
        system(uu.c_str());
        system(".\\D\\main.exe < .\\input.txt > .\\output.txt");
        system(".\\DP\\main.exe < .\\input.txt > .\\answer.txt");
        ifstream fin("input.txt");
        ifstream fout("output.txt");
        ifstream fans("answer.txt");
        int tcases;
        fin >> tcases;
        rep(tt, tcases){
            int u,v;
            fout >> u;
            fans >> v;
            if(u > v){
                ac = false;
                wt("Test case wrong on :", tt);
                break_break;
            }
        }
        if(ac) cout << "Successfully Pass All the Test Cases!" <<endl;
        fin.close();
        fout.close();
        fans.close();
    }
    
    
    return 0;
}
