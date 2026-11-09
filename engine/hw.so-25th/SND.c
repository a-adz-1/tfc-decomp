// SND_CloseMouth  @ 001ac480
void SND_CloseMouth(channel_t *ch)

{
  int iVar1;
  
  iVar1 = ch->entnum;
  if ((0 < iVar1) && (((ch->entchannel == 2 || (ch->entchannel == 5)) && (iVar1 < cl.max_edicts))))
  {
    cl_entities[iVar1].mouth.mouthopen = '\0';
    return;
  }
  return;
}


// SND_FStreamIsPlaying  @ 001a6bc0
int SND_FStreamIsPlaying(sfx_t *sfx)

{
  int iVar1;
  
                    /* Unresolved local var: int ch_idx@[???] */
  if (total_channels < 5) {
    return 0;
  }
  if (sfx != channels[4].sfx) {
    iVar1 = 4;
    do {
      iVar1 = iVar1 + 1;
      if (iVar1 == total_channels) {
        return 0;
      }
    } while (channels[iVar1].sfx != sfx);
  }
  return 1;
}


// SND_ForceCloseMouth  @ 001ac400
void SND_ForceCloseMouth(int entnum)

{
  if ((-1 < entnum) && (entnum < cl.max_edicts)) {
    cl_entities[entnum].mouth.mouthopen = '\0';
  }
  return;
}


// SND_ForceInitMouth  @ 001ac3c0
void SND_ForceInitMouth(int entnum)

{
  cl_entity_t *pcVar1;
  
  pcVar1 = cl_entities;
  if ((-1 < entnum) && (entnum < cl.max_edicts)) {
    cl_entities[entnum].mouth.mouthopen = '\0';
    pcVar1[entnum].mouth.sndavg = 0;
    pcVar1[entnum].mouth.sndcount = '\0';
  }
  return;
}


// SND_InitMouth  @ 001ac430
void SND_InitMouth(int entnum,int entchannel)

{
  cl_entity_t *pcVar1;
  
  pcVar1 = cl_entities;
  if (((entchannel == 2 || entchannel == 5) && (0 < entnum)) && (entnum < cl.max_edicts)) {
    cl_entities[entnum].mouth.mouthopen = '\0';
    pcVar1[entnum].mouth.sndavg = 0;
    pcVar1[entnum].mouth.sndcount = '\0';
    return;
  }
  return;
}


