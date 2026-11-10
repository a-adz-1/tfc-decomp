// GetWeapon__FP9entvars_sT0Pc  @ 0009b570
void GetWeapon__FP9entvars_sT0Pc(int *param_1,int *param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  char *__s1;
  int iVar3;
  undefined1 auStack_30 [24];
  char *pcStack_18;
  
  if (param_2[0x82] == 0) {
    (*DAT_0019f7b4)(0);
  }
  __s1 = "world";
  if ((*(byte *)(param_2 + 0x69) & 8) == 0) {
    iVar2 = param_1[0x82];
    if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x7c);
    }
    if (iVar2 != 0) {
      iVar2 = *(int *)(iVar2 + 0x3f8);
joined_r0x0009b6ce:
      if (iVar2 != 0) {
LAB_0009b6d0:
        __s1 = (char *)(*(int *)(gpGlobals + 0x98) + iVar2);
        goto LAB_0009b6f7;
      }
    }
  }
  else {
    (*DAT_0019f7bc)(param_2[0x82]);
    if (param_1 == (int *)0x0) goto LAB_0009b6f7;
    if (param_1 == param_2) {
      iVar2 = param_1[0x82];
      if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(iVar2 + 0x7c);
      }
      iVar1 = *(int *)(iVar3 + 0x8dc);
      if (iVar1 == 0) goto LAB_0009b6f7;
      iVar2 = *(int *)(iVar1 + 0x3f8);
      if (iVar2 == 0) {
        iVar2 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x118))
                          (*(undefined4 *)(iVar3 + 0x8dc),auStack_30);
        if (iVar2 != 0) {
          __s1 = pcStack_18;
        }
        goto LAB_0009b6f7;
      }
      goto LAB_0009b6d0;
    }
    iVar2 = param_1[0x82];
    if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x7c);
    }
    if (iVar2 != 0) {
      iVar2 = *(int *)(iVar2 + 0x3f8);
      goto joined_r0x0009b6ce;
    }
  }
  __s1 = (char *)(*param_1 + *(int *)(gpGlobals + 0x98));
LAB_0009b6f7:
  iVar2 = strncmp(__s1,"weapon_",7);
  if (iVar2 == 0) {
    __s1 = __s1 + 7;
  }
  else {
    iVar2 = strncmp(__s1,"tf_weapon_",10);
    if (iVar2 == 0) {
      __s1 = __s1 + 10;
    }
    else {
      iVar2 = strncmp(__s1,"monster_",8);
      if (iVar2 == 0) {
        __s1 = __s1 + 8;
      }
      else {
        iVar2 = strncmp(__s1,"func_",5);
        if (iVar2 == 0) {
          __s1 = __s1 + 5;
        }
      }
    }
  }
  strcpy(param_3,__s1);
  return;
}


