// setModel__10CTFBomblet  @ 001014ac
void setModel__10CTFBomblet(int *param_1)

{
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/bomblet.mdl");
  return;
}


// setModel__10CTFCaltrop  @ 00101210
void setModel__10CTFCaltrop(int *param_1)

{
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/caltrop.mdl");
  return;
}


// setModel__10CTFGrenade  @ 001045f0
void setModel__10CTFGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0x115] + 0x224))(param_1);
  if (iVar1 == 0) {
    (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/pipebomb.mdl");
    *(undefined4 *)(*param_1 + 0x110) = 1;
  }
  return;
}


// setModel__13CTFEMPGrenade  @ 00100f40
void setModel__13CTFEMPGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0x115] + 0x224))(param_1);
  if (iVar1 == 0) {
    (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/emp_grenade.mdl");
  }
  return;
}


// setModel__13CTFGasGrenade  @ 00100de8
void setModel__13CTFGasGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0x115] + 0x224))(param_1);
  if (iVar1 == 0) {
    (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/spy_grenade.mdl");
  }
  return;
}


// setModel__14CTFMirvGrenade  @ 001016c0
void setModel__14CTFMirvGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0x115] + 0x224))(param_1);
  if (iVar1 == 0) {
    (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/mirv_grenade.mdl");
  }
  return;
}


// setModel__14CTFNailGrenade  @ 0010145c
void setModel__14CTFNailGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0x115] + 0x224))(param_1);
  if (iVar1 == 0) {
    (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/ngrenade.mdl");
  }
  return;
}


// setModel__16CTFNapalmGrenade  @ 00101068
void setModel__16CTFNapalmGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0x115] + 0x224))(param_1);
  if (iVar1 == 0) {
    (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/napalm.mdl");
  }
  return;
}


// setModel__17CTFCaltropGrenade  @ 00101248
void setModel__17CTFCaltropGrenade(undefined4 param_1)

{
  setModel__8CGrenade(param_1);
  return;
}


// setModel__20CTFConcussionGrenade  @ 00101710
void setModel__20CTFConcussionGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0x115] + 0x224))(param_1);
  if (iVar1 == 0) {
    (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/conc_grenade.mdl");
  }
  return;
}


// setModel__8CGrenade  @ 0010464c
void setModel__8CGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0x115] + 0x224))(param_1);
  if (iVar1 == 0) {
    (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/w_grenade.mdl");
  }
  return;
}


