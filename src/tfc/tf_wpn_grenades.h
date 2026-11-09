/***
*
*	Team Fortress Classic: hand grenades
*
*	Reconstructed from tfc.so (legacy), DWARF-guided. Class layouts from
*	tools/gen_decls.py; inline bodies from the emitted out-of-line copies.
*
****/

#ifndef TF_WPN_GRENADES_H
#define TF_WPN_GRENADES_H

// original line 13
class CTFPrimeGrenade : public CGrenade
{
protected:
	float heat;			// time it goes off in the hand
	float blastRadius;

	void InitPriming(CBaseEntity *);
	static BOOL canPrime(CBaseEntity *);
public:
	virtual void Spawn();
	virtual void Precache();
	void GrenadePrimed();
	void ExplodeInHand();
	void Throw();
	void DeadThrow();
	virtual float getPrimeTime() { return 3.0; }
	virtual float getPinTime() { return 0.8; }
	virtual void setName() { pev->classname = MAKE_STRING( "tf_weapon_genericprimedgrenade" ); }
	virtual void setDamage() { pev->dmg = 180; }
	virtual void setRadius() { setDamage(); blastRadius = pev->dmg; }
	virtual void TakeEMPBlast(entvars_t *);
};

// original line 47
class CTFNormalGrenade : public CTFPrimeGrenade
{

public:
	virtual void Precache();
	static CGrenade * Prime(CBaseEntity *);
	virtual void Explode(TraceResult *, int);
	virtual void setName() { pev->classname = MAKE_STRING( "tf_weapon_normalgrenade" ); }
	virtual void setDamage() { pev->dmg = 180; }
	virtual void setRadius() { blastRadius = 180; }
};

// original line 67
class CTFEMPGrenade : public CTFPrimeGrenade
{
public:
	static int BlastTexture;

	virtual void Precache();
	static CGrenade * Prime(CBaseEntity *);
	virtual void Explode(TraceResult *, int);
	virtual void setName() { pev->classname = MAKE_STRING( "tf_weapon_empgrenade" ); }
	virtual void setDamage() { pev->dmg = 0; }
	virtual void setRadius() { blastRadius = 240; }
	virtual void setModel();
};

// original line 90
class CTFConcussionGrenade : public CTFPrimeGrenade
{
public:
	static int BlastTexture;

	virtual void Precache();
	static CGrenade * Prime(CBaseEntity *);
	virtual void Explode(TraceResult *, int);
	virtual void setName() { pev->classname = MAKE_STRING( "tf_weapon_concussiongrenade" ); }
	virtual void setDamage() { pev->dmg = 0; }
	virtual void setRadius() { blastRadius = 280; }
	virtual void setModel();
};

// original line 111
class CTFMirvGrenade : public CTFPrimeGrenade
{

public:
	virtual void Precache();
	static CGrenade * Prime(CBaseEntity *);
	virtual void Explode(TraceResult *, int);
	virtual void setName() { pev->classname = MAKE_STRING( "tf_weapon_mirvgrenade" ); deathtype = MAKE_STRING( "mirvgrenade" ); }
	virtual void setDamage() { pev->dmg = 180; }
	virtual void setRadius() { blastRadius = 180; }
	virtual void setModel();
};

// original line 125
class CTFBomblet : public CTFPrimeGrenade
{

public:
	virtual void setName() { pev->classname = MAKE_STRING( "tf_weapon_mirvbomblet" ); deathtype = MAKE_STRING( "mirvgrenade" ); }
	void LaunchFromMirv(CTFMirvGrenade *);
	virtual void setModel();
	virtual void Explode(TraceResult *, int);
};

// original line 140
class CTFNailGrenade : public CTFPrimeGrenade
{

public:
	virtual void Precache();
	static CGrenade * Prime(CBaseEntity *);
	virtual void Explode(TraceResult *, int);
	void NailGrenadeLaunchNail();
	void NailGrenadeNailEm();
	void FinishedExplode();
	virtual void setName() { pev->classname = MAKE_STRING( "tf_weapon_nailgrenade" ); }
	virtual void setModel();
};

// original line 167
class CTFNapalmGrenade : public CTFPrimeGrenade
{
protected:
	int numExplosionsLeft;
	int m_bitsDamageType;
	float m_flEffectTime;
	float m_flDamageTime;

public:
	virtual void Precache();
	static CGrenade * Prime(CBaseEntity *);
	virtual void Explode(TraceResult *, int);
	void Burn();
	virtual void setName() { pev->classname = MAKE_STRING( "tf_weapon_napalmgrenade" ); }
	virtual void setDamage() { pev->dmg = 20; }
	virtual void setRadius() { blastRadius = 180; }
	virtual void setModel();
};

// original line 197
class CTFGasGrenade : public CTFPrimeGrenade
{
protected:
	int gasCharges;

public:
	virtual void Precache();
	static CGrenade * Prime(CBaseEntity *);
	virtual void Explode(TraceResult *, int);
	void GasThePlace();
	virtual void setName() { pev->classname = MAKE_STRING( "tf_weapon_gasgrenade" ); }
	virtual void setDamage() { pev->dmg = 10; }
	virtual void setRadius() { blastRadius = 240; }
	virtual void setModel();
};

// original line 219
class CTFCaltropGrenade : public CTFPrimeGrenade
{

public:
	virtual void Precache();
	virtual void setDamage() { pev->dmg = 0; }
	void InitPriming(CBaseEntity *);
	virtual float getPrimeTime() { return 0.5; }
	static CGrenade * Prime(CBaseEntity *);
	virtual void Explode(TraceResult *, int);
	void CaltropGrenadePrimed();
	virtual void setName() { pev->classname = MAKE_STRING( "tf_weapon_caltropgrenade" ); }
	virtual void setModel();
	virtual void TakeEMPBlast(entvars_t *);
};

// original line 244
class CTFCaltrop : public CBaseEntity
{
public:
	float m_flRemovalTime;

	virtual void Precache();
	void ScatterDrop(CBaseEntity *);
	void CaltropTouch(CBaseEntity *);
	void CanisterTouch(CBaseEntity *);
	void CaltropScatterThink();
	void setName();
	void setModel();
	void setDamage();
};

#endif // TF_WPN_GRENADES_H
