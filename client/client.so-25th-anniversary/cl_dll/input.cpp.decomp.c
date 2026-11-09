// Ghidra decompilation of functions from cl_dll/input.cpp
// 69 functions, ordered by original source line

// KB_ConvertString  @ 00073d70  (line 134)

int KB_ConvertString(char *in,char **ppout)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  char *pcVar6;
  char cVar7;
  uint *puVar8;
  char *pcVar9;
  uint *puVar10;
  uint *puVar11;
  int in_GS_OFFSET;
  byte bVar12;
  char local_1060 [64];
  uint local_1020 [1024];
  int local_20;
  
                    /* Unresolved local var: char[4096] sz@[???]
                       Unresolved local var: char[64] binding@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char * pOut@[???]
                       Unresolved local var: char * pEnd@[???]
                       Unresolved local var: char * pBinding@[???] */
  bVar12 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (ppout == (char **)0x0) {
    iVar5 = 0;
  }
  else {
    *ppout = (char *)0x0;
    puVar10 = local_1020;
LAB_00073db2:
    cVar7 = *in;
    puVar8 = puVar10;
    if (cVar7 != '\0') {
      while (pcVar6 = local_1060, cVar7 != '+') {
        in = in + 1;
        puVar10 = (uint *)((int)puVar8 + 1);
        *(char *)puVar8 = cVar7;
        cVar7 = *in;
        puVar8 = puVar10;
        if (cVar7 == '\0') goto LAB_00073dd0;
      }
      while (pcVar9 = pcVar6, (int)pcVar6 - (int)local_1060 < 0x3f) {
        pcVar9 = pcVar6 + 1;
        in = in + 1;
        *pcVar6 = cVar7;
        cVar7 = *in;
        if ((cVar7 == '\0') ||
           ((iVar5 = isalnum((int)cVar7), pcVar6 = pcVar9, pcVar9 != local_1060 && (iVar5 == 0))))
        break;
      }
      *pcVar9 = '\0';
      if ((local_1060[1] == '\0') ||
         (pcVar6 = (*gEngfuncs.Key_LookupBinding)(local_1060 + 1), pcVar6 == (char *)0x0))
      goto LAB_00073e93;
      *(char *)puVar8 = '[';
      puVar10 = (uint *)((int)puVar8 + 1);
      cVar7 = *pcVar6;
      puVar8 = puVar10;
      pcVar9 = pcVar6;
      if (cVar7 != '\0') goto LAB_00073eb0;
      goto LAB_00073ec0;
    }
LAB_00073dd0:
    *(char *)puVar10 = '\0';
    puVar10 = local_1020;
    do {
      puVar8 = puVar10;
      uVar2 = *puVar8 + 0xfefefeff & ~*puVar8;
      uVar3 = uVar2 & 0x80808080;
      puVar10 = puVar8 + 1;
    } while (uVar3 == 0);
    bVar1 = (byte)uVar3;
    if ((uVar2 & 0x8080) == 0) {
      bVar1 = (byte)(uVar3 >> 0x10);
      puVar10 = (uint *)((int)puVar8 + 6);
    }
    iVar5 = (-3 - (uint)CARRY1(bVar1,bVar1)) - (int)local_1020;
    uVar2 = (int)puVar10 + iVar5 + 1;
    puVar4 = malloc(uVar2);
    puVar11 = local_1020;
    puVar8 = puVar4;
    if ((7 < uVar2) && (((uint)puVar4 & 4) != 0)) {
      puVar8 = puVar4 + 1;
      puVar11 = local_1020 + 1;
      uVar2 = (int)puVar10 + iVar5 + -3;
      *puVar4 = local_1020[0];
    }
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(char *)puVar8 = (char)*puVar11;
      puVar11 = (uint *)((int)puVar11 + (uint)bVar12 * -2 + 1);
      puVar8 = (uint *)((int)puVar8 + (uint)bVar12 * -2 + 1);
    }
    *ppout = (char *)puVar4;
    iVar5 = 1;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_00073e93:
  puVar10 = puVar8;
  if (local_1060[0] != '\0') {
    pcVar6 = local_1060;
    pcVar9 = (char *)0x0;
    cVar7 = local_1060[0];
LAB_00073eb0:
    do {
      puVar10 = (uint *)((int)puVar8 + 1);
      pcVar6 = pcVar6 + 1;
      *(char *)puVar8 = cVar7;
      cVar7 = *pcVar6;
      puVar8 = puVar10;
    } while (cVar7 != '\0');
    if (pcVar9 != (char *)0x0) {
LAB_00073ec0:
      *(char *)puVar10 = ']';
      puVar10 = (uint *)((int)puVar10 + 1);
    }
  }
  goto LAB_00073db2;
}


// KB_Find  @ 00073f30  (line 210)

kbutton_s * KB_Find(char *name)

{
  kblist_s *pkVar1;
  int iVar2;
  
  pkVar1 = g_kbkeys;
  while( true ) {
    if (pkVar1 == (kblist_t *)0x0) {
      return (kbutton_s *)0x0;
    }
    iVar2 = strcasecmp(name,pkVar1->name);
    if (iVar2 == 0) break;
    pkVar1 = pkVar1->next;
  }
  return pkVar1->pkey;
}


// KB_Add  @ 00073f80  (line 233)

void KB_Add(char *name,kbutton_t *pkb)

{
  kblist_s *pkVar1;
  kblist_t *pkVar2;
  int iVar3;
  kblist_t *pkVar4;
  
                    /* Unresolved local var: kblist_t * p@[???]
                       Unresolved local var: kbutton_t * kb@[???] */
  pkVar2 = g_kbkeys;
  pkVar1 = g_kbkeys;
                    /* Unresolved local var: kblist_t * p@[???] */
  do {
    if (pkVar1 == (kblist_t *)0x0) {
LAB_00073fd0:
                    /* Unresolved local var: kblist_t * p@[???]
                       Unresolved local var: kbutton_t * kb@[???] */
      pkVar4 = calloc(0x28,1);
      __strcpy_chk(pkVar4->name,name,0x20);
      pkVar4->next = pkVar2;
      g_kbkeys = pkVar4;
      pkVar4->pkey = pkb;
      return;
    }
    iVar3 = strcasecmp(name,pkVar1->name);
    if (iVar3 == 0) {
      if (pkVar1->pkey != (kbutton_t *)0x0) {
        return;
      }
      goto LAB_00073fd0;
    }
    pkVar1 = pkVar1->next;
  } while( true );
}


// KB_Init  @ 00074020  (line 260)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void KB_Init(void)

{
  kblist_t *pkVar1;
  char *__s2;
  int iVar2;
  kblist_s *pkVar3;
  kblist_s *pkVar4;
  char *__s2_00;
  
                    /* Unresolved local var: kblist_t * p@[???]
                       Unresolved local var: kbutton_t * kb@[???] */
  pkVar1 = calloc(0x28,1);
  __s2_00 = pkVar1->name;
                    /* Unresolved local var: kblist_t * p@[???]
                       Unresolved local var: kbutton_t * kb@[???] */
  builtin_strncpy(pkVar1->name,"in_graph",9);
  g_kbkeys = pkVar1;
  pkVar1->pkey = &in_graph;
  pkVar1->next = (kblist_s *)0x0;
  __s2 = __s2_00;
  pkVar4 = pkVar1;
  if (pkVar1 == (kblist_t *)0x0) {
LAB_000740d0:
                    /* Unresolved local var: kblist_t * p@[???]
                       Unresolved local var: kbutton_t * kb@[???] */
    pkVar3 = calloc(0x28,1);
    builtin_strncpy(pkVar3->name,"in_mlook",9);
    __s2_00 = pkVar3->name;
    pkVar3->pkey = &in_mlook;
    pkVar3->next = pkVar1;
    g_kbkeys = pkVar3;
    pkVar1 = pkVar3;
    if (pkVar3 == (kblist_t *)0x0) {
      pkVar1 = (kblist_t *)0x0;
      goto LAB_00074112;
    }
  }
  else {
    while (iVar2 = strcasecmp("in_mlook",__s2), iVar2 != 0) {
      pkVar4 = pkVar4->next;
      if (pkVar4 == (kblist_s *)0x0) goto LAB_000740d0;
      __s2 = pkVar4->name;
    }
    pkVar3 = pkVar1;
    if (pkVar4->pkey == (kbutton_t *)0x0) goto LAB_000740d0;
  }
  while (iVar2 = strcasecmp("in_jlook",__s2_00), iVar2 != 0) {
    pkVar3 = pkVar3->next;
    if (pkVar3 == (kblist_s *)0x0) goto LAB_00074112;
    __s2_00 = pkVar3->name;
  }
  if (pkVar3->pkey != (kbutton_t *)0x0) {
    return;
  }
LAB_00074112:
                    /* Unresolved local var: kblist_t * p@[DW_OP_reg0(EAX)]
                       Unresolved local var: kbutton_t * kb@[???] */
  g_kbkeys = calloc(0x28,1);
  builtin_strncpy(g_kbkeys->name,"in_jlook",9);
  g_kbkeys->pkey = &in_jlook;
  g_kbkeys->next = pkVar1;
  return;
}


// KB_Shutdown  @ 00074150  (line 278)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void KB_Shutdown(void)

{
  kblist_s *pkVar1;
  kblist_s *__ptr;
  
                    /* Unresolved local var: kblist_t * p@[???]
                       Unresolved local var: kblist_t * n@[???] */
  __ptr = g_kbkeys;
  if (g_kbkeys == (kblist_t *)0x0) {
    g_kbkeys = (kblist_t *)0x0;
    return;
  }
  do {
    pkVar1 = __ptr->next;
    free(__ptr);
    __ptr = pkVar1;
  } while (pkVar1 != (kblist_s *)0x0);
  g_kbkeys = (kblist_t *)0x0;
  return;
}


