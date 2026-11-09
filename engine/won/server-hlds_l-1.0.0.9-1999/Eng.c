// Eng_Frame__Fi  @ 0808a9b0
int Eng_Frame__Fi(int param_1)

{
  longdouble lVar1;
  double dVar2;
  clock_t cVar3;
  int iVar4;
  longdouble lVar5;
  longdouble lVar6;
  
  ServiceAuthRefresh__Fv();
  if ((gDLLState == 1) || (param_1 != 0)) {
    dVar2 = oldtime_102;
    if (gDLLState != 0) {
      while( true ) {
        lVar5 = (longdouble)Sys_FloatTime();
        lVar6 = lVar5 - (longdouble)oldtime_102;
        lVar1 = (longdouble)oosys_ticrate;
        if ((byte)(lVar6 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(lVar6 == lVar1) << 0xe) >> 8)) != 1) break;
        if (2 < (int)ROUND((oosys_ticrate - (double)lVar6) * 1000.0)) {
          usleep(2);
        }
      }
      accum_103 = (double)lVar6 + accum_103;
      cVar3 = clock();
      lastgap_104 = (double)((float)accum_103 - (float)(cVar3 - tStart) / 1e+06);
      gDLLStateInfo = 0;
      iVar4 = Host_Frame((float)lVar6,gDLLState,&gDLLStateInfo);
      if ((((gDLLStateInfo != 0) && (0 < gDLLStateInfo)) && (3 < gDLLStateInfo)) &&
         (gDLLStateInfo == 4)) {
        Eng_Unload__Fv();
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      if (iWait != 0) {
        iWait = iWait + -1;
        if (iVar4 == 2) {
          fDeferedPause = 1;
          Eng_SetState__Fi(1);
          iVar4 = 1;
        }
        if ((iWait == 0) && (fDeferedPause != 0)) {
          iVar4 = 2;
          gDLLState = 1;
          fDeferedPause = 0;
        }
      }
      if (iVar4 == 4) {
        iVar4 = 1;
        iWait = 5;
        Eng_SetState__Fi(1);
      }
      dVar2 = (double)lVar5;
      if (iVar4 != gDLLState) {
        Eng_SetState__Fi(iVar4);
      }
    }
    oldtime_102 = dVar2;
    iVar4 = gDLLState;
    if (gDLLState == 3) {
      Eng_Unload__Fv();
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}


// Eng_LoadGame__Fv  @ 0808a8f0
void Eng_LoadGame__Fv(void)

{
  return;
}


// Eng_Load__FPCci  @ 0808a920
undefined4 Eng_Load__FPCci(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  int iVar2;
  
  tStart = clock();
  Eng_SetState__Fi(1);
  Eng_SetSubState__Fi(param_2);
  gfInLoad = 1;
  pcVar1 = (char *)GetCommandLine__Fv();
  if (pcVar1 == (char *)0x0) {
    pcVar1 = szEmpty;
  }
  iVar2 = GameInit(pcVar1,gpMemBase,giMemSize,ef,0,"Player",1);
  if (iVar2 != 0) {
    Eng_Frame__Fi(1);
    gfInLoad = 0;
  }
  return 1;
}


// Eng_SaveGame__Fv  @ 0808a8e0
undefined4 Eng_SaveGame__Fv(void)

{
  return 1;
}


// Eng_SetState__Fi  @ 0808abb0
void Eng_SetState__Fi(undefined4 param_1)

{
  gDLLState = param_1;
  GameSetState(param_1);
  return;
}


// Eng_SetSubState__Fi  @ 0808ab90
void Eng_SetSubState__Fi(int param_1)

{
  if (param_1 != 1) {
    GameSetSubState(param_1);
  }
  return;
}


// Eng_Unload__Fv  @ 0808a900
void Eng_Unload__Fv(void)

{
  gDLLState = 0;
  gDLLStateInfo = 0;
  return;
}


