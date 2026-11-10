// reallocAndCopy__11WriteBufferUl  @ 000975ec
void reallocAndCopy__11WriteBufferUl(undefined4 *param_1,uint param_2)

{
  void *__src;
  void *__dest;
  
  if (param_2 <= (uint)param_1[2]) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("theNewSize>mWritePos","/home/jihad/valve/goldsrc/utils/crypt/won/WriteBuffer.cpp"
                  ,0xad,"void WriteBuffer::reallocAndCopy(long unsigned int)");
  }
  __src = (void *)*param_1;
  __dest = (void *)__builtin_vec_new(param_2);
  *param_1 = __dest;
  if (__dest == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("mBuffer","/home/jihad/valve/goldsrc/utils/crypt/won/WriteBuffer.cpp",0xb2,
                  "void WriteBuffer::reallocAndCopy(long unsigned int)");
  }
  param_1[1] = param_2;
  memcpy(__dest,__src,param_1[2]);
  if (__src != (void *)0x0) {
    __builtin_vec_delete(__src);
  }
  return;
}


