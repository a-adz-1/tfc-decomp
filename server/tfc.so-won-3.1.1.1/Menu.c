// Menu_ClassHelp_Input__11CBasePlayerf  @ 000ba7d4
void Menu_ClassHelp_Input__11CBasePlayerf(int param_1)

{
  *(undefined1 *)(param_1 + 0xa40) = 0;
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x110) = 0x3f800000;
  return;
}


// Menu_ClassHelp__11CBasePlayer  @ 000b7258
/* WARNING: Removing unreachable block (ram,0x000b7437) */
/* WARNING: Removing unreachable block (ram,0x000b7439) */
/* WARNING: Removing unreachable block (ram,0x000b743e) */
/* WARNING: Removing unreachable block (ram,0x000b7442) */
/* WARNING: Removing unreachable block (ram,0x000b7443) */
/* WARNING: Removing unreachable block (ram,0x000b7447) */
/* WARNING: Removing unreachable block (ram,0x000b7448) */
/* WARNING: Removing unreachable block (ram,0x000b744c) */
/* WARNING: Removing unreachable block (ram,0x000b76a1) */
/* WARNING: Removing unreachable block (ram,0x000b76a6) */
/* WARNING: Removing unreachable block (ram,0x000b76aa) */
/* WARNING: Removing unreachable block (ram,0x000b76ab) */
/* WARNING: Removing unreachable block (ram,0x000b76af) */
/* WARNING: Removing unreachable block (ram,0x000b7b6f) */
/* WARNING: Removing unreachable block (ram,0x000b7b71) */
/* WARNING: Removing unreachable block (ram,0x000b7b76) */
/* WARNING: Removing unreachable block (ram,0x000b7b7a) */
/* WARNING: Removing unreachable block (ram,0x000b7b7b) */
/* WARNING: Removing unreachable block (ram,0x000b7b7f) */
/* WARNING: Removing unreachable block (ram,0x000b7b80) */
/* WARNING: Removing unreachable block (ram,0x000b7b84) */
/* WARNING: Removing unreachable block (ram,0x000b7303) */
/* WARNING: Removing unreachable block (ram,0x000b7305) */
/* WARNING: Removing unreachable block (ram,0x000b730a) */
/* WARNING: Removing unreachable block (ram,0x000b730e) */
/* WARNING: Removing unreachable block (ram,0x000b730f) */
/* WARNING: Removing unreachable block (ram,0x000b7313) */
/* WARNING: Removing unreachable block (ram,0x000b7314) */
/* WARNING: Removing unreachable block (ram,0x000b7318) */
/* WARNING: Removing unreachable block (ram,0x000b7caa) */
/* WARNING: Removing unreachable block (ram,0x000b7cae) */

void Menu_ClassHelp__11CBasePlayer(int *param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  char local_38 [50];
  undefined1 local_6;
  
  iVar1 = *(int *)(*param_1 + 0x20c);
  if (iVar1 == 1) {
    if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
       (iVar1 = strcmp("#Help_scout",(char *)(param_1 + 0x290)), iVar1 != 0)) {
      param_1[0x311] = (int)(*gpGlobals + 10.0);
      strncpy((char *)(param_1 + 0x290),"#Help_scout",0x200);
      param_1[0x310] = 0xffff;
      puVar6 = (uint *)0x14ce48;
      do {
        puVar2 = puVar6;
        uVar4 = *puVar2;
        if ((char)uVar4 == '\0') goto LAB_000b733b;
        if ((char)(uVar4 >> 8) == '\0') goto LAB_000b733a;
        if ((uVar4 & 0xff0000) == 0) goto LAB_000b7339;
        puVar6 = puVar2 + 1;
      } while ((uVar4 & 0xff000000) != 0);
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b7339:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b733a:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b733b:
      if ((uint *)0x31 < puVar2 + -0x53392) {
        puVar6 = (uint *)0x14ce48;
        do {
          strncpy(local_38,(char *)puVar6,0x32);
          local_6 = 0;
          puVar5 = (uint *)((int)puVar6 + 0x32);
          uVar4 = (uint)puVar5 & 3;
          puVar2 = puVar5;
          if (uVar4 == 0) {
LAB_000b737e:
            do {
              puVar3 = puVar2;
              uVar4 = *puVar3;
              if ((char)uVar4 == '\0') goto LAB_000b73a0;
              if ((char)(uVar4 >> 8) == '\0') goto LAB_000b739f;
              if ((uVar4 & 0xff0000) == 0) goto LAB_000b739e;
              puVar2 = puVar3 + 1;
            } while ((uVar4 & 0xff000000) != 0);
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b739e:
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b739f:
            puVar3 = (uint *)((int)puVar3 + 1);
          }
          else {
            puVar3 = puVar5;
            if (POPCOUNT(uVar4) == '\0') {
LAB_000b7379:
              if ((char)*puVar3 != '\0') {
                puVar2 = (uint *)((int)puVar3 + 1);
                goto LAB_000b737e;
              }
            }
            else if (uVar4 == 2) {
LAB_000b7374:
              if ((char)*puVar3 != '\0') {
                puVar3 = (uint *)((int)puVar3 + 1);
                goto LAB_000b7379;
              }
            }
            else if (*(char *)puVar5 != '\0') {
              puVar3 = (uint *)((int)puVar6 + 0x33);
              goto LAB_000b7374;
            }
          }
LAB_000b73a0:
          puVar6 = puVar5;
        } while (0x31 < (uint)((int)puVar3 - (int)puVar5));
      }
    }
  }
  else if (iVar1 == 2) {
    if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
       (iVar1 = strcmp("#Help_sniper",(char *)(param_1 + 0x290)), iVar1 != 0)) {
      param_1[0x311] = (int)(*gpGlobals + 10.0);
      strncpy((char *)(param_1 + 0x290),"#Help_sniper",0x200);
      param_1[0x310] = 0xffff;
      puVar6 = (uint *)"#Help_sniper";
      do {
        puVar2 = puVar6;
        uVar4 = *puVar2;
        if ((char)uVar4 == '\0') goto LAB_000b746f;
        if ((char)(uVar4 >> 8) == '\0') goto LAB_000b746e;
        if ((uVar4 & 0xff0000) == 0) goto LAB_000b746d;
        puVar6 = puVar2 + 1;
      } while ((uVar4 & 0xff000000) != 0);
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b746d:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b746e:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b746f:
      if ((uint *)0x31 < puVar2 + -0x53395) {
        puVar6 = (uint *)"#Help_sniper";
        do {
          strncpy(local_38,(char *)puVar6,0x32);
          local_6 = 0;
          puVar5 = (uint *)((int)puVar6 + 0x32);
          uVar4 = (uint)puVar5 & 3;
          puVar2 = puVar5;
          if (uVar4 == 0) {
LAB_000b74b2:
            do {
              puVar3 = puVar2;
              uVar4 = *puVar3;
              if ((char)uVar4 == '\0') goto LAB_000b74d4;
              if ((char)(uVar4 >> 8) == '\0') goto LAB_000b74d3;
              if ((uVar4 & 0xff0000) == 0) goto LAB_000b74d2;
              puVar2 = puVar3 + 1;
            } while ((uVar4 & 0xff000000) != 0);
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b74d2:
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b74d3:
            puVar3 = (uint *)((int)puVar3 + 1);
          }
          else {
            puVar3 = puVar5;
            if (POPCOUNT(uVar4) == '\0') {
LAB_000b74ad:
              if ((char)*puVar3 != '\0') {
                puVar2 = (uint *)((int)puVar3 + 1);
                goto LAB_000b74b2;
              }
            }
            else if (uVar4 == 2) {
LAB_000b74a8:
              if ((char)*puVar3 != '\0') {
                puVar3 = (uint *)((int)puVar3 + 1);
                goto LAB_000b74ad;
              }
            }
            else if (*(char *)puVar5 != '\0') {
              puVar3 = (uint *)((int)puVar6 + 0x33);
              goto LAB_000b74a8;
            }
          }
LAB_000b74d4:
          puVar6 = puVar5;
        } while (0x31 < (uint)((int)puVar3 - (int)puVar5));
      }
    }
  }
  else if (iVar1 == 3) {
    if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
       (iVar1 = strcmp("#Help_soldier",(char *)(param_1 + 0x290)), iVar1 != 0)) {
      param_1[0x311] = (int)(*gpGlobals + 10.0);
      strncpy((char *)(param_1 + 0x290),"#Help_soldier",0x200);
      param_1[0x310] = 0xffff;
      puVar6 = (uint *)0x14ce64;
      do {
        puVar2 = puVar6;
        uVar4 = *puVar2;
        if ((char)uVar4 == '\0') goto LAB_000b75a3;
        if ((char)(uVar4 >> 8) == '\0') goto LAB_000b75a2;
        if ((uVar4 & 0xff0000) == 0) goto LAB_000b75a1;
        puVar6 = puVar2 + 1;
      } while ((uVar4 & 0xff000000) != 0);
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b75a1:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b75a2:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b75a3:
      if (0x31 < (int)puVar2 - 0x14ce61U) {
        puVar6 = (uint *)"#Help_soldier";
        do {
          strncpy(local_38,(char *)puVar6,0x32);
          local_6 = 0;
          puVar5 = (uint *)((int)puVar6 + 0x32);
          uVar4 = (uint)puVar5 & 3;
          puVar2 = puVar5;
          if (uVar4 == 0) {
LAB_000b75e6:
            do {
              puVar3 = puVar2;
              uVar4 = *puVar3;
              if ((char)uVar4 == '\0') goto LAB_000b7608;
              if ((char)(uVar4 >> 8) == '\0') goto LAB_000b7607;
              if ((uVar4 & 0xff0000) == 0) goto LAB_000b7606;
              puVar2 = puVar3 + 1;
            } while ((uVar4 & 0xff000000) != 0);
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b7606:
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b7607:
            puVar3 = (uint *)((int)puVar3 + 1);
          }
          else {
            puVar3 = puVar5;
            if ((POPCOUNT(uVar4) & 1U) == 0) {
LAB_000b75e1:
              if ((char)*puVar3 != '\0') {
                puVar2 = (uint *)((int)puVar3 + 1);
                goto LAB_000b75e6;
              }
            }
            else if (uVar4 == 2) {
LAB_000b75dc:
              if ((char)*puVar3 != '\0') {
                puVar3 = (uint *)((int)puVar3 + 1);
                goto LAB_000b75e1;
              }
            }
            else if (*(char *)puVar5 != '\0') {
              puVar3 = (uint *)((int)puVar6 + 0x33);
              goto LAB_000b75dc;
            }
          }
LAB_000b7608:
          puVar6 = puVar5;
        } while (0x31 < (uint)((int)puVar3 - (int)puVar5));
      }
    }
  }
  else if (iVar1 == 4) {
    if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
       (iVar1 = strcmp("#Help_demoman",(char *)(param_1 + 0x290)), iVar1 != 0)) {
      param_1[0x311] = (int)(*gpGlobals + 10.0);
      strncpy((char *)(param_1 + 0x290),"#Help_demoman",0x200);
      param_1[0x310] = 0xffff;
      puVar6 = (uint *)0x14ce70;
      do {
        puVar2 = puVar6;
        uVar4 = *puVar2;
        if ((char)uVar4 == '\0') goto LAB_000b76d7;
        if ((char)(uVar4 >> 8) == '\0') goto LAB_000b76d6;
        if ((uVar4 & 0xff0000) == 0) goto LAB_000b76d5;
        puVar6 = puVar2 + 1;
      } while ((uVar4 & 0xff000000) != 0);
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b76d5:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b76d6:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b76d7:
      if (0x31 < (int)puVar2 - 0x14ce6fU) {
        puVar6 = (uint *)"#Help_demoman";
        do {
          strncpy(local_38,(char *)puVar6,0x32);
          local_6 = 0;
          puVar5 = (uint *)((int)puVar6 + 0x32);
          uVar4 = (uint)puVar5 & 3;
          puVar2 = puVar5;
          if (uVar4 == 0) {
LAB_000b771a:
            do {
              puVar3 = puVar2;
              uVar4 = *puVar3;
              if ((char)uVar4 == '\0') goto LAB_000b773c;
              if ((char)(uVar4 >> 8) == '\0') goto LAB_000b773b;
              if ((uVar4 & 0xff0000) == 0) goto LAB_000b773a;
              puVar2 = puVar3 + 1;
            } while ((uVar4 & 0xff000000) != 0);
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b773a:
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b773b:
            puVar3 = (uint *)((int)puVar3 + 1);
          }
          else {
            puVar3 = puVar5;
            if ((POPCOUNT(uVar4) & 1U) == 0) {
LAB_000b7715:
              if ((char)*puVar3 != '\0') {
                puVar2 = (uint *)((int)puVar3 + 1);
                goto LAB_000b771a;
              }
            }
            else if (uVar4 == 2) {
LAB_000b7710:
              if ((char)*puVar3 != '\0') {
                puVar3 = (uint *)((int)puVar3 + 1);
                goto LAB_000b7715;
              }
            }
            else if (*(char *)puVar5 != '\0') {
              puVar3 = (uint *)((int)puVar6 + 0x33);
              goto LAB_000b7710;
            }
          }
LAB_000b773c:
          puVar6 = puVar5;
        } while (0x31 < (uint)((int)puVar3 - (int)puVar5));
      }
    }
  }
  else if (iVar1 == 5) {
    if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
       (iVar1 = strcmp("#Help_medic",(char *)(param_1 + 0x290)), iVar1 != 0)) {
      param_1[0x311] = (int)(*gpGlobals + 10.0);
      strncpy((char *)(param_1 + 0x290),"#Help_medic",0x200);
      param_1[0x310] = 0xffff;
      puVar6 = (uint *)0x14ce80;
      do {
        puVar2 = puVar6;
        uVar4 = *puVar2;
        if ((char)uVar4 == '\0') goto LAB_000b780b;
        if ((char)(uVar4 >> 8) == '\0') goto LAB_000b780a;
        if ((uVar4 & 0xff0000) == 0) goto LAB_000b7809;
        puVar6 = puVar2 + 1;
      } while ((uVar4 & 0xff000000) != 0);
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b7809:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b780a:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b780b:
      if (0x31 < (int)puVar2 - 0x14ce7dU) {
        puVar6 = (uint *)"#Help_medic";
        do {
          strncpy(local_38,(char *)puVar6,0x32);
          local_6 = 0;
          puVar5 = (uint *)((int)puVar6 + 0x32);
          uVar4 = (uint)puVar5 & 3;
          puVar2 = puVar5;
          if (uVar4 == 0) {
LAB_000b784e:
            do {
              puVar3 = puVar2;
              uVar4 = *puVar3;
              if ((char)uVar4 == '\0') goto LAB_000b7870;
              if ((char)(uVar4 >> 8) == '\0') goto LAB_000b786f;
              if ((uVar4 & 0xff0000) == 0) goto LAB_000b786e;
              puVar2 = puVar3 + 1;
            } while ((uVar4 & 0xff000000) != 0);
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b786e:
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b786f:
            puVar3 = (uint *)((int)puVar3 + 1);
          }
          else {
            puVar3 = puVar5;
            if ((POPCOUNT(uVar4) & 1U) == 0) {
LAB_000b7849:
              if ((char)*puVar3 != '\0') {
                puVar2 = (uint *)((int)puVar3 + 1);
                goto LAB_000b784e;
              }
            }
            else if (uVar4 == 2) {
LAB_000b7844:
              if ((char)*puVar3 != '\0') {
                puVar3 = (uint *)((int)puVar3 + 1);
                goto LAB_000b7849;
              }
            }
            else if (*(char *)puVar5 != '\0') {
              puVar3 = (uint *)((int)puVar6 + 0x33);
              goto LAB_000b7844;
            }
          }
LAB_000b7870:
          puVar6 = puVar5;
        } while (0x31 < (uint)((int)puVar3 - (int)puVar5));
      }
    }
  }
  else if (iVar1 == 6) {
    if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
       (iVar1 = strcmp("#Help_hwguy",(char *)(param_1 + 0x290)), iVar1 != 0)) {
      param_1[0x311] = (int)(*gpGlobals + 10.0);
      strncpy((char *)(param_1 + 0x290),"#Help_hwguy",0x200);
      param_1[0x310] = 0xffff;
      puVar6 = (uint *)"lp_hwguy";
      do {
        puVar2 = puVar6;
        uVar4 = *puVar2;
        if ((char)uVar4 == '\0') goto LAB_000b793f;
        if ((char)(uVar4 >> 8) == '\0') goto LAB_000b793e;
        if ((uVar4 & 0xff0000) == 0) goto LAB_000b793d;
        puVar6 = puVar2 + 1;
      } while ((uVar4 & 0xff000000) != 0);
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b793d:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b793e:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b793f:
      if (0x31 < (int)puVar2 - 0x14ce89U) {
        puVar6 = (uint *)&DAT_0014ce89;
        do {
          strncpy(local_38,(char *)puVar6,0x32);
          local_6 = 0;
          puVar5 = (uint *)((int)puVar6 + 0x32);
          uVar4 = (uint)puVar5 & 3;
          puVar2 = puVar5;
          if (uVar4 == 0) {
LAB_000b7982:
            do {
              puVar3 = puVar2;
              uVar4 = *puVar3;
              if ((char)uVar4 == '\0') goto LAB_000b79a4;
              if ((char)(uVar4 >> 8) == '\0') goto LAB_000b79a3;
              if ((uVar4 & 0xff0000) == 0) goto LAB_000b79a2;
              puVar2 = puVar3 + 1;
            } while ((uVar4 & 0xff000000) != 0);
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b79a2:
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b79a3:
            puVar3 = (uint *)((int)puVar3 + 1);
          }
          else {
            puVar3 = puVar5;
            if ((POPCOUNT(uVar4) & 1U) == 0) {
LAB_000b797d:
              if ((char)*puVar3 != '\0') {
                puVar2 = (uint *)((int)puVar3 + 1);
                goto LAB_000b7982;
              }
            }
            else if (uVar4 == 2) {
LAB_000b7978:
              if ((char)*puVar3 != '\0') {
                puVar3 = (uint *)((int)puVar3 + 1);
                goto LAB_000b797d;
              }
            }
            else if (*(char *)puVar5 != '\0') {
              puVar3 = (uint *)((int)puVar6 + 0x33);
              goto LAB_000b7978;
            }
          }
LAB_000b79a4:
          puVar6 = puVar5;
        } while (0x31 < (uint)((int)puVar3 - (int)puVar5));
      }
    }
  }
  else if (iVar1 == 7) {
    if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
       (iVar1 = strcmp("#Help_pyro",(char *)(param_1 + 0x290)), iVar1 != 0)) {
      param_1[0x311] = (int)(*gpGlobals + 10.0);
      strncpy((char *)(param_1 + 0x290),"#Help_pyro",0x200);
      param_1[0x310] = 0xffff;
      puVar6 = (uint *)0x14ce98;
      do {
        puVar2 = puVar6;
        uVar4 = *puVar2;
        if ((char)uVar4 == '\0') goto LAB_000b7a73;
        if ((char)(uVar4 >> 8) == '\0') goto LAB_000b7a72;
        if ((uVar4 & 0xff0000) == 0) goto LAB_000b7a71;
        puVar6 = puVar2 + 1;
      } while ((uVar4 & 0xff000000) != 0);
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b7a71:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b7a72:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b7a73:
      if (0x31 < (int)puVar2 - 0x14ce95U) {
        puVar6 = (uint *)"#Help_pyro";
        do {
          strncpy(local_38,(char *)puVar6,0x32);
          local_6 = 0;
          puVar5 = (uint *)((int)puVar6 + 0x32);
          uVar4 = (uint)puVar5 & 3;
          puVar2 = puVar5;
          if (uVar4 == 0) {
LAB_000b7ab6:
            do {
              puVar3 = puVar2;
              uVar4 = *puVar3;
              if ((char)uVar4 == '\0') goto LAB_000b7ad8;
              if ((char)(uVar4 >> 8) == '\0') goto LAB_000b7ad7;
              if ((uVar4 & 0xff0000) == 0) goto LAB_000b7ad6;
              puVar2 = puVar3 + 1;
            } while ((uVar4 & 0xff000000) != 0);
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b7ad6:
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b7ad7:
            puVar3 = (uint *)((int)puVar3 + 1);
          }
          else {
            puVar3 = puVar5;
            if ((POPCOUNT(uVar4) & 1U) == 0) {
LAB_000b7ab1:
              if ((char)*puVar3 != '\0') {
                puVar2 = (uint *)((int)puVar3 + 1);
                goto LAB_000b7ab6;
              }
            }
            else if (uVar4 == 2) {
LAB_000b7aac:
              if ((char)*puVar3 != '\0') {
                puVar3 = (uint *)((int)puVar3 + 1);
                goto LAB_000b7ab1;
              }
            }
            else if (*(char *)puVar5 != '\0') {
              puVar3 = (uint *)((int)puVar6 + 0x33);
              goto LAB_000b7aac;
            }
          }
LAB_000b7ad8:
          puVar6 = puVar5;
        } while (0x31 < (uint)((int)puVar3 - (int)puVar5));
      }
    }
  }
  else if (iVar1 == 8) {
    if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
       (iVar1 = strcmp("#Help_spy",(char *)(param_1 + 0x290)), iVar1 != 0)) {
      param_1[0x311] = (int)(*gpGlobals + 10.0);
      strncpy((char *)(param_1 + 0x290),"#Help_spy",0x200);
      param_1[0x310] = 0xffff;
      puVar6 = (uint *)"#Help_spy";
      do {
        puVar2 = puVar6;
        uVar4 = *puVar2;
        if ((char)uVar4 == '\0') goto LAB_000b7ba7;
        if ((char)(uVar4 >> 8) == '\0') goto LAB_000b7ba6;
        if ((uVar4 & 0xff0000) == 0) goto LAB_000b7ba5;
        puVar6 = puVar2 + 1;
      } while ((uVar4 & 0xff000000) != 0);
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b7ba5:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b7ba6:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b7ba7:
      if ((uint *)0x31 < puVar2 + -0x533a8) {
        puVar6 = (uint *)"#Help_spy";
        do {
          strncpy(local_38,(char *)puVar6,0x32);
          local_6 = 0;
          puVar5 = (uint *)((int)puVar6 + 0x32);
          uVar4 = (uint)puVar5 & 3;
          puVar2 = puVar5;
          if (uVar4 == 0) {
LAB_000b7bea:
            do {
              puVar3 = puVar2;
              uVar4 = *puVar3;
              if ((char)uVar4 == '\0') goto LAB_000b7c0c;
              if ((char)(uVar4 >> 8) == '\0') goto LAB_000b7c0b;
              if ((uVar4 & 0xff0000) == 0) goto LAB_000b7c0a;
              puVar2 = puVar3 + 1;
            } while ((uVar4 & 0xff000000) != 0);
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b7c0a:
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b7c0b:
            puVar3 = (uint *)((int)puVar3 + 1);
          }
          else {
            puVar3 = puVar5;
            if (POPCOUNT(uVar4) == '\0') {
LAB_000b7be5:
              if ((char)*puVar3 != '\0') {
                puVar2 = (uint *)((int)puVar3 + 1);
                goto LAB_000b7bea;
              }
            }
            else if (uVar4 == 2) {
LAB_000b7be0:
              if ((char)*puVar3 != '\0') {
                puVar3 = (uint *)((int)puVar3 + 1);
                goto LAB_000b7be5;
              }
            }
            else if (*(char *)puVar5 != '\0') {
              puVar3 = (uint *)((int)puVar6 + 0x33);
              goto LAB_000b7be0;
            }
          }
LAB_000b7c0c:
          puVar6 = puVar5;
        } while (0x31 < (uint)((int)puVar3 - (int)puVar5));
      }
    }
  }
  else if ((iVar1 == 9) &&
          ((((float)param_1[0x311] <= *gpGlobals || (param_1[0x310] != 0xffff)) ||
           (iVar1 = strcmp("#Help_engineer",(char *)(param_1 + 0x290)), iVar1 != 0)))) {
    param_1[0x311] = (int)(*gpGlobals + 10.0);
    strncpy((char *)(param_1 + 0x290),"#Help_engineer",0x200);
    param_1[0x310] = 0xffff;
    puVar6 = (uint *)0x14ceac;
    do {
      puVar2 = puVar6;
      uVar4 = *puVar2;
      if ((char)uVar4 == '\0') goto LAB_000b7cdb;
      if ((char)(uVar4 >> 8) == '\0') goto LAB_000b7cda;
      if ((uVar4 & 0xff0000) == 0) goto LAB_000b7cd9;
      puVar6 = puVar2 + 1;
    } while ((uVar4 & 0xff000000) != 0);
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b7cd9:
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b7cda:
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b7cdb:
    if (0x31 < (int)puVar2 - 0x14ceaaU) {
      puVar6 = (uint *)"#Help_engineer";
      do {
        strncpy(local_38,(char *)puVar6,0x32);
        local_6 = 0;
        puVar5 = (uint *)((int)puVar6 + 0x32);
        uVar4 = (uint)puVar5 & 3;
        puVar2 = puVar5;
        if (uVar4 == 0) {
LAB_000b7d1a:
          do {
            puVar3 = puVar2;
            uVar4 = *puVar3;
            if ((char)uVar4 == '\0') goto LAB_000b7d3c;
            if ((char)(uVar4 >> 8) == '\0') goto LAB_000b7d3b;
            if ((uVar4 & 0xff0000) == 0) goto LAB_000b7d3a;
            puVar2 = puVar3 + 1;
          } while ((uVar4 & 0xff000000) != 0);
          puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b7d3a:
          puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b7d3b:
          puVar3 = (uint *)((int)puVar3 + 1);
        }
        else {
          puVar3 = puVar5;
          if (POPCOUNT(uVar4) == '\0') {
LAB_000b7d15:
            if ((char)*puVar3 != '\0') {
              puVar2 = (uint *)((int)puVar3 + 1);
              goto LAB_000b7d1a;
            }
          }
          else if (uVar4 == 2) {
LAB_000b7d10:
            if ((char)*puVar3 != '\0') {
              puVar3 = (uint *)((int)puVar3 + 1);
              goto LAB_000b7d15;
            }
          }
          else if (*(char *)puVar5 != '\0') {
            puVar3 = (uint *)((int)puVar6 + 0x33);
            goto LAB_000b7d10;
          }
        }
LAB_000b7d3c:
        puVar6 = puVar5;
      } while (0x31 < (uint)((int)puVar3 - (int)puVar5));
    }
  }
  return;
}


