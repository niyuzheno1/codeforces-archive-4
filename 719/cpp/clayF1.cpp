//no-unlocked
//interactive
const int dbg = 0;
const int seed = 671242145;
#include <random>
int n, t, k;
int target;
vector<int> hid;
vector<int> ori;
void init(){
    if(!dbg){
        rd(n,t);
    }else{
        //n = 20, t = 1;
        n = 6, t = 1;
    }
}
const int arr[] = {1, 0, 1, 1, 0 ,1};
void init_k(){
    if(!dbg){
        rd(k);
    }
    else{
        rep(i , 6) hid.push_back(arr[i]);
        rep(i , 6) ori.push_back(arr[i]);
        k = 2;
        target = 5;
        // srand(seed);
        // rep(i, n) hid.push_back(rand()%2);
        // ori = hid;
        // int kk = 0;
        // rep(i, n) if(hid[i] == 0) ++kk;
        // k = rand()%kk;
        // kk = 0;
        // rep(i, n) {
        //     if(hid[i] == 0){
        //         if(kk == k) target = i + 1;
        //         ++kk;
        //     }
        // }
        // ++k;
    }
}

int ask(int l, int r){
    if(!dbg){
        wt("?", l, r);
        int x;
        rd(x);
        if(x == -1) exit(0);
        return x;
    }else{
        --l;
        int cnt = 0;
        rep(i, l, r){
            cnt += hid[i];
        }
        
        return cnt;
    }
}

void answer(int x){
    if(!dbg){
        wt("!", x);
        exit(0);
    }else{
        int k = 0;
        if(x == target){
            cout << "accepted" <<endl;
            return;
        }else{
            cout << "wrong answer " << x << ":" << target <<endl;
            exit(0);
        }
    }
}

int len(int x, int y){
    return y-x+1;
}

int findans(int l, int r, int k, int flipped){
    if(l == r) return l;
    int md = (l+r)>>1;
    int x = ask(l+1, md+1);
    int leftpart = flipped ?  x: (len(l+1, md+1) - x);
    if( leftpart >= k) return findans(l, md, k, flipped);
    else return findans(md+1, r, k-leftpart, flipped);
}

{ 
  init();
  REP(tcases, t){
      init_k();
      int ans=findans(0, n-1, k, 0);
      answer(ans+1);
  }
}
