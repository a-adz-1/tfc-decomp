// InitDBFormat__Fv  @ 00098db4
void InitDBFormat__Fv(void)

{
  if (g_pDB != (int *)0x0) {
    g_hLevel = (**(code **)(*g_pDB + 0x20))
                         (g_pDB,"Level",4,"LevelName",0,&g_hLevel_LevelName,"GameLength",1,
                          &g_hLevel_GameLength,"WinningTeam",1,&g_hLevel_WinningTeam,"NumClients",1,
                          &g_hLevel_NumClients);
    g_hLevelClass =
         (**(code **)(*g_pDB + 0x20))
                   (g_pDB,"LevelClass",3,"ClassName",0,&g_hLevelClass_ClassName,"ClassPercent",1,
                    &g_hLevelClass_ClassPercent,"Parent",2,&g_hLevelClass_Parent);
    g_hLevelArea = (**(code **)(*g_pDB + 0x20))
                             (g_pDB,"LevelArea",2,"AreaName",0,&g_hLevelArea_AreaName,"Parent",2,
                              &g_hLevelArea_Parent);
    g_hLevelAreaClass =
         (**(code **)(*g_pDB + 0x20))
                   (g_pDB,"LevelAreaClass",5,"ClassName",0,&g_hLevelAreaClass_ClassName,"Parent",2,
                    &g_hLevelAreaClass_Parent,"DeathCount",1,&g_hLevelAreaClass_DeathCount,
                    "PingTime",1,&g_hLevelAreaClass_PingTime,"TimeInArea",1,
                    &g_hLevelAreaClass_TimeInArea);
    g_hLevelAreaClassWeapon =
         (**(code **)(*g_pDB + 0x20))
                   (g_pDB,"LevelAreaClassWeapon",3,"WeaponName",0,
                    &g_hLevelAreaClassWeapon_WeaponName,"Parent",2,&g_hLevelAreaClassWeapon_Parent,
                    "NumShotsFired",1,&g_hLevelAreaClassWeapon_NumShotsFired);
    g_hLevelAreaClassWeaponDamage =
         (**(code **)(*g_pDB + 0x20))
                   (g_pDB,"LevelAreaClassWeaponDamage",4,"DamagedClassName",0,
                    &g_hLevelAreaClassWeaponDamage_DamagedClassName,"Parent",2,
                    &g_hLevelAreaClassWeaponDamage_Parent,"DamageInflicted",1,
                    &g_hLevelAreaClassWeaponDamage_DamageInflicted,"Kills",1,
                    &g_hLevelAreaClassWeaponDamage_Kills);
  }
  return;
}