// Menu_Class__11CBasePlayer  @ 000baab0
void Menu_Class__11CBasePlayer(int *param_1)

{
  param_1[0x44] = 0x40400000;
  (*DAT_0019f758)(1,gmsgVGUIMenu,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_0019f760)(3);
  (*DAT_0019f75c)();
  return;
}


// Menu_Dispenser_Input__11CBasePlayerf  @ 000ba218
void Menu_Dispenser_Input__11CBasePlayerf(void)

{
  return;
}


// Menu_Dispenser__11CBasePlayer  @ 000ba220
/* WARNING: Removing unreachable block (ram,0x000ba2b8) */
/* WARNING: Removing unreachable block (ram,0x000ba2ba) */
/* WARNING: Removing unreachable block (ram,0x000ba2bf) */
/* WARNING: Removing unreachable block (ram,0x000ba2c3) */
/* WARNING: Removing unreachable block (ram,0x000ba2c4) */
/* WARNING: Removing unreachable block (ram,0x000ba2c8) */
/* WARNING: Removing unreachable block (ram,0x000ba2c9) */
/* WARNING: Removing unreachable block (ram,0x000ba2cd) */

void Menu_Dispenser__11CBasePlayer(int param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  char local_38 [50];
  undefined1 local_6;
  
  if (((*(float *)(param_1 + 0xc44) <= *gpGlobals) || (*(int *)(param_1 + 0xc40) != 0xffff)) ||
     (iVar1 = strcmp("#Menu_Dispenser",(char *)(param_1 + 0xa40)), iVar1 != 0)) {
    *(float *)(param_1 + 0xc44) = *gpGlobals + 10.0;
    strncpy((char *)(param_1 + 0xa40),"#Menu_Dispenser",0x200);
    *(undefined4 *)(param_1 + 0xc40) = 0xffff;
    puVar5 = (uint *)0x14d868;
    do {
      puVar2 = puVar5;
      uVar4 = *puVar2;
      if ((char)uVar4 == '\0') goto LAB_000ba2f0;
      if ((char)(uVar4 >> 8) == '\0') goto LAB_000ba2ef;
      if ((uVar4 & 0xff0000) == 0) goto LAB_000ba2ee;
      puVar5 = puVar2 + 1;
    } while ((uVar4 & 0xff000000) != 0);
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000ba2ee:
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000ba2ef:
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000ba2f0:
    if ((uint *)0x31 < puVar2 + -0x5361a) {
      puVar5 = (uint *)0x14d868;
      do {
        strncpy(local_38,(char *)puVar5,0x32);
        local_6 = 0;
        puVar6 = (uint *)((int)puVar5 + 0x32);
        uVar4 = (uint)puVar6 & 3;
        puVar2 = puVar6;
        if (uVar4 == 0) {
LAB_000ba32e:
          do {
            puVar3 = puVar2;
            uVar4 = *puVar3;
            if ((char)uVar4 == '\0') goto LAB_000ba350;
            if ((char)(uVar4 >> 8) == '\0') goto LAB_000ba34f;
            if ((uVar4 & 0xff0000) == 0) goto LAB_000ba34e;
            puVar2 = puVar3 + 1;
          } while ((uVar4 & 0xff000000) != 0);
          puVar3 = (uint *)((int)puVar3 + 1);
LAB_000ba34e:
          puVar3 = (uint *)((int)puVar3 + 1);
LAB_000ba34f:
          puVar3 = (uint *)((int)puVar3 + 1);
        }
        else {
          puVar3 = puVar6;
          if (POPCOUNT(uVar4) == '\0') {
LAB_000ba329:
            if ((char)*puVar3 != '\0') {
              puVar2 = (uint *)((int)puVar3 + 1);
              goto LAB_000ba32e;
            }
          }
          else if (uVar4 == 2) {
LAB_000ba324:
            if ((char)*puVar3 != '\0') {
              puVar3 = (uint *)((int)puVar3 + 1);
              goto LAB_000ba329;
            }
          }
          else if (*(char *)puVar6 != '\0') {
            puVar3 = (uint *)((int)puVar5 + 0x33);
            goto LAB_000ba324;
          }
        }
LAB_000ba350:
        puVar5 = puVar6;
      } while (0x31 < (uint)((int)puVar3 - (int)puVar6));
    }
  }
  return;
}


// Menu_EngineerFix_Dispenser_Input__11CBasePlayerf  @ 000ba40c
void Menu_EngineerFix_Dispenser_Input__11CBasePlayerf(void)

{
  return;
}


// Menu_EngineerFix_Dispenser__11CBasePlayer  @ 000ba414
/* WARNING: Removing unreachable block (ram,0x000ba4ac) */
/* WARNING: Removing unreachable block (ram,0x000ba4ae) */
/* WARNING: Removing unreachable block (ram,0x000ba4b3) */
/* WARNING: Removing unreachable block (ram,0x000ba4b7) */
/* WARNING: Removing unreachable block (ram,0x000ba4b8) */
/* WARNING: Removing unreachable block (ram,0x000ba4bc) */
/* WARNING: Removing unreachable block (ram,0x000ba4bd) */
/* WARNING: Removing unreachable block (ram,0x000ba4c1) */

