// Ghidra decompilation of functions from cl_dll/com_weapons.cpp
// 16 functions, ordered by original source line

// COM_Log  @ 000688f0  (line 45)

void COM_Log(char *pszFile,char *fmt,...)

{
  FILE *__stream;
  int in_GS_OFFSET;
  char local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: char[1024] string@[???]
                       Unresolved local var: FILE * fp@[???]
                       Unresolved local var: char * pfilename@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (pszFile == (char *)0x0) {
    pszFile = "c:\\hllog.txt";
  }
  __vsprintf_chk(local_410,1,0x400,fmt,&stack0x0000000c);
  __stream = fopen(pszFile,"a+t");
  if (__stream != (FILE *)0x0) {
    fputs(local_410,__stream);
    fclose(__stream);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// HUD_SendWeaponAnim  @ 000689a0  (line 86)

void HUD_SendWeaponAnim(int iAnim,int body,int force)

{
  if (force == 0 && g_runfuncs == 0) {
    return;
  }
  g_currentanim = iAnim;
                    /* WARNING: Could not recover jumptable at 0x000689be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*gEngfuncs.pfnWeaponAnim)(iAnim,body);
  return;
}


// HUD_GetWeaponAnim  @ 000689d0  (line 105)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int HUD_GetWeaponAnim(void)

{
  return g_currentanim;
}


// HUD_PlaySound  @ 000689e0  (line 116)

void HUD_PlaySound(char *sound,float volume)

{
  if ((g_runfuncs != 0) && (g_finalstate != (local_state_s *)0x0)) {
    (*gEngfuncs.pfnPlaySoundByNameAtLocation)(sound,volume,&(g_finalstate->playerstate).origin.x);
  }
  return;
}


// HUD_PlaybackEvent  @ 00068a20  (line 131)

void HUD_PlaybackEvent(int flags,edict_t *pInvoker,ushort eventindex,float delay,float *origin,
                      float *angles,float fparam1,float fparam2,int iparam1,int iparam2,int bparam1,
                      int bparam2)

{
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: Vector org@[???]
                       Unresolved local var: Vector ang@[???] */
  if ((g_runfuncs != 0) && (g_finalstate != (local_state_s *)0x0)) {
    local_24 = (g_finalstate->playerstate).origin.x;
    local_20 = (g_finalstate->playerstate).origin.y;
    local_1c = (g_finalstate->playerstate).origin.z;
    local_18 = v_angles.x;
    local_14 = v_angles.y;
    local_10 = v_angles.z;
    (*gEngfuncs.pfnPlaybackEvent)
              (flags,pInvoker,eventindex,delay,&local_24,&local_18,fparam1,fparam2,iparam1,iparam2,
               bparam1,bparam2);
  }
  return;
}


// HUD_SetMaxSpeed  @ 00068af0  (line 151)

void HUD_SetMaxSpeed(edict_t *ed,float speed)

{
  return;
}


// UTIL_WeaponTimeBase  @ 00068b00  (line 166)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float UTIL_WeaponTimeBase(void)

{
  return 0.0;
}


// U_Random  @ 00068b10  (line 192)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint U_Random(void)

{
  glSeed = glSeed * 0x10dcd + 1 + seed_table[glSeed * 0x10dcd & 0xff];
  return glSeed & 0xfffffff;
}


// U_Srand  @ 00068b40  (line 200)

void U_Srand(uint seed)

{
  glSeed = seed_table[seed & 0xff];
  return;
}


// UTIL_SharedRandomLong  @ 00068b60  (line 209)

int UTIL_SharedRandomLong(uint seed,int low,int high)

{
  uint uVar1;
  uint uVar2;
  
                    /* Unresolved local var: uint range@[DW_OP_reg1(ECX)] */
  uVar2 = (high - low) + 1;
  glSeed = seed_table[seed + low + high & 0xff];
  if (uVar2 != 1) {
                    /* Unresolved local var: int offset@[???]
                       Unresolved local var: int rnum@[???] */
    uVar1 = seed_table[seed + low + high & 0xff] * 0x10dcd;
    glSeed = uVar1 + 1 + seed_table[uVar1 & 0xff];
    return (glSeed & 0xfffffff) % uVar2 + low;
  }
  return low;
}


// UTIL_SharedRandomFloat  @ 00068bc0  (line 238)

float UTIL_SharedRandomFloat(uint seed,float low,float high)

{
  uint uVar1;
  int local_c;
  
                    /* Unresolved local var: uint range@[???] */
  uVar1 = (seed_table[seed + (int)low + (int)high & 0xff] * 0x10dcd + 1 +
          seed_table[seed_table[seed + (int)low + (int)high & 0xff] * 0x10dcd & 0xff]) * 0x10dcd;
  glSeed = uVar1 + 1 + seed_table[uVar1 & 0xff];
  local_c = (int)(longlong)ROUND(high - low);
  if (local_c != 0) {
                    /* Unresolved local var: int tensixrand@[???]
                       Unresolved local var: float offset@[???] */
    glSeed = glSeed * 0x10dcd + 1 + seed_table[glSeed * 0x10dcd & 0xff];
    low = (float)((longlong)ROUND(high - low) & 0xffffffff) *
          (float)(glSeed & 0xffff) * 1.5258789e-05 + low;
  }
  return low;
}


// stub_PrecacheModel  @ 00068c80  (line 263)

/* stub_PrecacheModel(char*) */

undefined4 stub_PrecacheModel(char *param_1)

{
  return 0;
}


// stub_PrecacheSound  @ 00068c90  (line 274)

int stub_PrecacheSound(char *s)

{
  return 0;
}


// stub_PrecacheEvent  @ 00068ca0  (line 275)

ushort stub_PrecacheEvent(int type,char *s)

{
  return 0;
}


// stub_NameForFunction  @ 00068cb0  (line 276)

char * stub_NameForFunction(uint32 function)

{
  return "func";
}


// stub_SetModel  @ 00068cc0  (line 277)

void stub_SetModel(edict_t *e,char *m)

{
  return;
}


