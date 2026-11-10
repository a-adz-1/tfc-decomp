// TEXTURETYPE_Find__FPc  @ 000e31e8
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


// TEXTURETYPE_Init__Fv  @ 000e2fdc
void TEXTURETYPE_Init__Fv(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined1 auStack_208 [4];
  undefined4 local_204;
  char local_200 [512];
  
  if (fTextureTypeInit == 0) {
    memset(grgszTextureName,0,0x1a00);
    memset(&grgchTextureType,0,0x200);
    gcTextures = 0;
    memset(local_200,0,0x200);
    iVar1 = (*DAT_001a7fbc)("sound/materials.txt",&local_204);
    if (iVar1 != 0) {
LAB_000e3192:
      do {
        iVar5 = memfgets__FPUciRiPci(iVar1,local_204,auStack_208,local_200,0x1ff);
        if ((iVar5 == 0) || (0x1ff < gcTextures)) {
          (*DAT_001a7fc0)(iVar1);
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
              goto LAB_000e3104;
            }
            break;
          }
          iVar5 = iVar5 + 1;
        }
      } while( true );
    }
  }
  return;
LAB_000e3104:
  iVar2 = iVar5 + 1;
  if (*pcVar6 == '\0') goto LAB_000e3192;
  iVar3 = isspace((int)*pcVar6);
  if (iVar3 == 0) {
    if (local_200[iVar2] != '\0') {
      pcVar6 = local_200 + iVar5 + 1;
      iVar3 = iVar2;
      goto LAB_000e3134;
    }
    goto LAB_000e3192;
  }
  pcVar6 = pcVar6 + 1;
  iVar5 = iVar2;
  goto LAB_000e3104;
LAB_000e3134:
  if (*pcVar6 == '\0') goto LAB_000e3192;
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
    goto LAB_000e3192;
  }
  pcVar6 = pcVar6 + 1;
  iVar3 = iVar3 + 1;
  goto LAB_000e3134;
}


