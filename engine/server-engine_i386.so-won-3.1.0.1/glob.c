// glob_match  @ 0009271c
uint glob_match(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char local_9;
  char local_7;
  char local_6;
  
LAB_0009285c:
  while( true ) {
    cVar2 = *param_1;
    pcVar6 = param_1 + 1;
    if (cVar2 == '\0') {
      return (uint)(*param_2 == '\0');
    }
    if (cVar2 != '?') break;
    if (*param_2 == '\0') {
      return 0;
    }
    param_2 = param_2 + 1;
    param_1 = pcVar6;
  }
  if (cVar2 < '@') {
    if (cVar2 == '*') {
      uVar4 = glob_match_after_star(pcVar6,param_2);
      return uVar4;
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
      local_9 = *pcVar6;
      if ((local_9 == '!') || (local_9 == '^')) {
        bVar3 = true;
      }
      if (bVar3) {
        pcVar6 = param_1 + 2;
        local_9 = *pcVar6;
      }
      pcVar6 = pcVar6 + 1;
      do {
        local_6 = local_9;
        pcVar5 = pcVar6;
        if (local_9 == '\\') {
          local_6 = *pcVar6;
          pcVar5 = pcVar6 + 1;
        }
        if (local_9 == '\0') {
          return 0;
        }
        local_9 = *pcVar5;
        pcVar6 = pcVar5 + 1;
        cVar1 = local_6;
        if ((local_9 == '-') && (local_7 = *pcVar6, cVar1 = local_6, local_7 != ']')) {
          pcVar6 = pcVar5 + 2;
          if (local_7 == '\\') {
            local_7 = *pcVar6;
            pcVar6 = pcVar5 + 3;
          }
          if (local_7 == '\0') {
            return 0;
          }
          local_9 = *pcVar6;
          pcVar6 = pcVar6 + 1;
          cVar1 = local_7;
        }
        local_7 = cVar1;
        if ((local_6 <= cVar2) && (cVar2 <= local_7)) goto LAB_0009283f;
      } while (local_9 != ']');
      param_1 = pcVar6;
      if (!bVar3) {
        return 0;
      }
      goto LAB_0009285c;
    }
    if (cVar2 == '\\') {
      cVar2 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 2;
      if (*pcVar6 != cVar2) {
        return 0;
      }
      goto LAB_0009285c;
    }
  }
  cVar1 = *param_2;
  param_2 = param_2 + 1;
  param_1 = pcVar6;
  if (cVar2 != cVar1) {
    return 0;
  }
  goto LAB_0009285c;
LAB_0009283f:
  while (param_1 = pcVar6, local_9 != ']') {
    if (local_9 == '\0') {
      return 0;
    }
    local_9 = *param_1;
    if (local_9 == '\0') {
      return 0;
    }
    pcVar6 = param_1 + 1;
    if (local_9 == '\\') {
      pcVar6 = param_1 + 2;
    }
  }
  if (bVar3) {
    return 0;
  }
  goto LAB_0009285c;
}


// glob_match_after_star  @ 0009268c
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


