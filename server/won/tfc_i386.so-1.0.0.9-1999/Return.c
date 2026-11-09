// Return__19CMomentaryRotButton  @ 0009fa60
void Return__19CMomentaryRotButton(int *param_1)

{
  float fVar1;
  longdouble lVar2;
  
  lVar2 = (longdouble)
          AxisDelta__11CBaseToggleiRC6VectorT2
                    (*(undefined4 *)(*param_1 + 0x180),*param_1 + 0x50,param_1 + 0x11e);
  fVar1 = (float)(lVar2 / (longdouble)(float)param_1[0xfc]);
  UpdateAllButtons__19CMomentaryRotButtonfi
            (param_1,(float)(lVar2 / (longdouble)(float)param_1[0xfc]),0);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    UpdateTarget__19CMomentaryRotButtonf(param_1,fVar1);
  }
  return;
}


