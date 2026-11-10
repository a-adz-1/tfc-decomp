// COM_Log__FPcT0e  @ 001121c8
void COM_Log__FPcT0e(char *param_1,char *param_2)

{
  FILE *__stream;
  char local_400 [1024];
  
  if (param_1 == (char *)0x0) {
    param_1 = "c:\\hllog.txt";
  }
  vsprintf(local_400,param_2,&stack0x0000000c);
  __stream = fopen(param_1,"a+t");
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s",local_400);
    fclose(__stream);
  }
  return;
}


// COM_Parse__FPc  @ 000a5144
char * COM_Parse__FPc(char *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  com_token = 0;
  if (param_1 == (char *)0x0) {
    com_token = 0;
    return (char *)0x0;
  }
  while( true ) {
    for (; cVar1 = *param_1, cVar1 < '!'; param_1 = param_1 + 1) {
      if (cVar1 == '\0') {
        com_token = 0;
        return (char *)0x0;
      }
    }
    if ((cVar1 != '/') || (param_1[1] != '/')) break;
    for (; (*param_1 != '\0' && (*param_1 != '\n')); param_1 = param_1 + 1) {
    }
  }
  if (cVar1 == '\"') {
    param_1 = param_1 + 1;
    iVar2 = 0;
    while( true ) {
      cVar1 = *param_1;
      param_1 = param_1 + 1;
      if ((cVar1 == '\"') || (cVar1 == '\0')) break;
      (&com_token)[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    }
  }
  else {
    if ((((cVar1 == '{') || (cVar1 == '}')) || (cVar1 == ')')) ||
       (((cVar1 == '(' || (cVar1 == '\'')) || (cVar1 == ',')))) {
      com_token = cVar1;
      DAT_001a7821 = 0;
      return param_1 + 1;
    }
    while( true ) {
      (&com_token)[iVar2] = cVar1;
      param_1 = param_1 + 1;
      iVar2 = iVar2 + 1;
      cVar1 = *param_1;
      if ((cVar1 == '{') || (cVar1 == '}')) break;
      if ((cVar1 == ')') ||
         ((((cVar1 == '(' || (cVar1 == '\'')) || (cVar1 == ',')) || (cVar1 < '!')))) break;
    }
  }
  (&com_token)[iVar2] = 0;
  return param_1;
}


// COM_TokenWaiting__FPc  @ 000a5224
undefined4 COM_TokenWaiting__FPc(char *param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *param_1;
  while( true ) {
    if ((cVar1 == '\0') || (*param_1 == '\n')) {
      return 0;
    }
    iVar2 = isspace((int)*param_1);
    if ((iVar2 == 0) || (iVar2 = isalnum((int)*param_1), iVar2 != 0)) break;
    param_1 = param_1 + 1;
    cVar1 = *param_1;
  }
  return 1;
}


