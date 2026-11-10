// Entity_Encode__FP7delta_sPCUcT1  @ 0008b314
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Entity_Encode__FP7delta_sPCUcT1(undefined4 param_1,int param_2,int param_3)

{
  float fVar1;
  int iVar2;
  code *pcVar3;
  
  if (initialized_710 == 0) {
    Entity_FieldInit__FP7delta_s(param_1);
    initialized_710 = 1;
  }
  iVar2 = (*DAT_001a8048)();
  if (*(int *)(param_3 + 4) + -1 == iVar2) {
    (*DAT_001a8058)(param_1,_DAT_00148180);
    (*DAT_001a8058)(param_1,_DAT_001481a4);
    (*DAT_001a8058)(param_1,_DAT_001481c8);
  }
  fVar1 = *(float *)(param_3 + 0xfc);
  if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
     (fVar1 = *(float *)(param_3 + 0x100),
     (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
    (*DAT_001a8058)(param_1,_DAT_00148180);
    (*DAT_001a8058)(param_1,_DAT_001481a4);
    (*DAT_001a8058)(param_1,_DAT_001481c8);
    (*DAT_001a8058)(param_1,_DAT_001481ec);
    (*DAT_001a8058)(param_1,_DAT_00148210);
    (*DAT_001a8058)(param_1,_DAT_00148234);
  }
  if ((*(int *)(param_3 + 0x58) == 0xc) && (*(int *)(param_3 + 0x94) != 0)) {
    (*DAT_001a8058)(param_1,_DAT_00148180);
    (*DAT_001a8058)(param_1,_DAT_001481a4);
    pcVar3 = DAT_001a8058;
  }
  else {
    if (*(int *)(param_3 + 0x94) == *(int *)(param_2 + 0x94)) {
      return;
    }
    (*DAT_001a8054)(param_1,_DAT_00148180);
    (*DAT_001a8054)(param_1,_DAT_001481a4);
    pcVar3 = DAT_001a8054;
  }
  (*pcVar3)(param_1,_DAT_001481c8);
  return;
}


// Entity_FieldInit__FP7delta_s  @ 0008b258
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Entity_FieldInit__FP7delta_s(undefined4 param_1)

{
  _DAT_00148180 = (*DAT_001a8050)(param_1,entity_field_alias);
  _DAT_001481a4 = (*DAT_001a8050)(param_1,&DAT_00148184);
  _DAT_001481c8 = (*DAT_001a8050)(param_1,&DAT_001481a8);
  _DAT_001481ec = (*DAT_001a8050)(param_1,s_angles_0__001481cc);
  _DAT_00148210 = (*DAT_001a8050)(param_1,s_angles_1__001481f0);
  _DAT_00148234 = (*DAT_001a8050)(param_1,s_angles_2__00148214);
  return;
}


