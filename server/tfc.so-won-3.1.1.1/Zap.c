// Zap__10CLightningRC6VectorT1  @ 000a0904
void Zap__10CLightningRC6VectorT1(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  (*DAT_0019f758)(0,0x17,0,0);
  (*DAT_0019f760)(0);
  (*DAT_0019f774)(*param_2);
  (*DAT_0019f774)(param_2[1]);
  (*DAT_0019f774)(param_2[2]);
  (*DAT_0019f774)(*param_3);
  (*DAT_0019f774)(param_3[1]);
  (*DAT_0019f774)(param_3[2]);
  (*DAT_0019f768)(param_1[0x11f]);
  (*DAT_0019f760)(param_1[0x121]);
  (*DAT_0019f760)((int)ROUND(*(float *)(*param_1 + 0x138)));
  (*DAT_0019f760)((int)ROUND((float)param_1[0x119] * 10.0));
  (*DAT_0019f760)(param_1[0x11a]);
  (*DAT_0019f760)(param_1[0x11b]);
  (*DAT_0019f760)((int)ROUND(*(float *)(*param_1 + 0x150)));
  (*DAT_0019f760)((int)ROUND(*(float *)(*param_1 + 0x154)));
  (*DAT_0019f760)((int)ROUND(*(float *)(*param_1 + 0x158)));
  (*DAT_0019f760)((int)ROUND(*(float *)(*param_1 + 0x14c)));
  (*DAT_0019f760)(param_1[0x11d]);
  (*DAT_0019f75c)();
  iVar1 = *param_1;
  if ((*(uint *)(iVar1 + 0x1a0) & 0x30) != 0) {
    if ((*(uint *)(iVar1 + 0x1a0) & 0x10) != 0) {
      UTIL_Sparks__FRC6Vector(param_2);
      iVar1 = *param_1;
    }
    if ((*(byte *)(iVar1 + 0x1a0) & 0x20) != 0) {
      UTIL_Sparks__FRC6Vector(param_3);
    }
  }
  return;
}


