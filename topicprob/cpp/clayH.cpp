//no-unlocked
const int mxn =  1<<19;
int n, a[1d5+10], b[72], pr[], psz, cnt[];
mint dp[mxn], new_dp[];
{ 
    rd(n, a(n));
    rep(i, n) cnt[a[i]]++;
    psz = Prime(70, pr);
    rep(i, psz) b[pr[i]] = i;
    combination_mint  comb;
    comb.init(1d5+10);
    dp[0] = 1;
    rep(i, 1, 70+1){
        if(cnt[i] == 0) continue;
        int tmp = i, mask = 0;
        while(tmp > 1){
            rep(j, psz) while(tmp % pr[j] == 0) tmp /= pr[j], mask ^= (1<<b[pr[j]]);
        }
        mint addeven = 0, addodd = 0;
        rep(j, 0, cnt[i]+1, 2) addeven += comb.C(cnt[i], j);
        rep(j, 1, cnt[i]+1, 2) addodd += comb.C(cnt[i], j);
        rep(j, 0, mxn) new_dp[j] = addeven * dp[j];
        rep(j, 0, mxn) new_dp[j^mask] += addodd * dp[j];
        
        memcpy(dp, new_dp, sizeof(dp));
    }
    wt(dp[0]-1);
}
