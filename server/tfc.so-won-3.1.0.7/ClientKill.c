// ClientKill__FP7edict_s  @ 0008fab0
void ClientKill__FP7edict_s(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(param_1 + 0x288);
  if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(iVar1 + 0x7c);
  }
  if (*(int *)(param_1 + 0x28c) != 0) {
    if (*(float *)(iVar1 + 0x6ec) <= *gpGlobals) {
      *(float *)(iVar1 + 0x6ec) = *gpGlobals + 5.0;
      *(undefined4 *)(param_1 + 0x1e0) = 0;
      if (((*(byte *)(iVar1 + 0x84) & 0x10) != 0) &&
         (piVar2 = (int *)FindTimer__11CBaseEntityi(iVar1,2), piVar2 != (int *)0x0)) {
        iVar3 = *(int *)(*piVar2 + 400);
        if ((iVar3 == 0) && (iVar3 = (*DAT_001c1134)(0), iVar3 == 0)) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(undefined4 *)(iVar3 + 0x7c);
        }
        TF_AddFrags__11CBasePlayeri(uVar4,1);
      }
      (**(code **)(*(int *)(iVar1 + 0x444) + 0x40))(iVar1,0,param_1 + 0x80,1);
      return;
    }
    return;
  }
  return;
}


