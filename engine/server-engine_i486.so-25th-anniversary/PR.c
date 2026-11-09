// PR_Init  @ 000753d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PR_Init(void)

{
  return;
}


// PR_IsEmptyString  @ 00070870
qboolean PR_IsEmptyString(char *s)

{
  return (uint)(*s < '!');
}


