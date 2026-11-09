// linux_handler  @ 001bce80
void linux_handler(int i)

{
                    /* WARNING: Subroutine does not return */
  __longjmp_chk(g_mark,0xffffffff);
}


