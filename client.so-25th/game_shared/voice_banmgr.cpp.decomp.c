// Ghidra decompilation of functions from game_shared/voice_banmgr.cpp
// 12 functions, ordered by original source line

// HashPlayerID  @ 000abdd0  (line 20)

uchar HashPlayerID(char *playerID)

{
                    /* Unresolved local var: uchar curHash@[???] */
  return playerID[8] + *playerID + playerID[0xc] + playerID[4] +
         playerID[10] + playerID[2] + playerID[0xe] + playerID[6] +
         playerID[9] + playerID[1] + playerID[0xd] + playerID[5] +
         playerID[0xb] + playerID[3] + playerID[0xf] + playerID[7];
}


// CVoiceBanMgr::CVoiceBanMgr  @ 000abe20  (line 31)

/* DWARF original prototype: void CVoiceBanMgr(CVoiceBanMgr * this) */

void __thiscall CVoiceBanMgr::CVoiceBanMgr(CVoiceBanMgr *this)

{
  BannedPlayer *pBVar1;
  
  pBVar1 = this[1].m_PlayerHash;
  do {
                    /* Unresolved local var: int i@[???] */
    this->m_PlayerHash[0].m_pPrev = this->m_PlayerHash;
    this->m_PlayerHash[0].m_pNext = this->m_PlayerHash;
    this = (CVoiceBanMgr *)((int)this + 0x18);
  } while ((BannedPlayer *)this != pBVar1);
  return;
}


// CVoiceBanMgr::~CVoiceBanMgr  @ 000abe40  (line 37)

/* DWARF original prototype: void ~CVoiceBanMgr(CVoiceBanMgr * this, int __in_chrg) */

void __thiscall CVoiceBanMgr::~CVoiceBanMgr(CVoiceBanMgr *this,int __in_chrg)

{
  BannedPlayer *pBVar1;
  BannedPlayer *pBVar2;
  BannedPlayer *pBVar3;
  BannedPlayer *pBVar4;
  
  pBVar1 = this[1].m_PlayerHash;
  pBVar4 = this->m_PlayerHash;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: BannedPlayer * pListHead@[???]
                       Unresolved local var: BannedPlayer * pNext@[???]
                       Unresolved local var: BannedPlayer * pCur@[???] */
    pBVar3 = pBVar4->m_pNext;
    while (pBVar4 != pBVar3) {
      pBVar2 = pBVar3->m_pNext;
      operator_delete(pBVar3);
      pBVar3 = pBVar2;
    }
    pBVar4 = pBVar4 + 1;
  } while (pBVar4 != pBVar1);
  do {
                    /* Unresolved local var: int i@[???] */
    this->m_PlayerHash[0].m_pPrev = this->m_PlayerHash;
    this->m_PlayerHash[0].m_pNext = this->m_PlayerHash;
    this = (CVoiceBanMgr *)((int)this + 0x18);
  } while ((BannedPlayer *)this != pBVar1);
  return;
}


// CVoiceBanMgr::Init  @ 000abeb0  (line 44)

/* DWARF original prototype: bool Init(CVoiceBanMgr * this, char * pGameDir) */

bool __thiscall CVoiceBanMgr::Init(CVoiceBanMgr *this,char *pGameDir)

