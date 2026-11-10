// FCheckAITrigger__12CBaseMonster  @ 000c047c
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
  
  if (param_1[0x1a0] == 0) {
    return 0;
  }
  bVar4 = false;
  switch(param_1[0x1a0]) {
  case 1:
    iVar6 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13f);
    if ((iVar6 != 0) &&
       (piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x13f), (*(byte *)(*piVar5 + 0x1a4) & 8) != 0)) {
      bVar2 = *(byte *)(param_1 + 0x13e) & 0x10;
      goto joined_r0x000c053f;
    }
    break;
  case 2:
    bVar2 = *(byte *)((int)param_1 + 0x4f9) & 3;
    goto joined_r0x000c053f;
  case 3:
    iVar6 = (**(code **)(param_1[0x115] + 0x8c))(param_1);
    if (iVar6 != 0) {
      fVar3 = *(float *)(*param_1 + 0x1b0) * 0.5;
      fVar1 = *(float *)(*param_1 + 0x160);
      if ((byte)(fVar3 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) != 1) goto LAB_000c0623;
    }
    break;
  case 4:
    if (*(int *)(*param_1 + 0x170) == 0) break;
    goto LAB_000c0623;
  case 7:
    if ((*(byte *)((int)param_1 + 0x4fa) & 2) != 0) {
      bVar2 = *(byte *)(param_1 + 0x18a) & 2;
      goto joined_r0x000c053f;
    }
    break;
  case 8:
    if ((*(byte *)((int)param_1 + 0x4fa) & 2) != 0) {
      bVar2 = *(byte *)(param_1 + 0x18a) & 4;
      goto joined_r0x000c053f;
    }
    break;
  case 9:
    if (((*(byte *)((int)param_1 + 0x4fa) & 2) != 0) && ((*(byte *)(param_1 + 0x18a) & 1) != 0)) {
      bVar4 = true;
    }
    break;
  case 10:
    bVar2 = *(byte *)((int)param_1 + 0x4fa) & 0x20;
joined_r0x000c053f:
    if (bVar2 == 0) break;
    goto LAB_000c0623;
  case 0xb:
    if (((((*(byte *)((int)param_1 + 0x4fa) & 0x20) != 0) && (iVar6 = param_1[0x15d], iVar6 != 2))
        && (iVar6 != 5)) && (iVar6 != 6)) goto LAB_000c0623;
  }
  if (bVar4) {
LAB_000c0623:
    (*DAT_0019f794)(2,"AI Trigger Fire Target\n");
    FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
              (param_1[0x1a1] + *(int *)(gpGlobals + 0x98),param_1,param_1,3,0);
    param_1[0x1a0] = 0;
    uVar7 = 1;
  }
  else {
    uVar7 = 0;
  }
  return uVar7;
}