void Menu_EngineerFix_Dispenser__11CBasePlayer(int param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  char local_38 [50];
  undefined1 local_6;
  
  if (((*(float *)(param_1 + 0xc44) <= *gpGlobals) || (*(int *)(param_1 + 0xc40) != 0xffff)) ||
     (iVar1 = strcmp("#Action  \n1. #Menu_AmmoDisp \n2. #Menu_ArmorDisp \n3. #Menu_RepairDisp \n4. #Menu_DismantleDisp \n5. #Nothing \n\n"
                     ,(char *)(param_1 + 0xa40)), iVar1 != 0)) {
    *(float *)(param_1 + 0xc44) = *gpGlobals + 10.0;
    strncpy((char *)(param_1 + 0xa40),
            "#Action  \n1. #Menu_AmmoDisp \n2. #Menu_ArmorDisp \n3. #Menu_RepairDisp \n4. #Menu_DismantleDisp \n5. #Nothing \n\n"
            ,0x200);
    *(undefined4 *)(param_1 + 0xc40) = 0xffff;
    puVar5 = (uint *)0x14d6a0;
    do {
      puVar2 = puVar5;
      uVar4 = *puVar2;
      if ((char)uVar4 == '\0') goto LAB_000ba4e4;
      if ((char)(uVar4 >> 8) == '\0') goto LAB_000ba4e3;
      if ((uVar4 & 0xff0000) == 0) goto LAB_000ba4e2;
      puVar5 = puVar2 + 1;
    } while ((uVar4 & 0xff000000) != 0);
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000ba4e2:
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000ba4e3:
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000ba4e4:
    if ((uint *)0x31 < puVar2 + -0x535a8) {
      puVar5 = (uint *)0x14d6a0;
      do {
        strncpy(local_38,(char *)puVar5,0x32);
        local_6 = 0;
        puVar6 = (uint *)((int)puVar5 + 0x32);
        uVar4 = (uint)puVar6 & 3;
        puVar2 = puVar6;
        if (uVar4 == 0) {
LAB_000ba522:
          do {
            puVar3 = puVar2;
            uVar4 = *puVar3;
            if ((char)uVar4 == '\0') goto LAB_000ba544;
            if ((char)(uVar4 >> 8) == '\0') goto LAB_000ba543;
            if ((uVar4 & 0xff0000) == 0) goto LAB_000ba542;
            puVar2 = puVar3 + 1;
          } while ((uVar4 & 0xff000000) != 0);
          puVar3 = (uint *)((int)puVar3 + 1);
LAB_000ba542:
          puVar3 = (uint *)((int)puVar3 + 1);
LAB_000ba543:
          puVar3 = (uint *)((int)puVar3 + 1);
        }
        else {
          puVar3 = puVar6;
          if (POPCOUNT(uVar4) == '\0') {
LAB_000ba51d:
            if ((char)*puVar3 != '\0') {
              puVar2 = (uint *)((int)puVar3 + 1);
              goto LAB_000ba522;
            }
          }
          else if (uVar4 == 2) {
LAB_000ba518:
            if ((char)*puVar3 != '\0') {
              puVar3 = (uint *)((int)puVar3 + 1);
              goto LAB_000ba51d;
            }
          }
          else if (*(char *)puVar6 != '\0') {
            puVar3 = (uint *)((int)puVar5 + 0x33);
            goto LAB_000ba518;
          }
        }
LAB_000ba544:
        puVar5 = puVar6;
      } while (0x31 < (uint)((int)puVar3 - (int)puVar6));
    }
  }
  return;
}


// Menu_EngineerFix_Mortar_Input__11CBasePlayerf  @ 000ba364
void Menu_EngineerFix_Mortar_Input__11CBasePlayerf(int *param_1,float param_2)

{
  float fVar1;
  
  if ((1.0 <= param_2) &&
     ((byte)(5.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_2 == 5.0) << 0xe) >> 8)) != 1)) {
    *(undefined1 *)(param_1 + 0x290) = 0;
    param_1[0x45] = 0;
    param_1[0x46] = 0;
    param_1[0x44] = 0x3f800000;
    *(undefined4 *)(*param_1 + 0x184) = 0;
    fVar1 = *(float *)(*param_1 + 0x1bc);
    if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(*param_1 + 0x1b8) = 0;
      param_1[0xe] = 0;
      *(byte *)((int)param_1 + 0x89) = *(byte *)((int)param_1 + 0x89) & 0x1f;
    }
  }
  return;
}


// Menu_EngineerFix_Mortar__11CBasePlayer  @ 000ba404
void Menu_EngineerFix_Mortar__11CBasePlayer(void)

{
  return;
}


// Menu_EngineerFix_SentryGun_Input__11CBasePlayerf  @ 000b9b00
void Menu_EngineerFix_SentryGun_Input__11CBasePlayerf(int *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  float fStack_14;
  
  piVar8 = param_1 + 0x4e;
  iVar3 = __opP11CBaseEntity__7EHANDLE(piVar8);
  if (iVar3 == 0) {
    *(undefined1 *)(param_1 + 0x290) = 0;
    param_1[0x45] = 0;
    param_1[0x46] = 0;
    param_1[0x44] = 0x3f800000;
  }
  else {
    iVar3 = __rf__7EHANDLE(piVar8);
    iVar3 = __opP11CBaseEntity__7EHANDLE(iVar3 + 0x144);
    if (iVar3 != 0) {
      iVar3 = __rf__7EHANDLE(piVar8);
      iVar3 = __rf__7EHANDLE(iVar3 + 0x144);
      if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar3 + 0x150)) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x150) == 0.0) << 0xe) >> 8)) != 0x40) {
        if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) == 0x40) {
          fStack_14 = 40.0;
          if ((float)param_1[0x33] < 40.0) {
            fStack_14 = (float)param_1[0x33];
          }
          iVar3 = __rf__7EHANDLE(piVar8);
          iVar4 = __rf__7EHANDLE(piVar8);
          fVar1 = (float)(*(int *)(iVar3 + 0xc0) - *(int *)(iVar4 + 0xcc));
          if (0x3f < (byte)((fStack_14 < fVar1 |
                             (byte)((ushort)((ushort)(NAN(fStack_14) || NAN(fVar1)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fStack_14 == fVar1) << 0xe) >> 8)) - 1)) {
            iVar3 = __rf__7EHANDLE(piVar8);
            iVar4 = __rf__7EHANDLE(piVar8);
            fStack_14 = (float)(*(int *)(iVar3 + 0xc0) - *(int *)(iVar4 + 0xcc));
          }
          param_1[0x33] = (int)ROUND((float)param_1[0x33] - fStack_14);
          iVar3 = __rf__7EHANDLE(piVar8);
          iVar4 = __rf__7EHANDLE(piVar8);
          *(int *)(iVar3 + 0xcc) = (int)ROUND(fStack_14 + (float)*(int *)(iVar4 + 0xcc));
          iVar3 = __rf__7EHANDLE(piVar8);
          if (*(int *)(iVar3 + 0x8c) == 3) {
            fStack_14 = 20.0;
            if ((float)param_1[0x39] < 20.0) {
              fStack_14 = (float)param_1[0x39];
            }
            iVar3 = __rf__7EHANDLE(piVar8);
            iVar4 = __rf__7EHANDLE(piVar8);
            fVar1 = (float)(*(int *)(iVar3 + 0xe0) - *(int *)(iVar4 + 0xe4));
            if (0x3f < (byte)((fStack_14 < fVar1 |
                               (byte)((ushort)((ushort)(NAN(fStack_14) || NAN(fVar1)) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fStack_14 == fVar1) << 0xe) >> 8)) - 1)) {
              iVar3 = __rf__7EHANDLE(piVar8);
              iVar4 = __rf__7EHANDLE(piVar8);
              fStack_14 = (float)(*(int *)(iVar3 + 0xe0) - *(int *)(iVar4 + 0xe4));
            }
            param_1[0x39] = (int)ROUND((float)param_1[0x39] - fStack_14);
            iVar3 = __rf__7EHANDLE(piVar8);
            iVar4 = __rf__7EHANDLE(piVar8);
            *(int *)(iVar3 + 0xe4) = (int)ROUND(fStack_14 + (float)*(int *)(iVar4 + 0xe4));
          }
        }
        else {
          iVar3 = __rf__7EHANDLE(piVar8);
          if (((*(int *)(iVar3 + 0x8c) < 3) &&
              ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                     (byte)((ushort)((ushort)(param_2 == 2.0) << 0xe) >> 8)) == 0x40)) &&
             (0x81 < param_1[0x37])) {
            param_1[0x37] = param_1[0x37] + -0x82;
            uVar5 = __opP11CBaseEntity__7EHANDLE(piVar8);
            Upgrade__12CTFSentrygun(uVar5);
            iVar3 = __rf__7EHANDLE(piVar8,0,0,0);
            uVar5 = UTIL_dtos1__Fi(*(undefined4 *)(iVar3 + 0x8c));
            ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Sentry_upgrade",uVar5);
          }
          else if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                         (byte)((ushort)((ushort)(param_2 == 3.0) << 0xe) >> 8)) == 0x40) {
            piVar6 = (int *)__rf__7EHANDLE(piVar8);
            piVar7 = (int *)__rf__7EHANDLE(piVar8);
            fVar1 = (*(float *)(*piVar6 + 0x1b0) - *(float *)(*piVar7 + 0x160)) * 0.2;
            fVar2 = (float)param_1[0x37];
            if (fVar2 < fVar1) {
              fVar1 = fVar2;
            }
            param_1[0x37] = (int)ROUND(fVar2 - fVar1);
            piVar6 = (int *)__rf__7EHANDLE(piVar8);
            piVar7 = (int *)__rf__7EHANDLE(piVar8);
            *(float *)(*piVar6 + 0x160) = *(float *)(*piVar7 + 0x160) + fVar1 * 5.0;
          }
          else if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                         (byte)((ushort)((ushort)(param_2 == 4.0) << 0xe) >> 8)) == 0x40) {
            iVar3 = __rf__7EHANDLE(piVar8);
            iVar3 = __opP11CBaseEntity__7EHANDLE(iVar3 + 0x144);
            if (iVar3 != 0) {
              iVar3 = __rf__7EHANDLE(piVar8);
              piVar6 = (int *)__opP11CBaseEntity__7EHANDLE(iVar3 + 0x144);
              if (piVar6 != param_1) {
                return;
              }
              iVar3 = __rf__7EHANDLE(piVar8);
              iVar3 = __rf__7EHANDLE(iVar3 + 0x144);
              *(undefined4 *)(iVar3 + 0x150) = 0;
            }
            ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Sentry_dismantle",0,0,0,0);
            param_1[0x37] = param_1[0x37] + 0x41;
            TeamFortress_CheckClassStats__11CBasePlayer(param_1);
            iVar3 = __rf__7EHANDLE(piVar8);
            uVar5 = __opP11CBaseEntity__7EHANDLE(iVar3 + 0x98);
            dremove__FP11CBaseEntity(uVar5);
            uVar5 = __opP11CBaseEntity__7EHANDLE(piVar8);
            dremove__FP11CBaseEntity(uVar5);
          }
          else if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                         (byte)((ushort)((ushort)(param_2 == 6.0) << 0xe) >> 8)) == 0x40) {
            ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Sentry_rotate",0,0,0,0);
            iVar3 = __rf__7EHANDLE(piVar8);
            iVar4 = __rf__7EHANDLE(piVar8);
            fVar1 = (float)(*(int *)(iVar4 + 0xa0) + 0x2d);
            if (360.0 <= fVar1) {
              do {
                fVar1 = fVar1 - 360.0;
              } while ((byte)((360.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar1 == 360.0) << 0xe) >> 8)) - 1) < 0x40);
            }
            if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
              do {
                fVar1 = fVar1 + 360.0;
              } while ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1);
            }
            *(int *)(iVar3 + 0xa0) = (int)ROUND(fVar1);
            iVar3 = __rf__7EHANDLE(piVar8);
            iVar4 = __rf__7EHANDLE(piVar8);
            fVar1 = (float)(*(int *)(iVar4 + 0xa4) + 0x2d);
            if (360.0 <= fVar1) {
              do {
                fVar1 = fVar1 - 360.0;
              } while ((byte)((360.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar1 == 360.0) << 0xe) >> 8)) - 1) < 0x40);
            }
            if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
              do {
                fVar1 = fVar1 + 360.0;
              } while ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1);
            }
            *(int *)(iVar3 + 0xa4) = (int)ROUND(fVar1);
          }
        }
        if (param_2 < 1.0) {
          return;
        }
        if ((byte)(6.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(param_2 == 6.0) << 0xe) >> 8)) == 1) {
          return;
        }
        *(undefined1 *)(param_1 + 0x290) = 0;
        param_1[0x45] = 0;
        param_1[0x46] = 0;
        param_1[0x44] = 0x3f800000;
        *(undefined4 *)(*param_1 + 0x184) = 0;
        __as__7EHANDLEP11CBaseEntity(piVar8,0);
        fVar1 = *(float *)(*param_1 + 0x1bc);
        if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
          return;
        }
        *(undefined4 *)(*param_1 + 0x1b8) = 0;
        param_1[0xe] = 0;
        *(byte *)((int)param_1 + 0x89) = *(byte *)((int)param_1 + 0x89) & 0x1f;
        return;
      }
    }
    *(undefined1 *)(param_1 + 0x290) = 0;
    param_1[0x45] = 0;
    param_1[0x46] = 0;
    param_1[0x44] = 0x3f800000;
    __as__7EHANDLEP11CBaseEntity(piVar8,0);
  }
  return;
}


// Menu_EngineerFix_SentryGun__11CBasePlayer  @ 000b9858
/* WARNING: Removing unreachable block (ram,0x000b992f) */
/* WARNING: Removing unreachable block (ram,0x000b9934) */
/* WARNING: Removing unreachable block (ram,0x000b9938) */
/* WARNING: Removing unreachable block (ram,0x000b9939) */
/* WARNING: Removing unreachable block (ram,0x000b993d) */
/* WARNING: Removing unreachable block (ram,0x000b992d) */
/* WARNING: Removing unreachable block (ram,0x000b993e) */
/* WARNING: Removing unreachable block (ram,0x000b9942) */
/* WARNING: Removing unreachable block (ram,0x000b9a54) */
/* WARNING: Removing unreachable block (ram,0x000b9a56) */
/* WARNING: Removing unreachable block (ram,0x000b9a5b) */
/* WARNING: Removing unreachable block (ram,0x000b9a5f) */
/* WARNING: Removing unreachable block (ram,0x000b9a60) */
/* WARNING: Removing unreachable block (ram,0x000b9a64) */
/* WARNING: Removing unreachable block (ram,0x000b9a65) */
/* WARNING: Removing unreachable block (ram,0x000b9a69) */