// KeyDown  @ 00074190  (line 294)

void KeyDown(kbutton_t *b)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  iVar1 = b->down[0];
  if ((iVar3 != iVar1) && (iVar2 = b->down[1], iVar3 != iVar2)) {
    if (iVar1 == 0) {
      b->down[0] = iVar3;
    }
    else {
      if (iVar2 != 0) {
        (*gEngfuncs.Con_DPrintf)
                  ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",iVar1,iVar2,__nptr);
        return;
      }
      b->down[1] = iVar3;
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((b->state & 1U) == 0) {
      b->state = b->state | 3;
    }
  }
  return;
}


// KeyUp  @ 00074240  (line 328)

void KeyUp(kbutton_t *b)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    b->down[1] = 0;
    b->down[0] = 0;
    b->state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    iVar1 = b->down[0];
    if (iVar1 == lVar2) {
      iVar1 = b->down[1];
      b->down[0] = 0;
    }
    else {
      if (b->down[1] != lVar2) {
        return;
      }
      b->down[1] = 0;
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((b->state & 1U) != 0)) {
      b->state = b->state & 0xfffffffeU | 4;
    }
  }
  return;
}


// HUD_Key_Event  @ 000742d0  (line 372)

int HUD_Key_Event(int down,int keynum,char *pszCurrentBinding)

{
  int iVar1;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::KeyInput(gViewPort,down,keynum,pszCurrentBinding);
    return iVar1;
  }
  return 1;
}


// IN_BreakDown  @ 00072fc0  (line 378)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_BreakDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_break.down[0] != iVar3) && (iVar3 != in_break.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_break.down[1];
    if ((in_break.down[0] == 0) || (iVar1 = in_break.down[0], iVar2 = iVar3, in_break.down[1] == 0))
    {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_break.down[1] = iVar2;
      in_break.down[0] = iVar1;
      if ((in_break.state & 1U) == 0) {
        in_break.state = in_break.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_break.down[0],
                 in_break.down[1],__nptr);
    }
  }
  return;
}


// IN_BreakUp  @ 00072630  (line 379)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_BreakUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_break.down[1] = 0;
    in_break.down[0] = 0;
    in_break.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_break.down[0]) {
      in_break.down[0] = 0;
      iVar1 = in_break.down[1];
    }
    else {
      if (lVar2 != in_break.down[1]) {
        return;
      }
      in_break.down[1] = 0;
      iVar1 = in_break.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_break.state & 1U) != 0)) {
      in_break.state = in_break.state & 0xfffffffeU | 4;
    }
  }
  return;
}


// IN_KLookDown  @ 000732e0  (line 380)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_KLookDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_klook.down[0] != iVar3) && (iVar3 != in_klook.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_klook.down[1];
    if ((in_klook.down[0] == 0) || (iVar1 = in_klook.down[0], iVar2 = iVar3, in_klook.down[1] == 0))
    {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_klook.down[1] = iVar2;
      in_klook.down[0] = iVar1;
      if ((in_klook.state & 1U) == 0) {
        in_klook.state = in_klook.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_klook.down[0],
                 in_klook.down[1],__nptr);
    }
  }
  return;
}


// IN_KLookUp  @ 00071eb0  (line 381)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_KLookUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_klook.down[1] = 0;
    in_klook.down[0] = 0;
    in_klook.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_klook.down[0]) {
      in_klook.down[0] = 0;
      iVar1 = in_klook.down[1];
    }
    else {
      if (lVar2 != in_klook.down[1]) {
        return;
      }
      in_klook.down[1] = 0;
      iVar1 = in_klook.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_klook.state & 1U) != 0)) {
      in_klook.state = in_klook.state & 0xfffffffeU | 4;
    }
  }
  return;
}


// IN_JLookDown  @ 00073380  (line 382)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_JLookDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_jlook.down[0] != iVar3) && (iVar3 != in_jlook.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_jlook.down[1];
    if ((in_jlook.down[0] == 0) || (iVar1 = in_jlook.down[0], iVar2 = iVar3, in_jlook.down[1] == 0))
    {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_jlook.down[1] = iVar2;
      in_jlook.down[0] = iVar1;
      if ((in_jlook.state & 1U) == 0) {
        in_jlook.state = in_jlook.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_jlook.down[0],
                 in_jlook.down[1],__nptr);
    }
  }
  return;
}


// IN_JLookUp  @ 00071f50  (line 383)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_JLookUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_jlook.down[1] = 0;
    in_jlook.down[0] = 0;
    in_jlook.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_jlook.down[0]) {
      in_jlook.down[0] = 0;
      iVar1 = in_jlook.down[1];
    }
    else {
      if (lVar2 != in_jlook.down[1]) {
        return;
      }
      in_jlook.down[1] = 0;
      iVar1 = in_jlook.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_jlook.state & 1U) != 0)) {
      in_jlook.state = in_jlook.state & 0xfffffffeU | 4;
    }
  }
  return;
}


// IN_MLookDown  @ 00073560  (line 384)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_MLookDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_mlook.down[0] != iVar3) && (iVar3 != in_mlook.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_mlook.down[1];
    if ((in_mlook.down[0] == 0) || (iVar1 = in_mlook.down[0], iVar2 = iVar3, in_mlook.down[1] == 0))
    {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_mlook.down[1] = iVar2;
      in_mlook.down[0] = iVar1;
      if ((in_mlook.state & 1U) == 0) {
        in_mlook.state = in_mlook.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_mlook.down[0],
                 in_mlook.down[1],__nptr);
    }
  }
  return;
}


// IN_UpDown  @ 00073060  (line 385)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_UpDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_up.down[0] != iVar3) && (iVar3 != in_up.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_up.down[1];
    if ((in_up.down[0] == 0) || (iVar1 = in_up.down[0], iVar2 = iVar3, in_up.down[1] == 0)) {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_up.down[1] = iVar2;
      in_up.down[0] = iVar1;
      if ((in_up.state & 1U) == 0) {
        in_up.state = in_up.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_up.down[0],in_up.down[1],
                 __nptr);
    }
  }
  return;
}


// IN_UpUp  @ 00071e10  (line 386)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_UpUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_up.down[1] = 0;
    in_up.down[0] = 0;
    in_up.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_up.down[0]) {
      in_up.down[0] = 0;
      iVar1 = in_up.down[1];
    }
    else {
      if (lVar2 != in_up.down[1]) {
        return;
      }
      in_up.down[1] = 0;
      iVar1 = in_up.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_up.state & 1U) != 0)) {
      in_up.state = in_up.state & 0xfffffffeU | 4;
    }
  }
  return;
}


// IN_DownDown  @ 000734c0  (line 387)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_DownDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_down.down[0] != iVar3) && (iVar3 != in_down.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_down.down[1];
    if ((in_down.down[0] == 0) || (iVar1 = in_down.down[0], iVar2 = iVar3, in_down.down[1] == 0)) {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_down.down[1] = iVar2;
      in_down.down[0] = iVar1;
      if ((in_down.state & 1U) == 0) {
        in_down.state = in_down.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_down.down[0],
                 in_down.down[1],__nptr);
    }
  }
  return;
}


// IN_DownUp  @ 00071ff0  (line 388)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_DownUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_down.down[1] = 0;
    in_down.down[0] = 0;
    in_down.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_down.down[0]) {
      in_down.down[0] = 0;
      iVar1 = in_down.down[1];
    }
    else {
      if (lVar2 != in_down.down[1]) {
        return;
      }
      in_down.down[1] = 0;
      iVar1 = in_down.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_down.state & 1U) != 0)) {
      in_down.state = in_down.state & 0xfffffffeU | 4;
    }
  }
  return;
}


// IN_LeftDown  @ 00073240  (line 389)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_LeftDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_left.down[0] != iVar3) && (iVar3 != in_left.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_left.down[1];
    if ((in_left.down[0] == 0) || (iVar1 = in_left.down[0], iVar2 = iVar3, in_left.down[1] == 0)) {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_left.down[1] = iVar2;
      in_left.down[0] = iVar1;
      if ((in_left.state & 1U) == 0) {
        in_left.state = in_left.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_left.down[0],
                 in_left.down[1],__nptr);
    }
  }
  return;
}


// IN_LeftUp  @ 00072130  (line 390)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_LeftUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_left.down[1] = 0;
    in_left.down[0] = 0;
    in_left.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_left.down[0]) {
      in_left.down[0] = 0;
      iVar1 = in_left.down[1];
    }
    else {
      if (lVar2 != in_left.down[1]) {
        return;
      }
      in_left.down[1] = 0;
      iVar1 = in_left.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_left.state & 1U) != 0)) {
      in_left.state = in_left.state & 0xfffffffeU | 4;
    }
  }
  return;
}


// IN_RightDown  @ 00072d40  (line 391)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_RightDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_right.down[0] != iVar3) && (iVar3 != in_right.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_right.down[1];
    if ((in_right.down[0] == 0) || (iVar1 = in_right.down[0], iVar2 = iVar3, in_right.down[1] == 0))
    {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_right.down[1] = iVar2;
      in_right.down[0] = iVar1;
      if ((in_right.state & 1U) == 0) {
        in_right.state = in_right.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_right.down[0],
                 in_right.down[1],__nptr);
    }
  }
  return;
}


// IN_RightUp  @ 00072270  (line 392)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_RightUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_right.down[1] = 0;
    in_right.down[0] = 0;
    in_right.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_right.down[0]) {
      in_right.down[0] = 0;
      iVar1 = in_right.down[1];
    }
    else {
      if (lVar2 != in_right.down[1]) {
        return;
      }
      in_right.down[1] = 0;
      iVar1 = in_right.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_right.state & 1U) != 0)) {
      in_right.state = in_right.state & 0xfffffffeU | 4;
    }
  }
  return;
}


