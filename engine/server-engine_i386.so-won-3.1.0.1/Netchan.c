// Netchan_AddBufferToList  @ 0006926c
void Netchan_AddBufferToList(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *param_2 = 0;
  if (param_1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*param_1;
    if (puVar2 == (undefined4 *)0x0) {
      *param_2 = 0;
      *param_1 = param_2;
    }
    else {
      if ((undefined4 *)*puVar2 != (undefined4 *)0x0) {
        puVar3 = (undefined4 *)*puVar2;
        do {
          if (*(ushort *)((int)param_2 + 6) < *(ushort *)((int)puVar3 + 6)) {
            *param_2 = *puVar3;
            break;
          }
          puVar1 = (undefined4 *)*puVar3;
          puVar2 = puVar3;
          puVar3 = puVar1;
        } while (puVar1 != (undefined4 *)0x0);
      }
      *puVar2 = param_2;
    }
  }
  return;
}


// Netchan_AddFragbufToTail  @ 00069310
void Netchan_AddFragbufToTail(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  *param_2 = 0;
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  puVar1 = *(undefined4 **)(param_1 + 8);
  if (*(undefined4 **)(param_1 + 8) == (undefined4 *)0x0) {
    *(undefined4 **)(param_1 + 8) = param_2;
  }
  else {
    do {
      puVar2 = puVar1;
      puVar1 = (undefined4 *)*puVar2;
    } while (puVar1 != (undefined4 *)0x0);
    *puVar2 = param_2;
  }
  return;
}


// Netchan_AllocFragbuf  @ 000692cc
void Netchan_AllocFragbuf(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)Mem_ZeroMalloc(0x6a4);
  puVar1[1] = 0;
  puVar1[5] = 0;
  puVar1[3] = puVar1 + 6;
  puVar1[4] = 0x578;
  *puVar1 = 0;
  return;
}


// Netchan_CanPacket  @ 00067e88
undefined4 Netchan_CanPacket(int param_1)

{
  undefined4 uVar1;
  
  if (((byte)((byte)((ushort)((ushort)NAN((float)net_chokeloopback._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)net_chokeloopback._12_4_ == 0.0) << 0xe) >> 8)) == 0x40
      ) && (*(int *)(param_1 + 4) == 1)) {
    uVar1 = 1;
    *(double *)(param_1 + 0x28) = realtime;
  }
  else if (*(double *)(param_1 + 0x28) < realtime) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// Netchan_CheckForCompletion  @ 00068b94
void Netchan_CheckForCompletion(undefined *param_1,int param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  piVar1 = *(int **)(param_1 + param_2 * 4 + 0x1ff0);
  if (piVar1 != (int *)0x0) {
    do {
      uVar2 = uVar2 + 1;
      if ((*(ushort *)((int)piVar1 + 6) != uVar2) && (param_1 == &DAT_00382504)) {
        Con_Printf(
                  "Netchan_CheckForCompletion:  Lost/dropped fragment would cause stall, retrying connection\n"
                  );
        Cbuf_AddText("retry\n");
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
    if (uVar2 == param_3) {
      *(undefined4 *)(param_1 + param_2 * 4 + 0x1ff8) = 1;
    }
  }
  return;
}


// Netchan_Clear  @ 00067d1c
void Netchan_Clear(int param_1)

{
  Netchan_ClearFragments(param_1);
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x1010) = 0;
  *(undefined4 *)(param_1 + 0x1fd0) = 0;
  *(undefined4 *)(param_1 + 0x1fc8) = 0;
  *(undefined4 *)(param_1 + 0x1fe0) = 0;
  *(undefined2 *)(param_1 + 0x1fe8) = 0;
  *(undefined2 *)(param_1 + 0x1fec) = 0;
  *(undefined4 *)(param_1 + 0x1ff8) = 0;
  *(undefined4 *)(param_1 + 0x1fd4) = 0;
  *(undefined4 *)(param_1 + 0x1fcc) = 0;
  *(undefined4 *)(param_1 + 0x1fe4) = 0;
  *(undefined2 *)(param_1 + 0x1fea) = 0;
  *(undefined2 *)(param_1 + 0x1fee) = 0;
  *(undefined4 *)(param_1 + 0x1ffc) = 0;
  if (*(int *)(param_1 + 0x2104) != 0) {
    Mem_Free(*(int *)(param_1 + 0x2104));
    *(undefined4 *)(param_1 + 0x2104) = 0;
  }
  return;
}


// Netchan_ClearFragbufs  @ 00067c08
void Netchan_ClearFragbufs(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*param_1;
    while (puVar2 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*puVar2;
      Mem_Free(puVar2);
      puVar2 = puVar1;
    }
    *param_1 = 0;
  }
  return;
}


// Netchan_ClearFragments  @ 00067c4c
void Netchan_ClearFragments(int param_1)

{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(param_1 + 0x1fc0); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    Netchan_ClearFragbufs(puVar1 + 2);
  }
  *(undefined4 *)(param_1 + 0x1fc0) = 0;
  Netchan_ClearFragbufs(param_1 + 0x1fd8);
  Netchan_FlushIncoming(param_1,0);
  for (puVar1 = *(undefined4 **)(param_1 + 0x1fc4); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    Netchan_ClearFragbufs(puVar1 + 2);
  }
  *(undefined4 *)(param_1 + 0x1fc4) = 0;
  Netchan_ClearFragbufs(param_1 + 0x1fdc);
  Netchan_FlushIncoming(param_1,1);
  return;
}


