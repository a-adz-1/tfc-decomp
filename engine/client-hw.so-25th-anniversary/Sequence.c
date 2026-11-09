// Sequence_AddCommandLineToEntry  @ 00185650
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


// Sequence_AddSentenceGroup  @ 00186e10
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


// Sequence_AddSentenceToGroup  @ 00186e80
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
      if (iVar4 == 0) goto LAB_00186eb9;
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
  if (psVar7 == (sentenceGroupEntry_s *)0x0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Unable to allocate sentence group %s at line %d in file %s.seq",groupName,g_lineNum,
              g_sequenceParseFileName);
  }
LAB_00186eb9:
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


// Sequence_BakeDefaults  @ 00183d30
void Sequence_BakeDefaults(sequenceCommandLine_s *destination,sequenceCommandLine_s *source)

{
  char *pcVar1;
  
  if (destination == (sequenceCommandLine_s *)0x0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Attempt to bake defaults into a non-existant command.");
  }
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
                    /* WARNING: Subroutine does not return */
  Sys_Error("Attempt to bake defaults from a non-existant command.");
}


// Sequence_CalcEntryDuration  @ 00186110
float Sequence_CalcEntryDuration(sequenceEntry_s *entry)

{
  float fVar1;
  sequenceCommandLine_s *psVar2;
  
                    /* Unresolved local var: float duration@[???]
                       Unresolved local var: sequenceCommandLine_s * cmd@[DW_OP_reg0(EAX)] */
  fVar1 = 0.0;
  psVar2 = entry->firstCommand;
  if (psVar2 == (sequenceCommandLine_s *)0x0) {
    return 0.0;
  }
  do {
    fVar1 = fVar1 + psVar2->delay;
    psVar2 = psVar2->nextCommandLine;
  } while (psVar2 != (sequenceCommandLine_s *)0x0);
  return fVar1;
}


// Sequence_ConfirmCarriageReturnOrSymbol  @ 00184600
/* WARNING: Variable defined which should be unmapped: foundCarriageReturn */

qboolean Sequence_ConfirmCarriageReturnOrSymbol(char symbol)

{
  char cVar1;
  char *pcVar2;
  ushort **ppuVar3;
  char *pcVar4;
  qboolean qVar5;
  qboolean foundCarriageReturn;
  
  pcVar2 = g_scan;
                    /* Unresolved local var: qboolean passedCarriageReturn@[???] */
  qVar5 = false;
  ppuVar3 = __ctype_b_loc();
  while( true ) {
    pcVar4 = pcVar2 + 1;
    cVar1 = *pcVar2;
    if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
    pcVar2 = pcVar4;
    g_scan = pcVar4;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      qVar5 = true;
      g_lineScan = pcVar4;
    }
  }
  return symbol == cVar1 | qVar5;
}


// Sequence_CopyCommand  @ 00187510
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


// Sequence_CopyCommandList  @ 00187640
sequenceCommandLine_s * Sequence_CopyCommandList(sequenceCommandLine_s *list)

{
  sequenceCommandLine_s *psVar1;
  char *pcVar2;
  sequenceCommandLine_s *psVar3;
  sequenceCommandLine_s *psVar4;
  sequenceCommandLine_s *psVar5;
  
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???]
                       Unresolved local var: sequenceCommandLine_s * copyCommand@[???]
                       Unresolved local var: sequenceCommandLine_s * newCommandList@[???]
                       Unresolved local var: sequenceCommandLine_s * prevCommand@[???] */
  if (list == (sequenceCommandLine_s *)0x0) {
    psVar4 = (sequenceCommandLine_s *)0x0;
  }
  else {
    psVar3 = (sequenceCommandLine_s *)0x0;
    psVar5 = (sequenceCommandLine_s *)0x0;
    do {
      psVar4 = psVar3;
      psVar1 = psVar5;
      if (list->commandType != 8) {
                    /* Unresolved local var: sequenceCommandLine_s * commandCopy@[???] */
        psVar1 = Mem_ZeroMalloc(0x5c);
        psVar1->nextCommandLine = (sequenceCommandLine_s *)0x0;
        psVar1->commandType = list->commandType;
        psVar1->modifierBitField = list->modifierBitField;
        psVar1->repeatCount = list->repeatCount;
        psVar1->delay = list->delay;
        psVar1->textChannel = list->textChannel;
        pcVar2 = Mem_Strdup(list->fireTargetNames);
        psVar1->fireTargetNames = pcVar2;
        pcVar2 = Mem_Strdup(list->killTargetNames);
        psVar1->killTargetNames = pcVar2;
        pcVar2 = Mem_Strdup(list->listenerName);
        psVar1->listenerName = pcVar2;
        pcVar2 = Mem_Strdup(list->sentenceName);
        psVar1->sentenceName = pcVar2;
        pcVar2 = Mem_Strdup(list->soundFileName);
        psVar1->soundFileName = pcVar2;
        pcVar2 = Mem_Strdup(list->speakerName);
        psVar1->speakerName = pcVar2;
        (psVar1->clientMessage).effect = (list->clientMessage).effect;
        (psVar1->clientMessage).a1 = (list->clientMessage).a1;
        (psVar1->clientMessage).b1 = (list->clientMessage).b1;
        (psVar1->clientMessage).a2 = (list->clientMessage).a2;
        (psVar1->clientMessage).b2 = (list->clientMessage).b2;
        (psVar1->clientMessage).fadein = (list->clientMessage).fadein;
        (psVar1->clientMessage).fadeout = (list->clientMessage).fadeout;
        (psVar1->clientMessage).fxtime = (list->clientMessage).fxtime;
        (psVar1->clientMessage).g1 = (list->clientMessage).g1;
        (psVar1->clientMessage).g2 = (list->clientMessage).g2;
        (psVar1->clientMessage).holdtime = (list->clientMessage).holdtime;
        (psVar1->clientMessage).r1 = (list->clientMessage).r1;
        (psVar1->clientMessage).r2 = (list->clientMessage).r2;
        (psVar1->clientMessage).x = (list->clientMessage).x;
        (psVar1->clientMessage).y = (list->clientMessage).y;
        pcVar2 = Mem_Strdup((list->clientMessage).pMessage);
        (psVar1->clientMessage).pMessage = pcVar2;
        pcVar2 = Mem_Strdup((list->clientMessage).pName);
        (psVar1->clientMessage).pName = pcVar2;
        psVar4 = psVar1;
        if (psVar5 != (sequenceCommandLine_s *)0x0) {
          psVar5->nextCommandLine = psVar1;
          psVar4 = psVar3;
        }
      }
      list = list->nextCommandLine;
      psVar3 = psVar4;
      psVar5 = psVar1;
    } while (list != (sequenceCommandLine_s *)0x0);
  }
  return psVar4;
}


// Sequence_CreateDefaultsCommand  @ 001861b0
void Sequence_CreateDefaultsCommand(sequenceEntry_s *entry)

{
  sequenceCommandLine_s *psVar1;
  int iVar2;
  float fVar3;
  sequenceCommandLine_s *psVar4;
  char *pcVar5;
  sequenceCommandLine_s *psVar6;
  
                    /* Unresolved local var: sequenceCommandLine_s * defaultsCommand@[???] */
  psVar4 = Mem_ZeroMalloc(0x5c);
  iVar2 = g_fileScopeDefaults.clientMessage.effect;
  (psVar4->clientMessage).pName = (char *)0x0;
  (psVar4->clientMessage).pMessage = (char *)0x0;
  (psVar4->clientMessage).effect = iVar2;
  (psVar4->clientMessage).r1 = g_fileScopeDefaults.clientMessage.r1;
  (psVar4->clientMessage).g1 = g_fileScopeDefaults.clientMessage.g1;
  (psVar4->clientMessage).b1 = g_fileScopeDefaults.clientMessage.b1;
  (psVar4->clientMessage).a1 = g_fileScopeDefaults.clientMessage.a1;
  (psVar4->clientMessage).r2 = g_fileScopeDefaults.clientMessage.r2;
  (psVar4->clientMessage).g2 = g_fileScopeDefaults.clientMessage.g2;
  (psVar4->clientMessage).b2 = g_fileScopeDefaults.clientMessage.b2;
  (psVar4->clientMessage).a2 = g_fileScopeDefaults.clientMessage.a2;
  (psVar4->clientMessage).x = g_fileScopeDefaults.clientMessage.x;
  (psVar4->clientMessage).y = g_fileScopeDefaults.clientMessage.y;
  (psVar4->clientMessage).fadein = g_fileScopeDefaults.clientMessage.fadein;
  (psVar4->clientMessage).fadeout = g_fileScopeDefaults.clientMessage.fadeout;
  (psVar4->clientMessage).holdtime = g_fileScopeDefaults.clientMessage.holdtime;
  (psVar4->clientMessage).fxtime = g_fileScopeDefaults.clientMessage.fxtime;
  iVar2 = g_fileScopeDefaults.textChannel;
  fVar3 = g_fileScopeDefaults.delay;
  psVar4->nextCommandLine = (sequenceCommandLine_s *)0x0;
  psVar4->delay = fVar3;
  psVar4->textChannel = iVar2;
  iVar2 = g_fileScopeDefaults.repeatCount;
  psVar4->soundFileName = (char *)0x0;
  psVar4->repeatCount = iVar2;
  if (psVar4->speakerName != (char *)0x0) {
    Mem_Free(psVar4->speakerName);
  }
  pcVar5 = Mem_Strdup(g_fileScopeDefaults.speakerName);
  psVar4->speakerName = pcVar5;
  if (psVar4->listenerName != (char *)0x0) {
    Mem_Free(psVar4->listenerName);
  }
  pcVar5 = Mem_Strdup(g_fileScopeDefaults.listenerName);
  psVar4->commandType = 8;
  psVar4->modifierBitField = 0xff;
  psVar4->listenerName = pcVar5;
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???] */
  psVar1 = entry->firstCommand;
  if (entry->firstCommand != (sequenceCommandLine_s *)0x0) {
    do {
      psVar6 = psVar1;
      psVar1 = psVar6->nextCommandLine;
    } while (psVar1 != (sequenceCommandLine_s *)0x0);
    psVar6->nextCommandLine = psVar4;
    psVar4->nextCommandLine = (sequenceCommandLine_s *)0x0;
    return;
  }
  entry->firstCommand = psVar4;
  psVar4->nextCommandLine = (sequenceCommandLine_s *)0x0;
  return;
}


// Sequence_DoesEntryContainInfiniteLoop  @ 00186130
qboolean Sequence_DoesEntryContainInfiniteLoop(sequenceEntry_s *entry)

{
  sequenceCommandLine_s *psVar1;
  
                    /* Unresolved local var: sequenceCommandLine_s * cmd@[???] */
  psVar1 = entry->firstCommand;
  if (psVar1 == (sequenceCommandLine_s *)0x0) {
    return false;
  }
  do {
    if (psVar1->repeatCount < 0) {
      return true;
    }
    psVar1 = psVar1->nextCommandLine;
  } while (psVar1 != (sequenceCommandLine_s *)0x0);
  return false;
}


// Sequence_ExpandAllGosubs  @ 00187a80
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


// Sequence_ExpandGosubsForEntry  @ 001877c0
qboolean Sequence_ExpandGosubsForEntry(sequenceEntry_s *entry)

{
  char *__s2;
  sequenceCommandLine_s *psVar1;
  qboolean qVar2;
  int iVar3;
  sequenceCommandLine_s *psVar4;
  char *pcVar5;
  sequenceEntry_s *psVar6;
  sequenceCommandLine_s *psVar7;
  sequenceCommandLine_s *psVar8;
  sequenceCommandLine_s *psVar9;
  sequenceCommandLine_s *local_20;
  
                    /* Unresolved local var: sequenceCommandLine_s * cmd@[???]
                       Unresolved local var: qboolean foundGosubs@[???] */
  psVar8 = entry->firstCommand;
  if (psVar8 == (sequenceCommandLine_s *)0x0) {
    qVar2 = true;
  }
  else {
    qVar2 = false;
    do {
      pcVar5 = (psVar8->clientMessage).pName;
      if (pcVar5 != (char *)0x0) {
                    /* Unresolved local var: sequenceEntry_s * gosubEntry@[???]
                       Unresolved local var: sequenceCommandLine_s * copyList@[???]
                       Unresolved local var: sequenceCommandLine_s * scan@[???] */
        __s2 = entry->entryName;
        iVar3 = strcasecmp(pcVar5,__s2);
        if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("Error in %s.seq: entry \"%s\" gosubs itself!\n",entry->fileName,__s2);
        }
                    /* Unresolved local var: sequenceEntry_s * scan@[???] */
        psVar6 = g_sequenceList;
        if (g_sequenceList == (sequenceEntry_s *)0x0) {
LAB_001879f3:
                    /* WARNING: Subroutine does not return */
          Sys_Error("Error in %s.seq: Gosub in entry \"%s\" specified unknown entry \"%s\"\n",
                    entry->fileName,entry->entryName,pcVar5);
        }
        while (iVar3 = Q_stricmp(pcVar5,psVar6->entryName), iVar3 != 0) {
          psVar6 = psVar6->nextEntry;
          if (psVar6 == (sequenceEntry_s *)0x0) {
            pcVar5 = (psVar8->clientMessage).pName;
            goto LAB_001879f3;
          }
        }
        psVar7 = psVar6->firstCommand;
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???]
                       Unresolved local var: sequenceCommandLine_s * copyCommand@[???]
                       Unresolved local var: sequenceCommandLine_s * newCommandList@[???]
                       Unresolved local var: sequenceCommandLine_s * prevCommand@[???] */
        if (psVar7 != (sequenceCommandLine_s *)0x0) {
          local_20 = (sequenceCommandLine_s *)0x0;
          psVar9 = (sequenceCommandLine_s *)0x0;
          do {
            psVar4 = psVar9;
            psVar1 = local_20;
            if (psVar7->commandType != 8) {
                    /* Unresolved local var: sequenceCommandLine_s * commandCopy@[???] */
              psVar4 = Mem_ZeroMalloc(0x5c);
              psVar4->nextCommandLine = (sequenceCommandLine_s *)0x0;
              psVar4->commandType = psVar7->commandType;
              psVar4->modifierBitField = psVar7->modifierBitField;
              psVar4->repeatCount = psVar7->repeatCount;
              psVar4->delay = psVar7->delay;
              psVar4->textChannel = psVar7->textChannel;
              pcVar5 = Mem_Strdup(psVar7->fireTargetNames);
              psVar4->fireTargetNames = pcVar5;
              pcVar5 = Mem_Strdup(psVar7->killTargetNames);
              psVar4->killTargetNames = pcVar5;
              pcVar5 = Mem_Strdup(psVar7->listenerName);
              psVar4->listenerName = pcVar5;
              pcVar5 = Mem_Strdup(psVar7->sentenceName);
              psVar4->sentenceName = pcVar5;
              pcVar5 = Mem_Strdup(psVar7->soundFileName);
              psVar4->soundFileName = pcVar5;
              pcVar5 = Mem_Strdup(psVar7->speakerName);
              psVar4->speakerName = pcVar5;
              (psVar4->clientMessage).effect = (psVar7->clientMessage).effect;
              (psVar4->clientMessage).a1 = (psVar7->clientMessage).a1;
              (psVar4->clientMessage).b1 = (psVar7->clientMessage).b1;
              (psVar4->clientMessage).a2 = (psVar7->clientMessage).a2;
              (psVar4->clientMessage).b2 = (psVar7->clientMessage).b2;
              (psVar4->clientMessage).fadein = (psVar7->clientMessage).fadein;
              (psVar4->clientMessage).fadeout = (psVar7->clientMessage).fadeout;
              (psVar4->clientMessage).fxtime = (psVar7->clientMessage).fxtime;
              (psVar4->clientMessage).g1 = (psVar7->clientMessage).g1;
              (psVar4->clientMessage).g2 = (psVar7->clientMessage).g2;
              (psVar4->clientMessage).holdtime = (psVar7->clientMessage).holdtime;
              (psVar4->clientMessage).r1 = (psVar7->clientMessage).r1;
              (psVar4->clientMessage).r2 = (psVar7->clientMessage).r2;
              (psVar4->clientMessage).x = (psVar7->clientMessage).x;
              (psVar4->clientMessage).y = (psVar7->clientMessage).y;
              pcVar5 = Mem_Strdup((psVar7->clientMessage).pMessage);
              (psVar4->clientMessage).pMessage = pcVar5;
              pcVar5 = Mem_Strdup((psVar7->clientMessage).pName);
              (psVar4->clientMessage).pName = pcVar5;
              psVar1 = psVar4;
              if (psVar9 != (sequenceCommandLine_s *)0x0) {
                psVar9->nextCommandLine = psVar4;
                psVar1 = local_20;
              }
            }
            local_20 = psVar1;
            psVar7 = psVar7->nextCommandLine;
            psVar9 = psVar4;
          } while (psVar7 != (sequenceCommandLine_s *)0x0);
          psVar7 = local_20;
          if (local_20 != (sequenceCommandLine_s *)0x0) {
            do {
              psVar9 = psVar7;
              psVar7 = psVar9->nextCommandLine;
            } while (psVar9->nextCommandLine != (sequenceCommandLine_s *)0x0);
            psVar9->nextCommandLine = psVar8->nextCommandLine;
            psVar8->nextCommandLine = local_20;
            Mem_Free((psVar8->clientMessage).pName);
            qVar2 = true;
            (psVar8->clientMessage).pName = (char *)0x0;
            psVar8 = psVar9;
            goto LAB_001879cd;
          }
        }
        Mem_Free((psVar8->clientMessage).pName);
        qVar2 = true;
        (psVar8->clientMessage).pName = (char *)0x0;
      }
LAB_001879cd:
      psVar8 = psVar8->nextCommandLine;
    } while (psVar8 != (sequenceCommandLine_s *)0x0);
    qVar2 = qVar2 ^ true;
  }
  return qVar2;
}


// Sequence_FindSentenceGroup  @ 00186ca0
sentenceGroupEntry_s * Sequence_FindSentenceGroup(char *groupName)

{
  sentenceGroupEntry_s *psVar1;
  int iVar2;
  
  psVar1 = g_sentenceGroupList;
  while( true ) {
    if (psVar1 == (sentenceGroupEntry_s *)0x0) {
      return (sentenceGroupEntry_s *)0x0;
    }
    iVar2 = strcasecmp(psVar1->groupName,groupName);
    if (iVar2 == 0) break;
    psVar1 = psVar1->nextEntry;
  }
  return psVar1;
}


