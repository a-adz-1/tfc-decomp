// CreateBattleID__11CBasePlayer  @ 000faa4c
void CreateBattleID__11CBasePlayer(int *param_1)

{
  longdouble lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longdouble lVar4;
  
  if ((byte)((float)tfc_clanbattle._12_4_ < 0.0 |
             (byte)((ushort)((ushort)NAN((float)tfc_clanbattle._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)tfc_clanbattle._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    lVar4 = (longdouble)(*DAT_0019f80c)(0x41a00000,0x42200000);
    lVar1 = (longdouble)last_id;
    last_id = (float)(lVar4 + lVar1);
    param_1[0x7d] = (int)ROUND(lVar4 + lVar1);
    uVar2 = (*DAT_0019f848)(*(undefined4 *)(*param_1 + 0x208));
    uVar3 = UTIL_VarArgs__FPce(&DAT_001539b3,param_1[0x7d]);
    uVar2 = (*DAT_0019f7bc)(*(undefined4 *)(*param_1 + 0x208),uVar2,"tf_id",uVar3);
    (*DAT_0019f854)(uVar2);
    uVar2 = UTIL_dtos1__Fi(param_1[0x7d],0,0,0);
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Game_battleid",uVar2);
  }
  return;
}


