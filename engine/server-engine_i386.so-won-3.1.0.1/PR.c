// PR_CheckEmptyString  @ 0006dfcc
void PR_CheckEmptyString(char *param_1)

{
  if (*param_1 < '!') {
    Host_Error("Bad string: %s",param_1);
  }
  return;
}


// PR_Init  @ 00071b70
void PR_Init(void)

{
  return;
}


