// Sequence_AddCommandLineToEntry  @ 001dad00
void Sequence_AddCommandLineToEntry(sequenceCommandLine_s *commandLine,sequenceEntry_s *entry)

{
  sequenceCommandLine_s *psVar1;
  sequenceCommandLine_s *psVar2;
  
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???] */
  psVar1 = entry->firstCommand;
  if (entry->firstCommand != (sequenceCommandLine_s *)0x0) {
    do {
      psVar2 = psVar1;
      psVar1 = psVar2->nextCommandLine;
    } while (psVar1 != (sequenceCommandLine_s *)0x0);
    psVar2->nextCommandLine = commandLine;
    commandLine->nextCommandLine = (sequenceCommandLine_s *)0x0;
    return;
  }
  entry->firstCommand = commandLine;
  commandLine->nextCommandLine = (sequenceCommandLine_s *)0x0;
  return;
}


// Sequence_AddSentenceGroup  @ 001db8b0
sentenceGroupEntry_s * Sequence_AddSentenceGroup(char *groupName)

{
  sentenceGroupEntry_s *psVar1;
  sentenceGroupEntry_s *psVar2;
  char *pcVar3;
  sentenceGroupEntry_s *psVar4;
  
                    /* Unresolved local var: sentenceGroupEntry_s * newEntry@[???]
                       Unresolved local var: sentenceGroupEntry_s * lastEntry@[???] */
  psVar1 = g_sentenceGroupList;
  psVar2 = Mem_Malloc(0x10);
  pcVar3 = Mem_Strdup(groupName);
  psVar2->numSentences = 0;
  psVar2->firstSentence = (sentenceEntry_s *)0x0;
  psVar2->nextEntry = (sentenceGroupEntry_s *)0x0;
  psVar2->groupName = pcVar3;
  if (psVar1 != (sentenceGroupEntry_s *)0x0) {
    do {
      psVar4 = psVar1;
      psVar1 = psVar4->nextEntry;
    } while (psVar1 != (sentenceGroupEntry_s *)0x0);
    psVar4->nextEntry = psVar2;
    return psVar2;
  }
  g_sentenceGroupList = psVar2;
  return psVar2;
}


// Sequence_AddSentenceToGroup  @ 001db920
void Sequence_AddSentenceToGroup(char *groupName,char *data)

{
  sentenceGroupEntry_s **ppsVar1;
  sentenceEntry_s *psVar2;
  sentenceGroupEntry_s *psVar3;
  int iVar4;
  sentenceEntry_s *psVar5;
  char *pcVar6;
  sentenceGroupEntry_s *psVar7;
  sentenceEntry_s *psVar8;
  sentenceGroupEntry_s *psVar9;
  
                    /* Unresolved local var: sentenceEntry_s * newEntry@[???]
                       Unresolved local var: sentenceEntry_s * lastEntry@[???]
                       Unresolved local var: sentenceGroupEntry_s * groupEntry@[???] */
  psVar3 = g_sentenceGroupList;
                    /* Unresolved local var: sentenceGroupEntry_s * groupEntry@[???] */
  psVar7 = g_sentenceGroupList;
  if (g_sentenceGroupList == (sentenceGroupEntry_s *)0x0) {
    psVar7 = Mem_Malloc(0x10);
    pcVar6 = Mem_Strdup(groupName);
    psVar7->numSentences = 0;
    psVar7->firstSentence = (sentenceEntry_s *)0x0;
    psVar7->nextEntry = (sentenceGroupEntry_s *)0x0;
    psVar7->groupName = pcVar6;
    g_sentenceGroupList = psVar7;
  }
  else {
    do {
      iVar4 = strcasecmp(psVar7->groupName,groupName);
      if (iVar4 == 0) goto LAB_001db959;
      ppsVar1 = &psVar7->nextEntry;
      psVar7 = *ppsVar1;
    } while (*ppsVar1 != (sentenceGroupEntry_s *)0x0);
                    /* Unresolved local var: sentenceGroupEntry_s * newEntry@[???]
                       Unresolved local var: sentenceGroupEntry_s * lastEntry@[???] */
    psVar7 = Mem_Malloc(0x10);
    pcVar6 = Mem_Strdup(groupName);
    psVar7->numSentences = 0;
    psVar7->firstSentence = (sentenceEntry_s *)0x0;
    psVar7->nextEntry = (sentenceGroupEntry_s *)0x0;
    psVar7->groupName = pcVar6;
    do {
      psVar9 = psVar3;
      psVar3 = psVar9->nextEntry;
    } while (psVar3 != (sentenceGroupEntry_s *)0x0);
    psVar9->nextEntry = psVar7;
  }
LAB_001db959:
  psVar5 = Mem_Malloc(0x10);
  pcVar6 = Mem_Strdup(data);
  psVar5->nextEntry = (sentenceEntry_s *)0x0;
  psVar5->data = pcVar6;
  psVar5->isGlobal = g_sequenceParseFileIsGlobal;
  psVar5->index = g_nonGlobalSentences;
  g_nonGlobalSentences = g_nonGlobalSentences + 1;
  psVar7->numSentences = psVar7->numSentences + 1;
  psVar2 = psVar7->firstSentence;
  if (psVar7->firstSentence != (sentenceEntry_s *)0x0) {
    do {
      psVar8 = psVar2;
      psVar2 = psVar8->nextEntry;
    } while (psVar2 != (sentenceEntry_s *)0x0);
    psVar8->nextEntry = psVar5;
    return;
  }
  psVar7->firstSentence = psVar5;
  return;
}


// Sequence_BakeDefaults  @ 001d9020
void __regparm3
Sequence_BakeDefaults(sequenceCommandLine_s *destination,sequenceCommandLine_s *source)

{
  char *pcVar1;
  
  if (destination == (sequenceCommandLine_s *)0x0) {
    Sys_Error("Attempt to bake defaults into a non-existant command.");
  }
  (destination->clientMessage).effect = g_blockScopeDefaults.clientMessage.effect;
  (destination->clientMessage).r1 = g_blockScopeDefaults.clientMessage.r1;
  (destination->clientMessage).g1 = g_blockScopeDefaults.clientMessage.g1;
  (destination->clientMessage).b1 = g_blockScopeDefaults.clientMessage.b1;
  (destination->clientMessage).a1 = g_blockScopeDefaults.clientMessage.a1;
  (destination->clientMessage).r2 = g_blockScopeDefaults.clientMessage.r2;
  (destination->clientMessage).g2 = g_blockScopeDefaults.clientMessage.g2;
  (destination->clientMessage).b2 = g_blockScopeDefaults.clientMessage.b2;
  (destination->clientMessage).a2 = g_blockScopeDefaults.clientMessage.a2;
  (destination->clientMessage).x = g_blockScopeDefaults.clientMessage.x;
  (destination->clientMessage).y = g_blockScopeDefaults.clientMessage.y;
  (destination->clientMessage).fadein = g_blockScopeDefaults.clientMessage.fadein;
  (destination->clientMessage).fadeout = g_blockScopeDefaults.clientMessage.fadeout;
  (destination->clientMessage).holdtime = g_blockScopeDefaults.clientMessage.holdtime;
  (destination->clientMessage).fxtime = g_blockScopeDefaults.clientMessage.fxtime;
  destination->textChannel = g_blockScopeDefaults.textChannel;
  if (destination->speakerName != (char *)0x0) {
    Mem_Free(destination->speakerName);
  }
  pcVar1 = Mem_Strdup(g_blockScopeDefaults.speakerName);
  destination->speakerName = pcVar1;
  if (destination->listenerName != (char *)0x0) {
    Mem_Free(destination->listenerName);
  }
  pcVar1 = Mem_Strdup(g_blockScopeDefaults.listenerName);
  destination->listenerName = pcVar1;
  return;
}


// Sequence_BakeDefaults  @ 001d96e0
void Sequence_BakeDefaults(sequenceCommandLine_s *destination,sequenceCommandLine_s *source)

{
  char *pcVar1;
  
  if (destination == (sequenceCommandLine_s *)0x0) {
    Sys_Error("Attempt to bake defaults into a non-existant command.");
  }
  if (source == (sequenceCommandLine_s *)0x0) {
    Sys_Error("Attempt to bake defaults from a non-existant command.");
  }
  (destination->clientMessage).effect = (source->clientMessage).effect;
  (destination->clientMessage).r1 = (source->clientMessage).r1;
  (destination->clientMessage).g1 = (source->clientMessage).g1;
  (destination->clientMessage).b1 = (source->clientMessage).b1;
  (destination->clientMessage).a1 = (source->clientMessage).a1;
  (destination->clientMessage).r2 = (source->clientMessage).r2;
  (destination->clientMessage).g2 = (source->clientMessage).g2;
  (destination->clientMessage).b2 = (source->clientMessage).b2;
  (destination->clientMessage).a2 = (source->clientMessage).a2;
  (destination->clientMessage).x = (source->clientMessage).x;
  (destination->clientMessage).y = (source->clientMessage).y;
  (destination->clientMessage).fadein = (source->clientMessage).fadein;
  (destination->clientMessage).fadeout = (source->clientMessage).fadeout;
  (destination->clientMessage).holdtime = (source->clientMessage).holdtime;
  (destination->clientMessage).fxtime = (source->clientMessage).fxtime;
  destination->textChannel = source->textChannel;
  if (destination->speakerName != (char *)0x0) {
    Mem_Free(destination->speakerName);
  }
  pcVar1 = Mem_Strdup(source->speakerName);
  destination->speakerName = pcVar1;
  if (destination->listenerName != (char *)0x0) {
    Mem_Free(destination->listenerName);
  }
  pcVar1 = Mem_Strdup(source->listenerName);
  destination->listenerName = pcVar1;
  return;
}


// Sequence_CalcEntryDuration  @ 001db280
float Sequence_CalcEntryDuration(sequenceEntry_s *entry)

{
  sequenceCommandLine_s *psVar1;
  float fVar2;
  
                    /* Unresolved local var: float duration@[???]
                       Unresolved local var: sequenceCommandLine_s * cmd@[???] */
  fVar2 = 0.0;
  for (psVar1 = entry->firstCommand; psVar1 != (sequenceCommandLine_s *)0x0;
      psVar1 = psVar1->nextCommandLine) {
    fVar2 = fVar2 + psVar1->delay;
  }
  return fVar2;
}


// Sequence_ConfirmCarriageReturnOrSymbol  @ 001d9f90
/* WARNING: Variable defined which should be unmapped: foundCarriageReturn */

qboolean Sequence_ConfirmCarriageReturnOrSymbol(char symbol)

{
  char cVar1;
  bool bVar2;
  ushort **ppuVar3;
  qboolean qVar4;
  char *pcVar5;
  qboolean foundCarriageReturn;
  
                    /* Unresolved local var: qboolean passedCarriageReturn@[???] */
  bVar2 = false;
  ppuVar3 = __ctype_b_loc();
  while( true ) {
    pcVar5 = g_scan + 1;
    cVar1 = *g_scan;
    if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
    g_scan = pcVar5;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      bVar2 = true;
      g_lineScan = pcVar5;
    }
  }
  qVar4 = true;
  if (!bVar2) {
    qVar4 = (qboolean)(symbol == cVar1);
  }
  return qVar4;
}


// Sequence_CopyCommand  @ 001dc050
sequenceCommandLine_s * Sequence_CopyCommand(sequenceCommandLine_s *commandOrig)

{
  sequenceCommandLine_s *psVar1;
  char *pcVar2;
  
                    /* Unresolved local var: sequenceCommandLine_s * commandCopy@[???] */
  psVar1 = Mem_ZeroMalloc(0x5c);
  psVar1->nextCommandLine = (sequenceCommandLine_s *)0x0;
  psVar1->commandType = commandOrig->commandType;
  psVar1->modifierBitField = commandOrig->modifierBitField;
  psVar1->repeatCount = commandOrig->repeatCount;
  psVar1->delay = commandOrig->delay;
  psVar1->textChannel = commandOrig->textChannel;
  pcVar2 = Mem_Strdup(commandOrig->fireTargetNames);
  psVar1->fireTargetNames = pcVar2;
  pcVar2 = Mem_Strdup(commandOrig->killTargetNames);
  psVar1->killTargetNames = pcVar2;
  pcVar2 = Mem_Strdup(commandOrig->listenerName);
  psVar1->listenerName = pcVar2;
  pcVar2 = Mem_Strdup(commandOrig->sentenceName);
  psVar1->sentenceName = pcVar2;
  pcVar2 = Mem_Strdup(commandOrig->soundFileName);
  psVar1->soundFileName = pcVar2;
  pcVar2 = Mem_Strdup(commandOrig->speakerName);
  psVar1->speakerName = pcVar2;
  (psVar1->clientMessage).effect = (commandOrig->clientMessage).effect;
  (psVar1->clientMessage).a1 = (commandOrig->clientMessage).a1;
  (psVar1->clientMessage).b1 = (commandOrig->clientMessage).b1;
  (psVar1->clientMessage).a2 = (commandOrig->clientMessage).a2;
  (psVar1->clientMessage).b2 = (commandOrig->clientMessage).b2;
  (psVar1->clientMessage).fadein = (commandOrig->clientMessage).fadein;
  (psVar1->clientMessage).fadeout = (commandOrig->clientMessage).fadeout;
  (psVar1->clientMessage).fxtime = (commandOrig->clientMessage).fxtime;
  (psVar1->clientMessage).g1 = (commandOrig->clientMessage).g1;
  (psVar1->clientMessage).g2 = (commandOrig->clientMessage).g2;
  (psVar1->clientMessage).holdtime = (commandOrig->clientMessage).holdtime;
  (psVar1->clientMessage).r1 = (commandOrig->clientMessage).r1;
  (psVar1->clientMessage).r2 = (commandOrig->clientMessage).r2;
  (psVar1->clientMessage).x = (commandOrig->clientMessage).x;
  (psVar1->clientMessage).y = (commandOrig->clientMessage).y;
  pcVar2 = Mem_Strdup((commandOrig->clientMessage).pMessage);
  (psVar1->clientMessage).pMessage = pcVar2;
  pcVar2 = Mem_Strdup((commandOrig->clientMessage).pName);
  (psVar1->clientMessage).pName = pcVar2;
  return psVar1;
}


// Sequence_CopyCommandList  @ 001dc170
sequenceCommandLine_s * Sequence_CopyCommandList(sequenceCommandLine_s *list)

{
  sequenceCommandLine_s *psVar1;
  sequenceCommandLine_s *psVar2;
  sequenceCommandLine_s *psVar3;
  sequenceCommandLine_s *psVar4;
  
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???]
                       Unresolved local var: sequenceCommandLine_s * copyCommand@[???]
                       Unresolved local var: sequenceCommandLine_s * newCommandList@[???]
                       Unresolved local var: sequenceCommandLine_s * prevCommand@[???] */
  psVar3 = (sequenceCommandLine_s *)0x0;
  if (list != (sequenceCommandLine_s *)0x0) {
    psVar2 = (sequenceCommandLine_s *)0x0;
    psVar4 = (sequenceCommandLine_s *)0x0;
    do {
      psVar1 = psVar2;
      psVar3 = psVar4;
      if ((list->commandType != 8) &&
         (psVar1 = Sequence_CopyCommand(list), psVar3 = psVar1,
         psVar2 != (sequenceCommandLine_s *)0x0)) {
        psVar2->nextCommandLine = psVar1;
        psVar3 = psVar4;
      }
      list = list->nextCommandLine;
      psVar2 = psVar1;
      psVar4 = psVar3;
    } while (list != (sequenceCommandLine_s *)0x0);
  }
  return psVar3;
}


