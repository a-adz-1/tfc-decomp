// AdvanceRoute__12CBaseMonsterf  @ 000b0ff0
void AdvanceRoute__12CBaseMonsterf(int param_1,float param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  longdouble lVar5;
  int local_4;
  
  if (*(int *)(param_1 + 0x58c) == 7) {
    iVar2 = FRefreshRoute__12CBaseMonster(param_1);
    if (iVar2 == 0) {
      (*DAT_001a7f34)(2,"Can\'t Refresh Route!!\n");
    }
  }
  else {
    iVar2 = *(int *)(param_1 + 0x58c) * 0x10;
    if (*(char *)(iVar2 + param_1 + 0x514) < '\0') {
      fVar1 = *(float *)(param_1 + 0x3e4) * 0.2;
      if (0x3f < (byte)((fVar1 < param_2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(param_2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == param_2) << 0xe) >> 8)) - 1)) {
        MovementComplete__12CBaseMonster(param_1);
      }
    }
    else {
      if ((*(uint *)(iVar2 + param_1 + 0x514) & 0xfffffe7f) == 0x10) {
        uVar3 = (**(code **)(*(int *)(*(int *)(param_1 + 4) + 0x3d4) + 0xa4))(*(int *)(param_1 + 4))
        ;
        *(undefined4 *)(param_1 + 4) = uVar3;
      }
      iVar2 = *(int *)(param_1 + 0x58c) * 0x10;
      if (((*(byte *)(iVar2 + param_1 + 0x514) & 0x20) != 0) &&
         ((*(byte *)((*(int *)(param_1 + 0x58c) + 1) * 0x10 + param_1 + 0x514) & 0x20) != 0)) {
        uVar3 = FindNearestNode__6CGraphRC6VectorP11CBaseEntity
                          (&WorldGraph,param_1 + 0x508 + iVar2,param_1);
        uVar4 = FindNearestNode__6CGraphRC6VectorP11CBaseEntity
                          (&WorldGraph,param_1 + 0x518 + *(int *)(param_1 + 0x58c) * 0x10,param_1);
        HashSearch__6CGraphiiRi(&WorldGraph,uVar3,uVar4,&local_4);
        if (-1 < local_4) {
          if (*(int *)(DAT_001a82b0 + 8 + local_4 * 0x18) != 0) {
            iVar2 = HandleLinkEnt__6CGraphiP9entvars_siQ26CGraph9NODEQUERY
                              (&WorldGraph,uVar3,*(undefined4 *)(DAT_001a82b0 + 8 + local_4 * 0x18),
                               *(undefined4 *)(param_1 + 0x5d4),0);
            if ((iVar2 != 0) && (iVar2 = *(int *)(DAT_001a82b0 + 8 + local_4 * 0x18), iVar2 != 0)) {
              lVar5 = (longdouble)OpenDoorAndWait__12CBaseMonsterP9entvars_s(param_1,iVar2);
              *(float *)(param_1 + 0x4e4) = (float)lVar5;
            }
          }
        }
      }
      *(int *)(param_1 + 0x58c) = *(int *)(param_1 + 0x58c) + 1;
    }
  }
  return;
}


