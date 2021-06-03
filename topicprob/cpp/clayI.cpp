//no-unlocked
int n, K;
ll L[1d3+10], R[];
double P[], dp[1d3+10][1d3+10];
ll getones(ll x){
    if(x == 0) return 0;
    ll ret = 0;
    auto s = to_string(x);
    int n = s.length();
    rep(i, 1, n){
        ret += 10LL ** (i-1);
    }
    if(s[0] == '1'){
        auto t = s.substr(1);
        t = '0' + t;
        ret += stoll(t)+1;
    }else{
        ret += 10LL ** (n-1);
    }
    return ret;
}
{ 
    rd(n);
    if(n == -1) return 0;
    rd((L,R)(n), K);
    rep(i, n){
        auto delta = getones(R[i])-getones(L[i]-1);
        double prob = delta;
        prob /= double(R[i]-L[i]+1);
        P[i] = prob;
    }
    dp[0][0] = 1;
    rep(i, n+1){
        rep(j, n+1){
            dp[i+1][j+1] += dp[i][j] * P[i];
            dp[i+1][j] += dp[i][j] * (1.0 - P[i]);
        }
    }
    double ans = 0;
    rep(i, n+1){
        if(i * 100 >= K * n) ans += dp[n][i];
    }
    wt(ans);
}
