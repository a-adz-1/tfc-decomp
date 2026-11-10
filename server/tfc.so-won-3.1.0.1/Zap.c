// Zap__10CLightningRC6VectorT1  @ 000973e0
void Zap__10CLightningRC6VectorT1(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  (*DAT_001a7ef8)(0,0x17,0,0);
  (*DAT_001a7f00)(0);
  (*DAT_001a7f14)(*param_2);
  (*DAT_001a7f14)(param_2[1]);
  (*DAT_001a7f14)(param_2[2]);
  (*DAT_001a7f14)(*param_3);
  (*DAT_001a7f14)(param_3[1]);
  (*DAT_001a7f14)(param_3[2]);
  (*DAT_001a7f08)(param_1[0xff]);
  (*DAT_001a7f00)(param_1[0x101]);
  (*DAT_001a7f00)((int)ROUND(*(float *)(*param_1 + 0x138)));
  (*DAT_001a7f00)((int)ROUND((float)param_1[0xf9] * 10.0));
  (*DAT_001a7f00)(param_1[0xfa]);
  (*DAT_001a7f00)(param_1[0xfb]);
  (*DAT_001a7f00)((int)ROUND(*(float *)(*param_1 + 0x150)));
  (*DAT_001a7f00)((int)ROUND(*(float *)(*param_1 + 0x154)));
  (*DAT_001a7f00)((int)ROUND(*(float *)(*param_1 + 0x158)));
  (*DAT_001a7f00)((int)ROUND(*(float *)(*param_1 + 0x14c)));
  (*DAT_001a7f00)(param_1[0xfd]);
  (*DAT_001a7efc)();
  DoSparks__5CBeamRC6VectorT1(param_1,param_2,param_3);
  return;
}


