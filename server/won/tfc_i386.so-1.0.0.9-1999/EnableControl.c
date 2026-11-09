// EnableControl__11CBasePlayeri  @ 000df6b0
void EnableControl__11CBasePlayeri(int *param_1,int param_2)

{
  if (param_2 == 0) {
    *(byte *)(*param_1 + 0x185) = *(byte *)(*param_1 + 0x185) | 0x10;
  }
  else {
    *(byte *)(*param_1 + 0x185) = *(byte *)(*param_1 + 0x185) & 0xef;
  }
  return;
}


