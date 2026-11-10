// Observer_CheckProperties__11CBasePlayer  @ 000cbe18
void Observer_CheckProperties__11CBasePlayer(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(int *)(*param_1 + 0x244) == 4) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x1a7);
    if (iVar1 != 0) {
      piVar2 = (int *)__rf__7EHANDLE(param_1 + 0x1a7);
      uVar3 = (*DAT_0019f7bc)(*(undefined4 *)(*piVar2 + 0x208));
      iVar1 = UTIL_PlayerByIndex__Fi(uVar3);
      if (iVar1 == 0) {
        return;
      }
      iVar4 = 0;
      if (*(int *)(iVar1 + 0x8dc) != 0) {
        iVar4 = *(int *)(*(int *)(iVar1 + 0x8dc) + 0x47c);
      }
      iVar1 = *(int *)(iVar1 + 0x8bc);
      if ((param_1[0x22f] == iVar1) && (param_1[0x1aa] == iVar4)) {
        return;
      }
      param_1[0x22f] = iVar1;
      param_1[0x230] = iVar1;
      (*DAT_0019f758)(1,gmsgSetFOV,0,*(undefined4 *)(*param_1 + 0x208));
      (*DAT_0019f760)(param_1[0x22f]);
      (*DAT_0019f75c)();
      param_1[0x1aa] = iVar4;
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      goto LAB_000cbf77;
    }
  }
  param_1[0x22f] = 0x5a;
  if (param_1[0x1aa] == 0) {
    return;
  }
  param_1[0x1aa] = 0;
  uVar3 = *(undefined4 *)(*param_1 + 0x208);
LAB_000cbf77:
  (*DAT_0019f758)(1,gmsgCurWeapon,0,uVar3);
  (*DAT_0019f760)(1);
  (*DAT_0019f760)(param_1[0x1aa]);
  (*DAT_0019f760)(0);
  (*DAT_0019f75c)();
  return;
}


// Observer_CheckTarget__11CBasePlayer  @ 000cbd38
void Observer_CheckTarget__11CBasePlayer(int *param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  
  if (*(int *)(*param_1 + 0x244) != 3) {
    piVar2 = param_1 + 0x1a7;
    piVar4 = piVar2;
    iVar1 = __opP11CBaseEntity__7EHANDLE(piVar2);
    if (iVar1 == 0) {
      Observer_FindNextPlayer__11CBasePlayerb(param_1,(uint)piVar4 & 0xffff0000);
      iVar1 = __opP11CBaseEntity__7EHANDLE(piVar2);
      if (iVar1 == 0) {
        iVar1 = *(int *)(*param_1 + 0x244);
        Observer_SetMode__11CBasePlayeri(param_1,3);
        param_1[0x1ab] = iVar1;
        return;
      }
    }
    piVar2 = (int *)__rf__7EHANDLE(piVar2);
    uVar3 = (*DAT_0019f7bc)(*(undefined4 *)(*piVar2 + 0x208));
    piVar2 = (int *)UTIL_PlayerByIndex__Fi(uVar3);
    if ((piVar2 == (int *)0x0) ||
       ((*(int *)(*piVar2 + 0x170) == 2 && ((float)piVar2[0x225] + 2.0 < *gpGlobals)))) {
      Observer_FindNextPlayer__11CBasePlayerb(param_1,uVar3 & 0xffff0000);
    }
  }
  return;
}


// Observer_FindNextPlayer__11CBasePlayerb  @ 000cbac4
void Observer_FindNextPlayer__11CBasePlayerb(int *param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  
  piVar4 = param_1 + 0x1a7;
  iVar1 = __opi__7EHANDLE(piVar4);
  if (iVar1 == 0) {
    iVar1 = *param_1;
  }
  else {
    piVar2 = (int *)__rf__7EHANDLE(piVar4);
    iVar1 = *piVar2;
  }
  iVar3 = (*DAT_0019f7bc)(*(undefined4 *)(iVar1 + 0x208));
  __as__7EHANDLEP11CBaseEntity(piVar4,0);
  iVar6 = 1;
  iVar1 = iVar3;
  if (param_2 != '\0') {
    iVar6 = -1;
  }
  while( true ) {
    iVar1 = iVar1 + iVar6;
    if (*(int *)(gpGlobals + 0x90) < iVar1) {
      iVar1 = 1;
    }
    if (iVar1 < 1) {
      iVar1 = *(int *)(gpGlobals + 0x90);
    }
    piVar2 = (int *)UTIL_PlayerByIndex__Fi(iVar1);
    if ((((piVar2 != (int *)0x0) && (piVar2 != param_1)) && (piVar2[0x1e] == 0)) &&
       ((*(int *)(*piVar2 + 0x244) == 0 && (-1 < *(char *)(*piVar2 + 0x118))))) break;
    if (iVar1 == iVar3) {
LAB_000cbba9:
      iVar1 = __opi__7EHANDLE(piVar4);
      if (iVar1 != 0) {
        piVar2 = (int *)__rf__7EHANDLE(piVar4);
        UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*piVar2 + 8);
        if (*(int *)(*param_1 + 0x244) != 3) {
          piVar4 = (int *)__rf__7EHANDLE(piVar4);
          uVar5 = (*DAT_0019f7bc)(*(undefined4 *)(*piVar4 + 0x208));
          *(undefined4 *)(*param_1 + 0x248) = uVar5;
        }
      }
      return;
    }
  }
  __as__7EHANDLEP11CBaseEntity(piVar4,piVar2);
  goto LAB_000cbba9;
}