// Sequence_FlattenAllEntries  @ 00187e90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sequence_FlattenAllEntries(void)

{
  int iVar1;
  sequenceEntry_s *psVar2;
  char *pcVar3;
  uint uVar4;
  sequenceCommandLine_s *source;
  sequenceCommandLine_s *unaff_ESI;
  
  psVar2 = g_sequenceList;
  do {
    if (psVar2 == (sequenceEntry_s *)0x0) {
      return;
    }
                    /* Unresolved local var: sequenceCommandLine_s * cmd@[???]
                       Unresolved local var: sequenceCommandLine_s * lastCmd@[???] */
    for (source = psVar2->firstCommand; source != (sequenceCommandLine_s *)0x0;
        source = source->nextCommandLine) {
      while (iVar1 = source->commandType, iVar1 == 9) {
        uVar4 = source->modifierBitField;
        if ((uVar4 & 2) != 0) {
          g_blockScopeDefaults.clientMessage.effect = (source->clientMessage).effect;
        }
        if ((uVar4 & 8) != 0) {
          g_blockScopeDefaults.clientMessage.r1 = (source->clientMessage).r1;
          g_blockScopeDefaults.clientMessage.g1 = (source->clientMessage).g1;
          g_blockScopeDefaults.clientMessage.b1 = (source->clientMessage).b1;
          g_blockScopeDefaults.clientMessage.a1 = (source->clientMessage).a1;
        }
        if ((uVar4 & 0x10) != 0) {
          g_blockScopeDefaults.clientMessage.r2 = (source->clientMessage).r2;
          g_blockScopeDefaults.clientMessage.g2 = (source->clientMessage).g2;
          g_blockScopeDefaults.clientMessage.b2 = (source->clientMessage).b2;
          g_blockScopeDefaults.clientMessage.a2 = (source->clientMessage).a2;
        }
        if ((uVar4 & 4) != 0) {
          g_blockScopeDefaults.clientMessage.x = (source->clientMessage).x;
          g_blockScopeDefaults.clientMessage.y = (source->clientMessage).y;
        }
        if ((uVar4 & 0x20) != 0) {
          g_blockScopeDefaults.clientMessage.fadein = (source->clientMessage).fadein;
        }
        if ((uVar4 & 0x40) != 0) {
          g_blockScopeDefaults.clientMessage.fadeout = (source->clientMessage).fadeout;
        }
        if ((uVar4 & 0x80) != 0) {
          g_blockScopeDefaults.clientMessage.holdtime = (source->clientMessage).holdtime;
        }
        if ((uVar4 & 0x100) != 0) {
          g_blockScopeDefaults.clientMessage.fxtime = (source->clientMessage).fxtime;
        }
        if ((uVar4 & 0x800) != 0) {
          g_blockScopeDefaults.textChannel = source->textChannel;
        }
        if ((uVar4 & 0x200) != 0) {
          if (g_blockScopeDefaults.speakerName != (char *)0x0) {
            Mem_Free(g_blockScopeDefaults.speakerName);
          }
          g_blockScopeDefaults.speakerName = Mem_Strdup(source->speakerName);
          uVar4 = source->modifierBitField;
        }
        if ((uVar4 & 0x400) == 0) goto LAB_00187fc4;
        if (g_blockScopeDefaults.listenerName != (char *)0x0) {
          Mem_Free(g_blockScopeDefaults.listenerName);
        }
        g_blockScopeDefaults.listenerName = Mem_Strdup(source->listenerName);
        source = source->nextCommandLine;
        if (source == (sequenceCommandLine_s *)0x0) goto LAB_00188120;
      }
      if (iVar1 == 10) {
        Sequence_WriteDefaults(source,unaff_ESI);
      }
      else if (iVar1 == 8) {
        uVar4 = source->modifierBitField;
        if ((uVar4 & 2) != 0) {
          g_blockScopeDefaults.clientMessage.effect = (source->clientMessage).effect;
        }
        if ((uVar4 & 8) != 0) {
          g_blockScopeDefaults.clientMessage.r1 = (source->clientMessage).r1;
          g_blockScopeDefaults.clientMessage.g1 = (source->clientMessage).g1;
          g_blockScopeDefaults.clientMessage.b1 = (source->clientMessage).b1;
          g_blockScopeDefaults.clientMessage.a1 = (source->clientMessage).a1;
        }
        if ((uVar4 & 0x10) != 0) {
          g_blockScopeDefaults.clientMessage.r2 = (source->clientMessage).r2;
          g_blockScopeDefaults.clientMessage.g2 = (source->clientMessage).g2;
          g_blockScopeDefaults.clientMessage.b2 = (source->clientMessage).b2;
          g_blockScopeDefaults.clientMessage.a2 = (source->clientMessage).a2;
        }
        if ((uVar4 & 4) != 0) {
          g_blockScopeDefaults.clientMessage.x = (source->clientMessage).x;
          g_blockScopeDefaults.clientMessage.y = (source->clientMessage).y;
        }
        if ((uVar4 & 0x20) != 0) {
          g_blockScopeDefaults.clientMessage.fadein = (source->clientMessage).fadein;
        }
        if ((uVar4 & 0x40) != 0) {
          g_blockScopeDefaults.clientMessage.fadeout = (source->clientMessage).fadeout;
        }
        if ((uVar4 & 0x80) != 0) {
          g_blockScopeDefaults.clientMessage.holdtime = (source->clientMessage).holdtime;
        }
        if ((uVar4 & 0x100) != 0) {
          g_blockScopeDefaults.clientMessage.fxtime = (source->clientMessage).fxtime;
        }
        if ((uVar4 & 0x800) != 0) {
          g_blockScopeDefaults.textChannel = source->textChannel;
        }
        if ((uVar4 & 0x200) != 0) {
          if (g_blockScopeDefaults.speakerName != (char *)0x0) {
            Mem_Free(g_blockScopeDefaults.speakerName);
          }
          g_blockScopeDefaults.speakerName = Mem_Strdup(source->speakerName);
          uVar4 = source->modifierBitField;
        }
        if ((uVar4 & 0x400) != 0) {
          if (g_blockScopeDefaults.listenerName != (char *)0x0) {
            Mem_Free(g_blockScopeDefaults.listenerName);
          }
          g_blockScopeDefaults.listenerName = Mem_Strdup(source->listenerName);
        }
        source->commandType = 0xb;
      }
      else {
        (source->clientMessage).effect = g_blockScopeDefaults.clientMessage.effect;
        (source->clientMessage).r1 = g_blockScopeDefaults.clientMessage.r1;
        (source->clientMessage).g1 = g_blockScopeDefaults.clientMessage.g1;
        (source->clientMessage).b1 = g_blockScopeDefaults.clientMessage.b1;
        (source->clientMessage).a1 = g_blockScopeDefaults.clientMessage.a1;
        (source->clientMessage).r2 = g_blockScopeDefaults.clientMessage.r2;
        (source->clientMessage).g2 = g_blockScopeDefaults.clientMessage.g2;
        (source->clientMessage).b2 = g_blockScopeDefaults.clientMessage.b2;
        (source->clientMessage).a2 = g_blockScopeDefaults.clientMessage.a2;
        (source->clientMessage).x = g_blockScopeDefaults.clientMessage.x;
        (source->clientMessage).y = g_blockScopeDefaults.clientMessage.y;
        (source->clientMessage).fadein = g_blockScopeDefaults.clientMessage.fadein;
        (source->clientMessage).fadeout = g_blockScopeDefaults.clientMessage.fadeout;
        (source->clientMessage).holdtime = g_blockScopeDefaults.clientMessage.holdtime;
        (source->clientMessage).fxtime = g_blockScopeDefaults.clientMessage.fxtime;
        source->textChannel = g_blockScopeDefaults.textChannel;
        if (source->speakerName != (char *)0x0) {
          Mem_Free(source->speakerName);
        }
        pcVar3 = Mem_Strdup(g_blockScopeDefaults.speakerName);
        source->speakerName = pcVar3;
        if (source->listenerName != (char *)0x0) {
          Mem_Free(source->listenerName);
        }
        pcVar3 = Mem_Strdup(g_blockScopeDefaults.listenerName);
        source->listenerName = pcVar3;
        unaff_ESI = source;
      }
LAB_00187fc4:
    }
LAB_00188120:
    psVar2 = psVar2->nextEntry;
  } while( true );
}


// Sequence_FlattenEntry  @ 00187ac0
void Sequence_FlattenEntry(sequenceEntry_s *entry)

{
  sequenceCommandLine_s *source;
  int iVar1;
  char *pcVar2;
  uint uVar3;
  sequenceCommandLine_s *unaff_ESI;
  
                    /* Unresolved local var: sequenceCommandLine_s * cmd@[???]
                       Unresolved local var: sequenceCommandLine_s * lastCmd@[???] */
  source = entry->firstCommand;
  do {
    while( true ) {
      if (source == (sequenceCommandLine_s *)0x0) {
        return;
      }
      iVar1 = source->commandType;
      if (iVar1 == 9) break;
      if (iVar1 == 10) {
        Sequence_WriteDefaults(source,unaff_ESI);
      }
      else if (iVar1 == 8) {
        uVar3 = source->modifierBitField;
        if ((uVar3 & 2) != 0) {
          g_blockScopeDefaults.clientMessage.effect = (source->clientMessage).effect;
        }
        if ((uVar3 & 8) != 0) {
          g_blockScopeDefaults.clientMessage.r1 = (source->clientMessage).r1;
          g_blockScopeDefaults.clientMessage.g1 = (source->clientMessage).g1;
          g_blockScopeDefaults.clientMessage.b1 = (source->clientMessage).b1;
          g_blockScopeDefaults.clientMessage.a1 = (source->clientMessage).a1;
        }
        if ((uVar3 & 0x10) != 0) {
          g_blockScopeDefaults.clientMessage.r2 = (source->clientMessage).r2;
          g_blockScopeDefaults.clientMessage.g2 = (source->clientMessage).g2;
          g_blockScopeDefaults.clientMessage.b2 = (source->clientMessage).b2;
          g_blockScopeDefaults.clientMessage.a2 = (source->clientMessage).a2;
        }
        if ((uVar3 & 4) != 0) {
          g_blockScopeDefaults.clientMessage.x = (source->clientMessage).x;
          g_blockScopeDefaults.clientMessage.y = (source->clientMessage).y;
        }
        if ((uVar3 & 0x20) != 0) {
          g_blockScopeDefaults.clientMessage.fadein = (source->clientMessage).fadein;
        }
        if ((uVar3 & 0x40) != 0) {
          g_blockScopeDefaults.clientMessage.fadeout = (source->clientMessage).fadeout;
        }
        if ((uVar3 & 0x80) != 0) {
          g_blockScopeDefaults.clientMessage.holdtime = (source->clientMessage).holdtime;
        }
        if ((uVar3 & 0x100) != 0) {
          g_blockScopeDefaults.clientMessage.fxtime = (source->clientMessage).fxtime;
        }
        if ((uVar3 & 0x800) != 0) {
          g_blockScopeDefaults.textChannel = source->textChannel;
        }
        if ((uVar3 & 0x200) != 0) {
          if (g_blockScopeDefaults.speakerName != (char *)0x0) {
            Mem_Free(g_blockScopeDefaults.speakerName);
          }
          g_blockScopeDefaults.speakerName = Mem_Strdup(source->speakerName);
          uVar3 = source->modifierBitField;
        }
        if ((uVar3 & 0x400) != 0) {
          if (g_blockScopeDefaults.listenerName != (char *)0x0) {
            Mem_Free(g_blockScopeDefaults.listenerName);
          }
          g_blockScopeDefaults.listenerName = Mem_Strdup(source->listenerName);
        }
        source->commandType = 0xb;
      }
      else {
        (source->clientMessage).effect = g_blockScopeDefaults.clientMessage.effect;
        (source->clientMessage).r1 = g_blockScopeDefaults.clientMessage.r1;
        (source->clientMessage).g1 = g_blockScopeDefaults.clientMessage.g1;
        (source->clientMessage).b1 = g_blockScopeDefaults.clientMessage.b1;
        (source->clientMessage).a1 = g_blockScopeDefaults.clientMessage.a1;
        (source->clientMessage).r2 = g_blockScopeDefaults.clientMessage.r2;
        (source->clientMessage).g2 = g_blockScopeDefaults.clientMessage.g2;
        (source->clientMessage).b2 = g_blockScopeDefaults.clientMessage.b2;
        (source->clientMessage).a2 = g_blockScopeDefaults.clientMessage.a2;
        (source->clientMessage).x = g_blockScopeDefaults.clientMessage.x;
        (source->clientMessage).y = g_blockScopeDefaults.clientMessage.y;
        (source->clientMessage).fadein = g_blockScopeDefaults.clientMessage.fadein;
        (source->clientMessage).fadeout = g_blockScopeDefaults.clientMessage.fadeout;
        (source->clientMessage).holdtime = g_blockScopeDefaults.clientMessage.holdtime;
        (source->clientMessage).fxtime = g_blockScopeDefaults.clientMessage.fxtime;
        source->textChannel = g_blockScopeDefaults.textChannel;
        if (source->speakerName != (char *)0x0) {
          Mem_Free(source->speakerName);
        }
        pcVar2 = Mem_Strdup(g_blockScopeDefaults.speakerName);
        source->speakerName = pcVar2;
        if (source->listenerName != (char *)0x0) {
          Mem_Free(source->listenerName);
        }
        pcVar2 = Mem_Strdup(g_blockScopeDefaults.listenerName);
        source->listenerName = pcVar2;
        unaff_ESI = source;
      }
LAB_00187be4:
      source = source->nextCommandLine;
    }
    uVar3 = source->modifierBitField;
    if ((uVar3 & 2) != 0) {
      g_blockScopeDefaults.clientMessage.effect = (source->clientMessage).effect;
    }
    if ((uVar3 & 8) != 0) {
      g_blockScopeDefaults.clientMessage.r1 = (source->clientMessage).r1;
      g_blockScopeDefaults.clientMessage.g1 = (source->clientMessage).g1;
      g_blockScopeDefaults.clientMessage.b1 = (source->clientMessage).b1;
      g_blockScopeDefaults.clientMessage.a1 = (source->clientMessage).a1;
    }
    if ((uVar3 & 0x10) != 0) {
      g_blockScopeDefaults.clientMessage.r2 = (source->clientMessage).r2;
      g_blockScopeDefaults.clientMessage.g2 = (source->clientMessage).g2;
      g_blockScopeDefaults.clientMessage.b2 = (source->clientMessage).b2;
      g_blockScopeDefaults.clientMessage.a2 = (source->clientMessage).a2;
    }
    if ((uVar3 & 4) != 0) {
      g_blockScopeDefaults.clientMessage.x = (source->clientMessage).x;
      g_blockScopeDefaults.clientMessage.y = (source->clientMessage).y;
    }
    if ((uVar3 & 0x20) != 0) {
      g_blockScopeDefaults.clientMessage.fadein = (source->clientMessage).fadein;
    }
    if ((uVar3 & 0x40) != 0) {
      g_blockScopeDefaults.clientMessage.fadeout = (source->clientMessage).fadeout;
    }
    if ((uVar3 & 0x80) != 0) {
      g_blockScopeDefaults.clientMessage.holdtime = (source->clientMessage).holdtime;
    }
    if ((uVar3 & 0x100) != 0) {
      g_blockScopeDefaults.clientMessage.fxtime = (source->clientMessage).fxtime;
    }
    if ((uVar3 & 0x800) != 0) {
      g_blockScopeDefaults.textChannel = source->textChannel;
    }
    if ((uVar3 & 0x200) != 0) {
      if (g_blockScopeDefaults.speakerName != (char *)0x0) {
        Mem_Free(g_blockScopeDefaults.speakerName);
      }
      g_blockScopeDefaults.speakerName = Mem_Strdup(source->speakerName);
      uVar3 = source->modifierBitField;
    }
    if ((uVar3 & 0x400) == 0) goto LAB_00187be4;
    if (g_blockScopeDefaults.listenerName != (char *)0x0) {
      Mem_Free(g_blockScopeDefaults.listenerName);
    }
    g_blockScopeDefaults.listenerName = Mem_Strdup(source->listenerName);
    source = source->nextCommandLine;
  } while( true );
}


// Sequence_FreeCommand  @ 00188790
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


// Sequence_FreeDataPointer  @ 001839b0
void Sequence_FreeDataPointer(void *data)

{
  if (data != (void *)0x0) {
    Mem_Free(data);
    return;
  }
  return;
}


// Sequence_FreeEntry  @ 00188820
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
  if (kill != (sequenceEntry_s *)0x0) {
    Mem_Free(kill);
    return;
  }
  return;
}


// Sequence_FreeSentence  @ 001888e0
void Sequence_FreeSentence(sentenceEntry_s *sentenceEntry)

{
  if (sentenceEntry->data != (char *)0x0) {
    Mem_Free(sentenceEntry->data);
  }
  if (sentenceEntry != (sentenceEntry_s *)0x0) {
    Mem_Free(sentenceEntry);
    return;
  }
  return;
}


// Sequence_FreeSentenceGroup  @ 00188920
void Sequence_FreeSentenceGroup(sentenceGroupEntry_s *groupEntry)

{
  if (groupEntry->groupName != (char *)0x0) {
    Mem_Free(groupEntry->groupName);
  }
  if (groupEntry != (sentenceGroupEntry_s *)0x0) {
    Mem_Free(groupEntry);
    return;
  }
  return;
}


// Sequence_FreeSentenceGroupEntries  @ 00188960
void Sequence_FreeSentenceGroupEntries(sentenceGroupEntry_s *groupEntry,qboolean purgeGlobals)

{
  sentenceEntry_s *psVar1;
  sentenceEntry_s *p;
  sentenceEntry_s *psVar2;
  
                    /* Unresolved local var: sentenceEntry_s * sentenceEntry@[???]
                       Unresolved local var: sentenceEntry_s * deadSentence@[???]
                       Unresolved local var: sentenceEntry_s * prevSentence@[???] */
  if (groupEntry->firstSentence != (sentenceEntry_s *)0x0) {
    psVar1 = groupEntry->firstSentence;
    psVar2 = (sentenceEntry_s *)0x0;
    do {
      while ((p = psVar1, p->isGlobal == 0 || (purgeGlobals != false))) {
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
        if (psVar1 == (sentenceEntry_s *)0x0) {
          return;
        }
      }
      psVar1 = p->nextEntry;
      psVar2 = p;
    } while (p->nextEntry != (sentenceEntry_s *)0x0);
  }
  return;
}


// Sequence_GetCommandEnumForName  @ 001839d0
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


