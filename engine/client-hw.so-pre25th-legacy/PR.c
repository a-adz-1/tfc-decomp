// PR_Init  @ 00139340
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PR_Init(void)

{
  return;
}


// PR_IsEmptyString  @ 00134ff0
qboolean PR_IsEmptyString(char *s)

{
  return (uint)(*s < '!');
}


