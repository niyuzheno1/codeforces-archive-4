//no-unlocked
int pre[1d5+10], m , n, X;
int idx[], a[];
int getrange(int l, int r){
    if( l > r) return 0;
    if(l <= 0) return pre[r];
    return pre[r] - pre[l-1];
}
bool dfs(int x, int cid,int gt, int lt){
    if(gt > lt){
        return false;
    }
    if(cid == 1){
        int tmp =  getrange(0, x) ;
        if(gt <= tmp<= lt  ){
            rep(i, x+1){
                idx[i] = cid;
            }
            return true;
        }
        return false;
    }
    bool ret = false;
    int nid = bsearch_max[int, k, 0, x] ( getrange(k, x) >= gt );
    rrep(i, x+1){
        if(i == 0) return false;
        idx[i] = cid;
        int ps = getrange(i, x);
        int ngt = max(gt, ps-X);
        int nlt = min(lt, ps+X);
        ret = dfs(i-1, cid-1, ngt, nlt);
        if(ret) return true;
    }
    return ret;
}
{ 
  REP(rd_int()){
    rd(n,m , X, a(n));
    partial_sum(a, a+n, pre);
    bool res = dfs(n-1, m, 0, int_inf);
    if(res){
        wt("YES");
        wt(idx(n));
    }else{
        wt("NO");
    }
  }
}
