// TEXTURETYPE_Find__FPc  @ 000ed460
int TEXTURETYPE_Find__FPc(char *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < gcTextures) {
    do {
      iVar1 = strncasecmp(param_1,grgszTextureName + iVar2 * 0xd,0xc);
      if (iVar1 == 0) {
        return (int)(char)(&grgchTextureType)[iVar2];
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < gcTextures);
  }
  return 0x43;
}


// TEXTURETYPE_Init__Fv  @ 000ed250
void TEXTURETYPE_Init__Fv(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_20c [4];
  undefined4 local_208;
  char local_204 [512];
  
  if (fTextureTypeInit == 0) {
    memset(grgszTextureName,0,0x1a00);
    memset(&grgchTextureType,0,0x200);
    gcTextures = 0;
    memset(local_204,0,0x200);
    iVar1 = (*DAT_0017563c)("sound/materials.txt",&local_208);
    if (iVar1 != 0) {
LAB_000ed406:
      do {
        iVar5 = memfgets__FPUciRiPci(iVar1,local_208,auStack_20c,local_204,0x1ff);
        if ((iVar5 == 0) || (0x1ff < gcTextures)) {
          (*DAT_00175640)(iVar1);
          fTextureTypeInit = 1;
          return;
        }
        for (iVar5 = 0; local_204[iVar5] != '\0'; iVar5 = iVar5 + 1) {
          iVar2 = isspace((int)local_204[iVar5]);
          if (iVar2 == 0) {
            if (((local_204[iVar5] != '\0') && (local_204[iVar5] != '/')) &&
               (iVar2 = isalpha((int)local_204[iVar5]), iVar2 != 0)) {
              iVar2 = toupper((int)local_204[iVar5]);
              (&grgchTextureType)[gcTextures] = (char)iVar2;
              goto LAB_000ed36c;
            }
            break;
          }
        }
      } while( true );
    }
  }
  return;
  while (iVar3 = isspace((int)local_204[iVar2 + 1]), iVar3 != 0) {
LAB_000ed36c:
    iVar2 = iVar5;
    iVar5 = iVar2 + 1;
    if (local_204[iVar2 + 1] == '\0') goto LAB_000ed406;
  }
  iVar3 = iVar5;
  if (local_204[iVar5] != '\0') {
    for (; local_204[iVar3] != '\0'; iVar3 = iVar3 + 1) {
      iVar4 = isspace((int)local_204[iVar3]);
      if (iVar4 != 0) {
        if (local_204[iVar3] != '\0') {
          iVar4 = iVar2 + 0xd;
          if (iVar3 < iVar2 + 0xd) {
            iVar4 = iVar3;
          }
          local_204[iVar4] = '\0';
          iVar2 = gcTextures * 0xd;
          gcTextures = gcTextures + 1;
          strcpy(grgszTextureName + iVar2,local_204 + iVar5);
        }
        break;
      }
    }
  }
  goto LAB_000ed406;
}


