// IdleRespond__12CTalkMonster  @ 000f8e04
void IdleRespond__12CTalkMonster(int param_1)

{
  int iVar1;
  longdouble lVar2;
  
  (*DAT_0019f808)(0,3);
  iVar1 = *(int *)(param_1 + 0x454);
  lVar2 = (longdouble)(*DAT_0019f80c)(0x40333333,0x404ccccd,0x3f800000,0x40000000);
  (**(code **)(iVar1 + 0x188))(param_1,*(undefined4 *)(param_1 + 0x6a8),(float)lVar2);
  return;
}


