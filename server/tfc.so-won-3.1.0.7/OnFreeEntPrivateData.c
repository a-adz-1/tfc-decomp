// OnFreeEntPrivateData__FP7edict_s  @ 0008e0ec
void OnFreeEntPrivateData__FP7edict_s(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x7c) != 0)) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x7c) + 0x444) + 8))(*(int *)(param_1 + 0x7c),2);
  }
  return;
}


