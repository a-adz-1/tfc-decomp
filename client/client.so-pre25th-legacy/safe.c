// safe_sprintf  @ 000a7140
int safe_sprintf(char *dst,int len_dst,char *format,...)

{
  int iVar1;
  
                    /* Unresolved local var: va_list v@[???] */
  iVar1 = -1;
  if (0 < len_dst) {
    vsnprintf(dst,len_dst,format,&stack0x00000010);
    iVar1 = 0;
    dst[len_dst + -1] = '\0';
  }
  return iVar1;
}