// Sequence_CreateDefaultsCommand  @ 001db340
void Sequence_CreateDefaultsCommand(sequenceEntry_s *entry)

{
  sequenceCommandLine_s *psVar1;
  sequenceCommandLine_s *destination;
  sequenceCommandLine_s *psVar2;
  
                    /* Unresolved local var: sequenceCommandLine_s * defaultsCommand@[???] */
  destination = Mem_ZeroMalloc(0x5c);
  Sequence_ResetDefaults(destination,&g_fileScopeDefaults);
  destination->commandType = 8;
  destination->modifierBitField = 0xff;
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???] */
  psVar1 = entry->firstCommand;
  if (entry->firstCommand != (sequenceCommandLine_s *)0x0) {
    do {
      psVar2 = psVar1;
      psVar1 = psVar2->nextCommandLine;
    } while (psVar1 != (sequenceCommandLine_s *)0x0);
    psVar2->nextCommandLine = destination;
    destination->nextCommandLine = (sequenceCommandLine_s *)0x0;
    return;
  }
  entry->firstCommand = destination;
  destination->nextCommandLine = (sequenceCommandLine_s *)0x0;
  return;
}


// Sequence_DoesEntryContainInfiniteLoop  @ 001db2a0
qboolean Sequence_DoesEntryContainInfiniteLoop(sequenceEntry_s *entry)

{
  qboolean qVar1;
  sequenceCommandLine_s *psVar2;
  
                    /* Unresolved local var: sequenceCommandLine_s * cmd@[???] */
  psVar2 = entry->firstCommand;
  qVar1 = false;
  if (psVar2 != (sequenceCommandLine_s *)0x0) {
    if (psVar2->repeatCount < 0) {
      return true;
    }
    do {
      psVar2 = psVar2->nextCommandLine;
      if (psVar2 == (sequenceCommandLine_s *)0x0) {
        return false;
      }
    } while (-1 < psVar2->repeatCount);
    qVar1 = true;
  }
  return qVar1;
}


// Sequence_ExpandAllGosubs  @ 001dc360
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sequence_ExpandAllGosubs(void)

{
  bool bVar1;
  qboolean qVar2;
  sequenceEntry_s *entry;
  
  do {
    if (g_sequenceList == (sequenceEntry_s *)0x0) {
      return;
    }
    bVar1 = false;
    entry = g_sequenceList;
    do {
      qVar2 = Sequence_ExpandGosubsForEntry(entry);
      entry = entry->nextEntry;
      if (qVar2 == false) {
        bVar1 = true;
      }
    } while (entry != (sequenceEntry_s *)0x0);
  } while (bVar1);
  return;
}


// Sequence_ExpandGosubsForEntry  @ 001dc1d0
qboolean Sequence_ExpandGosubsForEntry(sequenceEntry_s *entry)

{
  char *__s2;
  bool bVar1;
  sequenceCommandLine_s *psVar2;
  qboolean qVar3;
  int iVar4;
  sequenceCommandLine_s *psVar5;
  sequenceEntry_s *psVar6;
  sequenceCommandLine_s *psVar7;
  sequenceCommandLine_s *psVar8;
  char *__s1;
  sequenceCommandLine_s *psVar9;
  sequenceCommandLine_s *psVar10;
  sequenceCommandLine_s *local_20;
  
                    /* Unresolved local var: sequenceCommandLine_s * cmd@[???]
                       Unresolved local var: qboolean foundGosubs@[???] */
  qVar3 = true;
  psVar9 = entry->firstCommand;
  if (psVar9 != (sequenceCommandLine_s *)0x0) {
    bVar1 = false;
    do {
      __s1 = (psVar9->clientMessage).pName;
      psVar10 = psVar9;
      if (__s1 != (char *)0x0) {
                    /* Unresolved local var: sequenceEntry_s * gosubEntry@[DW_OP_reg3(EBX)]
                       Unresolved local var: sequenceCommandLine_s * copyList@[???]
                       Unresolved local var: sequenceCommandLine_s * scan@[???] */
        __s2 = entry->entryName;
        iVar4 = strcasecmp(__s1,__s2);
        if (iVar4 == 0) {
          Sys_Error("Error in %s.seq: entry \"%s\" gosubs itself!\n",entry->fileName,__s2);
          __s1 = (psVar9->clientMessage).pName;
        }
                    /* Unresolved local var: sequenceEntry_s * scan@[???] */
        psVar6 = g_sequenceList;
        if (g_sequenceList != (sequenceEntry_s *)0x0) {
          do {
            iVar4 = Q_stricmp(__s1,psVar6->entryName);
            if (iVar4 == 0) {
              psVar7 = psVar6->firstCommand;
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???]
                       Unresolved local var: sequenceCommandLine_s * copyCommand@[???]
                       Unresolved local var: sequenceCommandLine_s * newCommandList@[???]
                       Unresolved local var: sequenceCommandLine_s * prevCommand@[???] */
              goto joined_r0x001dc24b;
            }
            psVar6 = psVar6->nextEntry;
          } while (psVar6 != (sequenceEntry_s *)0x0);
          __s1 = (psVar9->clientMessage).pName;
        }
        Sys_Error("Error in %s.seq: Gosub in entry \"%s\" specified unknown entry \"%s\"\n",
                  entry->fileName,entry->entryName,__s1);
        psVar7 = psRam00000008;
joined_r0x001dc24b:
        if (psVar7 != (sequenceCommandLine_s *)0x0) {
          local_20 = (sequenceCommandLine_s *)0x0;
          psVar8 = (sequenceCommandLine_s *)0x0;
          do {
            psVar5 = psVar8;
            psVar2 = local_20;
            if ((psVar7->commandType != 8) &&
               (psVar5 = Sequence_CopyCommand(psVar7), psVar2 = psVar5,
               psVar8 != (sequenceCommandLine_s *)0x0)) {
              psVar8->nextCommandLine = psVar5;
              psVar2 = local_20;
            }
            local_20 = psVar2;
            psVar7 = psVar7->nextCommandLine;
            psVar8 = psVar5;
          } while (psVar7 != (sequenceCommandLine_s *)0x0);
          psVar7 = local_20;
          if (local_20 != (sequenceCommandLine_s *)0x0) {
            do {
              psVar10 = psVar7;
              psVar7 = psVar10->nextCommandLine;
            } while (psVar10->nextCommandLine != (sequenceCommandLine_s *)0x0);
            psVar10->nextCommandLine = psVar9->nextCommandLine;
            psVar9->nextCommandLine = local_20;
            Mem_Free((psVar9->clientMessage).pName);
            bVar1 = true;
            (psVar9->clientMessage).pName = (char *)0x0;
            goto LAB_001dc2bf;
          }
        }
        Mem_Free((psVar9->clientMessage).pName);
        bVar1 = true;
        (psVar9->clientMessage).pName = (char *)0x0;
      }
LAB_001dc2bf:
      psVar9 = psVar10->nextCommandLine;
    } while (psVar9 != (sequenceCommandLine_s *)0x0);
    qVar3 = (qboolean)!bVar1;
  }
  return qVar3;
}


// Sequence_FindSentenceGroup  @ 001db750
sentenceGroupEntry_s * Sequence_FindSentenceGroup(char *groupName)

{
  sentenceGroupEntry_s *psVar1;
  int iVar2;
  
  psVar1 = g_sentenceGroupList;
  while ((psVar1 != (sentenceGroupEntry_s *)0x0 &&
         (iVar2 = strcasecmp(psVar1->groupName,groupName), iVar2 != 0))) {
    psVar1 = psVar1->nextEntry;
  }
  return psVar1;
}


// Sequence_FlattenAllEntries  @ 001dc430
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sequence_FlattenAllEntries(void)

{
  int iVar1;
  sequenceEntry_s *psVar2;
  sequenceCommandLine_s *in_EDX;
  sequenceCommandLine_s *extraout_EDX;
  sequenceCommandLine_s *extraout_EDX_00;
  sequenceCommandLine_s *extraout_EDX_01;
  sequenceCommandLine_s *extraout_EDX_02;
  sequenceCommandLine_s *source;
  sequenceCommandLine_s *destination;
  
  psVar2 = g_sequenceList;
  do {
    if (psVar2 == (sequenceEntry_s *)0x0) {
      return;
    }
                    /* Unresolved local var: sequenceCommandLine_s * cmd@[???]
                       Unresolved local var: sequenceCommandLine_s * lastCmd@[???] */
    source = psVar2->firstCommand;
    if (source != (sequenceCommandLine_s *)0x0) {
      destination = (sequenceCommandLine_s *)0x0;
      do {
        while (iVar1 = source->commandType, iVar1 != 9) {
          if (iVar1 == 10) {
            Sequence_WriteDefaults(source,destination);
            in_EDX = extraout_EDX_02;
          }
          else if (iVar1 == 8) {
            Sequence_WriteDefaults(source,&g_blockScopeDefaults);
            source->commandType = 0xb;
            in_EDX = extraout_EDX_01;
          }
          else {
            Sequence_BakeDefaults(source,in_EDX);
            in_EDX = extraout_EDX;
            destination = source;
          }
          source = source->nextCommandLine;
          if (source == (sequenceCommandLine_s *)0x0) goto LAB_001dc489;
        }
        Sequence_WriteDefaults(source,&g_blockScopeDefaults);
        source = source->nextCommandLine;
        in_EDX = extraout_EDX_00;
      } while (source != (sequenceCommandLine_s *)0x0);
    }
LAB_001dc489:
    psVar2 = psVar2->nextEntry;
  } while( true );
}


// Sequence_FlattenEntry  @ 001dc3a0
void __regparm2 Sequence_FlattenEntry(sequenceEntry_s *entry)

{
  int iVar1;
  sequenceCommandLine_s *in_EDX;
  sequenceCommandLine_s *extraout_EDX;
  sequenceCommandLine_s *extraout_EDX_00;
  sequenceCommandLine_s *extraout_EDX_01;
  sequenceCommandLine_s *extraout_EDX_02;
  sequenceCommandLine_s *source;
  sequenceCommandLine_s *unaff_ESI;
  int in_stack_00000004;
  
                    /* Unresolved local var: sequenceCommandLine_s * cmd@[???]
                       Unresolved local var: sequenceCommandLine_s * lastCmd@[???] */
  source = *(sequenceCommandLine_s **)(in_stack_00000004 + 8);
  do {
    if (source == (sequenceCommandLine_s *)0x0) {
      return;
    }
    while (iVar1 = source->commandType, iVar1 != 9) {
      if (iVar1 == 10) {
        Sequence_WriteDefaults(source,unaff_ESI);
        in_EDX = extraout_EDX_02;
      }
      else if (iVar1 == 8) {
        Sequence_WriteDefaults(source,&g_blockScopeDefaults);
        source->commandType = 0xb;
        in_EDX = extraout_EDX_01;
      }
      else {
        Sequence_BakeDefaults(source,in_EDX);
        in_EDX = extraout_EDX;
        unaff_ESI = source;
      }
      source = source->nextCommandLine;
      if (source == (sequenceCommandLine_s *)0x0) {
        return;
      }
    }
    Sequence_WriteDefaults(source,&g_blockScopeDefaults);
    source = source->nextCommandLine;
    in_EDX = extraout_EDX_00;
  } while( true );
}


// Sequence_FreeCommand  @ 001dc930
void Sequence_FreeCommand(sequenceCommandLine_s *kill)

{
  char *pcVar1;
  
  if (kill->fireTargetNames != (char *)0x0) {
    Mem_Free(kill->fireTargetNames);
  }
  if (kill->speakerName != (char *)0x0) {
    Mem_Free(kill->speakerName);
  }
  if (kill->listenerName != (char *)0x0) {
    Mem_Free(kill->listenerName);
  }
  if (kill->soundFileName != (char *)0x0) {
    Mem_Free(kill->soundFileName);
  }
  if (kill->sentenceName != (char *)0x0) {
    Mem_Free(kill->sentenceName);
  }
  pcVar1 = (kill->clientMessage).pName;
  if (pcVar1 != (char *)0x0) {
    Mem_Free(pcVar1);
  }
  pcVar1 = (kill->clientMessage).pMessage;
  if (pcVar1 != (char *)0x0) {
    Mem_Free(pcVar1);
    return;
  }
  return;
}


// Sequence_FreeDataPointer  @ 001d9380
void Sequence_FreeDataPointer(void *data)

{
  if (data != (void *)0x0) {
    Mem_Free(data);
    return;
  }
  return;
}


// Sequence_FreeEntry  @ 001dc9c0
void Sequence_FreeEntry(sequenceEntry_s *kill)

{
  char *pcVar1;
  sequenceCommandLine_s *psVar2;
  
  if (kill->entryName != (char *)0x0) {
    Mem_Free(kill->entryName);
  }
  pcVar1 = kill->fileName;
  while( true ) {
    if (pcVar1 != (char *)0x0) {
      Mem_Free(pcVar1);
    }
    psVar2 = kill->firstCommand;
    if (psVar2 == (sequenceCommandLine_s *)0x0) break;
                    /* Unresolved local var: sequenceCommandLine_s * dead@[???] */
    kill->firstCommand = psVar2->nextCommandLine;
    if (psVar2->fireTargetNames != (char *)0x0) {
      Mem_Free(psVar2->fireTargetNames);
    }
    if (psVar2->speakerName != (char *)0x0) {
      Mem_Free(psVar2->speakerName);
    }
    if (psVar2->listenerName != (char *)0x0) {
      Mem_Free(psVar2->listenerName);
    }
    if (psVar2->soundFileName != (char *)0x0) {
      Mem_Free(psVar2->soundFileName);
    }
    if (psVar2->sentenceName != (char *)0x0) {
      Mem_Free(psVar2->sentenceName);
    }
    pcVar1 = (psVar2->clientMessage).pName;
    if (pcVar1 != (char *)0x0) {
      Mem_Free(pcVar1);
    }
    pcVar1 = (psVar2->clientMessage).pMessage;
  }
  Mem_Free(kill);
  return;
}


// Sequence_FreeSentence  @ 001dca70
void Sequence_FreeSentence(sentenceEntry_s *sentenceEntry)

{
  if (sentenceEntry->data != (char *)0x0) {
    Mem_Free(sentenceEntry->data);
  }
  Mem_Free(sentenceEntry);
  return;
}


// Sequence_FreeSentenceGroup  @ 001dcaa0
void Sequence_FreeSentenceGroup(sentenceGroupEntry_s *groupEntry)

{
  if (groupEntry->groupName != (char *)0x0) {
    Mem_Free(groupEntry->groupName);
  }
  Mem_Free(groupEntry);
  return;
}


// Sequence_FreeSentenceGroupEntries  @ 001dcad0
void Sequence_FreeSentenceGroupEntries(sentenceGroupEntry_s *groupEntry,qboolean purgeGlobals)

