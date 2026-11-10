// SZ_Alloc  @ 00058e00
void SZ_Alloc(undefined4 param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  *param_2 = param_1;
  if (param_3 < 0x100) {
    param_3 = 0x100;
  }
  uVar1 = Hunk_AllocName(param_3,param_1);
  param_2[2] = uVar1;
  param_2[3] = param_3;
  param_2[4] = 0;
  *(undefined2 *)(param_2 + 1) = 0;
  return;
}


// SZ_Clear  @ 00058e6c
void SZ_Clear(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(ushort *)(param_1 + 4) = *(ushort *)(param_1 + 4) & 0xfffd;
  return;
}


// SZ_GetSpace  @ 00058e90
int SZ_GetSpace(int *param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  
  if (param_1[3] < param_2 + param_1[4]) {
    if ((*(ushort *)(param_1 + 1) & 1) == 0) {
      if (param_1[3] == 0) {
        puVar2 = (undefined *)*param_1;
        if (*param_1 == 0) {
          puVar2 = &DAT_000e0018;
        }
        Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",puVar2);
      }
      else {
        puVar2 = (undefined *)*param_1;
        if (*param_1 == 0) {
          puVar2 = &DAT_000e0018;
        }
        Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",puVar2);
      }
    }
    if (param_1[3] < param_2) {
      if ((*(ushort *)(param_1 + 1) & 1) == 0) {
        puVar2 = (undefined *)*param_1;
        if (*param_1 == 0) {
          puVar2 = &DAT_000e0018;
        }
        Sys_Error("SZ_GetSpace: %i is > full buffer size on %s",param_2,puVar2);
      }
      else {
        puVar2 = (undefined *)*param_1;
        if (*param_1 == 0) {
          puVar2 = &DAT_000e0018;
        }
        Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",param_2,puVar2);
      }
    }
    puVar2 = (undefined *)*param_1;
    if (*param_1 == 0) {
      puVar2 = &DAT_000e0018;
    }
    Con_Printf("SZ_GetSpace: overflow on %s\n",puVar2);
    SZ_Clear(param_1);
    *(ushort *)(param_1 + 1) = *(ushort *)(param_1 + 1) | 2;
  }
  iVar1 = param_1[4];
  param_1[4] = param_2 + param_1[4];
  return iVar1 + param_1[2];
}


// SZ_Print  @ 00059068
void SZ_Print(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0x59074;
  iVar1 = Q_strlen(param_2);
  iVar3 = iVar1 + 1;
  if (*(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x10) + -1) == '\0') {
    iVar1 = SZ_GetSpace(param_1,iVar1);
    Q_memcpy(iVar1 + -1,param_2,iVar3,uVar4);
  }
  else {
    uVar2 = SZ_GetSpace(param_1,iVar3);
    Q_memcpy(uVar2,param_2,iVar3,uVar4);
  }
  return;
}


// SZ_Write  @ 00059024
void SZ_Write(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0x59030;
  uVar1 = SZ_GetSpace(param_1,param_3);
  Q_memcpy(uVar1,param_2,param_3,uVar2);
  return;
}


