// DelayedUse  @ 000f0630
void DelayedUse(undefined4 param_1)

{
  GetClassPtr__H1Z10CBaseDelay_PX01_PX01(param_1);
  return;
}


// GetEntityAPI  @ 000a02e0
undefined4 GetEntityAPI(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined **ppuVar3;
  
  if ((param_1 == (undefined4 *)0x0) || (param_2 != 0x8a)) {
    uVar1 = 0;
  }
  else {
    ppuVar3 = &gFunctionTable;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_1 = *ppuVar3;
      ppuVar3 = ppuVar3 + 1;
      param_1 = param_1 + 1;
    }
    uVar1 = 1;
  }
  return uVar1;
}


// GiveFnptrsToDll  @ 000bc4e0
void GiveFnptrsToDll(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &g_engfuncs;
  for (iVar1 = 0x75; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  gpGlobals = param_2;
  return;
}


// beam  @ 000ab620
void beam(undefined4 param_1)

{
  GetClassPtr__H1Z5CBeam_PX01_PX01(param_1);
  return;
}


// bodyque  @ 0011d050
void bodyque(undefined4 param_1)

{
  GetClassPtr__H1Z7CCorpse_PX01_PX01(param_1);
  return;
}


// cycler  @ 000bb6c0
void cycler(undefined4 param_1)

{
  GetClassPtr__H1Z14CGenericCycler_PX01_PX01(param_1);
  return;
}


// detpack  @ 000a74a0
void detpack(undefined4 param_1)

{
  GetClassPtr__H1Z8CDetpack_PX01_PX01(param_1);
  return;
}


// entry  @ 0009a640
void processEntry entry(void)

{
  return;
}


// fireanddie  @ 00110e40
void fireanddie(undefined4 param_1)

{
  GetClassPtr__H1Z11CFireAndDie_PX01_PX01(param_1);
  return;
}


// ghost  @ 000f4400
void ghost(undefined4 param_1)

{
  GetClassPtr__H1Z6CGhost_PX01_PX01(param_1);
  return;
}


// gibshooter  @ 000ae590
void gibshooter(undefined4 param_1)

{
  GetClassPtr__H1Z11CGibShooter_PX01_PX01(param_1);
  return;
}


// grenade  @ 000b8c60
void grenade(undefined4 param_1)

{
  GetClassPtr__H1Z8CGrenade_PX01_PX01(param_1);
  return;
}


// infodecal  @ 0011ccd0
void infodecal(undefined4 param_1)

{
  GetClassPtr__H1Z6CDecal_PX01_PX01(param_1);
  return;
}


// light  @ 000bd990
void light(undefined4 param_1)

{
  GetClassPtr__H1Z6CLight_PX01_PX01(param_1);
  return;
}


// multisource  @ 0009d7e0
void multisource(undefined4 param_1)

{
  GetClassPtr__H1Z12CMultiSource_PX01_PX01(param_1);
  return;
}


// player  @ 000d5fb0
void player(undefined4 param_1)

{
  GetClassPtr__H1Z11CBasePlayer_PX01_PX01(param_1);
  return;
}


// soundent  @ 000edf20
void soundent(undefined4 param_1)

{
  GetClassPtr__H1Z9CSoundEnt_PX01_PX01(param_1);
  return;
}


// speaker  @ 000ed9a0
void speaker(undefined4 param_1)

{
  GetClassPtr__H1Z8CSpeaker_PX01_PX01(param_1);
  return;
}


// teledeath  @ 00113070
void teledeath(undefined4 param_1)

{
  GetClassPtr__H1Z14CTelefragDeath_PX01_PX01(param_1);
  return;
}


// testhull  @ 000cba90
void testhull(undefined4 param_1)

{
  GetClassPtr__H1Z9CTestHull_PX01_PX01(param_1);
  return;
}


// timer  @ 00104570
void timer(undefined4 param_1)

{
  GetClassPtr__H1Z6CTimer_PX01_PX01(param_1);
  return;
}


// trigger  @ 0010fd80
void trigger(undefined4 param_1)

{
  GetClassPtr__H1Z12CBaseTrigger_PX01_PX01(param_1);
  return;
}


// weaponbox  @ 0011c020
void weaponbox(undefined4 param_1)

{
  GetClassPtr__H1Z10CWeaponBox_PX01_PX01(param_1);
  return;
}


// worldspawn  @ 0011d8a0
void worldspawn(undefined4 param_1)

{
  GetClassPtr__H1Z6CWorld_PX01_PX01(param_1);
  return;
}


