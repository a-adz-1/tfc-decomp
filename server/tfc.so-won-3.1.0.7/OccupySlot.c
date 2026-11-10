// OccupySlot__13CSquadMonsteri  @ 000f2234
undefined4 OccupySlot__13CSquadMonsteri(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  byte bVar5;
  int iStack_4;
  
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x68c);
  if (iVar2 == 0) {
    uVar3 = 1;
  }
  else {
    iVar2 = SquadEnemySplit__13CSquadMonster(param_1);
    if (iVar2 == 0) {
      iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x68c);
      iStack_4 = param_1;
      if (iVar2 != 0) {
        iStack_4 = iVar2;
      }
      if (param_2 != *(uint *)(iStack_4 + 0x6b4)) {
        uVar1 = *(uint *)(iStack_4 + 0x6b4);
        uVar4 = 1;
        if (((((param_2 & 1) != 0) && ((uVar1 & 1) == 0)) ||
            ((uVar4 = 2, (param_2 & 2) != 0 && ((uVar1 & 2) == 0)))) ||
           ((uVar4 = 4, (param_2 & 4) != 0 && ((uVar1 & 4) == 0)))) {
LAB_000f22cc:
          *(uint *)(iStack_4 + 0x6b4) = *(uint *)(iStack_4 + 0x6b4) | uVar4;
          *(uint *)(param_1 + 0x6c0) = uVar4;
          return 1;
        }
        iVar2 = 3;
        do {
          bVar5 = (byte)iVar2;
          uVar4 = 1 << (bVar5 & 0x1f);
          if (((((uVar4 & param_2) != 0) && ((uVar4 & uVar1) == 0)) ||
              ((uVar4 = 1 << (bVar5 + 1 & 0x1f), (uVar4 & param_2) != 0 && ((uVar4 & uVar1) == 0))))
             || (((uVar4 = 1 << (bVar5 + 2 & 0x1f), (uVar4 & param_2) != 0 && ((uVar4 & uVar1) == 0)
                  ) || ((uVar4 = 1 << (bVar5 + 3 & 0x1f), (uVar4 & param_2) != 0 &&
                        ((uVar4 & uVar1) == 0)))))) goto LAB_000f22cc;
          iVar2 = iVar2 + 4;
        } while (iVar2 < 0xb);
      }
      uVar3 = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x6c0) = 0x400;
      uVar3 = 1;
    }
  }
  return uVar3;
}


