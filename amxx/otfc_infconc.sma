// OTFC Infinite Concs: scouts and medics never run out of concussion grenades.
// Load it per map (configs/maps/plugins-<map>.ini) for conc practice. otfc_infconc 0 turns it off.
#include <amxmodx>
#include <engine>
#include <tfcx>

new g_on

public plugin_init()
{
	register_plugin("OTFC Infinite Concs", "0.1", "OfficialTFC")
	g_on = register_cvar("otfc_infconc", "1")
	set_task(0.2, "refill", _, _, _, "b")
}

public refill()
{
	if (!get_pcvar_num(g_on)) return
	new players[32], n
	get_players(players, n, "a")
	for (new i; i < n; i++)
	{
		new id = players[i], cls = entity_get_int(id, EV_INT_playerclass)
		// (the classes' own conc counts: scout 3, medic 2)
		new full = cls == TFC_PC_SCOUT ? 3 : cls == TFC_PC_MEDIC ? 2 : 0
		if (full && tfc_getbammo(id, TFC_AMMO_NADE2) < full) tfc_setbammo(id, TFC_AMMO_NADE2, full)
	}
}
