// StopFollowing__12CBaseMonsteri  @ 000c85a0
void StopFollowing__12CBaseMonsteri(void)

{
  return;
}


// StopFollowing__12CTalkMonsteri  @ 000f2fe0
void StopFollowing__12CTalkMonsteri(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  longdouble lVar4;
  
  bVar3 = false;
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x478);
  if (iVar1 != 0) {
    piVar2 = (int *)__rf__7EHANDLE(param_1 + 0x478);
    bVar3 = (*(byte *)(*piVar2 + 0x184) & 8) != 0;
  }
  if (bVar3) {
    if (((*(byte *)(param_1 + 0x5b0) ^ 1) & 1) != 0) {
      iVar1 = *(int *)(param_1 + 0x3c8);
      lVar4 = (longdouble)(*DAT_0017562c)(0x40333333,0x404ccccd,0x3f800000,0x40000000);
      (**(code **)(iVar1 + 0x180))(param_1,*(undefined4 *)(param_1 + 0x630),(float)lVar4);
      *(undefined4 *)(param_1 + 0x678) = *(undefined4 *)(param_1 + 0x478);
      *(undefined4 *)(param_1 + 0x67c) = *(undefined4 *)(param_1 + 0x47c);
    }
    if (*(int *)(param_1 + 0x57c) == 1) {
      RouteClear__12CBaseMonster(param_1);
    }
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x478,0);
    if (param_2 != 0) {
      ClearSchedule__12CBaseMonster(param_1);
    }
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x470);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x4ec) = 2;
    }
  }
  return;
}


