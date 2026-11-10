// Smoke__13CEnvExplosion  @ 000a7e7c
void Smoke__13CEnvExplosion(int *param_1)

{
  if ((*(byte *)(*param_1 + 0x1a0) & 8) == 0) {
    (*DAT_001c10d8)(5,0x17,*param_1 + 8,0);
    (*DAT_001c10e0)(5);
    (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 8));
    (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0x10));
    (*DAT_001c10e8)((int)g_sModelIndexSmoke);
    (*DAT_001c10e0)((char)param_1[0x1a4]);
    (*DAT_001c10e0)(0xc);
    (*DAT_001c10dc)();
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 2) == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


// Smoke__8CGrenade  @ 000b18b0
void Smoke__8CGrenade(int *param_1)

{
  int iVar1;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar1 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
  if (iVar1 == -3) {
    local_18 = 0x42800000;
    iVar1 = *param_1;
    fStack_c = *(float *)(iVar1 + 8) - 64.0;
    fStack_8 = *(float *)(iVar1 + 0xc) - 64.0;
    fStack_4 = *(float *)(iVar1 + 0x10) - 64.0;
    fStack_24 = *(float *)(iVar1 + 8) + 64.0;
    fStack_20 = *(float *)(iVar1 + 0xc) + 64.0;
    fStack_1c = *(float *)(iVar1 + 0x10) + 64.0;
    local_14 = local_18;
    local_10 = local_18;
    UTIL_Bubbles__FG6VectorT0i(&fStack_c,&fStack_24,100);
  }
  else if (param_1[0x1a5] == 0) {
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x1a7]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0x1a7] == 0.0) << 0xe) >> 8)) == 0x40) {
      param_1[0x1a7] = (int)((*(float *)(*param_1 + 0x1e0) - 50.0) * 0.8);
    }
    (*DAT_001c10d8)(4,0x17,*param_1 + 8,0);
    (*DAT_001c10e0)(5);
    (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 8));
    (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0x10));
    (*DAT_001c10e8)((int)g_sModelIndexSmoke);
    (*DAT_001c10e0)((int)ROUND((float)param_1[0x1a7]));
    (*DAT_001c10e0)(0xc);
    (*DAT_001c10dc)();
  }
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


