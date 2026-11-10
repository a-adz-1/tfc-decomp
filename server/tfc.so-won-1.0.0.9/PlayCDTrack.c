// PlayCDTrack__Fi  @ 00110110
void PlayCDTrack__Fi(char *param_1)

{
  int iVar1;
  code *pcVar2;
  char **ppcVar3;
  undefined1 *puVar4;
  char *pcStackY_5c;
  char *pcStack_50;
  char local_44 [64];
  
  pcStack_50 = (char *)0x1;
  iVar1 = (*DAT_001755e0)();
  if (iVar1 != 0) {
    if (param_1 + 1 < (char *)0x20) {
      if (param_1 == (char *)0xffffffff) {
        ppcVar3 = &pcStack_50;
        pcStack_50 = "cd pause\n";
      }
      else {
        pcStack_50 = param_1;
        pcStackY_5c = (char *)0x11016f;
        sprintf(local_44,"cd play %3d\n");
        ppcVar3 = &pcStackY_5c;
        pcStackY_5c = local_44;
      }
      puVar4 = (undefined1 *)((int)ppcVar3 + -4);
      *(int *)((int)ppcVar3 + -4) = iVar1;
      pcVar2 = DAT_00175564;
    }
    else {
      pcStack_50 = "TriggerCDAudio - Track %d out of range\n";
      puVar4 = &stack0xffffffac;
      pcVar2 = DAT_001755b4;
    }
    *(undefined4 *)(puVar4 + -4) = 0x110178;
    (*pcVar2)();
  }
  return;
}