{
  sentenceEntry_s *psVar1;
  sentenceEntry_s *p;
  sentenceEntry_s *psVar2;
  
                    /* Unresolved local var: sentenceEntry_s * sentenceEntry@[???]
                       Unresolved local var: sentenceEntry_s * deadSentence@[???]
                       Unresolved local var: sentenceEntry_s * prevSentence@[???] */
  p = groupEntry->firstSentence;
  if (p != (sentenceEntry_s *)0x0) {
    psVar2 = (sentenceEntry_s *)0x0;
    if (purgeGlobals == false) {
      do {
        if (p->isGlobal == 0) {
          if (psVar2 == (sentenceEntry_s *)0x0) {
            groupEntry->firstSentence = p->nextEntry;
          }
          else {
            psVar2->nextEntry = p->nextEntry;
          }
          groupEntry->numSentences = groupEntry->numSentences - 1;
          g_nonGlobalSentences = g_nonGlobalSentences - 1;
          psVar1 = p->nextEntry;
          if (p->data != (char *)0x0) {
            Mem_Free(p->data);
          }
          Mem_Free(p);
        }
        else {
          psVar1 = p->nextEntry;
          psVar2 = p;
        }
        p = psVar1;
      } while (psVar1 != (sentenceEntry_s *)0x0);
    }
    else {
      do {
        psVar2 = p->nextEntry;
        g_nonGlobalSentences = g_nonGlobalSentences - 1;
        groupEntry->numSentences = groupEntry->numSentences - 1;
        groupEntry->firstSentence = psVar2;
        psVar2 = p->nextEntry;
        if (p->data != (char *)0x0) {
          Mem_Free(p->data);
        }
        Mem_Free(p);
        p = psVar2;
      } while (psVar2 != (sentenceEntry_s *)0x0);
    }
  }
  return;
}


// Sequence_GetCommandEnumForName  @ 001d93a0
sequenceCommandEnum_e Sequence_GetCommandEnumForName(char *commandName)

{
  int iVar1;
  int iVar2;
  char **ppcVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int numTableEntries@[???] */
  ppcVar3 = &g_sequenceCommandMappingTable[0].commandName;
  iVar2 = 0;
  do {
    iVar1 = Q_stricmp(commandName,*ppcVar3);
    if (iVar1 == 0) {
      return g_sequenceCommandMappingTable[iVar2].commandEnum;
    }
    iVar2 = iVar2 + 1;
    ppcVar3 = ppcVar3 + 3;
  } while (iVar2 != 0x17);
  return SEQUENCE_COMMAND_ERROR;
}


// Sequence_GetEntryForName  @ 001dc010
sequenceEntry_s * Sequence_GetEntryForName(char *entryName)

{
  sequenceEntry_s *psVar1;
  int iVar2;
  
  psVar1 = g_sequenceList;
  while ((psVar1 != (sequenceEntry_s *)0x0 &&
         (iVar2 = Q_stricmp(entryName,psVar1->entryName), iVar2 != 0))) {
    psVar1 = psVar1->nextEntry;
  }
  return psVar1;
}


// Sequence_GetLine  @ 001d9b30
void Sequence_GetLine(char *line,int lineMaxLen)

{
  char cVar1;
  ushort **ppuVar2;
  char *pcVar3;
  char *__src;
  size_t __n;
  
                    /* Unresolved local var: int lineLen@[???]
                       Unresolved local var: char * read@[???]
                       Unresolved local var: char * write@[???] */
                    /* Unresolved local var: qboolean passedCarriageReturn@[???] */
  ppuVar2 = __ctype_b_loc();
  while( true ) {
    __src = g_scan;
    pcVar3 = g_scan + 1;
    cVar1 = *g_scan;
    if ((*(byte *)((int)*ppuVar2 + cVar1 * 2 + 1) & 0x20) == 0) break;
    g_scan = pcVar3;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar3;
    }
  }
  pcVar3 = strchr(g_scan,10);
  if (pcVar3 == (char *)0x0) {
    Sys_Error("Syntax Error on line %d of %s.seq: expected sentence definition or \'}\', found End-Of-File!\n"
              ,g_lineNum,g_sequenceParseFileName);
    __src = g_scan;
  }
  __n = (int)pcVar3 - (int)__src;
  if (lineMaxLen <= (int)__n) {
    Sys_Error("Syntax Error on line %d of %s.seq: line was too long (was %d chars; max is %d chars)\n"
              ,g_lineNum,g_sequenceParseFileName,__n,lineMaxLen + -1);
    __src = g_scan;
  }
  strncpy(line,__src,__n);
  line[__n] = '\0';
  g_scan = pcVar3;
  return;
}


// Sequence_GetNameValueString  @ 001d9120
void __regparm3 Sequence_GetNameValueString(char *token,int tokenLen)

{
  ushort **ppuVar1;
  char *pcVar2;
  char cVar3;
  ushort uVar4;
  int iVar5;
  
                    /* Unresolved local var: char * write@[???] */
                    /* Unresolved local var: qboolean passedCarriageReturn@[???] */
  ppuVar1 = __ctype_b_loc();
  while( true ) {
    pcVar2 = g_scan + 1;
    cVar3 = *g_scan;
    iVar5 = (int)cVar3;
    uVar4 = (*ppuVar1)[iVar5];
    if ((uVar4 & 0x2000) == 0) break;
    g_scan = pcVar2;
    if (cVar3 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar2;
    }
  }
  if (((((uVar4 & 8) == 0) && (1 < (byte)(cVar3 - 0x2dU))) && (cVar3 != '_')) &&
     (cVar3 != '/' && cVar3 != '\\')) {
    if ((byte)(cVar3 - 0x23U) < 2) {
      Sys_Error("Parsing error on line %d of %s.seq: cannot have more than one \'%c\' per line; \'%c\' must be at the beginning of the line ONLY\n"
                ,g_lineNum,g_sequenceParseFileName,iVar5,iVar5);
    }
    else {
      Sys_Error("Parsing error on line %d of %s.seq: expected name/value, found illegal character \'%c\'\n"
                ,g_lineNum,g_sequenceParseFileName,iVar5);
    }
    cVar3 = *g_scan;
    uVar4 = (*ppuVar1)[cVar3];
  }
  for (pcVar2 = token;
      ((((uVar4 & 8) != 0 || ((byte)(cVar3 - 0x2dU) < 2)) ||
       ((cVar3 == '_' || ((cVar3 == '\\' || (cVar3 == '/')))))) &&
      ((int)pcVar2 - (int)token < tokenLen + -1)); pcVar2 = pcVar2 + 1) {
    *pcVar2 = cVar3;
    cVar3 = g_scan[1];
    uVar4 = (*ppuVar1)[cVar3];
    g_scan = g_scan + 1;
  }
  *pcVar2 = '\0';
  return;
}


// Sequence_GetNameValueString  @ 001d98e0
void Sequence_GetNameValueString(char *token,int tokenLen)

{
                    /* Unresolved local var: char * write@[???] */
  if (0 < tokenLen) {
    Sequence_GetNameValueString(token,tokenLen);
    return;
  }
  return;
}


// Sequence_GetSymbol  @ 001d9900
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char Sequence_GetSymbol(void)

{
  char cVar1;
  ushort **ppuVar2;
  char *pcVar3;
  
                    /* Unresolved local var: char ch@[???] */
                    /* Unresolved local var: char ch@[???] */
  ppuVar2 = __ctype_b_loc();
  while( true ) {
    pcVar3 = g_scan + 1;
    cVar1 = *g_scan;
    if ((*(byte *)((int)*ppuVar2 + cVar1 * 2 + 1) & 0x20) == 0) break;
    g_scan = pcVar3;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar3;
    }
  }
  if (cVar1 != '\0') {
    g_scan = pcVar3;
  }
  return cVar1;
}


// Sequence_GetToken  @ 001d99f0
void Sequence_GetToken(char *token,int tokenLen)

{
  char cVar1;
  ushort **ppuVar2;
  char *pcVar3;
  int iVar4;
  
  ppuVar2 = __ctype_b_loc();
  while( true ) {
    pcVar3 = g_scan + 1;
    cVar1 = *g_scan;
    iVar4 = (int)cVar1;
    if (((*ppuVar2)[iVar4] & 0x2000) == 0) break;
    g_scan = pcVar3;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar3;
    }
  }
  if ((((((*ppuVar2)[iVar4] & 8) == 0) && (1 < (byte)(cVar1 - 0x2dU))) && (cVar1 != '_')) &&
     ((cVar1 != '\\' && (cVar1 != '/')))) {
    if (cVar1 == '=') {
LAB_001d9ad0:
      snprintf(token,tokenLen,"%c",iVar4);
      g_scan = g_scan + 1;
      return;
    }
    if (cVar1 < '>') {
      if (('!' < cVar1) && ((cVar1 < '&' || (cVar1 == ',')))) goto LAB_001d9ad0;
    }
    else if (((cVar1 == '{') || (cVar1 == '}')) || (cVar1 == '@')) goto LAB_001d9ad0;
    Sys_Error("Parsing error on line %d of %s.seq: expected token, found \'%c\' instead\n",g_lineNum
              ,g_sequenceParseFileName,iVar4);
  }
  else {
                    /* Unresolved local var: char * write@[???] */
    if (0 < tokenLen) {
      Sequence_GetNameValueString(token,tokenLen);
      return;
    }
  }
  return;
}


// Sequence_Init  @ 001dc8c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sequence_Init(void)

{
  Sequence_ParseFile("global",true);
  return;
}


// Sequence_IsCommandAModifier  @ 001da000
qboolean Sequence_IsCommandAModifier(sequenceCommandEnum_e commandEnum)

{
  int iVar1;
  sequenceCommandMapping_s *psVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int numTableEntries@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int numTableEntries@[???] */
  psVar2 = g_sequenceCommandMappingTable;
  iVar1 = 0;
  do {
    if (psVar2->commandEnum == commandEnum) {
      return (uint)(g_sequenceCommandMappingTable[iVar1].commandType == SEQUENCE_TYPE_MODIFIER);
    }
    iVar1 = iVar1 + 1;
    psVar2 = psVar2 + 1;
  } while (iVar1 != 0x17);
  Sys_Error("Internal error caused by line %d of %s.seq: unknown command enum = %d\n",g_lineNum,
            g_sequenceParseFileName,commandEnum);
  return false;
}


// Sequence_IsEntrySafe  @ 001db2f0
qboolean Sequence_IsEntrySafe(sequenceEntry_s *entry)

{
  float fVar1;
  qboolean qVar2;
  sequenceCommandLine_s *psVar3;
  
                    /* Unresolved local var: float duration@[???]
                       Unresolved local var: sequenceCommandLine_s * cmd@[???] */
  psVar3 = entry->firstCommand;
  qVar2 = true;
  if (psVar3 != (sequenceCommandLine_s *)0x0) {
    fVar1 = 0.0;
    while ((fVar1 = fVar1 + psVar3->delay, -1 < psVar3->repeatCount || (0.0 < fVar1))) {
      psVar3 = psVar3->nextCommandLine;
      if (psVar3 == (sequenceCommandLine_s *)0x0) {
        return true;
      }
    }
    qVar2 = false;
  }
  return qVar2;
}


// Sequence_IsNameValueChar  @ 001d9840
qboolean Sequence_IsNameValueChar(char ch)

{
  ushort **ppuVar1;
  qboolean qVar2;
  
  ppuVar1 = __ctype_b_loc();
  qVar2 = true;
  if (((*ppuVar1)[ch] & 8) == 0) {
    if (((byte)(ch - 0x2dU) < 2) || (ch == '_')) {
      return true;
    }
    qVar2 = (qboolean)(ch == '\\' || ch == '/');
  }
  return qVar2;
}


// Sequence_IsSymbol  @ 001d98a0
qboolean Sequence_IsSymbol(char ch)

{
  if (ch != '=') {
    if (ch < '>') {
      if (ch < '\"') {
        return false;
      }
      if (('%' < ch) && (ch != ',')) {
        return false;
      }
    }
    else if (((ch != '{') && (ch != '}')) && (ch != '@')) {
      return false;
    }
  }
  return true;
}


// Sequence_OnLevelLoad  @ 001dcd20
void Sequence_OnLevelLoad(char *mapName)

{
  sentenceEntry_s *psVar1;
  sequenceEntry_s *kill;
  sequenceEntry_s *psVar2;
  sentenceEntry_s *p;
  sentenceGroupEntry_s *psVar3;
  sequenceEntry_s *psVar4;
  sentenceGroupEntry_s *p_00;
  sentenceEntry_s *psVar5;
  sentenceGroupEntry_s *local_20;
  
                    /* Unresolved local var: sequenceEntry_s * scan@[???]
                       Unresolved local var: sequenceEntry_s * prev@[???]
                       Unresolved local var: sentenceGroupEntry_s * groupEntry@[???]
                       Unresolved local var: sentenceGroupEntry_s * prevGroup@[???]
                       Unresolved local var: sequenceEntry_s * dead@[???]
                       Unresolved local var: sentenceGroupEntry_s * deadGroup@[???] */
  if (g_sequenceList != (sequenceEntry_s *)0x0) {
    psVar4 = g_sequenceList;
    psVar2 = (sequenceEntry_s *)0x0;
    do {
      while (kill = psVar4, kill->isGlobal == 0) {
        if (psVar2 == (sequenceEntry_s *)0x0) {
          psVar4 = kill->nextEntry;
          g_sequenceList = psVar4;
        }
        else {
          psVar2->nextEntry = kill->nextEntry;
          psVar4 = kill->nextEntry;
        }
        Sequence_FreeEntry(kill);
        if (psVar4 == (sequenceEntry_s *)0x0) goto LAB_001dcd67;
      }
      psVar4 = kill->nextEntry;
      psVar2 = kill;
    } while (kill->nextEntry != (sequenceEntry_s *)0x0);
  }
LAB_001dcd67:
  if (g_sentenceGroupList != (sentenceGroupEntry_s *)0x0) {
    local_20 = (sentenceGroupEntry_s *)0x0;
    p_00 = g_sentenceGroupList;
    do {
                    /* Unresolved local var: sentenceEntry_s * sentenceEntry@[???]
                       Unresolved local var: sentenceEntry_s * prevSentence@[???]
                       Unresolved local var: sentenceEntry_s * deadSentence@[???] */
      if (p_00->firstSentence != (sentenceEntry_s *)0x0) {
        psVar1 = p_00->firstSentence;
        psVar5 = (sentenceEntry_s *)0x0;
        do {
          while (p = psVar1, p->isGlobal == 0) {
            if (psVar5 == (sentenceEntry_s *)0x0) {
              p_00->firstSentence = p->nextEntry;
            }
            else {
              psVar5->nextEntry = p->nextEntry;
            }
            p_00->numSentences = p_00->numSentences - 1;
            g_nonGlobalSentences = g_nonGlobalSentences - 1;
            psVar1 = p->nextEntry;
            if (p->data != (char *)0x0) {
              Mem_Free(p->data);
            }
            Mem_Free(p);
            if (psVar1 == (sentenceEntry_s *)0x0) goto LAB_001dcdd2;
          }
          psVar1 = p->nextEntry;
          psVar5 = p;
        } while (p->nextEntry != (sentenceEntry_s *)0x0);
      }
LAB_001dcdd2:
      if (p_00->numSentences == 0) {
        if (local_20 == (sentenceGroupEntry_s *)0x0) {
          psVar3 = p_00->nextEntry;
          g_sentenceGroupList = psVar3;
        }
        else {
          local_20->nextEntry = p_00->nextEntry;
          psVar3 = p_00->nextEntry;
        }
        if (p_00->groupName != (char *)0x0) {
          Mem_Free(p_00->groupName);
        }
        Mem_Free(p_00);
      }
      else {
        psVar3 = p_00->nextEntry;
        local_20 = p_00;
      }
      p_00 = psVar3;
    } while (psVar3 != (sentenceGroupEntry_s *)0x0);
  }
  Sequence_ParseFile(mapName,false);
  return;
}


