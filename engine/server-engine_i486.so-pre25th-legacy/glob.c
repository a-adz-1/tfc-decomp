// glob_match  @ 000959a0
/* WARNING: Type propagation algorithm not settling */

int glob_match(char *pattern,char *text)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char *pcVar9;
  char *pcVar10;
  bool bVar11;
  bool bVar12;
  
                    /* Unresolved local var: char * p@[???]
                       Unresolved local var: char * t@[???]
                       Unresolved local var: bool c@[???] */
                    /* Unresolved local var: bool c1@[???]
                       Unresolved local var: int invert@[???] */
  cVar8 = *pattern;
joined_r0x000959b8:
  if (cVar8 == '\0') {
    return (uint)(*text == '\0');
  }
  pcVar9 = pattern + 1;
  if (cVar8 == '?') {
    if (*text == '\0') {
      return 0;
    }
  }
  else if (cVar8 < '@') {
    if (cVar8 == '*') {
      while( true ) {
        while( true ) {
          pcVar10 = pcVar9;
          cVar8 = *pcVar10;
          pcVar9 = pcVar10 + 1;
          if (cVar8 == '?') break;
          if (cVar8 != '*') {
            if (cVar8 == '\0') {
              return 1;
            }
            if (cVar8 == '\\') {
              cVar8 = pcVar10[1];
            }
            else if (cVar8 == '[') {
              do {
                iVar5 = glob_match(pcVar10,text);
                if (iVar5 != 0) {
                  return 1;
                }
                cVar8 = *text;
                text = text + 1;
              } while (cVar8 != '\0');
              return 0;
            }
            do {
              cVar4 = *text;
              if (cVar4 == cVar8) {
                iVar5 = glob_match(pcVar10,text);
                if (iVar5 != 0) {
                  return 1;
                }
                cVar4 = *text;
              }
              text = text + 1;
            } while (cVar4 != '\0');
            return 0;
          }
        }
                    /* Unresolved local var: char * p@[???]
                       Unresolved local var: char * t@[???]
                       Unresolved local var: bool c@[???]
                       Unresolved local var: bool c1@[???] */
        if (*text == '\0') break;
        text = text + 1;
      }
      return 0;
    }
LAB_000959d2:
    if (cVar8 != *text) {
      return 0;
    }
  }
  else if (cVar8 == '[') {
    cVar8 = *text;
    if (cVar8 == '\0') {
      return 0;
    }
    cVar4 = pattern[1];
    bVar11 = cVar4 == '^';
    bVar12 = cVar4 == '!';
    bVar2 = bVar11 || bVar12;
    if (bVar2) {
      pcVar9 = pattern + 2;
      cVar4 = pattern[2];
    }
    pcVar9 = pcVar9 + 1;
    do {
      if (cVar4 == '\\') {
        pcVar10 = pcVar9 + 1;
        cVar1 = *pcVar9;
        cVar6 = *pcVar10;
        pcVar3 = pcVar9 + 2;
      }
      else {
                    /* Unresolved local var: bool cstart@[???]
                       Unresolved local var: bool cend@[???] */
        if (cVar4 == '\0') {
          return 0;
        }
        cVar6 = *pcVar9;
        pcVar3 = pcVar9 + 1;
        pcVar10 = pcVar9;
        cVar1 = cVar4;
      }
      pcVar9 = pcVar3;
      cVar4 = cVar6;
      cVar6 = cVar1;
      if ((cVar4 == '-') && (cVar7 = pcVar10[1], cVar7 != ']')) {
        pcVar9 = pcVar10 + 2;
        if (cVar7 == '\\') {
          cVar7 = pcVar10[2];
          pcVar9 = pcVar10 + 3;
        }
        if (cVar7 == '\0') {
          return 0;
        }
        cVar4 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        cVar6 = cVar7;
      }
      if ((cVar8 <= cVar6) && (cVar1 <= cVar8)) {
        if (cVar4 == ']') goto LAB_00095bf5;
        if (cVar4 == '\0') {
          return 0;
        }
        cVar8 = *pcVar9;
        pcVar10 = pcVar9;
        goto joined_r0x00095bbb;
      }
    } while (cVar4 != ']');
    if (!bVar11 && !bVar12) {
      return 0;
    }
  }
  else {
    if (cVar8 != '\\') goto LAB_000959d2;
    if (pattern[1] != *text) {
      return 0;
    }
    pcVar9 = pattern + 2;
  }
  goto LAB_000959d7;
joined_r0x00095bbb:
  if (cVar8 == '\0') {
    return 0;
  }
  pcVar9 = pcVar10 + 1;
  pcVar10 = pcVar10 + 2;
  if (cVar8 != '\\') {
    if (cVar8 == ']') goto LAB_00095bf5;
    pcVar10 = pcVar9;
    if (cVar8 == '\0') {
      return 0;
    }
  }
  cVar8 = *pcVar10;
  goto joined_r0x00095bbb;
LAB_00095bf5:
  if (bVar2) {
    return 0;
  }
LAB_000959d7:
  cVar8 = *pcVar9;
  pattern = pcVar9;
  text = text + 1;
  goto joined_r0x000959b8;
}


