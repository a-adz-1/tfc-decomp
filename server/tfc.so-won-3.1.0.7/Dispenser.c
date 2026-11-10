// Dispenser_Explode__12CTFDispenser  @ 0009c4e8
void Dispenser_Explode__12CTFDispenser(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  
  (*DAT_001c10d8)(4,0x17,*param_1 + 8,0);
  (*DAT_001c10e0)(0x6b);
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 8));
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_001c10f4)(0x43c80000);
  (*DAT_001c10e8)(param_1[0x1a3]);
  (*DAT_001c10e8)(10);
  (*DAT_001c10e0)(0x19);
  (*DAT_001c10dc)();
  iVar2 = __rf__7EHANDLE(param_1 + 0x51);
  if (*(int *)(iVar2 + 0x78) != 1) {
    fVar1 = (float)param_1[0x39] * 1.5 + 25.0 + (float)param_1[0x37];
    if (250.0 < fVar1) {
      fVar1 = 250.0;
    }
    iVar2 = param_1[0x111];
    puVar3 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x51,fVar1,0,0x4000040);
    (**(code **)(iVar2 + 0x200))(param_1,*param_1,*puVar3);
  }
  (*DAT_001c10d8)(5,0x17,*param_1 + 8,0);
  (*DAT_001c10e0)(3);
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 8));
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_001c10e8)((int)g_sModelIndexFireball);
  (*DAT_001c10e0)(0x1e);
  (*DAT_001c10e0)(0xf);
  (*DAT_001c10e0)(3);
  (*DAT_001c10dc)();
  dremove__FP11CBaseEntity(param_1);
  return;
}


