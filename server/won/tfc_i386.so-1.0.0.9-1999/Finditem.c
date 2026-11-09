// Finditem__Fi  @ 00109b00
int Finditem__Fi(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    iVar1 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar1,"item_tfgoal");
    if (iVar1 == 0) {
      (*DAT_001755b4)(1,"Could not find an item with a goal_no of %d.\n",param_1);
      return 0;
    }
  } while (*(int *)(iVar1 + 0x210) != param_1);
  return iVar1;
}


