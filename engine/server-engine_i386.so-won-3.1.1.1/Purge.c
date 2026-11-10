// Purge__t10CUtlMemory1ZPQ212CInitTracker8InitFunc  @ 000da900
void Purge__t10CUtlMemory1ZPQ212CInitTracker8InitFunc(int *param_1)

{
  char cVar1;
  
  cVar1 = IsExternallyAllocated__Ct10CUtlMemory1ZPQ212CInitTracker8InitFunc(param_1);
  if (cVar1 == '\0') {
    if (*param_1 != 0) {
      free((void *)*param_1);
      *param_1 = 0;
    }
    param_1[1] = 0;
  }
  return;
}


// Purge__t10CUtlMemory1ZQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi6Node_t  @ 000dc130
void Purge__t10CUtlMemory1ZQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi6Node_t(int *param_1)

{
  char cVar1;
  
  cVar1 = IsExternallyAllocated__Ct10CUtlMemory1ZQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi6Node_t
                    (param_1);
  if (cVar1 == '\0') {
    if (*param_1 != 0) {
      free((void *)*param_1);
      *param_1 = 0;
    }
    param_1[1] = 0;
  }
  return;
}


// Purge__t10CUtlMemory1ZQ2t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi10ListElem_t  @ 000daefc
void Purge__t10CUtlMemory1ZQ2t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi10ListElem_t
               (int *param_1)

{
  char cVar1;
  
  cVar1 = IsExternallyAllocated__Ct10CUtlMemory1ZQ2t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi10ListElem_t
                    (param_1);
  if (cVar1 == '\0') {
    if (*param_1 != 0) {
      free((void *)*param_1);
      *param_1 = 0;
    }
    param_1[1] = 0;
  }
  return;
}


// Purge__t10CUtlMemory1ZUc  @ 000db300
void Purge__t10CUtlMemory1ZUc(int *param_1)

{
  char cVar1;
  
  cVar1 = IsExternallyAllocated__Ct10CUtlMemory1ZUc(param_1);
  if (cVar1 == '\0') {
    if (*param_1 != 0) {
      free((void *)*param_1);
      *param_1 = 0;
    }
    param_1[1] = 0;
  }
  return;
}


// Purge__t10CUtlVector1ZPQ212CInitTracker8InitFunc  @ 000daa3c
void Purge__t10CUtlVector1ZPQ212CInitTracker8InitFunc(undefined4 param_1)

{
  RemoveAll__t10CUtlVector1ZPQ212CInitTracker8InitFunc(param_1);
  Purge__t10CUtlMemory1ZPQ212CInitTracker8InitFunc(param_1);
  ResetDbgInfo__t10CUtlVector1ZPQ212CInitTracker8InitFunc(param_1);
  return;
}


