// Key_ClearStates  @ 10042680
void Key_ClearStates(void)

{
  int iVar1;
  undefined4 *puVar2;
  
                    /* 0x42680  39  Key_ClearStates */
  puVar2 = &DAT_1099b780;
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_1099a6f0;
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}


// Key_Event  @ 100423b0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Key_Event(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  char local_400 [1024];
  
                    /* 0x423b0  40  Key_Event */
  (&DAT_1099a6f0)[param_1] = param_2;
  if (((DAT_1099a904 != 0) && (DAT_1099a900 != 0)) && (DAT_1099a940 != 0)) {
    FUN_10085dc0(s_ctrl_alt_del_pressed_100cdcc4);
  }
  if (param_2 == 0) {
    (&DAT_1099b780)[param_1] = 0;
  }
  _DAT_1099db90 = param_1;
  DAT_1099b370 = DAT_1099b370 + 1;
  if (0 < DAT_1099b370) {
    if (param_2 != 0) {
      iVar1 = (&DAT_1099b780)[param_1];
      (&DAT_1099b780)[param_1] = iVar1 + 1;
      if (((param_1 != 0x7f) && (param_1 != 0xff)) && (1 < iVar1 + 1)) {
        return;
      }
      if ((199 < param_1) && ((&DAT_1099af70)[param_1] == 0)) {
        uVar3 = FUN_10041d90(param_1);
        Con_Printf(s__s_is_unbound__100cdcdc,uVar3);
      }
    }
    if (param_1 == 0x86) {
      DAT_100cd6a8 = param_2;
    }
    if (param_2 == 0) {
      pcVar2 = (char *)(&DAT_1099af70)[param_1];
      if ((pcVar2 != (char *)0x0) && (*pcVar2 == '+')) {
        _sprintf(local_400,s___s__i_100cdcec,pcVar2 + 1,param_1);
        Cbuf_AddText(local_400);
      }
      if (((param_1 != (&DAT_1099ab70)[param_1]) &&
          (pcVar2 = (char *)(&DAT_1099af70)[(&DAT_1099ab70)[param_1]], pcVar2 != (char *)0x0)) &&
         (*pcVar2 == '+')) {
        _sprintf(local_400,s___s__i_100cdcf4,pcVar2 + 1,param_1);
        Cbuf_AddText(local_400);
        return;
      }
    }
    else if (((DAT_1055980c & 0x10) == 0) || (param_1 == 0x1b)) {
      if ((DAT_109a2ee0 != 0) &&
         (((param_2 != 0 && (*(int *)(&DAT_1099b380 + param_1 * 4) != 0)) && (DAT_100cd6b4 == 0))))
      {
        FUN_10075660();
        return;
      }
      if ((((DAT_100cd6b4 == 3) && (*(int *)(&DAT_1099a2f0 + param_1 * 4) != 0)) ||
          ((DAT_100cd6b4 == 1 && (*(int *)(&DAT_1099b380 + param_1 * 4) == 0)))) ||
         ((DAT_100cd6b4 == 0 &&
          ((DAT_10572d4c == 0 || (*(int *)(&DAT_1099b380 + param_1 * 4) == 0)))))) {
        pcVar2 = (char *)(&DAT_1099af70)[param_1];
        if (pcVar2 != (char *)0x0) {
          if (*pcVar2 != '+') {
            Cbuf_AddText(pcVar2);
            Cbuf_AddText(&DAT_100cdd04);
            return;
          }
          _sprintf(local_400,s__s__i_100cdcfc,pcVar2,param_1);
          Cbuf_AddText(local_400);
          return;
        }
      }
      else if (param_2 != 0) {
        if (DAT_100cd6a8 != 0) {
          param_1 = (&DAT_1099ab70)[param_1];
        }
        switch(DAT_100cd6b4) {
        case 0:
        case 1:
          FUN_10041810(param_1);
          return;
        case 2:
          FUN_10041c80(param_1);
          return;
        default:
          FUN_10085dc0(s_Bad_key_dest_100cdd08);
          return;
        case 4:
          FUN_100540c0(param_1);
        }
      }
    }
  }
  return;
}


// Key_UpLine  @ 10041790
void Key_UpLine(void)

{
  do {
    DAT_100cd6b0 = DAT_100cd6b0 - 1 & 0x1f;
    if (DAT_100cd6ac == DAT_100cd6b0) break;
  } while ((&DAT_1099bb91)[DAT_100cd6b0 * 0x100] == '\0');
  if (DAT_100cd6ac == DAT_100cd6b0) {
    DAT_100cd6b0 = DAT_100cd6ac + 1 & 0x1f;
  }
  FUN_10060440(&DAT_1099bb90 + DAT_100cd6ac * 0x100,&DAT_1099bb90 + DAT_100cd6b0 * 0x100);
  DAT_1099bb80 = FUN_10060490(&DAT_1099bb90 + DAT_100cd6ac * 0x100);
  return;
}


