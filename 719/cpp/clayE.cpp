//no-unlocked
int n;
char s[1d6+10];
ll pre[1d6+10];
ll cnt[1d6+10];
ll sa[1d6+10];
ll getidx(int l, int r){
    if(l > r) return 0;
    if(l == 0) return pre[r];
    return pre[r] - pre[l-1];
}
ll getcnt(int l, int r){
    if(l > r) return 0;
    if(l == 0) return cnt[r];
    return cnt[r] - cnt[l-1];
}
{ 
    sa[0] = 0;
    rep(i, 1, 1d6+9) sa[i] = sa[i-1] + i;
    REP(rd_int()){
        
        rd(n, s);
        rep(i, n +2) pre[i] = 0, cnt[i] = 0;
        rep(i, n) if(s[i] == '*') pre[i] = i, cnt[i] = 1;
        rep(i, 1, n) pre[i] += pre[i-1], cnt[i] += cnt[i-1] ;
        if(getcnt(0, n-1) == 0) wt(0), continue;
        ll ans = ll_inf;
        rep(i, n){
            ll xi = i;
            if(s[i] == '*'){
                auto ct = getcnt(0, i-1);
                auto ct2 = getcnt(i+1, n-1);
                auto leftpart = (xi*ct-sa[ct]) - getidx(0,i-1);
                auto rightpart =  getidx(i+1, n-1) - (xi*ct2+sa[ct2]);
                ans <?= leftpart + rightpart;
            }else{
                auto ct = getcnt(0, i-1);
                auto ct2 = getcnt(i+1, n-1);
                if(ct > 0){
                    auto leftpart = xi*ct-sa[ct-1] - getidx(0,i-1);
                    auto rightpart = getidx(i+1, n-1) - (xi*ct2 + sa[ct2]);
                    ans <?= leftpart + rightpart;
                }
                if(ct2 > 0){
                    auto leftpart = xi*ct - sa[ct] - getidx(0, i-1);
                    auto rightpart = getidx(i+1, n-1) - (xi * ct2 + sa[ct2-1]);
                    ans <?= leftpart + rightpart;
                }
            }
        }
        wt(ans);
    }
}