// TEXTURETYPE_PlaySound__FP11TraceResultG6VectorT1i  @ 000e3248
longdouble
TEXTURETYPE_PlaySound__FP11TraceResultG6VectorT1i
          (int param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  longdouble lVar7;
  undefined4 uStack_7c;
  float fStack_78;
  float fStack_74;
  char cStack_6d;
  code *pcStack_68;
  char *pcStack_64;
  char *pcStack_60;
  char *pcStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  char acStack_40 [12];
  undefined1 uStack_34;
  
  uStack_7c = 0x3f4ccccd;
  iVar2 = (**(code **)(*g_pGameRules + 0xd4))(g_pGameRules);
  if (iVar2 == 0) {
LAB_000e3602:
    fStack_78 = 0.0;
    goto LAB_000e37eb;
  }
  iVar2 = *(int *)(param_1 + 0x30);
  if ((iVar2 == 0) && (iVar2 = (*DAT_001a7f54)(0), iVar2 == 0)) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    puVar6 = *(undefined4 **)(iVar2 + 0x7c);
  }
  cStack_6d = '\0';
  if (((puVar6 == (undefined4 *)0x0) ||
      (iVar2 = (**(code **)(puVar6[0xf5] + 0x28))(puVar6), iVar2 == 0)) ||
     (iVar2 = (**(code **)(puVar6[0xf5] + 0x28))(puVar6), iVar2 == 1)) {
    uStack_4c = *param_2;
    uStack_48 = param_2[1];
    uStack_44 = param_2[2];
    uStack_58 = *param_3;
    uStack_54 = param_3[1];
    uStack_50 = param_3[2];
    if (puVar6 != (undefined4 *)0x0) {
      lVar7 = (longdouble)FUN_000e3380(&uStack_4c,&uStack_58);
      return lVar7;
    }
    uVar5 = (*DAT_001a7f54)(0,&uStack_4c,&uStack_58);
    pcVar3 = (char *)(*DAT_001a7ed0)(uVar5);
    if (pcVar3 != (char *)0x0) {
      if ((*pcVar3 == '-') || (*pcVar3 == '+')) {
        pcVar3 = pcVar3 + 2;
      }
      if (((*pcVar3 == '{') || (*pcVar3 == '!')) || ((*pcVar3 == '~' || (*pcVar3 == ' ')))) {
        pcVar3 = pcVar3 + 1;
      }
      strcpy(acStack_40,pcVar3);
      uStack_34 = 0;
      cStack_6d = TEXTURETYPE_Find__FPc(acStack_40);
    }
  }
  else {
    cStack_6d = 'F';
  }
  switch(cStack_6d) {
  default:
    fStack_74 = 0.9;
    fStack_78 = 0.6;
    pcStack_64 = "player/pl_step2.wav";
    pcStack_68 = (code *)"player/pl_step1.wav";
    break;
  case 'D':
    fStack_74 = 0.9;
    fStack_78 = 0.1;
    pcStack_68 = (code *)0x13c90e;
    pcStack_64 = "player/pl_dirt2.wav";
    pcStack_60 = "player/pl_dirt3.wav";
    goto code_r0x000e35ea;
  case 'F':
    if (param_4 == 5) goto LAB_000e3602;
    fStack_74 = 1.0;
    fStack_78 = 0.2;
    pcStack_68 = (code *)0x13ca95;
    pcStack_64 = "weapons/bullet_hit2.wav";
    uStack_7c = 0x3f800000;
    break;
  case 'G':
    fStack_74 = 0.9;
    fStack_78 = 0.5;
    pcStack_68 = (code *)0x13c95e;
    pcStack_64 = "player/pl_grate4.wav";
    break;
  case 'M':
    fStack_74 = 0.9;
    fStack_78 = 0.3;
    pcStack_68 = (code *)0x13c8e4;
    pcStack_64 = "player/pl_metal2.wav";
    break;
  case 'P':
  case 'Y':
    fStack_74 = 0.8;
    fStack_78 = 0.2;
    pcStack_64 = "debris/glass2.wav";
    pcStack_60 = "debris/glass3.wav";
    pcStack_68 = (code *)"debris/glass1.wav";
    goto code_r0x000e35ea;
  case 'S':
    fStack_74 = 0.9;
    fStack_78 = 0.0;
    pcStack_68 = (code *)0x13c9d8;
    pcStack_64 = "player/pl_slosh3.wav";
    pcStack_60 = "player/pl_slosh2.wav";
    pcStack_5c = "player/pl_slosh4.wav";
    goto code_r0x000e3584;
  case 'T':
    fStack_74 = 0.8;
    fStack_78 = 0.2;
    pcStack_64 = "player/pl_tile3.wav";
    pcStack_60 = "player/pl_tile2.wav";
    pcStack_5c = "player/pl_tile4.wav";
    pcStack_68 = (code *)"player/pl_tile1.wav";
code_r0x000e3584:
    iVar2 = 4;
    goto code_r0x000e3641;
  case 'V':
    fStack_74 = 0.5;
    fStack_78 = 0.3;
    pcStack_68 = (code *)0x13c94a;
    pcStack_64 = "player/pl_duct1.wav";
    break;
  case 'W':
    fStack_74 = 0.9;
    fStack_78 = 0.2;
    pcStack_68 = FUN_0013ca2c;
    pcStack_64 = "debris/wood2.wav";
    pcStack_60 = "debris/wood3.wav";
code_r0x000e35ea:
    iVar2 = 3;
    goto code_r0x000e3641;
  }
  iVar2 = 2;
code_r0x000e3641:
  if ((puVar6 == (undefined4 *)0x0) ||
     (iVar4 = strcmp((char *)(*(int *)*puVar6 + *(int *)(gpGlobals + 0x98)),"func_breakable"),
     iVar4 != 0)) {
    if ((cStack_6d == 'P') &&
       ((fVar1 = *(float *)(param_1 + 0x10),
        (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40 &&
        (iVar4 = (*DAT_001a7fa8)(0,1), iVar4 != 0)))) {
      UTIL_Sparks__FRC6Vector(param_1 + 0x14);
      lVar7 = (longdouble)(*DAT_001a7fac)(0x3f333333,0x3f800000);
      iVar4 = (*DAT_001a7fa8)(0,1);
      if (iVar4 == 0) {
        pcVar3 = "buttons/spark5.wav";
      }
      else {
        if (iVar4 != 1) goto LAB_000e377f;
        pcVar3 = "buttons/spark6.wav";
      }
      uVar5 = (*DAT_001a7f54)(0,param_1 + 0x14,pcVar3,(float)lVar7,0x3f4ccccd,0,100);
      UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii(uVar5);
    }
  }
  else {
    fStack_74 = fStack_74 * 0.6666667;
    fStack_78 = fStack_78 * 0.5;
  }
LAB_000e377f:
  iVar4 = (*DAT_001a7fa8)(0,0xf);
  iVar2 = (*DAT_001a7fa8)(0,iVar2 + -1,fStack_74,uStack_7c,0,iVar4 + 0x60);
  uVar5 = (*DAT_001a7f54)(0,param_1 + 0x14,(&pcStack_68)[iVar2]);
  UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii(uVar5);
LAB_000e37eb:
  return (longdouble)fStack_78;
}


