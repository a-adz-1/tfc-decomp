// linux_handler  @ 0020cdc0
void linux_handler(int i)

{
                    /* WARNING: Subroutine does not return */
  siglongjmp((__jmp_buf_tag *)g_mark,-1);
}