void Menu_EngineerFix_SentryGun__11CBasePlayer(int param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  char local_38 [50];
  undefined1 local_6;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x138);
  if (iVar1 != 0) {
    iVar1 = __rf__7EHANDLE(param_1 + 0x138);
    if ((*(int *)(iVar1 + 0x8c) < 3) && (0x81 < *(int *)(param_1 + 0xdc))) {
      if (((*(float *)(param_1 + 0xc44) <= *gpGlobals) || (*(int *)(param_1 + 0xc40) != 0xffff)) ||
         (iVar1 = strcmp("#Action  \n1. #Menu_AmmoSentry \n2. #Menu_UpgradeSentry \n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
                         ,(char *)(param_1 + 0xa40)), iVar1 != 0)) {
        *(float *)(param_1 + 0xc44) = *gpGlobals + 10.0;
        strncpy((char *)(param_1 + 0xa40),
                "#Action  \n1. #Menu_AmmoSentry \n2. #Menu_UpgradeSentry \n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
                ,0x200);
        *(undefined4 *)(param_1 + 0xc40) = 0xffff;
        puVar5 = (uint *)
                 "#Action  \n1. #Menu_AmmoSentry \n2. #Menu_UpgradeSentry \n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
        ;
        do {
          puVar2 = puVar5;
          uVar4 = *puVar2;
          if ((char)uVar4 == '\0') goto LAB_000b9965;
          if ((char)(uVar4 >> 8) == '\0') goto LAB_000b9964;
          if ((uVar4 & 0xff0000) == 0) goto LAB_000b9963;
          puVar5 = puVar2 + 1;
        } while ((uVar4 & 0xff000000) != 0);
        puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b9963:
        puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b9964:
        puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b9965:
        if ((uint *)0x31 < puVar2 + -0x535c8) {
          puVar5 = (uint *)
                   "#Action  \n1. #Menu_AmmoSentry \n2. #Menu_UpgradeSentry \n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
          ;
          do {
            strncpy(local_38,(char *)puVar5,0x32);
            local_6 = 0;
            puVar6 = (uint *)((int)puVar5 + 0x32);
            uVar4 = (uint)puVar6 & 3;
            puVar2 = puVar6;
            if (uVar4 == 0) {
LAB_000b99a6:
              do {
                puVar3 = puVar2;
                uVar4 = *puVar3;
                if ((char)uVar4 == '\0') goto LAB_000b99c8;
                if ((char)(uVar4 >> 8) == '\0') goto LAB_000b99c7;
                if ((uVar4 & 0xff0000) == 0) goto LAB_000b99c6;
                puVar2 = puVar3 + 1;
              } while ((uVar4 & 0xff000000) != 0);
              puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b99c6:
              puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b99c7:
              puVar3 = (uint *)((int)puVar3 + 1);
            }
            else {
              puVar3 = puVar6;
              if (POPCOUNT(uVar4) == '\0') {
LAB_000b99a1:
                if ((char)*puVar3 != '\0') {
                  puVar2 = (uint *)((int)puVar3 + 1);
                  goto LAB_000b99a6;
                }
              }
              else if (uVar4 == 2) {
LAB_000b999c:
                if ((char)*puVar3 != '\0') {
                  puVar3 = (uint *)((int)puVar3 + 1);
                  goto LAB_000b99a1;
                }
              }
              else if (*(char *)puVar6 != '\0') {
                puVar3 = (uint *)((int)puVar5 + 0x33);
                goto LAB_000b999c;
              }
            }
LAB_000b99c8:
            puVar5 = puVar6;
          } while (0x31 < (uint)((int)puVar3 - (int)puVar6));
        }
      }
    }
    else if ((*(float *)(param_1 + 0xc44) <= *gpGlobals) ||
            ((*(int *)(param_1 + 0xc40) != 0xffff ||
             (iVar1 = strcmp("#Action  \n1. #Menu_AmmoSentry \n\n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
                             ,(char *)(param_1 + 0xa40)), iVar1 != 0)))) {
      *(float *)(param_1 + 0xc44) = *gpGlobals + 10.0;
      strncpy((char *)(param_1 + 0xa40),
              "#Action  \n1. #Menu_AmmoSentry \n\n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
              ,0x200);
      *(undefined4 *)(param_1 + 0xc40) = 0xffff;
      puVar5 = (uint *)
               "#Action  \n1. #Menu_AmmoSentry \n\n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
      ;
      do {
        puVar2 = puVar5;
        uVar4 = *puVar2;
        if ((char)uVar4 == '\0') goto LAB_000b9a8c;
        if ((char)(uVar4 >> 8) == '\0') goto LAB_000b9a8b;
        if ((uVar4 & 0xff0000) == 0) goto LAB_000b9a8a;
        puVar5 = puVar2 + 1;
      } while ((uVar4 & 0xff000000) != 0);
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b9a8a:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b9a8b:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b9a8c:
      if ((uint *)0x31 < puVar2 + -0x535f0) {
        puVar5 = (uint *)
                 "#Action  \n1. #Menu_AmmoSentry \n\n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
        ;
        do {
          strncpy(local_38,(char *)puVar5,0x32);
          local_6 = 0;
          puVar6 = (uint *)((int)puVar5 + 0x32);
          uVar4 = (uint)puVar6 & 3;
          puVar2 = puVar6;
          if (uVar4 == 0) {
LAB_000b9aca:
            do {
              puVar3 = puVar2;
              uVar4 = *puVar3;
              if ((char)uVar4 == '\0') goto LAB_000b9aec;
              if ((char)(uVar4 >> 8) == '\0') goto LAB_000b9aeb;
              if ((uVar4 & 0xff0000) == 0) goto LAB_000b9aea;
              puVar2 = puVar3 + 1;
            } while ((uVar4 & 0xff000000) != 0);
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b9aea:
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b9aeb:
            puVar3 = (uint *)((int)puVar3 + 1);
          }
          else {
            puVar3 = puVar6;
            if (POPCOUNT(uVar4) == '\0') {
LAB_000b9ac5:
              if ((char)*puVar3 != '\0') {
                puVar2 = (uint *)((int)puVar3 + 1);
                goto LAB_000b9aca;
              }
            }
            else if (uVar4 == 2) {
LAB_000b9ac0:
              if ((char)*puVar3 != '\0') {
                puVar3 = (uint *)((int)puVar3 + 1);
                goto LAB_000b9ac5;
              }
            }
            else if (*(char *)puVar6 != '\0') {
              puVar3 = (uint *)((int)puVar5 + 0x33);
              goto LAB_000b9ac0;
            }
          }
LAB_000b9aec:
          puVar5 = puVar6;
        } while (0x31 < (uint)((int)puVar3 - (int)puVar6));
      }
    }
  }
  return;
}


// Menu_Engineer_Input__11CBasePlayerf  @ 000b9080
void Menu_Engineer_Input__11CBasePlayerf(int *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int *piVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  
  if ((((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) == 0x40) &&
      (99 < param_1[0x37])) &&
     (fVar1 = (float)param_1[0x53],
     (byte)(fVar1 < 1.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40)) {
    uVar8 = 1;
  }
  else {
    if ((((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                (byte)((ushort)((ushort)(param_2 == 2.0) << 0xe) >> 8)) != 0x40) ||
        (param_1[0x37] < 0x82)) ||
       (fVar1 = (float)param_1[0x54],
       (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 0x40)) {
      if (((((byte)(3.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                   (byte)((ushort)((ushort)(param_2 == 3.0) << 0xe) >> 8)) == 0x40) ||
           ((byte)(4.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(param_2 == 4.0) << 0xe) >> 8)) == 0x40)) ||
          ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(param_2 == 6.0) << 0xe) >> 8)) == 0x40)) &&
         ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x54]) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)param_1[0x54] == 1.0) << 0xe) >> 8)) == 0x40)) {
        *(undefined1 *)(param_1 + 0x290) = 0;
        param_1[0x45] = 0;
        param_1[0x46] = 0;
        param_1[0x44] = 0x3f800000;
        *(undefined4 *)(*param_1 + 0x184) = 0;
        piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"building_sentrygun");
        if (piVar4 == (int *)0x0) {
          return;
        }
        do {
          piVar5 = (int *)__opP11CBaseEntity__7EHANDLE(piVar4 + 0x51);
          if (piVar5 == param_1) break;
          piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                    (piVar4,"building_sentrygun");
        } while (piVar4 != (int *)0x0);
        if (piVar4 == (int *)0x0) {
          return;
        }
        if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(param_2 == 3.0) << 0xe) >> 8)) != 0x40) {
          if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                    (byte)((ushort)((ushort)(param_2 == 4.0) << 0xe) >> 8)) == 0x40) {
            ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Sentry_rotate",0,0,0,0);
            fVar1 = (float)(piVar4[0x28] + 0x2d);
            if (360.0 <= fVar1) {
              do {
                fVar1 = fVar1 - 360.0;
              } while ((byte)((360.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar1 == 360.0) << 0xe) >> 8)) - 1) < 0x40);
            }
            if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
              do {
                fVar1 = fVar1 + 360.0;
              } while ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1);
            }
            piVar4[0x28] = (int)ROUND(fVar1);
            fVar1 = (float)(piVar4[0x29] + 0x2d);
            if (360.0 <= fVar1) {
              do {
                fVar1 = fVar1 - 360.0;
              } while ((byte)((360.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar1 == 360.0) << 0xe) >> 8)) - 1) < 0x40);
            }
            if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
              do {
                fVar1 = fVar1 + 360.0;
              } while ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1);
            }
          }
          else {
            if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                      (byte)((ushort)((ushort)(param_2 == 6.0) << 0xe) >> 8)) != 0x40) {
              return;
            }
            ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Sentry_rotate180",0,0,0,0);
            fVar1 = (float)(piVar4[0x28] + 0xb4);
            if (360.0 <= fVar1) {
              do {
                fVar1 = fVar1 - 360.0;
              } while ((byte)((360.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar1 == 360.0) << 0xe) >> 8)) - 1) < 0x40);
            }
            if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
              do {
                fVar1 = fVar1 + 360.0;
              } while ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1);
            }
            piVar4[0x28] = (int)ROUND(fVar1);
            fVar1 = (float)(piVar4[0x29] + 0xb4);
            if (360.0 <= fVar1) {
              do {
                fVar1 = fVar1 - 360.0;
              } while ((byte)((360.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar1 == 360.0) << 0xe) >> 8)) - 1) < 0x40);
            }
            if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
              do {
                fVar1 = fVar1 + 360.0;
              } while ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1);
            }
          }
          piVar4[0x29] = (int)ROUND(fVar1);
          return;
        }
        iVar7 = *param_1;
        fVar1 = *(float *)(iVar7 + 0xc) - *(float *)(*piVar4 + 0xc);
        fVar2 = *(float *)(iVar7 + 0x10) - *(float *)(*piVar4 + 0x10);
        fVar3 = *(float *)(iVar7 + 8) - *(float *)(*piVar4 + 8);
        if (SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1) <= 128.0) {
          ClientPrint__FP9entvars_siPCcN42(iVar7,1,"#Sentry_dismantle",0,0,0,0);
          if (param_1[0x48] == 0) {
            pcVar6 = "SPECTATOR";
          }
          else {
            pcVar6 = (char *)GetTeamName__Fi(param_1[0x48]);
          }
          uVar8 = (*DAT_0019f8dc)(*(undefined4 *)(*param_1 + 0x208),pcVar6);
          uVar8 = (*DAT_0019f864)(*(undefined4 *)(*param_1 + 0x208),uVar8);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i><%s><%s>\" triggered \"Sentry_Dismantle\"\n",
                     *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar8);
          param_1[0x37] = param_1[0x37] + piVar4[0x23] * 0x40 + piVar4[0x23];
          TeamFortress_CheckClassStats__11CBasePlayer(param_1);
          uVar8 = __opP11CBaseEntity__7EHANDLE(piVar4 + 0x26);
          dremove__FP11CBaseEntity(uVar8);
          dremove__FP11CBaseEntity(piVar4);
          param_1[0x54] = 0;
          return;
        }
        pcVar6 = "#Sentry_DistDismantle";
LAB_000b973a:
        ClientPrint__FP9entvars_siPCcN42(iVar7,1,pcVar6,0,0,0,0);
        return;
      }
      if (((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(param_2 == 7.0) << 0xe) >> 8)) == 0x40) &&
         ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x53]) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)param_1[0x53] == 1.0) << 0xe) >> 8)) == 0x40)) {
        pcVar6 = "building_dispenser";
      }
      else {
        if (((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                   (byte)((ushort)((ushort)(param_2 == 8.0) << 0xe) >> 8)) != 0x40) ||
           ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x54]) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)param_1[0x54] == 1.0) << 0xe) >> 8)) != 0x40)) {
          if (((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                     (byte)((ushort)((ushort)(param_2 == 9.0) << 0xe) >> 8)) == 0x40) &&
             ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x53]) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)param_1[0x53] == 1.0) << 0xe) >> 8)) == 0x40)) {
            *(undefined1 *)(param_1 + 0x290) = 0;
            param_1[0x45] = 0;
            param_1[0x46] = 0;
            param_1[0x44] = 0x3f800000;
            *(undefined4 *)(*param_1 + 0x184) = 0;
            piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"building_dispenser");
            if (piVar4 == (int *)0x0) {
              return;
            }
            do {
              piVar5 = (int *)__opP11CBaseEntity__7EHANDLE(piVar4 + 0x51);
              if (piVar5 == param_1) break;
              piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                        (piVar4,"building_dispenser");
            } while (piVar4 != (int *)0x0);
            if (piVar4 == (int *)0x0) {
              return;
            }
            iVar7 = *param_1;
            fVar1 = *(float *)(iVar7 + 0xc) - *(float *)(*piVar4 + 0xc);
            fVar2 = *(float *)(iVar7 + 0x10) - *(float *)(*piVar4 + 0x10);
            fVar3 = *(float *)(iVar7 + 8) - *(float *)(*piVar4 + 8);
            if (SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1) <= 128.0) {
              ClientPrint__FP9entvars_siPCcN42(iVar7,1,"#Dispenser_dismantle",0,0,0,0);
              if (param_1[0x48] == 0) {
                pcVar6 = "SPECTATOR";
              }
              else {
                pcVar6 = (char *)GetTeamName__Fi(param_1[0x48]);
              }
              uVar8 = (*DAT_0019f8dc)(*(undefined4 *)(*param_1 + 0x208),pcVar6);
              uVar8 = (*DAT_0019f864)(*(undefined4 *)(*param_1 + 0x208),uVar8);
              UTIL_LogPrintf__FPce
                        ("\"%s<%i><%s><%s>\" triggered \"Dispenser_Dismantle\"\n",
                         *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar8);
              param_1[0x37] = param_1[0x37] + 0x32;
              TeamFortress_CheckClassStats__11CBasePlayer(param_1);
              dremove__FP11CBaseEntity(piVar4);
              param_1[0x53] = 0;
              return;
            }
            pcVar6 = "#Dispenser_DistDismantle";
            goto LAB_000b973a;
          }
          if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                    (byte)((ushort)((ushort)(param_2 == 5.0) << 0xe) >> 8)) != 0x40) {
            return;
          }
          goto LAB_000b9812;
        }
        pcVar6 = "building_sentrygun";
      }
      DestroyBuilding__FP11CBaseEntityPc(param_1,pcVar6);
      goto LAB_000b9812;
    }
    uVar8 = 2;
  }
  TeamFortress_EngineerBuild__11CBasePlayeri(param_1,uVar8);
LAB_000b9812:
  *(undefined1 *)(param_1 + 0x290) = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x44] = 0x3f800000;
  *(undefined4 *)(*param_1 + 0x184) = 0;
  return;
}


// Menu_Engineer__11CBasePlayer  @ 000b8e48
/* WARNING: Removing unreachable block (ram,0x000b8fd4) */
/* WARNING: Removing unreachable block (ram,0x000b8fd6) */
/* WARNING: Removing unreachable block (ram,0x000b8fdb) */
/* WARNING: Removing unreachable block (ram,0x000b8fdf) */
/* WARNING: Removing unreachable block (ram,0x000b8fe0) */
/* WARNING: Removing unreachable block (ram,0x000b8fe4) */
/* WARNING: Removing unreachable block (ram,0x000b8fe5) */
/* WARNING: Removing unreachable block (ram,0x000b8fe9) */

