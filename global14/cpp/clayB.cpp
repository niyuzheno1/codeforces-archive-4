//no-unlocked
{ 
  REP(rd_int()){
      ll @n;
      bool flag = false;
      if(n % 2 == 0 && Isqrt_s(n/2) != -1) flag = true;
      if(n % 4 == 0 && Isqrt_s(n/4) != -1) flag = true;
      wt(if[flag, "YES", "NO"]);
  }
}
