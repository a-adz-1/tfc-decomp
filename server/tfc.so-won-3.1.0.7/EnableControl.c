// EnableControl__11CBasePlayeri  @ 000de8bc
void EnableControl__11CBasePlayeri(int *param_1,int param_2)

{
  if (param_2 == 0) {
    *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) | 0x10;
  }
  else {
    *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xef;
  }
  return;
}


