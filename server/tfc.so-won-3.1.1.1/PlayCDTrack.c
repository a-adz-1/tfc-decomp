// PlayCDTrack__Fi  @ 0011933c
void PlayCDTrack__Fi(char *param_1)

{
  int iVar1;
  code *pcVar2;
  char **ppcVar3;
  undefined1 *puVar4;
  char *pcStackY_60;
  char *pcStack_54;
  char local_44 [64];
  
  pcStack_54 = (char *)0x1;
  iVar1 = (*DAT_0019f7c0)();
  if (iVar1 != 0) {
    if (param_1 + 1 < (char *)0x20) {
      if (param_1 == (char *)0xffffffff) {
        pcStack_54 = "cd pause\n";
        ppcVar3 = &pcStack_54;
      }
      else {
        pcStack_54 = param_1;
        pcStackY_60 = (char *)0x1193b1;
        sprintf(local_44,"cd play %3d\n");
        ppcVar3 = &pcStackY_60;
        pcStackY_60 = local_44;
      }
      puVar4 = (undefined1 *)((int)ppcVar3 + -4);
      *(int *)((int)ppcVar3 + -4) = iVar1;
      pcVar2 = DAT_0019f744;
    }
    else {
      pcStack_54 = "TriggerCDAudio - Track %d out of range\n";
      puVar4 = &stack0xffffffa8;
      pcVar2 = DAT_0019f794;
    }
    *(undefined4 *)(puVar4 + -4) = 0x1193c1;
    (*pcVar2)();
  }
  return;
}


