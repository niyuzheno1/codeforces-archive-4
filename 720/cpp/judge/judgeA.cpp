#include<random>

{
    
    srand (time(NULL));
    
    bool ac = true;
    rep(i, 20){
        string cmdl = ".\\testset\\testsetA.exe " +to_string(rand()%20000)+" < ins.txt > input.txt";
        system(cmdl.c_str());
        system(".\\A\\main.exe < input.txt > output.txt");
        ifstream fin("input.txt");
        ifstream fout("output.txt");
        ifstream fans("answer.txt");
        int tcases;
        fin>>tcases;
        rep(ca, tcases){
            ll a, b;
            fin >> a >> b;
            string ans;
            fout >> ans;
            if(ans == "NO"){
                cout << a << "," << b << endl;
            }else{
                ll x, y, z;
                fout >> x >> y >> z;
                if(x != y && y != z && x != z){
                    if(x % b == 0 || y % b == 0){
                      wt("Wrong answer at case", ca);
                      exit(0);  
                    }
                }else{
                    wt("Wrong answer at case", ca);
                    exit(0);
                }
            }
        }
        if(ac) cout << "Successfully Pass All the Test Cases!" <<endl;
    }
    return 0;
}
