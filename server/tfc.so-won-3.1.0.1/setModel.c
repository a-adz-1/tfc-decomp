// setModel__10CTFBomblet  @ 000f03c4
void setModel__10CTFBomblet(int *param_1)

{
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/bomblet.mdl");
  return;
}


// setModel__10CTFCaltrop  @ 000f1170
void setModel__10CTFCaltrop(int *param_1)

{
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/caltrop.mdl");
  return;
}


// setModel__10CTFGrenade  @ 000f46b4
void setModel__10CTFGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0xf5] + 0x21c))(param_1);
  if (iVar1 == 0) {
    (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/pipebomb.mdl");
    *(undefined4 *)(*param_1 + 0x110) = 1;
  }
  return;
}


// setModel__13CTFEMPGrenade  @ 000f1be4
void setModel__13CTFEMPGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0xf5] + 0x21c))(param_1);
  if (iVar1 == 0) {
    (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/emp_grenade.mdl");
  }
  return;
}


// setModel__13CTFGasGrenade  @ 000f2060
void setModel__13CTFGasGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0xf5] + 0x21c))(param_1);
  if (iVar1 == 0) {
    (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/spy_grenade.mdl");
  }
  return;
}


// setModel__14CTFMirvGrenade  @ 000eff0c
void setModel__14CTFMirvGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0xf5] + 0x21c))(param_1);
  if (iVar1 == 0) {
    (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/mirv_grenade.mdl");
  }
  return;
}


// setModel__14CTFNailGrenade  @ 000f03f8
void setModel__14CTFNailGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0xf5] + 0x21c))(param_1);
  if (iVar1 == 0) {
    (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/ngrenade.mdl");
  }
  return;
}


// setModel__16CTFNapalmGrenade  @ 000f19fc
void setModel__16CTFNapalmGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0xf5] + 0x21c))(param_1);
  if (iVar1 == 0) {
    (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/napalm.mdl");
  }
  return;
}


// setModel__17CTFCaltropGrenade  @ 000f0e98
void setModel__17CTFCaltropGrenade(undefined4 param_1)

{
  setModel__8CGrenade(param_1);
  return;
}


// setModel__20CTFConcussionGrenade  @ 000efec0
void setModel__20CTFConcussionGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0xf5] + 0x21c))(param_1);
  if (iVar1 == 0) {
    (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/conc_grenade.mdl");
  }
  return;
}


// setModel__8CGrenade  @ 000f3fa8
void setModel__8CGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0xf5] + 0x21c))(param_1);
  if (iVar1 == 0) {
    (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/w_grenade.mdl");
  }
  return;
}


