// COM_Log__FPcT0e  @ 00124c50
void COM_Log__FPcT0e(char *param_1,char *param_2)

{
  FILE *__stream;
  char local_404 [1024];
  
  if (param_1 == (char *)0x0) {
    param_1 = "c:\\hllog.txt";
  }
  vsprintf(local_404,param_2,&stack0x0000000c);
  __stream = fopen(param_1,"a+t");
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s",local_404);
    fclose(__stream);
  }
  return;
}


// COM_Parse__FPc  @ 000ae988
char * COM_Parse__FPc(char *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  com_token = '\0';
  if (param_1 == (char *)0x0) {
LAB_000ae9aa:
    param_1 = (char *)0x0;
  }
  else {
    while( true ) {
      for (; cVar1 = *param_1, cVar1 < '!'; param_1 = param_1 + 1) {
        if (cVar1 == '\0') goto LAB_000ae9aa;
      }
      if ((cVar1 != '/') || (param_1[1] != '/')) break;
      for (; (*param_1 != '\0' && (*param_1 != '\n')); param_1 = param_1 + 1) {
      }
    }
    if (cVar1 == '\"') {
      param_1 = param_1 + 1;
      while( true ) {
        cVar1 = *param_1;
        param_1 = param_1 + 1;
        if ((cVar1 == '\"') || (cVar1 == '\0')) break;
        (&com_token)[iVar2] = cVar1;
        iVar2 = iVar2 + 1;
      }
      (&com_token)[iVar2] = 0;
    }
    else {
      com_token = cVar1;
      if (((((cVar1 == '{') || (cVar1 == '}')) || (cVar1 == ')')) ||
          ((cVar1 == '(' || (cVar1 == '\'')))) || (cVar1 == ',')) {
        DAT_0019f081._0_1_ = 0;
        param_1 = param_1 + 1;
      }
      else {
        param_1 = param_1 + 1;
        iVar2 = 1;
        cVar1 = *param_1;
        if (((cVar1 != '{') && (cVar1 != '}')) &&
           ((cVar1 != ')' && (((cVar1 != '(' && (cVar1 != '\'')) && (cVar1 != ',')))))) {
          iVar2 = 1;
          while (' ' < cVar1) {
            (&com_token)[iVar2] = cVar1;
            param_1 = param_1 + 1;
            iVar2 = iVar2 + 1;
            cVar1 = *param_1;
            if ((((cVar1 == '{') || (cVar1 == '}')) ||
                ((cVar1 == ')' || ((cVar1 == '(' || (cVar1 == '\'')))))) || (cVar1 == ',')) break;
          }
        }
        (&com_token)[iVar2] = 0;
      }
    }
  }
  return param_1;
}


// COM_TokenWaiting__FPc  @ 000af5cc
undefined4 COM_TokenWaiting__FPc(char *param_1)

{
  int iVar1;
  
  while( true ) {
    if ((*param_1 == '\0') || (*param_1 == '\n')) {
      return 0;
    }
    iVar1 = isspace((int)*param_1);
    if ((iVar1 == 0) || (iVar1 = isalnum((int)*param_1), iVar1 != 0)) break;
    param_1 = param_1 + 1;
  }
  return 1;
}


