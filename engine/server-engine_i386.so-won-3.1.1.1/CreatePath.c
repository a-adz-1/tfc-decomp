// CreatePath__11AuthRequestPc  @ 000d499c
void CreatePath__11AuthRequestPc(undefined4 param_1,char *param_2)

{
  char cVar1;
  char *local_8;
  
  local_8 = param_2;
  while (local_8 = local_8 + 1, *local_8 != '\0') {
    if ((*local_8 == '/') || (*local_8 == '\\')) {
      cVar1 = *local_8;
      *local_8 = '\0';
      mkdir(param_2,0x1ff);
      *local_8 = cVar1;
    }
  }
  return;
}


