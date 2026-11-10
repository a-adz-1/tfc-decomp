// ws__FR7istream  @ 000521e0
int * ws__FR7istream(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined1 local_14 [16];
  
  puVar1 = (undefined4 *)*param_1;
  if (*(byte *)((int)puVar1 + 0x12) == 0) {
    _IO_flockfile((_IO_FILE *)*puVar1);
    iVar3 = ((int *)*param_1)[1];
    if ((iVar3 != 0) && (iVar2 = *(int *)*param_1, *(int *)(iVar2 + 8) == *(int *)(iVar2 + 4))) {
      flush__7ostream(iVar3);
    }
    _pthread_cleanup_push_defer(local_14,_IO_funlockfile,*(undefined4 *)*param_1);
    iVar3 = skip_ws__FP9streambuf(*(undefined4 *)*param_1);
    if (iVar3 == -1) {
      *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 1;
    }
    else {
      sputbackc__9streambufc(*(undefined4 *)*param_1,(int)(char)iVar3);
    }
    _IO_funlockfile(*(_IO_FILE **)*param_1);
    _pthread_cleanup_pop_restore(local_14,0);
  }
  else {
    *(byte *)((int)puVar1 + 0x12) = *(byte *)((int)puVar1 + 0x12) | 2;
  }
  return param_1;
}


