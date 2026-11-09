// Host_Frame  @ 100177d0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Host_Frame(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  float10 fVar6;
  float10 fVar7;
  
                    /* 0x177d0  29  Host_Frame */
  iVar1 = __setjmp3(&DAT_10a4ff10,0);
  if (iVar1 != 0) {
    return DAT_105599c4;
  }
  if ((DAT_1099e680 == 5) && (DAT_100db320 != 0)) {
    FUN_10086890(&DAT_105597c0);
    DAT_100db320 = 0;
    puVar5 = &DAT_105597c0;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
  }
  DAT_105599c4 = param_2;
  *param_3 = 0;
  if (_DAT_100c15c4 != 0.0) {
    fVar6 = (float10)Sys_FloatTime();
    FUN_10017570(param_1);
    fVar7 = (float10)Sys_FloatTime();
    iVar1 = DAT_100db2e8;
    if (DAT_100db2e8 != 0) {
      DAT_100db2e8 = 0;
      *param_3 = iVar1;
      FUN_10003890();
    }
    if ((DAT_1099e680 == 1) && (DAT_100d7600 != 0)) {
      DAT_105599c4 = 2;
    }
    DAT_1040f214 = DAT_1040f214 + 1;
    _DAT_1040ea00 = (_DAT_1040ea00 - (double)fVar6) + (double)fVar7;
    if (999 < DAT_1040f214) {
      uVar2 = __ftol();
      iVar4 = 0;
      DAT_1040f214 = 0;
      _DAT_1040ea00 = 0.0;
      piVar3 = DAT_10ae0d20;
      iVar1 = DAT_10ad9d10;
      if (0 < DAT_10ad9d10) {
        do {
          if (*piVar3 != 0) {
            iVar4 = iVar4 + 1;
          }
          iVar1 = iVar1 + -1;
          piVar3 = piVar3 + 0x1434;
        } while (iVar1 != 0);
      }
      Con_Printf(s_serverprofile___2i_clients__2i_m_100c1c14,iVar4,uVar2);
      return DAT_105599c4;
    }
    return DAT_105599c4;
  }
  FUN_10017570(param_1);
  iVar1 = DAT_100db2e8;
  if (DAT_100db2e8 != 0) {
    DAT_100db2e8 = 0;
    *param_3 = iVar1;
    FUN_10003890();
  }
  return DAT_105599c4;
}


// Host_GetHostInfo  @ 100172f0
void Host_GetHostInfo(undefined4 *param_1,int *param_2,int *param_3,undefined4 *param_4,
                     char *param_5)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  int local_8;
  int local_4;
  
                    /* 0x172f0  30  Host_GetHostInfo */
  *param_1 = DAT_100c155c;
  local_4 = 0;
  local_8 = 0;
  FUN_100051e0(&local_8,&local_4);
  *param_2 = local_8 - local_4;
  *param_3 = local_4;
  if (param_5 != (char *)0x0) {
    if ((char)DAT_10ae1868 == '\0') {
      *param_5 = '\0';
    }
    else {
      uVar2 = 0xffffffff;
      pcVar4 = (char *)&DAT_10ae1868;
      do {
        pcVar5 = pcVar4;
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        pcVar5 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar5;
      } while (cVar1 != '\0');
      uVar2 = ~uVar2;
      pcVar4 = pcVar5 + -uVar2;
      for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined4 *)param_5 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        param_5 = param_5 + 4;
      }
      for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *param_5 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        param_5 = param_5 + 1;
      }
    }
  }
  *param_4 = DAT_10ad9d10;
  return;
}


// Host_Shutdown  @ 10018110
void Host_Shutdown(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x18110  31  Host_Shutdown */
  if (DAT_100c16a0 != 0) {
    _printf(s_recursive_shutdown_100c1f30);
    return;
  }
  DAT_100c16a0 = 1;
  if (DAT_100c1560 != 0) {
    FUN_10015d20();
  }
  DAT_100c1560 = 0;
  if (DAT_1099e680 != 0) {
    FUN_10078120();
  }
  iVar3 = 0;
  FUN_1007c6e0();
  FUN_10004830();
  iVar2 = DAT_10ae0d20;
  if (0 < DAT_10ad9d14) {
    do {
      iVar1 = iVar2 + 0x4d1c;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x50d0;
      FUN_10004a80(iVar1);
    } while (iVar3 < DAT_10ad9d14);
  }
  FUN_100169a0(1);
  DAT_1055a504 = 1;
  FUN_1001f3b0();
  FUN_1002d9b0();
  FUN_10020d90();
  FUN_10075ac0();
  if (DAT_1099e680 != 0) {
    (*DAT_105597ac)();
  }
  FUN_10087240();
  FUN_10032c50();
  FUN_10030dc0();
  if (DAT_100dc200 != (void *)0x0) {
    _free(DAT_100dc200);
  }
  DAT_100dc200 = (void *)0x0;
  if (DAT_1099e680 != 0) {
    FUN_100426a0();
  }
  FUN_100426d0();
  FUN_1001d3b0();
  FUN_10017b40(s_Server_shutdown__100c1f44);
  FUN_10017c80();
  FUN_10063790();
  if (DAT_1099e680 != 0) {
    FUN_10054140();
  }
  return;
}