void Menu_Engineer__11CBasePlayer(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  char *pcVar9;
  uint *puVar10;
  uint *puVar11;
  char *local_48;
  char *local_40;
  char local_38 [50];
  undefined1 local_6;
  
  fVar1 = *(float *)(param_1 + 0x14c);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    pcVar9 = "\n";
    if (99 < *(int *)(param_1 + 0xdc)) {
      pcVar9 = "1. #Menu_BuildDisp \n";
    }
  }
  else {
    pcVar9 = "7. #Menu_DetDisp \n";
  }
  local_48 = "\n";
  fVar2 = *(float *)(param_1 + 0x150);
  if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
    pcVar7 = local_48;
    if (0x81 < *(int *)(param_1 + 0xdc)) {
      pcVar7 = "2. #Menu_BuildSentry \n";
    }
  }
  else {
    pcVar7 = "8. #Menu_DetSentry \n";
  }
  local_40 = "\n";
  if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
    local_40 = "3. #Menu_DismantleSentry \n";
  }
  pcVar6 = local_48;
  if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
    pcVar6 = "4. #Menu_RotateSentry \n";
  }
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    local_48 = "9. #Menu_DismantleDisp \n";
  }
  sprintf(&cbuf,"%s%s%s%s%s%s%s","#Action \n",pcVar9,pcVar7,local_40,pcVar6,local_48,
          "5. #Nothing \n\n");
  if (((*(float *)(param_1 + 0xc44) <= *gpGlobals) || (*(int *)(param_1 + 0xc40) != 0xffff)) ||
     (iVar3 = strcmp(&cbuf,(char *)(param_1 + 0xa40)), iVar3 != 0)) {
    *(float *)(param_1 + 0xc44) = *gpGlobals + 10.0;
    strncpy((char *)(param_1 + 0xa40),&cbuf,0x200);
    *(undefined4 *)(param_1 + 0xc40) = 0xffff;
    puVar10 = (uint *)&cbuf;
    do {
      puVar4 = puVar10;
      uVar8 = *puVar4;
      if ((char)uVar8 == '\0') goto LAB_000b900c;
      if ((char)(uVar8 >> 8) == '\0') goto LAB_000b900b;
      if ((uVar8 & 0xff0000) == 0) goto LAB_000b900a;
      puVar10 = puVar4 + 1;
    } while ((uVar8 & 0xff000000) != 0);
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_000b900a:
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_000b900b:
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_000b900c:
    if ((uint *)0x31 < puVar4 + -0x67e40) {
      puVar10 = (uint *)&cbuf;
      do {
        strncpy(local_38,(char *)puVar10,0x32);
        local_6 = 0;
        puVar11 = (uint *)((int)puVar10 + 0x32);
        uVar8 = (uint)puVar11 & 3;
        puVar4 = puVar11;
        if (uVar8 == 0) {
LAB_000b904a:
          do {
            puVar5 = puVar4;
            uVar8 = *puVar5;
            if ((char)uVar8 == '\0') goto LAB_000b906c;
            if ((char)(uVar8 >> 8) == '\0') goto LAB_000b906b;
            if ((uVar8 & 0xff0000) == 0) goto LAB_000b906a;
            puVar4 = puVar5 + 1;
          } while ((uVar8 & 0xff000000) != 0);
          puVar5 = (uint *)((int)puVar5 + 1);
LAB_000b906a:
          puVar5 = (uint *)((int)puVar5 + 1);
LAB_000b906b:
          puVar5 = (uint *)((int)puVar5 + 1);
        }
        else {
          puVar5 = puVar11;
          if (POPCOUNT(uVar8) == '\0') {
LAB_000b9045:
            if ((char)*puVar5 != '\0') {
              puVar4 = (uint *)((int)puVar5 + 1);
              goto LAB_000b904a;
            }
          }
          else if (uVar8 == 2) {
FUN_000b9040:
            if ((char)*puVar5 != '\0') {
              puVar5 = (uint *)((int)puVar5 + 1);
              goto LAB_000b9045;
            }
          }
          else if (*(char *)puVar11 != '\0') {
            puVar5 = (uint *)((int)puVar10 + 0x33);
            goto FUN_000b9040;
          }
        }
LAB_000b906c:
        puVar10 = puVar11;
      } while (0x31 < (uint)((int)puVar5 - (int)puVar11));
    }
  }
  return;
}


// Menu_Input__11CBasePlayerf  @ 000ba818
void Menu_Input__11CBasePlayerf(int param_1,undefined4 param_2)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x110);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 12.0) << 0xe) >> 8)) == 0x40) {
    Menu_Spy_Input__11CBasePlayerf(param_1,param_2);
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 13.0) << 0xe) >> 8)) == 0x40) {
    Menu_Spy_Skin_Input__11CBasePlayerf(param_1,param_2);
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 14.0) << 0xe) >> 8)) == 0x40) {
    Menu_Spy_Color_Input__11CBasePlayerf(param_1,param_2);
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 15.0) << 0xe) >> 8)) == 0x40) {
    Menu_Engineer_Input__11CBasePlayerf(param_1,param_2);
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 18.0) << 0xe) >> 8)) == 0x40) {
    Menu_EngineerFix_Mortar_Input__11CBasePlayerf(param_1,param_2);
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 17.0) << 0xe) >> 8)) == 0x40) {
    Menu_EngineerFix_SentryGun_Input__11CBasePlayerf(param_1,param_2);
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 19.0) << 0xe) >> 8)) == 0x40) {
    Menu_Dispenser_Input__11CBasePlayerf(param_1,param_2);
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 6.0) << 0xe) >> 8)) == 0x40) {
    Menu_ClassHelp_Input__11CBasePlayerf(param_1,param_2);
  }
  return;
}


// Menu_Intro__11CBasePlayer  @ 000b6fc0
/* WARNING: Removing unreachable block (ram,0x000b7087) */
/* WARNING: Removing unreachable block (ram,0x000b708c) */
/* WARNING: Removing unreachable block (ram,0x000b7090) */
/* WARNING: Removing unreachable block (ram,0x000b7091) */
/* WARNING: Removing unreachable block (ram,0x000b7095) */
/* WARNING: Removing unreachable block (ram,0x000b7085) */
/* WARNING: Removing unreachable block (ram,0x000b7096) */
/* WARNING: Removing unreachable block (ram,0x000b709a) */
/* WARNING: Removing unreachable block (ram,0x000b71ac) */
/* WARNING: Removing unreachable block (ram,0x000b71ae) */
/* WARNING: Removing unreachable block (ram,0x000b71b3) */
/* WARNING: Removing unreachable block (ram,0x000b71b7) */
/* WARNING: Removing unreachable block (ram,0x000b71b8) */
/* WARNING: Removing unreachable block (ram,0x000b71bc) */
/* WARNING: Removing unreachable block (ram,0x000b71bd) */
/* WARNING: Removing unreachable block (ram,0x000b71c1) */
/* WARNING: Removing unreachable block (ram,0x000b6ff3) */
/* WARNING: Removing unreachable block (ram,0x000b7022) */
/* WARNING: Removing unreachable block (ram,0x000b702f) */
/* WARNING: Removing unreachable block (ram,0x000b7047) */
/* WARNING: Removing unreachable block (ram,0x000b709b) */
/* WARNING: Removing unreachable block (ram,0x000b70a1) */
/* WARNING: Removing unreachable block (ram,0x000b70a5) */
/* WARNING: Removing unreachable block (ram,0x000b70ad) */
/* WARNING: Removing unreachable block (ram,0x000b70b8) */
/* WARNING: Removing unreachable block (ram,0x000b70bb) */
/* WARNING: Removing unreachable block (ram,0x000b70bc) */
/* WARNING: Removing unreachable block (ram,0x000b70bd) */
/* WARNING: Removing unreachable block (ram,0x000b70c8) */
/* WARNING: Removing unreachable block (ram,0x000b70cc) */
/* WARNING: Removing unreachable block (ram,0x000b70e8) */
/* WARNING: Removing unreachable block (ram,0x000b70ea) */
/* WARNING: Removing unreachable block (ram,0x000b70ef) */
/* WARNING: Removing unreachable block (ram,0x000b70f3) */
/* WARNING: Removing unreachable block (ram,0x000b70f4) */
/* WARNING: Removing unreachable block (ram,0x000b70f8) */
/* WARNING: Removing unreachable block (ram,0x000b70f9) */
/* WARNING: Removing unreachable block (ram,0x000b70fd) */
/* WARNING: Removing unreachable block (ram,0x000b70fe) */
/* WARNING: Removing unreachable block (ram,0x000b7104) */
/* WARNING: Removing unreachable block (ram,0x000b7108) */
/* WARNING: Removing unreachable block (ram,0x000b7110) */
/* WARNING: Removing unreachable block (ram,0x000b711b) */
/* WARNING: Removing unreachable block (ram,0x000b711e) */
/* WARNING: Removing unreachable block (ram,0x000b711f) */
/* WARNING: Removing unreachable block (ram,0x000b7120) */
/* WARNING: Removing unreachable block (ram,0x000b7127) */

void Menu_Intro__11CBasePlayer(int param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  char local_38 [50];
  undefined1 local_6;
  
  if (((*(float *)(param_1 + 0xc44) <= *gpGlobals) || (*(int *)(param_1 + 0xc40) != 0xffff)) ||
     (iVar1 = strcmp("Welcome to TeamFortress v2.9 Beta\nby TeamFortress Software\n======================================\nwww.planetquake.com/teamfortress"
                     ,(char *)(param_1 + 0xa40)), iVar1 != 0)) {
    *(float *)(param_1 + 0xc44) = *gpGlobals + 10.0;
    strncpy((char *)(param_1 + 0xa40),
            "Welcome to TeamFortress v2.9 Beta\nby TeamFortress Software\n======================================\nwww.planetquake.com/teamfortress"
            ,0x200);
    *(undefined4 *)(param_1 + 0xc40) = 0xffff;
    puVar5 = (uint *)
             "Welcome to TeamFortress v2.9 Beta\nby TeamFortress Software\n======================================\nwww.planetquake.com/teamfortress"
    ;
    do {
      puVar2 = puVar5;
      uVar4 = *puVar2;
      if ((char)uVar4 == '\0') goto LAB_000b71e4;
      if ((char)(uVar4 >> 8) == '\0') goto LAB_000b71e3;
      if ((uVar4 & 0xff0000) == 0) goto LAB_000b71e2;
      puVar5 = puVar2 + 1;
    } while ((uVar4 & 0xff000000) != 0);
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b71e2:
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b71e3:
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b71e4:
    if ((uint *)0x31 < puVar2 + -0x53370) {
      puVar5 = (uint *)
               "Welcome to TeamFortress v2.9 Beta\nby TeamFortress Software\n======================================\nwww.planetquake.com/teamfortress"
      ;
      do {
        strncpy(local_38,(char *)puVar5,0x32);
        local_6 = 0;
        puVar6 = (uint *)((int)puVar5 + 0x32);
        uVar4 = (uint)puVar6 & 3;
        puVar2 = puVar6;
        if (uVar4 == 0) {
LAB_000b7222:
          do {
            puVar3 = puVar2;
            uVar4 = *puVar3;
            if ((char)uVar4 == '\0') goto LAB_000b7244;
            if ((char)(uVar4 >> 8) == '\0') goto LAB_000b7243;
            if ((uVar4 & 0xff0000) == 0) goto LAB_000b7242;
            puVar2 = puVar3 + 1;
          } while ((uVar4 & 0xff000000) != 0);
          puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b7242:
          puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b7243:
          puVar3 = (uint *)((int)puVar3 + 1);
        }
        else {
          puVar3 = puVar6;
          if (POPCOUNT(uVar4) == '\0') {
LAB_000b721d:
            if ((char)*puVar3 != '\0') {
              puVar2 = (uint *)((int)puVar3 + 1);
              goto LAB_000b7222;
            }
          }
          else if (uVar4 == 2) {
LAB_000b7218:
            if ((char)*puVar3 != '\0') {
              puVar3 = (uint *)((int)puVar3 + 1);
              goto LAB_000b721d;
            }
          }
          else if (*(char *)puVar6 != '\0') {
            puVar3 = (uint *)((int)puVar5 + 0x33);
            goto LAB_000b7218;
          }
        }
LAB_000b7244:
        puVar5 = puVar6;
      } while (0x31 < (uint)((int)puVar3 - (int)puVar6));
    }
  }
  return;
}


// Menu_MapBriefing__11CBasePlayer  @ 000b6ebc
void Menu_MapBriefing__11CBasePlayer(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  
  bVar1 = true;
  uVar2 = (*DAT_0019f848)(*(undefined4 *)(*param_1 + 0x208));
  pcVar3 = (char *)(*DAT_0019f84c)(uVar2,&DAT_0014cd78);
  if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
    iVar4 = 2;
    bVar7 = true;
    pcVar5 = pcVar3;
    pcVar6 = "0";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar7 = *pcVar5 == *pcVar6;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (!bVar7) {
      iVar4 = 4;
      bVar7 = true;
      pcVar5 = "off";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar7 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar7);
      if (!bVar7) goto LAB_000b6f47;
    }
    bVar1 = false;
  }
LAB_000b6f47:
  if (bVar1) {
    (*DAT_0019f758)(1,gmsgVGUIMenu,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_0019f760)(4);
    (*DAT_0019f778)(*(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98));
    (*DAT_0019f75c)();
  }
  return;
}


// Menu_RepeatHelp__11CBasePlayer  @ 000ba96c
void Menu_RepeatHelp__11CBasePlayer(int param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  char local_38 [50];
  undefined1 local_6;
  
  if (((*(float *)(param_1 + 0xc44) <= *gpGlobals) || (*(int *)(param_1 + 0xc40) != 0xffff)) ||
     (iVar1 = strcmp("#Menu_repeathelp",(char *)(param_1 + 0xa40)), iVar1 != 0)) {
    *(float *)(param_1 + 0xc44) = *gpGlobals + 10.0;
    strncpy((char *)(param_1 + 0xa40),"#Menu_repeathelp",0x200);
    *(undefined4 *)(param_1 + 0xc40) = 0xffff;
    puVar5 = (uint *)0x14cd84;
    do {
      puVar2 = puVar5;
      uVar4 = *puVar2;
      if ((char)uVar4 == '\0') goto LAB_000baa3c;
      if ((char)(uVar4 >> 8) == '\0') goto LAB_000baa3b;
      if ((uVar4 & 0xff0000) == 0) goto LAB_000baa3a;
      puVar5 = puVar2 + 1;
    } while ((uVar4 & 0xff000000) != 0);
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000baa3a:
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000baa3b:
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000baa3c:
    if (0x31 < (int)puVar2 - 0x14cd81U) {
      puVar5 = (uint *)"#Menu_repeathelp";
      do {
        strncpy(local_38,(char *)puVar5,0x32);
        local_6 = 0;
        puVar6 = (uint *)((int)puVar5 + 0x32);
        uVar4 = (uint)puVar6 & 3;
        puVar2 = puVar6;
        if (uVar4 == 0) {
LAB_000baa7a:
          do {
            puVar3 = puVar2;
            uVar4 = *puVar3;
            if ((char)uVar4 == '\0') goto LAB_000baa9c;
            if ((char)(uVar4 >> 8) == '\0') goto LAB_000baa9b;
            if ((uVar4 & 0xff0000) == 0) goto LAB_000baa9a;
            puVar2 = puVar3 + 1;
          } while ((uVar4 & 0xff000000) != 0);
          puVar3 = (uint *)((int)puVar3 + 1);
LAB_000baa9a:
          puVar3 = (uint *)((int)puVar3 + 1);
LAB_000baa9b:
          puVar3 = (uint *)((int)puVar3 + 1);
        }
        else {
          puVar3 = puVar6;
          if ((POPCOUNT(uVar4) & 1U) == 0) {
LAB_000baa75:
            if ((char)*puVar3 != '\0') {
              puVar2 = (uint *)((int)puVar3 + 1);
              goto LAB_000baa7a;
            }
          }
          else if (uVar4 == 2) {
LAB_000baa70:
            if ((char)*puVar3 != '\0') {
              puVar3 = (uint *)((int)puVar3 + 1);
              goto LAB_000baa75;
            }
          }
          else if (*(char *)puVar6 != '\0') {
            puVar3 = (uint *)((int)puVar5 + 0x33);
            goto LAB_000baa70;
          }
        }
LAB_000baa9c:
        puVar5 = puVar6;
      } while (0x31 < (uint)((int)puVar3 - (int)puVar6));
    }
  }
  return;
}


// Menu_Spy_Color_Input__11CBasePlayerf  @ 000ba558
void Menu_Spy_Color_Input__11CBasePlayerf(int *param_1,float param_2)

{
  if (((byte)(param_2 < 1.0 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) != 1) &&
     (param_2 <= number_of_teams)) {
    TeamFortress_SpyChangeColor__11CBasePlayeri(param_1,(int)ROUND(param_2));
    *(undefined1 *)(param_1 + 0x290) = 0;
    param_1[0x45] = 0;
    param_1[0x46] = 0;
    param_1[0x44] = 0x3f800000;
    *(undefined4 *)(*param_1 + 0x184) = 0;
  }
  return;
}


