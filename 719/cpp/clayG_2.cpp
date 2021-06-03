//no-unlocked
int n, m;
ll w;
ll a[2d3+10][2d3+10];
ll f[2d3+10][2d3+10];
bool within(int x, int y){
    return (0 <= x < n) && (0 <= y < m) && a[x][y] != -1;
}
int q[(2d3+10)*(2d3+10)], qed;
{ 
    rd(n, m, w, a(n, m));
    int tot = n*m+1;
    ll res = ll_inf;
    dimcomp2 dim(n,m);
    DijkstraHeap<ll> hp;
    hp.walloc(tot);
    hp.init(tot);
    rep(i, n) rep(j, m) f[i][j] = ll_inf;
    rep(i, n) rep(j, m) if(a[i][j] > 0) { hp.change( dim(i,j), a[i][j]); f[i][j] = a[i][j]; }
    while(hp.size){
        int x = hp.pop();
        auto y = hp.val[x];
        int _x, _y;
        dim(x, _x, _y);
        if(y > f[_x][_y]) continue;
        f[_x][_y] = y;
        rep(i, -1, 2) rep(j, -1, 2){
            if(abs(i)+abs(j) != 1) continue;
            int nx, ny;
            nx = _x + i; ny = _y + j;
            if(!within(nx,ny)) continue;
            hp.change(dim(nx,ny), w + y);
        }
    }
    if(f[0][0] != ll_inf && f[n-1][m-1] != ll_inf) res = f[0][0] +  f[n-1][m-1];
    rep(i, n) rep(j, m) f[i][j] = ll_inf;
    q[qed++] = 0;
    f[0][0] = 0;
    rep[q](i, qed){
        int _x, _y;
        dim(i, _x, _y);
        rep(i, -1, 2) rep(j, -1, 2){
            if(abs(i)+abs(j) != 1) continue;
            int nx, ny;
            nx = _x + i; ny = _y + j;
            if(!within(nx,ny)) continue;
            if(f[nx][ny] > f[_x][_y] + w){
                f[nx][ny] = f[_x][_y] + w;
                q[qed++] = dim(nx,ny);
            }
        }
    }
    res <?= f[n-1][m-1];
    if(res == ll_inf) wt(-1), return 0;
    wt(res);
}
