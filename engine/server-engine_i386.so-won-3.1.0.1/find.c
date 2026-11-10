// find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 00041750
void find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi
               (undefined4 param_1,uint *param_2,undefined4 param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_2 & 3;
  puVar1 = param_2;
  if (uVar3 != 0) {
    puVar2 = param_2;
    if ((POPCOUNT(uVar3) & 1U) != 0) {
      if (uVar3 != 2) {
        if ((char)*param_2 == '\0') goto LAB_0004179c;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_0004179c;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_0004179c;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_0004179c;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_0004179b;
    if ((uVar3 & 0xff0000) == 0) goto LAB_0004179a;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004179a:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004179b:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004179c:
  find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,param_2,param_3,(int)puVar2 - (int)param_2);
  return;
}


// find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi  @ 0003fe10
int find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
              (int *param_1,char *param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  uVar1 = *(uint *)(*param_1 + -0x10);
  if ((uint)(param_4 + param_3) <= uVar1) {
    do {
      pcVar3 = (char *)(*param_1 + param_3);
      if (*pcVar3 == *param_2) {
        bVar5 = true;
        iVar2 = param_4;
        pcVar4 = param_2;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar5 = *pcVar3 == *pcVar4;
          pcVar3 = pcVar3 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (bVar5) {
          return param_3;
        }
      }
      param_3 = param_3 + 1;
    } while ((uint)(param_4 + param_3) <= uVar1);
  }
  return -1;
}


// find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 000417c0
void find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
               (undefined4 param_1,int *param_2,undefined4 param_3)

{
  find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,*param_2,param_3,*(undefined4 *)(*param_2 + -0x10));
  return;
}


// find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi  @ 0003fe80
uint find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi
               (int *param_1,char param_2,uint param_3)

{
  while( true ) {
    if (*(uint *)(*param_1 + -0x10) <= param_3) {
      return 0xffffffff;
    }
    if (*(char *)(param_3 + *param_1) == param_2) break;
    param_3 = param_3 + 1;
  }
  return param_3;
}


// find_exception_handler  @ 000a04b0
undefined4 find_exception_handler(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint *local_c;
  int *local_8;
  
  if (param_2 != (undefined4 *)0x0) {
    puVar2 = param_2 + 2;
    if (param_2[2] != -1) {
      local_8 = param_2 + 5;
      local_c = param_2 + 3;
      puVar3 = param_2;
      do {
        puVar3 = puVar3 + 4;
        if (((*puVar2 <= param_1 - 1U) && (param_1 - 1U < *local_c)) &&
           ((*local_8 == 0 ||
            (((code *)*param_3 != (code *)0x0 &&
             (iVar1 = (*(code *)*param_3)(param_3,*local_8,param_2), iVar1 != 0)))))) {
          return *puVar3;
        }
        puVar2 = puVar2 + 4;
        local_8 = local_8 + 4;
        local_c = local_c + 4;
      } while (*puVar2 != 0xffffffff);
    }
  }
  return 0;
}


// find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 00041460
void find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi
               (undefined4 param_1,uint *param_2,undefined4 param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_2 & 3;
  puVar1 = param_2;
  if (uVar3 != 0) {
    puVar2 = param_2;
    if ((POPCOUNT(uVar3) & 1U) != 0) {
      if (uVar3 != 2) {
        if ((char)*param_2 == '\0') goto LAB_000414ac;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_000414ac;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_000414ac;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_000414ac;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_000414ab;
    if ((uVar3 & 0xff0000) == 0) goto LAB_000414aa;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_000414aa:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_000414ab:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_000414ac:
  find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,param_2,param_3,(int)puVar2 - (int)param_2);
  return;
}


// find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi  @ 00040070
uint find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
               (int *param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  
  do {
    if (*(uint *)(*param_1 + -0x10) <= param_3) {
      return 0xffffffff;
    }
    uVar1 = 0;
    if (param_4 != 0) {
      do {
        if (*(char *)(uVar1 + param_2) == *(char *)(param_3 + *param_1)) goto LAB_000400ae;
        uVar1 = uVar1 + 1;
      } while (uVar1 < param_4);
    }
    uVar1 = 0xffffffff;
LAB_000400ae:
    if (uVar1 == 0xffffffff) {
      return param_3;
    }
    param_3 = param_3 + 1;
  } while( true );
}


// find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 000414d0
void find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
               (undefined4 param_1,int *param_2,undefined4 param_3)

{
  find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,*param_2,param_3,*(undefined4 *)(*param_2 + -0x10));
  return;
}


// find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi  @ 000400e0
uint find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi
               (int *param_1,char param_2,uint param_3)

{
  while( true ) {
    if (*(uint *)(*param_1 + -0x10) <= param_3) {
      return 0xffffffff;
    }
    if (*(char *)(param_3 + *param_1) != param_2) break;
    param_3 = param_3 + 1;
  }
  return param_3;
}


// find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 000415e0
void find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi
               (undefined4 param_1,uint *param_2,undefined4 param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_2 & 3;
  puVar1 = param_2;
  if (uVar3 != 0) {
    puVar2 = param_2;
    if ((POPCOUNT(uVar3) & 1U) != 0) {
      if (uVar3 != 2) {
        if ((char)*param_2 == '\0') goto LAB_0004162c;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_0004162c;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_0004162c;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_0004162c;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_0004162b;
    if ((uVar3 & 0xff0000) == 0) goto LAB_0004162a;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004162a:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004162b:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004162c:
  find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,param_2,param_3,(int)puVar2 - (int)param_2);
  return;
}


// find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi  @ 0003ff80
uint find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
               (int *param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  
  do {
    if (*(uint *)(*param_1 + -0x10) <= param_3) {
      return 0xffffffff;
    }
    uVar1 = 0;
    if (param_4 != 0) {
      do {
        if (*(char *)(uVar1 + param_2) == *(char *)(param_3 + *param_1)) goto LAB_0003ffbe;
        uVar1 = uVar1 + 1;
      } while (uVar1 < param_4);
    }
    uVar1 = 0xffffffff;
LAB_0003ffbe:
    if (uVar1 != 0xffffffff) {
      return param_3;
    }
    param_3 = param_3 + 1;
  } while( true );
}


// find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 00041650
void find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
               (undefined4 param_1,int *param_2,undefined4 param_3)

{
  find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,*param_2,param_3,*(undefined4 *)(*param_2 + -0x10));
  return;
}


// find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi  @ 000415c0
void find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi
               (undefined4 param_1,char param_2,undefined4 param_3)

{
  find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi
            (param_1,(int)param_2,param_3);
  return;
}


// find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 000413c0
void find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi
               (undefined4 param_1,uint *param_2,undefined4 param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_2 & 3;
  puVar1 = param_2;
  if (uVar3 != 0) {
    puVar2 = param_2;
    if ((POPCOUNT(uVar3) & 1U) != 0) {
      if (uVar3 != 2) {
        if ((char)*param_2 == '\0') goto LAB_0004140c;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_0004140c;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_0004140c;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_0004140c;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_0004140b;
    if ((uVar3 & 0xff0000) == 0) goto LAB_0004140a;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004140a:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004140b:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004140c:
  find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,param_2,param_3,(int)puVar2 - (int)param_2);
  return;
}


// find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi  @ 00040130
uint find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
               (int *param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  iVar1 = *(int *)(*param_1 + -0x10);
  if (iVar1 != 0) {
    uVar3 = iVar1 - 1;
    if (param_3 < uVar3) {
      uVar3 = param_3;
    }
    uVar4 = uVar3;
    if (uVar3 != 0xffffffff) {
      do {
        uVar2 = 0;
        if (param_4 != 0) {
          do {
            if (*(char *)(uVar2 + param_2) == *(char *)(*param_1 + uVar4)) goto LAB_00040182;
            uVar2 = uVar2 + 1;
          } while (uVar2 < param_4);
        }
        uVar2 = 0xffffffff;
LAB_00040182:
        if (uVar2 == 0xffffffff) {
          return uVar3;
        }
        uVar3 = uVar3 - 1;
        bVar5 = uVar4 != 0;
        uVar4 = uVar4 - 1;
      } while (bVar5);
    }
  }
  return 0xffffffff;
}


// find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 00041430
void find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
               (undefined4 param_1,int *param_2,undefined4 param_3)

{
  find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,*param_2,param_3,*(undefined4 *)(*param_2 + -0x10));
  return;
}


// find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi  @ 000401b0
uint find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi
               (int *param_1,char param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = *(int *)(*param_1 + -0x10);
  if (iVar1 != 0) {
    uVar2 = iVar1 - 1;
    if (param_3 < uVar2) {
      uVar2 = param_3;
    }
    if (uVar2 != 0xffffffff) {
      do {
        if (*(char *)(uVar2 + *param_1) != param_2) {
          return uVar2;
        }
        bVar3 = uVar2 != 0;
        uVar2 = uVar2 - 1;
      } while (bVar3);
    }
  }
  return 0xffffffff;
}


// find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 00041520
void find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi
               (undefined4 param_1,uint *param_2,undefined4 param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_2 & 3;
  puVar1 = param_2;
  if (uVar3 != 0) {
    puVar2 = param_2;
    if ((POPCOUNT(uVar3) & 1U) != 0) {
      if (uVar3 != 2) {
        if ((char)*param_2 == '\0') goto LAB_0004156c;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_0004156c;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_0004156c;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_0004156c;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_0004156b;
    if ((uVar3 & 0xff0000) == 0) goto LAB_0004156a;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004156a:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004156b:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004156c:
  find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,param_2,param_3,(int)puVar2 - (int)param_2);
  return;
}


// find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi  @ 0003fff0
uint find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
               (int *param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  iVar1 = *(int *)(*param_1 + -0x10);
  if (iVar1 != 0) {
    uVar3 = iVar1 - 1;
    if (param_3 < uVar3) {
      uVar3 = param_3;
    }
    uVar4 = uVar3;
    if (uVar3 != 0xffffffff) {
      do {
        uVar2 = 0;
        if (param_4 != 0) {
          do {
            if (*(char *)(uVar2 + param_2) == *(char *)(*param_1 + uVar4)) goto LAB_00040042;
            uVar2 = uVar2 + 1;
          } while (uVar2 < param_4);
        }
        uVar2 = 0xffffffff;
LAB_00040042:
        if (uVar2 != 0xffffffff) {
          return uVar3;
        }
        uVar3 = uVar3 - 1;
        bVar5 = uVar4 != 0;
        uVar4 = uVar4 - 1;
      } while (bVar5);
    }
  }
  return 0xffffffff;
}


// find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 00041590
void find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
               (undefined4 param_1,int *param_2,undefined4 param_3)

{
  find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,*param_2,param_3,*(undefined4 *)(*param_2 + -0x10));
  return;
}


// find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi  @ 00041500
void find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi
               (undefined4 param_1,char param_2,undefined4 param_3)

{
  rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi
            (param_1,(int)param_2,param_3);
  return;
}


