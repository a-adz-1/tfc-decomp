// BufferSkipZString__8CRestore  @ 001206d8
int BufferSkipZString__8CRestore(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  
  piVar2 = (int *)*param_1;
  if (piVar2 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    pcVar4 = (char *)piVar2[1];
    for (iVar3 = 0;
        (cVar1 = *pcVar4, pcVar4 = pcVar4 + 1, cVar1 != '\0' && (iVar3 < piVar2[3] - piVar2[2]));
        iVar3 = iVar3 + 1) {
    }
    iVar3 = iVar3 + 1;
    if (piVar2 != (int *)0x0) {
      if (piVar2[1] - *piVar2 < piVar2[3]) {
        if (piVar2[3] < iVar3 + piVar2[2]) {
          (*DAT_0019f794)(4,"Restore overflow!");
          *(undefined4 *)(*param_1 + 8) = *(undefined4 *)(*param_1 + 0xc);
        }
        else {
          piVar2[1] = piVar2[1] + iVar3;
          *(int *)(*param_1 + 8) = *(int *)(*param_1 + 8) + iVar3;
        }
      }
    }
  }
  return iVar3;
}


