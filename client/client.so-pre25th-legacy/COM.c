// COM_FileBase  @ 000834c0
void COM_FileBase(char *in,char *out)

{
  size_t sVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int start@[???]
                       Unresolved local var: int end@[???] */
  sVar1 = strlen(in);
  iVar2 = sVar1 - 1;
  iVar5 = iVar2;
  if (iVar2 == 0) {
    cVar3 = *in;
    cVar4 = cVar3;
LAB_000834de:
    if (cVar4 == '.') {
      iVar6 = 0;
      goto LAB_00083580;
    }
  }
  else {
    cVar3 = in[iVar2];
    iVar6 = iVar2;
    cVar4 = cVar3;
    while (cVar4 != '.') {
      if ((cVar4 == '/') || (cVar4 == '\\')) goto LAB_000834f2;
      iVar6 = iVar6 + -1;
      if (iVar6 == 0) {
        cVar4 = *in;
        goto LAB_000834de;
      }
      cVar4 = in[iVar6];
    }
LAB_00083580:
    iVar5 = iVar6 + -1;
  }
LAB_000834f2:
  if (iVar2 < 0) {
LAB_00083544:
    if ((cVar3 != '\\') && (cVar3 != '/')) {
      iVar2 = 0;
      goto LAB_00083503;
    }
  }
  else {
    while ((cVar3 != '/' && (cVar3 != '\\'))) {
      iVar2 = iVar2 + -1;
      if (iVar2 == -1) {
        cVar3 = in[-1];
        goto LAB_00083544;
      }
      cVar3 = in[iVar2];
    }
  }
  iVar2 = iVar2 + 1;
LAB_00083503:
  sVar1 = (iVar5 - iVar2) + 1;
  strncpy(out,in + iVar2,sVar1);
  out[sVar1] = '\0';
  return;
}


// COM_Log  @ 0008bdf0
void COM_Log(char *pszFile,char *fmt,...)

{
  FILE *__stream;
  char *__filename;
  char local_40c [1028];
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: char[1024] string@[???]
                       Unresolved local var: FILE * fp@[???]
                       Unresolved local var: char * pfilename@[???] */
  __filename = "c:\\hllog.txt";
  if (pszFile != (char *)0x0) {
    __filename = pszFile;
  }
  vsprintf(local_40c,fmt,&stack0x0000000c);
  __stream = fopen(__filename,"a+t");
  if (__stream != (FILE *)0x0) {
    fputs(local_40c,__stream);
    fclose(__stream);
  }
  return;
}


