// CantChange__11CBasePlayerii  @ 000df91c
undefined4 CantChange__11CBasePlayerii(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = IsLegalClass__11CBasePlayeri(param_1,param_2);
  if ((iVar1 == 0) && (param_2 != 0xb)) {
    if (param_3 != 0) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Game_cantplayclass",0,0,0,0);
    }
    TeamFortress_DisplayLegalClasses__11CBasePlayer(param_1);
    return 1;
  }
  if (((byte)((byte)((ushort)((ushort)NAN(spy_off) << 10) >> 8) |
             (byte)((ushort)((ushort)(spy_off == 1.0) << 0xe) >> 8)) == 0x40) && (param_2 == 8)) {
    if (param_3 == 0) {
      return 1;
    }
    pcVar2 = "#Game_spydisabled";
  }
  else {
    iVar1 = ClassIsRestricted__Ffi((float)(int)param_1[0x48],param_2);
    if (iVar1 == 0) {
      return 0;
    }
    if (param_3 == 0) {
      return 1;
    }
    pcVar2 = "#Game_enoughofclass";
  }
  ClientPrint__FP9entvars_siPCcN42(*param_1,1,pcVar2,0,0,0,0);
  return 1;
}


