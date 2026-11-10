// DelayStart__12CCineMonsteri  @ 000dce00
void DelayStart__12CCineMonsteri(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *local_8;
  
  iVar2 = *(int *)(*param_1 + 0x1cc) + (int)gpGlobals[0x26];
  iVar3 = 0;
  do {
    iVar3 = (*DAT_001a7e78)(iVar3,"targetname",iVar2);
    bVar1 = false;
    if (iVar3 == 0) {
LAB_000dce64:
      bVar1 = true;
    }
    else {
      iVar2 = (*DAT_001a7f58)(iVar3);
      if (iVar2 == 0) goto LAB_000dce64;
    }
    if (bVar1) {
      return;
    }
    local_8 = (int *)(iVar3 + 0x80);
    if (iVar3 == 0) {
      local_8 = (int *)0x0;
    }
    iVar2 = strcmp((char *)(*local_8 + (int)gpGlobals[0x26]),"scripted_sequence");
    if (iVar2 == 0) {
      iVar2 = iVar3 + 0x80;
      if (iVar3 == 0) {
        iVar2 = 0;
      }
      iVar2 = GetClassPtr__H1Z12CCineMonster_PX01_PX01(iVar2);
      if (param_2 == 0) {
        *(int *)(iVar2 + 0x638) = *(int *)(iVar2 + 0x638) + -1;
        if (*(int *)(iVar2 + 0x638) < 1) {
          *(float *)(iVar2 + 0x63c) = *gpGlobals + 0.05;
        }
      }
      else {
        *(int *)(iVar2 + 0x638) = *(int *)(iVar2 + 0x638) + 1;
      }
    }
    iVar2 = *(int *)(*param_1 + 0x1cc) + (int)gpGlobals[0x26];
  } while( true );
}


