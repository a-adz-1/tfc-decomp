// Shoot__11CBaseTurretR6VectorT1  @ 00119588
void Shoot__11CBaseTurretR6VectorT1(void)

{
  return;
}


// Shoot__11CMiniTurretR6VectorT1  @ 00117778
void Shoot__11CMiniTurretR6VectorT1(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  float fVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  fVar1 = *(float *)(gpGlobals + 0x14);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_24 = *param_2;
    local_20 = param_2[1];
    local_1c = param_2[2];
    local_18 = *param_3;
    local_14 = param_3[1];
    local_10 = param_3[2];
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    uVar7 = 0;
    uVar6 = 8;
    puVar5 = &local_c;
    puVar2 = &local_24;
  }
  else {
    local_c = *param_2;
    local_8 = param_2[1];
    local_4 = param_2[2];
    local_18 = *param_3;
    local_14 = param_3[1];
    local_10 = param_3[2];
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    uVar7 = 0xf;
    uVar6 = 10;
    puVar5 = &local_24;
    puVar2 = &local_c;
  }
  FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_s
            (param_1,1,puVar2,&local_18,puVar5,0x44960000,uVar6,1,uVar7,0);
  iVar3 = (*DAT_001c1188)(0,2);
  if (iVar3 == 1) {
    uVar6 = *(undefined4 *)(*param_1 + 0x208);
    pcVar4 = "weapons/hks2.wav";
  }
  else if (iVar3 < 2) {
    if (iVar3 != 0) goto LAB_001178ec;
    uVar6 = *(undefined4 *)(*param_1 + 0x208);
    pcVar4 = "weapons/hks1.wav";
  }
  else {
    if (iVar3 != 2) goto LAB_001178ec;
    uVar6 = *(undefined4 *)(*param_1 + 0x208);
    pcVar4 = "weapons/hks3.wav";
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar6,1,pcVar4,0x3f800000,0x3f4ccccd,0,100);
LAB_001178ec:
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 2;
  return;
}


// Shoot__7CSentryR6VectorT1  @ 00118dd4
void Shoot__7CSentryR6VectorT1(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  float fVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  fVar1 = *(float *)(gpGlobals + 0x14);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_24 = *param_2;
    local_20 = param_2[1];
    local_1c = param_2[2];
    local_18 = *param_3;
    local_14 = param_3[1];
    local_10 = param_3[2];
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    uVar7 = 0;
    uVar6 = 9;
    puVar5 = &local_c;
    puVar2 = &local_24;
  }
  else {
    local_c = *param_2;
    local_8 = param_2[1];
    local_4 = param_2[2];
    local_18 = *param_3;
    local_14 = param_3[1];
    local_10 = param_3[2];
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    uVar7 = 10;
    uVar6 = 10;
    puVar5 = &local_24;
    puVar2 = &local_c;
  }
  FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_s
            (param_1,1,puVar2,&local_18,puVar5,0x44960000,uVar6,1,uVar7,0);
  iVar3 = (*DAT_001c1188)(0,2);
  if (iVar3 == 1) {
    uVar6 = *(undefined4 *)(*param_1 + 0x208);
    pcVar4 = "weapons/hks2.wav";
  }
  else if (iVar3 < 2) {
    if (iVar3 != 0) goto LAB_00118f48;
    uVar6 = *(undefined4 *)(*param_1 + 0x208);
    pcVar4 = "weapons/hks1.wav";
  }
  else {
    if (iVar3 != 2) goto LAB_00118f48;
    uVar6 = *(undefined4 *)(*param_1 + 0x208);
    pcVar4 = "weapons/hks3.wav";
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar6,1,pcVar4,0x3f800000,0x3f4ccccd,0,100);
LAB_00118f48:
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 2;
  return;
}


// Shoot__7CTurretR6VectorT1  @ 00117640
void Shoot__7CTurretR6VectorT1(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  float fVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  fVar1 = *(float *)(gpGlobals + 0x14);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_24 = *param_2;
    local_20 = param_2[1];
    local_1c = param_2[2];
    local_18 = *param_3;
    local_14 = param_3[1];
    local_10 = param_3[2];
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    uVar4 = 0;
    puVar3 = &local_c;
    puVar2 = &local_24;
  }
  else {
    local_c = *param_2;
    local_8 = param_2[1];
    local_4 = param_2[2];
    local_18 = *param_3;
    local_14 = param_3[1];
    local_10 = param_3[2];
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    uVar4 = 0x14;
    puVar3 = &local_24;
    puVar2 = &local_c;
  }
  FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_s
            (param_1,1,puVar2,&local_18,puVar3,0x44960000,10,1,uVar4,0);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x208),1,"turret/tu_fire1.wav",0x3f800000,0x3f19999a,0,100);
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 2;
  return;
}


