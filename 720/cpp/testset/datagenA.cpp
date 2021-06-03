#include "random_array.hpp"

//wt(rnd.next("one|two|three"));
int main(int argc, char ** argv){
    registerGen(argc, argv, 1);
    int tcases = 5000;
    wt(tcases);
    rep(i, tcases){
        int a,b;
        a = rnd.next(1,7);
        b = rnd.next(1,7);
        wt(a, b);
    }
}
