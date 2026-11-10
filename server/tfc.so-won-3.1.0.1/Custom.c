// Custom_Encode__FP7delta_sPCUcT1  @ 0008b810
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Custom_Encode__FP7delta_sPCUcT1(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if (initialized_720 == 0) {
    Custom_Entity_FieldInit__FP7delta_s(param_1);
    initialized_720 = 1;
  }
  uVar1 = *(uint *)(param_3 + 0x48) & 0xf;
  if (1 < uVar1) {
    (*DAT_001a8058)(param_1,_DAT_001482e0);
    (*DAT_001a8058)(param_1,_DAT_00148304);
    (*DAT_001a8058)(param_1,_DAT_00148328);
  }
  if (uVar1 != 0) {
    (*DAT_001a8058)(param_1,_DAT_0014834c);
    (*DAT_001a8058)(param_1,_DAT_00148370);
    (*DAT_001a8058)(param_1,_DAT_00148394);
  }
  if (1 < uVar1 - 1) {
    (*DAT_001a8058)(param_1,_DAT_001483b8);
    (*DAT_001a8058)(param_1,_DAT_001483dc);
  }
  if ((int)ROUND(*(float *)(param_2 + 0x5c)) == (int)ROUND(*(float *)(param_3 + 0x5c))) {
    (*DAT_001a8058)(param_1,_DAT_00148400);
  }
  return;
}


// Custom_Entity_FieldInit__FP7delta_s  @ 0008b6bc
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Custom_Entity_FieldInit__FP7delta_s(undefined4 param_1)

{
  _DAT_001482e0 = (*DAT_001a8050)(param_1,custom_entity_field_alias);
  _DAT_00148304 = (*DAT_001a8050)(param_1,&DAT_001482e4);
  _DAT_00148328 = (*DAT_001a8050)(param_1,&DAT_00148308);
  _DAT_0014834c = (*DAT_001a8050)(param_1,s_angles_0__0014832c);
  _DAT_00148370 = (*DAT_001a8050)(param_1,s_angles_1__00148350);
  _DAT_00148394 = (*DAT_001a8050)(param_1,s_angles_2__00148374);
  _DAT_001483b8 = (*DAT_001a8050)(param_1,&DAT_00148398);
  _DAT_001483dc = (*DAT_001a8050)(param_1,s_sequence_001483bc);
  _DAT_00148400 = (*DAT_001a8050)(param_1,s_animtime_001483e0);
  return;
}


