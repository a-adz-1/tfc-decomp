// Ghidra decompilation of functions from tfc/skill.cpp
// 1 functions, ordered by original source line

// GetSkillCvar  @ 000e8240  (line 26)

float GetSkillCvar(char *pName)

{
  int in_GS_OFFSET;
  longdouble extraout_ST0;
  longdouble lVar1;
  char local_50 [64];
  int local_10;
  
                    /* Unresolved local var: int iCount@[???]
                       Unresolved local var: float flValue@[???]
                       Unresolved local var: char[64] szBuffer@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __sprintf_chk(local_50,1,0x40,&DAT_0015a5d4,pName,gSkillData.iSkillLevel);
  (*g_engfuncs.pfnCVarGetFloat)(local_50);
  lVar1 = extraout_ST0;
  if (extraout_ST0 <= (longdouble)0) {
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"\n\n** GetSkillCVar Got a zero for %s **\n\n",local_50);
    lVar1 = (longdouble)(float)extraout_ST0;
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (float)lVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


