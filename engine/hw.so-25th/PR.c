// PR_Init  @ 000d5890
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PR_Init(void)

{
  return;
}


// PR_IsEmptyString  @ 000d0d30
qboolean PR_IsEmptyString(char *s)

{
  return (uint)(*s < '!');
}


