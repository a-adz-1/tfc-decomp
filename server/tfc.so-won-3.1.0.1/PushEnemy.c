// PushEnemy__12CBaseMonsterP11CBaseEntityR6Vector  @ 000b0820
void PushEnemy__12CBaseMonsterP11CBaseEntityR6Vector(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 != 0) {
    uVar2 = 0;
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x48c);
    if (iVar1 != param_2) {
      iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x48c);
      if (iVar1 != 0) {
        uVar2 = 1;
        iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x494);
        if (iVar1 == param_2) {
          return;
        }
        iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x494);
        if (iVar1 != 0) {
          uVar2 = 2;
          iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x49c);
          if (iVar1 == param_2) {
            return;
          }
          iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x49c);
          if (iVar1 != 0) {
            uVar2 = 3;
            iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4a4);
            if (iVar1 == param_2) {
              return;
            }
            iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4a4);
            if (iVar1 != 0) {
              uVar2 = 4;
            }
          }
        }
      }
      if (uVar2 < 4) {
        __as__7EHANDLEP11CBaseEntity(param_1 + 0x48c + uVar2 * 8,param_2);
        param_1 = param_1 + uVar2 * 0xc;
        *(undefined4 *)(param_1 + 0x4ac) = *param_3;
        *(undefined4 *)(param_1 + 0x4b0) = param_3[1];
        *(undefined4 *)(param_1 + 0x4b4) = param_3[2];
      }
    }
  }
  return;
}


