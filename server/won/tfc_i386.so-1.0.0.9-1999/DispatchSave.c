// DispatchSave__FP7edict_sP13saverestore_s  @ 000a06c0
void DispatchSave__FP7edict_sP13saverestore_s(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  undefined1 local_8 [4];
  
  if (param_1 == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(param_1 + 0xd8);
  }
  if ((piVar4 != (int *)0x0) && (param_2 != 0)) {
    iVar1 = *(int *)(param_2 + 0x28) + *(int *)(param_2 + 0x1c) * 0x18;
    if (*(int *)(iVar1 + 4) != param_1) {
      (*DAT_001755b4)(4,"ENTITY TABLE OR INDEX IS WRONG!!!!\n");
    }
    iVar3 = (**(code **)(piVar4[0xf2] + 0x1c))(piVar4);
    if (-1 < iVar3) {
      iVar3 = *piVar4;
      if (*(int *)(iVar3 + 0xe8) == 7) {
        fVar2 = *(float *)(iVar3 + 0xe0);
        *(undefined4 *)(iVar3 + 0xe0) = *gpGlobals;
        *(float *)(*piVar4 + 0xe4) = (*(float *)(iVar3 + 0xe4) - fVar2) + *(float *)(*piVar4 + 0xe0)
        ;
      }
      *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_2 + 8);
      *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)*piVar4;
      __18CSaveRestoreBufferP13saverestore_s(local_8,param_2);
      (**(code **)(piVar4[0xf2] + 0x14))(piVar4,local_8);
      *(int *)(iVar1 + 0xc) = *(int *)(param_2 + 8) - *(int *)(iVar1 + 8);
      ___18CSaveRestoreBuffer(local_8,2);
    }
  }
  return;
}


