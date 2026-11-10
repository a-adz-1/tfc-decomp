// lock__FR7istream  @ 00052350
undefined4 * lock__FR7istream(undefined4 *param_1)

{
  _IO_flockfile(*(_IO_FILE **)*param_1);
  return param_1;
}


// lock__FR7ostream  @ 00052390
undefined4 * lock__FR7ostream(undefined4 *param_1)

{
  _IO_flockfile(*(_IO_FILE **)*param_1);
  return param_1;
}


