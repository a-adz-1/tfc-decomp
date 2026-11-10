// SequencePrecache__FPvPCc  @ 0007f8b0
void SequencePrecache__FPvPCc(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  char *local_10;
  int local_c;
  
  iVar2 = LookupSequence__FPvPCc(param_1,param_2);
  if (((-1 < iVar2) && (param_1 != 0)) && (iVar2 < *(int *)(param_1 + 0xa4))) {
    iVar2 = param_1 + *(int *)(param_1 + 0xa8) + iVar2 * 0xb0;
    iVar3 = param_1 + *(int *)(iVar2 + 0x34);
    local_c = 0;
    if (0 < *(int *)(iVar2 + 0x30)) {
      local_10 = (char *)(iVar3 + 0xc);
      piVar4 = (int *)(iVar3 + 4);
      do {
        if (*piVar4 < 5000) {
          iVar3 = IsSoundEvent__Fi(*piVar4);
          if (iVar3 != 0) {
            iVar3 = -1;
            pcVar5 = local_10;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            if (iVar3 == -2) {
              (*DAT_001a7f34)(4,"Bad sound event %d in sequence %s :: %s (sound is \"%s\")\n",
                              *piVar4,param_1 + 8,param_2,local_10);
            }
            iVar3 = (*DAT_001a7f4c)(local_10);
            (*DAT_001a7e44)(iVar3 + *(int *)(gpGlobals + 0x98));
          }
        }
        local_10 = local_10 + 0x4c;
        piVar4 = piVar4 + 0x13;
        local_c = local_c + 1;
      } while (local_c < *(int *)(iVar2 + 0x30));
    }
  }
  return;
}


