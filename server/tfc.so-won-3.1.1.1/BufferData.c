// BufferData__5CSavePCci  @ 00120e24
void BufferData__5CSavePCci(int *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0xc) < (int)(param_3 + *(int *)(iVar1 + 8))) {
      (*DAT_0019f794)(4,"Save/Restore overflow!");
      *(undefined4 *)(*param_1 + 8) = *(undefined4 *)(*param_1 + 0xc);
    }
    else {
      memcpy(*(void **)(iVar1 + 4),param_2,param_3);
      *(int *)(*param_1 + 4) = *(int *)(*param_1 + 4) + param_3;
      *(int *)(*param_1 + 8) = *(int *)(*param_1 + 8) + param_3;
    }
  }
  return;
}


