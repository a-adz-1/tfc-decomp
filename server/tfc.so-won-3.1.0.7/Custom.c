// Custom_Encode__FP7delta_sPCUcT1  @ 000942c0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Custom_Encode__FP7delta_sPCUcT1(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if (initialized_726 == 0) {
    Custom_Entity_FieldInit__FP7delta_s(param_1);
    initialized_726 = 1;
  }
  uVar1 = *(uint *)(param_3 + 0x48) & 0xf;
  if (1 < uVar1) {
    (*DAT_001c1238)(param_1,_DAT_00159dc0);
    (*DAT_001c1238)(param_1,_DAT_00159de4);
    (*DAT_001c1238)(param_1,_DAT_00159e08);
  }
  if (uVar1 != 0) {
    (*DAT_001c1238)(param_1,_DAT_00159e2c);
    (*DAT_001c1238)(param_1,_DAT_00159e50);
    (*DAT_001c1238)(param_1,_DAT_00159e74);
  }
  if (1 < uVar1 - 1) {
    (*DAT_001c1238)(param_1,_DAT_00159e98);
    (*DAT_001c1238)(param_1,_DAT_00159ebc);
  }
  if ((int)ROUND(*(float *)(param_2 + 0x5c)) == (int)ROUND(*(float *)(param_3 + 0x5c))) {
    (*DAT_001c1238)(param_1,_DAT_00159ee0);
  }
  return;
}


// Custom_Entity_FieldInit__FP7delta_s  @ 0009416c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Custom_Entity_FieldInit__FP7delta_s(undefined4 param_1)

{
  _DAT_00159dc0 = (*DAT_001c1230)(param_1,custom_entity_field_alias);
  _DAT_00159de4 = (*DAT_001c1230)(param_1,&DAT_00159dc4);
  _DAT_00159e08 = (*DAT_001c1230)(param_1,&DAT_00159de8);
  _DAT_00159e2c = (*DAT_001c1230)(param_1,s_angles_0__00159e0c);
  _DAT_00159e50 = (*DAT_001c1230)(param_1,s_angles_1__00159e30);
  _DAT_00159e74 = (*DAT_001c1230)(param_1,s_angles_2__00159e54);
  _DAT_00159e98 = (*DAT_001c1230)(param_1,&DAT_00159e78);
  _DAT_00159ebc = (*DAT_001c1230)(param_1,s_sequence_00159e9c);
  _DAT_00159ee0 = (*DAT_001c1230)(param_1,s_animtime_00159ec0);
  return;
}


