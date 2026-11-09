// Ghidra decompilation of functions from tfc/skill.cpp
// 1 functions, ordered by original source line

// GetSkillCvar  @ 0011d8b0  (line 26)

float GetSkillCvar(char *pName)

{
  longdouble extraout_ST0;
  longdouble lVar1;
  char local_4c [72];
  
                    /* Unresolved local var: int iCount@[???]
                       Unresolved local var: float flValue@[???]
                       Unresolved local var: char[64] szBuffer@[???] */
  sprintf(local_4c,"%s%d",pName,gSkillData.iSkillLevel);
  (*g_engfuncs.pfnCVarGetFloat)(local_4c);
  lVar1 = extraout_ST0;
  if (extraout_ST0 <= (longdouble)0) {
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"\n\n** GetSkillCVar Got a zero for %s **\n\n",local_4c);
    lVar1 = (longdouble)(float)extraout_ST0;
  }
  return (float)lVar1;
}