// IN_ForwardDown  @ 000736c0  (line 395)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ForwardDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_forward.down[0] != iVar3) && (iVar3 != in_forward.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_forward.down[1];
    if ((in_forward.down[0] == 0) ||
       (iVar1 = in_forward.down[0], iVar2 = iVar3, in_forward.down[1] == 0)) {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_forward.down[1] = iVar2;
      in_forward.down[0] = iVar1;
      if ((in_forward.state & 1U) == 0) {
        in_forward.state = in_forward.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_forward.down[0],
                 in_forward.down[1],__nptr);
    }
  }
  CHudSpectator::HandleButtonsDown(&gHUD.m_Spectator,8);
  return;
}


// IN_ForwardUp  @ 000729a0  (line 401)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ForwardUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_forward.down[1] = 0;
    in_forward.down[0] = 0;
    in_forward.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_forward.down[0]) {
      in_forward.down[0] = 0;
      iVar1 = in_forward.down[1];
    }
    else {
      if (lVar2 != in_forward.down[1]) goto LAB_000729cd;
      in_forward.down[1] = 0;
      iVar1 = in_forward.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_forward.state & 1U) != 0)) {
      in_forward.state = in_forward.state & 0xfffffffeU | 4;
    }
  }
LAB_000729cd:
  CHudSpectator::HandleButtonsUp(&gHUD.m_Spectator,8);
  return;
}


// IN_BackDown  @ 00073840  (line 407)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_BackDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_back.down[0] != iVar3) && (iVar3 != in_back.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_back.down[1];
    if ((in_back.down[0] == 0) || (iVar1 = in_back.down[0], iVar2 = iVar3, in_back.down[1] == 0)) {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_back.down[1] = iVar2;
      in_back.down[0] = iVar1;
      if ((in_back.state & 1U) == 0) {
        in_back.state = in_back.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_back.down[0],
                 in_back.down[1],__nptr);
    }
  }
  CHudSpectator::HandleButtonsDown(&gHUD.m_Spectator,0x10);
  return;
}


// IN_BackUp  @ 00072a60  (line 413)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_BackUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_back.down[1] = 0;
    in_back.down[0] = 0;
    in_back.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_back.down[0]) {
      in_back.down[0] = 0;
      iVar1 = in_back.down[1];
    }
    else {
      if (lVar2 != in_back.down[1]) goto LAB_00072a8d;
      in_back.down[1] = 0;
      iVar1 = in_back.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_back.state & 1U) != 0)) {
      in_back.state = in_back.state & 0xfffffffeU | 4;
    }
  }
LAB_00072a8d:
  CHudSpectator::HandleButtonsUp(&gHUD.m_Spectator,0x10);
  return;
}


// IN_LookupDown  @ 00072e80  (line 417)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_LookupDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_lookup.down[0] != iVar3) && (iVar3 != in_lookup.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_lookup.down[1];
    if ((in_lookup.down[0] == 0) ||
       (iVar1 = in_lookup.down[0], iVar2 = iVar3, in_lookup.down[1] == 0)) {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_lookup.down[1] = iVar2;
      in_lookup.down[0] = iVar1;
      if ((in_lookup.state & 1U) == 0) {
        in_lookup.state = in_lookup.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_lookup.down[0],
                 in_lookup.down[1],__nptr);
    }
  }
  return;
}


// IN_LookupUp  @ 00072450  (line 418)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_LookupUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_lookup.down[1] = 0;
    in_lookup.down[0] = 0;
    in_lookup.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_lookup.down[0]) {
      in_lookup.down[0] = 0;
      iVar1 = in_lookup.down[1];
    }
    else {
      if (lVar2 != in_lookup.down[1]) {
        return;
      }
      in_lookup.down[1] = 0;
      iVar1 = in_lookup.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_lookup.state & 1U) != 0)) {
      in_lookup.state = in_lookup.state & 0xfffffffeU | 4;
    }
  }
  return;
}


// IN_LookdownDown  @ 00072de0  (line 419)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_LookdownDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_lookdown.down[0] != iVar3) && (iVar3 != in_lookdown.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_lookdown.down[1];
    if ((in_lookdown.down[0] == 0) ||
       (iVar1 = in_lookdown.down[0], iVar2 = iVar3, in_lookdown.down[1] == 0)) {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_lookdown.down[1] = iVar2;
      in_lookdown.down[0] = iVar1;
      if ((in_lookdown.state & 1U) == 0) {
        in_lookdown.state = in_lookdown.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_lookdown.down[0],
                 in_lookdown.down[1],__nptr);
    }
  }
  return;
}


// IN_LookdownUp  @ 000724f0  (line 420)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_LookdownUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_lookdown.down[1] = 0;
    in_lookdown.down[0] = 0;
    in_lookdown.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_lookdown.down[0]) {
      in_lookdown.down[0] = 0;
      iVar1 = in_lookdown.down[1];
    }
    else {
      if (lVar2 != in_lookdown.down[1]) {
        return;
      }
      in_lookdown.down[1] = 0;
      iVar1 = in_lookdown.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_lookdown.state & 1U) != 0)) {
      in_lookdown.state = in_lookdown.state & 0xfffffffeU | 4;
    }
  }
  return;
}


// IN_MoveleftDown  @ 000739c0  (line 422)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_MoveleftDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_moveleft.down[0] != iVar3) && (iVar3 != in_moveleft.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_moveleft.down[1];
    if ((in_moveleft.down[0] == 0) ||
       (iVar1 = in_moveleft.down[0], iVar2 = iVar3, in_moveleft.down[1] == 0)) {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_moveleft.down[1] = iVar2;
      in_moveleft.down[0] = iVar1;
      if ((in_moveleft.state & 1U) == 0) {
        in_moveleft.state = in_moveleft.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_moveleft.down[0],
                 in_moveleft.down[1],__nptr);
    }
  }
  CHudSpectator::HandleButtonsDown(&gHUD.m_Spectator,0x200);
  return;
}


// IN_MoveleftUp  @ 00072820  (line 428)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_MoveleftUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_moveleft.down[1] = 0;
    in_moveleft.down[0] = 0;
    in_moveleft.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_moveleft.down[0]) {
      in_moveleft.down[0] = 0;
      iVar1 = in_moveleft.down[1];
    }
    else {
      if (lVar2 != in_moveleft.down[1]) goto LAB_0007284d;
      in_moveleft.down[1] = 0;
      iVar1 = in_moveleft.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_moveleft.state & 1U) != 0)) {
      in_moveleft.state = in_moveleft.state & 0xfffffffeU | 4;
    }
  }
LAB_0007284d:
  CHudSpectator::HandleButtonsUp(&gHUD.m_Spectator,0x200);
  return;
}


// IN_MoverightDown  @ 00073780  (line 434)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_MoverightDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_moveright.down[0] != iVar3) && (iVar3 != in_moveright.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_moveright.down[1];
    if ((in_moveright.down[0] == 0) ||
       (iVar1 = in_moveright.down[0], iVar2 = iVar3, in_moveright.down[1] == 0)) {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_moveright.down[1] = iVar2;
      in_moveright.down[0] = iVar1;
      if ((in_moveright.state & 1U) == 0) {
        in_moveright.state = in_moveright.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_moveright.down[0],
                 in_moveright.down[1],__nptr);
    }
  }
  CHudSpectator::HandleButtonsDown(&gHUD.m_Spectator,0x400);
  return;
}


// IN_MoverightUp  @ 000728e0  (line 440)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_MoverightUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_moveright.down[1] = 0;
    in_moveright.down[0] = 0;
    in_moveright.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_moveright.down[0]) {
      in_moveright.down[0] = 0;
      iVar1 = in_moveright.down[1];
    }
    else {
      if (lVar2 != in_moveright.down[1]) goto LAB_0007290d;
      in_moveright.down[1] = 0;
      iVar1 = in_moveright.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_moveright.state & 1U) != 0)) {
      in_moveright.state = in_moveright.state & 0xfffffffeU | 4;
    }
  }
LAB_0007290d:
  CHudSpectator::HandleButtonsUp(&gHUD.m_Spectator,0x400);
  return;
}


// IN_SpeedDown  @ 00072ca0  (line 444)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_SpeedDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_speed.down[0] != iVar3) && (iVar3 != in_speed.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_speed.down[1];
    if ((in_speed.down[0] == 0) || (iVar1 = in_speed.down[0], iVar2 = iVar3, in_speed.down[1] == 0))
    {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_speed.down[1] = iVar2;
      in_speed.down[0] = iVar1;
      if ((in_speed.state & 1U) == 0) {
        in_speed.state = in_speed.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_speed.down[0],
                 in_speed.down[1],__nptr);
    }
  }
  return;
}


// IN_SpeedUp  @ 00072590  (line 445)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_SpeedUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_speed.down[1] = 0;
    in_speed.down[0] = 0;
    in_speed.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_speed.down[0]) {
      in_speed.down[0] = 0;
      iVar1 = in_speed.down[1];
    }
    else {
      if (lVar2 != in_speed.down[1]) {
        return;
      }
      in_speed.down[1] = 0;
      iVar1 = in_speed.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_speed.state & 1U) != 0)) {
      in_speed.state = in_speed.state & 0xfffffffeU | 4;
    }
  }
  return;
}


// IN_StrafeDown  @ 00073100  (line 446)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_StrafeDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_strafe.down[0] != iVar3) && (iVar3 != in_strafe.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_strafe.down[1];
    if ((in_strafe.down[0] == 0) ||
       (iVar1 = in_strafe.down[0], iVar2 = iVar3, in_strafe.down[1] == 0)) {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_strafe.down[1] = iVar2;
      in_strafe.down[0] = iVar1;
      if ((in_strafe.state & 1U) == 0) {
        in_strafe.state = in_strafe.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_strafe.down[0],
                 in_strafe.down[1],__nptr);
    }
  }
  return;
}


