//no-unlocked
{ 
  REP(rd_int()){
      ll @A, @B;
      if(B == 2){
          if(A % B == 0){
              wt("NO");
              continue;
          }
          wt("YES");
          wt(A, 3 * A, 4*A);
          continue;
      }else{
          if(A % B  == 0){
              wt("NO");
              continue;
          }
          wt("YES");
          wt(A, (B-1)*A, A*B);
      }
  }
}
