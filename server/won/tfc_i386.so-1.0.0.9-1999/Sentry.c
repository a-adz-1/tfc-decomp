// Sentry_Explode__12CTFSentrygun  @ 000ea580
void Sentry_Explode__12CTFSentrygun(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  (*DAT_00175578)(4,0x17,*param_1 + 8,0);
  (*DAT_00175580)(0x6b);
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_00175594)(0x43c80000);
  (*DAT_00175588)(param_1[0x185]);
  (*DAT_00175588)(0xf);
  (*DAT_00175580)(0x19);
  (*DAT_0017557c)();
  *(undefined4 *)(*param_1 + 0x14c) = 0;
  iVar1 = __rf__7EHANDLE(param_1 + 0x51);
  if (*(int *)(iVar1 + 0x7c) != 1) {
    iVar1 = param_1[0xf2];
    puVar2 = (undefined4 *)
             __rf__7EHANDLE(param_1 + 0x51,(float)(param_1[0x39] * 8 + 0x4b),0,0x4000040);
    (**(code **)(iVar1 + 0x1f8))(param_1,*param_1,*puVar2);
  }
  (*DAT_00175578)(5,0x17,*param_1 + 8,0);
  (*DAT_00175580)(3);
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_00175588)((int)g_sModelIndexFireball);
  (*DAT_00175580)(0x1e);
  (*DAT_00175580)(0xf);
  (*DAT_00175580)(3);
  (*DAT_0017557c)();
  uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x26);
  dremove__FP11CBaseEntity(uVar3);
  dremove__FP11CBaseEntity(param_1);
  return;
}


