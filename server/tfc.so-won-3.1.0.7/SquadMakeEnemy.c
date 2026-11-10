// SquadMakeEnemy__13CSquadMonsterP11CBaseEntity  @ 000f2730
void SquadMakeEnemy__13CSquadMonsterP11CBaseEntity(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int local_8;
  int local_4;
  
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x68c);
  if (iVar2 != 0) {
    if (param_2 == (int *)0x0) {
      (*DAT_001c1114)(1,"ERROR: SquadMakeEnemy() - pEnemy is NULL!\n");
    }
    else {
      iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x68c);
      local_4 = param_1;
      if (iVar2 != 0) {
        local_4 = iVar2;
      }
      iVar2 = 0;
      local_8 = local_4 + 0x694;
      do {
        iVar3 = local_4;
        if (iVar2 < 4) {
          iVar3 = __opP11CBaseEntity__7EHANDLE(local_8);
        }
        if (iVar3 != 0) {
          iVar1 = iVar3 + 0x4ec;
          piVar4 = (int *)__opP11CBaseEntity__7EHANDLE(iVar1);
          if ((piVar4 != param_2) && ((*(byte *)(iVar3 + 0x4e8) & 0x10) == 0)) {
            iVar5 = __opP11CBaseEntity__7EHANDLE(iVar1);
            if (iVar5 != 0) {
              uVar6 = __opP11CBaseEntity__7EHANDLE(iVar1,iVar3 + 0x634);
              PushEnemy__12CBaseMonsterP11CBaseEntityR6Vector(iVar3,uVar6);
            }
            __as__7EHANDLEP11CBaseEntity(iVar3 + 0x4ec,param_2);
            iVar1 = *param_2;
            *(undefined4 *)(iVar3 + 0x634) = *(undefined4 *)(iVar1 + 8);
            *(undefined4 *)(iVar3 + 0x638) = *(undefined4 *)(iVar1 + 0xc);
            *(undefined4 *)(iVar3 + 0x63c) = *(undefined4 *)(iVar1 + 0x10);
            *(byte *)(iVar3 + 0x4ea) = *(byte *)(iVar3 + 0x4ea) | 1;
          }
        }
        local_8 = local_8 + 8;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 5);
    }
  }
  return;
}


