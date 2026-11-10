// FindEntity__12CCineMonster  @ 000e93d4
undefined4 FindEntity__12CCineMonster(int *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *local_10;
  int local_8;
  
  local_8 = (*DAT_0019f6d8)(0,"targetname",param_1[0x1a9] + *(int *)(gpGlobals + 0x98));
  piVar5 = param_1 + 0x141;
  __as__7EHANDLEP11CBaseEntity(piVar5,0);
  while( true ) {
    bVar1 = false;
    if ((local_8 == 0) || (iVar2 = (*DAT_0019f7b8)(local_8), iVar2 == 0)) {
      bVar1 = true;
    }
    if (bVar1) break;
    iVar2 = local_8 + 0x80;
    if (local_8 == 0) {
      iVar2 = 0;
    }
    if ((*(byte *)(iVar2 + 0x1a4) & 0x20) != 0) {
      iVar2 = local_8;
      if ((local_8 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(iVar2 + 0x7c);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (**(code **)(*(int *)(iVar2 + 0x454) + 0x50))(iVar2);
      }
      if (iVar2 != 0) {
        iVar4 = *(int *)(iVar2 + 0x454);
        uVar3 = (**(code **)(param_1[0x115] + 0x224))(param_1,1);
        iVar4 = (**(code **)(iVar4 + 0x180))(iVar2,uVar3);
        if (iVar4 != 0) goto LAB_000e9601;
      }
      (*DAT_0019f794)(1,"Found %s, but can\'t play!\n",param_1[0x1a9] + *(int *)(gpGlobals + 0x98));
    }
    local_8 = (*DAT_0019f6d8)(local_8,"targetname",param_1[0x1a9] + *(int *)(gpGlobals + 0x98));
  }
  local_10 = (int *)0x0;
  do {
    do {
      local_10 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                  (local_10,*param_1 + 8,param_1[0x1ac]);
      if (local_10 == (int *)0x0) {
        __as__7EHANDLEP11CBaseEntity(piVar5,0);
        return 0;
      }
      iVar2 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + *(int *)*local_10),
                     (char *)(*(int *)(gpGlobals + 0x98) + param_1[0x1a9]));
    } while (((iVar2 != 0) || ((*(byte *)(*local_10 + 0x1a4) & 0x20) == 0)) ||
            (iVar2 = (**(code **)(local_10[0x115] + 0x50))(local_10), iVar2 == 0));
    iVar4 = *(int *)(iVar2 + 0x454);
    uVar3 = (**(code **)(param_1[0x115] + 0x224))(param_1,0);
    iVar4 = (**(code **)(iVar4 + 0x180))(iVar2,uVar3);
  } while (iVar4 == 0);
LAB_000e9601:
  __as__7EHANDLEP11CBaseEntity(piVar5,iVar2);
  return 1;
}


// FindEntity__17CScriptedSentence  @ 000ea6ec
int FindEntity__17CScriptedSentence(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piStack_c;
  
  iVar2 = param_1[0x13f] + *(int *)(gpGlobals + 0x98);
  iVar5 = 0;
  while( true ) {
    iVar5 = (*DAT_0019f6d8)(iVar5,"targetname",iVar2);
    bVar1 = false;
    if ((iVar5 == 0) || (iVar2 = (*DAT_0019f7b8)(iVar5), iVar2 == 0)) {
      bVar1 = true;
    }
    if (bVar1) break;
    iVar2 = iVar5;
    if ((iVar5 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x7c);
    }
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (**(code **)(*(int *)(iVar2 + 0x454) + 0x50))(iVar2);
    }
    if (iVar2 != 0) {
      if ((*(byte *)(*param_1 + 0x1a0) & 2) == 0) {
LAB_000ea7c6:
        iVar3 = (**(code **)(*(int *)(iVar2 + 0x454) + 0x184))
                          (iVar2,(*(byte *)(*param_1 + 0x1a0) & 4) != 0);
        if (iVar3 != 0) {
          return iVar2;
        }
      }
      else {
        iVar3 = __opP11CBaseEntity__7EHANDLE(iVar2 + 0x504);
        if (iVar3 != 0) {
          puVar4 = (undefined4 *)__rf__7EHANDLE(iVar2 + 0x504);
          iVar3 = strcmp((char *)(*(int *)*puVar4 + *(int *)(gpGlobals + 0x98)),(char *)FUN_00151d78
                        );
          if (iVar3 == 0) goto LAB_000ea7c6;
        }
      }
    }
    iVar2 = param_1[0x13f] + *(int *)(gpGlobals + 0x98);
  }
  piStack_c = (int *)0x0;
LAB_000ea954:
  do {
    do {
      piStack_c = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                   (piStack_c,*param_1 + 8,param_1[0x140]);
      if (piStack_c == (int *)0x0) {
        return 0;
      }
      iVar2 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + *(int *)*piStack_c),
                     (char *)(*(int *)(gpGlobals + 0x98) + param_1[0x13f]));
    } while ((iVar2 != 0) || ((*(byte *)(*piStack_c + 0x1a4) & 0x20) == 0));
    iVar2 = (**(code **)(piStack_c[0x115] + 0x50))(piStack_c);
    if (iVar2 == 0) {
LAB_000ea947:
      bVar1 = false;
    }
    else {
      if ((*(byte *)(*param_1 + 0x1a0) & 2) != 0) {
        iVar5 = __opP11CBaseEntity__7EHANDLE(iVar2 + 0x504);
        if (iVar5 == 0) goto LAB_000ea954;
        puVar4 = (undefined4 *)__rf__7EHANDLE(iVar2 + 0x504);
        iVar5 = strcmp((char *)(*(int *)*puVar4 + *(int *)(gpGlobals + 0x98)),(char *)FUN_00151d78);
        if (iVar5 != 0) goto LAB_000ea954;
      }
      iVar5 = (**(code **)(*(int *)(iVar2 + 0x454) + 0x184))
                        (iVar2,(*(byte *)(*param_1 + 0x1a0) & 4) != 0);
      bVar1 = true;
      if (iVar5 == 0) goto LAB_000ea947;
    }
    if (bVar1) {
      return iVar2;
    }
  } while( true );
}


