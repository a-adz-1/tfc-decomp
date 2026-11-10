// setBirthdayModel__8CGrenade  @ 000fae20
undefined4 setBirthdayModel__8CGrenade(int *param_1)

{
  longdouble lVar1;
  
  if ((birthday != 0) &&
     (lVar1 = (longdouble)(*DAT_0017562c)(0,0x3f800000), lVar1 < (longdouble)0.5)) {
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/presentsm.mdl");
    return 1;
  }
  return 0;
}