// Menu_Spy_Color__11CBasePlayer  @ 000b88d8
/* WARNING: Removing unreachable block (ram,0x000b8b36) */
/* WARNING: Removing unreachable block (ram,0x000b8b38) */
/* WARNING: Removing unreachable block (ram,0x000b8b3d) */
/* WARNING: Removing unreachable block (ram,0x000b8b41) */
/* WARNING: Removing unreachable block (ram,0x000b8b42) */
/* WARNING: Removing unreachable block (ram,0x000b8b46) */
/* WARNING: Removing unreachable block (ram,0x000b8b47) */
/* WARNING: Removing unreachable block (ram,0x000b8b4b) */
/* WARNING: Removing unreachable block (ram,0x000b8c74) */
/* WARNING: Removing unreachable block (ram,0x000b8c76) */
/* WARNING: Removing unreachable block (ram,0x000b8c7b) */
/* WARNING: Removing unreachable block (ram,0x000b8c7f) */
/* WARNING: Removing unreachable block (ram,0x000b8c80) */
/* WARNING: Removing unreachable block (ram,0x000b8c84) */
/* WARNING: Removing unreachable block (ram,0x000b8c85) */
/* WARNING: Removing unreachable block (ram,0x000b8c89) */
/* WARNING: Removing unreachable block (ram,0x000b89f6) */
/* WARNING: Removing unreachable block (ram,0x000b89f8) */
/* WARNING: Removing unreachable block (ram,0x000b89fd) */
/* WARNING: Removing unreachable block (ram,0x000b8a01) */
/* WARNING: Removing unreachable block (ram,0x000b8a02) */
/* WARNING: Removing unreachable block (ram,0x000b8a06) */
/* WARNING: Removing unreachable block (ram,0x000b8a07) */
/* WARNING: Removing unreachable block (ram,0x000b8a0b) */
/* WARNING: Removing unreachable block (ram,0x000b8d9e) */
/* WARNING: Removing unreachable block (ram,0x000b8da0) */
/* WARNING: Removing unreachable block (ram,0x000b8da5) */
/* WARNING: Removing unreachable block (ram,0x000b8da9) */
/* WARNING: Removing unreachable block (ram,0x000b8daa) */
/* WARNING: Removing unreachable block (ram,0x000b8dae) */
/* WARNING: Removing unreachable block (ram,0x000b8daf) */
/* WARNING: Removing unreachable block (ram,0x000b8db3) */

void Menu_Spy_Color__11CBasePlayer(int *param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  char local_38 [50];
  undefined1 local_6;
  
  if ((byte)((byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
            (byte)((ushort)((ushort)(number_of_teams == 0.0) << 0xe) >> 8)) == 0x40) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Game_nocolorchange",0,0,0,0);
    *(undefined1 *)(param_1 + 0x290) = 0;
    param_1[0x45] = 0;
    param_1[0x46] = 0;
    param_1[0x44] = 0x3f800000;
    *(undefined4 *)(*param_1 + 0x184) = 0;
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
                 (byte)((ushort)((ushort)(number_of_teams == 1.0) << 0xe) >> 8)) == 0x40) {
    if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
       (iVar1 = strcmp("#Spy_colormenu \n\n1. #BlueTeam \n\n",(char *)(param_1 + 0x290)), iVar1 != 0
       )) {
      param_1[0x311] = (int)(*gpGlobals + 10.0);
      strncpy((char *)(param_1 + 0x290),"#Spy_colormenu \n\n1. #BlueTeam \n\n",0x200);
      param_1[0x310] = 0xffff;
      puVar6 = (uint *)"#Spy_colormenu \n\n1. #BlueTeam \n\n";
      do {
        puVar2 = puVar6;
        uVar4 = *puVar2;
        if ((char)uVar4 == '\0') goto LAB_000b8a2e;
        if ((char)(uVar4 >> 8) == '\0') goto LAB_000b8a2d;
        if ((uVar4 & 0xff0000) == 0) goto LAB_000b8a2c;
        puVar6 = puVar2 + 1;
      } while ((uVar4 & 0xff000000) != 0);
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b8a2c:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b8a2d:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b8a2e:
      if ((uint *)0x31 < puVar2 + -0x534d8) {
        puVar6 = (uint *)"#Spy_colormenu \n\n1. #BlueTeam \n\n";
        do {
          strncpy(local_38,(char *)puVar6,0x32);
          local_6 = 0;
          puVar5 = (uint *)((int)puVar6 + 0x32);
          uVar4 = (uint)puVar5 & 3;
          puVar2 = puVar5;
          if (uVar4 == 0) {
LAB_000b8a6e:
            do {
              puVar3 = puVar2;
              uVar4 = *puVar3;
              if ((char)uVar4 == '\0') goto LAB_000b8a90;
              if ((char)(uVar4 >> 8) == '\0') goto LAB_000b8a8f;
              if ((uVar4 & 0xff0000) == 0) goto LAB_000b8a8e;
              puVar2 = puVar3 + 1;
            } while ((uVar4 & 0xff000000) != 0);
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b8a8e:
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b8a8f:
            puVar3 = (uint *)((int)puVar3 + 1);
          }
          else {
            puVar3 = puVar5;
            if (POPCOUNT(uVar4) == '\0') {
LAB_000b8a69:
              if ((char)*puVar3 != '\0') {
                puVar2 = (uint *)((int)puVar3 + 1);
                goto LAB_000b8a6e;
              }
            }
            else if (uVar4 == 2) {
LAB_000b8a64:
              if ((char)*puVar3 != '\0') {
                puVar3 = (uint *)((int)puVar3 + 1);
                goto LAB_000b8a69;
              }
            }
            else if (*(char *)puVar5 != '\0') {
              puVar3 = (uint *)((int)puVar6 + 0x33);
              goto LAB_000b8a64;
            }
          }
LAB_000b8a90:
          puVar6 = puVar5;
        } while (0x31 < (uint)((int)puVar3 - (int)puVar5));
      }
    }
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
                 (byte)((ushort)((ushort)(number_of_teams == 2.0) << 0xe) >> 8)) == 0x40) {
    if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
       (iVar1 = strcmp("#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n\n",
                       (char *)(param_1 + 0x290)), iVar1 != 0)) {
      param_1[0x311] = (int)(*gpGlobals + 10.0);
      strncpy((char *)(param_1 + 0x290),"#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n\n",0x200);
      param_1[0x310] = 0xffff;
      puVar6 = (uint *)"#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n\n";
      do {
        puVar2 = puVar6;
        uVar4 = *puVar2;
        if ((char)uVar4 == '\0') goto LAB_000b8b6e;
        if ((char)(uVar4 >> 8) == '\0') goto LAB_000b8b6d;
        if ((uVar4 & 0xff0000) == 0) goto LAB_000b8b6c;
        puVar6 = puVar2 + 1;
      } while ((uVar4 & 0xff000000) != 0);
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b8b6c:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b8b6d:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b8b6e:
      if ((uint *)0x31 < puVar2 + -0x534e8) {
        puVar6 = (uint *)"#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n\n";
        do {
          strncpy(local_38,(char *)puVar6,0x32);
          local_6 = 0;
          puVar5 = (uint *)((int)puVar6 + 0x32);
          uVar4 = (uint)puVar5 & 3;
          puVar2 = puVar5;
          if (uVar4 == 0) {
LAB_000b8bae:
            do {
              puVar3 = puVar2;
              uVar4 = *puVar3;
              if ((char)uVar4 == '\0') goto LAB_000b8bd0;
              if ((char)(uVar4 >> 8) == '\0') goto LAB_000b8bcf;
              if ((uVar4 & 0xff0000) == 0) goto LAB_000b8bce;
              puVar2 = puVar3 + 1;
            } while ((uVar4 & 0xff000000) != 0);
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b8bce:
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b8bcf:
            puVar3 = (uint *)((int)puVar3 + 1);
          }
          else {
            puVar3 = puVar5;
            if (POPCOUNT(uVar4) == '\0') {
LAB_000b8ba9:
              if ((char)*puVar3 != '\0') {
                puVar2 = (uint *)((int)puVar3 + 1);
                goto LAB_000b8bae;
              }
            }
            else if (uVar4 == 2) {
LAB_000b8ba4:
              if ((char)*puVar3 != '\0') {
                puVar3 = (uint *)((int)puVar3 + 1);
                goto LAB_000b8ba9;
              }
            }
            else if (*(char *)puVar5 != '\0') {
              puVar3 = (uint *)((int)puVar6 + 0x33);
              goto LAB_000b8ba4;
            }
          }
LAB_000b8bd0:
          puVar6 = puVar5;
        } while (0x31 < (uint)((int)puVar3 - (int)puVar5));
      }
    }
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
                 (byte)((ushort)((ushort)(number_of_teams == 3.0) << 0xe) >> 8)) == 0x40) {
    if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
       (iVar1 = strcmp("#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n\n",
                       (char *)(param_1 + 0x290)), iVar1 != 0)) {
      param_1[0x311] = (int)(*gpGlobals + 10.0);
      strncpy((char *)(param_1 + 0x290),
              "#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n\n",0x200);
      param_1[0x310] = 0xffff;
      puVar6 = (uint *)"#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n\n";
      do {
        puVar2 = puVar6;
        uVar4 = *puVar2;
        if ((char)uVar4 == '\0') goto LAB_000b8cac;
        if ((char)(uVar4 >> 8) == '\0') goto LAB_000b8cab;
        if ((uVar4 & 0xff0000) == 0) goto LAB_000b8caa;
        puVar6 = puVar2 + 1;
      } while ((uVar4 & 0xff000000) != 0);
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b8caa:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b8cab:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b8cac:
      if ((uint *)0x31 < puVar2 + -0x534f8) {
        puVar6 = (uint *)"#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n\n";
        do {
          strncpy(local_38,(char *)puVar6,0x32);
          local_6 = 0;
          puVar5 = (uint *)((int)puVar6 + 0x32);
          uVar4 = (uint)puVar5 & 3;
          puVar2 = puVar5;
          if (uVar4 == 0) {
LAB_000b8cee:
            do {
              puVar3 = puVar2;
              uVar4 = *puVar3;
              if ((char)uVar4 == '\0') goto LAB_000b8d10;
              if ((char)(uVar4 >> 8) == '\0') goto LAB_000b8d0f;
              if ((uVar4 & 0xff0000) == 0) goto LAB_000b8d0e;
              puVar2 = puVar3 + 1;
            } while ((uVar4 & 0xff000000) != 0);
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b8d0e:
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b8d0f:
            puVar3 = (uint *)((int)puVar3 + 1);
          }
          else {
            puVar3 = puVar5;
            if (POPCOUNT(uVar4) == '\0') {
LAB_000b8ce9:
              if ((char)*puVar3 != '\0') {
                puVar2 = (uint *)((int)puVar3 + 1);
                goto LAB_000b8cee;
              }
            }
            else if (uVar4 == 2) {
LAB_000b8ce4:
              if ((char)*puVar3 != '\0') {
                puVar3 = (uint *)((int)puVar3 + 1);
                goto LAB_000b8ce9;
              }
            }
            else if (*(char *)puVar5 != '\0') {
              puVar3 = (uint *)((int)puVar6 + 0x33);
              goto LAB_000b8ce4;
            }
          }
LAB_000b8d10:
          puVar6 = puVar5;
        } while (0x31 < (uint)((int)puVar3 - (int)puVar5));
      }
    }
  }
  else if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
          (iVar1 = strcmp("#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n4. #GreenTeam \n\n"
                          ,(char *)(param_1 + 0x290)), iVar1 != 0)) {
    param_1[0x311] = (int)(*gpGlobals + 10.0);
    strncpy((char *)(param_1 + 0x290),
            "#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n4. #GreenTeam \n\n",
            0x200);
    param_1[0x310] = 0xffff;
    puVar6 = (uint *)
             "#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n4. #GreenTeam \n\n";
    do {
      puVar2 = puVar6;
      uVar4 = *puVar2;
      if ((char)uVar4 == '\0') goto LAB_000b8dd6;
      if ((char)(uVar4 >> 8) == '\0') goto LAB_000b8dd5;
      if ((uVar4 & 0xff0000) == 0) goto LAB_000b8dd4;
      puVar6 = puVar2 + 1;
    } while ((uVar4 & 0xff000000) != 0);
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b8dd4:
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b8dd5:
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b8dd6:
    if ((uint *)0x31 < puVar2 + -0x53508) {
      puVar6 = (uint *)
               "#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n4. #GreenTeam \n\n"
      ;
      do {
        strncpy(local_38,(char *)puVar6,0x32);
        local_6 = 0;
        puVar5 = (uint *)((int)puVar6 + 0x32);
        uVar4 = (uint)puVar5 & 3;
        puVar2 = puVar5;
        if (uVar4 == 0) {
LAB_000b8e12:
          do {
            puVar3 = puVar2;
            uVar4 = *puVar3;
            if ((char)uVar4 == '\0') goto LAB_000b8e34;
            if ((char)(uVar4 >> 8) == '\0') goto LAB_000b8e33;
            if ((uVar4 & 0xff0000) == 0) goto LAB_000b8e32;
            puVar2 = puVar3 + 1;
          } while ((uVar4 & 0xff000000) != 0);
          puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b8e32:
          puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b8e33:
          puVar3 = (uint *)((int)puVar3 + 1);
        }
        else {
          puVar3 = puVar5;
          if (POPCOUNT(uVar4) == '\0') {
LAB_000b8e0d:
            if ((char)*puVar3 != '\0') {
              puVar2 = (uint *)((int)puVar3 + 1);
              goto LAB_000b8e12;
            }
          }
          else if (uVar4 == 2) {
LAB_000b8e08:
            if ((char)*puVar3 != '\0') {
              puVar3 = (uint *)((int)puVar3 + 1);
              goto LAB_000b8e0d;
            }
          }
          else if (*(char *)puVar5 != '\0') {
            puVar3 = (uint *)((int)puVar6 + 0x33);
            goto LAB_000b8e08;
          }
        }
LAB_000b8e34:
        puVar6 = puVar5;
      } while (0x31 < (uint)((int)puVar3 - (int)puVar5));
    }
  }
  return;
}


// Menu_Spy_Input__11CBasePlayerf  @ 000b874c
void Menu_Spy_Input__11CBasePlayerf(int *param_1,float param_2)

{
  char *pcVar1;
  int iVar2;
  
  if (((byte)(1.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) == 0x40) ||
     ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_2 == 2.0) << 0xe) >> 8)) == 0x40)) {
    if ((*(byte *)(*param_1 + 0x118) & 5) == 0) {
      if (param_1[0x1d] != 1) goto LAB_000b87c8;
      pcVar1 = "#Spy_unable";
    }
    else {
      pcVar1 = "#Spy_glowing";
    }
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,pcVar1,0,0,0,0);
  }
  else {
LAB_000b87c8:
    if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) == 0x40) {
      Menu_Spy_Skin__11CBasePlayer(param_1);
      iVar2 = *param_1;
      param_1[0x44] = 0x41500000;
      param_1[0x45] = 0;
      goto LAB_000b88c4;
    }
    if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2 == 2.0) << 0xe) >> 8)) == 0x40) {
      Menu_Spy_Color__11CBasePlayer(param_1);
      iVar2 = *param_1;
      param_1[0x44] = 0x41600000;
      param_1[0x45] = 0;
      goto LAB_000b88c4;
    }
    if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2 == 3.0) << 0xe) >> 8)) == 0x40) {
      TeamFortress_SpyFeignDeath__11CBasePlayeri(param_1,0);
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                   (byte)((ushort)((ushort)(param_2 == 4.0) << 0xe) >> 8)) == 0x40) {
      Spy_RemoveDisguise__11CBasePlayer(param_1);
    }
    else {
      if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                (byte)((ushort)((ushort)(param_2 == 5.0) << 0xe) >> 8)) != 0x40) {
        return;
      }
      if ((param_1[0x75] == 0) && (param_1[0x76] == 0)) {
        return;
      }
    }
  }
  *(undefined1 *)(param_1 + 0x290) = 0;
  iVar2 = *param_1;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x44] = 0x3f800000;
LAB_000b88c4:
  *(undefined4 *)(iVar2 + 0x184) = 0;
  return;
}


// Menu_Spy_Skin_Input__11CBasePlayerf  @ 000ba5f4
void Menu_Spy_Skin_Input__11CBasePlayerf(int *param_1,float param_2)

{
  if ((0x3f < (byte)((10.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                     (byte)((ushort)((ushort)(param_2 == 10.0) << 0xe) >> 8)) - 1)) &&
     (0.0 < param_2)) {
    TeamFortress_SpyChangeSkin__11CBasePlayeri(param_1,(int)ROUND(param_2));
    *(undefined1 *)(param_1 + 0x290) = 0;
    param_1[0x45] = 0;
    param_1[0x46] = 0;
    param_1[0x44] = 0x3f800000;
    *(undefined4 *)(*param_1 + 0x184) = 0;
  }
  return;
}