// Netchan_CopyFileFragments  @ 000698fc
undefined4 Netchan_CopyFileFragments(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int **ppiVar6;
  int *piVar7;
  int *piStack_138;
  int *piStack_134;
  int local_124;
  int local_114;
  undefined4 local_110;
  undefined4 local_10c;
  char local_108 [260];
  
  if (*(int *)(param_1 + 0x1ffc) == 0) {
    return 0;
  }
  piVar5 = *(int **)(param_1 + 0x1ff4);
  if (piVar5 == (int *)0x0) {
    piStack_134 = (int *)0xa8f60;
    piStack_138 = (int *)0x69941;
    Con_Printf();
    uVar3 = 0;
LAB_00069bff:
    *(undefined4 *)(param_1 + 0x1ffc) = 0;
  }
  else {
    piStack_134 = (int *)&net_message;
    piStack_138 = (int *)0x6995a;
    SZ_Clear();
    piStack_138 = (int *)0x6995f;
    MSG_BeginReading();
    piStack_138 = (int *)piVar5[5];
    SZ_Write(&net_message,piVar5[3]);
    uVar3 = MSG_ReadString();
    Q_strcpy(local_108,uVar3);
    iVar4 = Q_strlen(local_108);
    if (iVar4 < 1) {
      piStack_134 = (int *)0xa8fa0;
      ppiVar6 = &piStack_134;
      piStack_138 = (int *)0x699aa;
      Con_Printf();
    }
    else {
      piStack_134 = (int *)&DAT_000a8fde;
      piStack_138 = (int *)local_108;
      iVar4 = Q_strstr();
      if (iVar4 == 0) {
        piStack_138 = (int *)(param_1 + 0x2000);
        piStack_134 = (int *)local_108;
        Q_strcpy();
        if (local_108[0] != '!') {
          piStack_134 = &local_114;
          piStack_138 = (int *)local_108;
          iVar4 = COM_OpenFile();
          if (iVar4 != -1) {
            piStack_138 = (int *)0xa9040;
            piStack_134 = (int *)local_108;
            Con_Printf();
            Netchan_FlushIncoming(param_1,1);
            COM_CloseFile(local_114,local_110,local_10c);
            return 1;
          }
          piStack_138 = (int *)0x69a6c;
          piStack_134 = (int *)local_108;
          COM_CreatePath();
        }
        local_124 = 0;
        if (piVar5 != (int *)0x0) {
          do {
            local_124 = local_124 + piVar5[5];
            if (piVar5 == *(int **)(param_1 + 0x1ff4)) {
              local_124 = local_124 - msg_readcount;
            }
            piVar5 = (int *)*piVar5;
          } while (piVar5 != (int *)0x0);
        }
        piVar7 = (int *)(local_124 + 1);
        piStack_138 = (int *)0x69ab6;
        piStack_134 = piVar7;
        piVar5 = (int *)Mem_ZeroMalloc();
        if (piVar5 != (int *)0x0) {
          piStack_138 = (int *)0x0;
          piStack_134 = piVar7;
          Q_memset(piVar5);
          piVar7 = (int *)0x0;
          piVar2 = *(int **)(param_1 + 0x1ff4);
          while (piVar2 != (int *)0x0) {
            piVar1 = (int *)*piVar2;
            if (piVar2 == *(int **)(param_1 + 0x1ff4)) {
              piStack_134 = (int *)(piVar2[5] - msg_readcount);
              piVar2[5] = (int)piStack_134;
              piStack_138 = (int *)(msg_readcount + piVar2[3]);
            }
            else {
              piStack_134 = (int *)piVar2[5];
              piStack_138 = (int *)piVar2[3];
            }
            Q_memcpy((int)piVar5 + (int)piVar7);
            piVar7 = (int *)((int)piVar7 + piVar2[5]);
            piStack_138 = (int *)0x69b5e;
            piStack_134 = piVar2;
            Mem_Free();
            piVar2 = piVar1;
          }
          if (local_108[0] == '!') {
            if (*(int *)(param_1 + 0x2104) != 0) {
              piStack_134 = (int *)0xa90c0;
              piStack_138 = (int *)0x69bb4;
              Con_Printf();
              piStack_138 = *(int **)(param_1 + 0x2104);
              Mem_Free();
            }
            *(int **)(param_1 + 0x2104) = piVar5;
          }
          else {
            piStack_138 = piVar5;
            piStack_134 = piVar7;
            COM_WriteFile(local_108);
            Mem_Free(piVar5);
          }
          piStack_134 = (int *)&net_message;
          piStack_138 = (int *)0x69be1;
          SZ_Clear();
          msg_readcount = 0;
          uVar3 = 1;
          *(undefined4 *)(param_1 + 0x1ff4) = 0;
          goto LAB_00069bff;
        }
        piStack_138 = (int *)0xa9080;
        ppiVar6 = &piStack_138;
        piStack_134 = piVar7;
        Con_Printf();
      }
      else {
        piStack_134 = (int *)0xa9000;
        ppiVar6 = &piStack_134;
        piStack_138 = (int *)0x699d6;
        Con_Printf();
      }
    }
    *(undefined4 *)((int)ppiVar6 + -4) = 1;
    *(int *)((int)ppiVar6 + -8) = param_1;
    *(undefined4 *)((int)ppiVar6 + -0xc) = 0x69adb;
    Netchan_FlushIncoming();
    uVar3 = 0;
  }
  return uVar3;
}


// Netchan_CopyNormalFragments  @ 00069844
undefined4 Netchan_CopyNormalFragments(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (*(int *)(param_1 + 0x1ff8) == 0) {
    uVar2 = 0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x1ff0);
    if (piVar3 == (int *)0x0) {
      Con_Printf("Netchan_CopyNormalFragments:  Called with no fragments readied\n");
      uVar2 = 0;
      *(undefined4 *)(param_1 + 0x1ff8) = 0;
    }
    else {
      SZ_Clear(&net_message);
      MSG_BeginReading();
      do {
        piVar1 = (int *)*piVar3;
        SZ_Write(&net_message,piVar3[3],piVar3[5]);
        Mem_Free(piVar3);
        piVar3 = piVar1;
      } while (piVar1 != (int *)0x0);
      *(undefined4 *)(param_1 + 0x1ff0) = 0;
      *(undefined4 *)(param_1 + 0x1ff8) = 0;
      uVar2 = 1;
    }
  }
  return uVar2;
}


// Netchan_CreateFileFragments  @ 00069628
undefined4 Netchan_CreateFileFragments(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int local_20;
  int local_1c;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_20 = 1;
  bVar2 = true;
  iVar3 = (**(code **)(param_2 + 0x50))(*(undefined4 *)(param_2 + 0x4c));
  iVar4 = COM_OpenFile(param_3,&local_10);
  if (iVar4 == -1) {
    Con_Printf("Warning:  Unable to open %s for transfer\n",param_3);
LAB_00069681:
    uVar5 = 0;
  }
  else {
    COM_CloseFile(local_10,local_c,local_8);
    iVar6 = Mem_ZeroMalloc(0xc);
    local_1c = 0;
    for (; 0 < iVar4; iVar4 = iVar4 - iVar9) {
      iVar9 = iVar3;
      if (iVar4 < iVar3) {
        iVar9 = iVar4;
      }
      iVar7 = Netchan_AllocFragbuf();
      if (iVar7 == 0) {
        Con_Printf("Couldn\'t allocate fragbuf_t\n");
        Mem_Free(iVar6);
        if (param_1 == 0) {
          CL_Disconnect_f();
        }
        else {
          SV_DropClient(host_client,0);
        }
        goto LAB_00069681;
      }
      *(int *)(iVar7 + 4) = local_20;
      local_20 = local_20 + 1;
      SZ_Clear(iVar7 + 8);
      if (bVar2) {
        bVar2 = false;
        MSG_WriteString(iVar7 + 8,param_3);
        iVar9 = iVar9 - *(int *)(iVar7 + 0x14);
      }
      *(undefined4 *)(iVar7 + 0x590) = 1;
      *(int *)(iVar7 + 0x6a0) = iVar9;
      *(int *)(iVar7 + 0x69c) = local_1c;
      Q_strcpy(iVar7 + 0x598,param_3);
      local_1c = local_1c + iVar9;
      Netchan_AddFragbufToTail(iVar6,iVar7);
    }
    piVar1 = *(int **)(param_2 + 0x1fc4);
    if (*(int **)(param_2 + 0x1fc4) == (int *)0x0) {
      *(int *)(param_2 + 0x1fc4) = iVar6;
    }
    else {
      do {
        piVar8 = piVar1;
        piVar1 = (int *)*piVar8;
      } while (piVar1 != (int *)0x0);
      *piVar8 = iVar6;
    }
    uVar5 = 1;
  }
  return uVar5;
}


