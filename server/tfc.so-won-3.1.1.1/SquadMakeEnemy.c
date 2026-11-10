// SquadMakeEnemy__13CSquadMonsterP11CBaseEntity  @ 000f4678
void SquadMakeEnemy__13CSquadMonsterP11CBaseEntity(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int local_c;
  int local_8;
  
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x69c);
  if (iVar2 != 0) {
    if (param_2 == (int *)0x0) {
      (*DAT_0019f794)(1,"ERROR: SquadMakeEnemy() - pEnemy is NULL!\n");
    }
    else {
      iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x69c);
      local_8 = param_1;
      if (iVar2 != 0) {
        local_8 = iVar2;
      }
      local_c = 0;
      do {
        iVar2 = local_8;
        if (local_c < 4) {
          iVar2 = __opP11CBaseEntity__7EHANDLE(local_8 + 0x6a4 + local_c * 8);
        }
        if (iVar2 != 0) {
          iVar1 = iVar2 + 0x4fc;
          piVar3 = (int *)__opP11CBaseEntity__7EHANDLE(iVar1);
          if ((piVar3 != param_2) && ((*(byte *)(iVar2 + 0x4f8) & 0x10) == 0)) {
            iVar4 = __opP11CBaseEntity__7EHANDLE(iVar1);
            if (iVar4 != 0) {
              uVar5 = __opP11CBaseEntity__7EHANDLE(iVar1,iVar2 + 0x644);
              PushEnemy__12CBaseMonsterP11CBaseEntityR6Vector(iVar2,uVar5);
            }
            __as__7EHANDLEP11CBaseEntity(iVar1,param_2);
            iVar1 = *param_2;
            *(undefined4 *)(iVar2 + 0x644) = *(undefined4 *)(iVar1 + 8);
            *(undefined4 *)(iVar2 + 0x648) = *(undefined4 *)(iVar1 + 0xc);
            *(undefined4 *)(iVar2 + 0x64c) = *(undefined4 *)(iVar1 + 0x10);
            *(byte *)(iVar2 + 0x4fa) = *(byte *)(iVar2 + 0x4fa) | 1;
          }
        }
        local_c = local_c + 1;
      } while (local_c < 5);
    }
  }
  return;
}


