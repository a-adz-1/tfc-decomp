// find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 0004e128
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
        if ((char)*param_2 == '\0') goto LAB_0004e17a;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_0004e17a;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_0004e17a;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_0004e17a;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_0004e179;
    if ((uVar3 & 0xff0000) == 0) goto LAB_0004e178;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e178:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e179:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e17a:
  find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,param_2,param_3,(int)puVar2 - (int)param_2);
  return;
}


// find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi  @ 0004c95c
int find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
              (int *param_1,char *param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  uVar1 = *(uint *)(*param_1 + -0x10);
  if ((uint)(param_4 + param_3) <= uVar1) {
    pcVar3 = (char *)(*param_1 + param_3);
    do {
      if (*pcVar3 == *param_2) {
        bVar6 = true;
        iVar2 = param_4;
        pcVar4 = pcVar3;
        pcVar5 = param_2;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar6 = *pcVar4 == *pcVar5;
          pcVar4 = pcVar4 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (bVar6) {
          return param_3;
        }
      }
      pcVar3 = pcVar3 + 1;
      param_3 = param_3 + 1;
    } while ((uint)(param_4 + param_3) <= uVar1);
  }
  return -1;
}


// find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 0004e100
void find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
               (undefined4 param_1,int *param_2,undefined4 param_3)

{
  find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,*param_2,param_3,*(undefined4 *)(*param_2 + -0x10));
  return;
}


// find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi  @ 0004c9bc
uint find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi
               (int *param_1,char param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = param_3;
  while( true ) {
    if (*(uint *)(*param_1 + -0x10) <= uVar1) {
      return 0xffffffff;
    }
    if (*(char *)(*param_1 + param_3) == param_2) break;
    param_3 = param_3 + 1;
    uVar1 = uVar1 + 1;
  }
  return param_3;
}


// find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 0004e3d0
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
        if ((char)*param_2 == '\0') goto LAB_0004e422;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_0004e422;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_0004e422;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_0004e422;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_0004e421;
    if ((uVar3 & 0xff0000) == 0) goto LAB_0004e420;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e420:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e421:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e422:
  find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,param_2,param_3,(int)puVar2 - (int)param_2);
  return;
}


// find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi  @ 0004cb94
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
        if (*(char *)(uVar1 + param_2) == *(char *)(param_3 + *param_1)) goto LAB_0004cbd2;
        uVar1 = uVar1 + 1;
      } while (uVar1 < param_4);
    }
    uVar1 = 0xffffffff;
LAB_0004cbd2:
    if (uVar1 == 0xffffffff) {
      return param_3;
    }
    param_3 = param_3 + 1;
  } while( true );
}


// find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 0004e3a8
void find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
               (undefined4 param_1,int *param_2,undefined4 param_3)

{
  find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,*param_2,param_3,*(undefined4 *)(*param_2 + -0x10));
  return;
}


// find_first_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi  @ 0004cbf4
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


// find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 0004e270
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
        if ((char)*param_2 == '\0') goto LAB_0004e2c2;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_0004e2c2;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_0004e2c2;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_0004e2c2;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_0004e2c1;
    if ((uVar3 & 0xff0000) == 0) goto LAB_0004e2c0;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e2c0:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e2c1:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e2c2:
  find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,param_2,param_3,(int)puVar2 - (int)param_2);
  return;
}


// find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi  @ 0004cabc
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
        if (*(char *)(uVar1 + param_2) == *(char *)(param_3 + *param_1)) goto LAB_0004cb02;
        uVar1 = uVar1 + 1;
      } while (uVar1 < param_4);
    }
    uVar1 = 0xffffffff;
LAB_0004cb02:
    if (uVar1 != 0xffffffff) {
      return param_3;
    }
    param_3 = param_3 + 1;
  } while( true );
}


// find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 0004e248
void find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
               (undefined4 param_1,int *param_2,undefined4 param_3)

{
  find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,*param_2,param_3,*(undefined4 *)(*param_2 + -0x10));
  return;
}


// find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi  @ 0004e2d8
void find_first_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi
               (undefined4 param_1,char param_2,undefined4 param_3)

{
  find__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi
            (param_1,(int)param_2,param_3);
  return;
}


// find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 0004e460
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
        if ((char)*param_2 == '\0') goto LAB_0004e4b2;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_0004e4b2;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_0004e4b2;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_0004e4b2;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_0004e4b1;
    if ((uVar3 & 0xff0000) == 0) goto LAB_0004e4b0;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e4b0:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e4b1:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e4b2:
  find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,param_2,param_3,(int)puVar2 - (int)param_2);
  return;
}


// find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi  @ 0004cc30
uint find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
               (int *param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  iVar1 = *(int *)(*param_1 + -0x10);
  if (iVar1 != 0) {
    uVar3 = iVar1 - 1;
    if (param_3 < uVar3) {
      uVar3 = param_3;
    }
    if (uVar3 != 0xffffffff) {
      do {
        uVar2 = 0;
        if (param_4 != 0) {
          do {
            if (*(char *)(uVar2 + param_2) == *(char *)(uVar3 + *param_1)) goto LAB_0004cc82;
            uVar2 = uVar2 + 1;
          } while (uVar2 < param_4);
        }
        uVar2 = 0xffffffff;
LAB_0004cc82:
        if (uVar2 == 0xffffffff) {
          return uVar3;
        }
        bVar4 = uVar3 != 0;
        uVar3 = uVar3 - 1;
      } while (bVar4);
    }
  }
  return 0xffffffff;
}


// find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 0004e438
void find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
               (undefined4 param_1,int *param_2,undefined4 param_3)

{
  find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,*param_2,param_3,*(undefined4 *)(*param_2 + -0x10));
  return;
}


// find_last_not_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi  @ 0004cca4
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


// find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 0004e320
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
        if ((char)*param_2 == '\0') goto LAB_0004e372;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_0004e372;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_0004e372;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_0004e372;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_0004e371;
    if ((uVar3 & 0xff0000) == 0) goto LAB_0004e370;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e370:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e371:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e372:
  find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,param_2,param_3,(int)puVar2 - (int)param_2);
  return;
}


// find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi  @ 0004cb24
uint find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
               (int *param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  iVar1 = *(int *)(*param_1 + -0x10);
  if (iVar1 != 0) {
    uVar3 = iVar1 - 1;
    if (param_3 < uVar3) {
      uVar3 = param_3;
    }
    if (uVar3 != 0xffffffff) {
      do {
        uVar2 = 0;
        if (param_4 != 0) {
          do {
            if (*(char *)(uVar2 + param_2) == *(char *)(uVar3 + *param_1)) goto LAB_0004cb72;
            uVar2 = uVar2 + 1;
          } while (uVar2 < param_4);
        }
        uVar2 = 0xffffffff;
LAB_0004cb72:
        if (uVar2 != 0xffffffff) {
          return uVar3;
        }
        bVar4 = uVar3 != 0;
        uVar3 = uVar3 - 1;
      } while (bVar4);
    }
  }
  return 0xffffffff;
}


// find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 0004e2f8
void find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
               (undefined4 param_1,int *param_2,undefined4 param_3)

{
  find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,*param_2,param_3,*(undefined4 *)(*param_2 + -0x10));
  return;
}


// find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi  @ 0004e388
void find_last_of__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi
               (undefined4 param_1,char param_2,undefined4 param_3)

{
  rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi
            (param_1,(int)param_2,param_3);
  return;
}


