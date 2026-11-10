// TEXTURETYPE_Find__FPc  @ 000f20c8
int TEXTURETYPE_Find__FPc(char *param_1)

{
  int iVar1;
  int iVar2;
  
  if (0 < gcTextures) {
    iVar2 = 0;
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


// TEXTURETYPE_Init__Fv  @ 000f1190
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void TEXTURETYPE_Init__Fv(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  size_t __n;
  int iVar6;
  int iVar7;
  int local_20c;
  int local_208;
  char local_204 [512];
  
  local_208 = 0;
  local_20c = 0;
  if (fTextureTypeInit == 0) {
    memset(grgszTextureName,0,0x1a00);
    memset(&grgchTextureType,0,0x200);
    gcTextures = 0;
    memset(local_204,0,0x200);
    iVar3 = (*DAT_0019f81c)("sound/materials.txt",&local_208);
    if (iVar3 != 0) {
      do {
        if ((iVar3 == 0) || (local_208 <= local_20c)) {
LAB_000f143e:
          (*DAT_0019f820)(iVar3);
          fTextureTypeInit = 1;
          return;
        }
        iVar6 = local_208;
        if (0x1fe < local_208 - local_20c) {
          iVar6 = local_20c + 0x1fe;
        }
        bVar2 = false;
        iVar7 = local_20c;
        if (local_20c < iVar6) {
          do {
            if (*(char *)(iVar7 + iVar3) == '\n') {
              bVar2 = true;
            }
            iVar7 = iVar7 + 1;
          } while ((iVar7 < iVar6) && (!bVar2));
        }
        if (iVar7 == local_20c) {
          pcVar5 = (char *)0x0;
        }
        else {
          __n = iVar7 - local_20c;
          memcpy(local_204,(void *)(local_20c + iVar3),__n);
          pcVar5 = local_204;
          local_20c = iVar7;
          if ((int)__n < 0x1ff) {
            local_204[__n] = '\0';
          }
        }
        if ((pcVar5 == (char *)0x0) || (0x1ff < gcTextures)) goto LAB_000f143e;
        iVar6 = 0;
        if (local_204[0] != '\0') {
          do {
            iVar7 = isspace((int)local_204[iVar6]);
            if (iVar7 == 0) break;
            iVar6 = iVar6 + 1;
          } while (local_204[iVar6] != '\0');
          cVar1 = local_204[iVar6];
          if (((cVar1 != '\0') && (cVar1 != '/')) && (iVar7 = isalpha((int)cVar1), iVar7 != 0)) {
            iVar7 = iVar6 + 1;
            iVar6 = toupper((int)local_204[iVar6]);
            (&grgchTextureType)[gcTextures] = (char)iVar6;
            if (local_204[iVar7] != '\0') {
              do {
                iVar6 = isspace((int)local_204[iVar7]);
                if (iVar6 == 0) break;
                iVar7 = iVar7 + 1;
              } while (local_204[iVar7] != '\0');
              iVar6 = iVar7;
              if (local_204[iVar7] != '\0') {
                for (; local_204[iVar6] != '\0'; iVar6 = iVar6 + 1) {
                  iVar4 = isspace((int)local_204[iVar6]);
                  if (iVar4 != 0) {
                    if (local_204[iVar6] != '\0') {
                      iVar4 = iVar7 + 0xc;
                      if (iVar6 < iVar7 + 0xc) {
                        iVar4 = iVar6;
                      }
                      local_204[iVar4] = '\0';
                      iVar6 = gcTextures * 0xd;
                      gcTextures = gcTextures + 1;
                      strcpy(grgszTextureName + iVar6,local_204 + iVar7);
                    }
                    break;
                  }
                }
              }
            }
          }
        }
      } while( true );
    }
  }
  return;
}


// TEXTURETYPE_PlaySound__FP11TraceResultG6VectorT1i  @ 000f146c
longdouble
TEXTURETYPE_PlaySound__FP11TraceResultG6VectorT1i
          (int param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  char cVar6;
  longdouble lVar7;
  int *local_84;
  undefined4 local_80;
  float local_7c;
  float local_78;
  char local_74;
  char *local_6c;
  code *local_68;
  char *local_64;
  char *local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  char local_44 [12];
  undefined1 local_38;
  
  local_80 = 0x3f4ccccd;
  iVar2 = (**(code **)(*g_pGameRules + 0xd4))(g_pGameRules);
  if (iVar2 == 0) {
LAB_000f186a:
    return (longdouble)0;
  }
  iVar2 = *(int *)(param_1 + 0x30);
  if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
    local_84 = (int *)0x0;
  }
  else {
    local_84 = *(int **)(iVar2 + 0x7c);
  }
  local_74 = '\0';
  if (((local_84 == (int *)0x0) ||
      (iVar2 = (**(code **)(local_84[0x115] + 0x2c))(local_84), iVar2 == 0)) ||
     (iVar2 = (**(code **)(local_84[0x115] + 0x2c))(local_84), iVar2 == 1)) {
    local_50 = *param_2;
    local_4c = param_2[1];
    local_48 = param_2[2];
    local_5c = *param_3;
    local_58 = param_3[1];
    local_54 = param_3[2];
    if (local_84 == (int *)0x0) {
      uVar5 = (*DAT_0019f7b4)(0,&local_50,&local_5c);
      pcVar3 = (char *)(*DAT_0019f730)(uVar5);
    }
    else {
      pcVar3 = (char *)(*DAT_0019f730)(*(undefined4 *)(*local_84 + 0x208),&local_50,&local_5c);
    }
    if (pcVar3 != (char *)0x0) {
      cVar6 = *pcVar3;
      if ((cVar6 == '-') || (cVar6 == '+')) {
        pcVar3 = pcVar3 + 2;
        cVar6 = *pcVar3;
      }
      if (((cVar6 == '{') || (cVar6 == '!')) || ((cVar6 == '~' || (cVar6 == ' ')))) {
        pcVar3 = pcVar3 + 1;
      }
      strcpy(local_44,pcVar3);
      local_38 = 0;
      iVar2 = 0;
      if (0 < gcTextures) {
        do {
          iVar4 = strncasecmp(local_44,grgszTextureName + iVar2 * 0xd,0xc);
          if (iVar4 == 0) {
            local_74 = (&grgchTextureType)[iVar2];
            goto LAB_000f1647;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < gcTextures);
      }
      local_74 = 'C';
    }
  }
  else {
    local_74 = 'F';
  }
LAB_000f1647:
  switch(local_74) {
  default:
    local_6c = "player/pl_step1.wav";
    iVar2 = 2;
    local_78 = 0.9;
    local_7c = 0.6;
    local_68 = (code *)"player/pl_step2.wav";
    break;
  case 'D':
    local_6c = "player/pl_dirt1.wav";
    local_68 = (code *)0x15287e;
    local_64 = "player/pl_dirt3.wav";
    iVar2 = 3;
    local_78 = 0.9;
    local_7c = 0.1;
    break;
  case 'F':
    if (param_4 == 5) goto LAB_000f186a;
    local_6c = "weapons/bullet_hit1.wav";
    local_68 = (code *)0x152a09;
    iVar2 = 2;
    local_78 = 1.0;
    local_7c = 0.2;
    local_80 = 0x3f800000;
    break;
  case 'G':
    local_6c = "player/pl_grate1.wav";
    local_68 = (code *)0x1528cf;
    iVar2 = 2;
    local_78 = 0.9;
    local_7c = 0.5;
    break;
  case 'M':
    local_6c = "player/pl_metal1.wav";
    local_68 = (code *)0x152855;
    iVar2 = 2;
    local_78 = 0.9;
    local_7c = 0.3;
    break;
  case 'P':
  case 'Y':
    local_6c = "debris/glass1.wav";
    local_64 = "debris/glass3.wav";
    iVar2 = 3;
    local_68 = (code *)"debris/glass2.wav";
    goto LAB_000f1854;
  case 'S':
    local_6c = "player/pl_slosh1.wav";
    local_68 = (code *)0x152949;
    local_64 = "player/pl_slosh2.wav";
    local_60 = "player/pl_slosh4.wav";
    iVar2 = 4;
    local_78 = 0.9;
    local_7c = 0.0;
    break;
  case 'T':
    local_6c = "player/pl_tile1.wav";
    local_68 = FUN_001528f8;
    local_64 = "player/pl_tile2.wav";
    local_60 = "player/pl_tile4.wav";
    iVar2 = 4;
LAB_000f1854:
    local_78 = 0.8;
    local_7c = 0.2;
    break;
  case 'V':
    local_6c = "player/pl_duct1.wav";
    local_68 = (code *)0x1528a6;
    iVar2 = 2;
    local_78 = 0.5;
    local_7c = 0.3;
    break;
  case 'W':
    local_6c = "debris/wood1.wav";
    local_68 = (code *)0x152999;
    local_64 = "debris/wood3.wav";
    iVar2 = 3;
    local_78 = 0.9;
    local_7c = 0.2;
  }
  if ((local_84 == (int *)0x0) ||
     (iVar4 = strcmp((char *)(*(int *)*local_84 + *(int *)(gpGlobals + 0x98)),"func_breakable"),
     iVar4 != 0)) {
    if ((local_74 == 'P') &&
       ((fVar1 = *(float *)(param_1 + 0x10),
        (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40 &&
        (iVar4 = (*DAT_0019f808)(0,1), iVar4 != 0)))) {
      UTIL_Sparks__FRC6Vector(param_1 + 0x14);
      lVar7 = (longdouble)(*DAT_0019f80c)(0x3f333333,0x3f800000);
      iVar4 = (*DAT_0019f808)(0,1);
      if (iVar4 == 0) {
        pcVar3 = "buttons/spark5.wav";
      }
      else {
        if (iVar4 != 1) goto LAB_000f19cb;
        pcVar3 = "buttons/spark6.wav";
      }
      uVar5 = (*DAT_0019f7b4)(0,param_1 + 0x14,pcVar3,(float)lVar7,0x3f4ccccd,0,100);
      UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii(uVar5);
    }
  }
  else {
    local_78 = local_78 * 0.6666667;
    local_7c = local_7c * 0.5;
  }
LAB_000f19cb:
  iVar4 = (*DAT_0019f808)(0,0xf);
  iVar2 = (*DAT_0019f808)(0,iVar2 + -1,local_78,local_80,0,iVar4 + 0x60);
  uVar5 = (*DAT_0019f7b4)(0,param_1 + 0x14,(&local_6c)[iVar2]);
  UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii(uVar5);
  return (longdouble)local_7c;
}


