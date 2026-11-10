// IsFollowing__12CTalkMonster  @ 000ea1a8
bool IsFollowing__12CTalkMonster(int param_1)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  
  bVar3 = false;
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x484);
  if (iVar1 != 0) {
    piVar2 = (int *)__rf__7EHANDLE(param_1 + 0x484);
    bVar3 = (*(byte *)(*piVar2 + 0x1a4) & 8) != 0;
  }
  return bVar3;
}