// SND_InitScaletable  @ 001a9f50
/* WARNING: Removing unreachable block (ram,0x001a9f83) */
/* WARNING: Removing unreachable block (ram,0x001aa3a8) */
/* WARNING: Removing unreachable block (ram,0x001a9f92) */
/* WARNING: Removing unreachable block (ram,0x001aa390) */
/* WARNING: Removing unreachable block (ram,0x001a9fa2) */
/* WARNING: Removing unreachable block (ram,0x001a9fb5) */
/* WARNING: Removing unreachable block (ram,0x001aa18a) */
/* WARNING: Removing unreachable block (ram,0x001aa1ae) */
/* WARNING: Removing unreachable block (ram,0x001aa1cd) */
/* WARNING: Removing unreachable block (ram,0x001aa1ec) */
/* WARNING: Removing unreachable block (ram,0x001aa20b) */
/* WARNING: Removing unreachable block (ram,0x001aa22a) */
/* WARNING: Removing unreachable block (ram,0x001aa249) */
/* WARNING: Removing unreachable block (ram,0x001aa268) */
/* WARNING: Removing unreachable block (ram,0x001aa286) */
/* WARNING: Removing unreachable block (ram,0x001aa2aa) */
/* WARNING: Removing unreachable block (ram,0x001aa2c5) */
/* WARNING: Removing unreachable block (ram,0x001aa2e0) */
/* WARNING: Removing unreachable block (ram,0x001aa2fb) */
/* WARNING: Removing unreachable block (ram,0x001aa316) */
/* WARNING: Removing unreachable block (ram,0x001aa331) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SND_InitScaletable(void)

{
  char cVar1;
  undefined1 auVar17 [12];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [12];
  unkbyte10 Var23;
  unkbyte9 Var24;
  undefined6 uVar25;
  undefined4 uVar26;
  int *piVar27;
  uint uVar28;
  uint uVar29;
  undefined4 uVar30;
  uint6 uVar32;
  undefined2 uVar46;
  undefined2 uVar47;
  undefined2 uVar48;
  short sVar49;
  undefined1 auVar36 [16];
  undefined1 auVar40 [16];
  undefined1 auVar43 [16];
  int iVar50;
  int iVar72;
  short sVar74;
  short sVar75;
  short sVar76;
  undefined1 auVar52 [16];
  undefined1 auVar56 [16];
  undefined1 auVar60 [16];
  undefined1 auVar63 [16];
  undefined1 auVar64 [16];
  short sVar73;
  undefined1 auVar65 [16];
  undefined1 auVar66 [16];
  char cVar77;
  undefined1 auVar82 [15];
  undefined1 auVar78 [16];
  undefined1 auVar83 [14];
  undefined1 auVar88 [14];
  int iVar89;
  int iVar90;
  int iVar91;
  short sVar92;
  undefined1 auVar93 [16];
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
  undefined6 uVar31;
  undefined1 auVar37 [16];
  undefined8 uVar33;
  undefined1 auVar45 [16];
  undefined1 auVar38 [16];
  undefined1 auVar41 [16];
  undefined1 auVar34 [12];
  undefined1 auVar39 [16];
  undefined1 auVar42 [16];
  undefined1 auVar35 [14];
  undefined1 auVar44 [16];
  undefined1 auVar67 [16];
  undefined1 auVar68 [16];
  undefined1 auVar51 [12];
  undefined1 auVar53 [16];
  undefined1 auVar57 [16];
  undefined1 auVar69 [16];
  undefined1 auVar54 [16];
  undefined1 auVar58 [16];
  undefined1 auVar61 [16];
  undefined1 auVar70 [16];
  undefined1 auVar55 [16];
  undefined1 auVar59 [16];
  undefined1 auVar62 [16];
  undefined1 auVar71 [16];
  undefined1 auVar79 [16];
  undefined1 auVar80 [16];
  undefined1 auVar81 [16];
  char cVar84;
  char cVar85;
  char cVar86;
  char cVar87;
  undefined1 auVar94 [16];
  undefined1 auVar95 [16];
  undefined1 auVar96 [16];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
  uVar28 = 0;
  do {
    iVar89 = 0;
    iVar90 = 1;
    iVar91 = 2;
    sVar92 = 3;
    uVar29 = 0;
    piVar27 = snd_scaletable[uVar28];
    do {
      auVar17._8_4_ = iVar91;
      auVar17._0_8_ = CONCAT44(iVar90,iVar89);
      uVar48 = (undefined2)(iVar91 + 4);
      auVar96._12_2_ = (short)((uint)iVar90 >> 0x10);
      auVar96._0_12_ = auVar17;
      auVar96._14_2_ = (short)((uint)(iVar90 + 4) >> 0x10);
      uVar47 = (undefined2)(iVar90 + 4);
      auVar95._12_4_ = auVar96._12_4_;
      auVar95._0_10_ = auVar17._0_10_;
      auVar95._10_2_ = uVar47;
      auVar94._10_6_ = auVar95._10_6_;
      auVar94._8_2_ = (short)iVar90;
      auVar94._0_8_ = CONCAT44(iVar90,iVar89);
      uVar46 = (undefined2)((uint)(iVar89 + 4) >> 0x10);
      auVar18._2_8_ = auVar94._8_8_;
      auVar18._0_2_ = uVar46;
      auVar18._10_6_ = 0;
      auVar93._12_4_ = 0;
      auVar93._0_12_ = SUB1612(auVar18 << 0x30,4);
      auVar93 = auVar93 << 0x20;
      auVar39._0_12_ = auVar93._0_12_;
      auVar39._12_2_ = uVar46;
      auVar39._14_2_ = (short)((uint)(iVar91 + 4) >> 0x10);
      auVar38._12_4_ = auVar39._12_4_;
      auVar38._0_10_ = auVar93._0_10_;
      auVar38._10_2_ = (short)((uint)iVar91 >> 0x10);
      auVar37._10_6_ = auVar38._10_6_;
      auVar37._0_8_ = auVar93._0_8_;
      auVar37._8_2_ = (short)((uint)iVar89 >> 0x10);
      auVar19._2_8_ = auVar37._8_8_;
      auVar19._0_2_ = uVar48;
      auVar19._10_6_ = 0;
      auVar36._12_4_ = 0;
      auVar36._0_12_ = SUB1612(auVar19 << 0x30,4);
      auVar36 = auVar36 << 0x20;
      iVar50 = iVar89 + 8;
      iVar72 = iVar90 + 8;
      auVar51._0_8_ = CONCAT44(iVar72,iVar50);
      auVar51._8_4_ = iVar91 + 8;
      auVar42._0_12_ = auVar36._0_12_;
      auVar42._12_2_ = uVar48;
      auVar42._14_2_ = sVar92 + 4;
      auVar41._12_4_ = auVar42._12_4_;
      auVar41._0_10_ = auVar36._0_10_;
      auVar41._10_2_ = uVar47;
      auVar40._10_6_ = auVar41._10_6_;
      auVar40._0_8_ = auVar36._0_8_;
      auVar40._8_2_ = (short)(iVar89 + 4);
      auVar43._8_8_ = auVar40._8_8_;
      auVar43._6_2_ = sVar92;
      auVar43._4_2_ = (short)iVar91;
      auVar43._2_2_ = (short)iVar90;
      auVar43._0_2_ = (short)iVar89;
      auVar43 = auVar43 & _DAT_00267f50;
      uVar48 = (undefined2)(iVar91 + 0xc);
      auVar55._12_2_ = (short)((uint)iVar72 >> 0x10);
      auVar55._0_12_ = auVar51;
      auVar55._14_2_ = (short)((uint)(iVar90 + 0xc) >> 0x10);
      auVar54._12_4_ = auVar55._12_4_;
      auVar54._0_10_ = auVar51._0_10_;
      uVar47 = (undefined2)(iVar90 + 0xc);
      auVar54._10_2_ = uVar47;
      auVar53._10_6_ = auVar54._10_6_;
      auVar53._8_2_ = (short)iVar72;
      auVar53._0_8_ = auVar51._0_8_;
      uVar46 = (undefined2)((uint)(iVar89 + 0xc) >> 0x10);
      auVar20._2_8_ = auVar53._8_8_;
      auVar20._0_2_ = uVar46;
      auVar20._10_6_ = 0;
      auVar63._0_2_ = (undefined2)iVar50;
      auVar52._12_4_ = 0;
      auVar52._0_12_ = SUB1612(auVar20 << 0x30,4);
      auVar52 = auVar52 << 0x20;
      auVar59._0_12_ = auVar52._0_12_;
      auVar59._12_2_ = uVar46;
      auVar59._14_2_ = (short)((uint)(iVar91 + 0xc) >> 0x10);
      auVar58._12_4_ = auVar59._12_4_;
      auVar58._0_10_ = auVar52._0_10_;
      auVar58._10_2_ = (short)((uint)auVar51._8_4_ >> 0x10);
      auVar57._10_6_ = auVar58._10_6_;
      auVar57._0_8_ = auVar52._0_8_;
      auVar57._8_2_ = (short)((uint)iVar50 >> 0x10);
      auVar21._2_8_ = auVar57._8_8_;
      auVar21._0_2_ = uVar48;
      auVar21._10_6_ = 0;
      auVar56._12_4_ = 0;
      auVar56._0_12_ = SUB1612(auVar21 << 0x30,4);
      auVar56 = auVar56 << 0x20;
      auVar62._0_12_ = auVar56._0_12_;
      auVar62._12_2_ = uVar48;
      auVar62._14_2_ = sVar92 + 0xc;
      auVar61._12_4_ = auVar62._12_4_;
      auVar61._0_10_ = auVar56._0_10_;
      auVar61._10_2_ = uVar47;
      auVar60._10_6_ = auVar61._10_6_;
      auVar60._0_8_ = auVar56._0_8_;
      auVar60._8_2_ = (short)(iVar89 + 0xc);
      auVar63._8_8_ = auVar60._8_8_;
      auVar63._6_2_ = sVar92 + 8;
      auVar63._4_2_ = (short)auVar51._8_4_;
      auVar63._2_2_ = (short)iVar72;
      auVar63 = auVar63 & _DAT_00267f50;
      sVar49 = auVar43._0_2_;
      cVar1 = (0 < sVar49) * (sVar49 < 0x100) * auVar43[0] - (0xff < sVar49);
      sVar49 = auVar43._2_2_;
      cVar2 = (0 < sVar49) * (sVar49 < 0x100) * auVar43[2] - (0xff < sVar49);
      sVar49 = auVar43._4_2_;
      cVar3 = (0 < sVar49) * (sVar49 < 0x100) * auVar43[4] - (0xff < sVar49);
      sVar49 = auVar43._6_2_;
      cVar4 = (0 < sVar49) * (sVar49 < 0x100) * auVar43[6] - (0xff < sVar49);
      sVar49 = auVar43._8_2_;
      cVar5 = (0 < sVar49) * (sVar49 < 0x100) * auVar43[8] - (0xff < sVar49);
      sVar49 = auVar43._10_2_;
      cVar6 = (0 < sVar49) * (sVar49 < 0x100) * auVar43[10] - (0xff < sVar49);
      sVar49 = auVar43._12_2_;
      cVar7 = (0 < sVar49) * (sVar49 < 0x100) * auVar43[0xc] - (0xff < sVar49);
      sVar49 = auVar43._14_2_;
      cVar8 = (0 < sVar49) * (sVar49 < 0x100) * auVar43[0xe] - (0xff < sVar49);
      sVar49 = auVar63._0_2_;
      cVar9 = (0 < sVar49) * (sVar49 < 0x100) * auVar63[0] - (0xff < sVar49);
      sVar49 = auVar63._2_2_;
      cVar10 = (0 < sVar49) * (sVar49 < 0x100) * auVar63[2] - (0xff < sVar49);
      sVar49 = auVar63._4_2_;
      cVar11 = (0 < sVar49) * (sVar49 < 0x100) * auVar63[4] - (0xff < sVar49);
      sVar49 = auVar63._6_2_;
      cVar12 = (0 < sVar49) * (sVar49 < 0x100) * auVar63[6] - (0xff < sVar49);
      sVar49 = auVar63._8_2_;
      cVar13 = (0 < sVar49) * (sVar49 < 0x100) * auVar63[8] - (0xff < sVar49);
      sVar49 = auVar63._10_2_;
      cVar14 = (0 < sVar49) * (sVar49 < 0x100) * auVar63[10] - (0xff < sVar49);
      sVar49 = auVar63._12_2_;
      cVar15 = (0 < sVar49) * (sVar49 < 0x100) * auVar63[0xc] - (0xff < sVar49);
      sVar49 = auVar63._14_2_;
      cVar16 = (0 < sVar49) * (sVar49 < 0x100) * auVar63[0xe] - (0xff < sVar49);
      auVar82 = SUB1615((undefined1  [16])0x0,1);
      cVar77 = -(cVar1 < '\0');
      cVar84 = -(cVar9 < '\0');
      cVar85 = -(cVar10 < auVar82[8]);
      cVar86 = -(cVar11 < auVar82[9]);
      cVar87 = -(cVar12 < auVar82[10]);
      uVar46 = CONCAT11(cVar84,cVar9);
      uVar30 = CONCAT13(cVar85,CONCAT12(cVar10,uVar46));
      uVar31 = CONCAT15(cVar86,CONCAT14(cVar11,uVar30));
      uVar33 = CONCAT17(cVar87,CONCAT16(cVar12,uVar31));
      auVar34._0_10_ = CONCAT19(-(cVar13 < auVar82[0xb]),CONCAT18(cVar13,uVar33));
      auVar34[10] = cVar14;
      auVar34[0xb] = -(cVar14 < auVar82[0xc]);
      auVar35[0xc] = cVar15;
      auVar35._0_12_ = auVar34;
      auVar35[0xd] = -(cVar15 < auVar82[0xd]);
      auVar44[0xe] = cVar16;
      auVar44._0_14_ = auVar35;
      auVar44[0xf] = -(cVar16 < auVar82[0xe]);
      sVar49 = CONCAT11(-(cVar8 < '\0'),cVar8);
      uVar26 = CONCAT31(CONCAT21(sVar49,-(cVar7 < '\0')),cVar7);
      uVar25 = CONCAT51(CONCAT41(uVar26,-(cVar6 < '\0')),cVar6);
      Var24 = CONCAT72(CONCAT61(uVar25,-(cVar5 < '\0')),CONCAT11(cVar5,cVar8));
      Var23 = CONCAT91(CONCAT81((longlong)((unkuint9)Var24 >> 8),-(cVar4 < '\0')),cVar4);
      auVar22._2_10_ = Var23;
      auVar22[1] = -(cVar3 < '\0');
      auVar22[0] = cVar3;
      auVar83._2_12_ = auVar22;
      auVar83[1] = -(cVar2 < '\0');
      auVar83[0] = cVar2;
      auVar64._0_2_ = CONCAT11(cVar77,cVar1);
      auVar64._2_14_ = auVar83;
      auVar88 = SUB1614((undefined1  [16])0x0,2);
      sVar73 = (short)Var23;
      sVar74 = (short)((unkuint9)Var24 >> 8);
      sVar75 = (short)uVar25;
      sVar76 = (short)uVar26;
      auVar81._0_12_ = auVar64._0_12_;
      auVar81._12_2_ = sVar73;
      auVar81._14_2_ = -(ushort)(sVar73 < 0);
      auVar80._12_4_ = auVar81._12_4_;
      auVar80._0_10_ = auVar64._0_10_;
      auVar80._10_2_ = -(ushort)(auVar22._0_2_ < 0);
      auVar79._10_6_ = auVar80._10_6_;
      auVar79._0_8_ = auVar64._0_8_;
      auVar79._8_2_ = auVar22._0_2_;
      auVar78._8_8_ = auVar79._8_8_;
      auVar78._6_2_ = -(ushort)(auVar83._0_2_ < 0);
      auVar78._4_2_ = auVar83._0_2_;
      auVar78._0_4_ = CONCAT22(-(ushort)(cVar77 < '\0'),auVar64._0_2_);
      uVar32 = CONCAT24(sVar75,CONCAT22(-(ushort)(sVar74 < 0),sVar74));
      auVar65._0_8_ = CONCAT26(-(ushort)(sVar75 < auVar88._8_2_),uVar32);
      auVar65._8_2_ = sVar76;
      auVar65._10_2_ = -(ushort)(sVar76 < auVar88._10_2_);
      auVar65._12_2_ = sVar49;
      auVar65._14_2_ = -(ushort)(sVar49 < auVar88._12_2_);
      uVar29 = uVar29 + 1;
      *piVar27 = auVar78._0_4_ * uVar28 * 8;
      piVar27[1] = (int)((auVar78._0_8_ >> 0x20) * (ulonglong)uVar28) << 3;
      piVar27[2] = (int)((auVar78._8_8_ & 0xffffffff) * (ulonglong)uVar28) << 3;
      piVar27[3] = (int)((auVar78._8_8_ >> 0x20) * (ulonglong)uVar28) << 3;
      piVar27[4] = (int)(((ulonglong)uVar32 & 0xffffffff) * (ulonglong)uVar28) << 3;
      piVar27[5] = (int)((auVar65._0_8_ >> 0x20) * (ulonglong)uVar28) << 3;
      piVar27[6] = (int)((auVar65._8_8_ & 0xffffffff) * (ulonglong)uVar28) << 3;
      piVar27[7] = (int)((auVar65._8_8_ >> 0x20) * (ulonglong)uVar28) << 3;
      auVar83 = SUB1614((undefined1  [16])0x0,2);
      sVar49 = (short)((unkuint10)auVar34._0_10_ >> 0x40);
      auVar71._12_2_ = (short)((ulonglong)uVar33 >> 0x30);
      auVar71._0_12_ = auVar34;
      auVar71._14_2_ = -(ushort)(cVar87 < '\0');
      auVar70._12_4_ = auVar71._12_4_;
      auVar70._10_2_ = -(ushort)(cVar86 < '\0');
      auVar70._0_10_ = auVar34._0_10_;
      auVar69._10_6_ = auVar70._10_6_;
      auVar69._8_2_ = (short)((uint6)uVar31 >> 0x20);
      auVar69._0_8_ = uVar33;
      auVar68._8_8_ = auVar69._8_8_;
      auVar68._6_2_ = -(ushort)(cVar85 < '\0');
      auVar68._0_6_ = uVar31;
      auVar67._6_10_ = auVar68._6_10_;
      auVar67._4_2_ = (short)((uint)uVar30 >> 0x10);
      auVar67._0_4_ = uVar30;
      auVar66._4_12_ = auVar67._4_12_;
      auVar66._0_4_ = CONCAT22(-(ushort)(cVar84 < '\0'),uVar46);
      uVar32 = CONCAT24(auVar34._10_2_,CONCAT22(-(ushort)(sVar49 < 0),sVar49));
      auVar45._0_8_ = CONCAT26(-(ushort)(auVar34._10_2_ < auVar83._8_2_),uVar32);
      auVar45._8_2_ = auVar35._12_2_;
      auVar45._10_2_ = -(ushort)(auVar35._12_2_ < auVar83._10_2_);
      auVar45._12_2_ = auVar44._14_2_;
      auVar45._14_2_ = -(ushort)(auVar44._14_2_ < auVar83._12_2_);
      piVar27[8] = auVar66._0_4_ * uVar28 * 8;
      piVar27[9] = (int)((auVar66._0_8_ >> 0x20) * (ulonglong)uVar28) << 3;
      piVar27[10] = (int)((auVar68._8_8_ & 0xffffffff) * (ulonglong)uVar28) << 3;
      piVar27[0xb] = (int)((auVar68._8_8_ >> 0x20) * (ulonglong)uVar28) << 3;
      piVar27[0xc] = (int)(((ulonglong)uVar32 & 0xffffffff) * (ulonglong)uVar28) << 3;
      piVar27[0xd] = (int)((auVar45._0_8_ >> 0x20) * (ulonglong)uVar28) << 3;
      piVar27[0xe] = (int)((auVar45._8_8_ & 0xffffffff) * (ulonglong)uVar28) << 3;
      piVar27[0xf] = (int)((auVar45._8_8_ >> 0x20) * (ulonglong)uVar28) << 3;
      iVar89 = iVar89 + 0x10;
      iVar90 = iVar90 + 0x10;
      iVar91 = iVar91 + 0x10;
      sVar92 = sVar92 + 0x10;
      piVar27 = piVar27 + 0x10;
    } while (uVar29 < 0x10);
                    /* WARNING: Read-only address (ram,0x00267f50) is written */
    uVar28 = uVar28 + 1;
  } while (uVar28 != 0x20);
  return;
}


