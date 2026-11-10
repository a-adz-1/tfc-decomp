// CRC_File  @ 0005d080
void CRC_File(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iStack_410;
  int iStack_40c;
  undefined1 auStack_408 [1024];
  int local_8;
  
  local_8 = FS_Open(param_2,&DAT_000e0b30);
  if (local_8 == 0) {
    FUN_0005d1ec();
    return;
  }
  iStack_410 = FS_Size(local_8);
  while( true ) {
    if (iStack_410 < 1) {
      FUN_0005d1c0();
      return;
    }
    if (iStack_410 < 0x401) {
      iStack_40c = FS_Read(auStack_408,iStack_410,1,local_8);
    }
    else {
      iStack_40c = FS_Read(auStack_408,0x400,1,local_8);
    }
    if (0 < iStack_40c) {
      iStack_410 = iStack_410 - iStack_40c;
      CRC32_ProcessBuffer(param_1,auStack_408,iStack_40c);
    }
    iVar1 = FS_EndOfFile(local_8);
    if (iVar1 != 0) break;
    iVar1 = FS_IsOk(local_8);
    if (iVar1 == 0) {
      if (local_8 != 0) {
        FS_Close(local_8);
      }
      FUN_0005d1ec();
      return;
    }
  }
  FUN_0005d1c0();
  return;
}


// CRC_MapFile  @ 0005d1f8
/* WARNING: Removing unreachable block (ram,0x0005d348) */
/* WARNING: Removing unreachable block (ram,0x0005d39c) */
/* WARNING: Removing unreachable block (ram,0x0005d3a5) */
/* WARNING: Removing unreachable block (ram,0x0005d3ac) */
/* WARNING: Removing unreachable block (ram,0x0005d3dc) */
/* WARNING: Removing unreachable block (ram,0x0005d3b8) */
/* WARNING: Removing unreachable block (ram,0x0005d400) */
/* WARNING: Removing unreachable block (ram,0x0005d409) */
/* WARNING: Removing unreachable block (ram,0x0005d432) */
/* WARNING: Removing unreachable block (ram,0x0005d447) */
/* WARNING: Removing unreachable block (ram,0x0005d44d) */
/* WARNING: Removing unreachable block (ram,0x0005d45c) */
/* WARNING: Removing unreachable block (ram,0x0005d460) */
/* WARNING: Removing unreachable block (ram,0x0005d331) */

undefined4 CRC_MapFile(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_490 [32];
  undefined4 uStack_410;
  int local_40c;
  int local_8;
  
  local_8 = FS_Open(param_2,&DAT_000e0b30);
  if (local_8 == 0) {
    uVar1 = FUN_0005d490();
    return uVar1;
  }
  FS_Size(local_8);
  FS_Tell(local_8);
  iVar2 = FS_Read(local_490,0x7c,1,local_8);
  if (iVar2 == 0x7c) {
    local_40c = (*LittleLong)(local_490[0]);
    if ((local_40c != 0x1d) && (local_40c != 0x1e)) {
      FS_Close(local_8);
      Con_Printf("Map [%s] has incorrect BSP version (%i should be %i).\n",param_2,local_40c,0x1e);
      return 0;
    }
    uStack_410 = 0;
    uVar1 = FUN_0005d468();
    return uVar1;
  }
  Con_Printf("Could not read BSP header for map [%s].\n",param_2);
  FS_Close(local_8);
  uVar1 = FUN_0005d490();
  return uVar1;
}


