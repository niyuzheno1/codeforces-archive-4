//no-unlocked
ll n, m , X, a[3d5+10],  ans[], asz, ta[];
int A[], B[],C[];
struct UnionFindWithUpdates{
    unionFind f;
    int * d;
    void init(){
        d = f.d;
    }
    inline int connect(int a, int b){
        if(d[a]>=0){
            a=f.get(a);
        }
        if(d[b]>=0){
            b=f.get(b);
        }
        if(a==b){
            return 0;
        }
        if(d[a] < d[b]){
            d[a] += d[b];
            ta[a] += ta[b];
            d[b] = a;
        }
        else{
            d[b] += d[a];
            ta[b] += ta[a];
            d[a] = b;
        }
        return 1;
    }
};

DijkstraHeap<ll> h;
wgraph<int> g;
{ 
    UnionFindWithUpdates  uf;
    rd(n, m, X, a(n), (A--,B--)(m));
    rep(i, n) ta[i] = a[i];
    ll ve = sum(a(n));
    if(ve < (n-1)*X){
        wt("NO"); exit(0);
    }
    uf.f.walloc(n);
    uf.f.init(n);
    uf.init();
    h.walloc(n);
    h.init(n);
    rep(i, n) h.change(i, -a[i]);
    rep(i, m) C[i] = i+1;
    g.setEdge(n, m, A, B, C);
    while(h.size){
        auto i = h.pop();
        auto v = -h.val[i];
        if(v != ta[uf.f(i)]){
            h.change(i, -ta[uf.f(i)]);
            continue;
        }
        rep(j, g.es[i]){
            int to = g.edge[i][j];
            if(uf.connect(i, to)){
                int x = uf.f(i);
                h.change(i, -(ta[x]-X)), h.change(to, -(ta[x]-X)), ta[x]-=X, ans[asz++] = g.cost[i][j];
                break;
            }
        }
    }
    wt("YES");
    rep(i, asz) wt(ans[i]);
}
