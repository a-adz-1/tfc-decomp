// Ghidra decompilation of functions from cl_dll/cl_util.h
// 1 functions, ordered by original source line

// safe_sprintf  @ 00082650  (line 145)

int safe_sprintf(char *dst,int len_dst,char *format,...)

{
  int iVar1;
  
                    /* Unresolved local var: va_list v@[???] */
  if (len_dst < 1) {
    iVar1 = -1;
  }
  else {
    __vsnprintf_chk(dst,len_dst,1,0xffffffff,format,&stack0x00000010);
    iVar1 = 0;
    dst[len_dst + -1] = '\0';
  }
  return iVar1;
}


