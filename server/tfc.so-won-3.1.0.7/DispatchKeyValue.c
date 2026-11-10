// DispatchKeyValue__FP7edict_sP14KeyValueData_s  @ 0008dde4
void DispatchKeyValue__FP7edict_sP14KeyValueData_s(int param_1,int *param_2)

{
  int iVar1;
  
  if ((param_2 != (int *)0x0) && (param_1 != 0)) {
    EntvarsKeyvalue__FP9entvars_sP14KeyValueData_s(param_1 + 0x80,param_2);
    if ((param_2[3] == 0) && ((*param_2 != 0 && (iVar1 = *(int *)(param_1 + 0x7c), iVar1 != 0)))) {
      (**(code **)(*(int *)(iVar1 + 0x444) + 0x14))(iVar1,param_2);
    }
  }
  return;
}


