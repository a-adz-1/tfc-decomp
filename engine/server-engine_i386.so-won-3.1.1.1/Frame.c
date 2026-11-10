// Frame__7CEngine  @ 00099bd0
int Frame__7CEngine(int *param_1)

{
  double dVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  longdouble lVar5;
  undefined1 local_8 [4];
  
  cVar2 = (**(code **)(*(int *)game + 0x30))(game);
  if (cVar2 == '\0') {
    if (param_1[2] == 2) {
      uVar4 = 0x32;
    }
    else {
      uVar4 = 0x14;
    }
    (**(code **)(*(int *)game + 0x18))(game,uVar4);
  }
  lVar5 = (longdouble)Sys_FloatTime();
  *(double *)(param_1 + 4) = (double)lVar5;
  *(double *)(param_1 + 6) = *(double *)(param_1 + 4) - *(double *)(param_1 + 8);
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_1 + 4);
  dVar1 = *(double *)(param_1 + 6);
  if ((byte)(dVar1 < 0.0 | (byte)((ushort)((ushort)NAN(dVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(dVar1 == 0.0) << 0xe) >> 8)) == 1) {
    param_1[6] = 0x40000000;
    param_1[7] = 0x3f847ae1;
  }
  if ((param_1[2] != 0) &&
     (iVar3 = Host_Frame((float)*(double *)(param_1 + 6),param_1[2],local_8), iVar3 != param_1[2]))
  {
    (**(code **)(*param_1 + 0x14))(param_1,iVar3);
    switch(param_1[2]) {
    case 0:
    case 2:
      break;
    case 3:
      (**(code **)(*param_1 + 0x48))(param_1,1);
      break;
    case 5:
      (**(code **)(*param_1 + 0x48))(param_1,2);
    }
  }
  return param_1[2];
}


