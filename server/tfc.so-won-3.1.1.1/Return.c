// Return__19CMomentaryRotButton  @ 0008c780
void Return__19CMomentaryRotButton(int *param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)
          AxisDelta__11CBaseToggleiRC6VectorT2
                    (*(undefined4 *)(*param_1 + 0x1a0),*param_1 + 0x50,param_1 + 0x141);
  lVar1 = lVar1 / (longdouble)(float)param_1[0x11f];
  UpdateAllButtons__19CMomentaryRotButtonfi(param_1,(float)lVar1,0);
  if ((longdouble)0 < lVar1) {
    UpdateTarget__19CMomentaryRotButtonf(param_1,(float)lVar1);
  }
  return;
}


