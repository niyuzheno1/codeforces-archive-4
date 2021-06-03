//no-unlocked
//no-insert-define_MD
#define MD (998244353U)
modint f[5010][5010];
modint solve(int x, int y){
    
    rep(i, x+3) rep(j, y+3) f[i][j] = 0;
    f[0][y] = 1;
    rep(i, x){
        rep(j, y+1){
            f[i+1][j] += f[i][j];
            if(j >= 1) f[i+1][j-1] += j*f[i][j];
        }
    }
    modint ans = 0;
    rep(j, y+2) ans += f[x][j];
    return ans;
}

{ 
  int @a, @b, @c;
  modint ans = 1;
  ans *= solve(a, b);
  ans *= solve(b, c);
  ans *= solve(c, a);
  wt(ans);
}
