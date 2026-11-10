// GetEnemy__12CBaseMonster  @ 000c21f0
bool GetEnemy__12CBaseMonster(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  if ((*(uint *)(param_1 + 0x4e8) & 0x40000a) != 0) {
    piVar1 = (int *)(**(code **)(*(int *)(param_1 + 0x444) + 0x134))(param_1);
    iVar4 = param_1 + 0x4ec;
    piVar2 = (int *)__opP11CBaseEntity__7EHANDLE(iVar4);
    if (((piVar1 != piVar2) && (piVar1 != (int *)0x0)) && (*(int *)(param_1 + 0x570) != 0)) {
      if ((*(byte *)(*(int *)(param_1 + 0x570) + 10) & 1) != 0) {
        uVar3 = __opP11CBaseEntity__7EHANDLE(iVar4,param_1 + 0x634);
        PushEnemy__12CBaseMonsterP11CBaseEntityR6Vector(param_1,uVar3);
        *(byte *)(param_1 + 0x4ea) = *(byte *)(param_1 + 0x4ea) | 1;
        __as__7EHANDLEP11CBaseEntity(iVar4,piVar1);
        piVar2 = (int *)__rf__7EHANDLE(iVar4);
        iVar4 = *piVar2;
        *(undefined4 *)(param_1 + 0x634) = *(undefined4 *)(iVar4 + 8);
        *(undefined4 *)(param_1 + 0x638) = *(undefined4 *)(iVar4 + 0xc);
        *(undefined4 *)(param_1 + 0x63c) = *(undefined4 *)(iVar4 + 0x10);
      }
      if (*(int *)(*piVar1 + 0x198) != 0) {
        iVar4 = *(int *)(*piVar1 + 0x198);
        if ((iVar4 == 0) && (iVar4 = (*DAT_001c1134)(0), iVar4 == 0)) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(iVar4 + 0x7c);
        }
        if (iVar4 == 0) {
          piVar1 = (int *)0x0;
        }
        else {
          piVar1 = (int *)(**(code **)(*(int *)(iVar4 + 0x444) + 0x50))(iVar4);
        }
        if (((piVar1 != (int *)0x0) && ((*(byte *)(*piVar1 + 0x1a4) & 0x20) != 0)) &&
           (iVar4 = (**(code **)(*(int *)(param_1 + 0x444) + 0x120))(param_1,piVar1), iVar4 != 0)) {
          PushEnemy__12CBaseMonsterP11CBaseEntityR6Vector(param_1,piVar1,param_1 + 0x634);
        }
      }
    }
  }
  iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4ec);
  if ((((iVar4 == 0) && (iVar4 = PopEnemy__12CBaseMonster(param_1), iVar4 != 0)) &&
      (*(int *)(param_1 + 0x570) != 0)) && ((*(byte *)(*(int *)(param_1 + 0x570) + 10) & 1) != 0)) {
    *(byte *)(param_1 + 0x4ea) = *(byte *)(param_1 + 0x4ea) | 1;
  }
  iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4ec);
  return iVar4 != 0;
}


