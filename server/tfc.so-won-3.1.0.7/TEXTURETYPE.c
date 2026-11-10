// TEXTURETYPE_Find__FPc  @ 000efc24
int TEXTURETYPE_Find__FPc(char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (0 < gcTextures) {
    iVar3 = 0;
    iVar2 = 0;
    do {
      iVar1 = strncasecmp(param_1,grgszTextureName + iVar3,0xc);
      if (iVar1 == 0) {
        return (int)(char)(&grgchTextureType)[iVar2];
      }
      iVar3 = iVar3 + 0xd;
      iVar2 = iVar2 + 1;
    } while (iVar2 < gcTextures);
  }
  return 0x43;
}


// TEXTURETYPE_Init__Fv  @ 000efa08
void TEXTURETYPE_Init__Fv(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 local_208;
  undefined4 local_204;
  char local_200 [512];
  
  local_204 = 0;
  local_208 = 0;
  if (fTextureTypeInit == 0) {
    memset(grgszTextureName,0,0x1a00);
    memset(&grgchTextureType,0,0x200);
    gcTextures = 0;
    memset(local_200,0,0x200);
    iVar1 = (*DAT_001c119c)("sound/materials.txt",&local_204);
    if (iVar1 != 0) {
LAB_000efbce:
      do {
        iVar5 = memfgets__FPUciRiPci(iVar1,local_204,&local_208,local_200,0x1ff);
        if ((iVar5 == 0) || (0x1ff < gcTextures)) {
          (*DAT_001c11a0)(iVar1);
          fTextureTypeInit = 1;
          return;
        }
        iVar5 = 0;
        for (pcVar6 = local_200; *pcVar6 != '\0'; pcVar6 = pcVar6 + 1) {
          iVar2 = isspace((int)*pcVar6);
          if (iVar2 == 0) {
            if (((local_200[iVar5] != '\0') && (local_200[iVar5] != '/')) &&
               (iVar2 = isalpha((int)local_200[iVar5]), iVar2 != 0)) {
              iVar2 = toupper((int)local_200[iVar5]);
              (&grgchTextureType)[gcTextures] = (char)iVar2;
              pcVar6 = local_200 + iVar5 + 1;
              goto LAB_000efb40;
            }
            break;
          }
          iVar5 = iVar5 + 1;
        }
      } while( true );
    }
  }
  return;
LAB_000efb40:
  iVar2 = iVar5 + 1;
  if (*pcVar6 == '\0') goto LAB_000efbce;
  iVar3 = isspace((int)*pcVar6);
  if (iVar3 == 0) {
    if (local_200[iVar2] != '\0') {
      pcVar6 = local_200 + iVar5 + 1;
      iVar3 = iVar2;
      goto LAB_000efb70;
    }
    goto LAB_000efbce;
  }
  pcVar6 = pcVar6 + 1;
  iVar5 = iVar2;
  goto LAB_000efb40;
LAB_000efb70:
  if (*pcVar6 == '\0') goto LAB_000efbce;
  iVar4 = isspace((int)*pcVar6);
  if (iVar4 != 0) {
    if (local_200[iVar3] != '\0') {
      iVar4 = iVar5 + 0xd;
      if (iVar3 < iVar5 + 0xd) {
        iVar4 = iVar3;
      }
      local_200[iVar4] = '\0';
      iVar5 = gcTextures * 0xd;
      gcTextures = gcTextures + 1;
      strcpy(grgszTextureName + iVar5,local_200 + iVar2);
    }
    goto LAB_000efbce;
  }
  pcVar6 = pcVar6 + 1;
  iVar3 = iVar3 + 1;
  goto LAB_000efb70;
}


