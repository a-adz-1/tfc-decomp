// Dispenser_Explode__12CTFDispenser  @ 00092028
void Dispenser_Explode__12CTFDispenser(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  
  (*DAT_001a7ef8)(4,0x17,*param_1 + 8,0);
  (*DAT_001a7f00)(0x6b);
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 8));
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_001a7f14)(0x43c80000);
  (*DAT_001a7f08)(param_1[0x187]);
  (*DAT_001a7f08)(10);
  (*DAT_001a7f00)(0x19);
  (*DAT_001a7efc)();
  iVar2 = __rf__7EHANDLE(param_1 + 0x51);
  if (*(int *)(iVar2 + 0x78) != 1) {
    fVar1 = (float)param_1[0x39] * 1.5 + 25.0 + (float)param_1[0x37];
    if (250.0 < fVar1) {
      fVar1 = 250.0;
    }
    iVar2 = param_1[0xf5];
    puVar3 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x51,fVar1,0,0x4000040);
    (**(code **)(iVar2 + 0x1f8))(param_1,*param_1,*puVar3);
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
  dremove__FP11CBaseEntity(param_1);
  return;
}


