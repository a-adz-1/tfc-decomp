// DoSpark__FP9entvars_sRC6Vector  @ 0008b124
void DoSpark__FP9entvars_sRC6Vector(int param_1,float *param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  longdouble lVar3;
  longdouble lVar4;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = *(float *)(param_1 + 0xf4) * 0.5 + *param_2;
  local_c = *(float *)(param_1 + 0xf8) * 0.5 + param_2[1];
  local_8 = *(float *)(param_1 + 0xfc) * 0.5 + param_2[2];
  UTIL_Sparks__FRC6Vector(&local_10);
  lVar3 = (longdouble)(*DAT_0019f80c)(0x3e800000,0x3f400000);
  lVar4 = (longdouble)(*DAT_0019f80c)(0,0x3f800000);
  switch((int)ROUND((longdouble)6.0 * lVar4)) {
  case 0:
    uVar2 = *(undefined4 *)(param_1 + 0x208);
    pcVar1 = "buttons/spark1.wav";
    break;
  case 1:
    uVar2 = *(undefined4 *)(param_1 + 0x208);
    pcVar1 = "buttons/spark2.wav";
    break;
  case 2:
    uVar2 = *(undefined4 *)(param_1 + 0x208);
    pcVar1 = "buttons/spark3.wav";
    break;
  case 3:
    uVar2 = *(undefined4 *)(param_1 + 0x208);
    pcVar1 = "buttons/spark4.wav";
    break;
  case 4:
    uVar2 = *(undefined4 *)(param_1 + 0x208);
    pcVar1 = "buttons/spark5.wav";
    break;
  case 5:
    uVar2 = *(undefined4 *)(param_1 + 0x208);
    pcVar1 = "buttons/spark6.wav";
    break;
  default:
    goto switchD_0008b207_default;
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (uVar2,2,pcVar1,(float)((longdouble)0.4 * lVar3),0x3f4ccccd,0,100);
switchD_0008b207_default:
  return;
}