// SND_MoveMouth  @ 001ac4c0
void SND_MoveMouth(channel_t *ch,sfxcache_t *sc,int count)

{
  int iVar1;
  int iVar2;
  cl_entity_t *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: char * pdata@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int savg@[???]
                       Unresolved local var: int scount@[???]
                       Unresolved local var: cl_entity_t.conflict1 * pent@[???] */
  pcVar3 = cl_entities;
  iVar1 = ch->entnum;
  uVar5 = (uint)cl_entities[iVar1].mouth.sndcount;
  iVar7 = 0;
  if ((0 < count) && (uVar5 < 10)) {
    iVar2 = ch->pos + 0x14;
    iVar4 = 0;
    do {
      uVar5 = uVar5 + 1;
      uVar6 = (int)(char)sc->data[iVar4 + iVar2 + -0x14] >> 0x1f;
      iVar7 = iVar7 + (((int)(char)sc->data[iVar4 + iVar2 + -0x14] ^ uVar6) - uVar6);
      iVar4 = iVar4 + 0x50 + (uint)(sc->data[iVar4 + iVar2 + -0x14] & 0x1f);
      if (count <= iVar4) break;
    } while ((int)uVar5 < 10);
  }
  iVar4 = cl_entities[iVar1].mouth.sndavg;
  cl_entities[iVar1].mouth.sndcount = (byte)uVar5;
  iVar7 = iVar7 + iVar4;
  pcVar3[iVar1].mouth.sndavg = iVar7;
  if (9 < (int)uVar5) {
    pcVar3[iVar1].mouth.sndcount = '\0';
    pcVar3[iVar1].mouth.mouthopen = (byte)(iVar7 / 10);
    pcVar3[iVar1].mouth.sndavg = 0;
  }
  return;
}


