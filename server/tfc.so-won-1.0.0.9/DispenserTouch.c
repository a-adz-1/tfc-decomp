// DispenserTouch__12CTFDispenserP11CBaseEntity  @ 000a8b20
void DispenserTouch__12CTFDispenserP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  
  if ((*(byte *)(*param_2 + 0x184) & 8) != 0) {
    if ((param_2[0x48] != 0) && (param_2[0x48] != param_1[0x48])) {
      puVar3 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x51,4,"#Dispenser_used",0,0,0,0);
      ClientPrint__FP9entvars_tiPCcN42(*puVar3);
    }
    iVar4 = __opP11CBaseEntity__7EHANDLE(param_2 + 0x4e);
    if (iVar4 == 0) {
      fVar1 = (float)param_2[0x50];
      fVar2 = *gpGlobals;
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
        param_2[0x45] = 0x41980000;
        __as__7EHANDLEP11CBaseEntity(param_2 + 0x4e,param_1);
        piVar5 = (int *)CreateTimer__11CBaseEntityi(param_2,0xc);
        *(undefined4 *)(*piVar5 + 0x170) = *(undefined4 *)(*param_1 + 0x1e8);
        piVar5[3] = -0x10000;
        piVar5[4] = (int)Timer_CheckBuildDistance__11CBaseEntity;
        *(float *)(*piVar5 + 0xe4) = *gpGlobals + 0.3;
      }
    }
  }
  return;
}


