// DetpackExplode__8CDetpack  @ 000a7a00
void DetpackExplode__8CDetpack(int *param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  float local_10;
  float local_c;
  float local_8;
  
  iVar5 = *(int *)(*param_1 + 0x178);
  if ((iVar5 == 0) && (iVar5 = (*DAT_001755d4)(0), iVar5 == 0)) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = *(int **)(iVar5 + 0xd8);
  }
  iVar5 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
  if (((iVar5 == -2) || (iVar5 == -6)) || (piVar6[0x1f] == 1)) {
    ClientPrint__FP9entvars_tiPCcN42(*piVar6,1,"#Detpack_fizzle",0,0,0,0);
  }
  else {
    UTIL_ClientPrintAll__FiPCcN41(1,"#FITH",0,0,0,0);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),1,"weapons/mortarhit.wav",0x3f800000,0x3f4ccccd,0,
               100);
    if (birthday != 0) {
      UTIL_ClientPrintAll__FiPCcN41
                (1,"#SpreadsCheer",*(int *)(*piVar6 + 0x1b0) + *(int *)(gpGlobals + 0x98),0,0,0);
    }
    iVar5 = *param_1;
    local_10 = *(float *)(iVar5 + 8) + 0.0;
    local_c = *(float *)(iVar5 + 0xc) + 0.0;
    local_8 = *(float *)(iVar5 + 0x10) + 16.0;
    piVar7 = (int *)0x0;
    while (piVar7 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                     (piVar7,&local_10,0x44bb8000), piVar7 != (int *)0x0) {
      iVar5 = (**(code **)(param_1[0xf2] + 0xd8))(param_1,piVar7);
      if (iVar5 != 0) {
        iVar5 = strcmp((char *)(*(int *)*piVar7 + *(int *)(gpGlobals + 0x98)),"info_tfgoal");
        if (iVar5 == 0) {
          if (((*(byte *)(piVar7 + 0x88) & 2) != 0) &&
             ((byte)((byte)((ushort)((ushort)NAN((float)piVar7[0x93]) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)piVar7[0x93] == 0.0) << 0xe) >> 8)) == 0x40)) {
            ActivateDoResults__FP11CBaseEntityP11CBasePlayerT0(piVar7,piVar6,piVar7);
          }
        }
        else {
          iVar5 = *piVar7;
          fVar1 = *(float *)(iVar5 + 0x14c);
          if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
             (iVar2 = *param_1, fVar1 = *(float *)(iVar5 + 8) - *(float *)(iVar2 + 8),
             fVar4 = *(float *)(iVar5 + 0xc) - *(float *)(iVar2 + 0xc),
             fVar3 = *(float *)(iVar5 + 0x10) - *(float *)(iVar2 + 0x10),
             SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar1 * fVar1) <= 700.0)) {
            fVar1 = *(float *)(iVar2 + 8) -
                    (*(float *)(*piVar7 + 8) +
                    (*(float *)(*piVar7 + 0xbc) + *(float *)(*piVar7 + 200)) * 0.5);
            fVar4 = *(float *)(iVar2 + 0xc) -
                    (*(float *)(*piVar7 + 0xc) +
                    (*(float *)(*piVar7 + 0xc0) + *(float *)(*piVar7 + 0xcc)) * 0.5);
            fVar3 = *(float *)(iVar2 + 0x10) -
                    (*(float *)(*piVar7 + 0x10) +
                    (*(float *)(*piVar7 + 0xc4) + *(float *)(*piVar7 + 0xd0)) * 0.5);
            fVar1 = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar1 * fVar1) * 0.5;
            if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
              fVar1 = 0.0;
            }
            fVar1 = 700.0 - fVar1;
            if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
              (**(code **)(piVar7[0xf2] + 0x34))(piVar7,*param_1,*piVar6,fVar1 + fVar1,0x40);
            }
          }
        }
      }
    }
    (*DAT_00175578)(5,0x17,*param_1 + 8,0);
    (*DAT_00175580)(3);
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 0x10));
    (*DAT_00175588)((int)g_sModelIndexFireball);
    (*DAT_00175580)(0x32);
    (*DAT_00175580)(0xf);
    (*DAT_00175580)(3);
    (*DAT_0017557c)();
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x43]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x43] == 1.0) << 0xe) >> 8)) == 0x40) {
    iVar5 = *(int *)(*param_1 + 0x170);
    if ((iVar5 == 0) && (iVar5 = (*DAT_001755d4)(0), iVar5 == 0)) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(iVar5 + 0xd8);
    }
    *(byte *)(iVar5 + 0x8a) = *(byte *)(iVar5 + 0x8a) & 0xfe;
    TeamFortress_SetSpeed__11CBasePlayer(iVar5);
    iVar5 = FindTimer__11CBaseEntityi(iVar5,10);
    if (iVar5 != 0) {
      dremove__FP11CBaseEntity(iVar5);
    }
  }
  if (param_1[0x18b] != 0) {
    dremove__FP11CBaseEntity(param_1[0x18b]);
  }
  dremove__FP11CBaseEntity(param_1);
  return;
}


