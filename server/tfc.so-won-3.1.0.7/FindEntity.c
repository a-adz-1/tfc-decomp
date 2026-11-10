// FindEntity__12CCineMonster  @ 000e8150
undefined4 FindEntity__12CCineMonster(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  
  iVar2 = (*DAT_001c1058)(0,"targetname",param_1[0x1a5] + *(int *)(gpGlobals + 0x98));
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x13d,0);
  while( true ) {
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001c1138)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if (bVar1) break;
    iVar3 = iVar2 + 0x80;
    if (iVar2 == 0) {
      iVar3 = 0;
    }
    if ((*(byte *)(iVar3 + 0x1a4) & 0x20) != 0) {
      iVar3 = iVar2;
      if ((iVar2 == 0) && (iVar3 = (*DAT_001c1134)(0), iVar3 == 0)) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(iVar3 + 0x7c);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (**(code **)(*(int *)(iVar3 + 0x444) + 0x50))(iVar3);
      }
      if (iVar3 != 0) {
        iVar5 = *(int *)(iVar3 + 0x444);
        uVar4 = (**(code **)(param_1[0x111] + 0x224))(param_1,1);
        iVar5 = (**(code **)(iVar5 + 0x180))(iVar3,uVar4);
        if (iVar5 != 0) goto LAB_000e835d;
      }
      (*DAT_001c1114)(1,"Found %s, but can\'t play!\n",param_1[0x1a5] + *(int *)(gpGlobals + 0x98));
    }
    iVar2 = (*DAT_001c1058)(iVar2,"targetname",param_1[0x1a5] + *(int *)(gpGlobals + 0x98));
  }
  piVar6 = (int *)0x0;
  do {
    do {
      piVar6 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                (piVar6,*param_1 + 8,param_1[0x1a8]);
      if (piVar6 == (int *)0x0) {
        __as__7EHANDLEP11CBaseEntity(param_1 + 0x13d,0);
        return 0;
      }
      iVar2 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + *(int *)*piVar6),
                     (char *)(*(int *)(gpGlobals + 0x98) + param_1[0x1a5]));
    } while (((iVar2 != 0) || ((*(byte *)(*piVar6 + 0x1a4) & 0x20) == 0)) ||
            (iVar3 = (**(code **)(piVar6[0x111] + 0x50))(piVar6), iVar3 == 0));
    iVar2 = *(int *)(iVar3 + 0x444);
    uVar4 = (**(code **)(param_1[0x111] + 0x224))(param_1,0);
    iVar2 = (**(code **)(iVar2 + 0x180))(iVar3,uVar4);
  } while (iVar2 == 0);
LAB_000e835d:
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x13d,iVar3);
  return 1;
}


// FindEntity__17CScriptedSentence  @ 000e9b4c
int FindEntity__17CScriptedSentence(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar2 = param_1[0x13b] + *(int *)(gpGlobals + 0x98);
  iVar5 = 0;
  while( true ) {
    iVar5 = (*DAT_001c1058)(iVar5,"targetname",iVar2);
    bVar1 = false;
    if ((iVar5 == 0) || (iVar2 = (*DAT_001c1138)(iVar5), iVar2 == 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      piVar4 = (int *)0x0;
      do {
        do {
          piVar4 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                    (piVar4,*param_1 + 8,param_1[0x13c]);
          if (piVar4 == (int *)0x0) {
            return 0;
          }
          iVar2 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + *(int *)*piVar4),
                         (char *)(*(int *)(gpGlobals + 0x98) + param_1[0x13b]));
        } while ((iVar2 != 0) || ((*(byte *)(*piVar4 + 0x1a4) & 0x20) == 0));
        iVar2 = (**(code **)(piVar4[0x111] + 0x50))(piVar4);
        iVar5 = AcceptableSpeaker__17CScriptedSentenceP12CBaseMonster(param_1,iVar2);
      } while (iVar5 == 0);
      return iVar2;
    }
    iVar2 = iVar5;
    if ((iVar5 == 0) && (iVar2 = (*DAT_001c1134)(0), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x7c);
    }
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (**(code **)(*(int *)(iVar2 + 0x444) + 0x50))(iVar2);
    }
    if ((iVar2 != 0) &&
       (iVar3 = AcceptableSpeaker__17CScriptedSentenceP12CBaseMonster(param_1,iVar2), iVar3 != 0))
    break;
    iVar2 = param_1[0x13b] + *(int *)(gpGlobals + 0x98);
  }
  return iVar2;
}


