// IdleRespond__12CTalkMonster  @ 000f5af8
void IdleRespond__12CTalkMonster(int param_1)

{
  int iVar1;
  longdouble lVar2;
  
  GetVoicePitch__12CTalkMonster(param_1);
  iVar1 = *(int *)(param_1 + 0x444);
  lVar2 = (longdouble)(*DAT_001c118c)(0x40333333,0x404ccccd,0x3f800000,0x40000000);
  (**(code **)(iVar1 + 0x188))(param_1,*(undefined4 *)(param_1 + 0x698),(float)lVar2);
  return;
}


