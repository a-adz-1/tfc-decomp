// NodeType__6CGraphPC11CBaseEntity  @ 000b8c6c
undefined4 NodeType__6CGraphPC11CBaseEntity(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(*param_2 + 0x108) == 5) {
    if (*(int *)(*param_2 + 0x1c0) == 0) {
      uVar1 = 2;
    }
    else {
      uVar1 = 4;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