// Sequence_GetEntryForName  @ 001874c0
sequenceEntry_s * Sequence_GetEntryForName(char *entryName)

{
  sequenceEntry_s *psVar1;
  int iVar2;
  
  psVar1 = g_sequenceList;
  while( true ) {
    if (psVar1 == (sequenceEntry_s *)0x0) {
      return (sequenceEntry_s *)0x0;
    }
    iVar2 = Q_stricmp(entryName,psVar1->entryName);
    if (iVar2 == 0) break;
    psVar1 = psVar1->nextEntry;
  }
  return psVar1;
}


// Sequence_GetLine  @ 00184140
void Sequence_GetLine(char *line,int lineMaxLen)

{
  char cVar1;
  char *__s;
  ushort **ppuVar2;
  char *pcVar3;
  size_t __n;
  
                    /* Unresolved local var: int lineLen@[???]
                       Unresolved local var: char * read@[???]
                       Unresolved local var: char * write@[???] */
  __s = g_scan;
  ppuVar2 = __ctype_b_loc();
  while( true ) {
    pcVar3 = __s + 1;
    cVar1 = *__s;
    if ((*(byte *)((int)*ppuVar2 + cVar1 * 2 + 1) & 0x20) == 0) break;
    __s = pcVar3;
    g_scan = pcVar3;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar3;
    }
  }
  pcVar3 = strchr(__s,10);
  if (pcVar3 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Syntax Error on line %d of %s.seq: expected sentence definition or \'}\', found End-Of-File!\n"
              ,g_lineNum,g_sequenceParseFileName);
  }
  __n = (int)pcVar3 - (int)__s;
  if ((int)__n < lineMaxLen) {
    strncpy(line,__s,__n);
    line[__n] = '\0';
    g_scan = pcVar3;
    return;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Syntax Error on line %d of %s.seq: line was too long (was %d chars; max is %d chars)\n"
            ,g_lineNum,g_sequenceParseFileName,__n,lineMaxLen + -1);
}


// Sequence_GetNameValueString  @ 00183580
void __regparm3 Sequence_GetNameValueString(char *token,int tokenLen)

{
  ushort uVar1;
  ushort **ppuVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  char *pcVar6;
  
                    /* Unresolved local var: char * write@[???] */
  pcVar6 = g_scan;
  ppuVar2 = __ctype_b_loc();
  while( true ) {
    pcVar3 = pcVar6 + 1;
    cVar4 = *pcVar6;
    iVar5 = (int)cVar4;
    uVar1 = (*ppuVar2)[iVar5];
    if ((uVar1 & 0x2000) == 0) break;
    pcVar6 = pcVar3;
    g_scan = pcVar3;
    if (cVar4 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar3;
    }
  }
  pcVar6 = token;
  if (((((uVar1 & 8) == 0) && (2 < (byte)(cVar4 - 0x2dU))) && (cVar4 != '_')) && (cVar4 != '\\')) {
    if ((byte)(cVar4 - 0x23U) < 2) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Parsing error on line %d of %s.seq: cannot have more than one \'%c\' per line; \'%c\' must be at the beginning of the line ONLY\n"
                ,g_lineNum,g_sequenceParseFileName,iVar5,iVar5);
    }
                    /* WARNING: Subroutine does not return */
    Sys_Error("Parsing error on line %d of %s.seq: expected name/value, found illegal character \'%c\'\n"
              ,g_lineNum,g_sequenceParseFileName,iVar5);
  }
  for (; (((cVar4 = (char)iVar5, (uVar1 & 8) != 0 || ((byte)(cVar4 - 0x2dU) < 3)) ||
          ((cVar4 == '_' || (cVar4 == '\\')))) && ((int)pcVar6 - (int)token < 0xff));
      pcVar6 = pcVar6 + 1) {
    *pcVar6 = cVar4;
    iVar5 = (int)g_scan[1];
    uVar1 = (*ppuVar2)[iVar5];
    g_scan = g_scan + 1;
  }
  *pcVar6 = '\0';
  return;
}


// Sequence_GetNameValueString  @ 001836d0
void __regparm3 Sequence_GetNameValueString(char *token,int tokenLen)

{
  ushort uVar1;
  ushort **ppuVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  
                    /* Unresolved local var: char * write@[???] */
  pcVar6 = g_scan;
  ppuVar2 = __ctype_b_loc();
  while( true ) {
    pcVar4 = pcVar6 + 1;
    cVar3 = *pcVar6;
    iVar5 = (int)cVar3;
    uVar1 = (*ppuVar2)[iVar5];
    if ((uVar1 & 0x2000) == 0) break;
    pcVar6 = pcVar4;
    g_scan = pcVar4;
    if (cVar3 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar4;
    }
  }
  if (((((uVar1 & 8) == 0) && (2 < (byte)(cVar3 - 0x2dU))) && (cVar3 != '_')) && (cVar3 != '\\')) {
    if ((byte)(cVar3 - 0x23U) < 2) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Parsing error on line %d of %s.seq: cannot have more than one \'%c\' per line; \'%c\' must be at the beginning of the line ONLY\n"
                ,g_lineNum,g_sequenceParseFileName,iVar5,iVar5);
    }
                    /* WARNING: Subroutine does not return */
    Sys_Error("Parsing error on line %d of %s.seq: expected name/value, found illegal character \'%c\'\n"
              ,g_lineNum,g_sequenceParseFileName,iVar5);
  }
  for (pcVar6 = token;
      (((cVar3 = (char)iVar5, (uVar1 & 8) != 0 || ((byte)(cVar3 - 0x2dU) < 3)) ||
       ((cVar3 == '_' || (cVar3 == '\\')))) && ((int)pcVar6 - (int)token < tokenLen + -1));
      pcVar6 = pcVar6 + 1) {
    *pcVar6 = cVar3;
    iVar5 = (int)g_scan[1];
    uVar1 = (*ppuVar2)[iVar5];
    g_scan = g_scan + 1;
  }
  *pcVar6 = '\0';
  return;
}


// Sequence_GetNameValueString  @ 00183f30
void Sequence_GetNameValueString(char *token,int tokenLen)

{
                    /* Unresolved local var: char * write@[???] */
  if (0 < tokenLen) {
    Sequence_GetNameValueString(token,tokenLen);
    return;
  }
  return;
}


// Sequence_GetSymbol  @ 00183f50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char Sequence_GetSymbol(void)

{
  char cVar1;
  char *pcVar2;
  ushort **ppuVar3;
  char *pcVar4;
  
                    /* Unresolved local var: char ch@[???] */
  pcVar2 = g_scan;
  ppuVar3 = __ctype_b_loc();
  while( true ) {
    pcVar4 = pcVar2 + 1;
    cVar1 = *pcVar2;
    if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
    pcVar2 = pcVar4;
    g_scan = pcVar4;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar4;
    }
  }
  if (cVar1 != '\0') {
    g_scan = pcVar4;
  }
  return cVar1;
}


// Sequence_GetToken  @ 00184030
void Sequence_GetToken(char *token,int tokenLen)

{
  char cVar1;
  char *pcVar2;
  ushort **ppuVar3;
  char *pcVar4;
  int iVar5;
  
  pcVar2 = g_scan;
  ppuVar3 = __ctype_b_loc();
  while( true ) {
    pcVar4 = pcVar2 + 1;
    cVar1 = *pcVar2;
    iVar5 = (int)cVar1;
    if (((*ppuVar3)[iVar5] & 0x2000) == 0) break;
    pcVar2 = pcVar4;
    g_scan = pcVar4;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar4;
    }
  }
  if ((((((*ppuVar3)[iVar5] & 8) != 0) || ((byte)(cVar1 - 0x2dU) < 3)) || (cVar1 == '_')) ||
     (cVar1 == '\\')) {
                    /* Unresolved local var: char * write@[???] */
    if (tokenLen < 1) {
      return;
    }
    Sequence_GetNameValueString(token,tokenLen);
    return;
  }
  if (cVar1 != '=') {
    if (cVar1 < '>') {
      if ((cVar1 < '\"') || (('%' < cVar1 && (cVar1 != ',')))) goto LAB_001840b2;
    }
    else if ((cVar1 != '{') && ((cVar1 != '}' && (cVar1 != '@')))) {
LAB_001840b2:
                    /* WARNING: Subroutine does not return */
      Sys_Error("Parsing error on line %d of %s.seq: expected token, found \'%c\' instead\n",
                g_lineNum,g_sequenceParseFileName,iVar5);
    }
  }
  __snprintf_chk(token,tokenLen,1,0xffffffff,&DAT_0027168a,iVar5);
  g_scan = g_scan + 1;
  return;
}


// Sequence_Init  @ 00188710
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sequence_Init(void)

{
  Sequence_ParseFile("global",true);
  return;
}


// Sequence_IsCommandAModifier  @ 00184670
qboolean Sequence_IsCommandAModifier(sequenceCommandEnum_e commandEnum)

{
  int iVar1;
  sequenceCommandMapping_s *psVar2;
  
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
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int numTableEntries@[???] */
                    /* WARNING: Subroutine does not return */
  Sys_Error("Internal error caused by line %d of %s.seq: unknown command enum = %d\n",g_lineNum,
            g_sequenceParseFileName,commandEnum);
}


// Sequence_IsEntrySafe  @ 00186160
qboolean Sequence_IsEntrySafe(sequenceEntry_s *entry)

{
  float fVar1;
  sequenceCommandLine_s *psVar2;
  
                    /* Unresolved local var: float duration@[???]
                       Unresolved local var: sequenceCommandLine_s * cmd@[???] */
  psVar2 = entry->firstCommand;
  if (psVar2 != (sequenceCommandLine_s *)0x0) {
    fVar1 = 0.0;
    do {
      fVar1 = fVar1 + psVar2->delay;
      if ((psVar2->repeatCount < 0) && (fVar1 <= 0.0)) {
        return false;
      }
      psVar2 = psVar2->nextCommandLine;
    } while (psVar2 != (sequenceCommandLine_s *)0x0);
  }
  return true;
}


// Sequence_IsNameValueChar  @ 00183ea0
qboolean Sequence_IsNameValueChar(char ch)

{
  ushort **ppuVar1;
  qboolean qVar2;
  
  ppuVar1 = __ctype_b_loc();
  qVar2 = true;
  if (((*ppuVar1)[ch] & 8) == 0) {
    if (((byte)(ch - 0x2dU) < 3) || (ch == '_')) {
      return true;
    }
    qVar2 = (qboolean)(ch == '\\');
  }
  return qVar2;
}


// Sequence_IsSymbol  @ 00183ef0
qboolean Sequence_IsSymbol(char ch)

{
  if (ch == '=') {
    return true;
  }
  if (ch < '>') {
    if ('!' < ch) {
      if (ch < '&') {
        return true;
      }
      if (ch == ',') {
        return true;
      }
    }
  }
  else {
    if (ch == '{') {
      return true;
    }
    if (ch == '}') {
      return true;
    }
    if (ch == '@') {
      return true;
    }
  }
  return false;
}


// Sequence_OnLevelLoad  @ 00188be0
void Sequence_OnLevelLoad(char *mapName)

{
  Sequence_PurgeEntries(false);
  Sequence_ParseFile(mapName,false);
  return;
}


// Sequence_ParseBuffer  @ 00188290
void Sequence_ParseBuffer(byte *buffer,int bufferSize)

{
  byte bVar1;
  char *pcVar2;
  bool bVar3;
  char cVar4;
  ushort **ppuVar5;
  undefined3 extraout_var;
  int iVar6;
  undefined3 extraout_var_00;
  qboolean qVar7;
  ushort *puVar8;
  char *tokenLen;
  char *extraout_EDX;
  char *extraout_EDX_00;
  sequenceEntry_s *psVar9;
  sequenceCommandLine_s *defaults;
  int iVar10;
  int in_GS_OFFSET;
  char local_120 [256];
  int local_20;
  
                    /* Unresolved local var: char symbol@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  g_lineNum = 1;
  g_scan = (char *)buffer;
  g_lineScan = (char *)buffer;
  Sequence_StripComments((char *)buffer,&bufferSize);
  pcVar2 = g_scan;
  g_fileScopeDefaults.clientMessage.pName = (char *)0x0;
  g_fileScopeDefaults.clientMessage.pMessage = (char *)0x0;
  g_fileScopeDefaults.textChannel = 0;
  g_fileScopeDefaults.repeatCount = 0;
  g_fileScopeDefaults.nextCommandLine = (sequenceCommandLine_s *)0x0;
  g_fileScopeDefaults.speakerName = (char *)0x0;
  g_fileScopeDefaults.clientMessage.effect = 0;
  g_fileScopeDefaults.clientMessage.r1 = 0xff;
  g_fileScopeDefaults.clientMessage.g1 = 0xff;
  g_fileScopeDefaults.clientMessage.b1 = 0xff;
  g_fileScopeDefaults.clientMessage.a1 = 0xff;
  g_fileScopeDefaults.clientMessage.r2 = 0xff;
  g_fileScopeDefaults.clientMessage.g2 = 0xff;
  g_fileScopeDefaults.clientMessage.b2 = 0xff;
  g_fileScopeDefaults.clientMessage.a2 = 0xff;
  g_fileScopeDefaults.clientMessage.x = 0.5;
  g_fileScopeDefaults.clientMessage.y = 0.5;
  g_fileScopeDefaults.clientMessage.fadein = 0.2;
  g_fileScopeDefaults.clientMessage.fadeout = 0.2;
  g_fileScopeDefaults.clientMessage.holdtime = 1.6;
  g_fileScopeDefaults.clientMessage.fxtime = 1.0;
  g_fileScopeDefaults.delay = 0.0;
  g_fileScopeDefaults.soundFileName = (char *)0x0;
  g_fileScopeDefaults.listenerName = (char *)0x0;
  ppuVar5 = __ctype_b_loc();
  while( true ) {
    tokenLen = pcVar2 + 1;
    cVar4 = *pcVar2;
    defaults = (sequenceCommandLine_s *)(int)cVar4;
    if ((*(byte *)((int)*ppuVar5 + (int)defaults * 2 + 1) & 0x20) == 0) break;
    pcVar2 = tokenLen;
    g_scan = tokenLen;
    if (cVar4 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = tokenLen;
    }
  }
  if (cVar4 != '\0') {
                    /* Unresolved local var: char[256] token@[???]
                       Unresolved local var: char * write@[???] */
    g_scan = tokenLen;
    do {
      while (cVar4 = (char)defaults, cVar4 != '$') {
        if (cVar4 == '%') {
          cVar4 = Sequence_ParseEntry();
          defaults = (sequenceCommandLine_s *)CONCAT31(extraout_var_00,cVar4);
          tokenLen = extraout_EDX_00;
        }
        else {
          if (cVar4 != '!') {
                    /* WARNING: Subroutine does not return */
            Sys_Error("Parsing error on line %d of %s.seq: At file scope, lines must begin with \'$\' (modifier) or \'%\' (entry block) or \'!\' (sentence / global data block); found \'%c\'\n"
                      ,g_lineNum,g_sequenceParseFileName,(int)cVar4);
          }
          Sequence_GetNameValueString(local_120,(int)tokenLen);
          iVar6 = strcasecmp(local_120,"Sentences");
          if (iVar6 != 0) {
                    /* WARNING: Subroutine does not return */
            Sys_Error("Syntax error in file %s.seq on line %d: found global data block symbol \'!\' with unknown data type \"%s\""
                      ,g_sequenceParseFileName,g_lineNum,local_120);
          }
                    /* Unresolved local var: char symbol@[???]
                       Unresolved local var: qboolean finished@[???]
                       Unresolved local var: char ch@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
          cVar4 = *g_scan;
          iVar6 = (int)cVar4;
          bVar1 = *(byte *)((int)*ppuVar5 + iVar6 * 2 + 1);
          while ((bVar1 & 0x20) != 0) {
            g_scan = g_scan + 1;
            if ((char)iVar6 == '\n') {
              g_lineNum = g_lineNum + 1;
              g_lineScan = g_scan;
            }
            cVar4 = *g_scan;
            iVar6 = (int)cVar4;
            bVar1 = *(byte *)((int)*ppuVar5 + iVar6 * 2 + 1);
          }
          iVar10 = 0;
          if ((cVar4 == '\0') || (g_scan = g_scan + 1, iVar10 = iVar6, cVar4 != '{')) {
                    /* WARNING: Subroutine does not return */
            Sys_Error("Parsing error on line %d of %s.seq: expected \'{\' to start a\n new sentence block; found \'%c\' instead!"
                      ,g_lineNum,g_sequenceParseFileName,iVar10);
          }
          do {
            qVar7 = Sequence_ParseSentenceLine();
          } while (qVar7 == false);
                    /* Unresolved local var: char ch@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
          puVar8 = *ppuVar5;
          tokenLen = (char *)(int)*g_scan;
          if ((*(byte *)((int)puVar8 + (int)tokenLen * 2 + 1) & 0x20) != 0) {
            puVar8 = (ushort *)(g_scan + 1);
            do {
              g_scan = (char *)puVar8;
              if ((char)tokenLen == '\n') {
                g_lineNum = g_lineNum + 1;
                g_lineScan = g_scan;
              }
              puVar8 = (ushort *)((int)g_scan + 1);
              tokenLen = (char *)(int)(char)*(ushort *)g_scan;
            } while ((*(byte *)((int)*ppuVar5 + (int)tokenLen * 2 + 1) & 0x20) != 0);
          }
          cVar4 = (char)tokenLen;
          defaults = (sequenceCommandLine_s *)CONCAT31((int3)((uint)puVar8 >> 8),cVar4);
          if (cVar4 == '\0') goto LAB_00188460;
          g_scan = g_scan + 1;
        }
        if (cVar4 == '\0') goto LAB_00188460;
      }
      do {
                    /* Unresolved local var: sequenceCommandLine_s * newCommandLine@[???]
                       Unresolved local var: char delimiter@[???] */
        cVar4 = Sequence_ParseModifier(defaults);
        defaults = (sequenceCommandLine_s *)CONCAT31(extraout_var,cVar4);
      } while (cVar4 == ',');
      tokenLen = extraout_EDX;
    } while (cVar4 != '\0');
  }
LAB_00188460:
  do {
    if (g_sequenceList == (sequenceEntry_s *)0x0) goto LAB_001884af;
    bVar3 = false;
    psVar9 = g_sequenceList;
    do {
      qVar7 = Sequence_ExpandGosubsForEntry(psVar9);
      psVar9 = psVar9->nextEntry;
      if (qVar7 == false) {
        bVar3 = true;
      }
    } while (psVar9 != (sequenceEntry_s *)0x0);
    psVar9 = g_sequenceList;
  } while (bVar3);
                    /* Unresolved local var: sequenceEntry_s * entry@[???] */
  for (; psVar9 != (sequenceEntry_s *)0x0; psVar9 = psVar9->nextEntry) {
    Sequence_FlattenEntry(psVar9);
  }
