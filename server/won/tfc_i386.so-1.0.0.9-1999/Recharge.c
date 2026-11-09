// Recharge__11CWallHealth  @ 000bd220
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Recharge__11CWallHealth(int *param_1)

{
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x1e8),3,"items/medshot4.wav",0x3f800000,0x3f4ccccd,0,100);
  param_1[0x11d] = (int)ROUND(_DAT_00177ac0);
  *(undefined4 *)(*param_1 + 0x110) = 0;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_DoNothing__11CBaseEntity;
  return;
}


// Recharge__9CRecharge  @ 000bae90
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Recharge__9CRecharge(int *param_1)

{
  param_1[0x11d] = (int)ROUND(_DAT_00177ab8);
  *(undefined4 *)(*param_1 + 0x110) = 0;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_DoNothing__11CBaseEntity;
  return;
}


