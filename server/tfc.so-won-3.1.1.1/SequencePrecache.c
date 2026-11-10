// SequencePrecache__FPvPCc  @ 00087174
void SequencePrecache__FPvPCc(int param_1,char *param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  int local_10;
  
  if (param_1 == 0) {
    iVar8 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xa8);
    iVar8 = 0;
    if (0 < *(int *)(param_1 + 0xa4)) {
      do {
        iVar6 = strcasecmp((char *)(iVar8 * 0xb0 + param_1 + iVar2),param_2);
        if (iVar6 == 0) goto LAB_000871e2;
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)(param_1 + 0xa4));
    }
    iVar8 = -1;
LAB_000871e2:
    if (iVar8 < 0) {
      return;
    }
  }
  if ((param_1 != 0) && (iVar8 < *(int *)(param_1 + 0xa4))) {
    local_10 = 0;
    iVar6 = iVar8 * 0xb0 + param_1 + *(int *)(param_1 + 0xa8);
    iVar2 = param_1 + *(int *)(iVar6 + 0x34);
    iVar8 = *(int *)(iVar6 + 0x30);
    if (0 < iVar8) {
      do {
        iVar3 = *(int *)(iVar2 + 4 + local_10 * 0x4c);
        if ((iVar3 < 5000) && ((iVar3 == 0x3ec || (iVar3 == 0x3f0)))) {
          puVar1 = (uint *)(local_10 * 0x4c + 0xc + iVar2);
          puVar5 = puVar1;
          do {
            puVar7 = puVar5;
            uVar4 = *puVar7;
            if ((char)uVar4 == '\0') goto LAB_0008729a;
            if ((char)(uVar4 >> 8) == '\0') goto LAB_00087299;
            if ((uVar4 & 0xff0000) == 0) goto LAB_00087298;
            puVar5 = puVar7 + 1;
          } while ((uVar4 & 0xff000000) != 0);
          puVar7 = (uint *)((int)puVar7 + 1);
LAB_00087298:
          puVar7 = (uint *)((int)puVar7 + 1);
LAB_00087299:
          puVar7 = (uint *)((int)puVar7 + 1);
LAB_0008729a:
          if (puVar7 == puVar1) {
            (*DAT_0019f794)(4,"Bad sound event %d in sequence %s :: %s (sound is \"%s\")\n",iVar3,
                            param_1 + 8,param_2,puVar1);
          }
          iVar8 = (*DAT_0019f7ac)(puVar1);
          (*DAT_0019f6a4)(iVar8 + *(int *)(gpGlobals + 0x98));
          iVar8 = *(int *)(iVar6 + 0x30);
        }
        local_10 = local_10 + 1;
      } while (local_10 < iVar8);
    }
  }
  return;
}