// Observer_HandleButtons__11CBasePlayer  @ 000cbc20
void Observer_HandleButtons__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined2 uVar6;
  
  uVar5 = 0xcbc2d;
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0x1a9];
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
    return;
  }
  uVar4 = param_1[0x1b6];
  if ((uVar4 & 2) == 0) goto LAB_000cbcc9;
  iVar3 = *(int *)(*param_1 + 0x244);
  if (iVar3 == 1) {
LAB_000cbc9c:
    uVar5 = 2;
  }
  else if (iVar3 == 2) {
    uVar5 = 4;
  }
  else if (iVar3 == 4) {
    uVar5 = 3;
  }
  else if (iVar3 == 3) {
    uVar5 = 5;
  }
  else {
    if (iVar3 != 5) goto LAB_000cbc9c;
    uVar5 = 6;
  }
  Observer_SetMode__11CBasePlayeri(param_1,uVar5);
  uVar4 = param_1[0x1b6];
  param_1[0x1a9] = (int)(*gpGlobals + 0.2);
LAB_000cbcc9:
  uVar6 = (undefined2)(uVar5 >> 0x10);
  if ((uVar4 & 1) != 0) {
    uVar5 = uVar5 & 0xffff0000;
    Observer_FindNextPlayer__11CBasePlayerb(param_1,uVar5);
    uVar6 = (undefined2)(uVar5 >> 0x10);
    uVar4 = param_1[0x1b6];
    param_1[0x1a9] = (int)(*gpGlobals + 0.2);
  }
  if ((uVar4 & 0x800) != 0) {
    Observer_FindNextPlayer__11CBasePlayerb(param_1,CONCAT22(uVar6,1));
    param_1[0x1a9] = (int)(*gpGlobals + 0.2);
  }
  return;
}


// Observer_SetMode__11CBasePlayeri  @ 000cbfcc
void Observer_SetMode__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  char local_14 [16];
  
  if (param_2 != *(int *)(*param_1 + 0x244)) {
    if (5 < param_2 - 1U) {
      param_2 = 4;
    }
    piVar3 = param_1 + 0x1a7;
    iVar1 = __opP11CBaseEntity__7EHANDLE(piVar3);
    if (iVar1 != 0) {
      piVar2 = (int *)__opP11CBaseEntity__7EHANDLE(piVar3);
      if ((((piVar2 == param_1) || (piVar2 == (int *)0x0)) || (piVar2[0x1e] != 0)) ||
         ((*(int *)(*piVar2 + 0x244) != 0 || (*(char *)(*piVar2 + 0x118) < '\0')))) {
        __as__7EHANDLEP11CBaseEntity(piVar3,0);
      }
    }
    *(int *)(*param_1 + 0x244) = param_2;
    if (param_2 != 3) {
      piVar2 = piVar3;
      iVar1 = __opP11CBaseEntity__7EHANDLE(piVar3);
      if (iVar1 == 0) {
        Observer_FindNextPlayer__11CBasePlayerb(param_1,(uint)piVar2 & 0xffff0000);
        iVar1 = __opP11CBaseEntity__7EHANDLE(piVar3);
        if (iVar1 == 0) {
          ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Spec_NoTarget",0,0,0,0);
          *(undefined4 *)(*param_1 + 0x244) = 3;
        }
      }
    }
    if (*(int *)(*param_1 + 0x244) == 3) {
      *(undefined4 *)(*param_1 + 0x248) = 0;
    }
    else {
      piVar3 = (int *)__rf__7EHANDLE(piVar3);
      uVar4 = (*DAT_0019f7bc)(*(undefined4 *)(*piVar3 + 0x208));
      *(undefined4 *)(*param_1 + 0x248) = uVar4;
    }
    *(undefined4 *)(*param_1 + 0x24c) = 0;
    sprintf(local_14,"#Spec_Mode%i",*(undefined4 *)(*param_1 + 0x244));
    ClientPrint__FP9entvars_siPCcN42(*param_1,4,local_14,0,0,0,0);
    param_1[0x1ab] = param_2;
  }
  return;
}


