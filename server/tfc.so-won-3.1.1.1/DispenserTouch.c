// DispenserTouch__12CTFDispenserP11CBaseEntity  @ 0009bdec
void DispenserTouch__12CTFDispenserP11CBaseEntity(int param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  
  if ((*(byte *)(*param_2 + 0x1a4) & 8) != 0) {
    if ((param_2[0x48] != 0) && (param_2[0x48] != *(int *)(param_1 + 0x120))) {
      puVar3 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x144,4,"#Dispenser_used",0,0,0,0);
      ClientPrint__FP9entvars_siPCcN42(*puVar3);
    }
    fVar1 = *gpGlobals;
    fVar2 = *(float *)(param_1 + 0x6a0);
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
      iVar4 = FindTimer__11CBaseEntityi(param_1,0xe);
      if (iVar4 == 0) {
        piVar5 = (int *)GetClassPtr__H1Z23CDispenserRefillThinker_PX01_PX01(0);
        *(float *)(*piVar5 + 0x104) = *gpGlobals + 0.2;
        __as__7EHANDLEP11CBaseEntity(piVar5 + 0x116,param_1);
        __as__7EHANDLEP11CBaseEntity(piVar5 + 0x118,param_2);
        iVar4 = *param_2;
        piVar5[0x11a] = *(int *)(iVar4 + 8);
        piVar5[0x11b] = *(int *)(iVar4 + 0xc);
        piVar5[0x11c] = *(int *)(iVar4 + 0x10);
      }
      *(float *)(param_1 + 0x6a0) = *gpGlobals + 1.0;
    }
  }
  return;
}


