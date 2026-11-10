// InconsistentFile__FPC7edict_sPCcPc  @ 0008c1f0
bool InconsistentFile__FPC7edict_sPCcPc(undefined4 param_1,undefined4 param_2,char *param_3)

{
  bool bVar1;
  longdouble lVar2;
  
  lVar2 = (longdouble)(*DAT_001a7f24)("mp_consistency");
  bVar1 = (byte)((byte)((ushort)((ushort)(NAN((longdouble)1.0) || NAN(lVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)((longdouble)1.0 == lVar2) << 0xe) >> 8)) == 0x40;
  if (bVar1) {
    sprintf(param_3,"Server is enforcing file consistency for %s\n",param_2);
  }
  return bVar1;
}


