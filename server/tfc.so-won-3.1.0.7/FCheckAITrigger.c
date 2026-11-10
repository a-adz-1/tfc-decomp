// FCheckAITrigger__12CBaseMonster  @ 000c11f8
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
  
  if (param_1[0x19c] == 0) {
    return 0;
  }
  bVar4 = false;
  switch(param_1[0x19c]) {
  case 1:
    iVar6 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13b);
    if ((iVar6 != 0) &&
       (piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x13b), (*(byte *)(*piVar5 + 0x1a4) & 8) != 0)) {
      bVar2 = *(byte *)(param_1 + 0x13a) & 0x10;
      goto joined_r0x000c12b3;
    }
    break;
  case 2:
    bVar2 = *(byte *)((int)param_1 + 0x4e9) & 3;
    goto joined_r0x000c12b3;
  case 3:
    iVar6 = (**(code **)(param_1[0x111] + 0x8c))(param_1);
    if (iVar6 != 0) {
      fVar3 = *(float *)(*param_1 + 0x1b0) * 0.5;
      fVar1 = *(float *)(*param_1 + 0x160);
      if ((byte)(fVar3 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) != 1) goto LAB_000c139b;
    }
    break;
  case 4:
    if (*(int *)(*param_1 + 0x170) == 0) break;
    goto LAB_000c139b;
  case 7:
    if ((*(byte *)((int)param_1 + 0x4ea) & 2) != 0) {
      bVar2 = *(byte *)(param_1 + 0x186) & 2;
      goto joined_r0x000c12b3;
    }
    break;
  case 8:
    if ((*(byte *)((int)param_1 + 0x4ea) & 2) != 0) {
      bVar2 = *(byte *)(param_1 + 0x186) & 4;
      goto joined_r0x000c12b3;
    }
    break;
  case 9:
    if (((*(byte *)((int)param_1 + 0x4ea) & 2) != 0) && ((*(byte *)(param_1 + 0x186) & 1) != 0)) {
      bVar4 = true;
    }
    break;
  case 10:
    bVar2 = *(byte *)((int)param_1 + 0x4ea) & 0x20;
joined_r0x000c12b3:
    if (bVar2 == 0) break;
    goto LAB_000c139b;
  case 0xb:
    if (((((*(byte *)((int)param_1 + 0x4ea) & 0x20) != 0) && (param_1[0x159] != 2)) &&
        (param_1[0x159] != 5)) && (param_1[0x159] != 6)) goto LAB_000c139b;
  }
  if (bVar4) {
LAB_000c139b:
    (*DAT_001c1114)(2,"AI Trigger Fire Target\n");
    FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
              (param_1[0x19d] + *(int *)(gpGlobals + 0x98),param_1,param_1,3,0);
    param_1[0x19c] = 0;
    uVar7 = 1;
  }
  else {
    uVar7 = 0;
  }
  return uVar7;
}


