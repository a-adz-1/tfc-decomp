// setBuf__11WriteBufferUlPCvUl  @ 08090c40
void setBuf__11WriteBufferUlPCvUl(int *param_1,int param_2,void *param_3,size_t param_4)

{
  if ((uint)param_1[1] < param_4 + param_2) {
    reallocAndCopy__11WriteBufferUl(param_1,(param_4 + param_2) * 2);
  }
  memcpy((void *)(param_2 + *param_1),param_3,param_4);
  return;
}


