// FCheckAITrigger__12CBaseMonster  @ 000c7340
/* WARNING: Type propagation algorithm not settling */

undefined4 FCheckAITrigger__12CBaseMonster(int *param_1)

{
  byte bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (param_1[0x17d] == 0) goto LAB_000c7540;
  bVar2 = false;
  switch(param_1[0x17d]) {
  case 1:
    iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11c);
    if ((iVar4 != 0) &&
       (piVar3 = (int *)__rf__7EHANDLE(param_1 + 0x11c), (*(byte *)(*piVar3 + 0x184) & 8) != 0)) {
      bVar1 = *(byte *)(param_1 + 0x11b) & 0x10;
      goto joined_r0x000c73c7;
    }
    break;
  case 2:
    bVar1 = *(byte *)((int)param_1 + 0x46d) & 3;
    goto joined_r0x000c73c7;
  case 3:
    iVar4 = (**(code **)(param_1[0xf2] + 0x88))(param_1);
    if ((iVar4 == 0) || (*(float *)(*param_1 + 400) * 0.5 < *(float *)(*param_1 + 0x140))) break;
    goto LAB_000c74fb;
  case 4:
    if (*(int *)(*param_1 + 0x150) != 0) goto LAB_000c74fb;
    break;
  case 7:
    if ((*(byte *)((int)param_1 + 0x46e) & 2) != 0) {
      bVar1 = *(byte *)(param_1 + 0x167) & 2;
      goto joined_r0x000c73c7;
    }
    break;
  case 8:
    if ((*(byte *)((int)param_1 + 0x46e) & 2) != 0) {
      bVar1 = *(byte *)(param_1 + 0x167) & 4;
      goto joined_r0x000c73c7;
    }
    break;
  case 9:
    if (((*(byte *)((int)param_1 + 0x46e) & 2) != 0) && ((*(byte *)(param_1 + 0x167) & 1) != 0)) {
      bVar2 = true;
    }
    break;
  case 10:
    bVar1 = *(byte *)((int)param_1 + 0x46e) & 0x20;
joined_r0x000c73c7:
    if (bVar1 == 0) break;
    goto LAB_000c74fb;
  case 0xb:
    if (((((*(byte *)((int)param_1 + 0x46e) & 0x20) != 0) && (param_1[0x13a] != 2)) &&
        (param_1[0x13a] != 5)) && (param_1[0x13a] != 6)) goto LAB_000c74fb;
  }
  if (bVar2) {
LAB_000c74fb:
    (*DAT_001755b4)(2,"AI Trigger Fire Target\n");
    FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
              (param_1[0x17e] + *(int *)(gpGlobals + 0x98),param_1,param_1,3,0);
    param_1[0x17d] = 0;
    uVar5 = 1;
  }
  else {
LAB_000c7540:
    uVar5 = 0;
  }
  return uVar5;
}


