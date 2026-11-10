// GetEnemy__12CBaseMonster  @ 000c8130
bool GetEnemy__12CBaseMonster(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  if ((*(uint *)(param_1 + 0x46c) & 0x40000a) != 0) {
    piVar1 = (int *)(**(code **)(*(int *)(param_1 + 0x3c8) + 300))(param_1);
    iVar4 = param_1 + 0x470;
    piVar2 = (int *)__opP11CBaseEntity__7EHANDLE(iVar4);
    if (((piVar1 != piVar2) && (piVar1 != (int *)0x0)) && (*(int *)(param_1 + 0x4f4) != 0)) {
      if ((*(byte *)(*(int *)(param_1 + 0x4f4) + 10) & 1) != 0) {
        uVar3 = __opP11CBaseEntity__7EHANDLE(iVar4,param_1 + 0x5b8);
        PushEnemy__12CBaseMonsterP11CBaseEntityR6Vector(param_1,uVar3);
        *(byte *)(param_1 + 0x46e) = *(byte *)(param_1 + 0x46e) | 1;
        __as__7EHANDLEP11CBaseEntity(iVar4,piVar1);
        piVar2 = (int *)__rf__7EHANDLE(iVar4);
        iVar4 = *piVar2;
        *(undefined4 *)(param_1 + 0x5b8) = *(undefined4 *)(iVar4 + 8);
        *(undefined4 *)(param_1 + 0x5bc) = *(undefined4 *)(iVar4 + 0xc);
        *(undefined4 *)(param_1 + 0x5c0) = *(undefined4 *)(iVar4 + 0x10);
      }
      if (*(int *)(*piVar1 + 0x178) != 0) {
        iVar4 = *(int *)(*piVar1 + 0x178);
        if ((iVar4 == 0) && (iVar4 = (*DAT_001755d4)(0), iVar4 == 0)) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(iVar4 + 0xd8);
        }
        if (iVar4 == 0) {
          piVar1 = (int *)0x0;
        }
        else {
          piVar1 = (int *)(**(code **)(*(int *)(iVar4 + 0x3c8) + 0x4c))(iVar4);
        }
        if (((piVar1 != (int *)0x0) && ((*(byte *)(*piVar1 + 0x184) & 0x20) != 0)) &&
           (iVar4 = (**(code **)(*(int *)(param_1 + 0x3c8) + 0x118))(param_1,piVar1), iVar4 != 0)) {
          PushEnemy__12CBaseMonsterP11CBaseEntityR6Vector(param_1,piVar1,param_1 + 0x5b8);
        }
      }
    }
  }
  iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x470);
  if ((((iVar4 == 0) && (iVar4 = PopEnemy__12CBaseMonster(param_1), iVar4 != 0)) &&
      (*(int *)(param_1 + 0x4f4) != 0)) && ((*(byte *)(*(int *)(param_1 + 0x4f4) + 10) & 1) != 0)) {
    *(byte *)(param_1 + 0x46e) = *(byte *)(param_1 + 0x46e) | 1;
  }
  iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x470);
  return iVar4 != 0;
}


