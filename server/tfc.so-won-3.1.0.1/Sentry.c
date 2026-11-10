// Sentry_Explode__12CTFSentrygun  @ 000dfce0
void Sentry_Explode__12CTFSentrygun(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  (*DAT_001a7ef8)(4,0x17,*param_1 + 8,0);
  (*DAT_001a7f00)(0x6b);
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 8));
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_001a7f14)(0x43c80000);
  (*DAT_001a7f08)(param_1[0x188]);
  (*DAT_001a7f08)(0xf);
  (*DAT_001a7f00)(0x19);
  (*DAT_001a7efc)();
  *(undefined4 *)(*param_1 + 0x16c) = 0;
  iVar1 = __rf__7EHANDLE(param_1 + 0x51);
  if (*(int *)(iVar1 + 0x78) != 1) {
    iVar1 = param_1[0xf5];
    puVar2 = (undefined4 *)
             __rf__7EHANDLE(param_1 + 0x51,(float)(param_1[0x39] * 8 + 0x4b),0,0x4000040);
    (**(code **)(iVar1 + 0x1f8))(param_1,*param_1,*puVar2);
  }
  (*DAT_001a7ef8)(5,0x17,*param_1 + 8,0);
  (*DAT_001a7f00)(3);
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 8));
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_001a7f08)((int)g_sModelIndexFireball);
  (*DAT_001a7f00)(0x1e);
  (*DAT_001a7f00)(0xf);
  (*DAT_001a7f00)(3);
  (*DAT_001a7efc)();
  uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x26);
  dremove__FP11CBaseEntity(uVar3);
  dremove__FP11CBaseEntity(param_1);
  return;
}


