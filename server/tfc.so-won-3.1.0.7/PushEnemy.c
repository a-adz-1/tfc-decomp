// PushEnemy__12CBaseMonsterP11CBaseEntityR6Vector  @ 000bba80
void PushEnemy__12CBaseMonsterP11CBaseEntityR6Vector(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 != 0) {
    uVar2 = 0;
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4fc);
    if (iVar1 != param_2) {
      iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4fc);
      if (iVar1 != 0) {
        uVar2 = 1;
        iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x504);
        if (iVar1 == param_2) {
          return;
        }
        iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x504);
        if (iVar1 != 0) {
          uVar2 = 2;
          iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x50c);
          if (iVar1 == param_2) {
            return;
          }
          iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x50c);
          if (iVar1 != 0) {
            uVar2 = 3;
            iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x514);
            if (iVar1 == param_2) {
              return;
            }
            iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x514);
            if (iVar1 != 0) {
              uVar2 = 4;
            }
          }
        }
      }
      if (uVar2 < 4) {
        __as__7EHANDLEP11CBaseEntity(param_1 + 0x4fc + uVar2 * 8,param_2);
        param_1 = param_1 + uVar2 * 0xc;
        *(undefined4 *)(param_1 + 0x51c) = *param_3;
        *(undefined4 *)(param_1 + 0x520) = param_3[1];
        *(undefined4 *)(param_1 + 0x524) = param_3[2];
      }
    }
  }
  return;
}