// IN_StrafeUp  @ 00072310  (line 447)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_StrafeUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_strafe.down[1] = 0;
    in_strafe.down[0] = 0;
    in_strafe.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_strafe.down[0]) {
      in_strafe.down[0] = 0;
      iVar1 = in_strafe.down[1];
    }
    else {
      if (lVar2 != in_strafe.down[1]) {
        return;
      }
      in_strafe.down[1] = 0;
      iVar1 = in_strafe.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_strafe.state & 1U) != 0)) {
      in_strafe.state = in_strafe.state & 0xfffffffeU | 4;
    }
  }
  return;
}


// IN_Attack2Down  @ 00073c00  (line 453)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_Attack2Down(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_attack2.down[0] != iVar3) && (iVar3 != in_attack2.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_attack2.down[1];
    if ((in_attack2.down[0] == 0) ||
       (iVar1 = in_attack2.down[0], iVar2 = iVar3, in_attack2.down[1] == 0)) {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_attack2.down[1] = iVar2;
      in_attack2.down[0] = iVar1;
      if ((in_attack2.state & 1U) == 0) {
        in_attack2.state = in_attack2.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_attack2.down[0],
                 in_attack2.down[1],__nptr);
    }
  }
  __CmdFunc_InputPlayerSpecial();
  CHudSpectator::HandleButtonsDown(&gHUD.m_Spectator,0x800);
  return;
}


// IN_Attack2Up  @ 00072090  (line 463)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_Attack2Up(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_attack2.down[1] = 0;
    in_attack2.down[0] = 0;
    in_attack2.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_attack2.down[0]) {
      in_attack2.down[0] = 0;
      iVar1 = in_attack2.down[1];
    }
    else {
      if (lVar2 != in_attack2.down[1]) {
        return;
      }
      in_attack2.down[1] = 0;
      iVar1 = in_attack2.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_attack2.state & 1U) != 0)) {
      in_attack2.state = in_attack2.state & 0xfffffffeU | 4;
    }
  }
  return;
}


// IN_UseDown  @ 00073900  (line 465)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_UseDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_use.down[0] != iVar3) && (iVar3 != in_use.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_use.down[1];
    if ((in_use.down[0] == 0) || (iVar1 = in_use.down[0], iVar2 = iVar3, in_use.down[1] == 0)) {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_use.down[1] = iVar2;
      in_use.down[0] = iVar1;
      if ((in_use.state & 1U) == 0) {
        in_use.state = in_use.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_use.down[0],
                 in_use.down[1],__nptr);
    }
  }
  CHudSpectator::HandleButtonsDown(&gHUD.m_Spectator,0x20);
  return;
}


// IN_UseUp  @ 00071c30  (line 469)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_UseUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_use.down[1] = 0;
    in_use.down[0] = 0;
    in_use.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_use.down[0]) {
      in_use.down[0] = 0;
      iVar1 = in_use.down[1];
    }
    else {
      if (lVar2 != in_use.down[1]) {
        return;
      }
      in_use.down[1] = 0;
      iVar1 = in_use.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_use.state & 1U) != 0)) {
      in_use.state = in_use.state & 0xfffffffeU | 4;
    }
  }
  return;
}


// IN_JumpDown  @ 00073b40  (line 471)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_JumpDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_jump.down[0] != iVar3) && (iVar3 != in_jump.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_jump.down[1];
    if ((in_jump.down[0] == 0) || (iVar1 = in_jump.down[0], iVar2 = iVar3, in_jump.down[1] == 0)) {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_jump.down[1] = iVar2;
      in_jump.down[0] = iVar1;
      if ((in_jump.state & 1U) == 0) {
        in_jump.state = in_jump.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_jump.down[0],
                 in_jump.down[1],__nptr);
    }
  }
  CHudSpectator::HandleButtonsDown(&gHUD.m_Spectator,2);
  return;
}


// IN_JumpUp  @ 000721d0  (line 476)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_JumpUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_jump.down[1] = 0;
    in_jump.down[0] = 0;
    in_jump.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_jump.down[0]) {
      in_jump.down[0] = 0;
      iVar1 = in_jump.down[1];
    }
    else {
      if (lVar2 != in_jump.down[1]) {
        return;
      }
      in_jump.down[1] = 0;
      iVar1 = in_jump.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_jump.state & 1U) != 0)) {
      in_jump.state = in_jump.state & 0xfffffffeU | 4;
    }
  }
  return;
}


// IN_DuckDown  @ 00073600  (line 478)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_DuckDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_duck.down[0] != iVar3) && (iVar3 != in_duck.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_duck.down[1];
    if ((in_duck.down[0] == 0) || (iVar1 = in_duck.down[0], iVar2 = iVar3, in_duck.down[1] == 0)) {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_duck.down[1] = iVar2;
      in_duck.down[0] = iVar1;
      if ((in_duck.state & 1U) == 0) {
        in_duck.state = in_duck.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_duck.down[0],
                 in_duck.down[1],__nptr);
    }
  }
  CHudSpectator::HandleButtonsDown(&gHUD.m_Spectator,4);
  return;
}


// IN_DuckUp  @ 00071cd0  (line 483)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_DuckUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_duck.down[1] = 0;
    in_duck.down[0] = 0;
    in_duck.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_duck.down[0]) {
      in_duck.down[0] = 0;
      iVar1 = in_duck.down[1];
    }
    else {
      if (lVar2 != in_duck.down[1]) {
        return;
      }
      in_duck.down[1] = 0;
      iVar1 = in_duck.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_duck.state & 1U) != 0)) {
      in_duck.state = in_duck.state & 0xfffffffeU | 4;
    }
  }
  return;
}


// IN_ReloadDown  @ 000731a0  (line 484)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ReloadDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_reload.down[0] != iVar3) && (iVar3 != in_reload.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_reload.down[1];
    if ((in_reload.down[0] == 0) ||
       (iVar1 = in_reload.down[0], iVar2 = iVar3, in_reload.down[1] == 0)) {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_reload.down[1] = iVar2;
      in_reload.down[0] = iVar1;
      if ((in_reload.state & 1U) == 0) {
        in_reload.state = in_reload.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_reload.down[0],
                 in_reload.down[1],__nptr);
    }
  }
  return;
}


// IN_ReloadUp  @ 000723b0  (line 485)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ReloadUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_reload.down[1] = 0;
    in_reload.down[0] = 0;
    in_reload.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_reload.down[0]) {
      in_reload.down[0] = 0;
      iVar1 = in_reload.down[1];
    }
    else {
      if (lVar2 != in_reload.down[1]) {
        return;
      }
      in_reload.down[1] = 0;
      iVar1 = in_reload.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_reload.state & 1U) != 0)) {
      in_reload.state = in_reload.state & 0xfffffffeU | 4;
    }
  }
  return;
}


// IN_Alt1Down  @ 00072f20  (line 486)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_Alt1Down(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_alt1.down[0] != iVar3) && (iVar3 != in_alt1.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_alt1.down[1];
    if ((in_alt1.down[0] == 0) || (iVar1 = in_alt1.down[0], iVar2 = iVar3, in_alt1.down[1] == 0)) {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_alt1.down[1] = iVar2;
      in_alt1.down[0] = iVar1;
      if ((in_alt1.state & 1U) == 0) {
        in_alt1.state = in_alt1.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_alt1.down[0],
                 in_alt1.down[1],__nptr);
    }
  }
  return;
}


// IN_Alt1Up  @ 000726d0  (line 487)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_Alt1Up(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_alt1.down[1] = 0;
    in_alt1.down[0] = 0;
    in_alt1.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_alt1.down[0]) {
      in_alt1.down[0] = 0;
      iVar1 = in_alt1.down[1];
    }
    else {
      if (lVar2 != in_alt1.down[1]) {
        return;
      }
      in_alt1.down[1] = 0;
      iVar1 = in_alt1.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_alt1.state & 1U) != 0)) {
      in_alt1.state = in_alt1.state & 0xfffffffeU | 4;
    }
  }
  return;
}


// IN_GraphDown  @ 00073420  (line 488)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_GraphDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_graph.down[0] != iVar3) && (iVar3 != in_graph.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_graph.down[1];
    if ((in_graph.down[0] == 0) || (iVar1 = in_graph.down[0], iVar2 = iVar3, in_graph.down[1] == 0))
    {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_graph.down[1] = iVar2;
      in_graph.down[0] = iVar1;
      if ((in_graph.state & 1U) == 0) {
        in_graph.state = in_graph.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_graph.down[0],
                 in_graph.down[1],__nptr);
    }
  }
  return;
}


// IN_GraphUp  @ 00071d70  (line 489)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_GraphUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_graph.down[1] = 0;
    in_graph.down[0] = 0;
    in_graph.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_graph.down[0]) {
      in_graph.down[0] = 0;
      iVar1 = in_graph.down[1];
    }
    else {
      if (lVar2 != in_graph.down[1]) {
        return;
      }
      in_graph.down[1] = 0;
      iVar1 = in_graph.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_graph.state & 1U) != 0)) {
      in_graph.state = in_graph.state & 0xfffffffeU | 4;
    }
  }
  return;
}


// IN_AttackDown  @ 00073a80  (line 492)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_AttackDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_attack.down[0] != iVar3) && (iVar3 != in_attack.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_attack.down[1];
    if ((in_attack.down[0] == 0) ||
       (iVar1 = in_attack.down[0], iVar2 = iVar3, in_attack.down[1] == 0)) {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_attack.down[1] = iVar2;
      in_attack.down[0] = iVar1;
      if ((in_attack.state & 1U) == 0) {
        in_attack.state = in_attack.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_attack.down[0],
                 in_attack.down[1],__nptr);
    }
  }
  CHudSpectator::HandleButtonsDown(&gHUD.m_Spectator,1);
  return;
}


