// KB_Add  @ 00096860
void KB_Add(char *name,kbutton_t *pkb)

{
  kblist_s *pkVar1;
  kblist_t *pkVar2;
  uint uVar3;
  int iVar4;
  kblist_t *pkVar5;
  uint uVar6;
  char *pcVar7;
  
  pkVar2 = g_kbkeys;
  pkVar1 = g_kbkeys;
                    /* Unresolved local var: kblist_t * p@[???]
                       Unresolved local var: kbutton_t * kb@[???] */
  do {
    if (pkVar1 == (kblist_t *)0x0) {
LAB_000968b0:
                    /* Unresolved local var: kblist_t * p@[???]
                       Unresolved local var: kbutton_t * kb@[???] */
      pkVar5 = malloc(0x28);
      uVar3 = 0;
      do {
        uVar6 = uVar3;
        pcVar7 = pkVar5->name + (uVar6 - 4);
        pcVar7[0] = '\0';
        pcVar7[1] = '\0';
        pcVar7[2] = '\0';
        pcVar7[3] = '\0';
        pcVar7 = pkVar5->name + (uVar6 - 8);
        pcVar7[0] = '\0';
        pcVar7[1] = '\0';
        pcVar7[2] = '\0';
        pcVar7[3] = '\0';
        pcVar7 = pkVar5->name + uVar6;
        pcVar7[0] = '\0';
        pcVar7[1] = '\0';
        pcVar7[2] = '\0';
        pcVar7[3] = '\0';
        pcVar7 = pkVar5->name + uVar6 + 4;
        pcVar7[0] = '\0';
        pcVar7[1] = '\0';
        pcVar7[2] = '\0';
        pcVar7[3] = '\0';
        uVar3 = uVar6 + 0x10;
      } while (uVar6 + 0x10 < 0x20);
      pcVar7 = pkVar5->name + uVar6 + 8;
      pcVar7[0] = '\0';
      pcVar7[1] = '\0';
      pcVar7[2] = '\0';
      pcVar7[3] = '\0';
      pcVar7[4] = '\0';
      pcVar7[5] = '\0';
      pcVar7[6] = '\0';
      pcVar7[7] = '\0';
      strcpy(pkVar5->name,name);
      pkVar5->next = pkVar2;
      g_kbkeys = pkVar5;
      pkVar5->pkey = pkb;
      return;
    }
    iVar4 = strcasecmp(name,pkVar1->name);
    if (iVar4 == 0) {
      if (pkVar1->pkey != (kbutton_t *)0x0) {
        return;
      }
      goto LAB_000968b0;
    }
    pkVar1 = pkVar1->next;
  } while( true );
}


// KB_ConvertString  @ 000966b0
int KB_ConvertString(char *in,char **ppout)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  uint *puVar6;
  char cVar7;
  uint *puVar8;
  uint local_105c [1024];
  char local_5c [76];
  
                    /* Unresolved local var: char[4096] sz@[???]
                       Unresolved local var: char[64] binding@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char * pOut@[???]
                       Unresolved local var: char * pEnd@[???]
                       Unresolved local var: char * pBinding@[???] */
  iVar1 = 0;
  if (ppout != (char **)0x0) {
    *ppout = (char *)0x0;
    puVar8 = local_105c;
    while (cVar7 = *in, cVar7 != '\0') {
      while (cVar7 != '+') {
        in = in + 1;
        *(char *)puVar8 = cVar7;
        cVar7 = *in;
        puVar8 = (uint *)((int)puVar8 + 1);
        if (cVar7 == '\0') goto LAB_0009670b;
      }
      cVar7 = '+';
      pcVar4 = local_5c;
      do {
        iVar1 = isalnum((int)cVar7);
        if (((iVar1 == 0) && (pcVar4 != local_5c)) || (0x3e < (int)pcVar4 - (int)local_5c)) break;
        in = in + 1;
        *pcVar4 = cVar7;
        cVar7 = *in;
        pcVar4 = pcVar4 + 1;
      } while (cVar7 != '\0');
      *pcVar4 = '\0';
      pcVar4 = local_5c;
      if (local_5c[1] == '\0') {
        pcVar5 = (char *)0x0;
      }
      else {
        pcVar5 = (*gEngfuncs.Key_LookupBinding)(local_5c + 1);
        if (pcVar5 != (char *)0x0) {
          *(char *)puVar8 = '[';
          puVar8 = (uint *)((int)puVar8 + 1);
          pcVar4 = pcVar5;
        }
      }
      for (; *pcVar4 != '\0'; pcVar4 = pcVar4 + 1) {
        *(char *)puVar8 = *pcVar4;
        puVar8 = (uint *)((int)puVar8 + 1);
      }
      if (pcVar5 != (char *)0x0) {
        *(char *)puVar8 = ']';
        puVar8 = (uint *)((int)puVar8 + 1);
      }
    }
LAB_0009670b:
    *(char *)puVar8 = '\0';
    puVar8 = local_105c;
    do {
      puVar6 = puVar8;
      uVar2 = *puVar6 + 0xfefefeff & ~*puVar6;
      uVar3 = uVar2 & 0x80808080;
      puVar8 = puVar6 + 1;
    } while (uVar3 == 0);
    if ((uVar2 & 0x8080) == 0) {
      puVar8 = (uint *)((int)puVar6 + 6);
      uVar3 = uVar3 >> 0x10;
    }
    pcVar4 = malloc((int)puVar8 + (-(int)local_105c - (uint)CARRY1((byte)uVar3,(byte)uVar3)) + -2);
    strcpy(pcVar4,(char *)local_105c);
    *ppout = pcVar4;
    iVar1 = 1;
  }
  return iVar1;
}


