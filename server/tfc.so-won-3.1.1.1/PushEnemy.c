// PushEnemy__12CBaseMonsterP11CBaseEntityR6Vector  @ 000c2758
void PushEnemy__12CBaseMonsterP11CBaseEntityR6Vector(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 != 0) {
    iVar3 = 0;
    do {
      iVar2 = param_1 + 0x50c + iVar3 * 8;
      iVar1 = __opP11CBaseEntity__7EHANDLE(iVar2);
      if (iVar1 == param_2) {
        return;
      }
      iVar2 = __opP11CBaseEntity__7EHANDLE(iVar2);
    } while ((iVar2 != 0) && (iVar3 = iVar3 + 1, iVar3 < 4));
    if (iVar3 < 4) {
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x50c + iVar3 * 8,param_2);
      param_1 = param_1 + iVar3 * 0xc;
      *(undefined4 *)(param_1 + 0x52c) = *param_3;
      *(undefined4 *)(param_1 + 0x530) = param_3[1];
      *(undefined4 *)(param_1 + 0x534) = param_3[2];
    }
  }
  return;
}


