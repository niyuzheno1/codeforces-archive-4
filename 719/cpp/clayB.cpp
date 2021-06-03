//no-unlocked
vector<ll> ords;
map<ll, int> e; 
{ 
  rep(i, 1, 10){
      string u = to_string(i);
      string tmp;
      while(tmp.length() < 9){
          tmp += u;
          auto v = stoll(tmp);
          if(e[v] == 1) continue;
          ords.push_back(v);
          e[v] = 1;
      }
  }
  sort(ords.begin(), ords.end());
  REP(rd_int()){
      int @n;
      int cnt = 0;
      rep(i, ords.size()){
          if(ords[i] > n) break;
          ++cnt;
      }
      wt(cnt);
  }
}
