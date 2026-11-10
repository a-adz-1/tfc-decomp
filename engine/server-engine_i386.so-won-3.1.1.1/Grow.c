// Grow__t10CUtlMemory1ZPQ212CInitTracker8InitFunci  @ 000daa94
void Grow__t10CUtlMemory1ZPQ212CInitTracker8InitFunci(int *param_1,int param_2)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  
  cVar1 = IsExternallyAllocated__Ct10CUtlMemory1ZPQ212CInitTracker8InitFunc(param_1);
  if ((cVar1 == '\0') || (param_2 < 1)) {
    if (param_2 < 1) {
      param_2 = param_1[2];
    }
    if (param_2 == 0) {
      if (param_1[1] == 0) {
        iVar3 = param_1[1] + 1;
      }
      else {
        iVar3 = param_1[1] + param_1[1];
      }
      param_1[1] = iVar3;
    }
    else {
      param_1[1] = param_1[1] + param_2;
    }
    if (*param_1 == 0) {
      pvVar2 = malloc(param_1[1] * 4);
      *param_1 = (int)pvVar2;
    }
    else {
      pvVar2 = realloc((void *)*param_1,param_1[1] * 4);
      *param_1 = (int)pvVar2;
    }
  }
  return;
}


// Grow__t10CUtlMemory1ZQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi6Node_ti  @ 000dd438
void Grow__t10CUtlMemory1ZQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi6Node_ti
               (int *param_1,int param_2)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  
  cVar1 = IsExternallyAllocated__Ct10CUtlMemory1ZQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi6Node_t
                    (param_1);
  if ((cVar1 == '\0') || (param_2 < 1)) {
    if (param_2 < 1) {
      param_2 = param_1[2];
    }
    if (param_2 == 0) {
      if (param_1[1] == 0) {
        iVar3 = param_1[1] + 1;
      }
      else {
        iVar3 = param_1[1] + param_1[1];
      }
      param_1[1] = iVar3;
    }
    else {
      param_1[1] = param_1[1] + param_2;
    }
    if (*param_1 == 0) {
      pvVar2 = malloc(param_1[1] * 0x1c);
      *param_1 = (int)pvVar2;
    }
    else {
      pvVar2 = realloc((void *)*param_1,param_1[1] * 0x1c);
      *param_1 = (int)pvVar2;
    }
  }
  return;
}


// Grow__t10CUtlMemory1ZQ2t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi10ListElem_ti  @ 000db61c
void Grow__t10CUtlMemory1ZQ2t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi10ListElem_ti
               (int *param_1,int param_2)

{
  char cVar1;
  void *pvVar2;
  
  cVar1 = IsExternallyAllocated__Ct10CUtlMemory1ZQ2t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi10ListElem_t
                    (param_1);
  if ((cVar1 == '\0') || (param_2 < 1)) {
    if (param_2 < 1) {
      param_2 = param_1[2];
    }
    if (param_2 == 0) {
      if (param_1[1] != 0) {
        FUN_000db68c();
        return;
      }
      param_1[1] = param_1[1] + 1;
    }
    else {
      param_1[1] = param_1[1] + param_2;
    }
    if (*param_1 == 0) {
      pvVar2 = malloc(param_1[1] << 5);
      *param_1 = (int)pvVar2;
    }
    else {
      pvVar2 = realloc((void *)*param_1,param_1[1] << 5);
      *param_1 = (int)pvVar2;
    }
  }
  return;
}


// Grow__t10CUtlMemory1ZUci  @ 000df368
void Grow__t10CUtlMemory1ZUci(int *param_1,int param_2)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  
  cVar1 = IsExternallyAllocated__Ct10CUtlMemory1ZUc(param_1);
  if ((cVar1 == '\0') || (param_2 < 1)) {
    if (param_2 < 1) {
      param_2 = param_1[2];
    }
    if (param_2 == 0) {
      if (param_1[1] == 0) {
        iVar3 = param_1[1] + 1;
      }
      else {
        iVar3 = param_1[1] + param_1[1];
      }
      param_1[1] = iVar3;
    }
    else {
      param_1[1] = param_1[1] + param_2;
    }
    if (*param_1 == 0) {
      pvVar2 = malloc(param_1[1]);
      *param_1 = (int)pvVar2;
    }
    else {
      pvVar2 = realloc((void *)*param_1,param_1[1]);
      *param_1 = (int)pvVar2;
    }
  }
  return;
}


