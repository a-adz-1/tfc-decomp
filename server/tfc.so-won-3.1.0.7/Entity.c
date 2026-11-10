// Entity_Encode__FP7delta_sPCUcT1  @ 00093dc4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Entity_Encode__FP7delta_sPCUcT1(undefined4 param_1,int param_2,int param_3)

{
  float fVar1;
  int iVar2;
  code *pcVar3;
  
  if (initialized_716 == 0) {
    Entity_FieldInit__FP7delta_s(param_1);
    initialized_716 = 1;
  }
  iVar2 = (*DAT_001c1228)();
  if (*(int *)(param_3 + 4) + -1 == iVar2) {
    (*DAT_001c1238)(param_1,_DAT_00159c60);
    (*DAT_001c1238)(param_1,_DAT_00159c84);
    (*DAT_001c1238)(param_1,_DAT_00159ca8);
  }
  fVar1 = *(float *)(param_3 + 0xfc);
  if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
     (fVar1 = *(float *)(param_3 + 0x100),
     (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
    (*DAT_001c1238)(param_1,_DAT_00159c60);
    (*DAT_001c1238)(param_1,_DAT_00159c84);
    (*DAT_001c1238)(param_1,_DAT_00159ca8);
    (*DAT_001c1238)(param_1,_DAT_00159ccc);
    (*DAT_001c1238)(param_1,_DAT_00159cf0);
    (*DAT_001c1238)(param_1,_DAT_00159d14);
  }
  if ((*(int *)(param_3 + 0x58) == 0xc) && (*(int *)(param_3 + 0x94) != 0)) {
    (*DAT_001c1238)(param_1,_DAT_00159c60);
    (*DAT_001c1238)(param_1,_DAT_00159c84);
    pcVar3 = DAT_001c1238;
  }
  else {
    if (*(int *)(param_3 + 0x94) == *(int *)(param_2 + 0x94)) {
      return;
    }
    (*DAT_001c1234)(param_1,_DAT_00159c60);
    (*DAT_001c1234)(param_1,_DAT_00159c84);
    pcVar3 = DAT_001c1234;
  }
  (*pcVar3)(param_1,_DAT_00159ca8);
  return;
}


// Entity_FieldInit__FP7delta_s  @ 00093d08
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Entity_FieldInit__FP7delta_s(undefined4 param_1)

{
  _DAT_00159c60 = (*DAT_001c1230)(param_1,entity_field_alias);
  _DAT_00159c84 = (*DAT_001c1230)(param_1,&DAT_00159c64);
  _DAT_00159ca8 = (*DAT_001c1230)(param_1,&DAT_00159c88);
  _DAT_00159ccc = (*DAT_001c1230)(param_1,s_angles_0__00159cac);
  _DAT_00159cf0 = (*DAT_001c1230)(param_1,s_angles_1__00159cd0);
  _DAT_00159d14 = (*DAT_001c1230)(param_1,s_angles_2__00159cf4);
  return;
}


