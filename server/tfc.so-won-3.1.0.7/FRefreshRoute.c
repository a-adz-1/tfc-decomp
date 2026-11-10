// FRefreshRoute__12CBaseMonster  @ 000ba78c
undefined4 FRefreshRoute__12CBaseMonster(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *local_18;
  undefined4 *local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  RouteNew__12CBaseMonster(param_1);
  uVar6 = 0;
  iVar2 = *(int *)(param_1 + 0x5f8);
  if (iVar2 == 0x10) {
    piVar3 = *(int **)(param_1 + 4);
    local_10 = 0;
    if (piVar3 != (int *)0x0) {
      local_14 = (undefined4 *)(param_1 + 0x580);
      local_18 = (undefined4 *)(param_1 + 0x57c);
      puVar4 = (undefined4 *)(param_1 + 0x578);
      iVar2 = 0;
      do {
        iVar5 = iVar2;
        if (7 < local_10) goto LAB_000ba89a;
        *(undefined4 *)(iVar5 + param_1 + 0x584) = 0x10;
        iVar2 = *piVar3;
        *puVar4 = *(undefined4 *)(iVar2 + 8);
        *local_18 = *(undefined4 *)(iVar2 + 0xc);
        *local_14 = *(undefined4 *)(iVar2 + 0x10);
        piVar3 = (int *)(**(code **)(piVar3[0x111] + 0xac))(piVar3);
        local_10 = local_10 + 1;
        puVar4 = puVar4 + 4;
        local_18 = local_18 + 4;
        local_14 = local_14 + 4;
        iVar2 = iVar5 + 0x10;
      } while (piVar3 != (int *)0x0);
      pbVar1 = (byte *)(iVar5 + param_1 + 0x584);
      *pbVar1 = *pbVar1 | 0x80;
    }
LAB_000ba89a:
    uVar6 = 1;
  }
  else if (iVar2 < 0x11) {
    if (iVar2 == 1) {
      iVar5 = param_1 + 0x4f4;
      iVar2 = __opP11CBaseEntity__7EHANDLE(iVar5);
      if (iVar2 == 0) {
        return 0;
      }
      uVar6 = __opP11CBaseEntity__7EHANDLE(iVar5);
      uVar7 = 1;
      piVar3 = (int *)__rf__7EHANDLE(iVar5,1,uVar6);
      iVar2 = *piVar3 + 8;
    }
    else {
      if (iVar2 != 2) {
        return 0;
      }
      uVar6 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4ec);
      uVar7 = 2;
      iVar2 = param_1 + 0x634;
    }
    uVar6 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity(param_1,iVar2,uVar7,uVar6);
  }
  else if (iVar2 == 0x20) {
    local_c = *(undefined4 *)(param_1 + 0x604);
    local_8 = *(undefined4 *)(param_1 + 0x608);
    local_4 = *(undefined4 *)(param_1 + 0x60c);
    uVar6 = FGetNodeRoute__12CBaseMonsterG6Vector(param_1,&local_c);
  }
  else if (iVar2 == 0x40) {
    uVar6 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity(param_1,param_1 + 0x604,0x40,0);
  }
  return uVar6;
}