{
  BannedPlayer *pBVar1;
  FILE *__stream;
  long lVar2;
  BannedPlayer *pBVar3;
  uint uVar4;
  BannedPlayer *pBVar5;
  uint uVar6;
  int in_GS_OFFSET;
  int local_234;
  char local_230;
  char cStack_22f;
  char cStack_22e;
  char cStack_22d;
  char cStack_22c;
  char cStack_22b;
  char cStack_22a;
  char cStack_229;
  char local_228;
  char cStack_227;
  char cStack_226;
  char cStack_225;
  char cStack_224;
  char cStack_223;
  char cStack_222;
  char cStack_221;
  char local_220 [512];
  int local_20;
  
                    /* Unresolved local var: char[512] filename@[???]
                       Unresolved local var: FILE * fp@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pBVar3 = this->m_PlayerHash;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: BannedPlayer * pListHead@[???]
                       Unresolved local var: BannedPlayer * pNext@[???]
                       Unresolved local var: BannedPlayer * pCur@[???] */
    pBVar5 = pBVar3->m_pNext;
    while (pBVar3 != pBVar5) {
      pBVar1 = pBVar5->m_pNext;
      operator_delete(pBVar5);
      pBVar5 = pBVar1;
    }
    pBVar3 = pBVar3 + 1;
    pBVar5 = this->m_PlayerHash;
  } while (this[1].m_PlayerHash != pBVar3);
  do {
                    /* Unresolved local var: int i@[???] */
    pBVar5->m_pPrev = pBVar5;
    pBVar5->m_pNext = pBVar5;
    pBVar5 = pBVar5 + 1;
  } while (this[1].m_PlayerHash != pBVar5);
  __snprintf_chk(local_220,0x200,1,0x200,"%s/%s",pGameDir,g_pBanMgrFilename);
  __stream = fopen(local_220,"rb");
  if (__stream != (FILE *)0x0) {
                    /* Unresolved local var: int version@[???] */
    fread(&local_234,1,4,__stream);
    if (local_234 == 1) {
                    /* Unresolved local var: int nIDs@[???] */
      fseek(__stream,0,2);
      lVar2 = ftell(__stream);
      uVar6 = lVar2 - 4U >> 4;
      fseek(__stream,4,0);
                    /* Unresolved local var: int i@[???] */
      if (uVar6 != 0) {
        uVar4 = 0;
        do {
                    /* Unresolved local var: char[16] playerID@[???] */
          fread(&local_230,1,0x10,__stream);
                    /* Unresolved local var: BannedPlayer * pNew@[???]
                       Unresolved local var: int index@[???] */
          pBVar3 = operator_new(0x18);
          if (pBVar3 != (BannedPlayer *)0x0) {
                    /* Unresolved local var: uchar curHash@[???]
                       Unresolved local var: int i@[???] */
            *(ulonglong *)pBVar3->m_PlayerID =
                 CONCAT17(cStack_229,
                          CONCAT16(cStack_22a,
                                   CONCAT15(cStack_22b,
                                            CONCAT14(cStack_22c,
                                                     CONCAT13(cStack_22d,
                                                              CONCAT12(cStack_22e,
                                                                       CONCAT11(cStack_22f,local_230
                                                                               )))))));
            *(ulonglong *)(pBVar3->m_PlayerID + 8) =
                 CONCAT17(cStack_221,
                          CONCAT16(cStack_222,
                                   CONCAT15(cStack_223,
                                            CONCAT14(cStack_224,
                                                     CONCAT13(cStack_225,
                                                              CONCAT12(cStack_226,
                                                                       CONCAT11(cStack_227,local_228
                                                                               )))))));
            pBVar5 = this->m_PlayerHash +
                     (byte)(cStack_22f + local_230 + cStack_22e + cStack_22d + cStack_22c +
                            cStack_22b + cStack_22a + cStack_229 + local_228 + cStack_227 +
                            cStack_226 + cStack_225 + cStack_224 + cStack_223 + cStack_222 +
                           cStack_221);
            pBVar1 = pBVar5->m_pPrev;
            pBVar3->m_pNext = pBVar5;
            pBVar5->m_pPrev = pBVar3;
            pBVar3->m_pPrev = pBVar1;
            pBVar1->m_pNext = pBVar3;
          }
          uVar4 = uVar4 + 1;
        } while (uVar6 != uVar4);
      }
    }
    fclose(__stream);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return true;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CVoiceBanMgr::Term  @ 000ac0d0  (line 78)

/* DWARF original prototype: void Term(CVoiceBanMgr * this) */

void __thiscall CVoiceBanMgr::Term(CVoiceBanMgr *this)

{
  BannedPlayer *pBVar1;
  BannedPlayer *pBVar2;
  BannedPlayer *pBVar3;
  BannedPlayer *pBVar4;
  
  pBVar1 = this[1].m_PlayerHash;
  pBVar4 = this->m_PlayerHash;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: BannedPlayer * pListHead@[???]
                       Unresolved local var: BannedPlayer * pNext@[???]
                       Unresolved local var: BannedPlayer * pCur@[???] */
    pBVar3 = pBVar4->m_pNext;
    while (pBVar4 != pBVar3) {
      pBVar2 = pBVar3->m_pNext;
      operator_delete(pBVar3);
      pBVar3 = pBVar2;
    }
    pBVar4 = pBVar4 + 1;
  } while (pBVar4 != pBVar1);
  do {
                    /* Unresolved local var: int i@[???] */
    this->m_PlayerHash[0].m_pPrev = this->m_PlayerHash;
    this->m_PlayerHash[0].m_pNext = this->m_PlayerHash;
    this = (CVoiceBanMgr *)((int)this + 0x18);
  } while ((BannedPlayer *)this != pBVar1);
  return;
}


// CVoiceBanMgr::SaveState  @ 000ac140  (line 96)

/* DWARF original prototype: void SaveState(CVoiceBanMgr * this, char * pGameDir) */

