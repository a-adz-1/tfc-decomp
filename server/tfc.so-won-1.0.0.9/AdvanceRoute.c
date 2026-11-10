// AdvanceRoute__12CBaseMonsterf  @ 000c3000
void AdvanceRoute__12CBaseMonsterf(int param_1,float param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longdouble lVar4;
  int local_8;
  
  if (*(int *)(param_1 + 0x580) == 7) {
    iVar1 = FRefreshRoute__12CBaseMonster(param_1);
    if (iVar1 == 0) {
      (*DAT_001755b4)(2,"Can\'t Refresh Route!!\n");
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0x580) * 0x10;
    if (*(char *)(iVar1 + param_1 + 0x508) < '\0') {
      if (param_2 < *(float *)(param_1 + 0x3d8) * 0.2) {
        MovementComplete__12CBaseMonster(param_1);
      }
    }
    else {
      if ((*(uint *)(iVar1 + param_1 + 0x508) & 0xfffffe7f) == 0x10) {
        uVar2 = (**(code **)(*(int *)(*(int *)(param_1 + 4) + 0x3c8) + 0xa4))(*(int *)(param_1 + 4))
        ;
        *(undefined4 *)(param_1 + 4) = uVar2;
      }
      iVar1 = *(int *)(param_1 + 0x580) * 0x10;
      if (((*(byte *)(iVar1 + param_1 + 0x508) & 0x20) != 0) &&
         ((*(byte *)((*(int *)(param_1 + 0x580) + 1) * 0x10 + param_1 + 0x508) & 0x20) != 0)) {
        uVar2 = FindNearestNode__6CGraphRC6VectorP11CBaseEntity
                          (&WorldGraph,param_1 + 0x4fc + iVar1,param_1);
        uVar3 = FindNearestNode__6CGraphRC6VectorP11CBaseEntity
                          (&WorldGraph,param_1 + 0x50c + *(int *)(param_1 + 0x580) * 0x10,param_1);
        HashSearch__6CGraphiiRi(&WorldGraph,uVar2,uVar3,&local_8);
        if ((-1 < local_8) && (*(int *)(DAT_001758d0 + 8 + local_8 * 0x18) != 0)) {
          iVar1 = HandleLinkEnt__6CGraphiP9entvars_tiQ26CGraph9NODEQUERY
                            (&WorldGraph,uVar2,*(undefined4 *)(DAT_001758d0 + 8 + local_8 * 0x18),
                             *(undefined4 *)(param_1 + 0x5c8),0);
          if ((iVar1 != 0) && (iVar1 = *(int *)(DAT_001758d0 + 8 + local_8 * 0x18), iVar1 != 0)) {
            lVar4 = (longdouble)OpenDoorAndWait__12CBaseMonsterP9entvars_t(param_1,iVar1);
            *(float *)(param_1 + 0x4d8) = (float)lVar4;
          }
        }
      }
      *(int *)(param_1 + 0x580) = *(int *)(param_1 + 0x580) + 1;
    }
  }
  return;
}