// TEXTURETYPE_PlaySound__FP11TraceResultG6VectorT1i  @ 000efc84
longdouble
TEXTURETYPE_PlaySound__FP11TraceResultG6VectorT1i
          (int param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  longdouble lVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 local_7c;
  float local_78;
  float local_74;
  char local_6d;
  char *local_68 [4];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  char local_40 [12];
  undefined1 local_34;
  
  local_7c = 0x3f4ccccd;
  iVar2 = (**(code **)(*g_pGameRules + 0xd4))(g_pGameRules);
  if (iVar2 == 0) {
LAB_000f003e:
    local_78 = 0.0;
    goto LAB_000f0227;
  }
  iVar2 = *(int *)(param_1 + 0x30);
  if ((iVar2 == 0) && (iVar2 = (*DAT_001c1134)(0), iVar2 == 0)) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = *(int **)(iVar2 + 0x7c);
  }
  local_6d = '\0';
  if (((piVar6 == (int *)0x0) || (iVar2 = (**(code **)(piVar6[0x111] + 0x2c))(piVar6), iVar2 == 0))
     || (iVar2 = (**(code **)(piVar6[0x111] + 0x2c))(piVar6), iVar2 == 1)) {
    local_4c = *param_2;
    local_48 = param_2[1];
    local_44 = param_2[2];
    local_58 = *param_3;
    local_54 = param_3[1];
    local_50 = param_3[2];
    if (piVar6 == (int *)0x0) {
      puVar9 = &local_58;
      puVar8 = &local_4c;
      uVar5 = (*DAT_001c1134)(0,puVar8,puVar9);
    }
    else {
      puVar9 = &local_58;
      puVar8 = &local_4c;
      uVar5 = *(undefined4 *)(*piVar6 + 0x208);
    }
    pcVar3 = (char *)(*DAT_001c10b0)(uVar5,puVar8,puVar9);
    if (pcVar3 != (char *)0x0) {
      if ((*pcVar3 == '-') || (*pcVar3 == '+')) {
        pcVar3 = pcVar3 + 2;
      }
      if (((*pcVar3 == '{') || (*pcVar3 == '!')) || ((*pcVar3 == '~' || (*pcVar3 == ' ')))) {
        pcVar3 = pcVar3 + 1;
      }
      strcpy(local_40,pcVar3);
      local_34 = 0;
      local_6d = TEXTURETYPE_Find__FPc(local_40);
    }
  }
  else {
    local_6d = 'F';
  }
  switch(local_6d) {
  default:
    local_74 = 0.9;
    local_78 = 0.6;
    local_68[0] = "player/pl_step1.wav";
    local_68[1] = "player/pl_step2.wav";
    break;
  case 'D':
    local_74 = 0.9;
    local_78 = 0.1;
    local_68[0] = "player/pl_dirt1.wav";
    local_68[1] = "player/pl_dirt2.wav";
    local_68[2] = "player/pl_dirt3.wav";
    goto LAB_000f0026;
  case 'F':
    if (param_4 == 5) goto LAB_000f003e;
    local_74 = 1.0;
    local_78 = 0.2;
    local_68[0] = "weapons/bullet_hit1.wav";
    local_68[1] = "weapons/bullet_hit2.wav";
    local_7c = 0x3f800000;
    break;
  case 'G':
    local_74 = 0.9;
    local_78 = 0.5;
    local_68[0] = "player/pl_grate1.wav";
    local_68[1] = "player/pl_grate4.wav";
    break;
  case 'M':
    local_74 = 0.9;
    local_78 = 0.3;
    local_68[0] = "player/pl_metal1.wav";
    local_68[1] = "player/pl_metal2.wav";
    break;
  case 'P':
  case 'Y':
    local_74 = 0.8;
    local_78 = 0.2;
    local_68[0] = "debris/glass1.wav";
    local_68[1] = "debris/glass2.wav";
    local_68[2] = "debris/glass3.wav";
    goto LAB_000f0026;
  case 'S':
    local_74 = 0.9;
    local_78 = 0.0;
    local_68[0] = "player/pl_slosh1.wav";
    local_68[1] = "player/pl_slosh3.wav";
    local_68[2] = "player/pl_slosh2.wav";
    local_68[3] = "player/pl_slosh4.wav";
    goto LAB_000effc0;
  case 'T':
    local_74 = 0.8;
    local_78 = 0.2;
    local_68[0] = "player/pl_tile1.wav";
    local_68[1] = "player/pl_tile3.wav";
    local_68[2] = "player/pl_tile2.wav";
    local_68[3] = "player/pl_tile4.wav";
LAB_000effc0:
    iVar2 = 4;
    goto LAB_000f007d;
  case 'V':
    local_74 = 0.5;
    local_78 = 0.3;
    local_68[0] = "player/pl_duct1.wav";
    local_68[1] = "player/pl_duct1.wav";
    break;
  case 'W':
    local_74 = 0.9;
    local_78 = 0.2;
    local_68[0] = "debris/wood1.wav";
    local_68[1] = "debris/wood2.wav";
    local_68[2] = "debris/wood3.wav";
LAB_000f0026:
    iVar2 = 3;
    goto LAB_000f007d;
  }
  iVar2 = 2;
LAB_000f007d:
  if ((piVar6 == (int *)0x0) ||
     (iVar4 = strcmp((char *)(*(int *)*piVar6 + *(int *)(gpGlobals + 0x98)),"func_breakable"),
     iVar4 != 0)) {
    if ((local_6d == 'P') &&
       ((fVar1 = *(float *)(param_1 + 0x10),
        (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40 &&
        (iVar4 = (*DAT_001c1188)(0,1), iVar4 != 0)))) {
      UTIL_Sparks__FRC6Vector(param_1 + 0x14);
      lVar7 = (longdouble)(*DAT_001c118c)(0x3f333333,0x3f800000);
      iVar4 = (*DAT_001c1188)(0,1);
      if (iVar4 == 0) {
        pcVar3 = "buttons/spark5.wav";
      }
      else {
        if (iVar4 != 1) goto LAB_000f01bb;
        pcVar3 = "buttons/spark6.wav";
      }
      uVar5 = (*DAT_001c1134)(0,param_1 + 0x14,pcVar3,(float)lVar7,0x3f4ccccd,0,100);
      UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii(uVar5);
    }
  }
  else {
    local_74 = local_74 * 0.6666667;
    local_78 = local_78 * 0.5;
  }
LAB_000f01bb:
  iVar4 = (*DAT_001c1188)(0,0xf);
  iVar2 = (*DAT_001c1188)(0,iVar2 + -1,local_74,local_7c,0,iVar4 + 0x60);
  uVar5 = (*DAT_001c1134)(0,param_1 + 0x14,local_68[iVar2]);
  UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii(uVar5);
LAB_000f0227:
  return (longdouble)local_78;
}


