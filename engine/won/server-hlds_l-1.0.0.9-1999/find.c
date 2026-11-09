// find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 08098da4
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
        if ((char)*param_2 == '\0') goto LAB_08098df0;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08098df0;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08098df0;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_08098df0;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_08098def;
    if ((uVar3 & 0xff0000) == 0) goto LAB_08098dee;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098dee:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098def:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098df0:
  find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,param_2,param_3,(int)puVar2 - (int)param_2);
  return;
}


// find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi  @ 08097764
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


// find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 08098e08
void find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
               (undefined4 param_1,int *param_2,undefined4 param_3)

{
  find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,*param_2,param_3,*(undefined4 *)(*param_2 + -0x10));
  return;
}


// find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi  @ 080977cc
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


// find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 08098b20
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
        if ((char)*param_2 == '\0') goto LAB_08098b6c;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08098b6c;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08098b6c;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_08098b6c;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_08098b6b;
    if ((uVar3 & 0xff0000) == 0) goto LAB_08098b6a;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098b6a:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098b6b:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098b6c:
  find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,param_2,param_3,(int)puVar2 - (int)param_2);
  return;
}


// find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi  @ 08097984
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
        if (*(char *)(uVar1 + param_2) == *(char *)(param_3 + *param_1)) goto LAB_080979c2;
        uVar1 = uVar1 + 1;
      } while (uVar1 < param_4);
    }
    uVar1 = 0xffffffff;
LAB_080979c2:
    if (uVar1 == 0xffffffff) {
      return param_3;
    }
    param_3 = param_3 + 1;
  } while( true );
}


// find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 08098b84
void find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
               (undefined4 param_1,int *param_2,undefined4 param_3)

{
  find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,*param_2,param_3,*(undefined4 *)(*param_2 + -0x10));
  return;
}


// find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi  @ 080979e0
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


// find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 08098c68
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
        if ((char)*param_2 == '\0') goto LAB_08098cb4;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08098cb4;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08098cb4;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_08098cb4;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_08098cb3;
    if ((uVar3 & 0xff0000) == 0) goto LAB_08098cb2;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098cb2:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098cb3:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098cb4:
  find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,param_2,param_3,(int)puVar2 - (int)param_2);
  return;
}


// find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi  @ 080978b4
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
        if (*(char *)(uVar1 + param_2) == *(char *)(param_3 + *param_1)) goto LAB_080978f2;
        uVar1 = uVar1 + 1;
      } while (uVar1 < param_4);
    }
    uVar1 = 0xffffffff;
LAB_080978f2:
    if (uVar1 != 0xffffffff) {
      return param_3;
    }
    param_3 = param_3 + 1;
  } while( true );
}


// find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 08098ccc
void find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
               (undefined4 param_1,int *param_2,undefined4 param_3)

{
  find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,*param_2,param_3,*(undefined4 *)(*param_2 + -0x10));
  return;
}


// find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi  @ 08098c4c
void find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi
               (undefined4 param_1,char param_2,undefined4 param_3)

{
  find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi
            (param_1,(int)param_2,param_3);
  return;
}


// find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 08098a98
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
        if ((char)*param_2 == '\0') goto LAB_08098ae4;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08098ae4;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08098ae4;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_08098ae4;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_08098ae3;
    if ((uVar3 & 0xff0000) == 0) goto LAB_08098ae2;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098ae2:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098ae3:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098ae4:
  find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,param_2,param_3,(int)puVar2 - (int)param_2);
  return;
}


// find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi  @ 08097a1c
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
            if (*(char *)(uVar2 + param_2) == *(char *)(*param_1 + uVar4)) goto LAB_08097a6e;
            uVar2 = uVar2 + 1;
          } while (uVar2 < param_4);
        }
        uVar2 = 0xffffffff;
LAB_08097a6e:
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


// find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 08098afc
void find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
               (undefined4 param_1,int *param_2,undefined4 param_3)

{
  find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,*param_2,param_3,*(undefined4 *)(*param_2 + -0x10));
  return;
}


// find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi  @ 08097a90
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


// find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 08098bc4
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
        if ((char)*param_2 == '\0') goto LAB_08098c10;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08098c10;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08098c10;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_08098c10;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_08098c0f;
    if ((uVar3 & 0xff0000) == 0) goto LAB_08098c0e;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098c0e:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098c0f:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098c10:
  find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,param_2,param_3,(int)puVar2 - (int)param_2);
  return;
}


// find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi  @ 08097910
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
            if (*(char *)(uVar2 + param_2) == *(char *)(*param_1 + uVar4)) goto LAB_08097962;
            uVar2 = uVar2 + 1;
          } while (uVar2 < param_4);
        }
        uVar2 = 0xffffffff;
LAB_08097962:
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


// find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 08098c28
void find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
               (undefined4 param_1,int *param_2,undefined4 param_3)

{
  find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,*param_2,param_3,*(undefined4 *)(*param_2 + -0x10));
  return;
}


// find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi  @ 08098ba8
void find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi
               (undefined4 param_1,char param_2,undefined4 param_3)

{
  rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi
            (param_1,(int)param_2,param_3);
  return;
}


