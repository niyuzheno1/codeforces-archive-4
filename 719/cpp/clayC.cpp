//no-unlocked
const int dx[] = {1, -1, 0, 0};
const int dy[] = { 0, 0, 1, -1};
int n;
int a[110][110];
bool within(int x, int y){
    return 0 <= x < n && 0 <= y < n;
}
bool check(){
    rep(i, n) rep(j, n){
        rep(k, 4){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(!within(ni,nj)) continue;
            if(abs(a[ni][nj] - a[i][j]) == 1) return false;
        }
    }
    return true;
}

{ 
    REP(rd_int()){
        rd(n);
        rep(i, n+2) rep(j, n+2) a[i][j] = 0;
        int left = 2, right = n*n-1;
        rep(i, 2 * n){
            if(i == 0 || i == 2*(n-1)) continue;
            rep(j, n){
                if(!within(i-j, j) ) continue;
                a[i-j][j] = left++;
            }
        }
        a[0][0] = 0;
        if(n >= 2)
        a[n-1][n-1] = 1;
        rep(i, n) rep(j, n) ++a[i][j];
        if(!check()) wt(-1), continue;
        rep(i, n) wt(a[i](n));
    }
}
