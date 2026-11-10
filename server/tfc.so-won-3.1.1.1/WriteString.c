// WriteString__5CSavePCcPCii  @ 00121238
void WriteString__5CSavePCcPCii(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  char *local_8;
  
  local_8 = (char *)0x0;
  iVar6 = 0;
  if (0 < param_4) {
    do {
      iVar1 = iVar6 * 4;
      iVar6 = iVar6 + 1;
      puVar5 = (uint *)(*(int *)(param_3 + iVar1) + *(int *)(gpGlobals + 0x98));
      uVar4 = (uint)puVar5 & 3;
      puVar2 = puVar5;
      if (uVar4 == 0) {
LAB_00121293:
        do {
          puVar3 = puVar2;
          uVar4 = *puVar3;
          if ((char)uVar4 == '\0') goto LAB_001212b5;
          if ((char)(uVar4 >> 8) == '\0') goto LAB_001212b4;
          if ((uVar4 & 0xff0000) == 0) goto LAB_001212b3;
          puVar2 = puVar3 + 1;
        } while ((uVar4 & 0xff000000) != 0);
        puVar3 = (uint *)((int)puVar3 + 1);
LAB_001212b3:
        puVar3 = (uint *)((int)puVar3 + 1);
LAB_001212b4:
        puVar3 = (uint *)((int)puVar3 + 1);
      }
      else {
        puVar3 = puVar5;
        if ((POPCOUNT(uVar4) & 1U) == 0) {
LAB_0012128e:
          if ((char)*puVar3 != '\0') {
            puVar2 = (uint *)((int)puVar3 + 1);
            goto LAB_00121293;
          }
        }
        else if (uVar4 == 2) {
LAB_00121289:
          if ((char)*puVar3 != '\0') {
            puVar3 = (uint *)((int)puVar3 + 1);
            goto LAB_0012128e;
          }
        }
        else if ((char)*puVar5 != '\0') {
          puVar3 = (uint *)((int)puVar5 + 1);
          goto LAB_00121289;
        }
      }
LAB_001212b5:
      local_8 = (char *)((int)puVar3 + (int)(local_8 + (1 - (int)puVar5)));
    } while (iVar6 < param_4);
  }
  BufferHeader__5CSavePCci(param_1,param_2,local_8);
  if (0 < param_4) {
    iVar6 = 0;
    do {
      puVar5 = (uint *)(*(int *)(param_3 + iVar6 * 4) + *(int *)(gpGlobals + 0x98));
      uVar4 = (uint)puVar5 & 3;
      puVar2 = puVar5;
      if (uVar4 == 0) {
LAB_00121313:
        do {
          puVar3 = puVar2;
          uVar4 = *puVar3;
          if ((char)uVar4 == '\0') goto LAB_00121335;
          if ((char)(uVar4 >> 8) == '\0') goto LAB_00121334;
          if ((uVar4 & 0xff0000) == 0) goto LAB_00121333;
          puVar2 = puVar3 + 1;
        } while ((uVar4 & 0xff000000) != 0);
        puVar3 = (uint *)((int)puVar3 + 1);
LAB_00121333:
        puVar3 = (uint *)((int)puVar3 + 1);
LAB_00121334:
        puVar3 = (uint *)((int)puVar3 + 1);
      }
      else {
        puVar3 = puVar5;
        if ((POPCOUNT(uVar4) & 1U) == 0) {
LAB_0012130e:
          if ((char)*puVar3 != '\0') {
            puVar2 = (uint *)((int)puVar3 + 1);
            goto LAB_00121313;
          }
        }
        else if (uVar4 == 2) {
LAB_00121309:
          if ((char)*puVar3 != '\0') {
            puVar3 = (uint *)((int)puVar3 + 1);
            goto LAB_0012130e;
          }
        }
        else if ((char)*puVar5 != '\0') {
          puVar3 = (uint *)((int)puVar5 + 1);
          goto LAB_00121309;
        }
      }
LAB_00121335:
      BufferData__5CSavePCci(param_1,puVar5,(char *)((int)puVar3 + (1 - (int)puVar5)));
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_4);
  }
  return;
}


// WriteString__5CSavePCcT1  @ 00121358
void WriteString__5CSavePCcT1(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_3 & 3;
  puVar1 = param_3;
  if (uVar3 != 0) {
    puVar2 = param_3;
    if ((POPCOUNT(uVar3) & 1U) != 0) {
      if (uVar3 != 2) {
        if ((char)*param_3 == '\0') goto LAB_001213b2;
        puVar2 = (uint *)((int)param_3 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_001213b2;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_001213b2;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_001213b2;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_001213b1;
    if ((uVar3 & 0xff0000) == 0) goto LAB_001213b0;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_001213b0:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_001213b1:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_001213b2:
  BufferField__5CSavePCciT1(param_1,param_2,(char *)((int)puVar2 + (1 - (int)param_3)),param_3);
  return;
}