LAB_001884af:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Sequence_ParseCommand  @ 00185710
char __regparm2 Sequence_ParseCommand(sequenceCommandLine_s *newCommandLine)

{
  char cVar1;
  byte bVar2;
  sequenceCommandEnum_e commandEnum;
  int iVar3;
  ushort **ppuVar4;
  sequenceCommandLine_s *psVar5;
  int in_EDX;
  sequenceCommandMapping_s *psVar6;
  char *pcVar7;
  int iVar8;
  char **ppcVar9;
  int in_GS_OFFSET;
  sequenceCommandLine_s *in_stack_00000004;
  sequenceCommandLine_s *local_130;
  char local_120 [256];
  int local_20;
  
                    /* Unresolved local var: char[256] commandName@[???]
                       Unresolved local var: char delimiter@[???]
                       Unresolved local var: sequenceCommandEnum_e commandEnum@[???]
                       Unresolved local var: sequenceCommandLine_s * modifierCommandLine@[???] */
  ppcVar9 = &g_sequenceCommandMappingTable[0].commandName;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int numTableEntries@[???] */
  iVar8 = 0;
                    /* Unresolved local var: char * write@[???] */
  local_130 = in_stack_00000004;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Sequence_GetNameValueString(local_120,in_EDX);
  do {
    iVar3 = Q_stricmp(local_120,*ppcVar9);
    if (iVar3 == 0) {
      commandEnum = g_sequenceCommandMappingTable[iVar8].commandEnum;
      if (commandEnum != SEQUENCE_COMMAND_ERROR) {
        psVar6 = g_sequenceCommandMappingTable;
        iVar8 = 0;
        while (commandEnum != psVar6->commandEnum) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int numTableEntries@[???] */
          iVar8 = iVar8 + 1;
          psVar6 = psVar6 + 1;
          if (iVar8 == 0x17) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int numTableEntries@[???] */
                    /* WARNING: Subroutine does not return */
            Sys_Error("Internal error caused by line %d of %s.seq: unknown command enum = %d\n",
                      g_lineNum,g_sequenceParseFileName,commandEnum);
          }
        }
        if (g_sequenceCommandMappingTable[iVar8].commandType == SEQUENCE_TYPE_MODIFIER) {
          local_130 = Mem_ZeroMalloc(0x5c);
          local_130->commandType = 10;
          do {
            psVar5 = in_stack_00000004;
            in_stack_00000004 = psVar5->nextCommandLine;
          } while (in_stack_00000004 != (sequenceCommandLine_s *)0x0);
          psVar5->nextCommandLine = local_130;
        }
        ppuVar4 = __ctype_b_loc();
        while( true ) {
          pcVar7 = g_scan + 1;
          cVar1 = *g_scan;
          iVar8 = (int)cVar1;
          if ((*(byte *)((int)*ppuVar4 + iVar8 * 2 + 1) & 0x20) == 0) break;
          g_scan = pcVar7;
          if (cVar1 == '\n') {
            g_lineNum = g_lineNum + 1;
            g_lineScan = pcVar7;
          }
        }
        if (cVar1 == '\0') {
          iVar8 = 0;
        }
        else {
          g_scan = pcVar7;
          if (cVar1 == '=') {
            Sequence_ReadCommandData(commandEnum,local_130);
                    /* Unresolved local var: char ch@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
            cVar1 = *g_scan;
            iVar8 = (int)cVar1;
            bVar2 = *(byte *)((int)*ppuVar4 + iVar8 * 2 + 1);
            while ((bVar2 & 0x20) != 0) {
              g_scan = g_scan + 1;
              if ((char)iVar8 == '\n') {
                g_lineNum = g_lineNum + 1;
                g_lineScan = g_scan;
              }
              cVar1 = *g_scan;
              iVar8 = (int)cVar1;
              bVar2 = *(byte *)((int)*ppuVar4 + iVar8 * 2 + 1);
            }
            if (cVar1 != '\0') {
              g_scan = g_scan + 1;
            }
            if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
              return cVar1;
            }
                    /* WARNING: Subroutine does not return */
            __stack_chk_fail();
          }
        }
                    /* WARNING: Subroutine does not return */
        Sys_Error("Parsing error on or before line %d of %s.seq: after command \"%s\", expected \'=\', found \'%c\'\n"
                  ,g_lineNum,g_sequenceParseFileName,local_120,iVar8);
      }
      break;
    }
    iVar8 = iVar8 + 1;
    ppcVar9 = ppcVar9 + 3;
  } while (iVar8 != 0x17);
                    /* WARNING: Subroutine does not return */
  Sys_Error("Parsing error on line %d of %s.seq: unknown command \"%s\"\n",g_lineNum,
            g_sequenceParseFileName,local_120);
}


// Sequence_ParseCommandLine  @ 00185970
char Sequence_ParseCommandLine(sequenceEntry_s *entry)

{
  sequenceCommandLine_s *psVar1;
  int iVar2;
  float fVar3;
  char cVar4;
  sequenceCommandLine_s *psVar5;
  char *pcVar6;
  sequenceCommandLine_s *psVar7;
  undefined3 extraout_var;
  
                    /* Unresolved local var: char delimiter@[???]
                       Unresolved local var: sequenceCommandLine_s * newCommandLine@[???] */
  psVar5 = Mem_ZeroMalloc(0x5c);
  iVar2 = g_blockScopeDefaults.clientMessage.effect;
  (psVar5->clientMessage).pName = (char *)0x0;
  (psVar5->clientMessage).pMessage = (char *)0x0;
  (psVar5->clientMessage).effect = iVar2;
  (psVar5->clientMessage).r1 = g_blockScopeDefaults.clientMessage.r1;
  (psVar5->clientMessage).g1 = g_blockScopeDefaults.clientMessage.g1;
  (psVar5->clientMessage).b1 = g_blockScopeDefaults.clientMessage.b1;
  (psVar5->clientMessage).a1 = g_blockScopeDefaults.clientMessage.a1;
  (psVar5->clientMessage).r2 = g_blockScopeDefaults.clientMessage.r2;
  (psVar5->clientMessage).g2 = g_blockScopeDefaults.clientMessage.g2;
  (psVar5->clientMessage).b2 = g_blockScopeDefaults.clientMessage.b2;
  (psVar5->clientMessage).a2 = g_blockScopeDefaults.clientMessage.a2;
  (psVar5->clientMessage).x = g_blockScopeDefaults.clientMessage.x;
  (psVar5->clientMessage).y = g_blockScopeDefaults.clientMessage.y;
  (psVar5->clientMessage).fadein = g_blockScopeDefaults.clientMessage.fadein;
  (psVar5->clientMessage).fadeout = g_blockScopeDefaults.clientMessage.fadeout;
  (psVar5->clientMessage).holdtime = g_blockScopeDefaults.clientMessage.holdtime;
  (psVar5->clientMessage).fxtime = g_blockScopeDefaults.clientMessage.fxtime;
  iVar2 = g_blockScopeDefaults.textChannel;
  fVar3 = g_blockScopeDefaults.delay;
  psVar5->nextCommandLine = (sequenceCommandLine_s *)0x0;
  psVar5->delay = fVar3;
  psVar5->textChannel = iVar2;
  iVar2 = g_blockScopeDefaults.repeatCount;
  psVar5->soundFileName = (char *)0x0;
  psVar5->repeatCount = iVar2;
  if (psVar5->speakerName != (char *)0x0) {
    Mem_Free(psVar5->speakerName);
  }
  pcVar6 = Mem_Strdup(g_blockScopeDefaults.speakerName);
  psVar5->speakerName = pcVar6;
  if (psVar5->listenerName != (char *)0x0) {
    Mem_Free(psVar5->listenerName);
  }
  psVar7 = (sequenceCommandLine_s *)Mem_Strdup(g_blockScopeDefaults.listenerName);
  psVar5->listenerName = (char *)psVar7;
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???] */
  psVar1 = entry->firstCommand;
  if (entry->firstCommand == (sequenceCommandLine_s *)0x0) {
    entry->firstCommand = psVar5;
    psVar5->nextCommandLine = (sequenceCommandLine_s *)0x0;
  }
  else {
    do {
      psVar7 = psVar1;
      psVar1 = psVar7->nextCommandLine;
    } while (psVar1 != (sequenceCommandLine_s *)0x0);
    psVar7->nextCommandLine = psVar5;
    psVar5->nextCommandLine = (sequenceCommandLine_s *)0x0;
    psVar7 = (sequenceCommandLine_s *)0x0;
  }
  do {
    cVar4 = Sequence_ParseCommand(psVar7);
    psVar7 = (sequenceCommandLine_s *)CONCAT31(extraout_var,cVar4);
  } while (cVar4 == ',');
  return cVar4;
}


// Sequence_ParseEntry  @ 00186330
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char Sequence_ParseEntry(void)

