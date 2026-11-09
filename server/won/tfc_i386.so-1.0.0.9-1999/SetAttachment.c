// SetAttachment__7CSpriteP7edict_si  @ 000b0bf0
void SetAttachment__7CSpriteP7edict_si(int *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = (*DAT_001755dc)(param_2);
    *(undefined4 *)(*param_1 + 0xf0) = uVar1;
    *(undefined4 *)(*param_1 + 0xf4) = param_3;
    *(int *)(*param_1 + 0x174) = param_2;
    *(undefined4 *)(*param_1 + 0xe8) = 0xc;
  }
  return;
}


