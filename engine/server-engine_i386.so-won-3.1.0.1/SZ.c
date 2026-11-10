// SZ_Alloc  @ 0004b1c4
void SZ_Alloc(undefined2 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0x100) {
    param_2 = 0x100;
  }
  uVar1 = Hunk_AllocName(param_2,"sizebuf");
  *(undefined4 *)(param_1 + 2) = uVar1;
  *(int *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 6) = 0;
  *param_1 = 0;
  return;
}


// SZ_Clear  @ 0004b214
void SZ_Clear(byte *param_1)

{
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  *param_1 = *param_1 & 0xfd;
  return;
}


// SZ_GetSpace  @ 0004b228
int SZ_GetSpace(byte *param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0xc);
  iVar3 = *(int *)(param_1 + 8);
  if (iVar3 < param_2 + iVar2) {
    if ((*param_1 & 1) == 0) {
      if (iVar3 == 0) {
        pcVar1 = "SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t";
      }
      else {
        pcVar1 = "SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set";
      }
      Sys_Error(pcVar1);
      iVar3 = *(int *)(param_1 + 8);
    }
    if (iVar3 < param_2) {
      Sys_Error("SZ_GetSpace: %i is > full buffer size",param_2);
    }
    Con_Printf("SZ_GetSpace: overflow\n");
    SZ_Clear(param_1);
    *param_1 = *param_1 | 2;
    iVar2 = *(int *)(param_1 + 0xc);
  }
  *(int *)(param_1 + 0xc) = iVar2 + param_2;
  return iVar2 + *(int *)(param_1 + 4);
}


// SZ_Print  @ 0004b2e8
void SZ_Print(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = Q_strlen(param_2);
  iVar2 = iVar1 + 1;
  if (*(char *)(*(int *)(param_1 + 4) + -1 + *(int *)(param_1 + 0xc)) == '\0') {
    iVar2 = SZ_GetSpace(param_1,iVar1,param_2,iVar2);
    iVar2 = iVar2 + -1;
  }
  else {
    iVar2 = SZ_GetSpace(param_1,iVar2,param_2,iVar2);
  }
  Q_memcpy(iVar2);
  return;
}


// SZ_Write  @ 0004b2b4
void SZ_Write(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = SZ_GetSpace(param_1,param_3,param_2,param_3);
  Q_memcpy(uVar1);
  return;
}


