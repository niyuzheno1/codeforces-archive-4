//no-unlocked
int N, As, Bs, A[2d5], B[2d5];
{
  REP(rd_int()){
    int i, j, k, res = 0;
    rd(N,As,Bs);
    rep(i,N) A[i] = B[i] = 0;
    rep(As) A[rd_int()-1]++;
    rep(Bs) B[rd_int()-1]++;
    rep(i,N){
      k = min(A[i], B[i]);
      (As, Bs, A[i], B[i]) -= k;
    }
    rep(i,N) while(As > Bs && A[i] >= 2) res++, (As, A[i]) -= 2;
    rep(i,N) while(Bs > As && B[i] >= 2) res++, (Bs, B[i]) -= 2;
    k = min(As, Bs);
    (As, Bs) -= k;
    res += k;
    res += As + Bs;
    wt(res);
  }
}