// Netchan_CreateFileFragmentsFromBuffer  @ 000694b8
void Netchan_CreateFileFragmentsFromBuffer
               (int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int local_14;
  int local_10;
  
  local_14 = 1;
  bVar3 = true;
  if (param_5 != 0) {
    iVar4 = (**(code **)(param_2 + 0x50))(*(undefined4 *)(param_2 + 0x4c));
    iVar5 = Mem_ZeroMalloc(0xc);
    local_10 = 0;
    for (; 0 < param_5; param_5 = param_5 - iVar8) {
      iVar8 = iVar4;
      if (param_5 < iVar4) {
        iVar8 = param_5;
      }
      iVar6 = Netchan_AllocFragbuf();
      if (iVar6 == 0) {
        Con_Printf("Couldn\'t allocate fragbuf_t\n");
        Mem_Free(iVar5);
        if (param_1 == 0) {
          CL_Disconnect_f();
          return;
        }
        SV_DropClient(host_client,0);
        return;
      }
      *(int *)(iVar6 + 4) = local_14;
      local_14 = local_14 + 1;
      iVar1 = iVar6 + 8;
      SZ_Clear(iVar1);
      if (bVar3) {
        bVar3 = false;
        MSG_WriteString(iVar1,param_3);
        iVar8 = iVar8 - *(int *)(iVar6 + 0x14);
      }
      *(undefined4 *)(iVar6 + 0x594) = 1;
      *(undefined4 *)(iVar6 + 0x590) = 1;
      *(int *)(iVar6 + 0x6a0) = iVar8;
      *(int *)(iVar6 + 0x69c) = local_10;
      MSG_WriteBuf(iVar1,iVar8,param_4 + local_10);
      local_10 = local_10 + iVar8;
      Netchan_AddFragbufToTail(iVar5,iVar6);
    }
    piVar2 = *(int **)(param_2 + 0x1fc4);
    if (*(int **)(param_2 + 0x1fc4) == (int *)0x0) {
      *(int *)(param_2 + 0x1fc4) = iVar5;
    }
    else {
      do {
        piVar7 = piVar2;
        piVar2 = (int *)*piVar7;
      } while (piVar2 != (int *)0x0);
      *piVar7 = iVar5;
    }
  }
  return;
}


// Netchan_CreateFragments  @ 00069470
void Netchan_CreateFragments(undefined4 param_1,int param_2,undefined4 param_3)

{
  if (0 < *(int *)(param_2 + 0x60)) {
    Netchan_CreateFragments_(param_1,param_2,param_2 + 0x54);
    *(undefined4 *)(param_2 + 0x60) = 0;
  }
  Netchan_CreateFragments_(param_1,param_2,param_3);
  return;
}


// Netchan_CreateFragments_  @ 00069340
void Netchan_CreateFragments_(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int local_18;
  int local_14;
  int local_c;
  
  local_18 = 1;
  if (*(int *)(param_3 + 0xc) != 0) {
    iVar3 = (**(code **)(param_2 + 0x50))(*(undefined4 *)(param_2 + 0x4c));
    iVar4 = Mem_ZeroMalloc(0xc);
    local_14 = 0;
    iVar1 = *(int *)(param_3 + 0xc);
    while (0 < iVar1) {
      local_c = iVar3;
      if (iVar1 < iVar3) {
        local_c = iVar1;
      }
      iVar1 = iVar1 - local_c;
      iVar5 = Netchan_AllocFragbuf();
      if (iVar5 == 0) {
        Con_Printf("Couldn\'t allocate fragbuf_t\n");
        Mem_Free(iVar4);
        if (param_1 == 0) {
          CL_Disconnect_f();
          return;
        }
        SV_DropClient(host_client,0);
        return;
      }
      *(int *)(iVar5 + 4) = local_18;
      local_18 = local_18 + 1;
      SZ_Clear(iVar5 + 8);
      SZ_Write(iVar5 + 8,local_14 + *(int *)(param_3 + 4),local_c);
      local_14 = local_14 + local_c;
      Netchan_AddFragbufToTail(iVar4,iVar5);
    }
    piVar2 = *(int **)(param_2 + 0x1fc0);
    if (*(int **)(param_2 + 0x1fc0) == (int *)0x0) {
      *(int *)(param_2 + 0x1fc0) = iVar4;
    }
    else {
      do {
        piVar6 = piVar2;
        piVar2 = (int *)*piVar6;
      } while (piVar2 != (int *)0x0);
      *piVar6 = iVar4;
    }
  }
  return;
}


// Netchan_FindBufferById  @ 00068b24
undefined4 * Netchan_FindBufferById(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      if (param_3 == 0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = (undefined4 *)Mem_ZeroMalloc(0x6a4);
        puVar1[1] = param_2;
        puVar1[5] = 0;
        puVar1[3] = puVar1 + 6;
        puVar1[4] = 0x578;
        Netchan_AddBufferToList(param_1,puVar1);
      }
      return puVar1;
    }
    if (puVar1[1] == param_2) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1;
}


// Netchan_FlushIncoming  @ 000697c0
void Netchan_FlushIncoming(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  SZ_Clear(&net_message);
  param_2 = param_2 * 4;
  msg_readcount = 0;
  puVar2 = *(undefined4 **)(param_2 + param_1 + 0x1ff0);
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    Mem_Free(puVar2);
    puVar2 = puVar1;
  }
  *(undefined4 *)(param_2 + param_1 + 0x1ff0) = 0;
  *(undefined4 *)(param_2 + 0x1ff8 + param_1) = 0;
  return;
}


// Netchan_FragSend  @ 000691c4
void Netchan_FragSend(int param_1)

{
  undefined4 *puVar1;
  
  if (param_1 != 0) {
    if ((*(int *)(param_1 + 0x1fd8) == 0) &&
       (puVar1 = *(undefined4 **)(param_1 + 0x1fc0), puVar1 != (undefined4 *)0x0)) {
      *(undefined4 *)(param_1 + 0x1fc0) = *puVar1;
      *puVar1 = 0;
      *(undefined4 *)(param_1 + 0x1fd8) = puVar1[2];
      *(undefined4 *)(param_1 + 0x1fe0) = puVar1[1];
      Mem_Free(puVar1);
    }
    if ((*(int *)(param_1 + 0x1fdc) == 0) &&
       (puVar1 = *(undefined4 **)(param_1 + 0x1fc4), puVar1 != (undefined4 *)0x0)) {
      *(undefined4 *)(param_1 + 0x1fc4) = *puVar1;
      *puVar1 = 0;
      *(undefined4 *)(param_1 + 0x1fdc) = puVar1[2];
      *(undefined4 *)(param_1 + 0x1fe4) = puVar1[1];
      Mem_Free(puVar1);
    }
  }
  return;
}


// Netchan_IncomingReady  @ 00069c68
undefined4 Netchan_IncomingReady(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x1ff8) == 0) && (*(int *)(param_1 + 0x1ffc) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// Netchan_Init  @ 00069e7c
void Netchan_Init(void)

{
  Cvar_RegisterVariable(net_showpackets);
  Cvar_RegisterVariable(net_showdrop);
  Cvar_RegisterVariable(net_chokeloopback);
  Cvar_RegisterVariable(net_drawslider);
  return;
}


// Netchan_IsReceiving  @ 00069c40
undefined4 Netchan_IsReceiving(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x1ff0) == 0) && (*(int *)(param_1 + 0x1ff4) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// Netchan_IsSending  @ 00069c18
undefined4 Netchan_IsSending(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x1fd8) == 0) && (*(int *)(param_1 + 0x1fdc) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// Netchan_OutOfBand  @ 00067b20
void Netchan_OutOfBand(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 **ppuVar4;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000020;
  undefined2 *apuStack_ffc [4];
  undefined4 uStack_fec;
  undefined1 local_fdc [4040];
  undefined2 local_14 [2];
  undefined1 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = in_stack_0000001c;
  local_10 = local_fdc;
  local_c = 0xfc5;
  local_8 = 0;
  local_14[0] = 0;
  uStack_fec = 0xffffffff;
  apuStack_ffc[2] = (undefined2 *)0x67b63;
  apuStack_ffc[3] = local_14;
  MSG_WriteLong();
  apuStack_ffc[2] = (undefined2 *)uVar1;
  apuStack_ffc[1] = (undefined2 *)in_stack_00000020;
  apuStack_ffc[0] = local_14;
  SZ_Write();
  if (DAT_003855a4 == 0) {
    puVar3 = (undefined4 *)&stack0x00000008;
    ppuVar4 = apuStack_ffc;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppuVar4 = (undefined2 *)*puVar3;
      puVar3 = puVar3 + 1;
      ppuVar4 = ppuVar4 + 1;
    }
    NET_SendPacket(param_1,local_8,local_10);
  }
  return;
}


