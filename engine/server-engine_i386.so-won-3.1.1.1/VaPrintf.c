// VaPrintf__10CUtlBufferPCcPv  @ 000d8544
void VaPrintf__10CUtlBufferPCcPv(undefined4 param_1,char *param_2,__gnuc_va_list param_3)

{
  char cVar1;
  undefined4 uVar2;
  int local_808;
  char local_804 [2048];
  
  uVar2 = 0xd8554;
  local_808 = vsprintf(local_804,param_2,param_3);
  cVar1 = IsText__C10CUtlBuffer(param_1,param_2,param_3,uVar2);
  if (cVar1 == '\0') {
    local_808 = local_808 + 1;
  }
  Put__10CUtlBufferPCvi(param_1,local_804,local_808);
  return;
}


