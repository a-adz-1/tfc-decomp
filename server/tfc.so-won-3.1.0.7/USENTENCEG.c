// USENTENCEG_InitLRU__FPUci  @ 000eecf4
void USENTENCEG_InitLRU__FPUci(undefined1 *param_1,uint param_2)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  
  if (fSentencesInit == 0) {
    return;
  }
  if (0x20 < (int)param_2) {
    param_2 = 0x20;
  }
  iVar6 = 0;
  if (0 < (int)param_2) {
    uVar2 = param_2 & 3;
    if (uVar2 != 0) {
      if (1 < uVar2) {
        if (2 < uVar2) {
          *param_1 = 0;
        }
        uVar7 = (uint)(2 < uVar2);
        param_1[uVar7] = 2 < uVar2;
        iVar6 = uVar7 + 1;
      }
      param_1[iVar6] = (char)iVar6;
      iVar6 = iVar6 + 1;
      if ((int)param_2 <= iVar6) goto LAB_000eed82;
    }
    do {
      cVar5 = (char)iVar6;
      param_1[iVar6] = cVar5;
      param_1[iVar6 + 1] = cVar5 + '\x01';
      param_1[iVar6 + 2] = cVar5 + '\x02';
      param_1[iVar6 + 3] = cVar5 + '\x03';
      iVar6 = iVar6 + 4;
    } while (iVar6 < (int)param_2);
  }
LAB_000eed82:
  iVar6 = 0;
  if (0 < (int)(param_2 * 4)) {
    do {
      iVar3 = (*DAT_001c1188)(0,param_2 - 1);
      iVar4 = (*DAT_001c1188)(0,param_2 - 1);
      uVar1 = param_1[iVar3];
      param_1[iVar3] = param_1[iVar4];
      param_1[iVar4] = uVar1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)(param_2 * 4));
  }
  return;
}


// USENTENCEG_PickSequential__FiPcii  @ 000eedf8
uint USENTENCEG_PickSequential__FiPcii(int param_1,char *param_2,int param_3,int param_4)

{
  byte bVar1;
  char acStack_8 [8];
  
  if ((fSentencesInit != 0) && (-1 < param_1)) {
    bVar1 = rgsentenceg[param_1 * 0x34 + 0x10];
    if (bVar1 != 0) {
      if ((int)(uint)bVar1 <= param_3) {
        param_3 = bVar1 - 1;
      }
      param_2[0] = '!';
      param_2[1] = '\0';
      strcat(param_2,rgsentenceg + param_1 * 0x34);
      sprintf(acStack_8,"%d",param_3);
      strcat(param_2,acStack_8);
      if ((int)(uint)bVar1 <= param_3) {
        if (param_4 != 0) {
          return 0;
        }
        return (uint)bVar1;
      }
      return param_3 + 1;
    }
  }
  return 0xffffffff;
}


// USENTENCEG_Pick__FiPc  @ 000eeeb0
/* WARNING: Removing unreachable block (ram,0x000ef004) */

uint USENTENCEG_Pick__FiPc(int param_1,char *param_2)

{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  byte bVar5;
  char acStack_8 [8];
  
  if ((fSentencesInit == 0) || (param_1 < 0)) {
    return 0xffffffff;
  }
  param_1 = param_1 * 0x34;
  bVar2 = rgsentenceg[param_1 + 0x10];
  pcVar1 = rgsentenceg + param_1 + 0x14;
LAB_000eef0a:
  bVar5 = 0;
  if (bVar2 == 0) goto code_r0x000eefa4;
  bVar3 = bVar2 & 3;
  if ((char)bVar2 < '\x01') {
LAB_000eef4c:
    uVar4 = (uint)bVar5;
    if (pcVar1[uVar4] != -1) goto LAB_000eefbc;
    bVar5 = bVar5 + 1;
    if (bVar2 <= bVar5) goto code_r0x000eefa4;
  }
  else if (bVar3 != 0) {
    if (1 < bVar3) {
      if (2 < bVar3) {
        uVar4 = 0;
        if (*pcVar1 != -1) {
LAB_000eefbc:
          bVar2 = pcVar1[uVar4];
          pcVar1[uVar4] = -1;
          param_2[0] = '!';
          param_2[1] = '\0';
          strcat(param_2,rgsentenceg + param_1);
          sprintf(acStack_8,"%d",(uint)bVar2);
          strcat(param_2,acStack_8);
          return (uint)bVar2;
        }
        bVar5 = 1;
      }
      uVar4 = (uint)bVar5;
      if (pcVar1[uVar4] == -1) {
        bVar5 = bVar5 + 1;
        goto LAB_000eef4c;
      }
      goto LAB_000eefbc;
    }
    goto LAB_000eef4c;
  }
  do {
    uVar4 = (uint)bVar5;
    if ((((pcVar1[uVar4] != -1) || (uVar4 = (uint)(byte)(bVar5 + 1), pcVar1[uVar4] != -1)) ||
        (uVar4 = (uint)(byte)(bVar5 + 2), pcVar1[uVar4] != -1)) ||
       (uVar4 = (uint)(byte)(bVar5 + 3), pcVar1[uVar4] != -1)) goto LAB_000eefbc;
    bVar5 = bVar5 + 4;
  } while (bVar5 < bVar2);
code_r0x000eefa4:
  USENTENCEG_InitLRU__FPUci(pcVar1,bVar2);
  goto LAB_000eef0a;
}


