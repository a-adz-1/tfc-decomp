// InitGraph__6CGraph  @ 000cb938
void InitGraph__6CGraph(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  if ((void *)param_1[4] != (void *)0x0) {
    free((void *)param_1[4]);
    param_1[4] = 0;
  }
  if ((void *)param_1[3] != (void *)0x0) {
    free((void *)param_1[3]);
    param_1[3] = 0;
  }
  if ((void *)param_1[9] != (void *)0x0) {
    free((void *)param_1[9]);
    param_1[9] = 0;
  }
  if ((void *)param_1[5] != (void *)0x0) {
    free((void *)param_1[5]);
    param_1[5] = 0;
  }
  if ((void *)param_1[0x82f] != (void *)0x0) {
    free((void *)param_1[0x82f]);
    param_1[0x82f] = 0;
  }
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[0x831] = 0;
  param_1[0x832] = 0;
  return;
}


