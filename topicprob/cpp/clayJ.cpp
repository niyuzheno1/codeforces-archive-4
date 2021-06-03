//no-unlocked
int k,n,L[2d5+10], R[], CP[2d6+30], rCP[], cpsz;
vector<VI> evts[];
void push(int x){
    CP[cpsz++] = x-1;
    CP[cpsz++] = x;
    CP[cpsz++] = x+1;
}
{ 
    combination_mint  comb;
    comb.init(2d5+10);
    rd(n, k, (L,R)(n));
    rep(i, n) push(L[i]), push(R[i]);
    sortA(cpsz, CP);
    int mxn = coordcomp(cpsz, CP, rCP);
    map<int,int> cv;
    map<int,int> icv;
    rep(i, cpsz) cv[CP[i]] = rCP[i], icv[rCP[i]] = CP[i];
    rep(i, n){
        VI ins, outs;
        ins.push_back(-1);
        ins.push_back(i);
        outs.push_back(1);
        outs.push_back(i);
        evts[cv[L[i]]].push_back(ins);
        evts[cv[R[i]]].push_back(outs);
    }
    int pre = -1;
    set<int> swl;
    mint ans = 0;
    rep(i, mxn){
        int m = evts[i].size() ;
        if(m ==0) continue;
        sort(evts[i].begin(), evts[i].end());
        int l = 0;
        if(swl.size() >= k){
            ans += comb.C(swl.size(), k)*(icv[i] - icv[pre]-1);
        }
        while(l < m && evts[i][l][0] == -1){
            swl.insert(evts[i][l][1]);
            ++l;
        }
        if(swl.size() >= k){
            ans += comb.C(swl.size(), k);
        }
        while(l < m && evts[i][l][0] == 1){
            swl.erase(evts[i][l][1]);
            ++l;
        }
        pre = i;
    }
    wt(ans);
}