{
  float fVar1;
  byte bVar2;
  char cVar3;
  ushort **ppuVar4;
  char *pcVar5;
  sequenceEntry_s *psVar6;
  char *pcVar7;
  sequenceCommandLine_s *psVar8;
  sequenceCommandLine_s *psVar9;
  sequenceCommandLine_s *psVar10;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar11;
  int in_EDX;
  sequenceCommandLine_s *psVar12;
  int in_GS_OFFSET;
  char local_520 [256];
  sequenceCommandLine_s local_420 [11];
  int local_20;
  
                    /* Unresolved local var: char symbol@[???]
                       Unresolved local var: char delimiter@[???]
                       Unresolved local var: char[256] token@[???]
                       Unresolved local var: sequenceEntry_s * newEntry@[???] */
                    /* Unresolved local var: char * write@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Sequence_GetNameValueString(local_520,in_EDX);
  pcVar7 = g_scan;
  ppuVar4 = __ctype_b_loc();
  while( true ) {
    pcVar5 = pcVar7 + 1;
    cVar3 = *pcVar7;
    iVar11 = (int)cVar3;
    if ((*(byte *)((int)*ppuVar4 + iVar11 * 2 + 1) & 0x20) == 0) break;
    pcVar7 = pcVar5;
    g_scan = pcVar5;
    if (cVar3 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar5;
    }
  }
  if (cVar3 == '\0') {
    iVar11 = 0;
  }
  else {
    g_scan = pcVar5;
    if (cVar3 == '{') {
      psVar6 = Mem_Malloc(0x14);
      g_blockScopeDefaults.clientMessage.x = g_fileScopeDefaults.clientMessage.x;
      g_blockScopeDefaults.clientMessage.fadein = g_fileScopeDefaults.clientMessage.fadein;
      g_blockScopeDefaults.clientMessage.effect = g_fileScopeDefaults.clientMessage.effect;
      g_blockScopeDefaults.clientMessage.r1 = g_fileScopeDefaults.clientMessage.r1;
      g_blockScopeDefaults.clientMessage.y = g_fileScopeDefaults.clientMessage.y;
      g_blockScopeDefaults.clientMessage.fadeout = g_fileScopeDefaults.clientMessage.fadeout;
      g_blockScopeDefaults.clientMessage.holdtime = g_fileScopeDefaults.clientMessage.holdtime;
      g_blockScopeDefaults.clientMessage.g1 = g_fileScopeDefaults.clientMessage.g1;
      g_blockScopeDefaults.clientMessage.fxtime = g_fileScopeDefaults.clientMessage.fxtime;
      g_blockScopeDefaults.clientMessage.b1 = g_fileScopeDefaults.clientMessage.b1;
      g_blockScopeDefaults.clientMessage.a1 = g_fileScopeDefaults.clientMessage.a1;
      g_blockScopeDefaults.clientMessage.r2 = g_fileScopeDefaults.clientMessage.r2;
      g_blockScopeDefaults.clientMessage.g2 = g_fileScopeDefaults.clientMessage.g2;
      g_blockScopeDefaults.clientMessage.b2 = g_fileScopeDefaults.clientMessage.b2;
      g_blockScopeDefaults.clientMessage.a2 = g_fileScopeDefaults.clientMessage.a2;
      g_blockScopeDefaults.clientMessage.pName = (char *)0x0;
      g_blockScopeDefaults.clientMessage.pMessage = (char *)0x0;
      g_blockScopeDefaults.textChannel = g_fileScopeDefaults.textChannel;
      g_blockScopeDefaults.delay = g_fileScopeDefaults.delay;
      g_blockScopeDefaults.repeatCount = g_fileScopeDefaults.repeatCount;
      g_blockScopeDefaults.nextCommandLine = (sequenceCommandLine_s *)0x0;
      g_blockScopeDefaults.soundFileName = (char *)0x0;
      if (g_blockScopeDefaults.speakerName != (char *)0x0) {
        Mem_Free(g_blockScopeDefaults.speakerName);
      }
      g_blockScopeDefaults.speakerName = Mem_Strdup(g_fileScopeDefaults.speakerName);
      if (g_blockScopeDefaults.listenerName != (char *)0x0) {
        Mem_Free(g_blockScopeDefaults.listenerName);
      }
      g_blockScopeDefaults.listenerName = Mem_Strdup(g_fileScopeDefaults.listenerName);
      pcVar7 = Mem_Strdup(local_520);
      psVar6->entryName = pcVar7;
      pcVar7 = Mem_Strdup(g_sequenceParseFileName);
      psVar6->firstCommand = (sequenceCommandLine_s *)0x0;
      psVar6->fileName = pcVar7;
      psVar6->isGlobal = g_sequenceParseFileIsGlobal;
                    /* Unresolved local var: sequenceCommandLine_s * defaultsCommand@[???] */
      psVar8 = Mem_ZeroMalloc(0x5c);
      iVar11 = g_fileScopeDefaults.clientMessage.effect;
      (psVar8->clientMessage).pName = (char *)0x0;
      (psVar8->clientMessage).pMessage = (char *)0x0;
      (psVar8->clientMessage).effect = iVar11;
      (psVar8->clientMessage).r1 = g_fileScopeDefaults.clientMessage.r1;
      (psVar8->clientMessage).g1 = g_fileScopeDefaults.clientMessage.g1;
      (psVar8->clientMessage).b1 = g_fileScopeDefaults.clientMessage.b1;
      (psVar8->clientMessage).a1 = g_fileScopeDefaults.clientMessage.a1;
      (psVar8->clientMessage).r2 = g_fileScopeDefaults.clientMessage.r2;
      (psVar8->clientMessage).g2 = g_fileScopeDefaults.clientMessage.g2;
      (psVar8->clientMessage).b2 = g_fileScopeDefaults.clientMessage.b2;
      (psVar8->clientMessage).a2 = g_fileScopeDefaults.clientMessage.a2;
      (psVar8->clientMessage).x = g_fileScopeDefaults.clientMessage.x;
      (psVar8->clientMessage).y = g_fileScopeDefaults.clientMessage.y;
      (psVar8->clientMessage).fadein = g_fileScopeDefaults.clientMessage.fadein;
      (psVar8->clientMessage).fadeout = g_fileScopeDefaults.clientMessage.fadeout;
      (psVar8->clientMessage).holdtime = g_fileScopeDefaults.clientMessage.holdtime;
      (psVar8->clientMessage).fxtime = g_fileScopeDefaults.clientMessage.fxtime;
      iVar11 = g_fileScopeDefaults.textChannel;
      fVar1 = g_fileScopeDefaults.delay;
      psVar8->nextCommandLine = (sequenceCommandLine_s *)0x0;
      psVar8->delay = fVar1;
      psVar8->textChannel = iVar11;
      iVar11 = g_fileScopeDefaults.repeatCount;
      psVar8->soundFileName = (char *)0x0;
      psVar8->repeatCount = iVar11;
      if (psVar8->speakerName != (char *)0x0) {
        Mem_Free(psVar8->speakerName);
      }
      pcVar7 = Mem_Strdup(g_fileScopeDefaults.speakerName);
      psVar8->speakerName = pcVar7;
      if (psVar8->listenerName != (char *)0x0) {
        Mem_Free(psVar8->listenerName);
      }
      psVar9 = (sequenceCommandLine_s *)g_fileScopeDefaults.listenerName;
      pcVar7 = Mem_Strdup(g_fileScopeDefaults.listenerName);
      psVar8->commandType = 8;
      psVar8->modifierBitField = 0xff;
      psVar8->listenerName = pcVar7;
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???] */
      psVar10 = psVar6->firstCommand;
      if (psVar6->firstCommand == (sequenceCommandLine_s *)0x0) {
        psVar6->firstCommand = psVar8;
        psVar8->nextCommandLine = (sequenceCommandLine_s *)0x0;
      }
      else {
        do {
          psVar12 = psVar10;
          psVar10 = psVar12->nextCommandLine;
        } while (psVar10 != (sequenceCommandLine_s *)0x0);
        psVar12->nextCommandLine = psVar8;
        psVar8->nextCommandLine = (sequenceCommandLine_s *)0x0;
      }
                    /* Unresolved local var: char ch@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
      psVar8 = (sequenceCommandLine_s *)(int)*g_scan;
      bVar2 = *(byte *)((int)*ppuVar4 + (int)psVar8 * 2 + 1);
      while ((bVar2 & 0x20) != 0) {
        g_scan = g_scan + 1;
        if ((char)psVar8 == '\n') {
          g_lineNum = g_lineNum + 1;
          g_lineScan = g_scan;
        }
        psVar8 = (sequenceCommandLine_s *)(int)*g_scan;
        bVar2 = *(byte *)((int)*ppuVar4 + (int)psVar8 * 2 + 1);
      }
      if ((char)psVar8 == '\0') goto LAB_001866f4;
      g_scan = g_scan + 1;
      while( true ) {
        while( true ) {
          while( true ) {
            pcVar7 = g_scan;
            if ((char)psVar8 == '}') {
              fVar1 = 0.0;
                    /* Unresolved local var: float duration@[???]
                       Unresolved local var: sequenceCommandLine_s * cmd@[???] */
              for (psVar8 = psVar6->firstCommand; psVar8 != (sequenceCommandLine_s *)0x0;
                  psVar8 = psVar8->nextCommandLine) {
                fVar1 = fVar1 + psVar8->delay;
                if ((psVar8->repeatCount < 0) && (fVar1 <= 0.0)) {
                    /* WARNING: Subroutine does not return */
                  Sys_Error("Logic error in file %s.seq before line %d: execution of entry \"%%%s\" would cause an infinite loop!"
                            ,g_sequenceParseFileName,g_lineNum,psVar6->entryName);
                }
              }
                    /* Unresolved local var: char ch@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
              psVar6->nextEntry = g_sequenceList;
              g_sequenceList = psVar6;
              cVar3 = *pcVar7;
              iVar11 = (int)cVar3;
              bVar2 = *(byte *)((int)*ppuVar4 + iVar11 * 2 + 1);
              while ((bVar2 & 0x20) != 0) {
                g_scan = pcVar7 + 1;
                if ((char)iVar11 == '\n') {
                  g_lineNum = g_lineNum + 1;
                  g_lineScan = g_scan;
                }
                cVar3 = *g_scan;
                iVar11 = (int)cVar3;
                pcVar7 = g_scan;
                bVar2 = *(byte *)((int)*ppuVar4 + iVar11 * 2 + 1);
              }
              if (cVar3 != '\0') {
                g_scan = pcVar7 + 1;
              }
              if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
                __stack_chk_fail(psVar9);
              }
              return cVar3;
            }
LAB_001866f4:
            cVar3 = (char)psVar8;
                    /* Unresolved local var: char endToken@[DW_OP_reg0(EAX)] */
            if (cVar3 != '$') break;
            do {
              psVar9 = Mem_ZeroMalloc(0x5c);
              psVar9->commandType = 9;
              psVar8 = psVar6->firstCommand;
              if (psVar6->firstCommand == (sequenceCommandLine_s *)0x0) {
                psVar6->firstCommand = psVar9;
                psVar9->nextCommandLine = (sequenceCommandLine_s *)0x0;
              }
              else {
                do {
                  psVar10 = psVar8;
                  psVar8 = psVar10->nextCommandLine;
                } while (psVar8 != (sequenceCommandLine_s *)0x0);
                    /* Unresolved local var: char endToken@[???]
                       Unresolved local var: sequenceCommandLine_s * newCommandLine@[???]
                       Unresolved local var: char delimiter@[???]
                       Unresolved local var: sequenceCommandLine_s * scan@[???] */
                psVar10->nextCommandLine = psVar9;
                psVar9->nextCommandLine = (sequenceCommandLine_s *)0x0;
              }
              bVar2 = Sequence_ParseModifier(psVar9);
              psVar8 = (sequenceCommandLine_s *)(uint)bVar2;
            } while (bVar2 == 0x2c);
          }
          if (cVar3 != '#') break;
                    /* Unresolved local var: char delimiter@[???]
                       Unresolved local var: sequenceCommandLine_s * newCommandLine@[???] */
          psVar10 = Mem_ZeroMalloc(0x5c);
          iVar11 = g_blockScopeDefaults.clientMessage.effect;
          (psVar10->clientMessage).pName = (char *)0x0;
          (psVar10->clientMessage).pMessage = (char *)0x0;
          (psVar10->clientMessage).effect = iVar11;
          (psVar10->clientMessage).r1 = g_blockScopeDefaults.clientMessage.r1;
          (psVar10->clientMessage).g1 = g_blockScopeDefaults.clientMessage.g1;
          (psVar10->clientMessage).b1 = g_blockScopeDefaults.clientMessage.b1;
          (psVar10->clientMessage).a1 = g_blockScopeDefaults.clientMessage.a1;
          (psVar10->clientMessage).r2 = g_blockScopeDefaults.clientMessage.r2;
          (psVar10->clientMessage).g2 = g_blockScopeDefaults.clientMessage.g2;
          (psVar10->clientMessage).b2 = g_blockScopeDefaults.clientMessage.b2;
          (psVar10->clientMessage).a2 = g_blockScopeDefaults.clientMessage.a2;
          (psVar10->clientMessage).x = g_blockScopeDefaults.clientMessage.x;
          (psVar10->clientMessage).y = g_blockScopeDefaults.clientMessage.y;
          (psVar10->clientMessage).fadein = g_blockScopeDefaults.clientMessage.fadein;
          (psVar10->clientMessage).fadeout = g_blockScopeDefaults.clientMessage.fadeout;
          (psVar10->clientMessage).holdtime = g_blockScopeDefaults.clientMessage.holdtime;
          (psVar10->clientMessage).fxtime = g_blockScopeDefaults.clientMessage.fxtime;
          iVar11 = g_blockScopeDefaults.textChannel;
          fVar1 = g_blockScopeDefaults.delay;
          psVar10->nextCommandLine = (sequenceCommandLine_s *)0x0;
          psVar10->delay = fVar1;
          psVar10->textChannel = iVar11;
          iVar11 = g_blockScopeDefaults.repeatCount;
          psVar10->soundFileName = (char *)0x0;
          psVar10->repeatCount = iVar11;
          if (psVar10->speakerName != (char *)0x0) {
            Mem_Free(psVar10->speakerName);
          }
          pcVar7 = Mem_Strdup(g_blockScopeDefaults.speakerName);
          psVar10->speakerName = pcVar7;
          if (psVar10->listenerName != (char *)0x0) {
            Mem_Free(psVar10->listenerName);
          }
          psVar8 = (sequenceCommandLine_s *)Mem_Strdup(g_blockScopeDefaults.listenerName);
          psVar10->listenerName = (char *)psVar8;
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???] */
          psVar9 = psVar6->firstCommand;
          if (psVar6->firstCommand == (sequenceCommandLine_s *)0x0) {
            psVar6->firstCommand = psVar10;
            psVar10->nextCommandLine = (sequenceCommandLine_s *)0x0;
          }
          else {
            do {
              psVar8 = psVar9;
              psVar9 = psVar8->nextCommandLine;
            } while (psVar9 != (sequenceCommandLine_s *)0x0);
            psVar8->nextCommandLine = psVar10;
            psVar10->nextCommandLine = (sequenceCommandLine_s *)0x0;
            psVar8 = (sequenceCommandLine_s *)0x0;
          }
          do {
            psVar9 = psVar10;
            cVar3 = Sequence_ParseCommand(psVar8);
            psVar8 = (sequenceCommandLine_s *)CONCAT31(extraout_var_00,cVar3);
          } while (cVar3 == ',');
        }
        if (cVar3 != '@') break;
                    /* Unresolved local var: char delimiter@[???]
                       Unresolved local var: sequenceCommandLine_s * newCommandLine@[???] */
        psVar10 = Mem_Malloc(0x5c);
        Q_memset(psVar10,0,0x5c);
        iVar11 = g_blockScopeDefaults.clientMessage.effect;
        (psVar10->clientMessage).pName = (char *)0x0;
        (psVar10->clientMessage).pMessage = (char *)0x0;
        (psVar10->clientMessage).effect = iVar11;
        (psVar10->clientMessage).r1 = g_blockScopeDefaults.clientMessage.r1;
        (psVar10->clientMessage).g1 = g_blockScopeDefaults.clientMessage.g1;
        (psVar10->clientMessage).b1 = g_blockScopeDefaults.clientMessage.b1;
        (psVar10->clientMessage).a1 = g_blockScopeDefaults.clientMessage.a1;
        (psVar10->clientMessage).r2 = g_blockScopeDefaults.clientMessage.r2;
        (psVar10->clientMessage).g2 = g_blockScopeDefaults.clientMessage.g2;
        (psVar10->clientMessage).b2 = g_blockScopeDefaults.clientMessage.b2;
        (psVar10->clientMessage).a2 = g_blockScopeDefaults.clientMessage.a2;
        (psVar10->clientMessage).x = g_blockScopeDefaults.clientMessage.x;
        (psVar10->clientMessage).y = g_blockScopeDefaults.clientMessage.y;
        (psVar10->clientMessage).fadein = g_blockScopeDefaults.clientMessage.fadein;
        (psVar10->clientMessage).fadeout = g_blockScopeDefaults.clientMessage.fadeout;
        (psVar10->clientMessage).holdtime = g_blockScopeDefaults.clientMessage.holdtime;
        (psVar10->clientMessage).fxtime = g_blockScopeDefaults.clientMessage.fxtime;
        iVar11 = g_blockScopeDefaults.textChannel;
        fVar1 = g_blockScopeDefaults.delay;
        psVar10->nextCommandLine = (sequenceCommandLine_s *)0x0;
        psVar10->delay = fVar1;
        psVar10->textChannel = iVar11;
        iVar11 = g_blockScopeDefaults.repeatCount;
        psVar10->soundFileName = (char *)0x0;
        psVar10->repeatCount = iVar11;
        if (psVar10->speakerName != (char *)0x0) {
          Mem_Free(psVar10->speakerName);
        }
        pcVar7 = Mem_Strdup(g_blockScopeDefaults.speakerName);
        psVar10->speakerName = pcVar7;
        if (psVar10->listenerName != (char *)0x0) {
          Mem_Free(psVar10->listenerName);
        }
        pcVar7 = Mem_Strdup(g_blockScopeDefaults.listenerName);
        psVar10->listenerName = pcVar7;
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???] */
        psVar8 = psVar6->firstCommand;
        if (psVar6->firstCommand == (sequenceCommandLine_s *)0x0) {
          psVar6->firstCommand = psVar10;
          psVar10->nextCommandLine = (sequenceCommandLine_s *)0x0;
        }
        else {
          do {
            psVar9 = psVar8;
            psVar8 = psVar9->nextCommandLine;
          } while (psVar8 != (sequenceCommandLine_s *)0x0);
          psVar9->nextCommandLine = psVar10;
          psVar10->nextCommandLine = (sequenceCommandLine_s *)0x0;
        }
                    /* Unresolved local var: char[1024] tempString@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
        iVar11 = (int)*g_scan;
        bVar2 = *(byte *)((int)*ppuVar4 + iVar11 * 2 + 1);
        while ((bVar2 & 0x20) != 0) {
          g_scan = g_scan + 1;
          if ((char)iVar11 == '\n') {
            g_lineNum = g_lineNum + 1;
            g_lineScan = g_scan;
          }
          iVar11 = (int)*g_scan;
          bVar2 = *(byte *)((int)*ppuVar4 + iVar11 * 2 + 1);
        }
                    /* Unresolved local var: char * write@[???] */
        Sequence_GetNameValueString((char *)local_420,0x400);
        psVar9 = local_420;
        pcVar5 = Mem_Strdup((char *)psVar9);
        pcVar7 = g_scan;
        (psVar10->clientMessage).pName = pcVar5;
        psVar8 = (sequenceCommandLine_s *)(int)*pcVar7;
        bVar2 = *(byte *)((int)*ppuVar4 + (int)psVar8 * 2 + 1);
                    /* Unresolved local var: char ch@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
        while (cVar3 = (char)psVar8, (bVar2 & 0x20) != 0) {
          pcVar7 = pcVar7 + 1;
          if (cVar3 == '\n') {
            g_lineNum = g_lineNum + 1;
            g_lineScan = pcVar7;
          }
          psVar8 = (sequenceCommandLine_s *)(int)*pcVar7;
          g_scan = pcVar7;
          bVar2 = *(byte *)((int)*ppuVar4 + (int)psVar8 * 2 + 1);
        }
        if (cVar3 == '\0') break;
        g_scan = pcVar7 + 1;
        while (cVar3 == ',') {
          psVar9 = psVar10;
          cVar3 = Sequence_ParseCommand(psVar8);
          psVar8 = (sequenceCommandLine_s *)CONCAT31(extraout_var,cVar3);
        }
      }
                    /* WARNING: Subroutine does not return */
      Sys_Error("Parsing error on line %d of %s.seq: line must begin with either \'#\' (command) or \'$\' (modifier); found \'%c\'\n"
                ,g_lineNum,g_sequenceParseFileName,(int)(char)psVar8);
    }
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Parsing error on line %d of %s.seq: expected \'{\' to start a\n new entry block; found \'%c\' instead!"
            ,g_lineNum,g_sequenceParseFileName,iVar11);
}


// Sequence_ParseFile  @ 00188630
void Sequence_ParseFile(char *fileName,qboolean isGlobal)

{
  byte *buffer;
  int in_GS_OFFSET;
  int local_114;
  char local_110 [256];
  int local_10;
  
                    /* Unresolved local var: byte * buffer@[???]
                       Unresolved local var: int bufSize@[???]
                       Unresolved local var: char[256] filePathName@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Q_strncpy(g_sequenceParseFileName,fileName,0xff);
  g_sequenceParseFileIsGlobal = isGlobal;
  g_sequenceParseFileName[0xff] = '\0';
  __snprintf_chk(local_110,0x100,1,0x100,"sequences/%s.seq",fileName);
  buffer = COM_LoadTempFile(local_110,&local_114);
  if (buffer == (byte *)0x0) {
    Con_DPrintf("WARNING: failed to locate sequence file %s\n",fileName);
  }
  else {
    Sequence_ParseBuffer(buffer,local_114);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Sequence_ParseGlobalDataBlock  @ 00187340
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char Sequence_ParseGlobalDataBlock(void)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  int iVar4;
  ushort **ppuVar5;
  char *pcVar6;
  qboolean qVar7;
  int in_EDX;
  int in_GS_OFFSET;
  char local_110 [256];
  int local_10;
  
                    /* Unresolved local var: char[256] token@[???] */
                    /* Unresolved local var: char * write@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Sequence_GetNameValueString(local_110,in_EDX);
  iVar4 = strcasecmp(local_110,"Sentences");
  pcVar3 = g_scan;
  if (iVar4 != 0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Syntax error in file %s.seq on line %d: found global data block symbol \'!\' with unknown data type \"%s\""
              ,g_sequenceParseFileName,g_lineNum,local_110);
  }
  ppuVar5 = __ctype_b_loc();
  while( true ) {
    pcVar6 = pcVar3 + 1;
    cVar1 = *pcVar3;
    if ((*(byte *)((int)*ppuVar5 + cVar1 * 2 + 1) & 0x20) == 0) break;
    pcVar3 = pcVar6;
    g_scan = pcVar6;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar6;
    }
  }
  iVar4 = 0;
  if ((cVar1 != '\0') && (iVar4 = (int)cVar1, g_scan = pcVar6, cVar1 == '{')) {
    do {
      qVar7 = Sequence_ParseSentenceLine();
    } while (qVar7 == false);
                    /* Unresolved local var: char ch@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
    cVar1 = *g_scan;
    iVar4 = (int)cVar1;
    bVar2 = *(byte *)((int)*ppuVar5 + iVar4 * 2 + 1);
    while ((bVar2 & 0x20) != 0) {
      g_scan = g_scan + 1;
      if ((char)iVar4 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = g_scan;
      }
      cVar1 = *g_scan;
      iVar4 = (int)cVar1;
      bVar2 = *(byte *)((int)*ppuVar5 + iVar4 * 2 + 1);
    }
    if (cVar1 != '\0') {
      g_scan = g_scan + 1;
    }
    if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
      return cVar1;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Parsing error on line %d of %s.seq: expected \'{\' to start a\n new sentence block; found \'%c\' instead!"
            ,g_lineNum,g_sequenceParseFileName,iVar4);
}


// Sequence_ParseLine  @ 00185d00
char Sequence_ParseLine(char startToken,sequenceEntry_s *entry)

{
  int iVar1;
  float fVar2;
  byte bVar3;
  char cVar4;
  sequenceCommandLine_s *psVar5;
  char *pcVar6;
  ushort **ppuVar7;
  undefined3 extraout_var;
  sequenceCommandLine_s *psVar8;
  undefined3 extraout_var_00;
  sequenceCommandLine_s *psVar9;
  char *pcVar10;
  
                    /* Unresolved local var: char endToken@[???] */
  if (startToken == '$') {
    do {
      psVar8 = Mem_ZeroMalloc(0x5c);
      psVar8->commandType = 9;
      psVar5 = entry->firstCommand;
      if (entry->firstCommand == (sequenceCommandLine_s *)0x0) {
        entry->firstCommand = psVar8;
        psVar8->nextCommandLine = (sequenceCommandLine_s *)0x0;
      }
      else {
        do {
          psVar9 = psVar5;
          psVar5 = psVar9->nextCommandLine;
        } while (psVar5 != (sequenceCommandLine_s *)0x0);
                    /* Unresolved local var: char endToken@[???]
                       Unresolved local var: sequenceCommandLine_s * newCommandLine@[???]
                       Unresolved local var: char delimiter@[???]
                       Unresolved local var: sequenceCommandLine_s * scan@[???] */
        psVar9->nextCommandLine = psVar8;
        psVar8->nextCommandLine = (sequenceCommandLine_s *)0x0;
      }
      bVar3 = Sequence_ParseModifier(psVar8);
      psVar5 = (sequenceCommandLine_s *)(uint)bVar3;
    } while (bVar3 == 0x2c);
  }
  else if (startToken == '#') {
                    /* Unresolved local var: char delimiter@[???]
                       Unresolved local var: sequenceCommandLine_s * newCommandLine@[???] */
    psVar8 = Mem_ZeroMalloc(0x5c);
    iVar1 = g_blockScopeDefaults.clientMessage.effect;
    (psVar8->clientMessage).pName = (char *)0x0;
    (psVar8->clientMessage).pMessage = (char *)0x0;
    (psVar8->clientMessage).effect = iVar1;
    (psVar8->clientMessage).r1 = g_blockScopeDefaults.clientMessage.r1;
    (psVar8->clientMessage).g1 = g_blockScopeDefaults.clientMessage.g1;
    (psVar8->clientMessage).b1 = g_blockScopeDefaults.clientMessage.b1;
    (psVar8->clientMessage).a1 = g_blockScopeDefaults.clientMessage.a1;
    (psVar8->clientMessage).r2 = g_blockScopeDefaults.clientMessage.r2;
    (psVar8->clientMessage).g2 = g_blockScopeDefaults.clientMessage.g2;
    (psVar8->clientMessage).b2 = g_blockScopeDefaults.clientMessage.b2;
    (psVar8->clientMessage).a2 = g_blockScopeDefaults.clientMessage.a2;
    (psVar8->clientMessage).x = g_blockScopeDefaults.clientMessage.x;
    (psVar8->clientMessage).y = g_blockScopeDefaults.clientMessage.y;
    (psVar8->clientMessage).fadein = g_blockScopeDefaults.clientMessage.fadein;
    (psVar8->clientMessage).fadeout = g_blockScopeDefaults.clientMessage.fadeout;
    (psVar8->clientMessage).holdtime = g_blockScopeDefaults.clientMessage.holdtime;
    (psVar8->clientMessage).fxtime = g_blockScopeDefaults.clientMessage.fxtime;
    iVar1 = g_blockScopeDefaults.textChannel;
    fVar2 = g_blockScopeDefaults.delay;
    psVar8->nextCommandLine = (sequenceCommandLine_s *)0x0;
    psVar8->delay = fVar2;
    psVar8->textChannel = iVar1;
    iVar1 = g_blockScopeDefaults.repeatCount;
    psVar8->soundFileName = (char *)0x0;
    psVar8->repeatCount = iVar1;
    if (psVar8->speakerName != (char *)0x0) {
      Mem_Free(psVar8->speakerName);
    }
    pcVar6 = Mem_Strdup(g_blockScopeDefaults.speakerName);
    psVar8->speakerName = pcVar6;
    if (psVar8->listenerName != (char *)0x0) {
      Mem_Free(psVar8->listenerName);
    }
    psVar5 = (sequenceCommandLine_s *)Mem_Strdup(g_blockScopeDefaults.listenerName);
    psVar8->listenerName = (char *)psVar5;
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???] */
    psVar9 = entry->firstCommand;
    if (entry->firstCommand == (sequenceCommandLine_s *)0x0) {
      entry->firstCommand = psVar8;
      psVar8->nextCommandLine = (sequenceCommandLine_s *)0x0;
    }
    else {
      do {
        psVar5 = psVar9;
        psVar9 = psVar5->nextCommandLine;
      } while (psVar9 != (sequenceCommandLine_s *)0x0);
      psVar5->nextCommandLine = psVar8;
      psVar8->nextCommandLine = (sequenceCommandLine_s *)0x0;
      psVar5 = (sequenceCommandLine_s *)0x0;
    }
    do {
      cVar4 = Sequence_ParseCommand(psVar5);
      psVar5 = (sequenceCommandLine_s *)CONCAT31(extraout_var_00,cVar4);
    } while (cVar4 == ',');
  }
  else {
    if (startToken != '@') {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Parsing error on line %d of %s.seq: line must begin with either \'#\' (command) or \'$\' (modifier); found \'%c\'\n"
                ,g_lineNum,g_sequenceParseFileName,(int)startToken);
    }
                    /* Unresolved local var: char delimiter@[???]
                       Unresolved local var: sequenceCommandLine_s * newCommandLine@[???] */
    psVar5 = Mem_Malloc(0x5c);
    Q_memset(psVar5,0,0x5c);
    iVar1 = g_blockScopeDefaults.clientMessage.effect;
    (psVar5->clientMessage).pName = (char *)0x0;
    (psVar5->clientMessage).pMessage = (char *)0x0;
    (psVar5->clientMessage).effect = iVar1;
    (psVar5->clientMessage).r1 = g_blockScopeDefaults.clientMessage.r1;
    (psVar5->clientMessage).g1 = g_blockScopeDefaults.clientMessage.g1;
    (psVar5->clientMessage).b1 = g_blockScopeDefaults.clientMessage.b1;
    (psVar5->clientMessage).a1 = g_blockScopeDefaults.clientMessage.a1;
    (psVar5->clientMessage).r2 = g_blockScopeDefaults.clientMessage.r2;
    (psVar5->clientMessage).g2 = g_blockScopeDefaults.clientMessage.g2;
    (psVar5->clientMessage).b2 = g_blockScopeDefaults.clientMessage.b2;
    (psVar5->clientMessage).a2 = g_blockScopeDefaults.clientMessage.a2;
    (psVar5->clientMessage).x = g_blockScopeDefaults.clientMessage.x;
    (psVar5->clientMessage).y = g_blockScopeDefaults.clientMessage.y;
    (psVar5->clientMessage).fadein = g_blockScopeDefaults.clientMessage.fadein;
    (psVar5->clientMessage).fadeout = g_blockScopeDefaults.clientMessage.fadeout;
    (psVar5->clientMessage).holdtime = g_blockScopeDefaults.clientMessage.holdtime;
    (psVar5->clientMessage).fxtime = g_blockScopeDefaults.clientMessage.fxtime;
    iVar1 = g_blockScopeDefaults.textChannel;
    fVar2 = g_blockScopeDefaults.delay;
    psVar5->nextCommandLine = (sequenceCommandLine_s *)0x0;
    psVar5->delay = fVar2;
    psVar5->textChannel = iVar1;
    iVar1 = g_blockScopeDefaults.repeatCount;
    psVar5->soundFileName = (char *)0x0;
    psVar5->repeatCount = iVar1;
    if (psVar5->speakerName != (char *)0x0) {
      Mem_Free(psVar5->speakerName);
    }
    pcVar6 = Mem_Strdup(g_blockScopeDefaults.speakerName);
    psVar5->speakerName = pcVar6;
    if (psVar5->listenerName != (char *)0x0) {
      Mem_Free(psVar5->listenerName);
    }
    pcVar6 = Mem_Strdup(g_blockScopeDefaults.listenerName);
    psVar5->listenerName = pcVar6;
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???] */
    psVar8 = entry->firstCommand;
    psVar9 = psVar8;
    if (psVar8 == (sequenceCommandLine_s *)0x0) {
      entry->firstCommand = psVar5;
      psVar5->nextCommandLine = (sequenceCommandLine_s *)0x0;
    }
    else {
      do {
        psVar8 = psVar9;
        psVar9 = psVar8->nextCommandLine;
      } while (psVar8->nextCommandLine != (sequenceCommandLine_s *)0x0);
      psVar8->nextCommandLine = psVar5;
      psVar5->nextCommandLine = (sequenceCommandLine_s *)0x0;
    }
    Sequence_ReadCommandData((sequenceCommandEnum_e)psVar5,psVar8);
    pcVar6 = g_scan;
    ppuVar7 = __ctype_b_loc();
    while( true ) {
      pcVar10 = pcVar6 + 1;
      cVar4 = *pcVar6;
      psVar5 = (sequenceCommandLine_s *)(int)cVar4;
      if ((*(byte *)((int)*ppuVar7 + (int)psVar5 * 2 + 1) & 0x20) == 0) break;
      pcVar6 = pcVar10;
      g_scan = pcVar10;
      if (cVar4 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar10;
      }
    }
    if ((cVar4 != '\0') && (g_scan = pcVar10, cVar4 == ',')) {
      psVar5 = (sequenceCommandLine_s *)&DAT_0000002c;
      do {
        cVar4 = Sequence_ParseCommand(psVar5);
        psVar5 = (sequenceCommandLine_s *)CONCAT31(extraout_var,cVar4);
      } while (cVar4 == ',');
    }
  }
  return (char)psVar5;
}


