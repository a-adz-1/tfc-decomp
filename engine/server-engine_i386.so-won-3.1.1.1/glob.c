// glob_match  @ 000941a0
uint glob_match(char *param_1,char *param_2)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  char cVar4;
  char *pcVar5;
  char *pcVar6;
  char local_a;
  char local_9;
  
LAB_000941bc:
  cVar1 = *param_1;
  pcVar5 = param_1 + 1;
  if (cVar1 == '\0') {
    return (uint)(*param_2 == '\0');
  }
  if (cVar1 == '?') {
    if (*param_2 == '\0') {
      return 0;
    }
  }
  else if (cVar1 < '@') {
    if (cVar1 == '*') {
      uVar3 = glob_match_after_star(pcVar5,param_2);
      return uVar3;
    }
LAB_0009434e:
    if (cVar1 != *param_2) {
      return 0;
    }
  }
  else if (cVar1 == '[') {
    cVar1 = *param_2;
    if (cVar1 == '\0') {
      return 0;
    }
    bVar2 = false;
    if ((*pcVar5 == '!') || (*pcVar5 == '^')) {
      bVar2 = true;
    }
    if (bVar2) {
      pcVar5 = param_1 + 2;
    }
    local_9 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    do {
      cVar4 = local_9;
      pcVar6 = pcVar5;
      if (local_9 == '\\') {
        cVar4 = *pcVar5;
        pcVar6 = pcVar5 + 1;
      }
      if (local_9 == '\0') {
        return 0;
      }
      local_9 = *pcVar6;
      pcVar5 = pcVar6 + 1;
      local_a = cVar4;
      if ((local_9 == '-') && (*pcVar5 != ']')) {
        local_a = *pcVar5;
        pcVar5 = pcVar6 + 2;
        if (local_a == '\\') {
          local_a = *pcVar5;
          pcVar5 = pcVar6 + 3;
        }
        if (local_a == '\0') {
          return 0;
        }
        local_9 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      }
      if ((cVar4 <= cVar1) && (pcVar6 = pcVar5, cVar1 <= local_a)) goto LAB_0009430c;
    } while (local_9 != ']');
    if (!bVar2) {
      return 0;
    }
  }
  else {
    if (cVar1 != '\\') goto LAB_0009434e;
    cVar1 = *pcVar5;
    pcVar5 = param_1 + 2;
    if (cVar1 != *param_2) {
      return 0;
    }
  }
  goto LAB_0009435c;
LAB_0009430c:
  while (pcVar5 = pcVar6, local_9 != ']') {
    if (local_9 == '\0') {
      return 0;
    }
    local_9 = *pcVar5;
    if (local_9 == '\0') {
      return 0;
    }
    pcVar6 = pcVar5 + 1;
    if (local_9 == '\\') {
      pcVar6 = pcVar5 + 2;
    }
  }
  if (bVar2) {
    return 0;
  }
LAB_0009435c:
  param_2 = param_2 + 1;
  param_1 = pcVar5;
  goto LAB_000941bc;
}


// glob_match_after_star  @ 000940dc
undefined4 glob_match_after_star(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  char local_6;
  
  do {
    cVar1 = *param_1;
    pcVar4 = param_1 + 1;
    if ((cVar1 != '?') && (cVar1 != '*')) {
      if (cVar1 == '\0') {
        return 1;
      }
      local_6 = cVar1;
      if (cVar1 == '\\') {
        local_6 = *pcVar4;
      }
      while (((cVar1 != '[' && (*param_2 != local_6)) ||
             (iVar3 = glob_match(param_1,param_2), iVar3 == 0))) {
        cVar2 = *param_2;
        param_2 = param_2 + 1;
        if (cVar2 == '\0') {
          return 0;
        }
      }
      return 1;
    }
    param_1 = pcVar4;
  } while ((cVar1 != '?') || (cVar1 = *param_2, param_2 = param_2 + 1, cVar1 != '\0'));
  return 0;
}