// Sequence_ParseBuffer  @ 001dc4d0
void Sequence_ParseBuffer(byte *buffer,int bufferSize)

{
  byte bVar1;
  bool bVar2;
  char cVar3;
  ushort **ppuVar4;
  char *pcVar5;
  int iVar6;
  qboolean qVar7;
  sequenceCommandLine_s *extraout_EDX;
  sequenceCommandLine_s *extraout_EDX_00;
  sequenceCommandLine_s *source;
  sequenceCommandLine_s *extraout_EDX_01;
  sequenceCommandLine_s *extraout_EDX_02;
  sequenceCommandLine_s *extraout_EDX_03;
  sequenceEntry_s *psVar8;
  sequenceCommandLine_s *source_00;
  sequenceCommandLine_s *destination;
  char local_11c [268];
  
                    /* Unresolved local var: char symbol@[???] */
  g_lineNum = 1;
  g_scan = (char *)buffer;
  g_lineScan = (char *)buffer;
  Sequence_StripComments((char *)buffer,&bufferSize);
  Sequence_ResetDefaults(&g_fileScopeDefaults,(sequenceCommandLine_s *)0x0);
  ppuVar4 = __ctype_b_loc();
  while( true ) {
    pcVar5 = g_scan + 1;
    cVar3 = *g_scan;
    if ((*(byte *)((int)*ppuVar4 + cVar3 * 2 + 1) & 0x20) == 0) break;
    g_scan = pcVar5;
    if (cVar3 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar5;
    }
  }
  if (cVar3 != '\0') {
                    /* Unresolved local var: char ch@[???] */
    g_scan = pcVar5;
    do {
      if (cVar3 == '$') {
        do {
                    /* Unresolved local var: sequenceCommandLine_s * newCommandLine@[???]
                       Unresolved local var: char delimiter@[???] */
          cVar3 = Sequence_ParseModifier(&g_fileScopeDefaults);
        } while (cVar3 == ',');
      }
      else if (cVar3 == '%') {
        cVar3 = Sequence_ParseEntry();
      }
      else if (cVar3 == '!') {
        Sequence_GetNameValueString(local_11c,0x100);
                    /* Unresolved local var: char[256] token@[???] */
        iVar6 = strcasecmp(local_11c,"Sentences");
        if (iVar6 != 0) {
          Sys_Error("Syntax error in file %s.seq on line %d: found global data block symbol \'!\' with unknown data type \"%s\""
                    ,g_sequenceParseFileName,g_lineNum,local_11c);
          break;
        }
                    /* Unresolved local var: char symbol@[DW_OP_reg0(EAX)]
                       Unresolved local var: qboolean finished@[???]
                       Unresolved local var: char ch@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
        cVar3 = *g_scan;
        iVar6 = (int)cVar3;
        bVar1 = *(byte *)((int)*ppuVar4 + iVar6 * 2 + 1);
        while ((bVar1 & 0x20) != 0) {
          g_scan = g_scan + 1;
          if (cVar3 == '\n') {
            g_lineNum = g_lineNum + 1;
            g_lineScan = g_scan;
          }
          cVar3 = *g_scan;
          iVar6 = (int)cVar3;
          bVar1 = *(byte *)((int)*ppuVar4 + iVar6 * 2 + 1);
        }
        if (cVar3 == '\0') {
          iVar6 = 0;
LAB_001dc799:
          Sys_Error("Parsing error on line %d of %s.seq: expected \'{\' to start a\n new sentence block; found \'%c\' instead!"
                    ,g_lineNum,g_sequenceParseFileName,iVar6);
          qVar7 = Sequence_ParseSentenceLine();
          goto joined_r0x001dc7c2;
        }
                    /* Unresolved local var: char ch@[???] */
        g_scan = g_scan + 1;
        if (cVar3 != '{') goto LAB_001dc799;
        do {
          qVar7 = Sequence_ParseSentenceLine();
joined_r0x001dc7c2:
        } while (qVar7 == false);
                    /* Unresolved local var: char ch@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
        cVar3 = *g_scan;
        bVar1 = *(byte *)((int)*ppuVar4 + cVar3 * 2 + 1);
        while ((bVar1 & 0x20) != 0) {
          g_scan = g_scan + 1;
          if (cVar3 == '\n') {
            g_lineNum = g_lineNum + 1;
            g_lineScan = g_scan;
          }
          cVar3 = *g_scan;
          bVar1 = *(byte *)((int)*ppuVar4 + cVar3 * 2 + 1);
        }
        if (cVar3 == '\0') break;
                    /* Unresolved local var: char ch@[???] */
        g_scan = g_scan + 1;
      }
      else {
        Sys_Error("Parsing error on line %d of %s.seq: At file scope, lines must begin with \'$\' (modifier) or \'%\' (entry block) or \'!\' (sentence / global data block); found \'%c\'\n"
                  ,g_lineNum,g_sequenceParseFileName,(int)cVar3);
      }
    } while (cVar3 != '\0');
  }
  do {
    if (g_sequenceList == (sequenceEntry_s *)0x0) {
      return;
    }
    bVar2 = false;
    psVar8 = g_sequenceList;
    do {
      qVar7 = Sequence_ExpandGosubsForEntry(psVar8);
      psVar8 = psVar8->nextEntry;
      if (qVar7 == false) {
        bVar2 = true;
      }
    } while (psVar8 != (sequenceEntry_s *)0x0);
    source = extraout_EDX;
    psVar8 = g_sequenceList;
  } while (bVar2);
  do {
                    /* Unresolved local var: sequenceEntry_s * entry@[???] */
    if (psVar8 == (sequenceEntry_s *)0x0) {
      return;
    }
                    /* Unresolved local var: sequenceCommandLine_s * cmd@[???]
                       Unresolved local var: sequenceCommandLine_s * lastCmd@[???] */
    source_00 = psVar8->firstCommand;
    if (source_00 != (sequenceCommandLine_s *)0x0) {
      destination = (sequenceCommandLine_s *)0x0;
      do {
        while (iVar6 = source_00->commandType, iVar6 == 9) {
          Sequence_WriteDefaults(source_00,&g_blockScopeDefaults);
          source_00 = source_00->nextCommandLine;
          source = extraout_EDX_01;
          if (source_00 == (sequenceCommandLine_s *)0x0) goto LAB_001dc691;
        }
        if (iVar6 == 10) {
          Sequence_WriteDefaults(source_00,destination);
          source = extraout_EDX_03;
        }
        else if (iVar6 == 8) {
          Sequence_WriteDefaults(source_00,&g_blockScopeDefaults);
          source_00->commandType = 0xb;
          source = extraout_EDX_02;
        }
        else {
          Sequence_BakeDefaults(source_00,source);
          source = extraout_EDX_00;
          destination = source_00;
        }
        source_00 = source_00->nextCommandLine;
      } while (source_00 != (sequenceCommandLine_s *)0x0);
    }
LAB_001dc691:
    psVar8 = psVar8->nextEntry;
  } while( true );
}


// Sequence_ParseCommand  @ 001dadc0
char Sequence_ParseCommand(sequenceCommandLine_s *newCommandLine)

{
  byte bVar1;
  char cVar2;
  sequenceCommandEnum_e sVar3;
  int iVar4;
  ushort **ppuVar5;
  char *pcVar6;
  sequenceCommandLine_s *psVar7;
  sequenceCommandMapping_s *psVar8;
  sequenceCommandLine_s *psVar9;
  sequenceCommandLine_s *extraout_EDX;
  int iVar10;
  char **ppcVar11;
  char local_11c [268];
  
                    /* Unresolved local var: char[256] commandName@[???]
                       Unresolved local var: char delimiter@[DW_OP_reg2(EDX)]
                       Unresolved local var: sequenceCommandEnum_e commandEnum@[DW_OP_reg6(ESI)]
                       Unresolved local var: sequenceCommandLine_s *
                       modifierCommandLine@[DW_OP_reg0(EAX)] */
                    /* Unresolved local var: char ch@[???] */
  ppcVar11 = &g_sequenceCommandMappingTable[0].commandName;
                    /* Unresolved local var: char * write@[???] */
  iVar10 = 0;
  Sequence_GetNameValueString(local_11c,0x100);
  do {
    iVar4 = Q_stricmp(local_11c,*ppcVar11);
    if (iVar4 == 0) {
      sVar3 = g_sequenceCommandMappingTable[iVar10].commandEnum;
      if (sVar3 != SEQUENCE_COMMAND_ERROR) {
        psVar8 = g_sequenceCommandMappingTable;
        iVar10 = 0;
        goto LAB_001dae35;
      }
      break;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int numTableEntries@[???] */
    iVar10 = iVar10 + 1;
    ppcVar11 = ppcVar11 + 3;
  } while (iVar10 != 0x17);
  Sys_Error("Parsing error on line %d of %s.seq: unknown command \"%s\"\n",g_lineNum,
            g_sequenceParseFileName,local_11c);
  goto LAB_001dae4a;
  while( true ) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int numTableEntries@[???] */
    iVar10 = iVar10 + 1;
    psVar8 = psVar8 + 1;
    if (iVar10 == 0x17) break;
LAB_001dae35:
    if (sVar3 == psVar8->commandEnum) {
      if (g_sequenceCommandMappingTable[iVar10].commandType == SEQUENCE_TYPE_MODIFIER) {
        psVar9 = Mem_ZeroMalloc(0x5c);
        psVar9->commandType = 10;
        do {
          psVar7 = newCommandLine;
          newCommandLine = psVar7->nextCommandLine;
        } while (newCommandLine != (sequenceCommandLine_s *)0x0);
        psVar7->nextCommandLine = psVar9;
        newCommandLine = psVar9;
      }
      goto LAB_001dae4a;
    }
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int numTableEntries@[???] */
  Sys_Error("Internal error caused by line %d of %s.seq: unknown command enum = %d\n",g_lineNum,
            g_sequenceParseFileName,sVar3);
LAB_001dae4a:
  ppuVar5 = __ctype_b_loc();
  while( true ) {
    pcVar6 = g_scan + 1;
    bVar1 = *g_scan;
    psVar9 = (sequenceCommandLine_s *)(uint)bVar1;
    iVar10 = (int)(char)bVar1;
    if ((*(byte *)((int)*ppuVar5 + iVar10 * 2 + 1) & 0x20) == 0) break;
    g_scan = pcVar6;
    if (bVar1 == 10) {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar6;
    }
  }
  if (bVar1 == 0) {
    iVar10 = 0;
  }
  else {
    g_scan = pcVar6;
                    /* Unresolved local var: char ch@[???] */
    if (bVar1 == 0x3d) goto LAB_001daea3;
  }
  Sys_Error("Parsing error on or before line %d of %s.seq: after command \"%s\", expected \'=\', found \'%c\'\n"
            ,g_lineNum,g_sequenceParseFileName,local_11c,iVar10);
  psVar9 = extraout_EDX;
LAB_001daea3:
  Sequence_ReadCommandData((sequenceCommandEnum_e)newCommandLine,psVar9);
                    /* Unresolved local var: char ch@[DW_OP_reg0(EAX)]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
  cVar2 = *g_scan;
  bVar1 = *(byte *)((int)*ppuVar5 + cVar2 * 2 + 1);
  while ((bVar1 & 0x20) != 0) {
    g_scan = g_scan + 1;
    if (cVar2 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = g_scan;
    }
    cVar2 = *g_scan;
    bVar1 = *(byte *)((int)*ppuVar5 + cVar2 * 2 + 1);
  }
  if (cVar2 != '\0') {
                    /* Unresolved local var: char ch@[???] */
    g_scan = g_scan + 1;
  }
  return cVar2;
}


// Sequence_ParseCommandLine  @ 001daff0
char Sequence_ParseCommandLine(sequenceEntry_s *entry)

{
  sequenceCommandLine_s *psVar1;
  char cVar2;
  sequenceCommandLine_s *destination;
  sequenceCommandLine_s *psVar3;
  
                    /* Unresolved local var: char delimiter@[???]
                       Unresolved local var: sequenceCommandLine_s * newCommandLine@[???] */
  destination = Mem_ZeroMalloc(0x5c);
  Sequence_ResetDefaults(destination,&g_blockScopeDefaults);
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???] */
  psVar1 = entry->firstCommand;
  if (entry->firstCommand == (sequenceCommandLine_s *)0x0) {
    entry->firstCommand = destination;
    destination->nextCommandLine = (sequenceCommandLine_s *)0x0;
  }
  else {
    do {
      psVar3 = psVar1;
      psVar1 = psVar3->nextCommandLine;
    } while (psVar1 != (sequenceCommandLine_s *)0x0);
    psVar3->nextCommandLine = destination;
    destination->nextCommandLine = (sequenceCommandLine_s *)0x0;
  }
  do {
    cVar2 = Sequence_ParseCommand(destination);
  } while (cVar2 == ',');
  return cVar2;
}


// Sequence_ParseEntry  @ 001db3b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char Sequence_ParseEntry(void)

{
  byte bVar1;
  float fVar2;
  char cVar3;
  ushort **ppuVar4;
  char *pcVar5;
  sequenceEntry_s *entry;
  sequenceCommandLine_s *psVar6;
  sequenceCommandLine_s *psVar7;
  int iVar8;
  sequenceCommandLine_s *psVar9;
  char local_11c [268];
  
                    /* Unresolved local var: char symbol@[DW_OP_reg2(EDX)]
                       Unresolved local var: char delimiter@[???]
                       Unresolved local var: char[256] token@[???]
                       Unresolved local var: sequenceEntry_s * newEntry@[???] */
                    /* Unresolved local var: float duration@[???]
                       Unresolved local var: sequenceCommandLine_s * cmd@[???] */
  Sequence_GetNameValueString(local_11c,0x100);
  ppuVar4 = __ctype_b_loc();
  while( true ) {
    pcVar5 = g_scan + 1;
    cVar3 = *g_scan;
    iVar8 = (int)cVar3;
    if ((*(byte *)((int)*ppuVar4 + iVar8 * 2 + 1) & 0x20) == 0) break;
    g_scan = pcVar5;
    if (cVar3 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar5;
    }
  }
  if (cVar3 == '\0') {
    iVar8 = 0;
  }
  else {
    g_scan = pcVar5;
                    /* Unresolved local var: char ch@[???] */
    if (cVar3 == '{') goto LAB_001db41e;
  }
  Sys_Error("Parsing error on line %d of %s.seq: expected \'{\' to start a\n new entry block; found \'%c\' instead!"
            ,g_lineNum,g_sequenceParseFileName,iVar8);
LAB_001db41e:
  entry = Mem_Malloc(0x14);
  Sequence_ResetDefaults(&g_blockScopeDefaults,&g_fileScopeDefaults);
  pcVar5 = Mem_Strdup(local_11c);
  entry->entryName = pcVar5;
  pcVar5 = Mem_Strdup(g_sequenceParseFileName);
  entry->firstCommand = (sequenceCommandLine_s *)0x0;
  entry->fileName = pcVar5;
  entry->isGlobal = g_sequenceParseFileIsGlobal;
                    /* Unresolved local var: sequenceCommandLine_s * defaultsCommand@[???] */
  psVar6 = Mem_ZeroMalloc(0x5c);
  Sequence_ResetDefaults(psVar6,&g_fileScopeDefaults);
  psVar6->commandType = 8;
  psVar6->modifierBitField = 0xff;
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???] */
  psVar7 = entry->firstCommand;
  if (entry->firstCommand == (sequenceCommandLine_s *)0x0) {
    entry->firstCommand = psVar6;
    psVar6->nextCommandLine = (sequenceCommandLine_s *)0x0;
  }
  else {
    do {
      psVar9 = psVar7;
      psVar7 = psVar9->nextCommandLine;
    } while (psVar7 != (sequenceCommandLine_s *)0x0);
    psVar9->nextCommandLine = psVar6;
    psVar6->nextCommandLine = (sequenceCommandLine_s *)0x0;
  }
                    /* Unresolved local var: char ch@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
  cVar3 = *g_scan;
  bVar1 = *(byte *)((int)*ppuVar4 + cVar3 * 2 + 1);
  while ((bVar1 & 0x20) != 0) {
    g_scan = g_scan + 1;
    if (cVar3 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = g_scan;
    }
    cVar3 = *g_scan;
    bVar1 = *(byte *)((int)*ppuVar4 + cVar3 * 2 + 1);
  }
  if (cVar3 == '\0') goto LAB_001db525;
                    /* Unresolved local var: char ch@[???] */
  g_scan = g_scan + 1;
