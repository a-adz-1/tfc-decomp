// FSMC_FlushAccessedFiles  @ 00065668
void FSMC_FlushAccessedFiles(void)

{
  (**(code **)(*g_pFileSystemMemoryCache + 0x14))(g_pFileSystemMemoryCache);
  return;
}


// FSMC_FlushAllFiles  @ 000656a8
void FSMC_FlushAllFiles(void)

{
  (**(code **)(*g_pFileSystemMemoryCache + 0x18))(g_pFileSystemMemoryCache);
  return;
}


// FSMC_HintFileNeeded  @ 000655e0
void FSMC_HintFileNeeded(undefined4 param_1)

{
  (**(code **)(*g_pFileSystemMemoryCache + 0xc))(g_pFileSystemMemoryCache,param_1);
  return;
}


// FSMC_HintFileShouldStayInCache  @ 00065810
void FSMC_HintFileShouldStayInCache(undefined4 param_1)

{
  (**(code **)(*g_pFileSystemMemoryCache + 0x2c))(g_pFileSystemMemoryCache,param_1);
  return;
}


// FSMC_HintResourcesNeeded  @ 00065624
void FSMC_HintResourcesNeeded(undefined4 param_1)

{
  (**(code **)(*g_pFileSystemMemoryCache + 0x10))(g_pFileSystemMemoryCache,param_1);
  return;
}


// FSMC_IsFileInCache  @ 000657b4
undefined1 FSMC_IsFileInCache(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystemMemoryCache + 0x28))
                    (g_pFileSystemMemoryCache,param_1,
                     (short)CONCAT31((int3)((uint)g_pFileSystemMemoryCache >> 8),param_2 != 0));
  return uVar1;
}


// FSMC_PausePreloadThread  @ 000656e8
void FSMC_PausePreloadThread(void)

{
  (**(code **)(*g_pFileSystemMemoryCache + 0x1c))(g_pFileSystemMemoryCache);
  return;
}


// FSMC_ReportUsage  @ 00065854
void FSMC_ReportUsage(void)

{
  (**(code **)(*g_pFileSystemMemoryCache + 0x30))(g_pFileSystemMemoryCache);
  return;
}


// FSMC_ResumePreloadThread  @ 00065728
void FSMC_ResumePreloadThread(void)

{
  (**(code **)(*g_pFileSystemMemoryCache + 0x20))(g_pFileSystemMemoryCache);
  return;
}


// FSMC_SetPreloadEnabled  @ 00065768
void FSMC_SetPreloadEnabled(int param_1)

{
  (**(code **)(*g_pFileSystemMemoryCache + 0x24))
            (g_pFileSystemMemoryCache,
             (short)CONCAT31((int3)((uint)g_pFileSystemMemoryCache >> 8),param_1 != 0));
  return;
}


