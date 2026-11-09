// TranqTouch__14CTFNailgunNailP11CBaseEntity  @ 001041f0
void TranqTouch__14CTFNailgunNailP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined2 in_FPUControlWord;
  undefined1 local_48 [20];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_18;
  undefined4 local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  fVar1 = *(float *)(*param_2 + 0x14c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    if ((*(int *)(*param_2 + 0xec) == 4) || (*(int *)(*param_2 + 0xe8) == 0xd)) {
      iVar2 = *param_1;
      local_34 = *(undefined4 *)(iVar2 + 8);
      local_30 = *(undefined4 *)(iVar2 + 0xc);
      local_2c = *(undefined4 *)(iVar2 + 0x10);
      local_18 = *(undefined4 *)(*param_2 + 0x1e8);
      uVar4 = (*DAT_00175628)(0,4);
      UTIL_GunshotDecalTrace__FP11TraceResulti(local_48,uVar4);
    }
    goto LAB_001043ab;
  }
  iVar2 = *(int *)(*param_1 + 0x178);
  if (iVar2 == 0) {
    iVar2 = (*DAT_001755d4)(0);
    if (iVar2 != 0) goto LAB_00104237;
    puVar5 = (undefined4 *)0x0;
  }
  else {
LAB_00104237:
    puVar5 = *(undefined4 **)(iVar2 + 0xd8);
  }
  iVar2 = (**(code **)(param_2[0xf2] + 0x28))(param_2);
  if (iVar2 == 2) {
    iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(puVar5,param_2);
    if (iVar2 != 0) {
      _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
      local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      if (((int)ROUND(gpGlobals[7]) & 0x1eU) != 0) goto LAB_00104338;
    }
    if ((short)param_2[0x22] < 0) {
      piVar3 = (int *)FindTimer__11CBaseEntityi(param_2,4);
      if (piVar3 != (int *)0x0) {
        *(float *)(*piVar3 + 0xe4) = *gpGlobals + 15.0;
      }
    }
    else {
      ClientPrint__FP9entvars_tiPCcN42(*param_2,1,"#Spy_tranq",0,0,0,0);
      *(byte *)((int)param_2 + 0x89) = *(byte *)((int)param_2 + 0x89) | 0x80;
      piVar3 = (int *)CreateTimer__11CBaseEntityi(param_2,4);
      *(float *)(*piVar3 + 0xe4) = *gpGlobals + 15.0;
      piVar3[3] = -0x10000;
      piVar3[4] = (int)Timer_Tranquilisation__11CBaseEntity;
      piVar3[0x48] = puVar5[0x48];
      TeamFortress_SetSpeed__11CBasePlayer(param_2);
    }
  }
LAB_00104338:
  (**(code **)(param_2[0xf2] + 0x34))(param_2,*param_1,*puVar5,0x41a00000,0x800004);
LAB_001043ab:
  SUB_Remove__11CBaseEntity(param_1);
  return;
}