LAB_001db520:
  if (cVar3 != '}') {
LAB_001db525:
    while( true ) {
                    /* Unresolved local var: char endToken@[???] */
      if (cVar3 == '$') goto LAB_001db63f;
      if (cVar3 == '#') break;
      if (cVar3 == '@') {
        cVar3 = Sequence_ParseMacro(entry);
        goto LAB_001db520;
      }
      Sys_Error("Parsing error on line %d of %s.seq: line must begin with either \'#\' (command) or \'$\' (modifier); found \'%c\'\n"
                ,g_lineNum,g_sequenceParseFileName,(int)cVar3);
      cVar3 = '\0';
    }
                    /* Unresolved local var: char delimiter@[???]
                       Unresolved local var: sequenceCommandLine_s * newCommandLine@[???] */
    psVar6 = Mem_ZeroMalloc(0x5c);
    Sequence_ResetDefaults(psVar6,&g_blockScopeDefaults);
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???] */
    psVar7 = entry->firstCommand;
    if (entry->firstCommand == (sequenceCommandLine_s *)0x0) {
      entry->firstCommand = psVar6;
      psVar6->nextCommandLine = (sequenceCommandLine_s *)0x0;
    }
    else {
      do {
        psVar9 = psVar7;
        psVar7 = psVar9->nextCommandLine;
      } while (psVar7 != (sequenceCommandLine_s *)0x0);
      psVar9->nextCommandLine = psVar6;
      psVar6->nextCommandLine = (sequenceCommandLine_s *)0x0;
    }
    do {
      cVar3 = Sequence_ParseCommand(psVar6);
    } while (cVar3 == ',');
    goto LAB_001db520;
  }
  psVar7 = entry->firstCommand;
  if (psVar7 != (sequenceCommandLine_s *)0x0) {
    fVar2 = 0.0;
    do {
      fVar2 = fVar2 + psVar7->delay;
      if ((psVar7->repeatCount < 0) && (fVar2 <= 0.0)) {
        Sys_Error("Logic error in file %s.seq before line %d: execution of entry \"%%%s\" would cause an infinite loop!"
                  ,g_sequenceParseFileName,g_lineNum,entry->entryName);
        break;
      }
      psVar7 = psVar7->nextCommandLine;
    } while (psVar7 != (sequenceCommandLine_s *)0x0);
  }
  entry->nextEntry = g_sequenceList;
  g_sequenceList = entry;
                    /* Unresolved local var: char ch@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
  cVar3 = *g_scan;
  bVar1 = *(byte *)((int)*ppuVar4 + cVar3 * 2 + 1);
  while ((bVar1 & 0x20) != 0) {
    g_scan = g_scan + 1;
    if (cVar3 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = g_scan;
    }
    cVar3 = *g_scan;
    bVar1 = *(byte *)((int)*ppuVar4 + cVar3 * 2 + 1);
  }
  if (cVar3 != '\0') {
                    /* Unresolved local var: char ch@[???] */
    g_scan = g_scan + 1;
  }
  return cVar3;
LAB_001db63f:
  do {
    psVar6 = Mem_ZeroMalloc(0x5c);
    psVar6->commandType = 9;
    psVar7 = entry->firstCommand;
    if (entry->firstCommand == (sequenceCommandLine_s *)0x0) {
      entry->firstCommand = psVar6;
      psVar6->nextCommandLine = (sequenceCommandLine_s *)0x0;
    }
    else {
      do {
        psVar9 = psVar7;
        psVar7 = psVar9->nextCommandLine;
      } while (psVar7 != (sequenceCommandLine_s *)0x0);
                    /* Unresolved local var: sequenceCommandLine_s * newCommandLine@[???]
                       Unresolved local var: char delimiter@[???]
                       Unresolved local var: sequenceCommandLine_s * scan@[???] */
      psVar9->nextCommandLine = psVar6;
      psVar6->nextCommandLine = (sequenceCommandLine_s *)0x0;
    }
    cVar3 = Sequence_ParseModifier(psVar6);
  } while (cVar3 == ',');
  goto LAB_001db520;
}


// Sequence_ParseFile  @ 001dc810
void Sequence_ParseFile(char *fileName,qboolean isGlobal)

{
  byte *buffer;
  char local_110 [256];
  int local_10 [2];
  
                    /* Unresolved local var: byte * buffer@[???]
                       Unresolved local var: int bufSize@[???]
                       Unresolved local var: char[256] filePathName@[???] */
  Q_strncpy(g_sequenceParseFileName,fileName,0xff);
  g_sequenceParseFileName[0xff] = '\0';
  g_sequenceParseFileIsGlobal = isGlobal;
  snprintf(local_110,0x100,"sequences/%s.seq",fileName);
  buffer = COM_LoadTempFile(local_110,local_10);
  if (buffer != (byte *)0x0) {
    Sequence_ParseBuffer(buffer,local_10[0]);
    return;
  }
  Con_DPrintf("WARNING: failed to locate sequence file %s\n",fileName);
  return;
}


// Sequence_ParseGlobalDataBlock  @ 001dbeb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char Sequence_ParseGlobalDataBlock(void)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  ushort **ppuVar4;
  char *pcVar5;
  qboolean qVar6;
  char local_10c [256];
  
                    /* Unresolved local var: char[256] token@[???] */
  Sequence_GetNameValueString(local_10c,0x100);
  iVar3 = strcasecmp(local_10c,"Sentences");
  if (iVar3 != 0) {
    Sys_Error("Syntax error in file %s.seq on line %d: found global data block symbol \'!\' with unknown data type \"%s\""
              ,g_sequenceParseFileName,g_lineNum,local_10c);
    return '\0';
  }
  ppuVar4 = __ctype_b_loc();
  while( true ) {
    pcVar5 = g_scan + 1;
    cVar1 = *g_scan;
    iVar3 = (int)cVar1;
    if ((*(byte *)((int)*ppuVar4 + iVar3 * 2 + 1) & 0x20) == 0) break;
    g_scan = pcVar5;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar5;
    }
  }
  if (cVar1 == '\0') {
    iVar3 = 0;
  }
  else {
    g_scan = pcVar5;
                    /* Unresolved local var: char ch@[???] */
    if (cVar1 == '{') goto LAB_001dbf60;
  }
  Sys_Error("Parsing error on line %d of %s.seq: expected \'{\' to start a\n new sentence block; found \'%c\' instead!"
            ,g_lineNum,g_sequenceParseFileName,iVar3);
  qVar6 = Sequence_ParseSentenceLine();
  while (qVar6 == false) {
LAB_001dbf60:
    qVar6 = Sequence_ParseSentenceLine();
  }
                    /* Unresolved local var: char ch@[DW_OP_reg2(EDX)]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
  cVar1 = *g_scan;
  bVar2 = *(byte *)((int)*ppuVar4 + cVar1 * 2 + 1);
  while ((bVar2 & 0x20) != 0) {
    g_scan = g_scan + 1;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = g_scan;
    }
    cVar1 = *g_scan;
    bVar2 = *(byte *)((int)*ppuVar4 + cVar1 * 2 + 1);
  }
  if (cVar1 == '\0') {
    return '\0';
  }
                    /* Unresolved local var: char ch@[DW_OP_reg2(EDX)] */
  g_scan = g_scan + 1;
  return cVar1;
}


// Sequence_ParseLine  @ 001db160
char __regparm1 Sequence_ParseLine(char startToken,sequenceEntry_s *entry)

{
  sequenceCommandLine_s *psVar1;
  char cVar2;
  sequenceCommandLine_s *psVar3;
  sequenceCommandLine_s *psVar4;
  sequenceEntry_s *in_stack_00000008;
  
                    /* Unresolved local var: char endToken@[???] */
  if ((char)entry == '$') {
    do {
      psVar3 = Mem_ZeroMalloc(0x5c);
      psVar3->commandType = 9;
      psVar1 = in_stack_00000008->firstCommand;
      if (in_stack_00000008->firstCommand == (sequenceCommandLine_s *)0x0) {
        in_stack_00000008->firstCommand = psVar3;
        psVar3->nextCommandLine = (sequenceCommandLine_s *)0x0;
      }
      else {
        do {
          psVar4 = psVar1;
          psVar1 = psVar4->nextCommandLine;
        } while (psVar1 != (sequenceCommandLine_s *)0x0);
                    /* Unresolved local var: sequenceCommandLine_s * newCommandLine@[???]
                       Unresolved local var: char delimiter@[???]
                       Unresolved local var: sequenceCommandLine_s * scan@[???] */
        psVar4->nextCommandLine = psVar3;
        psVar3->nextCommandLine = (sequenceCommandLine_s *)0x0;
      }
      startToken = Sequence_ParseModifier(psVar3);
    } while (startToken == ',');
  }
  else if ((char)entry == '#') {
                    /* Unresolved local var: char delimiter@[???]
                       Unresolved local var: sequenceCommandLine_s * newCommandLine@[???] */
    psVar3 = Mem_ZeroMalloc(0x5c);
    Sequence_ResetDefaults(psVar3,&g_blockScopeDefaults);
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???] */
    psVar1 = in_stack_00000008->firstCommand;
    if (in_stack_00000008->firstCommand == (sequenceCommandLine_s *)0x0) {
      in_stack_00000008->firstCommand = psVar3;
      psVar3->nextCommandLine = (sequenceCommandLine_s *)0x0;
    }
    else {
      do {
        psVar4 = psVar1;
        psVar1 = psVar4->nextCommandLine;
      } while (psVar1 != (sequenceCommandLine_s *)0x0);
      psVar4->nextCommandLine = psVar3;
      psVar3->nextCommandLine = (sequenceCommandLine_s *)0x0;
    }
    do {
      startToken = Sequence_ParseCommand(psVar3);
    } while (startToken == ',');
  }
  else {
    if ((char)entry == '@') {
      cVar2 = Sequence_ParseMacro(in_stack_00000008);
      return cVar2;
    }
    Sys_Error("Parsing error on line %d of %s.seq: line must begin with either \'#\' (command) or \'$\' (modifier); found \'%c\'\n"
              ,g_lineNum,g_sequenceParseFileName,(int)(char)entry);
  }
  return startToken;
}


// Sequence_ParseMacro  @ 001db060
char Sequence_ParseMacro(sequenceEntry_s *entry)

{
  sequenceCommandLine_s *psVar1;
  char cVar2;
  sequenceCommandLine_s *destination;
  sequenceCommandEnum_e extraout_EAX;
  sequenceCommandEnum_e commandEnum;
  ushort **ppuVar3;
  char *pcVar4;
  sequenceCommandLine_s *defaults;
  
                    /* Unresolved local var: char delimiter@[???]
                       Unresolved local var: sequenceCommandLine_s * newCommandLine@[???] */
  destination = Mem_Malloc(0x5c);
  Q_memset(destination,0,0x5c);
  Sequence_ResetDefaults(destination,&g_blockScopeDefaults);
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???] */
  defaults = entry->firstCommand;
  psVar1 = defaults;
  if (defaults == (sequenceCommandLine_s *)0x0) {
    entry->firstCommand = destination;
    destination->nextCommandLine = (sequenceCommandLine_s *)0x0;
    commandEnum = extraout_EAX;
  }
  else {
    do {
      defaults = psVar1;
      psVar1 = defaults->nextCommandLine;
    } while (defaults->nextCommandLine != (sequenceCommandLine_s *)0x0);
    defaults->nextCommandLine = destination;
    destination->nextCommandLine = (sequenceCommandLine_s *)0x0;
    commandEnum = SEQUENCE_COMMAND_PAUSE;
  }
  Sequence_ReadCommandData(commandEnum,defaults);
  ppuVar3 = __ctype_b_loc();
  while( true ) {
    pcVar4 = g_scan + 1;
    cVar2 = *g_scan;
    if ((*(byte *)((int)*ppuVar3 + cVar2 * 2 + 1) & 0x20) == 0) break;
    g_scan = pcVar4;
    if (cVar2 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar4;
    }
  }
  if (cVar2 != '\0') {
    while (g_scan = pcVar4, cVar2 == ',') {
      cVar2 = Sequence_ParseCommand(destination);
      pcVar4 = g_scan;
    }
  }
  return cVar2;
}