// SND_MoveMouth16  @ 001ac590
void SND_MoveMouth16(int entnum,short *pdata,int count)

{
  cl_entity_t *pcVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int savg@[???]
                       Unresolved local var: int scount@[???]
                       Unresolved local var: cl_entity_t.conflict1 * pent@[???] */
  pcVar1 = cl_entities;
  if ((-1 < entnum) && (entnum < cl.max_edicts)) {
    iVar5 = 0;
    uVar4 = (uint)cl_entities[entnum].mouth.sndcount;
    if ((0 < count) && (uVar4 < 10)) {
      iVar3 = 0;
      do {
        uVar2 = (uint)*(char *)((int)pdata + iVar3 * 2 + 1);
        uVar4 = uVar4 + 1;
        iVar3 = iVar3 + 0x50 + (uVar2 & 0x1f);
        iVar5 = iVar5 + (((int)uVar2 >> 0x1f ^ uVar2) - ((int)uVar2 >> 0x1f));
        if (count <= iVar3) break;
      } while ((int)uVar4 < 10);
    }
    iVar3 = cl_entities[entnum].mouth.sndavg;
    cl_entities[entnum].mouth.sndcount = (byte)uVar4;
    iVar5 = iVar5 + iVar3;
    pcVar1[entnum].mouth.sndavg = iVar5;
    if (9 < (int)uVar4) {
      pcVar1[entnum].mouth.sndcount = '\0';
      pcVar1[entnum].mouth.mouthopen = (byte)(iVar5 / 10);
      pcVar1[entnum].mouth.sndavg = 0;
    }
  }
  return;
}