// IN_AttackUp  @ 00072770  (line 498)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_AttackUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_attack.down[1] = 0;
    in_attack.down[0] = 0;
    in_attack.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_attack.down[0]) {
      in_attack.down[0] = 0;
      iVar1 = in_attack.down[1];
    }
    else {
      if (lVar2 != in_attack.down[1]) {
        in_cancel = 0;
        return;
      }
      in_attack.down[1] = 0;
      iVar1 = in_attack.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_attack.state & 1U) != 0)) {
      in_attack.state = in_attack.state & 0xfffffffeU | 4;
    }
  }
  in_cancel = 0;
  return;
}


// IN_Cancel  @ 00074310  (line 506)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_Cancel(void)

{
  in_cancel = 1;
  return;
}


// IN_Impulse  @ 00071c00  (line 510)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_Impulse(void)

{
  char *__nptr;
  
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  in_impulse = strtol(__nptr,(char **)0x0,10);
  return;
}


// IN_ScoreDown  @ 00073cc0  (line 515)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ScoreDown(void)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  iVar3 = -1;
  if (*__nptr != '\0') {
    iVar3 = strtol(__nptr,(char **)0x0,10);
  }
  if ((in_score.down[0] != iVar3) && (iVar3 != in_score.down[1])) {
    iVar1 = iVar3;
    iVar2 = in_score.down[1];
    if ((in_score.down[0] == 0) || (iVar1 = in_score.down[0], iVar2 = iVar3, in_score.down[1] == 0))
    {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      in_score.down[1] = iVar2;
      in_score.down[0] = iVar1;
      if ((in_score.state & 1U) == 0) {
        in_score.state = in_score.state | 3;
      }
    }
    else {
      (*gEngfuncs.Con_DPrintf)
                ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_score.down[0],
                 in_score.down[1],__nptr);
    }
  }
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::ShowScoreBoard(gViewPort);
  }
  return;
}


// IN_ScoreUp  @ 00072bf0  (line 524)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ScoreUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_score.down[1] = 0;
    in_score.down[0] = 0;
    in_score.state = 4;
  }
  else {
    lVar2 = strtol(__nptr,(char **)0x0,10);
    if (lVar2 == in_score.down[0]) {
      in_score.down[0] = 0;
      iVar1 = in_score.down[1];
    }
    else {
      if (lVar2 != in_score.down[1]) goto LAB_00072c1d;
      in_score.down[1] = 0;
      iVar1 = in_score.down[0];
    }
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
    if ((iVar1 == 0) && ((in_score.state & 1U) != 0)) {
      in_score.state = in_score.state & 0xfffffffeU | 4;
    }
  }
LAB_00072c1d:
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::HideScoreBoard(gViewPort);
  }
  return;
}


// IN_MLookUp  @ 00072b20  (line 533)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_MLookUp(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  if (*__nptr == '\0') {
    in_mlook.down[1] = 0;
    in_mlook.down[0] = 0;
    in_mlook.state = 4;
    goto LAB_00072b4d;
  }
  lVar2 = strtol(__nptr,(char **)0x0,10);
  if (lVar2 == in_mlook.down[0]) {
    in_mlook.down[0] = 0;
    iVar1 = in_mlook.down[1];
joined_r0x00072be8:
    if (iVar1 == 0) {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      if ((in_mlook.state & 1U) == 0) goto LAB_00072b4d;
      in_mlook.state = in_mlook.state & 0xfffffffeU | 4;
    }
  }
  else if (lVar2 == in_mlook.down[1]) {
    in_mlook.down[1] = 0;
    iVar1 = in_mlook.down[0];
    goto joined_r0x00072be8;
  }
  if ((in_mlook.state & 1U) != 0) {
    return;
  }
LAB_00072b4d:
  if (lookspring->value != 0.0) {
    V_StartPitchDrift();
    return;
  }
  return;
}


// CL_KeyState  @ 00074320  (line 552)

float CL_KeyState(kbutton_t *key)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[DW_OP_reg2(EDX)] */
  uVar1 = key->state;
  uVar5 = uVar1 & 1;
  uVar6 = uVar1 & 2;
  uVar4 = uVar1 & 4;
  if ((uVar4 != 0 || uVar6 == 0) || (fVar2 = 0.5, (char)uVar5 == '\0')) {
    fVar2 = 0.0;
  }
  fVar3 = fVar2;
  if ((uVar6 == 0) && (fVar3 = 0.0, uVar4 == 0)) {
    fVar3 = fVar2;
  }
  if (((uVar1 & 6) == 0) && (fVar3 = 0.0, uVar5 != 0)) {
    fVar3 = 1.0;
  }
  if (((uVar6 != 0) && (uVar4 != 0)) && (fVar3 = 0.75, uVar5 == 0)) {
    fVar3 = 0.25;
  }
  key->state = uVar5;
  return fVar3;
}


// CL_AdjustAngles  @ 000743c0  (line 605)

void CL_AdjustAngles(float frametime,float *viewangles)

{
  float fVar1;
  cvar_t *pcVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint uVar7;
  bool bVar8;
  bool bVar9;
  float fVar10;
  bool local_1d;
  
                    /* Unresolved local var: float speed@[???]
                       Unresolved local var: float up@[DW_OP_reg12(ST1)]
                       Unresolved local var: float down@[DW_OP_reg13(ST2)] */
  pcVar2 = cl_yawspeed;
  if (((byte)in_speed.state & 1) != 0) {
    frametime = frametime * cl_anglespeedkey->value;
  }
  if (((byte)in_strafe.state & 1) == 0) {
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[DW_OP_reg7(EDI)]
                       Unresolved local var: int impulseup@[DW_OP_reg0(EAX)]
                       Unresolved local var: int down@[???] */
    uVar5 = in_right.state & 1;
    uVar7 = in_right.state & 2;
    uVar4 = in_right.state & 4;
    if ((uVar4 != 0 || uVar7 == 0) || (fVar10 = 0.5, (char)uVar5 == '\0')) {
      fVar10 = 0.0;
    }
    fVar1 = fVar10;
    if ((uVar7 == 0) && (fVar1 = 0.0, uVar4 == 0)) {
      fVar1 = fVar10;
    }
    if (((in_right.state & 6U) == 0) && (fVar1 = 1.0, uVar5 == 0)) {
      fVar1 = 0.0;
    }
    if (((uVar7 != 0) && (uVar4 != 0)) && (fVar1 = 0.25, uVar5 != 0)) {
      fVar1 = 0.75;
    }
    in_right.state = uVar5;
    viewangles[1] = viewangles[1] - fVar1 * frametime * cl_yawspeed->value;
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
    uVar5 = in_left.state & 1;
    uVar7 = in_left.state & 2;
    uVar4 = in_left.state & 4;
    if ((uVar4 != 0 || uVar7 == 0) || (fVar10 = 0.5, (char)uVar5 == '\0')) {
      fVar10 = 0.0;
    }
    fVar1 = fVar10;
    if ((uVar7 == 0) && (fVar1 = 0.0, uVar4 == 0)) {
      fVar1 = fVar10;
    }
    if (((in_left.state & 6U) == 0) && (fVar1 = 1.0, uVar5 == 0)) {
      fVar1 = 0.0;
    }
    if (((uVar7 != 0) && (uVar4 != 0)) && (fVar1 = 0.25, uVar5 != 0)) {
      fVar1 = 0.75;
    }
    fVar10 = fVar1 * frametime * pcVar2->value + viewangles[1];
    in_left.state = uVar5;
    viewangles[1] = fVar10;
    fVar10 = anglemod(fVar10);
    viewangles[1] = fVar10;
  }
  if (((byte)in_klook.state & 1) != 0) {
    V_StopPitchDrift();
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
    uVar5 = in_forward.state & 1;
    uVar7 = in_forward.state & 2;
    uVar4 = in_forward.state & 4;
    if ((uVar4 != 0 || uVar7 == 0) || (fVar10 = 0.5, (char)uVar5 == '\0')) {
      fVar10 = 0.0;
    }
    fVar1 = fVar10;
    if ((uVar7 == 0) && (fVar1 = 0.0, uVar4 == 0)) {
      fVar1 = fVar10;
    }
    if (((in_forward.state & 6U) == 0) && (fVar1 = 1.0, uVar5 == 0)) {
      fVar1 = 0.0;
    }
    if (((uVar7 != 0) && (uVar4 != 0)) && (fVar1 = 0.25, uVar5 != 0)) {
      fVar1 = 0.75;
    }
    in_forward.state = uVar5;
    *viewangles = *viewangles - fVar1 * frametime * cl_pitchspeed->value;
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
    uVar5 = in_back.state & 1;
    uVar7 = in_back.state & 2;
    uVar4 = in_back.state & 4;
    if ((uVar4 != 0 || uVar7 == 0) || (fVar10 = 0.5, (char)uVar5 == '\0')) {
      fVar10 = 0.0;
    }
    fVar1 = fVar10;
    if ((uVar7 == 0) && (fVar1 = 0.0, uVar4 == 0)) {
      fVar1 = fVar10;
    }
    if (((in_back.state & 6U) == 0) && (fVar1 = 1.0, uVar5 == 0)) {
      fVar1 = 0.0;
    }
    if (((uVar7 != 0) && (uVar4 != 0)) && (fVar1 = 0.25, uVar5 != 0)) {
      fVar1 = 0.75;
    }
    in_back.state = uVar5;
    *viewangles = fVar1 * frametime * cl_pitchspeed->value + *viewangles;
  }
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
  fVar10 = 0.0;
  uVar4 = in_lookup.state & 1;
  bVar8 = (in_lookup.state & 2U) != 0;
  local_1d = (bool)((byte)uVar4 & ((in_lookup.state & 4U) == 0 && bVar8));
  if (local_1d != false) {
    fVar10 = 0.5;
  }
  bVar9 = (in_lookup.state & 4U) != 0;
  if (((in_lookup.state & 2U) == 0) && (bVar9)) {
    local_1d = false;
    fVar10 = 0.0;
  }
  if ((in_lookup.state & 6U) == 0) {
    if (uVar4 == 0) {
      local_1d = false;
      fVar10 = 0.0;
    }
    else {
      local_1d = true;
      fVar10 = 1.0;
    }
  }
  if (bVar8 && bVar9) {
    local_1d = bVar8 && bVar9;
    fVar10 = 0.25;
    if (uVar4 != 0) {
      fVar10 = 0.75;
    }
  }
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
  fVar1 = 0.0;
  uVar5 = in_lookdown.state & 1;
  bVar8 = (in_lookdown.state & 2U) != 0;
  bVar3 = (byte)uVar5 & ((in_lookdown.state & 4U) == 0 && bVar8);
  if (bVar3 != 0) {
    fVar1 = 0.5;
  }
  bVar9 = (in_lookdown.state & 4U) != 0;
  if (((in_lookdown.state & 2U) == 0) && (bVar9)) {
    bVar3 = 0;
    fVar1 = 0.0;
  }
  if ((in_lookdown.state & 6U) == 0) {
    if (uVar5 == 0) {
      fVar1 = 0.25;
      bVar6 = true;
      if (bVar8 && bVar9) goto LAB_000744f8;
      bVar3 = 0;
      fVar1 = 0.0;
    }
    else {
      fVar1 = 0.75;
      bVar6 = true;
      if (bVar8 && bVar9) goto LAB_000744f8;
      bVar3 = 1;
      fVar1 = 1.0;
    }
  }
  else {
    bVar6 = bVar8 && bVar9;
    if (bVar8 && bVar9) {
      fVar1 = 0.25;
      if (uVar5 != 0) {
        fVar1 = 0.75;
      }
      goto LAB_000744f8;
    }
  }
  bVar6 = (bool)(local_1d | bVar3);
LAB_000744f8:
  fVar10 = *viewangles - frametime * cl_pitchspeed->value * fVar10;
  in_lookdown.state = uVar5;
  in_lookup.state = uVar4;
  *viewangles = fVar10;
  fVar10 = fVar10 + frametime * cl_pitchspeed->value * fVar1;
  *viewangles = fVar10;
  if (bVar6 != false) {
    V_StopPitchDrift();
    fVar10 = *viewangles;
  }
  fVar1 = cl_pitchdown->value;
  if (fVar1 < fVar10) {
    *viewangles = fVar1;
    fVar10 = fVar1;
  }
  if (fVar10 < -cl_pitchup->value) {
    *viewangles = -cl_pitchup->value;
  }
  if (viewangles[2] <= 50.0) {
    if (viewangles[2] < -50.0) {
      viewangles[2] = -50.0;
      return;
    }
  }
  else {
    viewangles[2] = 50.0;
  }
  return;
}


