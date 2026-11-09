// Smoke__13CEnvExplosion  @ 000b1e20
void Smoke__13CEnvExplosion(int *param_1)

{
  if ((*(byte *)(*param_1 + 0x180) & 8) == 0) {
    (*DAT_00175578)(5,0x17,*param_1 + 8,0);
    (*DAT_00175580)(5);
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 0x10));
    (*DAT_00175588)((int)g_sModelIndexSmoke);
    (*DAT_00175580)((char)param_1[0x185]);
    (*DAT_00175580)(0xc);
    (*DAT_0017557c)();
  }
  if ((*(byte *)(*param_1 + 0x180) & 2) == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


// Smoke__8CGrenade  @ 000b91c0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
    local_18 = 0x42800000;
    local_14 = 0x42800000;
    iVar1 = *param_1;
    local_10 = *(float *)(iVar1 + 8) - 64.0;
    local_c = *(float *)(iVar1 + 0xc) - 64.0;
    local_8 = *(float *)(iVar1 + 0x10) - 64.0;
    local_28 = *(float *)(iVar1 + 8) + 64.0;
    local_24 = *(float *)(iVar1 + 0xc) + 64.0;
    local_20 = *(float *)(iVar1 + 0x10) + 64.0;
    UTIL_Bubbles__FG6VectorT0i(&local_10,&local_28,100);
  }
  else if (param_1[0x185] == 0) {
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x187]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0x187] == 0.0) << 0xe) >> 8)) == 0x40) {
      param_1[0x187] = (int)((*(float *)(*param_1 + 0x1c0) - _FUN_0013259c) * 0.8);
    }
    (*DAT_00175578)(4,0x17,*param_1 + 8,0);
    (*DAT_00175580)(5);
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 0x10));
    (*DAT_00175588)((int)g_sModelIndexSmoke);
    (*DAT_00175580)((int)ROUND((float)param_1[0x187]));
    (*DAT_00175580)(0xc);
    (*DAT_0017557c)();
  }
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