void __thiscall CVoiceBanMgr::SaveState(CVoiceBanMgr *this,char *pGameDir)

{
  CVoiceBanMgr *pCVar1;
  BannedPlayer *__ptr;
  FILE *__s;
  int in_GS_OFFSET;
  undefined4 local_224;
  char local_220 [512];
  int local_20;
  
                    /* Unresolved local var: char[512] filename@[???]
                       Unresolved local var: FILE * fp@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  __snprintf_chk(local_220,0x200,1,0x200,"%s/%s",pGameDir,g_pBanMgrFilename);
  __s = fopen(local_220,"wb");
  if (__s != (FILE *)0x0) {
                    /* Unresolved local var: int version@[???] */
    pCVar1 = this + 1;
    local_224 = 1;
    fwrite(&local_224,1,4,__s);
    do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: BannedPlayer * pListHead@[???]
                       Unresolved local var: BannedPlayer * pCur@[???] */
      for (__ptr = this->m_PlayerHash[0].m_pNext; this->m_PlayerHash != __ptr;
          __ptr = __ptr->m_pNext) {
        fwrite(__ptr,1,0x10,__s);
      }
      this = (CVoiceBanMgr *)((int)this + 0x18);
    } while (this != pCVar1);
    fclose(__s);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CVoiceBanMgr::GetPlayerBan  @ 000ac260  (line 122)

/* DWARF original prototype: bool GetPlayerBan(CVoiceBanMgr * this, char * playerID) */

bool __thiscall CVoiceBanMgr::GetPlayerBan(CVoiceBanMgr *this,char *playerID)

{
  BannedPlayer *__s2;
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  char cVar15;
  char cVar16;
  int iVar17;
  
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: BannedPlayer * pListHead@[???]
                       Unresolved local var: uchar curHash@[???]
                       Unresolved local var: int i@[???] */
  cVar1 = *playerID;
  cVar2 = playerID[1];
  cVar3 = playerID[2];
  cVar4 = playerID[3];
  cVar5 = playerID[4];
  cVar6 = playerID[5];
  cVar7 = playerID[6];
  cVar8 = playerID[7];
  cVar9 = playerID[8];
  cVar10 = playerID[9];
  cVar11 = playerID[10];
  cVar12 = playerID[0xb];
  cVar13 = playerID[0xc];
  cVar14 = playerID[0xd];
  cVar15 = playerID[0xe];
  cVar16 = playerID[0xf];
                    /* Unresolved local var: BannedPlayer * pCur@[???] */
  __s2 = this->m_PlayerHash
         [(byte)(cVar9 + cVar1 + cVar13 + cVar5 + cVar11 + cVar3 + cVar15 + cVar7 +
                cVar10 + cVar2 + cVar14 + cVar6 + cVar12 + cVar4 + cVar16 + cVar8)].m_pNext;
  while( true ) {
    if (this->m_PlayerHash +
        (byte)(cVar9 + cVar1 + cVar13 + cVar5 + cVar11 + cVar3 + cVar15 + cVar7 +
              cVar10 + cVar2 + cVar14 + cVar6 + cVar12 + cVar4 + cVar16 + cVar8) == __s2) {
      return false;
    }
    iVar17 = memcmp(playerID,__s2,0x10);
    if (iVar17 == 0) break;
    __s2 = __s2->m_pNext;
  }
  return __s2 != (BannedPlayer *)0x0;
}


// CVoiceBanMgr::SetPlayerBan  @ 000ac300  (line 128)

/* DWARF original prototype: void SetPlayerBan(CVoiceBanMgr * this, char * playerID, bool bSquelch)
    */

void __thiscall CVoiceBanMgr::SetPlayerBan(CVoiceBanMgr *this,char *playerID,bool bSquelch)

