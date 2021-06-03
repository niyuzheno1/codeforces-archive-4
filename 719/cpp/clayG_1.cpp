//no-unlocked
int n, m;
ll w;
ll a[2d3+10][2d3+10];
bool within(int x, int y){
    return (0 <= x < n) && (0 <= y < m) && a[x][y] != -1;
}
{ 
    rd(n, m, w, a(n, m));
    int tot = n*m+1;
    dimcomp2 dim(n,m);
    DijkstraHeap<ll> hp;
    hp.walloc(tot);
    hp.init(tot);
    hp.change(0, 0);
    ll res = -1;
    while(hp.size){
        int x = hp.pop();
        ll y = hp.val[x];
        if(x == tot-1){
            rep(i,n) rep(j, m) if(a[i][j] > 0) hp.change(dim(i,j), a[i][j]+ y);
            continue;
        }
        if(x == dim(n-1,m-1)){
            res = y;
            break;
        }
        int _x, _y;
        dim(x, _x, _y);
        if(a[_x][_y] > 0){hp.change(tot-1, a[_x][_y] + y);}
        rep(i, -1, 2) rep(j, -1, 2){
            if(abs(i)+abs(j) != 1) continue;
            int nx, ny;
            nx = _x + i; ny = _y + j;
            if(!within(nx,ny)) continue;
            hp.change(dim(nx,ny), w + y);
        }
    }
    
    wt(res);
}