// Sequence_ParseModifier  @ 001daa60
char Sequence_ParseModifier(sequenceCommandLine_s *defaults)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  ushort **ppuVar4;
  char cVar5;
  sequenceCommandMapping_s *psVar6;
  sequenceCommandLine_s *defaults_00;
  sequenceCommandLine_s *extraout_EDX;
  int iVar7;
  char **ppcVar8;
  sequenceCommandEnum_e sVar9;
  char local_11c [268];
  
                    /* Unresolved local var: char[256] modifierName@[???]
                       Unresolved local var: char delimiter@[???]
                       Unresolved local var: sequenceCommandEnum_e modifierEnum@[DW_OP_reg7(EDI)] */
                    /* Unresolved local var: qboolean foundCarriageReturn@[???] */
  ppcVar8 = &g_sequenceCommandMappingTable[0].commandName;
                    /* Unresolved local var: char * write@[???] */
  iVar7 = 0;
  Sequence_GetNameValueString(local_11c,0x100);
  do {
    iVar3 = Q_stricmp(local_11c,*ppcVar8);
    if (iVar3 == 0) {
      sVar9 = g_sequenceCommandMappingTable[iVar7].commandEnum;
      if (sVar9 != SEQUENCE_COMMAND_ERROR) goto LAB_001daaba;
      break;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int numTableEntries@[???] */
    iVar7 = iVar7 + 1;
    ppcVar8 = ppcVar8 + 3;
  } while (iVar7 != 0x17);
  sVar9 = SEQUENCE_COMMAND_ERROR;
  Sys_Error("Parsing error on line %d of %s.seq: unknown modifier \"%s\"\n",g_lineNum,
            g_sequenceParseFileName,local_11c);
LAB_001daaba:
  psVar6 = g_sequenceCommandMappingTable;
  iVar7 = 0;
  do {
    if (sVar9 == psVar6->commandEnum) {
      if (g_sequenceCommandMappingTable[iVar7].commandType == SEQUENCE_TYPE_MODIFIER)
      goto LAB_001dab08;
      goto LAB_001daae6;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int numTableEntries@[???] */
    iVar7 = iVar7 + 1;
    psVar6 = psVar6 + 1;
  } while (iVar7 != 0x17);
  Sys_Error("Internal error caused by line %d of %s.seq: unknown command enum = %d\n",g_lineNum,
            g_sequenceParseFileName,sVar9);
LAB_001daae6:
  Sys_Error("Parsing error on line %d of %s.seq: \"%s\" is a #command, not a $modifier\n",g_lineNum,
            g_sequenceParseFileName,local_11c);
LAB_001dab08:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int numTableEntries@[???] */
  ppuVar4 = __ctype_b_loc();
  while( true ) {
    defaults_00 = (sequenceCommandLine_s *)(g_scan + 1);
    cVar5 = *g_scan;
    iVar7 = (int)cVar5;
    if ((*(byte *)((int)*ppuVar4 + iVar7 * 2 + 1) & 0x20) == 0) break;
    g_scan = (char *)defaults_00;
    if (cVar5 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = (char *)defaults_00;
    }
  }
  if (cVar5 == '\0') {
    iVar7 = 0;
LAB_001dabd2:
    Sys_Error("Parsing error on or after line %d of %s.seq: after modifier \"%s\", expected \'=\', found \'%c\'\n"
              ,g_lineNum,g_sequenceParseFileName,local_11c,iVar7);
    defaults_00 = extraout_EDX;
  }
  else {
    g_scan = (char *)defaults_00;
                    /* Unresolved local var: char ch@[???] */
    if (cVar5 != '=') goto LAB_001dabd2;
  }
  Sequence_ReadCommandData((sequenceCommandEnum_e)defaults,defaults_00);
                    /* Unresolved local var: qboolean passedCarriageReturn@[???] */
  cVar5 = *g_scan;
  iVar7 = (int)cVar5;
  if ((*(byte *)((int)*ppuVar4 + iVar7 * 2 + 1) & 0x20) == 0) {
LAB_001dac08:
    if (cVar5 == ',') goto LAB_001dac84;
    Sys_Error("Parsing error on line %d of %s.seq: after value(s) for modifier \"%s\", expected \',\' or End-Of-Line; found \'%c\'\n"
              ,g_lineNum,g_sequenceParseFileName,local_11c,iVar7);
                    /* Unresolved local var: char ch@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
    cVar5 = *g_scan;
    bVar1 = *(byte *)((int)*ppuVar4 + cVar5 * 2 + 1);
    while ((bVar1 & 0x20) != 0) {
      g_scan = g_scan + 1;
      if (cVar5 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = g_scan;
      }
      cVar5 = *g_scan;
      bVar1 = *(byte *)((int)*ppuVar4 + cVar5 * 2 + 1);
    }
  }
  else {
    bVar2 = false;
    do {
      g_scan = g_scan + 1;
      if (cVar5 == '\n') {
        g_lineNum = g_lineNum + 1;
        bVar2 = true;
        g_lineScan = g_scan;
      }
      cVar5 = *g_scan;
      iVar7 = (int)cVar5;
    } while ((*(byte *)((int)*ppuVar4 + iVar7 * 2 + 1) & 0x20) != 0);
    if (!bVar2) goto LAB_001dac08;
  }
  if (cVar5 == '\0') {
    return '\0';
  }
LAB_001dac84:
                    /* Unresolved local var: char ch@[???] */
  g_scan = g_scan + 1;
  return cVar5;
}


// Sequence_ParseModifierLine  @ 001dad40
char Sequence_ParseModifierLine(sequenceEntry_s *entry,int modifierType)

{
  sequenceCommandLine_s *psVar1;
  char cVar2;
  sequenceCommandLine_s *defaults;
  sequenceCommandLine_s *psVar3;
  
LAB_001dad50:
  do {
    if (modifierType == 0) {
      cVar2 = Sequence_ParseModifier(&g_fileScopeDefaults);
    }
    else {
      if (modifierType != 1) goto LAB_001dad50;
      defaults = Mem_ZeroMalloc(0x5c);
      defaults->commandType = 9;
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???] */
      psVar1 = entry->firstCommand;
      if (entry->firstCommand == (sequenceCommandLine_s *)0x0) {
        entry->firstCommand = defaults;
        defaults->nextCommandLine = (sequenceCommandLine_s *)0x0;
      }
      else {
        do {
          psVar3 = psVar1;
          psVar1 = psVar3->nextCommandLine;
        } while (psVar1 != (sequenceCommandLine_s *)0x0);
        psVar3->nextCommandLine = defaults;
        defaults->nextCommandLine = (sequenceCommandLine_s *)0x0;
      }
      cVar2 = Sequence_ParseModifier(defaults);
    }
    if (cVar2 != ',') {
      return cVar2;
    }
  } while( true );
}


// Sequence_ParseSentenceBlock  @ 001dbdb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char Sequence_ParseSentenceBlock(void)

{
  char cVar1;
  byte bVar2;
  ushort **ppuVar3;
  char *pcVar4;
  qboolean qVar5;
  int iVar6;
  
                    /* Unresolved local var: char symbol@[DW_OP_reg2(EDX)]
                       Unresolved local var: qboolean finished@[???] */
                    /* Unresolved local var: char ch@[???] */
  ppuVar3 = __ctype_b_loc();
  while( true ) {
    pcVar4 = g_scan + 1;
    cVar1 = *g_scan;
    iVar6 = (int)cVar1;
    if ((*(byte *)((int)*ppuVar3 + iVar6 * 2 + 1) & 0x20) == 0) break;
    g_scan = pcVar4;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar4;
    }
  }
  if (cVar1 == '\0') {
    iVar6 = 0;
LAB_001dbe5a:
    Sys_Error("Parsing error on line %d of %s.seq: expected \'{\' to start a\n new sentence block; found \'%c\' instead!"
              ,g_lineNum,g_sequenceParseFileName,iVar6);
    qVar5 = Sequence_ParseSentenceLine();
    if (qVar5 != false) goto LAB_001dbe09;
  }
  else {
    g_scan = pcVar4;
                    /* Unresolved local var: char ch@[???] */
    if (cVar1 != '{') goto LAB_001dbe5a;
  }
  do {
    qVar5 = Sequence_ParseSentenceLine();
  } while (qVar5 == false);
LAB_001dbe09:
                    /* Unresolved local var: char ch@[DW_OP_reg2(EDX)]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
  cVar1 = *g_scan;
  bVar2 = *(byte *)((int)*ppuVar3 + cVar1 * 2 + 1);
  while ((bVar2 & 0x20) != 0) {
    g_scan = g_scan + 1;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = g_scan;
    }
    cVar1 = *g_scan;
    bVar2 = *(byte *)((int)*ppuVar3 + cVar1 * 2 + 1);
  }
  if (cVar1 != '\0') {
                    /* Unresolved local var: char ch@[???] */
    g_scan = g_scan + 1;
  }
  return cVar1;
}


// Sequence_ParseSentenceLine  @ 001dba50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Sequence_ParseSentenceLine(void)

{
  char cVar1;
  byte bVar2;
  ushort *puVar3;
  ushort **ppuVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  size_t __n;
  char *local_4a0;
  uint local_49c [255];
  char acStack_a0 [4];
  uint local_9c [16];
  char local_5c [76];
  
                    /* Unresolved local var: char[1024] data@[???]
                       Unresolved local var: char[64] fullgroup@[???]
                       Unresolved local var: char[64] groupName@[???]
                       Unresolved local var: char * c@[???]
                       Unresolved local var: int lastCharacterPos@[???] */
  ppuVar4 = __ctype_b_loc();
  while( true ) {
    pcVar5 = g_scan + 1;
    cVar1 = *g_scan;
    iVar11 = (int)cVar1;
    if (((*ppuVar4)[iVar11] & 0x2000) == 0) break;
    g_scan = pcVar5;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar5;
    }
  }
  if ((((((*ppuVar4)[iVar11] & 8) != 0) || ((byte)(cVar1 - 0x2dU) < 2)) || (cVar1 == '_')) ||
     ((cVar1 == '\\' || (cVar1 == '/')))) {
    Sequence_GetNameValueString((char *)local_9c,0x40);
    goto joined_r0x001dbb1f;
  }
  if (cVar1 != '=') {
    if (cVar1 < '>') {
      if ((cVar1 < '\"') || (('%' < cVar1 && (cVar1 != ',')))) {
LAB_001dbaf0:
        Sys_Error("Parsing error on line %d of %s.seq: expected token, found \'%c\' instead\n",
                  g_lineNum,g_sequenceParseFileName,iVar11);
        goto joined_r0x001dbb1f;
      }
    }
    else if (((cVar1 != '{') && (cVar1 != '}')) && (cVar1 != '@')) goto LAB_001dbaf0;
  }
  snprintf((char *)local_9c,0x40,"%c",iVar11);
  g_scan = g_scan + 1;
joined_r0x001dbb1f:
  if ((char)local_9c[0] != '}') {
    puVar10 = local_9c;
    do {
      puVar9 = puVar10;
      uVar6 = *puVar9 + 0xfefefeff & ~*puVar9;
      uVar7 = uVar6 & 0x80808080;
      puVar10 = puVar9 + 1;
    } while (uVar7 == 0);
    puVar3 = *ppuVar4;
    if ((uVar6 & 0x8080) == 0) {
      puVar10 = (uint *)((int)puVar9 + 6);
      uVar7 = uVar7 >> 0x10;
    }
    pcVar5 = (char *)((int)puVar10 + (-(int)local_9c - (uint)CARRY1((byte)uVar7,(byte)uVar7)) + -4);
    pcVar8 = (char *)((int)local_9c + (int)pcVar5);
    cVar1 = acStack_a0[(int)(pcVar5 + 4)];
    bVar2 = *(byte *)((int)puVar3 + cVar1 * 2 + 1);
    while (((bVar2 & 4) == 0 && (cVar1 != '_'))) {
      pcVar8 = pcVar8 + -1;
      cVar1 = *pcVar8;
      bVar2 = *(byte *)((int)puVar3 + cVar1 * 2 + 1);
    }
    if ((pcVar8 != (char *)0xffffffff) && (pcVar8[1] != '\0')) {
      pcVar8[1] = '\0';
    }
    strcpy(local_5c,(char *)local_9c);
                    /* Unresolved local var: int lineLen@[???]
                       Unresolved local var: char * read@[???]
                       Unresolved local var: char * write@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
    cVar1 = *g_scan;
    bVar2 = *(byte *)((int)puVar3 + cVar1 * 2 + 1);
    pcVar5 = g_scan;
    while ((bVar2 & 0x20) != 0) {
      pcVar5 = pcVar5 + 1;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
      cVar1 = *pcVar5;
      bVar2 = *(byte *)((int)*ppuVar4 + cVar1 * 2 + 1);
    }
    g_scan = pcVar5;
    local_4a0 = strchr(pcVar5,10);
    if (local_4a0 == (char *)0x0) {
      Sys_Error("Syntax Error on line %d of %s.seq: expected sentence definition or \'}\', found End-Of-File!\n"
                ,g_lineNum,g_sequenceParseFileName);
      pcVar5 = g_scan;
    }
    __n = (int)local_4a0 - (int)pcVar5;
    if (0x3ff < (int)__n) {
      Sys_Error("Syntax Error on line %d of %s.seq: line was too long (was %d chars; max is %d chars)\n"
                ,g_lineNum,g_sequenceParseFileName,__n,0x3ff);
      pcVar5 = g_scan;
    }
    strncpy((char *)local_49c,pcVar5,__n);
    *(undefined1 *)((int)local_49c + __n) = 0;
    g_scan = local_4a0;
    puVar10 = local_49c;
    do {
      puVar9 = puVar10;
      uVar6 = *puVar9 + 0xfefefeff & ~*puVar9;
      uVar7 = uVar6 & 0x80808080;
      puVar10 = puVar9 + 1;
    } while (uVar7 == 0);
    if ((uVar6 & 0x8080) == 0) {
      puVar10 = (uint *)((int)puVar9 + 6);
      uVar7 = uVar7 >> 0x10;
    }
    iVar11 = (-(int)local_49c - (uint)CARRY1((byte)uVar7,(byte)uVar7)) + -4;
    cVar1 = *(char *)((int)puVar10 + (int)local_49c + iVar11);
    if ((cVar1 == '\r') || (cVar1 == '\n')) {
      *(char *)((int)puVar10 + (int)local_49c + iVar11) = '\0';
      Sequence_AddSentenceToGroup(local_5c,(char *)local_49c);
    }
    else {
      Sequence_AddSentenceToGroup(local_5c,(char *)local_49c);
    }
    return false;
  }
  return true;
}


// Sequence_PurgeEntries  @ 001dcb80
void Sequence_PurgeEntries(qboolean purgeGlobals)

{
  sequenceEntry_s *psVar1;
  sequenceEntry_s *psVar2;
  sequenceEntry_s *psVar3;
  sentenceEntry_s *psVar4;
  sentenceEntry_s *p;
  sentenceGroupEntry_s *psVar5;
  sentenceGroupEntry_s *p_00;
  sentenceEntry_s *psVar6;
  sentenceGroupEntry_s *local_20;
  
                    /* Unresolved local var: sequenceEntry_s * scan@[???]
                       Unresolved local var: sequenceEntry_s * dead@[???]
                       Unresolved local var: sequenceEntry_s * prev@[???]
                       Unresolved local var: sentenceGroupEntry_s * groupEntry@[???]
                       Unresolved local var: sentenceGroupEntry_s * deadGroup@[???]
                       Unresolved local var: sentenceGroupEntry_s * prevGroup@[???] */
  if (g_sequenceList != (sequenceEntry_s *)0x0) {
    psVar3 = (sequenceEntry_s *)0x0;
    psVar2 = g_sequenceList;
    if (purgeGlobals == false) {
      do {
        if (psVar2->isGlobal == 0) {
          if (psVar3 == (sequenceEntry_s *)0x0) {
            psVar1 = psVar2->nextEntry;
            g_sequenceList = psVar1;
          }
          else {
            psVar3->nextEntry = psVar2->nextEntry;
            psVar1 = psVar2->nextEntry;
          }
          Sequence_FreeEntry(psVar2);
        }
        else {
          psVar1 = psVar2->nextEntry;
          psVar3 = psVar2;
        }
        psVar2 = psVar1;
      } while (psVar1 != (sequenceEntry_s *)0x0);
    }
    else {
      do {
        psVar3 = psVar2->nextEntry;
        g_sequenceList = psVar3;
        Sequence_FreeEntry(psVar2);
        psVar2 = psVar3;
      } while (psVar3 != (sequenceEntry_s *)0x0);
    }
  }
  if (g_sentenceGroupList != (sentenceGroupEntry_s *)0x0) {
    local_20 = (sentenceGroupEntry_s *)0x0;
    p_00 = g_sentenceGroupList;
    do {
                    /* Unresolved local var: sentenceEntry_s * sentenceEntry@[???]
                       Unresolved local var: sentenceEntry_s * prevSentence@[???]
                       Unresolved local var: sentenceEntry_s * deadSentence@[???] */
      p = p_00->firstSentence;
      if (p != (sentenceEntry_s *)0x0) {
        psVar6 = (sentenceEntry_s *)0x0;
        if (purgeGlobals == false) {
          do {
            if (p->isGlobal == 0) {
              if (psVar6 == (sentenceEntry_s *)0x0) {
                p_00->firstSentence = p->nextEntry;
              }
              else {
                psVar6->nextEntry = p->nextEntry;
              }
              p_00->numSentences = p_00->numSentences - 1;
              g_nonGlobalSentences = g_nonGlobalSentences - 1;
              psVar4 = p->nextEntry;
              if (p->data != (char *)0x0) {
                Mem_Free(p->data);
              }
              Mem_Free(p);
            }
            else {
              psVar4 = p->nextEntry;
              psVar6 = p;
            }
            p = psVar4;
          } while (psVar4 != (sentenceEntry_s *)0x0);
        }
        else {
          do {
            psVar6 = p->nextEntry;
            g_nonGlobalSentences = g_nonGlobalSentences - 1;
            p_00->numSentences = p_00->numSentences - 1;
            p_00->firstSentence = psVar6;
            psVar6 = p->nextEntry;
            if (p->data != (char *)0x0) {
              Mem_Free(p->data);
            }
            Mem_Free(p);
            p = psVar6;
          } while (psVar6 != (sentenceEntry_s *)0x0);
        }
      }
      if (p_00->numSentences == 0) {
        if (local_20 == (sentenceGroupEntry_s *)0x0) {
          psVar5 = p_00->nextEntry;
          g_sentenceGroupList = psVar5;
        }
        else {
          local_20->nextEntry = p_00->nextEntry;
          psVar5 = p_00->nextEntry;
        }
        if (p_00->groupName != (char *)0x0) {
          Mem_Free(p_00->groupName);
        }
        Mem_Free(p_00);
      }
      else {
        psVar5 = p_00->nextEntry;
        local_20 = p_00;
      }
      p_00 = psVar5;
    } while (psVar5 != (sentenceGroupEntry_s *)0x0);
  }
  return;
}


