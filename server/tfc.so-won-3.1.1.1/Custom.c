// Custom_Encode__FP7delta_sPCUcT1  @ 00093508
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Custom_Encode__FP7delta_sPCUcT1(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if (initialized_741 == 0) {
    Custom_Entity_FieldInit__FP7delta_s(param_1);
    initialized_741 = 1;
  }
  uVar1 = *(uint *)(param_3 + 0x48) & 0xf;
  if (1 < uVar1) {
    (*DAT_0019f8b8)(param_1,_DAT_0015eee0);
    (*DAT_0019f8b8)(param_1,_DAT_0015ef04);
    (*DAT_0019f8b8)(param_1,_DAT_0015ef28);
  }
  if (uVar1 != 0) {
    (*DAT_0019f8b8)(param_1,_DAT_0015ef4c);
    (*DAT_0019f8b8)(param_1,_DAT_0015ef70);
    (*DAT_0019f8b8)(param_1,_DAT_0015ef94);
  }
  if (1 < uVar1 - 1) {
    (*DAT_0019f8b8)(param_1,_DAT_0015efb8);
    (*DAT_0019f8b8)(param_1,_DAT_0015efdc);
  }
  if ((int)ROUND(*(float *)(param_2 + 0x5c)) == (int)ROUND(*(float *)(param_3 + 0x5c))) {
    (*DAT_0019f8b8)(param_1,_DAT_0015f000);
  }
  return;
}


// Custom_Entity_FieldInit__FP7delta_s  @ 000933ac
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Custom_Entity_FieldInit__FP7delta_s(undefined4 param_1)

{
  _DAT_0015eee0 = (*DAT_0019f8b0)(param_1,custom_entity_field_alias);
  _DAT_0015ef04 = (*DAT_0019f8b0)(param_1,&DAT_0015eee4);
  _DAT_0015ef28 = (*DAT_0019f8b0)(param_1,&DAT_0015ef08);
  _DAT_0015ef4c = (*DAT_0019f8b0)(param_1,s_angles_0__0015ef2c);
  _DAT_0015ef70 = (*DAT_0019f8b0)(param_1,s_angles_1__0015ef50);
  _DAT_0015ef94 = (*DAT_0019f8b0)(param_1,s_angles_2__0015ef74);
  _DAT_0015efb8 = (*DAT_0019f8b0)(param_1,&DAT_0015ef98);
  _DAT_0015efdc = (*DAT_0019f8b0)(param_1,s_sequence_0015efbc);
  _DAT_0015f000 = (*DAT_0019f8b0)(param_1,s_animtime_0015efe0);
  return;
}