// Sequence_ParseMacro  @ 00185b00
char Sequence_ParseMacro(sequenceEntry_s *entry)

{
  int iVar1;
  float fVar2;
  sequenceCommandLine_s *psVar3;
  char cVar4;
  sequenceCommandLine_s *psVar5;
  char *pcVar6;
  ushort **ppuVar7;
  undefined3 extraout_var;
  sequenceCommandLine_s *defaults;
  char *pcVar8;
  
                    /* Unresolved local var: char delimiter@[???]
                       Unresolved local var: sequenceCommandLine_s * newCommandLine@[???] */
  psVar5 = Mem_Malloc(0x5c);
  Q_memset(psVar5,0,0x5c);
  iVar1 = g_blockScopeDefaults.clientMessage.effect;
  (psVar5->clientMessage).pName = (char *)0x0;
  (psVar5->clientMessage).pMessage = (char *)0x0;
  (psVar5->clientMessage).effect = iVar1;
  (psVar5->clientMessage).r1 = g_blockScopeDefaults.clientMessage.r1;
  (psVar5->clientMessage).g1 = g_blockScopeDefaults.clientMessage.g1;
  (psVar5->clientMessage).b1 = g_blockScopeDefaults.clientMessage.b1;
  (psVar5->clientMessage).a1 = g_blockScopeDefaults.clientMessage.a1;
  (psVar5->clientMessage).r2 = g_blockScopeDefaults.clientMessage.r2;
  (psVar5->clientMessage).g2 = g_blockScopeDefaults.clientMessage.g2;
  (psVar5->clientMessage).b2 = g_blockScopeDefaults.clientMessage.b2;
  (psVar5->clientMessage).a2 = g_blockScopeDefaults.clientMessage.a2;
  (psVar5->clientMessage).x = g_blockScopeDefaults.clientMessage.x;
  (psVar5->clientMessage).y = g_blockScopeDefaults.clientMessage.y;
  (psVar5->clientMessage).fadein = g_blockScopeDefaults.clientMessage.fadein;
  (psVar5->clientMessage).fadeout = g_blockScopeDefaults.clientMessage.fadeout;
  (psVar5->clientMessage).holdtime = g_blockScopeDefaults.clientMessage.holdtime;
  (psVar5->clientMessage).fxtime = g_blockScopeDefaults.clientMessage.fxtime;
  iVar1 = g_blockScopeDefaults.textChannel;
  fVar2 = g_blockScopeDefaults.delay;
  psVar5->nextCommandLine = (sequenceCommandLine_s *)0x0;
  psVar5->delay = fVar2;
  psVar5->textChannel = iVar1;
  iVar1 = g_blockScopeDefaults.repeatCount;
  psVar5->soundFileName = (char *)0x0;
  psVar5->repeatCount = iVar1;
  if (psVar5->speakerName != (char *)0x0) {
    Mem_Free(psVar5->speakerName);
  }
  pcVar6 = Mem_Strdup(g_blockScopeDefaults.speakerName);
  psVar5->speakerName = pcVar6;
  if (psVar5->listenerName != (char *)0x0) {
    Mem_Free(psVar5->listenerName);
  }
  pcVar6 = Mem_Strdup(g_blockScopeDefaults.listenerName);
  psVar5->listenerName = pcVar6;
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???] */
  defaults = entry->firstCommand;
  psVar3 = defaults;
  if (defaults == (sequenceCommandLine_s *)0x0) {
    entry->firstCommand = psVar5;
    psVar5->nextCommandLine = (sequenceCommandLine_s *)0x0;
  }
  else {
    do {
      defaults = psVar3;
      psVar3 = defaults->nextCommandLine;
    } while (defaults->nextCommandLine != (sequenceCommandLine_s *)0x0);
    defaults->nextCommandLine = psVar5;
    psVar5->nextCommandLine = (sequenceCommandLine_s *)0x0;
  }
  Sequence_ReadCommandData((sequenceCommandEnum_e)psVar5,defaults);
  pcVar6 = g_scan;
  ppuVar7 = __ctype_b_loc();
  while( true ) {
    pcVar8 = pcVar6 + 1;
    cVar4 = *pcVar6;
    psVar5 = (sequenceCommandLine_s *)(int)cVar4;
    if ((*(byte *)((int)*ppuVar7 + (int)psVar5 * 2 + 1) & 0x20) == 0) break;
    pcVar6 = pcVar8;
    g_scan = pcVar8;
    if (cVar4 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar8;
    }
  }
  if (cVar4 != '\0') {
    while (g_scan = pcVar8, cVar4 == ',') {
      cVar4 = Sequence_ParseCommand(psVar5);
      psVar5 = (sequenceCommandLine_s *)CONCAT31(extraout_var,cVar4);
      pcVar8 = g_scan;
    }
  }
  return (char)psVar5;
}


// Sequence_ParseModifier  @ 001850c0
char __regparm3 Sequence_ParseModifier(sequenceCommandLine_s *defaults)

{
  sequenceCommandEnum_e commandEnum;
  bool bVar1;
  int iVar2;
  ushort **ppuVar3;
  char *pcVar4;
  char cVar5;
  int in_EDX;
  sequenceCommandMapping_s *psVar6;
  int iVar7;
  char **ppcVar8;
  int in_GS_OFFSET;
  char local_120 [256];
  int local_20;
  
                    /* Unresolved local var: char[256] modifierName@[???]
                       Unresolved local var: char delimiter@[???]
                       Unresolved local var: sequenceCommandEnum_e modifierEnum@[???] */
  ppcVar8 = &g_sequenceCommandMappingTable[0].commandName;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int numTableEntries@[???] */
  iVar7 = 0;
                    /* Unresolved local var: char * write@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Sequence_GetNameValueString(local_120,in_EDX);
  do {
    iVar2 = Q_stricmp(local_120,*ppcVar8);
    if (iVar2 == 0) {
      commandEnum = g_sequenceCommandMappingTable[iVar7].commandEnum;
      if (commandEnum != SEQUENCE_COMMAND_ERROR) {
        psVar6 = g_sequenceCommandMappingTable;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int numTableEntries@[???] */
        iVar7 = 0;
        while (psVar6->commandEnum != commandEnum) {
          iVar7 = iVar7 + 1;
          psVar6 = psVar6 + 1;
          if (iVar7 == 0x17) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int numTableEntries@[???] */
                    /* WARNING: Subroutine does not return */
            Sys_Error("Internal error caused by line %d of %s.seq: unknown command enum = %d\n",
                      g_lineNum,g_sequenceParseFileName,commandEnum);
          }
        }
        if (g_sequenceCommandMappingTable[iVar7].commandType == SEQUENCE_TYPE_MODIFIER) {
          ppuVar3 = __ctype_b_loc();
          while( true ) {
            pcVar4 = g_scan + 1;
            cVar5 = *g_scan;
            iVar7 = (int)cVar5;
            if ((*(byte *)((int)*ppuVar3 + iVar7 * 2 + 1) & 0x20) == 0) break;
            g_scan = pcVar4;
            if (cVar5 == '\n') {
              g_lineNum = g_lineNum + 1;
              g_lineScan = pcVar4;
            }
          }
          if (cVar5 == '\0') {
            iVar7 = 0;
          }
          else {
            g_scan = pcVar4;
            if (cVar5 == '=') {
              Sequence_ReadCommandData(commandEnum,&g_fileScopeDefaults);
                    /* Unresolved local var: qboolean foundCarriageReturn@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
              cVar5 = *g_scan;
              iVar7 = (int)cVar5;
              if ((*(byte *)((int)*ppuVar3 + iVar7 * 2 + 1) & 0x20) == 0) {
                bVar1 = false;
              }
              else {
                bVar1 = false;
                do {
                  g_scan = g_scan + 1;
                  if ((char)iVar7 == '\n') {
                    g_lineNum = g_lineNum + 1;
                    bVar1 = true;
                    g_lineScan = g_scan;
                  }
                  cVar5 = *g_scan;
                  iVar7 = (int)cVar5;
                } while ((*(byte *)((int)*ppuVar3 + iVar7 * 2 + 1) & 0x20) != 0);
              }
                    /* Unresolved local var: qboolean foundCarriageReturn@[???] */
              if ((cVar5 != ',') && (!bVar1)) {
                    /* WARNING: Subroutine does not return */
                Sys_Error("Parsing error on line %d of %s.seq: after value(s) for modifier \"%s\", expected \',\' or End-Of-Line; found \'%c\'\n"
                          ,g_lineNum,g_sequenceParseFileName,local_120,iVar7);
              }
              if (cVar5 != '\0') {
                g_scan = g_scan + 1;
              }
              if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
                __stack_chk_fail();
              }
              return cVar5;
            }
          }
                    /* WARNING: Subroutine does not return */
          Sys_Error("Parsing error on or after line %d of %s.seq: after modifier \"%s\", expected \'=\', found \'%c\'\n"
                    ,g_lineNum,g_sequenceParseFileName,local_120,iVar7);
        }
                    /* WARNING: Subroutine does not return */
        Sys_Error("Parsing error on line %d of %s.seq: \"%s\" is a #command, not a $modifier\n",
                  g_lineNum,g_sequenceParseFileName,local_120);
      }
      break;
    }
    iVar7 = iVar7 + 1;
    ppcVar8 = ppcVar8 + 3;
  } while (iVar7 != 0x17);
                    /* WARNING: Subroutine does not return */
  Sys_Error("Parsing error on line %d of %s.seq: unknown modifier \"%s\"\n",g_lineNum,
            g_sequenceParseFileName,local_120);
}


// Sequence_ParseModifier  @ 00185380
char __regparm2 Sequence_ParseModifier(sequenceCommandLine_s *defaults)

{
  sequenceCommandEnum_e commandEnum;
  bool bVar1;
  int iVar2;
  ushort **ppuVar3;
  char *pcVar4;
  char cVar5;
  int in_EDX;
  sequenceCommandMapping_s *psVar6;
  int iVar7;
  char **ppcVar8;
  int in_GS_OFFSET;
  sequenceCommandLine_s *in_stack_00000004;
  char local_120 [256];
  int local_20;
  
                    /* Unresolved local var: char[256] modifierName@[???]
                       Unresolved local var: char delimiter@[???]
                       Unresolved local var: sequenceCommandEnum_e modifierEnum@[???] */
  ppcVar8 = &g_sequenceCommandMappingTable[0].commandName;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int numTableEntries@[???] */
  iVar7 = 0;
                    /* Unresolved local var: char * write@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Sequence_GetNameValueString(local_120,in_EDX);
  do {
    iVar2 = Q_stricmp(local_120,*ppcVar8);
    if (iVar2 == 0) {
      commandEnum = g_sequenceCommandMappingTable[iVar7].commandEnum;
      if (commandEnum != SEQUENCE_COMMAND_ERROR) {
        psVar6 = g_sequenceCommandMappingTable;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int numTableEntries@[???] */
        iVar7 = 0;
        while (psVar6->commandEnum != commandEnum) {
          iVar7 = iVar7 + 1;
          psVar6 = psVar6 + 1;
          if (iVar7 == 0x17) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int numTableEntries@[???] */
                    /* WARNING: Subroutine does not return */
            Sys_Error("Internal error caused by line %d of %s.seq: unknown command enum = %d\n",
                      g_lineNum,g_sequenceParseFileName,commandEnum);
          }
        }
        if (g_sequenceCommandMappingTable[iVar7].commandType == SEQUENCE_TYPE_MODIFIER) {
          ppuVar3 = __ctype_b_loc();
          while( true ) {
            pcVar4 = g_scan + 1;
            cVar5 = *g_scan;
            iVar7 = (int)cVar5;
            if ((*(byte *)((int)*ppuVar3 + iVar7 * 2 + 1) & 0x20) == 0) break;
            g_scan = pcVar4;
            if (cVar5 == '\n') {
              g_lineNum = g_lineNum + 1;
              g_lineScan = pcVar4;
            }
          }
          if (cVar5 == '\0') {
            iVar7 = 0;
          }
          else {
            g_scan = pcVar4;
            if (cVar5 == '=') {
              Sequence_ReadCommandData(commandEnum,in_stack_00000004);
                    /* Unresolved local var: qboolean foundCarriageReturn@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
              cVar5 = *g_scan;
              iVar7 = (int)cVar5;
              if ((*(byte *)((int)*ppuVar3 + iVar7 * 2 + 1) & 0x20) == 0) {
                bVar1 = false;
              }
              else {
                bVar1 = false;
                do {
                  g_scan = g_scan + 1;
                  if ((char)iVar7 == '\n') {
                    g_lineNum = g_lineNum + 1;
                    bVar1 = true;
                    g_lineScan = g_scan;
                  }
                  cVar5 = *g_scan;
                  iVar7 = (int)cVar5;
                } while ((*(byte *)((int)*ppuVar3 + iVar7 * 2 + 1) & 0x20) != 0);
              }
                    /* Unresolved local var: qboolean foundCarriageReturn@[???] */
              if ((cVar5 != ',') && (!bVar1)) {
                    /* WARNING: Subroutine does not return */
                Sys_Error("Parsing error on line %d of %s.seq: after value(s) for modifier \"%s\", expected \',\' or End-Of-Line; found \'%c\'\n"
                          ,g_lineNum,g_sequenceParseFileName,local_120,iVar7);
              }
              if (cVar5 != '\0') {
                g_scan = g_scan + 1;
              }
              if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
                __stack_chk_fail();
              }
              return cVar5;
            }
          }
                    /* WARNING: Subroutine does not return */
          Sys_Error("Parsing error on or after line %d of %s.seq: after modifier \"%s\", expected \'=\', found \'%c\'\n"
                    ,g_lineNum,g_sequenceParseFileName,local_120,iVar7);
        }
                    /* WARNING: Subroutine does not return */
        Sys_Error("Parsing error on line %d of %s.seq: \"%s\" is a #command, not a $modifier\n",
                  g_lineNum,g_sequenceParseFileName,local_120);
      }
      break;
    }
    iVar7 = iVar7 + 1;
    ppcVar8 = ppcVar8 + 3;
  } while (iVar7 != 0x17);
                    /* WARNING: Subroutine does not return */
  Sys_Error("Parsing error on line %d of %s.seq: unknown modifier \"%s\"\n",g_lineNum,
            g_sequenceParseFileName,local_120);
}


