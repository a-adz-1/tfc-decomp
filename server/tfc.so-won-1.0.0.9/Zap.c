// Zap__10CLightningRC6VectorT1  @ 000acbd0
void Zap__10CLightningRC6VectorT1(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  (*DAT_00175578)(0,0x17,0,0);
  (*DAT_00175580)(0);
  (*DAT_00175594)(*param_2);
  (*DAT_00175594)(param_2[1]);
  (*DAT_00175594)(param_2[2]);
  (*DAT_00175594)(*param_3);
  (*DAT_00175594)(param_3[1]);
  (*DAT_00175594)(param_3[2]);
  (*DAT_00175588)(param_1[0xfc]);
  (*DAT_00175580)(param_1[0xfe]);
  (*DAT_00175580)((int)ROUND(*(float *)(*param_1 + 0x118)));
  (*DAT_00175580)((int)ROUND((float)param_1[0xf6] * 10.0));
  (*DAT_00175580)(param_1[0xf7]);
  (*DAT_00175580)(param_1[0xf8]);
  (*DAT_00175580)((int)ROUND(*(float *)(*param_1 + 0x130)));
  (*DAT_00175580)((int)ROUND(*(float *)(*param_1 + 0x134)));
  (*DAT_00175580)((int)ROUND(*(float *)(*param_1 + 0x138)));
  (*DAT_00175580)((int)ROUND(*(float *)(*param_1 + 300)));
  (*DAT_00175580)(param_1[0xfa]);
  (*DAT_0017557c)();
  DoSparks__5CBeamRC6VectorT1(param_1,param_2,param_3);
  return;
}


