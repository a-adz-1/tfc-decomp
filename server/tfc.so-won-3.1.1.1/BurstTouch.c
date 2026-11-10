// BurstTouch__20CTFFlamethrowerBurstP11CBaseEntity  @ 001049dc
void BurstTouch__20CTFFlamethrowerBurstP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = *(int *)(*param_1 + 0x198);
  if (iVar2 != 0) {
    iVar3 = iVar2 + 0x80;
  }
  if ((param_2 != (int *)0x0) &&
     (fVar1 = *(float *)(*param_2 + 0x16c),
     (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
    (**(code **)(param_2[0x115] + 0x38))(param_2,*param_1,iVar3,0x41700000,0x1000008);
  }
  SUB_Remove__11CBaseEntity(param_1);
  return;
}