// CL_CreateMove  @ 00074af0  (line 661)

void CL_CreateMove(float frametime,usercmd_s *cmd,int active)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  cvar_t *pcVar6;
  cvar_t *pcVar7;
  vec_t vVar8;
  vec_t vVar9;
  bool bVar10;
  int iVar11;
  CVoiceStatus *this;
  uint uVar12;
  usercmd_s *puVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  longdouble extraout_ST0;
  longdouble lVar18;
  longdouble lVar19;
  longdouble lVar20;
  float fVar21;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: float spd@[???]
                       Unresolved local var: Vector viewangles@[???] */
  if ((CL_CreateMove::oldangles == '\0') &&
     (iVar11 = __cxa_guard_acquire(&CL_CreateMove::oldangles), iVar11 != 0)) {
    __cxa_guard_release(&CL_CreateMove::oldangles);
  }
  if ((active != 0) && (iVar11 = Bench_Active(), iVar11 == 0)) {
    (*gEngfuncs.GetViewAngles)(&local_28);
    CL_AdjustAngles(frametime,&local_28);
    bVar10 = ((uint)cmd & 1) != 0;
    uVar12 = 0x34;
    puVar13 = cmd;
    if (bVar10) {
      *(undefined1 *)&cmd->lerp_msec = 0;
      puVar13 = (usercmd_s *)((int)&cmd->lerp_msec + 1);
      uVar12 = 0x33;
    }
    if (((uint)puVar13 & 2) != 0) {
      puVar13->lerp_msec = 0;
      uVar12 = uVar12 - 2;
      puVar13 = (usercmd_s *)&puVar13->msec;
    }
    uVar15 = 0;
    do {
      uVar16 = uVar15;
      *(undefined4 *)((int)&puVar13->lerp_msec + uVar16) = 0;
      *(undefined4 *)((int)&(puVar13->viewangles).x + uVar16) = 0;
      uVar15 = uVar16 + 8;
    } while (uVar16 + 8 < (uVar12 & 0xfffffff8));
    puVar14 = (undefined4 *)((int)&(puVar13->viewangles).y + uVar16);
    if ((uVar12 & 4) != 0) {
      *puVar14 = 0;
      puVar14 = puVar14 + 1;
    }
    if ((uVar12 & 2) != 0) {
      *(undefined2 *)puVar14 = 0;
      puVar14 = (undefined4 *)((int)puVar14 + 2);
    }
    if (bVar10) {
      *(undefined1 *)puVar14 = 0;
    }
    (*gEngfuncs.SetViewAngles)(&local_28);
    pcVar6 = cl_sidespeed;
    if (((byte)in_strafe.state & 1) == 0) {
      fVar21 = cmd->sidemove;
    }
    else {
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
      uVar12 = in_right.state & 1;
      uVar16 = in_right.state & 2;
      uVar15 = in_right.state & 4;
      if ((uVar16 == 0 || uVar15 != 0) || (fVar21 = 0.5, (char)uVar12 == '\0')) {
        fVar21 = 0.0;
      }
      fVar3 = fVar21;
      if ((uVar16 == 0) && (fVar3 = 0.0, uVar15 == 0)) {
        fVar3 = fVar21;
      }
      if (((in_right.state & 6U) == 0) && (fVar3 = 1.0, uVar12 == 0)) {
        fVar3 = 0.0;
      }
      if (((uVar16 != 0) && (uVar15 != 0)) && (fVar3 = 0.25, uVar12 != 0)) {
        fVar3 = 0.75;
      }
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[DW_OP_reg6(ESI)]
                       Unresolved local var: int impulseup@[DW_OP_reg2(EDX)]
                       Unresolved local var: int down@[???] */
      uVar15 = in_left.state & 1;
      uVar17 = in_left.state & 2;
      uVar16 = in_left.state & 4;
      fVar21 = cmd->sidemove + fVar3 * cl_sidespeed->value;
      in_right.state = uVar12;
      cmd->sidemove = fVar21;
      if ((uVar17 == 0 || uVar16 != 0) || (fVar3 = 0.5, (char)uVar15 == '\0')) {
        fVar3 = 0.0;
      }
      fVar2 = fVar3;
      if ((uVar17 == 0) && (fVar2 = 0.0, uVar16 == 0)) {
        fVar2 = fVar3;
      }
      if (((in_left.state & 6U) == 0) && (fVar2 = 1.0, uVar15 == 0)) {
        fVar2 = 0.0;
      }
      if (((uVar17 != 0) && (uVar16 != 0)) && (fVar2 = 0.25, uVar15 != 0)) {
        fVar2 = 0.75;
      }
      fVar21 = fVar21 - fVar2 * pcVar6->value;
      in_left.state = uVar15;
      cmd->sidemove = fVar21;
    }
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
    uVar12 = in_moveright.state & 1;
    uVar15 = in_moveright.state & 2;
    uVar16 = in_moveright.state & 4;
    if ((uVar16 != 0 || uVar15 == 0) || (fVar3 = 0.5, (char)uVar12 == '\0')) {
      fVar3 = 0.0;
    }
    fVar2 = fVar3;
    if ((uVar15 == 0) && (fVar2 = 0.0, uVar16 == 0)) {
      fVar2 = fVar3;
    }
    if ((uVar15 == 0 && uVar16 == 0) && (fVar2 = 1.0, uVar12 == 0)) {
      fVar2 = 0.0;
    }
    if (((uVar15 != 0) && (uVar16 != 0)) && (fVar2 = 0.25, uVar12 != 0)) {
      fVar2 = 0.75;
    }
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
    uVar15 = in_moveleft.state & 1;
    fVar21 = fVar2 * pcVar6->value + fVar21;
    in_moveright.state = uVar12;
    cmd->sidemove = fVar21;
    pcVar7 = cl_upspeed;
    uVar16 = in_moveleft.state & 2;
    uVar12 = in_moveleft.state & 4;
    if ((uVar12 != 0 || uVar16 == 0) || (fVar3 = 0.5, (char)uVar15 == '\0')) {
      fVar3 = 0.0;
    }
    fVar2 = fVar3;
    if ((uVar16 == 0) && (fVar2 = 0.0, uVar12 == 0)) {
      fVar2 = fVar3;
    }
    if (((in_moveleft.state & 6U) == 0) && (fVar2 = 1.0, uVar15 == 0)) {
      fVar2 = 0.0;
    }
    if (((uVar16 != 0) && (uVar12 != 0)) && (fVar2 = 0.25, uVar15 != 0)) {
      fVar2 = 0.75;
    }
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[DW_OP_reg7(EDI)]
                       Unresolved local var: int impulseup@[DW_OP_reg0(EAX)]
                       Unresolved local var: int down@[???] */
    uVar16 = in_up.state & 1;
    uVar17 = in_up.state & 2;
    uVar12 = in_up.state & 4;
    fVar21 = fVar21 - fVar2 * pcVar6->value;
    in_moveleft.state = uVar15;
    cmd->sidemove = fVar21;
    if ((uVar17 == 0 || uVar12 != 0) || (fVar3 = 0.5, (char)uVar16 == '\0')) {
      fVar3 = 0.0;
    }
    fVar2 = fVar3;
    if ((uVar17 == 0) && (fVar2 = 0.0, uVar12 == 0)) {
      fVar2 = fVar3;
    }
    if (((in_up.state & 6U) == 0) && (fVar2 = 1.0, uVar16 == 0)) {
      fVar2 = 0.0;
    }
    if (((uVar17 != 0) && (uVar12 != 0)) && (fVar2 = 0.25, uVar16 != 0)) {
      fVar2 = 0.75;
    }
    fVar3 = fVar2 * pcVar7->value + cmd->upmove;
    in_up.state = uVar16;
    cmd->upmove = fVar3;
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
    uVar12 = in_down.state & 1;
    uVar16 = in_down.state & 2;
    uVar15 = in_down.state & 4;
    if ((uVar15 != 0 || uVar16 == 0) || (fVar2 = 0.5, (char)uVar12 == '\0')) {
      fVar2 = 0.0;
    }
    fVar4 = fVar2;
    if ((uVar16 == 0) && (fVar4 = 0.0, uVar15 == 0)) {
      fVar4 = fVar2;
    }
    if (((in_down.state & 6U) == 0) && (fVar4 = 1.0, uVar12 == 0)) {
      fVar4 = 0.0;
    }
    if (((uVar16 != 0) && (uVar15 != 0)) && (fVar4 = 0.25, uVar12 != 0)) {
      fVar4 = 0.75;
    }
    bVar1 = (byte)in_klook.state & 1;
    fVar3 = fVar3 - fVar4 * pcVar7->value;
    in_down.state = uVar12;
    cmd->upmove = fVar3;
    pcVar6 = cl_backspeed;
    if (bVar1 == 0) {
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
      uVar12 = in_forward.state & 1;
      uVar16 = in_forward.state & 2;
      uVar15 = in_forward.state & 4;
      if ((uVar15 != 0 || uVar16 == 0) || (fVar2 = 0.5, (char)uVar12 == '\0')) {
        fVar2 = 0.0;
      }
      fVar4 = fVar2;
      if ((uVar16 == 0) && (fVar4 = 0.0, uVar15 == 0)) {
        fVar4 = fVar2;
      }
      if (((in_forward.state & 6U) == 0) && (fVar4 = 1.0, uVar12 == 0)) {
        fVar4 = 0.0;
      }
      if (((uVar16 != 0) && (uVar15 != 0)) && (fVar4 = 0.25, uVar12 != 0)) {
        fVar4 = 0.75;
      }
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
      fVar2 = fVar4 * cl_forwardspeed->value + cmd->forwardmove;
      in_forward.state = uVar12;
      cmd->forwardmove = fVar2;
      uVar12 = in_back.state & 1;
      uVar16 = in_back.state & 2;
      uVar15 = in_back.state & 4;
      if ((uVar15 != 0 || uVar16 == 0) || (fVar4 = 0.5, (char)uVar12 == '\0')) {
        fVar4 = 0.0;
      }
      fVar5 = fVar4;
      if ((uVar16 == 0) && (fVar5 = 0.0, uVar15 == 0)) {
        fVar5 = fVar4;
      }
      if (((in_back.state & 6U) == 0) && (fVar5 = 1.0, uVar12 == 0)) {
        fVar5 = 0.0;
      }
      if (((uVar16 != 0) && (uVar15 != 0)) && (fVar5 = 0.25, uVar12 != 0)) {
        fVar5 = 0.75;
      }
      in_back.state = uVar12;
      cmd->forwardmove = fVar2 - fVar5 * pcVar6->value;
    }
    pcVar6 = cl_movespeedkey;
    if (((byte)in_speed.state & 1) != 0) {
      cmd->forwardmove = cmd->forwardmove * cl_movespeedkey->value;
      cmd->sidemove = fVar21 * pcVar6->value;
      cmd->upmove = fVar3 * pcVar6->value;
    }
    (*gEngfuncs.GetClientMaxspeed)();
    if (extraout_ST0 != (longdouble)0) {
                    /* Unresolved local var: float fmov@[???] */
      lVar19 = (longdouble)cmd->upmove * (longdouble)cmd->upmove +
               (longdouble)cmd->sidemove * (longdouble)cmd->sidemove +
               (longdouble)cmd->forwardmove * (longdouble)cmd->forwardmove;
      lVar18 = SQRT(lVar19);
      lVar20 = extraout_ST0;
      if (NAN(lVar18)) {
        fVar21 = sqrtf((float)lVar19);
        lVar18 = (longdouble)fVar21;
        lVar20 = (longdouble)(float)extraout_ST0;
      }
      if (lVar20 < lVar18) {
                    /* Unresolved local var: float fratio@[???] */
        lVar20 = lVar20 / lVar18;
        cmd->forwardmove = (float)((longdouble)cmd->forwardmove * lVar20);
        cmd->sidemove = (float)((longdouble)cmd->sidemove * lVar20);
        cmd->upmove = (float)(lVar20 * (longdouble)cmd->upmove);
      }
    }
    IN_Move(frametime,cmd);
  }
  cmd->impulse = (byte)in_impulse;
  in_impulse = 0;
  cmd->weaponselect = (byte)g_weaponselect;
  g_weaponselect = 0;
  iVar11 = CL_ButtonBits(1);
  cmd->buttons = (ushort)iVar11;
  this = GetClientVoiceMgr();
  bVar10 = CVoiceStatus::IsInSquelchMode(this);
  if (bVar10) {
    cmd->buttons = cmd->buttons & 0xfffe;
  }
  if (in_joystick->value != 0.0) {
    if (cmd->forwardmove <= 0.0) {
      if (cmd->forwardmove < 0.0) {
        cmd->buttons = cmd->buttons | 0x10;
      }
    }
    else {
      cmd->buttons = cmd->buttons | 8;
    }
  }
  (*gEngfuncs.GetViewAngles)(&local_28);
  vVar9 = CL_CreateMove::oldangles.z;
  vVar8 = CL_CreateMove::oldangles.y;
  if (g_iAlive == 0) {
    (cmd->viewangles).x = CL_CreateMove::oldangles.x;
    (cmd->viewangles).y = vVar8;
    (cmd->viewangles).z = vVar9;
  }
  else {
    CL_CreateMove::oldangles.x = local_28;
    (cmd->viewangles).x = local_28;
    CL_CreateMove::oldangles.y = local_24;
    (cmd->viewangles).y = local_24;
    CL_CreateMove::oldangles.z = local_20;
    (cmd->viewangles).z = local_20;
  }
  Bench_SetViewAngles(1,&(cmd->viewangles).x,frametime,cmd);
  return;
}


