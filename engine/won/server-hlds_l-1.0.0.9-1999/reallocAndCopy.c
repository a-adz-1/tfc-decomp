// reallocAndCopy__11WriteBufferUl  @ 08090ab0
void reallocAndCopy__11WriteBufferUl(int *param_1,uint param_2)

{
  void *__src;
  int iVar1;
  
  if (param_2 <= (uint)param_1[2]) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("theNewSize>mWritePos","/e/quiver/goldsrc/common/WriteBuffer.cpp",0xab,
                  "void WriteBuffer::reallocAndCopy(long unsigned int)");
  }
  __src = (void *)*param_1;
  iVar1 = __builtin_vec_new(param_2);
  *param_1 = iVar1;
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("mBuffer","/e/quiver/goldsrc/common/WriteBuffer.cpp",0xb0,
                  "void WriteBuffer::reallocAndCopy(long unsigned int)");
  }
  param_1[1] = param_2;
  memcpy((void *)*param_1,__src,param_1[2]);
  if (__src != (void *)0x0) {
    __builtin_vec_delete(__src);
  }
  return;
}


