// osfx__7ostream  @ 000526b0
void osfx__7ostream(int *param_1)

{
  _IO_funlockfile(*(_IO_FILE **)*param_1);
  if ((*(byte *)(*param_1 + 0xd) & 0x60) != 0) {
    do_osfx__7ostream(param_1);
  }
  return;
}