// Sequence_ReadCommandData  @ 001da060
void __regparm2
Sequence_ReadCommandData(sequenceCommandEnum_e commandEnum,sequenceCommandLine_s *defaults)

{
  char cVar1;
  byte bVar2;
  ushort **ppuVar3;
  long lVar4;
  char *pcVar5;
  char *pcVar6;
  double dVar7;
  undefined4 in_stack_00000004;
  int in_stack_00000008;
  char local_51c [1024];
  char local_11c [268];
  
                    /* Unresolved local var: char[1024] tempString@[???] */
  pcVar5 = g_scan;
  switch(in_stack_00000004) {
  case 0:
    ppuVar3 = __ctype_b_loc();
    while( true ) {
      pcVar5 = g_scan + 1;
      cVar1 = *g_scan;
      if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
      g_scan = pcVar5;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
    }
    Sequence_GetNameValueString(local_11c,0x100);
    dVar7 = strtod(local_11c,(char **)0x0);
    *(float *)(in_stack_00000008 + 0x48) = (float)dVar7;
    break;
  case 1:
    Sequence_ReadQuotedString(local_51c,(int)defaults);
    pcVar5 = Mem_Strdup(local_51c);
    *(char **)(in_stack_00000008 + 0x40) = pcVar5;
    break;
  case 2:
    Sequence_ReadQuotedString(local_51c,(int)defaults);
    pcVar5 = Mem_Strdup(local_51c);
    *(char **)(in_stack_00000008 + 0x44) = pcVar5;
    break;
  case 3:
    Sequence_ReadQuotedString(local_51c,(int)defaults);
    pcVar5 = Mem_Strdup(local_51c);
    *(char **)(in_stack_00000008 + 0x2c) = pcVar5;
    break;
  case 4:
    ppuVar3 = __ctype_b_loc();
    while( true ) {
      pcVar5 = g_scan + 1;
      cVar1 = *g_scan;
      if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
      g_scan = pcVar5;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
    }
    Sequence_GetNameValueString(local_51c,0x400);
    pcVar5 = Mem_Strdup(local_51c);
    *(char **)(in_stack_00000008 + 0x38) = pcVar5;
    break;
  case 5:
    ppuVar3 = __ctype_b_loc();
    while( true ) {
      pcVar5 = g_scan + 1;
      cVar1 = *g_scan;
      if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
      g_scan = pcVar5;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
    }
    Sequence_GetNameValueString(local_51c,0x400);
    pcVar5 = Mem_Strdup(local_51c);
    *(char **)(in_stack_00000008 + 0x28) = pcVar5;
    break;
  case 6:
    ppuVar3 = __ctype_b_loc();
    while( true ) {
      pcVar5 = g_scan + 1;
      cVar1 = *g_scan;
      if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
      g_scan = pcVar5;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
    }
    Sequence_GetNameValueString(local_51c,0x400);
    pcVar5 = Mem_Strdup(local_51c);
    *(char **)(in_stack_00000008 + 0x3c) = pcVar5;
    break;
  case 7:
    ppuVar3 = __ctype_b_loc();
    while( true ) {
      pcVar5 = g_scan + 1;
      cVar1 = *g_scan;
      if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
      g_scan = pcVar5;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
    }
    Sequence_GetNameValueString(local_11c,0x100);
    lVar4 = strtol(local_11c,(char **)0x0,10);
    *(long *)(in_stack_00000008 + 0x4c) = lVar4;
    break;
  default:
    Sys_Error("Internal error caused by line %d of %s.seq: unknown command enum = %d\n",g_lineNum,
              g_sequenceParseFileName);
    break;
  case 0xc:
    ppuVar3 = __ctype_b_loc();
    while( true ) {
      pcVar6 = pcVar5 + 1;
      cVar1 = *pcVar5;
      if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
      pcVar5 = pcVar6;
      g_scan = pcVar6;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar6;
      }
    }
    Sequence_GetNameValueString(local_11c,0x100);
    lVar4 = strtol(local_11c,(char **)0x0,10);
    *(uint *)(in_stack_00000008 + 0x54) = *(uint *)(in_stack_00000008 + 0x54) | 2;
    *(long *)(in_stack_00000008 + 4) = lVar4;
    break;
  case 0xd:
    ppuVar3 = __ctype_b_loc();
    while( true ) {
      pcVar5 = g_scan + 1;
      cVar1 = *g_scan;
      if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
      g_scan = pcVar5;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
    }
    Sequence_GetNameValueString(local_11c,0x100);
    dVar7 = strtod(local_11c,(char **)0x0);
    pcVar5 = g_scan;
                    /* Unresolved local var: char[256] floatString@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
    *(float *)(in_stack_00000008 + 0x10) = (float)dVar7;
    cVar1 = *pcVar5;
    bVar2 = *(byte *)((int)*ppuVar3 + cVar1 * 2 + 1);
    while ((bVar2 & 0x20) != 0) {
      pcVar5 = pcVar5 + 1;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
      cVar1 = *pcVar5;
      g_scan = pcVar5;
      bVar2 = *(byte *)((int)*ppuVar3 + cVar1 * 2 + 1);
    }
    Sequence_GetNameValueString(local_11c,0x100);
    dVar7 = strtod(local_11c,(char **)0x0);
    *(float *)(in_stack_00000008 + 0x14) = (float)dVar7;
    *(uint *)(in_stack_00000008 + 0x54) = *(uint *)(in_stack_00000008 + 0x54) | 4;
    break;
  case 0xe:
    ppuVar3 = __ctype_b_loc();
    while( true ) {
      pcVar5 = g_scan + 1;
      cVar1 = *g_scan;
      if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
      g_scan = pcVar5;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
    }
    Sequence_GetNameValueString(local_11c,0x100);
    lVar4 = strtol(local_11c,(char **)0x0,10);
    pcVar5 = g_scan;
                    /* Unresolved local var: char[256] intString@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
    *(char *)(in_stack_00000008 + 8) = (char)lVar4;
    cVar1 = *pcVar5;
    bVar2 = *(byte *)((int)*ppuVar3 + cVar1 * 2 + 1);
    while ((bVar2 & 0x20) != 0) {
      pcVar5 = pcVar5 + 1;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
      cVar1 = *pcVar5;
      g_scan = pcVar5;
      bVar2 = *(byte *)((int)*ppuVar3 + cVar1 * 2 + 1);
    }
    Sequence_GetNameValueString(local_11c,0x100);
    lVar4 = strtol(local_11c,(char **)0x0,10);
    pcVar5 = g_scan;
                    /* Unresolved local var: char[256] intString@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
    *(char *)(in_stack_00000008 + 9) = (char)lVar4;
    cVar1 = *pcVar5;
    bVar2 = *(byte *)((int)*ppuVar3 + cVar1 * 2 + 1);
    while ((bVar2 & 0x20) != 0) {
      pcVar5 = pcVar5 + 1;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
      cVar1 = *pcVar5;
      g_scan = pcVar5;
      bVar2 = *(byte *)((int)*ppuVar3 + cVar1 * 2 + 1);
    }
    Sequence_GetNameValueString(local_11c,0x100);
    lVar4 = strtol(local_11c,(char **)0x0,10);
    *(undefined1 *)(in_stack_00000008 + 0xb) = 0xff;
    *(uint *)(in_stack_00000008 + 0x54) = *(uint *)(in_stack_00000008 + 0x54) | 8;
    *(char *)(in_stack_00000008 + 10) = (char)lVar4;
    break;
  case 0xf:
    ppuVar3 = __ctype_b_loc();
    while( true ) {
      pcVar5 = g_scan + 1;
      cVar1 = *g_scan;
      if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
      g_scan = pcVar5;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
    }
    Sequence_GetNameValueString(local_11c,0x100);
    lVar4 = strtol(local_11c,(char **)0x0,10);
    pcVar5 = g_scan;
                    /* Unresolved local var: char[256] intString@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
    *(char *)(in_stack_00000008 + 0xc) = (char)lVar4;
    cVar1 = *pcVar5;
    bVar2 = *(byte *)((int)*ppuVar3 + cVar1 * 2 + 1);
    while ((bVar2 & 0x20) != 0) {
      pcVar5 = pcVar5 + 1;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
      cVar1 = *pcVar5;
      g_scan = pcVar5;
      bVar2 = *(byte *)((int)*ppuVar3 + cVar1 * 2 + 1);
    }
    Sequence_GetNameValueString(local_11c,0x100);
    lVar4 = strtol(local_11c,(char **)0x0,10);
    pcVar5 = g_scan;
                    /* Unresolved local var: char[256] intString@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
    *(char *)(in_stack_00000008 + 0xd) = (char)lVar4;
    cVar1 = *pcVar5;
    bVar2 = *(byte *)((int)*ppuVar3 + cVar1 * 2 + 1);
    while ((bVar2 & 0x20) != 0) {
      pcVar5 = pcVar5 + 1;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
      cVar1 = *pcVar5;
      g_scan = pcVar5;
      bVar2 = *(byte *)((int)*ppuVar3 + cVar1 * 2 + 1);
    }
    Sequence_GetNameValueString(local_11c,0x100);
    lVar4 = strtol(local_11c,(char **)0x0,10);
    *(undefined1 *)(in_stack_00000008 + 0xf) = 0xff;
    *(uint *)(in_stack_00000008 + 0x54) = *(uint *)(in_stack_00000008 + 0x54) | 0x10;
    *(char *)(in_stack_00000008 + 0xe) = (char)lVar4;
    break;
  case 0x10:
    ppuVar3 = __ctype_b_loc();
    while( true ) {
      pcVar5 = g_scan + 1;
      cVar1 = *g_scan;
      if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
      g_scan = pcVar5;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
    }
    Sequence_GetNameValueString(local_11c,0x100);
    dVar7 = strtod(local_11c,(char **)0x0);
    *(float *)(in_stack_00000008 + 0x18) = (float)dVar7;
    *(uint *)(in_stack_00000008 + 0x54) = *(uint *)(in_stack_00000008 + 0x54) | 0x20;
    break;
  case 0x11:
    ppuVar3 = __ctype_b_loc();
    while( true ) {
      pcVar5 = g_scan + 1;
      cVar1 = *g_scan;
      if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
      g_scan = pcVar5;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
    }
    Sequence_GetNameValueString(local_11c,0x100);
    dVar7 = strtod(local_11c,(char **)0x0);
    *(float *)(in_stack_00000008 + 0x1c) = (float)dVar7;
    *(uint *)(in_stack_00000008 + 0x54) = *(uint *)(in_stack_00000008 + 0x54) | 0x40;
    break;
  case 0x12:
    ppuVar3 = __ctype_b_loc();
    while( true ) {
      pcVar5 = g_scan + 1;
      cVar1 = *g_scan;
      if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
      g_scan = pcVar5;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
    }
    Sequence_GetNameValueString(local_11c,0x100);
    dVar7 = strtod(local_11c,(char **)0x0);
    *(float *)(in_stack_00000008 + 0x20) = (float)dVar7;
    *(uint *)(in_stack_00000008 + 0x54) = *(uint *)(in_stack_00000008 + 0x54) | 0x80;
    break;
  case 0x13:
    ppuVar3 = __ctype_b_loc();
    while( true ) {
      pcVar5 = g_scan + 1;
      cVar1 = *g_scan;
      if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
      g_scan = pcVar5;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
    }
    Sequence_GetNameValueString(local_11c,0x100);
    dVar7 = strtod(local_11c,(char **)0x0);
    *(float *)(in_stack_00000008 + 0x24) = (float)dVar7;
    *(uint *)(in_stack_00000008 + 0x54) = *(uint *)(in_stack_00000008 + 0x54) | 0x100;
    break;
  case 0x14:
    ppuVar3 = __ctype_b_loc();
    while( true ) {
      pcVar5 = g_scan + 1;
      cVar1 = *g_scan;
      if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
      g_scan = pcVar5;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
    }
    Sequence_GetNameValueString(local_51c,0x400);
    pcVar5 = Mem_Strdup(local_51c);
    *(uint *)(in_stack_00000008 + 0x54) = *(uint *)(in_stack_00000008 + 0x54) | 0x200;
    *(char **)(in_stack_00000008 + 0x30) = pcVar5;
    break;
  case 0x15:
    ppuVar3 = __ctype_b_loc();
    while( true ) {
      pcVar5 = g_scan + 1;
      cVar1 = *g_scan;
      if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
      g_scan = pcVar5;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
    }
    Sequence_GetNameValueString(local_51c,0x400);
    pcVar5 = Mem_Strdup(local_51c);
    *(uint *)(in_stack_00000008 + 0x54) = *(uint *)(in_stack_00000008 + 0x54) | 0x400;
    *(char **)(in_stack_00000008 + 0x34) = pcVar5;
    break;
  case 0x16:
    ppuVar3 = __ctype_b_loc();
    while( true ) {
      pcVar5 = g_scan + 1;
      cVar1 = *g_scan;
      if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
      g_scan = pcVar5;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
    }
    Sequence_GetNameValueString(local_11c,0x100);
    lVar4 = strtol(local_11c,(char **)0x0,10);
    *(uint *)(in_stack_00000008 + 0x54) = *(uint *)(in_stack_00000008 + 0x54) | 0x800;
    *(long *)(in_stack_00000008 + 0x50) = lVar4;
  }
  return;
}


// Sequence_ReadFloat  @ 001d9da0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float Sequence_ReadFloat(void)

{
  char cVar1;
  ushort **ppuVar2;
  char *pcVar3;
  double dVar4;
  char local_10c [260];
  
                    /* Unresolved local var: char[256] floatString@[???] */
  ppuVar2 = __ctype_b_loc();
  while( true ) {
    pcVar3 = g_scan + 1;
    cVar1 = *g_scan;
    if ((*(byte *)((int)*ppuVar2 + cVar1 * 2 + 1) & 0x20) == 0) break;
    g_scan = pcVar3;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar3;
    }
  }
  Sequence_GetNameValueString(local_10c,0x100);
  dVar4 = strtod(local_10c,(char **)0x0);
  return (float)dVar4;
}


