// Return__19CMomentaryRotButton  @ 0008d088
void Return__19CMomentaryRotButton(int *param_1)

{
  float fVar1;
  longdouble lVar2;
  
  lVar2 = (longdouble)
          AxisDelta__11CBaseToggleiRC6VectorT2
                    (*(undefined4 *)(*param_1 + 0x1a0),*param_1 + 0x50,param_1 + 0x13d);
  fVar1 = (float)(lVar2 / (longdouble)(float)param_1[0x11b]);
  UpdateAllButtons__19CMomentaryRotButtonfi(param_1,fVar1,0);
  if (0.0 < fVar1) {
    UpdateTarget__19CMomentaryRotButtonf(param_1,fVar1);
  }
  return;
}