// Netchan_OutOfBandPrint  @ 00067bb0
void Netchan_OutOfBandPrint(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char *in_stack_0000001c;
  undefined4 auStack_38 [4];
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  
  puStack_20 = (undefined1 *)0x67bd6;
  vsprintf(string_6,in_stack_0000001c,&stack0x00000020);
  uStack_28 = 0x67bdd;
  puStack_24 = string_6;
  puStack_20 = string_6;
  iVar1 = Q_strlen();
  puStack_24 = (undefined1 *)(iVar1 + 1);
  puVar2 = (undefined4 *)&stack0x00000008;
  puVar3 = auStack_38;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  Netchan_OutOfBand(param_1);
  return;
}


// Netchan_Process  @ 00068c20
/* WARNING: Type propagation algorithm not settling */

undefined4 Netchan_Process(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  undefined1 *puVar6;
  uint *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  int *piVar10;
  undefined1 *puVar11;
  int aiStack_ac [2];
  char *pcStack_a4;
  int aiStack_a0 [3];
  char *pcStack_94;
  undefined4 *puStack_90;
  undefined8 local_8c;
  uint local_6c;
  undefined4 *local_60;
  uint local_34;
  uint local_30;
  int local_2c;
  uint local_28 [8];
  float local_8;
  
  local_8c = (double)CONCAT44(0x68c2e,(undefined4)local_8c);
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  if (DAT_003855a4 == 0) {
    piVar10 = aiStack_ac + 5;
    puVar8 = param_1;
    for (iVar4 = 5; puVar8 = puVar8 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar10 = *puVar8;
      piVar10 = piVar10 + 1;
    }
    puVar8 = &net_from;
    piVar10 = aiStack_ac;
    for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar10 = *puVar8;
      puVar8 = puVar8 + 1;
      piVar10 = piVar10 + 1;
    }
    iVar4 = NET_CompareAdr();
    if (iVar4 == 0) {
      return 0;
    }
  }
  local_8c = (double)CONCAT44(0x68cb7,(undefined4)local_8c);
  MSG_BeginReading();
  local_8c = (double)CONCAT44(0x68cbc,(undefined4)local_8c);
  uVar2 = MSG_ReadLong();
  local_8c = (double)CONCAT44(0x68cc4,(undefined4)local_8c);
  uVar3 = MSG_ReadLong();
  uVar9 = uVar2 >> 0x1e & 1;
  if (uVar9 != 0) {
    local_8c = (double)CONCAT44(0x68ced,(undefined4)local_8c);
    iVar4 = MSG_ReadByte();
    if (iVar4 != 0) {
      local_28[6] = 1;
      local_8c = (double)CONCAT44(0x68cfd,(undefined4)local_8c);
      local_28[4] = MSG_ReadLong();
      local_8c = (double)CONCAT44(0x68d05,(undefined4)local_8c);
      local_28[2] = MSG_ReadShort();
      local_8c = (double)CONCAT44(0x68d0d,(undefined4)local_8c);
      local_28[0] = MSG_ReadShort();
    }
    local_8c = (double)CONCAT44(0x68d15,(undefined4)local_8c);
    iVar4 = MSG_ReadByte();
    if (iVar4 != 0) {
      local_28[7] = 1;
      local_8c = (double)CONCAT44(0x68d25,(undefined4)local_8c);
      local_28[5] = MSG_ReadLong();
      local_8c = (double)CONCAT44(0x68d2d,(undefined4)local_8c);
      local_28[3] = MSG_ReadShort();
      local_8c = (double)CONCAT44(0x68d35,(undefined4)local_8c);
      local_28[1] = MSG_ReadShort();
    }
  }
  local_30 = uVar2 & 0x3fffffff;
  local_34 = uVar3 & 0x7fffffff;
  if (((byte)((float)net_showpackets._12_4_ < 0.0 |
              (byte)((ushort)((ushort)NAN((float)net_showpackets._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)net_showpackets._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)
     && ((byte)(3.0 < (float)net_showpackets._12_4_ |
                (byte)((ushort)((ushort)NAN((float)net_showpackets._12_4_) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)net_showpackets._12_4_ == 3.0) << 0xe) >> 8)) != 0x40
        )) {
    cVar5 = 's';
    if (param_1 == (undefined4 *)&DAT_00382504) {
      cVar5 = 'c';
    }
    local_8c = realtime;
    pcStack_94 = (char *)(uVar3 & 0x3f);
    aiStack_a0[2] = uVar2 & 0x3f;
    aiStack_a0[1] = DAT_00226fec;
    aiStack_a0[0] = (int)cVar5;
    pcStack_a4 = " %c <-- sz=%i seq=%i ack=%i rel=%i tm=%f\n";
    aiStack_ac[1] = 0x68db7;
    puStack_90 = (undefined4 *)-((int)uVar2 >> 0x1f);
    Con_Printf();
  }
  uVar1 = param_1[0xc];
  if (local_30 <= uVar1) {
    if ((byte)((float)net_showdrop._12_4_ < 0.0 |
               (byte)((ushort)((ushort)NAN((float)net_showdrop._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)net_showdrop._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      if (local_30 == uVar1) {
        local_8c = (double)(CONCAT44(uVar2,uVar2) & 0x3fffffff3fffffff);
        puVar8 = param_1 + 1;
        piVar10 = aiStack_ac + 3;
        for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
          *piVar10 = *puVar8;
          puVar8 = puVar8 + 1;
          piVar10 = piVar10 + 1;
        }
        pcStack_a4 = (char *)0x68e05;
        puStack_90 = (undefined4 *)NET_AdrToString();
        pcStack_94 = "%s:duplicate packet %i at %i\n";
      }
      else {
        local_8c = (double)(CONCAT44(uVar1,uVar2) & 0xffffffff3fffffff);
        puVar8 = param_1 + 1;
        piVar10 = aiStack_ac + 3;
        for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
          *piVar10 = *puVar8;
          puVar8 = puVar8 + 1;
          piVar10 = piVar10 + 1;
        }
        pcStack_a4 = (char *)0x68e2b;
        puStack_90 = (undefined4 *)NET_AdrToString();
        pcStack_94 = "%s:out of order packet %i at %i\n";
      }
      aiStack_a0[2] = 0x68e3d;
      Con_Printf();
    }
    return 0;
  }
  net_drop = (local_30 - 1) - uVar1;
  if ((0 < net_drop) &&
     ((byte)((float)net_showdrop._12_4_ < 0.0 |
             (byte)((ushort)((ushort)NAN((float)net_showdrop._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)net_showdrop._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) {
    local_8c = (double)(CONCAT44(uVar2,(local_30 - 1) - param_1[0xc]) & 0x3fffffffffffffff);
    piVar10 = aiStack_ac + 3;
    puVar8 = param_1;
    for (iVar4 = 5; puVar8 = puVar8 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar10 = *puVar8;
      piVar10 = piVar10 + 1;
    }
    pcStack_a4 = (char *)0x68e91;
    puStack_90 = (undefined4 *)NET_AdrToString();
    pcStack_94 = "%s:Dropped %i packets at %i\n";
    aiStack_a0[2] = 0x68ea3;
    Con_Printf();
  }
  if ((uVar3 >> 0x1f == param_1[0x11]) && ((int)param_1[0x12] < (int)param_1[0xd])) {
    param_1[0x404] = 0;
  }
  param_1[0xc] = local_30;
  param_1[0xd] = local_34;
  param_1[0xe] = uVar3 >> 0x1f;
  if (-((int)uVar2 >> 0x1f) != 0) {
    *(byte *)(param_1 + 0xf) = *(byte *)(param_1 + 0xf) ^ 1;
  }
  local_8 = (float)realtime;
  param_1[6] = local_8;
  param_1[(param_1[0x907] & 0x1f) * 3 + 0x8a7] = DAT_00226fec + 0x1c;
  *(double *)(param_1 + (param_1[0x907] & 0x1f) * 3 + 0x8a8) = realtime;
  param_1[0x907] = param_1[0x907] + 1;
  local_8c = (double)CONCAT44(param_1,0x68f55);
  Netchan_UpdateFlow();
  if (uVar9 != 0) {
    local_2c = 0;
    local_60 = param_1 + 0x7fc;
    do {
      if (local_28[local_2c + 6] != 0) {
        uVar9 = local_28[local_2c + 4];
        if (uVar9 != 0) {
          local_8c = (double)CONCAT44(1,uVar9);
          puStack_90 = local_60;
          pcStack_94 = (char *)0x68fc0;
          iVar4 = Netchan_FindBufferById();
          if (iVar4 == 0) {
            local_8c = (double)CONCAT44(uVar9 >> 0x10,
                                        "Netchan_Process:  Couldn\'t allocate or find buffer %i\n");
            puStack_90 = (undefined4 *)0x69019;
            Con_Printf();
          }
          else {
            uVar2 = local_28[local_2c];
            local_8c._0_4_ = 0x68fde;
            local_8c._4_4_ = iVar4 + 8;
            SZ_Clear();
            local_8c = (double)CONCAT44(local_8c._4_4_,uVar2);
            puStack_90 = (undefined4 *)(local_28[local_2c + 2] + msg_readcount + DAT_00226fe4);
            aiStack_a0[2] = 0x69007;
            pcStack_94 = (char *)(iVar4 + 8);
            SZ_Write();
          }
          local_8c = (double)(CONCAT44(uVar9,local_2c) & 0xffffffffffff);
          puStack_90 = param_1;
          pcStack_94 = (char *)0x6902d;
          Netchan_CheckForCompletion();
        }
        iVar4 = msg_readcount + local_28[local_2c + 2];
        puVar11 = (undefined1 *)(DAT_00226fe4 + iVar4 + local_28[local_2c]);
        puVar6 = (undefined1 *)(DAT_00226fe4 + iVar4);
        uVar9 = ((DAT_00226fec - local_28[local_2c]) - local_28[local_2c + 2]) - msg_readcount;
        local_6c = 0;
        if (0 < (int)uVar9) {
          uVar2 = uVar9 & 3;
          if (uVar2 != 0) {
            if (1 < uVar2) {
              if (2 < uVar2) {
                *puVar6 = *puVar11;
                puVar11 = puVar11 + 1;
                puVar6 = puVar6 + 1;
              }
              local_6c = (uint)(2 < uVar2);
              *puVar6 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar6 = puVar6 + 1;
              local_6c = local_6c + 1;
            }
            *puVar6 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar6 = puVar6 + 1;
            local_6c = local_6c + 1;
            if ((int)uVar9 <= (int)local_6c) goto LAB_000690e9;
          }
          do {
            *puVar6 = *puVar11;
            puVar6[1] = puVar11[1];
            puVar6[2] = puVar11[2];
            puVar6[3] = puVar11[3];
            puVar11 = puVar11 + 4;
            puVar6 = puVar6 + 4;
            local_6c = local_6c + 4;
          } while ((int)local_6c < (int)uVar9);
        }
LAB_000690e9:
        DAT_00226fec = DAT_00226fec - local_28[local_2c];
        local_6c = local_2c + 1;
        if ((int)local_6c < 2) {
          puVar7 = local_28 + local_2c + 3;
          uVar9 = 2 - local_6c & 3;
          if ((int)local_6c < 2) {
            if (uVar9 != 0) {
              if (1 < uVar9) {
                if (2 < uVar9) {
                  *puVar7 = *puVar7 - local_28[local_2c];
                  puVar7 = local_28 + local_2c + 4;
                  local_6c = local_2c + 2;
                }
                *puVar7 = *puVar7 - local_28[local_2c];
                puVar7 = puVar7 + 1;
                local_6c = local_6c + 1;
              }
              goto LAB_00069158;
            }
          }
          else {
LAB_00069158:
            *puVar7 = *puVar7 - local_28[local_2c];
            puVar7 = puVar7 + 1;
            local_6c = local_6c + 1;
            if (1 < (int)local_6c) goto LAB_00069190;
          }
          do {
            *puVar7 = *puVar7 - local_28[local_2c];
            puVar7[1] = puVar7[1] - local_28[local_2c];
            puVar7[2] = puVar7[2] - local_28[local_2c];
            puVar7[3] = puVar7[3] - local_28[local_2c];
            puVar7 = puVar7 + 4;
            local_6c = local_6c + 4;
          } while ((int)local_6c < 2);
        }
      }
LAB_00069190:
      local_60 = local_60 + 1;
      local_2c = local_2c + 1;
    } while (local_2c < 2);
    if (DAT_00226fec < 0x11) {
      return 0;
    }
  }
  return 1;
}


// Netchan_Setup  @ 00067dec
void Netchan_Setup(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  
  Netchan_Clear(param_2);
  Q_memset(param_2,0,0x2430);
  *param_2 = param_1;
  puVar2 = (undefined4 *)&stack0x0000000c;
  puVar3 = param_2;
  for (iVar1 = 5; puVar3 = puVar3 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
  }
  param_2[6] = (float)realtime;
  param_2[7] = (float)realtime;
  param_2[0x16] = param_2 + 0x19;
  *(undefined2 *)(param_2 + 0x15) = 1;
  param_2[0x17] = 0xfaa;
  param_2[8] = 0;
  param_2[9] = 0x40c38780;
  param_2[0x13] = in_stack_00000020;
  param_2[0x14] = in_stack_00000024;
  return;
}


// Netchan_Transmit  @ 00068130
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void Netchan_Transmit(undefined4 *param_1,int param_2,undefined4 param_3)

{
  float fVar1;
  double dVar2;
  bool bVar3;
  double dVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 uVar7;
  short *psVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint *puVar11;
  bool bVar12;
  uint uStack_108c;
  undefined4 *puStack_1088;
  undefined4 *puStack_1084;
  undefined8 local_1080;
  uint local_1060;
  int local_1034;
  undefined4 *local_1028;
  int local_1024;
  int local_1008;
  int local_1004;
  int local_ff8;
  int local_ff4 [2];
  float local_fec;
  undefined4 local_fe8;
  uint local_fe4;
  undefined4 local_fe0;
  undefined1 local_fdc [4040];
  undefined2 local_14 [2];
  undefined1 *local_10;
  int local_c;
  int local_8;
  
  local_1080 = (double)CONCAT44(0x68141,(undefined4)local_1080);
  bVar3 = false;
  local_10 = local_fdc;
  local_c = 0xfc5;
  local_8 = 0;
  local_14[0] = 0;
  if ((*(byte *)(param_1 + 0x15) & 2) != 0) {
    puVar11 = &uStack_108c;
    for (iVar6 = 5; param_1 = param_1 + 1, iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar11 = *param_1;
      puVar11 = puVar11 + 1;
    }
    uVar5 = NET_AdrToString();
    Con_Printf("%s:Outgoing message overflow\n",uVar5);
    return;
  }
  local_ff8 = 0;
  if (((int)param_1[0x12] < (int)param_1[0xd]) && (param_1[0xe] != param_1[0x11])) {
    local_ff8 = 1;
    bVar3 = true;
  }
  if (param_1[0x404] == 0) {
    local_ff4[0] = 0;
    local_ff4[1] = 0;
    local_1080 = (double)CONCAT44(param_1,0x68210);
    Netchan_FragSend();
    bVar12 = param_1[0x18] != 0;
    if (param_1[0x7f6] != 0) {
      local_ff4[0] = 1;
    }
    if (param_1[0x7f7] != 0) {
      local_ff4[1] = 1;
    }
    if (((bVar12) && (local_ff4[0] != 0)) && (bVar12 = false, 0x4b0 < (int)param_1[0x18])) {
      local_1080 = (double)CONCAT44(param_1 + 0x15,param_1);
      puStack_1084 = (undefined4 *)(uint)(param_1 != (undefined4 *)&DAT_00382504);
      puStack_1088 = (undefined4 *)0x682b2;
      Netchan_CreateFragments();
      param_1[0x18] = 0;
    }
    *(undefined2 *)(param_1 + 0x7fa) = 0;
    param_1[0x7f2] = 0;
    param_1[0x7f4] = 0;
    *(undefined2 *)(param_1 + 0x7fb) = 0;
    *(undefined2 *)((int)param_1 + 0x1fea) = 0;
    param_1[0x7f3] = 0;
    param_1[0x7f5] = 0;
    *(undefined2 *)((int)param_1 + 0x1fee) = 0;
    if ((bVar12) || (local_ff4[1] != 0 || local_ff4[0] != 0)) {
      local_ff8 = 1;
      *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) ^ 1;
    }
    if (bVar12) {
      local_1080 = (double)CONCAT44(param_1[0x18],param_1 + 0x19);
      puStack_1084 = param_1 + 0x405;
      puStack_1088 = (undefined4 *)0x683b2;
      Q_memcpy();
      param_1[0x404] = param_1[0x18];
      param_1[0x18] = 0;
      *(undefined2 *)(param_1 + 0x7fa) = *(undefined2 *)(param_1 + 0x404);
      *(undefined2 *)((int)param_1 + 0x1fea) = *(undefined2 *)(param_1 + 0x404);
    }
    local_1004 = 0;
    local_1024 = 0;
    local_1028 = param_1 + 0x7f6;
    do {
      uVar9 = *(uint *)((int)param_1 + local_1024 * 2 + 0x1fd8);
      if (((uVar9 != 0) && (local_1008 = *(int *)(uVar9 + 0x14), *(int *)(uVar9 + 0x590) != 0)) &&
         (*(int *)(uVar9 + 0x594) == 0)) {
        local_1008 = *(int *)(uVar9 + 0x6a0);
      }
      if (((*(int *)((int)local_ff4 + local_1024 * 2) != 0) && (uVar9 != 0)) &&
         (local_1008 + param_1[0x404] < 0x4b0)) {
        *(uint *)((int)param_1 + local_1024 * 2 + 0x1fd0) =
             CONCAT22(*(undefined2 *)(uVar9 + 4),*(undefined2 *)(param_1 + local_1004 + 0x7f8));
        if ((*(int *)(uVar9 + 0x590) != 0) && (*(int *)(uVar9 + 0x594) == 0)) {
          local_1080 = (double)CONCAT44(&local_fe8,uVar9 + 0x598);
          puStack_1084 = (undefined4 *)0x684f0;
          COM_OpenFile();
          puStack_1084 = *(undefined4 **)(uVar9 + 0x69c);
          puStack_1088 = (undefined4 *)local_fe0;
          uStack_108c = local_fe4;
          COM_FileSeek(local_fe8);
          Sys_FileRead(local_fe0,*(int *)(uVar9 + 0x14) + *(int *)(uVar9 + 0xc),
                       *(undefined4 *)(uVar9 + 0x6a0));
          *(int *)(uVar9 + 0x14) = *(int *)(uVar9 + 0x14) + *(int *)(uVar9 + 0x6a0);
          puStack_1084 = (undefined4 *)local_fe8;
          puStack_1088 = (undefined4 *)0x68551;
          COM_CloseFile();
        }
        local_1080 = (double)CONCAT44(*(undefined4 *)(uVar9 + 0x14),*(undefined4 *)(uVar9 + 0xc));
        puStack_1084 = (undefined4 *)(param_1[0x404] + 0x1014 + (int)param_1);
        puStack_1088 = (undefined4 *)0x68573;
        Q_memcpy();
        param_1[0x404] = param_1[0x404] + *(int *)(uVar9 + 0x14);
        *(undefined2 *)((int)param_1 + local_1024 + 0x1fec) = *(undefined2 *)(uVar9 + 0x14);
        puStack_1088 = local_1028;
        uStack_108c = uVar9;
        Netchan_UnlinkFragment();
        *(undefined4 *)((int)param_1 + local_1024 * 2 + 0x1fc8) = 1;
        local_1034 = local_1004 + 1;
        if (local_1034 < 2) {
          psVar8 = (short *)((int)(param_1 + 0x7fa) + local_1034 * 2);
          uVar9 = 2U - local_1034 & 3;
          if (local_1034 < 2) {
            if (uVar9 != 0) {
              if (1 < uVar9) {
                if (2 < uVar9) {
                  *psVar8 = *psVar8 + *(short *)((int)param_1 + local_1024 + 0x1fec);
                  psVar8 = psVar8 + 1;
                  local_1034 = local_1004 + 2;
                }
                *psVar8 = *psVar8 + *(short *)((int)param_1 + local_1024 + 0x1fec);
                psVar8 = psVar8 + 1;
                local_1034 = local_1034 + 1;
              }
              goto LAB_0006864d;
            }
          }
          else {
LAB_0006864d:
            *psVar8 = *psVar8 + *(short *)((int)param_1 + local_1024 + 0x1fec);
            psVar8 = psVar8 + 1;
            local_1034 = local_1034 + 1;
            if (1 < local_1034) goto LAB_000686b6;
          }
          do {
            *psVar8 = *psVar8 + *(short *)((int)param_1 + local_1024 + 0x1fec);
            psVar8[1] = psVar8[1] + *(short *)((int)param_1 + local_1024 + 0x1fec);
            psVar8[2] = psVar8[2] + *(short *)((int)param_1 + local_1024 + 0x1fec);
            psVar8[3] = psVar8[3] + *(short *)((int)param_1 + local_1024 + 0x1fec);
            psVar8 = psVar8 + 4;
            local_1034 = local_1034 + 4;
          } while (local_1034 < 2);
        }
      }
LAB_000686b6:
      local_1024 = local_1024 + 2;
      local_1028 = local_1028 + 1;
      local_1004 = local_1004 + 1;
    } while (local_1004 < 2);
  }
  bVar12 = false;
  local_1060 = local_ff8 << 0x1f | param_1[0x10];
  iVar6 = param_1[0xf];
  uVar9 = param_1[0xc];
  if ((param_1[0x7f2] != 0) || (param_1[0x7f3] != 0)) {
    bVar12 = true;
  }
  if ((local_ff8 != 0) && (bVar12)) {
    local_1060 = local_1060 | 0x40000000;
  }
  param_1[0x10] = param_1[0x10] + 1;
  local_1080 = (double)CONCAT44(local_1060,local_14);
  puStack_1084 = (undefined4 *)0x6876a;
  MSG_WriteLong();
  uStack_108c = 0x68777;
  puStack_1088 = (undefined4 *)local_14;
  puStack_1084 = (undefined4 *)(iVar6 << 0x1f | uVar9);
  MSG_WriteLong();
  if (local_ff8 != 0) {
    if (bVar12) {
      if (param_1[0x7f2] == 0) {
        local_1080 = (double)ZEXT48(local_14);
        puStack_1084 = (undefined4 *)0x687fe;
        MSG_WriteByte();
      }
      else {
        local_1080 = (double)CONCAT44(1,local_14);
        puStack_1084 = (undefined4 *)0x687ad;
        MSG_WriteByte();
        puStack_1084 = (undefined4 *)param_1[0x7f4];
        uStack_108c = 0x687bd;
        puStack_1088 = (undefined4 *)local_14;
        MSG_WriteLong();
        uStack_108c = (uint)*(short *)(param_1 + 0x7fa);
        MSG_WriteShort(local_14);
        MSG_WriteShort(local_14,(int)*(short *)(param_1 + 0x7fb));
      }
      if (param_1[0x7f3] == 0) {
        local_1080 = (double)ZEXT48(local_14);
        puStack_1084 = (undefined4 *)0x6885a;
        MSG_WriteByte();
      }
      else {
        local_1080 = (double)CONCAT44(1,local_14);
        puStack_1084 = (undefined4 *)0x68815;
        MSG_WriteByte();
        puStack_1084 = (undefined4 *)param_1[0x7f5];
        uStack_108c = 0x68825;
        puStack_1088 = (undefined4 *)local_14;
        MSG_WriteLong();
        uStack_108c = (uint)*(short *)((int)param_1 + 0x1fea);
        MSG_WriteShort(local_14);
        MSG_WriteShort(local_14,(int)*(short *)((int)param_1 + 0x1fee));
      }
    }
    if (local_ff8 != 0) {
      local_1080 = (double)CONCAT44(param_1[0x404],param_1 + 0x405);
      puStack_1088 = (undefined4 *)0x68886;
      puStack_1084 = (undefined4 *)local_14;
      SZ_Write();
      param_1[0x12] = param_1[0x10] + -1;
    }
  }
  iVar6 = 0x578;
  if (!bVar3) {
    iVar6 = local_c;
  }
  if (iVar6 - local_8 < param_2) {
    local_1080 = 1.467198817983953e-308;
    Con_DPrintf();
  }
  else {
    local_1080 = (double)CONCAT44(param_2,param_3);
    puStack_1088 = (undefined4 *)0x688c0;
    puStack_1084 = (undefined4 *)local_14;
    SZ_Write();
  }
  iVar6 = local_8;
  if (0xf < local_8) goto LAB_0006897a;
  uVar9 = 0x10U - local_8 & 3;
  if (local_8 < 0x10) {
    if (uVar9 != 0) {
      if (1 < uVar9) {
        if (2 < uVar9) {
          local_1080 = (double)CONCAT44(1,local_14);
          puStack_1084 = (undefined4 *)0x68910;
          MSG_WriteByte();
          iVar6 = iVar6 + 1;
        }
        local_1080 = (double)CONCAT44(1,local_14);
        puStack_1084 = (undefined4 *)0x68922;
        MSG_WriteByte();
        iVar6 = iVar6 + 1;
      }
      goto LAB_00068926;
    }
  }
  else {
LAB_00068926:
    local_1080 = (double)CONCAT44(1,local_14);
    puStack_1084 = (undefined4 *)0x68934;
    MSG_WriteByte();
    iVar6 = iVar6 + 1;
    if (0xf < iVar6) goto LAB_0006897a;
  }
  do {
    local_1080 = (double)CONCAT44(1,local_14);
    puStack_1084 = (undefined4 *)0x6894e;
    MSG_WriteByte();
    local_1080 = (double)CONCAT44(1,local_14);
    puStack_1084 = (undefined4 *)0x68959;
    MSG_WriteByte();
    local_1080 = (double)CONCAT44(1,local_14);
    puStack_1084 = (undefined4 *)0x68964;
    MSG_WriteByte();
    local_1080 = (double)CONCAT44(1,local_14);
    puStack_1084 = (undefined4 *)0x6896f;
    MSG_WriteByte();
    iVar6 = iVar6 + 4;
  } while (iVar6 < 0x10);
LAB_0006897a:
  param_1[(param_1[0x8a2] & 0x1f) * 3 + 0x842] = local_8 + 0x1c;
  *(double *)(param_1 + (param_1[0x8a2] & 0x1f) * 3 + 0x843) = realtime;
  param_1[0x8a2] = param_1[0x8a2] + 1;
  local_1080 = (double)CONCAT44(param_1,0x689d0);
  Netchan_UpdateFlow();
  if (DAT_003855a4 == 0) {
    puVar11 = &uStack_108c;
    puVar10 = param_1;
    for (iVar6 = 5; puVar10 = puVar10 + 1, iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar11 = *puVar10;
      puVar11 = puVar11 + 1;
    }
    NET_SendPacket(*param_1,local_8,local_10);
  }
  dVar4 = realtime;
  if ((sv == 0) ||
     ((byte)((float)sv_lan._12_4_ < 0.0 |
             (byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)) {
    fVar1 = 1.0 / (float)*(double *)(param_1 + 8);
  }
  else {
    fVar1 = 0.00010001;
  }
  dVar2 = *(double *)(param_1 + 10);
  if (0x3f < (byte)((realtime < dVar2 |
                     (byte)((ushort)((ushort)(NAN(realtime) || NAN(dVar2)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(realtime == dVar2) << 0xe) >> 8)) - 1)) {
    *(double *)(param_1 + 10) = realtime;
    dVar2 = dVar4;
  }
  *(double *)(param_1 + 10) = (double)fVar1 * (double)(local_8 + 0x1c) + dVar2;
  if (((byte)((float)net_showpackets._12_4_ < 0.0 |
              (byte)((ushort)((ushort)NAN((float)net_showpackets._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)net_showpackets._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)
     && ((byte)(2.0 < (float)net_showpackets._12_4_ |
                (byte)((ushort)((ushort)NAN((float)net_showpackets._12_4_) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)net_showpackets._12_4_ == 2.0) << 0xe) >> 8)) != 0x40
        )) {
    uVar7 = 0x73;
    if (param_1 == (undefined4 *)&DAT_00382504) {
      uVar7 = 99;
    }
    local_fec = (float)realtime;
    local_1080 = (double)local_fec;
    puStack_1084 = (undefined4 *)local_ff8;
    puStack_1088 = (undefined4 *)(param_1[0xc] & 0x3f);
    uStack_108c = param_1[0x10] - 1 & 0x3f;
    Con_Printf(" %c --> sz=%i seq=%i ack=%i rel=%i tm=%f\n",uVar7,local_8);
  }
  return;
}


// Netchan_UnlinkFragment  @ 00067ab0
void Netchan_UnlinkFragment(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  char *pcVar3;
  
  if (param_2 == (int *)0x0) {
    pcVar3 = "Netchan_UnlinkFragment:  Asked to unlink fragment from empty list, ignored\n";
  }
  else {
    piVar1 = (int *)*param_2;
    if (param_1 == piVar1) {
      *param_2 = *param_1;
      Mem_Free(param_1);
      return;
    }
    for (piVar2 = (int *)*piVar1; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      if (piVar2 == param_1) {
        *piVar1 = *piVar2;
        Mem_Free(piVar2);
        return;
      }
      piVar1 = piVar2;
    }
    pcVar3 = (char *)FUN_000a8c60;
  }
  Con_Printf(pcVar3);
  return;
}


// Netchan_UpdateFlow  @ 00067ef4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Netchan_UpdateFlow(int param_1)

{
  double *pdVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  double dVar6;
  double dVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  longdouble lVar12;
  longdouble lVar13;
  longdouble lVar14;
  longdouble lVar15;
  longdouble lVar16;
  int local_20;
  double *local_1c;
  int *local_18;
  float *local_14;
  float *local_10;
  int local_c;
  
  dVar7 = _FUN_000a8c98;
  lVar16 = (longdouble)0;
  if (param_1 != 0) {
    local_c = 0;
    local_10 = (float *)(param_1 + 0x2298);
    local_14 = (float *)(param_1 + 0x2294);
    local_18 = (int *)(param_1 + 0x2288);
    local_1c = (double *)(param_1 + 0x228c);
    local_20 = param_1 + 0x2108;
    iVar11 = 0;
    do {
      dVar6 = realtime - *local_1c;
      if ((byte)(dVar6 < dVar7 | (byte)((ushort)((ushort)(NAN(dVar6) || NAN(dVar7)) << 10) >> 8) |
                (byte)((ushort)((ushort)(dVar6 == dVar7) << 0xe) >> 8)) != 1) {
        *local_1c = realtime + dVar7;
        iVar9 = 1;
        uVar8 = *local_18 - 1;
        piVar10 = (int *)(local_20 + (uVar8 & 0x1f) * 0xc);
        do {
          piVar2 = (int *)(local_20 + (uVar8 - iVar9 & 0x1f) * 0xc);
          pdVar1 = (double *)(piVar10 + 1);
          lVar12 = (longdouble)*(double *)(piVar2 + 1);
          piVar3 = (int *)(local_20 + (uVar8 - (iVar9 + 1) & 0x1f) * 0xc);
          lVar13 = (longdouble)*(double *)(piVar3 + 1);
          piVar4 = (int *)(local_20 + (uVar8 - (iVar9 + 2) & 0x1f) * 0xc);
          lVar14 = (longdouble)*(double *)(piVar4 + 1);
          piVar5 = (int *)(local_20 + (uVar8 - (iVar9 + 3) & 0x1f) * 0xc);
          lVar15 = (longdouble)*(double *)(piVar5 + 1);
          piVar10 = (int *)(local_20 + (uVar8 - (iVar9 + 4) & 0x1f) * 0xc);
          iVar9 = iVar9 + 5;
          iVar11 = iVar11 + *piVar2 + *piVar3 + *piVar4 + *piVar5 + *piVar10;
          lVar16 = (longdouble)
                   (float)((lVar15 - (longdouble)*(double *)(piVar10 + 1)) +
                          (longdouble)
                          (float)((lVar14 - lVar15) +
                                 (longdouble)
                                 (float)((lVar13 - lVar14) +
                                        (longdouble)
                                        (float)((lVar12 - lVar13) +
                                               (longdouble)
                                               (float)(((longdouble)*pdVar1 - lVar12) + lVar16)))));
        } while (iVar9 < 0x10);
        lVar12 = (longdouble)0;
        if ((byte)((byte)((ushort)((ushort)(NAN(lVar12) || NAN(lVar16)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(lVar12 == lVar16) << 0xe) >> 8)) == 0x40) {
          *local_14 = (float)lVar12;
        }
        else {
          *local_14 = (float)((longdouble)iVar11 / lVar16);
          *local_14 = (float)((longdouble)0.0009765625 * ((longdouble)iVar11 / lVar16));
        }
        *local_10 = *local_14 * 0.33333334 + *local_10 * 0.6666667;
      }
      local_10 = local_10 + 0x65;
      local_14 = local_14 + 0x65;
      local_18 = local_18 + 0x65;
      local_1c = (double *)((int)local_1c + 0x194);
      local_20 = local_20 + 0x194;
      local_c = local_c + 1;
    } while (local_c < 2);
  }
  return;
}


// Netchan_UpdateProgress  @ 00069c90
void Netchan_UpdateProgress(int param_1)

{
  ushort *puVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int *piVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int *local_414;
  int local_410;
  int local_40c;
  char local_408 [1024];
  float local_8;
  
  local_40c = 0;
  scr_downloading._12_4_ = 0xbf800000;
  gDownloadFile = 0;
  fVar3 = 0.0;
  if (((byte)(1.0 < (float)net_drawslider._12_4_ |
              (byte)((ushort)((ushort)NAN((float)net_drawslider._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)net_drawslider._12_4_ == 1.0) << 0xe) >> 8)) == 0x40)
     || (fVar4 = (float)scr_downloading._12_4_, *(int *)(param_1 + 0x1ff4) != 0)) {
    local_410 = 1;
    local_414 = (int *)(param_1 + 0x1ff4);
    do {
      piVar5 = (int *)*local_414;
      if (piVar5 == (int *)0x0) {
        iVar8 = *(int *)(local_410 * 4 + 0x1fd8 + param_1);
        if (((iVar8 != 0) && (iVar2 = *(int *)(local_410 * 4 + 0x1fe0 + param_1), iVar2 != 0)) &&
           (local_8 = ((float)*(int *)(iVar8 + 4) * 100.0) / (float)iVar2,
           0x3f < (byte)((local_8 < fVar3 |
                          (byte)((ushort)((ushort)(NAN(local_8) || NAN(fVar3)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(local_8 == fVar3) << 0xe) >> 8)) - 1))) {
          fVar3 = local_8;
        }
      }
      else {
        puVar1 = (ushort *)(piVar5 + 1);
        do {
          local_40c = local_40c + 1;
          piVar5 = (int *)*piVar5;
        } while (piVar5 != (int *)0x0);
        if ((*puVar1 != 0) &&
           (local_8 = ((float)local_40c * 100.0) / (float)*puVar1,
           0x3f < (byte)((local_8 < fVar3 |
                          (byte)((ushort)((ushort)(NAN(local_8) || NAN(fVar3)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(local_8 == fVar3) << 0xe) >> 8)) - 1))) {
          fVar3 = local_8;
        }
        if (local_410 == 1) {
          iVar8 = 0;
          pcVar6 = *(char **)(*local_414 + 0xc);
          pcVar7 = local_408;
          do {
            if (*pcVar6 == '\0') break;
            *pcVar7 = *pcVar6;
            pcVar6 = pcVar6 + 1;
            pcVar7 = pcVar7 + 1;
            iVar8 = iVar8 + 1;
          } while (iVar8 < 0x81);
          *pcVar7 = '\0';
          iVar8 = Q_strlen(local_408);
          if ((0 < iVar8) && (local_408[0] != '!')) {
            Q_strncpy(&gDownloadFile,local_408,0xff);
            DAT_0015255f = 0;
          }
        }
      }
      local_414 = local_414 + -1;
      local_410 = local_410 + -1;
      fVar4 = fVar3;
    } while (-1 < local_410);
  }
  scr_downloading._12_4_ = fVar4;
  return;
}