// Menu_Spy_Skin__11CBasePlayer  @ 000ba690
/* WARNING: Removing unreachable block (ram,0x000ba728) */
/* WARNING: Removing unreachable block (ram,0x000ba72a) */
/* WARNING: Removing unreachable block (ram,0x000ba72f) */
/* WARNING: Removing unreachable block (ram,0x000ba733) */
/* WARNING: Removing unreachable block (ram,0x000ba734) */
/* WARNING: Removing unreachable block (ram,0x000ba738) */
/* WARNING: Removing unreachable block (ram,0x000ba739) */
/* WARNING: Removing unreachable block (ram,0x000ba73d) */

void Menu_Spy_Skin__11CBasePlayer(int param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  char local_38 [50];
  undefined1 local_6;
  
  if (((*(float *)(param_1 + 0xc44) <= *gpGlobals) || (*(int *)(param_1 + 0xc40) != 0xffff)) ||
     (iVar1 = strcmp("#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
                     ,(char *)(param_1 + 0xa40)), iVar1 != 0)) {
    *(float *)(param_1 + 0xc44) = *gpGlobals + 10.0;
    strncpy((char *)(param_1 + 0xa40),
            "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
            ,0x200);
    *(undefined4 *)(param_1 + 0xc40) = 0xffff;
    puVar5 = (uint *)
             "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
    ;
    do {
      puVar2 = puVar5;
      uVar4 = *puVar2;
      if ((char)uVar4 == '\0') goto LAB_000ba760;
      if ((char)(uVar4 >> 8) == '\0') goto LAB_000ba75f;
      if ((uVar4 & 0xff0000) == 0) goto LAB_000ba75e;
      puVar5 = puVar2 + 1;
    } while ((uVar4 & 0xff000000) != 0);
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000ba75e:
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000ba75f:
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000ba760:
    if ((uint *)0x31 < puVar2 + -0x534b0) {
      puVar5 = (uint *)
               "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
      ;
      do {
        strncpy(local_38,(char *)puVar5,0x32);
        local_6 = 0;
        puVar6 = (uint *)((int)puVar5 + 0x32);
        uVar4 = (uint)puVar6 & 3;
        puVar2 = puVar6;
        if (uVar4 == 0) {
LAB_000ba79e:
          do {
            puVar3 = puVar2;
            uVar4 = *puVar3;
            if ((char)uVar4 == '\0') goto LAB_000ba7c0;
            if ((char)(uVar4 >> 8) == '\0') goto LAB_000ba7bf;
            if ((uVar4 & 0xff0000) == 0) goto LAB_000ba7be;
            puVar2 = puVar3 + 1;
          } while ((uVar4 & 0xff000000) != 0);
          puVar3 = (uint *)((int)puVar3 + 1);
LAB_000ba7be:
          puVar3 = (uint *)((int)puVar3 + 1);
LAB_000ba7bf:
          puVar3 = (uint *)((int)puVar3 + 1);
        }
        else {
          puVar3 = puVar6;
          if (POPCOUNT(uVar4) == '\0') {
LAB_000ba799:
            if ((char)*puVar3 != '\0') {
              puVar2 = (uint *)((int)puVar3 + 1);
              goto LAB_000ba79e;
            }
          }
          else if (uVar4 == 2) {
LAB_000ba794:
            if ((char)*puVar3 != '\0') {
              puVar3 = (uint *)((int)puVar3 + 1);
              goto LAB_000ba799;
            }
          }
          else if (*(char *)puVar6 != '\0') {
            puVar3 = (uint *)((int)puVar5 + 0x33);
            goto LAB_000ba794;
          }
        }
LAB_000ba7c0:
        puVar5 = puVar6;
      } while (0x31 < (uint)((int)puVar3 - (int)puVar6));
    }
  }
  return;
}


// Menu_Spy__11CBasePlayer  @ 000b7d50
/* WARNING: Removing unreachable block (ram,0x000b7f76) */
/* WARNING: Removing unreachable block (ram,0x000b7f78) */
/* WARNING: Removing unreachable block (ram,0x000b7f7d) */
/* WARNING: Removing unreachable block (ram,0x000b7f81) */
/* WARNING: Removing unreachable block (ram,0x000b7f82) */
/* WARNING: Removing unreachable block (ram,0x000b7f86) */
/* WARNING: Removing unreachable block (ram,0x000b7f87) */
/* WARNING: Removing unreachable block (ram,0x000b7f8b) */
/* WARNING: Removing unreachable block (ram,0x000b81d6) */
/* WARNING: Removing unreachable block (ram,0x000b81d8) */
/* WARNING: Removing unreachable block (ram,0x000b81dd) */
/* WARNING: Removing unreachable block (ram,0x000b81e1) */
/* WARNING: Removing unreachable block (ram,0x000b81e2) */
/* WARNING: Removing unreachable block (ram,0x000b81e6) */
/* WARNING: Removing unreachable block (ram,0x000b81e7) */
/* WARNING: Removing unreachable block (ram,0x000b81eb) */
/* WARNING: Removing unreachable block (ram,0x000b8442) */
/* WARNING: Removing unreachable block (ram,0x000b8444) */
/* WARNING: Removing unreachable block (ram,0x000b8449) */
/* WARNING: Removing unreachable block (ram,0x000b844d) */
/* WARNING: Removing unreachable block (ram,0x000b844e) */
/* WARNING: Removing unreachable block (ram,0x000b8452) */
/* WARNING: Removing unreachable block (ram,0x000b8453) */
/* WARNING: Removing unreachable block (ram,0x000b8457) */
/* WARNING: Removing unreachable block (ram,0x000b8577) */
/* WARNING: Removing unreachable block (ram,0x000b8579) */
/* WARNING: Removing unreachable block (ram,0x000b857e) */
/* WARNING: Removing unreachable block (ram,0x000b8582) */
/* WARNING: Removing unreachable block (ram,0x000b8583) */
/* WARNING: Removing unreachable block (ram,0x000b8587) */
/* WARNING: Removing unreachable block (ram,0x000b8588) */
/* WARNING: Removing unreachable block (ram,0x000b858c) */
/* WARNING: Removing unreachable block (ram,0x000b8318) */
/* WARNING: Removing unreachable block (ram,0x000b831a) */
/* WARNING: Removing unreachable block (ram,0x000b831f) */
/* WARNING: Removing unreachable block (ram,0x000b8323) */
/* WARNING: Removing unreachable block (ram,0x000b8324) */
/* WARNING: Removing unreachable block (ram,0x000b8328) */
/* WARNING: Removing unreachable block (ram,0x000b8329) */
/* WARNING: Removing unreachable block (ram,0x000b832d) */
/* WARNING: Removing unreachable block (ram,0x000b80ab) */
/* WARNING: Removing unreachable block (ram,0x000b80ad) */
/* WARNING: Removing unreachable block (ram,0x000b80b2) */
/* WARNING: Removing unreachable block (ram,0x000b80b6) */
/* WARNING: Removing unreachable block (ram,0x000b80b7) */
/* WARNING: Removing unreachable block (ram,0x000b80bb) */
/* WARNING: Removing unreachable block (ram,0x000b80bc) */
/* WARNING: Removing unreachable block (ram,0x000b80c0) */
/* WARNING: Removing unreachable block (ram,0x000b7e4e) */
/* WARNING: Removing unreachable block (ram,0x000b7e50) */
/* WARNING: Removing unreachable block (ram,0x000b7e55) */
/* WARNING: Removing unreachable block (ram,0x000b7e59) */
/* WARNING: Removing unreachable block (ram,0x000b7e5a) */
/* WARNING: Removing unreachable block (ram,0x000b7e5e) */
/* WARNING: Removing unreachable block (ram,0x000b7e5f) */
/* WARNING: Removing unreachable block (ram,0x000b7e63) */
/* WARNING: Removing unreachable block (ram,0x000b86a2) */
/* WARNING: Removing unreachable block (ram,0x000b86a4) */
/* WARNING: Removing unreachable block (ram,0x000b86a9) */
/* WARNING: Removing unreachable block (ram,0x000b86ad) */
/* WARNING: Removing unreachable block (ram,0x000b86ae) */
/* WARNING: Removing unreachable block (ram,0x000b86b2) */
/* WARNING: Removing unreachable block (ram,0x000b86b3) */
/* WARNING: Removing unreachable block (ram,0x000b86b7) */

