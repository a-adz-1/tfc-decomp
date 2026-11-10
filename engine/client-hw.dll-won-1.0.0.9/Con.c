// Con_DPrintf  @ 10075e70
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Con_DPrintf(void)

{
  char *in_stack_00001004;
  
                    /* 0x75e70  7  Con_DPrintf */
  FUN_100a3640();
  if ((_DAT_100c160c != 0.0) && ((_DAT_1055a4d8 == 0.0 || (DAT_1099e680 != 5)))) {
    _vsprintf(&stack0x00000000,in_stack_00001004,&stack0x00001008);
    DAT_100d7634 = 1;
    Con_Printf();
    DAT_100d7634 = 0;
  }
  return;
}


// Con_GetInput  @ 10076040
void Con_GetInput(char *param_1,size_t param_2)

{
  size_t _Count;
  
                    /* 0x76040  8  Con_GetInput */
  _Count = param_2;
  if ((int)DAT_100d7604 <= (int)param_2) {
    _Count = DAT_100d7604;
  }
  _strncpy(param_1,&DAT_1099bb90 + DAT_100cd6ac * 0x100,_Count);
  if ((int)DAT_100d7604 <= (int)param_2) {
    param_2 = DAT_100d7604;
  }
  param_1[param_2 - 1] = '\0';
  return;
}


// Con_Printf  @ 10075d10
void Con_Printf(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *in_stack_00001004;
  
                    /* 0x75d10  9  Con_Printf */
  FUN_100a3640();
  _vsprintf(&stack0x00000000,in_stack_00001004,&stack0x00001008);
  FUN_10085f00();
  if (DAT_10998944 == 0) {
    if (DAT_10572d6c != 0) {
      FUN_100626e0();
      FUN_10075cb0();
    }
    if ((DAT_10572d60 != 0) && (DAT_1099e680 != 0)) {
      if (((DAT_100d7600 == 0) && ((DAT_1055980c & 4) == 0)) || (DAT_100d7634 != 0)) {
        FUN_10075b40();
      }
      if (((DAT_109a234c != 3) && (DAT_1055a504 == 0)) && (DAT_104c02ac == 0)) {
        DAT_104c02ac = 1;
        FUN_10080e20();
        DAT_104c02ac = 0;
      }
    }
    return;
  }
  uVar2 = 0xffffffff;
  pcVar5 = (char *)register0x00000010;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = 0xffffffff;
  pcVar5 = &DAT_10998950;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (0x577 < ~uVar3 + (~uVar2 - 2)) {
    FUN_1005a480();
  }
  uVar2 = 0xffffffff;
  pcVar5 = (char *)register0x00000010;
  do {
    pcVar7 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  iVar4 = -1;
  pcVar5 = &DAT_10998950;
  do {
    pcVar6 = pcVar5;
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  pcVar5 = pcVar7 + -uVar2;
  pcVar7 = pcVar6 + -1;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar7 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  }
  return;
}


// Con_SafePrintf  @ 10075f00
void Con_SafePrintf(char *param_1)

{
  undefined4 uVar1;
  char local_400 [1024];
  
                    /* 0x75f00  10  Con_SafePrintf */
  _vsprintf(local_400,param_1,&stack0x00000008);
  uVar1 = DAT_1055a504;
  DAT_1055a504 = 1;
  DAT_100d7634 = 1;
  Con_Printf(&DAT_100d77d0,local_400);
  DAT_1055a504 = uVar1;
  DAT_100d7634 = 0;
  return;
}


