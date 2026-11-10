// FindEntity__12CCineMonster  @ 000dc0b4
/* WARNING: Removing unreachable block (ram,0x000dc301) */

undefined4 FindEntity__12CCineMonster(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar2 = (*DAT_001a7e78)(0,"targetname",*(int *)(param_1 + 0x624) + *(int *)(gpGlobals + 0x98));
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x484,0);
  while( true ) {
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001a7f58)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if (bVar1) break;
    iVar3 = iVar2 + 0x80;
    if (iVar2 == 0) {
      iVar3 = 0;
    }
    if ((*(byte *)(iVar3 + 0x1a4) & 0x20) != 0) {
      iVar3 = iVar2;
      if ((iVar2 == 0) && (iVar3 = (*DAT_001a7f54)(0), iVar3 == 0)) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(iVar3 + 0x7c);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (**(code **)(*(int *)(iVar3 + 0x3d4) + 0x4c))(iVar3);
      }
      if (iVar3 != 0) {
        iVar5 = *(int *)(iVar3 + 0x3d4);
        uVar4 = (**(code **)(*(int *)(param_1 + 0x3d4) + 0x21c))(param_1,1);
        iVar5 = (**(code **)(iVar5 + 0x178))(iVar3,uVar4);
        if (iVar5 != 0) {
          __as__7EHANDLEP11CBaseEntity(param_1 + 0x484,iVar3);
          return 1;
        }
      }
      (*DAT_001a7f34)(1,"Found %s, but can\'t play!\n",
                      *(int *)(param_1 + 0x624) + *(int *)(gpGlobals + 0x98));
    }
    iVar2 = (*DAT_001a7e78)(iVar2,"targetname",
                            *(int *)(param_1 + 0x624) + *(int *)(gpGlobals + 0x98));
  }
  uVar4 = FUN_000dc2d8();
  return uVar4;
}


// FindEntity__17CScriptedSentence  @ 000ddab0
int FindEntity__17CScriptedSentence(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar2 = param_1[0x11f] + *(int *)(gpGlobals + 0x98);
  iVar5 = 0;
  while( true ) {
    iVar5 = (*DAT_001a7e78)(iVar5,"targetname",iVar2);
    bVar1 = false;
    if ((iVar5 == 0) || (iVar2 = (*DAT_001a7f58)(iVar5), iVar2 == 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      piVar4 = (int *)0x0;
      do {
        do {
          piVar4 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                    (piVar4,*param_1 + 8,param_1[0x120]);
          if (piVar4 == (int *)0x0) {
            return 0;
          }
          iVar2 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + *(int *)*piVar4),
                         (char *)(*(int *)(gpGlobals + 0x98) + param_1[0x11f]));
        } while ((iVar2 != 0) || ((*(byte *)(*piVar4 + 0x1a4) & 0x20) == 0));
        iVar2 = (**(code **)(piVar4[0xf5] + 0x4c))(piVar4);
        iVar5 = AcceptableSpeaker__17CScriptedSentenceP12CBaseMonster(param_1,iVar2);
      } while (iVar5 == 0);
      return iVar2;
    }
    iVar2 = iVar5;
    if ((iVar5 == 0) && (iVar2 = (*DAT_001a7f54)(0), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x7c);
    }
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (**(code **)(*(int *)(iVar2 + 0x3d4) + 0x4c))(iVar2);
    }
    if ((iVar2 != 0) &&
       (iVar3 = AcceptableSpeaker__17CScriptedSentenceP12CBaseMonster(param_1,iVar2), iVar3 != 0))
    break;
    iVar2 = param_1[0x11f] + *(int *)(gpGlobals + 0x98);
  }
  return iVar2;
}


