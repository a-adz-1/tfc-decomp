// CreateBattleID__11CBasePlayer  @ 000f45f0
void CreateBattleID__11CBasePlayer(int *param_1)

{
  longdouble lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longdouble lVar4;
  
  lVar4 = (longdouble)(*DAT_0017562c)(0x41a00000,0x42200000);
  lVar1 = (longdouble)last_id;
  last_id = (float)(lVar4 + lVar1);
  param_1[0x7d] = (int)ROUND(lVar4 + lVar1);
  uVar2 = (*DAT_00175668)(*(undefined4 *)(*param_1 + 0x1e8));
  uVar3 = UTIL_VarArgs__FPce(&DAT_0013f473,param_1[0x7d]);
  uVar2 = (*DAT_001755dc)(*(undefined4 *)(*param_1 + 0x1e8),uVar2,"tf_id",uVar3);
  (*DAT_00175674)(uVar2);
  uVar2 = UTIL_dtos1__Fi(param_1[0x7d],0,0,0);
  ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Game_battleid",uVar2);
  return;
}


