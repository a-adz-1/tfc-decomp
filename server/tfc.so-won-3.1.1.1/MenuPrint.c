// MenuPrint__FP11CBasePlayerPCcii  @ 000babe0
void MenuPrint__FP11CBasePlayerPCcii(int param_1,uint *param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  char local_38 [50];
  undefined1 local_6;
  
  if (((*gpGlobals < *(float *)(param_1 + 0xc44)) && (param_3 == *(int *)(param_1 + 0xc40))) &&
     (iVar2 = strcmp((char *)param_2,(char *)(param_1 + 0xa40)), iVar2 == 0)) {
    return;
  }
  *(float *)(param_1 + 0xc44) = *gpGlobals + 10.0;
  strncpy((char *)(param_1 + 0xa40),(char *)param_2,0x200);
  *(int *)(param_1 + 0xc40) = param_3;
  uVar5 = (uint)param_2 & 3;
  puVar1 = param_2;
  if (uVar5 != 0) {
    puVar3 = param_2;
    if ((POPCOUNT(uVar5) & 1U) != 0) {
      if (uVar5 != 2) {
        if ((char)*param_2 == '\0') goto LAB_000bacac;
        puVar3 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar3 == '\0') goto LAB_000bacac;
      puVar3 = (uint *)((int)puVar3 + 1);
    }
    if ((char)*puVar3 == '\0') goto LAB_000bacac;
    puVar1 = (uint *)((int)puVar3 + 1);
  }
  do {
    puVar3 = puVar1;
    uVar5 = *puVar3;
    if ((char)uVar5 == '\0') goto LAB_000bacac;
    if ((char)(uVar5 >> 8) == '\0') goto LAB_000bacab;
    if ((uVar5 & 0xff0000) == 0) goto LAB_000bacaa;
    puVar1 = puVar3 + 1;
  } while ((uVar5 & 0xff000000) != 0);
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_000bacaa:
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_000bacab:
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_000bacac:
  if (0x31 < (uint)((int)puVar3 - (int)param_2)) {
    do {
      strncpy(local_38,(char *)param_2,0x32);
      local_6 = 0;
      puVar3 = (uint *)((int)param_2 + 0x32);
      uVar5 = (uint)puVar3 & 3;
      puVar1 = puVar3;
      if (uVar5 == 0) {
LAB_000bacea:
        do {
          puVar4 = puVar1;
          uVar5 = *puVar4;
          if ((char)uVar5 == '\0') goto LAB_000bad0c;
          if ((char)(uVar5 >> 8) == '\0') goto LAB_000bad0b;
          if ((uVar5 & 0xff0000) == 0) goto LAB_000bad0a;
          puVar1 = puVar4 + 1;
        } while ((uVar5 & 0xff000000) != 0);
        puVar4 = (uint *)((int)puVar4 + 1);
LAB_000bad0a:
        puVar4 = (uint *)((int)puVar4 + 1);
LAB_000bad0b:
        puVar4 = (uint *)((int)puVar4 + 1);
      }
      else {
        puVar4 = puVar3;
        if ((POPCOUNT(uVar5) & 1U) == 0) {
LAB_000bace5:
          if ((char)*puVar4 != '\0') {
            puVar1 = (uint *)((int)puVar4 + 1);
            goto LAB_000bacea;
          }
        }
        else if (uVar5 == 2) {
LAB_000bace0:
          if ((char)*puVar4 != '\0') {
            puVar4 = (uint *)((int)puVar4 + 1);
            goto LAB_000bace5;
          }
        }
        else if (*(char *)puVar3 != '\0') {
          puVar4 = (uint *)((int)param_2 + 0x33);
          goto LAB_000bace0;
        }
      }
LAB_000bad0c:
      param_2 = puVar3;
    } while (0x31 < (uint)((int)puVar4 - (int)puVar3));
  }
  return;
}


