// build_number  @ 0005375c
int build_number(void)

{
  int iVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  local_c = 0;
  if (b_3 == 0) {
    local_8 = 0;
    while ((local_8 < 0xb &&
           (iVar1 = Q_strncasecmp(date,*(undefined4 *)(mon + local_8 * 4),3), iVar1 != 0))) {
      local_c = local_c + (char)mond[local_8];
      local_8 = local_8 + 1;
    }
    iVar1 = atoi(date + 4);
    iVar2 = atoi(date + 7);
    b_3 = iVar1 + local_c + -1 + (int)ROUND((double)(iVar2 + -0x76d) * 365.25);
    if (((iVar2 - 0x76cU & 3) == 0) && (1 < local_8)) {
      b_3 = b_3 + 1;
    }
    b_3 = b_3 + -0x88b3;
  }
  return b_3;
}