// TEXTURETYPE_PlaySound__FP11TraceResultG6VectorT1i  @ 000ed4c0
longdouble
TEXTURETYPE_PlaySound__FP11TraceResultG6VectorT1i
          (int param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  longdouble lVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 local_80;
  float fStack_7c;
  float fStack_78;
  char cStack_71;
  char *apcStack_6c [4];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  char acStack_44 [12];
  undefined1 uStack_38;
  
  local_80 = 0x3f4ccccd;
  iVar2 = (**(code **)(*g_pGameRules + 0xd4))(g_pGameRules);
  if (iVar2 == 0) {
LAB_000ed7f6:
    return (longdouble)0;
  }
  iVar2 = *(int *)(param_1 + 0x30);
  if ((iVar2 == 0) && (iVar2 = (*DAT_001755d4)(0), iVar2 == 0)) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = *(int **)(iVar2 + 0xd8);
  }
  cStack_71 = '\0';
  if (((piVar6 == (int *)0x0) || (iVar2 = (**(code **)(piVar6[0xf2] + 0x28))(piVar6), iVar2 == 0))
     || (iVar2 = (**(code **)(piVar6[0xf2] + 0x28))(piVar6), iVar2 == 1)) {
    uStack_50 = *param_2;
    uStack_4c = param_2[1];
    uStack_48 = param_2[2];
    uStack_5c = *param_3;
    uStack_58 = param_3[1];
    uStack_54 = param_3[2];
    if (piVar6 == (int *)0x0) {
      puVar9 = &uStack_5c;
      puVar8 = &uStack_50;
      uVar3 = (*DAT_001755d4)(0,puVar8,puVar9);
    }
    else {
      puVar9 = &uStack_5c;
      puVar8 = &uStack_50;
      uVar3 = *(undefined4 *)(*piVar6 + 0x1e8);
    }
    pcVar4 = (char *)(*DAT_00175550)(uVar3,puVar8,puVar9);
    if (pcVar4 != (char *)0x0) {
      if ((*pcVar4 == '-') || (*pcVar4 == '+')) {
        pcVar4 = pcVar4 + 2;
      }
      if (((*pcVar4 == '{') || (*pcVar4 == '!')) || ((*pcVar4 == '~' || (*pcVar4 == ' ')))) {
        pcVar4 = pcVar4 + 1;
      }
      strcpy(acStack_44,pcVar4);
      uStack_38 = 0;
      cStack_71 = TEXTURETYPE_Find__FPc(acStack_44);
    }
  }
  else {
    cStack_71 = 'F';
  }
  switch(cStack_71) {
  default:
    apcStack_6c[0] = "player/pl_step1.wav";
    apcStack_6c[1] = "player/pl_step2.wav";
    lVar7 = (longdouble)FUN_000ed822();
    return lVar7;
  case 'D':
    fStack_78 = 0.9;
    fStack_7c = 0.1;
    apcStack_6c[0] = "player/pl_dirt1.wav";
    apcStack_6c[1] = "player/pl_dirt2.wav";
    apcStack_6c[2] = "player/pl_dirt3.wav";
    iVar2 = 3;
    break;
  case 'F':
    if (param_4 == 5) goto LAB_000ed7f6;
    fStack_78 = 1.0;
    fStack_7c = 0.2;
    apcStack_6c[0] = "weapons/bullet_hit1.wav";
    apcStack_6c[1] = "weapons/bullet_hit2.wav";
    local_80 = 0x3f800000;
    iVar2 = 2;
    break;
  case 'G':
    apcStack_6c[0] = "player/pl_grate1.wav";
    apcStack_6c[1] = "player/pl_grate4.wav";
    lVar7 = (longdouble)FUN_000ed822();
    return lVar7;
  case 'M':
    apcStack_6c[0] = "player/pl_metal1.wav";
    apcStack_6c[1] = "player/pl_metal2.wav";
    lVar7 = (longdouble)FUN_000ed822();
    return lVar7;
  case 'P':
  case 'Y':
    fStack_78 = 0.8;
    fStack_7c = 0.2;
    apcStack_6c[0] = "debris/glass1.wav";
    apcStack_6c[1] = "debris/glass2.wav";
    apcStack_6c[2] = "debris/glass3.wav";
    iVar2 = 3;
    break;
  case 'S':
    fStack_78 = 0.9;
    fStack_7c = 0.0;
    apcStack_6c[0] = "player/pl_slosh1.wav";
    apcStack_6c[1] = "player/pl_slosh3.wav";
    apcStack_6c[2] = "player/pl_slosh2.wav";
    apcStack_6c[3] = "player/pl_slosh4.wav";
    iVar2 = 4;
    break;
  case 'T':
    fStack_78 = 0.8;
    fStack_7c = 0.2;
    apcStack_6c[0] = "player/pl_tile1.wav";
    apcStack_6c[1] = "player/pl_tile3.wav";
    apcStack_6c[2] = "player/pl_tile2.wav";
    apcStack_6c[3] = "player/pl_tile4.wav";
    iVar2 = 4;
    break;
  case 'V':
    apcStack_6c[0] = "player/pl_duct1.wav";
    apcStack_6c[1] = "player/pl_duct1.wav";
    lVar7 = (longdouble)FUN_000ed822();
    return lVar7;
  case 'W':
    fStack_78 = 0.9;
    fStack_7c = 0.2;
    apcStack_6c[0] = "debris/wood1.wav";
    apcStack_6c[1] = "debris/wood2.wav";
    apcStack_6c[2] = "debris/wood3.wav";
    iVar2 = 3;
  }
  if ((piVar6 == (int *)0x0) ||
     (iVar5 = strcmp((char *)(*(int *)*piVar6 + *(int *)(gpGlobals + 0x98)),"func_breakable"),
     iVar5 != 0)) {
    if ((cStack_71 == 'P') &&
       ((fVar1 = *(float *)(param_1 + 0x10),
        (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40 &&
        (iVar5 = (*DAT_00175628)(0,1), iVar5 != 0)))) {
      UTIL_Sparks__FRC6Vector(param_1 + 0x14);
      lVar7 = (longdouble)(*DAT_0017562c)(0x3f333333,0x3f800000);
      iVar5 = (*DAT_00175628)(0,1);
      if (iVar5 == 0) {
        pcVar4 = "buttons/spark5.wav";
      }
      else {
        if (iVar5 != 1) goto LAB_000ed93d;
        pcVar4 = "buttons/spark6.wav";
      }
      uVar3 = (*DAT_001755d4)(0,param_1 + 0x14,pcVar4,(float)lVar7,0x3f4ccccd,0,100);
      UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii(uVar3);
    }
  }
  else {
    fStack_78 = fStack_78 / 1.5;
    fStack_7c = fStack_7c * 0.5;
  }
LAB_000ed93d:
  iVar5 = (*DAT_00175628)(0,0xf);
  iVar2 = (*DAT_00175628)(0,iVar2 + -1,fStack_78,local_80,0,iVar5 + 0x60);
  uVar3 = (*DAT_001755d4)(0,param_1 + 0x14,apcStack_6c[iVar2]);
  UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii(uVar3);
  return (longdouble)fStack_7c;
}


