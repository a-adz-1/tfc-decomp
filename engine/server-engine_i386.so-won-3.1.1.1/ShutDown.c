// ShutDown__13EngineWrapper  @ 00099774
void ShutDown__13EngineWrapper(int param_1)

{
  ShutDown__16BaseSystemModule(param_1 + 4);
  return;
}


// ShutDown__13SystemWrapper  @ 00097fe8
void ShutDown__13SystemWrapper(int param_1)

{
  int *piVar1;
  int iVar2;
  uint in_stack_ffffffc8;
  
  Clear__10ObjectListb(param_1 + 0xc,in_stack_ffffffc8 & 0xffff0000);
  *(undefined4 *)(param_1 + 0x120) = 4;
  Clear__10ObjectListb(param_1 + 0x158,1);
  while (piVar1 = (int *)GetFirst__10ObjectList(param_1 + 0x130), piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x40))(piVar1);
  }
  while (iVar2 = RemoveTail__10ObjectList(param_1 + 0x144), iVar2 != 0) {
    if (*(int *)(iVar2 + 0x1000) != 0) {
      Sys_UnloadModule__FP10CSysModule(*(undefined4 *)(iVar2 + 0x1000));
    }
    Mem_Free(iVar2);
  }
  if (*(int *)(param_1 + 0x17c) != 0) {
    (**(code **)(**(int **)(param_1 + 0x17c) + 8))(*(undefined4 *)(param_1 + 0x17c),3);
  }
  Cmd_RemoveWrapperCmds();
  return;
}


// ShutDown__16BaseSystemModule  @ 000cb46c
void ShutDown__16BaseSystemModule(int param_1)

{
  char cVar1;
  uint in_stack_ffffffd8;
  
  if (*(int *)(param_1 + 0x11c) != 4) {
    Clear__10ObjectListb(param_1 + 8,in_stack_ffffffd8 & 0xffff0000);
    *(undefined4 *)(param_1 + 0x11c) = 4;
    cVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x94))(*(undefined4 *)(param_1 + 4),param_1);
    if (cVar1 == '\0') {
      (**(code **)(**(int **)(param_1 + 4) + 0x50))
                (*(undefined4 *)(param_1 + 4),
                 "ERROR! BaseSystemModule::ShutDown: faild to remove module %s.\n",param_1 + 0x1c);
    }
  }
  return;
}


