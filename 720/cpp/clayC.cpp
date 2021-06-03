//no-unlocked
//interactive
ofstream sf("transcript.txt");

const int dbg = 0;
const int human = 0;
int Tcases, n;
void init(){
    if(!dbg){
        rd(Tcases);
    }else{
        Tcases = 3;
        sf << Tcases <<endl;

    }
}
int ires[310];
const int len[] = {4,5, 6};
const int aas[3][6] = {{3,1,4,2,0, 0},{2,5,3,4,1, 0}, {6,2,4,3,1,5}};

int curcase = 0;
void init_n(){
    if(!dbg){
        rd(n);
        if(n == -1) exit(0);

    }else{
        n =  100;
        sf << n <<endl;
        // rep(i, len[curcase] ) ires[i] = aas[curcase][i];
        rep(i, 100 ) ires[i] = i+1;
        ++curcase;
        random_shuffle(ires, ires+n);
        wt("Hint:", ires(n));
    }
}
int ask_upperbound; 
int asktimes = 0;

int ask(int t, int i, int j , int x){
    if(!dbg){
        wt("?", t, i, j,  x);
        int y;
        rd(y);
        if(y == -1) exit(0);
        return y;
    }else{
        // keeping the transcript so that we can use human intelligence 
        if(!human) wt("?", t, i, j,  x);
        int res = 0;
        int * p = ires - 1;
        if(t == 1){
            res = max(min(x, p[i]), min(x+1, p[j]));
        }else{
            res = min(max(x, p[i]), max(x+1, p[j]));
        }
        sf << res <<endl;
        
        return res;
    }
}
int ask_2(int t, int i, int j , int x){
    ++asktimes;
    if(i == j){
        return -1;
    }
    return ask(t, i, j, x);
}
void answer(int n, int * ans){
    if(!dbg){
        wt("!", ans(n));
    }else{
        bool good = true;
        rep(i, n){
            if(ires[i] != ans[i]){
                good = false;
                wt("Wrong answer");
                exit(0);
            }
        }
    }
}
int ans[1d6];
int vis[1d6];
int rin[1d6][2];

set<int> cur[1d6];
int curid[1d6];

{ 
    init();
    REP(Tcases){
        init_n();
        if(dbg && human){
            wt(((3*n)/2)+30);
            rep(i, ((3*n)/2)+30){
                int x,y,z,w;
                rd(x,y,z,w);
                wt(ask(x,y,z,w));
            }
        }
        if(!human){
            ask_upperbound =  ((3*n)/2)+30;            
            asktimes = 0 ;
            rep(i, 0, n+1){
                cur[i].clear();
            }
            int csz = 0;
            rep(i, 1, n, 2){
                int gmax1 = ask_2(1, i, i+1, n-1);
                int gmax3 = ask_2(2, i,i+1,  1);
                cur[csz].insert(gmax1);
                cur[csz].insert(gmax3);
                rin[csz][0] = i;
                rin[csz][1] = i+1;
                curid[i]= csz;
                curid[i+1]= csz;
                ++csz;
            }
            int oneset[3], osz =0;
            rep(i, csz){
                if(cur[i].find(1) != cur[i].end()){
                    oneset[osz] = i;
                    ++osz;
                }
                if(cur[i].find(2) != cur[i].end()){
                    oneset[osz] = i;
                    ++osz;
                }
            }
            if(osz == 1){
                oneset[osz] = csz;
                rin[csz][0] = n;
                rin[csz][1] = n;
                ++csz;
            }
            int oneind = 0;
            if(dbg) wt(oneset(2));
            rep(i, 2) rep(j, 2) {
                if(ask_2(1, rin[oneset[0]][i],rin[oneset[1]][j], 1 ) == 1){
                    oneind = rin[oneset[1]][j];
                    break;
                }
                if(ask_2(1,rin[oneset[1]][j], rin[oneset[0]][i], 1 ) == 1){
                    oneind = rin[oneset[0]][i];
                    break;
                }
            }
            if(dbg) wt(oneind);
            ans[oneind] = 1;
            rep(i, 1, n+1) vis[i] = 0;
            int kid = 0;
            rep(i, 1, n+1){
                if(i == oneind || vis[i]) continue; 
                ans[i] = ask_2(1, oneind, i, n-1);
                vis[i] = 1;
                int uuid = curid[i];
                if(i % 2== 0 || cur[uuid].find(n-1) != cur[uuid].end())  continue;
                for(auto & x : cur[uuid]){
                    if(x != ans[i]) {
                        ans[i+1] = x;
                        vis[i+1] = 1;
                    }
                }
            }
            ans[oneind] = 1;
            if(dbg) wt(asktimes, ask_upperbound);
            int * tmp = ans+1;
            if(dbg) wt(tmp(n));
            answer(n, tmp);
        }
    }

    exit(0);
}
