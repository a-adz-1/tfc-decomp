/* OTFC engine name: adds the engine to the server name when the server is started with
 *   +localinfo otfc_name_suffix "ReHLDS"
 * (the ReHLDS start lines do this). Applied a few seconds after each map starts, after every
 * config has run: FoxBot's map configs re-run server.cfg, which sets the name without it.
 * Server names are cut to 63 characters: " - " separators are dropped first, then it is cut.
 */
#include <amxmodx>

new g_suffix[32]

public plugin_init()
{
	register_plugin("OTFC engine name", "1.0", "OfficialTFC")
	get_localinfo("otfc_name_suffix", g_suffix, charsmax(g_suffix))
}

public plugin_cfg()
{
	if (g_suffix[0])
	{
		set_task(3.0, "apply")
		set_task(15.0, "apply")
	}
}

public apply()
{
	new name[64], len = strlen(g_suffix)
	get_cvar_string("hostname", name, charsmax(name))
	new nlen = strlen(name)
	// already there?
	if (nlen > len && equal(name[nlen - len], g_suffix))
		return
	// " ReHLDS" at the end; to fit 63 characters, first drop " - " separators, then cut
	new maxbase = 63 - len - 1
	while (strlen(name) > maxbase && replace(name, charsmax(name), " - ", " ")) {}
	if (strlen(name) > maxbase)
		name[maxbase] = 0
	trim(name)
	format(name, charsmax(name), "%s %s", name, g_suffix)
	set_cvar_string("hostname", name)
}
