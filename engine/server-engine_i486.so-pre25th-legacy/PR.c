// PR_Init  @ 00092040
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PR_Init(void)

{
  return;
}


// PR_IsEmptyString  @ 0008dcf0
qboolean PR_IsEmptyString(char *s)

{
  return (uint)(*s < '!');
}


