// DL_SharedVarArgs  @ 00182d80
char * DL_SharedVarArgs(char *format,...)

{
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: int BufLen@[???]
                       Unresolved local var: int NumBuffers@[???] */
  DL_SharedVarArgs::lexical_block_0::curstring =
       (DL_SharedVarArgs::lexical_block_0::curstring + 1) % 4;
  vsnprintf(DL_SharedVarArgs::lexical_block_0::string[DL_SharedVarArgs::lexical_block_0::curstring],
            0x400,format,&stack0x00000008);
  return DL_SharedVarArgs::lexical_block_0::string[DL_SharedVarArgs::lexical_block_0::curstring];
}


