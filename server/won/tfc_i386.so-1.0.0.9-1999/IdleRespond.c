// IdleRespond__12CTalkMonster  @ 000f2250
void IdleRespond__12CTalkMonster(int param_1)

{
  int iVar1;
  longdouble lVar2;
  
  GetVoicePitch__12CTalkMonster(param_1);
  iVar1 = *(int *)(param_1 + 0x3c8);
  lVar2 = (longdouble)(*DAT_0017562c)(0x40333333,0x404ccccd,0x3f800000,0x40000000);
  (**(code **)(iVar1 + 0x180))(param_1,*(undefined4 *)(param_1 + 0x61c),(float)lVar2);
  return;
}


