// Ghidra decompilation of functions from game_shared/bitvec.h
// 1 functions, ordered by original source line

// _GLOBAL__sub_I_g_PlayerModEnable  @ 0006c540  (line 110)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_PlayerModEnable(void)

{
  uint uVar1;
  uint uVar2;
  
                    /* Unresolved local var: int i@[???] */
  g_PlayerModEnable.m_DWords[0] = (uint32  [1])0;
  uVar2 = 0;
  do {
    *(undefined4 *)((int)g_BanMasks[0].m_DWords + uVar2) = 0;
    uVar1 = uVar2 + 8;
    *(undefined4 *)((int)g_BanMasks[1].m_DWords + uVar2) = 0;
    uVar2 = uVar1;
  } while (uVar1 < 0x80);
  uVar2 = 0;
  do {
    *(undefined4 *)((int)g_SentGameRulesMasks[0].m_DWords + uVar2) = 0;
    uVar1 = uVar2 + 8;
    *(undefined4 *)((int)g_SentGameRulesMasks[1].m_DWords + uVar2) = 0;
    uVar2 = uVar1;
  } while (uVar1 < 0x80);
  uVar2 = 0;
  do {
    *(undefined4 *)((int)g_SentBanMasks[0].m_DWords + uVar2) = 0;
    uVar1 = uVar2 + 8;
    *(undefined4 *)((int)g_SentBanMasks[1].m_DWords + uVar2) = 0;
    uVar2 = uVar1;
  } while (uVar1 < 0x80);
                    /* Unresolved local var: int i@[???] */
  g_bWantModEnable.m_DWords[0] = (uint32  [1])0;
  return;
}


