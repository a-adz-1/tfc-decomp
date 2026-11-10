// ServerActivate__FP7edict_sii  @ 000a3180
void ServerActivate__FP7edict_sii(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_2) {
    do {
      iVar1 = iVar3 * 0x2c8;
      if (((*(int *)(param_1 + iVar1) == 0) && (param_3 <= iVar3)) &&
         (*(int *)(param_1 + 0xd8 + iVar1) != 0)) {
        iVar1 = iVar1 + param_1;
        if ((iVar1 == 0) && (iVar1 = (*DAT_001755d4)(0), iVar1 == 0)) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = *(int **)(iVar1 + 0xd8);
        }
        if ((piVar2 == (int *)0x0) || (*(int *)(*piVar2 + 0x184) < 0)) {
          (*DAT_001755b4)(1,"Can\'t instance %s\n",
                          *(int *)(param_1 + 0xdc + iVar3 * 0x2c8) + *(int *)(gpGlobals + 0x98));
        }
        else {
          (**(code **)(piVar2[0xf2] + 0x20))(piVar2);
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_2);
  }
  ParseTFMapSettings__Fv();
  (*DAT_001755ac)("sv_maxspeed",0x43fa0000);
  return;
}


