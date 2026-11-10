// Observer_FindNextPlayer__11CBasePlayerb  @ 000cbf70
void Observer_FindNextPlayer__11CBasePlayerb(int *param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar1 = __opi__7EHANDLE(param_1 + 0x35d);
  if (iVar1 == 0) {
    iVar1 = *param_1;
  }
  else {
    piVar2 = (int *)__rf__7EHANDLE(param_1 + 0x35d);
    iVar1 = *piVar2;
  }
  iVar3 = (*DAT_001c113c)(*(undefined4 *)(iVar1 + 0x208));
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x35d,0);
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
LAB_000cc062:
      piVar2 = param_1 + 0x35d;
      iVar1 = __opi__7EHANDLE(piVar2);
      if (iVar1 == 0) {
        (*DAT_001c1114)(1,"No observer targets.\n");
      }
      else {
        piVar4 = (int *)__rf__7EHANDLE(piVar2);
        uVar5 = (*DAT_001c113c)(*(undefined4 *)(*piVar4 + 0x208));
        *(undefined4 *)(*param_1 + 0x248) = uVar5;
        piVar4 = (int *)__rf__7EHANDLE(piVar2);
        UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*piVar4 + 8);
        piVar2 = (int *)__rf__7EHANDLE(piVar2);
        (*DAT_001c1114)(1,"Now Tracking %s\n",*(int *)(*piVar2 + 0x1d0) + *(int *)(gpGlobals + 0x98)
                       );
      }
      return;
    }
  }
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x35d,piVar2);
  goto LAB_000cc062;
}


// Observer_HandleButtons__11CBasePlayer  @ 000cc124
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Observer_HandleButtons__11CBasePlayer(int *param_1)

{
  uint uVar1;
  undefined2 uVar2;
  
  uVar1 = 0xcc12e;
  if ((float)param_1[0x35f] <= *gpGlobals) {
    if ((*(byte *)(param_1 + 0x1ad) & 2) != 0) {
      if (*(int *)(*param_1 + 0x244) == 3) {
        uVar1 = 1;
      }
      else if (*(int *)(*param_1 + 0x244) == 1) {
        uVar1 = 2;
      }
      else {
        uVar1 = 3;
      }
      Observer_SetMode__11CBasePlayeri(param_1,uVar1);
      param_1[0x35f] = (int)((float)_FUN_00149e60 + *gpGlobals);
    }
    uVar2 = (undefined2)(uVar1 >> 0x10);
    if (((*(byte *)(param_1 + 0x1ad) & 1) != 0) && (*(int *)(*param_1 + 0x244) != 3)) {
      uVar1 = uVar1 & 0xffff0000;
      Observer_FindNextPlayer__11CBasePlayerb(param_1,uVar1);
      uVar2 = (undefined2)(uVar1 >> 0x10);
      param_1[0x35f] = (int)((float)_FUN_00149e60 + *gpGlobals);
    }
    if (((*(byte *)((int)param_1 + 0x6b5) & 8) != 0) && (*(int *)(*param_1 + 0x244) != 3)) {
      Observer_FindNextPlayer__11CBasePlayerb(param_1,CONCAT22(uVar2,1));
      param_1[0x35f] = (int)((float)_FUN_00149e60 + *gpGlobals);
    }
  }
  return;
}


// Observer_SetMode__11CBasePlayeri  @ 000cc230
void Observer_SetMode__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  if (param_2 == *(int *)(*param_1 + 0x244)) {
    return;
  }
  if (param_2 == 3) {
    *(undefined4 *)(*param_1 + 0x244) = 3;
    *(undefined4 *)(*param_1 + 0x248) = 0;
    pcVar4 = "#Spec_Mode3";
  }
  else if (param_2 == 1) {
    piVar2 = param_1 + 0x35d;
    iVar1 = __opP11CBaseEntity__7EHANDLE(piVar2);
    if (iVar1 == 0) {
      Observer_FindNextPlayer__11CBasePlayerb(param_1,(uint)piVar2 & 0xffff0000);
    }
    iVar1 = __opi__7EHANDLE(param_1 + 0x35d);
    if (iVar1 == 0) {
LAB_000cc3ac:
      ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Spec_NoTarget",0,0,0,0);
      Observer_SetMode__11CBasePlayeri(param_1,3);
      return;
    }
    *(undefined4 *)(*param_1 + 0x244) = 1;
    piVar2 = (int *)__rf__7EHANDLE(param_1 + 0x35d);
    uVar3 = (*DAT_001c113c)(*(undefined4 *)(*piVar2 + 0x208));
    *(undefined4 *)(*param_1 + 0x248) = uVar3;
    pcVar4 = "#Spec_Mode1";
  }
  else {
    if (param_2 != 2) {
      return;
    }
    piVar2 = param_1 + 0x35d;
    iVar1 = __opP11CBaseEntity__7EHANDLE(piVar2);
    if (iVar1 == 0) {
      Observer_FindNextPlayer__11CBasePlayerb(param_1,(uint)piVar2 & 0xffff0000);
    }
    iVar1 = __opi__7EHANDLE(param_1 + 0x35d);
    if (iVar1 == 0) goto LAB_000cc3ac;
    *(undefined4 *)(*param_1 + 0x244) = 2;
    piVar2 = (int *)__rf__7EHANDLE(param_1 + 0x35d);
    uVar3 = (*DAT_001c113c)(*(undefined4 *)(*piVar2 + 0x208));
    *(undefined4 *)(*param_1 + 0x248) = uVar3;
    pcVar4 = "#Spec_Mode2";
  }
  ClientPrint__FP9entvars_siPCcN42(*param_1,4,pcVar4,0,0,0,0);
  return;
}


