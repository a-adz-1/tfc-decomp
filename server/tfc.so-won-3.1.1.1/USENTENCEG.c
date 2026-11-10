// USENTENCEG_InitLRU__FPUci  @ 000f2748
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
    if (0 < param_2 * 4) {
      iVar4 = 0;
      do {
        iVar2 = (*DAT_0019f808)(0,param_2 + -1);
        iVar3 = (*DAT_0019f808)(0,param_2 + -1);
        uVar1 = *(undefined1 *)(iVar2 + param_1);
        *(undefined1 *)(iVar2 + param_1) = *(undefined1 *)(iVar3 + param_1);
        iVar4 = iVar4 + 1;
        *(undefined1 *)(iVar3 + param_1) = uVar1;
      } while (iVar4 < param_2 * 4);
    }
  }
  return;
}


// USENTENCEG_PickSequential__FiPcii  @ 000f2698
uint USENTENCEG_PickSequential__FiPcii(int param_1,char *param_2,int param_3,int param_4)

{
  uint uVar1;
  char local_c [8];
  
  if ((fSentencesInit != 0) && (-1 < param_1)) {
    if (rgsentenceg[param_1 * 0x34 + 0x10] != 0) {
      uVar1 = (uint)(byte)rgsentenceg[param_1 * 0x34 + 0x10];
      if ((int)uVar1 <= param_3) {
        param_3 = uVar1 - 1;
      }
      param_2[0] = '!';
      param_2[1] = '\0';
      strcat(param_2,rgsentenceg + param_1 * 0x34);
      sprintf(local_c,"%d",param_3);
      strcat(param_2,local_c);
      if ((int)uVar1 <= param_3) {
        if (param_4 == 0) {
          return uVar1;
        }
        return 0;
      }
      return param_3 + 1;
    }
  }
  return 0xffffffff;
}


// USENTENCEG_Pick__FiPc  @ 000f06fc
/* WARNING: Removing unreachable block (ram,0x000f086e) */

uint USENTENCEG_Pick__FiPc(int param_1,char *param_2)

{
  int iVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  char local_c [8];
  
  if ((fSentencesInit != 0) && (-1 < param_1)) {
    param_1 = param_1 * 0x34;
    bVar2 = rgsentenceg[param_1 + 0x10];
    iVar1 = param_1 + 0x1a7d74;
    do {
      uVar7 = 0;
      if (bVar2 != 0) {
        do {
          bVar6 = *(byte *)(uVar7 + iVar1);
          if (bVar6 != 0xff) {
            *(undefined1 *)(uVar7 + iVar1) = 0xff;
            param_2[0] = '!';
            param_2[1] = '\0';
            strcat(param_2,rgsentenceg + param_1);
            sprintf(local_c,"%d",(uint)bVar6);
            strcat(param_2,local_c);
            return (uint)bVar6;
          }
          bVar6 = (char)uVar7 + 1;
          uVar7 = (uint)bVar6;
        } while (bVar6 < bVar2);
      }
      uVar7 = (uint)bVar2;
      if (fSentencesInit != 0) {
        if (0x20 < bVar2) {
          uVar7 = 0x20;
        }
        iVar8 = 0;
        if (uVar7 != 0) {
          do {
            *(char *)(iVar8 + iVar1) = (char)iVar8;
            iVar8 = iVar8 + 1;
          } while (iVar8 < (int)uVar7);
        }
        if (uVar7 != 0) {
          iVar8 = 0;
          do {
            iVar4 = (*DAT_0019f808)(0,uVar7 - 1);
            iVar5 = (*DAT_0019f808)(0,uVar7 - 1);
            uVar3 = *(undefined1 *)(iVar4 + iVar1);
            *(undefined1 *)(iVar4 + iVar1) = *(undefined1 *)(iVar5 + iVar1);
            iVar8 = iVar8 + 1;
            *(undefined1 *)(iVar5 + iVar1) = uVar3;
          } while (iVar8 < (int)(uVar7 * 4));
        }
      }
    } while( true );
  }
  return 0xffffffff;
}


