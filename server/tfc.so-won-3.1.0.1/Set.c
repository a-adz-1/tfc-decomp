// Set__7EHANDLEP7edict_s  @ 00086698
int Set__7EHANDLEP7edict_s(int *param_1,int param_2)

{
  *param_1 = param_2;
  if (param_2 != 0) {
    param_1[1] = *(int *)(param_2 + 4);
  }
  return param_2;
}