{
  BannedPlayer *pBVar1;
  undefined8 uVar2;
  BannedPlayer *pBVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  char cVar15;
  char cVar16;
  char cVar17;
  char cVar18;
  char cVar19;
  BannedPlayer *pBVar20;
  int iVar21;
  byte bVar22;
  
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: BannedPlayer * pListHead@[???]
                       Unresolved local var: uchar curHash@[???]
                       Unresolved local var: int i@[???] */
  bVar22 = playerID[8] + *playerID + playerID[0xc] + playerID[4] +
           playerID[10] + playerID[2] + playerID[0xe] + playerID[6] +
           playerID[9] + playerID[1] + playerID[0xd] + playerID[5] +
           playerID[0xb] + playerID[3] + playerID[0xf] + playerID[7];
  if (bSquelch) {
                    /* Unresolved local var: BannedPlayer * pCur@[???] */
    for (pBVar20 = this->m_PlayerHash[bVar22].m_pNext; this->m_PlayerHash + bVar22 != pBVar20;
        pBVar20 = pBVar20->m_pNext) {
      iVar21 = memcmp(playerID,pBVar20,0x10);
      if (iVar21 == 0) {
        if (pBVar20 != (BannedPlayer *)0x0) {
          return;
        }
        break;
      }
    }
                    /* Unresolved local var: BannedPlayer * pNew@[???]
                       Unresolved local var: int index@[???] */
    pBVar20 = operator_new(0x18);
    if (pBVar20 != (BannedPlayer *)0x0) {
                    /* Unresolved local var: uchar curHash@[???]
                       Unresolved local var: int i@[???] */
      cVar4 = *playerID;
      cVar5 = playerID[1];
      cVar6 = playerID[2];
      cVar7 = playerID[3];
      cVar8 = playerID[4];
      cVar9 = playerID[5];
      cVar10 = playerID[6];
      cVar11 = playerID[7];
      cVar12 = playerID[8];
      cVar13 = playerID[9];
      cVar14 = playerID[10];
      cVar15 = playerID[0xb];
      cVar16 = playerID[0xc];
      cVar17 = playerID[0xd];
      cVar18 = playerID[0xe];
      cVar19 = playerID[0xf];
      uVar2 = *(undefined8 *)(playerID + 8);
      *(undefined8 *)pBVar20->m_PlayerID = *(undefined8 *)playerID;
      *(undefined8 *)(pBVar20->m_PlayerID + 8) = uVar2;
      pBVar1 = this->m_PlayerHash +
               (byte)(cVar6 + cVar14 + cVar10 + cVar18 + cVar4 + cVar12 + cVar8 + cVar16 +
                     cVar7 + cVar15 + cVar11 + cVar19 + cVar5 + cVar13 + cVar9 + cVar17);
      pBVar3 = pBVar1->m_pPrev;
      pBVar20->m_pNext = pBVar1;
      pBVar1->m_pPrev = pBVar20;
      pBVar20->m_pPrev = pBVar3;
      pBVar3->m_pNext = pBVar20;
    }
  }
  else {
                    /* Unresolved local var: BannedPlayer * pPlayer@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: BannedPlayer * pListHead@[???] */
                    /* Unresolved local var: BannedPlayer * pCur@[???] */
    for (pBVar20 = this->m_PlayerHash[bVar22].m_pNext; this->m_PlayerHash + bVar22 != pBVar20;
        pBVar20 = pBVar20->m_pNext) {
      iVar21 = memcmp(playerID,pBVar20,0x10);
      if (iVar21 == 0) {
        if (pBVar20 == (BannedPlayer *)0x0) {
          return;
        }
        pBVar20->m_pPrev->m_pNext = pBVar20->m_pNext;
        pBVar20->m_pNext->m_pPrev = pBVar20->m_pPrev;
        operator_delete(pBVar20);
        return;
      }
    }
  }
  return;
}


// CVoiceBanMgr::ForEachBannedPlayer  @ 000ac4a0  (line 151)

/* DWARF original prototype: void ForEachBannedPlayer(CVoiceBanMgr * this, _func_void_char_ptr *
   callback) */

void __thiscall CVoiceBanMgr::ForEachBannedPlayer(CVoiceBanMgr *this,_func_void_char_ptr *callback)

{
  CVoiceBanMgr *pCVar1;
  BannedPlayer *pBVar2;
  
  pCVar1 = this + 1;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: BannedPlayer * pCur@[???] */
    for (pBVar2 = this->m_PlayerHash[0].m_pNext; pBVar2 != this->m_PlayerHash;
        pBVar2 = pBVar2->m_pNext) {
      (*callback)(pBVar2->m_PlayerID);
    }
    this = (CVoiceBanMgr *)((int)this + 0x18);
  } while (this != pCVar1);
  return;
}


// CVoiceBanMgr::Clear  @ 000ac4f0  (line 163)

/* DWARF original prototype: void Clear(CVoiceBanMgr * this) */

void __thiscall CVoiceBanMgr::Clear(CVoiceBanMgr *this)

{
  BannedPlayer *pBVar1;
  
  pBVar1 = this[1].m_PlayerHash;
  do {
                    /* Unresolved local var: int i@[???] */
    this->m_PlayerHash[0].m_pPrev = this->m_PlayerHash;
    this->m_PlayerHash[0].m_pNext = this->m_PlayerHash;
    this = (CVoiceBanMgr *)((int)this + 0x18);
  } while ((BannedPlayer *)this != pBVar1);
  return;
}


