//no-unlocked
int pre[1d5+10], m , n, X;
int idx[], a[];
int getrange(int l, int r){
    if( l > r) return 0;
    if(l <= 0) return pre[r];
    return pre[r] - pre[l-1];
}
bool dfs(int x, int cid,int gt, int lt){
    if(gt > lt || x < 0){
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
    int tsum = getrange(nid, x);
    rrep(i, nid, x+1){
        idx[i] = cid;
    }
    ret =dfs(nid-1, cid -1, max(gt, tsum-X),min(lt, tsum+X) );
    if(ret) return true;
    if(cid == m){
        rrep(i, nid){
            tsum += a[i];
            idx[i] = cid;
            if(tsum > lt) break;
            ret= dfs(i-1, cid -1, max(gt, tsum-X),min(lt, tsum+X));
        if(ret) return true;
        }
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
