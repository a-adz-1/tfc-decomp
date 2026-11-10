// Sentry_Explode__12CTFSentrygun  @ 000edb94
void Sentry_Explode__12CTFSentrygun(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  (*DAT_0019f758)(4,0x17,*param_1 + 8,0);
  (*DAT_0019f760)(0x6b);
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 8));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_0019f774)(0x43c80000);
  (*DAT_0019f768)(param_1[0x1a8]);
  (*DAT_0019f768)(0xf);
  (*DAT_0019f760)(0x19);
  (*DAT_0019f75c)();
  *(undefined4 *)(*param_1 + 0x16c) = 0;
  iVar1 = __rf__7EHANDLE(param_1 + 0x51);
  if (*(int *)(iVar1 + 0x78) != 1) {
    iVar1 = param_1[0x115];
    puVar2 = (undefined4 *)
             __rf__7EHANDLE(param_1 + 0x51,(float)(param_1[0x39] * 8 + 0x4b),0,0x4000040);
    (**(code **)(iVar1 + 0x200))(param_1,*param_1,*puVar2);
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
  uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x26);
  dremove__FP11CBaseEntity(uVar3);
  dremove__FP11CBaseEntity(param_1);
  return;
}


