// Dispenser_Explode__12CTFDispenser  @ 0009ba90
void Dispenser_Explode__12CTFDispenser(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  
  (*DAT_0019f758)(4,0x17,*param_1 + 8,0);
  (*DAT_0019f760)(0x6b);
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 8));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_0019f774)(0x43c80000);
  (*DAT_0019f768)(param_1[0x1a7]);
  (*DAT_0019f768)(10);
  (*DAT_0019f760)(0x19);
  (*DAT_0019f75c)();
  iVar2 = __rf__7EHANDLE(param_1 + 0x51);
  if (*(int *)(iVar2 + 0x78) != 1) {
    fVar1 = (float)param_1[0x39] * 1.5 + 25.0 + (float)param_1[0x37];
    if (0x3f < (byte)((fVar1 < 250.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 250.0) << 0xe) >> 8)) - 1)) {
      fVar1 = 250.0;
    }
    iVar2 = param_1[0x115];
    puVar3 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x51,fVar1,0,0x4000040);
    (**(code **)(iVar2 + 0x200))(param_1,*param_1,*puVar3);
  }
  (*DAT_0019f758)(5,0x17,*param_1 + 8,0);
  (*DAT_0019f760)(3);
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 8));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_0019f768)((int)g_sModelIndexFireball);
  (*DAT_0019f760)(0x1e);
  (*DAT_0019f760)(0xf);
  (*DAT_0019f760)(3);
  (*DAT_0019f75c)();
  dremove__FP11CBaseEntity(param_1);
  return;
}


