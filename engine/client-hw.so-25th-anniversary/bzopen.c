// bzopen_or_bzdopen  @ 001e1806
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int bzopen_or_bzdopen(int param_1)

{
  bool bVar1;
  bool bVar2;
  char *in_EAX;
  ushort **ppuVar3;
  FILE *__stream;
  char *in_ECX;
  int in_EDX;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  char *pcVar8;
  byte bVar9;
  undefined4 local_13c4;
  undefined1 local_13b2 [4998];
  undefined2 uStack_2c;
  char local_2a [26];
  
  bVar9 = 0;
  local_2a[0] = '\0';
  local_2a[1] = '\0';
  local_2a[2] = '\0';
  local_2a[3] = '\0';
  local_2a[4] = '\0';
  local_2a[5] = '\0';
  local_2a[6] = '\0';
  local_2a[7] = '\0';
  local_2a[8] = '\0';
  local_2a[9] = '\0';
  iVar5 = 0;
  if (in_ECX != (char *)0x0) {
    cVar4 = *in_ECX;
    if (cVar4 == '\0') {
      bVar2 = false;
      local_13c4 = 0;
      iVar6 = 9;
      puVar7 = (undefined2 *)&LAB_00256fab;
    }
    else {
      local_13c4 = 0;
      bVar1 = false;
      iVar6 = 9;
      do {
        while (cVar4 != 's') {
          if (cVar4 == 'w') {
            bVar1 = true;
          }
          else if (cVar4 == 'r') {
            bVar1 = false;
          }
          else {
            ppuVar3 = __ctype_b_loc();
            if ((*(byte *)((int)*ppuVar3 + cVar4 * 2 + 1) & 8) != 0) {
              iVar6 = cVar4 + -0x30;
            }
          }
          in_ECX = in_ECX + 1;
          cVar4 = *in_ECX;
          if (cVar4 == '\0') goto LAB_001e18b6;
        }
        local_13c4 = 1;
        in_ECX = in_ECX + 1;
        cVar4 = *in_ECX;
      } while (cVar4 != '\0');
LAB_001e18b6:
      puVar7 = (undefined2 *)&LAB_00256fab;
      bVar2 = false;
      if (bVar1) {
        bVar2 = true;
        puVar7 = &DAT_0026ffa7;
      }
    }
    iVar5 = -1;
    pcVar8 = local_2a;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar4 = *pcVar8;
      pcVar8 = pcVar8 + (uint)bVar9 * -2 + 1;
    } while (cVar4 != '\0');
    *(undefined2 *)((int)&uStack_2c - iVar5) = *puVar7;
    iVar5 = -1;
    pcVar8 = local_2a;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar4 = *pcVar8;
      pcVar8 = pcVar8 + (uint)bVar9 * -2 + 1;
    } while (cVar4 != '\0');
    *(undefined2 *)((int)&uStack_2c - iVar5) = 0x62;
    if (param_1 == 0) {
      if ((in_EAX == (char *)0x0) || (*in_EAX == '\0')) {
        __stream = _stdout;
        if (!bVar2) {
          __stream = _stdin;
        }
      }
      else {
        __stream = fopen64(in_EAX,local_2a);
      }
    }
    else {
      __stream = fdopen(in_EDX,local_2a);
    }
    iVar5 = 0;
    if (__stream != (FILE *)0x0) {
      if (bVar2) {
        if (iVar6 < 1) {
          iVar6 = 1;
        }
        else if (9 < iVar6) {
          iVar6 = 9;
        }
        iVar5 = BZ2_bzWriteOpen(local_2a + 10,__stream,iVar6,0,0x1e);
      }
      else {
        iVar5 = BZ2_bzReadOpen(local_2a + 10,__stream,0,local_13c4,local_13b2,0);
      }
      if (((iVar5 == 0) && (__stream != _stdin)) && (__stream != _stdout)) {
        fclose(__stream);
      }
    }
  }
  return iVar5;
}


