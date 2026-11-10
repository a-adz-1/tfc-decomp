// SZ_Alloc  @ 0804fca0
void SZ_Alloc(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0x100) {
    param_2 = 0x100;
  }
  uVar1 = Hunk_AllocName(param_2,"sizebuf");
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(int *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


// SZ_Clear  @ 0804fce0
void SZ_Clear(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


// SZ_GetSpace  @ 0804fd00
int SZ_GetSpace(int *param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_1[3] < param_2 + param_1[4]) {
    if (*param_1 == 0) {
      if (param_1[3] == 0) {
        pcVar2 = "SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t";
      }
      else {
        pcVar2 = "SZ_GetSpace: overflow without allowoverflow set";
      }
      Sys_Error(pcVar2);
    }
    if (param_1[3] < param_2) {
      Sys_Error("SZ_GetSpace: %i is > full buffer size",param_2);
    }
    Con_Printf("SZ_GetSpace: overflow\n");
    SZ_Clear(param_1);
    param_1[1] = 1;
  }
  iVar1 = param_1[4];
  param_1[4] = param_2 + iVar1;
  return param_1[2] + iVar1;
}


// SZ_Print  @ 0804fdb0
void SZ_Print(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = Q_strlen(param_2);
  iVar2 = iVar1 + 1;
  if (*(char *)(*(int *)(param_1 + 8) + -1 + *(int *)(param_1 + 0x10)) == '\0') {
    iVar2 = SZ_GetSpace(param_1,iVar1,param_2,iVar2);
    iVar2 = iVar2 + -1;
  }
  else {
    iVar2 = SZ_GetSpace(param_1,iVar2,param_2,iVar2);
  }
  Q_memcpy(iVar2);
  return;
}


// SZ_Write  @ 0804fd80
void SZ_Write(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = SZ_GetSpace(param_1,param_3,param_2,param_3);
  Q_memcpy(uVar1);
  return;
}


