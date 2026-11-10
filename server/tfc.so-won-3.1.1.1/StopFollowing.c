// StopFollowing__12CBaseMonsteri  @ 000c2f60
void StopFollowing__12CBaseMonsteri(void)

{
  return;
}


// StopFollowing__12CTalkMonsteri  @ 000f8784
void StopFollowing__12CTalkMonsteri(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  bool bVar4;
  longdouble lVar5;
  
  bVar4 = false;
  iVar3 = param_1 + 0x504;
  iVar1 = __opP11CBaseEntity__7EHANDLE(iVar3);
  if (iVar1 != 0) {
    piVar2 = (int *)__rf__7EHANDLE(iVar3);
    bVar4 = (*(byte *)(*piVar2 + 0x1a4) & 8) != 0;
  }
  if (bVar4) {
    if (((*(byte *)(param_1 + 0x63c) ^ 1) & 1) != 0) {
      iVar1 = *(int *)(param_1 + 0x454);
      lVar5 = (longdouble)(*DAT_0019f80c)(0x40333333,0x404ccccd,0x3f800000,0x40000000);
      (**(code **)(iVar1 + 0x188))(param_1,*(undefined4 *)(param_1 + 0x6bc),(float)lVar5);
      *(undefined4 *)(param_1 + 0x704) = *(undefined4 *)(param_1 + 0x504);
      *(undefined4 *)(param_1 + 0x708) = *(undefined4 *)(param_1 + 0x508);
    }
    if (*(int *)(param_1 + 0x608) == 1) {
      RouteClear__12CBaseMonster(param_1);
    }
    __as__7EHANDLEP11CBaseEntity(iVar3,0);
    if (param_2 != 0) {
      ClearSchedule__12CBaseMonster(param_1);
    }
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4fc);
    if (iVar3 != 0) {
      *(undefined4 *)(param_1 + 0x578) = 2;
    }
  }
  return;
}


