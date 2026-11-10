// do_osfx__7ostream  @ 00052498
void do_osfx__7ostream(int *param_1)

{
  if ((*(byte *)(*param_1 + 0xd) & 0x20) != 0) {
    flush__7ostream(param_1);
  }
  if ((*(byte *)(*param_1 + 0xd) & 0x40) != 0) {
    fflush((FILE *)_IO_stdout_);
    fflush((FILE *)_IO_stderr_);
  }
  return;
}


