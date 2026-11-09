// PR_CheckEmptyString  @ 0806d9e0
void PR_CheckEmptyString(char *param_1)

{
  if (*param_1 < '!') {
    Host_Error("Bad string: %s",param_1);
  }
  return;
}


// PR_Init  @ 0806fe30
void PR_Init(void)

{
  return;
}