void Menu_Spy__11CBasePlayer(int *param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  code *pcVar4;
  code *pcVar5;
  uint uVar6;
  uint *puVar7;
  code *pcVar8;
  code *pcVar9;
  uint *puVar10;
  char local_38 [50];
  undefined1 local_6;
  
  if (((*(byte *)(*param_1 + 0x118) & 5) == 0) && (param_1[0x1d] != 1)) {
    if (param_1[0x1c] == 0) {
      if (param_1[0x75] == 0) {
        if (param_1[0x76] == 0) {
          if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
             (iVar1 = strcmp("#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Nothing \n\n"
                             ,(char *)(param_1 + 0x290)), iVar1 != 0)) {
            param_1[0x311] = (int)(*gpGlobals + 10.0);
            strncpy((char *)(param_1 + 0x290),
                    "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Nothing \n\n"
                    ,0x200);
            param_1[0x310] = 0xffff;
            puVar10 = (uint *)
                      "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Nothing \n\n"
            ;
            do {
              puVar2 = puVar10;
              uVar6 = *puVar2;
              if ((char)uVar6 == '\0') goto LAB_000b86da;
              if ((char)(uVar6 >> 8) == '\0') goto LAB_000b86d9;
              if ((uVar6 & 0xff0000) == 0) goto LAB_000b86d8;
              puVar10 = puVar2 + 1;
            } while ((uVar6 & 0xff000000) != 0);
            puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b86d8:
            puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b86d9:
            puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b86da:
            if ((uint *)0x31 < puVar2 + -0x53488) {
              puVar10 = (uint *)
                        "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Nothing \n\n"
              ;
              do {
                strncpy(local_38,(char *)puVar10,0x32);
                local_6 = 0;
                puVar7 = (uint *)((int)puVar10 + 0x32);
                uVar6 = (uint)puVar7 & 3;
                puVar2 = puVar7;
                if (uVar6 == 0) {
LAB_000b8716:
                  do {
                    puVar3 = puVar2;
                    uVar6 = *puVar3;
                    if ((char)uVar6 == '\0') goto LAB_000b8738;
                    if ((char)(uVar6 >> 8) == '\0') goto LAB_000b8737;
                    if ((uVar6 & 0xff0000) == 0) goto LAB_000b8736;
                    puVar2 = puVar3 + 1;
                  } while ((uVar6 & 0xff000000) != 0);
                  puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b8736:
                  puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b8737:
                  puVar3 = (uint *)((int)puVar3 + 1);
                }
                else {
                  puVar3 = puVar7;
                  if (POPCOUNT(uVar6) == '\0') {
LAB_000b8711:
                    if ((char)*puVar3 != '\0') {
                      puVar2 = (uint *)((int)puVar3 + 1);
                      goto LAB_000b8716;
                    }
                  }
                  else if (uVar6 == 2) {
LAB_000b870c:
                    if ((char)*puVar3 != '\0') {
                      puVar3 = (uint *)((int)puVar3 + 1);
                      goto LAB_000b8711;
                    }
                  }
                  else if (*(char *)puVar7 != '\0') {
                    puVar3 = (uint *)((int)puVar10 + 0x33);
                    goto LAB_000b870c;
                  }
                }
LAB_000b8738:
                puVar10 = puVar7;
              } while (0x31 < (uint)((int)puVar3 - (int)puVar7));
            }
          }
        }
        else if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
                (iVar1 = strcmp((char *)FUN_0014d1a0,(char *)(param_1 + 0x290)), iVar1 != 0)) {
          param_1[0x311] = (int)(*gpGlobals + 10.0);
          strncpy((char *)(param_1 + 0x290),(char *)FUN_0014d1a0,0x200);
          param_1[0x310] = 0xffff;
          pcVar8 = FUN_0014d1a0;
          do {
            pcVar4 = pcVar8;
            uVar6 = *(uint *)pcVar4;
            if ((char)uVar6 == '\0') goto LAB_000b85af;
            if ((char)(uVar6 >> 8) == '\0') goto LAB_000b85ae;
            if ((uVar6 & 0xff0000) == 0) goto LAB_000b85ad;
            pcVar8 = pcVar4 + 4;
          } while ((uVar6 & 0xff000000) != 0);
          pcVar4 = pcVar4 + 1;
LAB_000b85ad:
          pcVar4 = pcVar4 + 1;
LAB_000b85ae:
          pcVar4 = pcVar4 + 1;
LAB_000b85af:
          if ((code *)0x31 < pcVar4 + -0x14d1a0) {
            pcVar8 = FUN_0014d1a0;
            do {
              strncpy(local_38,(char *)pcVar8,0x32);
              local_6 = 0;
              pcVar9 = pcVar8 + 0x32;
              uVar6 = (uint)pcVar9 & 3;
              pcVar4 = pcVar9;
              if (uVar6 == 0) {
LAB_000b85f2:
                do {
                  pcVar5 = pcVar4;
                  uVar6 = *(uint *)pcVar5;
                  if ((char)uVar6 == '\0') goto LAB_000b8614;
                  if ((char)(uVar6 >> 8) == '\0') goto LAB_000b8613;
                  if ((uVar6 & 0xff0000) == 0) goto LAB_000b8612;
                  pcVar4 = pcVar5 + 4;
                } while ((uVar6 & 0xff000000) != 0);
                pcVar5 = pcVar5 + 1;
LAB_000b8612:
                pcVar5 = pcVar5 + 1;
LAB_000b8613:
                pcVar5 = pcVar5 + 1;
              }
              else {
                pcVar5 = pcVar9;
                if (POPCOUNT(uVar6) == '\0') {
LAB_000b85ed:
                  if (*pcVar5 != (code)0x0) {
                    pcVar4 = pcVar5 + 1;
                    goto LAB_000b85f2;
                  }
                }
                else if (uVar6 == 2) {
LAB_000b85e8:
                  if (*pcVar5 != (code)0x0) {
                    pcVar5 = pcVar5 + 1;
                    goto LAB_000b85ed;
                  }
                }
                else if (*pcVar9 != (code)0x0) {
                  pcVar5 = pcVar8 + 0x33;
                  goto LAB_000b85e8;
                }
              }
LAB_000b8614:
              pcVar8 = pcVar9;
            } while (0x31 < (uint)((int)pcVar5 - (int)pcVar9));
          }
        }
      }
      else if (param_1[0x76] == 0) {
        if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
           (iVar1 = strcmp("#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n"
                           ,(char *)(param_1 + 0x290)), iVar1 != 0)) {
          param_1[0x311] = (int)(*gpGlobals + 10.0);
          strncpy((char *)(param_1 + 0x290),
                  "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n"
                  ,0x200);
          param_1[0x310] = 0xffff;
          puVar10 = (uint *)
                    "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n"
          ;
          do {
            puVar2 = puVar10;
            uVar6 = *puVar2;
            if ((char)uVar6 == '\0') goto LAB_000b847a;
            if ((char)(uVar6 >> 8) == '\0') goto LAB_000b8479;
            if ((uVar6 & 0xff0000) == 0) goto LAB_000b8478;
            puVar10 = puVar2 + 1;
          } while ((uVar6 & 0xff000000) != 0);
          puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b8478:
          puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b8479:
          puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b847a:
          if ((uint *)0x31 < puVar2 + -0x53448) {
            puVar10 = (uint *)
                      "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n"
            ;
            do {
              strncpy(local_38,(char *)puVar10,0x32);
              local_6 = 0;
              puVar7 = (uint *)((int)puVar10 + 0x32);
              uVar6 = (uint)puVar7 & 3;
              puVar2 = puVar7;
              if (uVar6 == 0) {
LAB_000b84ba:
                do {
                  puVar3 = puVar2;
                  uVar6 = *puVar3;
                  if ((char)uVar6 == '\0') goto LAB_000b84dc;
                  if ((char)(uVar6 >> 8) == '\0') goto LAB_000b84db;
                  if ((uVar6 & 0xff0000) == 0) goto LAB_000b84da;
                  puVar2 = puVar3 + 1;
                } while ((uVar6 & 0xff000000) != 0);
                puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b84da:
                puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b84db:
                puVar3 = (uint *)((int)puVar3 + 1);
              }
              else {
                puVar3 = puVar7;
                if (POPCOUNT(uVar6) == '\0') {
LAB_000b84b5:
                  if ((char)*puVar3 != '\0') {
                    puVar2 = (uint *)((int)puVar3 + 1);
                    goto LAB_000b84ba;
                  }
                }
                else if (uVar6 == 2) {
LAB_000b84b0:
                  if ((char)*puVar3 != '\0') {
                    puVar3 = (uint *)((int)puVar3 + 1);
                    goto LAB_000b84b5;
                  }
                }
                else if (*(char *)puVar7 != '\0') {
                  puVar3 = (uint *)((int)puVar10 + 0x33);
                  goto LAB_000b84b0;
                }
              }
LAB_000b84dc:
              puVar10 = puVar7;
            } while (0x31 < (uint)((int)puVar3 - (int)puVar7));
          }
        }
      }
      else if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
              (iVar1 = strcmp("#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetskinandcolor \n5. #Nothing \n\n"
                              ,(char *)(param_1 + 0x290)), iVar1 != 0)) {
        param_1[0x311] = (int)(*gpGlobals + 10.0);
        strncpy((char *)(param_1 + 0x290),
                "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetskinandcolor \n5. #Nothing \n\n"
                ,0x200);
        param_1[0x310] = 0xffff;
        puVar10 = (uint *)
                  "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetskinandcolor \n5. #Nothing \n\n"
        ;
        do {
          puVar2 = puVar10;
          uVar6 = *puVar2;
          if ((char)uVar6 == '\0') goto LAB_000b8350;
          if ((char)(uVar6 >> 8) == '\0') goto LAB_000b834f;
          if ((uVar6 & 0xff0000) == 0) goto LAB_000b834e;
          puVar10 = puVar2 + 1;
        } while ((uVar6 & 0xff000000) != 0);
        puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b834e:
        puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b834f:
        puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b8350:
        if ((uint *)0x31 < puVar2 + -0x53428) {
          puVar10 = (uint *)
                    "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetskinandcolor \n5. #Nothing \n\n"
          ;
          do {
            strncpy(local_38,(char *)puVar10,0x32);
            local_6 = 0;
            puVar7 = (uint *)((int)puVar10 + 0x32);
            uVar6 = (uint)puVar7 & 3;
            puVar2 = puVar7;
            if (uVar6 == 0) {
LAB_000b8392:
              do {
                puVar3 = puVar2;
                uVar6 = *puVar3;
                if ((char)uVar6 == '\0') goto LAB_000b83b4;
                if ((char)(uVar6 >> 8) == '\0') goto LAB_000b83b3;
                if ((uVar6 & 0xff0000) == 0) goto LAB_000b83b2;
                puVar2 = puVar3 + 1;
              } while ((uVar6 & 0xff000000) != 0);
              puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b83b2:
              puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b83b3:
              puVar3 = (uint *)((int)puVar3 + 1);
            }
            else {
              puVar3 = puVar7;
              if (POPCOUNT(uVar6) == '\0') {
LAB_000b838d:
                if ((char)*puVar3 != '\0') {
                  puVar2 = (uint *)((int)puVar3 + 1);
                  goto LAB_000b8392;
                }
              }
              else if (uVar6 == 2) {
LAB_000b8388:
                if ((char)*puVar3 != '\0') {
                  puVar3 = (uint *)((int)puVar3 + 1);
                  goto LAB_000b838d;
                }
              }
              else if (*(char *)puVar7 != '\0') {
                puVar3 = (uint *)((int)puVar10 + 0x33);
                goto LAB_000b8388;
              }
            }
LAB_000b83b4:
            puVar10 = puVar7;
          } while (0x31 < (uint)((int)puVar3 - (int)puVar7));
        }
      }
    }
    else if (param_1[0x75] == 0) {
      if (param_1[0x76] == 0) {
        if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
           (iVar1 = strcmp("#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Nothing \n\n"
                           ,(char *)(param_1 + 0x290)), iVar1 != 0)) {
          param_1[0x311] = (int)(*gpGlobals + 10.0);
          strncpy((char *)(param_1 + 0x290),
                  "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Nothing \n\n"
                  ,0x200);
          param_1[0x310] = 0xffff;
          puVar10 = (uint *)
                    "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Nothing \n\n"
          ;
          do {
            puVar2 = puVar10;
            uVar6 = *puVar2;
            if ((char)uVar6 == '\0') goto LAB_000b820e;
            if ((char)(uVar6 >> 8) == '\0') goto LAB_000b820d;
            if ((uVar6 & 0xff0000) == 0) goto LAB_000b820c;
            puVar10 = puVar2 + 1;
          } while ((uVar6 & 0xff000000) != 0);
          puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b820c:
          puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b820d:
          puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b820e:
          if ((uint *)0x31 < puVar2 + -0x53410) {
            puVar10 = (uint *)
                      "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Nothing \n\n"
            ;
            do {
              strncpy(local_38,(char *)puVar10,0x32);
              local_6 = 0;
              puVar7 = (uint *)((int)puVar10 + 0x32);
              uVar6 = (uint)puVar7 & 3;
              puVar2 = puVar7;
              if (uVar6 == 0) {
LAB_000b824e:
                do {
                  puVar3 = puVar2;
                  uVar6 = *puVar3;
                  if ((char)uVar6 == '\0') goto LAB_000b8270;
                  if ((char)(uVar6 >> 8) == '\0') goto LAB_000b826f;
                  if ((uVar6 & 0xff0000) == 0) goto LAB_000b826e;
                  puVar2 = puVar3 + 1;
                } while ((uVar6 & 0xff000000) != 0);
                puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b826e:
                puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b826f:
                puVar3 = (uint *)((int)puVar3 + 1);
              }
              else {
                puVar3 = puVar7;
                if (POPCOUNT(uVar6) == '\0') {
LAB_000b8249:
                  if ((char)*puVar3 != '\0') {
                    puVar2 = (uint *)((int)puVar3 + 1);
                    goto LAB_000b824e;
                  }
                }
                else if (uVar6 == 2) {
LAB_000b8244:
                  if ((char)*puVar3 != '\0') {
                    puVar3 = (uint *)((int)puVar3 + 1);
                    goto LAB_000b8249;
                  }
                }
                else if (*(char *)puVar7 != '\0') {
                  puVar3 = (uint *)((int)puVar10 + 0x33);
                  goto LAB_000b8244;
                }
              }
LAB_000b8270:
              puVar10 = puVar7;
            } while (0x31 < (uint)((int)puVar3 - (int)puVar7));
          }
        }
      }
      else if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
              (iVar1 = strcmp("#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetskin \n5. #Nothing \n\n"
                              ,(char *)(param_1 + 0x290)), iVar1 != 0)) {
        param_1[0x311] = (int)(*gpGlobals + 10.0);
        strncpy((char *)(param_1 + 0x290),
                "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetskin \n5. #Nothing \n\n"
                ,0x200);
        param_1[0x310] = 0xffff;
        puVar10 = (uint *)
                  "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetskin \n5. #Nothing \n\n"
        ;
        do {
          puVar2 = puVar10;
          uVar6 = *puVar2;
          if ((char)uVar6 == '\0') goto LAB_000b80e3;
          if ((char)(uVar6 >> 8) == '\0') goto LAB_000b80e2;
          if ((uVar6 & 0xff0000) == 0) goto LAB_000b80e1;
          puVar10 = puVar2 + 1;
        } while ((uVar6 & 0xff000000) != 0);
        puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b80e1:
        puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b80e2:
        puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b80e3:
        if ((uint *)0x31 < puVar2 + -0x533f0) {
          puVar10 = (uint *)
                    "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetskin \n5. #Nothing \n\n"
          ;
          do {
            strncpy(local_38,(char *)puVar10,0x32);
            local_6 = 0;
            puVar7 = (uint *)((int)puVar10 + 0x32);
            uVar6 = (uint)puVar7 & 3;
            puVar2 = puVar7;
            if (uVar6 == 0) {
LAB_000b8126:
              do {
                puVar3 = puVar2;
                uVar6 = *puVar3;
                if ((char)uVar6 == '\0') goto LAB_000b8148;
                if ((char)(uVar6 >> 8) == '\0') goto LAB_000b8147;
                if ((uVar6 & 0xff0000) == 0) goto LAB_000b8146;
                puVar2 = puVar3 + 1;
              } while ((uVar6 & 0xff000000) != 0);
              puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b8146:
              puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b8147:
              puVar3 = (uint *)((int)puVar3 + 1);
            }
            else {
              puVar3 = puVar7;
              if (POPCOUNT(uVar6) == '\0') {
LAB_000b8121:
                if ((char)*puVar3 != '\0') {
                  puVar2 = (uint *)((int)puVar3 + 1);
                  goto LAB_000b8126;
                }
              }
              else if (uVar6 == 2) {
LAB_000b811c:
                if ((char)*puVar3 != '\0') {
                  puVar3 = (uint *)((int)puVar3 + 1);
                  goto LAB_000b8121;
                }
              }
              else if (*(char *)puVar7 != '\0') {
                puVar3 = (uint *)((int)puVar10 + 0x33);
                goto LAB_000b811c;
              }
            }
LAB_000b8148:
            puVar10 = puVar7;
          } while (0x31 < (uint)((int)puVar3 - (int)puVar7));
        }
      }
    }
    else if (param_1[0x76] == 0) {
      if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
         (iVar1 = strcmp("#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n"
                         ,(char *)(param_1 + 0x290)), iVar1 != 0)) {
        param_1[0x311] = (int)(*gpGlobals + 10.0);
        strncpy((char *)(param_1 + 0x290),
                "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n"
                ,0x200);
        param_1[0x310] = 0xffff;
        puVar10 = (uint *)
                  "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n"
        ;
        do {
          puVar2 = puVar10;
          uVar6 = *puVar2;
          if ((char)uVar6 == '\0') goto LAB_000b7fae;
          if ((char)(uVar6 >> 8) == '\0') goto LAB_000b7fad;
          if ((uVar6 & 0xff0000) == 0) goto LAB_000b7fac;
          puVar10 = puVar2 + 1;
        } while ((uVar6 & 0xff000000) != 0);
        puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b7fac:
        puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b7fad:
        puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b7fae:
        if ((uint *)0x31 < puVar2 + -0x533d0) {
          puVar10 = (uint *)
                    "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n"
          ;
          do {
            strncpy(local_38,(char *)puVar10,0x32);
            local_6 = 0;
            puVar7 = (uint *)((int)puVar10 + 0x32);
            uVar6 = (uint)puVar7 & 3;
            puVar2 = puVar7;
            if (uVar6 == 0) {
LAB_000b7fee:
              do {
                puVar3 = puVar2;
                uVar6 = *puVar3;
                if ((char)uVar6 == '\0') goto LAB_000b8010;
                if ((char)(uVar6 >> 8) == '\0') goto LAB_000b800f;
                if ((uVar6 & 0xff0000) == 0) goto LAB_000b800e;
                puVar2 = puVar3 + 1;
              } while ((uVar6 & 0xff000000) != 0);
              puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b800e:
              puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b800f:
              puVar3 = (uint *)((int)puVar3 + 1);
            }
            else {
              puVar3 = puVar7;
              if (POPCOUNT(uVar6) == '\0') {
LAB_000b7fe9:
                if ((char)*puVar3 != '\0') {
                  puVar2 = (uint *)((int)puVar3 + 1);
                  goto LAB_000b7fee;
                }
              }
              else if (uVar6 == 2) {
LAB_000b7fe4:
                if ((char)*puVar3 != '\0') {
                  puVar3 = (uint *)((int)puVar3 + 1);
                  goto LAB_000b7fe9;
                }
              }
              else if (*(char *)puVar7 != '\0') {
                puVar3 = (uint *)((int)puVar10 + 0x33);
                goto LAB_000b7fe4;
              }
            }
LAB_000b8010:
            puVar10 = puVar7;
          } while (0x31 < (uint)((int)puVar3 - (int)puVar7));
        }
      }
    }
    else if ((((float)param_1[0x311] <= *gpGlobals) || (param_1[0x310] != 0xffff)) ||
            (iVar1 = strcmp("#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetskinandcolor \n5. #Nothing \n\n"
                            ,(char *)(param_1 + 0x290)), iVar1 != 0)) {
      param_1[0x311] = (int)(*gpGlobals + 10.0);
      strncpy((char *)(param_1 + 0x290),
              "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetskinandcolor \n5. #Nothing \n\n"
              ,0x200);
      param_1[0x310] = 0xffff;
      puVar10 = (uint *)0x14cec0;
      do {
        puVar2 = puVar10;
        uVar6 = *puVar2;
        if ((char)uVar6 == '\0') goto LAB_000b7e86;
        if ((char)(uVar6 >> 8) == '\0') goto LAB_000b7e85;
        if ((uVar6 & 0xff0000) == 0) goto LAB_000b7e84;
        puVar10 = puVar2 + 1;
      } while ((uVar6 & 0xff000000) != 0);
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b7e84:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b7e85:
      puVar2 = (uint *)((int)puVar2 + 1);
LAB_000b7e86:
      if ((uint *)0x31 < puVar2 + -0x533b0) {
        puVar10 = (uint *)0x14cec0;
        do {
          strncpy(local_38,(char *)puVar10,0x32);
          local_6 = 0;
          puVar7 = (uint *)((int)puVar10 + 0x32);
          uVar6 = (uint)puVar7 & 3;
          puVar2 = puVar7;
          if (uVar6 == 0) {
LAB_000b7ec6:
            do {
              puVar3 = puVar2;
              uVar6 = *puVar3;
              if ((char)uVar6 == '\0') goto LAB_000b7ee8;
              if ((char)(uVar6 >> 8) == '\0') goto LAB_000b7ee7;
              if ((uVar6 & 0xff0000) == 0) goto LAB_000b7ee6;
              puVar2 = puVar3 + 1;
            } while ((uVar6 & 0xff000000) != 0);
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b7ee6:
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_000b7ee7:
            puVar3 = (uint *)((int)puVar3 + 1);
          }
          else {
            puVar3 = puVar7;
            if (POPCOUNT(uVar6) == '\0') {
LAB_000b7ec1:
              if ((char)*puVar3 != '\0') {
                puVar2 = (uint *)((int)puVar3 + 1);
                goto LAB_000b7ec6;
              }
            }
            else if (uVar6 == 2) {
LAB_000b7ebc:
              if ((char)*puVar3 != '\0') {
                puVar3 = (uint *)((int)puVar3 + 1);
                goto LAB_000b7ec1;
              }
            }
            else if (*(char *)puVar7 != '\0') {
              puVar3 = (uint *)((int)puVar10 + 0x33);
              goto LAB_000b7ebc;
            }
          }
LAB_000b7ee8:
          puVar10 = puVar7;
        } while (0x31 < (uint)((int)puVar3 - (int)puVar7));
      }
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x290) = 0;
    param_1[0x45] = 0;
    param_1[0x46] = 0;
    param_1[0x44] = 0x3f800000;
  }
  return;
}


// Menu_Team__11CBasePlayer  @ 000bab1c
void Menu_Team__11CBasePlayer(int *param_1)

{
  int iVar1;
  
  if ((((30.0 < *gpGlobals) &&
       ((byte)((float)tfc_autoteam._12_4_ < 0.0 |
               (byte)((ushort)((ushort)NAN((float)tfc_autoteam._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)tfc_autoteam._12_4_ == 0.0) << 0xe) >> 8)) != 0x40))
      && (iVar1 = (**(code **)(*g_pGameRules + 0x28))(g_pGameRules), iVar1 != 0)) &&
     (iVar1 = TeamFortress_TeamPutPlayerInTeam__11CBasePlayer(param_1), iVar1 != 0)) {
    return;
  }
  param_1[0x44] = 0x40000000;
  (*DAT_0019f758)(1,gmsgVGUIMenu,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_0019f760)(2);
  (*DAT_0019f75c)();
  return;
}


