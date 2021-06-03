//no-unlocked
int n;
char a[51];
int cnt[51];
{ 
    REP(rd_int()){
        memset(cnt, 0, sizeof(cnt));
        rd(n, a);
        rep(i,n) a[i] -= 'A';
        int cur = 'Z'-'A'+2;
        rep(i, n){
            if(cur != a[i]){
                ++cnt[cur];
                cur = a[i];
            }
        }
        ++cnt[cur];
        bool flag = true;
        rep(i, 'A'-'A', 'Z'-'A' + 1){
            if(cnt[i] > 1) flag = false;
        }
        wt(if[flag, "YES", "NO"]);
    }
}
