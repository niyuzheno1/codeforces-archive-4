//no-unlocked
combination_mint  c;
mint dp[410][410];
int n, M;
mint pw2[410];
{ 
    rd(n,M);
    dp[0][0].setmod(M);
    mint res = 0;
    pw2[0] = 1;
    pw2[1] = 2;
    rep(i,2,  410) pw2[i] = 2*pw2[i-1];
    
    c.init(410);
    
    dp[0][0] = 1;
    rep(i, n)
    {
        rep(j, i+1){
            rep(k, 1, n+1){
                if(i+k > n ) break;
                dp[i+k+1][j+k] += dp[i][j] * c.C(j + k,k) * pw2[(k-1)];
            }
        }
    }
    rep(i, n+1) res += dp[n+1][i];
    wt(res);
}
