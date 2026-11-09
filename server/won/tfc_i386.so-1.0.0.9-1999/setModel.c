// setModel__10CTFBomblet  @ 000fd210
void setModel__10CTFBomblet(int *param_1)

{
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/bomblet.mdl");
  return;
}


// setModel__10CTFCaltrop  @ 000fdc50
void setModel__10CTFCaltrop(int *param_1)

{
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/caltrop.mdl");
  return;
}


// setModel__10CTFGrenade  @ 000fb420
void setModel__10CTFGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0xf2] + 0x21c))(param_1);
  if (iVar1 == 0) {
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/pipebomb.mdl");
    *(undefined4 *)(*param_1 + 0xf0) = 1;
  }
  return;
}


// setModel__13CTFEMPGrenade  @ 000fe790
void setModel__13CTFEMPGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0xf2] + 0x21c))(param_1);
  if (iVar1 == 0) {
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/emp_grenade.mdl");
  }
  return;
}


// setModel__13CTFGasGrenade  @ 000febb0
void setModel__13CTFGasGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0xf2] + 0x21c))(param_1);
  if (iVar1 == 0) {
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/spy_grenade.mdl");
  }
  return;
}


// setModel__14CTFMirvGrenade  @ 000fcf20
void setModel__14CTFMirvGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0xf2] + 0x21c))(param_1);
  if (iVar1 == 0) {
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/mirv_grenade.mdl");
  }
  return;
}


// setModel__14CTFNailGrenade  @ 000fd230
void setModel__14CTFNailGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0xf2] + 0x21c))(param_1);
  if (iVar1 == 0) {
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/ngrenade.mdl");
  }
  return;
}


// setModel__16CTFNapalmGrenade  @ 000fe500
void setModel__16CTFNapalmGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0xf2] + 0x21c))(param_1);
  if (iVar1 == 0) {
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/napalm.mdl");
  }
  return;
}


// setModel__17CTFCaltropGrenade  @ 000fda40
void setModel__17CTFCaltropGrenade(undefined4 param_1)

{
  setModel__8CGrenade(param_1);
  return;
}


// setModel__20CTFConcussionGrenade  @ 000fcee0
void setModel__20CTFConcussionGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0xf2] + 0x21c))(param_1);
  if (iVar1 == 0) {
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/conc_grenade.mdl");
  }
  return;
}


// setModel__8CGrenade  @ 000fae80
void setModel__8CGrenade(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[0xf2] + 0x21c))(param_1);
  if (iVar1 == 0) {
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/w_grenade.mdl");
  }
  return;
}


