// do_osfx__7ostream  @ 00045b70
void do_osfx__7ostream(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if ((*(byte *)(iVar1 + 0xd) & 0x20) != 0) {
    flush__7ostream(param_1);
  }
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if ((*(byte *)(iVar1 + 0xd) & 0x40) != 0) {
    fflush((FILE *)_IO_stdout_);
    fflush((FILE *)_IO_stderr_);
  }
  return;
}


