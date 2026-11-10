// FCheckAITrigger__12CBaseMonster  @ 000b5f98
/* WARNING: Type propagation algorithm not settling */

undefined4 FCheckAITrigger__12CBaseMonster(int *param_1)

{
  float fVar1;
  byte bVar2;
  float fVar3;
  bool bVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  
  if (param_1[0x180] == 0) {
    return 0;
  }
  bVar4 = false;
  switch(param_1[0x180]) {
  case 1:
    iVar6 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11f);
    if ((iVar6 != 0) &&
       (piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x11f), (*(byte *)(*piVar5 + 0x1a4) & 8) != 0)) {
      bVar2 = *(byte *)(param_1 + 0x11e) & 0x10;
      goto joined_r0x000b6053;
    }
    break;
  case 2:
    bVar2 = *(byte *)((int)param_1 + 0x479) & 3;
    goto joined_r0x000b6053;
  case 3:
    iVar6 = (**(code **)(param_1[0xf5] + 0x88))(param_1);
    if (iVar6 != 0) {
      fVar3 = *(float *)(*param_1 + 0x1b0) * 0.5;
      fVar1 = *(float *)(*param_1 + 0x160);
      if ((byte)(fVar3 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) != 1) goto LAB_000b613b;
    }
    break;
  case 4:
    if (*(int *)(*param_1 + 0x170) == 0) break;
    goto LAB_000b613b;
  case 7:
    if ((*(byte *)((int)param_1 + 0x47a) & 2) != 0) {
      bVar2 = *(byte *)(param_1 + 0x16a) & 2;
      goto joined_r0x000b6053;
    }
    break;
  case 8:
    if ((*(byte *)((int)param_1 + 0x47a) & 2) != 0) {
      bVar2 = *(byte *)(param_1 + 0x16a) & 4;
      goto joined_r0x000b6053;
    }
    break;
  case 9:
    if (((*(byte *)((int)param_1 + 0x47a) & 2) != 0) && ((*(byte *)(param_1 + 0x16a) & 1) != 0)) {
      bVar4 = true;
    }
    break;
  case 10:
    bVar2 = *(byte *)((int)param_1 + 0x47a) & 0x20;
joined_r0x000b6053:
    if (bVar2 == 0) break;
    goto LAB_000b613b;
  case 0xb:
    if (((((*(byte *)((int)param_1 + 0x47a) & 0x20) != 0) && (param_1[0x13d] != 2)) &&
        (param_1[0x13d] != 5)) && (param_1[0x13d] != 6)) goto LAB_000b613b;
  }
  if (bVar4) {
LAB_000b613b:
    (*DAT_001a7f34)(2,"AI Trigger Fire Target\n");
    FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
              (param_1[0x181] + *(int *)(gpGlobals + 0x98),param_1,param_1,3,0);
    param_1[0x180] = 0;
    uVar7 = 1;
  }
  else {
    uVar7 = 0;
  }
  return uVar7;
}


