//no-unlocked
ll a[2d5+10];
{ 
    REP(rd_int()){
        int @n;
        map<ll,ll> f;
        rd(a(n));
        ll ans = 0 ;
        rep(i, n){
            ans += f[a[i]-i];
            ++f[a[i]-i];
        }
        wt(ans);
    }
}
