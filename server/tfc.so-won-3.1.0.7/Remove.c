// Remove__14CQueuePriorityRf  @ 000c8770
int Remove__14CQueuePriorityRf(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[1];
  *param_2 = param_1[2];
  *param_1 = *param_1 + -1;
  iVar2 = param_1[*param_1 * 2 + 2];
  param_1[1] = param_1[*param_1 * 2 + 1];
  param_1[2] = iVar2;
  Heap_SiftDown__14CQueuePriorityi(param_1,0);
  return iVar1;
}


// Remove__6CQueueRf  @ 000c86c4
int Remove__6CQueueRf(int *param_1,int *param_2)

{
  int iVar1;
  
  if (param_1[0xc9] == 100) {
    param_1[0xc9] = 0;
  }
  *param_1 = *param_1 + -1;
  *param_2 = param_1[param_1[0xc9] * 2 + 2];
  iVar1 = param_1[param_1[0xc9] * 2 + 1];
  param_1[0xc9] = param_1[0xc9] + 1;
  return iVar1;
}


