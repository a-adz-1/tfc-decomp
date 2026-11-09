// IdleHeadTurn__12CTalkMonsterR6Vector  @ 000f2580
void IdleHeadTurn__12CTalkMonsterR6Vector(int *param_1,float *param_2)

{
  longdouble lVar1;
  longdouble lVar2;
  float local_10;
  float local_c;
  float local_8;
  
  if ((*(byte *)((int)param_1 + 0x5c9) & 4) != 0) {
    local_10 = *param_2 - *(float *)(*param_1 + 8);
    local_c = param_2[1] - *(float *)(*param_1 + 0xc);
    local_8 = param_2[2] - *(float *)(*param_1 + 0x10);
    lVar1 = (longdouble)VecToYaw__12CBaseMonsterG6Vector(param_1,&local_10);
    lVar1 = lVar1 - (longdouble)*(float *)(*param_1 + 0x54);
    lVar2 = (longdouble)180.0;
    if ((byte)(lVar2 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar2 == lVar1) << 0xe) >> 8)) == 1) {
      lVar1 = lVar1 - (longdouble)360.0;
    }
    if (lVar1 < (longdouble)-180.0) {
      lVar1 = (longdouble)360.0 + lVar1;
    }
    SetBoneController__14CBaseAnimatingif(param_1,0,(float)lVar1);
  }
  return;
}


