//no-unlocked
//interactive
const int dbg = 0;
const int seed = 671242145;
#include <random>
int n, t, k;
int target;
vector<int> hid;
vector<int> ori;
int gettarget(){
        int kk = 0;
        rep(i, n) if(hid[i] == 0) ++kk;
        k = rand()%kk;
        kk = 0;
        rep(i, n) {
            if(hid[i] == 0){
                if(kk == k) target = i + 1;
                ++kk;
            }
        }
        ++k;
        return kk;
}
const int arr[] = {1, 0, 1, 1, 0 ,1};

void init(){
    if(!dbg){
        rd(n,t);
    }else{
        // n = 2d5, t = 1;
        // srand(seed);
        // rep(i, n) hid.push_back(rand()%2);
        // ori = hid;
        // t = min(1d4,gettarget());
        n = 6, t = 2;
        rep(i , 6) hid.push_back(arr[i]);
        rep(i , 6) ori.push_back(arr[i]);
        target = 5;
    }
}



void init_k(){
    if(!dbg){
        rd(k);
    }
    else{
        gettarget();
        //k = 2;

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
    }else{
        int k = 0;
        hid[target-1] = 1;
        if(x == target){
            cout << "accepted" << target <<endl;
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

fenwick<int> tr;

int preprocess(){
    tr.walloc(2d5);
    tr.init(2d5);
    rep(i, 0, n, 10){
        int next = min(n-1, i + 10 -1);
        tr.add(i/10, len(i, next)-ask(i+1, next+1));
        if(next == n-1){
            return i/10;
        }
    }
}

{ 
  init();
  int upperbnd = 0;
  REP(tcases, t){
      init_k();
      if(tcases == 0){
          upperbnd = preprocess();
      }
      int mn = bsearch_max[int, x, 0, upperbnd](tr.get(x) < k);
      mn = max(mn-2, 0);
      while(mn * 10 < n&& tr.get(mn) < k) ++ mn;
      --mn;
      auto part1 = 0;
      if(mn >= 0) part1= tr.get(mn);
      auto part2 = min(n-1, (mn+2) * 10-1);
      //auto part3 = len(1, (mn+1)*10) - ask(1, (mn+1)*10);
      int ans=findans((mn+1)*10, part2, k-part1, 0);
      answer(ans+1);
      tr.add((mn+1), -1);
  }
  exit(0);
}
