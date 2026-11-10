// SquadMakeEnemy__13CSquadMonsterP11CBaseEntity  @ 000ef650
void SquadMakeEnemy__13CSquadMonsterP11CBaseEntity(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iStack_8;
  
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x610);
  if (iVar2 != 0) {
    if (param_2 == (int *)0x0) {
      (*DAT_001755b4)(1,"ERROR: SquadMakeEnemy() - pEnemy is NULL!\n");
    }
    else {
      iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x610);
      iStack_8 = param_1;
      if (iVar2 != 0) {
        iStack_8 = iVar2;
      }
      iVar2 = 0;
      do {
        iVar3 = iStack_8;
        if (iVar2 < 4) {
          iVar3 = __opP11CBaseEntity__7EHANDLE(iStack_8 + 0x618 + iVar2 * 8);
        }
        if (iVar3 != 0) {
          iVar1 = iVar3 + 0x470;
          piVar4 = (int *)__opP11CBaseEntity__7EHANDLE(iVar1);
          if ((piVar4 != param_2) && ((*(byte *)(iVar3 + 0x46c) & 0x10) == 0)) {
            iVar5 = __opP11CBaseEntity__7EHANDLE(iVar1);
            if (iVar5 != 0) {
              uVar6 = __opP11CBaseEntity__7EHANDLE(iVar1,iVar3 + 0x5b8);
              PushEnemy__12CBaseMonsterP11CBaseEntityR6Vector(iVar3,uVar6);
            }
            __as__7EHANDLEP11CBaseEntity(iVar3 + 0x470,param_2);
            iVar1 = *param_2;
            *(undefined4 *)(iVar3 + 0x5b8) = *(undefined4 *)(iVar1 + 8);
            *(undefined4 *)(iVar3 + 0x5bc) = *(undefined4 *)(iVar1 + 0xc);
            *(undefined4 *)(iVar3 + 0x5c0) = *(undefined4 *)(iVar1 + 0x10);
            *(byte *)(iVar3 + 0x46e) = *(byte *)(iVar3 + 0x46e) | 1;
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 5);
    }
  }
  return;
}


