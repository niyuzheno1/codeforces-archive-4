//no-unlocked
ll n, m , X, a[3d5+10],  ans[], ahe, asz, ta[];
int A[], B[],C[];
wgraph<int> g;

void dfs(int x, int b, int id){
    rep(i, g.es[x]){
        int y = g.edge[x][i];
        int yid = g.cost[x][i];
        if(y == b) continue;
        dfs(y, x, yid);
    }

    if(id != -1){
        if(a[x] >= X){
            a[b] += a[x] - X;
            ans[ahe++] = id;
        }else{
            ans[asz--] = id;
        }
    }
}


{
    unionFind uf;
    rd(n, m, X, a(n), (A--,B--)(m));
    ahe = 0;
    asz = n-2;
    iota(C, C+m, 1);
    ll ve = sum(a(n));
    if(ve < (n-1)*X) wt("NO"), exit(0);
    uf.walloc(n);
    uf.init(n);
    int k = 0;
    rep(i, m) if(uf(A[i], B[i])) (A[k], B[k], C[k]) = (A[i], B[i], C[i]), ++k;
    g.setEdge(n, n-1, A, B, C);
    dfs(0, -1, -1);
    wt("YES");
    rep(i, n-1) wt(ans[i]);
}