// SND_PaintChannelFrom16Offs  @ 001aa540
void SND_PaintChannelFrom16Offs
               (portable_samplepair_t *paintbuffer,channel_t *ch,short *sfx,int count,int offset,
               int bVoice)

{
  portable_samplepair_t *ppVar1;
  int iVar2;
  undefined1 auVar3 [16];
  short sVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  undefined1 auVar19 [12];
  int *piVar20;
  portable_samplepair_t *ppVar21;
  portable_samplepair_t *ppVar22;
  uint uVar23;
  int iVar24;
  portable_samplepair_t *ppVar25;
  uint uVar26;
  uint6 uVar27;
  uint uVar30;
  portable_samplepair_t pVar31;
  portable_samplepair_t pVar32;
  ulonglong uVar36;
  undefined1 auVar37 [14];
  int iVar38;
  ulonglong uVar39;
  undefined1 auVar28 [12];
  undefined1 auVar29 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: int left@[???]
                       Unresolved local var: int right@[???]
                       Unresolved local var: int leftvol@[???]
                       Unresolved local var: int rightvol@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: portable_samplepair_t * pbuffer@[???] */
  uVar5 = ch->leftvol;
  uVar6 = ch->rightvol;
  if (0 < count) {
    ppVar22 = paintbuffer + offset;
    if ((sfx < paintbuffer + offset + count && ppVar22 < (portable_samplepair_t *)(sfx + count)) ||
       ((uint)count < 8)) {
      do {
        sVar4 = *sfx;
        sfx = sfx + 1;
        ppVar22->left = ppVar22->left + ((int)(uVar5 * (int)sVar4) >> 8);
        ppVar22->right = ppVar22->right + ((int)((int)sVar4 * uVar6) >> 8);
        ppVar22 = ppVar22 + 1;
      } while (ppVar22 != paintbuffer + count + offset);
    }
    else {
      uVar23 = (count - 8U >> 3) + 1;
      iVar24 = uVar23 * 8;
      ppVar25 = ppVar22 + 2;
      uVar26 = 0;
      do {
        piVar20 = &ppVar25->left;
        iVar8 = ppVar25->right;
        iVar9 = ppVar25[1].left;
        iVar10 = ppVar25[1].right;
        iVar11 = ppVar25[2].left;
        iVar12 = ppVar25[2].right;
        iVar13 = ppVar25[3].left;
        iVar14 = ppVar25[3].right;
        auVar3 = *(undefined1 (*) [16])(sfx + uVar26 * 8);
        auVar37 = SUB1614((undefined1  [16])0x0,2);
        auVar35._0_12_ = auVar3._0_12_;
        auVar35._12_2_ = auVar3._6_2_;
        auVar35._14_2_ = -(ushort)(auVar3._6_2_ < 0);
        auVar34._12_4_ = auVar35._12_4_;
        auVar34._0_10_ = auVar3._0_10_;
        auVar34._10_2_ = -(ushort)(auVar3._4_2_ < 0);
        auVar33._10_6_ = auVar34._10_6_;
        auVar33._0_8_ = auVar3._0_8_;
        auVar33._8_2_ = auVar3._4_2_;
        uVar36 = auVar33._8_8_;
        auVar19._4_8_ = uVar36;
        auVar19._2_2_ = -(ushort)(auVar3._2_2_ < 0);
        auVar19._0_2_ = auVar3._2_2_;
        uVar30 = CONCAT22(-(ushort)(auVar3._0_2_ < 0),auVar3._0_2_);
        iVar15 = ppVar25[4].left;
        iVar16 = ppVar25[4].right;
        iVar17 = ppVar25[5].left;
        iVar18 = ppVar25[5].right;
        uVar27 = CONCAT24(auVar3._10_2_,CONCAT22(-(ushort)(auVar3._8_2_ < 0),auVar3._8_2_));
        auVar28._0_8_ = CONCAT26(-(ushort)(auVar3._10_2_ < auVar37._8_2_),uVar27);
        auVar28._8_2_ = auVar3._12_2_;
        auVar28._10_2_ = -(ushort)(auVar3._12_2_ < auVar37._10_2_);
        auVar29._12_2_ = auVar3._14_2_;
        auVar29._0_12_ = auVar28;
        auVar29._14_2_ = -(ushort)(auVar3._14_2_ < auVar37._12_2_);
        ppVar1 = ppVar25 + -2;
        ppVar21 = ppVar25 + -2;
        iVar2 = ppVar25[-1].left;
        iVar7 = ppVar25[-1].right;
        uVar39 = auVar29._8_8_;
        iVar38 = (int)((ulonglong)auVar28._0_8_ >> 0x20);
        uVar26 = uVar26 + 1;
        ppVar25 = ppVar25 + 8;
        pVar31.right = ppVar21->right + ((int)(uVar30 * uVar6) >> 8);
        pVar31.left = ((int)((ulonglong)uVar5 * (ulonglong)uVar30) >> 8) + ppVar1->left;
        ppVar22[2].left = ((int)((ulonglong)uVar5 * (uVar36 & 0xffffffff)) >> 8) + *piVar20;
        ppVar22[2].right = iVar8 + ((int)((uVar36 & 0xffffffff) * (ulonglong)uVar6) >> 8);
        ppVar22[3].left = ((int)((ulonglong)uVar5 * (uVar36 >> 0x20)) >> 8) + iVar9;
        ppVar22[3].right = iVar10 + ((int)((uVar36 >> 0x20) * (ulonglong)uVar6) >> 8);
        *ppVar22 = pVar31;
        ppVar22[1].left = ((int)(uVar5 * auVar19._0_4_) >> 8) + iVar2;
        ppVar22[1].right = iVar7 + ((int)(auVar19._0_4_ * uVar6) >> 8);
        pVar32.right = ((int)(((ulonglong)uVar27 & 0xffffffff) * (ulonglong)uVar6) >> 8) + iVar12;
        pVar32.left = iVar11 + ((int)((ulonglong)uVar5 * ((ulonglong)uVar27 & 0xffffffff)) >> 8);
        ppVar22[6].left = iVar15 + ((int)((ulonglong)uVar5 * (ulonglong)auVar28._8_4_) >> 8);
        ppVar22[6].right = ((int)((uVar39 & 0xffffffff) * (ulonglong)uVar6) >> 8) + iVar16;
        ppVar22[7].left = iVar17 + ((int)((ulonglong)uVar5 * (uVar39 >> 0x20)) >> 8);
        ppVar22[7].right = ((int)((uVar39 >> 0x20) * (ulonglong)uVar6) >> 8) + iVar18;
        ppVar22[4] = pVar32;
        ppVar22[5].left = iVar13 + ((int)(uVar5 * iVar38) >> 8);
        ppVar22[5].right = ((int)(iVar38 * uVar6) >> 8) + iVar14;
        ppVar22 = ppVar22 + 8;
      } while (uVar26 < uVar23);
      if (count != iVar24) {
        sVar4 = sfx[uVar23 * 8];
        ppVar22 = paintbuffer + uVar23 * 8 + offset;
        ppVar22->left = ppVar22->left + ((int)(uVar5 * (int)sVar4) >> 8);
        ppVar22->right = ppVar22->right + ((int)((int)sVar4 * uVar6) >> 8);
        iVar2 = iVar24 + 1;
        if (iVar2 < count) {
          sVar4 = sfx[iVar2];
          ppVar22 = paintbuffer + iVar2 + offset;
          ppVar22->left = ppVar22->left + ((int)(uVar5 * (int)sVar4) >> 8);
          ppVar22->right = ppVar22->right + ((int)((int)sVar4 * uVar6) >> 8);
          iVar2 = iVar24 + 2;
          if (iVar2 < count) {
            sVar4 = sfx[iVar2];
            ppVar22 = paintbuffer + iVar2 + offset;
            ppVar22->left = ppVar22->left + ((int)(uVar5 * (int)sVar4) >> 8);
            ppVar22->right = ppVar22->right + ((int)((int)sVar4 * uVar6) >> 8);
            iVar2 = iVar24 + 3;
            if (iVar2 < count) {
              sVar4 = sfx[iVar2];
              ppVar22 = paintbuffer + iVar2 + offset;
              ppVar22->left = ppVar22->left + ((int)(uVar5 * (int)sVar4) >> 8);
              ppVar22->right = ppVar22->right + ((int)((int)sVar4 * uVar6) >> 8);
              iVar2 = iVar24 + 4;
              if (iVar2 < count) {
                sVar4 = sfx[iVar2];
                ppVar22 = paintbuffer + iVar2 + offset;
                ppVar22->left = ppVar22->left + ((int)(uVar5 * (int)sVar4) >> 8);
                ppVar22->right = ppVar22->right + ((int)((int)sVar4 * uVar6) >> 8);
                iVar2 = iVar24 + 5;
                if (iVar2 < count) {
                  iVar24 = iVar24 + 6;
                  sVar4 = sfx[iVar2];
                  ppVar22 = paintbuffer + iVar2 + offset;
                  ppVar22->left = ppVar22->left + ((int)(uVar5 * (int)sVar4) >> 8);
                  ppVar22->right = ppVar22->right + ((int)((int)sVar4 * uVar6) >> 8);
                  if (iVar24 < count) {
                    sVar4 = sfx[iVar24];
                    ppVar22 = paintbuffer + iVar24 + offset;
                    ppVar22->left = ppVar22->left + ((int)(uVar5 * (int)sVar4) >> 8);
                    ppVar22->right = ppVar22->right + ((int)((int)sVar4 * uVar6) >> 8);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  ch->pos = ch->pos + count;
  return;
}


// SND_PaintChannelFrom8  @ 001aa3c0
void SND_PaintChannelFrom8(channel_t *ch,sfxcache_t *sc,int count)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: int * lscale@[???]
                       Unresolved local var: int * rscale@[???]
                       Unresolved local var: uchar * sfx@[???]
                       Unresolved local var: int i@[???] */
  if (ch->leftvol < 0x100) {
    iVar2 = ch->leftvol >> 3;
  }
  else {
    ch->leftvol = 0xff;
    iVar2 = 0x1f;
  }
  if (ch->rightvol < 0x100) {
    iVar3 = ch->rightvol >> 3;
  }
  else {
    ch->rightvol = 0xff;
    iVar3 = 0x1f;
  }
  iVar5 = ch->pos;
  if (0 < count) {
    iVar4 = 0;
    do {
      iVar1 = snd_scaletable[iVar3][sc->data[iVar4 + iVar5]];
      paintbuffer[iVar4].left =
           paintbuffer[iVar4].left + snd_scaletable[iVar2][sc->data[iVar4 + iVar5]];
      paintbuffer[iVar4].right = paintbuffer[iVar4].right + iVar1;
      iVar4 = iVar4 + 1;
    } while (count != iVar4);
    iVar5 = ch->pos;
  }
  ch->pos = iVar5 + count;
  return;
}


// SND_PaintChannelFrom8Offs  @ 001aa470
void SND_PaintChannelFrom8Offs
               (portable_samplepair_t *paintbuffer,channel_t *ch,sfxcache_t *sc,int count,int offset
               )

{
  byte bVar1;
  portable_samplepair_t *ppVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: int * lscale@[???]
                       Unresolved local var: int * rscale@[???]
                       Unresolved local var: uchar * sfx@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: portable_samplepair_t * pbuffer@[???] */
  if (ch->leftvol < 0x100) {
    iVar5 = ch->leftvol >> 3;
  }
  else {
    ch->leftvol = 0xff;
    iVar5 = 0x1f;
  }
  if (ch->rightvol < 0x100) {
    iVar6 = ch->rightvol >> 3;
  }
  else {
    ch->rightvol = 0xff;
    iVar6 = 0x1f;
  }
  iVar3 = ch->pos;
  if (0 < count) {
    pbVar4 = sc->data + iVar3;
    ppVar2 = paintbuffer + offset;
    do {
      bVar1 = *pbVar4;
      pbVar4 = pbVar4 + 1;
      ppVar2->left = ppVar2->left + snd_scaletable[iVar5][bVar1];
      ppVar2->right = ppVar2->right + snd_scaletable[iVar6][bVar1];
      ppVar2 = ppVar2 + 1;
    } while (paintbuffer + count + offset != ppVar2);
    iVar3 = ch->pos;
  }
  ch->pos = iVar3 + count;
  return;
}


// SND_PickDynamicChannel  @ 001a6c10
channel_t * SND_PickDynamicChannel(int entnum,int entchannel,sfx_t *sfx)

{
  int *piVar1;
  FileHandle_t *ppvVar2;
  int iVar3;
  int iVar4;
  int local_28;
  int local_24;
  
                    /* Unresolved local var: int ch_idx@[???]
                       Unresolved local var: int first_to_die@[???]
                       Unresolved local var: int life_left@[???] */
  if (entchannel == 5) {
                    /* Unresolved local var: int ch_idx@[???] */
    if (4 < total_channels) {
      if (sfx == channels[4].sfx) {
        return (channel_t *)0x0;
      }
      iVar4 = 4;
      while (iVar4 = iVar4 + 1, total_channels != iVar4) {
        if (sfx == channels[iVar4].sfx) {
          return (channel_t *)0x0;
        }
      }
    }
  }
  else {
    if (entchannel == 2) {
      piVar1 = &channels[4].entchannel;
      local_28 = 0x7fffffff;
      ppvVar2 = &wavstreams[4].hFile;
      local_24 = -1;
      iVar4 = 4;
      do {
        if (*piVar1 == 5) {
          if (*ppvVar2 != (FileHandle_t)0x0) {
            return (channel_t *)0x0;
          }
          iVar3 = piVar1[-1];
        }
        else {
          iVar3 = piVar1[-1];
          if ((iVar3 == entnum) && (*piVar1 == 2)) goto LAB_001a6cdb;
        }
        if ((((iVar3 != cl.viewentity) || (entnum == cl.viewentity)) ||
            (((channel_t *)(piVar1 + -7))->sfx == (sfx_t *)0x0)) &&
           (piVar1[-4] - paintedtime < local_28)) {
          local_28 = piVar1[-4] - paintedtime;
          local_24 = iVar4;
        }
        iVar4 = iVar4 + 1;
        piVar1 = piVar1 + 0x10;
        ppvVar2 = ppvVar2 + 10;
      } while (iVar4 != 0x24);
      goto LAB_001a6cd0;
    }
    if (entchannel == 0) {
      local_24 = -1;
      piVar1 = &channels[4].entchannel;
      iVar4 = 0x7fffffff;
      iVar3 = 4;
      ppvVar2 = &wavstreams[4].hFile;
      do {
        while ((*piVar1 != 5 || (*ppvVar2 == (FileHandle_t)0x0))) {
          if ((((piVar1[-1] != cl.viewentity) || (entnum == cl.viewentity)) ||
              (((channel_t *)(piVar1 + -7))->sfx == (sfx_t *)0x0)) &&
             (piVar1[-4] - paintedtime < iVar4)) {
            iVar4 = piVar1[-4] - paintedtime;
            local_24 = iVar3;
          }
          iVar3 = iVar3 + 1;
          piVar1 = piVar1 + 0x10;
          ppvVar2 = ppvVar2 + 10;
          if (iVar3 == 0x24) goto LAB_001a6cd0;
        }
        iVar3 = iVar3 + 1;
        piVar1 = piVar1 + 0x10;
        ppvVar2 = ppvVar2 + 10;
      } while (iVar3 != 0x24);
      goto LAB_001a6cd0;
    }
  }
  local_28 = 0x7fffffff;
  piVar1 = &channels[4].entchannel;
  ppvVar2 = &wavstreams[4].hFile;
  local_24 = -1;
  iVar4 = 4;
  do {
    if (*piVar1 == 5) {
      if (*ppvVar2 == (FileHandle_t)0x0) {
        iVar3 = piVar1[-1];
        goto joined_r0x001a6d97;
      }
    }
    else {
      iVar3 = piVar1[-1];
joined_r0x001a6d97:
      if ((entnum == iVar3) && ((entchannel == -1 || (entchannel == *piVar1)))) goto LAB_001a6cdb;
      if (((iVar3 != cl.viewentity) ||
          ((entnum == cl.viewentity || (((channel_t *)(piVar1 + -7))->sfx == (sfx_t *)0x0)))) &&
         (piVar1[-4] - paintedtime < local_28)) {
        local_28 = piVar1[-4] - paintedtime;
        local_24 = iVar4;
      }
    }
    iVar4 = iVar4 + 1;
    piVar1 = piVar1 + 0x10;
    ppvVar2 = ppvVar2 + 10;
  } while (iVar4 != 0x24);
LAB_001a6cd0:
  iVar4 = local_24;
  if (local_24 == -1) {
    return (channel_t *)0x0;
  }
LAB_001a6cdb:
  local_24 = iVar4;
  if (channels[local_24].sfx != (sfx_t *)0x0) {
    S_FreeChannel(channels + local_24);
    channels[local_24].sfx = (sfx_t *)0x0;
  }
  return channels + local_24;
}


// SND_PickStaticChannel  @ 001a6ee0
channel_t * SND_PickStaticChannel(int entnum,int entchannel,sfx_t *sfx)

{
  sfx_t *psVar1;
  int iVar2;
  channel_t *pcVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: channel_t * ch@[???] */
                    /* Unresolved local var: int ch_idx@[???] */
  if (sfx->name[0] == '*') {
    if (4 < total_channels) {
      if (channels[4].sfx != sfx) {
        iVar2 = 4;
        do {
          iVar2 = iVar2 + 1;
          if (total_channels == iVar2) goto LAB_001a6ef3;
        } while (sfx != channels[iVar2].sfx);
      }
      return (channel_t *)0x0;
    }
  }
  else {
LAB_001a6ef3:
    if (0x24 < total_channels) {
      iVar2 = 0x24;
      psVar1 = channels[0x24].sfx;
      while( true ) {
        if (psVar1 == (sfx_t *)0x0) {
          return channels + iVar2;
        }
        iVar2 = iVar2 + 1;
        if (total_channels == iVar2) break;
        psVar1 = channels[iVar2].sfx;
      }
      if (total_channels == 0x80) {
        Con_DPrintf("total_channels == MAX_CHANNELS\n");
        return (channel_t *)0x0;
      }
    }
  }
  pcVar3 = channels + total_channels;
  total_channels = total_channels + 1;
  return pcVar3;
}


// SND_Spatialize  @ 001a6fa0
void SND_Spatialize(channel_t *ch)

{
  int iVar1;
  model_s *pmVar2;
  float fVar3;
  float fVar4;
  cl_entity_t *pcVar5;
  float fVar6;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: vec_t dot@[???]
                       Unresolved local var: vec_t dist@[???]
                       Unresolved local var: vec_t lscale@[???]
                       Unresolved local var: vec_t rscale@[???]
                       Unresolved local var: vec_t scale@[???]
                       Unresolved local var: vec3_t source_vec@[???]
                       Unresolved local var: sfx_t * snd@[???]
                       Unresolved local var: cl_entity_t.conflict * pent@[???] */
  iVar1 = ch->entnum;
  if (iVar1 == cl.viewentity) {
    ch->leftvol = ch->master_vol;
    ch->rightvol = ch->master_vol;
    VOX_SetChanVol(ch);
  }
  else {
    if ((((iVar1 < 1) || (cl.num_entities <= iVar1)) ||
        (pcVar5 = cl_entities + iVar1, pcVar5 == (cl_entity_t *)0x0)) ||
       ((pcVar5->model == (model_s *)0x0 || ((pcVar5->curstate).messagenum != cl.parsecount)))) {
      local_18 = ch->origin[0];
      local_14 = ch->origin[1];
      local_10 = ch->origin[2];
    }
    else {
      local_18 = pcVar5->origin[0];
      ch->origin[0] = local_18;
      local_14 = pcVar5->origin[1];
      ch->origin[1] = local_14;
      local_10 = pcVar5->origin[2];
      ch->origin[2] = local_10;
      pmVar2 = pcVar5->model;
      if (pmVar2->type == mod_brush) {
        local_18 = local_18 + (pmVar2->mins[0] + pmVar2->maxs[0]) * 0.5;
        ch->origin[0] = local_18;
        local_14 = (pcVar5->model->mins[1] + pcVar5->model->maxs[1]) * 0.5 + local_14;
        ch->origin[1] = local_14;
        local_10 = local_10 + (pcVar5->model->mins[2] + pcVar5->model->maxs[2]) * 0.5;
        ch->origin[2] = local_10;
      }
    }
    local_18 = local_18 - listener_origin[0];
    local_14 = local_14 - listener_origin[1];
    local_10 = local_10 - listener_origin[2];
    fVar6 = VectorNormalize(&local_18);
    fVar4 = listener_right[2] * local_10 +
            listener_right[1] * local_14 + listener_right[0] * local_18;
    if ((shm == (dma_t *)0x0) || (shm->channels != 1)) {
      fVar3 = fVar4 + 1.0;
      fVar4 = 1.0 - fVar4;
    }
    else {
      fVar3 = 1.0;
      fVar4 = fVar3;
    }
    fVar6 = 1.0 - fVar6 * ch->dist_mult;
    ch->rightvol = (int)(fVar3 * fVar6 * (float)ch->master_vol);
    ch->leftvol = (int)(fVar6 * fVar4 * (float)ch->master_vol);
    VOX_SetChanVol(ch);
    if (ch->rightvol < 0) {
      ch->rightvol = 0;
    }
    if (ch->leftvol < 0) {
      ch->leftvol = 0;
      return;
    }
  }
  return;
}


