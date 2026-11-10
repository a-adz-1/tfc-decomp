// IsFollowing__12CTalkMonster  @ 000f33c0
bool IsFollowing__12CTalkMonster(int param_1)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  
  bVar3 = false;
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x478);
  if (iVar1 != 0) {
    piVar2 = (int *)__rf__7EHANDLE(param_1 + 0x478);
    bVar3 = (*(byte *)(*piVar2 + 0x184) & 8) != 0;
  }
  return bVar3;
}


