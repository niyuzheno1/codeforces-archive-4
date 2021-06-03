//no-unlocked
{ 
  REP(rd_int()){
      ll @A, @B;
      bool flag = false;
      int k = 1;
      if(B % 2 == 0) k = 2;
      rep(j, k*B){
          int other = (k*B-j);
          if( (A* j % B == 0 || A* other % B ==0 || A* j  ==  A* other) ) continue;
          flag = true;
          wt("YES");
          wt(A * j, A*other, A*j + A*other);
          break_continue;
      }
      wt("NO");
  }
}
