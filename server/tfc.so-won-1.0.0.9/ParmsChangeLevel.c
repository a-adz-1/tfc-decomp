// ParmsChangeLevel__Fv  @ 000a3310
void ParmsChangeLevel__Fv(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(gpGlobals + 0x9c);
  if (iVar1 != 0) {
    uVar2 = BuildChangeList__FP9LEVELLISTi(iVar1 + 0x2c,0x10);
    *(undefined4 *)(iVar1 + 0x24) = uVar2;
  }
  return;
}


