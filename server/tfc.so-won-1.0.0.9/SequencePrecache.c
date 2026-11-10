// SequencePrecache__FPvPCc  @ 0009acb0
void SequencePrecache__FPvPCc(int param_1,undefined4 param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  
  iVar3 = LookupSequence__FPvPCc(param_1,param_2);
  if (((-1 < iVar3) && (param_1 != 0)) && (iVar3 < *(int *)(param_1 + 0xa4))) {
    iVar6 = param_1 + *(int *)(param_1 + 0xa8) + iVar3 * 0xb0;
    iVar3 = param_1 + *(int *)(iVar6 + 0x34);
    iVar7 = 0;
    if (0 < *(int *)(iVar6 + 0x30)) {
      do {
        iVar5 = iVar7 * 0x4c;
        if (*(int *)(iVar3 + 4 + iVar5) < 5000) {
          iVar4 = IsSoundEvent__Fi(*(undefined4 *)(iVar3 + 4 + iVar5));
          if (iVar4 != 0) {
            pcVar1 = (char *)(iVar5 + 0xc + iVar3);
            iVar4 = -1;
            pcVar8 = pcVar1;
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              cVar2 = *pcVar8;
              pcVar8 = pcVar8 + 1;
            } while (cVar2 != '\0');
            if (iVar4 == -2) {
              (*DAT_001755b4)(4,"Bad sound event %d in sequence %s :: %s (sound is \"%s\")\n",
                              *(undefined4 *)(iVar3 + 4 + iVar5),param_1 + 8,param_2,pcVar1);
            }
            iVar5 = (*DAT_001755cc)(iVar3 + 0xc + iVar7 * 0x4c);
            (*DAT_001754c4)(iVar5 + *(int *)(gpGlobals + 0x98));
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < *(int *)(iVar6 + 0x30));
    }
  }
  return;
}


