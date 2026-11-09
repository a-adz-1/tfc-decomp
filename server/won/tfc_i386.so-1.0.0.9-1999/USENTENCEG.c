// USENTENCEG_InitLRU__FPUci  @ 000ec6d0
void USENTENCEG_InitLRU__FPUci(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (fSentencesInit != 0) {
    if (0x20 < param_2) {
      param_2 = 0x20;
    }
    iVar4 = 0;
    if (0 < param_2) {
      do {
        *(char *)(iVar4 + param_1) = (char)iVar4;
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_2);
    }
    iVar4 = 0;
    if (0 < param_2 * 4) {
      do {
        iVar2 = (*DAT_00175628)(0,param_2 + -1);
        iVar3 = (*DAT_00175628)(0,param_2 + -1);
        uVar1 = *(undefined1 *)(iVar2 + param_1);
        *(undefined1 *)(iVar2 + param_1) = *(undefined1 *)(iVar3 + param_1);
        *(undefined1 *)(iVar3 + param_1) = uVar1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_2 * 4);
    }
  }
  return;
}


// USENTENCEG_PickSequential__FiPcii  @ 000ec770
uint USENTENCEG_PickSequential__FiPcii(int param_1,char *param_2,int param_3,int param_4)

{
  byte bVar1;
  char local_c [8];
  
  if ((fSentencesInit != 0) && (-1 < param_1)) {
    bVar1 = rgsentenceg[param_1 * 0x34 + 0x10];
    if (bVar1 != 0) {
      if ((int)(uint)bVar1 <= param_3) {
        param_3 = bVar1 - 1;
      }
      param_2[0] = '!';
      param_2[1] = '\0';
      strcat(param_2,rgsentenceg + param_1 * 0x34);
      sprintf(local_c,"%d",param_3);
      strcat(param_2,local_c);
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


// USENTENCEG_Pick__FiPc  @ 000ec830
uint USENTENCEG_Pick__FiPc(int param_1,char *param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  char local_c [8];
  
  if ((fSentencesInit != 0) && (-1 < param_1)) {
    param_1 = param_1 * 0x34;
    bVar1 = rgsentenceg[param_1 + 0x10];
    iVar4 = param_1 + 0x17db14;
    do {
      bVar2 = 0;
      if (bVar1 != 0) {
        do {
          uVar3 = (uint)bVar2;
          if (*(char *)(uVar3 + iVar4) != -1) {
            bVar1 = *(byte *)(uVar3 + iVar4);
            *(undefined1 *)(uVar3 + iVar4) = 0xff;
            param_2[0] = '!';
            param_2[1] = '\0';
            strcat(param_2,rgsentenceg + param_1);
            sprintf(local_c,"%d",(uint)bVar1);
            strcat(param_2,local_c);
            return (uint)bVar1;
          }
          bVar2 = bVar2 + 1;
        } while (bVar2 < bVar1);
      }
      USENTENCEG_InitLRU__FPUci(iVar4,bVar1);
    } while( true );
  }
  return 0xffffffff;
}


