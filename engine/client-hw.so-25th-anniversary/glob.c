// glob_match  @ 000e4300
/* WARNING: Type propagation algorithm not settling */

int glob_match(char *pattern,char *text)

{
  char cVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  char *pcVar5;
  char cVar6;
  char *pattern_00;
  char *pcVar7;
  bool bVar8;
  bool bVar9;
  
  cVar6 = *pattern;
joined_r0x000e431d:
  if (cVar6 == '\0') {
    return (uint)(*text == '\0');
  }
  pattern_00 = pattern + 1;
  if (cVar6 == '?') {
    if (*text == '\0') {
      return 0;
    }
  }
  else {
    if (cVar6 < '@') {
      if (cVar6 == '*') {
                    /* Unresolved local var: char * p@[???]
                       Unresolved local var: char * t@[???]
                       Unresolved local var: bool c@[???]
                       Unresolved local var: bool c1@[???] */
        pcVar7 = pattern + 2;
        cVar6 = *pattern_00;
        if (cVar6 == '?') goto LAB_000e4387;
        while (pcVar5 = pcVar7, cVar6 == '*') {
          while( true ) {
            pcVar7 = pcVar5 + 1;
            cVar6 = *pcVar5;
            pattern_00 = pcVar5;
            if (cVar6 != '?') break;
LAB_000e4387:
            cVar6 = *text;
            text = text + 1;
            pcVar5 = pcVar7;
            if (cVar6 == '\0') {
              return 0;
            }
          }
        }
        if (cVar6 != '\0') {
          if (cVar6 == '\\') {
            cVar6 = pattern_00[1];
          }
          else if (cVar6 == '[') {
            do {
              iVar2 = glob_match(pattern_00,text);
              if (iVar2 != 0) {
                return 1;
              }
              cVar6 = *text;
              text = text + 1;
            } while (cVar6 != '\0');
            return 0;
          }
          while ((cVar4 = *text, cVar6 != *text ||
                 (iVar2 = glob_match(pattern_00,text), cVar4 = cVar6, iVar2 == 0))) {
            text = text + 1;
            if (cVar4 == '\0') {
              return 0;
            }
          }
          return 1;
        }
        return 1;
      }
    }
    else {
      if (cVar6 == '[') {
        cVar6 = *text;
        if (cVar6 == '\0') {
          return 0;
        }
        cVar4 = pattern[1];
        bVar8 = cVar4 == '!';
        bVar9 = cVar4 == '^';
        if (bVar8 || bVar9) {
          pattern_00 = pattern + 2;
          cVar4 = pattern[2];
        }
        pattern_00 = pattern_00 + 1;
LAB_000e441a:
        if (cVar4 == '\\') {
          cVar1 = *pattern_00;
          pcVar7 = pattern_00 + 1;
          cVar3 = *pcVar7;
          pcVar5 = pattern_00 + 2;
        }
        else {
                    /* Unresolved local var: bool cstart@[???]
                       Unresolved local var: bool cend@[???] */
          if (cVar4 == '\0') {
            return 0;
          }
          cVar3 = *pattern_00;
          pcVar5 = pattern_00 + 1;
          pcVar7 = pattern_00;
          cVar1 = cVar4;
        }
        pattern_00 = pcVar5;
        cVar4 = cVar3;
        cVar3 = cVar1;
        if (cVar4 == '-') {
          cVar3 = pcVar7[1];
          if (cVar3 == ']') {
            if (cVar6 == cVar1) {
              cVar6 = ']';
              pcVar5 = pattern_00;
              pattern_00 = pcVar7 + 2;
              goto LAB_000e452e;
            }
            goto LAB_000e441a;
          }
          if (cVar3 == '\\') {
            pcVar5 = pcVar7 + 3;
            cVar3 = pcVar7[2];
          }
          else {
            pcVar5 = pcVar7 + 2;
          }
          if (cVar3 == '\0') {
            return 0;
          }
          pattern_00 = pcVar5 + 1;
          cVar4 = *pcVar5;
        }
        if ((cVar6 < cVar1) || (cVar3 < cVar6)) goto LAB_000e440d;
        if (cVar4 != ']') {
          if (cVar4 == '\0') {
            return 0;
          }
          cVar6 = *pattern_00;
          pcVar5 = pattern_00;
          while( true ) {
            pattern_00 = pcVar5 + 1;
            if (cVar6 == '\0') {
              return 0;
            }
LAB_000e452e:
            pcVar5 = pcVar5 + 2;
            if ((cVar6 != '\\') && (pcVar5 = pattern_00, cVar6 == ']')) break;
            cVar6 = *pcVar5;
          }
        }
        if (bVar8 || bVar9) {
          return 0;
        }
        goto LAB_000e4346;
      }
      if (cVar6 == '\\') {
        pattern_00 = pattern + 2;
        if (pattern[1] != *text) {
          return 0;
        }
        goto LAB_000e4346;
      }
    }
    if (cVar6 != *text) {
      return 0;
    }
  }
  goto LAB_000e4346;
LAB_000e440d:
  if (cVar4 == ']') goto LAB_000e44e8;
  goto LAB_000e441a;
LAB_000e44e8:
  if (!bVar8 && !bVar9) {
    return 0;
  }
LAB_000e4346:
                    /* Unresolved local var: bool c1@[???]
                       Unresolved local var: int invert@[???] */
  cVar6 = *pattern_00;
  pattern = pattern_00;
  text = text + 1;
  goto joined_r0x000e431d;
}


