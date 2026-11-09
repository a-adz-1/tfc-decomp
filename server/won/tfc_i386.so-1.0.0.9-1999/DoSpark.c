// DoSpark__FP9entvars_tRC6Vector  @ 0009e720
void DoSpark__FP9entvars_tRC6Vector(int param_1,float *param_2)

{
  undefined4 uVar1;
  longdouble lVar2;
  longdouble lVar3;
  char *pcVar4;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = *param_2 + *(float *)(param_1 + 0xd4) * 0.5;
  local_c = param_2[1] + *(float *)(param_1 + 0xd8) * 0.5;
  local_8 = param_2[2] + *(float *)(param_1 + 0xdc) * 0.5;
  UTIL_Sparks__FRC6Vector(&local_10);
  lVar2 = (longdouble)(*DAT_0017562c)(0x3e800000,0x3f400000);
  lVar3 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
  switch((int)ROUND((longdouble)6.0 * lVar3)) {
  case 0:
    uVar1 = *(undefined4 *)(param_1 + 0x1e8);
    pcVar4 = "buttons/spark1.wav";
    break;
  case 1:
    uVar1 = *(undefined4 *)(param_1 + 0x1e8);
    pcVar4 = "buttons/spark2.wav";
    break;
  case 2:
    uVar1 = *(undefined4 *)(param_1 + 0x1e8);
    pcVar4 = "buttons/spark3.wav";
    break;
  case 3:
    uVar1 = *(undefined4 *)(param_1 + 0x1e8);
    pcVar4 = "buttons/spark4.wav";
    break;
  case 4:
    uVar1 = *(undefined4 *)(param_1 + 0x1e8);
    pcVar4 = "buttons/spark5.wav";
    break;
  case 5:
    uVar1 = *(undefined4 *)(param_1 + 0x1e8);
    pcVar4 = "buttons/spark6.wav";
    break;
  default:
    goto switchD_0009e7d5_default;
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (uVar1,2,pcVar4,(float)((longdouble)0.4 * lVar2),0x3f4ccccd,0,100);
switchD_0009e7d5_default:
  return;
}