// CL_IsDead  @ 000748b0  (line 778)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_IsDead(void)

{
  return (uint)(gHUD.m_Health.m_iHealth < 1);
}


// CL_ButtonBits  @ 000748c0  (line 790)

int CL_ButtonBits(int bResetState)

{
  uint uVar1;
  
                    /* Unresolved local var: int bits@[???] */
  uVar1 = (uint)((in_attack.state & 3U) != 0);
  if ((in_duck.state & 3U) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((in_jump.state & 3U) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((in_forward.state & 3U) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((in_back.state & 3U) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  if ((in_use.state & 3U) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  if (in_cancel != 0) {
    uVar1 = uVar1 | 0x40;
  }
  if ((in_left.state & 3U) != 0) {
    uVar1 = uVar1 | 0x80;
  }
  if ((in_right.state & 3U) != 0) {
    uVar1 = uVar1 | 0x100;
  }
  if ((in_moveleft.state & 3U) != 0) {
    uVar1 = uVar1 | 0x200;
  }
  if ((in_moveright.state & 3U) != 0) {
    uVar1 = uVar1 | 0x400;
  }
  if ((in_attack2.state & 3U) != 0) {
    uVar1 = uVar1 | 0x800;
  }
  if ((in_reload.state & 3U) != 0) {
    uVar1 = uVar1 | 0x2000;
  }
  if ((in_alt1.state & 3U) != 0) {
    uVar1 = uVar1 | 0x4000;
  }
  if ((in_score.state & 3U) != 0) {
    uVar1 = uVar1 | 0x8000;
  }
  if ((gHUD.m_Health.m_iHealth < 1) || (gHUD.m_iIntermission != 0)) {
    uVar1 = uVar1 | 0x8000;
  }
  if (bResetState != 0) {
    in_attack.state = in_attack.state & 0xfffffffd;
    in_attack2.state = in_attack2.state & 0xfffffffd;
    in_reload.state = in_reload.state & 0xfffffffd;
    in_alt1.state = in_alt1.state & 0xfffffffd;
    in_score.state = in_score.state & 0xfffffffd;
    in_moveright.state = in_moveright.state & 0xfffffffd;
    in_duck.state = in_duck.state & 0xfffffffd;
    in_jump.state = in_jump.state & 0xfffffffd;
    in_forward.state = in_forward.state & 0xfffffffd;
    in_back.state = in_back.state & 0xfffffffd;
    in_use.state = in_use.state & 0xfffffffd;
    in_left.state = in_left.state & 0xfffffffd;
    in_right.state = in_right.state & 0xfffffffd;
    in_moveleft.state = in_moveleft.state & 0xfffffffd;
  }
  return uVar1;
}


// CL_ResetButtonBits  @ 000752f0  (line 902)

void CL_ResetButtonBits(int bits)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  int iVar3;
  
                    /* Unresolved local var: int bitsNew@[???] */
                    /* Unresolved local var: int bits@[???] */
  if ((((uint)((in_attack.state & 3U) != 0) ^ bits) & 1) != 0) {
    if ((bits & 1U) == 0) {
      in_attack.state = in_attack.state & 0xfffffff8;
    }
    else {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
      __nptr = (*gEngfuncs.Cmd_Argv)(1);
      iVar3 = -1;
      if (*__nptr != '\0') {
        iVar3 = strtol(__nptr,(char **)0x0,10);
      }
      if ((in_attack.down[0] != iVar3) && (iVar3 != in_attack.down[1])) {
        iVar1 = iVar3;
        iVar2 = in_attack.down[1];
        if ((in_attack.down[0] == 0) ||
           (iVar1 = in_attack.down[0], iVar2 = iVar3, in_attack.down[1] == 0)) {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: char * c@[???] */
          in_attack.down[1] = iVar2;
          in_attack.down[0] = iVar1;
          if ((in_attack.state & 1U) == 0) {
            in_attack.state = in_attack.state | 3;
          }
        }
        else {
          (*gEngfuncs.Con_DPrintf)
                    ("Three keys down for a button \'%c\' \'%c\' \'%c\'!\n",in_attack.down[0],
                     in_attack.down[1],__nptr);
        }
      }
    }
  }
  return;
}


// InitInput  @ 000754d0  (line 927)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void InitInput(void)

{
  (*gEngfuncs.pfnAddCommand)("+moveup",IN_UpDown);
  (*gEngfuncs.pfnAddCommand)("-moveup",IN_UpUp);
  (*gEngfuncs.pfnAddCommand)("+movedown",IN_DownDown);
  (*gEngfuncs.pfnAddCommand)("-movedown",IN_DownUp);
  (*gEngfuncs.pfnAddCommand)("+left",IN_LeftDown);
  (*gEngfuncs.pfnAddCommand)("-left",IN_LeftUp);
  (*gEngfuncs.pfnAddCommand)("+right",IN_RightDown);
  (*gEngfuncs.pfnAddCommand)("-right",IN_RightUp);
  (*gEngfuncs.pfnAddCommand)("+forward",IN_ForwardDown);
  (*gEngfuncs.pfnAddCommand)("-forward",IN_ForwardUp);
  (*gEngfuncs.pfnAddCommand)("+back",IN_BackDown);
  (*gEngfuncs.pfnAddCommand)("-back",IN_BackUp);
  (*gEngfuncs.pfnAddCommand)("+lookup",IN_LookupDown);
  (*gEngfuncs.pfnAddCommand)("-lookup",IN_LookupUp);
  (*gEngfuncs.pfnAddCommand)("+lookdown",IN_LookdownDown);
  (*gEngfuncs.pfnAddCommand)("-lookdown",IN_LookdownUp);
  (*gEngfuncs.pfnAddCommand)("+strafe",IN_StrafeDown);
  (*gEngfuncs.pfnAddCommand)("-strafe",IN_StrafeUp);
  (*gEngfuncs.pfnAddCommand)("+moveleft",IN_MoveleftDown);
  (*gEngfuncs.pfnAddCommand)("-moveleft",IN_MoveleftUp);
  (*gEngfuncs.pfnAddCommand)("+moveright",IN_MoverightDown);
  (*gEngfuncs.pfnAddCommand)("-moveright",IN_MoverightUp);
  (*gEngfuncs.pfnAddCommand)("+speed",IN_SpeedDown);
  (*gEngfuncs.pfnAddCommand)("-speed",IN_SpeedUp);
  (*gEngfuncs.pfnAddCommand)("+attack",IN_AttackDown);
  (*gEngfuncs.pfnAddCommand)("-attack",IN_AttackUp);
  (*gEngfuncs.pfnAddCommand)("+attack2",IN_Attack2Down);
  (*gEngfuncs.pfnAddCommand)("-attack2",IN_Attack2Up);
  (*gEngfuncs.pfnAddCommand)("+use",IN_UseDown);
  (*gEngfuncs.pfnAddCommand)("-use",IN_UseUp);
  (*gEngfuncs.pfnAddCommand)("+jump",IN_JumpDown);
  (*gEngfuncs.pfnAddCommand)("-jump",IN_JumpUp);
  (*gEngfuncs.pfnAddCommand)("impulse",IN_Impulse);
  (*gEngfuncs.pfnAddCommand)("+klook",IN_KLookDown);
  (*gEngfuncs.pfnAddCommand)("-klook",IN_KLookUp);
  (*gEngfuncs.pfnAddCommand)("+mlook",IN_MLookDown);
  (*gEngfuncs.pfnAddCommand)("-mlook",IN_MLookUp);
  (*gEngfuncs.pfnAddCommand)("+jlook",IN_JLookDown);
  (*gEngfuncs.pfnAddCommand)("-jlook",IN_JLookUp);
  (*gEngfuncs.pfnAddCommand)("+duck",IN_DuckDown);
  (*gEngfuncs.pfnAddCommand)("-duck",IN_DuckUp);
  (*gEngfuncs.pfnAddCommand)("+reload",IN_ReloadDown);
  (*gEngfuncs.pfnAddCommand)("-reload",IN_ReloadUp);
  (*gEngfuncs.pfnAddCommand)("+alt1",IN_Alt1Down);
  (*gEngfuncs.pfnAddCommand)("-alt1",IN_Alt1Up);
  (*gEngfuncs.pfnAddCommand)("+score",IN_ScoreDown);
  (*gEngfuncs.pfnAddCommand)("-score",IN_ScoreUp);
  (*gEngfuncs.pfnAddCommand)("+showscores",IN_ScoreDown);
  (*gEngfuncs.pfnAddCommand)("-showscores",IN_ScoreUp);
  (*gEngfuncs.pfnAddCommand)("+graph",IN_GraphDown);
  (*gEngfuncs.pfnAddCommand)("-graph",IN_GraphUp);
  (*gEngfuncs.pfnAddCommand)("+break",IN_BreakDown);
  (*gEngfuncs.pfnAddCommand)("-break",IN_BreakUp);
  lookstrafe = (*gEngfuncs.pfnRegisterVariable)("lookstrafe","0",1);
  lookspring = (*gEngfuncs.pfnRegisterVariable)("lookspring","0",1);
  cl_anglespeedkey = (*gEngfuncs.pfnRegisterVariable)("cl_anglespeedkey","0.67",0);
  cl_yawspeed = (*gEngfuncs.pfnRegisterVariable)("cl_yawspeed","210",0);
  cl_pitchspeed = (*gEngfuncs.pfnRegisterVariable)("cl_pitchspeed","225",0);
  cl_upspeed = (*gEngfuncs.pfnRegisterVariable)("cl_upspeed","320",0);
  cl_forwardspeed = (*gEngfuncs.pfnRegisterVariable)("cl_forwardspeed","400",1);
  cl_backspeed = (*gEngfuncs.pfnRegisterVariable)("cl_backspeed","400",1);
  cl_sidespeed = (*gEngfuncs.pfnRegisterVariable)("cl_sidespeed","400",0);
  cl_movespeedkey = (*gEngfuncs.pfnRegisterVariable)("cl_movespeedkey","0.3",0);
  cl_pitchup = (*gEngfuncs.pfnRegisterVariable)("cl_pitchup","89",0);
  cl_pitchdown = (*gEngfuncs.pfnRegisterVariable)("cl_pitchdown","89",0);
  cl_vsmoothing = (*gEngfuncs.pfnRegisterVariable)("cl_vsmoothing","0.05",1);
  m_pitch = (*gEngfuncs.pfnRegisterVariable)("m_pitch","0.022",1);
  m_yaw = (*gEngfuncs.pfnRegisterVariable)("m_yaw","0.022",1);
  m_forward = (*gEngfuncs.pfnRegisterVariable)("m_forward","1",1);
  m_side = (*gEngfuncs.pfnRegisterVariable)("m_side","0.8",1);
  CAM_Init();
  IN_Init();
  KB_Init();
  V_Init();
  return;
}


// ShutdownInput  @ 00075bd0  (line 1018)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ShutdownInput(void)

{
  kblist_s *pkVar1;
  kblist_t *__ptr;
  
  IN_Shutdown();
  __ptr = g_kbkeys;
                    /* Unresolved local var: kblist_t * p@[???]
                       Unresolved local var: kblist_t * n@[???] */
  while (__ptr != (kblist_t *)0x0) {
    pkVar1 = __ptr->next;
    free(__ptr);
    __ptr = pkVar1;
  }
  g_kbkeys = (kblist_t *)0x0;
  return;
}


// HUD_Shutdown  @ 00075c10  (line 1031)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HUD_Shutdown(void)

{
  kblist_s *pkVar1;
  kblist_t *__ptr;
  
                    /* Unresolved local var: CSysModule * g_hTrackerModule@[???] */
  IN_Shutdown();
  __ptr = g_kbkeys;
                    /* Unresolved local var: kblist_t * p@[???]
                       Unresolved local var: kblist_t * n@[???] */
  while (__ptr != (kblist_t *)0x0) {
    pkVar1 = __ptr->next;
    free(__ptr);
    __ptr = pkVar1;
  }
  g_kbkeys = (kblist_t *)0x0;
  ClearEventList();
  CL_UnloadParticleMan();
  if (g_hTrackerModule != (CSysModule *)0x0) {
    Sys_UnloadModule(g_hTrackerModule);
  }
  return;
}