// Sequence_ParseModifierLine  @ 00185690
char __regparm1 Sequence_ParseModifierLine(sequenceEntry_s *entry,int modifierType)

{
  int iVar1;
  char cVar2;
  sequenceCommandLine_s *defaults;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  int in_stack_00000008;
  
LAB_001856a0:
  do {
    if (in_stack_00000008 == 0) {
      cVar2 = Sequence_ParseModifier((sequenceCommandLine_s *)entry);
      entry = (sequenceEntry_s *)CONCAT31(extraout_var_00,cVar2);
    }
    else {
      if (in_stack_00000008 != 1) goto LAB_001856a0;
      defaults = Mem_ZeroMalloc(0x5c);
      defaults->commandType = 9;
                    /* Unresolved local var: sequenceCommandLine_s * scan@[???] */
      iVar1 = *(int *)(modifierType + 8);
      if (*(int *)(modifierType + 8) == 0) {
        *(sequenceCommandLine_s **)(modifierType + 8) = defaults;
        defaults->nextCommandLine = (sequenceCommandLine_s *)0x0;
      }
      else {
        do {
          iVar3 = iVar1;
          iVar1 = *(int *)(iVar3 + 0x58);
        } while (iVar1 != 0);
        *(sequenceCommandLine_s **)(iVar3 + 0x58) = defaults;
        defaults->nextCommandLine = (sequenceCommandLine_s *)0x0;
      }
      cVar2 = Sequence_ParseModifier(defaults);
      entry = (sequenceEntry_s *)CONCAT31(extraout_var,cVar2);
    }
    if ((char)entry != ',') {
      return (char)entry;
    }
  } while( true );
}


// Sequence_ParseSentenceBlock  @ 00187230
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char Sequence_ParseSentenceBlock(void)

{
  char cVar1;
  byte bVar2;
  ushort **ppuVar3;
  char *pcVar4;
  qboolean qVar5;
  int iVar6;
  
                    /* Unresolved local var: char symbol@[???]
                       Unresolved local var: qboolean finished@[???] */
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
  }
  else {
    g_scan = pcVar4;
    if (cVar1 == '{') {
      do {
        qVar5 = Sequence_ParseSentenceLine();
      } while (qVar5 == false);
                    /* Unresolved local var: char ch@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
      cVar1 = *g_scan;
      iVar6 = (int)cVar1;
      bVar2 = *(byte *)((int)*ppuVar3 + iVar6 * 2 + 1);
      while ((bVar2 & 0x20) != 0) {
        g_scan = g_scan + 1;
        if ((char)iVar6 == '\n') {
          g_lineNum = g_lineNum + 1;
          g_lineScan = g_scan;
        }
        cVar1 = *g_scan;
        iVar6 = (int)cVar1;
        bVar2 = *(byte *)((int)*ppuVar3 + iVar6 * 2 + 1);
      }
      if (cVar1 != '\0') {
        g_scan = g_scan + 1;
      }
      return cVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Parsing error on line %d of %s.seq: expected \'{\' to start a\n new sentence block; found \'%c\' instead!"
            ,g_lineNum,g_sequenceParseFileName,iVar6);
}


// Sequence_ParseSentenceLine  @ 00186fd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Sequence_ParseSentenceLine(void)

{
  ushort *puVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  ushort **ppuVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  uint *puVar9;
  uint *puVar10;
  qboolean qVar11;
  int in_GS_OFFSET;
  uint local_4a0 [16];
  char local_460 [60];
  char acStack_424 [4];
  uint local_420 [256];
  int local_20;
  
                    /* Unresolved local var: char[1024] data@[???]
                       Unresolved local var: char[64] fullgroup@[???]
                       Unresolved local var: char[64] groupName@[???]
                       Unresolved local var: char * c@[???]
                       Unresolved local var: int lastCharacterPos@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Sequence_GetToken((char *)local_4a0,0x40);
  puVar10 = local_4a0;
  if ((char)local_4a0[0] == '}') {
    qVar11 = true;
  }
  else {
    do {
      puVar9 = puVar10;
      uVar3 = *puVar9 + 0xfefefeff & ~*puVar9;
      uVar4 = uVar3 & 0x80808080;
      puVar10 = puVar9 + 1;
    } while (uVar4 == 0);
    bVar2 = (byte)uVar4;
    if ((uVar3 & 0x8080) == 0) {
      bVar2 = (byte)(uVar4 >> 0x10);
      puVar10 = (uint *)((int)puVar9 + 6);
    }
    ppuVar5 = __ctype_b_loc();
    puVar1 = *ppuVar5;
    for (pcVar7 = (char *)((int)puVar10 + (-4 - (uint)CARRY1(bVar2,bVar2)));
        ((*(byte *)((int)puVar1 + *pcVar7 * 2 + 1) & 4) == 0 && (*pcVar7 != '_'));
        pcVar7 = pcVar7 + -1) {
    }
    if ((pcVar7 != (char *)0xffffffff) && (pcVar7[1] != '\0')) {
      pcVar7[1] = '\0';
    }
    __strcpy_chk(local_460,local_4a0,0x40);
                    /* Unresolved local var: int lineLen@[???]
                       Unresolved local var: char * read@[???]
                       Unresolved local var: char * write@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
    iVar6 = (int)*g_scan;
    bVar2 = *(byte *)((int)puVar1 + iVar6 * 2 + 1);
    pcVar7 = g_scan;
    while ((bVar2 & 0x20) != 0) {
      pcVar7 = pcVar7 + 1;
      if ((char)iVar6 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar7;
      }
      iVar6 = (int)*pcVar7;
      bVar2 = *(byte *)((int)*ppuVar5 + iVar6 * 2 + 1);
    }
    g_scan = pcVar7;
    pcVar8 = strchr(pcVar7,10);
    if (pcVar8 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Syntax Error on line %d of %s.seq: expected sentence definition or \'}\', found End-Of-File!\n"
                ,g_lineNum,g_sequenceParseFileName);
    }
    iVar6 = (int)pcVar8 - (int)pcVar7;
    if (0x3ff < iVar6) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Syntax Error on line %d of %s.seq: line was too long (was %d chars; max is %d chars)\n"
                ,g_lineNum,g_sequenceParseFileName,iVar6,0x3ff);
    }
    __strncpy_chk(local_420,pcVar7,iVar6,0x400);
    *(undefined1 *)((int)local_420 + iVar6) = 0;
    puVar10 = local_420;
    do {
      puVar9 = puVar10;
      uVar4 = *puVar9 + 0xfefefeff & ~*puVar9;
      uVar3 = uVar4 & 0x80808080;
      puVar10 = puVar9 + 1;
    } while (uVar3 == 0);
    if ((uVar4 & 0x8080) == 0) {
      puVar10 = (uint *)((int)puVar9 + 6);
      uVar3 = uVar3 >> 0x10;
    }
    iVar6 = -(int)local_420 - (uint)CARRY1((byte)uVar3,(byte)uVar3);
    if ((*(char *)((int)puVar10 + (int)(acStack_424 + iVar6)) == '\n') ||
       (*(char *)((int)puVar10 + (int)(acStack_424 + iVar6)) == '\r')) {
      *(char *)((int)puVar10 + (int)(acStack_424 + iVar6)) = '\0';
    }
    g_scan = pcVar8;
    Sequence_AddSentenceToGroup(local_460,(char *)local_420);
    qVar11 = false;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return qVar11;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Sequence_PurgeEntries  @ 001889f0
void Sequence_PurgeEntries(qboolean purgeGlobals)

{
  sentenceEntry_s **ppsVar1;
  char *pcVar2;
  sequenceCommandLine_s *psVar3;
  sentenceEntry_s *psVar4;
  sentenceGroupEntry_s *p;
  sentenceGroupEntry_s *psVar5;
  sequenceEntry_s *psVar6;
  sequenceEntry_s *p_00;
  sentenceEntry_s *psVar7;
  sequenceEntry_s *psVar8;
  sentenceEntry_s *p_01;
  sentenceGroupEntry_s *local_20;
  
                    /* Unresolved local var: sequenceEntry_s * scan@[???]
                       Unresolved local var: sequenceEntry_s * dead@[???]
                       Unresolved local var: sequenceEntry_s * prev@[???]
                       Unresolved local var: sentenceGroupEntry_s * groupEntry@[???]
                       Unresolved local var: sentenceGroupEntry_s * deadGroup@[???]
                       Unresolved local var: sentenceGroupEntry_s * prevGroup@[???] */
  if (g_sequenceList != (sequenceEntry_s *)0x0) {
    psVar6 = g_sequenceList;
    psVar8 = (sequenceEntry_s *)0x0;
    do {
      while ((p_00 = psVar6, p_00->isGlobal != 0 && (purgeGlobals == false))) {
        psVar6 = p_00->nextEntry;
        psVar8 = p_00;
        if (p_00->nextEntry == (sequenceEntry_s *)0x0) goto LAB_00188ae8;
      }
      if (psVar8 == (sequenceEntry_s *)0x0) {
        psVar6 = p_00->nextEntry;
        g_sequenceList = psVar6;
      }
      else {
        psVar8->nextEntry = p_00->nextEntry;
        psVar6 = p_00->nextEntry;
      }
      if (p_00->entryName != (char *)0x0) {
        Mem_Free(p_00->entryName);
      }
      pcVar2 = p_00->fileName;
      while( true ) {
        if (pcVar2 != (char *)0x0) {
          Mem_Free(pcVar2);
        }
        psVar3 = p_00->firstCommand;
        if (psVar3 == (sequenceCommandLine_s *)0x0) break;
                    /* Unresolved local var: sequenceCommandLine_s * dead@[???] */
        p_00->firstCommand = psVar3->nextCommandLine;
        if (psVar3->fireTargetNames != (char *)0x0) {
          Mem_Free(psVar3->fireTargetNames);
        }
        if (psVar3->speakerName != (char *)0x0) {
          Mem_Free(psVar3->speakerName);
        }
        if (psVar3->listenerName != (char *)0x0) {
          Mem_Free(psVar3->listenerName);
        }
        if (psVar3->soundFileName != (char *)0x0) {
          Mem_Free(psVar3->soundFileName);
        }
        if (psVar3->sentenceName != (char *)0x0) {
          Mem_Free(psVar3->sentenceName);
        }
        pcVar2 = (psVar3->clientMessage).pName;
        if (pcVar2 != (char *)0x0) {
          Mem_Free(pcVar2);
        }
        pcVar2 = (psVar3->clientMessage).pMessage;
      }
      Mem_Free(p_00);
    } while (psVar6 != (sequenceEntry_s *)0x0);
  }
LAB_00188ae8:
  local_20 = (sentenceGroupEntry_s *)0x0;
  p = g_sentenceGroupList;
  do {
    if (p == (sentenceGroupEntry_s *)0x0) {
      return;
    }
                    /* Unresolved local var: sentenceEntry_s * sentenceEntry@[???]
                       Unresolved local var: sentenceEntry_s * deadSentence@[???]
                       Unresolved local var: sentenceEntry_s * prevSentence@[???] */
    if (p->firstSentence != (sentenceEntry_s *)0x0) {
      psVar7 = (sentenceEntry_s *)0x0;
      p_01 = p->firstSentence;
      do {
        while ((p_01->isGlobal != 0 && (purgeGlobals == false))) {
          ppsVar1 = &p_01->nextEntry;
          psVar7 = p_01;
          p_01 = *ppsVar1;
          if (*ppsVar1 == (sentenceEntry_s *)0x0) goto LAB_00188b6b;
        }
        if (psVar7 == (sentenceEntry_s *)0x0) {
          p->firstSentence = p_01->nextEntry;
        }
        else {
          psVar7->nextEntry = p_01->nextEntry;
        }
        p->numSentences = p->numSentences - 1;
        g_nonGlobalSentences = g_nonGlobalSentences - 1;
        psVar4 = p_01->nextEntry;
        if (p_01->data != (char *)0x0) {
          Mem_Free(p_01->data);
        }
        Mem_Free(p_01);
        p_01 = psVar4;
      } while (psVar4 != (sentenceEntry_s *)0x0);
    }
LAB_00188b6b:
    if (p->numSentences == 0) {
      if (local_20 == (sentenceGroupEntry_s *)0x0) {
        psVar5 = p->nextEntry;
        g_sentenceGroupList = psVar5;
      }
      else {
        local_20->nextEntry = p->nextEntry;
        psVar5 = p->nextEntry;
      }
      if (p->groupName != (char *)0x0) {
        Mem_Free(p->groupName);
      }
      Mem_Free(p);
      p = psVar5;
    }
    else {
      local_20 = p;
      p = p->nextEntry;
    }
  } while( true );
}


// Sequence_ReadCommandData  @ 00183910
void __regparm3
Sequence_ReadCommandData(sequenceCommandEnum_e commandEnum,sequenceCommandLine_s *defaults)

{
  char cVar1;
  ushort **ppuVar2;
  char *pcVar3;
  int in_GS_OFFSET;
  char local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: char[1024] tempString@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
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
  Sequence_GetNameValueString(local_410,0x400);
  pcVar3 = Mem_Strdup(local_410);
  *(char **)(commandEnum + 0x28) = pcVar3;
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Sequence_ReadCommandData  @ 001846d0
void Sequence_ReadCommandData(sequenceCommandEnum_e commandEnum,sequenceCommandLine_s *defaults)

{
  char cVar1;
  byte bVar2;
  ushort **ppuVar3;
  long lVar4;
  char *pcVar5;
  char *tokenLen;
  int iVar6;
  int in_GS_OFFSET;
  double dVar7;
  char local_420 [1024];
  int local_20;
  
                    /* Unresolved local var: char[1024] tempString@[???] */
  pcVar5 = g_scan;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  switch(commandEnum) {
  case SEQUENCE_COMMAND_PAUSE:
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
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,(int)pcVar5);
    dVar7 = strtod(local_420,(char **)0x0);
    defaults->delay = (float)dVar7;
    break;
  case SEQUENCE_COMMAND_FIRETARGETS:
                    /* Unresolved local var: char ch@[???]
                       Unresolved local var: char * write@[???] */
    Sequence_ReadQuotedString(local_420,0x400);
    pcVar5 = Mem_Strdup(local_420);
    defaults->fireTargetNames = pcVar5;
    break;
  case SEQUENCE_COMMAND_KILLTARGETS:
                    /* Unresolved local var: char ch@[???]
                       Unresolved local var: char * write@[???] */
    Sequence_ReadQuotedString(local_420,0x400);
    pcVar5 = Mem_Strdup(local_420);
    defaults->killTargetNames = pcVar5;
    break;
  case SEQUENCE_COMMAND_TEXT:
                    /* Unresolved local var: char ch@[???]
                       Unresolved local var: char * write@[???] */
    Sequence_ReadQuotedString(local_420,0x400);
    pcVar5 = Mem_Strdup(local_420);
    (defaults->clientMessage).pMessage = pcVar5;
    break;
  case SEQUENCE_COMMAND_SOUND:
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
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,0x400);
    pcVar5 = Mem_Strdup(local_420);
    defaults->soundFileName = pcVar5;
    break;
  case SEQUENCE_COMMAND_GOSUB:
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
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,0x400);
    pcVar5 = Mem_Strdup(local_420);
    (defaults->clientMessage).pName = pcVar5;
    break;
  case SEQUENCE_COMMAND_SENTENCE:
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
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,0x400);
    pcVar5 = Mem_Strdup(local_420);
    defaults->sentenceName = pcVar5;
    break;
  case SEQUENCE_COMMAND_REPEAT:
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
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,(int)pcVar5);
    lVar4 = strtol(local_420,(char **)0x0,10);
    defaults->repeatCount = lVar4;
    break;
  default:
                    /* WARNING: Subroutine does not return */
    Sys_Error("Internal error caused by line %d of %s.seq: unknown command enum = %d\n",g_lineNum,
              g_sequenceParseFileName,commandEnum);
  case SEQUENCE_MODIFIER_EFFECT:
    ppuVar3 = __ctype_b_loc();
    while( true ) {
      tokenLen = pcVar5 + 1;
      cVar1 = *pcVar5;
      if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
      pcVar5 = tokenLen;
      g_scan = tokenLen;
      if (cVar1 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = tokenLen;
      }
    }
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,(int)tokenLen);
    lVar4 = strtol(local_420,(char **)0x0,10);
    defaults->modifierBitField = defaults->modifierBitField | 2;
    (defaults->clientMessage).effect = lVar4;
    break;
  case SEQUENCE_MODIFIER_POSITION:
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
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,(int)cVar1);
    dVar7 = strtod(local_420,(char **)0x0);
    pcVar5 = g_scan;
    (defaults->clientMessage).x = (float)dVar7;
    iVar6 = (int)*pcVar5;
    bVar2 = *(byte *)((int)*ppuVar3 + iVar6 * 2 + 1);
                    /* Unresolved local var: char[256] floatString@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
    while ((bVar2 & 0x20) != 0) {
      pcVar5 = pcVar5 + 1;
      if ((char)iVar6 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
      iVar6 = (int)*pcVar5;
      g_scan = pcVar5;
      bVar2 = *(byte *)((int)*ppuVar3 + iVar6 * 2 + 1);
    }
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,iVar6);
    dVar7 = strtod(local_420,(char **)0x0);
    (defaults->clientMessage).y = (float)dVar7;
    defaults->modifierBitField = defaults->modifierBitField | 4;
    break;
  case SEQUENCE_MODIFIER_COLOR:
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
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,(int)cVar1);
    lVar4 = strtol(local_420,(char **)0x0,10);
    pcVar5 = g_scan;
    (defaults->clientMessage).r1 = (byte)lVar4;
    iVar6 = (int)*pcVar5;
    bVar2 = *(byte *)((int)*ppuVar3 + iVar6 * 2 + 1);
                    /* Unresolved local var: char[256] intString@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
    while (pcVar5 = pcVar5 + 1, (bVar2 & 0x20) != 0) {
      if ((char)iVar6 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
      iVar6 = (int)*pcVar5;
      g_scan = pcVar5;
      bVar2 = *(byte *)((int)*ppuVar3 + iVar6 * 2 + 1);
    }
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,(int)pcVar5);
    lVar4 = strtol(local_420,(char **)0x0,10);
    (defaults->clientMessage).g1 = (byte)lVar4;
                    /* Unresolved local var: char[256] intString@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
    iVar6 = (int)*g_scan;
    bVar2 = *(byte *)((int)*ppuVar3 + iVar6 * 2 + 1);
    while ((bVar2 & 0x20) != 0) {
      g_scan = g_scan + 1;
      if ((char)iVar6 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = g_scan;
      }
      iVar6 = (int)*g_scan;
      bVar2 = *(byte *)((int)*ppuVar3 + iVar6 * 2 + 1);
    }
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,iVar6);
    lVar4 = strtol(local_420,(char **)0x0,10);
    (defaults->clientMessage).a1 = 0xff;
    defaults->modifierBitField = defaults->modifierBitField | 8;
    (defaults->clientMessage).b1 = (byte)lVar4;
    break;
  case SEQUENCE_MODIFIER_COLOR2:
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
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,(int)cVar1);
    lVar4 = strtol(local_420,(char **)0x0,10);
    pcVar5 = g_scan;
    (defaults->clientMessage).r2 = (byte)lVar4;
    iVar6 = (int)*pcVar5;
    bVar2 = *(byte *)((int)*ppuVar3 + iVar6 * 2 + 1);
                    /* Unresolved local var: char[256] intString@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
    while (pcVar5 = pcVar5 + 1, (bVar2 & 0x20) != 0) {
      if ((char)iVar6 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = pcVar5;
      }
      iVar6 = (int)*pcVar5;
      g_scan = pcVar5;
      bVar2 = *(byte *)((int)*ppuVar3 + iVar6 * 2 + 1);
    }
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,(int)pcVar5);
    lVar4 = strtol(local_420,(char **)0x0,10);
    (defaults->clientMessage).g2 = (byte)lVar4;
                    /* Unresolved local var: char[256] intString@[???]
                       Unresolved local var: qboolean passedCarriageReturn@[???] */
    iVar6 = (int)*g_scan;
    bVar2 = *(byte *)((int)*ppuVar3 + iVar6 * 2 + 1);
    while ((bVar2 & 0x20) != 0) {
      g_scan = g_scan + 1;
      if ((char)iVar6 == '\n') {
        g_lineNum = g_lineNum + 1;
        g_lineScan = g_scan;
      }
      iVar6 = (int)*g_scan;
      bVar2 = *(byte *)((int)*ppuVar3 + iVar6 * 2 + 1);
    }
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,iVar6);
    lVar4 = strtol(local_420,(char **)0x0,10);
    (defaults->clientMessage).a2 = 0xff;
    defaults->modifierBitField = defaults->modifierBitField | 0x10;
    (defaults->clientMessage).b2 = (byte)lVar4;
    break;
  case SEQUENCE_MODIFIER_FADEIN:
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
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,(int)pcVar5);
    dVar7 = strtod(local_420,(char **)0x0);
    (defaults->clientMessage).fadein = (float)dVar7;
    defaults->modifierBitField = defaults->modifierBitField | 0x20;
    break;
  case SEQUENCE_MODIFIER_FADEOUT:
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
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,(int)pcVar5);
    dVar7 = strtod(local_420,(char **)0x0);
    (defaults->clientMessage).fadeout = (float)dVar7;
    defaults->modifierBitField = defaults->modifierBitField | 0x40;
    break;
  case SEQUENCE_MODIFIER_HOLDTIME:
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
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,(int)pcVar5);
    dVar7 = strtod(local_420,(char **)0x0);
    (defaults->clientMessage).holdtime = (float)dVar7;
    defaults->modifierBitField = defaults->modifierBitField | 0x80;
    break;
  case SEQUENCE_MODIFIER_FXTIME:
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
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,(int)pcVar5);
    dVar7 = strtod(local_420,(char **)0x0);
    (defaults->clientMessage).fxtime = (float)dVar7;
    defaults->modifierBitField = defaults->modifierBitField | 0x100;
    break;
  case SEQUENCE_MODIFIER_SPEAKER:
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
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,0x400);
    pcVar5 = Mem_Strdup(local_420);
    defaults->modifierBitField = defaults->modifierBitField | 0x200;
    defaults->speakerName = pcVar5;
    break;
  case SEQUENCE_MODIFIER_LISTENER:
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
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,0x400);
    pcVar5 = Mem_Strdup(local_420);
    defaults->modifierBitField = defaults->modifierBitField | 0x400;
    defaults->listenerName = pcVar5;
    break;
  case SEQUENCE_MODIFIER_TEXTCHANNEL:
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
                    /* Unresolved local var: char * write@[???] */
    Sequence_GetNameValueString(local_420,(int)pcVar5);
    lVar4 = strtol(local_420,(char **)0x0,10);
    defaults->modifierBitField = defaults->modifierBitField | 0x800;
    defaults->textChannel = lVar4;
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Sequence_ReadFloat  @ 001843e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float Sequence_ReadFloat(void)

