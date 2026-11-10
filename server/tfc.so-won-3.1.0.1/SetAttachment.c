// SetAttachment__7CSpriteP7edict_si  @ 0009bc90
void SetAttachment__7CSpriteP7edict_si(int *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = (*DAT_001a7f5c)(param_2);
    *(undefined4 *)(*param_1 + 0x110) = uVar1;
    *(undefined4 *)(*param_1 + 0x114) = param_3;
    *(int *)(*param_1 + 0x194) = param_2;
    *(undefined4 *)(*param_1 + 0x108) = 0xc;
  }
  return;
}


