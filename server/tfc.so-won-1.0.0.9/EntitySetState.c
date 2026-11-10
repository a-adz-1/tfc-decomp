// EntitySetState__12CGlobalStatei12GLOBALESTATE  @ 0011d540
void EntitySetState__12CGlobalStatei12GLOBALESTATE
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = Find__12CGlobalStatei(param_1,param_2);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x60) = param_3;
  }
  return;
}