{
  char cVar1;
  char *pcVar2;
  ushort **ppuVar3;
  char *tokenLen;
  int in_GS_OFFSET;
  double dVar4;
  char local_110 [256];
  int local_10;
  
                    /* Unresolved local var: char[256] floatString@[???] */
  pcVar2 = g_scan;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  ppuVar3 = __ctype_b_loc();
  while( true ) {
    tokenLen = pcVar2 + 1;
    cVar1 = *pcVar2;
    if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
    pcVar2 = tokenLen;
    g_scan = tokenLen;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = tokenLen;
    }
  }
                    /* Unresolved local var: char * write@[???] */
  Sequence_GetNameValueString(local_110,(int)tokenLen);
  dVar4 = strtod(local_110,(char **)0x0);
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (float)dVar4;
}


// Sequence_ReadInt  @ 00184340
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Sequence_ReadInt(void)

{
  char cVar1;
  char *pcVar2;
  ushort **ppuVar3;
  long lVar4;
  char *tokenLen;
  int in_GS_OFFSET;
  char local_110 [256];
  int local_10;
  
                    /* Unresolved local var: char[256] intString@[???] */
  pcVar2 = g_scan;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  ppuVar3 = __ctype_b_loc();
  while( true ) {
    tokenLen = pcVar2 + 1;
    cVar1 = *pcVar2;
    if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
    pcVar2 = tokenLen;
    g_scan = tokenLen;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = tokenLen;
    }
  }
                    /* Unresolved local var: char * write@[???] */
  Sequence_GetNameValueString(local_110,(int)tokenLen);
  lVar4 = strtol(local_110,(char **)0x0,10);
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar4;
}


// Sequence_ReadQuotedString  @ 00183810
void __regparm3 Sequence_ReadQuotedString(char *string,int stringLen)

{
  char cVar1;
  ushort **ppuVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  
                    /* Unresolved local var: char ch@[???]
                       Unresolved local var: char * write@[???] */
  pcVar4 = g_scan;
  ppuVar2 = __ctype_b_loc();
  while( true ) {
    pcVar3 = pcVar4 + 1;
    cVar1 = *pcVar4;
    iVar5 = (int)cVar1;
    if ((*(byte *)((int)*ppuVar2 + iVar5 * 2 + 1) & 0x20) == 0) break;
    pcVar4 = pcVar3;
    g_scan = pcVar3;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar3;
    }
  }
                    /* Unresolved local var: char ch@[???] */
  if (cVar1 == '\0') {
    iVar5 = 0;
  }
  else {
    g_scan = pcVar3;
    if (cVar1 == '\"') {
      cVar1 = *pcVar3;
      pcVar4 = string;
      if (((cVar1 != '\0') && (cVar1 != '\"')) && (0 < stringLen + -1)) {
        do {
          if (cVar1 == '\n') {
            g_lineNum = g_lineNum + 1;
            cVar1 = *pcVar3;
          }
          g_scan = pcVar3;
          *pcVar4 = cVar1;
          pcVar4 = pcVar4 + 1;
          pcVar3 = g_scan + 1;
          cVar1 = g_scan[1];
          g_scan = pcVar3;
        } while (((cVar1 != '\0') && (cVar1 != '\"')) &&
                ((int)pcVar4 - (int)string < stringLen + -1));
      }
      *pcVar4 = '\0';
      g_scan = g_scan + 1;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Parsing error on or before line %d of %s.seq: expected quote (\"), found \'%c\' instead\n"
            ,g_lineNum,g_sequenceParseFileName,iVar5);
}


// Sequence_ReadQuotedString  @ 00184500
void Sequence_ReadQuotedString(char *string,int stringLen)

{
  char cVar1;
  ushort **ppuVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  
                    /* Unresolved local var: char ch@[???]
                       Unresolved local var: char * write@[???] */
  pcVar4 = g_scan;
  if (stringLen < 1) {
    return;
  }
  ppuVar2 = __ctype_b_loc();
  while( true ) {
    pcVar3 = pcVar4 + 1;
    cVar1 = *pcVar4;
    iVar5 = (int)cVar1;
    if ((*(byte *)((int)*ppuVar2 + iVar5 * 2 + 1) & 0x20) == 0) break;
    pcVar4 = pcVar3;
    g_scan = pcVar3;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar3;
    }
  }
                    /* Unresolved local var: char ch@[???] */
  if (cVar1 == '\0') {
    iVar5 = 0;
  }
  else {
    g_scan = pcVar3;
    if (cVar1 == '\"') {
      cVar1 = *pcVar3;
      pcVar4 = string;
      if (((cVar1 != '\0') && (cVar1 != '\"')) && (stringLen != 1)) {
        do {
          if (cVar1 == '\n') {
            g_lineNum = g_lineNum + 1;
            cVar1 = *pcVar3;
          }
          g_scan = pcVar3;
          *pcVar4 = cVar1;
          pcVar4 = pcVar4 + 1;
          pcVar3 = g_scan + 1;
          cVar1 = g_scan[1];
          g_scan = pcVar3;
        } while (((cVar1 != '\0') && (cVar1 != '\"')) &&
                ((int)pcVar4 - (int)string < stringLen + -1));
      }
      *pcVar4 = '\0';
      g_scan = g_scan + 1;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Parsing error on or before line %d of %s.seq: expected quote (\"), found \'%c\' instead\n"
            ,g_lineNum,g_sequenceParseFileName,iVar5);
}


// Sequence_ReadString  @ 00184490
void Sequence_ReadString(char *string,int stringLen)

{
  char cVar1;
  char *pcVar2;
  ushort **ppuVar3;
  char *pcVar4;
  
  pcVar2 = g_scan;
  ppuVar3 = __ctype_b_loc();
  while( true ) {
    pcVar4 = pcVar2 + 1;
    cVar1 = *pcVar2;
    if ((*(byte *)((int)*ppuVar3 + cVar1 * 2 + 1) & 0x20) == 0) break;
    pcVar2 = pcVar4;
    g_scan = pcVar4;
    if (cVar1 == '\n') {
      g_lineNum = g_lineNum + 1;
      g_lineScan = pcVar4;
    }
  }
                    /* Unresolved local var: char * write@[???] */
  if (stringLen < 1) {
    return;
  }
  Sequence_GetNameValueString(string,stringLen);
  return;
}


// Sequence_ResetDefaults  @ 00183a30
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


// Sequence_SkipWhitespace  @ 00183e40
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


// Sequence_StripComments  @ 00184230
void Sequence_StripComments(char *buffer,int *pBufSize)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  byte *pbVar4;
  byte *pbVar5;
  
                    /* Unresolved local var: char * eof@[???]
                       Unresolved local var: char * read@[???]
                       Unresolved local var: char * write@[???] */
  pbVar5 = (byte *)(buffer + *pBufSize);
  if (buffer < pbVar5) {
    bVar3 = *buffer;
    pbVar4 = (byte *)buffer;
    while (bVar3 != 0) {
      while (bVar3 == 0x2f) {
        if (pbVar4[1] == 0x2f) {
          if ((0xd < *pbVar4) || (((byte)(0x2401 >> (*pbVar4 & 0x1f)) & 1) != 1)) {
            do {
              do {
                pbVar4 = pbVar4 + 1;
              } while (0xd < *pbVar4);
            } while ((0x2401U >> (*pbVar4 & 0x1f) & 1) == 0);
          }
          goto LAB_0018425c;
        }
        if (pbVar4[1] != 0x2a) break;
        bVar3 = pbVar4[2];
        pbVar2 = pbVar4 + 3;
        pbVar4 = pbVar4 + 2;
        while( true ) {
          pbVar1 = pbVar2;
          if (bVar3 == 0) goto LAB_001842be;
          if (*pbVar1 == 0) break;
          if ((*pbVar1 == 0x2f) && (bVar3 == 0x2a)) {
            pbVar4 = pbVar1 + 1;
            goto LAB_0018425c;
          }
          if ((bVar3 == 10) || (bVar3 == 0xd)) {
            *buffer = bVar3;
            buffer = buffer + 1;
          }
          bVar3 = *pbVar1;
          pbVar2 = pbVar1 + 1;
          pbVar4 = pbVar1;
        }
        if (pbVar5 <= pbVar4) goto LAB_001842be;
      }
      *buffer = bVar3;
      pbVar4 = pbVar4 + 1;
      buffer = buffer + 1;
LAB_0018425c:
      if (pbVar5 <= pbVar4) break;
      bVar3 = *pbVar4;
    }
  }
LAB_001842be:
  *buffer = 0;
  return;
}


// Sequence_ValidateNameValueString  @ 00183fb0
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
      if ((((((*ppuVar1)[cVar2] & 8) == 0) && (2 < (byte)(cVar2 - 0x2dU))) && (cVar2 != '_')) &&
         (cVar2 != '\\')) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Parsing error on line %d of %s.seq: name/value string \"%s\" had illegal character \'%c\'\n"
                  ,g_lineNum,g_sequenceParseFileName,token,(int)cVar2);
      }
      pcVar3 = pcVar3 + 1;
      cVar2 = *pcVar3;
    } while (cVar2 != '\0');
  }
  return;
}


// Sequence_WriteDefaults  @ 00183bd0
void Sequence_WriteDefaults(sequenceCommandLine_s *source,sequenceCommandLine_s *destination)

{
  char *pcVar1;
  uint uVar2;
  
  if (destination == (sequenceCommandLine_s *)0x0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Attempt to bake defaults into a non-existant command.");
  }
  if (source != (sequenceCommandLine_s *)0x0) {
    uVar2 = source->modifierBitField;
    if ((uVar2 & 2) != 0) {
      (destination->clientMessage).effect = (source->clientMessage).effect;
      uVar2 = source->modifierBitField;
    }
    if ((uVar2 & 8) != 0) {
      (destination->clientMessage).r1 = (source->clientMessage).r1;
      (destination->clientMessage).g1 = (source->clientMessage).g1;
      (destination->clientMessage).b1 = (source->clientMessage).b1;
      (destination->clientMessage).a1 = (source->clientMessage).a1;
      uVar2 = source->modifierBitField;
    }
    if ((uVar2 & 0x10) != 0) {
      (destination->clientMessage).r2 = (source->clientMessage).r2;
      (destination->clientMessage).g2 = (source->clientMessage).g2;
      (destination->clientMessage).b2 = (source->clientMessage).b2;
      (destination->clientMessage).a2 = (source->clientMessage).a2;
      uVar2 = source->modifierBitField;
    }
    if ((uVar2 & 4) != 0) {
      (destination->clientMessage).x = (source->clientMessage).x;
      (destination->clientMessage).y = (source->clientMessage).y;
      uVar2 = source->modifierBitField;
    }
    if ((uVar2 & 0x20) != 0) {
      (destination->clientMessage).fadein = (source->clientMessage).fadein;
      uVar2 = source->modifierBitField;
    }
    if ((uVar2 & 0x40) != 0) {
      (destination->clientMessage).fadeout = (source->clientMessage).fadeout;
      uVar2 = source->modifierBitField;
    }
    if ((uVar2 & 0x80) != 0) {
      (destination->clientMessage).holdtime = (source->clientMessage).holdtime;
      uVar2 = source->modifierBitField;
    }
    if ((uVar2 & 0x100) != 0) {
      (destination->clientMessage).fxtime = (source->clientMessage).fxtime;
      uVar2 = source->modifierBitField;
    }
    if ((uVar2 & 0x800) != 0) {
      destination->textChannel = source->textChannel;
      uVar2 = source->modifierBitField;
    }
    if ((uVar2 & 0x200) != 0) {
      if (destination->speakerName != (char *)0x0) {
        Mem_Free(destination->speakerName);
      }
      pcVar1 = Mem_Strdup(source->speakerName);
      destination->speakerName = pcVar1;
      uVar2 = source->modifierBitField;
    }
    if ((uVar2 & 0x400) != 0) {
      if (destination->listenerName != (char *)0x0) {
        Mem_Free(destination->listenerName);
      }
      pcVar1 = Mem_Strdup(source->listenerName);
      destination->listenerName = pcVar1;
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Attempt to bake defaults from a non-existant command.");
}