// CVoiceBanMgr::InternalFindPlayerSquelch  @ 000ac510  (line 171)

/* DWARF original prototype: BannedPlayer * InternalFindPlayerSquelch(CVoiceBanMgr * this, char *
   playerID) */

BannedPlayer * __thiscall CVoiceBanMgr::InternalFindPlayerSquelch(CVoiceBanMgr *this,char *playerID)

{
  BannedPlayer *__s2;
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  char cVar15;
  char cVar16;
  int iVar17;
  
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: BannedPlayer * pListHead@[???] */
                    /* Unresolved local var: uchar curHash@[???]
                       Unresolved local var: int i@[???] */
  cVar1 = *playerID;
  cVar2 = playerID[1];
  cVar3 = playerID[2];
  cVar4 = playerID[3];
  cVar5 = playerID[4];
  cVar6 = playerID[5];
  cVar7 = playerID[6];
  cVar8 = playerID[7];
  cVar9 = playerID[8];
  cVar10 = playerID[9];
  cVar11 = playerID[10];
  cVar12 = playerID[0xb];
  cVar13 = playerID[0xc];
  cVar14 = playerID[0xd];
  cVar15 = playerID[0xe];
  cVar16 = playerID[0xf];
                    /* Unresolved local var: BannedPlayer * pCur@[???] */
  __s2 = this->m_PlayerHash
         [(byte)(cVar9 + cVar1 + cVar13 + cVar5 + cVar11 + cVar3 + cVar15 + cVar7 +
                cVar10 + cVar2 + cVar14 + cVar6 + cVar12 + cVar4 + cVar16 + cVar8)].m_pNext;
  while( true ) {
    if (this->m_PlayerHash +
        (byte)(cVar9 + cVar1 + cVar13 + cVar5 + cVar11 + cVar3 + cVar15 + cVar7 +
              cVar10 + cVar2 + cVar14 + cVar6 + cVar12 + cVar4 + cVar16 + cVar8) == __s2) {
      return (BannedPlayer *)0x0;
    }
    iVar17 = memcmp(playerID,__s2,0x10);
    if (iVar17 == 0) break;
    __s2 = __s2->m_pNext;
  }
  return __s2;
}


// CVoiceBanMgr::AddBannedPlayer  @ 000ac5b0  (line 185)

/* DWARF original prototype: BannedPlayer * AddBannedPlayer(CVoiceBanMgr * this, char * playerID) */

BannedPlayer * __thiscall CVoiceBanMgr::AddBannedPlayer(CVoiceBanMgr *this,char *playerID)

{
  BannedPlayer *pBVar1;
  undefined8 uVar2;
  BannedPlayer *pBVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  char cVar15;
  char cVar16;
  char cVar17;
  char cVar18;
  char cVar19;
  BannedPlayer *pBVar20;
  
                    /* Unresolved local var: BannedPlayer * pNew@[DW_OP_reg0(EAX)]
                       Unresolved local var: int index@[???] */
  pBVar20 = operator_new(0x18);
  if (pBVar20 != (BannedPlayer *)0x0) {
                    /* Unresolved local var: uchar curHash@[???]
                       Unresolved local var: int i@[???] */
    cVar4 = *playerID;
    cVar5 = playerID[1];
    cVar6 = playerID[2];
    cVar7 = playerID[3];
    cVar8 = playerID[4];
    cVar9 = playerID[5];
    cVar10 = playerID[6];
    cVar11 = playerID[7];
    cVar12 = playerID[8];
    cVar13 = playerID[9];
    cVar14 = playerID[10];
    cVar15 = playerID[0xb];
    cVar16 = playerID[0xc];
    cVar17 = playerID[0xd];
    cVar18 = playerID[0xe];
    cVar19 = playerID[0xf];
    uVar2 = *(undefined8 *)(playerID + 8);
    *(undefined8 *)pBVar20->m_PlayerID = *(undefined8 *)playerID;
    *(undefined8 *)(pBVar20->m_PlayerID + 8) = uVar2;
    pBVar1 = this->m_PlayerHash +
             (byte)(cVar12 + cVar4 + cVar16 + cVar8 + cVar14 + cVar6 + cVar18 + cVar10 +
                   cVar13 + cVar5 + cVar17 + cVar9 + cVar15 + cVar7 + cVar19 + cVar11);
    pBVar3 = pBVar1->m_pPrev;
    pBVar20->m_pNext = pBVar1;
    pBVar1->m_pPrev = pBVar20;
    pBVar20->m_pPrev = pBVar3;
    pBVar3->m_pNext = pBVar20;
  }
  return pBVar20;
}


