//no-unlocked
int pre[1d5+10], m , n, X;
int idx[], a[], ans[], v[];
#define pii pair<int,int>
#define val first
#define sid second
#define mp make_pair
#define pq_type priority_queue<pii>

{ 
  REP(rd_int()){
    rd(n,m , X, a(n));
    rep(i, n) idx[i] = i;
    sortA(n, a, idx);
    pq_type pq;
    rep(i, m){
        pq.push(mp(0, i+1));
    }
    rep(i, n){
        auto u = pq.top(); pq.pop();
        ans[idx[i]] = u.sid;
        pq.push(mp(u.val-a[i], u.sid));
    }
    int vsz = 0;
    while(!pq.empty()){
        v[vsz++] = -pq.top().val; pq.pop();
    }
    sortA(vsz, v);
    bool flag = true;
    int gt = 0, lt = int_inf;
    rep(i, vsz){
        gt = max(v[i]-X, gt);
        lt = min(v[i]+X, lt);
    }
    if(lt < gt){
        wt("NO"); continue;
    }
    wt("YES");
    wt(ans(n));
  }
}
