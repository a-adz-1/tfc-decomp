// BufferData__5CSavePCci  @ 0011dfac
void BufferData__5CSavePCci(int *param_1,void *param_2,size_t param_3)

{
  if (*param_1 != 0) {
    if (*(int *)(*param_1 + 0xc) < (int)(param_3 + *(int *)(*param_1 + 8))) {
      (*DAT_001c1114)(4,"Save/Restore overflow!");
      *(undefined4 *)(*param_1 + 8) = *(undefined4 *)(*param_1 + 0xc);
    }
    else {
      memcpy(*(void **)(*param_1 + 4),param_2,param_3);
      *(int *)(*param_1 + 4) = *(int *)(*param_1 + 4) + param_3;
      *(int *)(*param_1 + 8) = *(int *)(*param_1 + 8) + param_3;
    }
  }
  return;
}


