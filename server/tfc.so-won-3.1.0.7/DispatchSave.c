// DispatchSave__FP7edict_sP13saverestore_s  @ 0008dfac
void DispatchSave__FP7edict_sP13saverestore_s(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  undefined1 local_4 [4];
  
  piVar4 = (int *)0x0;
  if (param_1 != 0) {
    piVar4 = *(int **)(param_1 + 0x7c);
  }
  if ((piVar4 != (int *)0x0) && (param_2 != 0)) {
    iVar1 = *(int *)(param_2 + 0x28) + *(int *)(param_2 + 0x1c) * 0x18;
    if (*(int *)(iVar1 + 4) != param_1) {
      (*DAT_001c1114)(4,"ENTITY TABLE OR INDEX IS WRONG!!!!\n");
    }
    iVar3 = (**(code **)(piVar4[0x111] + 0x20))(piVar4);
    if (-1 < iVar3) {
      iVar3 = *piVar4;
      if (*(int *)(iVar3 + 0x108) == 7) {
        fVar2 = *(float *)(iVar3 + 0x100);
        *(undefined4 *)(iVar3 + 0x100) = *gpGlobals;
        *(float *)(*piVar4 + 0x104) =
             (*(float *)(iVar3 + 0x104) - fVar2) + *(float *)(*piVar4 + 0x100);
      }
      *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_2 + 8);
      *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)*piVar4;
      __18CSaveRestoreBufferP13saverestore_s(local_4,param_2);
      (**(code **)(piVar4[0x111] + 0x18))(piVar4,local_4);
      *(int *)(iVar1 + 0xc) = *(int *)(param_2 + 8) - *(int *)(iVar1 + 8);
      ___18CSaveRestoreBuffer(local_4,2);
    }
  }
  return;
}


