// ClientKill__FP7edict_s  @ 0008f35c
void ClientKill__FP7edict_s(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar3 = *(int *)(param_1 + 0x288);
  if ((iVar3 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(iVar3 + 0x7c);
  }
  if (*(int *)(param_1 + 0x28c) != 0) {
    fVar1 = *gpGlobals;
    fVar2 = *(float *)(iVar3 + 0x710);
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
      *(float *)(iVar3 + 0x710) = fVar1 + 5.0;
      *(undefined4 *)(param_1 + 0x1e0) = 0;
      if (((*(byte *)(iVar3 + 0x84) & 0x10) != 0) &&
         (piVar4 = (int *)FindTimer__11CBaseEntityi(iVar3,2), piVar4 != (int *)0x0)) {
        iVar5 = *(int *)(*piVar4 + 400);
        if ((iVar5 == 0) && (iVar5 = (*DAT_0019f7b4)(0), iVar5 == 0)) {
          uVar6 = 0;
        }
        else {
          uVar6 = *(undefined4 *)(iVar5 + 0x7c);
        }
        TF_AddFrags__11CBasePlayeri(uVar6,1);
      }
      (**(code **)(*(int *)(iVar3 + 0x454) + 0x40))(iVar3,0,param_1 + 0x80,1);
    }
  }
  return;
}


