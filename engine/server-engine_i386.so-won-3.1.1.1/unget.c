// unget__7istream  @ 00052ca0
int * unget__7istream(int *param_1)

{
  int iVar1;
  
  if (*(char *)(*param_1 + 0x12) == '\0') {
    iVar1 = sungetc__9streambuf(*(undefined4 *)*param_1);
    if (iVar1 == -1) {
      *(undefined1 *)(*param_1 + 0x12) = 4;
    }
  }
  return param_1;
}


// unget__7istreamc  @ 00052cd4
int * unget__7istreamc(int *param_1,char param_2)

{
  int iVar1;
  
  if (*(char *)(*param_1 + 0x12) == '\0') {
    iVar1 = sputbackc__9streambufc(*(undefined4 *)*param_1,(int)param_2);
    if (iVar1 == -1) {
      *(undefined1 *)(*param_1 + 0x12) = 4;
    }
  }
  return param_1;
}