// KB_Find  @ 00096810
kbutton_s * KB_Find(char *name)

{
  kbutton_t *pkVar1;
  int iVar2;
  kblist_s *pkVar3;
  
                    /* Unresolved local var: kblist_t * p@[???] */
  pkVar1 = (kbutton_s *)0x0;
  pkVar3 = g_kbkeys;
  if (g_kbkeys != (kblist_t *)0x0) {
    while (iVar2 = strcasecmp(name,pkVar3->name), iVar2 != 0) {
      pkVar3 = pkVar3->next;
      if (pkVar3 == (kblist_s *)0x0) {
        return (kbutton_s *)0x0;
      }
    }
    pkVar1 = pkVar3->pkey;
  }
  return pkVar1;
}


// KB_Init  @ 00096910
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void KB_Init(void)

{
  kblist_s **ppkVar1;
  uint uVar2;
  kblist_t *pkVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  kblist_s *pkVar7;
  kblist_s *pkVar8;
  
                    /* Unresolved local var: kblist_t * p@[???]
                       Unresolved local var: kbutton_t * kb@[???] */
  pkVar3 = malloc(0x28);
  uVar2 = 0;
  do {
    uVar4 = uVar2;
    pcVar5 = pkVar3->name + (uVar4 - 8);
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = pkVar3->name + (uVar4 - 4);
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = pkVar3->name + uVar4;
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = pkVar3->name + uVar4 + 4;
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    uVar2 = uVar4 + 0x10;
  } while (uVar4 + 0x10 < 0x20);
  pcVar5 = pkVar3->name + uVar4 + 8;
  pcVar5[0] = '\0';
  pcVar5[1] = '\0';
  pcVar5[2] = '\0';
  pcVar5[3] = '\0';
  pcVar5[4] = '\0';
  pcVar5[5] = '\0';
  pcVar5[6] = '\0';
  pcVar5[7] = '\0';
  builtin_strncpy(pkVar3->name,"in_graph",9);
  pkVar3->pkey = &in_graph;
  pkVar3->next = (kblist_s *)0x0;
  pkVar8 = pkVar3;
  g_kbkeys = pkVar3;
  do {
    iVar6 = strcasecmp("in_mlook",pkVar8->name);
    if (iVar6 == 0) {
      pkVar7 = pkVar3;
      if (pkVar8->pkey != (kbutton_t *)0x0) goto LAB_000969be;
      break;
    }
                    /* Unresolved local var: kblist_t * p@[???]
                       Unresolved local var: kbutton_t * kb@[???] */
    pkVar8 = pkVar8->next;
  } while (pkVar8 != (kblist_s *)0x0);
  pkVar7 = malloc(0x28);
  uVar2 = 0;
  do {
    uVar4 = uVar2;
    pcVar5 = pkVar7->name + (uVar4 - 4);
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = pkVar7->name + (uVar4 - 8);
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = pkVar7->name + uVar4;
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = pkVar7->name + uVar4 + 4;
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    uVar2 = uVar4 + 0x10;
  } while (uVar4 + 0x10 < 0x20);
  pcVar5 = pkVar7->name + uVar4 + 8;
  pcVar5[0] = '\0';
  pcVar5[1] = '\0';
  pcVar5[2] = '\0';
  pcVar5[3] = '\0';
  pcVar5[4] = '\0';
  pcVar5[5] = '\0';
  pcVar5[6] = '\0';
  pcVar5[7] = '\0';
  pkVar7->next = pkVar3;
  builtin_strncpy(pkVar7->name,"in_mlook",9);
  pkVar7->pkey = &in_mlook;
  g_kbkeys = pkVar7;
  pkVar3 = pkVar7;
LAB_000969be:
  do {
    iVar6 = strcasecmp("in_jlook",pkVar7->name);
    if (iVar6 == 0) {
      if (pkVar7->pkey != (kbutton_t *)0x0) {
        return;
      }
      break;
    }
    ppkVar1 = &pkVar7->next;
                    /* Unresolved local var: kblist_t * p@[???]
                       Unresolved local var: kbutton_t * kb@[???] */
    pkVar7 = *ppkVar1;
  } while (*ppkVar1 != (kblist_s *)0x0);
                    /* Unresolved local var: kblist_t * p@[???]
                       Unresolved local var: kbutton_t * kb@[???] */
  g_kbkeys = malloc(0x28);
  uVar2 = 0;
  do {
    uVar4 = uVar2;
    pcVar5 = g_kbkeys->name + (uVar4 - 4);
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = g_kbkeys->name + (uVar4 - 8);
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = g_kbkeys->name + uVar4;
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = g_kbkeys->name + uVar4 + 4;
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    uVar2 = uVar4 + 0x10;
  } while (uVar4 + 0x10 < 0x20);
  pcVar5 = g_kbkeys->name + uVar4 + 8;
  pcVar5[0] = '\0';
  pcVar5[1] = '\0';
  pcVar5[2] = '\0';
  pcVar5[3] = '\0';
  pcVar5[4] = '\0';
  pcVar5[5] = '\0';
  pcVar5[6] = '\0';
  pcVar5[7] = '\0';
  builtin_strncpy(g_kbkeys->name,"in_jlook",9);
  g_kbkeys->pkey = &in_jlook;
  g_kbkeys->next = pkVar3;
  return;
}


// KB_Shutdown  @ 00096ac0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void KB_Shutdown(void)

{
  kblist_s *pkVar1;
  kblist_t *__ptr;
  
  __ptr = g_kbkeys;
  while (__ptr != (kblist_t *)0x0) {
    pkVar1 = __ptr->next;
    free(__ptr);
    __ptr = pkVar1;
  }
  g_kbkeys = (kblist_t *)0x0;
  return;
}


