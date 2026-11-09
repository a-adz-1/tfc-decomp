// TrainSpeed__Fii  @ 000d6810
undefined4 TrainSpeed__Fii(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 < 0) {
    uVar1 = 5;
  }
  else if (param_1 == 0) {
    uVar1 = 1;
  }
  else if (0.33 <= (double)param_1 / (double)param_2) {
    uVar1 = 4;
    if ((double)param_1 / (double)param_2 < 0.66) {
      uVar1 = 3;
    }
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}


