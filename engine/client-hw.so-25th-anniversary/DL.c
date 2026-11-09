// DL_SharedVarArgs  @ 00126ac0
/* DWARF original prototype: char * DL_SharedVarArgs(char * format, char * format, ...) */

char * DL_SharedVarArgs(char *format,char *format_1,...)

{
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: int BufLen@[???]
                       Unresolved local var: int NumBuffers@[???] */
  DL_SharedVarArgs::curstring = (DL_SharedVarArgs::curstring + 1) % 4;
  __vsnprintf_chk(DL_SharedVarArgs::string + DL_SharedVarArgs::curstring,0x400,1,0xffffffff,0x25e1a0
                  ,&format_1);
  return DL_SharedVarArgs::string[DL_SharedVarArgs::curstring];
}