// Sequence_ReadInt  @ 001d9d20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Sequence_ReadInt(void)

{
  char cVar1;
  ushort **ppuVar2;
  long lVar3;
  char *pcVar4;
  char local_10c [260];
  
                    /* Unresolved local var: char[256] intString@[???] */
  ppuVar2 = __ctype_b_loc();
  while( true ) {
    pcVar4 = g_scan + 1;
    cVar1 = *g_scan;
    if ((*(byte *)((int)*ppuVar2 + cVar1 * 2 + 1) & 0x20) == 0) break;
    g_scan = pcVar4;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar4;
    }
  }
  Sequence_GetNameValueString(local_10c,0x100);
  lVar3 = strtol(local_10c,(char **)0x0,10);
  return lVar3;
}


// Sequence_ReadQuotedString  @ 001d9280
void __regparm3 Sequence_ReadQuotedString(char *string,int stringLen)

{
  char *pcVar1;
  ushort **ppuVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  
                    /* Unresolved local var: char ch@[???]
                       Unresolved local var: char * write@[???] */
  ppuVar2 = __ctype_b_loc();
  while( true ) {
    pcVar3 = g_scan + 1;
    cVar4 = *g_scan;
    iVar5 = (int)cVar4;
    if ((*(byte *)((int)*ppuVar2 + iVar5 * 2 + 1) & 0x20) == 0) break;
    g_scan = pcVar3;
    if (cVar4 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar3;
    }
  }
                    /* Unresolved local var: char ch@[???] */
  if (cVar4 == '\0') {
    iVar5 = 0;
  }
  else {
    g_scan = pcVar3;
                    /* Unresolved local var: char ch@[???] */
    if (cVar4 == '\"') goto LAB_001d92e1;
  }
  Sys_Error("Parsing error on or before line %d of %s.seq: expected quote (\"), found \'%c\' instead\n"
            ,g_lineNum,g_sequenceParseFileName,iVar5);
LAB_001d92e1:
  cVar4 = *g_scan;
  pcVar3 = string;
  if ((cVar4 != '\0') && (cVar4 != '\"')) {
    do {
      if (cVar4 == '\n') {
        g_lineNum = g_lineNum + 1;
        cVar4 = *g_scan;
      }
      *pcVar3 = cVar4;
      pcVar3 = pcVar3 + 1;
      pcVar1 = g_scan + 1;
      cVar4 = g_scan[1];
      g_scan = pcVar1;
    } while (((cVar4 != '\"') && (cVar4 != '\0')) && ((int)pcVar3 - (int)string < 0x3ff));
  }
  *pcVar3 = '\0';
  g_scan = g_scan + 1;
  return;
}


// Sequence_ReadQuotedString  @ 001d9e90
void Sequence_ReadQuotedString(char *string,int stringLen)

{
  char *pcVar1;
  ushort **ppuVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  
                    /* Unresolved local var: char ch@[???]
                       Unresolved local var: char * write@[???] */
  if (stringLen < 1) {
    return;
  }
  ppuVar2 = __ctype_b_loc();
  while( true ) {
    pcVar3 = g_scan + 1;
    cVar4 = *g_scan;
    iVar5 = (int)cVar4;
    if ((*(byte *)((int)*ppuVar2 + iVar5 * 2 + 1) & 0x20) == 0) break;
    g_scan = pcVar3;
    if (cVar4 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar3;
    }
  }
                    /* Unresolved local var: char ch@[???] */
  if (cVar4 == '\0') {
    iVar5 = 0;
  }
  else {
    g_scan = pcVar3;
                    /* Unresolved local var: char ch@[???] */
    if (cVar4 == '\"') goto LAB_001d9f0f;
  }
  Sys_Error("Parsing error on or before line %d of %s.seq: expected quote (\"), found \'%c\' instead\n"
            ,g_lineNum,g_sequenceParseFileName,iVar5);
LAB_001d9f0f:
  cVar4 = *g_scan;
  pcVar3 = string;
  if (((cVar4 != '\"') && (cVar4 != '\0')) && (stringLen != 1)) {
    do {
      if (cVar4 == '\n') {
        g_lineNum = g_lineNum + 1;
        cVar4 = *g_scan;
      }
      *pcVar3 = cVar4;
      pcVar3 = pcVar3 + 1;
      pcVar1 = g_scan + 1;
      cVar4 = g_scan[1];
      g_scan = pcVar1;
    } while (((cVar4 != '\"') && (cVar4 != '\0')) && ((int)pcVar3 - (int)string < stringLen + -1));
  }
  *pcVar3 = '\0';
  g_scan = g_scan + 1;
  return;
}


// Sequence_ReadString  @ 001d9e20
void Sequence_ReadString(char *string,int stringLen)

{
  char cVar1;
  ushort **ppuVar2;
  char *pcVar3;
  
  ppuVar2 = __ctype_b_loc();
  while( true ) {
    pcVar3 = g_scan + 1;
    cVar1 = *g_scan;
    if ((*(byte *)((int)*ppuVar2 + cVar1 * 2 + 1) & 0x20) == 0) break;
    g_scan = pcVar3;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar3;
    }
  }
                    /* Unresolved local var: char * write@[???] */
  if (stringLen < 1) {
    return;
  }
  Sequence_GetNameValueString(string,stringLen);
  return;
}


// Sequence_ResetDefaults  @ 001d9400
void Sequence_ResetDefaults(sequenceCommandLine_s *destination,sequenceCommandLine_s *source)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  
  if (source != (sequenceCommandLine_s *)0x0) {
    (destination->clientMessage).effect = (source->clientMessage).effect;
    (destination->clientMessage).r1 = (source->clientMessage).r1;
    (destination->clientMessage).g1 = (source->clientMessage).g1;
    (destination->clientMessage).b1 = (source->clientMessage).b1;
    (destination->clientMessage).a1 = (source->clientMessage).a1;
    (destination->clientMessage).r2 = (source->clientMessage).r2;
    (destination->clientMessage).g2 = (source->clientMessage).g2;
    (destination->clientMessage).b2 = (source->clientMessage).b2;
    (destination->clientMessage).a2 = (source->clientMessage).a2;
    (destination->clientMessage).x = (source->clientMessage).x;
    (destination->clientMessage).y = (source->clientMessage).y;
    (destination->clientMessage).fadein = (source->clientMessage).fadein;
    (destination->clientMessage).fadeout = (source->clientMessage).fadeout;
    (destination->clientMessage).holdtime = (source->clientMessage).holdtime;
    fVar1 = (source->clientMessage).fxtime;
    (destination->clientMessage).pName = (char *)0x0;
    (destination->clientMessage).pMessage = (char *)0x0;
    (destination->clientMessage).fxtime = fVar1;
    destination->textChannel = source->textChannel;
    destination->delay = source->delay;
    iVar2 = source->repeatCount;
    destination->nextCommandLine = (sequenceCommandLine_s *)0x0;
    destination->soundFileName = (char *)0x0;
    destination->repeatCount = iVar2;
    if (destination->speakerName != (char *)0x0) {
      Mem_Free(destination->speakerName);
    }
    pcVar3 = Mem_Strdup(source->speakerName);
    destination->speakerName = pcVar3;
    if (destination->listenerName != (char *)0x0) {
      Mem_Free(destination->listenerName);
    }
    pcVar3 = Mem_Strdup(source->listenerName);
    destination->listenerName = pcVar3;
    return;
  }
  (destination->clientMessage).effect = 0;
  (destination->clientMessage).r1 = 0xff;
  (destination->clientMessage).g1 = 0xff;
  (destination->clientMessage).b1 = 0xff;
  (destination->clientMessage).a1 = 0xff;
  (destination->clientMessage).r2 = 0xff;
  (destination->clientMessage).g2 = 0xff;
  (destination->clientMessage).b2 = 0xff;
  (destination->clientMessage).a2 = 0xff;
  (destination->clientMessage).x = 0.5;
  (destination->clientMessage).y = 0.5;
  (destination->clientMessage).fadein = 0.2;
  (destination->clientMessage).fadeout = 0.2;
  (destination->clientMessage).holdtime = 1.6;
  (destination->clientMessage).fxtime = 1.0;
  (destination->clientMessage).pName = (char *)0x0;
  (destination->clientMessage).pMessage = (char *)0x0;
  destination->textChannel = 0;
  destination->delay = 0.0;
  destination->repeatCount = 0;
  destination->nextCommandLine = (sequenceCommandLine_s *)0x0;
  destination->soundFileName = (char *)0x0;
  destination->speakerName = (char *)0x0;
  destination->listenerName = (char *)0x0;
  return;
}


// Sequence_SkipWhitespace  @ 001d97e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Sequence_SkipWhitespace(void)

{
  char cVar1;
  ushort **ppuVar2;
  qboolean qVar3;
  char *pcVar4;
  
                    /* Unresolved local var: qboolean passedCarriageReturn@[???] */
  ppuVar2 = __ctype_b_loc();
  qVar3 = false;
  while( true ) {
    pcVar4 = g_scan + 1;
    cVar1 = *g_scan;
    if ((*(byte *)((int)*ppuVar2 + cVar1 * 2 + 1) & 0x20) == 0) break;
    g_scan = pcVar4;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      qVar3 = true;
      g_lineScan = pcVar4;
    }
  }
  return qVar3;
}


// Sequence_StripComments  @ 001d9c20
/* WARNING: Removing unreachable block (ram,0x001d9ced) */

void Sequence_StripComments(char *buffer,int *pBufSize)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  
                    /* Unresolved local var: char * eof@[???]
                       Unresolved local var: char * read@[???]
                       Unresolved local var: char * write@[???] */
  pcVar3 = buffer + *pBufSize;
  if (buffer < pcVar3) {
    cVar1 = *buffer;
    pcVar2 = buffer;
    while (cVar1 != '\0') {
      if (cVar1 == '/') {
        if (pcVar2[1] == '/') {
          do {
            pcVar2 = pcVar2 + 1;
            cVar1 = *pcVar2;
            if ((cVar1 == '\n') || (cVar1 == '\0')) break;
          } while (cVar1 != '\r');
        }
        else {
          pcVar4 = pcVar2 + 3;
          if (pcVar2[1] != '*') goto LAB_001d9c50;
          while( true ) {
            cVar1 = pcVar4[-1];
            pcVar2 = pcVar4 + -1;
            if ((cVar1 == '\0') || (*pcVar4 == '\0')) goto LAB_001d9c54;
            if ((cVar1 == '*') && (*pcVar4 == '/')) break;
            if ((cVar1 == '\r') || (cVar1 == '\n')) {
              *buffer = cVar1;
              buffer = buffer + 1;
            }
            pcVar4 = pcVar4 + 1;
          }
          pcVar2 = pcVar4 + 1;
        }
      }
      else {
LAB_001d9c50:
        *buffer = cVar1;
        pcVar2 = pcVar2 + 1;
        buffer = buffer + 1;
      }
LAB_001d9c54:
      if (pcVar3 <= pcVar2) break;
      cVar1 = *pcVar2;
    }
  }
  *buffer = '\0';
  return;
}


// Sequence_ValidateNameValueString  @ 001d9960
void Sequence_ValidateNameValueString(char *token)

{
  ushort **ppuVar1;
  char cVar2;
  char *pcVar3;
  
                    /* Unresolved local var: char * scan@[???] */
  cVar2 = *token;
  if (cVar2 != '\0') {
    ppuVar1 = __ctype_b_loc();
    pcVar3 = token;
    do {
      if ((((((*ppuVar1)[cVar2] & 8) == 0) && (1 < (byte)(cVar2 - 0x2dU))) && (cVar2 != '_')) &&
         (cVar2 != '\\' && cVar2 != '/')) {
        Sys_Error("Parsing error on line %d of %s.seq: name/value string \"%s\" had illegal character \'%c\'\n"
                  ,g_lineNum,g_sequenceParseFileName,token,(int)cVar2);
      }
      pcVar3 = pcVar3 + 1;
      cVar2 = *pcVar3;
    } while (cVar2 != '\0');
  }
  return;
}


// Sequence_WriteDefaults  @ 001d9580
void Sequence_WriteDefaults(sequenceCommandLine_s *source,sequenceCommandLine_s *destination)

{
  uint uVar1;
  char *pcVar2;
  
  if (destination == (sequenceCommandLine_s *)0x0) {
    Sys_Error("Attempt to bake defaults into a non-existant command.");
  }
  if (source == (sequenceCommandLine_s *)0x0) {
    Sys_Error("Attempt to bake defaults from a non-existant command.");
  }
  uVar1 = source->modifierBitField;
  if ((uVar1 & 2) != 0) {
    (destination->clientMessage).effect = (source->clientMessage).effect;
    uVar1 = source->modifierBitField;
  }
  if ((uVar1 & 8) != 0) {
    (destination->clientMessage).r1 = (source->clientMessage).r1;
    (destination->clientMessage).g1 = (source->clientMessage).g1;
    (destination->clientMessage).b1 = (source->clientMessage).b1;
    (destination->clientMessage).a1 = (source->clientMessage).a1;
    uVar1 = source->modifierBitField;
  }
  if ((uVar1 & 0x10) != 0) {
    (destination->clientMessage).r2 = (source->clientMessage).r2;
    (destination->clientMessage).g2 = (source->clientMessage).g2;
    (destination->clientMessage).b2 = (source->clientMessage).b2;
    (destination->clientMessage).a2 = (source->clientMessage).a2;
    uVar1 = source->modifierBitField;
  }
  if ((uVar1 & 4) != 0) {
    (destination->clientMessage).x = (source->clientMessage).x;
    (destination->clientMessage).y = (source->clientMessage).y;
    uVar1 = source->modifierBitField;
  }
  if ((uVar1 & 0x20) != 0) {
    (destination->clientMessage).fadein = (source->clientMessage).fadein;
    uVar1 = source->modifierBitField;
  }
  if ((uVar1 & 0x40) != 0) {
    (destination->clientMessage).fadeout = (source->clientMessage).fadeout;
    uVar1 = source->modifierBitField;
  }
  if ((uVar1 & 0x80) != 0) {
    (destination->clientMessage).holdtime = (source->clientMessage).holdtime;
    uVar1 = source->modifierBitField;
  }
  if ((uVar1 & 0x100) != 0) {
    (destination->clientMessage).fxtime = (source->clientMessage).fxtime;
    uVar1 = source->modifierBitField;
  }
  if ((uVar1 & 0x800) != 0) {
    destination->textChannel = source->textChannel;
    uVar1 = source->modifierBitField;
  }
  if ((uVar1 & 0x200) != 0) {
    if (destination->speakerName != (char *)0x0) {
      Mem_Free(destination->speakerName);
    }
    pcVar2 = Mem_Strdup(source->speakerName);
    destination->speakerName = pcVar2;
    uVar1 = source->modifierBitField;
  }
  if ((uVar1 & 0x400) == 0) {
    return;
  }
  if (destination->listenerName != (char *)0x0) {
    Mem_Free(destination->listenerName);
  }
  pcVar2 = Mem_Strdup(source->listenerName);
  destination->listenerName = pcVar2;
  return;
}


