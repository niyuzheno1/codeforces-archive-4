//no-unlocked
int n, a[100010],  dis[];
modint g[], f[];

void standard(){ 
  rd(n, a(n));
  rep(i, n) ++dis[a[i]];
  rep(i, 2, 1d5+1){
      int cnt = 0;
      rep(j, i, 1d5+1, i) cnt += dis[j];
      modint tmp;
      tmp = 2;
      tmp = tmp.pw(cnt);
      --tmp;
      g[i] = tmp;
      f[i] = tmp;
  }
  rrep(i, 2, 1d5+1){
      f[i] = g[i];
      rep(j, i*2, 1d5+1, i) f[i] -= f[j];
  }
  modint ans;
  ans = 2;
  ans = ans.pw(n); --ans;
  modint su = sum(f(1d5+1));
  ans -= su;
  wt(ans);
}



{ 
  rd(n, a(n));
  rep(i, n) ++dis[a[i]];
  rep(i, 2, 1d5+1){
      int cnt = 0;
      rep(j, i, 1d5+1, i) cnt += dis[j];
      modint tmp;
      tmp = 2;
      tmp = tmp.pw(cnt);
      --tmp;
      g[i] = tmp;
      f[i] = tmp;
  }
  modint su = 0;
  rep(i, 2, 1d5+1){
    su += Moebius(i) * g[i];      
  }

  modint ans;
  ans = 2;
  ans = ans.pw(n); --ans;
  ans += su;
  wt(ans);
}
