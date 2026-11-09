// glob_match  @ 08087cf0
uint glob_match(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  char cVar8;
  
LAB_08087e3b:
  while( true ) {
    cVar2 = *param_1;
    pcVar7 = param_1 + 1;
    if (cVar2 == '\0') {
      return (uint)(*param_2 == '\0');
    }
    if (cVar2 != '?') break;
    if (*param_2 == '\0') {
      return 0;
    }
    param_2 = param_2 + 1;
    param_1 = pcVar7;
  }
  if (cVar2 < '@') {
    if (cVar2 == '*') {
      uVar5 = glob_match_after_star(pcVar7,param_2);
      return uVar5;
    }
  }
  else {
    if (cVar2 == '[') {
      cVar2 = *param_2;
      param_2 = param_2 + 1;
      if (cVar2 == '\0') {
        return 0;
      }
      bVar3 = false;
      if ((*pcVar7 == '!') || (*pcVar7 == '^')) {
        bVar3 = true;
      }
      if (bVar3) {
        pcVar7 = param_1 + 2;
      }
      cVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      do {
        pcVar6 = pcVar7;
        cVar1 = cVar8;
        if (cVar8 == '\\') {
          cVar1 = *pcVar7;
          pcVar6 = pcVar7 + 1;
        }
        if (cVar8 == '\0') {
          return 0;
        }
        cVar8 = *pcVar6;
        pcVar7 = pcVar6 + 1;
        cVar4 = cVar1;
        if ((cVar8 == '-') && (*pcVar7 != ']')) {
          cVar4 = *pcVar7;
          pcVar7 = pcVar6 + 2;
          if (cVar4 == '\\') {
            cVar4 = *pcVar7;
            pcVar7 = pcVar6 + 3;
          }
          if (cVar4 == '\0') {
            return 0;
          }
          cVar8 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        }
        if ((cVar1 <= cVar2) && (cVar2 <= cVar4)) goto LAB_08087e19;
      } while (cVar8 != ']');
      param_1 = pcVar7;
      if (!bVar3) {
        return 0;
      }
      goto LAB_08087e3b;
    }
    if (cVar2 == '\\') {
      cVar2 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 2;
      if (*pcVar7 != cVar2) {
        return 0;
      }
      goto LAB_08087e3b;
    }
  }
  cVar8 = *param_2;
  param_2 = param_2 + 1;
  param_1 = pcVar7;
  if (cVar2 != cVar8) {
    return 0;
  }
  goto LAB_08087e3b;
LAB_08087e19:
  while (param_1 = pcVar7, cVar8 != ']') {
    if (cVar8 == '\0') {
      return 0;
    }
    cVar8 = *param_1;
    if (cVar8 == '\0') {
      return 0;
    }
    pcVar7 = param_1 + 1;
    if (cVar8 == '\\') {
      pcVar7 = param_1 + 2;
    }
  }
  if (bVar3) {
    return 0;
  }
  goto LAB_08087e3b;
}


// glob_match_after_star  @ 08087c60
undefined4 glob_match_after_star(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  char local_6;
  
  do {
    while( true ) {
      pcVar4 = param_1;
      cVar1 = *pcVar4;
      param_1 = pcVar4 + 1;
      if (cVar1 == '?') break;
      if (cVar1 != '*') {
        if (cVar1 == '\0') {
          return 1;
        }
        local_6 = cVar1;
        if (cVar1 == '\\') {
          local_6 = *param_1;
        }
        while (((cVar1 != '[' && (*param_2 != local_6)) ||
               (iVar3 = glob_match(pcVar4,param_2), iVar3 == 0))) {
          cVar2 = *param_2;
          param_2 = param_2 + 1;
          if (cVar2 == '\0') {
            return 0;
          }
        }
        return 1;
      }
    }
    cVar1 = *param_2;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  return 0;
}


