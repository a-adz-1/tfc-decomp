// MenuPrint__FP11CBasePlayerPCcii  @ 000be2c0
void MenuPrint__FP11CBasePlayerPCcii(int *param_1,char *param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char local_38 [50];
  undefined1 local_6;
  
  if (((*gpGlobals < (float)param_1[0x2e4]) && (param_3 == param_1[0x2e3])) &&
     (iVar2 = strcmp(param_2,(char *)(param_1 + 0x263)), iVar2 == 0)) {
    return;
  }
  param_1[0x2e4] = (int)(*gpGlobals + 10.0);
  strncpy((char *)(param_1 + 0x263),param_2,0x200);
  param_1[0x2e3] = param_3;
  uVar3 = 0xffffffff;
  pcVar4 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (0x31 < ~uVar3 - 1) {
    do {
      strncpy(local_38,param_2,0x32);
      local_6 = 0;
      param_2 = param_2 + 0x32;
      (*DAT_00175578)(1,gmsgShowMenu,0,*(undefined4 *)(*param_1 + 0x1e8));
      (*DAT_00175588)(param_3);
      (*DAT_00175584)(param_4);
      (*DAT_00175580)(1);
      (*DAT_00175598)(local_38);
      (*DAT_0017557c)();
      uVar3 = 0xffffffff;
      pcVar4 = param_2;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
    } while (0x31 < ~uVar3 - 1);
  }
  (*DAT_00175578)(1,gmsgShowMenu,0,*(undefined4 *)(*param_1 + 0x1e8));
  (*DAT_00175588)(param_3);
  (*DAT_00175584)(param_4);
  (*DAT_00175580)(0);
  (*DAT_00175598)(param_2);
  (*DAT_0017557c)();
  return;
}


