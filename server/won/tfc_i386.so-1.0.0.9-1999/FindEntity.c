// FindEntity__12CCineMonster  @ 000e71e0
undefined4 FindEntity__12CCineMonster(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  
  iVar2 = (*DAT_001754f8)(0,"targetname",param_1[0x186] + *(int *)(gpGlobals + 0x98));
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x11e,0);
  while( true ) {
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001755d8)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if (bVar1) break;
    if (iVar2 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = iVar2 + 0xdc;
    }
    if ((*(byte *)(iVar3 + 0x184) & 0x20) != 0) {
      iVar3 = iVar2;
      if ((iVar2 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(iVar3 + 0xd8);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (**(code **)(*(int *)(iVar3 + 0x3c8) + 0x4c))(iVar3);
      }
      if (iVar3 != 0) {
        iVar5 = *(int *)(iVar3 + 0x3c8);
        uVar4 = (**(code **)(param_1[0xf2] + 0x21c))(param_1,1);
        iVar5 = (**(code **)(iVar5 + 0x178))(iVar3,uVar4);
        if (iVar5 != 0) goto LAB_000e73c6;
      }
      (*DAT_001755b4)(1,"Found %s, but can\'t play!\n",param_1[0x186] + *(int *)(gpGlobals + 0x98));
    }
    iVar2 = (*DAT_001754f8)(iVar2,"targetname",param_1[0x186] + *(int *)(gpGlobals + 0x98));
  }
  piVar6 = (int *)0x0;
  do {
    do {
      piVar6 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                (piVar6,*param_1 + 8,param_1[0x189]);
      if (piVar6 == (int *)0x0) {
        __as__7EHANDLEP11CBaseEntity(param_1 + 0x11e,0);
        return 0;
      }
      iVar2 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + *(int *)*piVar6),
                     (char *)(*(int *)(gpGlobals + 0x98) + param_1[0x186]));
    } while (((iVar2 != 0) || ((*(byte *)(*piVar6 + 0x184) & 0x20) == 0)) ||
            (iVar3 = (**(code **)(piVar6[0xf2] + 0x4c))(piVar6), iVar3 == 0));
    iVar2 = *(int *)(iVar3 + 0x3c8);
    uVar4 = (**(code **)(param_1[0xf2] + 0x21c))(param_1,0);
    iVar2 = (**(code **)(iVar2 + 0x178))(iVar3,uVar4);
  } while (iVar2 == 0);
LAB_000e73c6:
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x11e,iVar3);
  return 1;
}


// FindEntity__17CScriptedSentence  @ 000e8a00
int FindEntity__17CScriptedSentence(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x470) + *(int *)(gpGlobals + 0x98);
  iVar4 = 0;
  do {
    iVar4 = (*DAT_001754f8)(iVar4,"targetname",iVar3);
    bVar1 = false;
    if (iVar4 == 0) {
LAB_000e8a44:
      bVar1 = true;
    }
    else {
      iVar3 = (*DAT_001755d8)(iVar4);
      if (iVar3 == 0) goto LAB_000e8a44;
    }
    if (bVar1) {
      iVar4 = FUN_000e8b30();
      return iVar4;
    }
    iVar3 = iVar4;
    if (iVar4 == 0) {
      iVar3 = (*DAT_001755d4)(0);
      if (iVar3 != 0) goto LAB_000e8a67;
      iVar3 = 0;
    }
    else {
LAB_000e8a67:
      iVar3 = *(int *)(iVar3 + 0xd8);
    }
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (**(code **)(*(int *)(iVar3 + 0x3c8) + 0x4c))(iVar3);
    }
    if (iVar3 != 0) {
      iVar2 = AcceptableSpeaker__17CScriptedSentenceP12CBaseMonster(param_1,iVar3);
      if (iVar2 != 0) {
        return iVar3;
      }
    }
    iVar3 = *(int *)(param_1 + 0x470) + *(int *)(gpGlobals + 0x98);
  } while( true );
}


