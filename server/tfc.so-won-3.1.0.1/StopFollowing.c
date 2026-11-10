// StopFollowing__12CBaseMonsteri  @ 000b743c
void StopFollowing__12CBaseMonsteri(void)

{
  return;
}


// StopFollowing__12CTalkMonsteri  @ 000e9d78
void StopFollowing__12CTalkMonsteri(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  longdouble lVar4;
  
  bVar3 = false;
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x484);
  if (iVar1 != 0) {
    piVar2 = (int *)__rf__7EHANDLE(param_1 + 0x484);
    bVar3 = (*(byte *)(*piVar2 + 0x1a4) & 8) != 0;
  }
  if (bVar3) {
    if (((*(byte *)(param_1 + 0x5bc) ^ 1) & 1) != 0) {
      iVar1 = *(int *)(param_1 + 0x3d4);
      lVar4 = (longdouble)(*DAT_001a7fac)(0x40333333,0x404ccccd,0x3f800000,0x40000000);
      (**(code **)(iVar1 + 0x180))(param_1,*(undefined4 *)(param_1 + 0x63c),(float)lVar4);
      *(undefined4 *)(param_1 + 0x684) = *(undefined4 *)(param_1 + 0x484);
      *(undefined4 *)(param_1 + 0x688) = *(undefined4 *)(param_1 + 0x488);
    }
    if (*(int *)(param_1 + 0x588) == 1) {
      RouteClear__12CBaseMonster(param_1);
    }
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x484,0);
    if (param_2 != 0) {
      ClearSchedule__12CBaseMonster(param_1);
    }
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x47c);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x4f8) = 2;
    }
  }
  return;
}


