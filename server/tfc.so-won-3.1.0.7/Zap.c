// Zap__10CLightningRC6VectorT1  @ 000a1960
void Zap__10CLightningRC6VectorT1(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  (*DAT_001c10d8)(0,0x17,0,0);
  (*DAT_001c10e0)(0);
  (*DAT_001c10f4)(*param_2);
  (*DAT_001c10f4)(param_2[1]);
  (*DAT_001c10f4)(param_2[2]);
  (*DAT_001c10f4)(*param_3);
  (*DAT_001c10f4)(param_3[1]);
  (*DAT_001c10f4)(param_3[2]);
  (*DAT_001c10e8)(param_1[0x11b]);
  (*DAT_001c10e0)(param_1[0x11d]);
  (*DAT_001c10e0)((int)ROUND(*(float *)(*param_1 + 0x138)));
  (*DAT_001c10e0)((int)ROUND((float)param_1[0x115] * 10.0));
  (*DAT_001c10e0)(param_1[0x116]);
  (*DAT_001c10e0)(param_1[0x117]);
  (*DAT_001c10e0)((int)ROUND(*(float *)(*param_1 + 0x150)));
  (*DAT_001c10e0)((int)ROUND(*(float *)(*param_1 + 0x154)));
  (*DAT_001c10e0)((int)ROUND(*(float *)(*param_1 + 0x158)));
  (*DAT_001c10e0)((int)ROUND(*(float *)(*param_1 + 0x14c)));
  (*DAT_001c10e0)(param_1[0x119]);
  (*DAT_001c10dc)();
  DoSparks__5CBeamRC6VectorT1(param_1,param_2,param_3);
  return;
}


