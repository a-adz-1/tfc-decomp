struct _IO_FILE {
	int                        _flags;               /*     0     4 */
	char *                     _IO_read_ptr;         /*     4     4 */
	char *                     _IO_read_end;         /*     8     4 */
	char *                     _IO_read_base;        /*    12     4 */
	char *                     _IO_write_base;       /*    16     4 */
	char *                     _IO_write_ptr;        /*    20     4 */
	char *                     _IO_write_end;        /*    24     4 */
	char *                     _IO_buf_base;         /*    28     4 */
	char *                     _IO_buf_end;          /*    32     4 */
	char *                     _IO_save_base;        /*    36     4 */
	char *                     _IO_backup_base;      /*    40     4 */
	char *                     _IO_save_end;         /*    44     4 */
	class _IO_marker *         _markers;             /*    48     4 */
	class _IO_FILE *           _chain;               /*    52     4 */
	int                        _fileno;              /*    56     4 */
	int                        _flags2;              /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	__off_t                    _old_offset;          /*    64     4 */
	short unsigned int         _cur_column;          /*    68     2 */
	signed char                _vtable_offset;       /*    70     1 */
	char                       _shortbuf[1];         /*    71     1 */
	_IO_lock_t *               _lock;                /*    72     4 */
	__off64_t                  _offset;              /*    76     8 */
	void *                     __pad1;               /*    84     4 */
	void *                     __pad2;               /*    88     4 */
	void *                     __pad3;               /*    92     4 */
	void *                     __pad4;               /*    96     4 */
	size_t                     __pad5;               /*   100     4 */
	int                        _mode;                /*   104     4 */
	char                       _unused2[40];         /*   108    40 */

	/* size: 148, cachelines: 3, members: 29 */
	/* last cacheline: 20 bytes */
} __attribute__((__packed__));
struct _IO_marker {
	class _IO_marker *         _next;                /*     0     4 */
	class _IO_FILE *           _sbuf;                /*     4     4 */
	int                        _pos;                 /*     8     4 */

	/* size: 12, cachelines: 1, members: 3 */
	/* last cacheline: 12 bytes */
};
class Vector2D {
	vec_t                      x;                    /*     0     4 */
	vec_t                      y;                    /*     4     4 */
	void Vector2D(class Vector2D *); /* linkage=_ZN8Vector2DC4Ev */

	void Vector2D(class Vector2D *, float, float); /* linkage=_ZN8Vector2DC4Eff */

	class Vector2D operator+(const class Vector2D  *, const class Vector2D  &); /* linkage=_ZNK8Vector2DplERKS_ */

	class Vector2D operator-(const class Vector2D  *, const class Vector2D  &); /* linkage=_ZNK8Vector2DmiERKS_ */

	class Vector2D operator*(const class Vector2D  *, float); /* linkage=_ZNK8Vector2DmlEf */

	class Vector2D operator/(const class Vector2D  *, float); /* linkage=_ZNK8Vector2DdvEf */

	float Length(const class Vector2D  *); /* linkage=_ZNK8Vector2D6LengthEv */

	class Vector2D Normalize(const class Vector2D  *); /* linkage=_ZNK8Vector2D9NormalizeEv */


	/* size: 8, cachelines: 1, members: 2 */
	/* last cacheline: 8 bytes */
};
class Vector {
	vec_t                      x;                    /*     0     4 */
	vec_t                      y;                    /*     4     4 */
	vec_t                      z;                    /*     8     4 */
	void Vector(class Vector *); /* linkage=_ZN6VectorC4Ev */

	void Vector(class Vector *, float, float, float); /* linkage=_ZN6VectorC4Efff */

	void Vector(class Vector *, const class Vector  &); /* linkage=_ZN6VectorC4ERKS_ */

	void Vector(class Vector *, float *); /* linkage=_ZN6VectorC4EPf */

	class Vector operator-(const class Vector  *); /* linkage=_ZNK6VectorngEv */

	int operator==(const class Vector  *, const class Vector  &); /* linkage=_ZNK6VectoreqERKS_ */

	int operator!=(const class Vector  *, const class Vector  &); /* linkage=_ZNK6VectorneERKS_ */

	class Vector operator+(const class Vector  *, const class Vector  &); /* linkage=_ZNK6VectorplERKS_ */

	class Vector operator-(const class Vector  *, const class Vector  &); /* linkage=_ZNK6VectormiERKS_ */

	class Vector operator*(const class Vector  *, float); /* linkage=_ZNK6VectormlEf */

	class Vector operator/(const class Vector  *, float); /* linkage=_ZNK6VectordvEf */

	void CopyToArray(const class Vector  *, float *); /* linkage=_ZNK6Vector11CopyToArrayEPf */

	float Length(const class Vector  *); /* linkage=_ZNK6Vector6LengthEv */

	float * operator float*(class Vector *); /* linkage=_ZN6VectorcvPfEv */

	const float  * operator float const*(const class Vector  *); /* linkage=_ZNK6VectorcvPKfEv */

	class Vector Normalize(const class Vector  *); /* linkage=_ZNK6Vector9NormalizeEv */

	class Vector2D Make2D(const class Vector  *); /* linkage=_ZNK6Vector6Make2DEv */

	float Length2D(const class Vector  *); /* linkage=_ZNK6Vector8Length2DEv */


	/* size: 12, cachelines: 1, members: 3 */
	/* last cacheline: 12 bytes */
};
struct link_s {
	class link_s *             prev;                 /*     0     4 */
	class link_s *             next;                 /*     4     4 */

	/* size: 8, cachelines: 1, members: 2 */
	/* last cacheline: 8 bytes */
};
struct edict_s {
	qboolean                   free;                 /*     0     4 */
	int                        serialnumber;         /*     4     4 */
	link_t                     area;                 /*     8     8 */
	int                        headnode;             /*    16     4 */
	int                        num_leafs;            /*    20     4 */
	short int                  leafnums[48];         /*    24    96 */
	/* --- cacheline 1 boundary (64 bytes) was 56 bytes ago --- */
	float                      freetime;             /*   120     4 */
	void *                     pvPrivateData;        /*   124     4 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	entvars_t                  v;                    /*   128   676 */
	void edict_s(class edict_s *); /* linkage=_ZN7edict_sC4Ev */


	/* size: 804, cachelines: 13, members: 9 */
	/* last cacheline: 36 bytes */
};
struct entvars_s {
	string_t                   classname;            /*     0     4 */
	string_t                   globalname;           /*     4     4 */
	class Vector              origin;                /*     8    12 */
	class Vector              oldorigin;             /*    20    12 */
	class Vector              velocity;              /*    32    12 */
	class Vector              basevelocity;          /*    44    12 */
	class Vector              clbasevelocity;        /*    56    12 */
	/* --- cacheline 1 boundary (64 bytes) was 4 bytes ago --- */
	class Vector              movedir;               /*    68    12 */
	class Vector              angles;                /*    80    12 */
	class Vector              avelocity;             /*    92    12 */
	class Vector              punchangle;            /*   104    12 */
	class Vector              v_angle;               /*   116    12 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	class Vector              endpos;                /*   128    12 */
	class Vector              startpos;              /*   140    12 */
	float                      impacttime;           /*   152     4 */
	float                      starttime;            /*   156     4 */
	int                        fixangle;             /*   160     4 */
	float                      idealpitch;           /*   164     4 */
	float                      pitch_speed;          /*   168     4 */
	float                      ideal_yaw;            /*   172     4 */
	float                      yaw_speed;            /*   176     4 */
	int                        modelindex;           /*   180     4 */
	string_t                   model;                /*   184     4 */
	int                        viewmodel;            /*   188     4 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	int                        weaponmodel;          /*   192     4 */
	class Vector              absmin;                /*   196    12 */
	class Vector              absmax;                /*   208    12 */
	class Vector              mins;                  /*   220    12 */
	class Vector              maxs;                  /*   232    12 */
	class Vector              size;                  /*   244    12 */
	/* --- cacheline 4 boundary (256 bytes) --- */
	float                      ltime;                /*   256     4 */
	float                      nextthink;            /*   260     4 */
	int                        movetype;             /*   264     4 */
	int                        solid;                /*   268     4 */
	int                        skin;                 /*   272     4 */
	int                        body;                 /*   276     4 */
	int                        effects;              /*   280     4 */
	float                      gravity;              /*   284     4 */
	float                      friction;             /*   288     4 */
	int                        light_level;          /*   292     4 */
	int                        sequence;             /*   296     4 */
	int                        gaitsequence;         /*   300     4 */
	float                      frame;                /*   304     4 */
	float                      animtime;             /*   308     4 */
	float                      framerate;            /*   312     4 */
	byte                       controller[4];        /*   316     4 */
	/* --- cacheline 5 boundary (320 bytes) --- */
	byte                       blending[2];          /*   320     2 */

	/* XXX 2 bytes hole, try to pack */

	float                      scale;                /*   324     4 */
	int                        rendermode;           /*   328     4 */
	float                      renderamt;            /*   332     4 */
	class Vector              rendercolor;           /*   336    12 */
	int                        renderfx;             /*   348     4 */
	float                      health;               /*   352     4 */
	float                      frags;                /*   356     4 */
	int                        weapons;              /*   360     4 */
	float                      takedamage;           /*   364     4 */
	int                        deadflag;             /*   368     4 */
	class Vector              view_ofs;              /*   372    12 */
	/* --- cacheline 6 boundary (384 bytes) --- */
	int                        button;               /*   384     4 */
	int                        impulse;              /*   388     4 */
	edict_t *                  chain;                /*   392     4 */
	edict_t *                  dmg_inflictor;        /*   396     4 */
	edict_t *                  enemy;                /*   400     4 */
	edict_t *                  aiment;               /*   404     4 */
	edict_t *                  owner;                /*   408     4 */
	edict_t *                  groundentity;         /*   412     4 */
	int                        spawnflags;           /*   416     4 */
	int                        flags;                /*   420     4 */
	int                        colormap;             /*   424     4 */
	int                        team;                 /*   428     4 */
	float                      max_health;           /*   432     4 */
	float                      teleport_time;        /*   436     4 */
	float                      armortype;            /*   440     4 */
	float                      armorvalue;           /*   444     4 */
	/* --- cacheline 7 boundary (448 bytes) --- */
	int                        waterlevel;           /*   448     4 */
	int                        watertype;            /*   452     4 */
	string_t                   target;               /*   456     4 */
	string_t                   targetname;           /*   460     4 */
	string_t                   netname;              /*   464     4 */
	string_t                   message;              /*   468     4 */
	float                      dmg_take;             /*   472     4 */
	float                      dmg_save;             /*   476     4 */
	float                      dmg;                  /*   480     4 */
	float                      dmgtime;              /*   484     4 */
	string_t                   noise;                /*   488     4 */
	string_t                   noise1;               /*   492     4 */
	string_t                   noise2;               /*   496     4 */
	string_t                   noise3;               /*   500     4 */
	float                      speed;                /*   504     4 */
	float                      air_finished;         /*   508     4 */
	/* --- cacheline 8 boundary (512 bytes) --- */
	float                      pain_finished;        /*   512     4 */
	float                      radsuit_finished;     /*   516     4 */
	edict_t *                  pContainingEntity;    /*   520     4 */
	int                        playerclass;          /*   524     4 */
	float                      maxspeed;             /*   528     4 */
	float                      fov;                  /*   532     4 */
	int                        weaponanim;           /*   536     4 */
	int                        pushmsec;             /*   540     4 */
	int                        bInDuck;              /*   544     4 */
	int                        flTimeStepSound;      /*   548     4 */
	int                        flSwimTime;           /*   552     4 */
	int                        flDuckTime;           /*   556     4 */
	int                        iStepLeft;            /*   560     4 */
	float                      flFallVelocity;       /*   564     4 */
	int                        gamestate;            /*   568     4 */
	int                        oldbuttons;           /*   572     4 */
	/* --- cacheline 9 boundary (576 bytes) --- */
	int                        groupinfo;            /*   576     4 */
	int                        iuser1;               /*   580     4 */
	int                        iuser2;               /*   584     4 */
	int                        iuser3;               /*   588     4 */
	int                        iuser4;               /*   592     4 */
	float                      fuser1;               /*   596     4 */
	float                      fuser2;               /*   600     4 */
	float                      fuser3;               /*   604     4 */
	float                      fuser4;               /*   608     4 */
	class Vector              vuser1;                /*   612    12 */
	class Vector              vuser2;                /*   624    12 */
	class Vector              vuser3;                /*   636    12 */
	/* --- cacheline 10 boundary (640 bytes) was 8 bytes ago --- */
	class Vector              vuser4;                /*   648    12 */
	edict_t *                  euser1;               /*   660     4 */
	edict_t *                  euser2;               /*   664     4 */
	edict_t *                  euser3;               /*   668     4 */
	edict_t *                  euser4;               /*   672     4 */
	void entvars_s(class entvars_s *); /* linkage=_ZN9entvars_sC4Ev */


	/* size: 676, cachelines: 11, members: 123 */
	/* sum members: 674, holes: 1, sum holes: 2 */
	/* last cacheline: 36 bytes */
};
struct cvar_s {
	char *                     name;                 /*     0     4 */
	char *                     string;               /*     4     4 */
	int                        flags;                /*     8     4 */
	float                      value;                /*    12     4 */
	class cvar_s *             next;                 /*    16     4 */

	/* size: 20, cachelines: 1, members: 5 */
	/* last cacheline: 20 bytes */
};
struct client_textmessage_s {
	int                        effect;               /*     0     4 */
	byte                       r1;                   /*     4     1 */
	byte                       g1;                   /*     5     1 */
	byte                       b1;                   /*     6     1 */
	byte                       a1;                   /*     7     1 */
	byte                       r2;                   /*     8     1 */
	byte                       g2;                   /*     9     1 */
	byte                       b2;                   /*    10     1 */
	byte                       a2;                   /*    11     1 */
	float                      x;                    /*    12     4 */
	float                      y;                    /*    16     4 */
	float                      fadein;               /*    20     4 */
	float                      fadeout;              /*    24     4 */
	float                      holdtime;             /*    28     4 */
	float                      fxtime;               /*    32     4 */
	const char  *              pName;                /*    36     4 */
	const char  *              pMessage;             /*    40     4 */

	/* size: 44, cachelines: 1, members: 17 */
	/* last cacheline: 44 bytes */
};
struct sequenceCommandLine_ {
	int                        commandType;          /*     0     4 */
	client_textmessage_t       clientMessage;        /*     4    44 */
	char *                     speakerName;          /*    48     4 */
	char *                     listenerName;         /*    52     4 */
	char *                     soundFileName;        /*    56     4 */
	char *                     sentenceName;         /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	char *                     fireTargetNames;      /*    64     4 */
	char *                     killTargetNames;      /*    68     4 */
	float                      delay;                /*    72     4 */
	int                        repeatCount;          /*    76     4 */
	int                        textChannel;          /*    80     4 */
	int                        modifierBitField;     /*    84     4 */
	sequenceCommandLine_s *    nextCommandLine;      /*    88     4 */

	/* size: 92, cachelines: 2, members: 13 */
	/* last cacheline: 28 bytes */
};
struct sequenceEntry_ {
	char *                     fileName;             /*     0     4 */
	char *                     entryName;            /*     4     4 */
	sequenceCommandLine_s *    firstCommand;         /*     8     4 */
	sequenceEntry_s *          nextEntry;            /*    12     4 */
	qboolean                   isGlobal;             /*    16     4 */

	/* size: 20, cachelines: 1, members: 5 */
	/* last cacheline: 20 bytes */
};
struct sentenceEntry_ {
	char *                     data;                 /*     0     4 */
	sentenceEntry_s *          nextEntry;            /*     4     4 */
	qboolean                   isGlobal;             /*     8     4 */
	unsigned int               index;                /*    12     4 */

	/* size: 16, cachelines: 1, members: 4 */
	/* last cacheline: 16 bytes */
};
struct enginefuncs_s {
	int                        (*pfnPrecacheModel)(char *); /*     0     4 */
	int                        (*pfnPrecacheSound)(char *); /*     4     4 */
	void                       (*pfnSetModel)(edict_t *, const char  *); /*     8     4 */
	int                        (*pfnModelIndex)(const char  *); /*    12     4 */
	int                        (*pfnModelFrames)(int); /*    16     4 */
	void                       (*pfnSetSize)(edict_t *, const float  *, const float  *); /*    20     4 */
	void                       (*pfnChangeLevel)(char *, char *); /*    24     4 */
	void                       (*pfnGetSpawnParms)(edict_t *); /*    28     4 */
	void                       (*pfnSaveSpawnParms)(edict_t *); /*    32     4 */
	float                      (*pfnVecToYaw)(const float  *); /*    36     4 */
	void                       (*pfnVecToAngles)(const float  *, float *); /*    40     4 */
	void                       (*pfnMoveToOrigin)(edict_t *, const float  *, float, int); /*    44     4 */
	void                       (*pfnChangeYaw)(edict_t *); /*    48     4 */
	void                       (*pfnChangePitch)(edict_t *); /*    52     4 */
	edict_t *                  (*pfnFindEntityByString)(edict_t *, const char  *, const char  *); /*    56     4 */
	int                        (*pfnGetEntityIllum)(edict_t *); /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	edict_t *                  (*pfnFindEntityInSphere)(edict_t *, const float  *, float); /*    64     4 */
	edict_t *                  (*pfnFindClientInPVS)(edict_t *); /*    68     4 */
	edict_t *                  (*pfnEntitiesInPVS)(edict_t *); /*    72     4 */
	void                       (*pfnMakeVectors)(const float  *); /*    76     4 */
	void                       (*pfnAngleVectors)(const float  *, float *, float *, float *); /*    80     4 */
	edict_t *                  (*pfnCreateEntity)(void); /*    84     4 */
	void                       (*pfnRemoveEntity)(edict_t *); /*    88     4 */
	edict_t *                  (*pfnCreateNamedEntity)(int); /*    92     4 */
	void                       (*pfnMakeStatic)(edict_t *); /*    96     4 */
	int                        (*pfnEntIsOnFloor)(edict_t *); /*   100     4 */
	int                        (*pfnDropToFloor)(edict_t *); /*   104     4 */
	int                        (*pfnWalkMove)(edict_t *, float, float, int); /*   108     4 */
	void                       (*pfnSetOrigin)(edict_t *, const float  *); /*   112     4 */
	void                       (*pfnEmitSound)(edict_t *, int, const char  *, float, float, int, int); /*   116     4 */
	void                       (*pfnEmitAmbientSound)(edict_t *, float *, const char  *, float, float, int, int); /*   120     4 */
	void                       (*pfnTraceLine)(const float  *, const float  *, int, edict_t *, class  *); /*   124     4 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	void                       (*pfnTraceToss)(edict_t *, edict_t *, class  *); /*   128     4 */
	int                        (*pfnTraceMonsterHull)(edict_t *, const float  *, const float  *, int, edict_t *, class  *); /*   132     4 */
	void                       (*pfnTraceHull)(const float  *, const float  *, int, int, edict_t *, class  *); /*   136     4 */
	void                       (*pfnTraceModel)(const float  *, const float  *, int, edict_t *, class  *); /*   140     4 */
	const char  *              (*pfnTraceTexture)(edict_t *, const float  *, const float  *); /*   144     4 */
	void                       (*pfnTraceSphere)(const float  *, const float  *, int, float, edict_t *, class  *); /*   148     4 */
	void                       (*pfnGetAimVector)(edict_t *, float, float *); /*   152     4 */
	void                       (*pfnServerCommand)(char *); /*   156     4 */
	void                       (*pfnServerExecute)(void); /*   160     4 */
	void                       (*pfnClientCommand)(edict_t *, char *, ...); /*   164     4 */
	void                       (*pfnParticleEffect)(const float  *, const float  *, float, float); /*   168     4 */
	void                       (*pfnLightStyle)(int, char *); /*   172     4 */
	int                        (*pfnDecalIndex)(const char  *); /*   176     4 */
	int                        (*pfnPointContents)(const float  *); /*   180     4 */
	void                       (*pfnMessageBegin)(int, int, const float  *, edict_t *); /*   184     4 */
	void                       (*pfnMessageEnd)(void); /*   188     4 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	void                       (*pfnWriteByte)(int); /*   192     4 */
	void                       (*pfnWriteChar)(int); /*   196     4 */
	void                       (*pfnWriteShort)(int); /*   200     4 */
	void                       (*pfnWriteLong)(int); /*   204     4 */
	void                       (*pfnWriteAngle)(float); /*   208     4 */
	void                       (*pfnWriteCoord)(float); /*   212     4 */
	void                       (*pfnWriteString)(const char  *); /*   216     4 */
	void                       (*pfnWriteEntity)(int); /*   220     4 */
	void                       (*pfnCVarRegister)(cvar_t *); /*   224     4 */
	float                      (*pfnCVarGetFloat)(const char  *); /*   228     4 */
	const char  *              (*pfnCVarGetString)(const char  *); /*   232     4 */
	void                       (*pfnCVarSetFloat)(const char  *, float); /*   236     4 */
	void                       (*pfnCVarSetString)(const char  *, const char  *); /*   240     4 */
	void                       (*pfnAlertMessage)(ALERT_TYPE, char *, ...); /*   244     4 */
	void                       (*pfnEngineFprintf)(void *, char *, ...); /*   248     4 */
	void *                     (*pfnPvAllocEntPrivateData)(edict_t *, int32); /*   252     4 */
	/* --- cacheline 4 boundary (256 bytes) --- */
	void *                     (*pfnPvEntPrivateData)(edict_t *); /*   256     4 */
	void                       (*pfnFreeEntPrivateData)(edict_t *); /*   260     4 */
	const char  *              (*pfnSzFromIndex)(int); /*   264     4 */
	int                        (*pfnAllocString)(const char  *); /*   268     4 */
	class entvars_s *          (*pfnGetVarsOfEnt)(edict_t *); /*   272     4 */
	edict_t *                  (*pfnPEntityOfEntOffset)(int); /*   276     4 */
	int                        (*pfnEntOffsetOfPEntity)(const edict_t  *); /*   280     4 */
	int                        (*pfnIndexOfEdict)(const edict_t  *); /*   284     4 */
	edict_t *                  (*pfnPEntityOfEntIndex)(int); /*   288     4 */
	edict_t *                  (*pfnFindEntityByVars)(class entvars_s *); /*   292     4 */
	void *                     (*pfnGetModelPtr)(edict_t *); /*   296     4 */
	int                        (*pfnRegUserMsg)(const char  *, int); /*   300     4 */
	void                       (*pfnAnimationAutomove)(const edict_t  *, float); /*   304     4 */
	void                       (*pfnGetBonePosition)(const edict_t  *, int, float *, float *); /*   308     4 */
	uint32                     (*pfnFunctionFromName)(const char  *); /*   312     4 */
	const char  *              (*pfnNameForFunction)(uint32); /*   316     4 */
	/* --- cacheline 5 boundary (320 bytes) --- */
	void                       (*pfnClientPrintf)(edict_t *, PRINT_TYPE, const char  *); /*   320     4 */
	void                       (*pfnServerPrint)(const char  *); /*   324     4 */
	const char  *              (*pfnCmd_Args)(void); /*   328     4 */
	const char  *              (*pfnCmd_Argv)(int);  /*   332     4 */
	int                        (*pfnCmd_Argc)(void); /*   336     4 */
	void                       (*pfnGetAttachment)(const edict_t  *, int, float *, float *); /*   340     4 */
	void                       (*pfnCRC32_Init)(CRC32_t *); /*   344     4 */
	void                       (*pfnCRC32_ProcessBuffer)(CRC32_t *, void *, int); /*   348     4 */
	void                       (*pfnCRC32_ProcessByte)(CRC32_t *, unsigned char); /*   352     4 */
	CRC32_t                    (*pfnCRC32_Final)(CRC32_t); /*   356     4 */
	int32                      (*pfnRandomLong)(int32, int32); /*   360     4 */
	float                      (*pfnRandomFloat)(float, float); /*   364     4 */
	void                       (*pfnSetView)(const edict_t  *, const edict_t  *); /*   368     4 */
	float                      (*pfnTime)(void);     /*   372     4 */
	void                       (*pfnCrosshairAngle)(const edict_t  *, float, float); /*   376     4 */
	byte *                     (*pfnLoadFileForMe)(char *, int *); /*   380     4 */
	/* --- cacheline 6 boundary (384 bytes) --- */
	void                       (*pfnFreeFile)(void *); /*   384     4 */
	void                       (*pfnEndSection)(const char  *); /*   388     4 */
	int                        (*pfnCompareFileTime)(char *, char *, int *); /*   392     4 */
	void                       (*pfnGetGameDir)(char *); /*   396     4 */
	void                       (*pfnCvar_RegisterVariable)(cvar_t *); /*   400     4 */
	void                       (*pfnFadeClientVolume)(const edict_t  *, int, int, int, int); /*   404     4 */
	void                       (*pfnSetClientMaxspeed)(const edict_t  *, float); /*   408     4 */
	edict_t *                  (*pfnCreateFakeClient)(const char  *); /*   412     4 */
	void                       (*pfnRunPlayerMove)(edict_t *, const float  *, float, float, float, short unsigned int, byte, byte); /*   416     4 */
	int                        (*pfnNumberOfEntities)(void); /*   420     4 */
	char *                     (*pfnGetInfoKeyBuffer)(edict_t *); /*   424     4 */
	char *                     (*pfnInfoKeyValue)(char *, char *); /*   428     4 */
	void                       (*pfnSetKeyValue)(char *, char *, char *); /*   432     4 */
	void                       (*pfnSetClientKeyValue)(int, char *, char *, char *); /*   436     4 */
	int                        (*pfnIsMapValid)(char *); /*   440     4 */
	void                       (*pfnStaticDecal)(const float  *, int, int, int); /*   444     4 */
	/* --- cacheline 7 boundary (448 bytes) --- */
	int                        (*pfnPrecacheGeneric)(char *); /*   448     4 */
	int                        (*pfnGetPlayerUserId)(edict_t *); /*   452     4 */
	void                       (*pfnBuildSoundMsg)(edict_t *, int, const char  *, float, float, int, int, int, int, const float  *, edict_t *); /*   456     4 */
	int                        (*pfnIsDedicatedServer)(void); /*   460     4 */
	cvar_t *                   (*pfnCVarGetPointer)(const char  *); /*   464     4 */
	unsigned int               (*pfnGetPlayerWONId)(edict_t *); /*   468     4 */
	void                       (*pfnInfo_RemoveKey)(char *, const char  *); /*   472     4 */
	const char  *              (*pfnGetPhysicsKeyValue)(const edict_t  *, const char  *); /*   476     4 */
	void                       (*pfnSetPhysicsKeyValue)(const edict_t  *, const char  *, const char  *); /*   480     4 */
	const char  *              (*pfnGetPhysicsInfoString)(const edict_t  *); /*   484     4 */
	short unsigned int         (*pfnPrecacheEvent)(int, const char  *); /*   488     4 */
	void                       (*pfnPlaybackEvent)(int, const edict_t  *, short unsigned int, float, float *, float *, float, float, int, int, int, int); /*   492     4 */
	unsigned char *            (*pfnSetFatPVS)(float *); /*   496     4 */
	unsigned char *            (*pfnSetFatPAS)(float *); /*   500     4 */
	int                        (*pfnCheckVisibility)(const edict_t  *, unsigned char *); /*   504     4 */
	void                       (*pfnDeltaSetField)(class delta_s *, const char  *); /*   508     4 */
	/* --- cacheline 8 boundary (512 bytes) --- */
	void                       (*pfnDeltaUnsetField)(class delta_s *, const char  *); /*   512     4 */
	void                       (*pfnDeltaAddEncoder)(char *, void (*)(class delta_s *, const unsigned char  *, const unsigned char  *)); /*   516     4 */
	int                        (*pfnGetCurrentPlayer)(void); /*   520     4 */
	int                        (*pfnCanSkipPlayer)(const edict_t  *); /*   524     4 */
	int                        (*pfnDeltaFindField)(class delta_s *, const char  *); /*   528     4 */
	void                       (*pfnDeltaSetFieldByIndex)(class delta_s *, int); /*   532     4 */
	void                       (*pfnDeltaUnsetFieldByIndex)(class delta_s *, int); /*   536     4 */
	void                       (*pfnSetGroupMask)(int, int); /*   540     4 */
	int                        (*pfnCreateInstancedBaseline)(int, class entity_state_s *); /*   544     4 */
	void                       (*pfnCvar_DirectSet)(class cvar_s *, char *); /*   548     4 */
	void                       (*pfnForceUnmodified)(FORCE_TYPE, float *, float *, const char  *); /*   552     4 */
	void                       (*pfnGetPlayerStats)(const edict_t  *, int *, int *); /*   556     4 */
	void                       (*pfnAddServerCommand)(char *, void (*)(void)); /*   560     4 */
	qboolean                   (*pfnVoice_GetClientListening)(int, int); /*   564     4 */
	qboolean                   (*pfnVoice_SetClientListening)(int, int, qboolean); /*   568     4 */
	const char  *              (*pfnGetPlayerAuthId)(edict_t *); /*   572     4 */
	/* --- cacheline 9 boundary (576 bytes) --- */
	sequenceEntry_s *          (*pfnSequenceGet)(const char  *, const char  *); /*   576     4 */
	sentenceEntry_s *          (*pfnSequencePickSentence)(const char  *, int, int *); /*   580     4 */
	int                        (*pfnGetFileSize)(char *); /*   584     4 */
	unsigned int               (*pfnGetApproxWavePlayLen)(const char  *); /*   588     4 */
	int                        (*pfnIsCareerMatch)(void); /*   592     4 */
	int                        (*pfnGetLocalizedStringLength)(const char  *); /*   596     4 */
	void                       (*pfnRegisterTutorMessageShown)(int); /*   600     4 */
	int                        (*pfnGetTimesTutorMessageShown)(int); /*   604     4 */
	void                       (*ProcessTutorMessageDecayBuffer)(int *, int); /*   608     4 */
	void                       (*ConstructTutorMessageDecayBuffer)(int *, int); /*   612     4 */
	void                       (*ResetTutorMessageDecayData)(void); /*   616     4 */
	void                       (*pfnQueryClientCvarValue)(const edict_t  *, const char  *); /*   620     4 */
	void                       (*pfnQueryClientCvarValue2)(const edict_t  *, const char  *, int); /*   624     4 */
	int                        (*pfnCheckParm)(const char  *, char * *); /*   628     4 */
	edict_t *                  (*pfnPEntityOfEntIndexAllEntities)(int); /*   632     4 */

	/* size: 636, cachelines: 10, members: 159 */
	/* last cacheline: 60 bytes */
};
struct saverestore_s {
	char *                     pBaseData;            /*     0     4 */
	char *                     pCurrentData;         /*     4     4 */
	int                        size;                 /*     8     4 */
	int                        bufferSize;           /*    12     4 */
	int                        tokenSize;            /*    16     4 */
	int                        tokenCount;           /*    20     4 */
	char * *                   pTokens;              /*    24     4 */
	int                        currentIndex;         /*    28     4 */
	int                        tableCount;           /*    32     4 */
	int                        connectionCount;      /*    36     4 */
	ENTITYTABLE *              pTable;               /*    40     4 */
	LEVELLIST                  levelList[16];        /*    44  1280 */
	/* --- cacheline 20 boundary (1280 bytes) was 44 bytes ago --- */
	int                        fUseLandmark;         /*  1324     4 */
	char                       szLandmarkName[20];   /*  1328    20 */
	/* --- cacheline 21 boundary (1344 bytes) was 4 bytes ago --- */
	class Vector              vecLandmarkOffset;     /*  1348    12 */
	float                      time;                 /*  1360     4 */
	char                       szCurrentMapName[32]; /*  1364    32 */
	void saverestore_s(class saverestore_s *); /* linkage=_ZN13saverestore_sC4Ev */


	/* size: 1396, cachelines: 22, members: 17 */
	/* last cacheline: 52 bytes */
};
class CSaveRestoreBuffer {
protected:

	SAVERESTOREDATA *          m_pdata;              /*     0     4 */
	void CSaveRestoreBuffer(class CSaveRestoreBuffer *); /* linkage=_ZN18CSaveRestoreBufferC4Ev */

	void CSaveRestoreBuffer(class CSaveRestoreBuffer *, SAVERESTOREDATA *); /* linkage=_ZN18CSaveRestoreBufferC4EP13saverestore_s */

	void ~CSaveRestoreBuffer(class CSaveRestoreBuffer *, int); /* linkage=_ZN18CSaveRestoreBufferD4Ev */

	int EntityIndex(class CSaveRestoreBuffer *, entvars_t *); /* linkage=_ZN18CSaveRestoreBuffer11EntityIndexEP9entvars_s */

	int EntityIndex(class CSaveRestoreBuffer *, edict_t *); /* linkage=_ZN18CSaveRestoreBuffer11EntityIndexEP7edict_s */

	int EntityIndex(class CSaveRestoreBuffer *, EOFFSET); /* linkage=_ZN18CSaveRestoreBuffer11EntityIndexEi */

	int EntityIndex(class CSaveRestoreBuffer *, class CBaseEntity *); /* linkage=_ZN18CSaveRestoreBuffer11EntityIndexEP11CBaseEntity */

	int EntityFlags(class CSaveRestoreBuffer *, int, int); /* linkage=_ZN18CSaveRestoreBuffer11EntityFlagsEii */

	int EntityFlagsSet(class CSaveRestoreBuffer *, int, int); /* linkage=_ZN18CSaveRestoreBuffer14EntityFlagsSetEii */

	edict_t * EntityFromIndex(class CSaveRestoreBuffer *, int); /* linkage=_ZN18CSaveRestoreBuffer15EntityFromIndexEi */

	short unsigned int TokenHash(class CSaveRestoreBuffer *, const char  *); /* linkage=_ZN18CSaveRestoreBuffer9TokenHashEPKc */

	void BufferRewind(class CSaveRestoreBuffer *, int); /* linkage=_ZN18CSaveRestoreBuffer12BufferRewindEi */

	unsigned int HashString(class CSaveRestoreBuffer *, const char  *); /* linkage=_ZN18CSaveRestoreBuffer10HashStringEPKc */


	/* size: 4, cachelines: 1, members: 1 */
	/* last cacheline: 4 bytes */
};
class CSave : public CSaveRestoreBuffer {
public:

	/* class CSaveRestoreBuffer  <ancestor>; */      /*     0     4 */
	void CSave(class CSave *, SAVERESTOREDATA *); /* linkage=_ZN5CSaveC4EP13saverestore_s */

	void WriteShort(class CSave *, const char  *, const short int  *, int); /* linkage=_ZN5CSave10WriteShortEPKcPKsi */

	void WriteInt(class CSave *, const char  *, const int  *, int); /* linkage=_ZN5CSave8WriteIntEPKcPKii */

	void WriteFloat(class CSave *, const char  *, const float  *, int); /* linkage=_ZN5CSave10WriteFloatEPKcPKfi */

	void WriteTime(class CSave *, const char  *, const float  *, int); /* linkage=_ZN5CSave9WriteTimeEPKcPKfi */

	void WriteData(class CSave *, const char  *, int, const char  *); /* linkage=_ZN5CSave9WriteDataEPKciS1_ */

	void WriteString(class CSave *, const char  *, const char  *); /* linkage=_ZN5CSave11WriteStringEPKcS1_ */

	void WriteString(class CSave *, const char  *, const int  *, int); /* linkage=_ZN5CSave11WriteStringEPKcPKii */

	void WriteVector(class CSave *, const char  *, const class Vector  &); /* linkage=_ZN5CSave11WriteVectorEPKcRK6Vector */

	void WriteVector(class CSave *, const char  *, const float  *, int); /* linkage=_ZN5CSave11WriteVectorEPKcPKfi */

	void WritePositionVector(class CSave *, const char  *, const class Vector  &); /* linkage=_ZN5CSave19WritePositionVectorEPKcRK6Vector */

	void WritePositionVector(class CSave *, const char  *, const float  *, int); /* linkage=_ZN5CSave19WritePositionVectorEPKcPKfi */

	void WriteFunction(class CSave *, const char  *, void * *, int); /* linkage=_ZN5CSave13WriteFunctionEPKcPPvi */

	int WriteEntVars(class CSave *, const char  *, entvars_t *); /* linkage=_ZN5CSave12WriteEntVarsEPKcP9entvars_s */

	int WriteFields(class CSave *, const char  *, void *, TYPEDESCRIPTION *, int); /* linkage=_ZN5CSave11WriteFieldsEPKcPvP15TYPEDESCRIPTIONi */

private:

	int DataEmpty(class CSave *, const char  *, int); /* linkage=_ZN5CSave9DataEmptyEPKci */

	void BufferField(class CSave *, const char  *, int, const char  *); /* linkage=_ZN5CSave11BufferFieldEPKciS1_ */

	void BufferString(class CSave *, char *, int); /* linkage=_ZN5CSave12BufferStringEPci */

	void BufferData(class CSave *, const char  *, int); /* linkage=_ZN5CSave10BufferDataEPKci */

	void BufferHeader(class CSave *, const char  *, int); /* linkage=_ZN5CSave12BufferHeaderEPKci */


	/* size: 4, cachelines: 1, members: 1 */
	/* last cacheline: 4 bytes */
};
class CRestore : public CSaveRestoreBuffer {
public:

	/* class CSaveRestoreBuffer  <ancestor>; */      /*     0     4 */
private:

	int                        m_global;             /*     4     4 */
	BOOL                       m_precache;           /*     8     4 */
	void CRestore(class CRestore *, SAVERESTOREDATA *); /* linkage=_ZN8CRestoreC4EP13saverestore_s */

	int ReadEntVars(class CRestore *, const char  *, entvars_t *); /* linkage=_ZN8CRestore11ReadEntVarsEPKcP9entvars_s */

	int ReadFields(class CRestore *, const char  *, void *, TYPEDESCRIPTION *, int); /* linkage=_ZN8CRestore10ReadFieldsEPKcPvP15TYPEDESCRIPTIONi */

	int ReadField(class CRestore *, void *, TYPEDESCRIPTION *, int, int, int, char *, void *); /* linkage=_ZN8CRestore9ReadFieldEPvP15TYPEDESCRIPTIONiiiPcS0_ */

	int ReadInt(class CRestore *); /* linkage=_ZN8CRestore7ReadIntEv */

	short int ReadShort(class CRestore *); /* linkage=_ZN8CRestore9ReadShortEv */

	int ReadNamedInt(class CRestore *, const char  *); /* linkage=_ZN8CRestore12ReadNamedIntEPKc */

	char * ReadNamedString(class CRestore *, const char  *); /* linkage=_ZN8CRestore15ReadNamedStringEPKc */

	int Empty(class CRestore *); /* linkage=_ZN8CRestore5EmptyEv */

	void SetGlobalMode(class CRestore *, int); /* linkage=_ZN8CRestore13SetGlobalModeEi */

	void PrecacheMode(class CRestore *, BOOL); /* linkage=_ZN8CRestore12PrecacheModeEi */

	char * BufferPointer(class CRestore *); /* linkage=_ZN8CRestore13BufferPointerEv */

	void BufferReadBytes(class CRestore *, char *, int); /* linkage=_ZN8CRestore15BufferReadBytesEPci */

	void BufferSkipBytes(class CRestore *, int); /* linkage=_ZN8CRestore15BufferSkipBytesEi */

	int BufferSkipZString(class CRestore *); /* linkage=_ZN8CRestore17BufferSkipZStringEv */

	int BufferCheckZString(class CRestore *, const char  *); /* linkage=_ZN8CRestore18BufferCheckZStringEPKc */

	void BufferReadHeader(class CRestore *, HEADER *); /* linkage=_ZN8CRestore16BufferReadHeaderEP6HEADER */


	/* size: 12, cachelines: 1, members: 3 */
	/* last cacheline: 12 bytes */
};
class CAirtank : public CGrenade {

	/* XXX 1752 bytes hole, try to pack */
public:


	/* class CGrenade            <ancestor>; */      /*     0     0 */
private:

	static TYPEDESCRIPTION            m_SaveData[1]; /*     0     0 */
	/* --- cacheline 27 boundary (1728 bytes) was 24 bytes ago --- */
	int                        m_state;              /*  1752     4 */
	void CAirtank(class CAirtank *, class CAirtank &); /* linkage=_ZN8CAirtankC4EOS_ */

	void CAirtank(class CAirtank *, const class CAirtank  &); /* linkage=_ZN8CAirtankC4ERKS_ */

	void CAirtank(class CAirtank *); /* linkage=_ZN8CAirtankC4Ev */

	virtual void Spawn(class CAirtank *); /* linkage=_ZN8CAirtank5SpawnEv */

	virtual void Precache(class CAirtank *); /* linkage=_ZN8CAirtank8PrecacheEv */

	void TankThink(class CAirtank *); /* linkage=_ZN8CAirtank9TankThinkEv */

	void TankTouch(class CAirtank *, class CBaseEntity *); /* linkage=_ZN8CAirtank9TankTouchEP11CBaseEntity */

	virtual int BloodColor(class CAirtank *); /* linkage=_ZN8CAirtank10BloodColorEv */

	virtual void Killed(class CAirtank *, entvars_t *, entvars_t *, int); /* linkage=_ZN8CAirtank6KilledEP9entvars_sS1_i */

	virtual int Save(class CAirtank *, class CSave &); /* linkage=_ZN8CAirtank4SaveER5CSave */

	virtual int Restore(class CAirtank *, class CRestore &); /* linkage=_ZN8CAirtank7RestoreER8CRestore */

	virtual void ~CAirtank(class CAirtank *, int); /* linkage=_ZN8CAirtankD4Ev */

	/* vtable has 6 entries: {
	   [2] = Spawn(_ZN8CAirtank5SpawnEv), 
	   [3] = Precache(_ZN8CAirtank8PrecacheEv), 
	   [16] = BloodColor(_ZN8CAirtank10BloodColorEv), 
	   [15] = Killed(_ZN8CAirtank6KilledEP9entvars_sS1_i), 
	   [5] = Save(_ZN8CAirtank4SaveER5CSave), 
	   [6] = Restore(_ZN8CAirtank7RestoreER8CRestore), 
	} */
	/* size: 1756, cachelines: 28, members: 2, static members: 1 */
	/* sum members: 4, holes: 1, sum holes: 1752 */
	/* last cacheline: 28 bytes */
};
struct KeyValueData_s {
	char *                     szClassName;          /*     0     4 */
	char *                     szKeyName;            /*     4     4 */
	char *                     szValue;              /*     8     4 */
	int32                      fHandled;             /*    12     4 */

	/* size: 16, cachelines: 1, members: 4 */
	/* last cacheline: 16 bytes */
};
class DBAreaClassData {
	int                        m_DB_PingTotal;       /*     0     4 */
	int                        m_DB_nPingTests;      /*     4     4 */
	int                        m_DB_TimeInArea;      /*     8     4 */
	void DBAreaClassData(class DBAreaClassData *); /* linkage=_ZN15DBAreaClassDataC4Ev */

	void Clear(class DBAreaClassData *); /* linkage=_ZN15DBAreaClassData5ClearEv */

	void MergeData(class DBAreaClassData *, class DBAreaClassData *); /* linkage=_ZN15DBAreaClassData9MergeDataEPS_ */


	/* size: 12, cachelines: 1, members: 3 */
	/* last cacheline: 12 bytes */
};
class CAreaDef : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	class DBAreaClassData     m_ClassData[12];       /*  1140   144 */
	/* --- cacheline 20 boundary (1280 bytes) was 4 bytes ago --- */
	char                       m_AreaName[32];       /*  1284    32 */
	class CAreaDef *           m_pNext;              /*  1316     4 */

	/* Bitfield combined with previous fields */

	static TYPEDESCRIPTION            m_SaveData[1]; /*     0     0 */
	void CAreaDef(class CAreaDef *, const class CAreaDef  &); /* linkage=_ZN8CAreaDefC4ERKS_ */

	void CAreaDef(class CAreaDef *, bool); /* linkage=_ZN8CAreaDefC4Eb */

	virtual void ~CAreaDef(class CAreaDef *, int); /* linkage=_ZN8CAreaDefD4Ev */

	virtual int Save(class CAreaDef *, class CSave &); /* linkage=_ZN8CAreaDef4SaveER5CSave */

	virtual int Restore(class CAreaDef *, class CRestore &); /* linkage=_ZN8CAreaDef7RestoreER8CRestore */

	virtual void KeyValue(class CAreaDef *, KeyValueData *); /* linkage=_ZN8CAreaDef8KeyValueEP14KeyValueData_s */

	class DBAreaClassData * GetClassData(class CAreaDef *, const char  *); /* linkage=_ZN8CAreaDef12GetClassDataEPKc */

	void ClearClassData(class CAreaDef *); /* linkage=_ZN8CAreaDef14ClearClassDataEv */

	void MergeData(class CAreaDef *, class CAreaDef *); /* linkage=_ZN8CAreaDef9MergeDataEPS_ */

	/* vtable has 3 entries: {
	   [5] = Save(_ZN8CAreaDef4SaveER5CSave), 
	   [6] = Restore(_ZN8CAreaDef7RestoreER8CRestore), 
	   [4] = KeyValue(_ZN8CAreaDef8KeyValueEP14KeyValueData_s), 
	} */
	/* size: 1320, cachelines: 21, members: 4, static members: 1 */
	/* sum members: 180, holes: 1, sum holes: 1140 */
	/* last cacheline: 40 bytes */
};
struct mstudioevent_s {
	int                        frame;                /*     0     4 */
	int                        event;                /*     4     4 */
	int                        type;                 /*     8     4 */
	char                       options[64];          /*    12    64 */

	/* size: 76, cachelines: 2, members: 4 */
	/* last cacheline: 12 bytes */
};
class CPendulum : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[8]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	float                      m_accel;              /*  1140     4 */
	float                      m_distance;           /*  1144     4 */
	float                      m_time;               /*  1148     4 */
	/* --- cacheline 18 boundary (1152 bytes) --- */
	float                      m_damp;               /*  1152     4 */
	float                      m_maxSpeed;           /*  1156     4 */
	float                      m_dampSpeed;          /*  1160     4 */
	class Vector              m_center;              /*  1164    12 */
	class Vector              m_start;               /*  1176    12 */
	void CPendulum(class CPendulum *, class CPendulum &); /* linkage=_ZN9CPendulumC4EOS_ */

	void CPendulum(class CPendulum *, const class CPendulum  &); /* linkage=_ZN9CPendulumC4ERKS_ */

	void CPendulum(class CPendulum *); /* linkage=_ZN9CPendulumC4Ev */

	virtual void Spawn(class CPendulum *); /* linkage=_ZN9CPendulum5SpawnEv */

	virtual void KeyValue(class CPendulum *, KeyValueData *); /* linkage=_ZN9CPendulum8KeyValueEP14KeyValueData_s */

	void Swing(class CPendulum *); /* linkage=_ZN9CPendulum5SwingEv */

	void PendulumUse(class CPendulum *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN9CPendulum11PendulumUseEP11CBaseEntityS1_8USE_TYPEf */

	void Stop(class CPendulum *); /* linkage=_ZN9CPendulum4StopEv */

	virtual void Touch(class CPendulum *, class CBaseEntity *); /* linkage=_ZN9CPendulum5TouchEP11CBaseEntity */

	void RopeTouch(class CPendulum *, class CBaseEntity *); /* linkage=_ZN9CPendulum9RopeTouchEP11CBaseEntity */

	virtual int ObjectCaps(class CPendulum *); /* linkage=_ZN9CPendulum10ObjectCapsEv */

	virtual int Save(class CPendulum *, class CSave &); /* linkage=_ZN9CPendulum4SaveER5CSave */

	virtual int Restore(class CPendulum *, class CRestore &); /* linkage=_ZN9CPendulum7RestoreER8CRestore */

	virtual void Blocked(class CPendulum *, class CBaseEntity *); /* linkage=_ZN9CPendulum7BlockedEP11CBaseEntity */

	virtual void ~CPendulum(class CPendulum *, int); /* linkage=_ZN9CPendulumD4Ev */

	/* vtable has 7 entries: {
	   [2] = Spawn(_ZN9CPendulum5SpawnEv), 
	   [4] = KeyValue(_ZN9CPendulum8KeyValueEP14KeyValueData_s), 
	   [44] = Touch(_ZN9CPendulum5TouchEP11CBaseEntity), 
	   [7] = ObjectCaps(_ZN9CPendulum10ObjectCapsEv), 
	   [5] = Save(_ZN9CPendulum4SaveER5CSave), 
	   [6] = Restore(_ZN9CPendulum7RestoreER8CRestore), 
	   [46] = Blocked(_ZN9CPendulum7BlockedEP11CBaseEntity), 
	} */
	/* size: 1188, cachelines: 19, members: 9, static members: 1 */
	/* sum members: 48, holes: 1, sum holes: 1140 */
	/* last cacheline: 36 bytes */
};
class CFuncRotating : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[5]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	float                      m_flFanFriction;      /*  1140     4 */
	float                      m_flAttenuation;      /*  1144     4 */
	float                      m_flVolume;           /*  1148     4 */
	/* --- cacheline 18 boundary (1152 bytes) --- */
	float                      m_pitch;              /*  1152     4 */
	int                        m_sounds;             /*  1156     4 */
	void CFuncRotating(class CFuncRotating *, class CFuncRotating &); /* linkage=_ZN13CFuncRotatingC4EOS_ */

	void CFuncRotating(class CFuncRotating *, const class CFuncRotating  &); /* linkage=_ZN13CFuncRotatingC4ERKS_ */

	void CFuncRotating(class CFuncRotating *); /* linkage=_ZN13CFuncRotatingC4Ev */

	virtual void Spawn(class CFuncRotating *); /* linkage=_ZN13CFuncRotating5SpawnEv */

	virtual void Precache(class CFuncRotating *); /* linkage=_ZN13CFuncRotating8PrecacheEv */

	void SpinUp(class CFuncRotating *); /* linkage=_ZN13CFuncRotating6SpinUpEv */

	void SpinDown(class CFuncRotating *); /* linkage=_ZN13CFuncRotating8SpinDownEv */

	virtual void KeyValue(class CFuncRotating *, KeyValueData *); /* linkage=_ZN13CFuncRotating8KeyValueEP14KeyValueData_s */

	void HurtTouch(class CFuncRotating *, class CBaseEntity *); /* linkage=_ZN13CFuncRotating9HurtTouchEP11CBaseEntity */

	void RotatingUse(class CFuncRotating *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN13CFuncRotating11RotatingUseEP11CBaseEntityS1_8USE_TYPEf */

	void Rotate(class CFuncRotating *); /* linkage=_ZN13CFuncRotating6RotateEv */

	void RampPitchVol(class CFuncRotating *, int); /* linkage=_ZN13CFuncRotating12RampPitchVolEi */

	virtual void Blocked(class CFuncRotating *, class CBaseEntity *); /* linkage=_ZN13CFuncRotating7BlockedEP11CBaseEntity */

	virtual int ObjectCaps(class CFuncRotating *); /* linkage=_ZN13CFuncRotating10ObjectCapsEv */

	virtual int Save(class CFuncRotating *, class CSave &); /* linkage=_ZN13CFuncRotating4SaveER5CSave */

	virtual int Restore(class CFuncRotating *, class CRestore &); /* linkage=_ZN13CFuncRotating7RestoreER8CRestore */

	virtual void ~CFuncRotating(class CFuncRotating *, int); /* linkage=_ZN13CFuncRotatingD4Ev */

	/* vtable has 7 entries: {
	   [2] = Spawn(_ZN13CFuncRotating5SpawnEv), 
	   [3] = Precache(_ZN13CFuncRotating8PrecacheEv), 
	   [4] = KeyValue(_ZN13CFuncRotating8KeyValueEP14KeyValueData_s), 
	   [46] = Blocked(_ZN13CFuncRotating7BlockedEP11CBaseEntity), 
	   [7] = ObjectCaps(_ZN13CFuncRotating10ObjectCapsEv), 
	   [5] = Save(_ZN13CFuncRotating4SaveER5CSave), 
	   [6] = Restore(_ZN13CFuncRotating7RestoreER8CRestore), 
	} */
	/* size: 1160, cachelines: 19, members: 6, static members: 1 */
	/* sum members: 20, holes: 1, sum holes: 1140 */
	/* last cacheline: 8 bytes */
};
class CFuncMonsterClip : public CFuncWall {
public:

	/* class CFuncWall           <ancestor>; */      /*     0  1140 */

	/* XXX last struct has 1140 bytes of padding */
	void CFuncMonsterClip(class CFuncMonsterClip *, class CFuncMonsterClip &); /* linkage=_ZN16CFuncMonsterClipC4EOS_ */

	void CFuncMonsterClip(class CFuncMonsterClip *, const class CFuncMonsterClip  &); /* linkage=_ZN16CFuncMonsterClipC4ERKS_ */

	void CFuncMonsterClip(class CFuncMonsterClip *); /* linkage=_ZN16CFuncMonsterClipC4Ev */

	virtual void Spawn(class CFuncMonsterClip *); /* linkage=_ZN16CFuncMonsterClip5SpawnEv */

	virtual void Use(class CFuncMonsterClip *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN16CFuncMonsterClip3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void ~CFuncMonsterClip(class CFuncMonsterClip *, int); /* linkage=_ZN16CFuncMonsterClipD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN16CFuncMonsterClip5SpawnEv), 
	   [45] = Use(_ZN16CFuncMonsterClip3UseEP11CBaseEntityS1_8USE_TYPEf), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* paddings: 1, sum paddings: 1140 */
	/* last cacheline: 52 bytes */
};
class CFuncWall : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CFuncWall(class CFuncWall *, class CFuncWall &); /* linkage=_ZN9CFuncWallC4EOS_ */

	void CFuncWall(class CFuncWall *, const class CFuncWall  &); /* linkage=_ZN9CFuncWallC4ERKS_ */

	void CFuncWall(class CFuncWall *); /* linkage=_ZN9CFuncWallC4Ev */

	virtual void Spawn(class CFuncWall *); /* linkage=_ZN9CFuncWall5SpawnEv */

	virtual void Use(class CFuncWall *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN9CFuncWall3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual int ObjectCaps(class CFuncWall *); /* linkage=_ZN9CFuncWall10ObjectCapsEv */

	virtual void ~CFuncWall(class CFuncWall *, int); /* linkage=_ZN9CFuncWallD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN9CFuncWall5SpawnEv), 
	   [45] = Use(_ZN9CFuncWall3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [7] = ObjectCaps(_ZN9CFuncWall10ObjectCapsEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CFuncIllusionary : public CBaseToggle {
public:

	/* class CBaseToggle         <ancestor>; */      /*     0     0 */
	void CFuncIllusionary(class CFuncIllusionary *, class CFuncIllusionary &); /* linkage=_ZN16CFuncIllusionaryC4EOS_ */

	void CFuncIllusionary(class CFuncIllusionary *, const class CFuncIllusionary  &); /* linkage=_ZN16CFuncIllusionaryC4ERKS_ */

	void CFuncIllusionary(class CFuncIllusionary *); /* linkage=_ZN16CFuncIllusionaryC4Ev */

	virtual void Spawn(class CFuncIllusionary *); /* linkage=_ZN16CFuncIllusionary5SpawnEv */

	void SloshTouch(class CFuncIllusionary *, class CBaseEntity *); /* linkage=_ZN16CFuncIllusionary10SloshTouchEP11CBaseEntity */

	virtual void KeyValue(class CFuncIllusionary *, KeyValueData *); /* linkage=_ZN16CFuncIllusionary8KeyValueEP14KeyValueData_s */

	virtual int ObjectCaps(class CFuncIllusionary *); /* linkage=_ZN16CFuncIllusionary10ObjectCapsEv */

	virtual void ~CFuncIllusionary(class CFuncIllusionary *, int); /* linkage=_ZN16CFuncIllusionaryD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN16CFuncIllusionary5SpawnEv), 
	   [4] = KeyValue(_ZN16CFuncIllusionary8KeyValueEP14KeyValueData_s), 
	   [7] = ObjectCaps(_ZN16CFuncIllusionary10ObjectCapsEv), 
	} */
	/* size: 1300, cachelines: 21, members: 1 */
	/* padding: 1300 */
	/* last cacheline: 20 bytes */
};
class CFuncConveyor : public CFuncWall {
public:

	/* class CFuncWall           <ancestor>; */      /*     0  1140 */

	/* XXX last struct has 1140 bytes of padding */
	void CFuncConveyor(class CFuncConveyor *, class CFuncConveyor &); /* linkage=_ZN13CFuncConveyorC4EOS_ */

	void CFuncConveyor(class CFuncConveyor *, const class CFuncConveyor  &); /* linkage=_ZN13CFuncConveyorC4ERKS_ */

	void CFuncConveyor(class CFuncConveyor *); /* linkage=_ZN13CFuncConveyorC4Ev */

	virtual void Spawn(class CFuncConveyor *); /* linkage=_ZN13CFuncConveyor5SpawnEv */

	virtual void Use(class CFuncConveyor *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN13CFuncConveyor3UseEP11CBaseEntityS1_8USE_TYPEf */

	void UpdateSpeed(class CFuncConveyor *, float); /* linkage=_ZN13CFuncConveyor11UpdateSpeedEf */

	virtual void ~CFuncConveyor(class CFuncConveyor *, int); /* linkage=_ZN13CFuncConveyorD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN13CFuncConveyor5SpawnEv), 
	   [45] = Use(_ZN13CFuncConveyor3UseEP11CBaseEntityS1_8USE_TYPEf), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* paddings: 1, sum paddings: 1140 */
	/* last cacheline: 52 bytes */
};
class CFuncWallToggle : public CFuncWall {
public:

	/* class CFuncWall           <ancestor>; */      /*     0  1140 */

	/* XXX last struct has 1140 bytes of padding */
	void CFuncWallToggle(class CFuncWallToggle *, class CFuncWallToggle &); /* linkage=_ZN15CFuncWallToggleC4EOS_ */

	void CFuncWallToggle(class CFuncWallToggle *, const class CFuncWallToggle  &); /* linkage=_ZN15CFuncWallToggleC4ERKS_ */

	void CFuncWallToggle(class CFuncWallToggle *); /* linkage=_ZN15CFuncWallToggleC4Ev */

	virtual void Spawn(class CFuncWallToggle *); /* linkage=_ZN15CFuncWallToggle5SpawnEv */

	virtual void Use(class CFuncWallToggle *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN15CFuncWallToggle3UseEP11CBaseEntityS1_8USE_TYPEf */

	void TurnOff(class CFuncWallToggle *); /* linkage=_ZN15CFuncWallToggle7TurnOffEv */

	void TurnOn(class CFuncWallToggle *); /* linkage=_ZN15CFuncWallToggle6TurnOnEv */

	BOOL IsOn(class CFuncWallToggle *); /* linkage=_ZN15CFuncWallToggle4IsOnEv */

	virtual void ~CFuncWallToggle(class CFuncWallToggle *, int); /* linkage=_ZN15CFuncWallToggleD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN15CFuncWallToggle5SpawnEv), 
	   [45] = Use(_ZN15CFuncWallToggle3UseEP11CBaseEntityS1_8USE_TYPEf), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* paddings: 1, sum paddings: 1140 */
	/* last cacheline: 52 bytes */
};
struct globalentity_s {
	char                       name[64];             /*     0    64 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	char                       levelName[32];        /*    64    32 */
	GLOBALESTATE               state;                /*    96     4 */
	globalentity_t *           pNext;                /*   100     4 */

	/* size: 104, cachelines: 2, members: 4 */
	/* last cacheline: 40 bytes */
};
class CGlobalState {
	static TYPEDESCRIPTION            m_SaveData[0]; /*     0     0 */
private:

	globalentity_t *           m_pList;              /*     0     4 */
	int                        m_listCount;          /*     4     4 */
	void CGlobalState(class CGlobalState *); /* linkage=_ZN12CGlobalStateC4Ev */

	void Reset(class CGlobalState *); /* linkage=_ZN12CGlobalState5ResetEv */

	void ClearStates(class CGlobalState *); /* linkage=_ZN12CGlobalState11ClearStatesEv */

	void EntityAdd(class CGlobalState *, string_t, string_t, GLOBALESTATE); /* linkage=_ZN12CGlobalState9EntityAddEjj12GLOBALESTATE */

	void EntitySetState(class CGlobalState *, string_t, GLOBALESTATE); /* linkage=_ZN12CGlobalState14EntitySetStateEj12GLOBALESTATE */

	void EntityUpdate(class CGlobalState *, string_t, string_t); /* linkage=_ZN12CGlobalState12EntityUpdateEjj */

	const globalentity_t  * EntityFromTable(class CGlobalState *, string_t); /* linkage=_ZN12CGlobalState15EntityFromTableEj */

	GLOBALESTATE EntityGetState(class CGlobalState *, string_t); /* linkage=_ZN12CGlobalState14EntityGetStateEj */

	int EntityInTable(class CGlobalState *, string_t); /* linkage=_ZN12CGlobalState13EntityInTableEj */

	int Save(class CGlobalState *, class CSave &); /* linkage=_ZN12CGlobalState4SaveER5CSave */

	int Restore(class CGlobalState *, class CRestore &); /* linkage=_ZN12CGlobalState7RestoreER8CRestore */

	void DumpGlobals(class CGlobalState *); /* linkage=_ZN12CGlobalState11DumpGlobalsEv */

	globalentity_t * Find(class CGlobalState *, string_t); /* linkage=_ZN12CGlobalState4FindEj */


	/* size: 8, cachelines: 1, members: 2, static members: 1 */
	/* last cacheline: 8 bytes */
};
class EHANDLE {
private:

	edict_t *                  m_pent;               /*     0     4 */
	int                        m_serialnumber;       /*     4     4 */
	edict_t * Get(class EHANDLE *); /* linkage=_ZN7EHANDLE3GetEv */

	edict_t * Set(class EHANDLE *, edict_t *); /* linkage=_ZN7EHANDLE3SetEP7edict_s */

	int operator int(class EHANDLE *); /* linkage=_ZN7EHANDLEcviEv */

	class CBaseEntity * operator CBaseEntity*(class EHANDLE *); /* linkage=_ZN7EHANDLEcvP11CBaseEntityEv */

	class CBaseEntity * operator=(class EHANDLE *, class CBaseEntity *); /* linkage=_ZN7EHANDLEaSEP11CBaseEntity */

	class CBaseEntity * operator->(class EHANDLE *); /* linkage=_ZN7EHANDLEptEv */


	/* size: 8, cachelines: 1, members: 2 */
	/* last cacheline: 8 bytes */
};
struct locksounds {
	string_t                   sLockedSound;         /*     0     4 */
	string_t                   sLockedSentence;      /*     4     4 */
	string_t                   sUnlockedSound;       /*     8     4 */
	string_t                   sUnlockedSentence;    /*    12     4 */
	int                        iLockedSentence;      /*    16     4 */
	int                        iUnlockedSentence;    /*    20     4 */
	float                      flwaitSound;          /*    24     4 */
	float                      flwaitSentence;       /*    28     4 */
	BYTE                       bEOFLocked;           /*    32     1 */
	BYTE                       bEOFUnlocked;         /*    33     1 */

	/* size: 36, cachelines: 1, members: 10 */
	/* padding: 2 */
	/* last cacheline: 36 bytes */
};
class CBaseButton : public CBaseToggle {

	/* XXX 1300 bytes hole, try to pack */
	enum BUTTON_CODE {
		BUTTON_NOTHING  = 0,
		BUTTON_ACTIVATE = 1,
		BUTTON_RETURN   = 2,
	};

public:


	/* class CBaseToggle         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[8]; /*     0     0 */
	/* --- cacheline 20 boundary (1280 bytes) was 20 bytes ago --- */
	BOOL                       m_fStayPushed;        /*  1300     4 */
	BOOL                       m_fRotating;          /*  1304     4 */
	string_t                   m_strChangeTarget;    /*  1308     4 */
	locksound_t                m_ls;                 /*  1312    36 */
	/* --- cacheline 21 boundary (1344 bytes) was 4 bytes ago --- */
	BYTE                       m_bLockedSound;       /*  1348     1 */
	BYTE                       m_bLockedSentence;    /*  1349     1 */
	BYTE                       m_bUnlockedSound;     /*  1350     1 */
	BYTE                       m_bUnlockedSentence;  /*  1351     1 */
	int                        m_sounds;             /*  1352     4 */
	void CBaseButton(class CBaseButton *, class CBaseButton &); /* linkage=_ZN11CBaseButtonC4EOS_ */

	void CBaseButton(class CBaseButton *, const class CBaseButton  &); /* linkage=_ZN11CBaseButtonC4ERKS_ */

	void CBaseButton(class CBaseButton *); /* linkage=_ZN11CBaseButtonC4Ev */

	virtual void Spawn(class CBaseButton *); /* linkage=_ZN11CBaseButton5SpawnEv */

	virtual void Precache(class CBaseButton *); /* linkage=_ZN11CBaseButton8PrecacheEv */

	void RotSpawn(class CBaseButton *); /* linkage=_ZN11CBaseButton8RotSpawnEv */

	virtual void KeyValue(class CBaseButton *, KeyValueData *); /* linkage=_ZN11CBaseButton8KeyValueEP14KeyValueData_s */

	void ButtonActivate(class CBaseButton *); /* linkage=_ZN11CBaseButton14ButtonActivateEv */

	void SparkSoundCache(class CBaseButton *); /* linkage=_ZN11CBaseButton15SparkSoundCacheEv */

	void ButtonShot(class CBaseButton *); /* linkage=_ZN11CBaseButton10ButtonShotEv */

	void ButtonTouch(class CBaseButton *, class CBaseEntity *); /* linkage=_ZN11CBaseButton11ButtonTouchEP11CBaseEntity */

	void ButtonSpark(class CBaseButton *); /* linkage=_ZN11CBaseButton11ButtonSparkEv */

	void TriggerAndWait(class CBaseButton *); /* linkage=_ZN11CBaseButton14TriggerAndWaitEv */

	void ButtonReturn(class CBaseButton *); /* linkage=_ZN11CBaseButton12ButtonReturnEv */

	void ButtonBackHome(class CBaseButton *); /* linkage=_ZN11CBaseButton14ButtonBackHomeEv */

	void ButtonUse(class CBaseButton *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN11CBaseButton9ButtonUseEP11CBaseEntityS1_8USE_TYPEf */

	virtual int TakeDamage(class CBaseButton *, entvars_t *, entvars_t *, float, int); /* linkage=_ZN11CBaseButton10TakeDamageEP9entvars_sS1_fi */

	virtual int Save(class CBaseButton *, class CSave &); /* linkage=_ZN11CBaseButton4SaveER5CSave */

	virtual int Restore(class CBaseButton *, class CRestore &); /* linkage=_ZN11CBaseButton7RestoreER8CRestore */

	enum BUTTON_CODE ButtonResponseToTouch(class CBaseButton *); /* linkage=_ZN11CBaseButton21ButtonResponseToTouchEv */

	virtual int ObjectCaps(class CBaseButton *); /* linkage=_ZN11CBaseButton10ObjectCapsEv */

	virtual void ~CBaseButton(class CBaseButton *, int); /* linkage=_ZN11CBaseButtonD4Ev */

	/* vtable has 7 entries: {
	   [2] = Spawn(_ZN11CBaseButton5SpawnEv), 
	   [3] = Precache(_ZN11CBaseButton8PrecacheEv), 
	   [4] = KeyValue(_ZN11CBaseButton8KeyValueEP14KeyValueData_s), 
	   [13] = TakeDamage(_ZN11CBaseButton10TakeDamageEP9entvars_sS1_fi), 
	   [5] = Save(_ZN11CBaseButton4SaveER5CSave), 
	   [6] = Restore(_ZN11CBaseButton7RestoreER8CRestore), 
	   [7] = ObjectCaps(_ZN11CBaseButton10ObjectCapsEv), 
	} */
	/* size: 1356, cachelines: 22, members: 10, static members: 1 */
	/* sum members: 56, holes: 1, sum holes: 1300 */
	/* last cacheline: 12 bytes */
};
class CButtonTarget : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CButtonTarget(class CButtonTarget *, class CButtonTarget &); /* linkage=_ZN13CButtonTargetC4EOS_ */

	void CButtonTarget(class CButtonTarget *, const class CButtonTarget  &); /* linkage=_ZN13CButtonTargetC4ERKS_ */

	void CButtonTarget(class CButtonTarget *); /* linkage=_ZN13CButtonTargetC4Ev */

	virtual void Spawn(class CButtonTarget *); /* linkage=_ZN13CButtonTarget5SpawnEv */

	virtual void Use(class CButtonTarget *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN13CButtonTarget3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual int TakeDamage(class CButtonTarget *, entvars_t *, entvars_t *, float, int); /* linkage=_ZN13CButtonTarget10TakeDamageEP9entvars_sS1_fi */

	virtual int ObjectCaps(class CButtonTarget *); /* linkage=_ZN13CButtonTarget10ObjectCapsEv */

	virtual void ~CButtonTarget(class CButtonTarget *, int); /* linkage=_ZN13CButtonTargetD4Ev */

	/* vtable has 4 entries: {
	   [2] = Spawn(_ZN13CButtonTarget5SpawnEv), 
	   [45] = Use(_ZN13CButtonTarget3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [13] = TakeDamage(_ZN13CButtonTarget10TakeDamageEP9entvars_sS1_fi), 
	   [7] = ObjectCaps(_ZN13CButtonTarget10ObjectCapsEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CEnvSpark : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[1]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	float                      m_flDelay;            /*  1140     4 */
	void CEnvSpark(class CEnvSpark *, class CEnvSpark &); /* linkage=_ZN9CEnvSparkC4EOS_ */

	void CEnvSpark(class CEnvSpark *, const class CEnvSpark  &); /* linkage=_ZN9CEnvSparkC4ERKS_ */

	void CEnvSpark(class CEnvSpark *); /* linkage=_ZN9CEnvSparkC4Ev */

	virtual void Spawn(class CEnvSpark *); /* linkage=_ZN9CEnvSpark5SpawnEv */

	virtual void Precache(class CEnvSpark *); /* linkage=_ZN9CEnvSpark8PrecacheEv */

	void SparkThink(class CEnvSpark *); /* linkage=_ZN9CEnvSpark10SparkThinkEv */

	void SparkStart(class CEnvSpark *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN9CEnvSpark10SparkStartEP11CBaseEntityS1_8USE_TYPEf */

	void SparkStop(class CEnvSpark *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN9CEnvSpark9SparkStopEP11CBaseEntityS1_8USE_TYPEf */

	virtual void KeyValue(class CEnvSpark *, KeyValueData *); /* linkage=_ZN9CEnvSpark8KeyValueEP14KeyValueData_s */

	virtual int Save(class CEnvSpark *, class CSave &); /* linkage=_ZN9CEnvSpark4SaveER5CSave */

	virtual int Restore(class CEnvSpark *, class CRestore &); /* linkage=_ZN9CEnvSpark7RestoreER8CRestore */

	virtual void ~CEnvSpark(class CEnvSpark *, int); /* linkage=_ZN9CEnvSparkD4Ev */

	/* vtable has 5 entries: {
	   [2] = Spawn(_ZN9CEnvSpark5SpawnEv), 
	   [3] = Precache(_ZN9CEnvSpark8PrecacheEv), 
	   [4] = KeyValue(_ZN9CEnvSpark8KeyValueEP14KeyValueData_s), 
	   [5] = Save(_ZN9CEnvSpark4SaveER5CSave), 
	   [6] = Restore(_ZN9CEnvSpark7RestoreER8CRestore), 
	} */
	/* size: 1144, cachelines: 18, members: 2, static members: 1 */
	/* sum members: 4, holes: 1, sum holes: 1140 */
	/* last cacheline: 56 bytes */
};
class CMomentaryRotButton : public CBaseToggle {

	/* XXX 1300 bytes hole, try to pack */
public:


	/* class CBaseToggle         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[6]; /*     0     0 */
	/* --- cacheline 20 boundary (1280 bytes) was 20 bytes ago --- */
	int                        m_lastUsed;           /*  1300     4 */
	int                        m_direction;          /*  1304     4 */
	float                      m_returnSpeed;        /*  1308     4 */
	class Vector              m_start;               /*  1312    12 */
	class Vector              m_end;                 /*  1324    12 */
	int                        m_sounds;             /*  1336     4 */
	void CMomentaryRotButton(class CMomentaryRotButton *, class CMomentaryRotButton &); /* linkage=_ZN19CMomentaryRotButtonC4EOS_ */

	void CMomentaryRotButton(class CMomentaryRotButton *, const class CMomentaryRotButton  &); /* linkage=_ZN19CMomentaryRotButtonC4ERKS_ */

	void CMomentaryRotButton(class CMomentaryRotButton *); /* linkage=_ZN19CMomentaryRotButtonC4Ev */

	virtual void Spawn(class CMomentaryRotButton *); /* linkage=_ZN19CMomentaryRotButton5SpawnEv */

	virtual void KeyValue(class CMomentaryRotButton *, KeyValueData *); /* linkage=_ZN19CMomentaryRotButton8KeyValueEP14KeyValueData_s */

	virtual int ObjectCaps(class CMomentaryRotButton *); /* linkage=_ZN19CMomentaryRotButton10ObjectCapsEv */

	virtual void Use(class CMomentaryRotButton *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN19CMomentaryRotButton3UseEP11CBaseEntityS1_8USE_TYPEf */

	void Off(class CMomentaryRotButton *); /* linkage=_ZN19CMomentaryRotButton3OffEv */

	void Return(class CMomentaryRotButton *); /* linkage=_ZN19CMomentaryRotButton6ReturnEv */

	void UpdateSelf(class CMomentaryRotButton *, float); /* linkage=_ZN19CMomentaryRotButton10UpdateSelfEf */

	void UpdateSelfReturn(class CMomentaryRotButton *, float); /* linkage=_ZN19CMomentaryRotButton16UpdateSelfReturnEf */

	void UpdateAllButtons(class CMomentaryRotButton *, float, int); /* linkage=_ZN19CMomentaryRotButton16UpdateAllButtonsEfi */

	void PlaySound(class CMomentaryRotButton *); /* linkage=_ZN19CMomentaryRotButton9PlaySoundEv */

	void UpdateTarget(class CMomentaryRotButton *, float); /* linkage=_ZN19CMomentaryRotButton12UpdateTargetEf */

	class CMomentaryRotButton * Instance(edict_t *); /* linkage=_ZN19CMomentaryRotButton8InstanceEP7edict_s */

	virtual int Save(class CMomentaryRotButton *, class CSave &); /* linkage=_ZN19CMomentaryRotButton4SaveER5CSave */

	virtual int Restore(class CMomentaryRotButton *, class CRestore &); /* linkage=_ZN19CMomentaryRotButton7RestoreER8CRestore */

	virtual void ~CMomentaryRotButton(class CMomentaryRotButton *, int); /* linkage=_ZN19CMomentaryRotButtonD4Ev */

	/* vtable has 6 entries: {
	   [2] = Spawn(_ZN19CMomentaryRotButton5SpawnEv), 
	   [4] = KeyValue(_ZN19CMomentaryRotButton8KeyValueEP14KeyValueData_s), 
	   [7] = ObjectCaps(_ZN19CMomentaryRotButton10ObjectCapsEv), 
	   [45] = Use(_ZN19CMomentaryRotButton3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [5] = Save(_ZN19CMomentaryRotButton4SaveER5CSave), 
	   [6] = Restore(_ZN19CMomentaryRotButton7RestoreER8CRestore), 
	} */
	/* size: 1340, cachelines: 21, members: 7, static members: 1 */
	/* sum members: 40, holes: 1, sum holes: 1300 */
	/* last cacheline: 60 bytes */
};
class CRotButton : public CBaseButton {
public:

	/* class CBaseButton         <ancestor>; */      /*     0  1356 */

	/* XXX last struct has 1 hole */
	void CRotButton(class CRotButton *, class CRotButton &); /* linkage=_ZN10CRotButtonC4EOS_ */

	void CRotButton(class CRotButton *, const class CRotButton  &); /* linkage=_ZN10CRotButtonC4ERKS_ */

	void CRotButton(class CRotButton *); /* linkage=_ZN10CRotButtonC4Ev */

	virtual void Spawn(class CRotButton *); /* linkage=_ZN10CRotButton5SpawnEv */

	virtual void ~CRotButton(class CRotButton *, int); /* linkage=_ZN10CRotButtonD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN10CRotButton5SpawnEv), 
	} */
	/* size: 1356, cachelines: 22, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 12 bytes */
};
class CMultiSource : public CPointEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CPointEntity        <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[4]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	class EHANDLE             m_rgEntities[32];      /*  1140   256 */
	/* --- cacheline 21 boundary (1344 bytes) was 52 bytes ago --- */
	int                        m_rgTriggered[32];    /*  1396   128 */
	/* --- cacheline 23 boundary (1472 bytes) was 52 bytes ago --- */
	int                        m_iTotal;             /*  1524     4 */
	string_t                   m_globalstate;        /*  1528     4 */
	void CMultiSource(class CMultiSource *, class CMultiSource &); /* linkage=_ZN12CMultiSourceC4EOS_ */

	void CMultiSource(class CMultiSource *, const class CMultiSource  &); /* linkage=_ZN12CMultiSourceC4ERKS_ */

	void CMultiSource(class CMultiSource *); /* linkage=_ZN12CMultiSourceC4Ev */

	virtual void Spawn(class CMultiSource *); /* linkage=_ZN12CMultiSource5SpawnEv */

	virtual void KeyValue(class CMultiSource *, KeyValueData *); /* linkage=_ZN12CMultiSource8KeyValueEP14KeyValueData_s */

	virtual void Use(class CMultiSource *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN12CMultiSource3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual int IsTriggered(class CMultiSource *); /* linkage=_ZN12CMultiSource11IsTriggeredEv */

	void Register(class CMultiSource *); /* linkage=_ZN12CMultiSource8RegisterEv */

	virtual int Save(class CMultiSource *, class CSave &); /* linkage=_ZN12CMultiSource4SaveER5CSave */

	virtual int Restore(class CMultiSource *, class CRestore &); /* linkage=_ZN12CMultiSource7RestoreER8CRestore */

	virtual void ~CMultiSource(class CMultiSource *, int); /* linkage=_ZN12CMultiSourceD4Ev */

	/* vtable has 6 entries: {
	   [2] = Spawn(_ZN12CMultiSource5SpawnEv), 
	   [4] = KeyValue(_ZN12CMultiSource8KeyValueEP14KeyValueData_s), 
	   [45] = Use(_ZN12CMultiSource3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [18] = IsTriggered(_ZN12CMultiSource11IsTriggeredEv), 
	   [5] = Save(_ZN12CMultiSource4SaveER5CSave), 
	   [6] = Restore(_ZN12CMultiSource7RestoreER8CRestore), 
	} */
	/* size: 1532, cachelines: 24, members: 5, static members: 1 */
	/* sum members: 392, holes: 1, sum holes: 1140 */
	/* last cacheline: 60 bytes */
};
class CEnvGlobal : public CPointEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CPointEntity        <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[3]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	string_t                   m_globalstate;        /*  1140     4 */
	int                        m_triggermode;        /*  1144     4 */
	int                        m_initialstate;       /*  1148     4 */
	void CEnvGlobal(class CEnvGlobal *, class CEnvGlobal &); /* linkage=_ZN10CEnvGlobalC4EOS_ */

	void CEnvGlobal(class CEnvGlobal *, const class CEnvGlobal  &); /* linkage=_ZN10CEnvGlobalC4ERKS_ */

	void CEnvGlobal(class CEnvGlobal *); /* linkage=_ZN10CEnvGlobalC4Ev */

	virtual void Spawn(class CEnvGlobal *); /* linkage=_ZN10CEnvGlobal5SpawnEv */

	virtual void KeyValue(class CEnvGlobal *, KeyValueData *); /* linkage=_ZN10CEnvGlobal8KeyValueEP14KeyValueData_s */

	virtual void Use(class CEnvGlobal *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN10CEnvGlobal3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual int Save(class CEnvGlobal *, class CSave &); /* linkage=_ZN10CEnvGlobal4SaveER5CSave */

	virtual int Restore(class CEnvGlobal *, class CRestore &); /* linkage=_ZN10CEnvGlobal7RestoreER8CRestore */

	virtual void ~CEnvGlobal(class CEnvGlobal *, int); /* linkage=_ZN10CEnvGlobalD4Ev */

	/* vtable has 5 entries: {
	   [2] = Spawn(_ZN10CEnvGlobal5SpawnEv), 
	   [4] = KeyValue(_ZN10CEnvGlobal8KeyValueEP14KeyValueData_s), 
	   [45] = Use(_ZN10CEnvGlobal3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [5] = Save(_ZN10CEnvGlobal4SaveER5CSave), 
	   [6] = Restore(_ZN10CEnvGlobal7RestoreER8CRestore), 
	} */
	/* size: 1152, cachelines: 18, members: 4, static members: 1 */
	/* sum members: 12, holes: 1, sum holes: 1140 */
};
struct resource_s {
	char                       szFileName[64];       /*     0    64 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	resourcetype_t             type;                 /*    64     4 */
	int                        nIndex;               /*    68     4 */
	int                        nDownloadSize;        /*    72     4 */
	unsigned char              ucFlags;              /*    76     1 */
	unsigned char              rgucMD5_hash[16];     /*    77    16 */
	unsigned char              playernum;            /*    93     1 */
	unsigned char              rguc_reserved[32];    /*    94    32 */

	/* XXX 2 bytes hole, try to pack */

	/* --- cacheline 2 boundary (128 bytes) --- */
	class resource_s *         pNext;                /*   128     4 */
	class resource_s *         pPrev;                /*   132     4 */

	/* size: 136, cachelines: 3, members: 10 */
	/* sum members: 134, holes: 1, sum holes: 2 */
	/* last cacheline: 8 bytes */
};
struct customization_s {
	qboolean                   bInUse;               /*     0     4 */
	resource_t                 resource;             /*     4   136 */
	/* --- cacheline 2 boundary (128 bytes) was 12 bytes ago --- */
	qboolean                   bTranslated;          /*   140     4 */
	int                        nUserData1;           /*   144     4 */
	int                        nUserData2;           /*   148     4 */
	void *                     pInfo;                /*   152     4 */
	void *                     pBuffer;              /*   156     4 */
	class customization_s *    pNext;                /*   160     4 */

	/* size: 164, cachelines: 3, members: 8 */
	/* last cacheline: 36 bytes */
};
struct entity_state_s {
	int                        entityType;           /*     0     4 */
	int                        number;               /*     4     4 */
	float                      msg_time;             /*     8     4 */
	int                        messagenum;           /*    12     4 */
	class Vector              origin;                /*    16    12 */
	class Vector              angles;                /*    28    12 */
	int                        modelindex;           /*    40     4 */
	int                        sequence;             /*    44     4 */
	float                      frame;                /*    48     4 */
	int                        colormap;             /*    52     4 */
	short int                  skin;                 /*    56     2 */
	short int                  solid;                /*    58     2 */
	int                        effects;              /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	float                      scale;                /*    64     4 */
	byte                       eflags;               /*    68     1 */

	/* XXX 3 bytes hole, try to pack */

	int                        rendermode;           /*    72     4 */
	int                        renderamt;            /*    76     4 */
	color24                    rendercolor;          /*    80     3 */

	/* XXX 1 byte hole, try to pack */

	int                        renderfx;             /*    84     4 */
	int                        movetype;             /*    88     4 */
	float                      animtime;             /*    92     4 */
	float                      framerate;            /*    96     4 */
	int                        body;                 /*   100     4 */
	byte                       controller[4];        /*   104     4 */
	byte                       blending[4];          /*   108     4 */
	class Vector              velocity;              /*   112    12 */
	class Vector              mins;                  /*   124    12 */
	/* --- cacheline 2 boundary (128 bytes) was 8 bytes ago --- */
	class Vector              maxs;                  /*   136    12 */
	int                        aiment;               /*   148     4 */
	int                        owner;                /*   152     4 */
	float                      friction;             /*   156     4 */
	float                      gravity;              /*   160     4 */
	int                        team;                 /*   164     4 */
	int                        playerclass;          /*   168     4 */
	int                        health;               /*   172     4 */
	qboolean                   spectator;            /*   176     4 */
	int                        weaponmodel;          /*   180     4 */
	int                        gaitsequence;         /*   184     4 */
	class Vector              basevelocity;          /*   188    12 */
	/* --- cacheline 3 boundary (192 bytes) was 8 bytes ago --- */
	int                        usehull;              /*   200     4 */
	int                        oldbuttons;           /*   204     4 */
	int                        onground;             /*   208     4 */
	int                        iStepLeft;            /*   212     4 */
	float                      flFallVelocity;       /*   216     4 */
	float                      fov;                  /*   220     4 */
	int                        weaponanim;           /*   224     4 */
	class Vector              startpos;              /*   228    12 */
	class Vector              endpos;                /*   240    12 */
	float                      impacttime;           /*   252     4 */
	/* --- cacheline 4 boundary (256 bytes) --- */
	float                      starttime;            /*   256     4 */
	int                        iuser1;               /*   260     4 */
	int                        iuser2;               /*   264     4 */
	int                        iuser3;               /*   268     4 */
	int                        iuser4;               /*   272     4 */
	float                      fuser1;               /*   276     4 */
	float                      fuser2;               /*   280     4 */
	float                      fuser3;               /*   284     4 */
	float                      fuser4;               /*   288     4 */
	class Vector              vuser1;                /*   292    12 */
	class Vector              vuser2;                /*   304    12 */
	class Vector              vuser3;                /*   316    12 */
	/* --- cacheline 5 boundary (320 bytes) was 8 bytes ago --- */
	class Vector              vuser4;                /*   328    12 */
	void entity_state_s(class entity_state_s *); /* linkage=_ZN14entity_state_sC4Ev */


	/* size: 340, cachelines: 6, members: 62 */
	/* sum members: 336, holes: 2, sum holes: 4 */
	/* last cacheline: 20 bytes */
};
struct clientdata_s {
	class Vector              origin;                /*     0    12 */
	class Vector              velocity;              /*    12    12 */
	int                        viewmodel;            /*    24     4 */
	class Vector              punchangle;            /*    28    12 */
	int                        flags;                /*    40     4 */
	int                        waterlevel;           /*    44     4 */
	int                        watertype;            /*    48     4 */
	class Vector              view_ofs;              /*    52    12 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	float                      health;               /*    64     4 */
	int                        bInDuck;              /*    68     4 */
	int                        weapons;              /*    72     4 */
	int                        flTimeStepSound;      /*    76     4 */
	int                        flDuckTime;           /*    80     4 */
	int                        flSwimTime;           /*    84     4 */
	int                        waterjumptime;        /*    88     4 */
	float                      maxspeed;             /*    92     4 */
	float                      fov;                  /*    96     4 */
	int                        weaponanim;           /*   100     4 */
	int                        m_iId;                /*   104     4 */
	int                        ammo_shells;          /*   108     4 */
	int                        ammo_nails;           /*   112     4 */
	int                        ammo_cells;           /*   116     4 */
	int                        ammo_rockets;         /*   120     4 */
	float                      m_flNextAttack;       /*   124     4 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	int                        tfstate;              /*   128     4 */
	int                        pushmsec;             /*   132     4 */
	int                        deadflag;             /*   136     4 */
	char                       physinfo[256];        /*   140   256 */
	/* --- cacheline 6 boundary (384 bytes) was 12 bytes ago --- */
	int                        iuser1;               /*   396     4 */
	int                        iuser2;               /*   400     4 */
	int                        iuser3;               /*   404     4 */
	int                        iuser4;               /*   408     4 */
	float                      fuser1;               /*   412     4 */
	float                      fuser2;               /*   416     4 */
	float                      fuser3;               /*   420     4 */
	float                      fuser4;               /*   424     4 */
	class Vector              vuser1;                /*   428    12 */
	class Vector              vuser2;                /*   440    12 */
	/* --- cacheline 7 boundary (448 bytes) was 4 bytes ago --- */
	class Vector              vuser3;                /*   452    12 */
	class Vector              vuser4;                /*   464    12 */
	void clientdata_s(class clientdata_s *); /* linkage=_ZN12clientdata_sC4Ev */


	/* size: 476, cachelines: 8, members: 40 */
	/* last cacheline: 28 bytes */
};
struct weapon_data_s {
	int                        m_iId;                /*     0     4 */
	int                        m_iClip;              /*     4     4 */
	float                      m_flNextPrimaryAttack; /*     8     4 */
	float                      m_flNextSecondaryAttack; /*    12     4 */
	float                      m_flTimeWeaponIdle;   /*    16     4 */
	int                        m_fInReload;          /*    20     4 */
	int                        m_fInSpecialReload;   /*    24     4 */
	float                      m_flNextReload;       /*    28     4 */
	float                      m_flPumpTime;         /*    32     4 */
	float                      m_fReloadTime;        /*    36     4 */
	float                      m_fAimedDamage;       /*    40     4 */
	float                      m_fNextAimBonus;      /*    44     4 */
	int                        m_fInZoom;            /*    48     4 */
	int                        m_iWeaponState;       /*    52     4 */
	int                        iuser1;               /*    56     4 */
	int                        iuser2;               /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	int                        iuser3;               /*    64     4 */
	int                        iuser4;               /*    68     4 */
	float                      fuser1;               /*    72     4 */
	float                      fuser2;               /*    76     4 */
	float                      fuser3;               /*    80     4 */
	float                      fuser4;               /*    84     4 */

	/* size: 88, cachelines: 2, members: 22 */
	/* last cacheline: 24 bytes */
};
struct usercmd_s {
	short int                  lerp_msec;            /*     0     2 */
	byte                       msec;                 /*     2     1 */

	/* XXX 1 byte hole, try to pack */

	class Vector              viewangles;            /*     4    12 */
	float                      forwardmove;          /*    16     4 */
	float                      sidemove;             /*    20     4 */
	float                      upmove;               /*    24     4 */
	byte                       lightlevel;           /*    28     1 */

	/* XXX 1 byte hole, try to pack */

	short unsigned int         buttons;              /*    30     2 */
	byte                       impulse;              /*    32     1 */
	byte                       weaponselect;         /*    33     1 */

	/* XXX 2 bytes hole, try to pack */

	int                        impact_index;         /*    36     4 */
	class Vector              impact_position;       /*    40    12 */
	void usercmd_s(class usercmd_s *); /* linkage=_ZN9usercmd_sC4Ev */


	/* size: 52, cachelines: 1, members: 12 */
	/* sum members: 48, holes: 3, sum holes: 4 */
	/* last cacheline: 52 bytes */
};
struct netadr_s {
	netadrtype_t               type;                 /*     0     4 */
	unsigned char              ip[4];                /*     4     4 */
	unsigned char              ipx[10];              /*     8    10 */
	short unsigned int         port;                 /*    18     2 */

	/* size: 20, cachelines: 1, members: 4 */
	/* last cacheline: 20 bytes */
};
class CSound {
	class Vector              m_vecOrigin;           /*     0    12 */
	int                        m_iType;              /*    12     4 */
	int                        m_iVolume;            /*    16     4 */
	float                      m_flExpireTime;       /*    20     4 */
	int                        m_iNext;              /*    24     4 */
	int                        m_iNextAudible;       /*    28     4 */
	void CSound(class CSound *); /* linkage=_ZN6CSoundC4Ev */

	void Clear(class CSound *); /* linkage=_ZN6CSound5ClearEv */

	void Reset(class CSound *); /* linkage=_ZN6CSound5ResetEv */

	BOOL FIsSound(class CSound *); /* linkage=_ZN6CSound8FIsSoundEv */

	BOOL FIsScent(class CSound *); /* linkage=_ZN6CSound8FIsScentEv */


	/* size: 32, cachelines: 1, members: 6 */
	/* last cacheline: 32 bytes */
};
class CGib : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	int                        m_bloodColor;         /*  1140     4 */
	int                        m_cBloodDecals;       /*  1144     4 */
	int                        m_material;           /*  1148     4 */
	/* --- cacheline 18 boundary (1152 bytes) --- */
	float                      m_lifeTime;           /*  1152     4 */
	void CGib(class CGib *, class CGib &); /* linkage=_ZN4CGibC4EOS_ */

	void CGib(class CGib *, const class CGib  &); /* linkage=_ZN4CGibC4ERKS_ */

	void CGib(class CGib *); /* linkage=_ZN4CGibC4Ev */

	void Spawn(class CGib *, const char  *); /* linkage=_ZN4CGib5SpawnEPKc */

	void BounceGibTouch(class CGib *, class CBaseEntity *); /* linkage=_ZN4CGib14BounceGibTouchEP11CBaseEntity */

	void StickyGibTouch(class CGib *, class CBaseEntity *); /* linkage=_ZN4CGib14StickyGibTouchEP11CBaseEntity */

	void WaitTillLand(class CGib *); /* linkage=_ZN4CGib12WaitTillLandEv */

	void LimitVelocity(class CGib *); /* linkage=_ZN4CGib13LimitVelocityEv */

	virtual int ObjectCaps(class CGib *); /* linkage=_ZN4CGib10ObjectCapsEv */

	void SpawnHeadGib(entvars_t *); /* linkage=_ZN4CGib12SpawnHeadGibEP9entvars_s */

	void SpawnRandomGibs(entvars_t *, int, int); /* linkage=_ZN4CGib15SpawnRandomGibsEP9entvars_sii */

	void SpawnStickyGibs(entvars_t *, class Vector, int); /* linkage=_ZN4CGib15SpawnStickyGibsEP9entvars_s6Vectori */

	virtual void ~CGib(class CGib *, int); /* linkage=_ZN4CGibD4Ev */

	/* vtable has 1 entries: {
	   [7] = ObjectCaps(_ZN4CGib10ObjectCapsEv), 
	} */
	/* size: 1156, cachelines: 19, members: 5 */
	/* sum members: 16, holes: 1, sum holes: 1140 */
	/* last cacheline: 4 bytes */
};
struct skilldata_t {
	int                        iSkillLevel;          /*     0     4 */
	float                      agruntHealth;         /*     4     4 */
	float                      agruntDmgPunch;       /*     8     4 */
	float                      apacheHealth;         /*    12     4 */
	float                      barneyHealth;         /*    16     4 */
	float                      bigmommaHealthFactor; /*    20     4 */
	float                      bigmommaDmgSlash;     /*    24     4 */
	float                      bigmommaDmgBlast;     /*    28     4 */
	float                      bigmommaRadiusBlast;  /*    32     4 */
	float                      bullsquidHealth;      /*    36     4 */
	float                      bullsquidDmgBite;     /*    40     4 */
	float                      bullsquidDmgWhip;     /*    44     4 */
	float                      bullsquidDmgSpit;     /*    48     4 */
	float                      gargantuaHealth;      /*    52     4 */
	float                      gargantuaDmgSlash;    /*    56     4 */
	float                      gargantuaDmgFire;     /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	float                      gargantuaDmgStomp;    /*    64     4 */
	float                      hassassinHealth;      /*    68     4 */
	float                      headcrabHealth;       /*    72     4 */
	float                      headcrabDmgBite;      /*    76     4 */
	float                      hgruntHealth;         /*    80     4 */
	float                      hgruntDmgKick;        /*    84     4 */
	float                      hgruntShotgunPellets; /*    88     4 */
	float                      hgruntGrenadeSpeed;   /*    92     4 */
	float                      houndeyeHealth;       /*    96     4 */
	float                      houndeyeDmgBlast;     /*   100     4 */
	float                      slaveHealth;          /*   104     4 */
	float                      slaveDmgClaw;         /*   108     4 */
	float                      slaveDmgClawrake;     /*   112     4 */
	float                      slaveDmgZap;          /*   116     4 */
	float                      ichthyosaurHealth;    /*   120     4 */
	float                      ichthyosaurDmgShake;  /*   124     4 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	float                      leechHealth;          /*   128     4 */
	float                      leechDmgBite;         /*   132     4 */
	float                      controllerHealth;     /*   136     4 */
	float                      controllerDmgZap;     /*   140     4 */
	float                      controllerSpeedBall;  /*   144     4 */
	float                      controllerDmgBall;    /*   148     4 */
	float                      nihilanthHealth;      /*   152     4 */
	float                      nihilanthZap;         /*   156     4 */
	float                      scientistHealth;      /*   160     4 */
	float                      snarkHealth;          /*   164     4 */
	float                      snarkDmgBite;         /*   168     4 */
	float                      snarkDmgPop;          /*   172     4 */
	float                      zombieHealth;         /*   176     4 */
	float                      zombieDmgOneSlash;    /*   180     4 */
	float                      zombieDmgBothSlash;   /*   184     4 */
	float                      turretHealth;         /*   188     4 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	float                      miniturretHealth;     /*   192     4 */
	float                      sentryHealth;         /*   196     4 */
	float                      plrDmgCrowbar;        /*   200     4 */
	float                      plrDmg9MM;            /*   204     4 */
	float                      plrDmg357;            /*   208     4 */
	float                      plrDmgMP5;            /*   212     4 */
	float                      plrDmgM203Grenade;    /*   216     4 */
	float                      plrDmgBuckshot;       /*   220     4 */
	float                      plrDmgCrossbowClient; /*   224     4 */
	float                      plrDmgCrossbowMonster; /*   228     4 */
	float                      plrDmgRPG;            /*   232     4 */
	float                      plrDmgGauss;          /*   236     4 */
	float                      plrDmgEgonNarrow;     /*   240     4 */
	float                      plrDmgEgonWide;       /*   244     4 */
	float                      plrDmgHornet;         /*   248     4 */
	float                      plrDmgHandGrenade;    /*   252     4 */
	/* --- cacheline 4 boundary (256 bytes) --- */
	float                      plrDmgSatchel;        /*   256     4 */
	float                      plrDmgTripmine;       /*   260     4 */
	float                      monDmg9MM;            /*   264     4 */
	float                      monDmgMP5;            /*   268     4 */
	float                      monDmg12MM;           /*   272     4 */
	float                      monDmgHornet;         /*   276     4 */
	float                      suitchargerCapacity;  /*   280     4 */
	float                      batteryCapacity;      /*   284     4 */
	float                      healthchargerCapacity; /*   288     4 */
	float                      healthkitCapacity;    /*   292     4 */
	float                      scientistHeal;        /*   296     4 */
	float                      monHead;              /*   300     4 */
	float                      monChest;             /*   304     4 */
	float                      monStomach;           /*   308     4 */
	float                      monLeg;               /*   312     4 */
	float                      monArm;               /*   316     4 */
	/* --- cacheline 5 boundary (320 bytes) --- */
	float                      plrHead;              /*   320     4 */
	float                      plrChest;             /*   324     4 */
	float                      plrStomach;           /*   328     4 */
	float                      plrLeg;               /*   332     4 */
	float                      plrArm;               /*   336     4 */

	/* size: 340, cachelines: 6, members: 85 */
	/* last cacheline: 20 bytes */
};
class CCrowbar : public CBasePlayerWeapon {

	/* XXX 1268 bytes hole, try to pack */
public:


	/* class CBasePlayerWeapon   <ancestor>; */      /*     0     0 */
	/* --- cacheline 19 boundary (1216 bytes) was 52 bytes ago --- */
	int                        m_iSwing;             /*  1268     4 */
	TraceResult                m_trHit;              /*  1272    56 */
	void CCrowbar(class CCrowbar *, class CCrowbar &); /* linkage=_ZN8CCrowbarC4EOS_ */

	void CCrowbar(class CCrowbar *, const class CCrowbar  &); /* linkage=_ZN8CCrowbarC4ERKS_ */

	void CCrowbar(class CCrowbar *); /* linkage=_ZN8CCrowbarC4Ev */

	virtual void Spawn(class CCrowbar *); /* linkage=_ZN8CCrowbar5SpawnEv */

	virtual void Precache(class CCrowbar *); /* linkage=_ZN8CCrowbar8PrecacheEv */

	virtual int iItemSlot(class CCrowbar *); /* linkage=_ZN8CCrowbar9iItemSlotEv */

	void SwingAgain(class CCrowbar *); /* linkage=_ZN8CCrowbar10SwingAgainEv */

	void Smack(class CCrowbar *); /* linkage=_ZN8CCrowbar5SmackEv */

	virtual int GetItemInfo(class CCrowbar *, ItemInfo *); /* linkage=_ZN8CCrowbar11GetItemInfoEP8ItemInfo */

	virtual void PrimaryAttack(class CCrowbar *); /* linkage=_ZN8CCrowbar13PrimaryAttackEv */

	int Swing(class CCrowbar *, int); /* linkage=_ZN8CCrowbar5SwingEi */

	virtual BOOL Deploy(class CCrowbar *); /* linkage=_ZN8CCrowbar6DeployEv */

	virtual void Holster(class CCrowbar *, int); /* linkage=_ZN8CCrowbar7HolsterEi */

	virtual void ~CCrowbar(class CCrowbar *, int); /* linkage=_ZN8CCrowbarD4Ev */

	/* vtable has 7 entries: {
	   [2] = Spawn(_ZN8CCrowbar5SpawnEv), 
	   [3] = Precache(_ZN8CCrowbar8PrecacheEv), 
	   [68] = iItemSlot(_ZN8CCrowbar9iItemSlotEv), 
	   [69] = GetItemInfo(_ZN8CCrowbar11GetItemInfoEP8ItemInfo), 
	   [91] = PrimaryAttack(_ZN8CCrowbar13PrimaryAttackEv), 
	   [71] = Deploy(_ZN8CCrowbar6DeployEv), 
	   [73] = Holster(_ZN8CCrowbar7HolsterEi), 
	} */
	/* size: 1328, cachelines: 21, members: 3 */
	/* sum members: 60, holes: 1, sum holes: 1268 */
	/* last cacheline: 48 bytes */
};
class AddTableColumnDesc {
	const char  *              m_pName;              /*     0     4 */
	ColumnType                 m_Type;               /*     4     4 */
	HCOLUMN *                  m_pColumnHandle;      /*     8     4 */

	/* size: 12, cachelines: 1, members: 3 */
	/* last cacheline: 12 bytes */
};
class IGameDB : public IBaseInterface {
public:

	/* class IBaseInterface      <ancestor>; */      /*     0     4 */
	void IGameDB(class IGameDB *); /* linkage=_ZN7IGameDBC4Ev */

	virtual void ~IGameDB(class IGameDB *, int); /* linkage=_ZN7IGameDBD4Ev */

	virtual void Release(class IGameDB *); /* linkage=_ZN7IGameDB7ReleaseEv */

	virtual void Term(class IGameDB *); /* linkage=_ZN7IGameDB4TermEv */

	virtual bool LoadDB(class IGameDB *, const char  *); /* linkage=_ZN7IGameDB6LoadDBEPKc */

	virtual bool SaveDB(class IGameDB *, const char  *); /* linkage=_ZN7IGameDB6SaveDBEPKc */

	virtual HTABLE AddTable(class IGameDB *, const char  *, int, class AddTableColumnDesc *); /* linkage=_ZN7IGameDB8AddTableEPKciP18AddTableColumnDesc */

	virtual HTABLE AddTable_VA(class IGameDB *, const char  *, int, ...); /* linkage=_ZN7IGameDB11AddTable_VAEPKciz */

	virtual HTABLE GetTable_VA(class IGameDB *, const char  *, int, ...); /* linkage=_ZN7IGameDB11GetTable_VAEPKciz */

	virtual HROW FindRow(class IGameDB *, HTABLE, int, bool, ...); /* linkage=_ZN7IGameDB7FindRowEPN6gamedb5TableEibz */

	virtual HFIELD GetField(class IGameDB *, HROW, HCOLUMN); /* linkage=_ZN7IGameDB8GetFieldEPN6gamedb8TableRowEj */

	virtual bool GetFieldValueInt(class IGameDB *, HFIELD, int32 &); /* linkage=_ZN7IGameDB16GetFieldValueIntEPN6gamedb5FieldERi */

	virtual bool SetFieldValueInt(class IGameDB *, HFIELD, int32); /* linkage=_ZN7IGameDB16SetFieldValueIntEPN6gamedb5FieldEi */

	virtual bool GetFieldValueString(class IGameDB *, HFIELD, char *, uint32); /* linkage=_ZN7IGameDB19GetFieldValueStringEPN6gamedb5FieldEPcj */

	virtual bool SetFieldValueString(class IGameDB *, HFIELD, const char  *); /* linkage=_ZN7IGameDB19SetFieldValueStringEPN6gamedb5FieldEPKc */

	/* vtable has 13 entries: {
	   [2] = Release(_ZN7IGameDB7ReleaseEv), 
	   [3] = Term(_ZN7IGameDB4TermEv), 
	   [4] = LoadDB(_ZN7IGameDB6LoadDBEPKc), 
	   [5] = SaveDB(_ZN7IGameDB6SaveDBEPKc), 
	   [6] = AddTable(_ZN7IGameDB8AddTableEPKciP18AddTableColumnDesc), 
	   [7] = AddTable_VA(_ZN7IGameDB11AddTable_VAEPKciz), 
	   [8] = GetTable_VA(_ZN7IGameDB11GetTable_VAEPKciz), 
	   [9] = FindRow(_ZN7IGameDB7FindRowEPN6gamedb5TableEibz), 
	   [10] = GetField(_ZN7IGameDB8GetFieldEPN6gamedb8TableRowEj), 
	   [11] = GetFieldValueInt(_ZN7IGameDB16GetFieldValueIntEPN6gamedb5FieldERi), 
	   [12] = SetFieldValueInt(_ZN7IGameDB16SetFieldValueIntEPN6gamedb5FieldEi), 
	   [13] = GetFieldValueString(_ZN7IGameDB19GetFieldValueStringEPN6gamedb5FieldEPcj), 
	   [14] = SetFieldValueString(_ZN7IGameDB19SetFieldValueStringEPN6gamedb5FieldEPKc), 
	} */
	/* size: 4, cachelines: 1, members: 1 */
	/* last cacheline: 4 bytes */
};
class IBaseInterface {
	int ()(void) * *           _vptr.IBaseInterface; /*     0     4 */
	void IBaseInterface(class IBaseInterface *, const class IBaseInterface  &); /* linkage=_ZN14IBaseInterfaceC4ERKS_ */

	void IBaseInterface(class IBaseInterface *); /* linkage=_ZN14IBaseInterfaceC4Ev */

	virtual void ~IBaseInterface(class IBaseInterface *, int); /* linkage=_ZN14IBaseInterfaceD4Ev */


	/* size: 4, cachelines: 1, members: 1 */
	/* last cacheline: 4 bytes */
};
struct Task_t {
	int                        iTask;                /*     0     4 */
	float                      flData;               /*     4     4 */

	/* size: 8, cachelines: 1, members: 2 */
	/* last cacheline: 8 bytes */
};
struct Schedule_t {
	class Task_t *             pTasklist;            /*     0     4 */
	int                        cTasks;               /*     4     4 */
	int                        iInterruptMask;       /*     8     4 */
	int                        iSoundMask;           /*    12     4 */
	const char  *              pName;                /*    16     4 */

	/* size: 20, cachelines: 1, members: 5 */
	/* last cacheline: 20 bytes */
};
class CDetpack : public CGrenade {

	/* XXX 1752 bytes hole, try to pack */
public:


	/* class CGrenade            <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 27 boundary (1728 bytes) was 24 bytes ago --- */
	BOOL                       bTicked;              /*  1752     4 */
	BOOL                       bAlternateLight;      /*  1756     4 */
	class CSprite *            m_pBlinkSprite;       /*  1760     4 */
	void CDetpack(class CDetpack *, class CDetpack &); /* linkage=_ZN8CDetpackC4EOS_ */

	void CDetpack(class CDetpack *, const class CDetpack  &); /* linkage=_ZN8CDetpackC4ERKS_ */

	void CDetpack(class CDetpack *); /* linkage=_ZN8CDetpackC4Ev */

	virtual void Spawn(class CDetpack *); /* linkage=_ZN8CDetpack5SpawnEv */

	virtual void Precache(class CDetpack *); /* linkage=_ZN8CDetpack8PrecacheEv */

	virtual int Classify(class CDetpack *); /* linkage=_ZN8CDetpack8ClassifyEv */

	void DetpackTouch(class CDetpack *, class CBaseEntity *); /* linkage=_ZN8CDetpack12DetpackTouchEP11CBaseEntity */

	void DetpackThink(class CDetpack *); /* linkage=_ZN8CDetpack12DetpackThinkEv */

	void DetpackExplode(class CDetpack *); /* linkage=_ZN8CDetpack14DetpackExplodeEv */

	void Remove(class CDetpack *); /* linkage=_ZN8CDetpack6RemoveEv */

	virtual void TeamFortress_TakeEMPBlast(class CDetpack *, entvars_t *); /* linkage=_ZN8CDetpack25TeamFortress_TakeEMPBlastEP9entvars_s */

	virtual void ~CDetpack(class CDetpack *, int); /* linkage=_ZN8CDetpackD4Ev */

	/* vtable has 4 entries: {
	   [2] = Spawn(_ZN8CDetpack5SpawnEv), 
	   [3] = Precache(_ZN8CDetpack8PrecacheEv), 
	   [10] = Classify(_ZN8CDetpack8ClassifyEv), 
	   [61] = TeamFortress_TakeEMPBlast(_ZN8CDetpack25TeamFortress_TakeEMPBlastEP9entvars_s), 
	} */
	/* size: 1764, cachelines: 28, members: 4 */
	/* sum members: 12, holes: 1, sum holes: 1752 */
	/* last cacheline: 36 bytes */
};
struct WayPoint_t {
	class Vector              vecLocation;           /*     0    12 */
	int                        iType;                /*    12     4 */
	void WayPoint_t(class WayPoint_t *); /* linkage=_ZN10WayPoint_tC4Ev */


	/* size: 16, cachelines: 1, members: 2 */
	/* last cacheline: 16 bytes */
};
class CDispenserRefillThinker : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	class EHANDLE             m_hDispenser;          /*  1140     8 */
	class EHANDLE             m_hPlayer;             /*  1148     8 */
	/* --- cacheline 18 boundary (1152 bytes) was 4 bytes ago --- */
	class Vector              m_InitialUsePoint;     /*  1156    12 */
	void CDispenserRefillThinker(class CDispenserRefillThinker *, class CDispenserRefillThinker &); /* linkage=_ZN23CDispenserRefillThinkerC4EOS_ */

	void CDispenserRefillThinker(class CDispenserRefillThinker *, const class CDispenserRefillThinker  &); /* linkage=_ZN23CDispenserRefillThinkerC4ERKS_ */

	void CDispenserRefillThinker(class CDispenserRefillThinker *); /* linkage=_ZN23CDispenserRefillThinkerC4Ev */

	virtual void Spawn(class CDispenserRefillThinker *); /* linkage=_ZN23CDispenserRefillThinker5SpawnEv */

	virtual void Think(class CDispenserRefillThinker *); /* linkage=_ZN23CDispenserRefillThinker5ThinkEv */

	void StartRefillingPlayer(class CDispenserRefillThinker *, class CBaseEntity *, class CTFDispenser *, float); /* linkage=_ZN23CDispenserRefillThinker20StartRefillingPlayerEP11CBaseEntityP12CTFDispenserf */

	virtual void ~CDispenserRefillThinker(class CDispenserRefillThinker *, int); /* linkage=_ZN23CDispenserRefillThinkerD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN23CDispenserRefillThinker5SpawnEv), 
	   [43] = Think(_ZN23CDispenserRefillThinker5ThinkEv), 
	} */
	/* size: 1168, cachelines: 19, members: 4 */
	/* sum members: 28, holes: 1, sum holes: 1140 */
	/* last cacheline: 16 bytes */
};
class CTFDispenser : public CBaseMonster {

	/* XXX 1724 bytes hole, try to pack */
public:


	/* class CBaseMonster        <ancestor>; */      /*     0     0 */
	/* --- cacheline 26 boundary (1664 bytes) was 60 bytes ago --- */
	int                        m_iShardIndex;        /*  1724     4 */
	/* --- cacheline 27 boundary (1728 bytes) --- */
	float                      m_flNextUseTime;      /*  1728     4 */
	float                      m_flInitialUseDelay;  /*  1732     4 */
	float                      m_flNextRefillTime;   /*  1736     4 */
	int                        m_iDestroyed;         /*  1740     4 */
	void CTFDispenser(class CTFDispenser *, class CTFDispenser &); /* linkage=_ZN12CTFDispenserC4EOS_ */

	void CTFDispenser(class CTFDispenser *, const class CTFDispenser  &); /* linkage=_ZN12CTFDispenserC4ERKS_ */

	void CTFDispenser(class CTFDispenser *); /* linkage=_ZN12CTFDispenserC4Ev */

	virtual void Spawn(class CTFDispenser *); /* linkage=_ZN12CTFDispenser5SpawnEv */

	virtual void Precache(class CTFDispenser *); /* linkage=_ZN12CTFDispenser8PrecacheEv */

	void Dispenser_Explode(class CTFDispenser *); /* linkage=_ZN12CTFDispenser17Dispenser_ExplodeEv */

	void DispenserThink(class CTFDispenser *); /* linkage=_ZN12CTFDispenser14DispenserThinkEv */

	void DispenserTouch(class CTFDispenser *, class CBaseEntity *); /* linkage=_ZN12CTFDispenser14DispenserTouchEP11CBaseEntity */

	virtual int Classify(class CTFDispenser *); /* linkage=_ZN12CTFDispenser8ClassifyEv */

	virtual int BloodColor(class CTFDispenser *); /* linkage=_ZN12CTFDispenser10BloodColorEv */

	void Remove(class CTFDispenser *); /* linkage=_ZN12CTFDispenser6RemoveEv */

	virtual void TeamFortress_TakeEMPBlast(class CTFDispenser *, entvars_t *); /* linkage=_ZN12CTFDispenser25TeamFortress_TakeEMPBlastEP9entvars_s */

	virtual void Finished(class CTFDispenser *); /* linkage=_ZN12CTFDispenser8FinishedEv */

	class CTFDispenser * CreateDispenser(class Vector, class Vector, class CBaseEntity *); /* linkage=_ZN12CTFDispenser15CreateDispenserE6VectorS0_P11CBaseEntity */

	virtual BOOL EngineerUse(class CTFDispenser *, class CBasePlayer *); /* linkage=_ZN12CTFDispenser11EngineerUseEP11CBasePlayer */

	virtual void Killed(class CTFDispenser *, entvars_t *, entvars_t *, int); /* linkage=_ZN12CTFDispenser6KilledEP9entvars_sS1_i */

	BOOL RefillPlayer(class CTFDispenser *, class CBasePlayer *); /* linkage=_ZN12CTFDispenser12RefillPlayerEP11CBasePlayer */

	virtual void ~CTFDispenser(class CTFDispenser *, int); /* linkage=_ZN12CTFDispenserD4Ev */

	/* vtable has 8 entries: {
	   [2] = Spawn(_ZN12CTFDispenser5SpawnEv), 
	   [3] = Precache(_ZN12CTFDispenser8PrecacheEv), 
	   [10] = Classify(_ZN12CTFDispenser8ClassifyEv), 
	   [16] = BloodColor(_ZN12CTFDispenser10BloodColorEv), 
	   [61] = TeamFortress_TakeEMPBlast(_ZN12CTFDispenser25TeamFortress_TakeEMPBlastEP9entvars_s), 
	   [58] = Finished(_ZN12CTFDispenser8FinishedEv), 
	   [57] = EngineerUse(_ZN12CTFDispenser11EngineerUseEP11CBasePlayer), 
	   [15] = Killed(_ZN12CTFDispenser6KilledEP9entvars_sS1_i), 
	} */
	/* size: 1744, cachelines: 28, members: 6 */
	/* sum members: 20, holes: 1, sum holes: 1724 */
	/* last cacheline: 16 bytes */
};
class CMomentaryDoor : public CBaseToggle {

	/* XXX 1300 bytes hole, try to pack */
public:


	/* class CBaseToggle         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[1]; /*     0     0 */
	/* --- cacheline 20 boundary (1280 bytes) was 20 bytes ago --- */
	BYTE                       m_bMoveSnd;           /*  1300     1 */
	void CMomentaryDoor(class CMomentaryDoor *, class CMomentaryDoor &); /* linkage=_ZN14CMomentaryDoorC4EOS_ */

	void CMomentaryDoor(class CMomentaryDoor *, const class CMomentaryDoor  &); /* linkage=_ZN14CMomentaryDoorC4ERKS_ */

	void CMomentaryDoor(class CMomentaryDoor *); /* linkage=_ZN14CMomentaryDoorC4Ev */

	virtual void Spawn(class CMomentaryDoor *); /* linkage=_ZN14CMomentaryDoor5SpawnEv */

	virtual void Precache(class CMomentaryDoor *); /* linkage=_ZN14CMomentaryDoor8PrecacheEv */

	virtual void KeyValue(class CMomentaryDoor *, KeyValueData *); /* linkage=_ZN14CMomentaryDoor8KeyValueEP14KeyValueData_s */

	virtual void Use(class CMomentaryDoor *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN14CMomentaryDoor3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual int ObjectCaps(class CMomentaryDoor *); /* linkage=_ZN14CMomentaryDoor10ObjectCapsEv */

	virtual int Save(class CMomentaryDoor *, class CSave &); /* linkage=_ZN14CMomentaryDoor4SaveER5CSave */

	virtual int Restore(class CMomentaryDoor *, class CRestore &); /* linkage=_ZN14CMomentaryDoor7RestoreER8CRestore */

	void DoorMoveDone(class CMomentaryDoor *); /* linkage=_ZN14CMomentaryDoor12DoorMoveDoneEv */

	virtual void ~CMomentaryDoor(class CMomentaryDoor *, int); /* linkage=_ZN14CMomentaryDoorD4Ev */

	/* vtable has 7 entries: {
	   [2] = Spawn(_ZN14CMomentaryDoor5SpawnEv), 
	   [3] = Precache(_ZN14CMomentaryDoor8PrecacheEv), 
	   [4] = KeyValue(_ZN14CMomentaryDoor8KeyValueEP14KeyValueData_s), 
	   [45] = Use(_ZN14CMomentaryDoor3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [7] = ObjectCaps(_ZN14CMomentaryDoor10ObjectCapsEv), 
	   [5] = Save(_ZN14CMomentaryDoor4SaveER5CSave), 
	   [6] = Restore(_ZN14CMomentaryDoor7RestoreER8CRestore), 
	} */
	/* size: 1304, cachelines: 21, members: 2, static members: 1 */
	/* sum members: 1, holes: 1, sum holes: 1300 */
	/* padding: 3 */
	/* last cacheline: 24 bytes */
};
class CRotDoor : public CBaseDoor {
public:

	/* class CBaseDoor           <ancestor>; */      /*     0  1360 */

	/* XXX last struct has 2 bytes of padding, 2 holes */
	void CRotDoor(class CRotDoor *, class CRotDoor &); /* linkage=_ZN8CRotDoorC4EOS_ */

	void CRotDoor(class CRotDoor *, const class CRotDoor  &); /* linkage=_ZN8CRotDoorC4ERKS_ */

	void CRotDoor(class CRotDoor *); /* linkage=_ZN8CRotDoorC4Ev */

	virtual void Spawn(class CRotDoor *); /* linkage=_ZN8CRotDoor5SpawnEv */

	virtual void SetToggleState(class CRotDoor *, int); /* linkage=_ZN8CRotDoor14SetToggleStateEi */

	virtual void ~CRotDoor(class CRotDoor *, int); /* linkage=_ZN8CRotDoorD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN8CRotDoor5SpawnEv), 
	   [29] = SetToggleState(_ZN8CRotDoor14SetToggleStateEi), 
	} */
	/* size: 1360, cachelines: 22, members: 1 */
	/* member types with holes: 1, total: 2 */
	/* paddings: 1, sum paddings: 2 */
	/* last cacheline: 16 bytes */
};
class CBaseDoor : public CBaseToggle {

	/* XXX 1300 bytes hole, try to pack */
public:


	/* class CBaseToggle         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[7]; /*     0     0 */
	/* --- cacheline 20 boundary (1280 bytes) was 20 bytes ago --- */
	BYTE                       m_bHealthValue;       /*  1300     1 */
	BYTE                       m_bMoveSnd;           /*  1301     1 */
	BYTE                       m_bStopSnd;           /*  1302     1 */

	/* XXX 1 byte hole, try to pack */

	locksound_t                m_ls;                 /*  1304    36 */
	BYTE                       m_bLockedSound;       /*  1340     1 */
	BYTE                       m_bLockedSentence;    /*  1341     1 */
	BYTE                       m_bUnlockedSound;     /*  1342     1 */
	BYTE                       m_bUnlockedSentence;  /*  1343     1 */
	/* --- cacheline 21 boundary (1344 bytes) --- */
	float                      m_fNextSoundPlay;     /*  1344     4 */
	bool                       m_bIsReopening;       /*  1348     1 */
	bool                       m_bStoppedOpenSound;  /*  1349     1 */
private:

	short unsigned int         m_usDoorGoUp;         /*  1350     2 */
	short unsigned int         m_usDoorGoDown;       /*  1352     2 */
	short unsigned int         m_usDoorHitTop;       /*  1354     2 */
	short unsigned int         m_usDoorHitBottom;    /*  1356     2 */
	void CBaseDoor(class CBaseDoor *, class CBaseDoor &); /* linkage=_ZN9CBaseDoorC4EOS_ */

	void CBaseDoor(class CBaseDoor *, const class CBaseDoor  &); /* linkage=_ZN9CBaseDoorC4ERKS_ */

	void CBaseDoor(class CBaseDoor *); /* linkage=_ZN9CBaseDoorC4Ev */

	virtual void Spawn(class CBaseDoor *); /* linkage=_ZN9CBaseDoor5SpawnEv */

	virtual void Precache(class CBaseDoor *); /* linkage=_ZN9CBaseDoor8PrecacheEv */

	virtual void KeyValue(class CBaseDoor *, KeyValueData *); /* linkage=_ZN9CBaseDoor8KeyValueEP14KeyValueData_s */

	virtual void Use(class CBaseDoor *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN9CBaseDoor3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void Blocked(class CBaseDoor *, class CBaseEntity *); /* linkage=_ZN9CBaseDoor7BlockedEP11CBaseEntity */

	virtual int ObjectCaps(class CBaseDoor *); /* linkage=_ZN9CBaseDoor10ObjectCapsEv */

	virtual int Save(class CBaseDoor *, class CSave &); /* linkage=_ZN9CBaseDoor4SaveER5CSave */

	virtual int Restore(class CBaseDoor *, class CRestore &); /* linkage=_ZN9CBaseDoor7RestoreER8CRestore */

	virtual void SetToggleState(class CBaseDoor *, int); /* linkage=_ZN9CBaseDoor14SetToggleStateEi */

	void DoorTouch(class CBaseDoor *, class CBaseEntity *); /* linkage=_ZN9CBaseDoor9DoorTouchEP11CBaseEntity */

	int DoorActivate(class CBaseDoor *); /* linkage=_ZN9CBaseDoor12DoorActivateEv */

	void DoorGoUp(class CBaseDoor *); /* linkage=_ZN9CBaseDoor8DoorGoUpEv */

	void DoorGoDown(class CBaseDoor *); /* linkage=_ZN9CBaseDoor10DoorGoDownEv */

	void DoorHitTop(class CBaseDoor *); /* linkage=_ZN9CBaseDoor10DoorHitTopEv */

	void DoorHitBottom(class CBaseDoor *); /* linkage=_ZN9CBaseDoor13DoorHitBottomEv */

	virtual void ~CBaseDoor(class CBaseDoor *, int); /* linkage=_ZN9CBaseDoorD4Ev */

	/* vtable has 9 entries: {
	   [2] = Spawn(_ZN9CBaseDoor5SpawnEv), 
	   [3] = Precache(_ZN9CBaseDoor8PrecacheEv), 
	   [4] = KeyValue(_ZN9CBaseDoor8KeyValueEP14KeyValueData_s), 
	   [45] = Use(_ZN9CBaseDoor3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [46] = Blocked(_ZN9CBaseDoor7BlockedEP11CBaseEntity), 
	   [7] = ObjectCaps(_ZN9CBaseDoor10ObjectCapsEv), 
	   [5] = Save(_ZN9CBaseDoor4SaveER5CSave), 
	   [6] = Restore(_ZN9CBaseDoor7RestoreER8CRestore), 
	   [29] = SetToggleState(_ZN9CBaseDoor14SetToggleStateEi), 
	} */
	/* size: 1360, cachelines: 22, members: 16, static members: 1 */
	/* sum members: 57, holes: 2, sum holes: 1301 */
	/* padding: 2 */
	/* last cacheline: 16 bytes */
};
class CItemSoda : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CItemSoda(class CItemSoda *, class CItemSoda &); /* linkage=_ZN9CItemSodaC4EOS_ */

	void CItemSoda(class CItemSoda *, const class CItemSoda  &); /* linkage=_ZN9CItemSodaC4ERKS_ */

	void CItemSoda(class CItemSoda *); /* linkage=_ZN9CItemSodaC4Ev */

	virtual void Spawn(class CItemSoda *); /* linkage=_ZN9CItemSoda5SpawnEv */

	virtual void Precache(class CItemSoda *); /* linkage=_ZN9CItemSoda8PrecacheEv */

	void CanThink(class CItemSoda *); /* linkage=_ZN9CItemSoda8CanThinkEv */

	void CanTouch(class CItemSoda *, class CBaseEntity *); /* linkage=_ZN9CItemSoda8CanTouchEP11CBaseEntity */

	virtual void ~CItemSoda(class CItemSoda *, int); /* linkage=_ZN9CItemSodaD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN9CItemSoda5SpawnEv), 
	   [3] = Precache(_ZN9CItemSoda8PrecacheEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CEnvBeverage : public CBaseDelay {
public:

	/* class CBaseDelay          <ancestor>; */      /*     0     0 */
	void CEnvBeverage(class CEnvBeverage *, class CEnvBeverage &); /* linkage=_ZN12CEnvBeverageC4EOS_ */

	void CEnvBeverage(class CEnvBeverage *, const class CEnvBeverage  &); /* linkage=_ZN12CEnvBeverageC4ERKS_ */

	void CEnvBeverage(class CEnvBeverage *); /* linkage=_ZN12CEnvBeverageC4Ev */

	virtual void Spawn(class CEnvBeverage *); /* linkage=_ZN12CEnvBeverage5SpawnEv */

	virtual void Precache(class CEnvBeverage *); /* linkage=_ZN12CEnvBeverage8PrecacheEv */

	virtual void Use(class CEnvBeverage *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN12CEnvBeverage3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void ~CEnvBeverage(class CEnvBeverage *, int); /* linkage=_ZN12CEnvBeverageD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN12CEnvBeverage5SpawnEv), 
	   [3] = Precache(_ZN12CEnvBeverage8PrecacheEv), 
	   [45] = Use(_ZN12CEnvBeverage3UseEP11CBaseEntityS1_8USE_TYPEf), 
	} */
	/* size: 1148, cachelines: 18, members: 1 */
	/* padding: 1148 */
	/* last cacheline: 60 bytes */
};
class CEnvFunnel : public CBaseDelay {

	/* XXX 1148 bytes hole, try to pack */
public:


	/* class CBaseDelay          <ancestor>; */      /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 60 bytes ago --- */
	int                        m_iSprite;            /*  1148     4 */
	void CEnvFunnel(class CEnvFunnel *, class CEnvFunnel &); /* linkage=_ZN10CEnvFunnelC4EOS_ */

	void CEnvFunnel(class CEnvFunnel *, const class CEnvFunnel  &); /* linkage=_ZN10CEnvFunnelC4ERKS_ */

	void CEnvFunnel(class CEnvFunnel *); /* linkage=_ZN10CEnvFunnelC4Ev */

	virtual void Spawn(class CEnvFunnel *); /* linkage=_ZN10CEnvFunnel5SpawnEv */

	virtual void Precache(class CEnvFunnel *); /* linkage=_ZN10CEnvFunnel8PrecacheEv */

	virtual void Use(class CEnvFunnel *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN10CEnvFunnel3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void ~CEnvFunnel(class CEnvFunnel *, int); /* linkage=_ZN10CEnvFunnelD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN10CEnvFunnel5SpawnEv), 
	   [3] = Precache(_ZN10CEnvFunnel8PrecacheEv), 
	   [45] = Use(_ZN10CEnvFunnel3UseEP11CBaseEntityS1_8USE_TYPEf), 
	} */
	/* size: 1152, cachelines: 18, members: 2 */
	/* sum members: 4, holes: 1, sum holes: 1148 */
};
class CMessage : public CPointEntity {
public:

	/* class CPointEntity        <ancestor>; */      /*     0     0 */
	void CMessage(class CMessage *, class CMessage &); /* linkage=_ZN8CMessageC4EOS_ */

	void CMessage(class CMessage *, const class CMessage  &); /* linkage=_ZN8CMessageC4ERKS_ */

	void CMessage(class CMessage *); /* linkage=_ZN8CMessageC4Ev */

	virtual void Spawn(class CMessage *); /* linkage=_ZN8CMessage5SpawnEv */

	virtual void Precache(class CMessage *); /* linkage=_ZN8CMessage8PrecacheEv */

	virtual void Use(class CMessage *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN8CMessage3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void KeyValue(class CMessage *, KeyValueData *); /* linkage=_ZN8CMessage8KeyValueEP14KeyValueData_s */

	virtual void ~CMessage(class CMessage *, int); /* linkage=_ZN8CMessageD4Ev */

	/* vtable has 4 entries: {
	   [2] = Spawn(_ZN8CMessage5SpawnEv), 
	   [3] = Precache(_ZN8CMessage8PrecacheEv), 
	   [45] = Use(_ZN8CMessage3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [4] = KeyValue(_ZN8CMessage8KeyValueEP14KeyValueData_s), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CFade : public CPointEntity {
public:

	/* class CPointEntity        <ancestor>; */      /*     0     0 */
	void CFade(class CFade *, class CFade &); /* linkage=_ZN5CFadeC4EOS_ */

	void CFade(class CFade *, const class CFade  &); /* linkage=_ZN5CFadeC4ERKS_ */

	void CFade(class CFade *); /* linkage=_ZN5CFadeC4Ev */

	virtual void Spawn(class CFade *); /* linkage=_ZN5CFade5SpawnEv */

	virtual void Use(class CFade *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN5CFade3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void KeyValue(class CFade *, KeyValueData *); /* linkage=_ZN5CFade8KeyValueEP14KeyValueData_s */

	float Duration(class CFade *); /* linkage=_ZN5CFade8DurationEv */

	float HoldTime(class CFade *); /* linkage=_ZN5CFade8HoldTimeEv */

	void SetDuration(class CFade *, float); /* linkage=_ZN5CFade11SetDurationEf */

	void SetHoldTime(class CFade *, float); /* linkage=_ZN5CFade11SetHoldTimeEf */

	virtual void ~CFade(class CFade *, int); /* linkage=_ZN5CFadeD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN5CFade5SpawnEv), 
	   [45] = Use(_ZN5CFade3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [4] = KeyValue(_ZN5CFade8KeyValueEP14KeyValueData_s), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CShake : public CPointEntity {
public:

	/* class CPointEntity        <ancestor>; */      /*     0     0 */
	void CShake(class CShake *, class CShake &); /* linkage=_ZN6CShakeC4EOS_ */

	void CShake(class CShake *, const class CShake  &); /* linkage=_ZN6CShakeC4ERKS_ */

	void CShake(class CShake *); /* linkage=_ZN6CShakeC4Ev */

	virtual void Spawn(class CShake *); /* linkage=_ZN6CShake5SpawnEv */

	virtual void Use(class CShake *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN6CShake3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void KeyValue(class CShake *, KeyValueData *); /* linkage=_ZN6CShake8KeyValueEP14KeyValueData_s */

	float Amplitude(class CShake *); /* linkage=_ZN6CShake9AmplitudeEv */

	float Frequency(class CShake *); /* linkage=_ZN6CShake9FrequencyEv */

	float Duration(class CShake *); /* linkage=_ZN6CShake8DurationEv */

	float Radius(class CShake *); /* linkage=_ZN6CShake6RadiusEv */

	void SetAmplitude(class CShake *, float); /* linkage=_ZN6CShake12SetAmplitudeEf */

	void SetFrequency(class CShake *, float); /* linkage=_ZN6CShake12SetFrequencyEf */

	void SetDuration(class CShake *, float); /* linkage=_ZN6CShake11SetDurationEf */

	void SetRadius(class CShake *, float); /* linkage=_ZN6CShake9SetRadiusEf */

	virtual void ~CShake(class CShake *, int); /* linkage=_ZN6CShakeD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN6CShake5SpawnEv), 
	   [45] = Use(_ZN6CShake3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [4] = KeyValue(_ZN6CShake8KeyValueEP14KeyValueData_s), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CBlood : public CPointEntity {
public:

	/* class CPointEntity        <ancestor>; */      /*     0     0 */
	void CBlood(class CBlood *, class CBlood &); /* linkage=_ZN6CBloodC4EOS_ */

	void CBlood(class CBlood *, const class CBlood  &); /* linkage=_ZN6CBloodC4ERKS_ */

	void CBlood(class CBlood *); /* linkage=_ZN6CBloodC4Ev */

	virtual void Spawn(class CBlood *); /* linkage=_ZN6CBlood5SpawnEv */

	virtual void Use(class CBlood *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN6CBlood3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void KeyValue(class CBlood *, KeyValueData *); /* linkage=_ZN6CBlood8KeyValueEP14KeyValueData_s */

	int Color(class CBlood *); /* linkage=_ZN6CBlood5ColorEv */

	float BloodAmount(class CBlood *); /* linkage=_ZN6CBlood11BloodAmountEv */

	void SetColor(class CBlood *, int); /* linkage=_ZN6CBlood8SetColorEi */

	void SetBloodAmount(class CBlood *, float); /* linkage=_ZN6CBlood14SetBloodAmountEf */

	class Vector Direction(class CBlood *); /* linkage=_ZN6CBlood9DirectionEv */

	class Vector BloodPosition(class CBlood *, class CBaseEntity *); /* linkage=_ZN6CBlood13BloodPositionEP11CBaseEntity */

	virtual void ~CBlood(class CBlood *, int); /* linkage=_ZN6CBloodD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN6CBlood5SpawnEv), 
	   [45] = Use(_ZN6CBlood3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [4] = KeyValue(_ZN6CBlood8KeyValueEP14KeyValueData_s), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CTestEffect : public CBaseDelay {

	/* XXX 1148 bytes hole, try to pack */
public:


	/* class CBaseDelay          <ancestor>; */      /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 60 bytes ago --- */
	int                        m_iLoop;              /*  1148     4 */
	/* --- cacheline 18 boundary (1152 bytes) --- */
	int                        m_iBeam;              /*  1152     4 */
	class CBeam *              m_pBeam[24];          /*  1156    96 */
	/* --- cacheline 19 boundary (1216 bytes) was 36 bytes ago --- */
	float                      m_flBeamTime[24];     /*  1252    96 */
	/* --- cacheline 21 boundary (1344 bytes) was 4 bytes ago --- */
	float                      m_flStartTime;        /*  1348     4 */
	void CTestEffect(class CTestEffect *, class CTestEffect &); /* linkage=_ZN11CTestEffectC4EOS_ */

	void CTestEffect(class CTestEffect *, const class CTestEffect  &); /* linkage=_ZN11CTestEffectC4ERKS_ */

	void CTestEffect(class CTestEffect *); /* linkage=_ZN11CTestEffectC4Ev */

	virtual void Spawn(class CTestEffect *); /* linkage=_ZN11CTestEffect5SpawnEv */

	virtual void Precache(class CTestEffect *); /* linkage=_ZN11CTestEffect8PrecacheEv */

	void TestThink(class CTestEffect *); /* linkage=_ZN11CTestEffect9TestThinkEv */

	virtual void Use(class CTestEffect *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN11CTestEffect3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void ~CTestEffect(class CTestEffect *, int); /* linkage=_ZN11CTestEffectD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN11CTestEffect5SpawnEv), 
	   [3] = Precache(_ZN11CTestEffect8PrecacheEv), 
	   [45] = Use(_ZN11CTestEffect3UseEP11CBaseEntityS1_8USE_TYPEf), 
	} */
	/* size: 1352, cachelines: 22, members: 6 */
	/* sum members: 204, holes: 1, sum holes: 1148 */
	/* last cacheline: 8 bytes */
};
class CBeam : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CBeam(class CBeam *, class CBeam &); /* linkage=_ZN5CBeamC4EOS_ */

	void CBeam(class CBeam *, const class CBeam  &); /* linkage=_ZN5CBeamC4ERKS_ */

	void CBeam(class CBeam *); /* linkage=_ZN5CBeamC4Ev */

	virtual void Spawn(class CBeam *); /* linkage=_ZN5CBeam5SpawnEv */

	virtual void Precache(class CBeam *); /* linkage=_ZN5CBeam8PrecacheEv */

	virtual int ObjectCaps(class CBeam *); /* linkage=_ZN5CBeam10ObjectCapsEv */

	void TriggerTouch(class CBeam *, class CBaseEntity *); /* linkage=_ZN5CBeam12TriggerTouchEP11CBaseEntity */

	void SetType(class CBeam *, int); /* linkage=_ZN5CBeam7SetTypeEi */

	void SetFlags(class CBeam *, int); /* linkage=_ZN5CBeam8SetFlagsEi */

	void SetStartPos(class CBeam *, const class Vector  &); /* linkage=_ZN5CBeam11SetStartPosERK6Vector */

	void SetEndPos(class CBeam *, const class Vector  &); /* linkage=_ZN5CBeam9SetEndPosERK6Vector */

	void SetStartEntity(class CBeam *, int); /* linkage=_ZN5CBeam14SetStartEntityEi */

	void SetEndEntity(class CBeam *, int); /* linkage=_ZN5CBeam12SetEndEntityEi */

	void SetStartAttachment(class CBeam *, int); /* linkage=_ZN5CBeam18SetStartAttachmentEi */

	void SetEndAttachment(class CBeam *, int); /* linkage=_ZN5CBeam16SetEndAttachmentEi */

	void SetTexture(class CBeam *, int); /* linkage=_ZN5CBeam10SetTextureEi */

	void SetWidth(class CBeam *, int); /* linkage=_ZN5CBeam8SetWidthEi */

	void SetNoise(class CBeam *, int); /* linkage=_ZN5CBeam8SetNoiseEi */

	void SetColor(class CBeam *, int, int, int); /* linkage=_ZN5CBeam8SetColorEiii */

	void SetBrightness(class CBeam *, int); /* linkage=_ZN5CBeam13SetBrightnessEi */

	void SetFrame(class CBeam *, float); /* linkage=_ZN5CBeam8SetFrameEf */

	void SetScrollRate(class CBeam *, int); /* linkage=_ZN5CBeam13SetScrollRateEi */

	int GetType(class CBeam *); /* linkage=_ZN5CBeam7GetTypeEv */

	int GetFlags(class CBeam *); /* linkage=_ZN5CBeam8GetFlagsEv */

	int GetStartEntity(class CBeam *); /* linkage=_ZN5CBeam14GetStartEntityEv */

	int GetEndEntity(class CBeam *); /* linkage=_ZN5CBeam12GetEndEntityEv */

	const class Vector  & GetStartPos(class CBeam *); /* linkage=_ZN5CBeam11GetStartPosEv */

	const class Vector  & GetEndPos(class CBeam *); /* linkage=_ZN5CBeam9GetEndPosEv */

	virtual class Vector Center(class CBeam *); /* linkage=_ZN5CBeam6CenterEv */

	int GetTexture(class CBeam *); /* linkage=_ZN5CBeam10GetTextureEv */

	int GetWidth(class CBeam *); /* linkage=_ZN5CBeam8GetWidthEv */

	int GetNoise(class CBeam *); /* linkage=_ZN5CBeam8GetNoiseEv */

	int GetBrightness(class CBeam *); /* linkage=_ZN5CBeam13GetBrightnessEv */

	int GetFrame(class CBeam *); /* linkage=_ZN5CBeam8GetFrameEv */

	int GetScrollRate(class CBeam *); /* linkage=_ZN5CBeam13GetScrollRateEv */

	void RelinkBeam(class CBeam *); /* linkage=_ZN5CBeam10RelinkBeamEv */

	void DoSparks(class CBeam *, const class Vector  &, const class Vector  &); /* linkage=_ZN5CBeam8DoSparksERK6VectorS2_ */

	class CBaseEntity * RandomTargetname(class CBeam *, const char  *); /* linkage=_ZN5CBeam16RandomTargetnameEPKc */

	void BeamDamage(class CBeam *, class  *); /* linkage=_ZN5CBeam10BeamDamageEP11TraceResult */

	void BeamInit(class CBeam *, const char  *, int); /* linkage=_ZN5CBeam8BeamInitEPKci */

	void PointsInit(class CBeam *, const class Vector  &, const class Vector  &); /* linkage=_ZN5CBeam10PointsInitERK6VectorS2_ */

	void PointEntInit(class CBeam *, const class Vector  &, int); /* linkage=_ZN5CBeam12PointEntInitERK6Vectori */

	void EntsInit(class CBeam *, int, int); /* linkage=_ZN5CBeam8EntsInitEii */

	void HoseInit(class CBeam *, const class Vector  &, const class Vector  &); /* linkage=_ZN5CBeam8HoseInitERK6VectorS2_ */

	class CBeam * BeamCreate(const char  *, int); /* linkage=_ZN5CBeam10BeamCreateEPKci */

	void LiveForTime(class CBeam *, float); /* linkage=_ZN5CBeam11LiveForTimeEf */

	void BeamDamageInstant(class CBeam *, class  *, float); /* linkage=_ZN5CBeam17BeamDamageInstantEP11TraceResultf */

	virtual void ~CBeam(class CBeam *, int); /* linkage=_ZN5CBeamD4Ev */

	/* vtable has 4 entries: {
	   [2] = Spawn(_ZN5CBeam5SpawnEv), 
	   [3] = Precache(_ZN5CBeam8PrecacheEv), 
	   [7] = ObjectCaps(_ZN5CBeam10ObjectCapsEv), 
	   [50] = Center(_ZN5CBeam6CenterEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CEnvShooter : public CGibShooter {
public:

	/* class CGibShooter         <ancestor>; */      /*     0  1176 */

	/* XXX last struct has 1 hole */
	void CEnvShooter(class CEnvShooter *, class CEnvShooter &); /* linkage=_ZN11CEnvShooterC4EOS_ */

	void CEnvShooter(class CEnvShooter *, const class CEnvShooter  &); /* linkage=_ZN11CEnvShooterC4ERKS_ */

	void CEnvShooter(class CEnvShooter *); /* linkage=_ZN11CEnvShooterC4Ev */

private:

	virtual void Precache(class CEnvShooter *); /* linkage=_ZN11CEnvShooter8PrecacheEv */

	virtual void KeyValue(class CEnvShooter *, KeyValueData *); /* linkage=_ZN11CEnvShooter8KeyValueEP14KeyValueData_s */

	virtual class CGib * CreateGib(class CEnvShooter *); /* linkage=_ZN11CEnvShooter9CreateGibEv */

	virtual void ~CEnvShooter(class CEnvShooter *, int); /* linkage=_ZN11CEnvShooterD4Ev */

	/* vtable has 3 entries: {
	   [3] = Precache(_ZN11CEnvShooter8PrecacheEv), 
	   [4] = KeyValue(_ZN11CEnvShooter8KeyValueEP14KeyValueData_s), 
	   [65] = CreateGib(_ZN11CEnvShooter9CreateGibEv), 
	} */
	/* size: 1176, cachelines: 19, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 24 bytes */
};
class CGibShooter : public CBaseDelay {

	/* XXX 1148 bytes hole, try to pack */
public:


	/* class CBaseDelay          <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[7]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 60 bytes ago --- */
	int                        m_iGibs;              /*  1148     4 */
	/* --- cacheline 18 boundary (1152 bytes) --- */
	int                        m_iGibCapacity;       /*  1152     4 */
	int                        m_iGibMaterial;       /*  1156     4 */
	int                        m_iGibModelIndex;     /*  1160     4 */
	float                      m_flGibVelocity;      /*  1164     4 */
	float                      m_flVariance;         /*  1168     4 */
	float                      m_flGibLife;          /*  1172     4 */
	void CGibShooter(class CGibShooter *, class CGibShooter &); /* linkage=_ZN11CGibShooterC4EOS_ */

	void CGibShooter(class CGibShooter *, const class CGibShooter  &); /* linkage=_ZN11CGibShooterC4ERKS_ */

	void CGibShooter(class CGibShooter *); /* linkage=_ZN11CGibShooterC4Ev */

	virtual void Spawn(class CGibShooter *); /* linkage=_ZN11CGibShooter5SpawnEv */

	virtual void Precache(class CGibShooter *); /* linkage=_ZN11CGibShooter8PrecacheEv */

	virtual void KeyValue(class CGibShooter *, KeyValueData *); /* linkage=_ZN11CGibShooter8KeyValueEP14KeyValueData_s */

	void ShootThink(class CGibShooter *); /* linkage=_ZN11CGibShooter10ShootThinkEv */

	virtual void Use(class CGibShooter *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN11CGibShooter3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual class CGib * CreateGib(class CGibShooter *); /* linkage=_ZN11CGibShooter9CreateGibEv */

	virtual int Save(class CGibShooter *, class CSave &); /* linkage=_ZN11CGibShooter4SaveER5CSave */

	virtual int Restore(class CGibShooter *, class CRestore &); /* linkage=_ZN11CGibShooter7RestoreER8CRestore */

	virtual void ~CGibShooter(class CGibShooter *, int); /* linkage=_ZN11CGibShooterD4Ev */

	/* vtable has 7 entries: {
	   [2] = Spawn(_ZN11CGibShooter5SpawnEv), 
	   [3] = Precache(_ZN11CGibShooter8PrecacheEv), 
	   [4] = KeyValue(_ZN11CGibShooter8KeyValueEP14KeyValueData_s), 
	   [45] = Use(_ZN11CGibShooter3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [65] = CreateGib(_ZN11CGibShooter9CreateGibEv), 
	   [5] = Save(_ZN11CGibShooter4SaveER5CSave), 
	   [6] = Restore(_ZN11CGibShooter7RestoreER8CRestore), 
	} */
	/* size: 1176, cachelines: 19, members: 8, static members: 1 */
	/* sum members: 28, holes: 1, sum holes: 1148 */
	/* last cacheline: 24 bytes */
};
class CSprite : public CPointEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CPointEntity        <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[2]; /*     0     0 */
private:

	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	float                      m_lastTime;           /*  1140     4 */
	float                      m_maxFrame;           /*  1144     4 */
	void CSprite(class CSprite *, class CSprite &); /* linkage=_ZN7CSpriteC4EOS_ */

	void CSprite(class CSprite *, const class CSprite  &); /* linkage=_ZN7CSpriteC4ERKS_ */

	void CSprite(class CSprite *); /* linkage=_ZN7CSpriteC4Ev */

	virtual void Spawn(class CSprite *); /* linkage=_ZN7CSprite5SpawnEv */

	virtual void Precache(class CSprite *); /* linkage=_ZN7CSprite8PrecacheEv */

	virtual int ObjectCaps(class CSprite *); /* linkage=_ZN7CSprite10ObjectCapsEv */

	void AnimateThink(class CSprite *); /* linkage=_ZN7CSprite12AnimateThinkEv */

	void ExpandThink(class CSprite *); /* linkage=_ZN7CSprite11ExpandThinkEv */

	virtual void Use(class CSprite *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN7CSprite3UseEP11CBaseEntityS1_8USE_TYPEf */

	void Animate(class CSprite *, float); /* linkage=_ZN7CSprite7AnimateEf */

	void Expand(class CSprite *, float, float); /* linkage=_ZN7CSprite6ExpandEff */

	void SpriteInit(class CSprite *, const char  *, const class Vector  &); /* linkage=_ZN7CSprite10SpriteInitEPKcRK6Vector */

	void SetAttachment(class CSprite *, edict_t *, int); /* linkage=_ZN7CSprite13SetAttachmentEP7edict_si */

	void TurnOff(class CSprite *); /* linkage=_ZN7CSprite7TurnOffEv */

	void TurnOn(class CSprite *); /* linkage=_ZN7CSprite6TurnOnEv */

	float Frames(class CSprite *); /* linkage=_ZN7CSprite6FramesEv */

	void SetTransparency(class CSprite *, int, int, int, int, int, int); /* linkage=_ZN7CSprite15SetTransparencyEiiiiii */

	void SetTexture(class CSprite *, int); /* linkage=_ZN7CSprite10SetTextureEi */

	void SetScale(class CSprite *, float); /* linkage=_ZN7CSprite8SetScaleEf */

	void SetColor(class CSprite *, int, int, int); /* linkage=_ZN7CSprite8SetColorEiii */

	void SetBrightness(class CSprite *, int); /* linkage=_ZN7CSprite13SetBrightnessEi */

	void AnimateAndDie(class CSprite *, float); /* linkage=_ZN7CSprite13AnimateAndDieEf */

	void AnimateUntilDead(class CSprite *); /* linkage=_ZN7CSprite16AnimateUntilDeadEv */

	virtual int Save(class CSprite *, class CSave &); /* linkage=_ZN7CSprite4SaveER5CSave */

	virtual int Restore(class CSprite *, class CRestore &); /* linkage=_ZN7CSprite7RestoreER8CRestore */

	class CSprite * SpriteCreate(const char  *, const class Vector  &, BOOL); /* linkage=_ZN7CSprite12SpriteCreateEPKcRK6Vectori */

	virtual void ~CSprite(class CSprite *, int); /* linkage=_ZN7CSpriteD4Ev */

	/* vtable has 6 entries: {
	   [2] = Spawn(_ZN7CSprite5SpawnEv), 
	   [3] = Precache(_ZN7CSprite8PrecacheEv), 
	   [7] = ObjectCaps(_ZN7CSprite10ObjectCapsEv), 
	   [45] = Use(_ZN7CSprite3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [5] = Save(_ZN7CSprite4SaveER5CSave), 
	   [6] = Restore(_ZN7CSprite7RestoreER8CRestore), 
	} */
	/* size: 1148, cachelines: 18, members: 3, static members: 1 */
	/* sum members: 8, holes: 1, sum holes: 1140 */
	/* last cacheline: 60 bytes */
};
class CGlow : public CPointEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CPointEntity        <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[2]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	float                      m_lastTime;           /*  1140     4 */
	float                      m_maxFrame;           /*  1144     4 */
	void CGlow(class CGlow *, class CGlow &); /* linkage=_ZN5CGlowC4EOS_ */

	void CGlow(class CGlow *, const class CGlow  &); /* linkage=_ZN5CGlowC4ERKS_ */

	void CGlow(class CGlow *); /* linkage=_ZN5CGlowC4Ev */

	virtual void Spawn(class CGlow *); /* linkage=_ZN5CGlow5SpawnEv */

	virtual void Think(class CGlow *); /* linkage=_ZN5CGlow5ThinkEv */

	void Animate(class CGlow *, float); /* linkage=_ZN5CGlow7AnimateEf */

	virtual int Save(class CGlow *, class CSave &); /* linkage=_ZN5CGlow4SaveER5CSave */

	virtual int Restore(class CGlow *, class CRestore &); /* linkage=_ZN5CGlow7RestoreER8CRestore */

	virtual void ~CGlow(class CGlow *, int); /* linkage=_ZN5CGlowD4Ev */

	/* vtable has 4 entries: {
	   [2] = Spawn(_ZN5CGlow5SpawnEv), 
	   [43] = Think(_ZN5CGlow5ThinkEv), 
	   [5] = Save(_ZN5CGlow4SaveER5CSave), 
	   [6] = Restore(_ZN5CGlow7RestoreER8CRestore), 
	} */
	/* size: 1148, cachelines: 18, members: 3, static members: 1 */
	/* sum members: 8, holes: 1, sum holes: 1140 */
	/* last cacheline: 60 bytes */
};
class CLaser : public CBeam {
public:

	/* class CBeam               <ancestor>; */      /*     0  1140 */

	/* XXX last struct has 1140 bytes of padding */

	static TYPEDESCRIPTION            m_SaveData[3]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	class CSprite *            m_pSprite;            /*  1140     4 */
	int                        m_iszSpriteName;      /*  1144     4 */
	class Vector              m_firePosition;        /*  1148    12 */
	void CLaser(class CLaser *, class CLaser &); /* linkage=_ZN6CLaserC4EOS_ */

	void CLaser(class CLaser *, const class CLaser  &); /* linkage=_ZN6CLaserC4ERKS_ */

	void CLaser(class CLaser *); /* linkage=_ZN6CLaserC4Ev */

	virtual void Spawn(class CLaser *); /* linkage=_ZN6CLaser5SpawnEv */

	virtual void Precache(class CLaser *); /* linkage=_ZN6CLaser8PrecacheEv */

	virtual void KeyValue(class CLaser *, KeyValueData *); /* linkage=_ZN6CLaser8KeyValueEP14KeyValueData_s */

	void TurnOn(class CLaser *); /* linkage=_ZN6CLaser6TurnOnEv */

	void TurnOff(class CLaser *); /* linkage=_ZN6CLaser7TurnOffEv */

	int IsOn(class CLaser *); /* linkage=_ZN6CLaser4IsOnEv */

	void FireAtPoint(class CLaser *, TraceResult &); /* linkage=_ZN6CLaser11FireAtPointER11TraceResult */

	void StrikeThink(class CLaser *); /* linkage=_ZN6CLaser11StrikeThinkEv */

	virtual void Use(class CLaser *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN6CLaser3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual int Save(class CLaser *, class CSave &); /* linkage=_ZN6CLaser4SaveER5CSave */

	virtual int Restore(class CLaser *, class CRestore &); /* linkage=_ZN6CLaser7RestoreER8CRestore */

	virtual void ~CLaser(class CLaser *, int); /* linkage=_ZN6CLaserD4Ev */

	/* vtable has 6 entries: {
	   [2] = Spawn(_ZN6CLaser5SpawnEv), 
	   [3] = Precache(_ZN6CLaser8PrecacheEv), 
	   [4] = KeyValue(_ZN6CLaser8KeyValueEP14KeyValueData_s), 
	   [45] = Use(_ZN6CLaser3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [5] = Save(_ZN6CLaser4SaveER5CSave), 
	   [6] = Restore(_ZN6CLaser7RestoreER8CRestore), 
	} */
	/* size: 1160, cachelines: 19, members: 4, static members: 1 */
	/* paddings: 1, sum paddings: 1140 */
	/* last cacheline: 8 bytes */
};
class CLightning : public CBeam {
public:

	/* class CBeam               <ancestor>; */      /*     0  1140 */

	/* XXX last struct has 1140 bytes of padding */

	static TYPEDESCRIPTION            m_SaveData[13]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	int                        m_active;             /*  1140     4 */
	int                        m_iszStartEntity;     /*  1144     4 */
	int                        m_iszEndEntity;       /*  1148     4 */
	/* --- cacheline 18 boundary (1152 bytes) --- */
	float                      m_life;               /*  1152     4 */
	int                        m_boltWidth;          /*  1156     4 */
	int                        m_noiseAmplitude;     /*  1160     4 */
	int                        m_brightness;         /*  1164     4 */
	int                        m_speed;              /*  1168     4 */
	float                      m_restrike;           /*  1172     4 */
	int                        m_spriteTexture;      /*  1176     4 */
	int                        m_iszSpriteName;      /*  1180     4 */
	int                        m_frameStart;         /*  1184     4 */
	float                      m_radius;             /*  1188     4 */
	void CLightning(class CLightning *, class CLightning &); /* linkage=_ZN10CLightningC4EOS_ */

	void CLightning(class CLightning *, const class CLightning  &); /* linkage=_ZN10CLightningC4ERKS_ */

	void CLightning(class CLightning *); /* linkage=_ZN10CLightningC4Ev */

	virtual void Spawn(class CLightning *); /* linkage=_ZN10CLightning5SpawnEv */

	virtual void Precache(class CLightning *); /* linkage=_ZN10CLightning8PrecacheEv */

	virtual void KeyValue(class CLightning *, KeyValueData *); /* linkage=_ZN10CLightning8KeyValueEP14KeyValueData_s */

	virtual void Activate(class CLightning *); /* linkage=_ZN10CLightning8ActivateEv */

	void StrikeThink(class CLightning *); /* linkage=_ZN10CLightning11StrikeThinkEv */

	void DamageThink(class CLightning *); /* linkage=_ZN10CLightning11DamageThinkEv */

	void RandomArea(class CLightning *); /* linkage=_ZN10CLightning10RandomAreaEv */

	void RandomPoint(class CLightning *, class Vector &); /* linkage=_ZN10CLightning11RandomPointER6Vector */

	void Zap(class CLightning *, const class Vector  &, const class Vector  &); /* linkage=_ZN10CLightning3ZapERK6VectorS2_ */

	void StrikeUse(class CLightning *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN10CLightning9StrikeUseEP11CBaseEntityS1_8USE_TYPEf */

	void ToggleUse(class CLightning *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN10CLightning9ToggleUseEP11CBaseEntityS1_8USE_TYPEf */

	BOOL ServerSide(class CLightning *); /* linkage=_ZN10CLightning10ServerSideEv */

	virtual int Save(class CLightning *, class CSave &); /* linkage=_ZN10CLightning4SaveER5CSave */

	virtual int Restore(class CLightning *, class CRestore &); /* linkage=_ZN10CLightning7RestoreER8CRestore */

	void BeamUpdateVars(class CLightning *); /* linkage=_ZN10CLightning14BeamUpdateVarsEv */

	virtual void ~CLightning(class CLightning *, int); /* linkage=_ZN10CLightningD4Ev */

	/* vtable has 6 entries: {
	   [2] = Spawn(_ZN10CLightning5SpawnEv), 
	   [3] = Precache(_ZN10CLightning8PrecacheEv), 
	   [4] = KeyValue(_ZN10CLightning8KeyValueEP14KeyValueData_s), 
	   [8] = Activate(_ZN10CLightning8ActivateEv), 
	   [5] = Save(_ZN10CLightning4SaveER5CSave), 
	   [6] = Restore(_ZN10CLightning7RestoreER8CRestore), 
	} */
	/* size: 1192, cachelines: 19, members: 14, static members: 1 */
	/* paddings: 1, sum paddings: 1140 */
	/* last cacheline: 40 bytes */
};
class CBubbling : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[3]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	int                        m_density;            /*  1140     4 */
	int                        m_frequency;          /*  1144     4 */
	int                        m_bubbleModel;        /*  1148     4 */
	/* --- cacheline 18 boundary (1152 bytes) --- */
	int                        m_state;              /*  1152     4 */
	void CBubbling(class CBubbling *, class CBubbling &); /* linkage=_ZN9CBubblingC4EOS_ */

	void CBubbling(class CBubbling *, const class CBubbling  &); /* linkage=_ZN9CBubblingC4ERKS_ */

	void CBubbling(class CBubbling *); /* linkage=_ZN9CBubblingC4Ev */

	virtual void Spawn(class CBubbling *); /* linkage=_ZN9CBubbling5SpawnEv */

	virtual void Precache(class CBubbling *); /* linkage=_ZN9CBubbling8PrecacheEv */

	virtual void KeyValue(class CBubbling *, KeyValueData *); /* linkage=_ZN9CBubbling8KeyValueEP14KeyValueData_s */

	void FizzThink(class CBubbling *); /* linkage=_ZN9CBubbling9FizzThinkEv */

	virtual void Use(class CBubbling *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN9CBubbling3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual int Save(class CBubbling *, class CSave &); /* linkage=_ZN9CBubbling4SaveER5CSave */

	virtual int Restore(class CBubbling *, class CRestore &); /* linkage=_ZN9CBubbling7RestoreER8CRestore */

	virtual int ObjectCaps(class CBubbling *); /* linkage=_ZN9CBubbling10ObjectCapsEv */

	virtual void ~CBubbling(class CBubbling *, int); /* linkage=_ZN9CBubblingD4Ev */

	/* vtable has 7 entries: {
	   [2] = Spawn(_ZN9CBubbling5SpawnEv), 
	   [3] = Precache(_ZN9CBubbling8PrecacheEv), 
	   [4] = KeyValue(_ZN9CBubbling8KeyValueEP14KeyValueData_s), 
	   [45] = Use(_ZN9CBubbling3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [5] = Save(_ZN9CBubbling4SaveER5CSave), 
	   [6] = Restore(_ZN9CBubbling7RestoreER8CRestore), 
	   [7] = ObjectCaps(_ZN9CBubbling10ObjectCapsEv), 
	} */
	/* size: 1156, cachelines: 19, members: 5, static members: 1 */
	/* sum members: 16, holes: 1, sum holes: 1140 */
	/* last cacheline: 4 bytes */
};
class CNoBuildArea : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CNoBuildArea(class CNoBuildArea *, class CNoBuildArea &); /* linkage=_ZN12CNoBuildAreaC4EOS_ */

	void CNoBuildArea(class CNoBuildArea *, const class CNoBuildArea  &); /* linkage=_ZN12CNoBuildAreaC4ERKS_ */

	void CNoBuildArea(class CNoBuildArea *); /* linkage=_ZN12CNoBuildAreaC4Ev */

	virtual void Spawn(class CNoBuildArea *); /* linkage=_ZN12CNoBuildArea5SpawnEv */

	virtual void ~CNoBuildArea(class CNoBuildArea *, int); /* linkage=_ZN12CNoBuildAreaD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN12CNoBuildArea5SpawnEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CEnvExplosion : public CBaseMonster {

	/* XXX 1724 bytes hole, try to pack */
public:


	/* class CBaseMonster        <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[2]; /*     0     0 */
	/* --- cacheline 26 boundary (1664 bytes) was 60 bytes ago --- */
	int                        m_iMagnitude;         /*  1724     4 */
	/* --- cacheline 27 boundary (1728 bytes) --- */
	int                        m_spriteScale;        /*  1728     4 */
	void CEnvExplosion(class CEnvExplosion *, class CEnvExplosion &); /* linkage=_ZN13CEnvExplosionC4EOS_ */

	void CEnvExplosion(class CEnvExplosion *, const class CEnvExplosion  &); /* linkage=_ZN13CEnvExplosionC4ERKS_ */

	void CEnvExplosion(class CEnvExplosion *); /* linkage=_ZN13CEnvExplosionC4Ev */

	virtual void Spawn(class CEnvExplosion *); /* linkage=_ZN13CEnvExplosion5SpawnEv */

	void Smoke(class CEnvExplosion *); /* linkage=_ZN13CEnvExplosion5SmokeEv */

	virtual void KeyValue(class CEnvExplosion *, KeyValueData *); /* linkage=_ZN13CEnvExplosion8KeyValueEP14KeyValueData_s */

	virtual void Use(class CEnvExplosion *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN13CEnvExplosion3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual int Save(class CEnvExplosion *, class CSave &); /* linkage=_ZN13CEnvExplosion4SaveER5CSave */

	virtual int Restore(class CEnvExplosion *, class CRestore &); /* linkage=_ZN13CEnvExplosion7RestoreER8CRestore */

	virtual void ~CEnvExplosion(class CEnvExplosion *, int); /* linkage=_ZN13CEnvExplosionD4Ev */

	/* vtable has 5 entries: {
	   [2] = Spawn(_ZN13CEnvExplosion5SpawnEv), 
	   [4] = KeyValue(_ZN13CEnvExplosion8KeyValueEP14KeyValueData_s), 
	   [45] = Use(_ZN13CEnvExplosion3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [5] = Save(_ZN13CEnvExplosion4SaveER5CSave), 
	   [6] = Restore(_ZN13CEnvExplosion7RestoreER8CRestore), 
	} */
	/* size: 1732, cachelines: 28, members: 3, static members: 1 */
	/* sum members: 8, holes: 1, sum holes: 1724 */
	/* last cacheline: 4 bytes */
};
class CShower : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CShower(class CShower *, class CShower &); /* linkage=_ZN7CShowerC4EOS_ */

	void CShower(class CShower *, const class CShower  &); /* linkage=_ZN7CShowerC4ERKS_ */

	void CShower(class CShower *); /* linkage=_ZN7CShowerC4Ev */

private:

	virtual void Spawn(class CShower *); /* linkage=_ZN7CShower5SpawnEv */

	virtual void Think(class CShower *); /* linkage=_ZN7CShower5ThinkEv */

	virtual void Touch(class CShower *, class CBaseEntity *); /* linkage=_ZN7CShower5TouchEP11CBaseEntity */

	virtual int ObjectCaps(class CShower *); /* linkage=_ZN7CShower10ObjectCapsEv */

	virtual void ~CShower(class CShower *, int); /* linkage=_ZN7CShowerD4Ev */

	/* vtable has 4 entries: {
	   [2] = Spawn(_ZN7CShower5SpawnEv), 
	   [43] = Think(_ZN7CShower5ThinkEv), 
	   [44] = Touch(_ZN7CShower5TouchEP11CBaseEntity), 
	   [7] = ObjectCaps(_ZN7CShower10ObjectCapsEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CPushable : public CBreakable {
public:

	/* class CBreakable          <ancestor>; */      /*     0  1172 */

	/* XXX last struct has 1 hole */

	static TYPEDESCRIPTION            m_SaveData[2]; /*     0     0 */
	static char *                     m_soundNames[3]; /*     0     0 */
	/* --- cacheline 18 boundary (1152 bytes) was 20 bytes ago --- */
	int                        m_lastSound;          /*  1172     4 */
	float                      m_maxSpeed;           /*  1176     4 */
	float                      m_soundTime;          /*  1180     4 */
	void CPushable(class CPushable *, class CPushable &); /* linkage=_ZN9CPushableC4EOS_ */

	void CPushable(class CPushable *, const class CPushable  &); /* linkage=_ZN9CPushableC4ERKS_ */

	void CPushable(class CPushable *); /* linkage=_ZN9CPushableC4Ev */

	virtual void Spawn(class CPushable *); /* linkage=_ZN9CPushable5SpawnEv */

	virtual void Precache(class CPushable *); /* linkage=_ZN9CPushable8PrecacheEv */

	virtual void Touch(class CPushable *, class CBaseEntity *); /* linkage=_ZN9CPushable5TouchEP11CBaseEntity */

	void Move(class CPushable *, class CBaseEntity *, int); /* linkage=_ZN9CPushable4MoveEP11CBaseEntityi */

	virtual void KeyValue(class CPushable *, KeyValueData *); /* linkage=_ZN9CPushable8KeyValueEP14KeyValueData_s */

	virtual void Use(class CPushable *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN9CPushable3UseEP11CBaseEntityS1_8USE_TYPEf */

	void StopSound(class CPushable *); /* linkage=_ZN9CPushable9StopSoundEv */

	virtual int ObjectCaps(class CPushable *); /* linkage=_ZN9CPushable10ObjectCapsEv */

	virtual int Save(class CPushable *, class CSave &); /* linkage=_ZN9CPushable4SaveER5CSave */

	virtual int Restore(class CPushable *, class CRestore &); /* linkage=_ZN9CPushable7RestoreER8CRestore */

	float MaxSpeed(class CPushable *); /* linkage=_ZN9CPushable8MaxSpeedEv */

	virtual int TakeDamage(class CPushable *, entvars_t *, entvars_t *, float, int); /* linkage=_ZN9CPushable10TakeDamageEP9entvars_sS1_fi */

	virtual void ~CPushable(class CPushable *, int); /* linkage=_ZN9CPushableD4Ev */

	/* vtable has 9 entries: {
	   [2] = Spawn(_ZN9CPushable5SpawnEv), 
	   [3] = Precache(_ZN9CPushable8PrecacheEv), 
	   [44] = Touch(_ZN9CPushable5TouchEP11CBaseEntity), 
	   [4] = KeyValue(_ZN9CPushable8KeyValueEP14KeyValueData_s), 
	   [45] = Use(_ZN9CPushable3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [7] = ObjectCaps(_ZN9CPushable10ObjectCapsEv), 
	   [5] = Save(_ZN9CPushable4SaveER5CSave), 
	   [6] = Restore(_ZN9CPushable7RestoreER8CRestore), 
	   [13] = TakeDamage(_ZN9CPushable10TakeDamageEP9entvars_sS1_fi), 
	} */
	/* size: 1184, cachelines: 19, members: 4, static members: 2 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 32 bytes */
};
class CBreakable : public CBaseDelay {

	/* XXX 1148 bytes hole, try to pack */
public:


	/* class CBaseDelay          <ancestor>; */      /*     0     0 */
	static const char  *              pSoundsWood[3]; /*     0     0 */
	static const char  *              pSoundsFlesh[6]; /*     0     0 */
	static const char  *              pSoundsGlass[3]; /*     0     0 */
	static const char  *              pSoundsMetal[3]; /*     0     0 */
	static const char  *              pSoundsConcrete[3]; /*     0     0 */
	static const char  *              pSpawnObjects[22]; /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[5]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 60 bytes ago --- */
	Materials                  m_Material;           /*  1148     4 */
	/* --- cacheline 18 boundary (1152 bytes) --- */
	Explosions                 m_Explosion;          /*  1152     4 */
	int                        m_idShard;            /*  1156     4 */
	float                      m_angle;              /*  1160     4 */
	int                        m_iszGibModel;        /*  1164     4 */
	int                        m_iszSpawnObject;     /*  1168     4 */
	void CBreakable(class CBreakable *, class CBreakable &); /* linkage=_ZN10CBreakableC4EOS_ */

	void CBreakable(class CBreakable *, const class CBreakable  &); /* linkage=_ZN10CBreakableC4ERKS_ */

	void CBreakable(class CBreakable *); /* linkage=_ZN10CBreakableC4Ev */

	virtual void Spawn(class CBreakable *); /* linkage=_ZN10CBreakable5SpawnEv */

	virtual void Precache(class CBreakable *); /* linkage=_ZN10CBreakable8PrecacheEv */

	virtual void KeyValue(class CBreakable *, KeyValueData *); /* linkage=_ZN10CBreakable8KeyValueEP14KeyValueData_s */

	void BreakTouch(class CBreakable *, class CBaseEntity *); /* linkage=_ZN10CBreakable10BreakTouchEP11CBaseEntity */

	virtual void Use(class CBreakable *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN10CBreakable3UseEP11CBaseEntityS1_8USE_TYPEf */

	void DamageSound(class CBreakable *); /* linkage=_ZN10CBreakable11DamageSoundEv */

	virtual int TakeDamage(class CBreakable *, entvars_t *, entvars_t *, float, int); /* linkage=_ZN10CBreakable10TakeDamageEP9entvars_sS1_fi */

	virtual void TraceAttack(class CBreakable *, entvars_t *, float, class Vector, class  *, int); /* linkage=_ZN10CBreakable11TraceAttackEP9entvars_sf6VectorP11TraceResulti */

	BOOL IsBreakable(class CBreakable *); /* linkage=_ZN10CBreakable11IsBreakableEv */

	BOOL SparkWhenHit(class CBreakable *); /* linkage=_ZN10CBreakable12SparkWhenHitEv */

	virtual int DamageDecal(class CBreakable *, int); /* linkage=_ZN10CBreakable11DamageDecalEi */

	void Die(class CBreakable *); /* linkage=_ZN10CBreakable3DieEv */

	virtual int ObjectCaps(class CBreakable *); /* linkage=_ZN10CBreakable10ObjectCapsEv */

	virtual int Save(class CBreakable *, class CSave &); /* linkage=_ZN10CBreakable4SaveER5CSave */

	virtual int Restore(class CBreakable *, class CRestore &); /* linkage=_ZN10CBreakable7RestoreER8CRestore */

	BOOL Explodable(class CBreakable *); /* linkage=_ZN10CBreakable10ExplodableEv */

	int ExplosionMagnitude(class CBreakable *); /* linkage=_ZN10CBreakable18ExplosionMagnitudeEv */

	void ExplosionSetMagnitude(class CBreakable *, int); /* linkage=_ZN10CBreakable21ExplosionSetMagnitudeEi */

	void MaterialSoundPrecache(Materials); /* linkage=_ZN10CBreakable21MaterialSoundPrecacheE9Materials */

	void MaterialSoundRandom(edict_t *, Materials, float); /* linkage=_ZN10CBreakable19MaterialSoundRandomEP7edict_s9Materialsf */

	const char  * * MaterialSoundList(Materials, int &); /* linkage=_ZN10CBreakable17MaterialSoundListE9MaterialsRi */

	virtual void ~CBreakable(class CBreakable *, int); /* linkage=_ZN10CBreakableD4Ev */

	/* vtable has 10 entries: {
	   [2] = Spawn(_ZN10CBreakable5SpawnEv), 
	   [3] = Precache(_ZN10CBreakable8PrecacheEv), 
	   [4] = KeyValue(_ZN10CBreakable8KeyValueEP14KeyValueData_s), 
	   [45] = Use(_ZN10CBreakable3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [13] = TakeDamage(_ZN10CBreakable10TakeDamageEP9entvars_sS1_fi), 
	   [12] = TraceAttack(_ZN10CBreakable11TraceAttackEP9entvars_sf6VectorP11TraceResulti), 
	   [28] = DamageDecal(_ZN10CBreakable11DamageDecalEi), 
	   [7] = ObjectCaps(_ZN10CBreakable10ObjectCapsEv), 
	   [5] = Save(_ZN10CBreakable4SaveER5CSave), 
	   [6] = Restore(_ZN10CBreakable7RestoreER8CRestore), 
	} */
	/* size: 1172, cachelines: 19, members: 7, static members: 7 */
	/* sum members: 24, holes: 1, sum holes: 1148 */
	/* last cacheline: 20 bytes */
};
class CFuncTankControls : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[1]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	class CFuncTank *          m_pTank;              /*  1140     4 */
	void CFuncTankControls(class CFuncTankControls *, class CFuncTankControls &); /* linkage=_ZN17CFuncTankControlsC4EOS_ */

	void CFuncTankControls(class CFuncTankControls *, const class CFuncTankControls  &); /* linkage=_ZN17CFuncTankControlsC4ERKS_ */

	void CFuncTankControls(class CFuncTankControls *); /* linkage=_ZN17CFuncTankControlsC4Ev */

	virtual int ObjectCaps(class CFuncTankControls *); /* linkage=_ZN17CFuncTankControls10ObjectCapsEv */

	virtual void Spawn(class CFuncTankControls *); /* linkage=_ZN17CFuncTankControls5SpawnEv */

	virtual void Use(class CFuncTankControls *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN17CFuncTankControls3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void Think(class CFuncTankControls *); /* linkage=_ZN17CFuncTankControls5ThinkEv */

	virtual int Save(class CFuncTankControls *, class CSave &); /* linkage=_ZN17CFuncTankControls4SaveER5CSave */

	virtual int Restore(class CFuncTankControls *, class CRestore &); /* linkage=_ZN17CFuncTankControls7RestoreER8CRestore */

	virtual void ~CFuncTankControls(class CFuncTankControls *, int); /* linkage=_ZN17CFuncTankControlsD4Ev */

	/* vtable has 6 entries: {
	   [7] = ObjectCaps(_ZN17CFuncTankControls10ObjectCapsEv), 
	   [2] = Spawn(_ZN17CFuncTankControls5SpawnEv), 
	   [45] = Use(_ZN17CFuncTankControls3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [43] = Think(_ZN17CFuncTankControls5ThinkEv), 
	   [5] = Save(_ZN17CFuncTankControls4SaveER5CSave), 
	   [6] = Restore(_ZN17CFuncTankControls7RestoreER8CRestore), 
	} */
	/* size: 1144, cachelines: 18, members: 2, static members: 1 */
	/* sum members: 4, holes: 1, sum holes: 1140 */
	/* last cacheline: 56 bytes */
};
class CFuncTank : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[25]; /*     0     0 */
protected:

	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	class CBasePlayer *        m_pController;        /*  1140     4 */
	float                      m_flNextAttack;       /*  1144     4 */
	class Vector              m_vecControllerUsePos; /*  1148    12 */
	/* --- cacheline 18 boundary (1152 bytes) was 8 bytes ago --- */
	float                      m_yawCenter;          /*  1160     4 */
	float                      m_yawRate;            /*  1164     4 */
	float                      m_yawRange;           /*  1168     4 */
	float                      m_yawTolerance;       /*  1172     4 */
	float                      m_pitchCenter;        /*  1176     4 */
	float                      m_pitchRate;          /*  1180     4 */
	float                      m_pitchRange;         /*  1184     4 */
	float                      m_pitchTolerance;     /*  1188     4 */
	float                      m_fireLast;           /*  1192     4 */
	float                      m_fireRate;           /*  1196     4 */
	float                      m_lastSightTime;      /*  1200     4 */
	float                      m_persist;            /*  1204     4 */
	float                      m_minRange;           /*  1208     4 */
	float                      m_maxRange;           /*  1212     4 */
	/* --- cacheline 19 boundary (1216 bytes) --- */
	class Vector              m_barrelPos;           /*  1216    12 */
	float                      m_spriteScale;        /*  1228     4 */
	int                        m_iszSpriteSmoke;     /*  1232     4 */
	int                        m_iszSpriteFlash;     /*  1236     4 */
	enum TANKBULLET            m_bulletType;         /*  1240     4 */
	int                        m_iBulletDamage;      /*  1244     4 */
	class Vector              m_sightOrigin;         /*  1248    12 */
	int                        m_spread;             /*  1260     4 */
	void CFuncTank(class CFuncTank *, class CFuncTank &); /* linkage=_ZN9CFuncTankC4EOS_ */

	void CFuncTank(class CFuncTank *, const class CFuncTank  &); /* linkage=_ZN9CFuncTankC4ERKS_ */

	void CFuncTank(class CFuncTank *); /* linkage=_ZN9CFuncTankC4Ev */

	virtual void Spawn(class CFuncTank *); /* linkage=_ZN9CFuncTank5SpawnEv */

	virtual void Precache(class CFuncTank *); /* linkage=_ZN9CFuncTank8PrecacheEv */

	virtual void KeyValue(class CFuncTank *, KeyValueData *); /* linkage=_ZN9CFuncTank8KeyValueEP14KeyValueData_s */

	virtual void Use(class CFuncTank *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN9CFuncTank3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void Think(class CFuncTank *); /* linkage=_ZN9CFuncTank5ThinkEv */

	void TrackTarget(class CFuncTank *); /* linkage=_ZN9CFuncTank11TrackTargetEv */

	virtual void Fire(class CFuncTank *, const class Vector  &, const class Vector  &, entvars_t *); /* linkage=_ZN9CFuncTank4FireERK6VectorS2_P9entvars_s */

	virtual class Vector UpdateTargetPosition(class CFuncTank *, class CBaseEntity *); /* linkage=_ZN9CFuncTank20UpdateTargetPositionEP11CBaseEntity */

	void StartRotSound(class CFuncTank *); /* linkage=_ZN9CFuncTank13StartRotSoundEv */

	void StopRotSound(class CFuncTank *); /* linkage=_ZN9CFuncTank12StopRotSoundEv */

	virtual int ObjectCaps(class CFuncTank *); /* linkage=_ZN9CFuncTank10ObjectCapsEv */

	BOOL IsActive(class CFuncTank *); /* linkage=_ZN9CFuncTank8IsActiveEv */

	void TankActivate(class CFuncTank *); /* linkage=_ZN9CFuncTank12TankActivateEv */

	void TankDeactivate(class CFuncTank *); /* linkage=_ZN9CFuncTank14TankDeactivateEv */

	BOOL CanFire(class CFuncTank *); /* linkage=_ZN9CFuncTank7CanFireEv */

	BOOL InRange(class CFuncTank *, float); /* linkage=_ZN9CFuncTank7InRangeEf */

	edict_t * FindTarget(class CFuncTank *, edict_t *); /* linkage=_ZN9CFuncTank10FindTargetEP7edict_s */

	void TankTrace(class CFuncTank *, const class Vector  &, const class Vector  &, const class Vector  &, TraceResult &); /* linkage=_ZN9CFuncTank9TankTraceERK6VectorS2_S2_R11TraceResult */

	class Vector BarrelPosition(class CFuncTank *); /* linkage=_ZN9CFuncTank14BarrelPositionEv */

	void AdjustAnglesForBarrel(class CFuncTank *, class Vector &, float); /* linkage=_ZN9CFuncTank21AdjustAnglesForBarrelER6Vectorf */

	virtual int Save(class CFuncTank *, class CSave &); /* linkage=_ZN9CFuncTank4SaveER5CSave */

	virtual int Restore(class CFuncTank *, class CRestore &); /* linkage=_ZN9CFuncTank7RestoreER8CRestore */

	virtual BOOL OnControls(class CFuncTank *, entvars_t *); /* linkage=_ZN9CFuncTank10OnControlsEP9entvars_s */

	BOOL StartControl(class CFuncTank *, class CBasePlayer *); /* linkage=_ZN9CFuncTank12StartControlEP11CBasePlayer */

	void StopControl(class CFuncTank *); /* linkage=_ZN9CFuncTank11StopControlEv */

	void ControllerPostFrame(class CFuncTank *); /* linkage=_ZN9CFuncTank19ControllerPostFrameEv */

	virtual void ~CFuncTank(class CFuncTank *, int); /* linkage=_ZN9CFuncTankD4Ev */

	/* vtable has 11 entries: {
	   [2] = Spawn(_ZN9CFuncTank5SpawnEv), 
	   [3] = Precache(_ZN9CFuncTank8PrecacheEv), 
	   [4] = KeyValue(_ZN9CFuncTank8KeyValueEP14KeyValueData_s), 
	   [45] = Use(_ZN9CFuncTank3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [43] = Think(_ZN9CFuncTank5ThinkEv), 
	   [65] = Fire(_ZN9CFuncTank4FireERK6VectorS2_P9entvars_s), 
	   [66] = UpdateTargetPosition(_ZN9CFuncTank20UpdateTargetPositionEP11CBaseEntity), 
	   [7] = ObjectCaps(_ZN9CFuncTank10ObjectCapsEv), 
	   [5] = Save(_ZN9CFuncTank4SaveER5CSave), 
	   [6] = Restore(_ZN9CFuncTank7RestoreER8CRestore), 
	   [32] = OnControls(_ZN9CFuncTank10OnControlsEP9entvars_s), 
	} */
	/* size: 1264, cachelines: 20, members: 26, static members: 1 */
	/* sum members: 124, holes: 1, sum holes: 1140 */
	/* last cacheline: 48 bytes */
};
class CFuncTankMortar : public CFuncTank {
public:

	/* class CFuncTank           <ancestor>; */      /*     0  1264 */

	/* XXX last struct has 1 hole */
	void CFuncTankMortar(class CFuncTankMortar *, class CFuncTankMortar &); /* linkage=_ZN15CFuncTankMortarC4EOS_ */

	void CFuncTankMortar(class CFuncTankMortar *, const class CFuncTankMortar  &); /* linkage=_ZN15CFuncTankMortarC4ERKS_ */

	void CFuncTankMortar(class CFuncTankMortar *); /* linkage=_ZN15CFuncTankMortarC4Ev */

	virtual void KeyValue(class CFuncTankMortar *, KeyValueData *); /* linkage=_ZN15CFuncTankMortar8KeyValueEP14KeyValueData_s */

	virtual void Fire(class CFuncTankMortar *, const class Vector  &, const class Vector  &, entvars_t *); /* linkage=_ZN15CFuncTankMortar4FireERK6VectorS2_P9entvars_s */

	virtual void ~CFuncTankMortar(class CFuncTankMortar *, int); /* linkage=_ZN15CFuncTankMortarD4Ev */

	/* vtable has 2 entries: {
	   [4] = KeyValue(_ZN15CFuncTankMortar8KeyValueEP14KeyValueData_s), 
	   [65] = Fire(_ZN15CFuncTankMortar4FireERK6VectorS2_P9entvars_s), 
	} */
	/* size: 1264, cachelines: 20, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 48 bytes */
};
class CFuncTankRocket : public CFuncTank {
public:

	/* class CFuncTank           <ancestor>; */      /*     0  1264 */

	/* XXX last struct has 1 hole */
	void CFuncTankRocket(class CFuncTankRocket *, class CFuncTankRocket &); /* linkage=_ZN15CFuncTankRocketC4EOS_ */

	void CFuncTankRocket(class CFuncTankRocket *, const class CFuncTankRocket  &); /* linkage=_ZN15CFuncTankRocketC4ERKS_ */

	void CFuncTankRocket(class CFuncTankRocket *); /* linkage=_ZN15CFuncTankRocketC4Ev */

	virtual void Precache(class CFuncTankRocket *); /* linkage=_ZN15CFuncTankRocket8PrecacheEv */

	virtual void Fire(class CFuncTankRocket *, const class Vector  &, const class Vector  &, entvars_t *); /* linkage=_ZN15CFuncTankRocket4FireERK6VectorS2_P9entvars_s */

	virtual void ~CFuncTankRocket(class CFuncTankRocket *, int); /* linkage=_ZN15CFuncTankRocketD4Ev */

	/* vtable has 2 entries: {
	   [3] = Precache(_ZN15CFuncTankRocket8PrecacheEv), 
	   [65] = Fire(_ZN15CFuncTankRocket4FireERK6VectorS2_P9entvars_s), 
	} */
	/* size: 1264, cachelines: 20, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 48 bytes */
};
class CFuncTankLaser : public CFuncTank {
public:

	/* class CFuncTank           <ancestor>; */      /*     0  1264 */

	/* XXX last struct has 1 hole */

	static TYPEDESCRIPTION            m_SaveData[2]; /*     0     0 */
private:

	/* --- cacheline 19 boundary (1216 bytes) was 48 bytes ago --- */
	class CLaser *             m_pLaser;             /*  1264     4 */
	float                      m_laserTime;          /*  1268     4 */
	void CFuncTankLaser(class CFuncTankLaser *, class CFuncTankLaser &); /* linkage=_ZN14CFuncTankLaserC4EOS_ */

	void CFuncTankLaser(class CFuncTankLaser *, const class CFuncTankLaser  &); /* linkage=_ZN14CFuncTankLaserC4ERKS_ */

	void CFuncTankLaser(class CFuncTankLaser *); /* linkage=_ZN14CFuncTankLaserC4Ev */

	virtual void Activate(class CFuncTankLaser *); /* linkage=_ZN14CFuncTankLaser8ActivateEv */

	virtual void KeyValue(class CFuncTankLaser *, KeyValueData *); /* linkage=_ZN14CFuncTankLaser8KeyValueEP14KeyValueData_s */

	virtual void Fire(class CFuncTankLaser *, const class Vector  &, const class Vector  &, entvars_t *); /* linkage=_ZN14CFuncTankLaser4FireERK6VectorS2_P9entvars_s */

	virtual void Think(class CFuncTankLaser *); /* linkage=_ZN14CFuncTankLaser5ThinkEv */

	class CLaser * GetLaser(class CFuncTankLaser *); /* linkage=_ZN14CFuncTankLaser8GetLaserEv */

	virtual int Save(class CFuncTankLaser *, class CSave &); /* linkage=_ZN14CFuncTankLaser4SaveER5CSave */

	virtual int Restore(class CFuncTankLaser *, class CRestore &); /* linkage=_ZN14CFuncTankLaser7RestoreER8CRestore */

	virtual void ~CFuncTankLaser(class CFuncTankLaser *, int); /* linkage=_ZN14CFuncTankLaserD4Ev */

	/* vtable has 6 entries: {
	   [8] = Activate(_ZN14CFuncTankLaser8ActivateEv), 
	   [4] = KeyValue(_ZN14CFuncTankLaser8KeyValueEP14KeyValueData_s), 
	   [65] = Fire(_ZN14CFuncTankLaser4FireERK6VectorS2_P9entvars_s), 
	   [43] = Think(_ZN14CFuncTankLaser5ThinkEv), 
	   [5] = Save(_ZN14CFuncTankLaser4SaveER5CSave), 
	   [6] = Restore(_ZN14CFuncTankLaser7RestoreER8CRestore), 
	} */
	/* size: 1272, cachelines: 20, members: 3, static members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 56 bytes */
};
class CFuncTankGun : public CFuncTank {
public:

	/* class CFuncTank           <ancestor>; */      /*     0  1264 */

	/* XXX last struct has 1 hole */
	void CFuncTankGun(class CFuncTankGun *, class CFuncTankGun &); /* linkage=_ZN12CFuncTankGunC4EOS_ */

	void CFuncTankGun(class CFuncTankGun *, const class CFuncTankGun  &); /* linkage=_ZN12CFuncTankGunC4ERKS_ */

	void CFuncTankGun(class CFuncTankGun *); /* linkage=_ZN12CFuncTankGunC4Ev */

	virtual void Fire(class CFuncTankGun *, const class Vector  &, const class Vector  &, entvars_t *); /* linkage=_ZN12CFuncTankGun4FireERK6VectorS2_P9entvars_s */

	virtual void ~CFuncTankGun(class CFuncTankGun *, int); /* linkage=_ZN12CFuncTankGunD4Ev */

	/* vtable has 1 entries: {
	   [65] = Fire(_ZN12CFuncTankGun4FireERK6VectorS2_P9entvars_s), 
	} */
	/* size: 1264, cachelines: 20, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 48 bytes */
};
struct mapcycle_item_s {
	class mapcycle_item_s *    next;                 /*     0     4 */
	char                       mapname[32];          /*     4    32 */
	int                        minplayers;           /*    36     4 */
	int                        maxplayers;           /*    40     4 */
	char                       rulebuffer[1024];     /*    44  1024 */

	/* size: 1068, cachelines: 17, members: 5 */
	/* last cacheline: 44 bytes */
};
struct mapcycle_s {
	class mapcycle_item_s *    items;                /*     0     4 */
	class mapcycle_item_s *    next_item;            /*     4     4 */

	/* size: 8, cachelines: 1, members: 2 */
	/* last cacheline: 8 bytes */
};
class CHalfLifeMultiplay : public CGameRules {
public:

	/* class CGameRules          <ancestor>; */      /*     0     4 */
protected:

	float                      m_flIntermissionEndTime; /*     4     4 */
	float                      m_flIntermissionStartTime; /*     8     4 */
	BOOL                       m_iEndIntermissionButtonHit; /*    12     4 */
	void CHalfLifeMultiplay(class CHalfLifeMultiplay *, class CHalfLifeMultiplay &); /* linkage=_ZN18CHalfLifeMultiplayC4EOS_ */

	void CHalfLifeMultiplay(class CHalfLifeMultiplay *, const class CHalfLifeMultiplay  &); /* linkage=_ZN18CHalfLifeMultiplayC4ERKS_ */

	void CHalfLifeMultiplay(class CHalfLifeMultiplay *); /* linkage=_ZN18CHalfLifeMultiplayC4Ev */

	virtual void Think(class CHalfLifeMultiplay *); /* linkage=_ZN18CHalfLifeMultiplay5ThinkEv */

	virtual BOOL IsAllowedToSpawn(class CHalfLifeMultiplay *, class CBaseEntity *); /* linkage=_ZN18CHalfLifeMultiplay16IsAllowedToSpawnEP11CBaseEntity */

	virtual BOOL FAllowFlashlight(class CHalfLifeMultiplay *); /* linkage=_ZN18CHalfLifeMultiplay16FAllowFlashlightEv */

	virtual BOOL FShouldSwitchWeapon(class CHalfLifeMultiplay *, class CBasePlayer *, class CBasePlayerItem *); /* linkage=_ZN18CHalfLifeMultiplay19FShouldSwitchWeaponEP11CBasePlayerP15CBasePlayerItem */

	virtual BOOL GetNextBestWeapon(class CHalfLifeMultiplay *, class CBasePlayer *, class CBasePlayerItem *); /* linkage=_ZN18CHalfLifeMultiplay17GetNextBestWeaponEP11CBasePlayerP15CBasePlayerItem */

	virtual BOOL IsMultiplayer(class CHalfLifeMultiplay *); /* linkage=_ZN18CHalfLifeMultiplay13IsMultiplayerEv */

	virtual BOOL IsDeathmatch(class CHalfLifeMultiplay *); /* linkage=_ZN18CHalfLifeMultiplay12IsDeathmatchEv */

	virtual BOOL IsCoOp(class CHalfLifeMultiplay *); /* linkage=_ZN18CHalfLifeMultiplay6IsCoOpEv */

	virtual BOOL ClientConnected(class CHalfLifeMultiplay *, edict_t *, const char  *, const char  *, char *); /* linkage=_ZN18CHalfLifeMultiplay15ClientConnectedEP7edict_sPKcS3_Pc */

	virtual void InitHUD(class CHalfLifeMultiplay *, class CBasePlayer *); /* linkage=_ZN18CHalfLifeMultiplay7InitHUDEP11CBasePlayer */

	virtual void ClientDisconnected(class CHalfLifeMultiplay *, edict_t *); /* linkage=_ZN18CHalfLifeMultiplay18ClientDisconnectedEP7edict_s */

	virtual void UpdateGameMode(class CHalfLifeMultiplay *, class CBasePlayer *); /* linkage=_ZN18CHalfLifeMultiplay14UpdateGameModeEP11CBasePlayer */

	virtual float FlPlayerFallDamage(class CHalfLifeMultiplay *, class CBasePlayer *); /* linkage=_ZN18CHalfLifeMultiplay18FlPlayerFallDamageEP11CBasePlayer */

	virtual BOOL FPlayerCanTakeDamage(class CHalfLifeMultiplay *, class CBasePlayer *, class CBaseEntity *); /* linkage=_ZN18CHalfLifeMultiplay20FPlayerCanTakeDamageEP11CBasePlayerP11CBaseEntity */

	virtual void PlayerSpawn(class CHalfLifeMultiplay *, class CBasePlayer *); /* linkage=_ZN18CHalfLifeMultiplay11PlayerSpawnEP11CBasePlayer */

	virtual void PlayerThink(class CHalfLifeMultiplay *, class CBasePlayer *); /* linkage=_ZN18CHalfLifeMultiplay11PlayerThinkEP11CBasePlayer */

	virtual BOOL FPlayerCanRespawn(class CHalfLifeMultiplay *, class CBasePlayer *); /* linkage=_ZN18CHalfLifeMultiplay17FPlayerCanRespawnEP11CBasePlayer */

	virtual float FlPlayerSpawnTime(class CHalfLifeMultiplay *, class CBasePlayer *); /* linkage=_ZN18CHalfLifeMultiplay17FlPlayerSpawnTimeEP11CBasePlayer */

	virtual BOOL ClientCommand(class CHalfLifeMultiplay *, class CBasePlayer *, const char  *); /* linkage=_ZN18CHalfLifeMultiplay13ClientCommandEP11CBasePlayerPKc */

	virtual BOOL AllowAutoTargetCrosshair(class CHalfLifeMultiplay *); /* linkage=_ZN18CHalfLifeMultiplay24AllowAutoTargetCrosshairEv */

	virtual int IPointsForKill(class CHalfLifeMultiplay *, class CBasePlayer *, class CBasePlayer *); /* linkage=_ZN18CHalfLifeMultiplay14IPointsForKillEP11CBasePlayerS1_ */

	virtual void PlayerKilled(class CHalfLifeMultiplay *, class CBasePlayer *, entvars_t *, entvars_t *); /* linkage=_ZN18CHalfLifeMultiplay12PlayerKilledEP11CBasePlayerP9entvars_sS3_ */

	virtual void DeathNotice(class CHalfLifeMultiplay *, class CBasePlayer *, entvars_t *, entvars_t *); /* linkage=_ZN18CHalfLifeMultiplay11DeathNoticeEP11CBasePlayerP9entvars_sS3_ */

	virtual void PlayerGotWeapon(class CHalfLifeMultiplay *, class CBasePlayer *, class CBasePlayerItem *); /* linkage=_ZN18CHalfLifeMultiplay15PlayerGotWeaponEP11CBasePlayerP15CBasePlayerItem */

	virtual BOOL CanHavePlayerItem(class CHalfLifeMultiplay *, class CBasePlayer *, class CBasePlayerItem *); /* linkage=_ZN18CHalfLifeMultiplay17CanHavePlayerItemEP11CBasePlayerP15CBasePlayerItem */

	virtual int WeaponShouldRespawn(class CHalfLifeMultiplay *, class CBasePlayerItem *); /* linkage=_ZN18CHalfLifeMultiplay19WeaponShouldRespawnEP15CBasePlayerItem */

	virtual float FlWeaponRespawnTime(class CHalfLifeMultiplay *, class CBasePlayerItem *); /* linkage=_ZN18CHalfLifeMultiplay19FlWeaponRespawnTimeEP15CBasePlayerItem */

	virtual float FlWeaponTryRespawn(class CHalfLifeMultiplay *, class CBasePlayerItem *); /* linkage=_ZN18CHalfLifeMultiplay18FlWeaponTryRespawnEP15CBasePlayerItem */

	virtual class Vector VecWeaponRespawnSpot(class CHalfLifeMultiplay *, class CBasePlayerItem *); /* linkage=_ZN18CHalfLifeMultiplay20VecWeaponRespawnSpotEP15CBasePlayerItem */

	virtual BOOL CanHaveItem(class CHalfLifeMultiplay *, class CBasePlayer *, class CItem *); /* linkage=_ZN18CHalfLifeMultiplay11CanHaveItemEP11CBasePlayerP5CItem */

	virtual void PlayerGotItem(class CHalfLifeMultiplay *, class CBasePlayer *, class CItem *); /* linkage=_ZN18CHalfLifeMultiplay13PlayerGotItemEP11CBasePlayerP5CItem */

	virtual int ItemShouldRespawn(class CHalfLifeMultiplay *, class CItem *); /* linkage=_ZN18CHalfLifeMultiplay17ItemShouldRespawnEP5CItem */

	virtual float FlItemRespawnTime(class CHalfLifeMultiplay *, class CItem *); /* linkage=_ZN18CHalfLifeMultiplay17FlItemRespawnTimeEP5CItem */

	virtual class Vector VecItemRespawnSpot(class CHalfLifeMultiplay *, class CItem *); /* linkage=_ZN18CHalfLifeMultiplay18VecItemRespawnSpotEP5CItem */

	virtual void PlayerGotAmmo(class CHalfLifeMultiplay *, class CBasePlayer *, char *, int); /* linkage=_ZN18CHalfLifeMultiplay13PlayerGotAmmoEP11CBasePlayerPci */

	virtual int AmmoShouldRespawn(class CHalfLifeMultiplay *, class CBasePlayerAmmo *); /* linkage=_ZN18CHalfLifeMultiplay17AmmoShouldRespawnEP15CBasePlayerAmmo */

	virtual float FlAmmoRespawnTime(class CHalfLifeMultiplay *, class CBasePlayerAmmo *); /* linkage=_ZN18CHalfLifeMultiplay17FlAmmoRespawnTimeEP15CBasePlayerAmmo */

	virtual class Vector VecAmmoRespawnSpot(class CHalfLifeMultiplay *, class CBasePlayerAmmo *); /* linkage=_ZN18CHalfLifeMultiplay18VecAmmoRespawnSpotEP15CBasePlayerAmmo */

	virtual float FlHealthChargerRechargeTime(class CHalfLifeMultiplay *); /* linkage=_ZN18CHalfLifeMultiplay27FlHealthChargerRechargeTimeEv */

	virtual float FlHEVChargerRechargeTime(class CHalfLifeMultiplay *); /* linkage=_ZN18CHalfLifeMultiplay24FlHEVChargerRechargeTimeEv */

	virtual int DeadPlayerWeapons(class CHalfLifeMultiplay *, class CBasePlayer *); /* linkage=_ZN18CHalfLifeMultiplay17DeadPlayerWeaponsEP11CBasePlayer */

	virtual int DeadPlayerAmmo(class CHalfLifeMultiplay *, class CBasePlayer *); /* linkage=_ZN18CHalfLifeMultiplay14DeadPlayerAmmoEP11CBasePlayer */

	virtual char * GetTeamID(class CHalfLifeMultiplay *, class CBaseEntity *); /* linkage=_ZN18CHalfLifeMultiplay9GetTeamIDEP11CBaseEntity */

	virtual int PlayerRelationship(class CHalfLifeMultiplay *, class CBasePlayer *, class CBaseEntity *); /* linkage=_ZN18CHalfLifeMultiplay18PlayerRelationshipEP11CBasePlayerP11CBaseEntity */

	virtual BOOL PlayTextureSounds(class CHalfLifeMultiplay *); /* linkage=_ZN18CHalfLifeMultiplay17PlayTextureSoundsEv */

	virtual BOOL PlayFootstepSounds(class CHalfLifeMultiplay *, class CBasePlayer *, float); /* linkage=_ZN18CHalfLifeMultiplay18PlayFootstepSoundsEP11CBasePlayerf */

	virtual void GoToIntermission(class CHalfLifeMultiplay *); /* linkage=_ZN18CHalfLifeMultiplay16GoToIntermissionEv */

	virtual void SendMOTDToClient(class CHalfLifeMultiplay *, edict_t *); /* linkage=_ZN18CHalfLifeMultiplay16SendMOTDToClientEP7edict_s */

	virtual void ChangeLevel(class CHalfLifeMultiplay *); /* linkage=_ZN18CHalfLifeMultiplay11ChangeLevelEv */

	/* vtable has 49 entries: {
	   [1] = Think(_ZN18CHalfLifeMultiplay5ThinkEv), 
	   [2] = IsAllowedToSpawn(_ZN18CHalfLifeMultiplay16IsAllowedToSpawnEP11CBaseEntity), 
	   [3] = FAllowFlashlight(_ZN18CHalfLifeMultiplay16FAllowFlashlightEv), 
	   [4] = FShouldSwitchWeapon(_ZN18CHalfLifeMultiplay19FShouldSwitchWeaponEP11CBasePlayerP15CBasePlayerItem), 
	   [5] = GetNextBestWeapon(_ZN18CHalfLifeMultiplay17GetNextBestWeaponEP11CBasePlayerP15CBasePlayerItem), 
	   [6] = IsMultiplayer(_ZN18CHalfLifeMultiplay13IsMultiplayerEv), 
	   [7] = IsDeathmatch(_ZN18CHalfLifeMultiplay12IsDeathmatchEv), 
	   [9] = IsCoOp(_ZN18CHalfLifeMultiplay6IsCoOpEv), 
	   [11] = ClientConnected(_ZN18CHalfLifeMultiplay15ClientConnectedEP7edict_sPKcS3_Pc), 
	   [12] = InitHUD(_ZN18CHalfLifeMultiplay7InitHUDEP11CBasePlayer), 
	   [13] = ClientDisconnected(_ZN18CHalfLifeMultiplay18ClientDisconnectedEP7edict_s), 
	   [14] = UpdateGameMode(_ZN18CHalfLifeMultiplay14UpdateGameModeEP11CBasePlayer), 
	   [15] = FlPlayerFallDamage(_ZN18CHalfLifeMultiplay18FlPlayerFallDamageEP11CBasePlayer), 
	   [16] = FPlayerCanTakeDamage(_ZN18CHalfLifeMultiplay20FPlayerCanTakeDamageEP11CBasePlayerP11CBaseEntity), 
	   [18] = PlayerSpawn(_ZN18CHalfLifeMultiplay11PlayerSpawnEP11CBasePlayer), 
	   [19] = PlayerThink(_ZN18CHalfLifeMultiplay11PlayerThinkEP11CBasePlayer), 
	   [20] = FPlayerCanRespawn(_ZN18CHalfLifeMultiplay17FPlayerCanRespawnEP11CBasePlayer), 
	   [21] = FlPlayerSpawnTime(_ZN18CHalfLifeMultiplay17FlPlayerSpawnTimeEP11CBasePlayer), 
	   [24] = ClientCommand(_ZN18CHalfLifeMultiplay13ClientCommandEP11CBasePlayerPKc), 
	   [23] = AllowAutoTargetCrosshair(_ZN18CHalfLifeMultiplay24AllowAutoTargetCrosshairEv), 
	   [26] = IPointsForKill(_ZN18CHalfLifeMultiplay14IPointsForKillEP11CBasePlayerS1_), 
	   [27] = PlayerKilled(_ZN18CHalfLifeMultiplay12PlayerKilledEP11CBasePlayerP9entvars_sS3_), 
	   [28] = DeathNotice(_ZN18CHalfLifeMultiplay11DeathNoticeEP11CBasePlayerP9entvars_sS3_), 
	   [30] = PlayerGotWeapon(_ZN18CHalfLifeMultiplay15PlayerGotWeaponEP11CBasePlayerP15CBasePlayerItem), 
	   [29] = CanHavePlayerItem(_ZN18CHalfLifeMultiplay17CanHavePlayerItemEP11CBasePlayerP15CBasePlayerItem), 
	   [31] = WeaponShouldRespawn(_ZN18CHalfLifeMultiplay19WeaponShouldRespawnEP15CBasePlayerItem), 
	   [32] = FlWeaponRespawnTime(_ZN18CHalfLifeMultiplay19FlWeaponRespawnTimeEP15CBasePlayerItem), 
	   [33] = FlWeaponTryRespawn(_ZN18CHalfLifeMultiplay18FlWeaponTryRespawnEP15CBasePlayerItem), 
	   [34] = VecWeaponRespawnSpot(_ZN18CHalfLifeMultiplay20VecWeaponRespawnSpotEP15CBasePlayerItem), 
	   [35] = CanHaveItem(_ZN18CHalfLifeMultiplay11CanHaveItemEP11CBasePlayerP5CItem), 
	   [36] = PlayerGotItem(_ZN18CHalfLifeMultiplay13PlayerGotItemEP11CBasePlayerP5CItem), 
	   [37] = ItemShouldRespawn(_ZN18CHalfLifeMultiplay17ItemShouldRespawnEP5CItem), 
	   [38] = FlItemRespawnTime(_ZN18CHalfLifeMultiplay17FlItemRespawnTimeEP5CItem), 
	   [39] = VecItemRespawnSpot(_ZN18CHalfLifeMultiplay18VecItemRespawnSpotEP5CItem), 
	   [41] = PlayerGotAmmo(_ZN18CHalfLifeMultiplay13PlayerGotAmmoEP11CBasePlayerPci), 
	   [42] = AmmoShouldRespawn(_ZN18CHalfLifeMultiplay17AmmoShouldRespawnEP15CBasePlayerAmmo), 
	   [43] = FlAmmoRespawnTime(_ZN18CHalfLifeMultiplay17FlAmmoRespawnTimeEP15CBasePlayerAmmo), 
	   [44] = VecAmmoRespawnSpot(_ZN18CHalfLifeMultiplay18VecAmmoRespawnSpotEP15CBasePlayerAmmo), 
	   [45] = FlHealthChargerRechargeTime(_ZN18CHalfLifeMultiplay27FlHealthChargerRechargeTimeEv), 
	   [46] = FlHEVChargerRechargeTime(_ZN18CHalfLifeMultiplay24FlHEVChargerRechargeTimeEv), 
	   [47] = DeadPlayerWeapons(_ZN18CHalfLifeMultiplay17DeadPlayerWeaponsEP11CBasePlayer), 
	   [48] = DeadPlayerAmmo(_ZN18CHalfLifeMultiplay14DeadPlayerAmmoEP11CBasePlayer), 
	   [49] = GetTeamID(_ZN18CHalfLifeMultiplay9GetTeamIDEP11CBaseEntity), 
	   [50] = PlayerRelationship(_ZN18CHalfLifeMultiplay18PlayerRelationshipEP11CBasePlayerP11CBaseEntity), 
	   [51] = PlayTextureSounds(_ZN18CHalfLifeMultiplay17PlayTextureSoundsEv), 
	   [52] = PlayFootstepSounds(_ZN18CHalfLifeMultiplay18PlayFootstepSoundsEP11CBasePlayerf), 
	   [54] = GoToIntermission(_ZN18CHalfLifeMultiplay16GoToIntermissionEv), 
	   [53] = SendMOTDToClient(_ZN18CHalfLifeMultiplay16SendMOTDToClientEP7edict_s), 
	   [55] = ChangeLevel(_ZN18CHalfLifeMultiplay11ChangeLevelEv), 
	} */
	/* size: 16, cachelines: 1, members: 4 */
	/* last cacheline: 16 bytes */
};
class CGameRules {
	int ()(void) * *           _vptr.CGameRules;     /*     0     4 */
	void ~CGameRules(class CGameRules *, int); /* linkage=_ZN10CGameRulesD4Ev */

	void CGameRules(class CGameRules *, class CGameRules &); /* linkage=_ZN10CGameRulesC4EOS_ */

	void CGameRules(class CGameRules *, const class CGameRules  &); /* linkage=_ZN10CGameRulesC4ERKS_ */

	void CGameRules(class CGameRules *); /* linkage=_ZN10CGameRulesC4Ev */

	virtual void RefreshSkillData(class CGameRules *); /* linkage=_ZN10CGameRules16RefreshSkillDataEv */

	virtual void Think(class CGameRules *); /* linkage=_ZN10CGameRules5ThinkEv */

	virtual BOOL IsAllowedToSpawn(class CGameRules *, class CBaseEntity *); /* linkage=_ZN10CGameRules16IsAllowedToSpawnEP11CBaseEntity */

	virtual BOOL FAllowFlashlight(class CGameRules *); /* linkage=_ZN10CGameRules16FAllowFlashlightEv */

	virtual BOOL FShouldSwitchWeapon(class CGameRules *, class CBasePlayer *, class CBasePlayerItem *); /* linkage=_ZN10CGameRules19FShouldSwitchWeaponEP11CBasePlayerP15CBasePlayerItem */

	virtual BOOL GetNextBestWeapon(class CGameRules *, class CBasePlayer *, class CBasePlayerItem *); /* linkage=_ZN10CGameRules17GetNextBestWeaponEP11CBasePlayerP15CBasePlayerItem */

	virtual BOOL IsMultiplayer(class CGameRules *); /* linkage=_ZN10CGameRules13IsMultiplayerEv */

	virtual BOOL IsDeathmatch(class CGameRules *); /* linkage=_ZN10CGameRules12IsDeathmatchEv */

	virtual BOOL IsTeamplay(class CGameRules *); /* linkage=_ZN10CGameRules10IsTeamplayEv */

	virtual BOOL IsCoOp(class CGameRules *); /* linkage=_ZN10CGameRules6IsCoOpEv */

	virtual const char  * GetGameDescription(class CGameRules *); /* linkage=_ZN10CGameRules18GetGameDescriptionEv */

	virtual BOOL ClientConnected(class CGameRules *, edict_t *, const char  *, const char  *, char *); /* linkage=_ZN10CGameRules15ClientConnectedEP7edict_sPKcS3_Pc */

	virtual void InitHUD(class CGameRules *, class CBasePlayer *); /* linkage=_ZN10CGameRules7InitHUDEP11CBasePlayer */

	virtual void ClientDisconnected(class CGameRules *, edict_t *); /* linkage=_ZN10CGameRules18ClientDisconnectedEP7edict_s */

	virtual void UpdateGameMode(class CGameRules *, class CBasePlayer *); /* linkage=_ZN10CGameRules14UpdateGameModeEP11CBasePlayer */

	virtual float FlPlayerFallDamage(class CGameRules *, class CBasePlayer *); /* linkage=_ZN10CGameRules18FlPlayerFallDamageEP11CBasePlayer */

	virtual BOOL FPlayerCanTakeDamage(class CGameRules *, class CBasePlayer *, class CBaseEntity *); /* linkage=_ZN10CGameRules20FPlayerCanTakeDamageEP11CBasePlayerP11CBaseEntity */

	virtual BOOL ShouldAutoAim(class CGameRules *, class CBasePlayer *, edict_t *); /* linkage=_ZN10CGameRules13ShouldAutoAimEP11CBasePlayerP7edict_s */

	virtual void PlayerSpawn(class CGameRules *, class CBasePlayer *); /* linkage=_ZN10CGameRules11PlayerSpawnEP11CBasePlayer */

	virtual void PlayerThink(class CGameRules *, class CBasePlayer *); /* linkage=_ZN10CGameRules11PlayerThinkEP11CBasePlayer */

	virtual BOOL FPlayerCanRespawn(class CGameRules *, class CBasePlayer *); /* linkage=_ZN10CGameRules17FPlayerCanRespawnEP11CBasePlayer */

	virtual float FlPlayerSpawnTime(class CGameRules *, class CBasePlayer *); /* linkage=_ZN10CGameRules17FlPlayerSpawnTimeEP11CBasePlayer */

	virtual void GetPlayerSpawnSpot(class CGameRules *, class CBasePlayer *); /* linkage=_ZN10CGameRules18GetPlayerSpawnSpotEP11CBasePlayer */

	virtual BOOL AllowAutoTargetCrosshair(class CGameRules *); /* linkage=_ZN10CGameRules24AllowAutoTargetCrosshairEv */

	virtual BOOL ClientCommand(class CGameRules *, class CBasePlayer *, const char  *); /* linkage=_ZN10CGameRules13ClientCommandEP11CBasePlayerPKc */

	virtual void ClientUserInfoChanged(class CGameRules *, class CBasePlayer *, char *); /* linkage=_ZN10CGameRules21ClientUserInfoChangedEP11CBasePlayerPc */

	virtual int IPointsForKill(class CGameRules *, class CBasePlayer *, class CBasePlayer *); /* linkage=_ZN10CGameRules14IPointsForKillEP11CBasePlayerS1_ */

	virtual void PlayerKilled(class CGameRules *, class CBasePlayer *, entvars_t *, entvars_t *); /* linkage=_ZN10CGameRules12PlayerKilledEP11CBasePlayerP9entvars_sS3_ */

	virtual void DeathNotice(class CGameRules *, class CBasePlayer *, entvars_t *, entvars_t *); /* linkage=_ZN10CGameRules11DeathNoticeEP11CBasePlayerP9entvars_sS3_ */

	virtual BOOL CanHavePlayerItem(class CGameRules *, class CBasePlayer *, class CBasePlayerItem *); /* linkage=_ZN10CGameRules17CanHavePlayerItemEP11CBasePlayerP15CBasePlayerItem */

	virtual void PlayerGotWeapon(class CGameRules *, class CBasePlayer *, class CBasePlayerItem *); /* linkage=_ZN10CGameRules15PlayerGotWeaponEP11CBasePlayerP15CBasePlayerItem */

	virtual int WeaponShouldRespawn(class CGameRules *, class CBasePlayerItem *); /* linkage=_ZN10CGameRules19WeaponShouldRespawnEP15CBasePlayerItem */

	virtual float FlWeaponRespawnTime(class CGameRules *, class CBasePlayerItem *); /* linkage=_ZN10CGameRules19FlWeaponRespawnTimeEP15CBasePlayerItem */

	virtual float FlWeaponTryRespawn(class CGameRules *, class CBasePlayerItem *); /* linkage=_ZN10CGameRules18FlWeaponTryRespawnEP15CBasePlayerItem */

	virtual class Vector VecWeaponRespawnSpot(class CGameRules *, class CBasePlayerItem *); /* linkage=_ZN10CGameRules20VecWeaponRespawnSpotEP15CBasePlayerItem */

	virtual BOOL CanHaveItem(class CGameRules *, class CBasePlayer *, class CItem *); /* linkage=_ZN10CGameRules11CanHaveItemEP11CBasePlayerP5CItem */

	virtual void PlayerGotItem(class CGameRules *, class CBasePlayer *, class CItem *); /* linkage=_ZN10CGameRules13PlayerGotItemEP11CBasePlayerP5CItem */

	virtual int ItemShouldRespawn(class CGameRules *, class CItem *); /* linkage=_ZN10CGameRules17ItemShouldRespawnEP5CItem */

	virtual float FlItemRespawnTime(class CGameRules *, class CItem *); /* linkage=_ZN10CGameRules17FlItemRespawnTimeEP5CItem */

	virtual class Vector VecItemRespawnSpot(class CGameRules *, class CItem *); /* linkage=_ZN10CGameRules18VecItemRespawnSpotEP5CItem */

	virtual BOOL CanHaveAmmo(class CGameRules *, class CBasePlayer *, const char  *, int); /* linkage=_ZN10CGameRules11CanHaveAmmoEP11CBasePlayerPKci */

	virtual void PlayerGotAmmo(class CGameRules *, class CBasePlayer *, char *, int); /* linkage=_ZN10CGameRules13PlayerGotAmmoEP11CBasePlayerPci */

	virtual int AmmoShouldRespawn(class CGameRules *, class CBasePlayerAmmo *); /* linkage=_ZN10CGameRules17AmmoShouldRespawnEP15CBasePlayerAmmo */

	virtual float FlAmmoRespawnTime(class CGameRules *, class CBasePlayerAmmo *); /* linkage=_ZN10CGameRules17FlAmmoRespawnTimeEP15CBasePlayerAmmo */

	virtual class Vector VecAmmoRespawnSpot(class CGameRules *, class CBasePlayerAmmo *); /* linkage=_ZN10CGameRules18VecAmmoRespawnSpotEP15CBasePlayerAmmo */

	virtual float FlHealthChargerRechargeTime(class CGameRules *); /* linkage=_ZN10CGameRules27FlHealthChargerRechargeTimeEv */

	virtual float FlHEVChargerRechargeTime(class CGameRules *); /* linkage=_ZN10CGameRules24FlHEVChargerRechargeTimeEv */

	virtual int DeadPlayerWeapons(class CGameRules *, class CBasePlayer *); /* linkage=_ZN10CGameRules17DeadPlayerWeaponsEP11CBasePlayer */

	virtual int DeadPlayerAmmo(class CGameRules *, class CBasePlayer *); /* linkage=_ZN10CGameRules14DeadPlayerAmmoEP11CBasePlayer */

	virtual char * GetTeamID(class CGameRules *, class CBaseEntity *); /* linkage=_ZN10CGameRules9GetTeamIDEP11CBaseEntity */

	virtual int PlayerRelationship(class CGameRules *, class CBasePlayer *, class CBaseEntity *); /* linkage=_ZN10CGameRules18PlayerRelationshipEP11CBasePlayerP11CBaseEntity */

	virtual BOOL PlayTextureSounds(class CGameRules *); /* linkage=_ZN10CGameRules17PlayTextureSoundsEv */

	virtual BOOL PlayFootstepSounds(class CGameRules *, class CBasePlayer *, float); /* linkage=_ZN10CGameRules18PlayFootstepSoundsEP11CBasePlayerf */

	virtual void SendMOTDToClient(class CGameRules *, edict_t *); /* linkage=_ZN10CGameRules16SendMOTDToClientEP7edict_s */

	/* vtable has 54 entries: {
	   [0] = RefreshSkillData(_ZN10CGameRules16RefreshSkillDataEv), 
	   [1] = Think(_ZN10CGameRules5ThinkEv), 
	   [2] = IsAllowedToSpawn(_ZN10CGameRules16IsAllowedToSpawnEP11CBaseEntity), 
	   [3] = FAllowFlashlight(_ZN10CGameRules16FAllowFlashlightEv), 
	   [4] = FShouldSwitchWeapon(_ZN10CGameRules19FShouldSwitchWeaponEP11CBasePlayerP15CBasePlayerItem), 
	   [5] = GetNextBestWeapon(_ZN10CGameRules17GetNextBestWeaponEP11CBasePlayerP15CBasePlayerItem), 
	   [6] = IsMultiplayer(_ZN10CGameRules13IsMultiplayerEv), 
	   [7] = IsDeathmatch(_ZN10CGameRules12IsDeathmatchEv), 
	   [8] = IsTeamplay(_ZN10CGameRules10IsTeamplayEv), 
	   [9] = IsCoOp(_ZN10CGameRules6IsCoOpEv), 
	   [10] = GetGameDescription(_ZN10CGameRules18GetGameDescriptionEv), 
	   [11] = ClientConnected(_ZN10CGameRules15ClientConnectedEP7edict_sPKcS3_Pc), 
	   [12] = InitHUD(_ZN10CGameRules7InitHUDEP11CBasePlayer), 
	   [13] = ClientDisconnected(_ZN10CGameRules18ClientDisconnectedEP7edict_s), 
	   [14] = UpdateGameMode(_ZN10CGameRules14UpdateGameModeEP11CBasePlayer), 
	   [15] = FlPlayerFallDamage(_ZN10CGameRules18FlPlayerFallDamageEP11CBasePlayer), 
	   [16] = FPlayerCanTakeDamage(_ZN10CGameRules20FPlayerCanTakeDamageEP11CBasePlayerP11CBaseEntity), 
	   [17] = ShouldAutoAim(_ZN10CGameRules13ShouldAutoAimEP11CBasePlayerP7edict_s), 
	   [18] = PlayerSpawn(_ZN10CGameRules11PlayerSpawnEP11CBasePlayer), 
	   [19] = PlayerThink(_ZN10CGameRules11PlayerThinkEP11CBasePlayer), 
	   [20] = FPlayerCanRespawn(_ZN10CGameRules17FPlayerCanRespawnEP11CBasePlayer), 
	   [21] = FlPlayerSpawnTime(_ZN10CGameRules17FlPlayerSpawnTimeEP11CBasePlayer), 
	   [22] = GetPlayerSpawnSpot(_ZN10CGameRules18GetPlayerSpawnSpotEP11CBasePlayer), 
	   [23] = AllowAutoTargetCrosshair(_ZN10CGameRules24AllowAutoTargetCrosshairEv), 
	   [24] = ClientCommand(_ZN10CGameRules13ClientCommandEP11CBasePlayerPKc), 
	   [25] = ClientUserInfoChanged(_ZN10CGameRules21ClientUserInfoChangedEP11CBasePlayerPc), 
	   [26] = IPointsForKill(_ZN10CGameRules14IPointsForKillEP11CBasePlayerS1_), 
	   [27] = PlayerKilled(_ZN10CGameRules12PlayerKilledEP11CBasePlayerP9entvars_sS3_), 
	   [28] = DeathNotice(_ZN10CGameRules11DeathNoticeEP11CBasePlayerP9entvars_sS3_), 
	   [29] = CanHavePlayerItem(_ZN10CGameRules17CanHavePlayerItemEP11CBasePlayerP15CBasePlayerItem), 
	   [30] = PlayerGotWeapon(_ZN10CGameRules15PlayerGotWeaponEP11CBasePlayerP15CBasePlayerItem), 
	   [31] = WeaponShouldRespawn(_ZN10CGameRules19WeaponShouldRespawnEP15CBasePlayerItem), 
	   [32] = FlWeaponRespawnTime(_ZN10CGameRules19FlWeaponRespawnTimeEP15CBasePlayerItem), 
	   [33] = FlWeaponTryRespawn(_ZN10CGameRules18FlWeaponTryRespawnEP15CBasePlayerItem), 
	   [34] = VecWeaponRespawnSpot(_ZN10CGameRules20VecWeaponRespawnSpotEP15CBasePlayerItem), 
	   [35] = CanHaveItem(_ZN10CGameRules11CanHaveItemEP11CBasePlayerP5CItem), 
	   [36] = PlayerGotItem(_ZN10CGameRules13PlayerGotItemEP11CBasePlayerP5CItem), 
	   [37] = ItemShouldRespawn(_ZN10CGameRules17ItemShouldRespawnEP5CItem), 
	   [38] = FlItemRespawnTime(_ZN10CGameRules17FlItemRespawnTimeEP5CItem), 
	   [39] = VecItemRespawnSpot(_ZN10CGameRules18VecItemRespawnSpotEP5CItem), 
	   [40] = CanHaveAmmo(_ZN10CGameRules11CanHaveAmmoEP11CBasePlayerPKci), 
	   [41] = PlayerGotAmmo(_ZN10CGameRules13PlayerGotAmmoEP11CBasePlayerPci), 
	   [42] = AmmoShouldRespawn(_ZN10CGameRules17AmmoShouldRespawnEP15CBasePlayerAmmo), 
	   [43] = FlAmmoRespawnTime(_ZN10CGameRules17FlAmmoRespawnTimeEP15CBasePlayerAmmo), 
	   [44] = VecAmmoRespawnSpot(_ZN10CGameRules18VecAmmoRespawnSpotEP15CBasePlayerAmmo), 
	   [45] = FlHealthChargerRechargeTime(_ZN10CGameRules27FlHealthChargerRechargeTimeEv), 
	   [46] = FlHEVChargerRechargeTime(_ZN10CGameRules24FlHEVChargerRechargeTimeEv), 
	   [47] = DeadPlayerWeapons(_ZN10CGameRules17DeadPlayerWeaponsEP11CBasePlayer), 
	   [48] = DeadPlayerAmmo(_ZN10CGameRules14DeadPlayerAmmoEP11CBasePlayer), 
	   [49] = GetTeamID(_ZN10CGameRules9GetTeamIDEP11CBaseEntity), 
	   [50] = PlayerRelationship(_ZN10CGameRules18PlayerRelationshipEP11CBasePlayerP11CBaseEntity), 
	   [51] = PlayTextureSounds(_ZN10CGameRules17PlayTextureSoundsEv), 
	   [52] = PlayFootstepSounds(_ZN10CGameRules18PlayFootstepSoundsEP11CBasePlayerf), 
	   [53] = SendMOTDToClient(_ZN10CGameRules16SendMOTDToClientEP7edict_s), 
	} */
	/* size: 4, cachelines: 1, members: 1 */
	/* last cacheline: 4 bytes */
};
class CHalfLifeRules : public CGameRules {
public:

	/* class CGameRules          <ancestor>; */      /*     0     4 */
	void CHalfLifeRules(class CHalfLifeRules *, class CHalfLifeRules &); /* linkage=_ZN14CHalfLifeRulesC4EOS_ */

	void CHalfLifeRules(class CHalfLifeRules *, const class CHalfLifeRules  &); /* linkage=_ZN14CHalfLifeRulesC4ERKS_ */

	void CHalfLifeRules(class CHalfLifeRules *); /* linkage=_ZN14CHalfLifeRulesC4Ev */

	virtual void Think(class CHalfLifeRules *); /* linkage=_ZN14CHalfLifeRules5ThinkEv */

	virtual BOOL IsAllowedToSpawn(class CHalfLifeRules *, class CBaseEntity *); /* linkage=_ZN14CHalfLifeRules16IsAllowedToSpawnEP11CBaseEntity */

	virtual BOOL FAllowFlashlight(class CHalfLifeRules *); /* linkage=_ZN14CHalfLifeRules16FAllowFlashlightEv */

	virtual BOOL FShouldSwitchWeapon(class CHalfLifeRules *, class CBasePlayer *, class CBasePlayerItem *); /* linkage=_ZN14CHalfLifeRules19FShouldSwitchWeaponEP11CBasePlayerP15CBasePlayerItem */

	virtual BOOL GetNextBestWeapon(class CHalfLifeRules *, class CBasePlayer *, class CBasePlayerItem *); /* linkage=_ZN14CHalfLifeRules17GetNextBestWeaponEP11CBasePlayerP15CBasePlayerItem */

	virtual BOOL IsMultiplayer(class CHalfLifeRules *); /* linkage=_ZN14CHalfLifeRules13IsMultiplayerEv */

	virtual BOOL IsDeathmatch(class CHalfLifeRules *); /* linkage=_ZN14CHalfLifeRules12IsDeathmatchEv */

	virtual BOOL IsCoOp(class CHalfLifeRules *); /* linkage=_ZN14CHalfLifeRules6IsCoOpEv */

	virtual BOOL ClientConnected(class CHalfLifeRules *, edict_t *, const char  *, const char  *, char *); /* linkage=_ZN14CHalfLifeRules15ClientConnectedEP7edict_sPKcS3_Pc */

	virtual void InitHUD(class CHalfLifeRules *, class CBasePlayer *); /* linkage=_ZN14CHalfLifeRules7InitHUDEP11CBasePlayer */

	virtual void ClientDisconnected(class CHalfLifeRules *, edict_t *); /* linkage=_ZN14CHalfLifeRules18ClientDisconnectedEP7edict_s */

	virtual float FlPlayerFallDamage(class CHalfLifeRules *, class CBasePlayer *); /* linkage=_ZN14CHalfLifeRules18FlPlayerFallDamageEP11CBasePlayer */

	virtual void PlayerSpawn(class CHalfLifeRules *, class CBasePlayer *); /* linkage=_ZN14CHalfLifeRules11PlayerSpawnEP11CBasePlayer */

	virtual void PlayerThink(class CHalfLifeRules *, class CBasePlayer *); /* linkage=_ZN14CHalfLifeRules11PlayerThinkEP11CBasePlayer */

	virtual BOOL FPlayerCanRespawn(class CHalfLifeRules *, class CBasePlayer *); /* linkage=_ZN14CHalfLifeRules17FPlayerCanRespawnEP11CBasePlayer */

	virtual float FlPlayerSpawnTime(class CHalfLifeRules *, class CBasePlayer *); /* linkage=_ZN14CHalfLifeRules17FlPlayerSpawnTimeEP11CBasePlayer */

	virtual BOOL AllowAutoTargetCrosshair(class CHalfLifeRules *); /* linkage=_ZN14CHalfLifeRules24AllowAutoTargetCrosshairEv */

	virtual int IPointsForKill(class CHalfLifeRules *, class CBasePlayer *, class CBasePlayer *); /* linkage=_ZN14CHalfLifeRules14IPointsForKillEP11CBasePlayerS1_ */

	virtual void PlayerKilled(class CHalfLifeRules *, class CBasePlayer *, entvars_t *, entvars_t *); /* linkage=_ZN14CHalfLifeRules12PlayerKilledEP11CBasePlayerP9entvars_sS3_ */

	virtual void DeathNotice(class CHalfLifeRules *, class CBasePlayer *, entvars_t *, entvars_t *); /* linkage=_ZN14CHalfLifeRules11DeathNoticeEP11CBasePlayerP9entvars_sS3_ */

	virtual void PlayerGotWeapon(class CHalfLifeRules *, class CBasePlayer *, class CBasePlayerItem *); /* linkage=_ZN14CHalfLifeRules15PlayerGotWeaponEP11CBasePlayerP15CBasePlayerItem */

	virtual int WeaponShouldRespawn(class CHalfLifeRules *, class CBasePlayerItem *); /* linkage=_ZN14CHalfLifeRules19WeaponShouldRespawnEP15CBasePlayerItem */

	virtual float FlWeaponRespawnTime(class CHalfLifeRules *, class CBasePlayerItem *); /* linkage=_ZN14CHalfLifeRules19FlWeaponRespawnTimeEP15CBasePlayerItem */

	virtual float FlWeaponTryRespawn(class CHalfLifeRules *, class CBasePlayerItem *); /* linkage=_ZN14CHalfLifeRules18FlWeaponTryRespawnEP15CBasePlayerItem */

	virtual class Vector VecWeaponRespawnSpot(class CHalfLifeRules *, class CBasePlayerItem *); /* linkage=_ZN14CHalfLifeRules20VecWeaponRespawnSpotEP15CBasePlayerItem */

	virtual BOOL CanHaveItem(class CHalfLifeRules *, class CBasePlayer *, class CItem *); /* linkage=_ZN14CHalfLifeRules11CanHaveItemEP11CBasePlayerP5CItem */

	virtual void PlayerGotItem(class CHalfLifeRules *, class CBasePlayer *, class CItem *); /* linkage=_ZN14CHalfLifeRules13PlayerGotItemEP11CBasePlayerP5CItem */

	virtual int ItemShouldRespawn(class CHalfLifeRules *, class CItem *); /* linkage=_ZN14CHalfLifeRules17ItemShouldRespawnEP5CItem */

	virtual float FlItemRespawnTime(class CHalfLifeRules *, class CItem *); /* linkage=_ZN14CHalfLifeRules17FlItemRespawnTimeEP5CItem */

	virtual class Vector VecItemRespawnSpot(class CHalfLifeRules *, class CItem *); /* linkage=_ZN14CHalfLifeRules18VecItemRespawnSpotEP5CItem */

	virtual void PlayerGotAmmo(class CHalfLifeRules *, class CBasePlayer *, char *, int); /* linkage=_ZN14CHalfLifeRules13PlayerGotAmmoEP11CBasePlayerPci */

	virtual int AmmoShouldRespawn(class CHalfLifeRules *, class CBasePlayerAmmo *); /* linkage=_ZN14CHalfLifeRules17AmmoShouldRespawnEP15CBasePlayerAmmo */

	virtual float FlAmmoRespawnTime(class CHalfLifeRules *, class CBasePlayerAmmo *); /* linkage=_ZN14CHalfLifeRules17FlAmmoRespawnTimeEP15CBasePlayerAmmo */

	virtual class Vector VecAmmoRespawnSpot(class CHalfLifeRules *, class CBasePlayerAmmo *); /* linkage=_ZN14CHalfLifeRules18VecAmmoRespawnSpotEP15CBasePlayerAmmo */

	virtual float FlHealthChargerRechargeTime(class CHalfLifeRules *); /* linkage=_ZN14CHalfLifeRules27FlHealthChargerRechargeTimeEv */

	virtual int DeadPlayerWeapons(class CHalfLifeRules *, class CBasePlayer *); /* linkage=_ZN14CHalfLifeRules17DeadPlayerWeaponsEP11CBasePlayer */

	virtual int DeadPlayerAmmo(class CHalfLifeRules *, class CBasePlayer *); /* linkage=_ZN14CHalfLifeRules14DeadPlayerAmmoEP11CBasePlayer */

	virtual char * GetTeamID(class CHalfLifeRules *, class CBaseEntity *); /* linkage=_ZN14CHalfLifeRules9GetTeamIDEP11CBaseEntity */

	virtual int PlayerRelationship(class CHalfLifeRules *, class CBasePlayer *, class CBaseEntity *); /* linkage=_ZN14CHalfLifeRules18PlayerRelationshipEP11CBasePlayerP11CBaseEntity */

	/* vtable has 39 entries: {
	   [1] = Think(_ZN14CHalfLifeRules5ThinkEv), 
	   [2] = IsAllowedToSpawn(_ZN14CHalfLifeRules16IsAllowedToSpawnEP11CBaseEntity), 
	   [3] = FAllowFlashlight(_ZN14CHalfLifeRules16FAllowFlashlightEv), 
	   [4] = FShouldSwitchWeapon(_ZN14CHalfLifeRules19FShouldSwitchWeaponEP11CBasePlayerP15CBasePlayerItem), 
	   [5] = GetNextBestWeapon(_ZN14CHalfLifeRules17GetNextBestWeaponEP11CBasePlayerP15CBasePlayerItem), 
	   [6] = IsMultiplayer(_ZN14CHalfLifeRules13IsMultiplayerEv), 
	   [7] = IsDeathmatch(_ZN14CHalfLifeRules12IsDeathmatchEv), 
	   [9] = IsCoOp(_ZN14CHalfLifeRules6IsCoOpEv), 
	   [11] = ClientConnected(_ZN14CHalfLifeRules15ClientConnectedEP7edict_sPKcS3_Pc), 
	   [12] = InitHUD(_ZN14CHalfLifeRules7InitHUDEP11CBasePlayer), 
	   [13] = ClientDisconnected(_ZN14CHalfLifeRules18ClientDisconnectedEP7edict_s), 
	   [15] = FlPlayerFallDamage(_ZN14CHalfLifeRules18FlPlayerFallDamageEP11CBasePlayer), 
	   [18] = PlayerSpawn(_ZN14CHalfLifeRules11PlayerSpawnEP11CBasePlayer), 
	   [19] = PlayerThink(_ZN14CHalfLifeRules11PlayerThinkEP11CBasePlayer), 
	   [20] = FPlayerCanRespawn(_ZN14CHalfLifeRules17FPlayerCanRespawnEP11CBasePlayer), 
	   [21] = FlPlayerSpawnTime(_ZN14CHalfLifeRules17FlPlayerSpawnTimeEP11CBasePlayer), 
	   [23] = AllowAutoTargetCrosshair(_ZN14CHalfLifeRules24AllowAutoTargetCrosshairEv), 
	   [26] = IPointsForKill(_ZN14CHalfLifeRules14IPointsForKillEP11CBasePlayerS1_), 
	   [27] = PlayerKilled(_ZN14CHalfLifeRules12PlayerKilledEP11CBasePlayerP9entvars_sS3_), 
	   [28] = DeathNotice(_ZN14CHalfLifeRules11DeathNoticeEP11CBasePlayerP9entvars_sS3_), 
	   [30] = PlayerGotWeapon(_ZN14CHalfLifeRules15PlayerGotWeaponEP11CBasePlayerP15CBasePlayerItem), 
	   [31] = WeaponShouldRespawn(_ZN14CHalfLifeRules19WeaponShouldRespawnEP15CBasePlayerItem), 
	   [32] = FlWeaponRespawnTime(_ZN14CHalfLifeRules19FlWeaponRespawnTimeEP15CBasePlayerItem), 
	   [33] = FlWeaponTryRespawn(_ZN14CHalfLifeRules18FlWeaponTryRespawnEP15CBasePlayerItem), 
	   [34] = VecWeaponRespawnSpot(_ZN14CHalfLifeRules20VecWeaponRespawnSpotEP15CBasePlayerItem), 
	   [35] = CanHaveItem(_ZN14CHalfLifeRules11CanHaveItemEP11CBasePlayerP5CItem), 
	   [36] = PlayerGotItem(_ZN14CHalfLifeRules13PlayerGotItemEP11CBasePlayerP5CItem), 
	   [37] = ItemShouldRespawn(_ZN14CHalfLifeRules17ItemShouldRespawnEP5CItem), 
	   [38] = FlItemRespawnTime(_ZN14CHalfLifeRules17FlItemRespawnTimeEP5CItem), 
	   [39] = VecItemRespawnSpot(_ZN14CHalfLifeRules18VecItemRespawnSpotEP5CItem), 
	   [41] = PlayerGotAmmo(_ZN14CHalfLifeRules13PlayerGotAmmoEP11CBasePlayerPci), 
	   [42] = AmmoShouldRespawn(_ZN14CHalfLifeRules17AmmoShouldRespawnEP15CBasePlayerAmmo), 
	   [43] = FlAmmoRespawnTime(_ZN14CHalfLifeRules17FlAmmoRespawnTimeEP15CBasePlayerAmmo), 
	   [44] = VecAmmoRespawnSpot(_ZN14CHalfLifeRules18VecAmmoRespawnSpotEP15CBasePlayerAmmo), 
	   [45] = FlHealthChargerRechargeTime(_ZN14CHalfLifeRules27FlHealthChargerRechargeTimeEv), 
	   [47] = DeadPlayerWeapons(_ZN14CHalfLifeRules17DeadPlayerWeaponsEP11CBasePlayer), 
	   [48] = DeadPlayerAmmo(_ZN14CHalfLifeRules14DeadPlayerAmmoEP11CBasePlayer), 
	   [49] = GetTeamID(_ZN14CHalfLifeRules9GetTeamIDEP11CBaseEntity), 
	   [50] = PlayerRelationship(_ZN14CHalfLifeRules18PlayerRelationshipEP11CBasePlayerP11CBaseEntity), 
	} */
	/* size: 4, cachelines: 1, members: 1 */
	/* last cacheline: 4 bytes */
};
class CTelefragDeath : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	class CBaseEntity *        m_pIgnore;            /*  1140     4 */
	void CTelefragDeath(class CTelefragDeath *, class CTelefragDeath &); /* linkage=_ZN14CTelefragDeathC4EOS_ */

	void CTelefragDeath(class CTelefragDeath *, const class CTelefragDeath  &); /* linkage=_ZN14CTelefragDeathC4ERKS_ */

	void CTelefragDeath(class CTelefragDeath *); /* linkage=_ZN14CTelefragDeathC4Ev */

	void Spawn(class CTelefragDeath *, class CBaseEntity *); /* linkage=_ZN14CTelefragDeath5SpawnEP11CBaseEntity */

	void DeathTouch(class CTelefragDeath *, class CBaseEntity *); /* linkage=_ZN14CTelefragDeath10DeathTouchEP11CBaseEntity */

	virtual void ~CTelefragDeath(class CTelefragDeath *, int); /* linkage=_ZN14CTelefragDeathD4Ev */


	/* size: 1144, cachelines: 18, members: 2 */
	/* sum members: 4, holes: 1, sum holes: 1140 */
	/* last cacheline: 56 bytes */
};
class CGenericMonster : public CBaseMonster {
public:

	/* class CBaseMonster        <ancestor>; */      /*     0     0 */
	void CGenericMonster(class CGenericMonster *, class CGenericMonster &); /* linkage=_ZN15CGenericMonsterC4EOS_ */

	void CGenericMonster(class CGenericMonster *, const class CGenericMonster  &); /* linkage=_ZN15CGenericMonsterC4ERKS_ */

	void CGenericMonster(class CGenericMonster *); /* linkage=_ZN15CGenericMonsterC4Ev */

	virtual void Spawn(class CGenericMonster *); /* linkage=_ZN15CGenericMonster5SpawnEv */

	virtual void Precache(class CGenericMonster *); /* linkage=_ZN15CGenericMonster8PrecacheEv */

	virtual void SetYawSpeed(class CGenericMonster *); /* linkage=_ZN15CGenericMonster11SetYawSpeedEv */

	virtual int Classify(class CGenericMonster *); /* linkage=_ZN15CGenericMonster8ClassifyEv */

	virtual void HandleAnimEvent(class CGenericMonster *, MonsterEvent_t *); /* linkage=_ZN15CGenericMonster15HandleAnimEventEP14MonsterEvent_t */

	virtual int ISoundMask(class CGenericMonster *); /* linkage=_ZN15CGenericMonster10ISoundMaskEv */

	virtual void ~CGenericMonster(class CGenericMonster *, int); /* linkage=_ZN15CGenericMonsterD4Ev */

	/* vtable has 6 entries: {
	   [2] = Spawn(_ZN15CGenericMonster5SpawnEv), 
	   [3] = Precache(_ZN15CGenericMonster8PrecacheEv), 
	   [105] = SetYawSpeed(_ZN15CGenericMonster11SetYawSpeedEv), 
	   [10] = Classify(_ZN15CGenericMonster8ClassifyEv), 
	   [65] = HandleAnimEvent(_ZN15CGenericMonster15HandleAnimEventEP14MonsterEvent_t), 
	   [115] = ISoundMask(_ZN15CGenericMonster10ISoundMaskEv), 
	} */
	/* size: 1724, cachelines: 27, members: 1 */
	/* padding: 1724 */
	/* last cacheline: 60 bytes */
};
class CGrenade : public CBaseMonster {

	/* XXX 1724 bytes hole, try to pack */
	enum {
		SATCHEL_DETONATE = 0,
		SATCHEL_RELEASE  = 1,
	};

public:


	/* class CBaseMonster        <ancestor>; */      /*     0     0 */
	/* --- cacheline 26 boundary (1664 bytes) was 60 bytes ago --- */
	BOOL                       m_bDontPlaySound;     /*  1724     4 */
	/* --- cacheline 27 boundary (1728 bytes) --- */
	BOOL                       m_bDontSpark;         /*  1728     4 */
	BOOL                       m_bDontSmoke;         /*  1732     4 */
	float                      m_flExplosionScale;   /*  1736     4 */
	float                      m_flSmokeScale;       /*  1740     4 */
	BOOL                       m_fRegisteredSound;   /*  1744     4 */
	short unsigned int         m_usExplode;          /*  1748     2 */
	typedef enum {
		SATCHEL_DETONATE = 0,
		SATCHEL_RELEASE  = 1,
	} SATCHELCODE;

	void CGrenade(class CGrenade *, class CGrenade &); /* linkage=_ZN8CGrenadeC4EOS_ */

	void CGrenade(class CGrenade *, const class CGrenade  &); /* linkage=_ZN8CGrenadeC4ERKS_ */

	void CGrenade(class CGrenade *); /* linkage=_ZN8CGrenadeC4Ev */

	virtual void Spawn(class CGrenade *); /* linkage=_ZN8CGrenade5SpawnEv */

	class CGrenade * ShootTimed(entvars_t *, class Vector, class Vector, float); /* linkage=_ZN8CGrenade10ShootTimedEP9entvars_s6VectorS2_f */

	class CGrenade * ShootContact(entvars_t *, class Vector, class Vector); /* linkage=_ZN8CGrenade12ShootContactEP9entvars_s6VectorS2_ */

	class CGrenade * ShootSatchelCharge(entvars_t *, class Vector, class Vector); /* linkage=_ZN8CGrenade18ShootSatchelChargeEP9entvars_s6VectorS2_ */

	void UseSatchelCharges(entvars_t *, SATCHELCODE); /* linkage=_ZN8CGrenade17UseSatchelChargesEP9entvars_sNS_11SATCHELCODEE */

	virtual void Explode(class CGrenade *, class Vector, class Vector); /* linkage=_ZN8CGrenade7ExplodeE6VectorS0_ */

	virtual void Explode(class CGrenade *, class  *, int); /* linkage=_ZN8CGrenade7ExplodeEP11TraceResulti */

	void Smoke(class CGrenade *); /* linkage=_ZN8CGrenade5SmokeEv */

	void BounceTouch(class CGrenade *, class CBaseEntity *); /* linkage=_ZN8CGrenade11BounceTouchEP11CBaseEntity */

	void SlideTouch(class CGrenade *, class CBaseEntity *); /* linkage=_ZN8CGrenade10SlideTouchEP11CBaseEntity */

	void ExplodeTouch(class CGrenade *, class CBaseEntity *); /* linkage=_ZN8CGrenade12ExplodeTouchEP11CBaseEntity */

	void DangerSoundThink(class CGrenade *); /* linkage=_ZN8CGrenade16DangerSoundThinkEv */

	void PreDetonate(class CGrenade *); /* linkage=_ZN8CGrenade11PreDetonateEv */

	void Detonate(class CGrenade *); /* linkage=_ZN8CGrenade8DetonateEv */

	void DetonateUse(class CGrenade *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN8CGrenade11DetonateUseEP11CBaseEntityS1_8USE_TYPEf */

	void TumbleThink(class CGrenade *); /* linkage=_ZN8CGrenade11TumbleThinkEv */

	virtual BOOL setBirthdayModel(class CGrenade *); /* linkage=_ZN8CGrenade16setBirthdayModelEv */

	virtual void setModel(class CGrenade *); /* linkage=_ZN8CGrenade8setModelEv */

	virtual void BounceSound(class CGrenade *); /* linkage=_ZN8CGrenade11BounceSoundEv */

	virtual int BloodColor(class CGrenade *); /* linkage=_ZN8CGrenade10BloodColorEv */

	virtual void Killed(class CGrenade *, entvars_t *, entvars_t *, int); /* linkage=_ZN8CGrenade6KilledEP9entvars_sS1_i */

	BOOL InNoGrenadeZone(class CGrenade *, class Vector); /* linkage=_ZN8CGrenade15InNoGrenadeZoneE6Vector */

	virtual void ~CGrenade(class CGrenade *, int); /* linkage=_ZN8CGrenadeD4Ev */

	/* vtable has 8 entries: {
	   [2] = Spawn(_ZN8CGrenade5SpawnEv), 
	   [134] = Explode(_ZN8CGrenade7ExplodeE6VectorS0_), 
	   [135] = Explode(_ZN8CGrenade7ExplodeEP11TraceResulti), 
	   [136] = setBirthdayModel(_ZN8CGrenade16setBirthdayModelEv), 
	   [137] = setModel(_ZN8CGrenade8setModelEv), 
	   [138] = BounceSound(_ZN8CGrenade11BounceSoundEv), 
	   [16] = BloodColor(_ZN8CGrenade10BloodColorEv), 
	   [15] = Killed(_ZN8CGrenade6KilledEP9entvars_sS1_i), 
	} */
	/* size: 1752, cachelines: 28, members: 8 */
	/* sum members: 26, holes: 1, sum holes: 1724 */
	/* padding: 2 */
	/* last cacheline: 24 bytes */
};
class CRecharge : public CBaseToggle {

	/* XXX 1300 bytes hole, try to pack */
public:


	/* class CBaseToggle         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[5]; /*     0     0 */
	/* --- cacheline 20 boundary (1280 bytes) was 20 bytes ago --- */
	float                      m_flNextCharge;       /*  1300     4 */
	int                        m_iReactivate;        /*  1304     4 */
	int                        m_iJuice;             /*  1308     4 */
	int                        m_iOn;                /*  1312     4 */
	float                      m_flSoundTime;        /*  1316     4 */
	void CRecharge(class CRecharge *, class CRecharge &); /* linkage=_ZN9CRechargeC4EOS_ */

	void CRecharge(class CRecharge *, const class CRecharge  &); /* linkage=_ZN9CRechargeC4ERKS_ */

	void CRecharge(class CRecharge *); /* linkage=_ZN9CRechargeC4Ev */

	virtual void Spawn(class CRecharge *); /* linkage=_ZN9CRecharge5SpawnEv */

	virtual void Precache(class CRecharge *); /* linkage=_ZN9CRecharge8PrecacheEv */

	void Off(class CRecharge *); /* linkage=_ZN9CRecharge3OffEv */

	void Recharge(class CRecharge *); /* linkage=_ZN9CRecharge8RechargeEv */

	virtual void KeyValue(class CRecharge *, KeyValueData *); /* linkage=_ZN9CRecharge8KeyValueEP14KeyValueData_s */

	virtual void Use(class CRecharge *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN9CRecharge3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual int ObjectCaps(class CRecharge *); /* linkage=_ZN9CRecharge10ObjectCapsEv */

	virtual int Save(class CRecharge *, class CSave &); /* linkage=_ZN9CRecharge4SaveER5CSave */

	virtual int Restore(class CRecharge *, class CRestore &); /* linkage=_ZN9CRecharge7RestoreER8CRestore */

	virtual void ~CRecharge(class CRecharge *, int); /* linkage=_ZN9CRechargeD4Ev */

	/* vtable has 7 entries: {
	   [2] = Spawn(_ZN9CRecharge5SpawnEv), 
	   [3] = Precache(_ZN9CRecharge8PrecacheEv), 
	   [4] = KeyValue(_ZN9CRecharge8KeyValueEP14KeyValueData_s), 
	   [45] = Use(_ZN9CRecharge3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [7] = ObjectCaps(_ZN9CRecharge10ObjectCapsEv), 
	   [5] = Save(_ZN9CRecharge4SaveER5CSave), 
	   [6] = Restore(_ZN9CRecharge7RestoreER8CRestore), 
	} */
	/* size: 1320, cachelines: 21, members: 6, static members: 1 */
	/* sum members: 20, holes: 1, sum holes: 1300 */
	/* last cacheline: 40 bytes */
};
class CCineBlood : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CCineBlood(class CCineBlood *, class CCineBlood &); /* linkage=_ZN10CCineBloodC4EOS_ */

	void CCineBlood(class CCineBlood *, const class CCineBlood  &); /* linkage=_ZN10CCineBloodC4ERKS_ */

	void CCineBlood(class CCineBlood *); /* linkage=_ZN10CCineBloodC4Ev */

	virtual void Spawn(class CCineBlood *); /* linkage=_ZN10CCineBlood5SpawnEv */

	void BloodStart(class CCineBlood *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN10CCineBlood10BloodStartEP11CBaseEntityS1_8USE_TYPEf */

	void BloodGush(class CCineBlood *); /* linkage=_ZN10CCineBlood9BloodGushEv */

	virtual void ~CCineBlood(class CCineBlood *, int); /* linkage=_ZN10CCineBloodD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN10CCineBlood5SpawnEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CLegacyCineMonster : public CBaseMonster {
public:

	/* class CBaseMonster        <ancestor>; */      /*     0     0 */
	void CLegacyCineMonster(class CLegacyCineMonster *, class CLegacyCineMonster &); /* linkage=_ZN18CLegacyCineMonsterC4EOS_ */

	void CLegacyCineMonster(class CLegacyCineMonster *, const class CLegacyCineMonster  &); /* linkage=_ZN18CLegacyCineMonsterC4ERKS_ */

	void CLegacyCineMonster(class CLegacyCineMonster *); /* linkage=_ZN18CLegacyCineMonsterC4Ev */

	void CineSpawn(class CLegacyCineMonster *, char *); /* linkage=_ZN18CLegacyCineMonster9CineSpawnEPc */

	virtual void Use(class CLegacyCineMonster *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN18CLegacyCineMonster3UseEP11CBaseEntityS1_8USE_TYPEf */

	void CineThink(class CLegacyCineMonster *); /* linkage=_ZN18CLegacyCineMonster9CineThinkEv */

	void Pain(class CLegacyCineMonster *); /* linkage=_ZN18CLegacyCineMonster4PainEv */

	void Die(class CLegacyCineMonster *); /* linkage=_ZN18CLegacyCineMonster3DieEv */

	virtual void ~CLegacyCineMonster(class CLegacyCineMonster *, int); /* linkage=_ZN18CLegacyCineMonsterD4Ev */

	/* vtable has 1 entries: {
	   [45] = Use(_ZN18CLegacyCineMonster3UseEP11CBaseEntityS1_8USE_TYPEf), 
	} */
	/* size: 1724, cachelines: 27, members: 1 */
	/* padding: 1724 */
	/* last cacheline: 60 bytes */
};
class CCine3Barney : public CLegacyCineMonster {
public:

	/* class CLegacyCineMonster  <ancestor>; */      /*     0  1724 */

	/* XXX last struct has 1724 bytes of padding */
	void CCine3Barney(class CCine3Barney *, class CCine3Barney &); /* linkage=_ZN12CCine3BarneyC4EOS_ */

	void CCine3Barney(class CCine3Barney *, const class CCine3Barney  &); /* linkage=_ZN12CCine3BarneyC4ERKS_ */

	void CCine3Barney(class CCine3Barney *); /* linkage=_ZN12CCine3BarneyC4Ev */

	virtual void Spawn(class CCine3Barney *); /* linkage=_ZN12CCine3Barney5SpawnEv */

	virtual void ~CCine3Barney(class CCine3Barney *, int); /* linkage=_ZN12CCine3BarneyD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN12CCine3Barney5SpawnEv), 
	} */
	/* size: 1724, cachelines: 27, members: 1 */
	/* paddings: 1, sum paddings: 1724 */
	/* last cacheline: 60 bytes */
};
class CCine3Scientist : public CLegacyCineMonster {
public:

	/* class CLegacyCineMonster  <ancestor>; */      /*     0  1724 */

	/* XXX last struct has 1724 bytes of padding */
	void CCine3Scientist(class CCine3Scientist *, class CCine3Scientist &); /* linkage=_ZN15CCine3ScientistC4EOS_ */

	void CCine3Scientist(class CCine3Scientist *, const class CCine3Scientist  &); /* linkage=_ZN15CCine3ScientistC4ERKS_ */

	void CCine3Scientist(class CCine3Scientist *); /* linkage=_ZN15CCine3ScientistC4Ev */

	virtual void Spawn(class CCine3Scientist *); /* linkage=_ZN15CCine3Scientist5SpawnEv */

	virtual void ~CCine3Scientist(class CCine3Scientist *, int); /* linkage=_ZN15CCine3ScientistD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN15CCine3Scientist5SpawnEv), 
	} */
	/* size: 1724, cachelines: 27, members: 1 */
	/* paddings: 1, sum paddings: 1724 */
	/* last cacheline: 60 bytes */
};
class CCine2Slave : public CLegacyCineMonster {
public:

	/* class CLegacyCineMonster  <ancestor>; */      /*     0  1724 */

	/* XXX last struct has 1724 bytes of padding */
	void CCine2Slave(class CCine2Slave *, class CCine2Slave &); /* linkage=_ZN11CCine2SlaveC4EOS_ */

	void CCine2Slave(class CCine2Slave *, const class CCine2Slave  &); /* linkage=_ZN11CCine2SlaveC4ERKS_ */

	void CCine2Slave(class CCine2Slave *); /* linkage=_ZN11CCine2SlaveC4Ev */

	virtual void Spawn(class CCine2Slave *); /* linkage=_ZN11CCine2Slave5SpawnEv */

	virtual void ~CCine2Slave(class CCine2Slave *, int); /* linkage=_ZN11CCine2SlaveD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN11CCine2Slave5SpawnEv), 
	} */
	/* size: 1724, cachelines: 27, members: 1 */
	/* paddings: 1, sum paddings: 1724 */
	/* last cacheline: 60 bytes */
};
class CCine2HeavyWeapons : public CLegacyCineMonster {
public:

	/* class CLegacyCineMonster  <ancestor>; */      /*     0  1724 */

	/* XXX last struct has 1724 bytes of padding */
	void CCine2HeavyWeapons(class CCine2HeavyWeapons *, class CCine2HeavyWeapons &); /* linkage=_ZN18CCine2HeavyWeaponsC4EOS_ */

	void CCine2HeavyWeapons(class CCine2HeavyWeapons *, const class CCine2HeavyWeapons  &); /* linkage=_ZN18CCine2HeavyWeaponsC4ERKS_ */

	void CCine2HeavyWeapons(class CCine2HeavyWeapons *); /* linkage=_ZN18CCine2HeavyWeaponsC4Ev */

	virtual void Spawn(class CCine2HeavyWeapons *); /* linkage=_ZN18CCine2HeavyWeapons5SpawnEv */

	virtual void ~CCine2HeavyWeapons(class CCine2HeavyWeapons *, int); /* linkage=_ZN18CCine2HeavyWeaponsD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN18CCine2HeavyWeapons5SpawnEv), 
	} */
	/* size: 1724, cachelines: 27, members: 1 */
	/* paddings: 1, sum paddings: 1724 */
	/* last cacheline: 60 bytes */
};
class CCineBarney : public CLegacyCineMonster {
public:

	/* class CLegacyCineMonster  <ancestor>; */      /*     0  1724 */

	/* XXX last struct has 1724 bytes of padding */
	void CCineBarney(class CCineBarney *, class CCineBarney &); /* linkage=_ZN11CCineBarneyC4EOS_ */

	void CCineBarney(class CCineBarney *, const class CCineBarney  &); /* linkage=_ZN11CCineBarneyC4ERKS_ */

	void CCineBarney(class CCineBarney *); /* linkage=_ZN11CCineBarneyC4Ev */

	virtual void Spawn(class CCineBarney *); /* linkage=_ZN11CCineBarney5SpawnEv */

	virtual void ~CCineBarney(class CCineBarney *, int); /* linkage=_ZN11CCineBarneyD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN11CCineBarney5SpawnEv), 
	} */
	/* size: 1724, cachelines: 27, members: 1 */
	/* paddings: 1, sum paddings: 1724 */
	/* last cacheline: 60 bytes */
};
class CCinePanther : public CLegacyCineMonster {
public:

	/* class CLegacyCineMonster  <ancestor>; */      /*     0  1724 */

	/* XXX last struct has 1724 bytes of padding */
	void CCinePanther(class CCinePanther *, class CCinePanther &); /* linkage=_ZN12CCinePantherC4EOS_ */

	void CCinePanther(class CCinePanther *, const class CCinePanther  &); /* linkage=_ZN12CCinePantherC4ERKS_ */

	void CCinePanther(class CCinePanther *); /* linkage=_ZN12CCinePantherC4Ev */

	virtual void Spawn(class CCinePanther *); /* linkage=_ZN12CCinePanther5SpawnEv */

	virtual void ~CCinePanther(class CCinePanther *, int); /* linkage=_ZN12CCinePantherD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN12CCinePanther5SpawnEv), 
	} */
	/* size: 1724, cachelines: 27, members: 1 */
	/* paddings: 1, sum paddings: 1724 */
	/* last cacheline: 60 bytes */
};
class CCine2Scientist : public CLegacyCineMonster {
public:

	/* class CLegacyCineMonster  <ancestor>; */      /*     0  1724 */

	/* XXX last struct has 1724 bytes of padding */
	void CCine2Scientist(class CCine2Scientist *, class CCine2Scientist &); /* linkage=_ZN15CCine2ScientistC4EOS_ */

	void CCine2Scientist(class CCine2Scientist *, const class CCine2Scientist  &); /* linkage=_ZN15CCine2ScientistC4ERKS_ */

	void CCine2Scientist(class CCine2Scientist *); /* linkage=_ZN15CCine2ScientistC4Ev */

	virtual void Spawn(class CCine2Scientist *); /* linkage=_ZN15CCine2Scientist5SpawnEv */

	virtual void ~CCine2Scientist(class CCine2Scientist *, int); /* linkage=_ZN15CCine2ScientistD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN15CCine2Scientist5SpawnEv), 
	} */
	/* size: 1724, cachelines: 27, members: 1 */
	/* paddings: 1, sum paddings: 1724 */
	/* last cacheline: 60 bytes */
};
class CCineScientist : public CLegacyCineMonster {
public:

	/* class CLegacyCineMonster  <ancestor>; */      /*     0  1724 */

	/* XXX last struct has 1724 bytes of padding */
	void CCineScientist(class CCineScientist *, class CCineScientist &); /* linkage=_ZN14CCineScientistC4EOS_ */

	void CCineScientist(class CCineScientist *, const class CCineScientist  &); /* linkage=_ZN14CCineScientistC4ERKS_ */

	void CCineScientist(class CCineScientist *); /* linkage=_ZN14CCineScientistC4Ev */

	virtual void Spawn(class CCineScientist *); /* linkage=_ZN14CCineScientist5SpawnEv */

	virtual void ~CCineScientist(class CCineScientist *, int); /* linkage=_ZN14CCineScientistD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN14CCineScientist5SpawnEv), 
	} */
	/* size: 1724, cachelines: 27, members: 1 */
	/* paddings: 1, sum paddings: 1724 */
	/* last cacheline: 60 bytes */
};
class CWreckage : public CBaseMonster {

	/* XXX 1724 bytes hole, try to pack */
public:


	/* class CBaseMonster        <ancestor>; */      /*     0     0 */
private:

	static TYPEDESCRIPTION            m_SaveData[1]; /*     0     0 */
	/* --- cacheline 26 boundary (1664 bytes) was 60 bytes ago --- */
	int                        m_flStartTime;        /*  1724     4 */
	void CWreckage(class CWreckage *, class CWreckage &); /* linkage=_ZN9CWreckageC4EOS_ */

	void CWreckage(class CWreckage *, const class CWreckage  &); /* linkage=_ZN9CWreckageC4ERKS_ */

	void CWreckage(class CWreckage *); /* linkage=_ZN9CWreckageC4Ev */

	virtual int Save(class CWreckage *, class CSave &); /* linkage=_ZN9CWreckage4SaveER5CSave */

	virtual int Restore(class CWreckage *, class CRestore &); /* linkage=_ZN9CWreckage7RestoreER8CRestore */

	virtual void Spawn(class CWreckage *); /* linkage=_ZN9CWreckage5SpawnEv */

	virtual void Precache(class CWreckage *); /* linkage=_ZN9CWreckage8PrecacheEv */

	virtual void Think(class CWreckage *); /* linkage=_ZN9CWreckage5ThinkEv */

	virtual void ~CWreckage(class CWreckage *, int); /* linkage=_ZN9CWreckageD4Ev */

	/* vtable has 5 entries: {
	   [5] = Save(_ZN9CWreckage4SaveER5CSave), 
	   [6] = Restore(_ZN9CWreckage7RestoreER8CRestore), 
	   [2] = Spawn(_ZN9CWreckage5SpawnEv), 
	   [3] = Precache(_ZN9CWreckage8PrecacheEv), 
	   [43] = Think(_ZN9CWreckage5ThinkEv), 
	} */
	/* size: 1728, cachelines: 27, members: 2, static members: 1 */
	/* sum members: 4, holes: 1, sum holes: 1724 */
};
class CWeaponCycler : public CBasePlayerWeapon {

	/* XXX 1268 bytes hole, try to pack */
public:


	/* class CBasePlayerWeapon   <ancestor>; */      /*     0     0 */
	/* --- cacheline 19 boundary (1216 bytes) was 52 bytes ago --- */
	int                        m_iszModel;           /*  1268     4 */
	int                        m_iModel;             /*  1272     4 */
	void CWeaponCycler(class CWeaponCycler *, class CWeaponCycler &); /* linkage=_ZN13CWeaponCyclerC4EOS_ */

	void CWeaponCycler(class CWeaponCycler *, const class CWeaponCycler  &); /* linkage=_ZN13CWeaponCyclerC4ERKS_ */

	void CWeaponCycler(class CWeaponCycler *); /* linkage=_ZN13CWeaponCyclerC4Ev */

	virtual void Spawn(class CWeaponCycler *); /* linkage=_ZN13CWeaponCycler5SpawnEv */

	virtual int iItemSlot(class CWeaponCycler *); /* linkage=_ZN13CWeaponCycler9iItemSlotEv */

	virtual int GetItemInfo(class CWeaponCycler *, ItemInfo *); /* linkage=_ZN13CWeaponCycler11GetItemInfoEP8ItemInfo */

	virtual void PrimaryAttack(class CWeaponCycler *); /* linkage=_ZN13CWeaponCycler13PrimaryAttackEv */

	virtual void SecondaryAttack(class CWeaponCycler *); /* linkage=_ZN13CWeaponCycler15SecondaryAttackEv */

	virtual BOOL Deploy(class CWeaponCycler *); /* linkage=_ZN13CWeaponCycler6DeployEv */

	void Holster(class CWeaponCycler *); /* linkage=_ZN13CWeaponCycler7HolsterEv */

	virtual void ~CWeaponCycler(class CWeaponCycler *, int); /* linkage=_ZN13CWeaponCyclerD4Ev */

	/* vtable has 6 entries: {
	   [2] = Spawn(_ZN13CWeaponCycler5SpawnEv), 
	   [68] = iItemSlot(_ZN13CWeaponCycler9iItemSlotEv), 
	   [69] = GetItemInfo(_ZN13CWeaponCycler11GetItemInfoEP8ItemInfo), 
	   [91] = PrimaryAttack(_ZN13CWeaponCycler13PrimaryAttackEv), 
	   [92] = SecondaryAttack(_ZN13CWeaponCycler15SecondaryAttackEv), 
	   [71] = Deploy(_ZN13CWeaponCycler6DeployEv), 
	} */
	/* size: 1276, cachelines: 20, members: 3 */
	/* sum members: 8, holes: 1, sum holes: 1268 */
	/* last cacheline: 60 bytes */
};
class CCyclerSprite : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[3]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	int                        m_animate;            /*  1140     4 */
	float                      m_lastTime;           /*  1144     4 */
	float                      m_maxFrame;           /*  1148     4 */
	void CCyclerSprite(class CCyclerSprite *, class CCyclerSprite &); /* linkage=_ZN13CCyclerSpriteC4EOS_ */

	void CCyclerSprite(class CCyclerSprite *, const class CCyclerSprite  &); /* linkage=_ZN13CCyclerSpriteC4ERKS_ */

	void CCyclerSprite(class CCyclerSprite *); /* linkage=_ZN13CCyclerSpriteC4Ev */

	virtual void Spawn(class CCyclerSprite *); /* linkage=_ZN13CCyclerSprite5SpawnEv */

	virtual void Think(class CCyclerSprite *); /* linkage=_ZN13CCyclerSprite5ThinkEv */

	virtual void Use(class CCyclerSprite *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN13CCyclerSprite3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual int ObjectCaps(class CCyclerSprite *); /* linkage=_ZN13CCyclerSprite10ObjectCapsEv */

	virtual int TakeDamage(class CCyclerSprite *, entvars_t *, entvars_t *, float, int); /* linkage=_ZN13CCyclerSprite10TakeDamageEP9entvars_sS1_fi */

	void Animate(class CCyclerSprite *, float); /* linkage=_ZN13CCyclerSprite7AnimateEf */

	virtual int Save(class CCyclerSprite *, class CSave &); /* linkage=_ZN13CCyclerSprite4SaveER5CSave */

	virtual int Restore(class CCyclerSprite *, class CRestore &); /* linkage=_ZN13CCyclerSprite7RestoreER8CRestore */

	int ShouldAnimate(class CCyclerSprite *); /* linkage=_ZN13CCyclerSprite13ShouldAnimateEv */

	virtual void ~CCyclerSprite(class CCyclerSprite *, int); /* linkage=_ZN13CCyclerSpriteD4Ev */

	/* vtable has 7 entries: {
	   [2] = Spawn(_ZN13CCyclerSprite5SpawnEv), 
	   [43] = Think(_ZN13CCyclerSprite5ThinkEv), 
	   [45] = Use(_ZN13CCyclerSprite3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [7] = ObjectCaps(_ZN13CCyclerSprite10ObjectCapsEv), 
	   [13] = TakeDamage(_ZN13CCyclerSprite10TakeDamageEP9entvars_sS1_fi), 
	   [5] = Save(_ZN13CCyclerSprite4SaveER5CSave), 
	   [6] = Restore(_ZN13CCyclerSprite7RestoreER8CRestore), 
	} */
	/* size: 1152, cachelines: 18, members: 4, static members: 1 */
	/* sum members: 12, holes: 1, sum holes: 1140 */
};
class CCycler : public CBaseMonster {

	/* XXX 1724 bytes hole, try to pack */
public:


	/* class CBaseMonster        <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[1]; /*     0     0 */
	/* --- cacheline 26 boundary (1664 bytes) was 60 bytes ago --- */
	int                        m_animate;            /*  1724     4 */
	void CCycler(class CCycler *, class CCycler &); /* linkage=_ZN7CCyclerC4EOS_ */

	void CCycler(class CCycler *, const class CCycler  &); /* linkage=_ZN7CCyclerC4ERKS_ */

	void CCycler(class CCycler *); /* linkage=_ZN7CCyclerC4Ev */

	void GenericCyclerSpawn(class CCycler *, char *, class Vector, class Vector); /* linkage=_ZN7CCycler18GenericCyclerSpawnEPc6VectorS1_ */

	virtual int ObjectCaps(class CCycler *); /* linkage=_ZN7CCycler10ObjectCapsEv */

	virtual int TakeDamage(class CCycler *, entvars_t *, entvars_t *, float, int); /* linkage=_ZN7CCycler10TakeDamageEP9entvars_sS1_fi */

	virtual void Spawn(class CCycler *); /* linkage=_ZN7CCycler5SpawnEv */

	virtual void Think(class CCycler *); /* linkage=_ZN7CCycler5ThinkEv */

	virtual void Use(class CCycler *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN7CCycler3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual BOOL IsAlive(class CCycler *); /* linkage=_ZN7CCycler7IsAliveEv */

	virtual int Save(class CCycler *, class CSave &); /* linkage=_ZN7CCycler4SaveER5CSave */

	virtual int Restore(class CCycler *, class CRestore &); /* linkage=_ZN7CCycler7RestoreER8CRestore */

	virtual void ~CCycler(class CCycler *, int); /* linkage=_ZN7CCyclerD4Ev */

	/* vtable has 8 entries: {
	   [7] = ObjectCaps(_ZN7CCycler10ObjectCapsEv), 
	   [13] = TakeDamage(_ZN7CCycler10TakeDamageEP9entvars_sS1_fi), 
	   [2] = Spawn(_ZN7CCycler5SpawnEv), 
	   [43] = Think(_ZN7CCycler5ThinkEv), 
	   [45] = Use(_ZN7CCycler3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [34] = IsAlive(_ZN7CCycler7IsAliveEv), 
	   [5] = Save(_ZN7CCycler4SaveER5CSave), 
	   [6] = Restore(_ZN7CCycler7RestoreER8CRestore), 
	} */
	/* size: 1728, cachelines: 27, members: 2, static members: 1 */
	/* sum members: 4, holes: 1, sum holes: 1724 */
};
class CCyclerProbe : public CCycler {
public:

	/* class CCycler             <ancestor>; */      /*     0  1728 */

	/* XXX last struct has 1 hole */
	void CCyclerProbe(class CCyclerProbe *, class CCyclerProbe &); /* linkage=_ZN12CCyclerProbeC4EOS_ */

	void CCyclerProbe(class CCyclerProbe *, const class CCyclerProbe  &); /* linkage=_ZN12CCyclerProbeC4ERKS_ */

	void CCyclerProbe(class CCyclerProbe *); /* linkage=_ZN12CCyclerProbeC4Ev */

	virtual void Spawn(class CCyclerProbe *); /* linkage=_ZN12CCyclerProbe5SpawnEv */

	virtual void ~CCyclerProbe(class CCyclerProbe *, int); /* linkage=_ZN12CCyclerProbeD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN12CCyclerProbe5SpawnEv), 
	} */
	/* size: 1728, cachelines: 27, members: 1 */
	/* member types with holes: 1, total: 1 */
};
class CGenericCycler : public CCycler {
public:

	/* class CCycler             <ancestor>; */      /*     0  1728 */

	/* XXX last struct has 1 hole */
	void CGenericCycler(class CGenericCycler *, class CGenericCycler &); /* linkage=_ZN14CGenericCyclerC4EOS_ */

	void CGenericCycler(class CGenericCycler *, const class CGenericCycler  &); /* linkage=_ZN14CGenericCyclerC4ERKS_ */

	void CGenericCycler(class CGenericCycler *); /* linkage=_ZN14CGenericCyclerC4Ev */

	virtual void Spawn(class CGenericCycler *); /* linkage=_ZN14CGenericCycler5SpawnEv */

	virtual void ~CGenericCycler(class CGenericCycler *, int); /* linkage=_ZN14CGenericCyclerD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN14CGenericCycler5SpawnEv), 
	} */
	/* size: 1728, cachelines: 27, members: 1 */
	/* member types with holes: 1, total: 1 */
};
class CHandGrenade : public CBasePlayerWeapon {

	/* XXX 1268 bytes hole, try to pack */
public:


	/* class CBasePlayerWeapon   <ancestor>; */      /*     0     0 */
	/* --- cacheline 19 boundary (1216 bytes) was 52 bytes ago --- */
	float                      m_flStartThrow;       /*  1268     4 */
	float                      m_flReleaseThrow;     /*  1272     4 */
	void CHandGrenade(class CHandGrenade *, class CHandGrenade &); /* linkage=_ZN12CHandGrenadeC4EOS_ */

	void CHandGrenade(class CHandGrenade *, const class CHandGrenade  &); /* linkage=_ZN12CHandGrenadeC4ERKS_ */

	void CHandGrenade(class CHandGrenade *); /* linkage=_ZN12CHandGrenadeC4Ev */

	virtual void Spawn(class CHandGrenade *); /* linkage=_ZN12CHandGrenade5SpawnEv */

	virtual void Precache(class CHandGrenade *); /* linkage=_ZN12CHandGrenade8PrecacheEv */

	virtual int iItemSlot(class CHandGrenade *); /* linkage=_ZN12CHandGrenade9iItemSlotEv */

	virtual int GetItemInfo(class CHandGrenade *, ItemInfo *); /* linkage=_ZN12CHandGrenade11GetItemInfoEP8ItemInfo */

	virtual void PrimaryAttack(class CHandGrenade *); /* linkage=_ZN12CHandGrenade13PrimaryAttackEv */

	virtual BOOL Deploy(class CHandGrenade *); /* linkage=_ZN12CHandGrenade6DeployEv */

	virtual BOOL CanHolster(class CHandGrenade *); /* linkage=_ZN12CHandGrenade10CanHolsterEv */

	void Holster(class CHandGrenade *); /* linkage=_ZN12CHandGrenade7HolsterEv */

	virtual void WeaponIdle(class CHandGrenade *); /* linkage=_ZN12CHandGrenade10WeaponIdleEv */

	virtual void ~CHandGrenade(class CHandGrenade *, int); /* linkage=_ZN12CHandGrenadeD4Ev */

	/* vtable has 8 entries: {
	   [2] = Spawn(_ZN12CHandGrenade5SpawnEv), 
	   [3] = Precache(_ZN12CHandGrenade8PrecacheEv), 
	   [68] = iItemSlot(_ZN12CHandGrenade9iItemSlotEv), 
	   [69] = GetItemInfo(_ZN12CHandGrenade11GetItemInfoEP8ItemInfo), 
	   [91] = PrimaryAttack(_ZN12CHandGrenade13PrimaryAttackEv), 
	   [71] = Deploy(_ZN12CHandGrenade6DeployEv), 
	   [72] = CanHolster(_ZN12CHandGrenade10CanHolsterEv), 
	   [94] = WeaponIdle(_ZN12CHandGrenade10WeaponIdleEv), 
	} */
	/* size: 1276, cachelines: 20, members: 3 */
	/* sum members: 8, holes: 1, sum holes: 1268 */
	/* last cacheline: 60 bytes */
};
class CWallHealth : public CBaseToggle {

	/* XXX 1300 bytes hole, try to pack */
public:


	/* class CBaseToggle         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[5]; /*     0     0 */
	/* --- cacheline 20 boundary (1280 bytes) was 20 bytes ago --- */
	float                      m_flNextCharge;       /*  1300     4 */
	int                        m_iReactivate;        /*  1304     4 */
	int                        m_iJuice;             /*  1308     4 */
	int                        m_iOn;                /*  1312     4 */
	float                      m_flSoundTime;        /*  1316     4 */
	void CWallHealth(class CWallHealth *, class CWallHealth &); /* linkage=_ZN11CWallHealthC4EOS_ */

	void CWallHealth(class CWallHealth *, const class CWallHealth  &); /* linkage=_ZN11CWallHealthC4ERKS_ */

	void CWallHealth(class CWallHealth *); /* linkage=_ZN11CWallHealthC4Ev */

	virtual void Spawn(class CWallHealth *); /* linkage=_ZN11CWallHealth5SpawnEv */

	virtual void Precache(class CWallHealth *); /* linkage=_ZN11CWallHealth8PrecacheEv */

	void Off(class CWallHealth *); /* linkage=_ZN11CWallHealth3OffEv */

	void Recharge(class CWallHealth *); /* linkage=_ZN11CWallHealth8RechargeEv */

	virtual void KeyValue(class CWallHealth *, KeyValueData *); /* linkage=_ZN11CWallHealth8KeyValueEP14KeyValueData_s */

	virtual void Use(class CWallHealth *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN11CWallHealth3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual int ObjectCaps(class CWallHealth *); /* linkage=_ZN11CWallHealth10ObjectCapsEv */

	virtual int Save(class CWallHealth *, class CSave &); /* linkage=_ZN11CWallHealth4SaveER5CSave */

	virtual int Restore(class CWallHealth *, class CRestore &); /* linkage=_ZN11CWallHealth7RestoreER8CRestore */

	virtual void ~CWallHealth(class CWallHealth *, int); /* linkage=_ZN11CWallHealthD4Ev */

	/* vtable has 7 entries: {
	   [2] = Spawn(_ZN11CWallHealth5SpawnEv), 
	   [3] = Precache(_ZN11CWallHealth8PrecacheEv), 
	   [4] = KeyValue(_ZN11CWallHealth8KeyValueEP14KeyValueData_s), 
	   [45] = Use(_ZN11CWallHealth3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [7] = ObjectCaps(_ZN11CWallHealth10ObjectCapsEv), 
	   [5] = Save(_ZN11CWallHealth4SaveER5CSave), 
	   [6] = Restore(_ZN11CWallHealth7RestoreER8CRestore), 
	} */
	/* size: 1320, cachelines: 21, members: 6, static members: 1 */
	/* sum members: 20, holes: 1, sum holes: 1300 */
	/* last cacheline: 40 bytes */
};
class CHealthKit : public CItem {
public:

	/* class CItem               <ancestor>; */      /*     0     0 */
	void CHealthKit(class CHealthKit *, class CHealthKit &); /* linkage=_ZN10CHealthKitC4EOS_ */

	void CHealthKit(class CHealthKit *, const class CHealthKit  &); /* linkage=_ZN10CHealthKitC4ERKS_ */

	void CHealthKit(class CHealthKit *); /* linkage=_ZN10CHealthKitC4Ev */

private:

	virtual void Spawn(class CHealthKit *); /* linkage=_ZN10CHealthKit5SpawnEv */

	virtual void Precache(class CHealthKit *); /* linkage=_ZN10CHealthKit8PrecacheEv */

	virtual BOOL MyTouch(class CHealthKit *, class CBasePlayer *); /* linkage=_ZN10CHealthKit7MyTouchEP11CBasePlayer */

	virtual void ~CHealthKit(class CHealthKit *, int); /* linkage=_ZN10CHealthKitD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN10CHealthKit5SpawnEv), 
	   [3] = Precache(_ZN10CHealthKit8PrecacheEv), 
	   [65] = MyTouch(_ZN10CHealthKit7MyTouchEP11CBasePlayer), 
	} */
	/* size: 1144, cachelines: 18, members: 1 */
	/* padding: 1144 */
	/* last cacheline: 56 bytes */
};
class CItemLongJump : public CItem {
public:

	/* class CItem               <ancestor>; */      /*     0  1144 */

	/* XXX last struct has 1 hole */
	void CItemLongJump(class CItemLongJump *, class CItemLongJump &); /* linkage=_ZN13CItemLongJumpC4EOS_ */

	void CItemLongJump(class CItemLongJump *, const class CItemLongJump  &); /* linkage=_ZN13CItemLongJumpC4ERKS_ */

	void CItemLongJump(class CItemLongJump *); /* linkage=_ZN13CItemLongJumpC4Ev */

private:

	virtual void Spawn(class CItemLongJump *); /* linkage=_ZN13CItemLongJump5SpawnEv */

	virtual void Precache(class CItemLongJump *); /* linkage=_ZN13CItemLongJump8PrecacheEv */

	virtual BOOL MyTouch(class CItemLongJump *, class CBasePlayer *); /* linkage=_ZN13CItemLongJump7MyTouchEP11CBasePlayer */

	virtual void ~CItemLongJump(class CItemLongJump *, int); /* linkage=_ZN13CItemLongJumpD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN13CItemLongJump5SpawnEv), 
	   [3] = Precache(_ZN13CItemLongJump8PrecacheEv), 
	   [65] = MyTouch(_ZN13CItemLongJump7MyTouchEP11CBasePlayer), 
	} */
	/* size: 1144, cachelines: 18, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 56 bytes */
};
class CItem : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	float                      m_flRespawnTime;      /*  1140     4 */
	void CItem(class CItem *, class CItem &); /* linkage=_ZN5CItemC4EOS_ */

	void CItem(class CItem *, const class CItem  &); /* linkage=_ZN5CItemC4ERKS_ */

	void CItem(class CItem *); /* linkage=_ZN5CItemC4Ev */

	virtual void Spawn(class CItem *); /* linkage=_ZN5CItem5SpawnEv */

	virtual class CBaseEntity * Respawn(class CItem *); /* linkage=_ZN5CItem7RespawnEv */

	virtual void KeyValue(class CItem *, KeyValueData *); /* linkage=_ZN5CItem8KeyValueEP14KeyValueData_s */

	void ItemTouch(class CItem *, class CBaseEntity *); /* linkage=_ZN5CItem9ItemTouchEP11CBaseEntity */

	void Materialize(class CItem *); /* linkage=_ZN5CItem11MaterializeEv */

	virtual BOOL MyTouch(class CItem *, class CBasePlayer *); /* linkage=_ZN5CItem7MyTouchEP11CBasePlayer */

	virtual void TeamFortress_EMPRemove(class CItem *); /* linkage=_ZN5CItem22TeamFortress_EMPRemoveEv */

	virtual void ~CItem(class CItem *, int); /* linkage=_ZN5CItemD4Ev */

	/* vtable has 5 entries: {
	   [2] = Spawn(_ZN5CItem5SpawnEv), 
	   [47] = Respawn(_ZN5CItem7RespawnEv), 
	   [4] = KeyValue(_ZN5CItem8KeyValueEP14KeyValueData_s), 
	   [65] = MyTouch(_ZN5CItem7MyTouchEP11CBasePlayer), 
	   [62] = TeamFortress_EMPRemove(_ZN5CItem22TeamFortress_EMPRemoveEv), 
	} */
	/* size: 1144, cachelines: 18, members: 2 */
	/* sum members: 4, holes: 1, sum holes: 1140 */
	/* last cacheline: 56 bytes */
};
class CItemSecurity : public CItem {
public:

	/* class CItem               <ancestor>; */      /*     0  1144 */

	/* XXX last struct has 1 hole */
	void CItemSecurity(class CItemSecurity *, class CItemSecurity &); /* linkage=_ZN13CItemSecurityC4EOS_ */

	void CItemSecurity(class CItemSecurity *, const class CItemSecurity  &); /* linkage=_ZN13CItemSecurityC4ERKS_ */

	void CItemSecurity(class CItemSecurity *); /* linkage=_ZN13CItemSecurityC4Ev */

private:

	virtual void Spawn(class CItemSecurity *); /* linkage=_ZN13CItemSecurity5SpawnEv */

	virtual void Precache(class CItemSecurity *); /* linkage=_ZN13CItemSecurity8PrecacheEv */

	virtual BOOL MyTouch(class CItemSecurity *, class CBasePlayer *); /* linkage=_ZN13CItemSecurity7MyTouchEP11CBasePlayer */

	virtual void ~CItemSecurity(class CItemSecurity *, int); /* linkage=_ZN13CItemSecurityD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN13CItemSecurity5SpawnEv), 
	   [3] = Precache(_ZN13CItemSecurity8PrecacheEv), 
	   [65] = MyTouch(_ZN13CItemSecurity7MyTouchEP11CBasePlayer), 
	} */
	/* size: 1144, cachelines: 18, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 56 bytes */
};
class CItemAntidote : public CItem {
public:

	/* class CItem               <ancestor>; */      /*     0  1144 */

	/* XXX last struct has 1 hole */
	void CItemAntidote(class CItemAntidote *, class CItemAntidote &); /* linkage=_ZN13CItemAntidoteC4EOS_ */

	void CItemAntidote(class CItemAntidote *, const class CItemAntidote  &); /* linkage=_ZN13CItemAntidoteC4ERKS_ */

	void CItemAntidote(class CItemAntidote *); /* linkage=_ZN13CItemAntidoteC4Ev */

private:

	virtual void Spawn(class CItemAntidote *); /* linkage=_ZN13CItemAntidote5SpawnEv */

	virtual void Precache(class CItemAntidote *); /* linkage=_ZN13CItemAntidote8PrecacheEv */

	virtual BOOL MyTouch(class CItemAntidote *, class CBasePlayer *); /* linkage=_ZN13CItemAntidote7MyTouchEP11CBasePlayer */

	virtual void ~CItemAntidote(class CItemAntidote *, int); /* linkage=_ZN13CItemAntidoteD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN13CItemAntidote5SpawnEv), 
	   [3] = Precache(_ZN13CItemAntidote8PrecacheEv), 
	   [65] = MyTouch(_ZN13CItemAntidote7MyTouchEP11CBasePlayer), 
	} */
	/* size: 1144, cachelines: 18, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 56 bytes */
};
class CItemBattery : public CItem {
public:

	/* class CItem               <ancestor>; */      /*     0  1144 */

	/* XXX last struct has 1 hole */
	void CItemBattery(class CItemBattery *, class CItemBattery &); /* linkage=_ZN12CItemBatteryC4EOS_ */

	void CItemBattery(class CItemBattery *, const class CItemBattery  &); /* linkage=_ZN12CItemBatteryC4ERKS_ */

	void CItemBattery(class CItemBattery *); /* linkage=_ZN12CItemBatteryC4Ev */

private:

	virtual void Spawn(class CItemBattery *); /* linkage=_ZN12CItemBattery5SpawnEv */

	virtual void Precache(class CItemBattery *); /* linkage=_ZN12CItemBattery8PrecacheEv */

	virtual BOOL MyTouch(class CItemBattery *, class CBasePlayer *); /* linkage=_ZN12CItemBattery7MyTouchEP11CBasePlayer */

	virtual void ~CItemBattery(class CItemBattery *, int); /* linkage=_ZN12CItemBatteryD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN12CItemBattery5SpawnEv), 
	   [3] = Precache(_ZN12CItemBattery8PrecacheEv), 
	   [65] = MyTouch(_ZN12CItemBattery7MyTouchEP11CBasePlayer), 
	} */
	/* size: 1144, cachelines: 18, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 56 bytes */
};
class CItemSuit : public CItem {
public:

	/* class CItem               <ancestor>; */      /*     0  1144 */

	/* XXX last struct has 1 hole */
	void CItemSuit(class CItemSuit *, class CItemSuit &); /* linkage=_ZN9CItemSuitC4EOS_ */

	void CItemSuit(class CItemSuit *, const class CItemSuit  &); /* linkage=_ZN9CItemSuitC4ERKS_ */

	void CItemSuit(class CItemSuit *); /* linkage=_ZN9CItemSuitC4Ev */

private:

	virtual void Spawn(class CItemSuit *); /* linkage=_ZN9CItemSuit5SpawnEv */

	virtual void Precache(class CItemSuit *); /* linkage=_ZN9CItemSuit8PrecacheEv */

	virtual BOOL MyTouch(class CItemSuit *, class CBasePlayer *); /* linkage=_ZN9CItemSuit7MyTouchEP11CBasePlayer */

	virtual void ~CItemSuit(class CItemSuit *, int); /* linkage=_ZN9CItemSuitD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN9CItemSuit5SpawnEv), 
	   [3] = Precache(_ZN9CItemSuit8PrecacheEv), 
	   [65] = MyTouch(_ZN9CItemSuit7MyTouchEP11CBasePlayer), 
	} */
	/* size: 1144, cachelines: 18, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 56 bytes */
};
class CWorldItem : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	int                        m_iType;              /*  1140     4 */
	void CWorldItem(class CWorldItem *, class CWorldItem &); /* linkage=_ZN10CWorldItemC4EOS_ */

	void CWorldItem(class CWorldItem *, const class CWorldItem  &); /* linkage=_ZN10CWorldItemC4ERKS_ */

	void CWorldItem(class CWorldItem *); /* linkage=_ZN10CWorldItemC4Ev */

	virtual void KeyValue(class CWorldItem *, KeyValueData *); /* linkage=_ZN10CWorldItem8KeyValueEP14KeyValueData_s */

	virtual void Spawn(class CWorldItem *); /* linkage=_ZN10CWorldItem5SpawnEv */

	virtual void ~CWorldItem(class CWorldItem *, int); /* linkage=_ZN10CWorldItemD4Ev */

	/* vtable has 2 entries: {
	   [4] = KeyValue(_ZN10CWorldItem8KeyValueEP14KeyValueData_s), 
	   [2] = Spawn(_ZN10CWorldItem5SpawnEv), 
	} */
	/* size: 1144, cachelines: 18, members: 2 */
	/* sum members: 4, holes: 1, sum holes: 1140 */
	/* last cacheline: 56 bytes */
};
class CEnvLight : public CLight {
public:

	/* class CLight              <ancestor>; */      /*     0  1148 */

	/* XXX last struct has 1 hole */
	void CEnvLight(class CEnvLight *, class CEnvLight &); /* linkage=_ZN9CEnvLightC4EOS_ */

	void CEnvLight(class CEnvLight *, const class CEnvLight  &); /* linkage=_ZN9CEnvLightC4ERKS_ */

	void CEnvLight(class CEnvLight *); /* linkage=_ZN9CEnvLightC4Ev */

	virtual void KeyValue(class CEnvLight *, KeyValueData *); /* linkage=_ZN9CEnvLight8KeyValueEP14KeyValueData_s */

	virtual void Spawn(class CEnvLight *); /* linkage=_ZN9CEnvLight5SpawnEv */

	virtual void ~CEnvLight(class CEnvLight *, int); /* linkage=_ZN9CEnvLightD4Ev */

	/* vtable has 2 entries: {
	   [4] = KeyValue(_ZN9CEnvLight8KeyValueEP14KeyValueData_s), 
	   [2] = Spawn(_ZN9CEnvLight5SpawnEv), 
	} */
	/* size: 1148, cachelines: 18, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 60 bytes */
};
class CLight : public CPointEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CPointEntity        <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[2]; /*     0     0 */
private:

	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	int                        m_iStyle;             /*  1140     4 */
	int                        m_iszPattern;         /*  1144     4 */
	void CLight(class CLight *, class CLight &); /* linkage=_ZN6CLightC4EOS_ */

	void CLight(class CLight *, const class CLight  &); /* linkage=_ZN6CLightC4ERKS_ */

	void CLight(class CLight *); /* linkage=_ZN6CLightC4Ev */

	virtual void KeyValue(class CLight *, KeyValueData *); /* linkage=_ZN6CLight8KeyValueEP14KeyValueData_s */

	virtual void Spawn(class CLight *); /* linkage=_ZN6CLight5SpawnEv */

	virtual void Use(class CLight *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN6CLight3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual int Save(class CLight *, class CSave &); /* linkage=_ZN6CLight4SaveER5CSave */

	virtual int Restore(class CLight *, class CRestore &); /* linkage=_ZN6CLight7RestoreER8CRestore */

	virtual void ~CLight(class CLight *, int); /* linkage=_ZN6CLightD4Ev */

	/* vtable has 5 entries: {
	   [4] = KeyValue(_ZN6CLight8KeyValueEP14KeyValueData_s), 
	   [2] = Spawn(_ZN6CLight5SpawnEv), 
	   [45] = Use(_ZN6CLight3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [5] = Save(_ZN6CLight4SaveER5CSave), 
	   [6] = Restore(_ZN6CLight7RestoreER8CRestore), 
	} */
	/* size: 1148, cachelines: 18, members: 3, static members: 1 */
	/* sum members: 8, holes: 1, sum holes: 1140 */
	/* last cacheline: 60 bytes */
};
class CBaseMonster : public CBaseToggle {

	/* XXX 1300 bytes hole, try to pack */
	enum {
		SCRIPT_PLAYING      = 0,
		SCRIPT_WAIT         = 1,
		SCRIPT_CLEANUP      = 2,
		SCRIPT_WALK_TO_MARK = 3,
		SCRIPT_RUN_TO_MARK  = 4,
	};

public:


	/* class CBaseToggle         <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 20 boundary (1280 bytes) was 20 bytes ago --- */
	int                        m_afConditions;       /*  1300     4 */
	class EHANDLE             m_hEnemy;              /*  1304     8 */
	class EHANDLE             m_hTargetEnt;          /*  1312     8 */
	class EHANDLE             m_hOldEnemy[4];        /*  1320    32 */
	/* --- cacheline 21 boundary (1344 bytes) was 8 bytes ago --- */
	class Vector              m_vecOldEnemy[4];      /*  1352    48 */
	float                      m_flFieldOfView;      /*  1400     4 */
	float                      m_flWaitFinished;     /*  1404     4 */
	/* --- cacheline 22 boundary (1408 bytes) --- */
	float                      m_flMoveWaitFinished; /*  1408     4 */
	Activity                   m_Activity;           /*  1412     4 */
	Activity                   m_IdealActivity;      /*  1416     4 */
	int                        m_LastHitGroup;       /*  1420     4 */
	MONSTERSTATE               m_MonsterState;       /*  1424     4 */
	MONSTERSTATE               m_IdealMonsterState;  /*  1428     4 */
	int                        m_iTaskStatus;        /*  1432     4 */
	class Schedule_t *         m_pSchedule;          /*  1436     4 */
	int                        m_iScheduleIndex;     /*  1440     4 */
	struct WayPoint_t          m_Route[8];           /*  1444   128 */
	/* --- cacheline 24 boundary (1536 bytes) was 36 bytes ago --- */
	int                        m_movementGoal;       /*  1572     4 */
	int                        m_iRouteIndex;        /*  1576     4 */
	float                      m_moveWaitTime;       /*  1580     4 */
	class Vector              m_vecMoveGoal;         /*  1584    12 */
	Activity                   m_movementActivity;   /*  1596     4 */
	/* --- cacheline 25 boundary (1600 bytes) --- */
	int                        m_iAudibleList;       /*  1600     4 */
	int                        m_afSoundTypes;       /*  1604     4 */
	class Vector              m_vecLastPosition;     /*  1608    12 */
	int                        m_iHintNode;          /*  1620     4 */
	int                        m_afMemory;           /*  1624     4 */
	int                        m_iMaxHealth;         /*  1628     4 */
	class Vector              m_vecEnemyLKP;         /*  1632    12 */
	int                        m_cAmmoLoaded;        /*  1644     4 */
	int                        m_afCapability;       /*  1648     4 */
	float                      m_flNextAttack;       /*  1652     4 */
	int                        m_bitsDamageType;     /*  1656     4 */
	BYTE                       m_rgbTimeBasedDamage[8]; /*  1660     8 */
	/* --- cacheline 26 boundary (1664 bytes) was 4 bytes ago --- */
	int                        m_lastDamageAmount;   /*  1668     4 */
	int                        m_bloodColor;         /*  1672     4 */
	int                        m_failSchedule;       /*  1676     4 */
	float                      m_flHungryTime;       /*  1680     4 */
	float                      m_flDistTooFar;       /*  1684     4 */
	float                      m_flDistLook;         /*  1688     4 */
	int                        m_iTriggerCondition;  /*  1692     4 */
	string_t                   m_iszTriggerTarget;   /*  1696     4 */
	class Vector              m_HackedGunPos;        /*  1700    12 */
	typedef enum {
		SCRIPT_PLAYING      = 0,
		SCRIPT_WAIT         = 1,
		SCRIPT_CLEANUP      = 2,
		SCRIPT_WALK_TO_MARK = 3,
		SCRIPT_RUN_TO_MARK  = 4,
	} SCRIPTSTATE;

	SCRIPTSTATE                m_scriptState;        /*  1712     4 */
	class CCineMonster *       m_pCine;              /*  1716     4 */
	float                      m_flLastYawTime;      /*  1720     4 */

	/* Bitfield combined with previous fields */

	static TYPEDESCRIPTION            m_SaveData[37]; /*     0     0 */
	static class Schedule_t *         m_scheduleList[0]; /*     0     0 */
	void CBaseMonster(class CBaseMonster *, class CBaseMonster &); /* linkage=_ZN12CBaseMonsterC4EOS_ */

	void CBaseMonster(class CBaseMonster *, const class CBaseMonster  &); /* linkage=_ZN12CBaseMonsterC4ERKS_ */

	void CBaseMonster(class CBaseMonster *); /* linkage=_ZN12CBaseMonsterC4Ev */

	virtual int Save(class CBaseMonster *, class CSave &); /* linkage=_ZN12CBaseMonster4SaveER5CSave */

	virtual int Restore(class CBaseMonster *, class CRestore &); /* linkage=_ZN12CBaseMonster7RestoreER8CRestore */

	virtual void KeyValue(class CBaseMonster *, KeyValueData *); /* linkage=_ZN12CBaseMonster8KeyValueEP14KeyValueData_s */

	void MonsterUse(class CBaseMonster *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN12CBaseMonster10MonsterUseEP11CBaseEntityS1_8USE_TYPEf */

	void CorpseUse(class CBaseMonster *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN12CBaseMonster9CorpseUseEP11CBaseEntityS1_8USE_TYPEf */

	virtual int BloodColor(class CBaseMonster *); /* linkage=_ZN12CBaseMonster10BloodColorEv */

	virtual class CBaseMonster * MyMonsterPointer(class CBaseMonster *); /* linkage=_ZN12CBaseMonster16MyMonsterPointerEv */

	virtual void Look(class CBaseMonster *, int); /* linkage=_ZN12CBaseMonster4LookEi */

	virtual void RunAI(class CBaseMonster *); /* linkage=_ZN12CBaseMonster5RunAIEv */

	void Listen(class CBaseMonster *); /* linkage=_ZN12CBaseMonster6ListenEv */

	virtual BOOL IsAlive(class CBaseMonster *); /* linkage=_ZN12CBaseMonster7IsAliveEv */

	virtual BOOL ShouldFadeOnDeath(class CBaseMonster *); /* linkage=_ZN12CBaseMonster17ShouldFadeOnDeathEv */

	virtual float ChangeYaw(class CBaseMonster *, int); /* linkage=_ZN12CBaseMonster9ChangeYawEi */

	float VecToYaw(class CBaseMonster *, class Vector); /* linkage=_ZN12CBaseMonster8VecToYawE6Vector */

	float FlYawDiff(class CBaseMonster *); /* linkage=_ZN12CBaseMonster9FlYawDiffEv */

	float DamageForce(class CBaseMonster *, float); /* linkage=_ZN12CBaseMonster11DamageForceEf */

	virtual void MonsterThink(class CBaseMonster *); /* linkage=_ZN12CBaseMonster12MonsterThinkEv */

	void CallMonsterThink(class CBaseMonster *); /* linkage=_ZN12CBaseMonster16CallMonsterThinkEv */

	virtual int IRelationship(class CBaseMonster *, class CBaseEntity *); /* linkage=_ZN12CBaseMonster13IRelationshipEP11CBaseEntity */

	virtual void MonsterInit(class CBaseMonster *); /* linkage=_ZN12CBaseMonster11MonsterInitEv */

	virtual void MonsterInitDead(class CBaseMonster *); /* linkage=_ZN12CBaseMonster15MonsterInitDeadEv */

	virtual void BecomeDead(class CBaseMonster *); /* linkage=_ZN12CBaseMonster10BecomeDeadEv */

	void CorpseFallThink(class CBaseMonster *); /* linkage=_ZN12CBaseMonster15CorpseFallThinkEv */

	void MonsterInitThink(class CBaseMonster *); /* linkage=_ZN12CBaseMonster16MonsterInitThinkEv */

	virtual void StartMonster(class CBaseMonster *); /* linkage=_ZN12CBaseMonster12StartMonsterEv */

	virtual class CBaseEntity * BestVisibleEnemy(class CBaseMonster *); /* linkage=_ZN12CBaseMonster16BestVisibleEnemyEv */

	virtual BOOL FInViewCone(class CBaseMonster *, class CBaseEntity *); /* linkage=_ZN12CBaseMonster11FInViewConeEP11CBaseEntity */

	virtual BOOL FInViewCone(class CBaseMonster *, class Vector *); /* linkage=_ZN12CBaseMonster11FInViewConeEP6Vector */

	virtual void HandleAnimEvent(class CBaseMonster *, MonsterEvent_t *); /* linkage=_ZN12CBaseMonster15HandleAnimEventEP14MonsterEvent_t */

	virtual int CheckLocalMove(class CBaseMonster *, const class Vector  &, const class Vector  &, class CBaseEntity *, float *); /* linkage=_ZN12CBaseMonster14CheckLocalMoveERK6VectorS2_P11CBaseEntityPf */

	virtual void Move(class CBaseMonster *, float); /* linkage=_ZN12CBaseMonster4MoveEf */

	virtual void MoveExecute(class CBaseMonster *, class CBaseEntity *, const class Vector  &, float); /* linkage=_ZN12CBaseMonster11MoveExecuteEP11CBaseEntityRK6Vectorf */

	virtual BOOL ShouldAdvanceRoute(class CBaseMonster *, float); /* linkage=_ZN12CBaseMonster18ShouldAdvanceRouteEf */

	virtual Activity GetStoppedActivity(class CBaseMonster *); /* linkage=_ZN12CBaseMonster18GetStoppedActivityEv */

	virtual void Stop(class CBaseMonster *); /* linkage=_ZN12CBaseMonster4StopEv */

	void StopAnimation(class CBaseMonster *); /* linkage=_ZN12CBaseMonster13StopAnimationEv */

	virtual BOOL CheckRangeAttack1(class CBaseMonster *, float, float); /* linkage=_ZN12CBaseMonster17CheckRangeAttack1Eff */

	virtual BOOL CheckRangeAttack2(class CBaseMonster *, float, float); /* linkage=_ZN12CBaseMonster17CheckRangeAttack2Eff */

	virtual BOOL CheckMeleeAttack1(class CBaseMonster *, float, float); /* linkage=_ZN12CBaseMonster17CheckMeleeAttack1Eff */

	virtual BOOL CheckMeleeAttack2(class CBaseMonster *, float, float); /* linkage=_ZN12CBaseMonster17CheckMeleeAttack2Eff */

	BOOL FHaveSchedule(class CBaseMonster *); /* linkage=_ZN12CBaseMonster13FHaveScheduleEv */

	BOOL FScheduleValid(class CBaseMonster *); /* linkage=_ZN12CBaseMonster14FScheduleValidEv */

	void ClearSchedule(class CBaseMonster *); /* linkage=_ZN12CBaseMonster13ClearScheduleEv */

	BOOL FScheduleDone(class CBaseMonster *); /* linkage=_ZN12CBaseMonster13FScheduleDoneEv */

	void ChangeSchedule(class CBaseMonster *, class Schedule_t *); /* linkage=_ZN12CBaseMonster14ChangeScheduleEP10Schedule_t */

	void NextScheduledTask(class CBaseMonster *); /* linkage=_ZN12CBaseMonster17NextScheduledTaskEv */

	class Schedule_t * ScheduleInList(class CBaseMonster *, const char  *, class Schedule_t * *, int); /* linkage=_ZN12CBaseMonster14ScheduleInListEPKcPP10Schedule_ti */

	virtual class Schedule_t * ScheduleFromName(class CBaseMonster *, const char  *); /* linkage=_ZN12CBaseMonster16ScheduleFromNameEPKc */

	void MaintainSchedule(class CBaseMonster *); /* linkage=_ZN12CBaseMonster16MaintainScheduleEv */

	virtual void StartTask(class CBaseMonster *, class Task_t *); /* linkage=_ZN12CBaseMonster9StartTaskEP6Task_t */

	virtual void RunTask(class CBaseMonster *, class Task_t *); /* linkage=_ZN12CBaseMonster7RunTaskEP6Task_t */

	virtual class Schedule_t * GetScheduleOfType(class CBaseMonster *, int); /* linkage=_ZN12CBaseMonster17GetScheduleOfTypeEi */

	virtual class Schedule_t * GetSchedule(class CBaseMonster *); /* linkage=_ZN12CBaseMonster11GetScheduleEv */

	virtual void ScheduleChange(class CBaseMonster *); /* linkage=_ZN12CBaseMonster14ScheduleChangeEv */

	virtual int CanPlaySequence(class CBaseMonster *, BOOL, int); /* linkage=_ZN12CBaseMonster15CanPlaySequenceEii */

	virtual int CanPlaySentence(class CBaseMonster *, BOOL); /* linkage=_ZN12CBaseMonster15CanPlaySentenceEi */

	virtual void PlaySentence(class CBaseMonster *, const char  *, float, float, float); /* linkage=_ZN12CBaseMonster12PlaySentenceEPKcfff */

	virtual void PlayScriptedSentence(class CBaseMonster *, const char  *, float, float, float, BOOL, class CBaseEntity *); /* linkage=_ZN12CBaseMonster20PlayScriptedSentenceEPKcfffiP11CBaseEntity */

	virtual void SentenceStop(class CBaseMonster *); /* linkage=_ZN12CBaseMonster12SentenceStopEv */

	class Task_t * GetTask(class CBaseMonster *); /* linkage=_ZN12CBaseMonster7GetTaskEv */

	virtual MONSTERSTATE GetIdealState(class CBaseMonster *); /* linkage=_ZN12CBaseMonster13GetIdealStateEv */

	virtual void SetActivity(class CBaseMonster *, Activity); /* linkage=_ZN12CBaseMonster11SetActivityE8Activity */

	void SetSequenceByName(class CBaseMonster *, char *); /* linkage=_ZN12CBaseMonster17SetSequenceByNameEPc */

	void SetState(class CBaseMonster *, MONSTERSTATE); /* linkage=_ZN12CBaseMonster8SetStateE12MONSTERSTATE */

	virtual void ReportAIState(class CBaseMonster *); /* linkage=_ZN12CBaseMonster13ReportAIStateEv */

	void CheckAttacks(class CBaseMonster *, class CBaseEntity *, float); /* linkage=_ZN12CBaseMonster12CheckAttacksEP11CBaseEntityf */

	virtual int CheckEnemy(class CBaseMonster *, class CBaseEntity *); /* linkage=_ZN12CBaseMonster10CheckEnemyEP11CBaseEntity */

	void PushEnemy(class CBaseMonster *, class CBaseEntity *, class Vector &); /* linkage=_ZN12CBaseMonster9PushEnemyEP11CBaseEntityR6Vector */

	BOOL PopEnemy(class CBaseMonster *); /* linkage=_ZN12CBaseMonster8PopEnemyEv */

	BOOL FGetNodeRoute(class CBaseMonster *, class Vector); /* linkage=_ZN12CBaseMonster13FGetNodeRouteE6Vector */

	void TaskComplete(class CBaseMonster *); /* linkage=_ZN12CBaseMonster12TaskCompleteEv */

	void MovementComplete(class CBaseMonster *); /* linkage=_ZN12CBaseMonster16MovementCompleteEv */

	void TaskFail(class CBaseMonster *); /* linkage=_ZN12CBaseMonster8TaskFailEv */

	void TaskBegin(class CBaseMonster *); /* linkage=_ZN12CBaseMonster9TaskBeginEv */

	int TaskIsRunning(class CBaseMonster *); /* linkage=_ZN12CBaseMonster13TaskIsRunningEv */

	int TaskIsComplete(class CBaseMonster *); /* linkage=_ZN12CBaseMonster14TaskIsCompleteEv */

	int MovementIsComplete(class CBaseMonster *); /* linkage=_ZN12CBaseMonster18MovementIsCompleteEv */

	int IScheduleFlags(class CBaseMonster *); /* linkage=_ZN12CBaseMonster14IScheduleFlagsEv */

	BOOL FRefreshRoute(class CBaseMonster *); /* linkage=_ZN12CBaseMonster13FRefreshRouteEv */

	BOOL FRouteClear(class CBaseMonster *); /* linkage=_ZN12CBaseMonster11FRouteClearEv */

	void RouteSimplify(class CBaseMonster *, class CBaseEntity *); /* linkage=_ZN12CBaseMonster13RouteSimplifyEP11CBaseEntity */

	void AdvanceRoute(class CBaseMonster *, float); /* linkage=_ZN12CBaseMonster12AdvanceRouteEf */

	virtual BOOL FTriangulate(class CBaseMonster *, const class Vector  &, const class Vector  &, float, class CBaseEntity *, class Vector *); /* linkage=_ZN12CBaseMonster12FTriangulateERK6VectorS2_fP11CBaseEntityPS0_ */

	void MakeIdealYaw(class CBaseMonster *, class Vector); /* linkage=_ZN12CBaseMonster12MakeIdealYawE6Vector */

	virtual void SetYawSpeed(class CBaseMonster *); /* linkage=_ZN12CBaseMonster11SetYawSpeedEv */

	BOOL BuildRoute(class CBaseMonster *, const class Vector  &, int, class CBaseEntity *); /* linkage=_ZN12CBaseMonster10BuildRouteERK6VectoriP11CBaseEntity */

	virtual BOOL BuildNearestRoute(class CBaseMonster *, class Vector, class Vector, float, float); /* linkage=_ZN12CBaseMonster17BuildNearestRouteE6VectorS0_ff */

	int RouteClassify(class CBaseMonster *, int); /* linkage=_ZN12CBaseMonster13RouteClassifyEi */

	void InsertWaypoint(class CBaseMonster *, class Vector, int); /* linkage=_ZN12CBaseMonster14InsertWaypointE6Vectori */

	BOOL FindLateralCover(class CBaseMonster *, const class Vector  &, const class Vector  &); /* linkage=_ZN12CBaseMonster16FindLateralCoverERK6VectorS2_ */

	virtual BOOL FindCover(class CBaseMonster *, class Vector, class Vector, float, float); /* linkage=_ZN12CBaseMonster9FindCoverE6VectorS0_ff */

	virtual BOOL FValidateCover(class CBaseMonster *, const class Vector  &); /* linkage=_ZN12CBaseMonster14FValidateCoverERK6Vector */

	virtual float CoverRadius(class CBaseMonster *); /* linkage=_ZN12CBaseMonster11CoverRadiusEv */

	virtual BOOL FCanCheckAttacks(class CBaseMonster *); /* linkage=_ZN12CBaseMonster16FCanCheckAttacksEv */

	virtual void CheckAmmo(class CBaseMonster *); /* linkage=_ZN12CBaseMonster9CheckAmmoEv */

	virtual int IgnoreConditions(class CBaseMonster *); /* linkage=_ZN12CBaseMonster16IgnoreConditionsEv */

	void SetConditions(class CBaseMonster *, int); /* linkage=_ZN12CBaseMonster13SetConditionsEi */

	void ClearConditions(class CBaseMonster *, int); /* linkage=_ZN12CBaseMonster15ClearConditionsEi */

	BOOL HasConditions(class CBaseMonster *, int); /* linkage=_ZN12CBaseMonster13HasConditionsEi */

	BOOL HasAllConditions(class CBaseMonster *, int); /* linkage=_ZN12CBaseMonster16HasAllConditionsEi */

	virtual BOOL FValidateHintType(class CBaseMonster *, short int); /* linkage=_ZN12CBaseMonster17FValidateHintTypeEs */

	int FindHintNode(class CBaseMonster *); /* linkage=_ZN12CBaseMonster12FindHintNodeEv */

	virtual BOOL FCanActiveIdle(class CBaseMonster *); /* linkage=_ZN12CBaseMonster14FCanActiveIdleEv */

	void SetTurnActivity(class CBaseMonster *); /* linkage=_ZN12CBaseMonster15SetTurnActivityEv */

	float FLSoundVolume(class CBaseMonster *, class CSound *); /* linkage=_ZN12CBaseMonster13FLSoundVolumeEP6CSound */

	BOOL MoveToNode(class CBaseMonster *, Activity, float, const class Vector  &); /* linkage=_ZN12CBaseMonster10MoveToNodeE8ActivityfRK6Vector */

	BOOL MoveToTarget(class CBaseMonster *, Activity, float); /* linkage=_ZN12CBaseMonster12MoveToTargetE8Activityf */

	BOOL MoveToLocation(class CBaseMonster *, Activity, float, const class Vector  &); /* linkage=_ZN12CBaseMonster14MoveToLocationE8ActivityfRK6Vector */

	BOOL MoveToEnemy(class CBaseMonster *, Activity, float); /* linkage=_ZN12CBaseMonster11MoveToEnemyE8Activityf */

	float OpenDoorAndWait(class CBaseMonster *, entvars_t *); /* linkage=_ZN12CBaseMonster15OpenDoorAndWaitEP9entvars_s */

	virtual int ISoundMask(class CBaseMonster *); /* linkage=_ZN12CBaseMonster10ISoundMaskEv */

	virtual class CSound * PBestSound(class CBaseMonster *); /* linkage=_ZN12CBaseMonster10PBestSoundEv */

	virtual class CSound * PBestScent(class CBaseMonster *); /* linkage=_ZN12CBaseMonster10PBestScentEv */

	virtual float HearingSensitivity(class CBaseMonster *); /* linkage=_ZN12CBaseMonster18HearingSensitivityEv */

	virtual BOOL FBecomeProne(class CBaseMonster *); /* linkage=_ZN12CBaseMonster12FBecomeProneEv */

	virtual void BarnacleVictimBitten(class CBaseMonster *, entvars_t *); /* linkage=_ZN12CBaseMonster20BarnacleVictimBittenEP9entvars_s */

	virtual void BarnacleVictimReleased(class CBaseMonster *); /* linkage=_ZN12CBaseMonster22BarnacleVictimReleasedEv */

	void SetEyePosition(class CBaseMonster *); /* linkage=_ZN12CBaseMonster14SetEyePositionEv */

	BOOL FShouldEat(class CBaseMonster *); /* linkage=_ZN12CBaseMonster10FShouldEatEv */

	void Eat(class CBaseMonster *, float); /* linkage=_ZN12CBaseMonster3EatEf */

	class CBaseEntity * CheckTraceHullAttack(class CBaseMonster *, float, int, int); /* linkage=_ZN12CBaseMonster20CheckTraceHullAttackEfii */

	BOOL FacingIdeal(class CBaseMonster *); /* linkage=_ZN12CBaseMonster11FacingIdealEv */

	BOOL FCheckAITrigger(class CBaseMonster *); /* linkage=_ZN12CBaseMonster15FCheckAITriggerEv */

	BOOL NoFriendlyFire(class CBaseMonster *); /* linkage=_ZN12CBaseMonster14NoFriendlyFireEv */

	BOOL BBoxFlat(class CBaseMonster *); /* linkage=_ZN12CBaseMonster8BBoxFlatEv */

	virtual void PrescheduleThink(class CBaseMonster *); /* linkage=_ZN12CBaseMonster16PrescheduleThinkEv */

	BOOL GetEnemy(class CBaseMonster *); /* linkage=_ZN12CBaseMonster8GetEnemyEv */

	void MakeDamageBloodDecal(class CBaseMonster *, int, float, class  *, const class Vector  &); /* linkage=_ZN12CBaseMonster20MakeDamageBloodDecalEifP11TraceResultRK6Vector */

	virtual void TraceAttack(class CBaseMonster *, entvars_t *, float, class Vector, class  *, int); /* linkage=_ZN12CBaseMonster11TraceAttackEP9entvars_sf6VectorP11TraceResulti */

	float UpdateTarget(class CBaseMonster *, entvars_t *); /* linkage=_ZN12CBaseMonster12UpdateTargetEP9entvars_s */

	virtual Activity GetDeathActivity(class CBaseMonster *); /* linkage=_ZN12CBaseMonster16GetDeathActivityEv */

	Activity GetSmallFlinchActivity(class CBaseMonster *); /* linkage=_ZN12CBaseMonster22GetSmallFlinchActivityEv */

	virtual void Killed(class CBaseMonster *, entvars_t *, entvars_t *, int); /* linkage=_ZN12CBaseMonster6KilledEP9entvars_sS1_i */

	virtual void GibMonster(class CBaseMonster *); /* linkage=_ZN12CBaseMonster10GibMonsterEv */

	BOOL ShouldGibMonster(class CBaseMonster *, int); /* linkage=_ZN12CBaseMonster16ShouldGibMonsterEi */

	void CallGibMonster(class CBaseMonster *); /* linkage=_ZN12CBaseMonster14CallGibMonsterEv */

	virtual BOOL HasHumanGibs(class CBaseMonster *); /* linkage=_ZN12CBaseMonster12HasHumanGibsEv */

	virtual BOOL HasAlienGibs(class CBaseMonster *); /* linkage=_ZN12CBaseMonster12HasAlienGibsEv */

	virtual void FadeMonster(class CBaseMonster *); /* linkage=_ZN12CBaseMonster11FadeMonsterEv */

	class Vector ShootAtEnemy(class CBaseMonster *, const class Vector  &); /* linkage=_ZN12CBaseMonster12ShootAtEnemyERK6Vector */

	virtual class Vector BodyTarget(class CBaseMonster *, const class Vector  &); /* linkage=_ZN12CBaseMonster10BodyTargetERK6Vector */

	class Vector GetGunPosition(class CBaseMonster *); /* linkage=_ZN12CBaseMonster14GetGunPositionEv */

	virtual int TakeHealth(class CBaseMonster *, float, int); /* linkage=_ZN12CBaseMonster10TakeHealthEfi */

	virtual int TakeDamage(class CBaseMonster *, entvars_t *, entvars_t *, float, int); /* linkage=_ZN12CBaseMonster10TakeDamageEP9entvars_sS1_fi */

	int DeadTakeDamage(class CBaseMonster *, entvars_t *, entvars_t *, float, int); /* linkage=_ZN12CBaseMonster14DeadTakeDamageEP9entvars_sS1_fi */

	virtual void RadiusDamage(class CBaseMonster *, entvars_t *, entvars_t *, float, int, int); /* linkage=_ZN12CBaseMonster12RadiusDamageEP9entvars_sS1_fii */

	virtual void RadiusDamage(class CBaseMonster *, class Vector, entvars_t *, entvars_t *, float, int, int); /* linkage=_ZN12CBaseMonster12RadiusDamageE6VectorP9entvars_sS2_fii */

	virtual int IsMoving(class CBaseMonster *); /* linkage=_ZN12CBaseMonster8IsMovingEv */

	void RouteClear(class CBaseMonster *); /* linkage=_ZN12CBaseMonster10RouteClearEv */

	void RouteNew(class CBaseMonster *); /* linkage=_ZN12CBaseMonster8RouteNewEv */

	virtual void DeathSound(class CBaseMonster *); /* linkage=_ZN12CBaseMonster10DeathSoundEv */

	virtual void AlertSound(class CBaseMonster *); /* linkage=_ZN12CBaseMonster10AlertSoundEv */

	virtual void IdleSound(class CBaseMonster *); /* linkage=_ZN12CBaseMonster9IdleSoundEv */

	virtual void PainSound(class CBaseMonster *); /* linkage=_ZN12CBaseMonster9PainSoundEv */

	virtual void StopFollowing(class CBaseMonster *, BOOL); /* linkage=_ZN12CBaseMonster13StopFollowingEi */

	void Remember(class CBaseMonster *, int); /* linkage=_ZN12CBaseMonster8RememberEi */

	void Forget(class CBaseMonster *, int); /* linkage=_ZN12CBaseMonster6ForgetEi */

	BOOL HasMemory(class CBaseMonster *, int); /* linkage=_ZN12CBaseMonster9HasMemoryEi */

	BOOL HasAllMemories(class CBaseMonster *, int); /* linkage=_ZN12CBaseMonster14HasAllMemoriesEi */

	BOOL ExitScriptedSequence(class CBaseMonster *); /* linkage=_ZN12CBaseMonster20ExitScriptedSequenceEv */

	BOOL CineCleanup(class CBaseMonster *); /* linkage=_ZN12CBaseMonster11CineCleanupEv */

	class CBaseEntity * DropItem(class CBaseMonster *, char *, const class Vector  &, const class Vector  &); /* linkage=_ZN12CBaseMonster8DropItemEPcRK6VectorS3_ */

	virtual void ~CBaseMonster(class CBaseMonster *, int); /* linkage=_ZN12CBaseMonsterD4Ev */

	/* vtable has 82 entries: {
	   [5] = Save(_ZN12CBaseMonster4SaveER5CSave), 
	   [6] = Restore(_ZN12CBaseMonster7RestoreER8CRestore), 
	   [4] = KeyValue(_ZN12CBaseMonster8KeyValueEP14KeyValueData_s), 
	   [16] = BloodColor(_ZN12CBaseMonster10BloodColorEv), 
	   [19] = MyMonsterPointer(_ZN12CBaseMonster16MyMonsterPointerEv), 
	   [66] = Look(_ZN12CBaseMonster4LookEi), 
	   [67] = RunAI(_ZN12CBaseMonster5RunAIEv), 
	   [34] = IsAlive(_ZN12CBaseMonster7IsAliveEv), 
	   [68] = ShouldFadeOnDeath(_ZN12CBaseMonster17ShouldFadeOnDeathEv), 
	   [69] = ChangeYaw(_ZN12CBaseMonster9ChangeYawEi), 
	   [70] = MonsterThink(_ZN12CBaseMonster12MonsterThinkEv), 
	   [71] = IRelationship(_ZN12CBaseMonster13IRelationshipEP11CBaseEntity), 
	   [72] = MonsterInit(_ZN12CBaseMonster11MonsterInitEv), 
	   [73] = MonsterInitDead(_ZN12CBaseMonster15MonsterInitDeadEv), 
	   [74] = BecomeDead(_ZN12CBaseMonster10BecomeDeadEv), 
	   [75] = StartMonster(_ZN12CBaseMonster12StartMonsterEv), 
	   [76] = BestVisibleEnemy(_ZN12CBaseMonster16BestVisibleEnemyEv), 
	   [77] = FInViewCone(_ZN12CBaseMonster11FInViewConeEP11CBaseEntity), 
	   [78] = FInViewCone(_ZN12CBaseMonster11FInViewConeEP6Vector), 
	   [65] = HandleAnimEvent(_ZN12CBaseMonster15HandleAnimEventEP14MonsterEvent_t), 
	   [79] = CheckLocalMove(_ZN12CBaseMonster14CheckLocalMoveERK6VectorS2_P11CBaseEntityPf), 
	   [80] = Move(_ZN12CBaseMonster4MoveEf), 
	   [81] = MoveExecute(_ZN12CBaseMonster11MoveExecuteEP11CBaseEntityRK6Vectorf), 
	   [82] = ShouldAdvanceRoute(_ZN12CBaseMonster18ShouldAdvanceRouteEf), 
	   [83] = GetStoppedActivity(_ZN12CBaseMonster18GetStoppedActivityEv), 
	   [84] = Stop(_ZN12CBaseMonster4StopEv), 
	   [85] = CheckRangeAttack1(_ZN12CBaseMonster17CheckRangeAttack1Eff), 
	   [86] = CheckRangeAttack2(_ZN12CBaseMonster17CheckRangeAttack2Eff), 
	   [87] = CheckMeleeAttack1(_ZN12CBaseMonster17CheckMeleeAttack1Eff), 
	   [88] = CheckMeleeAttack2(_ZN12CBaseMonster17CheckMeleeAttack2Eff), 
	   [89] = ScheduleFromName(_ZN12CBaseMonster16ScheduleFromNameEPKc), 
	   [90] = StartTask(_ZN12CBaseMonster9StartTaskEP6Task_t), 
	   [91] = RunTask(_ZN12CBaseMonster7RunTaskEP6Task_t), 
	   [92] = GetScheduleOfType(_ZN12CBaseMonster17GetScheduleOfTypeEi), 
	   [93] = GetSchedule(_ZN12CBaseMonster11GetScheduleEv), 
	   [94] = ScheduleChange(_ZN12CBaseMonster14ScheduleChangeEv), 
	   [95] = CanPlaySequence(_ZN12CBaseMonster15CanPlaySequenceEii), 
	   [96] = CanPlaySentence(_ZN12CBaseMonster15CanPlaySentenceEi), 
	   [97] = PlaySentence(_ZN12CBaseMonster12PlaySentenceEPKcfff), 
	   [98] = PlayScriptedSentence(_ZN12CBaseMonster20PlayScriptedSentenceEPKcfffiP11CBaseEntity), 
	   [99] = SentenceStop(_ZN12CBaseMonster12SentenceStopEv), 
	   [100] = GetIdealState(_ZN12CBaseMonster13GetIdealStateEv), 
	   [101] = SetActivity(_ZN12CBaseMonster11SetActivityE8Activity), 
	   [102] = ReportAIState(_ZN12CBaseMonster13ReportAIStateEv), 
	   [103] = CheckEnemy(_ZN12CBaseMonster10CheckEnemyEP11CBaseEntity), 
	   [104] = FTriangulate(_ZN12CBaseMonster12FTriangulateERK6VectorS2_fP11CBaseEntityPS0_), 
	   [105] = SetYawSpeed(_ZN12CBaseMonster11SetYawSpeedEv), 
	   [106] = BuildNearestRoute(_ZN12CBaseMonster17BuildNearestRouteE6VectorS0_ff), 
	   [107] = FindCover(_ZN12CBaseMonster9FindCoverE6VectorS0_ff), 
	   [108] = FValidateCover(_ZN12CBaseMonster14FValidateCoverERK6Vector), 
	   [109] = CoverRadius(_ZN12CBaseMonster11CoverRadiusEv), 
	   [110] = FCanCheckAttacks(_ZN12CBaseMonster16FCanCheckAttacksEv), 
	   [111] = CheckAmmo(_ZN12CBaseMonster9CheckAmmoEv), 
	   [112] = IgnoreConditions(_ZN12CBaseMonster16IgnoreConditionsEv), 
	   [113] = FValidateHintType(_ZN12CBaseMonster17FValidateHintTypeEs), 
	   [114] = FCanActiveIdle(_ZN12CBaseMonster14FCanActiveIdleEv), 
	   [115] = ISoundMask(_ZN12CBaseMonster10ISoundMaskEv), 
	   [116] = PBestSound(_ZN12CBaseMonster10PBestSoundEv), 
	   [117] = PBestScent(_ZN12CBaseMonster10PBestScentEv), 
	   [118] = HearingSensitivity(_ZN12CBaseMonster18HearingSensitivityEv), 
	   [49] = FBecomeProne(_ZN12CBaseMonster12FBecomeProneEv), 
	   [119] = BarnacleVictimBitten(_ZN12CBaseMonster20BarnacleVictimBittenEP9entvars_s), 
	   [120] = BarnacleVictimReleased(_ZN12CBaseMonster22BarnacleVictimReleasedEv), 
	   [121] = PrescheduleThink(_ZN12CBaseMonster16PrescheduleThinkEv), 
	   [12] = TraceAttack(_ZN12CBaseMonster11TraceAttackEP9entvars_sf6VectorP11TraceResulti), 
	   [122] = GetDeathActivity(_ZN12CBaseMonster16GetDeathActivityEv), 
	   [15] = Killed(_ZN12CBaseMonster6KilledEP9entvars_sS1_i), 
	   [123] = GibMonster(_ZN12CBaseMonster10GibMonsterEv), 
	   [124] = HasHumanGibs(_ZN12CBaseMonster12HasHumanGibsEv), 
	   [125] = HasAlienGibs(_ZN12CBaseMonster12HasAlienGibsEv), 
	   [126] = FadeMonster(_ZN12CBaseMonster11FadeMonsterEv), 
	   [53] = BodyTarget(_ZN12CBaseMonster10BodyTargetERK6Vector), 
	   [14] = TakeHealth(_ZN12CBaseMonster10TakeHealthEfi), 
	   [13] = TakeDamage(_ZN12CBaseMonster10TakeDamageEP9entvars_sS1_fi), 
	   [127] = RadiusDamage(_ZN12CBaseMonster12RadiusDamageEP9entvars_sS1_fii), 
	   [128] = RadiusDamage(_ZN12CBaseMonster12RadiusDamageE6VectorP9entvars_sS2_fii), 
	   [26] = IsMoving(_ZN12CBaseMonster8IsMovingEv), 
	   [129] = DeathSound(_ZN12CBaseMonster10DeathSoundEv), 
	   [130] = AlertSound(_ZN12CBaseMonster10AlertSoundEv), 
	   [131] = IdleSound(_ZN12CBaseMonster9IdleSoundEv), 
	   [132] = PainSound(_ZN12CBaseMonster9PainSoundEv), 
	   [133] = StopFollowing(_ZN12CBaseMonster13StopFollowingEi), 
	} */
	/* size: 1724, cachelines: 27, members: 47, static members: 2 */
	/* sum members: 424, holes: 1, sum holes: 1300 */
	/* last cacheline: 60 bytes */
};
class CNode {
	class Vector              m_vecOrigin;           /*     0    12 */
	class Vector              m_vecOriginPeek;       /*    12    12 */
	BYTE                       m_Region[3];          /*    24     3 */

	/* XXX 1 byte hole, try to pack */

	int                        m_afNodeInfo;         /*    28     4 */
	int                        m_cNumLinks;          /*    32     4 */
	int                        m_iFirstLink;         /*    36     4 */
	int                        m_pNextBestNode[4][2]; /*    40    32 */
	/* --- cacheline 1 boundary (64 bytes) was 8 bytes ago --- */
	float                      m_flClosestSoFar;     /*    72     4 */
	int                        m_iPreviousNode;      /*    76     4 */
	short int                  m_sHintType;          /*    80     2 */
	short int                  m_sHintActivity;      /*    82     2 */
	float                      m_flHintYaw;          /*    84     4 */
	void CNode(class CNode *); /* linkage=_ZN5CNodeC4Ev */


	/* size: 88, cachelines: 2, members: 12 */
	/* sum members: 87, holes: 1, sum holes: 1 */
	/* last cacheline: 24 bytes */
};
class CLink {
	int                        m_iSrcNode;           /*     0     4 */
	int                        m_iDestNode;          /*     4     4 */
	entvars_t *                m_pLinkEnt;           /*     8     4 */
	char                       m_szLinkEntModelname[4]; /*    12     4 */
	int                        m_afLinkInfo;         /*    16     4 */
	float                      m_flWeight;           /*    20     4 */

	/* size: 24, cachelines: 1, members: 6 */
	/* last cacheline: 24 bytes */
};
class CGraph {
	enum NODEQUERY {
		NODEGRAPH_DYNAMIC = 0,
		NODEGRAPH_STATIC  = 1,
	};

	BOOL                       m_fGraphPresent;      /*     0     4 */
	BOOL                       m_fGraphPointersSet;  /*     4     4 */
	BOOL                       m_fRoutingComplete;   /*     8     4 */
	class CNode *              m_pNodes;             /*    12     4 */
	class CLink *              m_pLinkPool;          /*    16     4 */
	char *                     m_pRouteInfo;         /*    20     4 */
	int                        m_cNodes;             /*    24     4 */
	int                        m_cLinks;             /*    28     4 */
	int                        m_nRouteInfo;         /*    32     4 */
	DIST_INFO *                m_di;                 /*    36     4 */
	int                        m_RangeStart[3][256]; /*    40  3072 */
	/* --- cacheline 48 boundary (3072 bytes) was 40 bytes ago --- */
	int                        m_RangeEnd[3][256];   /*  3112  3072 */
	/* --- cacheline 96 boundary (6144 bytes) was 40 bytes ago --- */
	float                      m_flShortest;         /*  6184     4 */
	int                        m_iNearest;           /*  6188     4 */
	int                        m_minX;               /*  6192     4 */
	int                        m_minY;               /*  6196     4 */
	int                        m_minZ;               /*  6200     4 */
	int                        m_maxX;               /*  6204     4 */
	/* --- cacheline 97 boundary (6208 bytes) --- */
	int                        m_maxY;               /*  6208     4 */
	int                        m_maxZ;               /*  6212     4 */
	int                        m_minBoxX;            /*  6216     4 */
	int                        m_minBoxY;            /*  6220     4 */
	int                        m_minBoxZ;            /*  6224     4 */
	int                        m_maxBoxX;            /*  6228     4 */
	int                        m_maxBoxY;            /*  6232     4 */
	int                        m_maxBoxZ;            /*  6236     4 */
	int                        m_CheckedCounter;     /*  6240     4 */
	float                      m_RegionMin[3];       /*  6244    12 */
	float                      m_RegionMax[3];       /*  6256    12 */
	CACHE_ENTRY                m_Cache[128];         /*  6268  2048 */
	/* --- cacheline 129 boundary (8256 bytes) was 60 bytes ago --- */
	int                        m_HashPrimes[16];     /*  8316    64 */
	/* --- cacheline 130 boundary (8320 bytes) was 60 bytes ago --- */
	short int *                m_pHashLinks;         /*  8380     4 */
	/* --- cacheline 131 boundary (8384 bytes) --- */
	int                        m_nHashLinks;         /*  8384     4 */
	int                        m_iLastActiveIdleSearch; /*  8388     4 */
	int                        m_iLastCoverSearch;   /*  8392     4 */
	void CGraph(class CGraph *); /* linkage=_ZN6CGraphC4Ev */

	int LinkVisibleNodes(class CGraph *, class CLink *, FILE *, int *); /* linkage=_ZN6CGraph16LinkVisibleNodesEP5CLinkP8_IO_FILEPi */

	int RejectInlineLinks(class CGraph *, class CLink *, FILE *); /* linkage=_ZN6CGraph17RejectInlineLinksEP5CLinkP8_IO_FILE */

	int FindShortestPath(class CGraph *, int *, int, int, int, int); /* linkage=_ZN6CGraph16FindShortestPathEPiiiii */

	int FindNearestNode(class CGraph *, const class Vector  &, class CBaseEntity *); /* linkage=_ZN6CGraph15FindNearestNodeERK6VectorP11CBaseEntity */

	int FindNearestNode(class CGraph *, const class Vector  &, int); /* linkage=_ZN6CGraph15FindNearestNodeERK6Vectori */

	float PathLength(class CGraph *, int, int, int, int); /* linkage=_ZN6CGraph10PathLengthEiiii */

	int NextNodeInRoute(class CGraph *, int, int, int, int); /* linkage=_ZN6CGraph15NextNodeInRouteEiiii */

	int HandleLinkEnt(class CGraph *, int, entvars_t *, int, enum NODEQUERY); /* linkage=_ZN6CGraph13HandleLinkEntEiP9entvars_siNS_9NODEQUERYE */

	entvars_t * LinkEntForLink(class CGraph *, class CLink *, class CNode *); /* linkage=_ZN6CGraph14LinkEntForLinkEP5CLinkP5CNode */

	void ShowNodeConnections(class CGraph *, int); /* linkage=_ZN6CGraph19ShowNodeConnectionsEi */

	void InitGraph(class CGraph *); /* linkage=_ZN6CGraph9InitGraphEv */

	int AllocNodes(class CGraph *); /* linkage=_ZN6CGraph10AllocNodesEv */

	int CheckNODFile(class CGraph *, char *); /* linkage=_ZN6CGraph12CheckNODFileEPc */

	int FLoadGraph(class CGraph *, char *); /* linkage=_ZN6CGraph10FLoadGraphEPc */

	int FSaveGraph(class CGraph *, char *); /* linkage=_ZN6CGraph10FSaveGraphEPc */

	int FSetGraphPointers(class CGraph *); /* linkage=_ZN6CGraph17FSetGraphPointersEv */

	void CheckNode(class CGraph *, class Vector, int); /* linkage=_ZN6CGraph9CheckNodeE6Vectori */

	void BuildRegionTables(class CGraph *); /* linkage=_ZN6CGraph17BuildRegionTablesEv */

	void ComputeStaticRoutingTables(class CGraph *); /* linkage=_ZN6CGraph26ComputeStaticRoutingTablesEv */

	void TestRoutingTables(class CGraph *); /* linkage=_ZN6CGraph17TestRoutingTablesEv */

	void HashInsert(class CGraph *, int, int, int); /* linkage=_ZN6CGraph10HashInsertEiii */

	void HashSearch(class CGraph *, int, int, int &); /* linkage=_ZN6CGraph10HashSearchEiiRi */

	void HashChoosePrimes(class CGraph *, int); /* linkage=_ZN6CGraph16HashChoosePrimesEi */

	void BuildLinkLookups(class CGraph *); /* linkage=_ZN6CGraph16BuildLinkLookupsEv */

	void SortNodes(class CGraph *); /* linkage=_ZN6CGraph9SortNodesEv */

	int HullIndex(class CGraph *, const class CBaseEntity  *); /* linkage=_ZN6CGraph9HullIndexEPK11CBaseEntity */

	int NodeType(class CGraph *, const class CBaseEntity  *); /* linkage=_ZN6CGraph8NodeTypeEPK11CBaseEntity */

	int CapIndex(class CGraph *, int); /* linkage=_ZN6CGraph8CapIndexEi */

	class CNode & Node(class CGraph *, int); /* linkage=_ZN6CGraph4NodeEi */

	class CLink & Link(class CGraph *, int); /* linkage=_ZN6CGraph4LinkEi */

	class CLink & NodeLink(class CGraph *, int, int); /* linkage=_ZN6CGraph8NodeLinkEii */

	class CLink & NodeLink(class CGraph *, const class CNode  &, int); /* linkage=_ZN6CGraph8NodeLinkERK5CNodei */

	int INodeLink(class CGraph *, int, int); /* linkage=_ZN6CGraph9INodeLinkEii */


	/* size: 8396, cachelines: 132, members: 35 */
	/* last cacheline: 12 bytes */
};
class CBaseAnimating : public CBaseDelay {

	/* XXX 1148 bytes hole, try to pack */
public:


	/* class CBaseDelay          <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[5]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 60 bytes ago --- */
	float                      m_flFrameRate;        /*  1148     4 */
	/* --- cacheline 18 boundary (1152 bytes) --- */
	float                      m_flGroundSpeed;      /*  1152     4 */
	float                      m_flLastEventCheck;   /*  1156     4 */
	BOOL                       m_fSequenceFinished;  /*  1160     4 */
	BOOL                       m_fSequenceLoops;     /*  1164     4 */
	void CBaseAnimating(class CBaseAnimating *, class CBaseAnimating &); /* linkage=_ZN14CBaseAnimatingC4EOS_ */

	void CBaseAnimating(class CBaseAnimating *, const class CBaseAnimating  &); /* linkage=_ZN14CBaseAnimatingC4ERKS_ */

	void CBaseAnimating(class CBaseAnimating *); /* linkage=_ZN14CBaseAnimatingC4Ev */

	virtual int Save(class CBaseAnimating *, class CSave &); /* linkage=_ZN14CBaseAnimating4SaveER5CSave */

	virtual int Restore(class CBaseAnimating *, class CRestore &); /* linkage=_ZN14CBaseAnimating7RestoreER8CRestore */

	float StudioFrameAdvance(class CBaseAnimating *, float); /* linkage=_ZN14CBaseAnimating18StudioFrameAdvanceEf */

	BOOL GetSequenceFlags(class CBaseAnimating *); /* linkage=_ZN14CBaseAnimating16GetSequenceFlagsEv */

	int LookupActivity(class CBaseAnimating *, int); /* linkage=_ZN14CBaseAnimating14LookupActivityEi */

	int LookupActivityHeaviest(class CBaseAnimating *, int); /* linkage=_ZN14CBaseAnimating22LookupActivityHeaviestEi */

	int LookupSequence(class CBaseAnimating *, const char  *); /* linkage=_ZN14CBaseAnimating14LookupSequenceEPKc */

	void ResetSequenceInfo(class CBaseAnimating *); /* linkage=_ZN14CBaseAnimating17ResetSequenceInfoEv */

	void DispatchAnimEvents(class CBaseAnimating *, float); /* linkage=_ZN14CBaseAnimating18DispatchAnimEventsEf */

	virtual void HandleAnimEvent(class CBaseAnimating *, MonsterEvent_t *); /* linkage=_ZN14CBaseAnimating15HandleAnimEventEP14MonsterEvent_t */

	float SetBoneController(class CBaseAnimating *, int, float); /* linkage=_ZN14CBaseAnimating17SetBoneControllerEif */

	void InitBoneControllers(class CBaseAnimating *); /* linkage=_ZN14CBaseAnimating19InitBoneControllersEv */

	float SetBlending(class CBaseAnimating *, int, float); /* linkage=_ZN14CBaseAnimating11SetBlendingEif */

	void GetBonePosition(class CBaseAnimating *, int, class Vector &, class Vector &); /* linkage=_ZN14CBaseAnimating15GetBonePositionEiR6VectorS1_ */

	void GetAutomovement(class CBaseAnimating *, class Vector &, class Vector &, float); /* linkage=_ZN14CBaseAnimating15GetAutomovementER6VectorS1_f */

	int FindTransition(class CBaseAnimating *, int, int, int *); /* linkage=_ZN14CBaseAnimating14FindTransitionEiiPi */

	void GetAttachment(class CBaseAnimating *, int, class Vector &, class Vector &); /* linkage=_ZN14CBaseAnimating13GetAttachmentEiR6VectorS1_ */

	void SetBodygroup(class CBaseAnimating *, int, int); /* linkage=_ZN14CBaseAnimating12SetBodygroupEii */

	int GetBodygroup(class CBaseAnimating *, int); /* linkage=_ZN14CBaseAnimating12GetBodygroupEi */

	virtual void ~CBaseAnimating(class CBaseAnimating *, int); /* linkage=_ZN14CBaseAnimatingD4Ev */

	/* vtable has 3 entries: {
	   [5] = Save(_ZN14CBaseAnimating4SaveER5CSave), 
	   [6] = Restore(_ZN14CBaseAnimating7RestoreER8CRestore), 
	   [65] = HandleAnimEvent(_ZN14CBaseAnimating15HandleAnimEventEP14MonsterEvent_t), 
	} */
	/* size: 1168, cachelines: 19, members: 6, static members: 1 */
	/* sum members: 20, holes: 1, sum holes: 1148 */
	/* last cacheline: 16 bytes */
};
class CMortar : public CGrenade {

	/* XXX 1752 bytes hole, try to pack */
public:


	/* class CGrenade            <ancestor>; */      /*     0     0 */
	/* --- cacheline 27 boundary (1728 bytes) was 24 bytes ago --- */
	int                        m_spriteTexture;      /*  1752     4 */
	void CMortar(class CMortar *, class CMortar &); /* linkage=_ZN7CMortarC4EOS_ */

	void CMortar(class CMortar *, const class CMortar  &); /* linkage=_ZN7CMortarC4ERKS_ */

	void CMortar(class CMortar *); /* linkage=_ZN7CMortarC4Ev */

	virtual void Spawn(class CMortar *); /* linkage=_ZN7CMortar5SpawnEv */

	virtual void Precache(class CMortar *); /* linkage=_ZN7CMortar8PrecacheEv */

	void MortarExplode(class CMortar *); /* linkage=_ZN7CMortar13MortarExplodeEv */

	virtual void ~CMortar(class CMortar *, int); /* linkage=_ZN7CMortarD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN7CMortar5SpawnEv), 
	   [3] = Precache(_ZN7CMortar8PrecacheEv), 
	} */
	/* size: 1756, cachelines: 28, members: 2 */
	/* sum members: 4, holes: 1, sum holes: 1752 */
	/* last cacheline: 28 bytes */
};
class CFuncMortarField : public CBaseToggle {

	/* XXX 1300 bytes hole, try to pack */
public:


	/* class CBaseToggle         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[6]; /*     0     0 */
	/* --- cacheline 20 boundary (1280 bytes) was 20 bytes ago --- */
	int                        m_iszXController;     /*  1300     4 */
	int                        m_iszYController;     /*  1304     4 */
	float                      m_flSpread;           /*  1308     4 */
	float                      m_flDelay;            /*  1312     4 */
	int                        m_iCount;             /*  1316     4 */
	int                        m_fControl;           /*  1320     4 */
	void CFuncMortarField(class CFuncMortarField *, class CFuncMortarField &); /* linkage=_ZN16CFuncMortarFieldC4EOS_ */

	void CFuncMortarField(class CFuncMortarField *, const class CFuncMortarField  &); /* linkage=_ZN16CFuncMortarFieldC4ERKS_ */

	void CFuncMortarField(class CFuncMortarField *); /* linkage=_ZN16CFuncMortarFieldC4Ev */

	virtual void Spawn(class CFuncMortarField *); /* linkage=_ZN16CFuncMortarField5SpawnEv */

	virtual void Precache(class CFuncMortarField *); /* linkage=_ZN16CFuncMortarField8PrecacheEv */

	virtual void KeyValue(class CFuncMortarField *, KeyValueData *); /* linkage=_ZN16CFuncMortarField8KeyValueEP14KeyValueData_s */

	virtual int ObjectCaps(class CFuncMortarField *); /* linkage=_ZN16CFuncMortarField10ObjectCapsEv */

	virtual int Save(class CFuncMortarField *, class CSave &); /* linkage=_ZN16CFuncMortarField4SaveER5CSave */

	virtual int Restore(class CFuncMortarField *, class CRestore &); /* linkage=_ZN16CFuncMortarField7RestoreER8CRestore */

	void FieldUse(class CFuncMortarField *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN16CFuncMortarField8FieldUseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void ~CFuncMortarField(class CFuncMortarField *, int); /* linkage=_ZN16CFuncMortarFieldD4Ev */

	/* vtable has 6 entries: {
	   [2] = Spawn(_ZN16CFuncMortarField5SpawnEv), 
	   [3] = Precache(_ZN16CFuncMortarField8PrecacheEv), 
	   [4] = KeyValue(_ZN16CFuncMortarField8KeyValueEP14KeyValueData_s), 
	   [7] = ObjectCaps(_ZN16CFuncMortarField10ObjectCapsEv), 
	   [5] = Save(_ZN16CFuncMortarField4SaveER5CSave), 
	   [6] = Restore(_ZN16CFuncMortarField7RestoreER8CRestore), 
	} */
	/* size: 1324, cachelines: 21, members: 7, static members: 1 */
	/* sum members: 24, holes: 1, sum holes: 1300 */
	/* last cacheline: 44 bytes */
};
class CGraph {
	enum NODEQUERY {
		NODEGRAPH_DYNAMIC = 0,
		NODEGRAPH_STATIC  = 1,
	};

	BOOL                       m_fGraphPresent;      /*     0     4 */
	BOOL                       m_fGraphPointersSet;  /*     4     4 */
	BOOL                       m_fRoutingComplete;   /*     8     4 */
	class CNode *              m_pNodes;             /*    12     4 */
	class CLink *              m_pLinkPool;          /*    16     4 */
	char *                     m_pRouteInfo;         /*    20     4 */
	int                        m_cNodes;             /*    24     4 */
	int                        m_cLinks;             /*    28     4 */
	int                        m_nRouteInfo;         /*    32     4 */
	DIST_INFO *                m_di;                 /*    36     4 */
	int                        m_RangeStart[3][256]; /*    40  3072 */
	/* --- cacheline 48 boundary (3072 bytes) was 40 bytes ago --- */
	int                        m_RangeEnd[3][256];   /*  3112  3072 */
	/* --- cacheline 96 boundary (6144 bytes) was 40 bytes ago --- */
	float                      m_flShortest;         /*  6184     4 */
	int                        m_iNearest;           /*  6188     4 */
	int                        m_minX;               /*  6192     4 */
	int                        m_minY;               /*  6196     4 */
	int                        m_minZ;               /*  6200     4 */
	int                        m_maxX;               /*  6204     4 */
	/* --- cacheline 97 boundary (6208 bytes) --- */
	int                        m_maxY;               /*  6208     4 */
	int                        m_maxZ;               /*  6212     4 */
	int                        m_minBoxX;            /*  6216     4 */
	int                        m_minBoxY;            /*  6220     4 */
	int                        m_minBoxZ;            /*  6224     4 */
	int                        m_maxBoxX;            /*  6228     4 */
	int                        m_maxBoxY;            /*  6232     4 */
	int                        m_maxBoxZ;            /*  6236     4 */
	int                        m_CheckedCounter;     /*  6240     4 */
	float                      m_RegionMin[3];       /*  6244    12 */
	float                      m_RegionMax[3];       /*  6256    12 */
	CACHE_ENTRY                m_Cache[128];         /*  6268  2048 */
	/* --- cacheline 129 boundary (8256 bytes) was 60 bytes ago --- */
	int                        m_HashPrimes[16];     /*  8316    64 */
	/* --- cacheline 130 boundary (8320 bytes) was 60 bytes ago --- */
	short int *                m_pHashLinks;         /*  8380     4 */
	/* --- cacheline 131 boundary (8384 bytes) --- */
	int                        m_nHashLinks;         /*  8384     4 */
	int                        m_iLastActiveIdleSearch; /*  8388     4 */
	int                        m_iLastCoverSearch;   /*  8392     4 */
	void CGraph(class CGraph *); /* linkage=_ZN6CGraphC4Ev */

	int LinkVisibleNodes(class CGraph *, class CLink *, FILE *, int *); /* linkage=_ZN6CGraph16LinkVisibleNodesEP5CLinkP8_IO_FILEPi */

	int RejectInlineLinks(class CGraph *, class CLink *, FILE *); /* linkage=_ZN6CGraph17RejectInlineLinksEP5CLinkP8_IO_FILE */

	int FindShortestPath(class CGraph *, int *, int, int, int, int); /* linkage=_ZN6CGraph16FindShortestPathEPiiiii */

	int FindNearestNode(class CGraph *, const class Vector  &, class CBaseEntity *); /* linkage=_ZN6CGraph15FindNearestNodeERK6VectorP11CBaseEntity */

	int FindNearestNode(class CGraph *, const class Vector  &, int); /* linkage=_ZN6CGraph15FindNearestNodeERK6Vectori */

	float PathLength(class CGraph *, int, int, int, int); /* linkage=_ZN6CGraph10PathLengthEiiii */

	int NextNodeInRoute(class CGraph *, int, int, int, int); /* linkage=_ZN6CGraph15NextNodeInRouteEiiii */

	int HandleLinkEnt(class CGraph *, int, entvars_t *, int, enum NODEQUERY); /* linkage=_ZN6CGraph13HandleLinkEntEiP9entvars_siNS_9NODEQUERYE */

	entvars_t * LinkEntForLink(class CGraph *, class CLink *, class CNode *); /* linkage=_ZN6CGraph14LinkEntForLinkEP5CLinkP5CNode */

	void ShowNodeConnections(class CGraph *, int); /* linkage=_ZN6CGraph19ShowNodeConnectionsEi */

	void InitGraph(class CGraph *); /* linkage=_ZN6CGraph9InitGraphEv */

	int AllocNodes(class CGraph *); /* linkage=_ZN6CGraph10AllocNodesEv */

	int CheckNODFile(class CGraph *, char *); /* linkage=_ZN6CGraph12CheckNODFileEPc */

	int FLoadGraph(class CGraph *, char *); /* linkage=_ZN6CGraph10FLoadGraphEPc */

	int FSaveGraph(class CGraph *, char *); /* linkage=_ZN6CGraph10FSaveGraphEPc */

	int FSetGraphPointers(class CGraph *); /* linkage=_ZN6CGraph17FSetGraphPointersEv */

	void CheckNode(class CGraph *, class Vector, int); /* linkage=_ZN6CGraph9CheckNodeE6Vectori */

	void BuildRegionTables(class CGraph *); /* linkage=_ZN6CGraph17BuildRegionTablesEv */

	void ComputeStaticRoutingTables(class CGraph *); /* linkage=_ZN6CGraph26ComputeStaticRoutingTablesEv */

	void TestRoutingTables(class CGraph *); /* linkage=_ZN6CGraph17TestRoutingTablesEv */

	void HashInsert(class CGraph *, int, int, int); /* linkage=_ZN6CGraph10HashInsertEiii */

	void HashSearch(class CGraph *, int, int, int &); /* linkage=_ZN6CGraph10HashSearchEiiRi */

	void HashChoosePrimes(class CGraph *, int); /* linkage=_ZN6CGraph16HashChoosePrimesEi */

	void BuildLinkLookups(class CGraph *); /* linkage=_ZN6CGraph16BuildLinkLookupsEv */

	void SortNodes(class CGraph *); /* linkage=_ZN6CGraph9SortNodesEv */

	int HullIndex(class CGraph *, const class CBaseEntity  *); /* linkage=_ZN6CGraph9HullIndexEPK11CBaseEntity */

	int NodeType(class CGraph *, const class CBaseEntity  *); /* linkage=_ZN6CGraph8NodeTypeEPK11CBaseEntity */

	int CapIndex(class CGraph *, int); /* linkage=_ZN6CGraph8CapIndexEi */

	class CNode & Node(class CGraph *, int); /* linkage=_ZN6CGraph4NodeEi */

	class CLink & Link(class CGraph *, int); /* linkage=_ZN6CGraph4LinkEi */

	class CLink & NodeLink(class CGraph *, int, int); /* linkage=_ZN6CGraph8NodeLinkEii */

	class CLink & NodeLink(class CGraph *, const class CNode  &, int); /* linkage=_ZN6CGraph8NodeLinkERK5CNodei */

	int INodeLink(class CGraph *, int, int); /* linkage=_ZN6CGraph9INodeLinkEii */


	/* size: 8396, cachelines: 132, members: 35 */
	/* last cacheline: 12 bytes */
};
class CStack {
private:

	int                        m_stack[100];         /*     0   400 */
	/* --- cacheline 6 boundary (384 bytes) was 16 bytes ago --- */
	int                        m_level;              /*   400     4 */
	void CStack(class CStack *); /* linkage=_ZN6CStackC4Ev */

	void Push(class CStack *, int); /* linkage=_ZN6CStack4PushEi */

	int Pop(class CStack *); /* linkage=_ZN6CStack3PopEv */

	int Top(class CStack *); /* linkage=_ZN6CStack3TopEv */

	int Empty(class CStack *); /* linkage=_ZN6CStack5EmptyEv */

	int Size(class CStack *); /* linkage=_ZN6CStack4SizeEv */

	void CopyToArray(class CStack *, int *); /* linkage=_ZN6CStack11CopyToArrayEPi */


	/* size: 404, cachelines: 7, members: 2 */
	/* last cacheline: 20 bytes */
};
class CQueue {
	struct tag_QUEUE_NODE {
		int                        Id;                   /*     0     4 */
		float                      Priority;             /*     4     4 */

		/* size: 8, cachelines: 1, members: 2 */
		/* last cacheline: 8 bytes */
	};

private:

	int                        m_cSize;              /*     0     4 */
	struct tag_QUEUE_NODE      m_queue[100];         /*     4   800 */
	/* --- cacheline 12 boundary (768 bytes) was 36 bytes ago --- */
	int                        m_head;               /*   804     4 */
	int                        m_tail;               /*   808     4 */
	void CQueue(class CQueue *); /* linkage=_ZN6CQueueC4Ev */

	int Full(class CQueue *); /* linkage=_ZN6CQueue4FullEv */

	int Empty(class CQueue *); /* linkage=_ZN6CQueue5EmptyEv */

	int Size(class CQueue *); /* linkage=_ZN6CQueue4SizeEv */

	void Insert(class CQueue *, int, float); /* linkage=_ZN6CQueue6InsertEif */

	int Remove(class CQueue *, float &); /* linkage=_ZN6CQueue6RemoveERf */


	/* size: 812, cachelines: 13, members: 4 */
	/* last cacheline: 44 bytes */
};
class CQueuePriority {
	struct tag_HEAP_NODE {
		int                        Id;                   /*     0     4 */
		float                      Priority;             /*     4     4 */

		/* size: 8, cachelines: 1, members: 2 */
		/* last cacheline: 8 bytes */
	};

private:

	int                        m_cSize;              /*     0     4 */
	struct tag_HEAP_NODE       m_heap[100];          /*     4   800 */
	void CQueuePriority(class CQueuePriority *); /* linkage=_ZN14CQueuePriorityC4Ev */

	int Full(class CQueuePriority *); /* linkage=_ZN14CQueuePriority4FullEv */

	int Empty(class CQueuePriority *); /* linkage=_ZN14CQueuePriority5EmptyEv */

	int Size(class CQueuePriority *); /* linkage=_ZN14CQueuePriority4SizeEv */

	void Insert(class CQueuePriority *, int, float); /* linkage=_ZN14CQueuePriority6InsertEif */

	int Remove(class CQueuePriority *, float &); /* linkage=_ZN14CQueuePriority6RemoveERf */

	void Heap_SiftDown(class CQueuePriority *, int); /* linkage=_ZN14CQueuePriority13Heap_SiftDownEi */

	void Heap_SiftUp(class CQueuePriority *); /* linkage=_ZN14CQueuePriority11Heap_SiftUpEv */


	/* size: 804, cachelines: 13, members: 2 */
	/* last cacheline: 36 bytes */
};
struct tagNodePair {
	short int                  iSrc;                 /*     0     2 */
	short int                  iDest;                /*     2     2 */

	/* size: 4, cachelines: 1, members: 2 */
	/* last cacheline: 4 bytes */
};
class CNodeViewer : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	int                        m_iBaseNode;          /*  1140     4 */
	int                        m_iDraw;              /*  1144     4 */
	int                        m_nVisited;           /*  1148     4 */
	/* --- cacheline 18 boundary (1152 bytes) --- */
	int                        m_aFrom[128];         /*  1152   512 */
	/* --- cacheline 26 boundary (1664 bytes) --- */
	int                        m_aTo[128];           /*  1664   512 */
	/* --- cacheline 34 boundary (2176 bytes) --- */
	int                        m_iHull;              /*  2176     4 */
	int                        m_afNodeType;         /*  2180     4 */
	class Vector              m_vecColor;            /*  2184    12 */
	void CNodeViewer(class CNodeViewer *, class CNodeViewer &); /* linkage=_ZN11CNodeViewerC4EOS_ */

	void CNodeViewer(class CNodeViewer *, const class CNodeViewer  &); /* linkage=_ZN11CNodeViewerC4ERKS_ */

	void CNodeViewer(class CNodeViewer *); /* linkage=_ZN11CNodeViewerC4Ev */

	virtual void Spawn(class CNodeViewer *); /* linkage=_ZN11CNodeViewer5SpawnEv */

	void FindNodeConnections(class CNodeViewer *, int); /* linkage=_ZN11CNodeViewer19FindNodeConnectionsEi */

	void AddNode(class CNodeViewer *, int, int); /* linkage=_ZN11CNodeViewer7AddNodeEii */

	void DrawThink(class CNodeViewer *); /* linkage=_ZN11CNodeViewer9DrawThinkEv */

	virtual void ~CNodeViewer(class CNodeViewer *, int); /* linkage=_ZN11CNodeViewerD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN11CNodeViewer5SpawnEv), 
	} */
	/* size: 2196, cachelines: 35, members: 9 */
	/* sum members: 1056, holes: 1, sum holes: 1140 */
	/* last cacheline: 20 bytes */
};
class CNodeEnt : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	short int                  m_sHintType;          /*  1140     2 */
	short int                  m_sHintActivity;      /*  1142     2 */
	void CNodeEnt(class CNodeEnt *, class CNodeEnt &); /* linkage=_ZN8CNodeEntC4EOS_ */

	void CNodeEnt(class CNodeEnt *, const class CNodeEnt  &); /* linkage=_ZN8CNodeEntC4ERKS_ */

	void CNodeEnt(class CNodeEnt *); /* linkage=_ZN8CNodeEntC4Ev */

	virtual void Spawn(class CNodeEnt *); /* linkage=_ZN8CNodeEnt5SpawnEv */

	virtual void KeyValue(class CNodeEnt *, KeyValueData *); /* linkage=_ZN8CNodeEnt8KeyValueEP14KeyValueData_s */

	virtual int ObjectCaps(class CNodeEnt *); /* linkage=_ZN8CNodeEnt10ObjectCapsEv */

	virtual void ~CNodeEnt(class CNodeEnt *, int); /* linkage=_ZN8CNodeEntD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN8CNodeEnt5SpawnEv), 
	   [4] = KeyValue(_ZN8CNodeEnt8KeyValueEP14KeyValueData_s), 
	   [7] = ObjectCaps(_ZN8CNodeEnt10ObjectCapsEv), 
	} */
	/* size: 1144, cachelines: 18, members: 3 */
	/* sum members: 4, holes: 1, sum holes: 1140 */
	/* last cacheline: 56 bytes */
};
class CTestHull : public CBaseMonster {

	/* XXX 1724 bytes hole, try to pack */
public:


	/* class CBaseMonster        <ancestor>; */      /*     0     0 */
	/* --- cacheline 26 boundary (1664 bytes) was 60 bytes ago --- */
	class Vector              vecBadNodeOrigin;      /*  1724    12 */
	void CTestHull(class CTestHull *, class CTestHull &); /* linkage=_ZN9CTestHullC4EOS_ */

	void CTestHull(class CTestHull *, const class CTestHull  &); /* linkage=_ZN9CTestHullC4ERKS_ */

	void CTestHull(class CTestHull *); /* linkage=_ZN9CTestHullC4Ev */

	void Spawn(class CTestHull *, entvars_t *); /* linkage=_ZN9CTestHull5SpawnEP9entvars_s */

	virtual int ObjectCaps(class CTestHull *); /* linkage=_ZN9CTestHull10ObjectCapsEv */

	void CallBuildNodeGraph(class CTestHull *); /* linkage=_ZN9CTestHull18CallBuildNodeGraphEv */

	void BuildNodeGraph(class CTestHull *); /* linkage=_ZN9CTestHull14BuildNodeGraphEv */

	void ShowBadNode(class CTestHull *); /* linkage=_ZN9CTestHull11ShowBadNodeEv */

	void DropDelay(class CTestHull *); /* linkage=_ZN9CTestHull9DropDelayEv */

	void PathFind(class CTestHull *); /* linkage=_ZN9CTestHull8PathFindEv */

	virtual void ~CTestHull(class CTestHull *, int); /* linkage=_ZN9CTestHullD4Ev */

	/* vtable has 1 entries: {
	   [7] = ObjectCaps(_ZN9CTestHull10ObjectCapsEv), 
	} */
	/* size: 1736, cachelines: 28, members: 2 */
	/* sum members: 12, holes: 1, sum holes: 1724 */
	/* last cacheline: 8 bytes */
};
class CPathTrack : public CPointEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CPointEntity        <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[5]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	float                      m_length;             /*  1140     4 */
	string_t                   m_altName;            /*  1144     4 */
	class CPathTrack *         m_pnext;              /*  1148     4 */
	/* --- cacheline 18 boundary (1152 bytes) --- */
	class CPathTrack *         m_pprevious;          /*  1152     4 */
	class CPathTrack *         m_paltpath;           /*  1156     4 */
	void CPathTrack(class CPathTrack *, class CPathTrack &); /* linkage=_ZN10CPathTrackC4EOS_ */

	void CPathTrack(class CPathTrack *, const class CPathTrack  &); /* linkage=_ZN10CPathTrackC4ERKS_ */

	void CPathTrack(class CPathTrack *); /* linkage=_ZN10CPathTrackC4Ev */

	virtual void Spawn(class CPathTrack *); /* linkage=_ZN10CPathTrack5SpawnEv */

	virtual void Activate(class CPathTrack *); /* linkage=_ZN10CPathTrack8ActivateEv */

	virtual void KeyValue(class CPathTrack *, KeyValueData *); /* linkage=_ZN10CPathTrack8KeyValueEP14KeyValueData_s */

	void SetPrevious(class CPathTrack *, class CPathTrack *); /* linkage=_ZN10CPathTrack11SetPreviousEPS_ */

	void Link(class CPathTrack *); /* linkage=_ZN10CPathTrack4LinkEv */

	virtual void Use(class CPathTrack *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN10CPathTrack3UseEP11CBaseEntityS1_8USE_TYPEf */

	class CPathTrack * ValidPath(class CPathTrack *, class CPathTrack *, int); /* linkage=_ZN10CPathTrack9ValidPathEPS_i */

	void Project(class CPathTrack *, class CPathTrack *, class CPathTrack *, class Vector *, float); /* linkage=_ZN10CPathTrack7ProjectEPS_S0_P6Vectorf */

	class CPathTrack * Instance(edict_t *); /* linkage=_ZN10CPathTrack8InstanceEP7edict_s */

	class CPathTrack * LookAhead(class CPathTrack *, class Vector *, float, int); /* linkage=_ZN10CPathTrack9LookAheadEP6Vectorfi */

	class CPathTrack * Nearest(class CPathTrack *, class Vector); /* linkage=_ZN10CPathTrack7NearestE6Vector */

	class CPathTrack * GetNext(class CPathTrack *); /* linkage=_ZN10CPathTrack7GetNextEv */

	class CPathTrack * GetPrevious(class CPathTrack *); /* linkage=_ZN10CPathTrack11GetPreviousEv */

	virtual int Save(class CPathTrack *, class CSave &); /* linkage=_ZN10CPathTrack4SaveER5CSave */

	virtual int Restore(class CPathTrack *, class CRestore &); /* linkage=_ZN10CPathTrack7RestoreER8CRestore */

	virtual void ~CPathTrack(class CPathTrack *, int); /* linkage=_ZN10CPathTrackD4Ev */

	/* vtable has 6 entries: {
	   [2] = Spawn(_ZN10CPathTrack5SpawnEv), 
	   [8] = Activate(_ZN10CPathTrack8ActivateEv), 
	   [4] = KeyValue(_ZN10CPathTrack8KeyValueEP14KeyValueData_s), 
	   [45] = Use(_ZN10CPathTrack3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [5] = Save(_ZN10CPathTrack4SaveER5CSave), 
	   [6] = Restore(_ZN10CPathTrack7RestoreER8CRestore), 
	} */
	/* size: 1160, cachelines: 19, members: 6, static members: 1 */
	/* sum members: 20, holes: 1, sum holes: 1140 */
	/* last cacheline: 8 bytes */
};
class CPathCorner : public CPointEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CPointEntity        <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[1]; /*     0     0 */
private:

	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	float                      m_flWait;             /*  1140     4 */
	void CPathCorner(class CPathCorner *, class CPathCorner &); /* linkage=_ZN11CPathCornerC4EOS_ */

	void CPathCorner(class CPathCorner *, const class CPathCorner  &); /* linkage=_ZN11CPathCornerC4ERKS_ */

	void CPathCorner(class CPathCorner *); /* linkage=_ZN11CPathCornerC4Ev */

	virtual void Spawn(class CPathCorner *); /* linkage=_ZN11CPathCorner5SpawnEv */

	virtual void KeyValue(class CPathCorner *, KeyValueData *); /* linkage=_ZN11CPathCorner8KeyValueEP14KeyValueData_s */

	virtual float GetDelay(class CPathCorner *); /* linkage=_ZN11CPathCorner8GetDelayEv */

	virtual int Save(class CPathCorner *, class CSave &); /* linkage=_ZN11CPathCorner4SaveER5CSave */

	virtual int Restore(class CPathCorner *, class CRestore &); /* linkage=_ZN11CPathCorner7RestoreER8CRestore */

	virtual void ~CPathCorner(class CPathCorner *, int); /* linkage=_ZN11CPathCornerD4Ev */

	/* vtable has 5 entries: {
	   [2] = Spawn(_ZN11CPathCorner5SpawnEv), 
	   [4] = KeyValue(_ZN11CPathCorner8KeyValueEP14KeyValueData_s), 
	   [25] = GetDelay(_ZN11CPathCorner8GetDelayEv), 
	   [5] = Save(_ZN11CPathCorner4SaveER5CSave), 
	   [6] = Restore(_ZN11CPathCorner7RestoreER8CRestore), 
	} */
	/* size: 1144, cachelines: 18, members: 2, static members: 1 */
	/* sum members: 4, holes: 1, sum holes: 1140 */
	/* last cacheline: 56 bytes */
};
class CPlane {
	class Vector              m_vecNormal;           /*     0    12 */
	float                      m_flDist;             /*    12     4 */
	BOOL                       m_fInitialized;       /*    16     4 */
	void CPlane(class CPlane *); /* linkage=_ZN6CPlaneC4Ev */

	void InitializePlane(class CPlane *, const class Vector  &, const class Vector  &); /* linkage=_ZN6CPlane15InitializePlaneERK6VectorS2_ */

	BOOL PointOnPlane(class CPlane *, const class Vector  &); /* linkage=_ZN6CPlane12PointOnPlaneERK6Vector */

	BOOL PointInFront(class CPlane *, const class Vector  &); /* linkage=_ZN6CPlane12PointInFrontERK6Vector */


	/* size: 20, cachelines: 1, members: 3 */
	/* last cacheline: 20 bytes */
};
class CGunTarget : public CBaseMonster {

	/* XXX 1724 bytes hole, try to pack */
public:


	/* class CBaseMonster        <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[1]; /*     0     0 */
private:

	/* --- cacheline 26 boundary (1664 bytes) was 60 bytes ago --- */
	BOOL                       m_on;                 /*  1724     4 */
	void CGunTarget(class CGunTarget *, class CGunTarget &); /* linkage=_ZN10CGunTargetC4EOS_ */

	void CGunTarget(class CGunTarget *, const class CGunTarget  &); /* linkage=_ZN10CGunTargetC4ERKS_ */

	void CGunTarget(class CGunTarget *); /* linkage=_ZN10CGunTargetC4Ev */

	virtual void Spawn(class CGunTarget *); /* linkage=_ZN10CGunTarget5SpawnEv */

	virtual void Activate(class CGunTarget *); /* linkage=_ZN10CGunTarget8ActivateEv */

	void Next(class CGunTarget *); /* linkage=_ZN10CGunTarget4NextEv */

	void Start(class CGunTarget *); /* linkage=_ZN10CGunTarget5StartEv */

	void Wait(class CGunTarget *); /* linkage=_ZN10CGunTarget4WaitEv */

	virtual void Stop(class CGunTarget *); /* linkage=_ZN10CGunTarget4StopEv */

	virtual int BloodColor(class CGunTarget *); /* linkage=_ZN10CGunTarget10BloodColorEv */

	virtual int Classify(class CGunTarget *); /* linkage=_ZN10CGunTarget8ClassifyEv */

	virtual int TakeDamage(class CGunTarget *, entvars_t *, entvars_t *, float, int); /* linkage=_ZN10CGunTarget10TakeDamageEP9entvars_sS1_fi */

	virtual void Use(class CGunTarget *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN10CGunTarget3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual class Vector BodyTarget(class CGunTarget *, const class Vector  &); /* linkage=_ZN10CGunTarget10BodyTargetERK6Vector */

	virtual int ObjectCaps(class CGunTarget *); /* linkage=_ZN10CGunTarget10ObjectCapsEv */

	virtual int Save(class CGunTarget *, class CSave &); /* linkage=_ZN10CGunTarget4SaveER5CSave */

	virtual int Restore(class CGunTarget *, class CRestore &); /* linkage=_ZN10CGunTarget7RestoreER8CRestore */

	virtual void ~CGunTarget(class CGunTarget *, int); /* linkage=_ZN10CGunTargetD4Ev */

	/* vtable has 11 entries: {
	   [2] = Spawn(_ZN10CGunTarget5SpawnEv), 
	   [8] = Activate(_ZN10CGunTarget8ActivateEv), 
	   [84] = Stop(_ZN10CGunTarget4StopEv), 
	   [16] = BloodColor(_ZN10CGunTarget10BloodColorEv), 
	   [10] = Classify(_ZN10CGunTarget8ClassifyEv), 
	   [13] = TakeDamage(_ZN10CGunTarget10TakeDamageEP9entvars_sS1_fi), 
	   [45] = Use(_ZN10CGunTarget3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [53] = BodyTarget(_ZN10CGunTarget10BodyTargetERK6Vector), 
	   [7] = ObjectCaps(_ZN10CGunTarget10ObjectCapsEv), 
	   [5] = Save(_ZN10CGunTarget4SaveER5CSave), 
	   [6] = Restore(_ZN10CGunTarget7RestoreER8CRestore), 
	} */
	/* size: 1728, cachelines: 27, members: 2, static members: 1 */
	/* sum members: 4, holes: 1, sum holes: 1724 */
};
class CFuncTrackAuto : public CFuncTrackChange {
public:

	/* class CFuncTrackChange    <ancestor>; */      /*     0  1368 */
	void CFuncTrackAuto(class CFuncTrackAuto *, class CFuncTrackAuto &); /* linkage=_ZN14CFuncTrackAutoC4EOS_ */

	void CFuncTrackAuto(class CFuncTrackAuto *, const class CFuncTrackAuto  &); /* linkage=_ZN14CFuncTrackAutoC4ERKS_ */

	void CFuncTrackAuto(class CFuncTrackAuto *); /* linkage=_ZN14CFuncTrackAutoC4Ev */

	virtual void Use(class CFuncTrackAuto *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN14CFuncTrackAuto3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void UpdateAutoTargets(class CFuncTrackAuto *, int); /* linkage=_ZN14CFuncTrackAuto17UpdateAutoTargetsEi */

	virtual void ~CFuncTrackAuto(class CFuncTrackAuto *, int); /* linkage=_ZN14CFuncTrackAutoD4Ev */

	/* vtable has 2 entries: {
	   [45] = Use(_ZN14CFuncTrackAuto3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [71] = UpdateAutoTargets(_ZN14CFuncTrackAuto17UpdateAutoTargetsEi), 
	} */
	/* size: 1368, cachelines: 22, members: 1 */
	/* last cacheline: 24 bytes */
};
class CFuncTrackChange : public CFuncPlatRot {
public:

	/* class CFuncPlatRot        <ancestor>; */      /*     0  1332 */
	static TYPEDESCRIPTION            m_SaveData[9]; /*     0     0 */
	/* --- cacheline 20 boundary (1280 bytes) was 52 bytes ago --- */
	class CPathTrack *         m_trackTop;           /*  1332     4 */
	class CPathTrack *         m_trackBottom;        /*  1336     4 */
	class CFuncTrackTrain *    m_train;              /*  1340     4 */
	/* --- cacheline 21 boundary (1344 bytes) --- */
	int                        m_trackTopName;       /*  1344     4 */
	int                        m_trackBottomName;    /*  1348     4 */
	int                        m_trainName;          /*  1352     4 */
	TRAIN_CODE                 m_code;               /*  1356     4 */
	int                        m_targetState;        /*  1360     4 */
	int                        m_use;                /*  1364     4 */
	void CFuncTrackChange(class CFuncTrackChange *, class CFuncTrackChange &); /* linkage=_ZN16CFuncTrackChangeC4EOS_ */

	void CFuncTrackChange(class CFuncTrackChange *, const class CFuncTrackChange  &); /* linkage=_ZN16CFuncTrackChangeC4ERKS_ */

	void CFuncTrackChange(class CFuncTrackChange *); /* linkage=_ZN16CFuncTrackChangeC4Ev */

	virtual void Spawn(class CFuncTrackChange *); /* linkage=_ZN16CFuncTrackChange5SpawnEv */

	virtual void Precache(class CFuncTrackChange *); /* linkage=_ZN16CFuncTrackChange8PrecacheEv */

	virtual void GoUp(class CFuncTrackChange *); /* linkage=_ZN16CFuncTrackChange4GoUpEv */

	virtual void GoDown(class CFuncTrackChange *); /* linkage=_ZN16CFuncTrackChange6GoDownEv */

	virtual void KeyValue(class CFuncTrackChange *, KeyValueData *); /* linkage=_ZN16CFuncTrackChange8KeyValueEP14KeyValueData_s */

	virtual void Use(class CFuncTrackChange *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN16CFuncTrackChange3UseEP11CBaseEntityS1_8USE_TYPEf */

	void Find(class CFuncTrackChange *); /* linkage=_ZN16CFuncTrackChange4FindEv */

	TRAIN_CODE EvaluateTrain(class CFuncTrackChange *, class CPathTrack *); /* linkage=_ZN16CFuncTrackChange13EvaluateTrainEP10CPathTrack */

	void UpdateTrain(class CFuncTrackChange *, class Vector &); /* linkage=_ZN16CFuncTrackChange11UpdateTrainER6Vector */

	virtual void HitBottom(class CFuncTrackChange *); /* linkage=_ZN16CFuncTrackChange9HitBottomEv */

	virtual void HitTop(class CFuncTrackChange *); /* linkage=_ZN16CFuncTrackChange6HitTopEv */

	virtual void Touch(class CFuncTrackChange *, class CBaseEntity *); /* linkage=_ZN16CFuncTrackChange5TouchEP11CBaseEntity */

	virtual void UpdateAutoTargets(class CFuncTrackChange *, int); /* linkage=_ZN16CFuncTrackChange17UpdateAutoTargetsEi */

	virtual BOOL IsTogglePlat(class CFuncTrackChange *); /* linkage=_ZN16CFuncTrackChange12IsTogglePlatEv */

	void DisableUse(class CFuncTrackChange *); /* linkage=_ZN16CFuncTrackChange10DisableUseEv */

	void EnableUse(class CFuncTrackChange *); /* linkage=_ZN16CFuncTrackChange9EnableUseEv */

	int UseEnabled(class CFuncTrackChange *); /* linkage=_ZN16CFuncTrackChange10UseEnabledEv */

	virtual int Save(class CFuncTrackChange *, class CSave &); /* linkage=_ZN16CFuncTrackChange4SaveER5CSave */

	virtual int Restore(class CFuncTrackChange *, class CRestore &); /* linkage=_ZN16CFuncTrackChange7RestoreER8CRestore */

	virtual void OverrideReset(class CFuncTrackChange *); /* linkage=_ZN16CFuncTrackChange13OverrideResetEv */

	virtual void ~CFuncTrackChange(class CFuncTrackChange *, int); /* linkage=_ZN16CFuncTrackChangeD4Ev */

	/* vtable has 14 entries: {
	   [2] = Spawn(_ZN16CFuncTrackChange5SpawnEv), 
	   [3] = Precache(_ZN16CFuncTrackChange8PrecacheEv), 
	   [67] = GoUp(_ZN16CFuncTrackChange4GoUpEv), 
	   [68] = GoDown(_ZN16CFuncTrackChange6GoDownEv), 
	   [4] = KeyValue(_ZN16CFuncTrackChange8KeyValueEP14KeyValueData_s), 
	   [45] = Use(_ZN16CFuncTrackChange3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [70] = HitBottom(_ZN16CFuncTrackChange9HitBottomEv), 
	   [69] = HitTop(_ZN16CFuncTrackChange6HitTopEv), 
	   [44] = Touch(_ZN16CFuncTrackChange5TouchEP11CBaseEntity), 
	   [71] = UpdateAutoTargets(_ZN16CFuncTrackChange17UpdateAutoTargetsEi), 
	   [66] = IsTogglePlat(_ZN16CFuncTrackChange12IsTogglePlatEv), 
	   [5] = Save(_ZN16CFuncTrackChange4SaveER5CSave), 
	   [6] = Restore(_ZN16CFuncTrackChange7RestoreER8CRestore), 
	   [27] = OverrideReset(_ZN16CFuncTrackChange13OverrideResetEv), 
	} */
	/* size: 1368, cachelines: 22, members: 10, static members: 1 */
	/* last cacheline: 24 bytes */
};
class CFuncPlatRot : public CFuncPlat {
public:

	/* class CFuncPlat           <ancestor>; */      /*     0  1308 */
	static TYPEDESCRIPTION            m_SaveData[2]; /*     0     0 */
	/* --- cacheline 20 boundary (1280 bytes) was 28 bytes ago --- */
	class Vector              m_end;                 /*  1308    12 */
	class Vector              m_start;               /*  1320    12 */
	void CFuncPlatRot(class CFuncPlatRot *, class CFuncPlatRot &); /* linkage=_ZN12CFuncPlatRotC4EOS_ */

	void CFuncPlatRot(class CFuncPlatRot *, const class CFuncPlatRot  &); /* linkage=_ZN12CFuncPlatRotC4ERKS_ */

	void CFuncPlatRot(class CFuncPlatRot *); /* linkage=_ZN12CFuncPlatRotC4Ev */

	virtual void Spawn(class CFuncPlatRot *); /* linkage=_ZN12CFuncPlatRot5SpawnEv */

	void SetupRotation(class CFuncPlatRot *); /* linkage=_ZN12CFuncPlatRot13SetupRotationEv */

	virtual void GoUp(class CFuncPlatRot *); /* linkage=_ZN12CFuncPlatRot4GoUpEv */

	virtual void GoDown(class CFuncPlatRot *); /* linkage=_ZN12CFuncPlatRot6GoDownEv */

	virtual void HitTop(class CFuncPlatRot *); /* linkage=_ZN12CFuncPlatRot6HitTopEv */

	virtual void HitBottom(class CFuncPlatRot *); /* linkage=_ZN12CFuncPlatRot9HitBottomEv */

	void RotMove(class CFuncPlatRot *, class Vector &, float); /* linkage=_ZN12CFuncPlatRot7RotMoveER6Vectorf */

	virtual int Save(class CFuncPlatRot *, class CSave &); /* linkage=_ZN12CFuncPlatRot4SaveER5CSave */

	virtual int Restore(class CFuncPlatRot *, class CRestore &); /* linkage=_ZN12CFuncPlatRot7RestoreER8CRestore */

	virtual void ~CFuncPlatRot(class CFuncPlatRot *, int); /* linkage=_ZN12CFuncPlatRotD4Ev */

	/* vtable has 7 entries: {
	   [2] = Spawn(_ZN12CFuncPlatRot5SpawnEv), 
	   [67] = GoUp(_ZN12CFuncPlatRot4GoUpEv), 
	   [68] = GoDown(_ZN12CFuncPlatRot6GoDownEv), 
	   [69] = HitTop(_ZN12CFuncPlatRot6HitTopEv), 
	   [70] = HitBottom(_ZN12CFuncPlatRot9HitBottomEv), 
	   [5] = Save(_ZN12CFuncPlatRot4SaveER5CSave), 
	   [6] = Restore(_ZN12CFuncPlatRot7RestoreER8CRestore), 
	} */
	/* size: 1332, cachelines: 21, members: 3, static members: 1 */
	/* last cacheline: 52 bytes */
};
class CFuncTrackTrain : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[12]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	class CPathTrack *         m_ppath;              /*  1140     4 */
	float                      m_length;             /*  1144     4 */
	float                      m_height;             /*  1148     4 */
	/* --- cacheline 18 boundary (1152 bytes) --- */
	float                      m_speed;              /*  1152     4 */
	float                      m_dir;                /*  1156     4 */
	float                      m_startSpeed;         /*  1160     4 */
	class Vector              m_controlMins;         /*  1164    12 */
	class Vector              m_controlMaxs;         /*  1176    12 */
	int                        m_soundPlaying;       /*  1188     4 */
	int                        m_sounds;             /*  1192     4 */
	float                      m_flVolume;           /*  1196     4 */
	float                      m_flBank;             /*  1200     4 */
	float                      m_oldSpeed;           /*  1204     4 */
private:

	short unsigned int         m_usAdjustPitch;      /*  1208     2 */
	void CFuncTrackTrain(class CFuncTrackTrain *, class CFuncTrackTrain &); /* linkage=_ZN15CFuncTrackTrainC4EOS_ */

	void CFuncTrackTrain(class CFuncTrackTrain *, const class CFuncTrackTrain  &); /* linkage=_ZN15CFuncTrackTrainC4ERKS_ */

	void CFuncTrackTrain(class CFuncTrackTrain *); /* linkage=_ZN15CFuncTrackTrainC4Ev */

	virtual void Spawn(class CFuncTrackTrain *); /* linkage=_ZN15CFuncTrackTrain5SpawnEv */

	virtual void Precache(class CFuncTrackTrain *); /* linkage=_ZN15CFuncTrackTrain8PrecacheEv */

	virtual void Blocked(class CFuncTrackTrain *, class CBaseEntity *); /* linkage=_ZN15CFuncTrackTrain7BlockedEP11CBaseEntity */

	virtual void Use(class CFuncTrackTrain *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN15CFuncTrackTrain3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void KeyValue(class CFuncTrackTrain *, KeyValueData *); /* linkage=_ZN15CFuncTrackTrain8KeyValueEP14KeyValueData_s */

	void Next(class CFuncTrackTrain *); /* linkage=_ZN15CFuncTrackTrain4NextEv */

	void Find(class CFuncTrackTrain *); /* linkage=_ZN15CFuncTrackTrain4FindEv */

	void NearestPath(class CFuncTrackTrain *); /* linkage=_ZN15CFuncTrackTrain11NearestPathEv */

	void DeadEnd(class CFuncTrackTrain *); /* linkage=_ZN15CFuncTrackTrain7DeadEndEv */

	void NextThink(class CFuncTrackTrain *, float, BOOL); /* linkage=_ZN15CFuncTrackTrain9NextThinkEfi */

	void SetTrack(class CFuncTrackTrain *, class CPathTrack *); /* linkage=_ZN15CFuncTrackTrain8SetTrackEP10CPathTrack */

	void SetControls(class CFuncTrackTrain *, entvars_t *); /* linkage=_ZN15CFuncTrackTrain11SetControlsEP9entvars_s */

	virtual BOOL OnControls(class CFuncTrackTrain *, entvars_t *); /* linkage=_ZN15CFuncTrackTrain10OnControlsEP9entvars_s */

	void StopSound(class CFuncTrackTrain *); /* linkage=_ZN15CFuncTrackTrain9StopSoundEv */

	void UpdateSound(class CFuncTrackTrain *); /* linkage=_ZN15CFuncTrackTrain11UpdateSoundEv */

	class CFuncTrackTrain * Instance(edict_t *); /* linkage=_ZN15CFuncTrackTrain8InstanceEP7edict_s */

	virtual int Save(class CFuncTrackTrain *, class CSave &); /* linkage=_ZN15CFuncTrackTrain4SaveER5CSave */

	virtual int Restore(class CFuncTrackTrain *, class CRestore &); /* linkage=_ZN15CFuncTrackTrain7RestoreER8CRestore */

	virtual int ObjectCaps(class CFuncTrackTrain *); /* linkage=_ZN15CFuncTrackTrain10ObjectCapsEv */

	virtual void OverrideReset(class CFuncTrackTrain *); /* linkage=_ZN15CFuncTrackTrain13OverrideResetEv */

	virtual void ~CFuncTrackTrain(class CFuncTrackTrain *, int); /* linkage=_ZN15CFuncTrackTrainD4Ev */

	/* vtable has 10 entries: {
	   [2] = Spawn(_ZN15CFuncTrackTrain5SpawnEv), 
	   [3] = Precache(_ZN15CFuncTrackTrain8PrecacheEv), 
	   [46] = Blocked(_ZN15CFuncTrackTrain7BlockedEP11CBaseEntity), 
	   [45] = Use(_ZN15CFuncTrackTrain3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [4] = KeyValue(_ZN15CFuncTrackTrain8KeyValueEP14KeyValueData_s), 
	   [32] = OnControls(_ZN15CFuncTrackTrain10OnControlsEP9entvars_s), 
	   [5] = Save(_ZN15CFuncTrackTrain4SaveER5CSave), 
	   [6] = Restore(_ZN15CFuncTrackTrain7RestoreER8CRestore), 
	   [7] = ObjectCaps(_ZN15CFuncTrackTrain10ObjectCapsEv), 
	   [27] = OverrideReset(_ZN15CFuncTrackTrain13OverrideResetEv), 
	} */
	/* size: 1212, cachelines: 19, members: 15, static members: 1 */
	/* sum members: 70, holes: 1, sum holes: 1140 */
	/* padding: 2 */
	/* last cacheline: 60 bytes */
};
class CFuncTrainControls : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CFuncTrainControls(class CFuncTrainControls *, class CFuncTrainControls &); /* linkage=_ZN18CFuncTrainControlsC4EOS_ */

	void CFuncTrainControls(class CFuncTrainControls *, const class CFuncTrainControls  &); /* linkage=_ZN18CFuncTrainControlsC4ERKS_ */

	void CFuncTrainControls(class CFuncTrainControls *); /* linkage=_ZN18CFuncTrainControlsC4Ev */

	virtual int ObjectCaps(class CFuncTrainControls *); /* linkage=_ZN18CFuncTrainControls10ObjectCapsEv */

	virtual void Spawn(class CFuncTrainControls *); /* linkage=_ZN18CFuncTrainControls5SpawnEv */

	void Find(class CFuncTrainControls *); /* linkage=_ZN18CFuncTrainControls4FindEv */

	virtual void ~CFuncTrainControls(class CFuncTrainControls *, int); /* linkage=_ZN18CFuncTrainControlsD4Ev */

	/* vtable has 2 entries: {
	   [7] = ObjectCaps(_ZN18CFuncTrainControls10ObjectCapsEv), 
	   [2] = Spawn(_ZN18CFuncTrainControls5SpawnEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CFuncTrain : public CBasePlatTrain {
public:

	/* class CBasePlatTrain      <ancestor>; */      /*     0  1308 */

	/* XXX last struct has 2 holes */

	static TYPEDESCRIPTION            m_SaveData[3]; /*     0     0 */
	/* --- cacheline 20 boundary (1280 bytes) was 28 bytes ago --- */
	entvars_t *                m_pevCurrentTarget;   /*  1308     4 */
	int                        m_sounds;             /*  1312     4 */
	BOOL                       m_activated;          /*  1316     4 */
	void CFuncTrain(class CFuncTrain *, class CFuncTrain &); /* linkage=_ZN10CFuncTrainC4EOS_ */

	void CFuncTrain(class CFuncTrain *, const class CFuncTrain  &); /* linkage=_ZN10CFuncTrainC4ERKS_ */

	void CFuncTrain(class CFuncTrain *); /* linkage=_ZN10CFuncTrainC4Ev */

	virtual void Spawn(class CFuncTrain *); /* linkage=_ZN10CFuncTrain5SpawnEv */

	virtual void Precache(class CFuncTrain *); /* linkage=_ZN10CFuncTrain8PrecacheEv */

	virtual void Activate(class CFuncTrain *); /* linkage=_ZN10CFuncTrain8ActivateEv */

	virtual void OverrideReset(class CFuncTrain *); /* linkage=_ZN10CFuncTrain13OverrideResetEv */

	virtual void Blocked(class CFuncTrain *, class CBaseEntity *); /* linkage=_ZN10CFuncTrain7BlockedEP11CBaseEntity */

	virtual void Use(class CFuncTrain *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN10CFuncTrain3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void KeyValue(class CFuncTrain *, KeyValueData *); /* linkage=_ZN10CFuncTrain8KeyValueEP14KeyValueData_s */

	void Wait(class CFuncTrain *); /* linkage=_ZN10CFuncTrain4WaitEv */

	void Next(class CFuncTrain *); /* linkage=_ZN10CFuncTrain4NextEv */

	virtual int Save(class CFuncTrain *, class CSave &); /* linkage=_ZN10CFuncTrain4SaveER5CSave */

	virtual int Restore(class CFuncTrain *, class CRestore &); /* linkage=_ZN10CFuncTrain7RestoreER8CRestore */

	virtual void ~CFuncTrain(class CFuncTrain *, int); /* linkage=_ZN10CFuncTrainD4Ev */

	/* vtable has 9 entries: {
	   [2] = Spawn(_ZN10CFuncTrain5SpawnEv), 
	   [3] = Precache(_ZN10CFuncTrain8PrecacheEv), 
	   [8] = Activate(_ZN10CFuncTrain8ActivateEv), 
	   [27] = OverrideReset(_ZN10CFuncTrain13OverrideResetEv), 
	   [46] = Blocked(_ZN10CFuncTrain7BlockedEP11CBaseEntity), 
	   [45] = Use(_ZN10CFuncTrain3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [4] = KeyValue(_ZN10CFuncTrain8KeyValueEP14KeyValueData_s), 
	   [5] = Save(_ZN10CFuncTrain4SaveER5CSave), 
	   [6] = Restore(_ZN10CFuncTrain7RestoreER8CRestore), 
	} */
	/* size: 1320, cachelines: 21, members: 4, static members: 1 */
	/* member types with holes: 1, total: 2 */
	/* last cacheline: 40 bytes */
};
class CBasePlatTrain : public CBaseToggle {

	/* XXX 1300 bytes hole, try to pack */
public:


	/* class CBaseToggle         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[3]; /*     0     0 */
	/* --- cacheline 20 boundary (1280 bytes) was 20 bytes ago --- */
	BYTE                       m_bMoveSnd;           /*  1300     1 */
	BYTE                       m_bStopSnd;           /*  1301     1 */

	/* XXX 2 bytes hole, try to pack */

	float                      m_volume;             /*  1304     4 */
	void CBasePlatTrain(class CBasePlatTrain *, class CBasePlatTrain &); /* linkage=_ZN14CBasePlatTrainC4EOS_ */

	void CBasePlatTrain(class CBasePlatTrain *, const class CBasePlatTrain  &); /* linkage=_ZN14CBasePlatTrainC4ERKS_ */

	void CBasePlatTrain(class CBasePlatTrain *); /* linkage=_ZN14CBasePlatTrainC4Ev */

	virtual int ObjectCaps(class CBasePlatTrain *); /* linkage=_ZN14CBasePlatTrain10ObjectCapsEv */

	virtual void KeyValue(class CBasePlatTrain *, KeyValueData *); /* linkage=_ZN14CBasePlatTrain8KeyValueEP14KeyValueData_s */

	virtual void Precache(class CBasePlatTrain *); /* linkage=_ZN14CBasePlatTrain8PrecacheEv */

	virtual BOOL IsTogglePlat(class CBasePlatTrain *); /* linkage=_ZN14CBasePlatTrain12IsTogglePlatEv */

	virtual int Save(class CBasePlatTrain *, class CSave &); /* linkage=_ZN14CBasePlatTrain4SaveER5CSave */

	virtual int Restore(class CBasePlatTrain *, class CRestore &); /* linkage=_ZN14CBasePlatTrain7RestoreER8CRestore */

	virtual void ~CBasePlatTrain(class CBasePlatTrain *, int); /* linkage=_ZN14CBasePlatTrainD4Ev */

	/* vtable has 6 entries: {
	   [7] = ObjectCaps(_ZN14CBasePlatTrain10ObjectCapsEv), 
	   [4] = KeyValue(_ZN14CBasePlatTrain8KeyValueEP14KeyValueData_s), 
	   [3] = Precache(_ZN14CBasePlatTrain8PrecacheEv), 
	   [66] = IsTogglePlat(_ZN14CBasePlatTrain12IsTogglePlatEv), 
	   [5] = Save(_ZN14CBasePlatTrain4SaveER5CSave), 
	   [6] = Restore(_ZN14CBasePlatTrain7RestoreER8CRestore), 
	} */
	/* size: 1308, cachelines: 21, members: 4, static members: 1 */
	/* sum members: 6, holes: 2, sum holes: 1302 */
	/* last cacheline: 28 bytes */
};
class CFuncPlat : public CBasePlatTrain {
public:

	/* class CBasePlatTrain      <ancestor>; */      /*     0  1308 */

	/* XXX last struct has 2 holes */
	void CFuncPlat(class CFuncPlat *, class CFuncPlat &); /* linkage=_ZN9CFuncPlatC4EOS_ */

	void CFuncPlat(class CFuncPlat *, const class CFuncPlat  &); /* linkage=_ZN9CFuncPlatC4ERKS_ */

	void CFuncPlat(class CFuncPlat *); /* linkage=_ZN9CFuncPlatC4Ev */

	virtual void Spawn(class CFuncPlat *); /* linkage=_ZN9CFuncPlat5SpawnEv */

	virtual void Precache(class CFuncPlat *); /* linkage=_ZN9CFuncPlat8PrecacheEv */

	void Setup(class CFuncPlat *); /* linkage=_ZN9CFuncPlat5SetupEv */

	virtual void Blocked(class CFuncPlat *, class CBaseEntity *); /* linkage=_ZN9CFuncPlat7BlockedEP11CBaseEntity */

	void PlatUse(class CFuncPlat *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN9CFuncPlat7PlatUseEP11CBaseEntityS1_8USE_TYPEf */

	void CallGoDown(class CFuncPlat *); /* linkage=_ZN9CFuncPlat10CallGoDownEv */

	void CallHitTop(class CFuncPlat *); /* linkage=_ZN9CFuncPlat10CallHitTopEv */

	void CallHitBottom(class CFuncPlat *); /* linkage=_ZN9CFuncPlat13CallHitBottomEv */

	virtual void GoUp(class CFuncPlat *); /* linkage=_ZN9CFuncPlat4GoUpEv */

	virtual void GoDown(class CFuncPlat *); /* linkage=_ZN9CFuncPlat6GoDownEv */

	virtual void HitTop(class CFuncPlat *); /* linkage=_ZN9CFuncPlat6HitTopEv */

	virtual void HitBottom(class CFuncPlat *); /* linkage=_ZN9CFuncPlat9HitBottomEv */

	virtual void ~CFuncPlat(class CFuncPlat *, int); /* linkage=_ZN9CFuncPlatD4Ev */

	/* vtable has 7 entries: {
	   [2] = Spawn(_ZN9CFuncPlat5SpawnEv), 
	   [3] = Precache(_ZN9CFuncPlat8PrecacheEv), 
	   [46] = Blocked(_ZN9CFuncPlat7BlockedEP11CBaseEntity), 
	   [67] = GoUp(_ZN9CFuncPlat4GoUpEv), 
	   [68] = GoDown(_ZN9CFuncPlat6GoDownEv), 
	   [69] = HitTop(_ZN9CFuncPlat6HitTopEv), 
	   [70] = HitBottom(_ZN9CFuncPlat9HitBottomEv), 
	} */
	/* size: 1308, cachelines: 21, members: 1 */
	/* member types with holes: 1, total: 2 */
	/* last cacheline: 28 bytes */
};
class CPlatTrigger : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	class CFuncPlat *          m_pPlatform;          /*  1140     4 */
	void CPlatTrigger(class CPlatTrigger *, class CPlatTrigger &); /* linkage=_ZN12CPlatTriggerC4EOS_ */

	void CPlatTrigger(class CPlatTrigger *, const class CPlatTrigger  &); /* linkage=_ZN12CPlatTriggerC4ERKS_ */

	void CPlatTrigger(class CPlatTrigger *); /* linkage=_ZN12CPlatTriggerC4Ev */

	virtual int ObjectCaps(class CPlatTrigger *); /* linkage=_ZN12CPlatTrigger10ObjectCapsEv */

	void SpawnInsideTrigger(class CPlatTrigger *, class CFuncPlat *); /* linkage=_ZN12CPlatTrigger18SpawnInsideTriggerEP9CFuncPlat */

	virtual void Touch(class CPlatTrigger *, class CBaseEntity *); /* linkage=_ZN12CPlatTrigger5TouchEP11CBaseEntity */

	virtual void ~CPlatTrigger(class CPlatTrigger *, int); /* linkage=_ZN12CPlatTriggerD4Ev */

	/* vtable has 2 entries: {
	   [7] = ObjectCaps(_ZN12CPlatTrigger10ObjectCapsEv), 
	   [44] = Touch(_ZN12CPlatTrigger5TouchEP11CBaseEntity), 
	} */
	/* size: 1144, cachelines: 18, members: 2 */
	/* sum members: 4, holes: 1, sum holes: 1140 */
	/* last cacheline: 56 bytes */
};
class CBasePlayer : public CBaseMonster {

	/* XXX 1724 bytes hole, try to pack */
	enum {
		MENU_STRING_BUFFER_SIZE = 512,
		SBAR_STRING_SIZE        = 128,
	};

public:


	/* class CBaseMonster        <ancestor>; */      /*     0     0 */
	/* --- cacheline 26 boundary (1664 bytes) was 60 bytes ago --- */
	class EHANDLE             m_hObserverTarget;     /*  1724     8 */
	/* --- cacheline 27 boundary (1728 bytes) was 4 bytes ago --- */
	float                      m_flNextObserverInput; /*  1732     4 */
	int                        m_iObserverWeapon;    /*  1736     4 */
	int                        m_iObserverLastMode;  /*  1740     4 */
	int                        random_seed;          /*  1744     4 */
	int                        m_iPlayerSound;       /*  1748     4 */
	int                        m_iTargetVolume;      /*  1752     4 */
	int                        m_iWeaponVolume;      /*  1756     4 */
	int                        m_iExtraSoundTypes;   /*  1760     4 */
	int                        m_iWeaponFlash;       /*  1764     4 */
	float                      m_flStopExtraSoundTime; /*  1768     4 */
	float                      m_flFlashLightTime;   /*  1772     4 */
	int                        m_iFlashBattery;      /*  1776     4 */
	int                        m_afButtonLast;       /*  1780     4 */
	int                        m_afButtonPressed;    /*  1784     4 */
	int                        m_afButtonReleased;   /*  1788     4 */
	/* --- cacheline 28 boundary (1792 bytes) --- */
	edict_t *                  m_pentSndLast;        /*  1792     4 */
	float                      m_flSndRoomtype;      /*  1796     4 */
	float                      m_flSndRange;         /*  1800     4 */
	float                      m_flFallVelocity;     /*  1804     4 */
	int                        m_rgItems[5];         /*  1808    20 */
	int                        m_fKnownItem;         /*  1828     4 */
	int                        m_fNewAmmo;           /*  1832     4 */
	unsigned int               m_afPhysicsFlags;     /*  1836     4 */
	float                      m_fNextSuicideTime;   /*  1840     4 */
	float                      m_fDontPackItemsUntil; /*  1844     4 */
	float                      m_fNextTeamOrClassChange; /*  1848     4 */
	float                      m_flTimeStepSound;    /*  1852     4 */
	/* --- cacheline 29 boundary (1856 bytes) --- */
	float                      m_flTimeWeaponIdle;   /*  1856     4 */
	float                      m_flSwimTime;         /*  1860     4 */
	float                      m_flDuckTime;         /*  1864     4 */
	float                      m_flWallJumpTime;     /*  1868     4 */
	float                      m_flSuitUpdate;       /*  1872     4 */
	int                        m_rgSuitPlayList[4];  /*  1876    16 */
	int                        m_iSuitPlayNext;      /*  1892     4 */
	int                        m_rgiSuitNoRepeat[32]; /*  1896   128 */
	/* --- cacheline 31 boundary (1984 bytes) was 40 bytes ago --- */
	float                      m_rgflSuitNoRepeatTime[32]; /*  2024   128 */
	/* --- cacheline 33 boundary (2112 bytes) was 40 bytes ago --- */
	int                        m_lastDamageAmount;   /*  2152     4 */
	float                      m_tbdPrev;            /*  2156     4 */
	float                      m_flgeigerRange;      /*  2160     4 */
	float                      m_flgeigerDelay;      /*  2164     4 */
	int                        m_igeigerRangePrev;   /*  2168     4 */
	int                        m_iStepLeft;          /*  2172     4 */
	/* --- cacheline 34 boundary (2176 bytes) --- */
	char                       m_szTextureName[13];  /*  2176    13 */
	char                       m_chTextureType;      /*  2189     1 */

	/* XXX 2 bytes hole, try to pack */

	int                        m_idrowndmg;          /*  2192     4 */
	int                        m_idrownrestored;     /*  2196     4 */
	int                        m_bitsHUDDamage;      /*  2200     4 */
	BOOL                       m_fInitHUD;           /*  2204     4 */
	BOOL                       m_fGameHUDInitialized; /*  2208     4 */
	int                        m_iTrain;             /*  2212     4 */
	BOOL                       m_fWeapon;            /*  2216     4 */
	class EHANDLE             m_pTank;               /*  2220     8 */
	float                      m_fDeadTime;          /*  2228     4 */
	BOOL                       m_fNoPlayerSound;     /*  2232     4 */
	BOOL                       m_fLongJump;          /*  2236     4 */
	/* --- cacheline 35 boundary (2240 bytes) --- */
	int                        m_iGLClip;            /*  2240     4 */
	float                      m_tSneaking;          /*  2244     4 */
	int                        m_iUpdateTime;        /*  2248     4 */
	int                        m_iClientHealth;      /*  2252     4 */
	int                        m_iClientBattery;     /*  2256     4 */
	int                        m_iHideHUD;           /*  2260     4 */
	int                        m_iClientHideHUD;     /*  2264     4 */
	int                        m_iFOV;               /*  2268     4 */
	int                        m_iClientFOV;         /*  2272     4 */
	class CBasePlayerItem *    m_rgpPlayerItems[6];  /*  2276    24 */
	class CBasePlayerItem *    m_pActiveItem;        /*  2300     4 */
	/* --- cacheline 36 boundary (2304 bytes) --- */
	class CBasePlayerItem *    m_pClientActiveItem;  /*  2304     4 */
	class CBasePlayerItem *    m_pLastItem;          /*  2308     4 */
	const char  *              m_pszLastItem;        /*  2312     4 */
	int                        m_rgAmmo[32];         /*  2316   128 */
	/* --- cacheline 38 boundary (2432 bytes) was 12 bytes ago --- */
	int                        m_rgAmmoLast[32];     /*  2444   128 */
	/* --- cacheline 40 boundary (2560 bytes) was 12 bytes ago --- */
	class Vector              m_vecAutoAim;          /*  2572    12 */
	BOOL                       m_fOnTarget;          /*  2584     4 */
	int                        m_iDeaths;            /*  2588     4 */
	int                        m_iClientDeaths;      /*  2592     4 */
	int                        m_iClientFrags;       /*  2596     4 */
	int                        m_iClientPlayerClass; /*  2600     4 */
	int                        m_iClientTeam;        /*  2604     4 */
	int                        m_iClientItems;       /*  2608     4 */
	float                      m_iRespawnFrames;     /*  2612     4 */
	int                        m_iTimeCheckAllowed;  /*  2616     4 */
	int                        m_lastx;              /*  2620     4 */
	/* --- cacheline 41 boundary (2624 bytes) --- */
	int                        m_lasty;              /*  2624     4 */
	int                        m_iConcussion;        /*  2628     4 */
	int                        m_iClientConcussion;  /*  2632     4 */
	int                        m_iConcStartVal;      /*  2636     4 */
	float                      m_flConcStartTime;    /*  2640     4 */
	float                      m_flConcDuration;     /*  2644     4 */
	int                        m_iBeingTeleported;   /*  2648     4 */
	int                        m_nCustomSprayFrames; /*  2652     4 */
	float                      m_flNextDecalTime;    /*  2656     4 */
	BOOL                       m_bDisplayedMOTD;     /*  2660     4 */
	BOOL                       m_bSentBuildingEvents; /*  2664     4 */
	char                       m_MenuStringBuffer[512]; /*  2668   512 */
	/* --- cacheline 49 boundary (3136 bytes) was 44 bytes ago --- */
	int                        m_MenuSelectionBuffer; /*  3180     4 */
	float                      m_MenuUpdateTime;     /*  3184     4 */
	char                       m_SbarString0[128];   /*  3188   128 */
	/* --- cacheline 51 boundary (3264 bytes) was 52 bytes ago --- */
	char                       m_SbarString1[128];   /*  3316   128 */
	/* --- cacheline 53 boundary (3392 bytes) was 52 bytes ago --- */
	char                       m_SbarString2[128];   /*  3444   128 */

	/* Bitfield combined with previous fields */

	static TYPEDESCRIPTION            m_playerSaveData[38]; /*     0     0 */
	/* --- cacheline 55 boundary (3520 bytes) was 52 bytes ago --- */
	char                       m_szAnimExtention[32]; /*  3572    32 */
	/* --- cacheline 56 boundary (3584 bytes) was 20 bytes ago --- */
	int                        m_iCurrentAnimationState; /*  3604     4 */
	int                        m_iCurrentAnimationSequence; /*  3608     4 */
	char                       m_szSavedAnimExtention[32]; /*  3612    32 */
	char *                     m_pszSavedWeaponModel; /*  3644     4 */
	/* --- cacheline 57 boundary (3648 bytes) --- */
	int                        m_iTeamToDisguiseAs;  /*  3648     4 */
	float                      m_DB_LastTimingTestTime; /*  3652     4 */
	int                        m_nFirstSpawn;        /*  3656     4 */
	string_t                   delayed_spawn_message; /*  3660     4 */
	int                        forced_spawn;         /*  3664     4 */
	int                        no_sentry_message;    /*  3668     4 */
	int                        no_dispenser_message; /*  3672     4 */
	int                        m_iPipebombCount;     /*  3676     4 */
	int                        m_iAmmoboxCount;      /*  3680     4 */
	int                        m_iMaxArmor;          /*  3684     4 */
	int                        no_entry_teleporter_message; /*  3688     4 */
	int                        no_exit_teleporter_message; /*  3692     4 */
	int                        m_iFadeDirection;     /*  3696     4 */
	float                      m_flFadeAmount;       /*  3700     4 */
	float                      m_flGagTime;          /*  3704     4 */
	float                      m_flLastTalkTime;     /*  3708     4 */
	/* --- cacheline 58 boundary (3712 bytes) --- */
	int                        m_cSpamPoints;        /*  3712     4 */
	float                      m_flNextSBarUpdateTime; /*  3716     4 */
	int                        m_izSBarState[7];     /*  3720    28 */
	float                      m_flStatusBarDisappearDelay; /*  3748     4 */
	class EHANDLE             m_hLastIDTarget;       /*  3752     8 */
	BOOL                       m_bUpdatedCommandMenu; /*  3760     4 */
	int                        m_iClientIsFeigning;  /*  3764     4 */
	int                        m_iClientIsDetpacking; /*  3768     4 */
	int                        m_iClientDetpackAmmo; /*  3772     4 */
	/* --- cacheline 59 boundary (3776 bytes) --- */
	int                        m_iClientBuildState;  /*  3776     4 */
	int                        m_iClientRandomPC;    /*  3780     4 */
	float                      m_flTeleporterEffectEndTime; /*  3784     4 */
	void CBasePlayer(class CBasePlayer *, const class CBasePlayer  &); /* linkage=_ZN11CBasePlayerC4ERKS_ */

	void CBasePlayer(class CBasePlayer *); /* linkage=_ZN11CBasePlayerC4Ev */

	virtual void ~CBasePlayer(class CBasePlayer *, int); /* linkage=_ZN11CBasePlayerD4Ev */

	void Observer_FindNextPlayer(class CBasePlayer *, bool); /* linkage=_ZN11CBasePlayer23Observer_FindNextPlayerEb */

	void Observer_HandleButtons(class CBasePlayer *); /* linkage=_ZN11CBasePlayer22Observer_HandleButtonsEv */

	void Observer_SetMode(class CBasePlayer *, int); /* linkage=_ZN11CBasePlayer16Observer_SetModeEi */

	void Observer_CheckTarget(class CBasePlayer *); /* linkage=_ZN11CBasePlayer20Observer_CheckTargetEv */

	void Observer_CheckProperties(class CBasePlayer *); /* linkage=_ZN11CBasePlayer24Observer_CheckPropertiesEv */

	int IsObserver(class CBasePlayer *); /* linkage=_ZN11CBasePlayer10IsObserverEv */

	virtual void Spawn(class CBasePlayer *); /* linkage=_ZN11CBasePlayer5SpawnEv */

	virtual void PainSound(class CBasePlayer *); /* linkage=_ZN11CBasePlayer9PainSoundEv */

	virtual void Jump(class CBasePlayer *); /* linkage=_ZN11CBasePlayer4JumpEv */

	virtual void Duck(class CBasePlayer *); /* linkage=_ZN11CBasePlayer4DuckEv */

	virtual void PreThink(class CBasePlayer *); /* linkage=_ZN11CBasePlayer8PreThinkEv */

	virtual void PostThink(class CBasePlayer *); /* linkage=_ZN11CBasePlayer9PostThinkEv */

	virtual int TakeHealth(class CBasePlayer *, float, int); /* linkage=_ZN11CBasePlayer10TakeHealthEfi */

	virtual void TraceAttack(class CBasePlayer *, entvars_t *, float, class Vector, class  *, int); /* linkage=_ZN11CBasePlayer11TraceAttackEP9entvars_sf6VectorP11TraceResulti */

	virtual int TakeDamage(class CBasePlayer *, entvars_t *, entvars_t *, float, int); /* linkage=_ZN11CBasePlayer10TakeDamageEP9entvars_sS1_fi */

	virtual void Killed(class CBasePlayer *, entvars_t *, entvars_t *, int); /* linkage=_ZN11CBasePlayer6KilledEP9entvars_sS1_i */

	virtual class Vector BodyTarget(class CBasePlayer *, const class Vector  &); /* linkage=_ZN11CBasePlayer10BodyTargetERK6Vector */

	virtual void StartSneaking(class CBasePlayer *); /* linkage=_ZN11CBasePlayer13StartSneakingEv */

	virtual void StopSneaking(class CBasePlayer *); /* linkage=_ZN11CBasePlayer12StopSneakingEv */

	virtual BOOL IsSneaking(class CBasePlayer *); /* linkage=_ZN11CBasePlayer10IsSneakingEv */

	virtual BOOL IsAlive(class CBasePlayer *); /* linkage=_ZN11CBasePlayer7IsAliveEv */

	virtual BOOL ShouldFadeOnDeath(class CBasePlayer *); /* linkage=_ZN11CBasePlayer17ShouldFadeOnDeathEv */

	virtual BOOL IsPlayer(class CBasePlayer *); /* linkage=_ZN11CBasePlayer8IsPlayerEv */

	virtual BOOL IsNetClient(class CBasePlayer *); /* linkage=_ZN11CBasePlayer11IsNetClientEv */

	virtual int Save(class CBasePlayer *, class CSave &); /* linkage=_ZN11CBasePlayer4SaveER5CSave */

	virtual int Restore(class CBasePlayer *, class CRestore &); /* linkage=_ZN11CBasePlayer7RestoreER8CRestore */

	void RenewItems(class CBasePlayer *); /* linkage=_ZN11CBasePlayer10RenewItemsEv */

	void PackDeadPlayerItems(class CBasePlayer *); /* linkage=_ZN11CBasePlayer19PackDeadPlayerItemsEv */

	void RemoveAllItems(class CBasePlayer *, BOOL); /* linkage=_ZN11CBasePlayer14RemoveAllItemsEi */

	BOOL SwitchWeapon(class CBasePlayer *, class CBasePlayerItem *); /* linkage=_ZN11CBasePlayer12SwitchWeaponEP15CBasePlayerItem */

	BOOL SwitchWeapon(class CBasePlayer *, const char  *); /* linkage=_ZN11CBasePlayer12SwitchWeaponEPKc */

	void UpdateClientData(class CBasePlayer *); /* linkage=_ZN11CBasePlayer16UpdateClientDataEv */

	void UpdateLowPriorityClientData(class CBasePlayer *); /* linkage=_ZN11CBasePlayer27UpdateLowPriorityClientDataEv */

	virtual int ObjectCaps(class CBasePlayer *); /* linkage=_ZN11CBasePlayer10ObjectCapsEv */

	virtual void Precache(class CBasePlayer *); /* linkage=_ZN11CBasePlayer8PrecacheEv */

	BOOL IsOnLadder(class CBasePlayer *); /* linkage=_ZN11CBasePlayer10IsOnLadderEv */

	BOOL FlashlightIsOn(class CBasePlayer *); /* linkage=_ZN11CBasePlayer14FlashlightIsOnEv */

	void FlashlightTurnOn(class CBasePlayer *); /* linkage=_ZN11CBasePlayer16FlashlightTurnOnEv */

	void FlashlightTurnOff(class CBasePlayer *); /* linkage=_ZN11CBasePlayer17FlashlightTurnOffEv */

	void UpdatePlayerSound(class CBasePlayer *); /* linkage=_ZN11CBasePlayer17UpdatePlayerSoundEv */

	virtual void DeathSound(class CBasePlayer *); /* linkage=_ZN11CBasePlayer10DeathSoundEv */

	virtual int Classify(class CBasePlayer *); /* linkage=_ZN11CBasePlayer8ClassifyEv */

	void SetAnimation(class CBasePlayer *, PLAYER_ANIM); /* linkage=_ZN11CBasePlayer12SetAnimationE11PLAYER_ANIM */

	void SetWeaponAnimType(class CBasePlayer *, const char  *); /* linkage=_ZN11CBasePlayer17SetWeaponAnimTypeEPKc */

	virtual void ImpulseCommands(class CBasePlayer *); /* linkage=_ZN11CBasePlayer15ImpulseCommandsEv */

	void CheatImpulseCommands(class CBasePlayer *, int); /* linkage=_ZN11CBasePlayer20CheatImpulseCommandsEi */

	void StartDeathCam(class CBasePlayer *); /* linkage=_ZN11CBasePlayer13StartDeathCamEv */

	void StartObserver(class CBasePlayer *, class Vector, class Vector); /* linkage=_ZN11CBasePlayer13StartObserverE6VectorS0_ */

	virtual int AddPlayerItem(class CBasePlayer *, class CBasePlayerItem *); /* linkage=_ZN11CBasePlayer13AddPlayerItemEP15CBasePlayerItem */

	virtual int RemovePlayerItem(class CBasePlayer *, class CBasePlayerItem *); /* linkage=_ZN11CBasePlayer16RemovePlayerItemEP15CBasePlayerItem */

	void DropPlayerItem(class CBasePlayer *, char *); /* linkage=_ZN11CBasePlayer14DropPlayerItemEPc */

	BOOL HasPlayerItem(class CBasePlayer *, class CBasePlayerItem *); /* linkage=_ZN11CBasePlayer13HasPlayerItemEP15CBasePlayerItem */

	BOOL HasNamedPlayerItem(class CBasePlayer *, char *); /* linkage=_ZN11CBasePlayer18HasNamedPlayerItemEPc */

	BOOL HasWeapons(class CBasePlayer *); /* linkage=_ZN11CBasePlayer10HasWeaponsEv */

	void SelectPrevItem(class CBasePlayer *, int); /* linkage=_ZN11CBasePlayer14SelectPrevItemEi */

	void SelectNextItem(class CBasePlayer *, int); /* linkage=_ZN11CBasePlayer14SelectNextItemEi */

	void SelectLastItem(class CBasePlayer *); /* linkage=_ZN11CBasePlayer14SelectLastItemEv */

	void SelectItem(class CBasePlayer *, const char  *); /* linkage=_ZN11CBasePlayer10SelectItemEPKc */

	void ItemPreFrame(class CBasePlayer *); /* linkage=_ZN11CBasePlayer12ItemPreFrameEv */

	void ItemPostFrame(class CBasePlayer *); /* linkage=_ZN11CBasePlayer13ItemPostFrameEv */

	void GiveNamedItem(class CBasePlayer *, char *); /* linkage=_ZN11CBasePlayer13GiveNamedItemEPc */

	void EnableControl(class CBasePlayer *, BOOL); /* linkage=_ZN11CBasePlayer13EnableControlEi */

	virtual int GiveAmmo(class CBasePlayer *, int, char *, int, int *); /* linkage=_ZN11CBasePlayer8GiveAmmoEiPciPi */

	BOOL GiveTFAmmo(class CBasePlayer *, int, int, int, int); /* linkage=_ZN11CBasePlayer10GiveTFAmmoEiiii */

	void SendAmmoUpdate(class CBasePlayer *); /* linkage=_ZN11CBasePlayer14SendAmmoUpdateEv */

	void WaterMove(class CBasePlayer *); /* linkage=_ZN11CBasePlayer9WaterMoveEv */

	void PlayerDeathThink(class CBasePlayer *); /* linkage=_ZN11CBasePlayer16PlayerDeathThinkEv */

	void PlayerUse(class CBasePlayer *); /* linkage=_ZN11CBasePlayer9PlayerUseEv */

	void CheckSuitUpdate(class CBasePlayer *); /* linkage=_ZN11CBasePlayer15CheckSuitUpdateEv */

	void SetSuitUpdate(class CBasePlayer *, char *, int, int); /* linkage=_ZN11CBasePlayer13SetSuitUpdateEPcii */

	void UpdateGeigerCounter(class CBasePlayer *); /* linkage=_ZN11CBasePlayer19UpdateGeigerCounterEv */

	void CheckTimeBasedDamage(class CBasePlayer *); /* linkage=_ZN11CBasePlayer20CheckTimeBasedDamageEv */

	void UpdateStepSound(class CBasePlayer *); /* linkage=_ZN11CBasePlayer15UpdateStepSoundEv */

	void PlayStepSound(class CBasePlayer *, int, float); /* linkage=_ZN11CBasePlayer13PlayStepSoundEif */

	virtual BOOL FBecomeProne(class CBasePlayer *); /* linkage=_ZN11CBasePlayer12FBecomeProneEv */

	virtual void BarnacleVictimBitten(class CBasePlayer *, entvars_t *); /* linkage=_ZN11CBasePlayer20BarnacleVictimBittenEP9entvars_s */

	virtual void BarnacleVictimReleased(class CBasePlayer *); /* linkage=_ZN11CBasePlayer22BarnacleVictimReleasedEv */

	int GetAmmoIndex(const char  *); /* linkage=_ZN11CBasePlayer12GetAmmoIndexEPKc */

	int AmmoInventory(class CBasePlayer *, int); /* linkage=_ZN11CBasePlayer13AmmoInventoryEi */

	virtual int Illumination(class CBasePlayer *); /* linkage=_ZN11CBasePlayer12IlluminationEv */

	void Spy_DisguiseExternalWeaponModel(class CBasePlayer *); /* linkage=_ZN11CBasePlayer31Spy_DisguiseExternalWeaponModelEv */

	void Spy_ResetExternalWeaponModel(class CBasePlayer *); /* linkage=_ZN11CBasePlayer28Spy_ResetExternalWeaponModelEv */

	void ResetAutoaim(class CBasePlayer *); /* linkage=_ZN11CBasePlayer12ResetAutoaimEv */

	class Vector GetAutoaimVector(class CBasePlayer *, float); /* linkage=_ZN11CBasePlayer16GetAutoaimVectorEf */

	class Vector AutoaimDeflection(class CBasePlayer *, class Vector &, float, float); /* linkage=_ZN11CBasePlayer17AutoaimDeflectionER6Vectorff */

	void ForceClientDllUpdate(class CBasePlayer *); /* linkage=_ZN11CBasePlayer20ForceClientDllUpdateEv */

	void DeathMessage(class CBasePlayer *, entvars_t *); /* linkage=_ZN11CBasePlayer12DeathMessageEP9entvars_s */

	void SetCustomDecalFrames(class CBasePlayer *, int); /* linkage=_ZN11CBasePlayer20SetCustomDecalFramesEi */

	int GetCustomDecalFrames(class CBasePlayer *); /* linkage=_ZN11CBasePlayer20GetCustomDecalFramesEv */

	void CheckPowerups(class CBasePlayer *); /* linkage=_ZN11CBasePlayer13CheckPowerupsEv */

	void PlayerTouch(class CBasePlayer *, class CBaseEntity *); /* linkage=_ZN11CBasePlayer11PlayerTouchEP11CBaseEntity */

	void UpdateClientCommandMenu(class CBasePlayer *); /* linkage=_ZN11CBasePlayer23UpdateClientCommandMenuEv */

	BOOL PositionAvailable(class CBasePlayer *); /* linkage=_ZN11CBasePlayer17PositionAvailableEv */

	BOOL CantChange(class CBasePlayer *, int, BOOL); /* linkage=_ZN11CBasePlayer10CantChangeEii */

	void ChangeClass(class CBasePlayer *, int); /* linkage=_ZN11CBasePlayer11ChangeClassEi */

	void TeamFortress_SetEquipment(class CBasePlayer *); /* linkage=_ZN11CBasePlayer25TeamFortress_SetEquipmentEv */

	void SetLastWeapon(class CBasePlayer *); /* linkage=_ZN11CBasePlayer13SetLastWeaponEv */

	void TeamFortress_SetHealth(class CBasePlayer *); /* linkage=_ZN11CBasePlayer22TeamFortress_SetHealthEv */

	void TeamFortress_SetSpeed(class CBasePlayer *); /* linkage=_ZN11CBasePlayer21TeamFortress_SetSpeedEv */

	void TeamFortress_SetSkin(class CBasePlayer *); /* linkage=_ZN11CBasePlayer20TeamFortress_SetSkinEv */

	void TeamFortress_InitStatusBar(class CBasePlayer *); /* linkage=_ZN11CBasePlayer26TeamFortress_InitStatusBarEv */

	void TeamFortress_UpdateStatusBar(class CBasePlayer *); /* linkage=_ZN11CBasePlayer28TeamFortress_UpdateStatusBarEv */

	class CBaseEntity * GetTeleporter(class CBasePlayer *, int); /* linkage=_ZN11CBasePlayer13GetTeleporterEi */

	BOOL IsLegalClass(class CBasePlayer *, int); /* linkage=_ZN11CBasePlayer12IsLegalClassEi */

	void TeamFortress_DisplayLegalClasses(class CBasePlayer *); /* linkage=_ZN11CBasePlayer32TeamFortress_DisplayLegalClassesEv */

	void TeamFortress_PrintClassName(class CBasePlayer *, int); /* linkage=_ZN11CBasePlayer27TeamFortress_PrintClassNameEi */

	BOOL TeamFortress_TeamPutPlayerInTeam(class CBasePlayer *); /* linkage=_ZN11CBasePlayer32TeamFortress_TeamPutPlayerInTeamEv */

	BOOL TeamFortress_TeamSet(class CBasePlayer *, int); /* linkage=_ZN11CBasePlayer20TeamFortress_TeamSetEi */

	void TeamFortress_ExecClassScript(class CBasePlayer *); /* linkage=_ZN11CBasePlayer28TeamFortress_ExecClassScriptEv */

	void TeamFortress_ExecMapScript(class CBasePlayer *); /* linkage=_ZN11CBasePlayer26TeamFortress_ExecMapScriptEv */

	void TeamFortress_TeamShowMemberClasses(class CBasePlayer *); /* linkage=_ZN11CBasePlayer34TeamFortress_TeamShowMemberClassesEv */

	virtual void TeamFortress_CalcEMPDmgRad(class CBasePlayer *, float &, float &); /* linkage=_ZN11CBasePlayer26TeamFortress_CalcEMPDmgRadERfS0_ */

	virtual void TeamFortress_TakeEMPBlast(class CBasePlayer *, entvars_t *); /* linkage=_ZN11CBasePlayer25TeamFortress_TakeEMPBlastEP9entvars_s */

	virtual void TeamFortress_TakeConcussionBlast(class CBasePlayer *, entvars_t *, float); /* linkage=_ZN11CBasePlayer32TeamFortress_TakeConcussionBlastEP9entvars_sf */

	virtual void TeamFortress_Concuss(class CBasePlayer *, entvars_t *); /* linkage=_ZN11CBasePlayer20TeamFortress_ConcussEP9entvars_s */

	void ExplodeOldPipebomb(class CBasePlayer *, BOOL, BOOL); /* linkage=_ZN11CBasePlayer18ExplodeOldPipebombEii */

	void RemovePipebombs(class CBasePlayer *); /* linkage=_ZN11CBasePlayer15RemovePipebombsEv */

	void Engineer_RemoveBuildings(class CBasePlayer *); /* linkage=_ZN11CBasePlayer24Engineer_RemoveBuildingsEv */

	void TeamFortress_RemoveBuildings(class CBasePlayer *); /* linkage=_ZN11CBasePlayer28TeamFortress_RemoveBuildingsEv */

	void Ignite(class CBasePlayer *, entvars_t *, entvars_t *); /* linkage=_ZN11CBasePlayer6IgniteEP9entvars_sS1_ */

	void TF_AddFrags(class CBasePlayer *, int); /* linkage=_ZN11CBasePlayer11TF_AddFragsEi */

	void ResetMenu(class CBasePlayer *); /* linkage=_ZN11CBasePlayer9ResetMenuEv */

	void Player_Menu(class CBasePlayer *); /* linkage=_ZN11CBasePlayer11Player_MenuEv */

	void Menu_MapBriefing(class CBasePlayer *); /* linkage=_ZN11CBasePlayer16Menu_MapBriefingEv */

	void Menu_Team(class CBasePlayer *); /* linkage=_ZN11CBasePlayer9Menu_TeamEv */

	void Menu_Class(class CBasePlayer *); /* linkage=_ZN11CBasePlayer10Menu_ClassEv */

	void Menu_RepeatHelp(class CBasePlayer *); /* linkage=_ZN11CBasePlayer15Menu_RepeatHelpEv */

	void Menu_DoBindings_Input(class CBasePlayer *, float); /* linkage=_ZN11CBasePlayer21Menu_DoBindings_InputEf */

	void Menu_Input(class CBasePlayer *, float); /* linkage=_ZN11CBasePlayer10Menu_InputEf */

	void Menu_Intro(class CBasePlayer *); /* linkage=_ZN11CBasePlayer10Menu_IntroEv */

	void Menu_ClassHelp(class CBasePlayer *); /* linkage=_ZN11CBasePlayer14Menu_ClassHelpEv */

	void Menu_ClassHelp_Input(class CBasePlayer *, float); /* linkage=_ZN11CBasePlayer20Menu_ClassHelp_InputEf */

	void Menu_Spy(class CBasePlayer *); /* linkage=_ZN11CBasePlayer8Menu_SpyEv */

	void Menu_Spy_Input(class CBasePlayer *, float); /* linkage=_ZN11CBasePlayer14Menu_Spy_InputEf */

	void Menu_Spy_Skin(class CBasePlayer *); /* linkage=_ZN11CBasePlayer13Menu_Spy_SkinEv */

	void Menu_Spy_Skin_Input(class CBasePlayer *, float); /* linkage=_ZN11CBasePlayer19Menu_Spy_Skin_InputEf */

	void Menu_Spy_Color(class CBasePlayer *); /* linkage=_ZN11CBasePlayer14Menu_Spy_ColorEv */

	void Menu_Spy_Color_Input(class CBasePlayer *, float); /* linkage=_ZN11CBasePlayer20Menu_Spy_Color_InputEf */

	void Menu_Engineer(class CBasePlayer *); /* linkage=_ZN11CBasePlayer13Menu_EngineerEv */

	void Menu_Engineer_Input(class CBasePlayer *, float); /* linkage=_ZN11CBasePlayer19Menu_Engineer_InputEf */

	void Menu_EngineerFix_Dispenser(class CBasePlayer *); /* linkage=_ZN11CBasePlayer26Menu_EngineerFix_DispenserEv */

	void Menu_EngineerFix_Dispenser_Input(class CBasePlayer *, float); /* linkage=_ZN11CBasePlayer32Menu_EngineerFix_Dispenser_InputEf */

	void Menu_EngineerFix_SentryGun(class CBasePlayer *); /* linkage=_ZN11CBasePlayer26Menu_EngineerFix_SentryGunEv */

	void Menu_EngineerFix_SentryGun_Input(class CBasePlayer *, float); /* linkage=_ZN11CBasePlayer32Menu_EngineerFix_SentryGun_InputEf */

	void Menu_EngineerFix_Mortar(class CBasePlayer *); /* linkage=_ZN11CBasePlayer23Menu_EngineerFix_MortarEv */

	void Menu_EngineerFix_Mortar_Input(class CBasePlayer *, float); /* linkage=_ZN11CBasePlayer29Menu_EngineerFix_Mortar_InputEf */

	void Menu_Dispenser(class CBasePlayer *); /* linkage=_ZN11CBasePlayer14Menu_DispenserEv */

	void Menu_Dispenser_Input(class CBasePlayer *, float); /* linkage=_ZN11CBasePlayer20Menu_Dispenser_InputEf */

	void CleanupOnPlayerDisconnection(class CBasePlayer *); /* linkage=_ZN11CBasePlayer28CleanupOnPlayerDisconnectionEv */

	void TeamFortress_RemoveTimers(class CBasePlayer *); /* linkage=_ZN11CBasePlayer25TeamFortress_RemoveTimersEv */

	void TeamFortress_SetupRespawn(class CBasePlayer *, BOOL); /* linkage=_ZN11CBasePlayer25TeamFortress_SetupRespawnEi */

	void TeamFortress_CheckClassStats(class CBasePlayer *); /* linkage=_ZN11CBasePlayer28TeamFortress_CheckClassStatsEv */

	void TeamFortress_PrimeGrenade(class CBasePlayer *, int); /* linkage=_ZN11CBasePlayer25TeamFortress_PrimeGrenadeEi */

	void TeamFortress_ThrowPrimedGrenade(class CBasePlayer *); /* linkage=_ZN11CBasePlayer31TeamFortress_ThrowPrimedGrenadeEv */

	void TeamFortress_SetDetpack(class CBasePlayer *, int); /* linkage=_ZN11CBasePlayer23TeamFortress_SetDetpackEi */

	void TeamFortress_DetpackStop(class CBasePlayer *); /* linkage=_ZN11CBasePlayer24TeamFortress_DetpackStopEv */

	BOOL TeamFortress_RemoveDetpacks(class CBasePlayer *); /* linkage=_ZN11CBasePlayer27TeamFortress_RemoveDetpacksEv */

	void TeamFortress_RemoveLiveGrenades(class CBasePlayer *); /* linkage=_ZN11CBasePlayer31TeamFortress_RemoveLiveGrenadesEv */

	void TeamFortress_RemoveRockets(class CBasePlayer *); /* linkage=_ZN11CBasePlayer26TeamFortress_RemoveRocketsEv */

	void RemoveOwnedEnt(class CBasePlayer *, char *); /* linkage=_ZN11CBasePlayer14RemoveOwnedEntEPc */

	void TeamFortress_EngineerBuild(class CBasePlayer *, int); /* linkage=_ZN11CBasePlayer26TeamFortress_EngineerBuildEi */

	void TeamFortress_Build(class CBasePlayer *, int); /* linkage=_ZN11CBasePlayer18TeamFortress_BuildEi */

	void Spy_RemoveDisguise(class CBasePlayer *); /* linkage=_ZN11CBasePlayer18Spy_RemoveDisguiseEv */

	void TeamFortress_SpyFeignDeath(class CBasePlayer *, BOOL); /* linkage=_ZN11CBasePlayer26TeamFortress_SpyFeignDeathEi */

	void ForceRespawn(class CBasePlayer *); /* linkage=_ZN11CBasePlayer12ForceRespawnEv */

	void DropGoalItems(class CBasePlayer *); /* linkage=_ZN11CBasePlayer13DropGoalItemsEv */

	void UseSpecialSkill(class CBasePlayer *); /* linkage=_ZN11CBasePlayer15UseSpecialSkillEv */

	void ClientHearVox(class CBasePlayer *, const char  *); /* linkage=_ZN11CBasePlayer13ClientHearVoxEPKc */

	void ConnectDuringBattle(class CBasePlayer *); /* linkage=_ZN11CBasePlayer19ConnectDuringBattleEv */

	void CreateBattleID(class CBasePlayer *); /* linkage=_ZN11CBasePlayer14CreateBattleIDEv */

	void CreateGhost(class CBasePlayer *); /* linkage=_ZN11CBasePlayer11CreateGhostEv */

	BOOL CanFeign(class CBasePlayer *); /* linkage=_ZN11CBasePlayer8CanFeignEv */

	void TeamFortress_SpyGoUndercover(class CBasePlayer *); /* linkage=_ZN11CBasePlayer28TeamFortress_SpyGoUndercoverEv */

	void TeamFortress_SpyCalcName(class CBasePlayer *); /* linkage=_ZN11CBasePlayer24TeamFortress_SpyCalcNameEv */

	void TeamFortress_SpyChangeColor(class CBasePlayer *, int); /* linkage=_ZN11CBasePlayer27TeamFortress_SpyChangeColorEi */

	void TeamFortress_SpyChangeSkin(class CBasePlayer *, int); /* linkage=_ZN11CBasePlayer26TeamFortress_SpyChangeSkinEi */

	void TeamFortress_SpyDisguiseEnemy(class CBasePlayer *, BOOL, int); /* linkage=_ZN11CBasePlayer29TeamFortress_SpyDisguiseEnemyEii */

	void TeamFortress_SpyDisguise(class CBasePlayer *, int, int); /* linkage=_ZN11CBasePlayer24TeamFortress_SpyDisguiseEii */

	void CheckUncoveringSpies(class CBasePlayer *, class CBasePlayer *); /* linkage=_ZN11CBasePlayer20CheckUncoveringSpiesEPS_ */

	virtual BOOL EngineerUse(class CBasePlayer *, class CBasePlayer *); /* linkage=_ZN11CBasePlayer11EngineerUseEPS_ */

	void TeamFortress_Discard(class CBasePlayer *); /* linkage=_ZN11CBasePlayer20TeamFortress_DiscardEv */

	void RemoveOldAmmobox(class CBasePlayer *); /* linkage=_ZN11CBasePlayer16RemoveOldAmmoboxEv */

	void TeamFortress_SaveMe(class CBasePlayer *); /* linkage=_ZN11CBasePlayer19TeamFortress_SaveMeEv */

	void TeamFortress_DisplayDetectionItems(class CBasePlayer *); /* linkage=_ZN11CBasePlayer34TeamFortress_DisplayDetectionItemsEv */

	void DisplayLocalItemStatus(class CBasePlayer *, class CBaseEntity *); /* linkage=_ZN11CBasePlayer22DisplayLocalItemStatusEP11CBaseEntity */

	void AdminAccess(class CBasePlayer *, char *); /* linkage=_ZN11CBasePlayer11AdminAccessEPc */

	void Admin_CountPlayers(class CBasePlayer *); /* linkage=_ZN11CBasePlayer18Admin_CountPlayersEv */

	void Admin_ListIPs(class CBasePlayer *); /* linkage=_ZN11CBasePlayer13Admin_ListIPsEv */

	void Admin_CycleDeal(class CBasePlayer *); /* linkage=_ZN11CBasePlayer15Admin_CycleDealEv */

	void Admin_DoKick(class CBasePlayer *); /* linkage=_ZN11CBasePlayer12Admin_DoKickEv */

	void Admin_DoBan(class CBasePlayer *); /* linkage=_ZN11CBasePlayer11Admin_DoBanEv */

	void CheckAutoKick(class CBasePlayer *); /* linkage=_ZN11CBasePlayer13CheckAutoKickEv */

	void Admin_Changelevel(class CBasePlayer *); /* linkage=_ZN11CBasePlayer17Admin_ChangelevelEv */

	void TeleporterEffectThink(class CBasePlayer *); /* linkage=_ZN11CBasePlayer21TeleporterEffectThinkEv */

	const char  * DB_GetPlayerClassName(class CBasePlayer *); /* linkage=_ZN11CBasePlayer21DB_GetPlayerClassNameEv */

	/* vtable has 37 entries: {
	   [2] = Spawn(_ZN11CBasePlayer5SpawnEv), 
	   [132] = PainSound(_ZN11CBasePlayer9PainSoundEv), 
	   [134] = Jump(_ZN11CBasePlayer4JumpEv), 
	   [135] = Duck(_ZN11CBasePlayer4DuckEv), 
	   [136] = PreThink(_ZN11CBasePlayer8PreThinkEv), 
	   [137] = PostThink(_ZN11CBasePlayer9PostThinkEv), 
	   [14] = TakeHealth(_ZN11CBasePlayer10TakeHealthEfi), 
	   [12] = TraceAttack(_ZN11CBasePlayer11TraceAttackEP9entvars_sf6VectorP11TraceResulti), 
	   [13] = TakeDamage(_ZN11CBasePlayer10TakeDamageEP9entvars_sS1_fi), 
	   [15] = Killed(_ZN11CBasePlayer6KilledEP9entvars_sS1_i), 
	   [53] = BodyTarget(_ZN11CBasePlayer10BodyTargetERK6Vector), 
	   [30] = StartSneaking(_ZN11CBasePlayer13StartSneakingEv), 
	   [31] = StopSneaking(_ZN11CBasePlayer12StopSneakingEv), 
	   [33] = IsSneaking(_ZN11CBasePlayer10IsSneakingEv), 
	   [34] = IsAlive(_ZN11CBasePlayer7IsAliveEv), 
	   [68] = ShouldFadeOnDeath(_ZN11CBasePlayer17ShouldFadeOnDeathEv), 
	   [39] = IsPlayer(_ZN11CBasePlayer8IsPlayerEv), 
	   [40] = IsNetClient(_ZN11CBasePlayer11IsNetClientEv), 
	   [5] = Save(_ZN11CBasePlayer4SaveER5CSave), 
	   [6] = Restore(_ZN11CBasePlayer7RestoreER8CRestore), 
	   [7] = ObjectCaps(_ZN11CBasePlayer10ObjectCapsEv), 
	   [3] = Precache(_ZN11CBasePlayer8PrecacheEv), 
	   [129] = DeathSound(_ZN11CBasePlayer10DeathSoundEv), 
	   [10] = Classify(_ZN11CBasePlayer8ClassifyEv), 
	   [138] = ImpulseCommands(_ZN11CBasePlayer15ImpulseCommandsEv), 
	   [22] = AddPlayerItem(_ZN11CBasePlayer13AddPlayerItemEP15CBasePlayerItem), 
	   [23] = RemovePlayerItem(_ZN11CBasePlayer16RemovePlayerItemEP15CBasePlayerItem), 
	   [24] = GiveAmmo(_ZN11CBasePlayer8GiveAmmoEiPciPi), 
	   [49] = FBecomeProne(_ZN11CBasePlayer12FBecomeProneEv), 
	   [119] = BarnacleVictimBitten(_ZN11CBasePlayer20BarnacleVictimBittenEP9entvars_s), 
	   [120] = BarnacleVictimReleased(_ZN11CBasePlayer22BarnacleVictimReleasedEv), 
	   [54] = Illumination(_ZN11CBasePlayer12IlluminationEv), 
	   [60] = TeamFortress_CalcEMPDmgRad(_ZN11CBasePlayer26TeamFortress_CalcEMPDmgRadERfS0_), 
	   [61] = TeamFortress_TakeEMPBlast(_ZN11CBasePlayer25TeamFortress_TakeEMPBlastEP9entvars_s), 
	   [63] = TeamFortress_TakeConcussionBlast(_ZN11CBasePlayer32TeamFortress_TakeConcussionBlastEP9entvars_sf), 
	   [64] = TeamFortress_Concuss(_ZN11CBasePlayer20TeamFortress_ConcussEP9entvars_s), 
	   [57] = EngineerUse(_ZN11CBasePlayer11EngineerUseEPS_), 
	} */
	/* size: 3788, cachelines: 60, members: 134, static members: 1 */
	/* sum members: 2062, holes: 2, sum holes: 1726 */
	/* last cacheline: 12 bytes */
};
class CGraph {
	enum NODEQUERY {
		NODEGRAPH_DYNAMIC = 0,
		NODEGRAPH_STATIC  = 1,
	};

	BOOL                       m_fGraphPresent;      /*     0     4 */
	BOOL                       m_fGraphPointersSet;  /*     4     4 */
	BOOL                       m_fRoutingComplete;   /*     8     4 */
	class CNode *              m_pNodes;             /*    12     4 */
	class CLink *              m_pLinkPool;          /*    16     4 */
	char *                     m_pRouteInfo;         /*    20     4 */
	int                        m_cNodes;             /*    24     4 */
	int                        m_cLinks;             /*    28     4 */
	int                        m_nRouteInfo;         /*    32     4 */
	DIST_INFO *                m_di;                 /*    36     4 */
	int                        m_RangeStart[3][256]; /*    40  3072 */
	/* --- cacheline 48 boundary (3072 bytes) was 40 bytes ago --- */
	int                        m_RangeEnd[3][256];   /*  3112  3072 */
	/* --- cacheline 96 boundary (6144 bytes) was 40 bytes ago --- */
	float                      m_flShortest;         /*  6184     4 */
	int                        m_iNearest;           /*  6188     4 */
	int                        m_minX;               /*  6192     4 */
	int                        m_minY;               /*  6196     4 */
	int                        m_minZ;               /*  6200     4 */
	int                        m_maxX;               /*  6204     4 */
	/* --- cacheline 97 boundary (6208 bytes) --- */
	int                        m_maxY;               /*  6208     4 */
	int                        m_maxZ;               /*  6212     4 */
	int                        m_minBoxX;            /*  6216     4 */
	int                        m_minBoxY;            /*  6220     4 */
	int                        m_minBoxZ;            /*  6224     4 */
	int                        m_maxBoxX;            /*  6228     4 */
	int                        m_maxBoxY;            /*  6232     4 */
	int                        m_maxBoxZ;            /*  6236     4 */
	int                        m_CheckedCounter;     /*  6240     4 */
	float                      m_RegionMin[3];       /*  6244    12 */
	float                      m_RegionMax[3];       /*  6256    12 */
	CACHE_ENTRY                m_Cache[128];         /*  6268  2048 */
	/* --- cacheline 129 boundary (8256 bytes) was 60 bytes ago --- */
	int                        m_HashPrimes[16];     /*  8316    64 */
	/* --- cacheline 130 boundary (8320 bytes) was 60 bytes ago --- */
	short int *                m_pHashLinks;         /*  8380     4 */
	/* --- cacheline 131 boundary (8384 bytes) --- */
	int                        m_nHashLinks;         /*  8384     4 */
	int                        m_iLastActiveIdleSearch; /*  8388     4 */
	int                        m_iLastCoverSearch;   /*  8392     4 */
	void CGraph(class CGraph *); /* linkage=_ZN6CGraphC4Ev */

	int LinkVisibleNodes(class CGraph *, class CLink *, FILE *, int *); /* linkage=_ZN6CGraph16LinkVisibleNodesEP5CLinkP8_IO_FILEPi */

	int RejectInlineLinks(class CGraph *, class CLink *, FILE *); /* linkage=_ZN6CGraph17RejectInlineLinksEP5CLinkP8_IO_FILE */

	int FindShortestPath(class CGraph *, int *, int, int, int, int); /* linkage=_ZN6CGraph16FindShortestPathEPiiiii */

	int FindNearestNode(class CGraph *, const class Vector  &, class CBaseEntity *); /* linkage=_ZN6CGraph15FindNearestNodeERK6VectorP11CBaseEntity */

	int FindNearestNode(class CGraph *, const class Vector  &, int); /* linkage=_ZN6CGraph15FindNearestNodeERK6Vectori */

	float PathLength(class CGraph *, int, int, int, int); /* linkage=_ZN6CGraph10PathLengthEiiii */

	int NextNodeInRoute(class CGraph *, int, int, int, int); /* linkage=_ZN6CGraph15NextNodeInRouteEiiii */

	int HandleLinkEnt(class CGraph *, int, entvars_t *, int, enum NODEQUERY); /* linkage=_ZN6CGraph13HandleLinkEntEiP9entvars_siNS_9NODEQUERYE */

	entvars_t * LinkEntForLink(class CGraph *, class CLink *, class CNode *); /* linkage=_ZN6CGraph14LinkEntForLinkEP5CLinkP5CNode */

	void ShowNodeConnections(class CGraph *, int); /* linkage=_ZN6CGraph19ShowNodeConnectionsEi */

	void InitGraph(class CGraph *); /* linkage=_ZN6CGraph9InitGraphEv */

	int AllocNodes(class CGraph *); /* linkage=_ZN6CGraph10AllocNodesEv */

	int CheckNODFile(class CGraph *, char *); /* linkage=_ZN6CGraph12CheckNODFileEPc */

	int FLoadGraph(class CGraph *, char *); /* linkage=_ZN6CGraph10FLoadGraphEPc */

	int FSaveGraph(class CGraph *, char *); /* linkage=_ZN6CGraph10FSaveGraphEPc */

	int FSetGraphPointers(class CGraph *); /* linkage=_ZN6CGraph17FSetGraphPointersEv */

	void CheckNode(class CGraph *, class Vector, int); /* linkage=_ZN6CGraph9CheckNodeE6Vectori */

	void BuildRegionTables(class CGraph *); /* linkage=_ZN6CGraph17BuildRegionTablesEv */

	void ComputeStaticRoutingTables(class CGraph *); /* linkage=_ZN6CGraph26ComputeStaticRoutingTablesEv */

	void TestRoutingTables(class CGraph *); /* linkage=_ZN6CGraph17TestRoutingTablesEv */

	void HashInsert(class CGraph *, int, int, int); /* linkage=_ZN6CGraph10HashInsertEiii */

	void HashSearch(class CGraph *, int, int, int &); /* linkage=_ZN6CGraph10HashSearchEiiRi */

	void HashChoosePrimes(class CGraph *, int); /* linkage=_ZN6CGraph16HashChoosePrimesEi */

	void BuildLinkLookups(class CGraph *); /* linkage=_ZN6CGraph16BuildLinkLookupsEv */

	void SortNodes(class CGraph *); /* linkage=_ZN6CGraph9SortNodesEv */

	int HullIndex(class CGraph *, const class CBaseEntity  *); /* linkage=_ZN6CGraph9HullIndexEPK11CBaseEntity */

	int NodeType(class CGraph *, const class CBaseEntity  *); /* linkage=_ZN6CGraph8NodeTypeEPK11CBaseEntity */

	int CapIndex(class CGraph *, int); /* linkage=_ZN6CGraph8CapIndexEi */

	class CNode & Node(class CGraph *, int); /* linkage=_ZN6CGraph4NodeEi */

	class CLink & Link(class CGraph *, int); /* linkage=_ZN6CGraph4LinkEi */

	class CLink & NodeLink(class CGraph *, int, int); /* linkage=_ZN6CGraph8NodeLinkEii */

	class CLink & NodeLink(class CGraph *, const class CNode  &, int); /* linkage=_ZN6CGraph8NodeLinkERK5CNodei */

	int INodeLink(class CGraph *, int, int); /* linkage=_ZN6CGraph9INodeLinkEii */


	/* size: 8396, cachelines: 132, members: 35 */
	/* last cacheline: 12 bytes */
};
class CInfoIntermission : public CPointEntity {
public:

	/* class CPointEntity        <ancestor>; */      /*     0     0 */
	void CInfoIntermission(class CInfoIntermission *, class CInfoIntermission &); /* linkage=_ZN17CInfoIntermissionC4EOS_ */

	void CInfoIntermission(class CInfoIntermission *, const class CInfoIntermission  &); /* linkage=_ZN17CInfoIntermissionC4ERKS_ */

	void CInfoIntermission(class CInfoIntermission *); /* linkage=_ZN17CInfoIntermissionC4Ev */

private:

	virtual void Spawn(class CInfoIntermission *); /* linkage=_ZN17CInfoIntermission5SpawnEv */

	virtual void Think(class CInfoIntermission *); /* linkage=_ZN17CInfoIntermission5ThinkEv */

	virtual void ~CInfoIntermission(class CInfoIntermission *, int); /* linkage=_ZN17CInfoIntermissionD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN17CInfoIntermission5SpawnEv), 
	   [43] = Think(_ZN17CInfoIntermission5ThinkEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CRevertSaved : public CPointEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CPointEntity        <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[2]; /*     0     0 */
private:

	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	float                      m_messageTime;        /*  1140     4 */
	float                      m_loadTime;           /*  1144     4 */
	void CRevertSaved(class CRevertSaved *, class CRevertSaved &); /* linkage=_ZN12CRevertSavedC4EOS_ */

	void CRevertSaved(class CRevertSaved *, const class CRevertSaved  &); /* linkage=_ZN12CRevertSavedC4ERKS_ */

	void CRevertSaved(class CRevertSaved *); /* linkage=_ZN12CRevertSavedC4Ev */

	virtual void Use(class CRevertSaved *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN12CRevertSaved3UseEP11CBaseEntityS1_8USE_TYPEf */

	void MessageThink(class CRevertSaved *); /* linkage=_ZN12CRevertSaved12MessageThinkEv */

	void LoadThink(class CRevertSaved *); /* linkage=_ZN12CRevertSaved9LoadThinkEv */

	virtual void KeyValue(class CRevertSaved *, KeyValueData *); /* linkage=_ZN12CRevertSaved8KeyValueEP14KeyValueData_s */

	virtual int Save(class CRevertSaved *, class CSave &); /* linkage=_ZN12CRevertSaved4SaveER5CSave */

	virtual int Restore(class CRevertSaved *, class CRestore &); /* linkage=_ZN12CRevertSaved7RestoreER8CRestore */

	float Duration(class CRevertSaved *); /* linkage=_ZN12CRevertSaved8DurationEv */

	float HoldTime(class CRevertSaved *); /* linkage=_ZN12CRevertSaved8HoldTimeEv */

	float MessageTime(class CRevertSaved *); /* linkage=_ZN12CRevertSaved11MessageTimeEv */

	float LoadTime(class CRevertSaved *); /* linkage=_ZN12CRevertSaved8LoadTimeEv */

	void SetDuration(class CRevertSaved *, float); /* linkage=_ZN12CRevertSaved11SetDurationEf */

	void SetHoldTime(class CRevertSaved *, float); /* linkage=_ZN12CRevertSaved11SetHoldTimeEf */

	void SetMessageTime(class CRevertSaved *, float); /* linkage=_ZN12CRevertSaved14SetMessageTimeEf */

	void SetLoadTime(class CRevertSaved *, float); /* linkage=_ZN12CRevertSaved11SetLoadTimeEf */

	virtual void ~CRevertSaved(class CRevertSaved *, int); /* linkage=_ZN12CRevertSavedD4Ev */

	/* vtable has 4 entries: {
	   [45] = Use(_ZN12CRevertSaved3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [4] = KeyValue(_ZN12CRevertSaved8KeyValueEP14KeyValueData_s), 
	   [5] = Save(_ZN12CRevertSaved4SaveER5CSave), 
	   [6] = Restore(_ZN12CRevertSaved7RestoreER8CRestore), 
	} */
	/* size: 1148, cachelines: 18, members: 3, static members: 1 */
	/* sum members: 8, holes: 1, sum holes: 1140 */
	/* last cacheline: 60 bytes */
};
class CStripWeapons : public CPointEntity {
public:

	/* class CPointEntity        <ancestor>; */      /*     0     0 */
	void CStripWeapons(class CStripWeapons *, class CStripWeapons &); /* linkage=_ZN13CStripWeaponsC4EOS_ */

	void CStripWeapons(class CStripWeapons *, const class CStripWeapons  &); /* linkage=_ZN13CStripWeaponsC4ERKS_ */

	void CStripWeapons(class CStripWeapons *); /* linkage=_ZN13CStripWeaponsC4Ev */

	virtual void Use(class CStripWeapons *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN13CStripWeapons3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void ~CStripWeapons(class CStripWeapons *, int); /* linkage=_ZN13CStripWeaponsD4Ev */

	/* vtable has 1 entries: {
	   [45] = Use(_ZN13CStripWeapons3UseEP11CBaseEntityS1_8USE_TYPEf), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CDeadHEV : public CBaseMonster {

	/* XXX 1724 bytes hole, try to pack */
public:


	/* class CBaseMonster        <ancestor>; */      /*     0     0 */
	/* --- cacheline 26 boundary (1664 bytes) was 60 bytes ago --- */
	int                        m_iPose;              /*  1724     4 */

	/* Bitfield combined with previous fields */

	static char *                     m_szPoses[4];  /*     0     0 */
	void CDeadHEV(class CDeadHEV *, class CDeadHEV &); /* linkage=_ZN8CDeadHEVC4EOS_ */

	void CDeadHEV(class CDeadHEV *, const class CDeadHEV  &); /* linkage=_ZN8CDeadHEVC4ERKS_ */

	void CDeadHEV(class CDeadHEV *); /* linkage=_ZN8CDeadHEVC4Ev */

	virtual void Spawn(class CDeadHEV *); /* linkage=_ZN8CDeadHEV5SpawnEv */

	virtual int Classify(class CDeadHEV *); /* linkage=_ZN8CDeadHEV8ClassifyEv */

	virtual void KeyValue(class CDeadHEV *, KeyValueData *); /* linkage=_ZN8CDeadHEV8KeyValueEP14KeyValueData_s */

	virtual void ~CDeadHEV(class CDeadHEV *, int); /* linkage=_ZN8CDeadHEVD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN8CDeadHEV5SpawnEv), 
	   [10] = Classify(_ZN8CDeadHEV8ClassifyEv), 
	   [4] = KeyValue(_ZN8CDeadHEV8KeyValueEP14KeyValueData_s), 
	} */
	/* size: 1728, cachelines: 27, members: 2, static members: 1 */
	/* sum members: 4, holes: 1, sum holes: 1724 */
};
class CSprayCan : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CSprayCan(class CSprayCan *, class CSprayCan &); /* linkage=_ZN9CSprayCanC4EOS_ */

	void CSprayCan(class CSprayCan *, const class CSprayCan  &); /* linkage=_ZN9CSprayCanC4ERKS_ */

	void CSprayCan(class CSprayCan *); /* linkage=_ZN9CSprayCanC4Ev */

	void Spawn(class CSprayCan *, entvars_t *); /* linkage=_ZN9CSprayCan5SpawnEP9entvars_s */

	virtual void Think(class CSprayCan *); /* linkage=_ZN9CSprayCan5ThinkEv */

	virtual int ObjectCaps(class CSprayCan *); /* linkage=_ZN9CSprayCan10ObjectCapsEv */

	virtual void ~CSprayCan(class CSprayCan *, int); /* linkage=_ZN9CSprayCanD4Ev */

	/* vtable has 2 entries: {
	   [43] = Think(_ZN9CSprayCan5ThinkEv), 
	   [7] = ObjectCaps(_ZN9CSprayCan10ObjectCapsEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CTFFlame : public CBaseMonster {

	/* XXX 1724 bytes hole, try to pack */
public:


	/* class CBaseMonster        <ancestor>; */      /*     0     0 */
	/* --- cacheline 26 boundary (1664 bytes) was 60 bytes ago --- */
	float                      m_flNextDamageTime;   /*  1724     4 */
	void CTFFlame(class CTFFlame *, class CTFFlame &); /* linkage=_ZN8CTFFlameC4EOS_ */

	void CTFFlame(class CTFFlame *, const class CTFFlame  &); /* linkage=_ZN8CTFFlameC4ERKS_ */

	void CTFFlame(class CTFFlame *); /* linkage=_ZN8CTFFlameC4Ev */

	virtual void Spawn(class CTFFlame *); /* linkage=_ZN8CTFFlame5SpawnEv */

	virtual void Precache(class CTFFlame *); /* linkage=_ZN8CTFFlame8PrecacheEv */

	void FlameThink(class CTFFlame *); /* linkage=_ZN8CTFFlame10FlameThinkEv */

	class CTFFlame * FlameSpawn(class CBaseEntity *, class CBaseEntity *); /* linkage=_ZN8CTFFlame10FlameSpawnEP11CBaseEntityS1_ */

	void FlameDestroy(class CTFFlame *); /* linkage=_ZN8CTFFlame12FlameDestroyEv */

	virtual void ~CTFFlame(class CTFFlame *, int); /* linkage=_ZN8CTFFlameD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN8CTFFlame5SpawnEv), 
	   [3] = Precache(_ZN8CTFFlame8PrecacheEv), 
	} */
	/* size: 1728, cachelines: 27, members: 2 */
	/* sum members: 4, holes: 1, sum holes: 1724 */
};
class CGraph {
	enum NODEQUERY {
		NODEGRAPH_DYNAMIC = 0,
		NODEGRAPH_STATIC  = 1,
	};

	BOOL                       m_fGraphPresent;      /*     0     4 */
	BOOL                       m_fGraphPointersSet;  /*     4     4 */
	BOOL                       m_fRoutingComplete;   /*     8     4 */
	class CNode *              m_pNodes;             /*    12     4 */
	class CLink *              m_pLinkPool;          /*    16     4 */
	char *                     m_pRouteInfo;         /*    20     4 */
	int                        m_cNodes;             /*    24     4 */
	int                        m_cLinks;             /*    28     4 */
	int                        m_nRouteInfo;         /*    32     4 */
	DIST_INFO *                m_di;                 /*    36     4 */
	int                        m_RangeStart[3][256]; /*    40  3072 */
	/* --- cacheline 48 boundary (3072 bytes) was 40 bytes ago --- */
	int                        m_RangeEnd[3][256];   /*  3112  3072 */
	/* --- cacheline 96 boundary (6144 bytes) was 40 bytes ago --- */
	float                      m_flShortest;         /*  6184     4 */
	int                        m_iNearest;           /*  6188     4 */
	int                        m_minX;               /*  6192     4 */
	int                        m_minY;               /*  6196     4 */
	int                        m_minZ;               /*  6200     4 */
	int                        m_maxX;               /*  6204     4 */
	/* --- cacheline 97 boundary (6208 bytes) --- */
	int                        m_maxY;               /*  6208     4 */
	int                        m_maxZ;               /*  6212     4 */
	int                        m_minBoxX;            /*  6216     4 */
	int                        m_minBoxY;            /*  6220     4 */
	int                        m_minBoxZ;            /*  6224     4 */
	int                        m_maxBoxX;            /*  6228     4 */
	int                        m_maxBoxY;            /*  6232     4 */
	int                        m_maxBoxZ;            /*  6236     4 */
	int                        m_CheckedCounter;     /*  6240     4 */
	float                      m_RegionMin[3];       /*  6244    12 */
	float                      m_RegionMax[3];       /*  6256    12 */
	CACHE_ENTRY                m_Cache[128];         /*  6268  2048 */
	/* --- cacheline 129 boundary (8256 bytes) was 60 bytes ago --- */
	int                        m_HashPrimes[16];     /*  8316    64 */
	/* --- cacheline 130 boundary (8320 bytes) was 60 bytes ago --- */
	short int *                m_pHashLinks;         /*  8380     4 */
	/* --- cacheline 131 boundary (8384 bytes) --- */
	int                        m_nHashLinks;         /*  8384     4 */
	int                        m_iLastActiveIdleSearch; /*  8388     4 */
	int                        m_iLastCoverSearch;   /*  8392     4 */
	void CGraph(class CGraph *); /* linkage=_ZN6CGraphC4Ev */

	int LinkVisibleNodes(class CGraph *, class CLink *, FILE *, int *); /* linkage=_ZN6CGraph16LinkVisibleNodesEP5CLinkP8_IO_FILEPi */

	int RejectInlineLinks(class CGraph *, class CLink *, FILE *); /* linkage=_ZN6CGraph17RejectInlineLinksEP5CLinkP8_IO_FILE */

	int FindShortestPath(class CGraph *, int *, int, int, int, int); /* linkage=_ZN6CGraph16FindShortestPathEPiiiii */

	int FindNearestNode(class CGraph *, const class Vector  &, class CBaseEntity *); /* linkage=_ZN6CGraph15FindNearestNodeERK6VectorP11CBaseEntity */

	int FindNearestNode(class CGraph *, const class Vector  &, int); /* linkage=_ZN6CGraph15FindNearestNodeERK6Vectori */

	float PathLength(class CGraph *, int, int, int, int); /* linkage=_ZN6CGraph10PathLengthEiiii */

	int NextNodeInRoute(class CGraph *, int, int, int, int); /* linkage=_ZN6CGraph15NextNodeInRouteEiiii */

	int HandleLinkEnt(class CGraph *, int, entvars_t *, int, enum NODEQUERY); /* linkage=_ZN6CGraph13HandleLinkEntEiP9entvars_siNS_9NODEQUERYE */

	entvars_t * LinkEntForLink(class CGraph *, class CLink *, class CNode *); /* linkage=_ZN6CGraph14LinkEntForLinkEP5CLinkP5CNode */

	void ShowNodeConnections(class CGraph *, int); /* linkage=_ZN6CGraph19ShowNodeConnectionsEi */

	void InitGraph(class CGraph *); /* linkage=_ZN6CGraph9InitGraphEv */

	int AllocNodes(class CGraph *); /* linkage=_ZN6CGraph10AllocNodesEv */

	int CheckNODFile(class CGraph *, char *); /* linkage=_ZN6CGraph12CheckNODFileEPc */

	int FLoadGraph(class CGraph *, char *); /* linkage=_ZN6CGraph10FLoadGraphEPc */

	int FSaveGraph(class CGraph *, char *); /* linkage=_ZN6CGraph10FSaveGraphEPc */

	int FSetGraphPointers(class CGraph *); /* linkage=_ZN6CGraph17FSetGraphPointersEv */

	void CheckNode(class CGraph *, class Vector, int); /* linkage=_ZN6CGraph9CheckNodeE6Vectori */

	void BuildRegionTables(class CGraph *); /* linkage=_ZN6CGraph17BuildRegionTablesEv */

	void ComputeStaticRoutingTables(class CGraph *); /* linkage=_ZN6CGraph26ComputeStaticRoutingTablesEv */

	void TestRoutingTables(class CGraph *); /* linkage=_ZN6CGraph17TestRoutingTablesEv */

	void HashInsert(class CGraph *, int, int, int); /* linkage=_ZN6CGraph10HashInsertEiii */

	void HashSearch(class CGraph *, int, int, int &); /* linkage=_ZN6CGraph10HashSearchEiiRi */

	void HashChoosePrimes(class CGraph *, int); /* linkage=_ZN6CGraph16HashChoosePrimesEi */

	void BuildLinkLookups(class CGraph *); /* linkage=_ZN6CGraph16BuildLinkLookupsEv */

	void SortNodes(class CGraph *); /* linkage=_ZN6CGraph9SortNodesEv */

	int HullIndex(class CGraph *, const class CBaseEntity  *); /* linkage=_ZN6CGraph9HullIndexEPK11CBaseEntity */

	int NodeType(class CGraph *, const class CBaseEntity  *); /* linkage=_ZN6CGraph8NodeTypeEPK11CBaseEntity */

	int CapIndex(class CGraph *, int); /* linkage=_ZN6CGraph8CapIndexEi */

	class CNode & Node(class CGraph *, int); /* linkage=_ZN6CGraph4NodeEi */

	class CLink & Link(class CGraph *, int); /* linkage=_ZN6CGraph4LinkEi */

	class CLink & NodeLink(class CGraph *, int, int); /* linkage=_ZN6CGraph8NodeLinkEii */

	class CLink & NodeLink(class CGraph *, const class CNode  &, int); /* linkage=_ZN6CGraph8NodeLinkERK5CNodei */

	int INodeLink(class CGraph *, int, int); /* linkage=_ZN6CGraph9INodeLinkEii */


	/* size: 8396, cachelines: 132, members: 35 */
	/* last cacheline: 12 bytes */
};
class CFurniture : public CBaseMonster {
public:

	/* class CBaseMonster        <ancestor>; */      /*     0     0 */
	void CFurniture(class CFurniture *, class CFurniture &); /* linkage=_ZN10CFurnitureC4EOS_ */

	void CFurniture(class CFurniture *, const class CFurniture  &); /* linkage=_ZN10CFurnitureC4ERKS_ */

	void CFurniture(class CFurniture *); /* linkage=_ZN10CFurnitureC4Ev */

	virtual void Spawn(class CFurniture *); /* linkage=_ZN10CFurniture5SpawnEv */

	void Die(class CFurniture *); /* linkage=_ZN10CFurniture3DieEv */

	virtual int Classify(class CFurniture *); /* linkage=_ZN10CFurniture8ClassifyEv */

	virtual int ObjectCaps(class CFurniture *); /* linkage=_ZN10CFurniture10ObjectCapsEv */

	virtual void ~CFurniture(class CFurniture *, int); /* linkage=_ZN10CFurnitureD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN10CFurniture5SpawnEv), 
	   [10] = Classify(_ZN10CFurniture8ClassifyEv), 
	   [7] = ObjectCaps(_ZN10CFurniture10ObjectCapsEv), 
	} */
	/* size: 1724, cachelines: 27, members: 1 */
	/* padding: 1724 */
	/* last cacheline: 60 bytes */
};
class CScriptedSentence : public CBaseToggle {

	/* XXX 1300 bytes hole, try to pack */
public:


	/* class CBaseToggle         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[9]; /*     0     0 */
private:

	/* --- cacheline 20 boundary (1280 bytes) was 20 bytes ago --- */
	int                        m_iszSentence;        /*  1300     4 */
	int                        m_iszEntity;          /*  1304     4 */
	float                      m_flRadius;           /*  1308     4 */
	float                      m_flDuration;         /*  1312     4 */
	float                      m_flRepeat;           /*  1316     4 */
	float                      m_flAttenuation;      /*  1320     4 */
	float                      m_flVolume;           /*  1324     4 */
	BOOL                       m_active;             /*  1328     4 */
	int                        m_iszListener;        /*  1332     4 */
	void CScriptedSentence(class CScriptedSentence *, class CScriptedSentence &); /* linkage=_ZN17CScriptedSentenceC4EOS_ */

	void CScriptedSentence(class CScriptedSentence *, const class CScriptedSentence  &); /* linkage=_ZN17CScriptedSentenceC4ERKS_ */

	void CScriptedSentence(class CScriptedSentence *); /* linkage=_ZN17CScriptedSentenceC4Ev */

	virtual void Spawn(class CScriptedSentence *); /* linkage=_ZN17CScriptedSentence5SpawnEv */

	virtual void KeyValue(class CScriptedSentence *, KeyValueData *); /* linkage=_ZN17CScriptedSentence8KeyValueEP14KeyValueData_s */

	virtual void Use(class CScriptedSentence *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN17CScriptedSentence3UseEP11CBaseEntityS1_8USE_TYPEf */

	void FindThink(class CScriptedSentence *); /* linkage=_ZN17CScriptedSentence9FindThinkEv */

	void DelayThink(class CScriptedSentence *); /* linkage=_ZN17CScriptedSentence10DelayThinkEv */

	virtual int ObjectCaps(class CScriptedSentence *); /* linkage=_ZN17CScriptedSentence10ObjectCapsEv */

	virtual int Save(class CScriptedSentence *, class CSave &); /* linkage=_ZN17CScriptedSentence4SaveER5CSave */

	virtual int Restore(class CScriptedSentence *, class CRestore &); /* linkage=_ZN17CScriptedSentence7RestoreER8CRestore */

	class CBaseMonster * FindEntity(class CScriptedSentence *); /* linkage=_ZN17CScriptedSentence10FindEntityEv */

	BOOL AcceptableSpeaker(class CScriptedSentence *, class CBaseMonster *); /* linkage=_ZN17CScriptedSentence17AcceptableSpeakerEP12CBaseMonster */

	BOOL StartSentence(class CScriptedSentence *, class CBaseMonster *); /* linkage=_ZN17CScriptedSentence13StartSentenceEP12CBaseMonster */

	virtual void ~CScriptedSentence(class CScriptedSentence *, int); /* linkage=_ZN17CScriptedSentenceD4Ev */

	/* vtable has 6 entries: {
	   [2] = Spawn(_ZN17CScriptedSentence5SpawnEv), 
	   [4] = KeyValue(_ZN17CScriptedSentence8KeyValueEP14KeyValueData_s), 
	   [45] = Use(_ZN17CScriptedSentence3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [7] = ObjectCaps(_ZN17CScriptedSentence10ObjectCapsEv), 
	   [5] = Save(_ZN17CScriptedSentence4SaveER5CSave), 
	   [6] = Restore(_ZN17CScriptedSentence7RestoreER8CRestore), 
	} */
	/* size: 1336, cachelines: 21, members: 10, static members: 1 */
	/* sum members: 36, holes: 1, sum holes: 1300 */
	/* last cacheline: 56 bytes */
};
class CCineAI : public CCineMonster {
public:

	/* class CCineMonster        <ancestor>; */      /*     0  1776 */

	/* XXX last struct has 1 hole */
	void CCineAI(class CCineAI *, class CCineAI &); /* linkage=_ZN7CCineAIC4EOS_ */

	void CCineAI(class CCineAI *, const class CCineAI  &); /* linkage=_ZN7CCineAIC4ERKS_ */

	void CCineAI(class CCineAI *); /* linkage=_ZN7CCineAIC4Ev */

private:

	virtual BOOL StartSequence(class CCineAI *, class CBaseMonster *, int, BOOL); /* linkage=_ZN7CCineAI13StartSequenceEP12CBaseMonsterii */

	virtual void PossessEntity(class CCineAI *); /* linkage=_ZN7CCineAI13PossessEntityEv */

	virtual BOOL FCanOverrideState(class CCineAI *); /* linkage=_ZN7CCineAI17FCanOverrideStateEv */

	virtual void FixScriptMonsterSchedule(class CCineAI *, class CBaseMonster *); /* linkage=_ZN7CCineAI24FixScriptMonsterScheduleEP12CBaseMonster */

	virtual void ~CCineAI(class CCineAI *, int); /* linkage=_ZN7CCineAID4Ev */

	/* vtable has 4 entries: {
	   [135] = StartSequence(_ZN7CCineAI13StartSequenceEP12CBaseMonsterii), 
	   [134] = PossessEntity(_ZN7CCineAI13PossessEntityEv), 
	   [136] = FCanOverrideState(_ZN7CCineAI17FCanOverrideStateEv), 
	   [137] = FixScriptMonsterSchedule(_ZN7CCineAI24FixScriptMonsterScheduleEP12CBaseMonster), 
	} */
	/* size: 1776, cachelines: 28, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 48 bytes */
};
class CCineMonster : public CBaseMonster {

	/* XXX 1724 bytes hole, try to pack */
public:


	/* class CBaseMonster        <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[13]; /*     0     0 */
	/* --- cacheline 26 boundary (1664 bytes) was 60 bytes ago --- */
	int                        m_iszIdle;            /*  1724     4 */
	/* --- cacheline 27 boundary (1728 bytes) --- */
	int                        m_iszPlay;            /*  1728     4 */
	int                        m_iszEntity;          /*  1732     4 */
	int                        m_fMoveTo;            /*  1736     4 */
	int                        m_iFinishSchedule;    /*  1740     4 */
	float                      m_flRadius;           /*  1744     4 */
	float                      m_flRepeat;           /*  1748     4 */
	int                        m_iDelay;             /*  1752     4 */
	float                      m_startTime;          /*  1756     4 */
	int                        m_saved_movetype;     /*  1760     4 */
	int                        m_saved_solid;        /*  1764     4 */
	int                        m_saved_effects;      /*  1768     4 */
	BOOL                       m_interruptable;      /*  1772     4 */
	void CCineMonster(class CCineMonster *, class CCineMonster &); /* linkage=_ZN12CCineMonsterC4EOS_ */

	void CCineMonster(class CCineMonster *, const class CCineMonster  &); /* linkage=_ZN12CCineMonsterC4ERKS_ */

	void CCineMonster(class CCineMonster *); /* linkage=_ZN12CCineMonsterC4Ev */

	virtual void Spawn(class CCineMonster *); /* linkage=_ZN12CCineMonster5SpawnEv */

	virtual void KeyValue(class CCineMonster *, KeyValueData *); /* linkage=_ZN12CCineMonster8KeyValueEP14KeyValueData_s */

	virtual void Use(class CCineMonster *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN12CCineMonster3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void Blocked(class CCineMonster *, class CBaseEntity *); /* linkage=_ZN12CCineMonster7BlockedEP11CBaseEntity */

	virtual void Touch(class CCineMonster *, class CBaseEntity *); /* linkage=_ZN12CCineMonster5TouchEP11CBaseEntity */

	virtual int ObjectCaps(class CCineMonster *); /* linkage=_ZN12CCineMonster10ObjectCapsEv */

	virtual void Activate(class CCineMonster *); /* linkage=_ZN12CCineMonster8ActivateEv */

	virtual int Save(class CCineMonster *, class CSave &); /* linkage=_ZN12CCineMonster4SaveER5CSave */

	virtual int Restore(class CCineMonster *, class CRestore &); /* linkage=_ZN12CCineMonster7RestoreER8CRestore */

	void CineThink(class CCineMonster *); /* linkage=_ZN12CCineMonster9CineThinkEv */

	void Pain(class CCineMonster *); /* linkage=_ZN12CCineMonster4PainEv */

	void Die(class CCineMonster *); /* linkage=_ZN12CCineMonster3DieEv */

	void DelayStart(class CCineMonster *, int); /* linkage=_ZN12CCineMonster10DelayStartEi */

	int FindEntity(class CCineMonster *); /* linkage=_ZN12CCineMonster10FindEntityEv */

	virtual void PossessEntity(class CCineMonster *); /* linkage=_ZN12CCineMonster13PossessEntityEv */

	void ReleaseEntity(class CCineMonster *, class CBaseMonster *); /* linkage=_ZN12CCineMonster13ReleaseEntityEP12CBaseMonster */

	void CancelScript(class CCineMonster *); /* linkage=_ZN12CCineMonster12CancelScriptEv */

	virtual BOOL StartSequence(class CCineMonster *, class CBaseMonster *, int, BOOL); /* linkage=_ZN12CCineMonster13StartSequenceEP12CBaseMonsterii */

	virtual BOOL FCanOverrideState(class CCineMonster *); /* linkage=_ZN12CCineMonster17FCanOverrideStateEv */

	void SequenceDone(class CCineMonster *, class CBaseMonster *); /* linkage=_ZN12CCineMonster12SequenceDoneEP12CBaseMonster */

	virtual void FixScriptMonsterSchedule(class CCineMonster *, class CBaseMonster *); /* linkage=_ZN12CCineMonster24FixScriptMonsterScheduleEP12CBaseMonster */

	BOOL CanInterrupt(class CCineMonster *); /* linkage=_ZN12CCineMonster12CanInterruptEv */

	void AllowInterrupt(class CCineMonster *, BOOL); /* linkage=_ZN12CCineMonster14AllowInterruptEi */

	virtual int IgnoreConditions(class CCineMonster *); /* linkage=_ZN12CCineMonster16IgnoreConditionsEv */

	virtual void ~CCineMonster(class CCineMonster *, int); /* linkage=_ZN12CCineMonsterD4Ev */

	/* vtable has 14 entries: {
	   [2] = Spawn(_ZN12CCineMonster5SpawnEv), 
	   [4] = KeyValue(_ZN12CCineMonster8KeyValueEP14KeyValueData_s), 
	   [45] = Use(_ZN12CCineMonster3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [46] = Blocked(_ZN12CCineMonster7BlockedEP11CBaseEntity), 
	   [44] = Touch(_ZN12CCineMonster5TouchEP11CBaseEntity), 
	   [7] = ObjectCaps(_ZN12CCineMonster10ObjectCapsEv), 
	   [8] = Activate(_ZN12CCineMonster8ActivateEv), 
	   [5] = Save(_ZN12CCineMonster4SaveER5CSave), 
	   [6] = Restore(_ZN12CCineMonster7RestoreER8CRestore), 
	   [134] = PossessEntity(_ZN12CCineMonster13PossessEntityEv), 
	   [135] = StartSequence(_ZN12CCineMonster13StartSequenceEP12CBaseMonsterii), 
	   [136] = FCanOverrideState(_ZN12CCineMonster17FCanOverrideStateEv), 
	   [137] = FixScriptMonsterSchedule(_ZN12CCineMonster24FixScriptMonsterScheduleEP12CBaseMonster), 
	   [112] = IgnoreConditions(_ZN12CCineMonster16IgnoreConditionsEv), 
	} */
	/* size: 1776, cachelines: 28, members: 14, static members: 1 */
	/* sum members: 52, holes: 1, sum holes: 1724 */
	/* last cacheline: 48 bytes */
};
class CTFSentrygun : public CBaseMonster {

	/* XXX 1724 bytes hole, try to pack */
public:


	/* class CBaseMonster        <ancestor>; */      /*     0     0 */
	/* --- cacheline 26 boundary (1664 bytes) was 60 bytes ago --- */
	BOOL                       m_bTurningRight;      /*  1724     4 */
	/* --- cacheline 27 boundary (1728 bytes) --- */
	int                        m_iShardIndex;        /*  1728     4 */
	float                      m_flNextCheck;        /*  1732     4 */
	int                        m_iBaseTurnRate;      /*  1736     4 */
	float                      m_fTurnRate;          /*  1740     4 */
	class Vector              m_vecCurAngles;        /*  1744    12 */
	class Vector              m_vecGoalAngles;       /*  1756    12 */
	class Vector              m_vecCurDishAngles;    /*  1768    12 */
	void CTFSentrygun(class CTFSentrygun *, class CTFSentrygun &); /* linkage=_ZN12CTFSentrygunC4EOS_ */

	void CTFSentrygun(class CTFSentrygun *, const class CTFSentrygun  &); /* linkage=_ZN12CTFSentrygunC4ERKS_ */

	void CTFSentrygun(class CTFSentrygun *); /* linkage=_ZN12CTFSentrygunC4Ev */

	virtual void Spawn(class CTFSentrygun *); /* linkage=_ZN12CTFSentrygun5SpawnEv */

	virtual void Precache(class CTFSentrygun *); /* linkage=_ZN12CTFSentrygun8PrecacheEv */

	virtual int Classify(class CTFSentrygun *); /* linkage=_ZN12CTFSentrygun8ClassifyEv */

	virtual int TakeDamage(class CTFSentrygun *, entvars_t *, entvars_t *, float, int); /* linkage=_ZN12CTFSentrygun10TakeDamageEP9entvars_sS1_fi */

	virtual BOOL FInViewCone(class CTFSentrygun *, class CBaseEntity *); /* linkage=_ZN12CTFSentrygun11FInViewConeEP11CBaseEntity */

	virtual int BloodColor(class CTFSentrygun *); /* linkage=_ZN12CTFSentrygun10BloodColorEv */

	virtual BOOL EngineerUse(class CTFSentrygun *, class CBasePlayer *); /* linkage=_ZN12CTFSentrygun11EngineerUseEP11CBasePlayer */

	void Upgrade(class CTFSentrygun *); /* linkage=_ZN12CTFSentrygun7UpgradeEv */

	void Remove(class CTFSentrygun *); /* linkage=_ZN12CTFSentrygun6RemoveEv */

	void SentryRotate(class CTFSentrygun *); /* linkage=_ZN12CTFSentrygun12SentryRotateEv */

	void Attack(class CTFSentrygun *); /* linkage=_ZN12CTFSentrygun6AttackEv */

	void Sentry_Explode(class CTFSentrygun *); /* linkage=_ZN12CTFSentrygun14Sentry_ExplodeEv */

	virtual void TeamFortress_TakeEMPBlast(class CTFSentrygun *, entvars_t *); /* linkage=_ZN12CTFSentrygun25TeamFortress_TakeEMPBlastEP9entvars_s */

	void CheckShield(class CTFSentrygun *); /* linkage=_ZN12CTFSentrygun11CheckShieldEv */

	virtual void Killed(class CTFSentrygun *, entvars_t *, entvars_t *, int); /* linkage=_ZN12CTFSentrygun6KilledEP9entvars_sS1_i */

	BOOL CheckSentry(class CTFSentrygun *); /* linkage=_ZN12CTFSentrygun11CheckSentryEv */

	void SetSentryAnim(class CTFSentrygun *, enum TFTURRET_ANIM); /* linkage=_ZN12CTFSentrygun13SetSentryAnimE13TFTURRET_ANIM */

	BOOL FindTarget(class CTFSentrygun *); /* linkage=_ZN12CTFSentrygun10FindTargetEv */

	void FoundTarget(class CTFSentrygun *); /* linkage=_ZN12CTFSentrygun11FoundTargetEv */

	BOOL ValidTarget(class CTFSentrygun *, class CBaseEntity *); /* linkage=_ZN12CTFSentrygun11ValidTargetEP11CBaseEntity */

	int Range(class CTFSentrygun *, class CBaseEntity *); /* linkage=_ZN12CTFSentrygun5RangeEP11CBaseEntity */

	BOOL Fire(class CTFSentrygun *); /* linkage=_ZN12CTFSentrygun4FireEv */

	int MoveTurret(class CTFSentrygun *); /* linkage=_ZN12CTFSentrygun10MoveTurretEv */

	virtual void ~CTFSentrygun(class CTFSentrygun *, int); /* linkage=_ZN12CTFSentrygunD4Ev */

	/* vtable has 9 entries: {
	   [2] = Spawn(_ZN12CTFSentrygun5SpawnEv), 
	   [3] = Precache(_ZN12CTFSentrygun8PrecacheEv), 
	   [10] = Classify(_ZN12CTFSentrygun8ClassifyEv), 
	   [13] = TakeDamage(_ZN12CTFSentrygun10TakeDamageEP9entvars_sS1_fi), 
	   [77] = FInViewCone(_ZN12CTFSentrygun11FInViewConeEP11CBaseEntity), 
	   [16] = BloodColor(_ZN12CTFSentrygun10BloodColorEv), 
	   [57] = EngineerUse(_ZN12CTFSentrygun11EngineerUseEP11CBasePlayer), 
	   [61] = TeamFortress_TakeEMPBlast(_ZN12CTFSentrygun25TeamFortress_TakeEMPBlastEP9entvars_s), 
	   [15] = Killed(_ZN12CTFSentrygun6KilledEP9entvars_sS1_i), 
	} */
	/* size: 1780, cachelines: 28, members: 9 */
	/* sum members: 56, holes: 1, sum holes: 1724 */
	/* last cacheline: 52 bytes */
};
class CTFSentrygunBase : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CTFSentrygunBase(class CTFSentrygunBase *, class CTFSentrygunBase &); /* linkage=_ZN16CTFSentrygunBaseC4EOS_ */

	void CTFSentrygunBase(class CTFSentrygunBase *, const class CTFSentrygunBase  &); /* linkage=_ZN16CTFSentrygunBaseC4ERKS_ */

	void CTFSentrygunBase(class CTFSentrygunBase *); /* linkage=_ZN16CTFSentrygunBaseC4Ev */

	virtual void Spawn(class CTFSentrygunBase *); /* linkage=_ZN16CTFSentrygunBase5SpawnEv */

	virtual void Finished(class CTFSentrygunBase *); /* linkage=_ZN16CTFSentrygunBase8FinishedEv */

	void Remove(class CTFSentrygunBase *); /* linkage=_ZN16CTFSentrygunBase6RemoveEv */

	virtual int Classify(class CTFSentrygunBase *); /* linkage=_ZN16CTFSentrygunBase8ClassifyEv */

	virtual int TakeDamage(class CTFSentrygunBase *, entvars_t *, entvars_t *, float, int); /* linkage=_ZN16CTFSentrygunBase10TakeDamageEP9entvars_sS1_fi */

	class CTFSentrygunBase * CreateSentryBase(class Vector, class Vector, class CBaseEntity *); /* linkage=_ZN16CTFSentrygunBase16CreateSentryBaseE6VectorS0_P11CBaseEntity */

	virtual void ~CTFSentrygunBase(class CTFSentrygunBase *, int); /* linkage=_ZN16CTFSentrygunBaseD4Ev */

	/* vtable has 4 entries: {
	   [2] = Spawn(_ZN16CTFSentrygunBase5SpawnEv), 
	   [58] = Finished(_ZN16CTFSentrygunBase8FinishedEv), 
	   [10] = Classify(_ZN16CTFSentrygunBase8ClassifyEv), 
	   [13] = TakeDamage(_ZN16CTFSentrygunBase10TakeDamageEP9entvars_sS1_fi), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
struct dynpitchvol {
	int                        preset;               /*     0     4 */
	int                        pitchrun;             /*     4     4 */
	int                        pitchstart;           /*     8     4 */
	int                        spinup;               /*    12     4 */
	int                        spindown;             /*    16     4 */
	int                        volrun;               /*    20     4 */
	int                        volstart;             /*    24     4 */
	int                        fadein;               /*    28     4 */
	int                        fadeout;              /*    32     4 */
	int                        lfotype;              /*    36     4 */
	int                        lforate;              /*    40     4 */
	int                        lfomodpitch;          /*    44     4 */
	int                        lfomodvol;            /*    48     4 */
	int                        cspinup;              /*    52     4 */
	int                        cspincount;           /*    56     4 */
	int                        pitch;                /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	int                        spinupsav;            /*    64     4 */
	int                        spindownsav;          /*    68     4 */
	int                        pitchfrac;            /*    72     4 */
	int                        vol;                  /*    76     4 */
	int                        fadeinsav;            /*    80     4 */
	int                        fadeoutsav;           /*    84     4 */
	int                        volfrac;              /*    88     4 */
	int                        lfofrac;              /*    92     4 */
	int                        lfomult;              /*    96     4 */

	/* size: 100, cachelines: 2, members: 25 */
	/* last cacheline: 36 bytes */
};
struct sentenceg {
	char                       szgroupname[16];      /*     0    16 */
	int                        count;                /*    16     4 */
	unsigned char              rgblru[32];           /*    20    32 */

	/* size: 52, cachelines: 1, members: 3 */
	/* last cacheline: 52 bytes */
};
class CSpeaker : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[1]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	int                        m_preset;             /*  1140     4 */
	void CSpeaker(class CSpeaker *, class CSpeaker &); /* linkage=_ZN8CSpeakerC4EOS_ */

	void CSpeaker(class CSpeaker *, const class CSpeaker  &); /* linkage=_ZN8CSpeakerC4ERKS_ */

	void CSpeaker(class CSpeaker *); /* linkage=_ZN8CSpeakerC4Ev */

	virtual void KeyValue(class CSpeaker *, KeyValueData *); /* linkage=_ZN8CSpeaker8KeyValueEP14KeyValueData_s */

	virtual void Spawn(class CSpeaker *); /* linkage=_ZN8CSpeaker5SpawnEv */

	virtual void Precache(class CSpeaker *); /* linkage=_ZN8CSpeaker8PrecacheEv */

	void ToggleUse(class CSpeaker *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN8CSpeaker9ToggleUseEP11CBaseEntityS1_8USE_TYPEf */

	void SpeakerThink(class CSpeaker *); /* linkage=_ZN8CSpeaker12SpeakerThinkEv */

	virtual int Save(class CSpeaker *, class CSave &); /* linkage=_ZN8CSpeaker4SaveER5CSave */

	virtual int Restore(class CSpeaker *, class CRestore &); /* linkage=_ZN8CSpeaker7RestoreER8CRestore */

	virtual int ObjectCaps(class CSpeaker *); /* linkage=_ZN8CSpeaker10ObjectCapsEv */

	virtual void ~CSpeaker(class CSpeaker *, int); /* linkage=_ZN8CSpeakerD4Ev */

	/* vtable has 6 entries: {
	   [4] = KeyValue(_ZN8CSpeaker8KeyValueEP14KeyValueData_s), 
	   [2] = Spawn(_ZN8CSpeaker5SpawnEv), 
	   [3] = Precache(_ZN8CSpeaker8PrecacheEv), 
	   [5] = Save(_ZN8CSpeaker4SaveER5CSave), 
	   [6] = Restore(_ZN8CSpeaker7RestoreER8CRestore), 
	   [7] = ObjectCaps(_ZN8CSpeaker10ObjectCapsEv), 
	} */
	/* size: 1144, cachelines: 18, members: 2, static members: 1 */
	/* sum members: 4, holes: 1, sum holes: 1140 */
	/* last cacheline: 56 bytes */
};
class CEnvSound : public CPointEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CPointEntity        <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[2]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	float                      m_flRadius;           /*  1140     4 */
	float                      m_flRoomtype;         /*  1144     4 */
	void CEnvSound(class CEnvSound *, class CEnvSound &); /* linkage=_ZN9CEnvSoundC4EOS_ */

	void CEnvSound(class CEnvSound *, const class CEnvSound  &); /* linkage=_ZN9CEnvSoundC4ERKS_ */

	void CEnvSound(class CEnvSound *); /* linkage=_ZN9CEnvSoundC4Ev */

	virtual void KeyValue(class CEnvSound *, KeyValueData *); /* linkage=_ZN9CEnvSound8KeyValueEP14KeyValueData_s */

	virtual void Spawn(class CEnvSound *); /* linkage=_ZN9CEnvSound5SpawnEv */

	virtual void Think(class CEnvSound *); /* linkage=_ZN9CEnvSound5ThinkEv */

	virtual int Save(class CEnvSound *, class CSave &); /* linkage=_ZN9CEnvSound4SaveER5CSave */

	virtual int Restore(class CEnvSound *, class CRestore &); /* linkage=_ZN9CEnvSound7RestoreER8CRestore */

	virtual void ~CEnvSound(class CEnvSound *, int); /* linkage=_ZN9CEnvSoundD4Ev */

	/* vtable has 5 entries: {
	   [4] = KeyValue(_ZN9CEnvSound8KeyValueEP14KeyValueData_s), 
	   [2] = Spawn(_ZN9CEnvSound5SpawnEv), 
	   [43] = Think(_ZN9CEnvSound5ThinkEv), 
	   [5] = Save(_ZN9CEnvSound4SaveER5CSave), 
	   [6] = Restore(_ZN9CEnvSound7RestoreER8CRestore), 
	} */
	/* size: 1148, cachelines: 18, members: 3, static members: 1 */
	/* sum members: 8, holes: 1, sum holes: 1140 */
	/* last cacheline: 60 bytes */
};
class CAmbientGeneric : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[4]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	float                      m_flAttenuation;      /*  1140     4 */
	dynpitchvol_t              m_dpv;                /*  1144   100 */
	/* --- cacheline 19 boundary (1216 bytes) was 28 bytes ago --- */
	BOOL                       m_fActive;            /*  1244     4 */
	BOOL                       m_fLooping;           /*  1248     4 */
	void CAmbientGeneric(class CAmbientGeneric *, class CAmbientGeneric &); /* linkage=_ZN15CAmbientGenericC4EOS_ */

	void CAmbientGeneric(class CAmbientGeneric *, const class CAmbientGeneric  &); /* linkage=_ZN15CAmbientGenericC4ERKS_ */

	void CAmbientGeneric(class CAmbientGeneric *); /* linkage=_ZN15CAmbientGenericC4Ev */

	virtual void KeyValue(class CAmbientGeneric *, KeyValueData *); /* linkage=_ZN15CAmbientGeneric8KeyValueEP14KeyValueData_s */

	virtual void Spawn(class CAmbientGeneric *); /* linkage=_ZN15CAmbientGeneric5SpawnEv */

	virtual void Precache(class CAmbientGeneric *); /* linkage=_ZN15CAmbientGeneric8PrecacheEv */

	void ToggleUse(class CAmbientGeneric *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN15CAmbientGeneric9ToggleUseEP11CBaseEntityS1_8USE_TYPEf */

	void RampThink(class CAmbientGeneric *); /* linkage=_ZN15CAmbientGeneric9RampThinkEv */

	void InitModulationParms(class CAmbientGeneric *); /* linkage=_ZN15CAmbientGeneric19InitModulationParmsEv */

	virtual int Save(class CAmbientGeneric *, class CSave &); /* linkage=_ZN15CAmbientGeneric4SaveER5CSave */

	virtual int Restore(class CAmbientGeneric *, class CRestore &); /* linkage=_ZN15CAmbientGeneric7RestoreER8CRestore */

	virtual int ObjectCaps(class CAmbientGeneric *); /* linkage=_ZN15CAmbientGeneric10ObjectCapsEv */

	virtual void ~CAmbientGeneric(class CAmbientGeneric *, int); /* linkage=_ZN15CAmbientGenericD4Ev */

	/* vtable has 6 entries: {
	   [4] = KeyValue(_ZN15CAmbientGeneric8KeyValueEP14KeyValueData_s), 
	   [2] = Spawn(_ZN15CAmbientGeneric5SpawnEv), 
	   [3] = Precache(_ZN15CAmbientGeneric8PrecacheEv), 
	   [5] = Save(_ZN15CAmbientGeneric4SaveER5CSave), 
	   [6] = Restore(_ZN15CAmbientGeneric7RestoreER8CRestore), 
	   [7] = ObjectCaps(_ZN15CAmbientGeneric10ObjectCapsEv), 
	} */
	/* size: 1252, cachelines: 20, members: 5, static members: 1 */
	/* sum members: 112, holes: 1, sum holes: 1140 */
	/* last cacheline: 36 bytes */
};
class CSoundEnt : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	int                        m_iFreeSound;         /*  1140     4 */
	int                        m_iActiveSound;       /*  1144     4 */
	int                        m_cLastActiveSounds;  /*  1148     4 */
	/* --- cacheline 18 boundary (1152 bytes) --- */
	BOOL                       m_fShowReport;        /*  1152     4 */
private:

	class CSound              m_SoundPool[64];       /*  1156  2048 */
	void CSoundEnt(class CSoundEnt *, class CSoundEnt &); /* linkage=_ZN9CSoundEntC4EOS_ */

	void CSoundEnt(class CSoundEnt *, const class CSoundEnt  &); /* linkage=_ZN9CSoundEntC4ERKS_ */

	void CSoundEnt(class CSoundEnt *); /* linkage=_ZN9CSoundEntC4Ev */

	virtual void Precache(class CSoundEnt *); /* linkage=_ZN9CSoundEnt8PrecacheEv */

	virtual void Spawn(class CSoundEnt *); /* linkage=_ZN9CSoundEnt5SpawnEv */

	virtual void Think(class CSoundEnt *); /* linkage=_ZN9CSoundEnt5ThinkEv */

	void Initialize(class CSoundEnt *); /* linkage=_ZN9CSoundEnt10InitializeEv */

	void InsertSound(int, const class Vector  &, int, float); /* linkage=_ZN9CSoundEnt11InsertSoundEiRK6Vectorif */

	void FreeSound(int, int); /* linkage=_ZN9CSoundEnt9FreeSoundEii */

	int ActiveList(void); /* linkage=_ZN9CSoundEnt10ActiveListEv */

	int FreeList(void); /* linkage=_ZN9CSoundEnt8FreeListEv */

	class CSound * SoundPointerForIndex(int); /* linkage=_ZN9CSoundEnt20SoundPointerForIndexEi */

	int ClientSoundIndex(edict_t *); /* linkage=_ZN9CSoundEnt16ClientSoundIndexEP7edict_s */

	BOOL IsEmpty(class CSoundEnt *); /* linkage=_ZN9CSoundEnt7IsEmptyEv */

	int ISoundsInList(class CSoundEnt *, int); /* linkage=_ZN9CSoundEnt13ISoundsInListEi */

	int IAllocSound(class CSoundEnt *); /* linkage=_ZN9CSoundEnt11IAllocSoundEv */

	virtual int ObjectCaps(class CSoundEnt *); /* linkage=_ZN9CSoundEnt10ObjectCapsEv */

	virtual void ~CSoundEnt(class CSoundEnt *, int); /* linkage=_ZN9CSoundEntD4Ev */

	/* vtable has 4 entries: {
	   [3] = Precache(_ZN9CSoundEnt8PrecacheEv), 
	   [2] = Spawn(_ZN9CSoundEnt5SpawnEv), 
	   [43] = Think(_ZN9CSoundEnt5ThinkEv), 
	   [7] = ObjectCaps(_ZN9CSoundEnt10ObjectCapsEv), 
	} */
	/* size: 3204, cachelines: 51, members: 6 */
	/* sum members: 2064, holes: 1, sum holes: 1140 */
	/* last cacheline: 4 bytes */
};
class CBaseSpectator : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CBaseSpectator(class CBaseSpectator *); /* linkage=_ZN14CBaseSpectatorC4Ev */

	virtual void Spawn(class CBaseSpectator *); /* linkage=_ZN14CBaseSpectator5SpawnEv */

	void SpectatorConnect(class CBaseSpectator *); /* linkage=_ZN14CBaseSpectator16SpectatorConnectEv */

	void SpectatorDisconnect(class CBaseSpectator *); /* linkage=_ZN14CBaseSpectator19SpectatorDisconnectEv */

	void SpectatorThink(class CBaseSpectator *); /* linkage=_ZN14CBaseSpectator14SpectatorThinkEv */

private:

	void SpectatorImpulseCommand(class CBaseSpectator *); /* linkage=_ZN14CBaseSpectator23SpectatorImpulseCommandEv */

	virtual void ~CBaseSpectator(class CBaseSpectator *, int); /* linkage=_ZN14CBaseSpectatorD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN14CBaseSpectator5SpawnEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CSquadMonster : public CBaseMonster {

	/* XXX 1724 bytes hole, try to pack */
public:


	/* class CBaseMonster        <ancestor>; */      /*     0     0 */
	/* --- cacheline 26 boundary (1664 bytes) was 60 bytes ago --- */
	class EHANDLE             m_hSquadLeader;        /*  1724     8 */
	/* --- cacheline 27 boundary (1728 bytes) was 4 bytes ago --- */
	class EHANDLE             m_hSquadMember[4];     /*  1732    32 */
	int                        m_afSquadSlots;       /*  1764     4 */
	float                      m_flLastEnemySightTime; /*  1768     4 */
	BOOL                       m_fEnemyEluded;       /*  1772     4 */
	int                        m_iMySlot;            /*  1776     4 */

	/* Bitfield combined with previous fields */

	static TYPEDESCRIPTION            m_SaveData[5]; /*     0     0 */
	void CSquadMonster(class CSquadMonster *); /* linkage=_ZN13CSquadMonsterC4Ev */

	virtual int CheckEnemy(class CSquadMonster *, class CBaseEntity *); /* linkage=_ZN13CSquadMonster10CheckEnemyEP11CBaseEntity */

	virtual void StartMonster(class CSquadMonster *); /* linkage=_ZN13CSquadMonster12StartMonsterEv */

	void VacateSlot(class CSquadMonster *); /* linkage=_ZN13CSquadMonster10VacateSlotEv */

	virtual void ScheduleChange(class CSquadMonster *); /* linkage=_ZN13CSquadMonster14ScheduleChangeEv */

	virtual void Killed(class CSquadMonster *, entvars_t *, entvars_t *, int); /* linkage=_ZN13CSquadMonster6KilledEP9entvars_sS1_i */

	BOOL OccupySlot(class CSquadMonster *, int); /* linkage=_ZN13CSquadMonster10OccupySlotEi */

	BOOL NoFriendlyFire(class CSquadMonster *); /* linkage=_ZN13CSquadMonster14NoFriendlyFireEv */

	class CSquadMonster * MySquadLeader(class CSquadMonster *); /* linkage=_ZN13CSquadMonster13MySquadLeaderEv */

	class CSquadMonster * MySquadMember(class CSquadMonster *, int); /* linkage=_ZN13CSquadMonster13MySquadMemberEi */

	int InSquad(class CSquadMonster *); /* linkage=_ZN13CSquadMonster7InSquadEv */

	int IsLeader(class CSquadMonster *); /* linkage=_ZN13CSquadMonster8IsLeaderEv */

	int SquadJoin(class CSquadMonster *, int); /* linkage=_ZN13CSquadMonster9SquadJoinEi */

	int SquadRecruit(class CSquadMonster *, int, int); /* linkage=_ZN13CSquadMonster12SquadRecruitEii */

	int SquadCount(class CSquadMonster *); /* linkage=_ZN13CSquadMonster10SquadCountEv */

	void SquadRemove(class CSquadMonster *, class CSquadMonster *); /* linkage=_ZN13CSquadMonster11SquadRemoveEPS_ */

	void SquadUnlink(class CSquadMonster *); /* linkage=_ZN13CSquadMonster11SquadUnlinkEv */

	BOOL SquadAdd(class CSquadMonster *, class CSquadMonster *); /* linkage=_ZN13CSquadMonster8SquadAddEPS_ */

	void SquadDisband(class CSquadMonster *); /* linkage=_ZN13CSquadMonster12SquadDisbandEv */

	void SquadAddConditions(class CSquadMonster *, int); /* linkage=_ZN13CSquadMonster18SquadAddConditionsEi */

	void SquadMakeEnemy(class CSquadMonster *, class CBaseEntity *); /* linkage=_ZN13CSquadMonster14SquadMakeEnemyEP11CBaseEntity */

	void SquadPasteEnemyInfo(class CSquadMonster *); /* linkage=_ZN13CSquadMonster19SquadPasteEnemyInfoEv */

	void SquadCopyEnemyInfo(class CSquadMonster *); /* linkage=_ZN13CSquadMonster18SquadCopyEnemyInfoEv */

	BOOL SquadEnemySplit(class CSquadMonster *); /* linkage=_ZN13CSquadMonster15SquadEnemySplitEv */

	BOOL SquadMemberInRange(class CSquadMonster *, const class Vector  &, float); /* linkage=_ZN13CSquadMonster18SquadMemberInRangeERK6Vectorf */

	virtual class CSquadMonster * MySquadMonsterPointer(class CSquadMonster *); /* linkage=_ZN13CSquadMonster21MySquadMonsterPointerEv */

	virtual int Save(class CSquadMonster *, class CSave &); /* linkage=_ZN13CSquadMonster4SaveER5CSave */

	virtual int Restore(class CSquadMonster *, class CRestore &); /* linkage=_ZN13CSquadMonster7RestoreER8CRestore */

	virtual BOOL FValidateCover(class CSquadMonster *, const class Vector  &); /* linkage=_ZN13CSquadMonster14FValidateCoverERK6Vector */

	virtual MONSTERSTATE GetIdealState(class CSquadMonster *); /* linkage=_ZN13CSquadMonster13GetIdealStateEv */

	virtual class Schedule_t * GetScheduleOfType(class CSquadMonster *, int); /* linkage=_ZN13CSquadMonster17GetScheduleOfTypeEi */

	virtual void ~CSquadMonster(class CSquadMonster *, int); /* linkage=_ZN13CSquadMonsterD4Ev */

	/* vtable has 10 entries: {
	   [103] = CheckEnemy(_ZN13CSquadMonster10CheckEnemyEP11CBaseEntity), 
	   [75] = StartMonster(_ZN13CSquadMonster12StartMonsterEv), 
	   [94] = ScheduleChange(_ZN13CSquadMonster14ScheduleChangeEv), 
	   [15] = Killed(_ZN13CSquadMonster6KilledEP9entvars_sS1_i), 
	   [20] = MySquadMonsterPointer(_ZN13CSquadMonster21MySquadMonsterPointerEv), 
	   [5] = Save(_ZN13CSquadMonster4SaveER5CSave), 
	   [6] = Restore(_ZN13CSquadMonster7RestoreER8CRestore), 
	   [108] = FValidateCover(_ZN13CSquadMonster14FValidateCoverERK6Vector), 
	   [100] = GetIdealState(_ZN13CSquadMonster13GetIdealStateEv), 
	   [92] = GetScheduleOfType(_ZN13CSquadMonster17GetScheduleOfTypeEi), 
	} */
	/* size: 1780, cachelines: 28, members: 7, static members: 1 */
	/* sum members: 56, holes: 1, sum holes: 1724 */
	/* last cacheline: 52 bytes */
};
class CGraph {
	enum NODEQUERY {
		NODEGRAPH_DYNAMIC = 0,
		NODEGRAPH_STATIC  = 1,
	};

	BOOL                       m_fGraphPresent;      /*     0     4 */
	BOOL                       m_fGraphPointersSet;  /*     4     4 */
	BOOL                       m_fRoutingComplete;   /*     8     4 */
	class CNode *              m_pNodes;             /*    12     4 */
	class CLink *              m_pLinkPool;          /*    16     4 */
	char *                     m_pRouteInfo;         /*    20     4 */
	int                        m_cNodes;             /*    24     4 */
	int                        m_cLinks;             /*    28     4 */
	int                        m_nRouteInfo;         /*    32     4 */
	DIST_INFO *                m_di;                 /*    36     4 */
	int                        m_RangeStart[3][256]; /*    40  3072 */
	/* --- cacheline 48 boundary (3072 bytes) was 40 bytes ago --- */
	int                        m_RangeEnd[3][256];   /*  3112  3072 */
	/* --- cacheline 96 boundary (6144 bytes) was 40 bytes ago --- */
	float                      m_flShortest;         /*  6184     4 */
	int                        m_iNearest;           /*  6188     4 */
	int                        m_minX;               /*  6192     4 */
	int                        m_minY;               /*  6196     4 */
	int                        m_minZ;               /*  6200     4 */
	int                        m_maxX;               /*  6204     4 */
	/* --- cacheline 97 boundary (6208 bytes) --- */
	int                        m_maxY;               /*  6208     4 */
	int                        m_maxZ;               /*  6212     4 */
	int                        m_minBoxX;            /*  6216     4 */
	int                        m_minBoxY;            /*  6220     4 */
	int                        m_minBoxZ;            /*  6224     4 */
	int                        m_maxBoxX;            /*  6228     4 */
	int                        m_maxBoxY;            /*  6232     4 */
	int                        m_maxBoxZ;            /*  6236     4 */
	int                        m_CheckedCounter;     /*  6240     4 */
	float                      m_RegionMin[3];       /*  6244    12 */
	float                      m_RegionMax[3];       /*  6256    12 */
	CACHE_ENTRY                m_Cache[128];         /*  6268  2048 */
	/* --- cacheline 129 boundary (8256 bytes) was 60 bytes ago --- */
	int                        m_HashPrimes[16];     /*  8316    64 */
	/* --- cacheline 130 boundary (8320 bytes) was 60 bytes ago --- */
	short int *                m_pHashLinks;         /*  8380     4 */
	/* --- cacheline 131 boundary (8384 bytes) --- */
	int                        m_nHashLinks;         /*  8384     4 */
	int                        m_iLastActiveIdleSearch; /*  8388     4 */
	int                        m_iLastCoverSearch;   /*  8392     4 */
	void CGraph(class CGraph *); /* linkage=_ZN6CGraphC4Ev */

	int LinkVisibleNodes(class CGraph *, class CLink *, FILE *, int *); /* linkage=_ZN6CGraph16LinkVisibleNodesEP5CLinkP8_IO_FILEPi */

	int RejectInlineLinks(class CGraph *, class CLink *, FILE *); /* linkage=_ZN6CGraph17RejectInlineLinksEP5CLinkP8_IO_FILE */

	int FindShortestPath(class CGraph *, int *, int, int, int, int); /* linkage=_ZN6CGraph16FindShortestPathEPiiiii */

	int FindNearestNode(class CGraph *, const class Vector  &, class CBaseEntity *); /* linkage=_ZN6CGraph15FindNearestNodeERK6VectorP11CBaseEntity */

	int FindNearestNode(class CGraph *, const class Vector  &, int); /* linkage=_ZN6CGraph15FindNearestNodeERK6Vectori */

	float PathLength(class CGraph *, int, int, int, int); /* linkage=_ZN6CGraph10PathLengthEiiii */

	int NextNodeInRoute(class CGraph *, int, int, int, int); /* linkage=_ZN6CGraph15NextNodeInRouteEiiii */

	int HandleLinkEnt(class CGraph *, int, entvars_t *, int, enum NODEQUERY); /* linkage=_ZN6CGraph13HandleLinkEntEiP9entvars_siNS_9NODEQUERYE */

	entvars_t * LinkEntForLink(class CGraph *, class CLink *, class CNode *); /* linkage=_ZN6CGraph14LinkEntForLinkEP5CLinkP5CNode */

	void ShowNodeConnections(class CGraph *, int); /* linkage=_ZN6CGraph19ShowNodeConnectionsEi */

	void InitGraph(class CGraph *); /* linkage=_ZN6CGraph9InitGraphEv */

	int AllocNodes(class CGraph *); /* linkage=_ZN6CGraph10AllocNodesEv */

	int CheckNODFile(class CGraph *, char *); /* linkage=_ZN6CGraph12CheckNODFileEPc */

	int FLoadGraph(class CGraph *, char *); /* linkage=_ZN6CGraph10FLoadGraphEPc */

	int FSaveGraph(class CGraph *, char *); /* linkage=_ZN6CGraph10FSaveGraphEPc */

	int FSetGraphPointers(class CGraph *); /* linkage=_ZN6CGraph17FSetGraphPointersEv */

	void CheckNode(class CGraph *, class Vector, int); /* linkage=_ZN6CGraph9CheckNodeE6Vectori */

	void BuildRegionTables(class CGraph *); /* linkage=_ZN6CGraph17BuildRegionTablesEv */

	void ComputeStaticRoutingTables(class CGraph *); /* linkage=_ZN6CGraph26ComputeStaticRoutingTablesEv */

	void TestRoutingTables(class CGraph *); /* linkage=_ZN6CGraph17TestRoutingTablesEv */

	void HashInsert(class CGraph *, int, int, int); /* linkage=_ZN6CGraph10HashInsertEiii */

	void HashSearch(class CGraph *, int, int, int &); /* linkage=_ZN6CGraph10HashSearchEiiRi */

	void HashChoosePrimes(class CGraph *, int); /* linkage=_ZN6CGraph16HashChoosePrimesEi */

	void BuildLinkLookups(class CGraph *); /* linkage=_ZN6CGraph16BuildLinkLookupsEv */

	void SortNodes(class CGraph *); /* linkage=_ZN6CGraph9SortNodesEv */

	int HullIndex(class CGraph *, const class CBaseEntity  *); /* linkage=_ZN6CGraph9HullIndexEPK11CBaseEntity */

	int NodeType(class CGraph *, const class CBaseEntity  *); /* linkage=_ZN6CGraph8NodeTypeEPK11CBaseEntity */

	int CapIndex(class CGraph *, int); /* linkage=_ZN6CGraph8CapIndexEi */

	class CNode & Node(class CGraph *, int); /* linkage=_ZN6CGraph4NodeEi */

	class CLink & Link(class CGraph *, int); /* linkage=_ZN6CGraph4LinkEi */

	class CLink & NodeLink(class CGraph *, int, int); /* linkage=_ZN6CGraph8NodeLinkEii */

	class CLink & NodeLink(class CGraph *, const class CNode  &, int); /* linkage=_ZN6CGraph8NodeLinkERK5CNodei */

	int INodeLink(class CGraph *, int, int); /* linkage=_ZN6CGraph9INodeLinkEii */


	/* size: 8396, cachelines: 132, members: 35 */
	/* last cacheline: 12 bytes */
};
class CBaseToggle : public CBaseAnimating {

	/* XXX 1168 bytes hole, try to pack */
public:


	/* class CBaseAnimating      <ancestor>; */      /*     0     0 */
	/* --- cacheline 18 boundary (1152 bytes) was 16 bytes ago --- */
	TOGGLE_STATE               m_toggle_state;       /*  1168     4 */
	float                      m_flActivateFinished; /*  1172     4 */
	float                      m_flMoveDistance;     /*  1176     4 */
	float                      m_flWait;             /*  1180     4 */
	float                      m_flLip;              /*  1184     4 */
	float                      m_flTWidth;           /*  1188     4 */
	float                      m_flTLength;          /*  1192     4 */
	class Vector              m_vecPosition1;        /*  1196    12 */
	class Vector              m_vecPosition2;        /*  1208    12 */
	/* --- cacheline 19 boundary (1216 bytes) was 4 bytes ago --- */
	class Vector              m_vecAngle1;           /*  1220    12 */
	class Vector              m_vecAngle2;           /*  1232    12 */
	int                        m_cTriggersLeft;      /*  1244     4 */
	float                      m_flHeight;           /*  1248     4 */
	class EHANDLE             m_hActivator;          /*  1252     8 */
	struct {
		void               (*__pfn)(class CBaseToggle *); /*  1260     4 */
		int                __delta;              /*  1264     4 */
	} m_pfnCallWhenMoveDone;                         /*  1260     8 */
	class Vector              m_vecFinalDest;        /*  1268    12 */
	/* --- cacheline 20 boundary (1280 bytes) --- */
	class Vector              m_vecFinalAngle;       /*  1280    12 */
	int                        m_bitsDamageInflict;  /*  1292     4 */

	/* Bitfield combined with previous fields */

	static TYPEDESCRIPTION            m_SaveData[19]; /*     0     0 */
	string_t                   m_sMaster;            /*  1296     4 */
	void CBaseToggle(class CBaseToggle *, class CBaseToggle &); /* linkage=_ZN11CBaseToggleC4EOS_ */

	void CBaseToggle(class CBaseToggle *, const class CBaseToggle  &); /* linkage=_ZN11CBaseToggleC4ERKS_ */

	void CBaseToggle(class CBaseToggle *); /* linkage=_ZN11CBaseToggleC4Ev */

	virtual void KeyValue(class CBaseToggle *, KeyValueData *); /* linkage=_ZN11CBaseToggle8KeyValueEP14KeyValueData_s */

	virtual int Save(class CBaseToggle *, class CSave &); /* linkage=_ZN11CBaseToggle4SaveER5CSave */

	virtual int Restore(class CBaseToggle *, class CRestore &); /* linkage=_ZN11CBaseToggle7RestoreER8CRestore */

	virtual int GetToggleState(class CBaseToggle *); /* linkage=_ZN11CBaseToggle14GetToggleStateEv */

	virtual float GetDelay(class CBaseToggle *); /* linkage=_ZN11CBaseToggle8GetDelayEv */

	void LinearMove(class CBaseToggle *, class Vector, float); /* linkage=_ZN11CBaseToggle10LinearMoveE6Vectorf */

	void LinearMoveDone(class CBaseToggle *); /* linkage=_ZN11CBaseToggle14LinearMoveDoneEv */

	void AngularMove(class CBaseToggle *, class Vector, float); /* linkage=_ZN11CBaseToggle11AngularMoveE6Vectorf */

	void AngularMoveDone(class CBaseToggle *); /* linkage=_ZN11CBaseToggle15AngularMoveDoneEv */

	BOOL IsLockedByMaster(class CBaseToggle *); /* linkage=_ZN11CBaseToggle16IsLockedByMasterEv */

	float AxisValue(int, const class Vector  &); /* linkage=_ZN11CBaseToggle9AxisValueEiRK6Vector */

	void AxisDir(entvars_t *); /* linkage=_ZN11CBaseToggle7AxisDirEP9entvars_s */

	float AxisDelta(int, const class Vector  &, const class Vector  &); /* linkage=_ZN11CBaseToggle9AxisDeltaEiRK6VectorS2_ */

	virtual void ~CBaseToggle(class CBaseToggle *, int); /* linkage=_ZN11CBaseToggleD4Ev */

	/* vtable has 5 entries: {
	   [4] = KeyValue(_ZN11CBaseToggle8KeyValueEP14KeyValueData_s), 
	   [5] = Save(_ZN11CBaseToggle4SaveER5CSave), 
	   [6] = Restore(_ZN11CBaseToggle7RestoreER8CRestore), 
	   [21] = GetToggleState(_ZN11CBaseToggle14GetToggleStateEv), 
	   [25] = GetDelay(_ZN11CBaseToggle8GetDelayEv), 
	} */
	/* size: 1300, cachelines: 21, members: 20, static members: 1 */
	/* sum members: 132, holes: 1, sum holes: 1168 */
	/* last cacheline: 20 bytes */
};
class CBaseDelay : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	float                      m_flDelay;            /*  1140     4 */
	int                        m_iszKillTarget;      /*  1144     4 */

	/* Bitfield combined with previous fields */

	static TYPEDESCRIPTION            m_SaveData[2]; /*     0     0 */
	void CBaseDelay(class CBaseDelay *, class CBaseDelay &); /* linkage=_ZN10CBaseDelayC4EOS_ */

	void CBaseDelay(class CBaseDelay *, const class CBaseDelay  &); /* linkage=_ZN10CBaseDelayC4ERKS_ */

	void CBaseDelay(class CBaseDelay *); /* linkage=_ZN10CBaseDelayC4Ev */

	virtual void KeyValue(class CBaseDelay *, KeyValueData *); /* linkage=_ZN10CBaseDelay8KeyValueEP14KeyValueData_s */

	virtual int Save(class CBaseDelay *, class CSave &); /* linkage=_ZN10CBaseDelay4SaveER5CSave */

	virtual int Restore(class CBaseDelay *, class CRestore &); /* linkage=_ZN10CBaseDelay7RestoreER8CRestore */

	void SUB_UseTargets(class CBaseDelay *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN10CBaseDelay14SUB_UseTargetsEP11CBaseEntity8USE_TYPEf */

	void DelayThink(class CBaseDelay *); /* linkage=_ZN10CBaseDelay10DelayThinkEv */

	virtual void ~CBaseDelay(class CBaseDelay *, int); /* linkage=_ZN10CBaseDelayD4Ev */

	/* vtable has 3 entries: {
	   [4] = KeyValue(_ZN10CBaseDelay8KeyValueEP14KeyValueData_s), 
	   [5] = Save(_ZN10CBaseDelay4SaveER5CSave), 
	   [6] = Restore(_ZN10CBaseDelay7RestoreER8CRestore), 
	} */
	/* size: 1148, cachelines: 18, members: 3, static members: 1 */
	/* sum members: 8, holes: 1, sum holes: 1140 */
	/* last cacheline: 60 bytes */
};
class CNullEntity : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CNullEntity(class CNullEntity *, class CNullEntity &); /* linkage=_ZN11CNullEntityC4EOS_ */

	void CNullEntity(class CNullEntity *, const class CNullEntity  &); /* linkage=_ZN11CNullEntityC4ERKS_ */

	void CNullEntity(class CNullEntity *); /* linkage=_ZN11CNullEntityC4Ev */

	virtual void Spawn(class CNullEntity *); /* linkage=_ZN11CNullEntity5SpawnEv */

	virtual void ~CNullEntity(class CNullEntity *, int); /* linkage=_ZN11CNullEntityD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN11CNullEntity5SpawnEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CPointEntity : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CPointEntity(class CPointEntity *, class CPointEntity &); /* linkage=_ZN12CPointEntityC4EOS_ */

	void CPointEntity(class CPointEntity *, const class CPointEntity  &); /* linkage=_ZN12CPointEntityC4ERKS_ */

	void CPointEntity(class CPointEntity *); /* linkage=_ZN12CPointEntityC4Ev */

private:

	virtual void Spawn(class CPointEntity *); /* linkage=_ZN12CPointEntity5SpawnEv */

	virtual int ObjectCaps(class CPointEntity *); /* linkage=_ZN12CPointEntity10ObjectCapsEv */

	virtual void ~CPointEntity(class CPointEntity *, int); /* linkage=_ZN12CPointEntityD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN12CPointEntity5SpawnEv), 
	   [7] = ObjectCaps(_ZN12CPointEntity10ObjectCapsEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CTalkMonster : public CBaseMonster {

	/* XXX 1724 bytes hole, try to pack */
public:


	/* class CBaseMonster        <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[8]; /*     0     0 */
	static char *                     m_szFriends[3]; /*     0     0 */
	static float                      g_talkWaitTime; /*     0     0 */
	/* --- cacheline 26 boundary (1664 bytes) was 60 bytes ago --- */
	int                        m_bitsSaid;           /*  1724     4 */
	/* --- cacheline 27 boundary (1728 bytes) --- */
	int                        m_nSpeak;             /*  1728     4 */
	int                        m_voicePitch;         /*  1732     4 */
	const char  *              m_szGrp[18];          /*  1736    72 */
	/* --- cacheline 28 boundary (1792 bytes) was 16 bytes ago --- */
	float                      m_useTime;            /*  1808     4 */
	int                        m_iszUse;             /*  1812     4 */
	int                        m_iszUnUse;           /*  1816     4 */
	float                      m_flLastSaidSmelled;  /*  1820     4 */
	float                      m_flStopTalkTime;     /*  1824     4 */
	class EHANDLE             m_hTalkTarget;         /*  1828     8 */

	/* Bitfield combined with previous fields */

	static class Schedule_t *         m_scheduleList[11]; /*     0     0 */
	void CTalkMonster(class CTalkMonster *); /* linkage=_ZN12CTalkMonsterC4Ev */

	void TalkInit(class CTalkMonster *); /* linkage=_ZN12CTalkMonster8TalkInitEv */

	class CBaseEntity * FindNearestFriend(class CTalkMonster *, BOOL); /* linkage=_ZN12CTalkMonster17FindNearestFriendEi */

	float TargetDistance(class CTalkMonster *); /* linkage=_ZN12CTalkMonster14TargetDistanceEv */

	void StopTalking(class CTalkMonster *); /* linkage=_ZN12CTalkMonster11StopTalkingEv */

	virtual void Precache(class CTalkMonster *); /* linkage=_ZN12CTalkMonster8PrecacheEv */

	virtual int TakeDamage(class CTalkMonster *, entvars_t *, entvars_t *, float, int); /* linkage=_ZN12CTalkMonster10TakeDamageEP9entvars_sS1_fi */

	virtual void Touch(class CTalkMonster *, class CBaseEntity *); /* linkage=_ZN12CTalkMonster5TouchEP11CBaseEntity */

	virtual void Killed(class CTalkMonster *, entvars_t *, entvars_t *, int); /* linkage=_ZN12CTalkMonster6KilledEP9entvars_sS1_i */

	virtual int IRelationship(class CTalkMonster *, class CBaseEntity *); /* linkage=_ZN12CTalkMonster13IRelationshipEP11CBaseEntity */

	virtual int CanPlaySentence(class CTalkMonster *, BOOL); /* linkage=_ZN12CTalkMonster15CanPlaySentenceEi */

	virtual void PlaySentence(class CTalkMonster *, const char  *, float, float, float); /* linkage=_ZN12CTalkMonster12PlaySentenceEPKcfff */

	virtual void PlayScriptedSentence(class CTalkMonster *, const char  *, float, float, float, BOOL, class CBaseEntity *); /* linkage=_ZN12CTalkMonster20PlayScriptedSentenceEPKcfffiP11CBaseEntity */

	virtual void KeyValue(class CTalkMonster *, KeyValueData *); /* linkage=_ZN12CTalkMonster8KeyValueEP14KeyValueData_s */

	virtual void SetActivity(class CTalkMonster *, Activity); /* linkage=_ZN12CTalkMonster11SetActivityE8Activity */

	virtual class Schedule_t * GetScheduleOfType(class CTalkMonster *, int); /* linkage=_ZN12CTalkMonster17GetScheduleOfTypeEi */

	virtual void StartTask(class CTalkMonster *, class Task_t *); /* linkage=_ZN12CTalkMonster9StartTaskEP6Task_t */

	virtual void RunTask(class CTalkMonster *, class Task_t *); /* linkage=_ZN12CTalkMonster7RunTaskEP6Task_t */

	virtual void HandleAnimEvent(class CTalkMonster *, MonsterEvent_t *); /* linkage=_ZN12CTalkMonster15HandleAnimEventEP14MonsterEvent_t */

	virtual void PrescheduleThink(class CTalkMonster *); /* linkage=_ZN12CTalkMonster16PrescheduleThinkEv */

	int GetVoicePitch(class CTalkMonster *); /* linkage=_ZN12CTalkMonster13GetVoicePitchEv */

	void IdleRespond(class CTalkMonster *); /* linkage=_ZN12CTalkMonster11IdleRespondEv */

	int FIdleSpeak(class CTalkMonster *); /* linkage=_ZN12CTalkMonster10FIdleSpeakEv */

	int FIdleStare(class CTalkMonster *); /* linkage=_ZN12CTalkMonster10FIdleStareEv */

	int FIdleHello(class CTalkMonster *); /* linkage=_ZN12CTalkMonster10FIdleHelloEv */

	void IdleHeadTurn(class CTalkMonster *, class Vector &); /* linkage=_ZN12CTalkMonster12IdleHeadTurnER6Vector */

	int FOkToSpeak(class CTalkMonster *); /* linkage=_ZN12CTalkMonster10FOkToSpeakEv */

	void TrySmellTalk(class CTalkMonster *); /* linkage=_ZN12CTalkMonster12TrySmellTalkEv */

	class CBaseEntity * EnumFriends(class CTalkMonster *, class CBaseEntity *, int, BOOL); /* linkage=_ZN12CTalkMonster11EnumFriendsEP11CBaseEntityii */

	void AlertFriends(class CTalkMonster *); /* linkage=_ZN12CTalkMonster12AlertFriendsEv */

	void ShutUpFriends(class CTalkMonster *); /* linkage=_ZN12CTalkMonster13ShutUpFriendsEv */

	BOOL IsTalking(class CTalkMonster *); /* linkage=_ZN12CTalkMonster9IsTalkingEv */

	void Talk(class CTalkMonster *, float); /* linkage=_ZN12CTalkMonster4TalkEf */

	BOOL CanFollow(class CTalkMonster *); /* linkage=_ZN12CTalkMonster9CanFollowEv */

	BOOL IsFollowing(class CTalkMonster *); /* linkage=_ZN12CTalkMonster11IsFollowingEv */

	virtual void StopFollowing(class CTalkMonster *, BOOL); /* linkage=_ZN12CTalkMonster13StopFollowingEi */

	void StartFollowing(class CTalkMonster *, class CBaseEntity *); /* linkage=_ZN12CTalkMonster14StartFollowingEP11CBaseEntity */

	virtual void DeclineFollowing(class CTalkMonster *); /* linkage=_ZN12CTalkMonster16DeclineFollowingEv */

	void LimitFollowers(class CTalkMonster *, class CBaseEntity *, int); /* linkage=_ZN12CTalkMonster14LimitFollowersEP11CBaseEntityi */

	void FollowerUse(class CTalkMonster *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN12CTalkMonster11FollowerUseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void SetAnswerQuestion(class CTalkMonster *, class CTalkMonster *); /* linkage=_ZN12CTalkMonster17SetAnswerQuestionEPS_ */

	virtual int FriendNumber(class CTalkMonster *, int); /* linkage=_ZN12CTalkMonster12FriendNumberEi */

	virtual int Save(class CTalkMonster *, class CSave &); /* linkage=_ZN12CTalkMonster4SaveER5CSave */

	virtual int Restore(class CTalkMonster *, class CRestore &); /* linkage=_ZN12CTalkMonster7RestoreER8CRestore */

	virtual class Schedule_t * ScheduleFromName(class CTalkMonster *, const char  *); /* linkage=_ZN12CTalkMonster16ScheduleFromNameEPKc */

	virtual void ~CTalkMonster(class CTalkMonster *, int); /* linkage=_ZN12CTalkMonsterD4Ev */

	/* vtable has 22 entries: {
	   [3] = Precache(_ZN12CTalkMonster8PrecacheEv), 
	   [13] = TakeDamage(_ZN12CTalkMonster10TakeDamageEP9entvars_sS1_fi), 
	   [44] = Touch(_ZN12CTalkMonster5TouchEP11CBaseEntity), 
	   [15] = Killed(_ZN12CTalkMonster6KilledEP9entvars_sS1_i), 
	   [71] = IRelationship(_ZN12CTalkMonster13IRelationshipEP11CBaseEntity), 
	   [96] = CanPlaySentence(_ZN12CTalkMonster15CanPlaySentenceEi), 
	   [97] = PlaySentence(_ZN12CTalkMonster12PlaySentenceEPKcfff), 
	   [98] = PlayScriptedSentence(_ZN12CTalkMonster20PlayScriptedSentenceEPKcfffiP11CBaseEntity), 
	   [4] = KeyValue(_ZN12CTalkMonster8KeyValueEP14KeyValueData_s), 
	   [101] = SetActivity(_ZN12CTalkMonster11SetActivityE8Activity), 
	   [92] = GetScheduleOfType(_ZN12CTalkMonster17GetScheduleOfTypeEi), 
	   [90] = StartTask(_ZN12CTalkMonster9StartTaskEP6Task_t), 
	   [91] = RunTask(_ZN12CTalkMonster7RunTaskEP6Task_t), 
	   [65] = HandleAnimEvent(_ZN12CTalkMonster15HandleAnimEventEP14MonsterEvent_t), 
	   [121] = PrescheduleThink(_ZN12CTalkMonster16PrescheduleThinkEv), 
	   [133] = StopFollowing(_ZN12CTalkMonster13StopFollowingEi), 
	   [134] = DeclineFollowing(_ZN12CTalkMonster16DeclineFollowingEv), 
	   [135] = SetAnswerQuestion(_ZN12CTalkMonster17SetAnswerQuestionEPS_), 
	   [136] = FriendNumber(_ZN12CTalkMonster12FriendNumberEi), 
	   [5] = Save(_ZN12CTalkMonster4SaveER5CSave), 
	   [6] = Restore(_ZN12CTalkMonster7RestoreER8CRestore), 
	   [89] = ScheduleFromName(_ZN12CTalkMonster16ScheduleFromNameEPKc), 
	} */
	/* size: 1836, cachelines: 29, members: 11, static members: 4 */
	/* sum members: 112, holes: 1, sum holes: 1724 */
	/* last cacheline: 44 bytes */
};
class CHalfLifeTeamplay : public CHalfLifeMultiplay {

	/* XXX 16 bytes hole, try to pack */
public:


	/* class CHalfLifeMultiplay  <ancestor>; */      /*     0     0 */
private:

	BOOL                       m_DisableDeathMessages; /*    16     4 */
	BOOL                       m_DisableDeathPenalty; /*    20     4 */
	void CHalfLifeTeamplay(class CHalfLifeTeamplay *, class CHalfLifeTeamplay &); /* linkage=_ZN17CHalfLifeTeamplayC4EOS_ */

	void CHalfLifeTeamplay(class CHalfLifeTeamplay *, const class CHalfLifeTeamplay  &); /* linkage=_ZN17CHalfLifeTeamplayC4ERKS_ */

	void CHalfLifeTeamplay(class CHalfLifeTeamplay *); /* linkage=_ZN17CHalfLifeTeamplayC4Ev */

	virtual void PlayerSpawn(class CHalfLifeTeamplay *, class CBasePlayer *); /* linkage=_ZN17CHalfLifeTeamplay11PlayerSpawnEP11CBasePlayer */

	virtual BOOL ClientCommand(class CHalfLifeTeamplay *, class CBasePlayer *, const char  *); /* linkage=_ZN17CHalfLifeTeamplay13ClientCommandEP11CBasePlayerPKc */

	virtual void ClientUserInfoChanged(class CHalfLifeTeamplay *, class CBasePlayer *, char *); /* linkage=_ZN17CHalfLifeTeamplay21ClientUserInfoChangedEP11CBasePlayerPc */

	virtual BOOL IsTeamplay(class CHalfLifeTeamplay *); /* linkage=_ZN17CHalfLifeTeamplay10IsTeamplayEv */

	virtual BOOL FPlayerCanTakeDamage(class CHalfLifeTeamplay *, class CBasePlayer *, class CBaseEntity *); /* linkage=_ZN17CHalfLifeTeamplay20FPlayerCanTakeDamageEP11CBasePlayerP11CBaseEntity */

	virtual int PlayerRelationship(class CHalfLifeTeamplay *, class CBasePlayer *, class CBaseEntity *); /* linkage=_ZN17CHalfLifeTeamplay18PlayerRelationshipEP11CBasePlayerP11CBaseEntity */

	virtual char * GetTeamID(class CHalfLifeTeamplay *, class CBaseEntity *); /* linkage=_ZN17CHalfLifeTeamplay9GetTeamIDEP11CBaseEntity */

	virtual BOOL ShouldAutoAim(class CHalfLifeTeamplay *, class CBasePlayer *, edict_t *); /* linkage=_ZN17CHalfLifeTeamplay13ShouldAutoAimEP11CBasePlayerP7edict_s */

	virtual int IPointsForKill(class CHalfLifeTeamplay *, class CBasePlayer *, class CBasePlayer *); /* linkage=_ZN17CHalfLifeTeamplay14IPointsForKillEP11CBasePlayerS1_ */

	virtual void InitHUD(class CHalfLifeTeamplay *, class CBasePlayer *); /* linkage=_ZN17CHalfLifeTeamplay7InitHUDEP11CBasePlayer */

	virtual void DeathNotice(class CHalfLifeTeamplay *, class CBasePlayer *, entvars_t *, entvars_t *); /* linkage=_ZN17CHalfLifeTeamplay11DeathNoticeEP11CBasePlayerP9entvars_sS3_ */

	virtual const char  * GetGameDescription(class CHalfLifeTeamplay *); /* linkage=_ZN17CHalfLifeTeamplay18GetGameDescriptionEv */

	virtual void UpdateGameMode(class CHalfLifeTeamplay *, class CBasePlayer *); /* linkage=_ZN17CHalfLifeTeamplay14UpdateGameModeEP11CBasePlayer */

	virtual void PlayerKilled(class CHalfLifeTeamplay *, class CBasePlayer *, entvars_t *, entvars_t *); /* linkage=_ZN17CHalfLifeTeamplay12PlayerKilledEP11CBasePlayerP9entvars_sS3_ */

	/* vtable has 14 entries: {
	   [18] = PlayerSpawn(_ZN17CHalfLifeTeamplay11PlayerSpawnEP11CBasePlayer), 
	   [24] = ClientCommand(_ZN17CHalfLifeTeamplay13ClientCommandEP11CBasePlayerPKc), 
	   [25] = ClientUserInfoChanged(_ZN17CHalfLifeTeamplay21ClientUserInfoChangedEP11CBasePlayerPc), 
	   [8] = IsTeamplay(_ZN17CHalfLifeTeamplay10IsTeamplayEv), 
	   [16] = FPlayerCanTakeDamage(_ZN17CHalfLifeTeamplay20FPlayerCanTakeDamageEP11CBasePlayerP11CBaseEntity), 
	   [50] = PlayerRelationship(_ZN17CHalfLifeTeamplay18PlayerRelationshipEP11CBasePlayerP11CBaseEntity), 
	   [49] = GetTeamID(_ZN17CHalfLifeTeamplay9GetTeamIDEP11CBaseEntity), 
	   [17] = ShouldAutoAim(_ZN17CHalfLifeTeamplay13ShouldAutoAimEP11CBasePlayerP7edict_s), 
	   [26] = IPointsForKill(_ZN17CHalfLifeTeamplay14IPointsForKillEP11CBasePlayerS1_), 
	   [12] = InitHUD(_ZN17CHalfLifeTeamplay7InitHUDEP11CBasePlayer), 
	   [28] = DeathNotice(_ZN17CHalfLifeTeamplay11DeathNoticeEP11CBasePlayerP9entvars_sS3_), 
	   [10] = GetGameDescription(_ZN17CHalfLifeTeamplay18GetGameDescriptionEv), 
	   [14] = UpdateGameMode(_ZN17CHalfLifeTeamplay14UpdateGameModeEP11CBasePlayer), 
	   [27] = PlayerKilled(_ZN17CHalfLifeTeamplay12PlayerKilledEP11CBasePlayerP9entvars_sS3_), 
	} */
	/* size: 24, cachelines: 1, members: 3 */
	/* sum members: 8, holes: 1, sum holes: 16 */
	/* last cacheline: 24 bytes */
};
class CGhost : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CGhost(class CGhost *, class CGhost &); /* linkage=_ZN6CGhostC4EOS_ */

	void CGhost(class CGhost *, const class CGhost  &); /* linkage=_ZN6CGhostC4ERKS_ */

	void CGhost(class CGhost *); /* linkage=_ZN6CGhostC4Ev */

	virtual void ~CGhost(class CGhost *, int); /* linkage=_ZN6CGhostD4Ev */


	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CTeamFortress : public CHalfLifeTeamplay {

	/* XXX 24 bytes hole, try to pack */
public:


	/* class CHalfLifeTeamplay   <ancestor>; */      /*     0     0 */
	class CVoiceGameMgr       m_VoiceGameMgr;        /*    24     0 */
	void CTeamFortress(class CTeamFortress *, class CTeamFortress &); /* linkage=_ZN13CTeamFortressC4EOS_ */

	void CTeamFortress(class CTeamFortress *, const class CTeamFortress  &); /* linkage=_ZN13CTeamFortressC4ERKS_ */

	void CTeamFortress(class CTeamFortress *); /* linkage=_ZN13CTeamFortressC4Ev */

	virtual void Think(class CTeamFortress *); /* linkage=_ZN13CTeamFortress5ThinkEv */

	virtual BOOL IsTeamplay(class CTeamFortress *); /* linkage=_ZN13CTeamFortress10IsTeamplayEv */

	virtual void PlayerSpawn(class CTeamFortress *, class CBasePlayer *); /* linkage=_ZN13CTeamFortress11PlayerSpawnEP11CBasePlayer */

	virtual BOOL ClientCommand(class CTeamFortress *, class CBasePlayer *, const char  *); /* linkage=_ZN13CTeamFortress13ClientCommandEP11CBasePlayerPKc */

	virtual void ClientUserInfoChanged(class CTeamFortress *, class CBasePlayer *, char *); /* linkage=_ZN13CTeamFortress21ClientUserInfoChangedEP11CBasePlayerPc */

	virtual int DeadPlayerWeapons(class CTeamFortress *, class CBasePlayer *); /* linkage=_ZN13CTeamFortress17DeadPlayerWeaponsEP11CBasePlayer */

	virtual int DeadPlayerAmmo(class CTeamFortress *, class CBasePlayer *); /* linkage=_ZN13CTeamFortress14DeadPlayerAmmoEP11CBasePlayer */

	virtual float FlItemRespawnTime(class CTeamFortress *, class CItem *); /* linkage=_ZN13CTeamFortress17FlItemRespawnTimeEP5CItem */

	virtual BOOL CanHaveItem(class CTeamFortress *, class CBasePlayer *, class CItem *); /* linkage=_ZN13CTeamFortress11CanHaveItemEP11CBasePlayerP5CItem */

	virtual const char  * GetGameDescription(class CTeamFortress *); /* linkage=_ZN13CTeamFortress18GetGameDescriptionEv */

	virtual char * GetTeamID(class CTeamFortress *, class CBaseEntity *); /* linkage=_ZN13CTeamFortress9GetTeamIDEP11CBaseEntity */

	virtual void InitHUD(class CTeamFortress *, class CBasePlayer *); /* linkage=_ZN13CTeamFortress7InitHUDEP11CBasePlayer */

	virtual BOOL ClientConnected(class CTeamFortress *, edict_t *, const char  *, const char  *, char *); /* linkage=_ZN13CTeamFortress15ClientConnectedEP7edict_sPKcS3_Pc */

	virtual void GoToIntermission(class CTeamFortress *); /* linkage=_ZN13CTeamFortress16GoToIntermissionEv */

	/* vtable has 14 entries: {
	   [1] = Think(_ZN13CTeamFortress5ThinkEv), 
	   [8] = IsTeamplay(_ZN13CTeamFortress10IsTeamplayEv), 
	   [18] = PlayerSpawn(_ZN13CTeamFortress11PlayerSpawnEP11CBasePlayer), 
	   [24] = ClientCommand(_ZN13CTeamFortress13ClientCommandEP11CBasePlayerPKc), 
	   [25] = ClientUserInfoChanged(_ZN13CTeamFortress21ClientUserInfoChangedEP11CBasePlayerPc), 
	   [47] = DeadPlayerWeapons(_ZN13CTeamFortress17DeadPlayerWeaponsEP11CBasePlayer), 
	   [48] = DeadPlayerAmmo(_ZN13CTeamFortress14DeadPlayerAmmoEP11CBasePlayer), 
	   [38] = FlItemRespawnTime(_ZN13CTeamFortress17FlItemRespawnTimeEP5CItem), 
	   [35] = CanHaveItem(_ZN13CTeamFortress11CanHaveItemEP11CBasePlayerP5CItem), 
	   [10] = GetGameDescription(_ZN13CTeamFortress18GetGameDescriptionEv), 
	   [49] = GetTeamID(_ZN13CTeamFortress9GetTeamIDEP11CBaseEntity), 
	   [12] = InitHUD(_ZN13CTeamFortress7InitHUDEP11CBasePlayer), 
	   [11] = ClientConnected(_ZN13CTeamFortress15ClientConnectedEP7edict_sPKcS3_Pc), 
	   [54] = GoToIntermission(_ZN13CTeamFortress16GoToIntermissionEv), 
	} */
	/* size: 52, cachelines: 1, members: 2 */
	/* padding: 28 */
	/* last cacheline: 52 bytes */
};
class TFGameMgrHelper : public IVoiceGameMgrHelper {
public:

	/* class IVoiceGameMgrHelper <ancestor>; */      /*     0     4 */
	void TFGameMgrHelper(class TFGameMgrHelper *, class TFGameMgrHelper &); /* linkage=_ZN15TFGameMgrHelperC4EOS_ */

	void TFGameMgrHelper(class TFGameMgrHelper *, const class TFGameMgrHelper  &); /* linkage=_ZN15TFGameMgrHelperC4ERKS_ */

	void TFGameMgrHelper(class TFGameMgrHelper *); /* linkage=_ZN15TFGameMgrHelperC4Ev */

	virtual bool CanPlayerHearPlayer(class TFGameMgrHelper *, class CBasePlayer *, class CBasePlayer *); /* linkage=_ZN15TFGameMgrHelper19CanPlayerHearPlayerEP11CBasePlayerS1_ */

	virtual void ~TFGameMgrHelper(class TFGameMgrHelper *, int); /* linkage=_ZN15TFGameMgrHelperD4Ev */

	/* vtable has 1 entries: {
	   [2] = CanPlayerHearPlayer(_ZN15TFGameMgrHelper19CanPlayerHearPlayerEP11CBasePlayerS1_), 
	} */
	/* size: 4, cachelines: 1, members: 1 */
	/* last cacheline: 4 bytes */
};
class IVoiceGameMgrHelper {
	int ()(void) * *           _vptr.IVoiceGameMgrHelper; /*     0     4 */
	void IVoiceGameMgrHelper(class IVoiceGameMgrHelper *, const class IVoiceGameMgrHelper  &); /* linkage=_ZN19IVoiceGameMgrHelperC4ERKS_ */

	void IVoiceGameMgrHelper(class IVoiceGameMgrHelper *); /* linkage=_ZN19IVoiceGameMgrHelperC4Ev */

	virtual void ~IVoiceGameMgrHelper(class IVoiceGameMgrHelper *, int); /* linkage=_ZN19IVoiceGameMgrHelperD4Ev */

	virtual bool CanPlayerHearPlayer(class IVoiceGameMgrHelper *, class CBasePlayer *, class CBasePlayer *); /* linkage=_ZN19IVoiceGameMgrHelper19CanPlayerHearPlayerEP11CBasePlayerS1_ */

	/* vtable has 1 entries: {
	   [2] = CanPlayerHearPlayer(_ZN19IVoiceGameMgrHelper19CanPlayerHearPlayerEP11CBasePlayerS1_), 
	} */
	/* size: 4, cachelines: 1, members: 1 */
	/* last cacheline: 4 bytes */
};
class CItemPowerupQuad : public CItemPowerup {
public:

	/* class CItemPowerup        <ancestor>; */      /*     0  1144 */

	/* XXX last struct has 1144 bytes of padding */
	void CItemPowerupQuad(class CItemPowerupQuad *, class CItemPowerupQuad &); /* linkage=_ZN16CItemPowerupQuadC4EOS_ */

	void CItemPowerupQuad(class CItemPowerupQuad *, const class CItemPowerupQuad  &); /* linkage=_ZN16CItemPowerupQuadC4ERKS_ */

	void CItemPowerupQuad(class CItemPowerupQuad *); /* linkage=_ZN16CItemPowerupQuadC4Ev */

	virtual void Spawn(class CItemPowerupQuad *); /* linkage=_ZN16CItemPowerupQuad5SpawnEv */

	virtual void Precache(class CItemPowerupQuad *); /* linkage=_ZN16CItemPowerupQuad8PrecacheEv */

	virtual void ~CItemPowerupQuad(class CItemPowerupQuad *, int); /* linkage=_ZN16CItemPowerupQuadD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN16CItemPowerupQuad5SpawnEv), 
	   [3] = Precache(_ZN16CItemPowerupQuad8PrecacheEv), 
	} */
	/* size: 1144, cachelines: 18, members: 1 */
	/* paddings: 1, sum paddings: 1144 */
	/* last cacheline: 56 bytes */
};
class CItemPowerup : public CItem {
public:

	/* class CItem               <ancestor>; */      /*     0     0 */
	void CItemPowerup(class CItemPowerup *, class CItemPowerup &); /* linkage=_ZN12CItemPowerupC4EOS_ */

	void CItemPowerup(class CItemPowerup *, const class CItemPowerup  &); /* linkage=_ZN12CItemPowerupC4ERKS_ */

	void CItemPowerup(class CItemPowerup *); /* linkage=_ZN12CItemPowerupC4Ev */

	virtual void Spawn(class CItemPowerup *); /* linkage=_ZN12CItemPowerup5SpawnEv */

	virtual BOOL MyTouch(class CItemPowerup *, class CBasePlayer *); /* linkage=_ZN12CItemPowerup7MyTouchEP11CBasePlayer */

	virtual void ~CItemPowerup(class CItemPowerup *, int); /* linkage=_ZN12CItemPowerupD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN12CItemPowerup5SpawnEv), 
	   [65] = MyTouch(_ZN12CItemPowerup7MyTouchEP11CBasePlayer), 
	} */
	/* size: 1144, cachelines: 18, members: 1 */
	/* padding: 1144 */
	/* last cacheline: 56 bytes */
};
class CItemPowerupInvisibility : public CItemPowerup {
public:

	/* class CItemPowerup        <ancestor>; */      /*     0  1144 */

	/* XXX last struct has 1144 bytes of padding */
	void CItemPowerupInvisibility(class CItemPowerupInvisibility *, class CItemPowerupInvisibility &); /* linkage=_ZN24CItemPowerupInvisibilityC4EOS_ */

	void CItemPowerupInvisibility(class CItemPowerupInvisibility *, const class CItemPowerupInvisibility  &); /* linkage=_ZN24CItemPowerupInvisibilityC4ERKS_ */

	void CItemPowerupInvisibility(class CItemPowerupInvisibility *); /* linkage=_ZN24CItemPowerupInvisibilityC4Ev */

	virtual void Spawn(class CItemPowerupInvisibility *); /* linkage=_ZN24CItemPowerupInvisibility5SpawnEv */

	virtual void Precache(class CItemPowerupInvisibility *); /* linkage=_ZN24CItemPowerupInvisibility8PrecacheEv */

	virtual void ~CItemPowerupInvisibility(class CItemPowerupInvisibility *, int); /* linkage=_ZN24CItemPowerupInvisibilityD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN24CItemPowerupInvisibility5SpawnEv), 
	   [3] = Precache(_ZN24CItemPowerupInvisibility8PrecacheEv), 
	} */
	/* size: 1144, cachelines: 18, members: 1 */
	/* paddings: 1, sum paddings: 1144 */
	/* last cacheline: 56 bytes */
};
class CItemPowerupRadsuit : public CItemPowerup {
public:

	/* class CItemPowerup        <ancestor>; */      /*     0  1144 */

	/* XXX last struct has 1144 bytes of padding */
	void CItemPowerupRadsuit(class CItemPowerupRadsuit *, class CItemPowerupRadsuit &); /* linkage=_ZN19CItemPowerupRadsuitC4EOS_ */

	void CItemPowerupRadsuit(class CItemPowerupRadsuit *, const class CItemPowerupRadsuit  &); /* linkage=_ZN19CItemPowerupRadsuitC4ERKS_ */

	void CItemPowerupRadsuit(class CItemPowerupRadsuit *); /* linkage=_ZN19CItemPowerupRadsuitC4Ev */

	virtual void Spawn(class CItemPowerupRadsuit *); /* linkage=_ZN19CItemPowerupRadsuit5SpawnEv */

	virtual void Precache(class CItemPowerupRadsuit *); /* linkage=_ZN19CItemPowerupRadsuit8PrecacheEv */

	virtual void ~CItemPowerupRadsuit(class CItemPowerupRadsuit *, int); /* linkage=_ZN19CItemPowerupRadsuitD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN19CItemPowerupRadsuit5SpawnEv), 
	   [3] = Precache(_ZN19CItemPowerupRadsuit8PrecacheEv), 
	} */
	/* size: 1144, cachelines: 18, members: 1 */
	/* paddings: 1, sum paddings: 1144 */
	/* last cacheline: 56 bytes */
};
class CItemPowerupInvincible : public CItemPowerup {
public:

	/* class CItemPowerup        <ancestor>; */      /*     0  1144 */

	/* XXX last struct has 1144 bytes of padding */
	void CItemPowerupInvincible(class CItemPowerupInvincible *, class CItemPowerupInvincible &); /* linkage=_ZN22CItemPowerupInvincibleC4EOS_ */

	void CItemPowerupInvincible(class CItemPowerupInvincible *, const class CItemPowerupInvincible  &); /* linkage=_ZN22CItemPowerupInvincibleC4ERKS_ */

	void CItemPowerupInvincible(class CItemPowerupInvincible *); /* linkage=_ZN22CItemPowerupInvincibleC4Ev */

	virtual void Spawn(class CItemPowerupInvincible *); /* linkage=_ZN22CItemPowerupInvincible5SpawnEv */

	virtual void Precache(class CItemPowerupInvincible *); /* linkage=_ZN22CItemPowerupInvincible8PrecacheEv */

	virtual void ~CItemPowerupInvincible(class CItemPowerupInvincible *, int); /* linkage=_ZN22CItemPowerupInvincibleD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN22CItemPowerupInvincible5SpawnEv), 
	   [3] = Precache(_ZN22CItemPowerupInvincible8PrecacheEv), 
	} */
	/* size: 1144, cachelines: 18, members: 1 */
	/* paddings: 1, sum paddings: 1144 */
	/* last cacheline: 56 bytes */
};
class CItemAmmoCells : public CItemAmmo {
public:

	/* class CItemAmmo           <ancestor>; */      /*     0  1152 */

	/* XXX last struct has 1 hole */
	void CItemAmmoCells(class CItemAmmoCells *, class CItemAmmoCells &); /* linkage=_ZN14CItemAmmoCellsC4EOS_ */

	void CItemAmmoCells(class CItemAmmoCells *, const class CItemAmmoCells  &); /* linkage=_ZN14CItemAmmoCellsC4ERKS_ */

	void CItemAmmoCells(class CItemAmmoCells *); /* linkage=_ZN14CItemAmmoCellsC4Ev */

	virtual void Spawn(class CItemAmmoCells *); /* linkage=_ZN14CItemAmmoCells5SpawnEv */

	virtual void Precache(class CItemAmmoCells *); /* linkage=_ZN14CItemAmmoCells8PrecacheEv */

	virtual void ~CItemAmmoCells(class CItemAmmoCells *, int); /* linkage=_ZN14CItemAmmoCellsD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN14CItemAmmoCells5SpawnEv), 
	   [3] = Precache(_ZN14CItemAmmoCells8PrecacheEv), 
	} */
	/* size: 1152, cachelines: 18, members: 1 */
	/* member types with holes: 1, total: 1 */
};
class CItemAmmo : public CItem {

	/* XXX 1144 bytes hole, try to pack */
public:


	/* class CItem               <ancestor>; */      /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 56 bytes ago --- */
	int                        m_isSmallBox;         /*  1144     4 */
	int                        m_isLargeBox;         /*  1148     4 */
	void CItemAmmo(class CItemAmmo *, class CItemAmmo &); /* linkage=_ZN9CItemAmmoC4EOS_ */

	void CItemAmmo(class CItemAmmo *, const class CItemAmmo  &); /* linkage=_ZN9CItemAmmoC4ERKS_ */

	void CItemAmmo(class CItemAmmo *); /* linkage=_ZN9CItemAmmoC4Ev */

	virtual void Spawn(class CItemAmmo *); /* linkage=_ZN9CItemAmmo5SpawnEv */

	virtual void Precache(class CItemAmmo *); /* linkage=_ZN9CItemAmmo8PrecacheEv */

	virtual BOOL MyTouch(class CItemAmmo *, class CBasePlayer *); /* linkage=_ZN9CItemAmmo7MyTouchEP11CBasePlayer */

	virtual BOOL GetGrenadePossibility(class CItemAmmo *, class CBasePlayer *); /* linkage=_ZN9CItemAmmo21GetGrenadePossibilityEP11CBasePlayer */

	virtual void ~CItemAmmo(class CItemAmmo *, int); /* linkage=_ZN9CItemAmmoD4Ev */

	/* vtable has 4 entries: {
	   [2] = Spawn(_ZN9CItemAmmo5SpawnEv), 
	   [3] = Precache(_ZN9CItemAmmo8PrecacheEv), 
	   [65] = MyTouch(_ZN9CItemAmmo7MyTouchEP11CBasePlayer), 
	   [66] = GetGrenadePossibility(_ZN9CItemAmmo21GetGrenadePossibilityEP11CBasePlayer), 
	} */
	/* size: 1152, cachelines: 18, members: 3 */
	/* sum members: 8, holes: 1, sum holes: 1144 */
};
class CItemAmmoRockets : public CItemAmmo {
public:

	/* class CItemAmmo           <ancestor>; */      /*     0  1152 */

	/* XXX last struct has 1 hole */
	void CItemAmmoRockets(class CItemAmmoRockets *, class CItemAmmoRockets &); /* linkage=_ZN16CItemAmmoRocketsC4EOS_ */

	void CItemAmmoRockets(class CItemAmmoRockets *, const class CItemAmmoRockets  &); /* linkage=_ZN16CItemAmmoRocketsC4ERKS_ */

	void CItemAmmoRockets(class CItemAmmoRockets *); /* linkage=_ZN16CItemAmmoRocketsC4Ev */

	virtual void Spawn(class CItemAmmoRockets *); /* linkage=_ZN16CItemAmmoRockets5SpawnEv */

	virtual void Precache(class CItemAmmoRockets *); /* linkage=_ZN16CItemAmmoRockets8PrecacheEv */

	virtual BOOL GetGrenadePossibility(class CItemAmmoRockets *, class CBasePlayer *); /* linkage=_ZN16CItemAmmoRockets21GetGrenadePossibilityEP11CBasePlayer */

	virtual void ~CItemAmmoRockets(class CItemAmmoRockets *, int); /* linkage=_ZN16CItemAmmoRocketsD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN16CItemAmmoRockets5SpawnEv), 
	   [3] = Precache(_ZN16CItemAmmoRockets8PrecacheEv), 
	   [66] = GetGrenadePossibility(_ZN16CItemAmmoRockets21GetGrenadePossibilityEP11CBasePlayer), 
	} */
	/* size: 1152, cachelines: 18, members: 1 */
	/* member types with holes: 1, total: 1 */
};
class CItemAmmoNails : public CItemAmmo {
public:

	/* class CItemAmmo           <ancestor>; */      /*     0  1152 */

	/* XXX last struct has 1 hole */
	void CItemAmmoNails(class CItemAmmoNails *, class CItemAmmoNails &); /* linkage=_ZN14CItemAmmoNailsC4EOS_ */

	void CItemAmmoNails(class CItemAmmoNails *, const class CItemAmmoNails  &); /* linkage=_ZN14CItemAmmoNailsC4ERKS_ */

	void CItemAmmoNails(class CItemAmmoNails *); /* linkage=_ZN14CItemAmmoNailsC4Ev */

	virtual void Spawn(class CItemAmmoNails *); /* linkage=_ZN14CItemAmmoNails5SpawnEv */

	virtual void Precache(class CItemAmmoNails *); /* linkage=_ZN14CItemAmmoNails8PrecacheEv */

	virtual void ~CItemAmmoNails(class CItemAmmoNails *, int); /* linkage=_ZN14CItemAmmoNailsD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN14CItemAmmoNails5SpawnEv), 
	   [3] = Precache(_ZN14CItemAmmoNails8PrecacheEv), 
	} */
	/* size: 1152, cachelines: 18, members: 1 */
	/* member types with holes: 1, total: 1 */
};
class CItemAmmoShells : public CItemAmmo {
public:

	/* class CItemAmmo           <ancestor>; */      /*     0  1152 */

	/* XXX last struct has 1 hole */
	void CItemAmmoShells(class CItemAmmoShells *, class CItemAmmoShells &); /* linkage=_ZN15CItemAmmoShellsC4EOS_ */

	void CItemAmmoShells(class CItemAmmoShells *, const class CItemAmmoShells  &); /* linkage=_ZN15CItemAmmoShellsC4ERKS_ */

	void CItemAmmoShells(class CItemAmmoShells *); /* linkage=_ZN15CItemAmmoShellsC4Ev */

	virtual void Spawn(class CItemAmmoShells *); /* linkage=_ZN15CItemAmmoShells5SpawnEv */

	virtual void Precache(class CItemAmmoShells *); /* linkage=_ZN15CItemAmmoShells8PrecacheEv */

	virtual void ~CItemAmmoShells(class CItemAmmoShells *, int); /* linkage=_ZN15CItemAmmoShellsD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN15CItemAmmoShells5SpawnEv), 
	   [3] = Precache(_ZN15CItemAmmoShells8PrecacheEv), 
	} */
	/* size: 1152, cachelines: 18, members: 1 */
	/* member types with holes: 1, total: 1 */
};
class CItemArmorRed : public CItemArmor {
public:

	/* class CItemArmor          <ancestor>; */      /*     0  1152 */

	/* XXX last struct has 1 hole */
	void CItemArmorRed(class CItemArmorRed *, class CItemArmorRed &); /* linkage=_ZN13CItemArmorRedC4EOS_ */

	void CItemArmorRed(class CItemArmorRed *, const class CItemArmorRed  &); /* linkage=_ZN13CItemArmorRedC4ERKS_ */

	void CItemArmorRed(class CItemArmorRed *); /* linkage=_ZN13CItemArmorRedC4Ev */

	virtual void Spawn(class CItemArmorRed *); /* linkage=_ZN13CItemArmorRed5SpawnEv */

	virtual void Precache(class CItemArmorRed *); /* linkage=_ZN13CItemArmorRed8PrecacheEv */

	virtual void ~CItemArmorRed(class CItemArmorRed *, int); /* linkage=_ZN13CItemArmorRedD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN13CItemArmorRed5SpawnEv), 
	   [3] = Precache(_ZN13CItemArmorRed8PrecacheEv), 
	} */
	/* size: 1152, cachelines: 18, members: 1 */
	/* member types with holes: 1, total: 1 */
};
class CItemArmor : public CItem {

	/* XXX 1144 bytes hole, try to pack */
public:


	/* class CItem               <ancestor>; */      /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 56 bytes ago --- */
	float                      m_flArmorCount;       /*  1144     4 */
	float                      m_flArmorType;        /*  1148     4 */
	void CItemArmor(class CItemArmor *, class CItemArmor &); /* linkage=_ZN10CItemArmorC4EOS_ */

	void CItemArmor(class CItemArmor *, const class CItemArmor  &); /* linkage=_ZN10CItemArmorC4ERKS_ */

	void CItemArmor(class CItemArmor *); /* linkage=_ZN10CItemArmorC4Ev */

	virtual BOOL MyTouch(class CItemArmor *, class CBasePlayer *); /* linkage=_ZN10CItemArmor7MyTouchEP11CBasePlayer */

	int CalculateBit(class CItemArmor *, float); /* linkage=_ZN10CItemArmor12CalculateBitEf */

	virtual void ~CItemArmor(class CItemArmor *, int); /* linkage=_ZN10CItemArmorD4Ev */

	/* vtable has 1 entries: {
	   [65] = MyTouch(_ZN10CItemArmor7MyTouchEP11CBasePlayer), 
	} */
	/* size: 1152, cachelines: 18, members: 3 */
	/* sum members: 8, holes: 1, sum holes: 1144 */
};
class CItemArmorYellow : public CItemArmor {
public:

	/* class CItemArmor          <ancestor>; */      /*     0  1152 */

	/* XXX last struct has 1 hole */
	void CItemArmorYellow(class CItemArmorYellow *, class CItemArmorYellow &); /* linkage=_ZN16CItemArmorYellowC4EOS_ */

	void CItemArmorYellow(class CItemArmorYellow *, const class CItemArmorYellow  &); /* linkage=_ZN16CItemArmorYellowC4ERKS_ */

	void CItemArmorYellow(class CItemArmorYellow *); /* linkage=_ZN16CItemArmorYellowC4Ev */

	virtual void Spawn(class CItemArmorYellow *); /* linkage=_ZN16CItemArmorYellow5SpawnEv */

	virtual void Precache(class CItemArmorYellow *); /* linkage=_ZN16CItemArmorYellow8PrecacheEv */

	virtual void ~CItemArmorYellow(class CItemArmorYellow *, int); /* linkage=_ZN16CItemArmorYellowD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN16CItemArmorYellow5SpawnEv), 
	   [3] = Precache(_ZN16CItemArmorYellow8PrecacheEv), 
	} */
	/* size: 1152, cachelines: 18, members: 1 */
	/* member types with holes: 1, total: 1 */
};
class CItemArmorGreen : public CItemArmor {
public:

	/* class CItemArmor          <ancestor>; */      /*     0  1152 */

	/* XXX last struct has 1 hole */
	void CItemArmorGreen(class CItemArmorGreen *, class CItemArmorGreen &); /* linkage=_ZN15CItemArmorGreenC4EOS_ */

	void CItemArmorGreen(class CItemArmorGreen *, const class CItemArmorGreen  &); /* linkage=_ZN15CItemArmorGreenC4ERKS_ */

	void CItemArmorGreen(class CItemArmorGreen *); /* linkage=_ZN15CItemArmorGreenC4Ev */

	virtual void Spawn(class CItemArmorGreen *); /* linkage=_ZN15CItemArmorGreen5SpawnEv */

	virtual void Precache(class CItemArmorGreen *); /* linkage=_ZN15CItemArmorGreen8PrecacheEv */

	virtual void ~CItemArmorGreen(class CItemArmorGreen *, int); /* linkage=_ZN15CItemArmorGreenD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN15CItemArmorGreen5SpawnEv), 
	   [3] = Precache(_ZN15CItemArmorGreen8PrecacheEv), 
	} */
	/* size: 1152, cachelines: 18, members: 1 */
	/* member types with holes: 1, total: 1 */
};
class CItemHealth : public CItem {

	/* XXX 1144 bytes hole, try to pack */
public:


	/* class CItem               <ancestor>; */      /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 56 bytes ago --- */
	int                        m_iHealAmount;        /*  1144     4 */
	int                        m_iHealType;          /*  1148     4 */
	void CItemHealth(class CItemHealth *, class CItemHealth &); /* linkage=_ZN11CItemHealthC4EOS_ */

	void CItemHealth(class CItemHealth *, const class CItemHealth  &); /* linkage=_ZN11CItemHealthC4ERKS_ */

	void CItemHealth(class CItemHealth *); /* linkage=_ZN11CItemHealthC4Ev */

	virtual void Spawn(class CItemHealth *); /* linkage=_ZN11CItemHealth5SpawnEv */

	virtual void Precache(class CItemHealth *); /* linkage=_ZN11CItemHealth8PrecacheEv */

	virtual BOOL MyTouch(class CItemHealth *, class CBasePlayer *); /* linkage=_ZN11CItemHealth7MyTouchEP11CBasePlayer */

	virtual void ~CItemHealth(class CItemHealth *, int); /* linkage=_ZN11CItemHealthD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN11CItemHealth5SpawnEv), 
	   [3] = Precache(_ZN11CItemHealth8PrecacheEv), 
	   [65] = MyTouch(_ZN11CItemHealth7MyTouchEP11CBasePlayer), 
	} */
	/* size: 1152, cachelines: 18, members: 3 */
	/* sum members: 8, holes: 1, sum holes: 1144 */
};
class CTFGasGrenade : public CTFPrimeGrenade {
public:

	/* class CTFPrimeGrenade     <ancestor>; */      /*     0  1760 */

	/* XXX last struct has 1 hole */
protected:


	/* --- cacheline 27 boundary (1728 bytes) was 32 bytes ago --- */
	int                        gasCharges;           /*  1760     4 */
	void CTFGasGrenade(class CTFGasGrenade *, class CTFGasGrenade &); /* linkage=_ZN13CTFGasGrenadeC4EOS_ */

	void CTFGasGrenade(class CTFGasGrenade *, const class CTFGasGrenade  &); /* linkage=_ZN13CTFGasGrenadeC4ERKS_ */

	void CTFGasGrenade(class CTFGasGrenade *); /* linkage=_ZN13CTFGasGrenadeC4Ev */

	virtual void Precache(class CTFGasGrenade *); /* linkage=_ZN13CTFGasGrenade8PrecacheEv */

	class CGrenade * Prime(class CBaseEntity *); /* linkage=_ZN13CTFGasGrenade5PrimeEP11CBaseEntity */

	virtual void Explode(class CTFGasGrenade *, class  *, int); /* linkage=_ZN13CTFGasGrenade7ExplodeEP11TraceResulti */

	void GasThePlace(class CTFGasGrenade *); /* linkage=_ZN13CTFGasGrenade11GasThePlaceEv */

	virtual void setName(class CTFGasGrenade *); /* linkage=_ZN13CTFGasGrenade7setNameEv */

	virtual void setDamage(class CTFGasGrenade *); /* linkage=_ZN13CTFGasGrenade9setDamageEv */

	virtual void setRadius(class CTFGasGrenade *); /* linkage=_ZN13CTFGasGrenade9setRadiusEv */

	virtual void setModel(class CTFGasGrenade *); /* linkage=_ZN13CTFGasGrenade8setModelEv */

	virtual void ~CTFGasGrenade(class CTFGasGrenade *, int); /* linkage=_ZN13CTFGasGrenadeD4Ev */

	/* vtable has 6 entries: {
	   [3] = Precache(_ZN13CTFGasGrenade8PrecacheEv), 
	   [135] = Explode(_ZN13CTFGasGrenade7ExplodeEP11TraceResulti), 
	   [141] = setName(_ZN13CTFGasGrenade7setNameEv), 
	   [142] = setDamage(_ZN13CTFGasGrenade9setDamageEv), 
	   [143] = setRadius(_ZN13CTFGasGrenade9setRadiusEv), 
	   [137] = setModel(_ZN13CTFGasGrenade8setModelEv), 
	} */
	/* size: 1764, cachelines: 28, members: 2 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 36 bytes */
};
class CTFPrimeGrenade : public CGrenade {

	/* XXX 1752 bytes hole, try to pack */
public:


	/* class CGrenade            <ancestor>; */      /*     0     0 */
protected:

	/* --- cacheline 27 boundary (1728 bytes) was 24 bytes ago --- */
	float                      heat;                 /*  1752     4 */
	float                      blastRadius;          /*  1756     4 */
	void CTFPrimeGrenade(class CTFPrimeGrenade *, class CTFPrimeGrenade &); /* linkage=_ZN15CTFPrimeGrenadeC4EOS_ */

	void CTFPrimeGrenade(class CTFPrimeGrenade *, const class CTFPrimeGrenade  &); /* linkage=_ZN15CTFPrimeGrenadeC4ERKS_ */

	void CTFPrimeGrenade(class CTFPrimeGrenade *); /* linkage=_ZN15CTFPrimeGrenadeC4Ev */

	void InitPriming(class CTFPrimeGrenade *, class CBaseEntity *); /* linkage=_ZN15CTFPrimeGrenade11InitPrimingEP11CBaseEntity */

	BOOL canPrime(class CBaseEntity *); /* linkage=_ZN15CTFPrimeGrenade8canPrimeEP11CBaseEntity */

	virtual void Spawn(class CTFPrimeGrenade *); /* linkage=_ZN15CTFPrimeGrenade5SpawnEv */

	virtual void Precache(class CTFPrimeGrenade *); /* linkage=_ZN15CTFPrimeGrenade8PrecacheEv */

	void GrenadePrimed(class CTFPrimeGrenade *); /* linkage=_ZN15CTFPrimeGrenade13GrenadePrimedEv */

	void ExplodeInHand(class CTFPrimeGrenade *); /* linkage=_ZN15CTFPrimeGrenade13ExplodeInHandEv */

	void Throw(class CTFPrimeGrenade *); /* linkage=_ZN15CTFPrimeGrenade5ThrowEv */

	void DeadThrow(class CTFPrimeGrenade *); /* linkage=_ZN15CTFPrimeGrenade9DeadThrowEv */

	virtual float getPrimeTime(class CTFPrimeGrenade *); /* linkage=_ZN15CTFPrimeGrenade12getPrimeTimeEv */

	virtual float getPinTime(class CTFPrimeGrenade *); /* linkage=_ZN15CTFPrimeGrenade10getPinTimeEv */

	virtual void setName(class CTFPrimeGrenade *); /* linkage=_ZN15CTFPrimeGrenade7setNameEv */

	virtual void setDamage(class CTFPrimeGrenade *); /* linkage=_ZN15CTFPrimeGrenade9setDamageEv */

	virtual void setRadius(class CTFPrimeGrenade *); /* linkage=_ZN15CTFPrimeGrenade9setRadiusEv */

	virtual void TakeEMPBlast(class CTFPrimeGrenade *, entvars_t *); /* linkage=_ZN15CTFPrimeGrenade12TakeEMPBlastEP9entvars_s */

	virtual void ~CTFPrimeGrenade(class CTFPrimeGrenade *, int); /* linkage=_ZN15CTFPrimeGrenadeD4Ev */

	/* vtable has 8 entries: {
	   [2] = Spawn(_ZN15CTFPrimeGrenade5SpawnEv), 
	   [3] = Precache(_ZN15CTFPrimeGrenade8PrecacheEv), 
	   [139] = getPrimeTime(_ZN15CTFPrimeGrenade12getPrimeTimeEv), 
	   [140] = getPinTime(_ZN15CTFPrimeGrenade10getPinTimeEv), 
	   [141] = setName(_ZN15CTFPrimeGrenade7setNameEv), 
	   [142] = setDamage(_ZN15CTFPrimeGrenade9setDamageEv), 
	   [143] = setRadius(_ZN15CTFPrimeGrenade9setRadiusEv), 
	   [144] = TakeEMPBlast(_ZN15CTFPrimeGrenade12TakeEMPBlastEP9entvars_s), 
	} */
	/* size: 1760, cachelines: 28, members: 3 */
	/* sum members: 8, holes: 1, sum holes: 1752 */
	/* last cacheline: 32 bytes */
};
class CTFEMPGrenade : public CTFPrimeGrenade {
public:

	/* class CTFPrimeGrenade     <ancestor>; */      /*     0  1760 */

	/* XXX last struct has 1 hole */

	static int                        BlastTexture;  /*     0     0 */
	void CTFEMPGrenade(class CTFEMPGrenade *, class CTFEMPGrenade &); /* linkage=_ZN13CTFEMPGrenadeC4EOS_ */

	void CTFEMPGrenade(class CTFEMPGrenade *, const class CTFEMPGrenade  &); /* linkage=_ZN13CTFEMPGrenadeC4ERKS_ */

	void CTFEMPGrenade(class CTFEMPGrenade *); /* linkage=_ZN13CTFEMPGrenadeC4Ev */

	virtual void Precache(class CTFEMPGrenade *); /* linkage=_ZN13CTFEMPGrenade8PrecacheEv */

	class CGrenade * Prime(class CBaseEntity *); /* linkage=_ZN13CTFEMPGrenade5PrimeEP11CBaseEntity */

	virtual void Explode(class CTFEMPGrenade *, class  *, int); /* linkage=_ZN13CTFEMPGrenade7ExplodeEP11TraceResulti */

	virtual void setName(class CTFEMPGrenade *); /* linkage=_ZN13CTFEMPGrenade7setNameEv */

	virtual void setDamage(class CTFEMPGrenade *); /* linkage=_ZN13CTFEMPGrenade9setDamageEv */

	virtual void setRadius(class CTFEMPGrenade *); /* linkage=_ZN13CTFEMPGrenade9setRadiusEv */

	virtual void setModel(class CTFEMPGrenade *); /* linkage=_ZN13CTFEMPGrenade8setModelEv */

	virtual void ~CTFEMPGrenade(class CTFEMPGrenade *, int); /* linkage=_ZN13CTFEMPGrenadeD4Ev */

	/* vtable has 6 entries: {
	   [3] = Precache(_ZN13CTFEMPGrenade8PrecacheEv), 
	   [135] = Explode(_ZN13CTFEMPGrenade7ExplodeEP11TraceResulti), 
	   [141] = setName(_ZN13CTFEMPGrenade7setNameEv), 
	   [142] = setDamage(_ZN13CTFEMPGrenade9setDamageEv), 
	   [143] = setRadius(_ZN13CTFEMPGrenade9setRadiusEv), 
	   [137] = setModel(_ZN13CTFEMPGrenade8setModelEv), 
	} */
	/* size: 1760, cachelines: 28, members: 1, static members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 32 bytes */
};
class CTFNapalmGrenade : public CTFPrimeGrenade {
public:

	/* class CTFPrimeGrenade     <ancestor>; */      /*     0  1760 */

	/* XXX last struct has 1 hole */
protected:


	/* --- cacheline 27 boundary (1728 bytes) was 32 bytes ago --- */
	int                        numExplosionsLeft;    /*  1760     4 */
	int                        m_bitsDamageType;     /*  1764     4 */
	float                      m_flEffectTime;       /*  1768     4 */
	float                      m_flDamageTime;       /*  1772     4 */
	void CTFNapalmGrenade(class CTFNapalmGrenade *, class CTFNapalmGrenade &); /* linkage=_ZN16CTFNapalmGrenadeC4EOS_ */

	void CTFNapalmGrenade(class CTFNapalmGrenade *, const class CTFNapalmGrenade  &); /* linkage=_ZN16CTFNapalmGrenadeC4ERKS_ */

	void CTFNapalmGrenade(class CTFNapalmGrenade *); /* linkage=_ZN16CTFNapalmGrenadeC4Ev */

	virtual void Precache(class CTFNapalmGrenade *); /* linkage=_ZN16CTFNapalmGrenade8PrecacheEv */

	class CGrenade * Prime(class CBaseEntity *); /* linkage=_ZN16CTFNapalmGrenade5PrimeEP11CBaseEntity */

	virtual void Explode(class CTFNapalmGrenade *, class  *, int); /* linkage=_ZN16CTFNapalmGrenade7ExplodeEP11TraceResulti */

	void Burn(class CTFNapalmGrenade *); /* linkage=_ZN16CTFNapalmGrenade4BurnEv */

	virtual void setName(class CTFNapalmGrenade *); /* linkage=_ZN16CTFNapalmGrenade7setNameEv */

	virtual void setDamage(class CTFNapalmGrenade *); /* linkage=_ZN16CTFNapalmGrenade9setDamageEv */

	virtual void setRadius(class CTFNapalmGrenade *); /* linkage=_ZN16CTFNapalmGrenade9setRadiusEv */

	virtual void setModel(class CTFNapalmGrenade *); /* linkage=_ZN16CTFNapalmGrenade8setModelEv */

	virtual void ~CTFNapalmGrenade(class CTFNapalmGrenade *, int); /* linkage=_ZN16CTFNapalmGrenadeD4Ev */

	/* vtable has 6 entries: {
	   [3] = Precache(_ZN16CTFNapalmGrenade8PrecacheEv), 
	   [135] = Explode(_ZN16CTFNapalmGrenade7ExplodeEP11TraceResulti), 
	   [141] = setName(_ZN16CTFNapalmGrenade7setNameEv), 
	   [142] = setDamage(_ZN16CTFNapalmGrenade9setDamageEv), 
	   [143] = setRadius(_ZN16CTFNapalmGrenade9setRadiusEv), 
	   [137] = setModel(_ZN16CTFNapalmGrenade8setModelEv), 
	} */
	/* size: 1776, cachelines: 28, members: 5 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 48 bytes */
};
class CTFCaltrop : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	float                      m_flRemovalTime;      /*  1140     4 */
	void CTFCaltrop(class CTFCaltrop *, class CTFCaltrop &); /* linkage=_ZN10CTFCaltropC4EOS_ */

	void CTFCaltrop(class CTFCaltrop *, const class CTFCaltrop  &); /* linkage=_ZN10CTFCaltropC4ERKS_ */

	void CTFCaltrop(class CTFCaltrop *); /* linkage=_ZN10CTFCaltropC4Ev */

	virtual void Precache(class CTFCaltrop *); /* linkage=_ZN10CTFCaltrop8PrecacheEv */

	void ScatterDrop(class CTFCaltrop *, class CBaseEntity *); /* linkage=_ZN10CTFCaltrop11ScatterDropEP11CBaseEntity */

	void CaltropTouch(class CTFCaltrop *, class CBaseEntity *); /* linkage=_ZN10CTFCaltrop12CaltropTouchEP11CBaseEntity */

	void CanisterTouch(class CTFCaltrop *, class CBaseEntity *); /* linkage=_ZN10CTFCaltrop13CanisterTouchEP11CBaseEntity */

	void CaltropScatterThink(class CTFCaltrop *); /* linkage=_ZN10CTFCaltrop19CaltropScatterThinkEv */

	void setName(class CTFCaltrop *); /* linkage=_ZN10CTFCaltrop7setNameEv */

	void setModel(class CTFCaltrop *); /* linkage=_ZN10CTFCaltrop8setModelEv */

	void setDamage(class CTFCaltrop *); /* linkage=_ZN10CTFCaltrop9setDamageEv */

	virtual void ~CTFCaltrop(class CTFCaltrop *, int); /* linkage=_ZN10CTFCaltropD4Ev */

	/* vtable has 1 entries: {
	   [3] = Precache(_ZN10CTFCaltrop8PrecacheEv), 
	} */
	/* size: 1144, cachelines: 18, members: 2 */
	/* sum members: 4, holes: 1, sum holes: 1140 */
	/* last cacheline: 56 bytes */
};
class CTFCaltropGrenade : public CTFPrimeGrenade {
public:

	/* class CTFPrimeGrenade     <ancestor>; */      /*     0  1760 */

	/* XXX last struct has 1 hole */
	void CTFCaltropGrenade(class CTFCaltropGrenade *, class CTFCaltropGrenade &); /* linkage=_ZN17CTFCaltropGrenadeC4EOS_ */

	void CTFCaltropGrenade(class CTFCaltropGrenade *, const class CTFCaltropGrenade  &); /* linkage=_ZN17CTFCaltropGrenadeC4ERKS_ */

	void CTFCaltropGrenade(class CTFCaltropGrenade *); /* linkage=_ZN17CTFCaltropGrenadeC4Ev */

	virtual void Precache(class CTFCaltropGrenade *); /* linkage=_ZN17CTFCaltropGrenade8PrecacheEv */

	virtual void setDamage(class CTFCaltropGrenade *); /* linkage=_ZN17CTFCaltropGrenade9setDamageEv */

	void InitPriming(class CTFCaltropGrenade *, class CBaseEntity *); /* linkage=_ZN17CTFCaltropGrenade11InitPrimingEP11CBaseEntity */

	virtual float getPrimeTime(class CTFCaltropGrenade *); /* linkage=_ZN17CTFCaltropGrenade12getPrimeTimeEv */

	class CGrenade * Prime(class CBaseEntity *); /* linkage=_ZN17CTFCaltropGrenade5PrimeEP11CBaseEntity */

	virtual void Explode(class CTFCaltropGrenade *, class  *, int); /* linkage=_ZN17CTFCaltropGrenade7ExplodeEP11TraceResulti */

	void CaltropGrenadePrimed(class CTFCaltropGrenade *); /* linkage=_ZN17CTFCaltropGrenade20CaltropGrenadePrimedEv */

	virtual void setName(class CTFCaltropGrenade *); /* linkage=_ZN17CTFCaltropGrenade7setNameEv */

	virtual void setModel(class CTFCaltropGrenade *); /* linkage=_ZN17CTFCaltropGrenade8setModelEv */

	virtual void TakeEMPBlast(class CTFCaltropGrenade *, entvars_t *); /* linkage=_ZN17CTFCaltropGrenade12TakeEMPBlastEP9entvars_s */

	virtual void ~CTFCaltropGrenade(class CTFCaltropGrenade *, int); /* linkage=_ZN17CTFCaltropGrenadeD4Ev */

	/* vtable has 7 entries: {
	   [3] = Precache(_ZN17CTFCaltropGrenade8PrecacheEv), 
	   [142] = setDamage(_ZN17CTFCaltropGrenade9setDamageEv), 
	   [139] = getPrimeTime(_ZN17CTFCaltropGrenade12getPrimeTimeEv), 
	   [135] = Explode(_ZN17CTFCaltropGrenade7ExplodeEP11TraceResulti), 
	   [141] = setName(_ZN17CTFCaltropGrenade7setNameEv), 
	   [137] = setModel(_ZN17CTFCaltropGrenade8setModelEv), 
	   [144] = TakeEMPBlast(_ZN17CTFCaltropGrenade12TakeEMPBlastEP9entvars_s), 
	} */
	/* size: 1760, cachelines: 28, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 32 bytes */
};
class CTFNailGrenade : public CTFPrimeGrenade {
public:

	/* class CTFPrimeGrenade     <ancestor>; */      /*     0  1760 */

	/* XXX last struct has 1 hole */
	void CTFNailGrenade(class CTFNailGrenade *, class CTFNailGrenade &); /* linkage=_ZN14CTFNailGrenadeC4EOS_ */

	void CTFNailGrenade(class CTFNailGrenade *, const class CTFNailGrenade  &); /* linkage=_ZN14CTFNailGrenadeC4ERKS_ */

	void CTFNailGrenade(class CTFNailGrenade *); /* linkage=_ZN14CTFNailGrenadeC4Ev */

	virtual void Precache(class CTFNailGrenade *); /* linkage=_ZN14CTFNailGrenade8PrecacheEv */

	class CGrenade * Prime(class CBaseEntity *); /* linkage=_ZN14CTFNailGrenade5PrimeEP11CBaseEntity */

	virtual void Explode(class CTFNailGrenade *, class  *, int); /* linkage=_ZN14CTFNailGrenade7ExplodeEP11TraceResulti */

	void NailGrenadeLaunchNail(class CTFNailGrenade *); /* linkage=_ZN14CTFNailGrenade21NailGrenadeLaunchNailEv */

	void NailGrenadeNailEm(class CTFNailGrenade *); /* linkage=_ZN14CTFNailGrenade17NailGrenadeNailEmEv */

	void FinishedExplode(class CTFNailGrenade *); /* linkage=_ZN14CTFNailGrenade15FinishedExplodeEv */

	virtual void setName(class CTFNailGrenade *); /* linkage=_ZN14CTFNailGrenade7setNameEv */

	virtual void setModel(class CTFNailGrenade *); /* linkage=_ZN14CTFNailGrenade8setModelEv */

	virtual void ~CTFNailGrenade(class CTFNailGrenade *, int); /* linkage=_ZN14CTFNailGrenadeD4Ev */

	/* vtable has 4 entries: {
	   [3] = Precache(_ZN14CTFNailGrenade8PrecacheEv), 
	   [135] = Explode(_ZN14CTFNailGrenade7ExplodeEP11TraceResulti), 
	   [141] = setName(_ZN14CTFNailGrenade7setNameEv), 
	   [137] = setModel(_ZN14CTFNailGrenade8setModelEv), 
	} */
	/* size: 1760, cachelines: 28, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 32 bytes */
};
class CTFBomblet : public CTFPrimeGrenade {
public:

	/* class CTFPrimeGrenade     <ancestor>; */      /*     0  1760 */

	/* XXX last struct has 1 hole */
	void CTFBomblet(class CTFBomblet *, class CTFBomblet &); /* linkage=_ZN10CTFBombletC4EOS_ */

	void CTFBomblet(class CTFBomblet *, const class CTFBomblet  &); /* linkage=_ZN10CTFBombletC4ERKS_ */

	void CTFBomblet(class CTFBomblet *); /* linkage=_ZN10CTFBombletC4Ev */

	virtual void setName(class CTFBomblet *); /* linkage=_ZN10CTFBomblet7setNameEv */

	void LaunchFromMirv(class CTFBomblet *, class CTFMirvGrenade *); /* linkage=_ZN10CTFBomblet14LaunchFromMirvEP14CTFMirvGrenade */

	virtual void setModel(class CTFBomblet *); /* linkage=_ZN10CTFBomblet8setModelEv */

	virtual void Explode(class CTFBomblet *, class  *, int); /* linkage=_ZN10CTFBomblet7ExplodeEP11TraceResulti */

	virtual void ~CTFBomblet(class CTFBomblet *, int); /* linkage=_ZN10CTFBombletD4Ev */

	/* vtable has 3 entries: {
	   [141] = setName(_ZN10CTFBomblet7setNameEv), 
	   [137] = setModel(_ZN10CTFBomblet8setModelEv), 
	   [135] = Explode(_ZN10CTFBomblet7ExplodeEP11TraceResulti), 
	} */
	/* size: 1760, cachelines: 28, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 32 bytes */
};
class CTFMirvGrenade : public CTFPrimeGrenade {
public:

	/* class CTFPrimeGrenade     <ancestor>; */      /*     0  1760 */

	/* XXX last struct has 1 hole */
	void CTFMirvGrenade(class CTFMirvGrenade *, class CTFMirvGrenade &); /* linkage=_ZN14CTFMirvGrenadeC4EOS_ */

	void CTFMirvGrenade(class CTFMirvGrenade *, const class CTFMirvGrenade  &); /* linkage=_ZN14CTFMirvGrenadeC4ERKS_ */

	void CTFMirvGrenade(class CTFMirvGrenade *); /* linkage=_ZN14CTFMirvGrenadeC4Ev */

	virtual void Precache(class CTFMirvGrenade *); /* linkage=_ZN14CTFMirvGrenade8PrecacheEv */

	class CGrenade * Prime(class CBaseEntity *); /* linkage=_ZN14CTFMirvGrenade5PrimeEP11CBaseEntity */

	virtual void Explode(class CTFMirvGrenade *, class  *, int); /* linkage=_ZN14CTFMirvGrenade7ExplodeEP11TraceResulti */

	virtual void setName(class CTFMirvGrenade *); /* linkage=_ZN14CTFMirvGrenade7setNameEv */

	virtual void setDamage(class CTFMirvGrenade *); /* linkage=_ZN14CTFMirvGrenade9setDamageEv */

	virtual void setRadius(class CTFMirvGrenade *); /* linkage=_ZN14CTFMirvGrenade9setRadiusEv */

	virtual void setModel(class CTFMirvGrenade *); /* linkage=_ZN14CTFMirvGrenade8setModelEv */

	virtual void ~CTFMirvGrenade(class CTFMirvGrenade *, int); /* linkage=_ZN14CTFMirvGrenadeD4Ev */

	/* vtable has 6 entries: {
	   [3] = Precache(_ZN14CTFMirvGrenade8PrecacheEv), 
	   [135] = Explode(_ZN14CTFMirvGrenade7ExplodeEP11TraceResulti), 
	   [141] = setName(_ZN14CTFMirvGrenade7setNameEv), 
	   [142] = setDamage(_ZN14CTFMirvGrenade9setDamageEv), 
	   [143] = setRadius(_ZN14CTFMirvGrenade9setRadiusEv), 
	   [137] = setModel(_ZN14CTFMirvGrenade8setModelEv), 
	} */
	/* size: 1760, cachelines: 28, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 32 bytes */
};
class CTFConcussionGrenade : public CTFPrimeGrenade {
public:

	/* class CTFPrimeGrenade     <ancestor>; */      /*     0  1760 */

	/* XXX last struct has 1 hole */

	static int                        BlastTexture;  /*     0     0 */
	void CTFConcussionGrenade(class CTFConcussionGrenade *, class CTFConcussionGrenade &); /* linkage=_ZN20CTFConcussionGrenadeC4EOS_ */

	void CTFConcussionGrenade(class CTFConcussionGrenade *, const class CTFConcussionGrenade  &); /* linkage=_ZN20CTFConcussionGrenadeC4ERKS_ */

	void CTFConcussionGrenade(class CTFConcussionGrenade *); /* linkage=_ZN20CTFConcussionGrenadeC4Ev */

	virtual void Precache(class CTFConcussionGrenade *); /* linkage=_ZN20CTFConcussionGrenade8PrecacheEv */

	class CGrenade * Prime(class CBaseEntity *); /* linkage=_ZN20CTFConcussionGrenade5PrimeEP11CBaseEntity */

	virtual void Explode(class CTFConcussionGrenade *, class  *, int); /* linkage=_ZN20CTFConcussionGrenade7ExplodeEP11TraceResulti */

	virtual void setName(class CTFConcussionGrenade *); /* linkage=_ZN20CTFConcussionGrenade7setNameEv */

	virtual void setDamage(class CTFConcussionGrenade *); /* linkage=_ZN20CTFConcussionGrenade9setDamageEv */

	virtual void setRadius(class CTFConcussionGrenade *); /* linkage=_ZN20CTFConcussionGrenade9setRadiusEv */

	virtual void setModel(class CTFConcussionGrenade *); /* linkage=_ZN20CTFConcussionGrenade8setModelEv */

	virtual void ~CTFConcussionGrenade(class CTFConcussionGrenade *, int); /* linkage=_ZN20CTFConcussionGrenadeD4Ev */

	/* vtable has 6 entries: {
	   [3] = Precache(_ZN20CTFConcussionGrenade8PrecacheEv), 
	   [135] = Explode(_ZN20CTFConcussionGrenade7ExplodeEP11TraceResulti), 
	   [141] = setName(_ZN20CTFConcussionGrenade7setNameEv), 
	   [142] = setDamage(_ZN20CTFConcussionGrenade9setDamageEv), 
	   [143] = setRadius(_ZN20CTFConcussionGrenade9setRadiusEv), 
	   [137] = setModel(_ZN20CTFConcussionGrenade8setModelEv), 
	} */
	/* size: 1760, cachelines: 28, members: 1, static members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 32 bytes */
};
class CTFNormalGrenade : public CTFPrimeGrenade {
public:

	/* class CTFPrimeGrenade     <ancestor>; */      /*     0  1760 */

	/* XXX last struct has 1 hole */
	void CTFNormalGrenade(class CTFNormalGrenade *, class CTFNormalGrenade &); /* linkage=_ZN16CTFNormalGrenadeC4EOS_ */

	void CTFNormalGrenade(class CTFNormalGrenade *, const class CTFNormalGrenade  &); /* linkage=_ZN16CTFNormalGrenadeC4ERKS_ */

	void CTFNormalGrenade(class CTFNormalGrenade *); /* linkage=_ZN16CTFNormalGrenadeC4Ev */

	virtual void Precache(class CTFNormalGrenade *); /* linkage=_ZN16CTFNormalGrenade8PrecacheEv */

	class CGrenade * Prime(class CBaseEntity *); /* linkage=_ZN16CTFNormalGrenade5PrimeEP11CBaseEntity */

	virtual void Explode(class CTFNormalGrenade *, class  *, int); /* linkage=_ZN16CTFNormalGrenade7ExplodeEP11TraceResulti */

	virtual void setName(class CTFNormalGrenade *); /* linkage=_ZN16CTFNormalGrenade7setNameEv */

	virtual void setDamage(class CTFNormalGrenade *); /* linkage=_ZN16CTFNormalGrenade9setDamageEv */

	virtual void setRadius(class CTFNormalGrenade *); /* linkage=_ZN16CTFNormalGrenade9setRadiusEv */

	virtual void ~CTFNormalGrenade(class CTFNormalGrenade *, int); /* linkage=_ZN16CTFNormalGrenadeD4Ev */

	/* vtable has 5 entries: {
	   [3] = Precache(_ZN16CTFNormalGrenade8PrecacheEv), 
	   [135] = Explode(_ZN16CTFNormalGrenade7ExplodeEP11TraceResulti), 
	   [141] = setName(_ZN16CTFNormalGrenade7setNameEv), 
	   [142] = setDamage(_ZN16CTFNormalGrenade9setDamageEv), 
	   [143] = setRadius(_ZN16CTFNormalGrenade9setRadiusEv), 
	} */
	/* size: 1760, cachelines: 28, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 32 bytes */
};
class CLaserSpot : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CLaserSpot(class CLaserSpot *, class CLaserSpot &); /* linkage=_ZN10CLaserSpotC4EOS_ */

	void CLaserSpot(class CLaserSpot *, const class CLaserSpot  &); /* linkage=_ZN10CLaserSpotC4ERKS_ */

	void CLaserSpot(class CLaserSpot *); /* linkage=_ZN10CLaserSpotC4Ev */

private:

	virtual void Spawn(class CLaserSpot *); /* linkage=_ZN10CLaserSpot5SpawnEv */

	virtual void Precache(class CLaserSpot *); /* linkage=_ZN10CLaserSpot8PrecacheEv */

	virtual int ObjectCaps(class CLaserSpot *); /* linkage=_ZN10CLaserSpot10ObjectCapsEv */

	void Suspend(class CLaserSpot *, float); /* linkage=_ZN10CLaserSpot7SuspendEf */

	void Revive(class CLaserSpot *); /* linkage=_ZN10CLaserSpot6ReviveEv */

	class CLaserSpot * CreateSpot(void); /* linkage=_ZN10CLaserSpot10CreateSpotEv */

	virtual void ~CLaserSpot(class CLaserSpot *, int); /* linkage=_ZN10CLaserSpotD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN10CLaserSpot5SpawnEv), 
	   [3] = Precache(_ZN10CLaserSpot8PrecacheEv), 
	   [7] = ObjectCaps(_ZN10CLaserSpot10ObjectCapsEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CTFGrenade : public CGrenade {

	/* XXX 1752 bytes hole, try to pack */
public:


	/* class CGrenade            <ancestor>; */      /*     0     0 */
	/* --- cacheline 27 boundary (1728 bytes) was 24 bytes ago --- */
	int                        m_iTrail;             /*  1752     4 */
	float                      m_flCreationTime;     /*  1756     4 */
	void CTFGrenade(class CTFGrenade *, class CTFGrenade &); /* linkage=_ZN10CTFGrenadeC4EOS_ */

	void CTFGrenade(class CTFGrenade *, const class CTFGrenade  &); /* linkage=_ZN10CTFGrenadeC4ERKS_ */

	void CTFGrenade(class CTFGrenade *); /* linkage=_ZN10CTFGrenadeC4Ev */

	virtual void Spawn(class CTFGrenade *); /* linkage=_ZN10CTFGrenade5SpawnEv */

	virtual void Precache(class CTFGrenade *); /* linkage=_ZN10CTFGrenade8PrecacheEv */

	void GrenadeTouch(class CTFGrenade *, class CBaseEntity *); /* linkage=_ZN10CTFGrenade12GrenadeTouchEP11CBaseEntity */

	class CTFGrenade * CreateTFGrenade(class Vector, class Vector, class CBaseEntity *, class CTFGrenadeLauncher *); /* linkage=_ZN10CTFGrenade15CreateTFGrenadeE6VectorS0_P11CBaseEntityP18CTFGrenadeLauncher */

	class CTFGrenade * CreateTFPipebomb(class Vector, class Vector, class CBaseEntity *, class CTFGrenadeLauncher *); /* linkage=_ZN10CTFGrenade16CreateTFPipebombE6VectorS0_P11CBaseEntityP18CTFGrenadeLauncher */

	virtual void RadiusDamage(class CTFGrenade *, entvars_t *, entvars_t *, float, int, int); /* linkage=_ZN10CTFGrenade12RadiusDamageEP9entvars_sS1_fii */

	virtual void setModel(class CTFGrenade *); /* linkage=_ZN10CTFGrenade8setModelEv */

	void PipebombDetonate(class CTFGrenade *); /* linkage=_ZN10CTFGrenade16PipebombDetonateEv */

	virtual void TeamFortress_TakeEMPBlast(class CTFGrenade *, entvars_t *); /* linkage=_ZN10CTFGrenade25TeamFortress_TakeEMPBlastEP9entvars_s */

	virtual void ~CTFGrenade(class CTFGrenade *, int); /* linkage=_ZN10CTFGrenadeD4Ev */

	/* vtable has 5 entries: {
	   [2] = Spawn(_ZN10CTFGrenade5SpawnEv), 
	   [3] = Precache(_ZN10CTFGrenade8PrecacheEv), 
	   [127] = RadiusDamage(_ZN10CTFGrenade12RadiusDamageEP9entvars_sS1_fii), 
	   [137] = setModel(_ZN10CTFGrenade8setModelEv), 
	   [61] = TeamFortress_TakeEMPBlast(_ZN10CTFGrenade25TeamFortress_TakeEMPBlastEP9entvars_s), 
	} */
	/* size: 1760, cachelines: 28, members: 3 */
	/* sum members: 8, holes: 1, sum holes: 1752 */
	/* last cacheline: 32 bytes */
};
class CTFRpgAmmo : public CBasePlayerAmmo {
public:

	/* class CBasePlayerAmmo     <ancestor>; */      /*     0     0 */
	void CTFRpgAmmo(class CTFRpgAmmo *, class CTFRpgAmmo &); /* linkage=_ZN10CTFRpgAmmoC4EOS_ */

	void CTFRpgAmmo(class CTFRpgAmmo *, const class CTFRpgAmmo  &); /* linkage=_ZN10CTFRpgAmmoC4ERKS_ */

	void CTFRpgAmmo(class CTFRpgAmmo *); /* linkage=_ZN10CTFRpgAmmoC4Ev */

private:

	virtual void Spawn(class CTFRpgAmmo *); /* linkage=_ZN10CTFRpgAmmo5SpawnEv */

	virtual void Precache(class CTFRpgAmmo *); /* linkage=_ZN10CTFRpgAmmo8PrecacheEv */

	virtual BOOL AddAmmo(class CTFRpgAmmo *, class CBaseEntity *); /* linkage=_ZN10CTFRpgAmmo7AddAmmoEP11CBaseEntity */

	virtual void ~CTFRpgAmmo(class CTFRpgAmmo *, int); /* linkage=_ZN10CTFRpgAmmoD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN10CTFRpgAmmo5SpawnEv), 
	   [3] = Precache(_ZN10CTFRpgAmmo8PrecacheEv), 
	   [65] = AddAmmo(_ZN10CTFRpgAmmo7AddAmmoEP11CBaseEntity), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CTFRpgRocket : public CGrenade {

	/* XXX 1752 bytes hole, try to pack */
public:


	/* class CGrenade            <ancestor>; */      /*     0     0 */
	/* --- cacheline 27 boundary (1728 bytes) was 24 bytes ago --- */
	int                        m_iTrail;             /*  1752     4 */
	void CTFRpgRocket(class CTFRpgRocket *, class CTFRpgRocket &); /* linkage=_ZN12CTFRpgRocketC4EOS_ */

	void CTFRpgRocket(class CTFRpgRocket *, const class CTFRpgRocket  &); /* linkage=_ZN12CTFRpgRocketC4ERKS_ */

	void CTFRpgRocket(class CTFRpgRocket *); /* linkage=_ZN12CTFRpgRocketC4Ev */

	virtual void Spawn(class CTFRpgRocket *); /* linkage=_ZN12CTFRpgRocket5SpawnEv */

	virtual void Precache(class CTFRpgRocket *); /* linkage=_ZN12CTFRpgRocket8PrecacheEv */

	void RocketTouch(class CTFRpgRocket *, class CBaseEntity *); /* linkage=_ZN12CTFRpgRocket11RocketTouchEP11CBaseEntity */

	class CTFRpgRocket * CreateRpgRocket(class Vector, class Vector, class CBaseEntity *, class CTFRpg *); /* linkage=_ZN12CTFRpgRocket15CreateRpgRocketE6VectorS0_P11CBaseEntityP6CTFRpg */

	virtual void RadiusDamage(class CTFRpgRocket *, entvars_t *, entvars_t *, float, int, int); /* linkage=_ZN12CTFRpgRocket12RadiusDamageEP9entvars_sS1_fii */

	virtual void ~CTFRpgRocket(class CTFRpgRocket *, int); /* linkage=_ZN12CTFRpgRocketD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN12CTFRpgRocket5SpawnEv), 
	   [3] = Precache(_ZN12CTFRpgRocket8PrecacheEv), 
	   [127] = RadiusDamage(_ZN12CTFRpgRocket12RadiusDamageEP9entvars_sS1_fii), 
	} */
	/* size: 1756, cachelines: 28, members: 2 */
	/* sum members: 4, holes: 1, sum holes: 1752 */
	/* last cacheline: 28 bytes */
};
class CTFIncendiaryCRocket : public CGrenade {

	/* XXX 1752 bytes hole, try to pack */
public:


	/* class CGrenade            <ancestor>; */      /*     0     0 */
	/* --- cacheline 27 boundary (1728 bytes) was 24 bytes ago --- */
	int                        m_iTrail;             /*  1752     4 */
	void CTFIncendiaryCRocket(class CTFIncendiaryCRocket *, class CTFIncendiaryCRocket &); /* linkage=_ZN20CTFIncendiaryCRocketC4EOS_ */

	void CTFIncendiaryCRocket(class CTFIncendiaryCRocket *, const class CTFIncendiaryCRocket  &); /* linkage=_ZN20CTFIncendiaryCRocketC4ERKS_ */

	void CTFIncendiaryCRocket(class CTFIncendiaryCRocket *); /* linkage=_ZN20CTFIncendiaryCRocketC4Ev */

	virtual void Spawn(class CTFIncendiaryCRocket *); /* linkage=_ZN20CTFIncendiaryCRocket5SpawnEv */

	virtual void Precache(class CTFIncendiaryCRocket *); /* linkage=_ZN20CTFIncendiaryCRocket8PrecacheEv */

	void RocketTouch(class CTFIncendiaryCRocket *, class CBaseEntity *); /* linkage=_ZN20CTFIncendiaryCRocket11RocketTouchEP11CBaseEntity */

	class CTFIncendiaryCRocket * CreateRpgRocket(class Vector, class Vector, class CBaseEntity *, class CTFIncendiaryC *); /* linkage=_ZN20CTFIncendiaryCRocket15CreateRpgRocketE6VectorS0_P11CBaseEntityP14CTFIncendiaryC */

	virtual void RadiusDamage(class CTFIncendiaryCRocket *, entvars_t *, entvars_t *, float, int, int); /* linkage=_ZN20CTFIncendiaryCRocket12RadiusDamageEP9entvars_sS1_fii */

	virtual void ~CTFIncendiaryCRocket(class CTFIncendiaryCRocket *, int); /* linkage=_ZN20CTFIncendiaryCRocketD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN20CTFIncendiaryCRocket5SpawnEv), 
	   [3] = Precache(_ZN20CTFIncendiaryCRocket8PrecacheEv), 
	   [127] = RadiusDamage(_ZN20CTFIncendiaryCRocket12RadiusDamageEP9entvars_sS1_fii), 
	} */
	/* size: 1756, cachelines: 28, members: 2 */
	/* sum members: 4, holes: 1, sum holes: 1752 */
	/* last cacheline: 28 bytes */
};
class CTFFlamethrowerBurst : public CGrenade {

	/* XXX 1752 bytes hole, try to pack */
public:


	/* class CGrenade            <ancestor>; */      /*     0     0 */
	/* --- cacheline 27 boundary (1728 bytes) was 24 bytes ago --- */
	int                        m_iTrail;             /*  1752     4 */
	void CTFFlamethrowerBurst(class CTFFlamethrowerBurst *, class CTFFlamethrowerBurst &); /* linkage=_ZN20CTFFlamethrowerBurstC4EOS_ */

	void CTFFlamethrowerBurst(class CTFFlamethrowerBurst *, const class CTFFlamethrowerBurst  &); /* linkage=_ZN20CTFFlamethrowerBurstC4ERKS_ */

	void CTFFlamethrowerBurst(class CTFFlamethrowerBurst *); /* linkage=_ZN20CTFFlamethrowerBurstC4Ev */

	virtual void Spawn(class CTFFlamethrowerBurst *); /* linkage=_ZN20CTFFlamethrowerBurst5SpawnEv */

	virtual void Precache(class CTFFlamethrowerBurst *); /* linkage=_ZN20CTFFlamethrowerBurst8PrecacheEv */

	void BurstTouch(class CTFFlamethrowerBurst *, class CBaseEntity *); /* linkage=_ZN20CTFFlamethrowerBurst10BurstTouchEP11CBaseEntity */

	class CTFFlamethrowerBurst * CreateBurst(class Vector, class Vector, class CBaseEntity *, class CTFFlamethrower *); /* linkage=_ZN20CTFFlamethrowerBurst11CreateBurstE6VectorS0_P11CBaseEntityP15CTFFlamethrower */

	virtual void ~CTFFlamethrowerBurst(class CTFFlamethrowerBurst *, int); /* linkage=_ZN20CTFFlamethrowerBurstD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN20CTFFlamethrowerBurst5SpawnEv), 
	   [3] = Precache(_ZN20CTFFlamethrowerBurst8PrecacheEv), 
	} */
	/* size: 1756, cachelines: 28, members: 2 */
	/* sum members: 4, holes: 1, sum holes: 1752 */
	/* last cacheline: 28 bytes */
};
class CTFNailgunNail : public CGrenade {

	/* XXX 1752 bytes hole, try to pack */
public:


	/* class CGrenade            <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 27 boundary (1728 bytes) was 24 bytes ago --- */
	class Vector              m_vecPreviousVelocity; /*  1752    12 */
	void CTFNailgunNail(class CTFNailgunNail *, class CTFNailgunNail &); /* linkage=_ZN14CTFNailgunNailC4EOS_ */

	void CTFNailgunNail(class CTFNailgunNail *, const class CTFNailgunNail  &); /* linkage=_ZN14CTFNailgunNailC4ERKS_ */

	void CTFNailgunNail(class CTFNailgunNail *); /* linkage=_ZN14CTFNailgunNailC4Ev */

	virtual void Spawn(class CTFNailgunNail *); /* linkage=_ZN14CTFNailgunNail5SpawnEv */

	virtual void Precache(class CTFNailgunNail *); /* linkage=_ZN14CTFNailgunNail8PrecacheEv */

	void RailgunNail_Think(class CTFNailgunNail *); /* linkage=_ZN14CTFNailgunNail17RailgunNail_ThinkEv */

	void NailTouch(class CTFNailgunNail *, class CBaseEntity *); /* linkage=_ZN14CTFNailgunNail9NailTouchEP11CBaseEntity */

	void TranqTouch(class CTFNailgunNail *, class CBaseEntity *); /* linkage=_ZN14CTFNailgunNail10TranqTouchEP11CBaseEntity */

	void RailgunNailTouch(class CTFNailgunNail *, class CBaseEntity *); /* linkage=_ZN14CTFNailgunNail16RailgunNailTouchEP11CBaseEntity */

	class CTFNailgunNail * CreateNail(BOOL, class Vector, class Vector, class CBaseEntity *, class CBaseEntity *, BOOL); /* linkage=_ZN14CTFNailgunNail10CreateNailEi6VectorS0_P11CBaseEntityS2_i */

	class CTFNailgunNail * CreateSuperNail(class Vector, class Vector, class CBaseEntity *, class CBaseEntity *); /* linkage=_ZN14CTFNailgunNail15CreateSuperNailE6VectorS0_P11CBaseEntityS2_ */

	class CTFNailgunNail * CreateTranqNail(class Vector, class Vector, class CBaseEntity *, class CBaseEntity *); /* linkage=_ZN14CTFNailgunNail15CreateTranqNailE6VectorS0_P11CBaseEntityS2_ */

	class CTFNailgunNail * CreateRailgunNail(class Vector, class Vector, class CBaseEntity *, class CBaseEntity *); /* linkage=_ZN14CTFNailgunNail17CreateRailgunNailE6VectorS0_P11CBaseEntityS2_ */

	class CTFNailgunNail * CreateNailGrenNail(class Vector, class Vector, class CBaseEntity *, class CBaseEntity *); /* linkage=_ZN14CTFNailgunNail18CreateNailGrenNailE6VectorS0_P11CBaseEntityS2_ */

	virtual void ~CTFNailgunNail(class CTFNailgunNail *, int); /* linkage=_ZN14CTFNailgunNailD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN14CTFNailgunNail5SpawnEv), 
	   [3] = Precache(_ZN14CTFNailgunNail8PrecacheEv), 
	} */
	/* size: 1764, cachelines: 28, members: 2 */
	/* sum members: 12, holes: 1, sum holes: 1752 */
	/* last cacheline: 36 bytes */
};
class CTimer : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CTimer(class CTimer *, class CTimer &); /* linkage=_ZN6CTimerC4EOS_ */

	void CTimer(class CTimer *, const class CTimer  &); /* linkage=_ZN6CTimerC4ERKS_ */

	void CTimer(class CTimer *); /* linkage=_ZN6CTimerC4Ev */

	virtual void ~CTimer(class CTimer *, int); /* linkage=_ZN6CTimerD4Ev */


	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
struct tm {
	int                        tm_sec;               /*     0     4 */
	int                        tm_min;               /*     4     4 */
	int                        tm_hour;              /*     8     4 */
	int                        tm_mday;              /*    12     4 */
	int                        tm_mon;               /*    16     4 */
	int                        tm_year;              /*    20     4 */
	int                        tm_wday;              /*    24     4 */
	int                        tm_yday;              /*    28     4 */
	int                        tm_isdst;             /*    32     4 */
	long int                   tm_gmtoff;            /*    36     4 */
	const char  *              tm_zone;              /*    40     4 */

	/* size: 44, cachelines: 1, members: 11 */
	/* last cacheline: 44 bytes */
};
class CBaseEntity {
	int ()(void) * *           _vptr.CBaseEntity;    /*     0     4 */
	entvars_t *                pev;                  /*     4     4 */
	class CBaseEntity *        m_pGoalEnt;           /*     8     4 */
	class CBaseEntity *        m_pLink;              /*    12     4 */

	/* Bitfield combined with previous fields */

	static TYPEDESCRIPTION            m_SaveData[0]; /*     0     0 */
	struct {
		void               (*__pfn)(class CBaseEntity *); /*    16     4 */
		int                __delta;              /*    20     4 */
	} m_pfnThink;                                    /*    16     8 */
	struct {
		void               (*__pfn)(class CBaseEntity *, class CBaseEntity *); /*    24     4 */
		int                __delta;              /*    28     4 */
	} m_pfnTouch;                                    /*    24     8 */
	struct {
		void               (*__pfn)(class CBaseEntity *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /*    32     4 */
		int                __delta;              /*    36     4 */
	} m_pfnUse;                                      /*    32     8 */
	struct {
		void               (*__pfn)(class CBaseEntity *, class CBaseEntity *); /*    40     4 */
		int                __delta;              /*    44     4 */
	} m_pfnBlocked;                                  /*    40     8 */
	int                        nextpc;               /*    48     4 */
	int                        lastpc;               /*    52     4 */
	int                        last_impulse;         /*    56     4 */
	int                        armorclass;           /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	int                        tf_items;             /*    64     4 */
	int                        tf_items_flags;       /*    68     4 */
	int                        no_grenades_1;        /*    72     4 */
	int                        no_grenades_2;        /*    76     4 */
	int                        tp_grenades_1;        /*    80     4 */
	int                        tp_grenades_2;        /*    84     4 */
	string_t                   m_iszGrenadeName;     /*    88     4 */
	BOOL                       got_aliases;          /*    92     4 */
	BOOL                       cheat_check;          /*    96     4 */
	BOOL                       is_removed;           /*   100     4 */
	BOOL                       is_undercover;        /*   104     4 */
	BOOL                       is_building;          /*   108     4 */
	BOOL                       is_detpacking;        /*   112     4 */
	BOOL                       is_feigning;          /*   116     4 */
	BOOL                       is_unableto_spy_or_teleport; /*   120     4 */
	BOOL                       has_disconnected;     /*   124     4 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	BOOL                       fClientGrenadePrimed; /*   128     4 */
	BOOL                       bRemoveGrenade;       /*   132     4 */
	short unsigned int         m_usBuildingEvent;    /*   136     2 */

	/* XXX 2 bytes hole, try to pack */

	int                        m_iBuildingEventState; /*   140     4 */
	class Vector              m_vOldOrigin;          /*   144    12 */
	int                        tfstate;              /*   156     4 */
	int                        items;                /*   160     4 */
	int                        weapon;               /*   164     4 */
	int                        m_iPrimedGrenType;    /*   168     4 */
	class CBaseEntity *        observer_list;        /*   172     4 */
	class EHANDLE             m_pOtherSection;       /*   176     8 */
	int                        m_iRightBound;        /*   184     4 */
	int                        m_iLeftBound;         /*   188     4 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	float                      cl_no_grenades_1;     /*   192     4 */
	float                      cl_no_grenades_2;     /*   196     4 */
	int *                      current_ammo;         /*   200     4 */
	float                      currentammo;          /*   204     4 */
	int                        maxammo_medikit;      /*   208     4 */
	int                        ammo_medikit;         /*   212     4 */
	int                        maxammo_shells;       /*   216     4 */
	int                        ammo_detpack;         /*   220     4 */
	int                        maxammo_detpack;      /*   224     4 */
	int                        ammo_shells;          /*   228     4 */
	int                        maxammo_nails;        /*   232     4 */
	int                        ammo_nails;           /*   236     4 */
	int                        maxammo_cells;        /*   240     4 */
	int                        ammo_cells;           /*   244     4 */
	int                        maxammo_rockets;      /*   248     4 */
	int                        ammo_rockets;         /*   252     4 */
	/* --- cacheline 4 boundary (256 bytes) --- */
	int                        items_allowed;        /*   256     4 */
	float                      armor_allowed;        /*   260     4 */
	float                      maxarmor;             /*   264     4 */
	int                        exec_scripts;         /*   268     4 */
	int                        exec_map_scripts;     /*   272     4 */
	int                        display_class_briefing; /*   276     4 */
	int                        take_screenshots;     /*   280     4 */
	int                        local_blood;          /*   284     4 */
	float                      weaponmode;           /*   288     4 */
	float                      motd;                 /*   292     4 */
	float                      current_menu;         /*   296     4 */
	float                      menu_displaytime;     /*   300     4 */
	float                      menu_refreshtime;     /*   304     4 */
	float                      m_flSafetyCheckTime;  /*   308     4 */
	int                        team_no;              /*   312     4 */
	int                        lives;                /*   316     4 */
	/* --- cacheline 5 boundary (320 bytes) --- */
	int                        infection_team_no;    /*   320     4 */
	int                        real_frags;           /*   324     4 */
	float                      respawn_time;         /*   328     4 */
	float                      suicide_time;         /*   332     4 */
	class EHANDLE             building;              /*   336     8 */
	float                      building_wait;        /*   344     4 */
	class EHANDLE             real_owner;            /*   348     8 */
	float                      has_dispenser;        /*   356     4 */
	float                      has_sentry;           /*   360     4 */
	float                      has_entry_teleporter; /*   364     4 */
	float                      has_exit_teleporter;  /*   368     4 */
	int                        weapons_carried;      /*   372     4 */
	float                      current_weapon;       /*   376     4 */
	int                        last_weapon;          /*   380     4 */
	/* --- cacheline 6 boundary (384 bytes) --- */
	float                      last_weaponmode;      /*   384     4 */
	float                      reload_shotgun;       /*   388     4 */
	float                      reload_super_shotgun; /*   392     4 */
	float                      reload_nailgun;       /*   396     4 */
	float                      reload_super_nailgun; /*   400     4 */
	float                      reload_grenade_launcher; /*   404     4 */
	float                      reload_rocket_launcher; /*   408     4 */
	float                      reload_flamethrower;  /*   412     4 */
	float                      reload_incendiary;    /*   416     4 */
	float                      heat;                 /*   420     4 */
	float                      sniper_zoom;          /*   424     4 */
	float                      immune_to_check;      /*   428     4 */
	float                      last_saveme_sound;    /*   432     4 */
	class Vector              head_shot_vector;      /*   436    12 */
	/* --- cacheline 7 boundary (448 bytes) --- */
	float                      leg_damage;           /*   448     4 */
	float                      cheat_level;          /*   452     4 */
	float                      FlashTime;            /*   456     4 */
	float                      nailpos;              /*   460     4 */
	float                      old_leg_damage;       /*   464     4 */
	float                      clientHalluc;         /*   468     4 */
	float                      clientTranq;          /*   472     4 */
	float                      no_active_nail_grens; /*   476     4 */
	float                      no_active_napalm_grens; /*   480     4 */
	float                      no_active_gas_grens;  /*   484     4 */
	float                      numflames;            /*   488     4 */
	float                      timecount;            /*   492     4 */
	char *                     flame_id;             /*   496     4 */
	int                        undercover_team;      /*   500     4 */
	int                        undercover_skin;      /*   504     4 */
	class EHANDLE             undercover_target;     /*   508     8 */
	/* --- cacheline 8 boundary (512 bytes) was 4 bytes ago --- */
	float                      StatusRefreshTime;    /*   516     4 */
	float                      StatusBarSize;        /*   520     4 */
	float                      StatusBarRes;         /*   524     4 */
	float                      ScannerOn;            /*   528     4 */
	int                        tf_id;                /*   532     4 */
	int                        teamkills;            /*   536     4 */
	BOOL                       is_admin;             /*   540     4 */
	int                        admin_mode;           /*   544     4 */
	class EHANDLE             admin_use;             /*   548     8 */
	int                        ip;                   /*   556     4 */
	int                        goal_no;              /*   560     4 */
	int                        group_no;             /*   564     4 */
	int                        goal_state;           /*   568     4 */
	int                        owned_by;             /*   572     4 */
	/* --- cacheline 9 boundary (576 bytes) --- */
	string_t                   teamcheck;            /*   576     4 */
	string_t                   owned_by_teamcheck;   /*   580     4 */
	int                        goal_activation;      /*   584     4 */
	int                        goal_effects;         /*   588     4 */
	int                        goal_result;          /*   592     4 */
	int                        goal_group;           /*   596     4 */
	int                        else_goal;            /*   600     4 */
	int                        if_goal_is_active;    /*   604     4 */
	int                        if_goal_is_inactive;  /*   608     4 */
	int                        if_goal_is_removed;   /*   612     4 */
	int                        if_group_is_active;   /*   616     4 */
	int                        if_group_is_inactive; /*   620     4 */
	int                        if_group_is_removed;  /*   624     4 */
	float                      search_time;          /*   628     4 */
	float                      t_length;             /*   632     4 */
	int                        activate_goal_no;     /*   636     4 */
	/* --- cacheline 10 boundary (640 bytes) --- */
	int                        inactivate_goal_no;   /*   640     4 */
	int                        remove_goal_no;       /*   644     4 */
	int                        restore_goal_no;      /*   648     4 */
	int                        activate_group_no;    /*   652     4 */
	int                        inactivate_group_no;  /*   656     4 */
	int                        remove_group_no;      /*   660     4 */
	int                        restore_group_no;     /*   664     4 */
	BOOL                       m_bAddBonuses;        /*   668     4 */
	class Vector              goal_min;              /*   672    12 */
	class Vector              goal_max;              /*   684    12 */
	string_t                   replacement_model;    /*   696     4 */
	int                        replacement_model_body; /*   700     4 */
	/* --- cacheline 11 boundary (704 bytes) --- */
	int                        replacement_model_skin; /*   704     4 */
	int                        replacement_model_flags; /*   708     4 */
	int                        has_item_from_group;  /*   712     4 */
	int                        hasnt_item_from_group; /*   716     4 */
	int                        remove_item_group;    /*   720     4 */
	int                        return_item_no;       /*   724     4 */
	int                        if_item_has_moved;    /*   728     4 */
	int                        if_item_hasnt_moved;  /*   732     4 */
	int                        remove_spawnpoint;    /*   736     4 */
	int                        restore_spawnpoint;   /*   740     4 */
	int                        remove_spawngroup;    /*   744     4 */
	int                        restore_spawngroup;   /*   748     4 */
	int                        display_item_status[4]; /*   752    16 */
	/* --- cacheline 12 boundary (768 bytes) --- */
	string_t                   team_str_home;        /*   768     4 */
	string_t                   team_str_moved;       /*   772     4 */
	string_t                   team_str_carried;     /*   776     4 */
	string_t                   non_team_str_home;    /*   780     4 */
	string_t                   non_team_str_moved;   /*   784     4 */
	string_t                   non_team_str_carried; /*   788     4 */
	int                        ex_skill_min;         /*   792     4 */
	int                        ex_skill_max;         /*   796     4 */
	int                        increase_team[4];     /*   800    16 */
	int                        increase_team_owned_by; /*   816     4 */
	float                      wait;                 /*   820     4 */
	int                        count;                /*   824     4 */
	int                        axhitme;              /*   828     4 */
	/* --- cacheline 13 boundary (832 bytes) --- */
	float                      drop_time;            /*   832     4 */
	class Vector              redrop_origin;         /*   836    12 */
	int                        redrop_count;         /*   848     4 */
	float                      attack_finished;      /*   852     4 */
	float                      distance;             /*   856     4 */
	int                        speed_reduction;      /*   860     4 */
	float                      m_flEndRoundTime;     /*   864     4 */
	string_t                   m_iszEndRoundMsg_Team1_Win; /*   868     4 */
	string_t                   m_iszEndRoundMsg_Team2_Win; /*   872     4 */
	string_t                   m_iszEndRoundMsg_Team3_Win; /*   876     4 */
	string_t                   m_iszEndRoundMsg_Team4_Win; /*   880     4 */
	string_t                   m_iszEndRoundMsg_Team1_Lose; /*   884     4 */
	string_t                   m_iszEndRoundMsg_Team2_Lose; /*   888     4 */
	string_t                   m_iszEndRoundMsg_Team3_Lose; /*   892     4 */
	/* --- cacheline 14 boundary (896 bytes) --- */
	string_t                   m_iszEndRoundMsg_Team4_Lose; /*   896     4 */
	string_t                   m_iszEndRoundMsg_Team1; /*   900     4 */
	string_t                   m_iszEndRoundMsg_Team2; /*   904     4 */
	string_t                   m_iszEndRoundMsg_Team3; /*   908     4 */
	string_t                   m_iszEndRoundMsg_Team4; /*   912     4 */
	string_t                   m_iszEndRoundMsg_OwnedBy; /*   916     4 */
	string_t                   m_iszEndRoundMsg_NonOwnedBy; /*   920     4 */
	string_t                   killtarget;           /*   924     4 */
	string_t                   noise4;               /*   928     4 */
	string_t                   broadcast;            /*   932     4 */
	string_t                   team_broadcast;       /*   936     4 */
	string_t                   non_team_broadcast;   /*   940     4 */
	string_t                   owners_team_broadcast; /*   944     4 */
	string_t                   non_owners_team_broadcast; /*   948     4 */
	string_t                   team_drop;            /*   952     4 */
	string_t                   non_team_drop;        /*   956     4 */
	/* --- cacheline 15 boundary (960 bytes) --- */
	string_t                   org_broadcast;        /*   960     4 */
	string_t                   org_team_broadcast;   /*   964     4 */
	string_t                   org_non_team_broadcast; /*   968     4 */
	string_t                   org_owners_team_broadcast; /*   972     4 */
	string_t                   org_non_owners_team_broadcast; /*   976     4 */
	string_t                   org_team_drop;        /*   980     4 */
	string_t                   org_non_team_drop;    /*   984     4 */
	string_t                   org_message;          /*   988     4 */
	string_t                   org_noise3;           /*   992     4 */
	string_t                   org_noise4;           /*   996     4 */
	string_t                   netname_broadcast;    /*  1000     4 */
	string_t                   netname_team_broadcast; /*  1004     4 */
	string_t                   netname_non_team_broadcast; /*  1008     4 */
	string_t                   netname_owners_team_broadcast; /*  1012     4 */
	string_t                   netname_team_drop;    /*  1016     4 */
	string_t                   netname_non_team_drop; /*  1020     4 */
	/* --- cacheline 16 boundary (1024 bytes) --- */
	string_t                   speak;                /*  1024     4 */
	string_t                   AP_speak;             /*  1028     4 */
	string_t                   team_speak;           /*  1032     4 */
	string_t                   non_team_speak;       /*  1036     4 */
	string_t                   owners_team_speak;    /*  1040     4 */
	string_t                   non_owners_team_speak; /*  1044     4 */
	string_t                   deathtype;            /*  1048     4 */
	int                        all_active;           /*  1052     4 */
	int                        item_list;            /*  1056     4 */
	float                      delay_time;           /*  1060     4 */
	BOOL                       do_triggerwork;       /*  1064     4 */
	float                      rv_s_h;               /*  1068     4 */
	float                      rs_s_h;               /*  1072     4 */
	float                      rv_gr;                /*  1076     4 */
	float                      rs_gr;                /*  1080     4 */
	float                      rv_g;                 /*  1084     4 */
	/* --- cacheline 17 boundary (1088 bytes) --- */
	float                      rs_g;                 /*  1088     4 */
	float                      has_abbreviated;      /*  1092     4 */
	int                        timer_type;           /*  1096     4 */
	float                      invincible_finished;  /*  1100     4 */
	float                      invisible_finished;   /*  1104     4 */
	float                      super_damage_finished; /*  1108     4 */
	float                      radsuit_finished;     /*  1112     4 */
	BOOL                       m_bLostInvincSound;   /*  1116     4 */
	BOOL                       m_bLostInvisSound;    /*  1120     4 */
	BOOL                       m_bLostSuperSound;    /*  1124     4 */
	BOOL                       m_bLostRadSound;      /*  1128     4 */
	float                      m_fInvincSound;       /*  1132     4 */
	float                      m_fSuperSound;        /*  1136     4 */
	void CBaseEntity(class CBaseEntity *, const class CBaseEntity  &); /* linkage=_ZN11CBaseEntityC4ERKS_ */

	void CBaseEntity(class CBaseEntity *); /* linkage=_ZN11CBaseEntityC4Ev */

	virtual void ~CBaseEntity(class CBaseEntity *, int); /* linkage=_ZN11CBaseEntityD4Ev */

	virtual void Spawn(class CBaseEntity *); /* linkage=_ZN11CBaseEntity5SpawnEv */

	virtual void Precache(class CBaseEntity *); /* linkage=_ZN11CBaseEntity8PrecacheEv */

	virtual void KeyValue(class CBaseEntity *, KeyValueData *); /* linkage=_ZN11CBaseEntity8KeyValueEP14KeyValueData_s */

	void KeyValuePartTwo(class CBaseEntity *, KeyValueData *); /* linkage=_ZN11CBaseEntity15KeyValuePartTwoEP14KeyValueData_s */

	void KeyValuePartThree(class CBaseEntity *, KeyValueData *); /* linkage=_ZN11CBaseEntity17KeyValuePartThreeEP14KeyValueData_s */

	virtual int Save(class CBaseEntity *, class CSave &); /* linkage=_ZN11CBaseEntity4SaveER5CSave */

	virtual int Restore(class CBaseEntity *, class CRestore &); /* linkage=_ZN11CBaseEntity7RestoreER8CRestore */

	virtual int ObjectCaps(class CBaseEntity *); /* linkage=_ZN11CBaseEntity10ObjectCapsEv */

	virtual void Activate(class CBaseEntity *); /* linkage=_ZN11CBaseEntity8ActivateEv */

	virtual void SetObjectCollisionBox(class CBaseEntity *); /* linkage=_ZN11CBaseEntity21SetObjectCollisionBoxEv */

	virtual int Classify(class CBaseEntity *); /* linkage=_ZN11CBaseEntity8ClassifyEv */

	virtual void DeathNotice(class CBaseEntity *, entvars_t *); /* linkage=_ZN11CBaseEntity11DeathNoticeEP9entvars_s */

	virtual void TraceAttack(class CBaseEntity *, entvars_t *, float, class Vector, class  *, int); /* linkage=_ZN11CBaseEntity11TraceAttackEP9entvars_sf6VectorP11TraceResulti */

	virtual int TakeDamage(class CBaseEntity *, entvars_t *, entvars_t *, float, int); /* linkage=_ZN11CBaseEntity10TakeDamageEP9entvars_sS1_fi */

	virtual int TakeHealth(class CBaseEntity *, float, int); /* linkage=_ZN11CBaseEntity10TakeHealthEfi */

	virtual void Killed(class CBaseEntity *, entvars_t *, entvars_t *, int); /* linkage=_ZN11CBaseEntity6KilledEP9entvars_sS1_i */

	virtual int BloodColor(class CBaseEntity *); /* linkage=_ZN11CBaseEntity10BloodColorEv */

	virtual void TraceBleed(class CBaseEntity *, float, class Vector, class  *, int); /* linkage=_ZN11CBaseEntity10TraceBleedEf6VectorP11TraceResulti */

	virtual int IsTriggered(class CBaseEntity *); /* linkage=_ZN11CBaseEntity11IsTriggeredEv */

	virtual class CBaseMonster * MyMonsterPointer(class CBaseEntity *); /* linkage=_ZN11CBaseEntity16MyMonsterPointerEv */

	virtual class CSquadMonster * MySquadMonsterPointer(class CBaseEntity *); /* linkage=_ZN11CBaseEntity21MySquadMonsterPointerEv */

	virtual int GetToggleState(class CBaseEntity *); /* linkage=_ZN11CBaseEntity14GetToggleStateEv */

	virtual BOOL AddPlayerItem(class CBaseEntity *, class CBasePlayerItem *); /* linkage=_ZN11CBaseEntity13AddPlayerItemEP15CBasePlayerItem */

	virtual BOOL RemovePlayerItem(class CBaseEntity *, class CBasePlayerItem *); /* linkage=_ZN11CBaseEntity16RemovePlayerItemEP15CBasePlayerItem */

	virtual int GiveAmmo(class CBaseEntity *, int, char *, int, int *); /* linkage=_ZN11CBaseEntity8GiveAmmoEiPciPi */

	virtual float GetDelay(class CBaseEntity *); /* linkage=_ZN11CBaseEntity8GetDelayEv */

	virtual int IsMoving(class CBaseEntity *); /* linkage=_ZN11CBaseEntity8IsMovingEv */

	virtual void OverrideReset(class CBaseEntity *); /* linkage=_ZN11CBaseEntity13OverrideResetEv */

	virtual int DamageDecal(class CBaseEntity *, int); /* linkage=_ZN11CBaseEntity11DamageDecalEi */

	virtual void SetToggleState(class CBaseEntity *, int); /* linkage=_ZN11CBaseEntity14SetToggleStateEi */

	virtual void StartSneaking(class CBaseEntity *); /* linkage=_ZN11CBaseEntity13StartSneakingEv */

	virtual void StopSneaking(class CBaseEntity *); /* linkage=_ZN11CBaseEntity12StopSneakingEv */

	virtual BOOL OnControls(class CBaseEntity *, entvars_t *); /* linkage=_ZN11CBaseEntity10OnControlsEP9entvars_s */

	virtual BOOL IsSneaking(class CBaseEntity *); /* linkage=_ZN11CBaseEntity10IsSneakingEv */

	virtual BOOL IsAlive(class CBaseEntity *); /* linkage=_ZN11CBaseEntity7IsAliveEv */

	virtual BOOL IsBSPModel(class CBaseEntity *); /* linkage=_ZN11CBaseEntity10IsBSPModelEv */

	virtual BOOL ReflectGauss(class CBaseEntity *); /* linkage=_ZN11CBaseEntity12ReflectGaussEv */

	virtual BOOL HasTarget(class CBaseEntity *, string_t); /* linkage=_ZN11CBaseEntity9HasTargetEj */

	virtual BOOL IsInWorld(class CBaseEntity *); /* linkage=_ZN11CBaseEntity9IsInWorldEv */

	virtual BOOL IsPlayer(class CBaseEntity *); /* linkage=_ZN11CBaseEntity8IsPlayerEv */

	virtual BOOL IsNetClient(class CBaseEntity *); /* linkage=_ZN11CBaseEntity11IsNetClientEv */

	virtual const char  * DB_GetItemName(class CBaseEntity *); /* linkage=_ZN11CBaseEntity14DB_GetItemNameEv */

	virtual class CBaseEntity * GetNextTarget(class CBaseEntity *); /* linkage=_ZN11CBaseEntity13GetNextTargetEv */

	virtual void Think(class CBaseEntity *); /* linkage=_ZN11CBaseEntity5ThinkEv */

	virtual void Touch(class CBaseEntity *, class CBaseEntity *); /* linkage=_ZN11CBaseEntity5TouchEPS_ */

	virtual void Use(class CBaseEntity *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN11CBaseEntity3UseEPS_S0_8USE_TYPEf */

	virtual void Blocked(class CBaseEntity *, class CBaseEntity *); /* linkage=_ZN11CBaseEntity7BlockedEPS_ */

	void * operator new(size_t, entvars_t *); /* linkage=_ZN11CBaseEntitynwEjP9entvars_s */

	void operator delete(void *); /* linkage=_ZN11CBaseEntitydlEPv */

	void UpdateOnRemove(class CBaseEntity *); /* linkage=_ZN11CBaseEntity14UpdateOnRemoveEv */

	void SUB_Remove(class CBaseEntity *); /* linkage=_ZN11CBaseEntity10SUB_RemoveEv */

	void SUB_DoNothing(class CBaseEntity *); /* linkage=_ZN11CBaseEntity13SUB_DoNothingEv */

	void SUB_StartFadeOut(class CBaseEntity *); /* linkage=_ZN11CBaseEntity16SUB_StartFadeOutEv */

	void SUB_FadeOut(class CBaseEntity *); /* linkage=_ZN11CBaseEntity11SUB_FadeOutEv */

	void SUB_CallUseToggle(class CBaseEntity *); /* linkage=_ZN11CBaseEntity17SUB_CallUseToggleEv */

	int ShouldToggle(class CBaseEntity *, USE_TYPE, BOOL); /* linkage=_ZN11CBaseEntity12ShouldToggleE8USE_TYPEi */

	void FireBullets(class CBaseEntity *, ULONG, class Vector, class Vector, class Vector, float, int, int, int, entvars_t *); /* linkage=_ZN11CBaseEntity11FireBulletsEj6VectorS0_S0_fiiiP9entvars_s */

	virtual class CBaseEntity * Respawn(class CBaseEntity *); /* linkage=_ZN11CBaseEntity7RespawnEv */

	void SUB_UseTargets(class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN11CBaseEntity14SUB_UseTargetsEPS_8USE_TYPEf */

	int Intersects(class CBaseEntity *, class CBaseEntity *); /* linkage=_ZN11CBaseEntity10IntersectsEPS_ */

	void MakeDormant(class CBaseEntity *); /* linkage=_ZN11CBaseEntity11MakeDormantEv */

	int IsDormant(class CBaseEntity *); /* linkage=_ZN11CBaseEntity9IsDormantEv */

	BOOL IsLockedByMaster(class CBaseEntity *); /* linkage=_ZN11CBaseEntity16IsLockedByMasterEv */

	class CBaseEntity * Instance(edict_t *); /* linkage=_ZN11CBaseEntity8InstanceEP7edict_s */

	class CBaseEntity * Instance(entvars_t *); /* linkage=_ZN11CBaseEntity8InstanceEP9entvars_s */

	class CBaseEntity * Instance(int); /* linkage=_ZN11CBaseEntity8InstanceEi */

	class CBaseMonster * GetMonsterPointer(class CBaseEntity *, entvars_t *); /* linkage=_ZN11CBaseEntity17GetMonsterPointerEP9entvars_s */

	class CBaseMonster * GetMonsterPointer(class CBaseEntity *, edict_t *); /* linkage=_ZN11CBaseEntity17GetMonsterPointerEP7edict_s */

	virtual void UpdateOwner(class CBaseEntity *); /* linkage=_ZN11CBaseEntity11UpdateOwnerEv */

	class CBaseEntity * Create(char *, const class Vector  &, const class Vector  &, edict_t *); /* linkage=_ZN11CBaseEntity6CreateEPcRK6VectorS3_P7edict_s */

	virtual BOOL FBecomeProne(class CBaseEntity *); /* linkage=_ZN11CBaseEntity12FBecomeProneEv */

	edict_t * edict(class CBaseEntity *); /* linkage=_ZN11CBaseEntity5edictEv */

	EOFFSET eoffset(class CBaseEntity *); /* linkage=_ZN11CBaseEntity7eoffsetEv */

	int entindex(class CBaseEntity *); /* linkage=_ZN11CBaseEntity8entindexEv */

	virtual class Vector Center(class CBaseEntity *); /* linkage=_ZN11CBaseEntity6CenterEv */

	virtual class Vector EyePosition(class CBaseEntity *); /* linkage=_ZN11CBaseEntity11EyePositionEv */

	virtual class Vector EarPosition(class CBaseEntity *); /* linkage=_ZN11CBaseEntity11EarPositionEv */

	virtual class Vector BodyTarget(class CBaseEntity *, const class Vector  &); /* linkage=_ZN11CBaseEntity10BodyTargetERK6Vector */

	virtual int Illumination(class CBaseEntity *); /* linkage=_ZN11CBaseEntity12IlluminationEv */

	virtual BOOL FVisible(class CBaseEntity *, class CBaseEntity *); /* linkage=_ZN11CBaseEntity8FVisibleEPS_ */

	virtual BOOL FVisible(class CBaseEntity *, const class Vector  &); /* linkage=_ZN11CBaseEntity8FVisibleERK6Vector */

	virtual BOOL EngineerUse(class CBaseEntity *, class CBasePlayer *); /* linkage=_ZN11CBaseEntity11EngineerUseEP11CBasePlayer */

	class CBaseEntity * FindTimer(class CBaseEntity *, int); /* linkage=_ZN11CBaseEntity9FindTimerEi */

	class CBaseEntity * CreateTimer(class CBaseEntity *, int); /* linkage=_ZN11CBaseEntity11CreateTimerEi */

	BOOL CheckExistence(class CBaseEntity *); /* linkage=_ZN11CBaseEntity14CheckExistenceEv */

	void CheckBelowBuilding(class CBaseEntity *, int); /* linkage=_ZN11CBaseEntity18CheckBelowBuildingEi */

	int CheckArea(class CBaseEntity *, class CBaseEntity *); /* linkage=_ZN11CBaseEntity9CheckAreaEPS_ */

	virtual void Finished(class CBaseEntity *); /* linkage=_ZN11CBaseEntity8FinishedEv */

	BOOL IsAlly(class CBaseEntity *, class CBaseEntity *); /* linkage=_ZN11CBaseEntity6IsAllyEPS_ */

	BOOL IsAlly(class CBaseEntity *, int); /* linkage=_ZN11CBaseEntity6IsAllyEi */

	BOOL IsTeammate(class CBaseEntity *, class CBaseEntity *); /* linkage=_ZN11CBaseEntity10IsTeammateEPS_ */

	virtual void TeamFortress_EMPExplode(class CBaseEntity *, entvars_t *, float, float); /* linkage=_ZN11CBaseEntity23TeamFortress_EMPExplodeEP9entvars_sff */

	virtual void TeamFortress_CalcEMPDmgRad(class CBaseEntity *, float &, float &); /* linkage=_ZN11CBaseEntity26TeamFortress_CalcEMPDmgRadERfS0_ */

	virtual void TeamFortress_TakeEMPBlast(class CBaseEntity *, entvars_t *); /* linkage=_ZN11CBaseEntity25TeamFortress_TakeEMPBlastEP9entvars_s */

	virtual void TeamFortress_EMPRemove(class CBaseEntity *); /* linkage=_ZN11CBaseEntity22TeamFortress_EMPRemoveEv */

	virtual void TeamFortress_TakeConcussionBlast(class CBaseEntity *, entvars_t *, float); /* linkage=_ZN11CBaseEntity32TeamFortress_TakeConcussionBlastEP9entvars_sf */

	virtual void TeamFortress_Concuss(class CBaseEntity *, entvars_t *); /* linkage=_ZN11CBaseEntity20TeamFortress_ConcussEP9entvars_s */

	void Timer_Infection(class CBaseEntity *); /* linkage=_ZN11CBaseEntity15Timer_InfectionEv */

	void Timer_HealthRot(class CBaseEntity *); /* linkage=_ZN11CBaseEntity15Timer_HealthRotEv */

	void Timer_Hallucination(class CBaseEntity *); /* linkage=_ZN11CBaseEntity19Timer_HallucinationEv */

	void Timer_Tranquilisation(class CBaseEntity *); /* linkage=_ZN11CBaseEntity21Timer_TranquilisationEv */

	void Timer_Regeneration(class CBaseEntity *); /* linkage=_ZN11CBaseEntity18Timer_RegenerationEv */

	void Timer_Birthday(class CBaseEntity *); /* linkage=_ZN11CBaseEntity14Timer_BirthdayEv */

	void Timer_DetpackSet(class CBaseEntity *); /* linkage=_ZN11CBaseEntity16Timer_DetpackSetEv */

	void Timer_DetpackDisarm(class CBaseEntity *); /* linkage=_ZN11CBaseEntity19Timer_DetpackDisarmEv */

	void Timer_FinishedBuilding(class CBaseEntity *); /* linkage=_ZN11CBaseEntity22Timer_FinishedBuildingEv */

	void Timer_CheckBuildDistance(class CBaseEntity *); /* linkage=_ZN11CBaseEntity24Timer_CheckBuildDistanceEv */

	void Timer_SpyUndercoverThink(class CBaseEntity *); /* linkage=_ZN11CBaseEntity24Timer_SpyUndercoverThinkEv */

	void Timer_CeaseFireThink(class CBaseEntity *); /* linkage=_ZN11CBaseEntity20Timer_CeaseFireThinkEv */

	void Timer_AutokickThink(class CBaseEntity *); /* linkage=_ZN11CBaseEntity19Timer_AutokickThinkEv */

	void DoRespawn(class CBaseEntity *); /* linkage=_ZN11CBaseEntity9DoRespawnEv */

	void tfgoal_timer_tick(class CBaseEntity *); /* linkage=_ZN11CBaseEntity17tfgoal_timer_tickEv */

	void tfgoalitem_dropthink(class CBaseEntity *); /* linkage=_ZN11CBaseEntity20tfgoalitem_dropthinkEv */

	void tfgoalitem_droptouch(class CBaseEntity *); /* linkage=_ZN11CBaseEntity20tfgoalitem_droptouchEv */

	void tfgoalitem_remove(class CBaseEntity *); /* linkage=_ZN11CBaseEntity17tfgoalitem_removeEv */

	void ReturnItem(class CBaseEntity *); /* linkage=_ZN11CBaseEntity10ReturnItemEv */

	void DelayedResult(class CBaseEntity *); /* linkage=_ZN11CBaseEntity13DelayedResultEv */

	void EndRoundEnd(class CBaseEntity *); /* linkage=_ZN11CBaseEntity11EndRoundEndEv */

	void item_tfgoal_touch(class CBaseEntity *, class CBaseEntity *); /* linkage=_ZN11CBaseEntity17item_tfgoal_touchEPS_ */

	void tfgoal_touch(class CBaseEntity *, class CBaseEntity *); /* linkage=_ZN11CBaseEntity12tfgoal_touchEPS_ */

	void DoDrop(class CBaseEntity *, class Vector); /* linkage=_ZN11CBaseEntity6DoDropE6Vector */

	class CBaseEntity * FindTeamSpawnPoint(class CBaseEntity *); /* linkage=_ZN11CBaseEntity18FindTeamSpawnPointEv */

	/* vtable has 63 entries: {
	   [2] = Spawn(_ZN11CBaseEntity5SpawnEv), 
	   [3] = Precache(_ZN11CBaseEntity8PrecacheEv), 
	   [4] = KeyValue(_ZN11CBaseEntity8KeyValueEP14KeyValueData_s), 
	   [5] = Save(_ZN11CBaseEntity4SaveER5CSave), 
	   [6] = Restore(_ZN11CBaseEntity7RestoreER8CRestore), 
	   [7] = ObjectCaps(_ZN11CBaseEntity10ObjectCapsEv), 
	   [8] = Activate(_ZN11CBaseEntity8ActivateEv), 
	   [9] = SetObjectCollisionBox(_ZN11CBaseEntity21SetObjectCollisionBoxEv), 
	   [10] = Classify(_ZN11CBaseEntity8ClassifyEv), 
	   [11] = DeathNotice(_ZN11CBaseEntity11DeathNoticeEP9entvars_s), 
	   [12] = TraceAttack(_ZN11CBaseEntity11TraceAttackEP9entvars_sf6VectorP11TraceResulti), 
	   [13] = TakeDamage(_ZN11CBaseEntity10TakeDamageEP9entvars_sS1_fi), 
	   [14] = TakeHealth(_ZN11CBaseEntity10TakeHealthEfi), 
	   [15] = Killed(_ZN11CBaseEntity6KilledEP9entvars_sS1_i), 
	   [16] = BloodColor(_ZN11CBaseEntity10BloodColorEv), 
	   [17] = TraceBleed(_ZN11CBaseEntity10TraceBleedEf6VectorP11TraceResulti), 
	   [18] = IsTriggered(_ZN11CBaseEntity11IsTriggeredEv), 
	   [19] = MyMonsterPointer(_ZN11CBaseEntity16MyMonsterPointerEv), 
	   [20] = MySquadMonsterPointer(_ZN11CBaseEntity21MySquadMonsterPointerEv), 
	   [21] = GetToggleState(_ZN11CBaseEntity14GetToggleStateEv), 
	   [22] = AddPlayerItem(_ZN11CBaseEntity13AddPlayerItemEP15CBasePlayerItem), 
	   [23] = RemovePlayerItem(_ZN11CBaseEntity16RemovePlayerItemEP15CBasePlayerItem), 
	   [24] = GiveAmmo(_ZN11CBaseEntity8GiveAmmoEiPciPi), 
	   [25] = GetDelay(_ZN11CBaseEntity8GetDelayEv), 
	   [26] = IsMoving(_ZN11CBaseEntity8IsMovingEv), 
	   [27] = OverrideReset(_ZN11CBaseEntity13OverrideResetEv), 
	   [28] = DamageDecal(_ZN11CBaseEntity11DamageDecalEi), 
	   [29] = SetToggleState(_ZN11CBaseEntity14SetToggleStateEi), 
	   [30] = StartSneaking(_ZN11CBaseEntity13StartSneakingEv), 
	   [31] = StopSneaking(_ZN11CBaseEntity12StopSneakingEv), 
	   [32] = OnControls(_ZN11CBaseEntity10OnControlsEP9entvars_s), 
	   [33] = IsSneaking(_ZN11CBaseEntity10IsSneakingEv), 
	   [34] = IsAlive(_ZN11CBaseEntity7IsAliveEv), 
	   [35] = IsBSPModel(_ZN11CBaseEntity10IsBSPModelEv), 
	   [36] = ReflectGauss(_ZN11CBaseEntity12ReflectGaussEv), 
	   [37] = HasTarget(_ZN11CBaseEntity9HasTargetEj), 
	   [38] = IsInWorld(_ZN11CBaseEntity9IsInWorldEv), 
	   [39] = IsPlayer(_ZN11CBaseEntity8IsPlayerEv), 
	   [40] = IsNetClient(_ZN11CBaseEntity11IsNetClientEv), 
	   [41] = DB_GetItemName(_ZN11CBaseEntity14DB_GetItemNameEv), 
	   [42] = GetNextTarget(_ZN11CBaseEntity13GetNextTargetEv), 
	   [43] = Think(_ZN11CBaseEntity5ThinkEv), 
	   [44] = Touch(_ZN11CBaseEntity5TouchEPS_), 
	   [45] = Use(_ZN11CBaseEntity3UseEPS_S0_8USE_TYPEf), 
	   [46] = Blocked(_ZN11CBaseEntity7BlockedEPS_), 
	   [47] = Respawn(_ZN11CBaseEntity7RespawnEv), 
	   [48] = UpdateOwner(_ZN11CBaseEntity11UpdateOwnerEv), 
	   [49] = FBecomeProne(_ZN11CBaseEntity12FBecomeProneEv), 
	   [50] = Center(_ZN11CBaseEntity6CenterEv), 
	   [51] = EyePosition(_ZN11CBaseEntity11EyePositionEv), 
	   [52] = EarPosition(_ZN11CBaseEntity11EarPositionEv), 
	   [53] = BodyTarget(_ZN11CBaseEntity10BodyTargetERK6Vector), 
	   [54] = Illumination(_ZN11CBaseEntity12IlluminationEv), 
	   [55] = FVisible(_ZN11CBaseEntity8FVisibleEPS_), 
	   [56] = FVisible(_ZN11CBaseEntity8FVisibleERK6Vector), 
	   [57] = EngineerUse(_ZN11CBaseEntity11EngineerUseEP11CBasePlayer), 
	   [58] = Finished(_ZN11CBaseEntity8FinishedEv), 
	   [59] = TeamFortress_EMPExplode(_ZN11CBaseEntity23TeamFortress_EMPExplodeEP9entvars_sff), 
	   [60] = TeamFortress_CalcEMPDmgRad(_ZN11CBaseEntity26TeamFortress_CalcEMPDmgRadERfS0_), 
	   [61] = TeamFortress_TakeEMPBlast(_ZN11CBaseEntity25TeamFortress_TakeEMPBlastEP9entvars_s), 
	   [62] = TeamFortress_EMPRemove(_ZN11CBaseEntity22TeamFortress_EMPRemoveEv), 
	   [63] = TeamFortress_TakeConcussionBlast(_ZN11CBaseEntity32TeamFortress_TakeConcussionBlastEP9entvars_sf), 
	   [64] = TeamFortress_Concuss(_ZN11CBaseEntity20TeamFortress_ConcussEP9entvars_s), 
	} */
	/* size: 1140, cachelines: 18, members: 260, static members: 1 */
	/* sum members: 1138, holes: 1, sum holes: 2 */
	/* last cacheline: 52 bytes */
};
class CNoGrenadeArea : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0  1140 */

	/* XXX last struct has 1 hole */
	void CNoGrenadeArea(class CNoGrenadeArea *, class CNoGrenadeArea &); /* linkage=_ZN14CNoGrenadeAreaC4EOS_ */

	void CNoGrenadeArea(class CNoGrenadeArea *, const class CNoGrenadeArea  &); /* linkage=_ZN14CNoGrenadeAreaC4ERKS_ */

	void CNoGrenadeArea(class CNoGrenadeArea *); /* linkage=_ZN14CNoGrenadeAreaC4Ev */

	virtual void Spawn(class CNoGrenadeArea *); /* linkage=_ZN14CNoGrenadeArea5SpawnEv */

	void NoGrenadeTouch(class CNoGrenadeArea *, class CBaseEntity *); /* linkage=_ZN14CNoGrenadeArea14NoGrenadeTouchEP11CBaseEntity */

	virtual void ~CNoGrenadeArea(class CNoGrenadeArea *, int); /* linkage=_ZN14CNoGrenadeAreaD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN14CNoGrenadeArea5SpawnEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 52 bytes */
};
class CTeamSet : public CBaseDelay {
public:

	/* class CBaseDelay          <ancestor>; */      /*     0     0 */
	void CTeamSet(class CTeamSet *, class CTeamSet &); /* linkage=_ZN8CTeamSetC4EOS_ */

	void CTeamSet(class CTeamSet *, const class CTeamSet  &); /* linkage=_ZN8CTeamSetC4ERKS_ */

	void CTeamSet(class CTeamSet *); /* linkage=_ZN8CTeamSetC4Ev */

	virtual void Spawn(class CTeamSet *); /* linkage=_ZN8CTeamSet5SpawnEv */

	virtual void Use(class CTeamSet *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN8CTeamSet3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void ~CTeamSet(class CTeamSet *, int); /* linkage=_ZN8CTeamSetD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN8CTeamSet5SpawnEv), 
	   [45] = Use(_ZN8CTeamSet3UseEP11CBaseEntityS1_8USE_TYPEf), 
	} */
	/* size: 1148, cachelines: 18, members: 1 */
	/* padding: 1148 */
	/* last cacheline: 60 bytes */
};
class CTeamCheck : public CBaseDelay {
public:

	/* class CBaseDelay          <ancestor>; */      /*     0     0 */
	void CTeamCheck(class CTeamCheck *, class CTeamCheck &); /* linkage=_ZN10CTeamCheckC4EOS_ */

	void CTeamCheck(class CTeamCheck *, const class CTeamCheck  &); /* linkage=_ZN10CTeamCheckC4ERKS_ */

	void CTeamCheck(class CTeamCheck *); /* linkage=_ZN10CTeamCheckC4Ev */

	virtual void Spawn(class CTeamCheck *); /* linkage=_ZN10CTeamCheck5SpawnEv */

	virtual void Use(class CTeamCheck *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN10CTeamCheck3UseEP11CBaseEntityS1_8USE_TYPEf */

	BOOL TeamMatches(class CTeamCheck *, int); /* linkage=_ZN10CTeamCheck11TeamMatchesEi */

	virtual void ~CTeamCheck(class CTeamCheck *, int); /* linkage=_ZN10CTeamCheckD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN10CTeamCheck5SpawnEv), 
	   [45] = Use(_ZN10CTeamCheck3UseEP11CBaseEntityS1_8USE_TYPEf), 
	} */
	/* size: 1148, cachelines: 18, members: 1 */
	/* padding: 1148 */
	/* last cacheline: 60 bytes */
};
class CTFDetect : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0  1140 */

	/* XXX last struct has 1 hole */
	void CTFDetect(class CTFDetect *, class CTFDetect &); /* linkage=_ZN9CTFDetectC4EOS_ */

	void CTFDetect(class CTFDetect *, const class CTFDetect  &); /* linkage=_ZN9CTFDetectC4ERKS_ */

	void CTFDetect(class CTFDetect *); /* linkage=_ZN9CTFDetectC4Ev */

	virtual void Spawn(class CTFDetect *); /* linkage=_ZN9CTFDetect5SpawnEv */

	virtual int Classify(class CTFDetect *); /* linkage=_ZN9CTFDetect8ClassifyEv */

	virtual void ~CTFDetect(class CTFDetect *, int); /* linkage=_ZN9CTFDetectD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN9CTFDetect5SpawnEv), 
	   [10] = Classify(_ZN9CTFDetect8ClassifyEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 52 bytes */
};
class CTFGoalItem : public CTFGoal {
public:

	/* class CTFGoal             <ancestor>; */      /*     0  1168 */

	/* XXX last struct has 1168 bytes of padding */

	/* --- cacheline 18 boundary (1152 bytes) was 16 bytes ago --- */
	float                      m_flDroppedAt;        /*  1168     4 */
	void CTFGoalItem(class CTFGoalItem *, class CTFGoalItem &); /* linkage=_ZN11CTFGoalItemC4EOS_ */

	void CTFGoalItem(class CTFGoalItem *, const class CTFGoalItem  &); /* linkage=_ZN11CTFGoalItemC4ERKS_ */

	void CTFGoalItem(class CTFGoalItem *); /* linkage=_ZN11CTFGoalItemC4Ev */

	virtual void Spawn(class CTFGoalItem *); /* linkage=_ZN11CTFGoalItem5SpawnEv */

	void StartItem(class CTFGoalItem *); /* linkage=_ZN11CTFGoalItem9StartItemEv */

	void PlaceItem(class CTFGoalItem *); /* linkage=_ZN11CTFGoalItem9PlaceItemEv */

	virtual int Classify(class CTFGoalItem *); /* linkage=_ZN11CTFGoalItem8ClassifyEv */

	virtual void ~CTFGoalItem(class CTFGoalItem *, int); /* linkage=_ZN11CTFGoalItemD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN11CTFGoalItem5SpawnEv), 
	   [10] = Classify(_ZN11CTFGoalItem8ClassifyEv), 
	} */
	/* size: 1172, cachelines: 19, members: 2 */
	/* paddings: 1, sum paddings: 1168 */
	/* last cacheline: 20 bytes */
};
class CTFGoal : public CBaseAnimating {
public:

	/* class CBaseAnimating      <ancestor>; */      /*     0     0 */
	void CTFGoal(class CTFGoal *, class CTFGoal &); /* linkage=_ZN7CTFGoalC4EOS_ */

	void CTFGoal(class CTFGoal *, const class CTFGoal  &); /* linkage=_ZN7CTFGoalC4ERKS_ */

	void CTFGoal(class CTFGoal *); /* linkage=_ZN7CTFGoalC4Ev */

	virtual void Spawn(class CTFGoal *); /* linkage=_ZN7CTFGoal5SpawnEv */

	void StartGoal(class CTFGoal *); /* linkage=_ZN7CTFGoal9StartGoalEv */

	void PlaceGoal(class CTFGoal *); /* linkage=_ZN7CTFGoal9PlaceGoalEv */

	virtual void Use(class CTFGoal *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN7CTFGoal3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual int Classify(class CTFGoal *); /* linkage=_ZN7CTFGoal8ClassifyEv */

	virtual void SetObjectCollisionBox(class CTFGoal *); /* linkage=_ZN7CTFGoal21SetObjectCollisionBoxEv */

	virtual void ~CTFGoal(class CTFGoal *, int); /* linkage=_ZN7CTFGoalD4Ev */

	/* vtable has 4 entries: {
	   [2] = Spawn(_ZN7CTFGoal5SpawnEv), 
	   [45] = Use(_ZN7CTFGoal3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [10] = Classify(_ZN7CTFGoal8ClassifyEv), 
	   [9] = SetObjectCollisionBox(_ZN7CTFGoal21SetObjectCollisionBoxEv), 
	} */
	/* size: 1168, cachelines: 19, members: 1 */
	/* padding: 1168 */
	/* last cacheline: 16 bytes */
};
class CTFTimerGoal : public CTFGoal {
public:

	/* class CTFGoal             <ancestor>; */      /*     0  1168 */

	/* XXX last struct has 1168 bytes of padding */
	void CTFTimerGoal(class CTFTimerGoal *, class CTFTimerGoal &); /* linkage=_ZN12CTFTimerGoalC4EOS_ */

	void CTFTimerGoal(class CTFTimerGoal *, const class CTFTimerGoal  &); /* linkage=_ZN12CTFTimerGoalC4ERKS_ */

	void CTFTimerGoal(class CTFTimerGoal *); /* linkage=_ZN12CTFTimerGoalC4Ev */

	virtual void Spawn(class CTFTimerGoal *); /* linkage=_ZN12CTFTimerGoal5SpawnEv */

	virtual int Classify(class CTFTimerGoal *); /* linkage=_ZN12CTFTimerGoal8ClassifyEv */

	virtual void ~CTFTimerGoal(class CTFTimerGoal *, int); /* linkage=_ZN12CTFTimerGoalD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN12CTFTimerGoal5SpawnEv), 
	   [10] = Classify(_ZN12CTFTimerGoal8ClassifyEv), 
	} */
	/* size: 1168, cachelines: 19, members: 1 */
	/* paddings: 1, sum paddings: 1168 */
	/* last cacheline: 16 bytes */
};
class CTFSpawn : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0  1140 */

	/* XXX last struct has 1 hole */

	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	class EHANDLE             m_pTeamCheck;          /*  1140     8 */
	void CTFSpawn(class CTFSpawn *, class CTFSpawn &); /* linkage=_ZN8CTFSpawnC4EOS_ */

	void CTFSpawn(class CTFSpawn *, const class CTFSpawn  &); /* linkage=_ZN8CTFSpawnC4ERKS_ */

	void CTFSpawn(class CTFSpawn *); /* linkage=_ZN8CTFSpawnC4Ev */

	virtual void Spawn(class CTFSpawn *); /* linkage=_ZN8CTFSpawn5SpawnEv */

	virtual void Activate(class CTFSpawn *); /* linkage=_ZN8CTFSpawn8ActivateEv */

	virtual int Classify(class CTFSpawn *); /* linkage=_ZN8CTFSpawn8ClassifyEv */

	BOOL CheckTeam(class CTFSpawn *, int); /* linkage=_ZN8CTFSpawn9CheckTeamEi */

	virtual void ~CTFSpawn(class CTFSpawn *, int); /* linkage=_ZN8CTFSpawnD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN8CTFSpawn5SpawnEv), 
	   [8] = Activate(_ZN8CTFSpawn8ActivateEv), 
	   [10] = Classify(_ZN8CTFSpawn8ClassifyEv), 
	} */
	/* size: 1148, cachelines: 18, members: 2 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 60 bytes */
};
class CTriggerCamera : public CBaseDelay {

	/* XXX 1148 bytes hole, try to pack */
public:


	/* class CBaseDelay          <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[13]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 60 bytes ago --- */
	class EHANDLE             m_hPlayer;             /*  1148     8 */
	/* --- cacheline 18 boundary (1152 bytes) was 4 bytes ago --- */
	class EHANDLE             m_hTarget;             /*  1156     8 */
	class CBaseEntity *        m_pentPath;           /*  1164     4 */
	int                        m_sPath;              /*  1168     4 */
	float                      m_flWait;             /*  1172     4 */
	float                      m_flReturnTime;       /*  1176     4 */
	float                      m_flStopTime;         /*  1180     4 */
	float                      m_moveDistance;       /*  1184     4 */
	float                      m_targetSpeed;        /*  1188     4 */
	float                      m_initialSpeed;       /*  1192     4 */
	float                      m_acceleration;       /*  1196     4 */
	float                      m_deceleration;       /*  1200     4 */
	int                        m_state;              /*  1204     4 */
	void CTriggerCamera(class CTriggerCamera *, class CTriggerCamera &); /* linkage=_ZN14CTriggerCameraC4EOS_ */

	void CTriggerCamera(class CTriggerCamera *, const class CTriggerCamera  &); /* linkage=_ZN14CTriggerCameraC4ERKS_ */

	void CTriggerCamera(class CTriggerCamera *); /* linkage=_ZN14CTriggerCameraC4Ev */

	virtual void Spawn(class CTriggerCamera *); /* linkage=_ZN14CTriggerCamera5SpawnEv */

	virtual void KeyValue(class CTriggerCamera *, KeyValueData *); /* linkage=_ZN14CTriggerCamera8KeyValueEP14KeyValueData_s */

	virtual void Use(class CTriggerCamera *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN14CTriggerCamera3UseEP11CBaseEntityS1_8USE_TYPEf */

	void FollowTarget(class CTriggerCamera *); /* linkage=_ZN14CTriggerCamera12FollowTargetEv */

	void Move(class CTriggerCamera *); /* linkage=_ZN14CTriggerCamera4MoveEv */

	virtual int Save(class CTriggerCamera *, class CSave &); /* linkage=_ZN14CTriggerCamera4SaveER5CSave */

	virtual int Restore(class CTriggerCamera *, class CRestore &); /* linkage=_ZN14CTriggerCamera7RestoreER8CRestore */

	virtual int ObjectCaps(class CTriggerCamera *); /* linkage=_ZN14CTriggerCamera10ObjectCapsEv */

	virtual void ~CTriggerCamera(class CTriggerCamera *, int); /* linkage=_ZN14CTriggerCameraD4Ev */

	/* vtable has 6 entries: {
	   [2] = Spawn(_ZN14CTriggerCamera5SpawnEv), 
	   [4] = KeyValue(_ZN14CTriggerCamera8KeyValueEP14KeyValueData_s), 
	   [45] = Use(_ZN14CTriggerCamera3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [5] = Save(_ZN14CTriggerCamera4SaveER5CSave), 
	   [6] = Restore(_ZN14CTriggerCamera7RestoreER8CRestore), 
	   [7] = ObjectCaps(_ZN14CTriggerCamera10ObjectCapsEv), 
	} */
	/* size: 1208, cachelines: 19, members: 14, static members: 1 */
	/* sum members: 60, holes: 1, sum holes: 1148 */
	/* last cacheline: 56 bytes */
};
class CTriggerChangeTarget : public CBaseDelay {

	/* XXX 1148 bytes hole, try to pack */
public:


	/* class CBaseDelay          <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[1]; /*     0     0 */
private:

	/* --- cacheline 17 boundary (1088 bytes) was 60 bytes ago --- */
	int                        m_iszNewTarget;       /*  1148     4 */
	void CTriggerChangeTarget(class CTriggerChangeTarget *, class CTriggerChangeTarget &); /* linkage=_ZN20CTriggerChangeTargetC4EOS_ */

	void CTriggerChangeTarget(class CTriggerChangeTarget *, const class CTriggerChangeTarget  &); /* linkage=_ZN20CTriggerChangeTargetC4ERKS_ */

	void CTriggerChangeTarget(class CTriggerChangeTarget *); /* linkage=_ZN20CTriggerChangeTargetC4Ev */

	virtual void KeyValue(class CTriggerChangeTarget *, KeyValueData *); /* linkage=_ZN20CTriggerChangeTarget8KeyValueEP14KeyValueData_s */

	virtual void Spawn(class CTriggerChangeTarget *); /* linkage=_ZN20CTriggerChangeTarget5SpawnEv */

	virtual void Use(class CTriggerChangeTarget *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN20CTriggerChangeTarget3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual int ObjectCaps(class CTriggerChangeTarget *); /* linkage=_ZN20CTriggerChangeTarget10ObjectCapsEv */

	virtual int Save(class CTriggerChangeTarget *, class CSave &); /* linkage=_ZN20CTriggerChangeTarget4SaveER5CSave */

	virtual int Restore(class CTriggerChangeTarget *, class CRestore &); /* linkage=_ZN20CTriggerChangeTarget7RestoreER8CRestore */

	virtual void ~CTriggerChangeTarget(class CTriggerChangeTarget *, int); /* linkage=_ZN20CTriggerChangeTargetD4Ev */

	/* vtable has 6 entries: {
	   [4] = KeyValue(_ZN20CTriggerChangeTarget8KeyValueEP14KeyValueData_s), 
	   [2] = Spawn(_ZN20CTriggerChangeTarget5SpawnEv), 
	   [45] = Use(_ZN20CTriggerChangeTarget3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [7] = ObjectCaps(_ZN20CTriggerChangeTarget10ObjectCapsEv), 
	   [5] = Save(_ZN20CTriggerChangeTarget4SaveER5CSave), 
	   [6] = Restore(_ZN20CTriggerChangeTarget7RestoreER8CRestore), 
	} */
	/* size: 1152, cachelines: 18, members: 2, static members: 1 */
	/* sum members: 4, holes: 1, sum holes: 1148 */
};
class CTriggerGravity : public CBaseTrigger {
public:

	/* class CBaseTrigger        <ancestor>; */      /*     0  1300 */

	/* XXX last struct has 1300 bytes of padding */
	void CTriggerGravity(class CTriggerGravity *, class CTriggerGravity &); /* linkage=_ZN15CTriggerGravityC4EOS_ */

	void CTriggerGravity(class CTriggerGravity *, const class CTriggerGravity  &); /* linkage=_ZN15CTriggerGravityC4ERKS_ */

	void CTriggerGravity(class CTriggerGravity *); /* linkage=_ZN15CTriggerGravityC4Ev */

	virtual void Spawn(class CTriggerGravity *); /* linkage=_ZN15CTriggerGravity5SpawnEv */

	void GravityTouch(class CTriggerGravity *, class CBaseEntity *); /* linkage=_ZN15CTriggerGravity12GravityTouchEP11CBaseEntity */

	virtual void ~CTriggerGravity(class CTriggerGravity *, int); /* linkage=_ZN15CTriggerGravityD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN15CTriggerGravity5SpawnEv), 
	} */
	/* size: 1300, cachelines: 21, members: 1 */
	/* paddings: 1, sum paddings: 1300 */
	/* last cacheline: 20 bytes */
};
class CBaseTrigger : public CBaseToggle {
public:

	/* class CBaseToggle         <ancestor>; */      /*     0     0 */
	void CBaseTrigger(class CBaseTrigger *, class CBaseTrigger &); /* linkage=_ZN12CBaseTriggerC4EOS_ */

	void CBaseTrigger(class CBaseTrigger *, const class CBaseTrigger  &); /* linkage=_ZN12CBaseTriggerC4ERKS_ */

	void CBaseTrigger(class CBaseTrigger *); /* linkage=_ZN12CBaseTriggerC4Ev */

	void TeleportTouch(class CBaseTrigger *, class CBaseEntity *); /* linkage=_ZN12CBaseTrigger13TeleportTouchEP11CBaseEntity */

	virtual void KeyValue(class CBaseTrigger *, KeyValueData *); /* linkage=_ZN12CBaseTrigger8KeyValueEP14KeyValueData_s */

	void MultiTouch(class CBaseTrigger *, class CBaseEntity *); /* linkage=_ZN12CBaseTrigger10MultiTouchEP11CBaseEntity */

	void HurtTouch(class CBaseTrigger *, class CBaseEntity *); /* linkage=_ZN12CBaseTrigger9HurtTouchEP11CBaseEntity */

	void CDAudioTouch(class CBaseTrigger *, class CBaseEntity *); /* linkage=_ZN12CBaseTrigger12CDAudioTouchEP11CBaseEntity */

	void ActivateMultiTrigger(class CBaseTrigger *, class CBaseEntity *); /* linkage=_ZN12CBaseTrigger20ActivateMultiTriggerEP11CBaseEntity */

	void MultiWaitOver(class CBaseTrigger *); /* linkage=_ZN12CBaseTrigger13MultiWaitOverEv */

	void CounterUse(class CBaseTrigger *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN12CBaseTrigger10CounterUseEP11CBaseEntityS1_8USE_TYPEf */

	void ToggleUse(class CBaseTrigger *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN12CBaseTrigger9ToggleUseEP11CBaseEntityS1_8USE_TYPEf */

	void InitTrigger(class CBaseTrigger *); /* linkage=_ZN12CBaseTrigger11InitTriggerEv */

	virtual int ObjectCaps(class CBaseTrigger *); /* linkage=_ZN12CBaseTrigger10ObjectCapsEv */

	virtual void ~CBaseTrigger(class CBaseTrigger *, int); /* linkage=_ZN12CBaseTriggerD4Ev */

	/* vtable has 2 entries: {
	   [4] = KeyValue(_ZN12CBaseTrigger8KeyValueEP14KeyValueData_s), 
	   [7] = ObjectCaps(_ZN12CBaseTrigger10ObjectCapsEv), 
	} */
	/* size: 1300, cachelines: 21, members: 1 */
	/* padding: 1300 */
	/* last cacheline: 20 bytes */
};
class CTriggerEndSection : public CBaseTrigger {
public:

	/* class CBaseTrigger        <ancestor>; */      /*     0  1300 */

	/* XXX last struct has 1300 bytes of padding */
	void CTriggerEndSection(class CTriggerEndSection *, class CTriggerEndSection &); /* linkage=_ZN18CTriggerEndSectionC4EOS_ */

	void CTriggerEndSection(class CTriggerEndSection *, const class CTriggerEndSection  &); /* linkage=_ZN18CTriggerEndSectionC4ERKS_ */

	void CTriggerEndSection(class CTriggerEndSection *); /* linkage=_ZN18CTriggerEndSectionC4Ev */

	virtual void Spawn(class CTriggerEndSection *); /* linkage=_ZN18CTriggerEndSection5SpawnEv */

	void EndSectionTouch(class CTriggerEndSection *, class CBaseEntity *); /* linkage=_ZN18CTriggerEndSection15EndSectionTouchEP11CBaseEntity */

	virtual void KeyValue(class CTriggerEndSection *, KeyValueData *); /* linkage=_ZN18CTriggerEndSection8KeyValueEP14KeyValueData_s */

	void EndSectionUse(class CTriggerEndSection *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN18CTriggerEndSection13EndSectionUseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void ~CTriggerEndSection(class CTriggerEndSection *, int); /* linkage=_ZN18CTriggerEndSectionD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN18CTriggerEndSection5SpawnEv), 
	   [4] = KeyValue(_ZN18CTriggerEndSection8KeyValueEP14KeyValueData_s), 
	} */
	/* size: 1300, cachelines: 21, members: 1 */
	/* paddings: 1, sum paddings: 1300 */
	/* last cacheline: 20 bytes */
};
class CTriggerSave : public CBaseTrigger {
public:

	/* class CBaseTrigger        <ancestor>; */      /*     0  1300 */

	/* XXX last struct has 1300 bytes of padding */
	void CTriggerSave(class CTriggerSave *, class CTriggerSave &); /* linkage=_ZN12CTriggerSaveC4EOS_ */

	void CTriggerSave(class CTriggerSave *, const class CTriggerSave  &); /* linkage=_ZN12CTriggerSaveC4ERKS_ */

	void CTriggerSave(class CTriggerSave *); /* linkage=_ZN12CTriggerSaveC4Ev */

	virtual void Spawn(class CTriggerSave *); /* linkage=_ZN12CTriggerSave5SpawnEv */

	void SaveTouch(class CTriggerSave *, class CBaseEntity *); /* linkage=_ZN12CTriggerSave9SaveTouchEP11CBaseEntity */

	virtual void ~CTriggerSave(class CTriggerSave *, int); /* linkage=_ZN12CTriggerSaveD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN12CTriggerSave5SpawnEv), 
	} */
	/* size: 1300, cachelines: 21, members: 1 */
	/* paddings: 1, sum paddings: 1300 */
	/* last cacheline: 20 bytes */
};
class CTriggerTeleport : public CBaseTrigger {
public:

	/* class CBaseTrigger        <ancestor>; */      /*     0  1300 */

	/* XXX last struct has 1300 bytes of padding */
	void CTriggerTeleport(class CTriggerTeleport *, class CTriggerTeleport &); /* linkage=_ZN16CTriggerTeleportC4EOS_ */

	void CTriggerTeleport(class CTriggerTeleport *, const class CTriggerTeleport  &); /* linkage=_ZN16CTriggerTeleportC4ERKS_ */

	void CTriggerTeleport(class CTriggerTeleport *); /* linkage=_ZN16CTriggerTeleportC4Ev */

	virtual void Spawn(class CTriggerTeleport *); /* linkage=_ZN16CTriggerTeleport5SpawnEv */

	virtual void ~CTriggerTeleport(class CTriggerTeleport *, int); /* linkage=_ZN16CTriggerTeleportD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN16CTriggerTeleport5SpawnEv), 
	} */
	/* size: 1300, cachelines: 21, members: 1 */
	/* paddings: 1, sum paddings: 1300 */
	/* last cacheline: 20 bytes */
};
class CTriggerPush : public CBaseTrigger {
public:

	/* class CBaseTrigger        <ancestor>; */      /*     0  1300 */

	/* XXX last struct has 1300 bytes of padding */
	void CTriggerPush(class CTriggerPush *, class CTriggerPush &); /* linkage=_ZN12CTriggerPushC4EOS_ */

	void CTriggerPush(class CTriggerPush *, const class CTriggerPush  &); /* linkage=_ZN12CTriggerPushC4ERKS_ */

	void CTriggerPush(class CTriggerPush *); /* linkage=_ZN12CTriggerPushC4Ev */

	virtual void Spawn(class CTriggerPush *); /* linkage=_ZN12CTriggerPush5SpawnEv */

	virtual void KeyValue(class CTriggerPush *, KeyValueData *); /* linkage=_ZN12CTriggerPush8KeyValueEP14KeyValueData_s */

	virtual void Touch(class CTriggerPush *, class CBaseEntity *); /* linkage=_ZN12CTriggerPush5TouchEP11CBaseEntity */

	virtual void ~CTriggerPush(class CTriggerPush *, int); /* linkage=_ZN12CTriggerPushD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN12CTriggerPush5SpawnEv), 
	   [4] = KeyValue(_ZN12CTriggerPush8KeyValueEP14KeyValueData_s), 
	   [44] = Touch(_ZN12CTriggerPush5TouchEP11CBaseEntity), 
	} */
	/* size: 1300, cachelines: 21, members: 1 */
	/* paddings: 1, sum paddings: 1300 */
	/* last cacheline: 20 bytes */
};
class CLadder : public CBaseTrigger {
public:

	/* class CBaseTrigger        <ancestor>; */      /*     0  1300 */

	/* XXX last struct has 1300 bytes of padding */
	void CLadder(class CLadder *, class CLadder &); /* linkage=_ZN7CLadderC4EOS_ */

	void CLadder(class CLadder *, const class CLadder  &); /* linkage=_ZN7CLadderC4ERKS_ */

	void CLadder(class CLadder *); /* linkage=_ZN7CLadderC4Ev */

	virtual void KeyValue(class CLadder *, KeyValueData *); /* linkage=_ZN7CLadder8KeyValueEP14KeyValueData_s */

	virtual void Spawn(class CLadder *); /* linkage=_ZN7CLadder5SpawnEv */

	virtual void Precache(class CLadder *); /* linkage=_ZN7CLadder8PrecacheEv */

	virtual void ~CLadder(class CLadder *, int); /* linkage=_ZN7CLadderD4Ev */

	/* vtable has 3 entries: {
	   [4] = KeyValue(_ZN7CLadder8KeyValueEP14KeyValueData_s), 
	   [2] = Spawn(_ZN7CLadder5SpawnEv), 
	   [3] = Precache(_ZN7CLadder8PrecacheEv), 
	} */
	/* size: 1300, cachelines: 21, members: 1 */
	/* paddings: 1, sum paddings: 1300 */
	/* last cacheline: 20 bytes */
};
class CChangeLevel : public CBaseTrigger {
public:

	/* class CBaseTrigger        <ancestor>; */      /*     0  1300 */

	/* XXX last struct has 1300 bytes of padding */

	static TYPEDESCRIPTION            m_SaveData[4]; /*     0     0 */
	/* --- cacheline 20 boundary (1280 bytes) was 20 bytes ago --- */
	char                       m_szMapName[32];      /*  1300    32 */
	char                       m_szLandmarkName[32]; /*  1332    32 */
	/* --- cacheline 21 boundary (1344 bytes) was 20 bytes ago --- */
	int                        m_changeTarget;       /*  1364     4 */
	float                      m_changeTargetDelay;  /*  1368     4 */
	void CChangeLevel(class CChangeLevel *, class CChangeLevel &); /* linkage=_ZN12CChangeLevelC4EOS_ */

	void CChangeLevel(class CChangeLevel *, const class CChangeLevel  &); /* linkage=_ZN12CChangeLevelC4ERKS_ */

	void CChangeLevel(class CChangeLevel *); /* linkage=_ZN12CChangeLevelC4Ev */

	virtual void Spawn(class CChangeLevel *); /* linkage=_ZN12CChangeLevel5SpawnEv */

	virtual void KeyValue(class CChangeLevel *, KeyValueData *); /* linkage=_ZN12CChangeLevel8KeyValueEP14KeyValueData_s */

	void UseChangeLevel(class CChangeLevel *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN12CChangeLevel14UseChangeLevelEP11CBaseEntityS1_8USE_TYPEf */

	void TriggerChangeLevel(class CChangeLevel *); /* linkage=_ZN12CChangeLevel18TriggerChangeLevelEv */

	void ExecuteChangeLevel(class CChangeLevel *); /* linkage=_ZN12CChangeLevel18ExecuteChangeLevelEv */

	void TouchChangeLevel(class CChangeLevel *, class CBaseEntity *); /* linkage=_ZN12CChangeLevel16TouchChangeLevelEP11CBaseEntity */

	void ChangeLevelNow(class CChangeLevel *, class CBaseEntity *); /* linkage=_ZN12CChangeLevel14ChangeLevelNowEP11CBaseEntity */

	edict_t * FindLandmark(const char  *); /* linkage=_ZN12CChangeLevel12FindLandmarkEPKc */

	int ChangeList(class  *, int); /* linkage=_ZN12CChangeLevel10ChangeListEP9LEVELLISTi */

	int AddTransitionToList(class  *, int, const char  *, const char  *, edict_t *); /* linkage=_ZN12CChangeLevel19AddTransitionToListEP9LEVELLISTiPKcS3_P7edict_s */

	int InTransitionVolume(class CBaseEntity *, char *); /* linkage=_ZN12CChangeLevel18InTransitionVolumeEP11CBaseEntityPc */

	virtual int Save(class CChangeLevel *, class CSave &); /* linkage=_ZN12CChangeLevel4SaveER5CSave */

	virtual int Restore(class CChangeLevel *, class CRestore &); /* linkage=_ZN12CChangeLevel7RestoreER8CRestore */

	virtual void ~CChangeLevel(class CChangeLevel *, int); /* linkage=_ZN12CChangeLevelD4Ev */

	/* vtable has 4 entries: {
	   [2] = Spawn(_ZN12CChangeLevel5SpawnEv), 
	   [4] = KeyValue(_ZN12CChangeLevel8KeyValueEP14KeyValueData_s), 
	   [5] = Save(_ZN12CChangeLevel4SaveER5CSave), 
	   [6] = Restore(_ZN12CChangeLevel7RestoreER8CRestore), 
	} */
	/* size: 1372, cachelines: 22, members: 5, static members: 1 */
	/* paddings: 1, sum paddings: 1300 */
	/* last cacheline: 28 bytes */
};
class CFireAndDie : public CBaseDelay {
public:

	/* class CBaseDelay          <ancestor>; */      /*     0     0 */
	void CFireAndDie(class CFireAndDie *, class CFireAndDie &); /* linkage=_ZN11CFireAndDieC4EOS_ */

	void CFireAndDie(class CFireAndDie *, const class CFireAndDie  &); /* linkage=_ZN11CFireAndDieC4ERKS_ */

	void CFireAndDie(class CFireAndDie *); /* linkage=_ZN11CFireAndDieC4Ev */

	virtual void Spawn(class CFireAndDie *); /* linkage=_ZN11CFireAndDie5SpawnEv */

	virtual void Precache(class CFireAndDie *); /* linkage=_ZN11CFireAndDie8PrecacheEv */

	virtual void Think(class CFireAndDie *); /* linkage=_ZN11CFireAndDie5ThinkEv */

	virtual int ObjectCaps(class CFireAndDie *); /* linkage=_ZN11CFireAndDie10ObjectCapsEv */

	virtual void ~CFireAndDie(class CFireAndDie *, int); /* linkage=_ZN11CFireAndDieD4Ev */

	/* vtable has 4 entries: {
	   [2] = Spawn(_ZN11CFireAndDie5SpawnEv), 
	   [3] = Precache(_ZN11CFireAndDie8PrecacheEv), 
	   [43] = Think(_ZN11CFireAndDie5ThinkEv), 
	   [7] = ObjectCaps(_ZN11CFireAndDie10ObjectCapsEv), 
	} */
	/* size: 1148, cachelines: 18, members: 1 */
	/* padding: 1148 */
	/* last cacheline: 60 bytes */
};
class CTriggerVolume : public CPointEntity {
public:

	/* class CPointEntity        <ancestor>; */      /*     0     0 */
	void CTriggerVolume(class CTriggerVolume *, class CTriggerVolume &); /* linkage=_ZN14CTriggerVolumeC4EOS_ */

	void CTriggerVolume(class CTriggerVolume *, const class CTriggerVolume  &); /* linkage=_ZN14CTriggerVolumeC4ERKS_ */

	void CTriggerVolume(class CTriggerVolume *); /* linkage=_ZN14CTriggerVolumeC4Ev */

	virtual void Spawn(class CTriggerVolume *); /* linkage=_ZN14CTriggerVolume5SpawnEv */

	virtual void ~CTriggerVolume(class CTriggerVolume *, int); /* linkage=_ZN14CTriggerVolumeD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN14CTriggerVolume5SpawnEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CTriggerCounter : public CBaseTrigger {
public:

	/* class CBaseTrigger        <ancestor>; */      /*     0  1300 */

	/* XXX last struct has 1300 bytes of padding */
	void CTriggerCounter(class CTriggerCounter *, class CTriggerCounter &); /* linkage=_ZN15CTriggerCounterC4EOS_ */

	void CTriggerCounter(class CTriggerCounter *, const class CTriggerCounter  &); /* linkage=_ZN15CTriggerCounterC4ERKS_ */

	void CTriggerCounter(class CTriggerCounter *); /* linkage=_ZN15CTriggerCounterC4Ev */

	virtual void Spawn(class CTriggerCounter *); /* linkage=_ZN15CTriggerCounter5SpawnEv */

	virtual void ~CTriggerCounter(class CTriggerCounter *, int); /* linkage=_ZN15CTriggerCounterD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN15CTriggerCounter5SpawnEv), 
	} */
	/* size: 1300, cachelines: 21, members: 1 */
	/* paddings: 1, sum paddings: 1300 */
	/* last cacheline: 20 bytes */
};
class CTriggerOnce : public CTriggerMultiple {
public:

	/* class CTriggerMultiple    <ancestor>; */      /*     0  1300 */
	void CTriggerOnce(class CTriggerOnce *, class CTriggerOnce &); /* linkage=_ZN12CTriggerOnceC4EOS_ */

	void CTriggerOnce(class CTriggerOnce *, const class CTriggerOnce  &); /* linkage=_ZN12CTriggerOnceC4ERKS_ */

	void CTriggerOnce(class CTriggerOnce *); /* linkage=_ZN12CTriggerOnceC4Ev */

	virtual void Spawn(class CTriggerOnce *); /* linkage=_ZN12CTriggerOnce5SpawnEv */

	virtual void ~CTriggerOnce(class CTriggerOnce *, int); /* linkage=_ZN12CTriggerOnceD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN12CTriggerOnce5SpawnEv), 
	} */
	/* size: 1300, cachelines: 21, members: 1 */
	/* last cacheline: 20 bytes */
};
class CTriggerMultiple : public CBaseTrigger {
public:

	/* class CBaseTrigger        <ancestor>; */      /*     0  1300 */

	/* XXX last struct has 1300 bytes of padding */
	void CTriggerMultiple(class CTriggerMultiple *, class CTriggerMultiple &); /* linkage=_ZN16CTriggerMultipleC4EOS_ */

	void CTriggerMultiple(class CTriggerMultiple *, const class CTriggerMultiple  &); /* linkage=_ZN16CTriggerMultipleC4ERKS_ */

	void CTriggerMultiple(class CTriggerMultiple *); /* linkage=_ZN16CTriggerMultipleC4Ev */

	virtual void Spawn(class CTriggerMultiple *); /* linkage=_ZN16CTriggerMultiple5SpawnEv */

	virtual void ~CTriggerMultiple(class CTriggerMultiple *, int); /* linkage=_ZN16CTriggerMultipleD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN16CTriggerMultiple5SpawnEv), 
	} */
	/* size: 1300, cachelines: 21, members: 1 */
	/* paddings: 1, sum paddings: 1300 */
	/* last cacheline: 20 bytes */
};
class CTriggerHurt : public CBaseTrigger {
public:

	/* class CBaseTrigger        <ancestor>; */      /*     0  1300 */

	/* XXX last struct has 1300 bytes of padding */
	void CTriggerHurt(class CTriggerHurt *, class CTriggerHurt &); /* linkage=_ZN12CTriggerHurtC4EOS_ */

	void CTriggerHurt(class CTriggerHurt *, const class CTriggerHurt  &); /* linkage=_ZN12CTriggerHurtC4ERKS_ */

	void CTriggerHurt(class CTriggerHurt *); /* linkage=_ZN12CTriggerHurtC4Ev */

	virtual void Spawn(class CTriggerHurt *); /* linkage=_ZN12CTriggerHurt5SpawnEv */

	void RadiationThink(class CTriggerHurt *); /* linkage=_ZN12CTriggerHurt14RadiationThinkEv */

	virtual void ~CTriggerHurt(class CTriggerHurt *, int); /* linkage=_ZN12CTriggerHurtD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN12CTriggerHurt5SpawnEv), 
	} */
	/* size: 1300, cachelines: 21, members: 1 */
	/* paddings: 1, sum paddings: 1300 */
	/* last cacheline: 20 bytes */
};
class CTargetCDAudio : public CPointEntity {
public:

	/* class CPointEntity        <ancestor>; */      /*     0     0 */
	void CTargetCDAudio(class CTargetCDAudio *, class CTargetCDAudio &); /* linkage=_ZN14CTargetCDAudioC4EOS_ */

	void CTargetCDAudio(class CTargetCDAudio *, const class CTargetCDAudio  &); /* linkage=_ZN14CTargetCDAudioC4ERKS_ */

	void CTargetCDAudio(class CTargetCDAudio *); /* linkage=_ZN14CTargetCDAudioC4Ev */

	virtual void Spawn(class CTargetCDAudio *); /* linkage=_ZN14CTargetCDAudio5SpawnEv */

	virtual void KeyValue(class CTargetCDAudio *, KeyValueData *); /* linkage=_ZN14CTargetCDAudio8KeyValueEP14KeyValueData_s */

	virtual void Use(class CTargetCDAudio *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN14CTargetCDAudio3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void Think(class CTargetCDAudio *); /* linkage=_ZN14CTargetCDAudio5ThinkEv */

	void Play(class CTargetCDAudio *); /* linkage=_ZN14CTargetCDAudio4PlayEv */

	virtual void ~CTargetCDAudio(class CTargetCDAudio *, int); /* linkage=_ZN14CTargetCDAudioD4Ev */

	/* vtable has 4 entries: {
	   [2] = Spawn(_ZN14CTargetCDAudio5SpawnEv), 
	   [4] = KeyValue(_ZN14CTargetCDAudio8KeyValueEP14KeyValueData_s), 
	   [45] = Use(_ZN14CTargetCDAudio3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [43] = Think(_ZN14CTargetCDAudio5ThinkEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CTriggerCDAudio : public CBaseTrigger {
public:

	/* class CBaseTrigger        <ancestor>; */      /*     0  1300 */

	/* XXX last struct has 1300 bytes of padding */
	void CTriggerCDAudio(class CTriggerCDAudio *, class CTriggerCDAudio &); /* linkage=_ZN15CTriggerCDAudioC4EOS_ */

	void CTriggerCDAudio(class CTriggerCDAudio *, const class CTriggerCDAudio  &); /* linkage=_ZN15CTriggerCDAudioC4ERKS_ */

	void CTriggerCDAudio(class CTriggerCDAudio *); /* linkage=_ZN15CTriggerCDAudioC4Ev */

	virtual void Spawn(class CTriggerCDAudio *); /* linkage=_ZN15CTriggerCDAudio5SpawnEv */

	virtual void Use(class CTriggerCDAudio *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN15CTriggerCDAudio3UseEP11CBaseEntityS1_8USE_TYPEf */

	void PlayTrack(class CTriggerCDAudio *); /* linkage=_ZN15CTriggerCDAudio9PlayTrackEv */

	virtual void Touch(class CTriggerCDAudio *, class CBaseEntity *); /* linkage=_ZN15CTriggerCDAudio5TouchEP11CBaseEntity */

	virtual void ~CTriggerCDAudio(class CTriggerCDAudio *, int); /* linkage=_ZN15CTriggerCDAudioD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN15CTriggerCDAudio5SpawnEv), 
	   [45] = Use(_ZN15CTriggerCDAudio3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [44] = Touch(_ZN15CTriggerCDAudio5TouchEP11CBaseEntity), 
	} */
	/* size: 1300, cachelines: 21, members: 1 */
	/* paddings: 1, sum paddings: 1300 */
	/* last cacheline: 20 bytes */
};
class CTriggerMonsterJump : public CBaseTrigger {
public:

	/* class CBaseTrigger        <ancestor>; */      /*     0  1300 */

	/* XXX last struct has 1300 bytes of padding */
	void CTriggerMonsterJump(class CTriggerMonsterJump *, class CTriggerMonsterJump &); /* linkage=_ZN19CTriggerMonsterJumpC4EOS_ */

	void CTriggerMonsterJump(class CTriggerMonsterJump *, const class CTriggerMonsterJump  &); /* linkage=_ZN19CTriggerMonsterJumpC4ERKS_ */

	void CTriggerMonsterJump(class CTriggerMonsterJump *); /* linkage=_ZN19CTriggerMonsterJumpC4Ev */

	virtual void Spawn(class CTriggerMonsterJump *); /* linkage=_ZN19CTriggerMonsterJump5SpawnEv */

	virtual void Touch(class CTriggerMonsterJump *, class CBaseEntity *); /* linkage=_ZN19CTriggerMonsterJump5TouchEP11CBaseEntity */

	virtual void Think(class CTriggerMonsterJump *); /* linkage=_ZN19CTriggerMonsterJump5ThinkEv */

	virtual void ~CTriggerMonsterJump(class CTriggerMonsterJump *, int); /* linkage=_ZN19CTriggerMonsterJumpD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN19CTriggerMonsterJump5SpawnEv), 
	   [44] = Touch(_ZN19CTriggerMonsterJump5TouchEP11CBaseEntity), 
	   [43] = Think(_ZN19CTriggerMonsterJump5ThinkEv), 
	} */
	/* size: 1300, cachelines: 21, members: 1 */
	/* paddings: 1, sum paddings: 1300 */
	/* last cacheline: 20 bytes */
};
class CRenderFxManager : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CRenderFxManager(class CRenderFxManager *, class CRenderFxManager &); /* linkage=_ZN16CRenderFxManagerC4EOS_ */

	void CRenderFxManager(class CRenderFxManager *, const class CRenderFxManager  &); /* linkage=_ZN16CRenderFxManagerC4ERKS_ */

	void CRenderFxManager(class CRenderFxManager *); /* linkage=_ZN16CRenderFxManagerC4Ev */

	virtual void Spawn(class CRenderFxManager *); /* linkage=_ZN16CRenderFxManager5SpawnEv */

	virtual void Use(class CRenderFxManager *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN16CRenderFxManager3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void ~CRenderFxManager(class CRenderFxManager *, int); /* linkage=_ZN16CRenderFxManagerD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN16CRenderFxManager5SpawnEv), 
	   [45] = Use(_ZN16CRenderFxManager3UseEP11CBaseEntityS1_8USE_TYPEf), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CMultiManager : public CBaseToggle {

	/* XXX 1300 bytes hole, try to pack */
public:


	/* class CBaseToggle         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[5]; /*     0     0 */
	/* --- cacheline 20 boundary (1280 bytes) was 20 bytes ago --- */
	int                        m_cTargets;           /*  1300     4 */
	int                        m_index;              /*  1304     4 */
	float                      m_startTime;          /*  1308     4 */
	int                        m_iTargetName[16];    /*  1312    64 */
	/* --- cacheline 21 boundary (1344 bytes) was 32 bytes ago --- */
	float                      m_flTargetDelay[16];  /*  1376    64 */
	void CMultiManager(class CMultiManager *, class CMultiManager &); /* linkage=_ZN13CMultiManagerC4EOS_ */

	void CMultiManager(class CMultiManager *, const class CMultiManager  &); /* linkage=_ZN13CMultiManagerC4ERKS_ */

	void CMultiManager(class CMultiManager *); /* linkage=_ZN13CMultiManagerC4Ev */

	virtual void KeyValue(class CMultiManager *, KeyValueData *); /* linkage=_ZN13CMultiManager8KeyValueEP14KeyValueData_s */

	virtual void Spawn(class CMultiManager *); /* linkage=_ZN13CMultiManager5SpawnEv */

	void ManagerThink(class CMultiManager *); /* linkage=_ZN13CMultiManager12ManagerThinkEv */

	void ManagerUse(class CMultiManager *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN13CMultiManager10ManagerUseEP11CBaseEntityS1_8USE_TYPEf */

	void ManagerReport(class CMultiManager *); /* linkage=_ZN13CMultiManager13ManagerReportEv */

	virtual BOOL HasTarget(class CMultiManager *, string_t); /* linkage=_ZN13CMultiManager9HasTargetEj */

	virtual int ObjectCaps(class CMultiManager *); /* linkage=_ZN13CMultiManager10ObjectCapsEv */

	virtual int Save(class CMultiManager *, class CSave &); /* linkage=_ZN13CMultiManager4SaveER5CSave */

	virtual int Restore(class CMultiManager *, class CRestore &); /* linkage=_ZN13CMultiManager7RestoreER8CRestore */

	virtual void ~CMultiManager(class CMultiManager *, int); /* linkage=_ZN13CMultiManagerD4Ev */

	/* vtable has 6 entries: {
	   [4] = KeyValue(_ZN13CMultiManager8KeyValueEP14KeyValueData_s), 
	   [2] = Spawn(_ZN13CMultiManager5SpawnEv), 
	   [37] = HasTarget(_ZN13CMultiManager9HasTargetEj), 
	   [7] = ObjectCaps(_ZN13CMultiManager10ObjectCapsEv), 
	   [5] = Save(_ZN13CMultiManager4SaveER5CSave), 
	   [6] = Restore(_ZN13CMultiManager7RestoreER8CRestore), 
	} */
	/* size: 1440, cachelines: 23, members: 6, static members: 1 */
	/* sum members: 140, holes: 1, sum holes: 1300 */
	/* last cacheline: 32 bytes */
};
class CTriggerRelay : public CBaseDelay {

	/* XXX 1148 bytes hole, try to pack */
public:


	/* class CBaseDelay          <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[1]; /*     0     0 */
private:

	/* --- cacheline 17 boundary (1088 bytes) was 60 bytes ago --- */
	USE_TYPE                   triggerType;          /*  1148     4 */
	void CTriggerRelay(class CTriggerRelay *, class CTriggerRelay &); /* linkage=_ZN13CTriggerRelayC4EOS_ */

	void CTriggerRelay(class CTriggerRelay *, const class CTriggerRelay  &); /* linkage=_ZN13CTriggerRelayC4ERKS_ */

	void CTriggerRelay(class CTriggerRelay *); /* linkage=_ZN13CTriggerRelayC4Ev */

	virtual void KeyValue(class CTriggerRelay *, KeyValueData *); /* linkage=_ZN13CTriggerRelay8KeyValueEP14KeyValueData_s */

	virtual void Spawn(class CTriggerRelay *); /* linkage=_ZN13CTriggerRelay5SpawnEv */

	virtual void Use(class CTriggerRelay *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN13CTriggerRelay3UseEP11CBaseEntityS1_8USE_TYPEf */

	virtual int ObjectCaps(class CTriggerRelay *); /* linkage=_ZN13CTriggerRelay10ObjectCapsEv */

	virtual int Save(class CTriggerRelay *, class CSave &); /* linkage=_ZN13CTriggerRelay4SaveER5CSave */

	virtual int Restore(class CTriggerRelay *, class CRestore &); /* linkage=_ZN13CTriggerRelay7RestoreER8CRestore */

	virtual void ~CTriggerRelay(class CTriggerRelay *, int); /* linkage=_ZN13CTriggerRelayD4Ev */

	/* vtable has 6 entries: {
	   [4] = KeyValue(_ZN13CTriggerRelay8KeyValueEP14KeyValueData_s), 
	   [2] = Spawn(_ZN13CTriggerRelay5SpawnEv), 
	   [45] = Use(_ZN13CTriggerRelay3UseEP11CBaseEntityS1_8USE_TYPEf), 
	   [7] = ObjectCaps(_ZN13CTriggerRelay10ObjectCapsEv), 
	   [5] = Save(_ZN13CTriggerRelay4SaveER5CSave), 
	   [6] = Restore(_ZN13CTriggerRelay7RestoreER8CRestore), 
	} */
	/* size: 1152, cachelines: 18, members: 2, static members: 1 */
	/* sum members: 4, holes: 1, sum holes: 1148 */
};
class CAutoTrigger : public CBaseDelay {

	/* XXX 1148 bytes hole, try to pack */
public:


	/* class CBaseDelay          <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[2]; /*     0     0 */
private:

	/* --- cacheline 17 boundary (1088 bytes) was 60 bytes ago --- */
	int                        m_globalstate;        /*  1148     4 */
	/* --- cacheline 18 boundary (1152 bytes) --- */
	USE_TYPE                   triggerType;          /*  1152     4 */
	void CAutoTrigger(class CAutoTrigger *, class CAutoTrigger &); /* linkage=_ZN12CAutoTriggerC4EOS_ */

	void CAutoTrigger(class CAutoTrigger *, const class CAutoTrigger  &); /* linkage=_ZN12CAutoTriggerC4ERKS_ */

	void CAutoTrigger(class CAutoTrigger *); /* linkage=_ZN12CAutoTriggerC4Ev */

	virtual void KeyValue(class CAutoTrigger *, KeyValueData *); /* linkage=_ZN12CAutoTrigger8KeyValueEP14KeyValueData_s */

	virtual void Spawn(class CAutoTrigger *); /* linkage=_ZN12CAutoTrigger5SpawnEv */

	virtual void Precache(class CAutoTrigger *); /* linkage=_ZN12CAutoTrigger8PrecacheEv */

	virtual void Think(class CAutoTrigger *); /* linkage=_ZN12CAutoTrigger5ThinkEv */

	virtual int ObjectCaps(class CAutoTrigger *); /* linkage=_ZN12CAutoTrigger10ObjectCapsEv */

	virtual int Save(class CAutoTrigger *, class CSave &); /* linkage=_ZN12CAutoTrigger4SaveER5CSave */

	virtual int Restore(class CAutoTrigger *, class CRestore &); /* linkage=_ZN12CAutoTrigger7RestoreER8CRestore */

	virtual void ~CAutoTrigger(class CAutoTrigger *, int); /* linkage=_ZN12CAutoTriggerD4Ev */

	/* vtable has 7 entries: {
	   [4] = KeyValue(_ZN12CAutoTrigger8KeyValueEP14KeyValueData_s), 
	   [2] = Spawn(_ZN12CAutoTrigger5SpawnEv), 
	   [3] = Precache(_ZN12CAutoTrigger8PrecacheEv), 
	   [43] = Think(_ZN12CAutoTrigger5ThinkEv), 
	   [7] = ObjectCaps(_ZN12CAutoTrigger10ObjectCapsEv), 
	   [5] = Save(_ZN12CAutoTrigger4SaveER5CSave), 
	   [6] = Restore(_ZN12CAutoTrigger7RestoreER8CRestore), 
	} */
	/* size: 1156, cachelines: 19, members: 3, static members: 1 */
	/* sum members: 8, holes: 1, sum holes: 1148 */
	/* last cacheline: 4 bytes */
};
class CFrictionModifier : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[1]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	float                      m_frictionFraction;   /*  1140     4 */
	void CFrictionModifier(class CFrictionModifier *, class CFrictionModifier &); /* linkage=_ZN17CFrictionModifierC4EOS_ */

	void CFrictionModifier(class CFrictionModifier *, const class CFrictionModifier  &); /* linkage=_ZN17CFrictionModifierC4ERKS_ */

	void CFrictionModifier(class CFrictionModifier *); /* linkage=_ZN17CFrictionModifierC4Ev */

	virtual void Spawn(class CFrictionModifier *); /* linkage=_ZN17CFrictionModifier5SpawnEv */

	virtual void KeyValue(class CFrictionModifier *, KeyValueData *); /* linkage=_ZN17CFrictionModifier8KeyValueEP14KeyValueData_s */

	void ChangeFriction(class CFrictionModifier *, class CBaseEntity *); /* linkage=_ZN17CFrictionModifier14ChangeFrictionEP11CBaseEntity */

	virtual int Save(class CFrictionModifier *, class CSave &); /* linkage=_ZN17CFrictionModifier4SaveER5CSave */

	virtual int Restore(class CFrictionModifier *, class CRestore &); /* linkage=_ZN17CFrictionModifier7RestoreER8CRestore */

	virtual int ObjectCaps(class CFrictionModifier *); /* linkage=_ZN17CFrictionModifier10ObjectCapsEv */

	virtual void ~CFrictionModifier(class CFrictionModifier *, int); /* linkage=_ZN17CFrictionModifierD4Ev */

	/* vtable has 5 entries: {
	   [2] = Spawn(_ZN17CFrictionModifier5SpawnEv), 
	   [4] = KeyValue(_ZN17CFrictionModifier8KeyValueEP14KeyValueData_s), 
	   [5] = Save(_ZN17CFrictionModifier4SaveER5CSave), 
	   [6] = Restore(_ZN17CFrictionModifier7RestoreER8CRestore), 
	   [7] = ObjectCaps(_ZN17CFrictionModifier10ObjectCapsEv), 
	} */
	/* size: 1144, cachelines: 18, members: 2, static members: 1 */
	/* sum members: 4, holes: 1, sum holes: 1140 */
	/* last cacheline: 56 bytes */
};
class CSentry : public CBaseTurret {
public:

	/* class CBaseTurret         <ancestor>; */      /*     0  1836 */

	/* XXX last struct has 1 hole */
	void CSentry(class CSentry *, class CSentry &); /* linkage=_ZN7CSentryC4EOS_ */

	void CSentry(class CSentry *, const class CSentry  &); /* linkage=_ZN7CSentryC4ERKS_ */

	void CSentry(class CSentry *); /* linkage=_ZN7CSentryC4Ev */

	virtual void Spawn(class CSentry *); /* linkage=_ZN7CSentry5SpawnEv */

	virtual void Precache(class CSentry *); /* linkage=_ZN7CSentry8PrecacheEv */

	virtual void Shoot(class CSentry *, class Vector &, class Vector &); /* linkage=_ZN7CSentry5ShootER6VectorS1_ */

	virtual int TakeDamage(class CSentry *, entvars_t *, entvars_t *, float, int); /* linkage=_ZN7CSentry10TakeDamageEP9entvars_sS1_fi */

	void SentryTouch(class CSentry *, class CBaseEntity *); /* linkage=_ZN7CSentry11SentryTouchEP11CBaseEntity */

	void SentryDeath(class CSentry *); /* linkage=_ZN7CSentry11SentryDeathEv */

	virtual void ~CSentry(class CSentry *, int); /* linkage=_ZN7CSentryD4Ev */

	/* vtable has 4 entries: {
	   [2] = Spawn(_ZN7CSentry5SpawnEv), 
	   [3] = Precache(_ZN7CSentry8PrecacheEv), 
	   [139] = Shoot(_ZN7CSentry5ShootER6VectorS1_), 
	   [13] = TakeDamage(_ZN7CSentry10TakeDamageEP9entvars_sS1_fi), 
	} */
	/* size: 1836, cachelines: 29, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 44 bytes */
};
class CBaseTurret : public CBaseMonster {

	/* XXX 1724 bytes hole, try to pack */
public:


	/* class CBaseMonster        <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[22]; /*     0     0 */
	/* --- cacheline 26 boundary (1664 bytes) was 60 bytes ago --- */
	float                      m_flMaxSpin;          /*  1724     4 */
	/* --- cacheline 27 boundary (1728 bytes) --- */
	int                        m_iSpin;              /*  1728     4 */
	class CSprite *            m_pEyeGlow;           /*  1732     4 */
	int                        m_eyeBrightness;      /*  1736     4 */
	int                        m_iDeployHeight;      /*  1740     4 */
	int                        m_iRetractHeight;     /*  1744     4 */
	int                        m_iMinPitch;          /*  1748     4 */
	int                        m_iBaseTurnRate;      /*  1752     4 */
	float                      m_fTurnRate;          /*  1756     4 */
	int                        m_iOrientation;       /*  1760     4 */
	int                        m_iOn;                /*  1764     4 */
	int                        m_fBeserk;            /*  1768     4 */
	int                        m_iAutoStart;         /*  1772     4 */
	class Vector              m_vecLastSight;        /*  1776    12 */
	float                      m_flLastSight;        /*  1788     4 */
	/* --- cacheline 28 boundary (1792 bytes) --- */
	float                      m_flMaxWait;          /*  1792     4 */
	int                        m_iSearchSpeed;       /*  1796     4 */
	float                      m_flStartYaw;         /*  1800     4 */
	class Vector              m_vecCurAngles;        /*  1804    12 */
	class Vector              m_vecGoalAngles;       /*  1816    12 */
	float                      m_flPingTime;         /*  1828     4 */
	float                      m_flSpinUpTime;       /*  1832     4 */
	void CBaseTurret(class CBaseTurret *, class CBaseTurret &); /* linkage=_ZN11CBaseTurretC4EOS_ */

	void CBaseTurret(class CBaseTurret *, const class CBaseTurret  &); /* linkage=_ZN11CBaseTurretC4ERKS_ */

	void CBaseTurret(class CBaseTurret *); /* linkage=_ZN11CBaseTurretC4Ev */

	virtual void Spawn(class CBaseTurret *); /* linkage=_ZN11CBaseTurret5SpawnEv */

	virtual void Precache(class CBaseTurret *); /* linkage=_ZN11CBaseTurret8PrecacheEv */

	virtual void KeyValue(class CBaseTurret *, KeyValueData *); /* linkage=_ZN11CBaseTurret8KeyValueEP14KeyValueData_s */

	void TurretUse(class CBaseTurret *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN11CBaseTurret9TurretUseEP11CBaseEntityS1_8USE_TYPEf */

	virtual void TraceAttack(class CBaseTurret *, entvars_t *, float, class Vector, class  *, int); /* linkage=_ZN11CBaseTurret11TraceAttackEP9entvars_sf6VectorP11TraceResulti */

	virtual int TakeDamage(class CBaseTurret *, entvars_t *, entvars_t *, float, int); /* linkage=_ZN11CBaseTurret10TakeDamageEP9entvars_sS1_fi */

	virtual int Classify(class CBaseTurret *); /* linkage=_ZN11CBaseTurret8ClassifyEv */

	virtual int BloodColor(class CBaseTurret *); /* linkage=_ZN11CBaseTurret10BloodColorEv */

	virtual void GibMonster(class CBaseTurret *); /* linkage=_ZN11CBaseTurret10GibMonsterEv */

	void ActiveThink(class CBaseTurret *); /* linkage=_ZN11CBaseTurret11ActiveThinkEv */

	void SearchThink(class CBaseTurret *); /* linkage=_ZN11CBaseTurret11SearchThinkEv */

	void AutoSearchThink(class CBaseTurret *); /* linkage=_ZN11CBaseTurret15AutoSearchThinkEv */

	void TurretDeath(class CBaseTurret *); /* linkage=_ZN11CBaseTurret11TurretDeathEv */

	virtual void SpinDownCall(class CBaseTurret *); /* linkage=_ZN11CBaseTurret12SpinDownCallEv */

	virtual void SpinUpCall(class CBaseTurret *); /* linkage=_ZN11CBaseTurret10SpinUpCallEv */

	void Deploy(class CBaseTurret *); /* linkage=_ZN11CBaseTurret6DeployEv */

	void Retire(class CBaseTurret *); /* linkage=_ZN11CBaseTurret6RetireEv */

	void Initialize(class CBaseTurret *); /* linkage=_ZN11CBaseTurret10InitializeEv */

	virtual void Ping(class CBaseTurret *); /* linkage=_ZN11CBaseTurret4PingEv */

	virtual void EyeOn(class CBaseTurret *); /* linkage=_ZN11CBaseTurret5EyeOnEv */

	virtual void EyeOff(class CBaseTurret *); /* linkage=_ZN11CBaseTurret6EyeOffEv */

	virtual int Save(class CBaseTurret *, class CSave &); /* linkage=_ZN11CBaseTurret4SaveER5CSave */

	virtual int Restore(class CBaseTurret *, class CRestore &); /* linkage=_ZN11CBaseTurret7RestoreER8CRestore */

	void SetTurretAnim(class CBaseTurret *, TURRET_ANIM); /* linkage=_ZN11CBaseTurret13SetTurretAnimE11TURRET_ANIM */

	int MoveTurret(class CBaseTurret *); /* linkage=_ZN11CBaseTurret10MoveTurretEv */

	virtual void Shoot(class CBaseTurret *, class Vector &, class Vector &); /* linkage=_ZN11CBaseTurret5ShootER6VectorS1_ */

	virtual void ~CBaseTurret(class CBaseTurret *, int); /* linkage=_ZN11CBaseTurretD4Ev */

	/* vtable has 16 entries: {
	   [2] = Spawn(_ZN11CBaseTurret5SpawnEv), 
	   [3] = Precache(_ZN11CBaseTurret8PrecacheEv), 
	   [4] = KeyValue(_ZN11CBaseTurret8KeyValueEP14KeyValueData_s), 
	   [12] = TraceAttack(_ZN11CBaseTurret11TraceAttackEP9entvars_sf6VectorP11TraceResulti), 
	   [13] = TakeDamage(_ZN11CBaseTurret10TakeDamageEP9entvars_sS1_fi), 
	   [10] = Classify(_ZN11CBaseTurret8ClassifyEv), 
	   [16] = BloodColor(_ZN11CBaseTurret10BloodColorEv), 
	   [123] = GibMonster(_ZN11CBaseTurret10GibMonsterEv), 
	   [134] = SpinDownCall(_ZN11CBaseTurret12SpinDownCallEv), 
	   [135] = SpinUpCall(_ZN11CBaseTurret10SpinUpCallEv), 
	   [136] = Ping(_ZN11CBaseTurret4PingEv), 
	   [137] = EyeOn(_ZN11CBaseTurret5EyeOnEv), 
	   [138] = EyeOff(_ZN11CBaseTurret6EyeOffEv), 
	   [5] = Save(_ZN11CBaseTurret4SaveER5CSave), 
	   [6] = Restore(_ZN11CBaseTurret7RestoreER8CRestore), 
	   [139] = Shoot(_ZN11CBaseTurret5ShootER6VectorS1_), 
	} */
	/* size: 1836, cachelines: 29, members: 23, static members: 1 */
	/* sum members: 112, holes: 1, sum holes: 1724 */
	/* last cacheline: 44 bytes */
};
class CMiniTurret : public CBaseTurret {
public:

	/* class CBaseTurret         <ancestor>; */      /*     0  1836 */

	/* XXX last struct has 1 hole */
	void CMiniTurret(class CMiniTurret *, class CMiniTurret &); /* linkage=_ZN11CMiniTurretC4EOS_ */

	void CMiniTurret(class CMiniTurret *, const class CMiniTurret  &); /* linkage=_ZN11CMiniTurretC4ERKS_ */

	void CMiniTurret(class CMiniTurret *); /* linkage=_ZN11CMiniTurretC4Ev */

	virtual void Spawn(class CMiniTurret *); /* linkage=_ZN11CMiniTurret5SpawnEv */

	virtual void Precache(class CMiniTurret *); /* linkage=_ZN11CMiniTurret8PrecacheEv */

	virtual void Shoot(class CMiniTurret *, class Vector &, class Vector &); /* linkage=_ZN11CMiniTurret5ShootER6VectorS1_ */

	virtual void ~CMiniTurret(class CMiniTurret *, int); /* linkage=_ZN11CMiniTurretD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN11CMiniTurret5SpawnEv), 
	   [3] = Precache(_ZN11CMiniTurret8PrecacheEv), 
	   [139] = Shoot(_ZN11CMiniTurret5ShootER6VectorS1_), 
	} */
	/* size: 1836, cachelines: 29, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 44 bytes */
};
class CTurret : public CBaseTurret {
public:

	/* class CBaseTurret         <ancestor>; */      /*     0  1836 */

	/* XXX last struct has 1 hole */

	static TYPEDESCRIPTION            m_SaveData[1]; /*     0     0 */
private:

	/* --- cacheline 28 boundary (1792 bytes) was 44 bytes ago --- */
	int                        m_iStartSpin;         /*  1836     4 */
	void CTurret(class CTurret *, class CTurret &); /* linkage=_ZN7CTurretC4EOS_ */

	void CTurret(class CTurret *, const class CTurret  &); /* linkage=_ZN7CTurretC4ERKS_ */

	void CTurret(class CTurret *); /* linkage=_ZN7CTurretC4Ev */

	virtual void Spawn(class CTurret *); /* linkage=_ZN7CTurret5SpawnEv */

	virtual void Precache(class CTurret *); /* linkage=_ZN7CTurret8PrecacheEv */

	virtual void SpinUpCall(class CTurret *); /* linkage=_ZN7CTurret10SpinUpCallEv */

	virtual void SpinDownCall(class CTurret *); /* linkage=_ZN7CTurret12SpinDownCallEv */

	virtual int Save(class CTurret *, class CSave &); /* linkage=_ZN7CTurret4SaveER5CSave */

	virtual int Restore(class CTurret *, class CRestore &); /* linkage=_ZN7CTurret7RestoreER8CRestore */

	virtual void Shoot(class CTurret *, class Vector &, class Vector &); /* linkage=_ZN7CTurret5ShootER6VectorS1_ */

	virtual void ~CTurret(class CTurret *, int); /* linkage=_ZN7CTurretD4Ev */

	/* vtable has 7 entries: {
	   [2] = Spawn(_ZN7CTurret5SpawnEv), 
	   [3] = Precache(_ZN7CTurret8PrecacheEv), 
	   [135] = SpinUpCall(_ZN7CTurret10SpinUpCallEv), 
	   [134] = SpinDownCall(_ZN7CTurret12SpinDownCallEv), 
	   [5] = Save(_ZN7CTurret4SaveER5CSave), 
	   [6] = Restore(_ZN7CTurret7RestoreER8CRestore), 
	   [139] = Shoot(_ZN7CTurret5ShootER6VectorS1_), 
	} */
	/* size: 1840, cachelines: 29, members: 2, static members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 48 bytes */
};
class UTIL_GroupTrace {
private:

	int                        m_oldgroupmask;       /*     0     4 */
	int                        m_oldgroupop;         /*     4     4 */
	void UTIL_GroupTrace(class UTIL_GroupTrace *, int, int); /* linkage=_ZN15UTIL_GroupTraceC4Eii */

	void ~UTIL_GroupTrace(class UTIL_GroupTrace *, int); /* linkage=_ZN15UTIL_GroupTraceD4Ev */


	/* size: 8, cachelines: 1, members: 2 */
	/* last cacheline: 8 bytes */
};
class CWeaponBox : public CBaseEntity {

	/* XXX 1140 bytes hole, try to pack */
public:


	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[4]; /*     0     0 */
	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	class CBasePlayerItem *    m_rgpPlayerItems[6];  /*  1140    24 */
	/* --- cacheline 18 boundary (1152 bytes) was 12 bytes ago --- */
	float                      m_flTouchableAt;      /*  1164     4 */
	float                      m_flCreationTime;     /*  1168     4 */
	int                        m_rgiszAmmo[32];      /*  1172   128 */
	/* --- cacheline 20 boundary (1280 bytes) was 20 bytes ago --- */
	int                        m_rgAmmo[32];         /*  1300   128 */
	/* --- cacheline 22 boundary (1408 bytes) was 20 bytes ago --- */
	int                        m_cAmmoTypes;         /*  1428     4 */
	void CWeaponBox(class CWeaponBox *, class CWeaponBox &); /* linkage=_ZN10CWeaponBoxC4EOS_ */

	void CWeaponBox(class CWeaponBox *, const class CWeaponBox  &); /* linkage=_ZN10CWeaponBoxC4ERKS_ */

	void CWeaponBox(class CWeaponBox *); /* linkage=_ZN10CWeaponBoxC4Ev */

private:

	virtual void Precache(class CWeaponBox *); /* linkage=_ZN10CWeaponBox8PrecacheEv */

	virtual void Touch(class CWeaponBox *, class CBaseEntity *); /* linkage=_ZN10CWeaponBox5TouchEP11CBaseEntity */

	virtual void KeyValue(class CWeaponBox *, KeyValueData *); /* linkage=_ZN10CWeaponBox8KeyValueEP14KeyValueData_s */

	BOOL IsEmpty(class CWeaponBox *); /* linkage=_ZN10CWeaponBox7IsEmptyEv */

	virtual int GiveAmmo(class CWeaponBox *, int, char *, int, int *); /* linkage=_ZN10CWeaponBox8GiveAmmoEiPciPi */

	virtual void SetObjectCollisionBox(class CWeaponBox *); /* linkage=_ZN10CWeaponBox21SetObjectCollisionBoxEv */

	virtual void Spawn(class CWeaponBox *); /* linkage=_ZN10CWeaponBox5SpawnEv */

	void Kill(class CWeaponBox *); /* linkage=_ZN10CWeaponBox4KillEv */

	virtual int Save(class CWeaponBox *, class CSave &); /* linkage=_ZN10CWeaponBox4SaveER5CSave */

	virtual int Restore(class CWeaponBox *, class CRestore &); /* linkage=_ZN10CWeaponBox7RestoreER8CRestore */

	BOOL HasWeapon(class CWeaponBox *, class CBasePlayerItem *); /* linkage=_ZN10CWeaponBox9HasWeaponEP15CBasePlayerItem */

	BOOL PackWeapon(class CWeaponBox *, class CBasePlayerItem *); /* linkage=_ZN10CWeaponBox10PackWeaponEP15CBasePlayerItem */

	BOOL PackAmmo(class CWeaponBox *, int, int); /* linkage=_ZN10CWeaponBox8PackAmmoEii */

	virtual void TeamFortress_TakeEMPBlast(class CWeaponBox *, entvars_t *); /* linkage=_ZN10CWeaponBox25TeamFortress_TakeEMPBlastEP9entvars_s */

	virtual void ~CWeaponBox(class CWeaponBox *, int); /* linkage=_ZN10CWeaponBoxD4Ev */

	/* vtable has 9 entries: {
	   [3] = Precache(_ZN10CWeaponBox8PrecacheEv), 
	   [44] = Touch(_ZN10CWeaponBox5TouchEP11CBaseEntity), 
	   [4] = KeyValue(_ZN10CWeaponBox8KeyValueEP14KeyValueData_s), 
	   [24] = GiveAmmo(_ZN10CWeaponBox8GiveAmmoEiPciPi), 
	   [9] = SetObjectCollisionBox(_ZN10CWeaponBox21SetObjectCollisionBoxEv), 
	   [2] = Spawn(_ZN10CWeaponBox5SpawnEv), 
	   [5] = Save(_ZN10CWeaponBox4SaveER5CSave), 
	   [6] = Restore(_ZN10CWeaponBox7RestoreER8CRestore), 
	   [61] = TeamFortress_TakeEMPBlast(_ZN10CWeaponBox25TeamFortress_TakeEMPBlastEP9entvars_s), 
	} */
	/* size: 1432, cachelines: 23, members: 7, static members: 1 */
	/* sum members: 292, holes: 1, sum holes: 1140 */
	/* last cacheline: 24 bytes */
};
class CBasePlayerItem : public CBaseAnimating {

	/* XXX 1168 bytes hole, try to pack */
public:


	/* class CBaseAnimating      <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[3]; /*     0     0 */
	static ItemInfo                   ItemInfoArray[32]; /*     0     0 */
	static AmmoInfo                   AmmoInfoArray[32]; /*     0     0 */
	/* --- cacheline 18 boundary (1152 bytes) was 16 bytes ago --- */
	class CBasePlayer *        m_pPlayer;            /*  1168     4 */
	class CBasePlayerItem *    m_pNext;              /*  1172     4 */
	int                        m_iId;                /*  1176     4 */
	void CBasePlayerItem(class CBasePlayerItem *, class CBasePlayerItem &); /* linkage=_ZN15CBasePlayerItemC4EOS_ */

	void CBasePlayerItem(class CBasePlayerItem *, const class CBasePlayerItem  &); /* linkage=_ZN15CBasePlayerItemC4ERKS_ */

	void CBasePlayerItem(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItemC4Ev */

	virtual void SetObjectCollisionBox(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem21SetObjectCollisionBoxEv */

	virtual int Save(class CBasePlayerItem *, class CSave &); /* linkage=_ZN15CBasePlayerItem4SaveER5CSave */

	virtual int Restore(class CBasePlayerItem *, class CRestore &); /* linkage=_ZN15CBasePlayerItem7RestoreER8CRestore */

	virtual int AddToPlayer(class CBasePlayerItem *, class CBasePlayer *); /* linkage=_ZN15CBasePlayerItem11AddToPlayerEP11CBasePlayer */

	virtual int AddDuplicate(class CBasePlayerItem *, class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem12AddDuplicateEPS_ */

	virtual int iItemSlot(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem9iItemSlotEv */

	void DestroyItem(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem11DestroyItemEv */

	void DefaultTouch(class CBasePlayerItem *, class CBaseEntity *); /* linkage=_ZN15CBasePlayerItem12DefaultTouchEP11CBaseEntity */

	void FallThink(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem9FallThinkEv */

	void Materialize(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem11MaterializeEv */

	void AttemptToMaterialize(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem20AttemptToMaterializeEv */

	virtual class CBaseEntity * Respawn(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem7RespawnEv */

	void FallInit(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem8FallInitEv */

	void CheckRespawn(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem12CheckRespawnEv */

	virtual int GetItemInfo(class CBasePlayerItem *, ItemInfo *); /* linkage=_ZN15CBasePlayerItem11GetItemInfoEP8ItemInfo */

	virtual BOOL CanDeploy(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem9CanDeployEv */

	virtual BOOL Deploy(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem6DeployEv */

	virtual BOOL CanHolster(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem10CanHolsterEv */

	virtual void Holster(class CBasePlayerItem *, int); /* linkage=_ZN15CBasePlayerItem7HolsterEi */

	virtual void UpdateItemInfo(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem14UpdateItemInfoEv */

	virtual void ItemPreFrame(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem12ItemPreFrameEv */

	virtual void ItemPostFrame(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem13ItemPostFrameEv */

	virtual void Drop(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem4DropEv */

	virtual void Kill(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem4KillEv */

	virtual void AttachToPlayer(class CBasePlayerItem *, class CBasePlayer *); /* linkage=_ZN15CBasePlayerItem14AttachToPlayerEP11CBasePlayer */

	virtual int PrimaryAmmoIndex(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem16PrimaryAmmoIndexEv */

	virtual int SecondaryAmmoIndex(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem18SecondaryAmmoIndexEv */

	virtual int UpdateClientData(class CBasePlayerItem *, class CBasePlayer *); /* linkage=_ZN15CBasePlayerItem16UpdateClientDataEP11CBasePlayer */

	virtual class CBasePlayerItem * GetWeaponPtr(class CBasePlayerItem *); /* linkage=_ZN15CBasePlayerItem12GetWeaponPtrEv */

	virtual void ~CBasePlayerItem(class CBasePlayerItem *, int); /* linkage=_ZN15CBasePlayerItemD4Ev */

	/* vtable has 22 entries: {
	   [9] = SetObjectCollisionBox(_ZN15CBasePlayerItem21SetObjectCollisionBoxEv), 
	   [5] = Save(_ZN15CBasePlayerItem4SaveER5CSave), 
	   [6] = Restore(_ZN15CBasePlayerItem7RestoreER8CRestore), 
	   [66] = AddToPlayer(_ZN15CBasePlayerItem11AddToPlayerEP11CBasePlayer), 
	   [67] = AddDuplicate(_ZN15CBasePlayerItem12AddDuplicateEPS_), 
	   [68] = iItemSlot(_ZN15CBasePlayerItem9iItemSlotEv), 
	   [47] = Respawn(_ZN15CBasePlayerItem7RespawnEv), 
	   [69] = GetItemInfo(_ZN15CBasePlayerItem11GetItemInfoEP8ItemInfo), 
	   [70] = CanDeploy(_ZN15CBasePlayerItem9CanDeployEv), 
	   [71] = Deploy(_ZN15CBasePlayerItem6DeployEv), 
	   [72] = CanHolster(_ZN15CBasePlayerItem10CanHolsterEv), 
	   [73] = Holster(_ZN15CBasePlayerItem7HolsterEi), 
	   [74] = UpdateItemInfo(_ZN15CBasePlayerItem14UpdateItemInfoEv), 
	   [75] = ItemPreFrame(_ZN15CBasePlayerItem12ItemPreFrameEv), 
	   [76] = ItemPostFrame(_ZN15CBasePlayerItem13ItemPostFrameEv), 
	   [77] = Drop(_ZN15CBasePlayerItem4DropEv), 
	   [78] = Kill(_ZN15CBasePlayerItem4KillEv), 
	   [79] = AttachToPlayer(_ZN15CBasePlayerItem14AttachToPlayerEP11CBasePlayer), 
	   [80] = PrimaryAmmoIndex(_ZN15CBasePlayerItem16PrimaryAmmoIndexEv), 
	   [81] = SecondaryAmmoIndex(_ZN15CBasePlayerItem18SecondaryAmmoIndexEv), 
	   [82] = UpdateClientData(_ZN15CBasePlayerItem16UpdateClientDataEP11CBasePlayer), 
	   [83] = GetWeaponPtr(_ZN15CBasePlayerItem12GetWeaponPtrEv), 
	} */
	/* size: 1180, cachelines: 19, members: 4, static members: 3 */
	/* sum members: 12, holes: 1, sum holes: 1168 */
	/* last cacheline: 28 bytes */
};
class CBasePlayerAmmo : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CBasePlayerAmmo(class CBasePlayerAmmo *); /* linkage=_ZN15CBasePlayerAmmoC4Ev */

	virtual void Spawn(class CBasePlayerAmmo *); /* linkage=_ZN15CBasePlayerAmmo5SpawnEv */

	void DefaultTouch(class CBasePlayerAmmo *, class CBaseEntity *); /* linkage=_ZN15CBasePlayerAmmo12DefaultTouchEP11CBaseEntity */

	virtual BOOL AddAmmo(class CBasePlayerAmmo *, class CBaseEntity *); /* linkage=_ZN15CBasePlayerAmmo7AddAmmoEP11CBaseEntity */

	virtual class CBaseEntity * Respawn(class CBasePlayerAmmo *); /* linkage=_ZN15CBasePlayerAmmo7RespawnEv */

	void Materialize(class CBasePlayerAmmo *); /* linkage=_ZN15CBasePlayerAmmo11MaterializeEv */

	virtual void ~CBasePlayerAmmo(class CBasePlayerAmmo *, int); /* linkage=_ZN15CBasePlayerAmmoD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN15CBasePlayerAmmo5SpawnEv), 
	   [65] = AddAmmo(_ZN15CBasePlayerAmmo7AddAmmoEP11CBaseEntity), 
	   [47] = Respawn(_ZN15CBasePlayerAmmo7RespawnEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CBasePlayerWeapon : public CBasePlayerItem {
public:

	/* class CBasePlayerItem     <ancestor>; */      /*     0  1180 */

	/* XXX last struct has 1 hole */

	static TYPEDESCRIPTION            m_SaveData[7]; /*     0     0 */
	/* --- cacheline 18 boundary (1152 bytes) was 28 bytes ago --- */
	int                        m_iPlayEmptySound;    /*  1180     4 */
	int                        m_fFireOnEmpty;       /*  1184     4 */
	float                      m_flNextPrimaryAttack; /*  1188     4 */
	float                      m_flNextSecondaryAttack; /*  1192     4 */
	float                      m_flTimeWeaponIdle;   /*  1196     4 */
	float                      m_flNextReload;       /*  1200     4 */
	float                      m_flPumpTime;         /*  1204     4 */
	float                      m_fReloadTime;        /*  1208     4 */
	float                      m_fAimedDamage;       /*  1212     4 */
	/* --- cacheline 19 boundary (1216 bytes) --- */
	float                      m_fNextAimBonus;      /*  1216     4 */
	int                        m_fInZoom;            /*  1220     4 */
	int                        m_iWeaponState;       /*  1224     4 */
	int                        m_fInReload;          /*  1228     4 */
	int                        m_fInSpecialReload;   /*  1232     4 */
	int                        m_iPrimaryAmmoType;   /*  1236     4 */
	int                        m_iSecondaryAmmoType; /*  1240     4 */
	int                        m_iClip;              /*  1244     4 */
	int                        m_iClientClip;        /*  1248     4 */
	int                        m_iClientWeaponState; /*  1252     4 */
	int                        m_iDefaultAmmo;       /*  1256     4 */
	float                      m_flPrevPrimaryAttack; /*  1260     4 */
	float                      m_flLastFireTime;     /*  1264     4 */
	void CBasePlayerWeapon(class CBasePlayerWeapon *, class CBasePlayerWeapon &); /* linkage=_ZN17CBasePlayerWeaponC4EOS_ */

	void CBasePlayerWeapon(class CBasePlayerWeapon *, const class CBasePlayerWeapon  &); /* linkage=_ZN17CBasePlayerWeaponC4ERKS_ */

	void CBasePlayerWeapon(class CBasePlayerWeapon *); /* linkage=_ZN17CBasePlayerWeaponC4Ev */

	virtual int Save(class CBasePlayerWeapon *, class CSave &); /* linkage=_ZN17CBasePlayerWeapon4SaveER5CSave */

	virtual int Restore(class CBasePlayerWeapon *, class CRestore &); /* linkage=_ZN17CBasePlayerWeapon7RestoreER8CRestore */

	virtual int AddToPlayer(class CBasePlayerWeapon *, class CBasePlayer *); /* linkage=_ZN17CBasePlayerWeapon11AddToPlayerEP11CBasePlayer */

	virtual int AddDuplicate(class CBasePlayerWeapon *, class CBasePlayerItem *); /* linkage=_ZN17CBasePlayerWeapon12AddDuplicateEP15CBasePlayerItem */

	virtual int ExtractAmmo(class CBasePlayerWeapon *, class CBasePlayerWeapon *); /* linkage=_ZN17CBasePlayerWeapon11ExtractAmmoEPS_ */

	virtual int ExtractClipAmmo(class CBasePlayerWeapon *, class CBasePlayerWeapon *); /* linkage=_ZN17CBasePlayerWeapon15ExtractClipAmmoEPS_ */

	virtual int AddWeapon(class CBasePlayerWeapon *); /* linkage=_ZN17CBasePlayerWeapon9AddWeaponEv */

	BOOL AddPrimaryAmmo(class CBasePlayerWeapon *, int, char *, int, int); /* linkage=_ZN17CBasePlayerWeapon14AddPrimaryAmmoEiPcii */

	BOOL AddSecondaryAmmo(class CBasePlayerWeapon *, int, char *, int); /* linkage=_ZN17CBasePlayerWeapon16AddSecondaryAmmoEiPci */

	virtual void UpdateItemInfo(class CBasePlayerWeapon *); /* linkage=_ZN17CBasePlayerWeapon14UpdateItemInfoEv */

	virtual BOOL PlayEmptySound(class CBasePlayerWeapon *); /* linkage=_ZN17CBasePlayerWeapon14PlayEmptySoundEv */

	virtual void ResetEmptySound(class CBasePlayerWeapon *); /* linkage=_ZN17CBasePlayerWeapon15ResetEmptySoundEv */

	virtual void SendWeaponAnim(class CBasePlayerWeapon *, int, int); /* linkage=_ZN17CBasePlayerWeapon14SendWeaponAnimEii */

	virtual BOOL CanDeploy(class CBasePlayerWeapon *); /* linkage=_ZN17CBasePlayerWeapon9CanDeployEv */

	virtual BOOL IsUseable(class CBasePlayerWeapon *); /* linkage=_ZN17CBasePlayerWeapon9IsUseableEv */

	BOOL DefaultDeploy(class CBasePlayerWeapon *, char *, char *, int, char *, int); /* linkage=_ZN17CBasePlayerWeapon13DefaultDeployEPcS0_iS0_i */

	BOOL DefaultReload(class CBasePlayerWeapon *, int, int, float); /* linkage=_ZN17CBasePlayerWeapon13DefaultReloadEiif */

	virtual void ItemPostFrame(class CBasePlayerWeapon *); /* linkage=_ZN17CBasePlayerWeapon13ItemPostFrameEv */

	void DB_LogShots(class CBasePlayerWeapon *, int32); /* linkage=_ZN17CBasePlayerWeapon11DB_LogShotsEi */

	virtual void PrimaryAttack(class CBasePlayerWeapon *); /* linkage=_ZN17CBasePlayerWeapon13PrimaryAttackEv */

	virtual void SecondaryAttack(class CBasePlayerWeapon *); /* linkage=_ZN17CBasePlayerWeapon15SecondaryAttackEv */

	virtual void Reload(class CBasePlayerWeapon *); /* linkage=_ZN17CBasePlayerWeapon6ReloadEv */

	virtual void WeaponIdle(class CBasePlayerWeapon *); /* linkage=_ZN17CBasePlayerWeapon10WeaponIdleEv */

	virtual int UpdateClientData(class CBasePlayerWeapon *, class CBasePlayer *); /* linkage=_ZN17CBasePlayerWeapon16UpdateClientDataEP11CBasePlayer */

	virtual void RetireWeapon(class CBasePlayerWeapon *); /* linkage=_ZN17CBasePlayerWeapon12RetireWeaponEv */

	virtual BOOL ShouldWeaponIdle(class CBasePlayerWeapon *); /* linkage=_ZN17CBasePlayerWeapon16ShouldWeaponIdleEv */

	virtual void Holster(class CBasePlayerWeapon *, int); /* linkage=_ZN17CBasePlayerWeapon7HolsterEi */

	virtual int PrimaryAmmoIndex(class CBasePlayerWeapon *); /* linkage=_ZN17CBasePlayerWeapon16PrimaryAmmoIndexEv */

	virtual int SecondaryAmmoIndex(class CBasePlayerWeapon *); /* linkage=_ZN17CBasePlayerWeapon18SecondaryAmmoIndexEv */

	virtual float GetNextAttackDelay(class CBasePlayerWeapon *, float); /* linkage=_ZN17CBasePlayerWeapon18GetNextAttackDelayEf */

	virtual class CBasePlayerItem * GetWeaponPtr(class CBasePlayerWeapon *); /* linkage=_ZN17CBasePlayerWeapon12GetWeaponPtrEv */

	virtual void ~CBasePlayerWeapon(class CBasePlayerWeapon *, int); /* linkage=_ZN17CBasePlayerWeaponD4Ev */

	/* vtable has 26 entries: {
	   [5] = Save(_ZN17CBasePlayerWeapon4SaveER5CSave), 
	   [6] = Restore(_ZN17CBasePlayerWeapon7RestoreER8CRestore), 
	   [66] = AddToPlayer(_ZN17CBasePlayerWeapon11AddToPlayerEP11CBasePlayer), 
	   [67] = AddDuplicate(_ZN17CBasePlayerWeapon12AddDuplicateEP15CBasePlayerItem), 
	   [84] = ExtractAmmo(_ZN17CBasePlayerWeapon11ExtractAmmoEPS_), 
	   [85] = ExtractClipAmmo(_ZN17CBasePlayerWeapon15ExtractClipAmmoEPS_), 
	   [86] = AddWeapon(_ZN17CBasePlayerWeapon9AddWeaponEv), 
	   [74] = UpdateItemInfo(_ZN17CBasePlayerWeapon14UpdateItemInfoEv), 
	   [87] = PlayEmptySound(_ZN17CBasePlayerWeapon14PlayEmptySoundEv), 
	   [88] = ResetEmptySound(_ZN17CBasePlayerWeapon15ResetEmptySoundEv), 
	   [89] = SendWeaponAnim(_ZN17CBasePlayerWeapon14SendWeaponAnimEii), 
	   [70] = CanDeploy(_ZN17CBasePlayerWeapon9CanDeployEv), 
	   [90] = IsUseable(_ZN17CBasePlayerWeapon9IsUseableEv), 
	   [76] = ItemPostFrame(_ZN17CBasePlayerWeapon13ItemPostFrameEv), 
	   [91] = PrimaryAttack(_ZN17CBasePlayerWeapon13PrimaryAttackEv), 
	   [92] = SecondaryAttack(_ZN17CBasePlayerWeapon15SecondaryAttackEv), 
	   [93] = Reload(_ZN17CBasePlayerWeapon6ReloadEv), 
	   [94] = WeaponIdle(_ZN17CBasePlayerWeapon10WeaponIdleEv), 
	   [82] = UpdateClientData(_ZN17CBasePlayerWeapon16UpdateClientDataEP11CBasePlayer), 
	   [95] = RetireWeapon(_ZN17CBasePlayerWeapon12RetireWeaponEv), 
	   [96] = ShouldWeaponIdle(_ZN17CBasePlayerWeapon16ShouldWeaponIdleEv), 
	   [73] = Holster(_ZN17CBasePlayerWeapon7HolsterEi), 
	   [80] = PrimaryAmmoIndex(_ZN17CBasePlayerWeapon16PrimaryAmmoIndexEv), 
	   [81] = SecondaryAmmoIndex(_ZN17CBasePlayerWeapon18SecondaryAmmoIndexEv), 
	   [97] = GetNextAttackDelay(_ZN17CBasePlayerWeapon18GetNextAttackDelayEf), 
	   [83] = GetWeaponPtr(_ZN17CBasePlayerWeapon12GetWeaponPtrEv), 
	} */
	/* size: 1268, cachelines: 20, members: 23, static members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 52 bytes */
};
class CGraph {
	enum NODEQUERY {
		NODEGRAPH_DYNAMIC = 0,
		NODEGRAPH_STATIC  = 1,
	};

	BOOL                       m_fGraphPresent;      /*     0     4 */
	BOOL                       m_fGraphPointersSet;  /*     4     4 */
	BOOL                       m_fRoutingComplete;   /*     8     4 */
	class CNode *              m_pNodes;             /*    12     4 */
	class CLink *              m_pLinkPool;          /*    16     4 */
	char *                     m_pRouteInfo;         /*    20     4 */
	int                        m_cNodes;             /*    24     4 */
	int                        m_cLinks;             /*    28     4 */
	int                        m_nRouteInfo;         /*    32     4 */
	DIST_INFO *                m_di;                 /*    36     4 */
	int                        m_RangeStart[3][256]; /*    40  3072 */
	/* --- cacheline 48 boundary (3072 bytes) was 40 bytes ago --- */
	int                        m_RangeEnd[3][256];   /*  3112  3072 */
	/* --- cacheline 96 boundary (6144 bytes) was 40 bytes ago --- */
	float                      m_flShortest;         /*  6184     4 */
	int                        m_iNearest;           /*  6188     4 */
	int                        m_minX;               /*  6192     4 */
	int                        m_minY;               /*  6196     4 */
	int                        m_minZ;               /*  6200     4 */
	int                        m_maxX;               /*  6204     4 */
	/* --- cacheline 97 boundary (6208 bytes) --- */
	int                        m_maxY;               /*  6208     4 */
	int                        m_maxZ;               /*  6212     4 */
	int                        m_minBoxX;            /*  6216     4 */
	int                        m_minBoxY;            /*  6220     4 */
	int                        m_minBoxZ;            /*  6224     4 */
	int                        m_maxBoxX;            /*  6228     4 */
	int                        m_maxBoxY;            /*  6232     4 */
	int                        m_maxBoxZ;            /*  6236     4 */
	int                        m_CheckedCounter;     /*  6240     4 */
	float                      m_RegionMin[3];       /*  6244    12 */
	float                      m_RegionMax[3];       /*  6256    12 */
	CACHE_ENTRY                m_Cache[128];         /*  6268  2048 */
	/* --- cacheline 129 boundary (8256 bytes) was 60 bytes ago --- */
	int                        m_HashPrimes[16];     /*  8316    64 */
	/* --- cacheline 130 boundary (8320 bytes) was 60 bytes ago --- */
	short int *                m_pHashLinks;         /*  8380     4 */
	/* --- cacheline 131 boundary (8384 bytes) --- */
	int                        m_nHashLinks;         /*  8384     4 */
	int                        m_iLastActiveIdleSearch; /*  8388     4 */
	int                        m_iLastCoverSearch;   /*  8392     4 */
	void CGraph(class CGraph *); /* linkage=_ZN6CGraphC4Ev */

	int LinkVisibleNodes(class CGraph *, class CLink *, FILE *, int *); /* linkage=_ZN6CGraph16LinkVisibleNodesEP5CLinkP8_IO_FILEPi */

	int RejectInlineLinks(class CGraph *, class CLink *, FILE *); /* linkage=_ZN6CGraph17RejectInlineLinksEP5CLinkP8_IO_FILE */

	int FindShortestPath(class CGraph *, int *, int, int, int, int); /* linkage=_ZN6CGraph16FindShortestPathEPiiiii */

	int FindNearestNode(class CGraph *, const class Vector  &, class CBaseEntity *); /* linkage=_ZN6CGraph15FindNearestNodeERK6VectorP11CBaseEntity */

	int FindNearestNode(class CGraph *, const class Vector  &, int); /* linkage=_ZN6CGraph15FindNearestNodeERK6Vectori */

	float PathLength(class CGraph *, int, int, int, int); /* linkage=_ZN6CGraph10PathLengthEiiii */

	int NextNodeInRoute(class CGraph *, int, int, int, int); /* linkage=_ZN6CGraph15NextNodeInRouteEiiii */

	int HandleLinkEnt(class CGraph *, int, entvars_t *, int, enum NODEQUERY); /* linkage=_ZN6CGraph13HandleLinkEntEiP9entvars_siNS_9NODEQUERYE */

	entvars_t * LinkEntForLink(class CGraph *, class CLink *, class CNode *); /* linkage=_ZN6CGraph14LinkEntForLinkEP5CLinkP5CNode */

	void ShowNodeConnections(class CGraph *, int); /* linkage=_ZN6CGraph19ShowNodeConnectionsEi */

	void InitGraph(class CGraph *); /* linkage=_ZN6CGraph9InitGraphEv */

	int AllocNodes(class CGraph *); /* linkage=_ZN6CGraph10AllocNodesEv */

	int CheckNODFile(class CGraph *, char *); /* linkage=_ZN6CGraph12CheckNODFileEPc */

	int FLoadGraph(class CGraph *, char *); /* linkage=_ZN6CGraph10FLoadGraphEPc */

	int FSaveGraph(class CGraph *, char *); /* linkage=_ZN6CGraph10FSaveGraphEPc */

	int FSetGraphPointers(class CGraph *); /* linkage=_ZN6CGraph17FSetGraphPointersEv */

	void CheckNode(class CGraph *, class Vector, int); /* linkage=_ZN6CGraph9CheckNodeE6Vectori */

	void BuildRegionTables(class CGraph *); /* linkage=_ZN6CGraph17BuildRegionTablesEv */

	void ComputeStaticRoutingTables(class CGraph *); /* linkage=_ZN6CGraph26ComputeStaticRoutingTablesEv */

	void TestRoutingTables(class CGraph *); /* linkage=_ZN6CGraph17TestRoutingTablesEv */

	void HashInsert(class CGraph *, int, int, int); /* linkage=_ZN6CGraph10HashInsertEiii */

	void HashSearch(class CGraph *, int, int, int &); /* linkage=_ZN6CGraph10HashSearchEiiRi */

	void HashChoosePrimes(class CGraph *, int); /* linkage=_ZN6CGraph16HashChoosePrimesEi */

	void BuildLinkLookups(class CGraph *); /* linkage=_ZN6CGraph16BuildLinkLookupsEv */

	void SortNodes(class CGraph *); /* linkage=_ZN6CGraph9SortNodesEv */

	int HullIndex(class CGraph *, const class CBaseEntity  *); /* linkage=_ZN6CGraph9HullIndexEPK11CBaseEntity */

	int NodeType(class CGraph *, const class CBaseEntity  *); /* linkage=_ZN6CGraph8NodeTypeEPK11CBaseEntity */

	int CapIndex(class CGraph *, int); /* linkage=_ZN6CGraph8CapIndexEi */

	class CNode & Node(class CGraph *, int); /* linkage=_ZN6CGraph4NodeEi */

	class CLink & Link(class CGraph *, int); /* linkage=_ZN6CGraph4LinkEi */

	class CLink & NodeLink(class CGraph *, int, int); /* linkage=_ZN6CGraph8NodeLinkEii */

	class CLink & NodeLink(class CGraph *, const class CNode  &, int); /* linkage=_ZN6CGraph8NodeLinkERK5CNodei */

	int INodeLink(class CGraph *, int, int); /* linkage=_ZN6CGraph9INodeLinkEii */


	/* size: 8396, cachelines: 132, members: 35 */
	/* last cacheline: 12 bytes */
};
class CWorld : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CWorld(class CWorld *, class CWorld &); /* linkage=_ZN6CWorldC4EOS_ */

	void CWorld(class CWorld *, const class CWorld  &); /* linkage=_ZN6CWorldC4ERKS_ */

	void CWorld(class CWorld *); /* linkage=_ZN6CWorldC4Ev */

	virtual void Spawn(class CWorld *); /* linkage=_ZN6CWorld5SpawnEv */

	virtual void Precache(class CWorld *); /* linkage=_ZN6CWorld8PrecacheEv */

	virtual void KeyValue(class CWorld *, KeyValueData *); /* linkage=_ZN6CWorld8KeyValueEP14KeyValueData_s */

	virtual void ~CWorld(class CWorld *, int); /* linkage=_ZN6CWorldD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN6CWorld5SpawnEv), 
	   [3] = Precache(_ZN6CWorld8PrecacheEv), 
	   [4] = KeyValue(_ZN6CWorld8KeyValueEP14KeyValueData_s), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CCorpse : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CCorpse(class CCorpse *, class CCorpse &); /* linkage=_ZN7CCorpseC4EOS_ */

	void CCorpse(class CCorpse *, const class CCorpse  &); /* linkage=_ZN7CCorpseC4ERKS_ */

	void CCorpse(class CCorpse *); /* linkage=_ZN7CCorpseC4Ev */

private:

	virtual int ObjectCaps(class CCorpse *); /* linkage=_ZN7CCorpse10ObjectCapsEv */

	virtual void ~CCorpse(class CCorpse *, int); /* linkage=_ZN7CCorpseD4Ev */

	/* vtable has 1 entries: {
	   [7] = ObjectCaps(_ZN7CCorpse10ObjectCapsEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CDecal : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CDecal(class CDecal *, class CDecal &); /* linkage=_ZN6CDecalC4EOS_ */

	void CDecal(class CDecal *, const class CDecal  &); /* linkage=_ZN6CDecalC4ERKS_ */

	void CDecal(class CDecal *); /* linkage=_ZN6CDecalC4Ev */

	virtual void Spawn(class CDecal *); /* linkage=_ZN6CDecal5SpawnEv */

	virtual void KeyValue(class CDecal *, KeyValueData *); /* linkage=_ZN6CDecal8KeyValueEP14KeyValueData_s */

	void StaticDecal(class CDecal *); /* linkage=_ZN6CDecal11StaticDecalEv */

	void TriggerDecal(class CDecal *, class CBaseEntity *, class CBaseEntity *, USE_TYPE, float); /* linkage=_ZN6CDecal12TriggerDecalEP11CBaseEntityS1_8USE_TYPEf */

	virtual void ~CDecal(class CDecal *, int); /* linkage=_ZN6CDecalD4Ev */

	/* vtable has 2 entries: {
	   [2] = Spawn(_ZN6CDecal5SpawnEv), 
	   [4] = KeyValue(_ZN6CDecal8KeyValueEP14KeyValueData_s), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CXenSpore : public CActAnimating {
public:

	/* class CActAnimating       <ancestor>; */      /*     0  1172 */

	/* XXX last struct has 1 hole */

	static const char  *              pModelNames[3]; /*     0     0 */
	void CXenSpore(class CXenSpore *, class CXenSpore &); /* linkage=_ZN9CXenSporeC4EOS_ */

	void CXenSpore(class CXenSpore *, const class CXenSpore  &); /* linkage=_ZN9CXenSporeC4ERKS_ */

	void CXenSpore(class CXenSpore *); /* linkage=_ZN9CXenSporeC4Ev */

	virtual void Spawn(class CXenSpore *); /* linkage=_ZN9CXenSpore5SpawnEv */

	virtual void Precache(class CXenSpore *); /* linkage=_ZN9CXenSpore8PrecacheEv */

	virtual void Touch(class CXenSpore *, class CBaseEntity *); /* linkage=_ZN9CXenSpore5TouchEP11CBaseEntity */

	virtual void Think(class CXenSpore *); /* linkage=_ZN9CXenSpore5ThinkEv */

	virtual int TakeDamage(class CXenSpore *, entvars_t *, entvars_t *, float, int); /* linkage=_ZN9CXenSpore10TakeDamageEP9entvars_sS1_fi */

	void Attack(class CXenSpore *); /* linkage=_ZN9CXenSpore6AttackEv */

	virtual void ~CXenSpore(class CXenSpore *, int); /* linkage=_ZN9CXenSporeD4Ev */

	/* vtable has 5 entries: {
	   [2] = Spawn(_ZN9CXenSpore5SpawnEv), 
	   [3] = Precache(_ZN9CXenSpore8PrecacheEv), 
	   [44] = Touch(_ZN9CXenSpore5TouchEP11CBaseEntity), 
	   [43] = Think(_ZN9CXenSpore5ThinkEv), 
	   [13] = TakeDamage(_ZN9CXenSpore10TakeDamageEP9entvars_sS1_fi), 
	} */
	/* size: 1172, cachelines: 19, members: 1, static members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 20 bytes */
};
class CActAnimating : public CBaseAnimating {

	/* XXX 1168 bytes hole, try to pack */
public:


	/* class CBaseAnimating      <ancestor>; */      /*     0     0 */
	static TYPEDESCRIPTION            m_SaveData[1]; /*     0     0 */
private:

	/* --- cacheline 18 boundary (1152 bytes) was 16 bytes ago --- */
	Activity                   m_Activity;           /*  1168     4 */
	void CActAnimating(class CActAnimating *, class CActAnimating &); /* linkage=_ZN13CActAnimatingC4EOS_ */

	void CActAnimating(class CActAnimating *, const class CActAnimating  &); /* linkage=_ZN13CActAnimatingC4ERKS_ */

	void CActAnimating(class CActAnimating *); /* linkage=_ZN13CActAnimatingC4Ev */

	void SetActivity(class CActAnimating *, Activity); /* linkage=_ZN13CActAnimating11SetActivityE8Activity */

	Activity GetActivity(class CActAnimating *); /* linkage=_ZN13CActAnimating11GetActivityEv */

	virtual int ObjectCaps(class CActAnimating *); /* linkage=_ZN13CActAnimating10ObjectCapsEv */

	virtual int Save(class CActAnimating *, class CSave &); /* linkage=_ZN13CActAnimating4SaveER5CSave */

	virtual int Restore(class CActAnimating *, class CRestore &); /* linkage=_ZN13CActAnimating7RestoreER8CRestore */

	virtual void ~CActAnimating(class CActAnimating *, int); /* linkage=_ZN13CActAnimatingD4Ev */

	/* vtable has 3 entries: {
	   [7] = ObjectCaps(_ZN13CActAnimating10ObjectCapsEv), 
	   [5] = Save(_ZN13CActAnimating4SaveER5CSave), 
	   [6] = Restore(_ZN13CActAnimating7RestoreER8CRestore), 
	} */
	/* size: 1172, cachelines: 19, members: 2, static members: 1 */
	/* sum members: 4, holes: 1, sum holes: 1168 */
	/* last cacheline: 20 bytes */
};
class CXenSporeLarge : public CXenSpore {
public:

	/* class CXenSpore           <ancestor>; */      /*     0  1172 */
private:

	static const class Vector        m_hullSizes[5]; /*     0     0 */
	void CXenSporeLarge(class CXenSporeLarge *, class CXenSporeLarge &); /* linkage=_ZN14CXenSporeLargeC4EOS_ */

	void CXenSporeLarge(class CXenSporeLarge *, const class CXenSporeLarge  &); /* linkage=_ZN14CXenSporeLargeC4ERKS_ */

	void CXenSporeLarge(class CXenSporeLarge *); /* linkage=_ZN14CXenSporeLargeC4Ev */

	virtual void Spawn(class CXenSporeLarge *); /* linkage=_ZN14CXenSporeLarge5SpawnEv */

	virtual void ~CXenSporeLarge(class CXenSporeLarge *, int); /* linkage=_ZN14CXenSporeLargeD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN14CXenSporeLarge5SpawnEv), 
	} */
	/* size: 1172, cachelines: 19, members: 1, static members: 1 */
	/* last cacheline: 20 bytes */
};
class CXenSporeMed : public CXenSpore {
public:

	/* class CXenSpore           <ancestor>; */      /*     0  1172 */
	void CXenSporeMed(class CXenSporeMed *, class CXenSporeMed &); /* linkage=_ZN12CXenSporeMedC4EOS_ */

	void CXenSporeMed(class CXenSporeMed *, const class CXenSporeMed  &); /* linkage=_ZN12CXenSporeMedC4ERKS_ */

	void CXenSporeMed(class CXenSporeMed *); /* linkage=_ZN12CXenSporeMedC4Ev */

private:

	virtual void Spawn(class CXenSporeMed *); /* linkage=_ZN12CXenSporeMed5SpawnEv */

	virtual void ~CXenSporeMed(class CXenSporeMed *, int); /* linkage=_ZN12CXenSporeMedD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN12CXenSporeMed5SpawnEv), 
	} */
	/* size: 1172, cachelines: 19, members: 1 */
	/* last cacheline: 20 bytes */
};
class CXenSporeSmall : public CXenSpore {
public:

	/* class CXenSpore           <ancestor>; */      /*     0  1172 */
	void CXenSporeSmall(class CXenSporeSmall *, class CXenSporeSmall &); /* linkage=_ZN14CXenSporeSmallC4EOS_ */

	void CXenSporeSmall(class CXenSporeSmall *, const class CXenSporeSmall  &); /* linkage=_ZN14CXenSporeSmallC4ERKS_ */

	void CXenSporeSmall(class CXenSporeSmall *); /* linkage=_ZN14CXenSporeSmallC4Ev */

private:

	virtual void Spawn(class CXenSporeSmall *); /* linkage=_ZN14CXenSporeSmall5SpawnEv */

	virtual void ~CXenSporeSmall(class CXenSporeSmall *, int); /* linkage=_ZN14CXenSporeSmallD4Ev */

	/* vtable has 1 entries: {
	   [2] = Spawn(_ZN14CXenSporeSmall5SpawnEv), 
	} */
	/* size: 1172, cachelines: 19, members: 1 */
	/* last cacheline: 20 bytes */
};
class CXenHull : public CPointEntity {
public:

	/* class CPointEntity        <ancestor>; */      /*     0     0 */
	void CXenHull(class CXenHull *, class CXenHull &); /* linkage=_ZN8CXenHullC4EOS_ */

	void CXenHull(class CXenHull *, const class CXenHull  &); /* linkage=_ZN8CXenHullC4ERKS_ */

	void CXenHull(class CXenHull *); /* linkage=_ZN8CXenHullC4Ev */

	class CXenHull * CreateHull(class CBaseEntity *, const class Vector  &, const class Vector  &, const class Vector  &); /* linkage=_ZN8CXenHull10CreateHullEP11CBaseEntityRK6VectorS4_S4_ */

	virtual int Classify(class CXenHull *); /* linkage=_ZN8CXenHull8ClassifyEv */

	virtual void ~CXenHull(class CXenHull *, int); /* linkage=_ZN8CXenHullD4Ev */

	/* vtable has 1 entries: {
	   [10] = Classify(_ZN8CXenHull8ClassifyEv), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CXenTree : public CActAnimating {
public:

	/* class CActAnimating       <ancestor>; */      /*     0  1172 */

	/* XXX last struct has 1 hole */

	static TYPEDESCRIPTION            m_SaveData[1]; /*     0     0 */
	static const char  *              pAttackHitSounds[3]; /*     0     0 */
	static const char  *              pAttackMissSounds[2]; /*     0     0 */
private:

	/* --- cacheline 18 boundary (1152 bytes) was 20 bytes ago --- */
	class CXenTreeTrigger *    m_pTrigger;           /*  1172     4 */
	void CXenTree(class CXenTree *, class CXenTree &); /* linkage=_ZN8CXenTreeC4EOS_ */

	void CXenTree(class CXenTree *, const class CXenTree  &); /* linkage=_ZN8CXenTreeC4ERKS_ */

	void CXenTree(class CXenTree *); /* linkage=_ZN8CXenTreeC4Ev */

	virtual void Spawn(class CXenTree *); /* linkage=_ZN8CXenTree5SpawnEv */

	virtual void Precache(class CXenTree *); /* linkage=_ZN8CXenTree8PrecacheEv */

	virtual void Touch(class CXenTree *, class CBaseEntity *); /* linkage=_ZN8CXenTree5TouchEP11CBaseEntity */

	virtual void Think(class CXenTree *); /* linkage=_ZN8CXenTree5ThinkEv */

	virtual int TakeDamage(class CXenTree *, entvars_t *, entvars_t *, float, int); /* linkage=_ZN8CXenTree10TakeDamageEP9entvars_sS1_fi */

	virtual void HandleAnimEvent(class CXenTree *, MonsterEvent_t *); /* linkage=_ZN8CXenTree15HandleAnimEventEP14MonsterEvent_t */

	void Attack(class CXenTree *); /* linkage=_ZN8CXenTree6AttackEv */

	virtual int Classify(class CXenTree *); /* linkage=_ZN8CXenTree8ClassifyEv */

	virtual int Save(class CXenTree *, class CSave &); /* linkage=_ZN8CXenTree4SaveER5CSave */

	virtual int Restore(class CXenTree *, class CRestore &); /* linkage=_ZN8CXenTree7RestoreER8CRestore */

	virtual void ~CXenTree(class CXenTree *, int); /* linkage=_ZN8CXenTreeD4Ev */

	/* vtable has 9 entries: {
	   [2] = Spawn(_ZN8CXenTree5SpawnEv), 
	   [3] = Precache(_ZN8CXenTree8PrecacheEv), 
	   [44] = Touch(_ZN8CXenTree5TouchEP11CBaseEntity), 
	   [43] = Think(_ZN8CXenTree5ThinkEv), 
	   [13] = TakeDamage(_ZN8CXenTree10TakeDamageEP9entvars_sS1_fi), 
	   [65] = HandleAnimEvent(_ZN8CXenTree15HandleAnimEventEP14MonsterEvent_t), 
	   [10] = Classify(_ZN8CXenTree8ClassifyEv), 
	   [5] = Save(_ZN8CXenTree4SaveER5CSave), 
	   [6] = Restore(_ZN8CXenTree7RestoreER8CRestore), 
	} */
	/* size: 1176, cachelines: 19, members: 2, static members: 3 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 24 bytes */
};
class CXenTreeTrigger : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0     0 */
	void CXenTreeTrigger(class CXenTreeTrigger *, class CXenTreeTrigger &); /* linkage=_ZN15CXenTreeTriggerC4EOS_ */

	void CXenTreeTrigger(class CXenTreeTrigger *, const class CXenTreeTrigger  &); /* linkage=_ZN15CXenTreeTriggerC4ERKS_ */

	void CXenTreeTrigger(class CXenTreeTrigger *); /* linkage=_ZN15CXenTreeTriggerC4Ev */

	virtual void Touch(class CXenTreeTrigger *, class CBaseEntity *); /* linkage=_ZN15CXenTreeTrigger5TouchEP11CBaseEntity */

	class CXenTreeTrigger * TriggerCreate(edict_t *, const class Vector  &); /* linkage=_ZN15CXenTreeTrigger13TriggerCreateEP7edict_sRK6Vector */

	virtual void ~CXenTreeTrigger(class CXenTreeTrigger *, int); /* linkage=_ZN15CXenTreeTriggerD4Ev */

	/* vtable has 1 entries: {
	   [44] = Touch(_ZN15CXenTreeTrigger5TouchEP11CBaseEntity), 
	} */
	/* size: 1140, cachelines: 18, members: 1 */
	/* padding: 1140 */
	/* last cacheline: 52 bytes */
};
class CXenHair : public CActAnimating {
public:

	/* class CActAnimating       <ancestor>; */      /*     0  1172 */

	/* XXX last struct has 1 hole */
	void CXenHair(class CXenHair *, class CXenHair &); /* linkage=_ZN8CXenHairC4EOS_ */

	void CXenHair(class CXenHair *, const class CXenHair  &); /* linkage=_ZN8CXenHairC4ERKS_ */

	void CXenHair(class CXenHair *); /* linkage=_ZN8CXenHairC4Ev */

	virtual void Spawn(class CXenHair *); /* linkage=_ZN8CXenHair5SpawnEv */

	virtual void Precache(class CXenHair *); /* linkage=_ZN8CXenHair8PrecacheEv */

	virtual void Think(class CXenHair *); /* linkage=_ZN8CXenHair5ThinkEv */

	virtual void ~CXenHair(class CXenHair *, int); /* linkage=_ZN8CXenHairD4Ev */

	/* vtable has 3 entries: {
	   [2] = Spawn(_ZN8CXenHair5SpawnEv), 
	   [3] = Precache(_ZN8CXenHair8PrecacheEv), 
	   [43] = Think(_ZN8CXenHair5ThinkEv), 
	} */
	/* size: 1172, cachelines: 19, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 20 bytes */
};
class CXenPLight : public CActAnimating {
public:

	/* class CActAnimating       <ancestor>; */      /*     0  1172 */

	/* XXX last struct has 1 hole */

	static TYPEDESCRIPTION            m_SaveData[1]; /*     0     0 */
private:

	/* --- cacheline 18 boundary (1152 bytes) was 20 bytes ago --- */
	class CSprite *            m_pGlow;              /*  1172     4 */
	void CXenPLight(class CXenPLight *, class CXenPLight &); /* linkage=_ZN10CXenPLightC4EOS_ */

	void CXenPLight(class CXenPLight *, const class CXenPLight  &); /* linkage=_ZN10CXenPLightC4ERKS_ */

	void CXenPLight(class CXenPLight *); /* linkage=_ZN10CXenPLightC4Ev */

	virtual void Spawn(class CXenPLight *); /* linkage=_ZN10CXenPLight5SpawnEv */

	virtual void Precache(class CXenPLight *); /* linkage=_ZN10CXenPLight8PrecacheEv */

	virtual void Touch(class CXenPLight *, class CBaseEntity *); /* linkage=_ZN10CXenPLight5TouchEP11CBaseEntity */

	virtual void Think(class CXenPLight *); /* linkage=_ZN10CXenPLight5ThinkEv */

	void LightOn(class CXenPLight *); /* linkage=_ZN10CXenPLight7LightOnEv */

	void LightOff(class CXenPLight *); /* linkage=_ZN10CXenPLight8LightOffEv */

	virtual int Save(class CXenPLight *, class CSave &); /* linkage=_ZN10CXenPLight4SaveER5CSave */

	virtual int Restore(class CXenPLight *, class CRestore &); /* linkage=_ZN10CXenPLight7RestoreER8CRestore */

	virtual void ~CXenPLight(class CXenPLight *, int); /* linkage=_ZN10CXenPLightD4Ev */

	/* vtable has 6 entries: {
	   [2] = Spawn(_ZN10CXenPLight5SpawnEv), 
	   [3] = Precache(_ZN10CXenPLight8PrecacheEv), 
	   [44] = Touch(_ZN10CXenPLight5TouchEP11CBaseEntity), 
	   [43] = Think(_ZN10CXenPLight5ThinkEv), 
	   [5] = Save(_ZN10CXenPLight4SaveER5CSave), 
	   [6] = Restore(_ZN10CXenPLight7RestoreER8CRestore), 
	} */
	/* size: 1176, cachelines: 19, members: 2, static members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 24 bytes */
};
class CTFTeleporter : public CBaseMonster {

	/* XXX 1724 bytes hole, try to pack */
public:


	/* class CBaseMonster        <ancestor>; */      /*     0     0 */
	/* --- cacheline 26 boundary (1664 bytes) was 60 bytes ago --- */
	class CBasePlayer *        m_pPlayer;            /*  1724     4 */
	/* --- cacheline 27 boundary (1728 bytes) --- */
	float                      m_flInitialUseDelay;  /*  1728     4 */
	int                        m_iType;              /*  1732     4 */
	int                        m_iState;             /*  1736     4 */
	int                        m_iDestroyed;         /*  1740     4 */
	int                        m_iShardIndex;        /*  1744     4 */
	float                      m_flMyNextThink;      /*  1748     4 */
	float                      m_flDamageDelay;      /*  1752     4 */
	void CTFTeleporter(class CTFTeleporter *, class CTFTeleporter &); /* linkage=_ZN13CTFTeleporterC4EOS_ */

	void CTFTeleporter(class CTFTeleporter *, const class CTFTeleporter  &); /* linkage=_ZN13CTFTeleporterC4ERKS_ */

	void CTFTeleporter(class CTFTeleporter *); /* linkage=_ZN13CTFTeleporterC4Ev */

	virtual void Spawn(class CTFTeleporter *); /* linkage=_ZN13CTFTeleporter5SpawnEv */

	virtual void Precache(class CTFTeleporter *); /* linkage=_ZN13CTFTeleporter8PrecacheEv */

	void Teleporter_Explode(class CTFTeleporter *); /* linkage=_ZN13CTFTeleporter18Teleporter_ExplodeEv */

	void TeleporterThink(class CTFTeleporter *); /* linkage=_ZN13CTFTeleporter15TeleporterThinkEv */

	void TeleporterTouch(class CTFTeleporter *, class CBaseEntity *); /* linkage=_ZN13CTFTeleporter15TeleporterTouchEP11CBaseEntity */

	virtual int Classify(class CTFTeleporter *); /* linkage=_ZN13CTFTeleporter8ClassifyEv */

	virtual int BloodColor(class CTFTeleporter *); /* linkage=_ZN13CTFTeleporter10BloodColorEv */

	void Remove(class CTFTeleporter *); /* linkage=_ZN13CTFTeleporter6RemoveEv */

	virtual void TeamFortress_TakeEMPBlast(class CTFTeleporter *, entvars_t *); /* linkage=_ZN13CTFTeleporter25TeamFortress_TakeEMPBlastEP9entvars_s */

	virtual void Finished(class CTFTeleporter *); /* linkage=_ZN13CTFTeleporter8FinishedEv */

	class CTFTeleporter * CreateTeleporter(class Vector, class Vector, class CBaseEntity *, int); /* linkage=_ZN13CTFTeleporter16CreateTeleporterE6VectorS0_P11CBaseEntityi */

	virtual BOOL EngineerUse(class CTFTeleporter *, class CBasePlayer *); /* linkage=_ZN13CTFTeleporter11EngineerUseEP11CBasePlayer */

	virtual void Killed(class CTFTeleporter *, entvars_t *, entvars_t *, int); /* linkage=_ZN13CTFTeleporter6KilledEP9entvars_sS1_i */

	void TeleporterSend(class CTFTeleporter *, class CBasePlayer *); /* linkage=_ZN13CTFTeleporter14TeleporterSendEP11CBasePlayer */

	void TeleporterReceive(class CTFTeleporter *, class CBasePlayer *, float); /* linkage=_ZN13CTFTeleporter17TeleporterReceiveEP11CBasePlayerf */

	void TeleporterKilled(class CTFTeleporter *); /* linkage=_ZN13CTFTeleporter16TeleporterKilledEv */

	BOOL TeleportersReady(class CTFTeleporter *); /* linkage=_ZN13CTFTeleporter16TeleportersReadyEv */

	void TeleporterFadePlayer(class CTFTeleporter *, int); /* linkage=_ZN13CTFTeleporter20TeleporterFadePlayerEi */

	void TeleporterProcessFade(class CTFTeleporter *); /* linkage=_ZN13CTFTeleporter21TeleporterProcessFadeEv */

	void SetTeleporterRings(class CTFTeleporter *, int); /* linkage=_ZN13CTFTeleporter18SetTeleporterRingsEi */

	void SetTeleporterParticles(class CTFTeleporter *, int); /* linkage=_ZN13CTFTeleporter22SetTeleporterParticlesEi */

	float GetDamageMultiplier(class CTFTeleporter *); /* linkage=_ZN13CTFTeleporter19GetDamageMultiplierEv */

	class CTFTeleporter * FindMatch(class CTFTeleporter *); /* linkage=_ZN13CTFTeleporter9FindMatchEv */

	const class Vector  & GetTeamColor(class CTFTeleporter *); /* linkage=_ZN13CTFTeleporter12GetTeamColorEv */

	bool PlayerIsStandingOnTeleporter(class CTFTeleporter *, class CBaseEntity *); /* linkage=_ZN13CTFTeleporter28PlayerIsStandingOnTeleporterEP11CBaseEntity */

	virtual void ~CTFTeleporter(class CTFTeleporter *, int); /* linkage=_ZN13CTFTeleporterD4Ev */

	/* vtable has 8 entries: {
	   [2] = Spawn(_ZN13CTFTeleporter5SpawnEv), 
	   [3] = Precache(_ZN13CTFTeleporter8PrecacheEv), 
	   [10] = Classify(_ZN13CTFTeleporter8ClassifyEv), 
	   [16] = BloodColor(_ZN13CTFTeleporter10BloodColorEv), 
	   [61] = TeamFortress_TakeEMPBlast(_ZN13CTFTeleporter25TeamFortress_TakeEMPBlastEP9entvars_s), 
	   [58] = Finished(_ZN13CTFTeleporter8FinishedEv), 
	   [57] = EngineerUse(_ZN13CTFTeleporter11EngineerUseEP11CBasePlayer), 
	   [15] = Killed(_ZN13CTFTeleporter6KilledEP9entvars_sS1_i), 
	} */
	/* size: 1756, cachelines: 28, members: 9 */
	/* sum members: 32, holes: 1, sum holes: 1724 */
	/* last cacheline: 28 bytes */
};
class CTFAssaultC : public CBasePlayerWeapon {

	/* XXX 1268 bytes hole, try to pack */
public:


	/* class CBasePlayerWeapon   <ancestor>; */      /*     0     0 */
	/* --- cacheline 19 boundary (1216 bytes) was 52 bytes ago --- */
	float                      m_flNextAnimTime;     /*  1268     4 */
	int                        m_iShell;             /*  1272     4 */
private:

	short unsigned int         m_usWindUp;           /*  1276     2 */
	short unsigned int         m_usWindDown;         /*  1278     2 */
	/* --- cacheline 20 boundary (1280 bytes) --- */
	short unsigned int         m_usFire;             /*  1280     2 */
	short unsigned int         m_usStartSpin;        /*  1282     2 */
	short unsigned int         m_usSpin;             /*  1284     2 */
	short unsigned int         m_usACStart;          /*  1286     2 */
	void CTFAssaultC(class CTFAssaultC *, class CTFAssaultC &); /* linkage=_ZN11CTFAssaultCC4EOS_ */

	void CTFAssaultC(class CTFAssaultC *, const class CTFAssaultC  &); /* linkage=_ZN11CTFAssaultCC4ERKS_ */

	void CTFAssaultC(class CTFAssaultC *); /* linkage=_ZN11CTFAssaultCC4Ev */

	virtual void Spawn(class CTFAssaultC *); /* linkage=_ZN11CTFAssaultC5SpawnEv */

	virtual void Precache(class CTFAssaultC *); /* linkage=_ZN11CTFAssaultC8PrecacheEv */

	virtual int iItemSlot(class CTFAssaultC *); /* linkage=_ZN11CTFAssaultC9iItemSlotEv */

	virtual int GetItemInfo(class CTFAssaultC *, ItemInfo *); /* linkage=_ZN11CTFAssaultC11GetItemInfoEP8ItemInfo */

	virtual int AddToPlayer(class CTFAssaultC *, class CBasePlayer *); /* linkage=_ZN11CTFAssaultC11AddToPlayerEP11CBasePlayer */

	void Fire(class CTFAssaultC *); /* linkage=_ZN11CTFAssaultC4FireEv */

	void Spin(class CTFAssaultC *); /* linkage=_ZN11CTFAssaultC4SpinEv */

	void StartSpin(class CTFAssaultC *); /* linkage=_ZN11CTFAssaultC9StartSpinEv */

	void WindUp(class CTFAssaultC *); /* linkage=_ZN11CTFAssaultC6WindUpEv */

	void WindDown(class CTFAssaultC *, bool); /* linkage=_ZN11CTFAssaultC8WindDownEb */

	virtual void PrimaryAttack(class CTFAssaultC *); /* linkage=_ZN11CTFAssaultC13PrimaryAttackEv */

	virtual BOOL Deploy(class CTFAssaultC *); /* linkage=_ZN11CTFAssaultC6DeployEv */

	virtual void Reload(class CTFAssaultC *); /* linkage=_ZN11CTFAssaultC6ReloadEv */

	virtual void WeaponIdle(class CTFAssaultC *); /* linkage=_ZN11CTFAssaultC10WeaponIdleEv */

	virtual void Holster(class CTFAssaultC *, int); /* linkage=_ZN11CTFAssaultC7HolsterEi */

	virtual BOOL ShouldWeaponIdle(class CTFAssaultC *); /* linkage=_ZN11CTFAssaultC16ShouldWeaponIdleEv */

	virtual void ~CTFAssaultC(class CTFAssaultC *, int); /* linkage=_ZN11CTFAssaultCD4Ev */

	/* vtable has 11 entries: {
	   [2] = Spawn(_ZN11CTFAssaultC5SpawnEv), 
	   [3] = Precache(_ZN11CTFAssaultC8PrecacheEv), 
	   [68] = iItemSlot(_ZN11CTFAssaultC9iItemSlotEv), 
	   [69] = GetItemInfo(_ZN11CTFAssaultC11GetItemInfoEP8ItemInfo), 
	   [66] = AddToPlayer(_ZN11CTFAssaultC11AddToPlayerEP11CBasePlayer), 
	   [91] = PrimaryAttack(_ZN11CTFAssaultC13PrimaryAttackEv), 
	   [71] = Deploy(_ZN11CTFAssaultC6DeployEv), 
	   [93] = Reload(_ZN11CTFAssaultC6ReloadEv), 
	   [94] = WeaponIdle(_ZN11CTFAssaultC10WeaponIdleEv), 
	   [73] = Holster(_ZN11CTFAssaultC7HolsterEi), 
	   [96] = ShouldWeaponIdle(_ZN11CTFAssaultC16ShouldWeaponIdleEv), 
	} */
	/* size: 1288, cachelines: 21, members: 9 */
	/* sum members: 20, holes: 1, sum holes: 1268 */
	/* last cacheline: 8 bytes */
};
class CTFAutoRifle : public CBasePlayerWeapon {

	/* XXX 1268 bytes hole, try to pack */
public:


	/* class CBasePlayerWeapon   <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 19 boundary (1216 bytes) was 52 bytes ago --- */
	short unsigned int         m_usFireAutoRifle;    /*  1268     2 */
	void CTFAutoRifle(class CTFAutoRifle *, class CTFAutoRifle &); /* linkage=_ZN12CTFAutoRifleC4EOS_ */

	void CTFAutoRifle(class CTFAutoRifle *, const class CTFAutoRifle  &); /* linkage=_ZN12CTFAutoRifleC4ERKS_ */

	void CTFAutoRifle(class CTFAutoRifle *); /* linkage=_ZN12CTFAutoRifleC4Ev */

	virtual void Spawn(class CTFAutoRifle *); /* linkage=_ZN12CTFAutoRifle5SpawnEv */

	virtual void Precache(class CTFAutoRifle *); /* linkage=_ZN12CTFAutoRifle8PrecacheEv */

	virtual int iItemSlot(class CTFAutoRifle *); /* linkage=_ZN12CTFAutoRifle9iItemSlotEv */

	virtual int GetItemInfo(class CTFAutoRifle *, ItemInfo *); /* linkage=_ZN12CTFAutoRifle11GetItemInfoEP8ItemInfo */

	virtual void PrimaryAttack(class CTFAutoRifle *); /* linkage=_ZN12CTFAutoRifle13PrimaryAttackEv */

	virtual int AddToPlayer(class CTFAutoRifle *, class CBasePlayer *); /* linkage=_ZN12CTFAutoRifle11AddToPlayerEP11CBasePlayer */

	virtual BOOL Deploy(class CTFAutoRifle *); /* linkage=_ZN12CTFAutoRifle6DeployEv */

	virtual void Holster(class CTFAutoRifle *, int); /* linkage=_ZN12CTFAutoRifle7HolsterEi */

	virtual void Reload(class CTFAutoRifle *); /* linkage=_ZN12CTFAutoRifle6ReloadEv */

	virtual void WeaponIdle(class CTFAutoRifle *); /* linkage=_ZN12CTFAutoRifle10WeaponIdleEv */

	virtual void ~CTFAutoRifle(class CTFAutoRifle *, int); /* linkage=_ZN12CTFAutoRifleD4Ev */

	/* vtable has 10 entries: {
	   [2] = Spawn(_ZN12CTFAutoRifle5SpawnEv), 
	   [3] = Precache(_ZN12CTFAutoRifle8PrecacheEv), 
	   [68] = iItemSlot(_ZN12CTFAutoRifle9iItemSlotEv), 
	   [69] = GetItemInfo(_ZN12CTFAutoRifle11GetItemInfoEP8ItemInfo), 
	   [91] = PrimaryAttack(_ZN12CTFAutoRifle13PrimaryAttackEv), 
	   [66] = AddToPlayer(_ZN12CTFAutoRifle11AddToPlayerEP11CBasePlayer), 
	   [71] = Deploy(_ZN12CTFAutoRifle6DeployEv), 
	   [73] = Holster(_ZN12CTFAutoRifle7HolsterEi), 
	   [93] = Reload(_ZN12CTFAutoRifle6ReloadEv), 
	   [94] = WeaponIdle(_ZN12CTFAutoRifle10WeaponIdleEv), 
	} */
	/* size: 1272, cachelines: 20, members: 2 */
	/* sum members: 2, holes: 1, sum holes: 1268 */
	/* padding: 2 */
	/* last cacheline: 56 bytes */
};
class CTFMedikit : public CTFAxe {
public:

	/* class CTFAxe              <ancestor>; */      /*     0  1400 */

	/* XXX last struct has 1 hole */

	/* --- cacheline 21 boundary (1344 bytes) was 56 bytes ago --- */
	short unsigned int         m_usNormalShot;       /*  1400     2 */
	short unsigned int         m_usSuperShot;        /*  1402     2 */
	short unsigned int         m_usSteamShot;        /*  1404     2 */
	void CTFMedikit(class CTFMedikit *, class CTFMedikit &); /* linkage=_ZN10CTFMedikitC4EOS_ */

	void CTFMedikit(class CTFMedikit *, const class CTFMedikit  &); /* linkage=_ZN10CTFMedikitC4ERKS_ */

	void CTFMedikit(class CTFMedikit *); /* linkage=_ZN10CTFMedikitC4Ev */

	virtual void Spawn(class CTFMedikit *); /* linkage=_ZN10CTFMedikit5SpawnEv */

	virtual void Precache(class CTFMedikit *); /* linkage=_ZN10CTFMedikit8PrecacheEv */

	virtual int GetItemInfo(class CTFMedikit *, ItemInfo *); /* linkage=_ZN10CTFMedikit11GetItemInfoEP8ItemInfo */

	virtual BOOL Deploy(class CTFMedikit *); /* linkage=_ZN10CTFMedikit6DeployEv */

	virtual void Holster(class CTFMedikit *, int); /* linkage=_ZN10CTFMedikit7HolsterEi */

	virtual void WeaponIdle(class CTFMedikit *); /* linkage=_ZN10CTFMedikit10WeaponIdleEv */

	virtual void PlayAnim(class CTFMedikit *, int); /* linkage=_ZN10CTFMedikit8PlayAnimEi */

	virtual void PlaySound(class CTFMedikit *, int, float); /* linkage=_ZN10CTFMedikit9PlaySoundEif */

	virtual void PlayDecal(class CTFMedikit *); /* linkage=_ZN10CTFMedikit9PlayDecalEv */

	virtual BOOL AxeHit(class CTFMedikit *, class CBaseEntity *, class Vector, class  *); /* linkage=_ZN10CTFMedikit6AxeHitEP11CBaseEntity6VectorP11TraceResult */

	virtual void ~CTFMedikit(class CTFMedikit *, int); /* linkage=_ZN10CTFMedikitD4Ev */

	/* vtable has 10 entries: {
	   [2] = Spawn(_ZN10CTFMedikit5SpawnEv), 
	   [3] = Precache(_ZN10CTFMedikit8PrecacheEv), 
	   [69] = GetItemInfo(_ZN10CTFMedikit11GetItemInfoEP8ItemInfo), 
	   [71] = Deploy(_ZN10CTFMedikit6DeployEv), 
	   [73] = Holster(_ZN10CTFMedikit7HolsterEi), 
	   [94] = WeaponIdle(_ZN10CTFMedikit10WeaponIdleEv), 
	   [99] = PlayAnim(_ZN10CTFMedikit8PlayAnimEi), 
	   [100] = PlaySound(_ZN10CTFMedikit9PlaySoundEif), 
	   [101] = PlayDecal(_ZN10CTFMedikit9PlayDecalEv), 
	   [98] = AxeHit(_ZN10CTFMedikit6AxeHitEP11CBaseEntity6VectorP11TraceResult), 
	} */
	/* size: 1408, cachelines: 22, members: 4 */
	/* padding: 2 */
	/* member types with holes: 1, total: 1 */
};
class CTFAxe : public CCrowbar {

	/* XXX 1328 bytes hole, try to pack */
public:


	/* class CCrowbar            <ancestor>; */      /*     0     0 */
	/* --- cacheline 20 boundary (1280 bytes) was 48 bytes ago --- */
	int                        m_iSwing;             /*  1328     4 */
	TraceResult                m_trHit;              /*  1332    56 */
	/* --- cacheline 21 boundary (1344 bytes) was 44 bytes ago --- */
	BOOL                       m_bHullHit;           /*  1388     4 */
	short unsigned int         m_usAxe;              /*  1392     2 */
	short unsigned int         m_usAxeDecal;         /*  1394     2 */
	int                        classid;              /*  1396     4 */
	void CTFAxe(class CTFAxe *, class CTFAxe &); /* linkage=_ZN6CTFAxeC4EOS_ */

	void CTFAxe(class CTFAxe *, const class CTFAxe  &); /* linkage=_ZN6CTFAxeC4ERKS_ */

	void CTFAxe(class CTFAxe *); /* linkage=_ZN6CTFAxeC4Ev */

	virtual void Spawn(class CTFAxe *); /* linkage=_ZN6CTFAxe5SpawnEv */

	virtual void Precache(class CTFAxe *); /* linkage=_ZN6CTFAxe8PrecacheEv */

	virtual int iItemSlot(class CTFAxe *); /* linkage=_ZN6CTFAxe9iItemSlotEv */

	void Smack(class CTFAxe *); /* linkage=_ZN6CTFAxe5SmackEv */

	virtual BOOL AxeHit(class CTFAxe *, class CBaseEntity *, class Vector, class  *); /* linkage=_ZN6CTFAxe6AxeHitEP11CBaseEntity6VectorP11TraceResult */

	virtual int GetItemInfo(class CTFAxe *, ItemInfo *); /* linkage=_ZN6CTFAxe11GetItemInfoEP8ItemInfo */

	virtual void PlayAnim(class CTFAxe *, int); /* linkage=_ZN6CTFAxe8PlayAnimEi */

	virtual void PlaySound(class CTFAxe *, int, float); /* linkage=_ZN6CTFAxe9PlaySoundEif */

	virtual void PlayDecal(class CTFAxe *); /* linkage=_ZN6CTFAxe9PlayDecalEv */

	virtual void PrimaryAttack(class CTFAxe *); /* linkage=_ZN6CTFAxe13PrimaryAttackEv */

	virtual BOOL Deploy(class CTFAxe *); /* linkage=_ZN6CTFAxe6DeployEv */

	virtual void Holster(class CTFAxe *, int); /* linkage=_ZN6CTFAxe7HolsterEi */

	virtual BOOL IsUseable(class CTFAxe *); /* linkage=_ZN6CTFAxe9IsUseableEv */

	virtual void ~CTFAxe(class CTFAxe *, int); /* linkage=_ZN6CTFAxeD4Ev */

	/* vtable has 12 entries: {
	   [2] = Spawn(_ZN6CTFAxe5SpawnEv), 
	   [3] = Precache(_ZN6CTFAxe8PrecacheEv), 
	   [68] = iItemSlot(_ZN6CTFAxe9iItemSlotEv), 
	   [98] = AxeHit(_ZN6CTFAxe6AxeHitEP11CBaseEntity6VectorP11TraceResult), 
	   [69] = GetItemInfo(_ZN6CTFAxe11GetItemInfoEP8ItemInfo), 
	   [99] = PlayAnim(_ZN6CTFAxe8PlayAnimEi), 
	   [100] = PlaySound(_ZN6CTFAxe9PlaySoundEif), 
	   [101] = PlayDecal(_ZN6CTFAxe9PlayDecalEv), 
	   [91] = PrimaryAttack(_ZN6CTFAxe13PrimaryAttackEv), 
	   [71] = Deploy(_ZN6CTFAxe6DeployEv), 
	   [73] = Holster(_ZN6CTFAxe7HolsterEi), 
	   [90] = IsUseable(_ZN6CTFAxe9IsUseableEv), 
	} */
	/* size: 1400, cachelines: 22, members: 7 */
	/* sum members: 72, holes: 1, sum holes: 1328 */
	/* last cacheline: 56 bytes */
};
class CTFKnife : public CTFAxe {
public:

	/* class CTFAxe              <ancestor>; */      /*     0  1400 */

	/* XXX last struct has 1 hole */
private:


	/* --- cacheline 21 boundary (1344 bytes) was 56 bytes ago --- */
	short unsigned int         m_usKnife;            /*  1400     2 */
	void CTFKnife(class CTFKnife *, class CTFKnife &); /* linkage=_ZN8CTFKnifeC4EOS_ */

	void CTFKnife(class CTFKnife *, const class CTFKnife  &); /* linkage=_ZN8CTFKnifeC4ERKS_ */

	void CTFKnife(class CTFKnife *); /* linkage=_ZN8CTFKnifeC4Ev */

	virtual void Spawn(class CTFKnife *); /* linkage=_ZN8CTFKnife5SpawnEv */

	virtual void Precache(class CTFKnife *); /* linkage=_ZN8CTFKnife8PrecacheEv */

	virtual int GetItemInfo(class CTFKnife *, ItemInfo *); /* linkage=_ZN8CTFKnife11GetItemInfoEP8ItemInfo */

	virtual BOOL Deploy(class CTFKnife *); /* linkage=_ZN8CTFKnife6DeployEv */

	virtual void Holster(class CTFKnife *, int); /* linkage=_ZN8CTFKnife7HolsterEi */

	virtual void WeaponIdle(class CTFKnife *); /* linkage=_ZN8CTFKnife10WeaponIdleEv */

	virtual void PlayAnim(class CTFKnife *, int); /* linkage=_ZN8CTFKnife8PlayAnimEi */

	virtual void ~CTFKnife(class CTFKnife *, int); /* linkage=_ZN8CTFKnifeD4Ev */

	/* vtable has 7 entries: {
	   [2] = Spawn(_ZN8CTFKnife5SpawnEv), 
	   [3] = Precache(_ZN8CTFKnife8PrecacheEv), 
	   [69] = GetItemInfo(_ZN8CTFKnife11GetItemInfoEP8ItemInfo), 
	   [71] = Deploy(_ZN8CTFKnife6DeployEv), 
	   [73] = Holster(_ZN8CTFKnife7HolsterEi), 
	   [94] = WeaponIdle(_ZN8CTFKnife10WeaponIdleEv), 
	   [99] = PlayAnim(_ZN8CTFKnife8PlayAnimEi), 
	} */
	/* size: 1404, cachelines: 22, members: 2 */
	/* padding: 2 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 60 bytes */
};
class CTFSpanner : public CTFAxe {
public:

	/* class CTFAxe              <ancestor>; */      /*     0  1400 */

	/* XXX last struct has 1 hole */
	void CTFSpanner(class CTFSpanner *, class CTFSpanner &); /* linkage=_ZN10CTFSpannerC4EOS_ */

	void CTFSpanner(class CTFSpanner *, const class CTFSpanner  &); /* linkage=_ZN10CTFSpannerC4ERKS_ */

	void CTFSpanner(class CTFSpanner *); /* linkage=_ZN10CTFSpannerC4Ev */

	virtual void Spawn(class CTFSpanner *); /* linkage=_ZN10CTFSpanner5SpawnEv */

	virtual void Precache(class CTFSpanner *); /* linkage=_ZN10CTFSpanner8PrecacheEv */

	virtual int GetItemInfo(class CTFSpanner *, ItemInfo *); /* linkage=_ZN10CTFSpanner11GetItemInfoEP8ItemInfo */

	virtual BOOL Deploy(class CTFSpanner *); /* linkage=_ZN10CTFSpanner6DeployEv */

	virtual void Holster(class CTFSpanner *, int); /* linkage=_ZN10CTFSpanner7HolsterEi */

	virtual void WeaponIdle(class CTFSpanner *); /* linkage=_ZN10CTFSpanner10WeaponIdleEv */

	virtual void PlayAnim(class CTFSpanner *, int); /* linkage=_ZN10CTFSpanner8PlayAnimEi */

	virtual BOOL AxeHit(class CTFSpanner *, class CBaseEntity *, class Vector, class  *); /* linkage=_ZN10CTFSpanner6AxeHitEP11CBaseEntity6VectorP11TraceResult */

	virtual void ~CTFSpanner(class CTFSpanner *, int); /* linkage=_ZN10CTFSpannerD4Ev */

	/* vtable has 8 entries: {
	   [2] = Spawn(_ZN10CTFSpanner5SpawnEv), 
	   [3] = Precache(_ZN10CTFSpanner8PrecacheEv), 
	   [69] = GetItemInfo(_ZN10CTFSpanner11GetItemInfoEP8ItemInfo), 
	   [71] = Deploy(_ZN10CTFSpanner6DeployEv), 
	   [73] = Holster(_ZN10CTFSpanner7HolsterEi), 
	   [94] = WeaponIdle(_ZN10CTFSpanner10WeaponIdleEv), 
	   [99] = PlayAnim(_ZN10CTFSpanner8PlayAnimEi), 
	   [98] = AxeHit(_ZN10CTFSpanner6AxeHitEP11CBaseEntity6VectorP11TraceResult), 
	} */
	/* size: 1400, cachelines: 22, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 56 bytes */
};
class CTFFlamethrower : public CBasePlayerWeapon {

	/* XXX 1268 bytes hole, try to pack */
public:


	/* class CBasePlayerWeapon   <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 19 boundary (1216 bytes) was 52 bytes ago --- */
	short unsigned int         m_usFireFlame;        /*  1268     2 */
	void CTFFlamethrower(class CTFFlamethrower *, class CTFFlamethrower &); /* linkage=_ZN15CTFFlamethrowerC4EOS_ */

	void CTFFlamethrower(class CTFFlamethrower *, const class CTFFlamethrower  &); /* linkage=_ZN15CTFFlamethrowerC4ERKS_ */

	void CTFFlamethrower(class CTFFlamethrower *); /* linkage=_ZN15CTFFlamethrowerC4Ev */

	virtual void Spawn(class CTFFlamethrower *); /* linkage=_ZN15CTFFlamethrower5SpawnEv */

	virtual void Precache(class CTFFlamethrower *); /* linkage=_ZN15CTFFlamethrower8PrecacheEv */

	virtual void Reload(class CTFFlamethrower *); /* linkage=_ZN15CTFFlamethrower6ReloadEv */

	virtual int iItemSlot(class CTFFlamethrower *); /* linkage=_ZN15CTFFlamethrower9iItemSlotEv */

	virtual int GetItemInfo(class CTFFlamethrower *, ItemInfo *); /* linkage=_ZN15CTFFlamethrower11GetItemInfoEP8ItemInfo */

	virtual int AddToPlayer(class CTFFlamethrower *, class CBasePlayer *); /* linkage=_ZN15CTFFlamethrower11AddToPlayerEP11CBasePlayer */

	virtual BOOL Deploy(class CTFFlamethrower *); /* linkage=_ZN15CTFFlamethrower6DeployEv */

	virtual BOOL CanHolster(class CTFFlamethrower *); /* linkage=_ZN15CTFFlamethrower10CanHolsterEv */

	virtual void Holster(class CTFFlamethrower *, int); /* linkage=_ZN15CTFFlamethrower7HolsterEi */

	virtual void PrimaryAttack(class CTFFlamethrower *); /* linkage=_ZN15CTFFlamethrower13PrimaryAttackEv */

	virtual void SecondaryAttack(class CTFFlamethrower *); /* linkage=_ZN15CTFFlamethrower15SecondaryAttackEv */

	virtual void WeaponIdle(class CTFFlamethrower *); /* linkage=_ZN15CTFFlamethrower10WeaponIdleEv */

	virtual void ~CTFFlamethrower(class CTFFlamethrower *, int); /* linkage=_ZN15CTFFlamethrowerD4Ev */

	/* vtable has 12 entries: {
	   [2] = Spawn(_ZN15CTFFlamethrower5SpawnEv), 
	   [3] = Precache(_ZN15CTFFlamethrower8PrecacheEv), 
	   [93] = Reload(_ZN15CTFFlamethrower6ReloadEv), 
	   [68] = iItemSlot(_ZN15CTFFlamethrower9iItemSlotEv), 
	   [69] = GetItemInfo(_ZN15CTFFlamethrower11GetItemInfoEP8ItemInfo), 
	   [66] = AddToPlayer(_ZN15CTFFlamethrower11AddToPlayerEP11CBasePlayer), 
	   [71] = Deploy(_ZN15CTFFlamethrower6DeployEv), 
	   [72] = CanHolster(_ZN15CTFFlamethrower10CanHolsterEv), 
	   [73] = Holster(_ZN15CTFFlamethrower7HolsterEi), 
	   [91] = PrimaryAttack(_ZN15CTFFlamethrower13PrimaryAttackEv), 
	   [92] = SecondaryAttack(_ZN15CTFFlamethrower15SecondaryAttackEv), 
	   [94] = WeaponIdle(_ZN15CTFFlamethrower10WeaponIdleEv), 
	} */
	/* size: 1272, cachelines: 20, members: 2 */
	/* sum members: 2, holes: 1, sum holes: 1268 */
	/* padding: 2 */
	/* last cacheline: 56 bytes */
};
class CTFPipebombLauncher : public CTFGrenadeLauncher {
public:

	/* class CTFGrenadeLauncher  <ancestor>; */      /*     0  1292 */

	/* XXX last struct has 2 bytes of padding, 1 hole */
	void CTFPipebombLauncher(class CTFPipebombLauncher *, class CTFPipebombLauncher &); /* linkage=_ZN19CTFPipebombLauncherC4EOS_ */

	void CTFPipebombLauncher(class CTFPipebombLauncher *, const class CTFPipebombLauncher  &); /* linkage=_ZN19CTFPipebombLauncherC4ERKS_ */

	void CTFPipebombLauncher(class CTFPipebombLauncher *); /* linkage=_ZN19CTFPipebombLauncherC4Ev */

	virtual void Spawn(class CTFPipebombLauncher *); /* linkage=_ZN19CTFPipebombLauncher5SpawnEv */

	virtual int iItemSlot(class CTFPipebombLauncher *); /* linkage=_ZN19CTFPipebombLauncher9iItemSlotEv */

	virtual void PrimaryAttack(class CTFPipebombLauncher *); /* linkage=_ZN19CTFPipebombLauncher13PrimaryAttackEv */

	virtual int GetItemInfo(class CTFPipebombLauncher *, ItemInfo *); /* linkage=_ZN19CTFPipebombLauncher11GetItemInfoEP8ItemInfo */

	virtual void ~CTFPipebombLauncher(class CTFPipebombLauncher *, int); /* linkage=_ZN19CTFPipebombLauncherD4Ev */

	/* vtable has 4 entries: {
	   [2] = Spawn(_ZN19CTFPipebombLauncher5SpawnEv), 
	   [68] = iItemSlot(_ZN19CTFPipebombLauncher9iItemSlotEv), 
	   [91] = PrimaryAttack(_ZN19CTFPipebombLauncher13PrimaryAttackEv), 
	   [69] = GetItemInfo(_ZN19CTFPipebombLauncher11GetItemInfoEP8ItemInfo), 
	} */
	/* size: 1292, cachelines: 21, members: 1 */
	/* member types with holes: 1, total: 1 */
	/* paddings: 1, sum paddings: 2 */
	/* last cacheline: 12 bytes */
};
class CTFGrenadeLauncher : public CBasePlayerWeapon {

	/* XXX 1268 bytes hole, try to pack */
public:


	/* class CBasePlayerWeapon   <ancestor>; */      /*     0     0 */
	/* --- cacheline 19 boundary (1216 bytes) was 52 bytes ago --- */
	int                        m_iAnim_Deploy;       /*  1268     4 */
	int                        m_iAnim_Holster;      /*  1272     4 */
	int                        m_iAnim_Idle;         /*  1276     4 */
	/* --- cacheline 20 boundary (1280 bytes) --- */
	int                        m_iAnim_ReloadDown;   /*  1280     4 */
	int                        m_iAnim_ReloadUp;     /*  1284     4 */
	short unsigned int         m_usFireGL;           /*  1288     2 */
	void CTFGrenadeLauncher(class CTFGrenadeLauncher *, class CTFGrenadeLauncher &); /* linkage=_ZN18CTFGrenadeLauncherC4EOS_ */

	void CTFGrenadeLauncher(class CTFGrenadeLauncher *, const class CTFGrenadeLauncher  &); /* linkage=_ZN18CTFGrenadeLauncherC4ERKS_ */

	void CTFGrenadeLauncher(class CTFGrenadeLauncher *); /* linkage=_ZN18CTFGrenadeLauncherC4Ev */

	virtual void Spawn(class CTFGrenadeLauncher *); /* linkage=_ZN18CTFGrenadeLauncher5SpawnEv */

	virtual void Precache(class CTFGrenadeLauncher *); /* linkage=_ZN18CTFGrenadeLauncher8PrecacheEv */

	virtual void Reload(class CTFGrenadeLauncher *); /* linkage=_ZN18CTFGrenadeLauncher6ReloadEv */

	virtual int iItemSlot(class CTFGrenadeLauncher *); /* linkage=_ZN18CTFGrenadeLauncher9iItemSlotEv */

	virtual int GetItemInfo(class CTFGrenadeLauncher *, ItemInfo *); /* linkage=_ZN18CTFGrenadeLauncher11GetItemInfoEP8ItemInfo */

	virtual int AddToPlayer(class CTFGrenadeLauncher *, class CBasePlayer *); /* linkage=_ZN18CTFGrenadeLauncher11AddToPlayerEP11CBasePlayer */

	virtual BOOL Deploy(class CTFGrenadeLauncher *); /* linkage=_ZN18CTFGrenadeLauncher6DeployEv */

	virtual void Holster(class CTFGrenadeLauncher *, int); /* linkage=_ZN18CTFGrenadeLauncher7HolsterEi */

	virtual void PrimaryAttack(class CTFGrenadeLauncher *); /* linkage=_ZN18CTFGrenadeLauncher13PrimaryAttackEv */

	virtual void SecondaryAttack(class CTFGrenadeLauncher *); /* linkage=_ZN18CTFGrenadeLauncher15SecondaryAttackEv */

	virtual void WeaponIdle(class CTFGrenadeLauncher *); /* linkage=_ZN18CTFGrenadeLauncher10WeaponIdleEv */

	virtual void ~CTFGrenadeLauncher(class CTFGrenadeLauncher *, int); /* linkage=_ZN18CTFGrenadeLauncherD4Ev */

	/* vtable has 11 entries: {
	   [2] = Spawn(_ZN18CTFGrenadeLauncher5SpawnEv), 
	   [3] = Precache(_ZN18CTFGrenadeLauncher8PrecacheEv), 
	   [93] = Reload(_ZN18CTFGrenadeLauncher6ReloadEv), 
	   [68] = iItemSlot(_ZN18CTFGrenadeLauncher9iItemSlotEv), 
	   [69] = GetItemInfo(_ZN18CTFGrenadeLauncher11GetItemInfoEP8ItemInfo), 
	   [66] = AddToPlayer(_ZN18CTFGrenadeLauncher11AddToPlayerEP11CBasePlayer), 
	   [71] = Deploy(_ZN18CTFGrenadeLauncher6DeployEv), 
	   [73] = Holster(_ZN18CTFGrenadeLauncher7HolsterEi), 
	   [91] = PrimaryAttack(_ZN18CTFGrenadeLauncher13PrimaryAttackEv), 
	   [92] = SecondaryAttack(_ZN18CTFGrenadeLauncher15SecondaryAttackEv), 
	   [94] = WeaponIdle(_ZN18CTFGrenadeLauncher10WeaponIdleEv), 
	} */
	/* size: 1292, cachelines: 21, members: 7 */
	/* sum members: 22, holes: 1, sum holes: 1268 */
	/* padding: 2 */
	/* last cacheline: 12 bytes */
};
class CTFIncendiaryC : public CBasePlayerWeapon {

	/* XXX 1268 bytes hole, try to pack */
public:


	/* class CBasePlayerWeapon   <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 19 boundary (1216 bytes) was 52 bytes ago --- */
	short unsigned int         m_usFireIC;           /*  1268     2 */
	void CTFIncendiaryC(class CTFIncendiaryC *, class CTFIncendiaryC &); /* linkage=_ZN14CTFIncendiaryCC4EOS_ */

	void CTFIncendiaryC(class CTFIncendiaryC *, const class CTFIncendiaryC  &); /* linkage=_ZN14CTFIncendiaryCC4ERKS_ */

	void CTFIncendiaryC(class CTFIncendiaryC *); /* linkage=_ZN14CTFIncendiaryCC4Ev */

	virtual void Spawn(class CTFIncendiaryC *); /* linkage=_ZN14CTFIncendiaryC5SpawnEv */

	virtual void Precache(class CTFIncendiaryC *); /* linkage=_ZN14CTFIncendiaryC8PrecacheEv */

	virtual void Reload(class CTFIncendiaryC *); /* linkage=_ZN14CTFIncendiaryC6ReloadEv */

	virtual int iItemSlot(class CTFIncendiaryC *); /* linkage=_ZN14CTFIncendiaryC9iItemSlotEv */

	virtual int GetItemInfo(class CTFIncendiaryC *, ItemInfo *); /* linkage=_ZN14CTFIncendiaryC11GetItemInfoEP8ItemInfo */

	virtual int AddToPlayer(class CTFIncendiaryC *, class CBasePlayer *); /* linkage=_ZN14CTFIncendiaryC11AddToPlayerEP11CBasePlayer */

	virtual BOOL Deploy(class CTFIncendiaryC *); /* linkage=_ZN14CTFIncendiaryC6DeployEv */

	virtual BOOL CanHolster(class CTFIncendiaryC *); /* linkage=_ZN14CTFIncendiaryC10CanHolsterEv */

	virtual void Holster(class CTFIncendiaryC *, int); /* linkage=_ZN14CTFIncendiaryC7HolsterEi */

	virtual void PrimaryAttack(class CTFIncendiaryC *); /* linkage=_ZN14CTFIncendiaryC13PrimaryAttackEv */

	virtual void SecondaryAttack(class CTFIncendiaryC *); /* linkage=_ZN14CTFIncendiaryC15SecondaryAttackEv */

	virtual void WeaponIdle(class CTFIncendiaryC *); /* linkage=_ZN14CTFIncendiaryC10WeaponIdleEv */

	virtual void ~CTFIncendiaryC(class CTFIncendiaryC *, int); /* linkage=_ZN14CTFIncendiaryCD4Ev */

	/* vtable has 12 entries: {
	   [2] = Spawn(_ZN14CTFIncendiaryC5SpawnEv), 
	   [3] = Precache(_ZN14CTFIncendiaryC8PrecacheEv), 
	   [93] = Reload(_ZN14CTFIncendiaryC6ReloadEv), 
	   [68] = iItemSlot(_ZN14CTFIncendiaryC9iItemSlotEv), 
	   [69] = GetItemInfo(_ZN14CTFIncendiaryC11GetItemInfoEP8ItemInfo), 
	   [66] = AddToPlayer(_ZN14CTFIncendiaryC11AddToPlayerEP11CBasePlayer), 
	   [71] = Deploy(_ZN14CTFIncendiaryC6DeployEv), 
	   [72] = CanHolster(_ZN14CTFIncendiaryC10CanHolsterEv), 
	   [73] = Holster(_ZN14CTFIncendiaryC7HolsterEi), 
	   [91] = PrimaryAttack(_ZN14CTFIncendiaryC13PrimaryAttackEv), 
	   [92] = SecondaryAttack(_ZN14CTFIncendiaryC15SecondaryAttackEv), 
	   [94] = WeaponIdle(_ZN14CTFIncendiaryC10WeaponIdleEv), 
	} */
	/* size: 1272, cachelines: 20, members: 2 */
	/* sum members: 2, holes: 1, sum holes: 1268 */
	/* padding: 2 */
	/* last cacheline: 56 bytes */
};
class CTFSuperNailgun : public CTFNailgun {
public:

	/* class CTFNailgun          <ancestor>; */      /*     0  1272 */

	/* XXX last struct has 2 bytes of padding, 1 hole */
private:


	/* --- cacheline 19 boundary (1216 bytes) was 54 bytes ago --- */
	short unsigned int         m_usFireSuperNailGun; /*  1270     2 */
	void CTFSuperNailgun(class CTFSuperNailgun *, class CTFSuperNailgun &); /* linkage=_ZN15CTFSuperNailgunC4EOS_ */

	void CTFSuperNailgun(class CTFSuperNailgun *, const class CTFSuperNailgun  &); /* linkage=_ZN15CTFSuperNailgunC4ERKS_ */

	void CTFSuperNailgun(class CTFSuperNailgun *); /* linkage=_ZN15CTFSuperNailgunC4Ev */

	virtual int iItemSlot(class CTFSuperNailgun *); /* linkage=_ZN15CTFSuperNailgun9iItemSlotEv */

	virtual int GetItemInfo(class CTFSuperNailgun *, ItemInfo *); /* linkage=_ZN15CTFSuperNailgun11GetItemInfoEP8ItemInfo */

	virtual void PrimaryAttack(class CTFSuperNailgun *); /* linkage=_ZN15CTFSuperNailgun13PrimaryAttackEv */

	virtual BOOL Deploy(class CTFSuperNailgun *); /* linkage=_ZN15CTFSuperNailgun6DeployEv */

	virtual void Precache(class CTFSuperNailgun *); /* linkage=_ZN15CTFSuperNailgun8PrecacheEv */

	virtual void ~CTFSuperNailgun(class CTFSuperNailgun *, int); /* linkage=_ZN15CTFSuperNailgunD4Ev */

	/* vtable has 5 entries: {
	   [68] = iItemSlot(_ZN15CTFSuperNailgun9iItemSlotEv), 
	   [69] = GetItemInfo(_ZN15CTFSuperNailgun11GetItemInfoEP8ItemInfo), 
	   [91] = PrimaryAttack(_ZN15CTFSuperNailgun13PrimaryAttackEv), 
	   [71] = Deploy(_ZN15CTFSuperNailgun6DeployEv), 
	   [3] = Precache(_ZN15CTFSuperNailgun8PrecacheEv), 
	} */
	/* size: 1272, cachelines: 20, members: 2 */
	/* member types with holes: 1, total: 1 */
	/* paddings: 1, sum paddings: 2 */
	/* last cacheline: 56 bytes */
};
class CTFNailgun : public CBasePlayerWeapon {

	/* XXX 1268 bytes hole, try to pack */
public:


	/* class CBasePlayerWeapon   <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 19 boundary (1216 bytes) was 52 bytes ago --- */
	short unsigned int         m_usFireNailGun;      /*  1268     2 */
	void CTFNailgun(class CTFNailgun *, class CTFNailgun &); /* linkage=_ZN10CTFNailgunC4EOS_ */

	void CTFNailgun(class CTFNailgun *, const class CTFNailgun  &); /* linkage=_ZN10CTFNailgunC4ERKS_ */

	void CTFNailgun(class CTFNailgun *); /* linkage=_ZN10CTFNailgunC4Ev */

	virtual void Spawn(class CTFNailgun *); /* linkage=_ZN10CTFNailgun5SpawnEv */

	virtual void Precache(class CTFNailgun *); /* linkage=_ZN10CTFNailgun8PrecacheEv */

	virtual void Reload(class CTFNailgun *); /* linkage=_ZN10CTFNailgun6ReloadEv */

	virtual int iItemSlot(class CTFNailgun *); /* linkage=_ZN10CTFNailgun9iItemSlotEv */

	virtual int GetItemInfo(class CTFNailgun *, ItemInfo *); /* linkage=_ZN10CTFNailgun11GetItemInfoEP8ItemInfo */

	virtual int AddToPlayer(class CTFNailgun *, class CBasePlayer *); /* linkage=_ZN10CTFNailgun11AddToPlayerEP11CBasePlayer */

	virtual BOOL Deploy(class CTFNailgun *); /* linkage=_ZN10CTFNailgun6DeployEv */

	virtual void PrimaryAttack(class CTFNailgun *); /* linkage=_ZN10CTFNailgun13PrimaryAttackEv */

	virtual void SecondaryAttack(class CTFNailgun *); /* linkage=_ZN10CTFNailgun15SecondaryAttackEv */

	virtual void WeaponIdle(class CTFNailgun *); /* linkage=_ZN10CTFNailgun10WeaponIdleEv */

	virtual void ~CTFNailgun(class CTFNailgun *, int); /* linkage=_ZN10CTFNailgunD4Ev */

	/* vtable has 10 entries: {
	   [2] = Spawn(_ZN10CTFNailgun5SpawnEv), 
	   [3] = Precache(_ZN10CTFNailgun8PrecacheEv), 
	   [93] = Reload(_ZN10CTFNailgun6ReloadEv), 
	   [68] = iItemSlot(_ZN10CTFNailgun9iItemSlotEv), 
	   [69] = GetItemInfo(_ZN10CTFNailgun11GetItemInfoEP8ItemInfo), 
	   [66] = AddToPlayer(_ZN10CTFNailgun11AddToPlayerEP11CBasePlayer), 
	   [71] = Deploy(_ZN10CTFNailgun6DeployEv), 
	   [91] = PrimaryAttack(_ZN10CTFNailgun13PrimaryAttackEv), 
	   [92] = SecondaryAttack(_ZN10CTFNailgun15SecondaryAttackEv), 
	   [94] = WeaponIdle(_ZN10CTFNailgun10WeaponIdleEv), 
	} */
	/* size: 1272, cachelines: 20, members: 2 */
	/* sum members: 2, holes: 1, sum holes: 1268 */
	/* padding: 2 */
	/* last cacheline: 56 bytes */
};
class CTFRailgun : public CBasePlayerWeapon {

	/* XXX 1268 bytes hole, try to pack */
public:


	/* class CBasePlayerWeapon   <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 19 boundary (1216 bytes) was 52 bytes ago --- */
	short unsigned int         m_usFireRail;         /*  1268     2 */
	void CTFRailgun(class CTFRailgun *, class CTFRailgun &); /* linkage=_ZN10CTFRailgunC4EOS_ */

	void CTFRailgun(class CTFRailgun *, const class CTFRailgun  &); /* linkage=_ZN10CTFRailgunC4ERKS_ */

	void CTFRailgun(class CTFRailgun *); /* linkage=_ZN10CTFRailgunC4Ev */

	virtual void Spawn(class CTFRailgun *); /* linkage=_ZN10CTFRailgun5SpawnEv */

	virtual void Precache(class CTFRailgun *); /* linkage=_ZN10CTFRailgun8PrecacheEv */

	virtual int iItemSlot(class CTFRailgun *); /* linkage=_ZN10CTFRailgun9iItemSlotEv */

	virtual int GetItemInfo(class CTFRailgun *, ItemInfo *); /* linkage=_ZN10CTFRailgun11GetItemInfoEP8ItemInfo */

	virtual void PrimaryAttack(class CTFRailgun *); /* linkage=_ZN10CTFRailgun13PrimaryAttackEv */

	virtual BOOL Deploy(class CTFRailgun *); /* linkage=_ZN10CTFRailgun6DeployEv */

	virtual void Reload(class CTFRailgun *); /* linkage=_ZN10CTFRailgun6ReloadEv */

	virtual void WeaponIdle(class CTFRailgun *); /* linkage=_ZN10CTFRailgun10WeaponIdleEv */

	virtual void ~CTFRailgun(class CTFRailgun *, int); /* linkage=_ZN10CTFRailgunD4Ev */

	/* vtable has 8 entries: {
	   [2] = Spawn(_ZN10CTFRailgun5SpawnEv), 
	   [3] = Precache(_ZN10CTFRailgun8PrecacheEv), 
	   [68] = iItemSlot(_ZN10CTFRailgun9iItemSlotEv), 
	   [69] = GetItemInfo(_ZN10CTFRailgun11GetItemInfoEP8ItemInfo), 
	   [91] = PrimaryAttack(_ZN10CTFRailgun13PrimaryAttackEv), 
	   [71] = Deploy(_ZN10CTFRailgun6DeployEv), 
	   [93] = Reload(_ZN10CTFRailgun6ReloadEv), 
	   [94] = WeaponIdle(_ZN10CTFRailgun10WeaponIdleEv), 
	} */
	/* size: 1272, cachelines: 20, members: 2 */
	/* sum members: 2, holes: 1, sum holes: 1268 */
	/* padding: 2 */
	/* last cacheline: 56 bytes */
};
class CTFRpg : public CBasePlayerWeapon {

	/* XXX 1268 bytes hole, try to pack */
public:


	/* class CBasePlayerWeapon   <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 19 boundary (1216 bytes) was 52 bytes ago --- */
	short unsigned int         m_usFireRPG;          /*  1268     2 */
	void CTFRpg(class CTFRpg *, class CTFRpg &); /* linkage=_ZN6CTFRpgC4EOS_ */

	void CTFRpg(class CTFRpg *, const class CTFRpg  &); /* linkage=_ZN6CTFRpgC4ERKS_ */

	void CTFRpg(class CTFRpg *); /* linkage=_ZN6CTFRpgC4Ev */

	virtual void Spawn(class CTFRpg *); /* linkage=_ZN6CTFRpg5SpawnEv */

	virtual void Precache(class CTFRpg *); /* linkage=_ZN6CTFRpg8PrecacheEv */

	virtual void Reload(class CTFRpg *); /* linkage=_ZN6CTFRpg6ReloadEv */

	virtual int iItemSlot(class CTFRpg *); /* linkage=_ZN6CTFRpg9iItemSlotEv */

	virtual int GetItemInfo(class CTFRpg *, ItemInfo *); /* linkage=_ZN6CTFRpg11GetItemInfoEP8ItemInfo */

	virtual int AddToPlayer(class CTFRpg *, class CBasePlayer *); /* linkage=_ZN6CTFRpg11AddToPlayerEP11CBasePlayer */

	virtual BOOL Deploy(class CTFRpg *); /* linkage=_ZN6CTFRpg6DeployEv */

	virtual BOOL CanHolster(class CTFRpg *); /* linkage=_ZN6CTFRpg10CanHolsterEv */

	virtual void Holster(class CTFRpg *, int); /* linkage=_ZN6CTFRpg7HolsterEi */

	virtual void PrimaryAttack(class CTFRpg *); /* linkage=_ZN6CTFRpg13PrimaryAttackEv */

	virtual void SecondaryAttack(class CTFRpg *); /* linkage=_ZN6CTFRpg15SecondaryAttackEv */

	virtual void WeaponIdle(class CTFRpg *); /* linkage=_ZN6CTFRpg10WeaponIdleEv */

	virtual void ~CTFRpg(class CTFRpg *, int); /* linkage=_ZN6CTFRpgD4Ev */

	/* vtable has 12 entries: {
	   [2] = Spawn(_ZN6CTFRpg5SpawnEv), 
	   [3] = Precache(_ZN6CTFRpg8PrecacheEv), 
	   [93] = Reload(_ZN6CTFRpg6ReloadEv), 
	   [68] = iItemSlot(_ZN6CTFRpg9iItemSlotEv), 
	   [69] = GetItemInfo(_ZN6CTFRpg11GetItemInfoEP8ItemInfo), 
	   [66] = AddToPlayer(_ZN6CTFRpg11AddToPlayerEP11CBasePlayer), 
	   [71] = Deploy(_ZN6CTFRpg6DeployEv), 
	   [72] = CanHolster(_ZN6CTFRpg10CanHolsterEv), 
	   [73] = Holster(_ZN6CTFRpg7HolsterEi), 
	   [91] = PrimaryAttack(_ZN6CTFRpg13PrimaryAttackEv), 
	   [92] = SecondaryAttack(_ZN6CTFRpg15SecondaryAttackEv), 
	   [94] = WeaponIdle(_ZN6CTFRpg10WeaponIdleEv), 
	} */
	/* size: 1272, cachelines: 20, members: 2 */
	/* sum members: 2, holes: 1, sum holes: 1268 */
	/* padding: 2 */
	/* last cacheline: 56 bytes */
};
class CTFSuperShotgun : public CTFShotgun {
public:

	/* class CTFShotgun          <ancestor>; */      /*     0  1288 */

	/* XXX last struct has 2 bytes of padding, 1 hole */
private:


	/* --- cacheline 20 boundary (1280 bytes) was 6 bytes ago --- */
	short unsigned int         m_usFireSuperShotgun; /*  1286     2 */
	void CTFSuperShotgun(class CTFSuperShotgun *, class CTFSuperShotgun &); /* linkage=_ZN15CTFSuperShotgunC4EOS_ */

	void CTFSuperShotgun(class CTFSuperShotgun *, const class CTFSuperShotgun  &); /* linkage=_ZN15CTFSuperShotgunC4ERKS_ */

	void CTFSuperShotgun(class CTFSuperShotgun *); /* linkage=_ZN15CTFSuperShotgunC4Ev */

	virtual void Spawn(class CTFSuperShotgun *); /* linkage=_ZN15CTFSuperShotgun5SpawnEv */

	virtual void Precache(class CTFSuperShotgun *); /* linkage=_ZN15CTFSuperShotgun8PrecacheEv */

	virtual void PrimaryAttack(class CTFSuperShotgun *); /* linkage=_ZN15CTFSuperShotgun13PrimaryAttackEv */

	virtual int GetItemInfo(class CTFSuperShotgun *, ItemInfo *); /* linkage=_ZN15CTFSuperShotgun11GetItemInfoEP8ItemInfo */

	virtual BOOL Deploy(class CTFSuperShotgun *); /* linkage=_ZN15CTFSuperShotgun6DeployEv */

	virtual void ~CTFSuperShotgun(class CTFSuperShotgun *, int); /* linkage=_ZN15CTFSuperShotgunD4Ev */

	/* vtable has 5 entries: {
	   [2] = Spawn(_ZN15CTFSuperShotgun5SpawnEv), 
	   [3] = Precache(_ZN15CTFSuperShotgun8PrecacheEv), 
	   [91] = PrimaryAttack(_ZN15CTFSuperShotgun13PrimaryAttackEv), 
	   [69] = GetItemInfo(_ZN15CTFSuperShotgun11GetItemInfoEP8ItemInfo), 
	   [71] = Deploy(_ZN15CTFSuperShotgun6DeployEv), 
	} */
	/* size: 1288, cachelines: 21, members: 2 */
	/* member types with holes: 1, total: 1 */
	/* paddings: 1, sum paddings: 2 */
	/* last cacheline: 8 bytes */
};
class CTFShotgun : public CBasePlayerWeapon {

	/* XXX 1268 bytes hole, try to pack */
public:


	/* class CBasePlayerWeapon   <ancestor>; */      /*     0     0 */
	/* --- cacheline 19 boundary (1216 bytes) was 52 bytes ago --- */
	int                        m_iShell;             /*  1268     4 */
	int                        m_iShellsReloaded;    /*  1272     4 */
	int                        m_iMaxClipSize;       /*  1276     4 */
	/* --- cacheline 20 boundary (1280 bytes) --- */
	short unsigned int         m_usReloadShotgun;    /*  1280     2 */
	short unsigned int         m_usPumpShotgun;      /*  1282     2 */
private:

	short unsigned int         m_usFireShotgun;      /*  1284     2 */
	void CTFShotgun(class CTFShotgun *, class CTFShotgun &); /* linkage=_ZN10CTFShotgunC4EOS_ */

	void CTFShotgun(class CTFShotgun *, const class CTFShotgun  &); /* linkage=_ZN10CTFShotgunC4ERKS_ */

	void CTFShotgun(class CTFShotgun *); /* linkage=_ZN10CTFShotgunC4Ev */

	virtual void Spawn(class CTFShotgun *); /* linkage=_ZN10CTFShotgun5SpawnEv */

	virtual void Precache(class CTFShotgun *); /* linkage=_ZN10CTFShotgun8PrecacheEv */

	virtual int GetItemInfo(class CTFShotgun *, ItemInfo *); /* linkage=_ZN10CTFShotgun11GetItemInfoEP8ItemInfo */

	virtual int AddToPlayer(class CTFShotgun *, class CBasePlayer *); /* linkage=_ZN10CTFShotgun11AddToPlayerEP11CBasePlayer */

	virtual void PrimaryAttack(class CTFShotgun *); /* linkage=_ZN10CTFShotgun13PrimaryAttackEv */

	virtual void SecondaryAttack(class CTFShotgun *); /* linkage=_ZN10CTFShotgun15SecondaryAttackEv */

	virtual BOOL Deploy(class CTFShotgun *); /* linkage=_ZN10CTFShotgun6DeployEv */

	virtual void Reload(class CTFShotgun *); /* linkage=_ZN10CTFShotgun6ReloadEv */

	virtual void WeaponIdle(class CTFShotgun *); /* linkage=_ZN10CTFShotgun10WeaponIdleEv */

	virtual void ItemPostFrame(class CTFShotgun *); /* linkage=_ZN10CTFShotgun13ItemPostFrameEv */

	virtual void ~CTFShotgun(class CTFShotgun *, int); /* linkage=_ZN10CTFShotgunD4Ev */

	/* vtable has 10 entries: {
	   [2] = Spawn(_ZN10CTFShotgun5SpawnEv), 
	   [3] = Precache(_ZN10CTFShotgun8PrecacheEv), 
	   [69] = GetItemInfo(_ZN10CTFShotgun11GetItemInfoEP8ItemInfo), 
	   [66] = AddToPlayer(_ZN10CTFShotgun11AddToPlayerEP11CBasePlayer), 
	   [91] = PrimaryAttack(_ZN10CTFShotgun13PrimaryAttackEv), 
	   [92] = SecondaryAttack(_ZN10CTFShotgun15SecondaryAttackEv), 
	   [71] = Deploy(_ZN10CTFShotgun6DeployEv), 
	   [93] = Reload(_ZN10CTFShotgun6ReloadEv), 
	   [94] = WeaponIdle(_ZN10CTFShotgun10WeaponIdleEv), 
	   [76] = ItemPostFrame(_ZN10CTFShotgun13ItemPostFrameEv), 
	} */
	/* size: 1288, cachelines: 21, members: 7 */
	/* sum members: 18, holes: 1, sum holes: 1268 */
	/* padding: 2 */
	/* last cacheline: 8 bytes */
};
class CTFSniperRifle : public CBasePlayerWeapon {

	/* XXX 1268 bytes hole, try to pack */
public:


	/* class CBasePlayerWeapon   <ancestor>; */      /*     0     0 */
	/* --- cacheline 19 boundary (1216 bytes) was 52 bytes ago --- */
	class CLaserSpot *         m_pSpot;              /*  1268     4 */
	int                        m_iSpotActive;        /*  1272     4 */
private:

	short unsigned int         m_usFireSniper;       /*  1276     2 */
	short unsigned int         m_usSniperHit;        /*  1278     2 */
	void CTFSniperRifle(class CTFSniperRifle *, class CTFSniperRifle &); /* linkage=_ZN14CTFSniperRifleC4EOS_ */

	void CTFSniperRifle(class CTFSniperRifle *, const class CTFSniperRifle  &); /* linkage=_ZN14CTFSniperRifleC4ERKS_ */

	void CTFSniperRifle(class CTFSniperRifle *); /* linkage=_ZN14CTFSniperRifleC4Ev */

	virtual void Spawn(class CTFSniperRifle *); /* linkage=_ZN14CTFSniperRifle5SpawnEv */

	virtual void Precache(class CTFSniperRifle *); /* linkage=_ZN14CTFSniperRifle8PrecacheEv */

	virtual int iItemSlot(class CTFSniperRifle *); /* linkage=_ZN14CTFSniperRifle9iItemSlotEv */

	virtual int GetItemInfo(class CTFSniperRifle *, ItemInfo *); /* linkage=_ZN14CTFSniperRifle11GetItemInfoEP8ItemInfo */

	virtual void ItemPostFrame(class CTFSniperRifle *); /* linkage=_ZN14CTFSniperRifle13ItemPostFrameEv */

	virtual void PrimaryAttack(class CTFSniperRifle *); /* linkage=_ZN14CTFSniperRifle13PrimaryAttackEv */

	virtual void SecondaryAttack(class CTFSniperRifle *); /* linkage=_ZN14CTFSniperRifle15SecondaryAttackEv */

	virtual int AddToPlayer(class CTFSniperRifle *, class CBasePlayer *); /* linkage=_ZN14CTFSniperRifle11AddToPlayerEP11CBasePlayer */

	virtual BOOL Deploy(class CTFSniperRifle *); /* linkage=_ZN14CTFSniperRifle6DeployEv */

	virtual void Holster(class CTFSniperRifle *, int); /* linkage=_ZN14CTFSniperRifle7HolsterEi */

	virtual void Reload(class CTFSniperRifle *); /* linkage=_ZN14CTFSniperRifle6ReloadEv */

	virtual void WeaponIdle(class CTFSniperRifle *); /* linkage=_ZN14CTFSniperRifle10WeaponIdleEv */

	void UpdateSpot(class CTFSniperRifle *); /* linkage=_ZN14CTFSniperRifle10UpdateSpotEv */

	virtual void ~CTFSniperRifle(class CTFSniperRifle *, int); /* linkage=_ZN14CTFSniperRifleD4Ev */

	/* vtable has 12 entries: {
	   [2] = Spawn(_ZN14CTFSniperRifle5SpawnEv), 
	   [3] = Precache(_ZN14CTFSniperRifle8PrecacheEv), 
	   [68] = iItemSlot(_ZN14CTFSniperRifle9iItemSlotEv), 
	   [69] = GetItemInfo(_ZN14CTFSniperRifle11GetItemInfoEP8ItemInfo), 
	   [76] = ItemPostFrame(_ZN14CTFSniperRifle13ItemPostFrameEv), 
	   [91] = PrimaryAttack(_ZN14CTFSniperRifle13PrimaryAttackEv), 
	   [92] = SecondaryAttack(_ZN14CTFSniperRifle15SecondaryAttackEv), 
	   [66] = AddToPlayer(_ZN14CTFSniperRifle11AddToPlayerEP11CBasePlayer), 
	   [71] = Deploy(_ZN14CTFSniperRifle6DeployEv), 
	   [73] = Holster(_ZN14CTFSniperRifle7HolsterEi), 
	   [93] = Reload(_ZN14CTFSniperRifle6ReloadEv), 
	   [94] = WeaponIdle(_ZN14CTFSniperRifle10WeaponIdleEv), 
	} */
	/* size: 1280, cachelines: 20, members: 5 */
	/* sum members: 12, holes: 1, sum holes: 1268 */
};
class CTFTranq : public CBasePlayerWeapon {

	/* XXX 1268 bytes hole, try to pack */
public:


	/* class CBasePlayerWeapon   <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 19 boundary (1216 bytes) was 52 bytes ago --- */
	short unsigned int         m_usFireTranquilizer; /*  1268     2 */
	void CTFTranq(class CTFTranq *, class CTFTranq &); /* linkage=_ZN8CTFTranqC4EOS_ */

	void CTFTranq(class CTFTranq *, const class CTFTranq  &); /* linkage=_ZN8CTFTranqC4ERKS_ */

	void CTFTranq(class CTFTranq *); /* linkage=_ZN8CTFTranqC4Ev */

	virtual void Spawn(class CTFTranq *); /* linkage=_ZN8CTFTranq5SpawnEv */

	virtual void Precache(class CTFTranq *); /* linkage=_ZN8CTFTranq8PrecacheEv */

	virtual int iItemSlot(class CTFTranq *); /* linkage=_ZN8CTFTranq9iItemSlotEv */

	virtual int GetItemInfo(class CTFTranq *, ItemInfo *); /* linkage=_ZN8CTFTranq11GetItemInfoEP8ItemInfo */

	virtual void PrimaryAttack(class CTFTranq *); /* linkage=_ZN8CTFTranq13PrimaryAttackEv */

	virtual BOOL Deploy(class CTFTranq *); /* linkage=_ZN8CTFTranq6DeployEv */

	virtual void Reload(class CTFTranq *); /* linkage=_ZN8CTFTranq6ReloadEv */

	virtual void WeaponIdle(class CTFTranq *); /* linkage=_ZN8CTFTranq10WeaponIdleEv */

	virtual void ~CTFTranq(class CTFTranq *, int); /* linkage=_ZN8CTFTranqD4Ev */

	/* vtable has 8 entries: {
	   [2] = Spawn(_ZN8CTFTranq5SpawnEv), 
	   [3] = Precache(_ZN8CTFTranq8PrecacheEv), 
	   [68] = iItemSlot(_ZN8CTFTranq9iItemSlotEv), 
	   [69] = GetItemInfo(_ZN8CTFTranq11GetItemInfoEP8ItemInfo), 
	   [91] = PrimaryAttack(_ZN8CTFTranq13PrimaryAttackEv), 
	   [71] = Deploy(_ZN8CTFTranq6DeployEv), 
	   [93] = Reload(_ZN8CTFTranq6ReloadEv), 
	   [94] = WeaponIdle(_ZN8CTFTranq10WeaponIdleEv), 
	} */
	/* size: 1272, cachelines: 20, members: 2 */
	/* sum members: 2, holes: 1, sum holes: 1268 */
	/* padding: 2 */
	/* last cacheline: 56 bytes */
};
struct pmtrace_s {
	qboolean                   allsolid;             /*     0     4 */
	qboolean                   startsolid;           /*     4     4 */
	qboolean                   inopen;               /*     8     4 */
	qboolean                   inwater;              /*    12     4 */
	float                      fraction;             /*    16     4 */
	vec3_t                     endpos;               /*    20    12 */
	pmplane_t                  plane;                /*    32    16 */
	int                        ent;                  /*    48     4 */
	vec3_t                     deltavelocity;        /*    52    12 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	int                        hitgroup;             /*    64     4 */

	/* size: 68, cachelines: 2, members: 10 */
	/* last cacheline: 4 bytes */
};
struct physent_s {
	char                       name[32];             /*     0    32 */
	int                        player;               /*    32     4 */
	vec3_t                     origin;               /*    36    12 */
	struct model_s *           model;                /*    48     4 */
	struct model_s *           studiomodel;          /*    52     4 */
	vec3_t                     mins;                 /*    56    12 */
	/* --- cacheline 1 boundary (64 bytes) was 4 bytes ago --- */
	vec3_t                     maxs;                 /*    68    12 */
	int                        info;                 /*    80     4 */
	vec3_t                     angles;               /*    84    12 */
	int                        solid;                /*    96     4 */
	int                        skin;                 /*   100     4 */
	int                        rendermode;           /*   104     4 */
	float                      frame;                /*   108     4 */
	int                        sequence;             /*   112     4 */
	byte                       controller[4];        /*   116     4 */
	byte                       blending[2];          /*   120     2 */

	/* XXX 2 bytes hole, try to pack */

	int                        movetype;             /*   124     4 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	int                        takedamage;           /*   128     4 */
	int                        blooddecal;           /*   132     4 */
	int                        team;                 /*   136     4 */
	int                        classnumber;          /*   140     4 */
	int                        iuser1;               /*   144     4 */
	int                        iuser2;               /*   148     4 */
	int                        iuser3;               /*   152     4 */
	int                        iuser4;               /*   156     4 */
	float                      fuser1;               /*   160     4 */
	float                      fuser2;               /*   164     4 */
	float                      fuser3;               /*   168     4 */
	float                      fuser4;               /*   172     4 */
	vec3_t                     vuser1;               /*   176    12 */
	vec3_t                     vuser2;               /*   188    12 */
	/* --- cacheline 3 boundary (192 bytes) was 8 bytes ago --- */
	vec3_t                     vuser3;               /*   200    12 */
	vec3_t                     vuser4;               /*   212    12 */

	/* size: 224, cachelines: 4, members: 33 */
	/* sum members: 222, holes: 1, sum holes: 2 */
	/* last cacheline: 32 bytes */
};
struct playermove_s {
	int                        player_index;         /*     0     4 */
	qboolean                   server;               /*     4     4 */
	qboolean                   multiplayer;          /*     8     4 */
	float                      time;                 /*    12     4 */
	float                      frametime;            /*    16     4 */
	vec3_t                     forward;              /*    20    12 */
	vec3_t                     right;                /*    32    12 */
	vec3_t                     up;                   /*    44    12 */
	vec3_t                     origin;               /*    56    12 */
	/* --- cacheline 1 boundary (64 bytes) was 4 bytes ago --- */
	vec3_t                     angles;               /*    68    12 */
	vec3_t                     oldangles;            /*    80    12 */
	vec3_t                     velocity;             /*    92    12 */
	vec3_t                     movedir;              /*   104    12 */
	vec3_t                     basevelocity;         /*   116    12 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	vec3_t                     view_ofs;             /*   128    12 */
	float                      flDuckTime;           /*   140     4 */
	qboolean                   bInDuck;              /*   144     4 */
	int                        flTimeStepSound;      /*   148     4 */
	int                        iStepLeft;            /*   152     4 */
	float                      flFallVelocity;       /*   156     4 */
	vec3_t                     punchangle;           /*   160    12 */
	float                      flSwimTime;           /*   172     4 */
	float                      flNextPrimaryAttack;  /*   176     4 */
	int                        effects;              /*   180     4 */
	int                        flags;                /*   184     4 */
	int                        usehull;              /*   188     4 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	float                      gravity;              /*   192     4 */
	float                      friction;             /*   196     4 */
	int                        oldbuttons;           /*   200     4 */
	float                      waterjumptime;        /*   204     4 */
	qboolean                   dead;                 /*   208     4 */
	int                        deadflag;             /*   212     4 */
	int                        spectator;            /*   216     4 */
	int                        movetype;             /*   220     4 */
	int                        onground;             /*   224     4 */
	int                        waterlevel;           /*   228     4 */
	int                        watertype;            /*   232     4 */
	int                        oldwaterlevel;        /*   236     4 */
	char                       sztexturename[256];   /*   240   256 */
	/* --- cacheline 7 boundary (448 bytes) was 48 bytes ago --- */
	char                       chtexturetype;        /*   496     1 */

	/* XXX 3 bytes hole, try to pack */

	float                      maxspeed;             /*   500     4 */
	float                      clientmaxspeed;       /*   504     4 */
	int                        iuser1;               /*   508     4 */
	/* --- cacheline 8 boundary (512 bytes) --- */
	int                        iuser2;               /*   512     4 */
	int                        iuser3;               /*   516     4 */
	int                        iuser4;               /*   520     4 */
	float                      fuser1;               /*   524     4 */
	float                      fuser2;               /*   528     4 */
	float                      fuser3;               /*   532     4 */
	float                      fuser4;               /*   536     4 */
	vec3_t                     vuser1;               /*   540    12 */
	vec3_t                     vuser2;               /*   552    12 */
	vec3_t                     vuser3;               /*   564    12 */
	/* --- cacheline 9 boundary (576 bytes) --- */
	vec3_t                     vuser4;               /*   576    12 */
	int                        numphysent;           /*   588     4 */
	physent_t                  physents[600];        /*   592 134400 */
	/* --- cacheline 2109 boundary (134976 bytes) was 16 bytes ago --- */
	int                        nummoveent;           /* 134992     4 */
	physent_t                  moveents[64];         /* 134996 14336 */
	/* --- cacheline 2333 boundary (149312 bytes) was 20 bytes ago --- */
	int                        numvisent;            /* 149332     4 */
	physent_t                  visents[600];         /* 149336 134400 */
	/* --- cacheline 4433 boundary (283712 bytes) was 24 bytes ago --- */
	usercmd_t                  cmd;                  /* 283736    52 */
	/* --- cacheline 4434 boundary (283776 bytes) was 12 bytes ago --- */
	int                        numtouch;             /* 283788     4 */
	pmtrace_t                  touchindex[600];      /* 283792 40800 */
	/* --- cacheline 5071 boundary (324544 bytes) was 48 bytes ago --- */
	char                       physinfo[256];        /* 324592   256 */
	/* --- cacheline 5075 boundary (324800 bytes) was 48 bytes ago --- */
	struct movevars_s *        movevars;             /* 324848     4 */
	vec_t                      player_mins[4][3];    /* 324852    48 */
	/* --- cacheline 5076 boundary (324864 bytes) was 36 bytes ago --- */
	vec_t                      player_maxs[4][3];    /* 324900    48 */
	/* --- cacheline 5077 boundary (324928 bytes) was 20 bytes ago --- */
	const char  *              (*PM_Info_ValueForKey)(const char  *, const char  *); /* 324948     4 */
	void                       (*PM_Particle)(float *, int, float, int, int); /* 324952     4 */
	int                        (*PM_TestPlayerPosition)(float *, pmtrace_t *); /* 324956     4 */
	void                       (*Con_NPrintf)(int, char *, ...); /* 324960     4 */
	void                       (*Con_DPrintf)(char *, ...); /* 324964     4 */
	void                       (*Con_Printf)(char *, ...); /* 324968     4 */
	double                     (*Sys_FloatTime)(void); /* 324972     4 */
	void                       (*PM_StuckTouch)(int, pmtrace_t *); /* 324976     4 */
	int                        (*PM_PointContents)(float *, int *); /* 324980     4 */
	int                        (*PM_TruePointContents)(float *); /* 324984     4 */
	int                        (*PM_HullPointContents)(struct hull_s *, int, float *); /* 324988     4 */
	/* --- cacheline 5078 boundary (324992 bytes) --- */
	pmtrace_t                  (*PM_PlayerTrace)(float *, float *, int, int); /* 324992     4 */
	struct pmtrace_s *         (*PM_TraceLine)(float *, float *, int, int, int); /* 324996     4 */
	int32                      (*RandomLong)(int32, int32); /* 325000     4 */
	float                      (*RandomFloat)(float, float); /* 325004     4 */
	int                        (*PM_GetModelType)(struct model_s *); /* 325008     4 */
	void                       (*PM_GetModelBounds)(struct model_s *, float *, float *); /* 325012     4 */
	void *                     (*PM_HullForBsp)(physent_t *, float *); /* 325016     4 */
	float                      (*PM_TraceModel)(physent_t *, float *, float *, trace_t *); /* 325020     4 */
	int                        (*COM_FileSize)(char *); /* 325024     4 */
	byte *                     (*COM_LoadFile)(char *, int, int *); /* 325028     4 */
	void                       (*COM_FreeFile)(void *); /* 325032     4 */
	char *                     (*memfgets)(byte *, int, int *, char *, int); /* 325036     4 */
	qboolean                   runfuncs;             /* 325040     4 */
	void                       (*PM_PlaySound)(int, const char  *, float, float, int, int); /* 325044     4 */
	const char  *              (*PM_TraceTexture)(int, float *, float *); /* 325048     4 */
	void                       (*PM_PlaybackEventFull)(int, int, short unsigned int, float, float *, float *, float, float, int, int, int, int); /* 325052     4 */
	/* --- cacheline 5079 boundary (325056 bytes) --- */
	pmtrace_t                  (*PM_PlayerTraceEx)(float *, float *, int, int (*)(physent_t *)); /* 325056     4 */
	int                        (*PM_TestPlayerPositionEx)(float *, pmtrace_t *, int (*)(physent_t *)); /* 325060     4 */
	struct pmtrace_s *         (*PM_TraceLineEx)(float *, float *, int, int, int (*)(physent_t *)); /* 325064     4 */

	/* size: 325068, cachelines: 5080, members: 97 */
	/* sum members: 325065, holes: 1, sum holes: 3 */
	/* last cacheline: 12 bytes */
};
struct movevars_s {
	float                      gravity;              /*     0     4 */
	float                      stopspeed;            /*     4     4 */
	float                      maxspeed;             /*     8     4 */
	float                      spectatormaxspeed;    /*    12     4 */
	float                      accelerate;           /*    16     4 */
	float                      airaccelerate;        /*    20     4 */
	float                      wateraccelerate;      /*    24     4 */
	float                      friction;             /*    28     4 */
	float                      edgefriction;         /*    32     4 */
	float                      waterfriction;        /*    36     4 */
	float                      entgravity;           /*    40     4 */
	float                      bounce;               /*    44     4 */
	float                      stepsize;             /*    48     4 */
	float                      maxvelocity;          /*    52     4 */
	float                      zmax;                 /*    56     4 */
	float                      waveHeight;           /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	qboolean                   footsteps;            /*    64     4 */
	char                       skyName[32];          /*    68    32 */
	float                      rollangle;            /*   100     4 */
	float                      rollspeed;            /*   104     4 */
	float                      skycolor_r;           /*   108     4 */
	float                      skycolor_g;           /*   112     4 */
	float                      skycolor_b;           /*   116     4 */
	float                      skyvec_x;             /*   120     4 */
	float                      skyvec_y;             /*   124     4 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	float                      skyvec_z;             /*   128     4 */

	/* size: 132, cachelines: 3, members: 26 */
	/* last cacheline: 4 bytes */
};
struct mplane_s {
	vec3_t                     normal;               /*     0    12 */
	float                      dist;                 /*    12     4 */
	byte                       type;                 /*    16     1 */
	byte                       signbits;             /*    17     1 */
	byte                       pad[2];               /*    18     2 */

	/* size: 20, cachelines: 1, members: 5 */
	/* last cacheline: 20 bytes */
};
struct hull_s {
	dclipnode_t *              clipnodes;            /*     0     4 */
	mplane_t *                 planes;               /*     4     4 */
	int                        firstclipnode;        /*     8     4 */
	int                        lastclipnode;         /*    12     4 */
	vec3_t                     clip_mins;            /*    16    12 */
	vec3_t                     clip_maxs;            /*    28    12 */

	/* size: 40, cachelines: 1, members: 6 */
	/* last cacheline: 40 bytes */
};
class CBitVecAccessor {
private:

	uint32 *                   m_pDWords;            /*     0     4 */
	int                        m_iBit;               /*     4     4 */
	void CBitVecAccessor(class CBitVecAccessor *, uint32 *, int); /* linkage=_ZN15CBitVecAccessorC4EPji */

	void operator=(class CBitVecAccessor *, int); /* linkage=_ZN15CBitVecAccessoraSEi */

	uint32 operator uint32(class CBitVecAccessor *); /* linkage=_ZN15CBitVecAccessorcvjEv */


	/* size: 8, cachelines: 1, members: 2 */
	/* last cacheline: 8 bytes */
};
class CBitVec<32> {
	enum {
		NUM_DWORDS = 1,
	};

private:

	uint32                     m_DWords[1];          /*     0     4 */
	void CBitVec(class CBitVec<32> *); /* linkage=_ZN7CBitVecILi32EEC4Ev */

	void Init(class CBitVec<32> *, int); /* linkage=_ZN7CBitVecILi32EE4InitEi */

	class CBitVecAccessor operator[](class CBitVec<32> *, int); /* linkage=_ZN7CBitVecILi32EEixEi */

	class CBitVec<32> & operator=(class CBitVec<32> *, const class CBitVec<32>  &); /* linkage=_ZN7CBitVecILi32EEaSERKS0_ */

	bool operator==(class CBitVec<32> *, const class CBitVec<32>  &); /* linkage=_ZN7CBitVecILi32EEeqERKS0_ */

	bool operator!=(class CBitVec<32> *, const class CBitVec<32>  &); /* linkage=_ZN7CBitVecILi32EEneERKS0_ */

	int GetNumDWords(class CBitVec<32> *); /* linkage=_ZN7CBitVecILi32EE12GetNumDWordsEv */

	uint32 GetDWord(class CBitVec<32> *, int); /* linkage=_ZN7CBitVecILi32EE8GetDWordEi */

	void SetDWord(class CBitVec<32> *, int, uint32); /* linkage=_ZN7CBitVecILi32EE8SetDWordEij */

	int GetNumBits(class CBitVec<32> *); /* linkage=_ZN7CBitVecILi32EE10GetNumBitsEv */


	/* size: 4, cachelines: 1, members: 1 */
	/* last cacheline: 4 bytes */
};
class CVoiceGameMgr {
	int ()(void) * *           _vptr.CVoiceGameMgr;  /*     0     4 */
private:

	int                        m_msgPlayerVoiceMask; /*     4     4 */
	int                        m_msgRequestState;    /*     8     4 */
	class IVoiceGameMgrHelper * m_pHelper;           /*    12     4 */
	int                        m_nMaxPlayers;        /*    16     4 */
	double                     m_UpdateInterval;     /*    20     8 */
	void CVoiceGameMgr(class CVoiceGameMgr *, const class CVoiceGameMgr  &); /* linkage=_ZN13CVoiceGameMgrC4ERKS_ */

	void CVoiceGameMgr(class CVoiceGameMgr *); /* linkage=_ZN13CVoiceGameMgrC4Ev */

	virtual void ~CVoiceGameMgr(class CVoiceGameMgr *, int); /* linkage=_ZN13CVoiceGameMgrD4Ev */

	bool Init(class CVoiceGameMgr *, class IVoiceGameMgrHelper *, int); /* linkage=_ZN13CVoiceGameMgr4InitEP19IVoiceGameMgrHelperi */

	void SetHelper(class CVoiceGameMgr *, class IVoiceGameMgrHelper *); /* linkage=_ZN13CVoiceGameMgr9SetHelperEP19IVoiceGameMgrHelper */

	void Update(class CVoiceGameMgr *, double); /* linkage=_ZN13CVoiceGameMgr6UpdateEd */

	void ClientConnected(class CVoiceGameMgr *, edict_t *); /* linkage=_ZN13CVoiceGameMgr15ClientConnectedEP7edict_s */

	bool ClientCommand(class CVoiceGameMgr *, class CBasePlayer *, const char  *); /* linkage=_ZN13CVoiceGameMgr13ClientCommandEP11CBasePlayerPKc */

	bool PlayerHasBlockedPlayer(class CVoiceGameMgr *, class CBasePlayer *, class CBasePlayer *); /* linkage=_ZN13CVoiceGameMgr22PlayerHasBlockedPlayerEP11CBasePlayerS1_ */

	void UpdateMasks(class CVoiceGameMgr *); /* linkage=_ZN13CVoiceGameMgr11UpdateMasksEv */


	/* size: 28, cachelines: 1, members: 6 */
	/* last cacheline: 28 bytes */
} __attribute__((__packed__));
class InterfaceReg {
	InstantiateInterfaceFn     m_CreateFn;           /*     0     4 */
	const char  *              m_pName;              /*     4     4 */
	class InterfaceReg *       m_pNext;              /*     8     4 */

	/* Bitfield combined with previous fields */

	static class InterfaceReg *       s_pInterfaceRegs; /*     0     0 */
	void InterfaceReg(class InterfaceReg *, InstantiateInterfaceFn, const char  *); /* linkage=_ZN12InterfaceRegC4EPFPvvEPKc */


	/* size: 12, cachelines: 1, members: 3, static members: 1 */
	/* last cacheline: 12 bytes */
};
