//no-unlocked
int A[2d5+40], B[], n, l, r;
{ 
  REP(rd_int()){
      rd(n, l, r);
      rep(i, n) A[i] = B[i] = 0;
      rep(i, l) ++A[rd_int()-1];
      rep(i, r) ++B[rd_int()-1];
      int ans = 0;
      //match the same color and left and right
      rep(i, n){ int k = min(A[i],B[i]);  (l, r, A[i], B[i]) -= k; }
      //reorient the socks and match the color if we have l > r 
      rep(i,n) while(l > r && A[i] >= 2) ++ans, (l, A[i]) -= 2;
      rep(i,n) while(l < r && B[i] >= 2) ++ans, (r, B[i]) -= 2;
      // recoloring the socks so that they match 
      int k =  min(l, r);
      (l,r) -= k;
      ans += k;
      //everything else
      ans += (l+r);
      wt(ans);
  }
}
