// Entity_Encode__FP7delta_sPCUcT1  @ 0009301c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Entity_Encode__FP7delta_sPCUcT1(undefined4 param_1,int param_2,int param_3)

{
  float fVar1;
  int iVar2;
  code *pcVar3;
  
  if (initialized_731 == 0) {
    Entity_FieldInit__FP7delta_s(param_1);
    initialized_731 = 1;
  }
  iVar2 = (*DAT_0019f8a8)();
  if (*(int *)(param_3 + 4) + -1 == iVar2) {
    (*DAT_0019f8b8)(param_1,_DAT_0015ed80);
    (*DAT_0019f8b8)(param_1,_DAT_0015eda4);
    (*DAT_0019f8b8)(param_1,_DAT_0015edc8);
  }
  fVar1 = *(float *)(param_3 + 0xfc);
  if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
     (fVar1 = *(float *)(param_3 + 0x100),
     (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
    (*DAT_0019f8b8)(param_1,_DAT_0015ed80);
    (*DAT_0019f8b8)(param_1,_DAT_0015eda4);
    (*DAT_0019f8b8)(param_1,_DAT_0015edc8);
    (*DAT_0019f8b8)(param_1,_DAT_0015edec);
    (*DAT_0019f8b8)(param_1,_DAT_0015ee10);
    (*DAT_0019f8b8)(param_1,_DAT_0015ee34);
  }
  if ((*(int *)(param_3 + 0x58) == 0xc) && (*(int *)(param_3 + 0x94) != 0)) {
    (*DAT_0019f8b8)(param_1,_DAT_0015ed80);
    (*DAT_0019f8b8)(param_1,_DAT_0015eda4);
    pcVar3 = DAT_0019f8b8;
  }
  else {
    if (*(int *)(param_3 + 0x94) == *(int *)(param_2 + 0x94)) {
      return;
    }
    (*DAT_0019f8b4)(param_1,_DAT_0015ed80);
    (*DAT_0019f8b4)(param_1,_DAT_0015eda4);
    pcVar3 = DAT_0019f8b4;
  }
  (*pcVar3)(param_1,_DAT_0015edc8);
  return;
}


// Entity_FieldInit__FP7delta_s  @ 00092f58
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Entity_FieldInit__FP7delta_s(undefined4 param_1)

{
  _DAT_0015ed80 = (*DAT_0019f8b0)(param_1,entity_field_alias);
  _DAT_0015eda4 = (*DAT_0019f8b0)(param_1,&DAT_0015ed84);
  _DAT_0015edc8 = (*DAT_0019f8b0)(param_1,&DAT_0015eda8);
  _DAT_0015edec = (*DAT_0019f8b0)(param_1,s_angles_0__0015edcc);
  _DAT_0015ee10 = (*DAT_0019f8b0)(param_1,s_angles_1__0015edf0);
  _DAT_0015ee34 = (*DAT_0019f8b0)(param_1,s_angles_2__0015ee14);
  return;
}


