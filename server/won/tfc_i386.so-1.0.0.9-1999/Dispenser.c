// Dispenser_Explode__12CTFDispenser  @ 000a8970
void Dispenser_Explode__12CTFDispenser(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  
  (*DAT_00175578)(4,0x17,*param_1 + 8,0);
  (*DAT_00175580)(0x6b);
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_00175594)(0x43c80000);
  (*DAT_00175588)(param_1[0x184]);
  (*DAT_00175588)(10);
  (*DAT_00175580)(0x19);
  (*DAT_0017557c)();
  iVar2 = __rf__7EHANDLE(param_1 + 0x51);
  if (*(int *)(iVar2 + 0x7c) != 1) {
    fVar1 = (float)param_1[0x39] * 1.5 + 25.0 + (float)param_1[0x37];
    if ((byte)(250.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 250.0) << 0xe) >> 8)) == 1) {
      fVar1 = 250.0;
    }
    iVar2 = param_1[0xf2];
    puVar3 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x51,fVar1,0,0x4000040);
    (**(code **)(iVar2 + 0x1f8))(param_1,*param_1,*puVar3);
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
  dremove__FP11CBaseEntity(param_1);
  return;
}


