// getNewDescriptor__10EasySocket  @ 0808e110
undefined4 getNewDescriptor__10EasySocket(int *param_1)

{
  int iVar1;
  int __protocol;
  
  iVar1 = isInvalid__10EasySocket(param_1);
  if (iVar1 == 0) {
    close__10EasySocket(param_1);
  }
  iVar1 = param_1[1];
  if (iVar1 != 1) {
    if (iVar1 < 2) {
      if (iVar1 == 0) {
        return 0x3e9;
      }
    }
    else if (iVar1 == 2) {
      __protocol = 0x11;
      iVar1 = 2;
      goto LAB_0808e174;
    }
                    /* WARNING: Subroutine does not return */
    __assert_fail("0","/e/quiver/goldsrc/common/EasySocket.cpp",0x20b,
                  "enum ES_ErrorType EasySocket::getNewDescriptor()");
  }
  __protocol = 6;
  iVar1 = 1;
LAB_0808e174:
  iVar1 = socket(2,iVar1,__protocol);
  *param_1 = iVar1;
  return 0;
}


