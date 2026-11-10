// reallocAndCopy__11WriteBufferUl  @ 000cfb38
void reallocAndCopy__11WriteBufferUl(undefined4 *param_1,undefined4 param_2)

{
  void *__src;
  undefined4 uVar1;
  
  __src = (void *)*param_1;
  uVar1 = __builtin_vec_new(param_2);
  *param_1 = uVar1;
  param_1[1] = param_2;
  memcpy((void *)*param_1,__src,param_1[2]);
  if (__src != (void *)0x0) {
    __builtin_vec_delete(__src);
  }
  return;
}


