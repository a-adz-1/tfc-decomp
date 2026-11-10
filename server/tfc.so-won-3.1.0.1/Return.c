// Return__19CMomentaryRotButton  @ 00085084
void Return__19CMomentaryRotButton(int *param_1)

{
  float fVar1;
  longdouble lVar2;
  
  lVar2 = (longdouble)
          AxisDelta__11CBaseToggleiRC6VectorT2
                    (*(undefined4 *)(*param_1 + 0x1a0),*param_1 + 0x50,param_1 + 0x121);
  fVar1 = (float)(lVar2 / (longdouble)(float)param_1[0xff]);
  UpdateAllButtons__19CMomentaryRotButtonfi(param_1,fVar1,0);
  if (0.0 < fVar1) {
    UpdateTarget__19CMomentaryRotButtonf(param_1,fVar1);
  }
  return;
}


