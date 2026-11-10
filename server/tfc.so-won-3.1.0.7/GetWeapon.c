// GetWeapon__FP9entvars_sT0Pc  @ 0009bfb0
void GetWeapon__FP9entvars_sT0Pc(int *param_1,int *param_2,char *param_3)

{
  int iVar1;
  char *__s1;
  undefined1 local_2c [24];
  char *local_14;
  
  if (param_2[0x82] == 0) {
    (*DAT_001c1134)(0);
  }
  __s1 = "world";
  if ((*(byte *)(param_2 + 0x69) & 8) == 0) {
    iVar1 = param_1[0x82];
    if (iVar1 == 0) {
      iVar1 = (*DAT_001c1134)(0);
      if (iVar1 != 0) goto LAB_0009c119;
      iVar1 = 0;
    }
    else {
LAB_0009c119:
      iVar1 = *(int *)(iVar1 + 0x7c);
    }
    if ((iVar1 == 0) || (*(int *)(iVar1 + 1000) == 0)) {
LAB_0009c140:
      iVar1 = *param_1;
    }
    else {
      iVar1 = *(int *)(iVar1 + 1000);
    }
  }
  else {
    (*DAT_001c113c)(param_2[0x82]);
    if (param_1 == (int *)0x0) goto LAB_0009c153;
    if (param_1 != param_2) {
      iVar1 = param_1[0x82];
      if (iVar1 == 0) {
        iVar1 = (*DAT_001c1134)(0);
        if (iVar1 != 0) goto LAB_0009c0d1;
        iVar1 = 0;
      }
      else {
LAB_0009c0d1:
        iVar1 = *(int *)(iVar1 + 0x7c);
      }
      if ((iVar1 != 0) && (*(int *)(iVar1 + 1000) != 0)) {
        iVar1 = *(int *)(iVar1 + 1000);
        goto LAB_0009c14b;
      }
      goto LAB_0009c140;
    }
    iVar1 = param_1[0x82];
    if (iVar1 == 0) {
      iVar1 = (*DAT_001c1134)(0);
      if (iVar1 != 0) goto LAB_0009c043;
      iVar1 = 0;
    }
    else {
LAB_0009c043:
      iVar1 = *(int *)(iVar1 + 0x7c);
    }
    if (*(int *)(iVar1 + 0x8b4) == 0) goto LAB_0009c153;
    if (*(int *)(*(int *)(iVar1 + 0x8b4) + 1000) == 0) {
      iVar1 = (**(code **)(*(int *)(*(int *)(iVar1 + 0x8b4) + 0x444) + 0x118))
                        (*(undefined4 *)(iVar1 + 0x8b4),local_2c);
      if (iVar1 != 0) {
        __s1 = local_14;
      }
      goto LAB_0009c153;
    }
    iVar1 = *(int *)(*(int *)(iVar1 + 0x8b4) + 1000);
  }
LAB_0009c14b:
  __s1 = (char *)(*(int *)(gpGlobals + 0x98) + iVar1);
LAB_0009c153:
  iVar1 = strncmp(__s1,"weapon_",7);
  if (iVar1 == 0) {
    __s1 = __s1 + 7;
  }
  else {
    iVar1 = strncmp(__s1,"tf_weapon_",10);
    if (iVar1 == 0) {
      __s1 = __s1 + 10;
    }
    else {
      iVar1 = strncmp(__s1,"monster_",8);
      if (iVar1 == 0) {
        __s1 = __s1 + 8;
      }
      else {
        iVar1 = strncmp(__s1,"func_",5);
        if (iVar1 == 0) {
          __s1 = __s1 + 5;
        }
      }
    }
  }
  strcpy(param_3,__s1);
  return;
}


