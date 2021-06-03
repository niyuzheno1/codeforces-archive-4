//no-unlocked
int n, m;
ll w;
ll a[2d3+10][2d3+10];
ll f[2][2d3+10][2d3+10];
bool within(int x, int y){
    return (0 <= x < n) && (0 <= y < m) && a[x][y] != -1;
}
int q[(2d3+10)*(2d3+10)], qed;
{ 
    rd(n, m, w, a(n, m));
    memset(f, 0xff, sizeof(f));
    dimcomp2 dim(n,m);
    int tot = n*m+1;
    ll res = ll_inf;
    rep(k, 2){
        int sx = k > 0 ? n - 1 : 0;
        int sy = k > 0 ? m - 1 : 0;
        qed = 0;
        q[qed++] = dim(sx, sy);
        f[k][sx][sy] = 0;
        rep[q](i, qed){
            int _x, _y;
            dim(i, _x, _y);
            rep(i, -1, 2) rep(j, -1, 2){
                if(abs(i)+abs(j) != 1) continue;
                int nx, ny;
                nx = _x + i; ny = _y + j;
                if(!within(nx,ny)) continue;
                if(f[k][nx][ny]  == -1 || f[k][nx][ny] > f[k][_x][_y] + w){
                    f[k][nx][ny] = f[k][_x][_y] + w;
                    q[qed++] = dim(nx,ny);
                }
            }
        }
    }
    ll ans[2];
    ans[0] = ans[1] = ll_inf;
    if(f[1][0][0] >= 0) res = f[1][0][0];
    rep(i, n) rep(j, m) rep(k, 2) if(a[i][j] > 0 && f[k][i][j] >= 0) ans[k] <?= f[k][i][j]+a[i][j];
    res <?= ans[0] + ans[1];
    if(res == ll_inf) wt(-1), return 0;
    wt(res);
}
