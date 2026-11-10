// Smoke__13CEnvExplosion  @ 000a740c
void Smoke__13CEnvExplosion(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((*(byte *)(iVar1 + 0x1a0) & 8) == 0) {
    (*DAT_0019f758)(5,0x17,iVar1 + 8,0);
    (*DAT_0019f760)(5);
    (*DAT_0019f774)(*(undefined4 *)(*param_1 + 8));
    (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0x10));
    (*DAT_0019f768)((int)g_sModelIndexSmoke);
    (*DAT_0019f760)((char)param_1[0x1a8]);
    (*DAT_0019f760)(0xc);
    (*DAT_0019f75c)();
    iVar1 = *param_1;
  }
  if ((*(byte *)(iVar1 + 0x1a0) & 2) == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


// Smoke__8CGrenade  @ 000b0e3c
void Smoke__8CGrenade(int *param_1)

{
  int iVar1;
  float local_28;
  float local_24;
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar1 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
  if (iVar1 == -3) {
    local_1c = 0x42800000;
    iVar1 = *param_1;
    local_10 = *(float *)(iVar1 + 8) - 64.0;
    local_c = *(float *)(iVar1 + 0xc) - 64.0;
    local_8 = *(float *)(iVar1 + 0x10) - 64.0;
    local_28 = *(float *)(iVar1 + 8) + 64.0;
    local_24 = *(float *)(iVar1 + 0xc) + 64.0;
    local_20 = *(float *)(iVar1 + 0x10) + 64.0;
    local_18 = local_1c;
    local_14 = local_1c;
    UTIL_Bubbles__FG6VectorT0i(&local_10,&local_28,100);
  }
  else if (param_1[0x1a9] == 0) {
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x1ab]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0x1ab] == 0.0) << 0xe) >> 8)) == 0x40) {
      param_1[0x1ab] = (int)((*(float *)(*param_1 + 0x1e0) - 50.0) * 0.8);
    }
    (*DAT_0019f758)(4,0x17,*param_1 + 8,0);
    (*DAT_0019f760)(5);
    (*DAT_0019f774)(*(undefined4 *)(*param_1 + 8));
    (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0x10));
    (*DAT_0019f768)((int)g_sModelIndexSmoke);
    (*DAT_0019f760)((int)ROUND((float)param_1[0x1ab]));
    (*DAT_0019f760)(0xc);
    (*DAT_0019f75c)();
  }
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


