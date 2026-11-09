// CD_Command_f  @ 001bf690
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CD_Command_f(void)

{
  int iVar1;
  CCDAudio *in_stack_00000004;
  
                    /* Unresolved local var: char * command@[???]
                       Unresolved local var: int ret@[???]
                       Unresolved local var: int n@[???] */
  iVar1 = Cmd_Argc();
  if (1 < iVar1) {
    CCDAudio::CD_f(in_stack_00000004);
    return;
  }
  return;
}


