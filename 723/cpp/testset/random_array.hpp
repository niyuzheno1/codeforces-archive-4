#pragma once
#include "testlib.hpp" 
int tmp_array[100000];

int * getarray(int n, int a, int b){
    for(int i=(0);i<(n);i++){
      auto u = rnd.next(a,b);
      tmp_array[i] = u;
    }
    return tmp_array;
}