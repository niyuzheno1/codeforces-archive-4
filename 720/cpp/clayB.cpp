//no-unlocked
int n, asz;
ll a[1d6], ans[1d6][4];



void push(int x, int y, int z, int w){
    ans[asz][0] = x;
    ans[asz][1] = y;
    ans[asz][2] = z;
    ans[asz][3] = w;
    ++asz;
}

{ 
    REP(rd_int()){
        asz = 0;
        rd(n, a(n));
        int idx = argmin(a(n));
        rrep(i, idx){
            auto g = gcd(a[i], a[i+1]);
            if(g != 1){
                push(i+1, idx+1, a[i+1]+1, a[idx]);
                a[i] = a[i+1]+1;
            }
        }
        rep(i, idx+1, n){
            if(gcd(a[i], a[i-1]) != 1){
                push(i+1, idx+1, a[i-1]+1, a[idx]);
                a[i] = a[i-1]+1;
            }
        }
        wt(asz);
        rep(i,asz){
            wt(ans[i](4));
        }
    }
}
