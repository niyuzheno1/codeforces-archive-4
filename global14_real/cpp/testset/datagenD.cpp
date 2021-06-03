#include "random_array.hpp"

//wt(rnd.next("one|two|three"));
int main(int argc, char ** argv){
    registerGen(argc, argv, 1);
    int tcases = 100;
    wt(tcases);
    rep(i, tcases){
        int n = rnd.next(1, 10);
        n = n*2;
        int l = rnd.next(0, n);
        int r = n-l;
        wt(n,l,r);
        int * u = getarray(n, 1, n);
        wt(u(n));
    }
}
