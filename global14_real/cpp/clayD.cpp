//no-unlocked
int n, l, r, c[2d5+10], d[];
int idc(int x){
    if(x > 0) return 1;
    else return -1;
}
int nidc(int x){
    if(x % 2 == 0) return 0;
    return idc(x);
}

int oneway(){
      rep(i, n){
          int p1 = 0;
          if( i < l) p1 = 1;
          else p1 = -1;
          d[c[i]] += p1;
      }
      sortA(n+1, d);
      int pos = n;
      int pre = 0;
      int cost = 0;

      while(pre < pos){
          if(d[pre] >= 0 || d[pos] <= 0) break;
          int delta = min(abs(d[pre]), abs(d[pos]));
          cost += delta;
          d[pos] -= delta;
          d[pre] += delta;
          if(d[pos] == 0) --pos;
          if(d[pre] == 0) ++pre;
      }
      rep(i, n+2){
          if(d[i] == 0) continue;
          if(d[i] == idc(d[i])) continue;
          cost += abs(d[i])/2;
          d[i] = nidc(d[i]);
      }
      int u = sum(d(n+2));      
      return (cost + abs(u));

}

int otherway(){
      rep(i, n){
          int p1 = 0;
          if( i < l) p1 = 1;
          else p1 = -1;
          d[c[i]] += p1;
      }
      int pos = n;
      int pre = 0;
      int cost = 0;
      rep(i, n+2){
          if(d[i] == 0) continue;
          if(d[i] == idc(d[i])) continue;
          cost += abs(d[i])/2;
          d[i] = nidc(d[i]);
      }
      sortA(n+1, d);

      while(pre < pos){
          if(d[pre] >= 0 || d[pos] <= 0) break;
          int delta = min(abs(d[pre]), abs(d[pos]));
          cost += delta;
          d[pos] -= delta;
          d[pre] += delta;
          if(d[pos] == 0) --pos;
          if(d[pre] == 0) ++pre;
      }
      
      int u = sum(d(n+2));      
      return (cost + abs(u));

}

{ 
  REP(rd_int()){
      rd(n, l, r, c(n));
      wt(oneway());
      rep(i, 0, n + 10) d[i] = 0;
  }
}
