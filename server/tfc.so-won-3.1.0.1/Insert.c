// Insert__14CQueuePriorityif  @ 000bd438
void Insert__14CQueuePriorityif(int *param_1,int param_2,int param_3)

{
  if (*param_1 == 100) {
    printf("Queue is full!\n");
  }
  else {
    param_1[*param_1 * 2 + 2] = param_3;
    param_1[*param_1 * 2 + 1] = param_2;
    *param_1 = *param_1 + 1;
    Heap_SiftUp__14CQueuePriority(param_1);
  }
  return;
}


// Insert__6CQueueif  @ 000bd374
void Insert__6CQueueif(int *param_1,int param_2,int param_3)

{
  if (*param_1 == 100) {
    printf("Queue is full!\n");
  }
  else {
    param_1[0xca] = param_1[0xca] + 1;
    if (param_1[0xca] == 100) {
      param_1[0xca] = 0;
    }
    param_1[param_1[0xca] * 2 + 1] = param_2;
    param_1[param_1[0xca] * 2 + 2] = param_3;
    *param_1 = *param_1 + 1;
  }
  return;
}


