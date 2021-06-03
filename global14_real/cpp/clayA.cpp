//no-unlocked
int n, x, w[110];
{ 
  REP(rd_int()){
    rd(n, x, w(n));
    rep(i, n){
        int addv = 0;
        rep(j, 0, i+1){
            addv += w[j];
        }
        if(addv == x){
            if(i+1 < n){
                swap(w[i], w[i+1]);
            }else{
                swap(w[i], w[0]);
            }
        }
    }
    int addv = 0;
    rep(i, n){
        addv += w[i];
        if(addv == x){
            wt("NO");
            break_continue;
        }
    }
    wt("YES");
    wt(w(n));
  }
}
