// AdvanceRoute__12CBaseMonsterf  @ 000bc944
void AdvanceRoute__12CBaseMonsterf(int param_1,float param_2)

{
  int iVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  longdouble lVar6;
  int iStack_8;
  
  iVar3 = *(int *)(param_1 + 0x60c);
  if (iVar3 == 7) {
    iVar3 = FRefreshRoute__12CBaseMonster(param_1);
    if (iVar3 == 0) {
      (*DAT_0019f794)(2,"Can\'t Refresh Route!!\n");
    }
  }
  else {
    iVar1 = param_1 + 0x594;
    if (*(char *)(iVar3 * 0x10 + iVar1) < '\0') {
      fVar2 = *(float *)(param_1 + 0x464) * 0.2;
      if (0x3f < (byte)((fVar2 < param_2 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(param_2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == param_2) << 0xe) >> 8)) - 1)) {
        MovementComplete__12CBaseMonster(param_1);
      }
    }
    else {
      if ((*(uint *)(iVar3 * 0x10 + iVar1) & 0xfffffe7f) == 0x10) {
        uVar4 = (**(code **)(*(int *)(*(int *)(param_1 + 4) + 0x454) + 0xac))(*(int *)(param_1 + 4))
        ;
        *(undefined4 *)(param_1 + 4) = uVar4;
        iVar3 = *(int *)(param_1 + 0x60c);
      }
      if (((*(byte *)(iVar3 * 0x10 + iVar1) & 0x20) != 0) &&
         ((*(byte *)((iVar3 + 1) * 0x10 + iVar1) & 0x20) != 0)) {
        uVar4 = FindNearestNode__6CGraphRC6VectorP11CBaseEntity
                          (&WorldGraph,param_1 + 0x588 + iVar3 * 0x10,param_1);
        uVar5 = FindNearestNode__6CGraphRC6VectorP11CBaseEntity
                          (&WorldGraph,param_1 + 0x598 + *(int *)(param_1 + 0x60c) * 0x10,param_1);
        HashSearch__6CGraphiiRi(&WorldGraph,uVar4,uVar5,&iStack_8);
        if (-1 < iStack_8) {
          if (*(int *)(DAT_0019fb30 + 8 + iStack_8 * 0x18) != 0) {
            iVar3 = HandleLinkEnt__6CGraphiP9entvars_siQ26CGraph9NODEQUERY
                              (&WorldGraph,uVar4,*(undefined4 *)(DAT_0019fb30 + 8 + iStack_8 * 0x18)
                               ,*(undefined4 *)(param_1 + 0x654),0);
            if ((iVar3 != 0) && (iVar3 = *(int *)(DAT_0019fb30 + 8 + iStack_8 * 0x18), iVar3 != 0))
            {
              lVar6 = (longdouble)OpenDoorAndWait__12CBaseMonsterP9entvars_s(param_1,iVar3);
              *(float *)(param_1 + 0x564) = (float)lVar6;
            }
          }
        }
      }
      *(int *)(param_1 + 0x60c) = *(int *)(param_1 + 0x60c) + 1;
    }
  }
  return;
}


