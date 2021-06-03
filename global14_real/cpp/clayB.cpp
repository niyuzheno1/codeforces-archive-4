//no-unlocked

bool good(int x){
    if(x % 2== 0){
      int y = x/2;
      y = sqrt(y);
      if(y * y == x/2)
        return true;
      
    }
    if(x % 4== 0){
      int y = x/4;
      y = sqrt(y);
      if(y * y == x/4)
        return true;
     
    }
    return false;
   
}

{ 
  REP(rd_int()){
      int @n;
      wt(if[good(n), "YES", "NO"]);
  }
}
