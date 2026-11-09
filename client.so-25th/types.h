struct rect_s {
	int                        left;                 /*     0     4 */
	int                        right;                /*     4     4 */
	int                        top;                  /*     8     4 */
	int                        bottom;               /*    12     4 */

	/* size: 16, cachelines: 1, members: 4 */
	/* last cacheline: 16 bytes */
};
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

	void Vector(class Vector *, double, double, double); /* linkage=_ZN6VectorC4Eddd */

	void Vector(class Vector *, int, int, int); /* linkage=_ZN6VectorC4Eiii */

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
struct particle_s {
	class Vector              org;                   /*     0    12 */
	short int                  color;                /*    12     2 */
	short int                  packedColor;          /*    14     2 */
	class particle_s *         next;                 /*    16     4 */
	class Vector              vel;                   /*    20    12 */
	float                      ramp;                 /*    32     4 */
	float                      die;                  /*    36     4 */
	ptype_t                    type;                 /*    40     4 */
	void                       (*deathfunc)(class particle_s *); /*    44     4 */
	void                       (*callback)(class particle_s *, float); /*    48     4 */
	unsigned char              context;              /*    52     1 */
	void particle_s(class particle_s *); /* linkage=_ZN10particle_sC4Ev */


	/* size: 56, cachelines: 1, members: 11 */
	/* padding: 3 */
	/* last cacheline: 56 bytes */
};
struct beam_s {
	BEAM *                     next;                 /*     0     4 */
	int                        type;                 /*     4     4 */
	int                        flags;                /*     8     4 */
	class Vector              source;                /*    12    12 */
	class Vector              target;                /*    24    12 */
	class Vector              delta;                 /*    36    12 */
	float                      t;                    /*    48     4 */
	float                      freq;                 /*    52     4 */
	float                      die;                  /*    56     4 */
	float                      width;                /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	float                      amplitude;            /*    64     4 */
	float                      r;                    /*    68     4 */
	float                      g;                    /*    72     4 */
	float                      b;                    /*    76     4 */
	float                      brightness;           /*    80     4 */
	float                      speed;                /*    84     4 */
	float                      frameRate;            /*    88     4 */
	float                      frame;                /*    92     4 */
	int                        segments;             /*    96     4 */
	int                        startEntity;          /*   100     4 */
	int                        endEntity;            /*   104     4 */
	int                        modelIndex;           /*   108     4 */
	int                        frameCount;           /*   112     4 */
	class model_s *            pFollowModel;         /*   116     4 */
	class particle_s *         particles;            /*   120     4 */
	void beam_s(class beam_s *); /* linkage=_ZN6beam_sC4Ev */


	/* size: 124, cachelines: 2, members: 25 */
	/* last cacheline: 60 bytes */
};
struct dlight_s {
	class Vector              origin;                /*     0    12 */
	float                      radius;               /*    12     4 */
	color24                    color;                /*    16     3 */

	/* XXX 1 byte hole, try to pack */

	float                      die;                  /*    20     4 */
	float                      decay;                /*    24     4 */
	float                      minlight;             /*    28     4 */
	int                        key;                  /*    32     4 */
	qboolean                   dark;                 /*    36     4 */
	void dlight_s(class dlight_s *); /* linkage=_ZN8dlight_sC4Ev */


	/* size: 40, cachelines: 1, members: 8 */
	/* sum members: 39, holes: 1, sum holes: 1 */
	/* last cacheline: 40 bytes */
};
struct efrag_s {
	class mleaf_s *            leaf;                 /*     0     4 */
	class efrag_s *            leafnext;             /*     4     4 */
	class cl_entity_s *        entity;               /*     8     4 */
	class efrag_s *            entnext;              /*    12     4 */

	/* size: 16, cachelines: 1, members: 4 */
	/* last cacheline: 16 bytes */
};
struct cl_entity_s {
	int                        index;                /*     0     4 */
	qboolean                   player;               /*     4     4 */
	entity_state_t             baseline;             /*     8   340 */
	/* --- cacheline 5 boundary (320 bytes) was 28 bytes ago --- */
	entity_state_t             prevstate;            /*   348   340 */
	/* --- cacheline 10 boundary (640 bytes) was 48 bytes ago --- */
	entity_state_t             curstate;             /*   688   340 */
	/* --- cacheline 16 boundary (1024 bytes) was 4 bytes ago --- */
	int                        current_position;     /*  1028     4 */
	position_history_t         ph[64];               /*  1032  1792 */
	/* --- cacheline 44 boundary (2816 bytes) was 8 bytes ago --- */
	mouth_t                    mouth;                /*  2824     8 */
	latchedvars_t              latched;              /*  2832    52 */
	/* --- cacheline 45 boundary (2880 bytes) was 4 bytes ago --- */
	float                      lastmove;             /*  2884     4 */
	class Vector              origin;                /*  2888    12 */
	class Vector              angles;                /*  2900    12 */
	class Vector              attachment[4];         /*  2912    48 */
	/* --- cacheline 46 boundary (2944 bytes) was 16 bytes ago --- */
	int                        trivial_accept;       /*  2960     4 */
	class model_s *            model;                /*  2964     4 */
	class efrag_s *            efrag;                /*  2968     4 */
	class mnode_s *            topnode;              /*  2972     4 */
	float                      syncbase;             /*  2976     4 */
	int                        visframe;             /*  2980     4 */
	colorVec                   cvFloorColor;         /*  2984    16 */
	void cl_entity_s(class cl_entity_s *); /* linkage=_ZN11cl_entity_sC4Ev */


	/* size: 3000, cachelines: 47, members: 20 */
	/* last cacheline: 56 bytes */
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
struct event_args_s {
	int                        flags;                /*     0     4 */
	int                        entindex;             /*     4     4 */
	float                      origin[3];            /*     8    12 */
	float                      angles[3];            /*    20    12 */
	float                      velocity[3];          /*    32    12 */
	int                        ducking;              /*    44     4 */
	float                      fparam1;              /*    48     4 */
	float                      fparam2;              /*    52     4 */
	int                        iparam1;              /*    56     4 */
	int                        iparam2;              /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	int                        bparam1;              /*    64     4 */
	int                        bparam2;              /*    68     4 */

	/* size: 72, cachelines: 2, members: 12 */
	/* last cacheline: 8 bytes */
};
struct tempent_s {
	int                        flags;                /*     0     4 */
	float                      die;                  /*     4     4 */
	float                      frameMax;             /*     8     4 */
	float                      x;                    /*    12     4 */
	float                      y;                    /*    16     4 */
	float                      z;                    /*    20     4 */
	float                      fadeSpeed;            /*    24     4 */
	float                      bounceFactor;         /*    28     4 */
	int                        hitSound;             /*    32     4 */
	void                       (*hitcallback)(class tempent_s *, class pmtrace_s *); /*    36     4 */
	void                       (*callback)(class tempent_s *, float, float); /*    40     4 */
	class tempent_s *          next;                 /*    44     4 */
	int                        priority;             /*    48     4 */
	short int                  clientIndex;          /*    52     2 */

	/* XXX 2 bytes hole, try to pack */

	class Vector              tentOffset;            /*    56    12 */
	/* --- cacheline 1 boundary (64 bytes) was 4 bytes ago --- */
	cl_entity_t                entity;               /*    68  3000 */
	void tempent_s(class tempent_s *); /* linkage=_ZN9tempent_sC4Ev */


	/* size: 3068, cachelines: 48, members: 16 */
	/* sum members: 3066, holes: 1, sum holes: 2 */
	/* last cacheline: 60 bytes */
};
struct pmtrace_s {
	qboolean                   allsolid;             /*     0     4 */
	qboolean                   startsolid;           /*     4     4 */
	qboolean                   inopen;               /*     8     4 */
	qboolean                   inwater;              /*    12     4 */
	float                      fraction;             /*    16     4 */
	class Vector              endpos;                /*    20    12 */
	pmplane_t                  plane;                /*    32    16 */
	int                        ent;                  /*    48     4 */
	class Vector              deltavelocity;         /*    52    12 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	int                        hitgroup;             /*    64     4 */
	void pmtrace_s(class pmtrace_s *); /* linkage=_ZN9pmtrace_sC4Ev */


	/* size: 68, cachelines: 2, members: 10 */
	/* last cacheline: 4 bytes */
};
struct efx_api_s {
	particle_t *               (*R_AllocParticle)(void (*)(class particle_s *, float)); /*     0     4 */
	void                       (*R_BlobExplosion)(float *); /*     4     4 */
	void                       (*R_Blood)(float *, float *, int, int); /*     8     4 */
	void                       (*R_BloodSprite)(float *, int, int, int, float); /*    12     4 */
	void                       (*R_BloodStream)(float *, float *, int, int); /*    16     4 */
	void                       (*R_BreakModel)(float *, float *, float *, float, float, int, int, char); /*    20     4 */
	void                       (*R_Bubbles)(float *, float *, float, int, int, float); /*    24     4 */
	void                       (*R_BubbleTrail)(float *, float *, float, int, int, float); /*    28     4 */
	void                       (*R_BulletImpactParticles)(float *); /*    32     4 */
	void                       (*R_EntityParticles)(class cl_entity_s *); /*    36     4 */
	void                       (*R_Explosion)(float *, int, float, float, int); /*    40     4 */
	void                       (*R_FizzEffect)(class cl_entity_s *, int, int); /*    44     4 */
	void                       (*R_FireField)(float *, int, int, int, int, float); /*    48     4 */
	void                       (*R_FlickerParticles)(float *); /*    52     4 */
	void                       (*R_FunnelSprite)(float *, int, int); /*    56     4 */
	void                       (*R_Implosion)(float *, float, int, float); /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	void                       (*R_LargeFunnel)(float *, int); /*    64     4 */
	void                       (*R_LavaSplash)(float *); /*    68     4 */
	void                       (*R_MultiGunshot)(float *, float *, float *, int, int, int *); /*    72     4 */
	void                       (*R_MuzzleFlash)(float *, int); /*    76     4 */
	void                       (*R_ParticleBox)(float *, float *, unsigned char, unsigned char, unsigned char, float); /*    80     4 */
	void                       (*R_ParticleBurst)(float *, int, int, float); /*    84     4 */
	void                       (*R_ParticleExplosion)(float *); /*    88     4 */
	void                       (*R_ParticleExplosion2)(float *, int, int); /*    92     4 */
	void                       (*R_ParticleLine)(float *, float *, unsigned char, unsigned char, unsigned char, float); /*    96     4 */
	void                       (*R_PlayerSprites)(int, int, int, int); /*   100     4 */
	void                       (*R_Projectile)(float *, float *, int, int, int, void (*)(class tempent_s *, class pmtrace_s *)); /*   104     4 */
	void                       (*R_RicochetSound)(float *); /*   108     4 */
	void                       (*R_RicochetSprite)(float *, class model_s *, float, float); /*   112     4 */
	void                       (*R_RocketFlare)(float *); /*   116     4 */
	void                       (*R_RocketTrail)(float *, float *, int); /*   120     4 */
	void                       (*R_RunParticleEffect)(float *, float *, int, int); /*   124     4 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	void                       (*R_ShowLine)(float *, float *); /*   128     4 */
	void                       (*R_SparkEffect)(float *, int, int, int); /*   132     4 */
	void                       (*R_SparkShower)(float *); /*   136     4 */
	void                       (*R_SparkStreaks)(float *, int, int, int); /*   140     4 */
	void                       (*R_Spray)(float *, float *, int, int, int, int, int); /*   144     4 */
	void                       (*R_Sprite_Explode)(TEMPENTITY *, float, int); /*   148     4 */
	void                       (*R_Sprite_Smoke)(TEMPENTITY *, float); /*   152     4 */
	void                       (*R_Sprite_Spray)(float *, float *, int, int, int, int); /*   156     4 */
	void                       (*R_Sprite_Trail)(int, float *, float *, int, int, float, float, float, int, float); /*   160     4 */
	void                       (*R_Sprite_WallPuff)(TEMPENTITY *, float); /*   164     4 */
	void                       (*R_StreakSplash)(float *, float *, int, int, float, int, int); /*   168     4 */
	void                       (*R_TracerEffect)(float *, float *); /*   172     4 */
	void                       (*R_UserTracerParticle)(float *, float *, float, int, float, unsigned char, void (*)(class particle_s *)); /*   176     4 */
	particle_t *               (*R_TracerParticles)(float *, float *, float); /*   180     4 */
	void                       (*R_TeleportSplash)(float *); /*   184     4 */
	void                       (*R_TempSphereModel)(float *, float, float, int, int); /*   188     4 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	TEMPENTITY *               (*R_TempModel)(float *, float *, float *, float, int, int); /*   192     4 */
	TEMPENTITY *               (*R_DefaultSprite)(float *, int, float); /*   196     4 */
	TEMPENTITY *               (*R_TempSprite)(float *, float *, float, int, int, int, float, float, int); /*   200     4 */
	int                        (*Draw_DecalIndex)(int); /*   204     4 */
	int                        (*Draw_DecalIndexFromName)(char *); /*   208     4 */
	void                       (*R_DecalShoot)(int, int, int, float *, int); /*   212     4 */
	void                       (*R_AttachTentToPlayer)(int, int, float, float); /*   216     4 */
	void                       (*R_KillAttachedTents)(int); /*   220     4 */
	BEAM *                     (*R_BeamCirclePoints)(int, float *, float *, int, float, float, float, float, float, int, float, float, float, float); /*   224     4 */
	BEAM *                     (*R_BeamEntPoint)(int, float *, int, float, float, float, float, float, int, float, float, float, float); /*   228     4 */
	BEAM *                     (*R_BeamEnts)(int, int, int, float, float, float, float, float, int, float, float, float, float); /*   232     4 */
	BEAM *                     (*R_BeamFollow)(int, int, float, float, float, float, float, float); /*   236     4 */
	void                       (*R_BeamKill)(int);   /*   240     4 */
	BEAM *                     (*R_BeamLightning)(float *, float *, int, float, float, float, float, float); /*   244     4 */
	BEAM *                     (*R_BeamPoints)(float *, float *, int, float, float, float, float, float, int, float, float, float, float); /*   248     4 */
	BEAM *                     (*R_BeamRing)(int, int, int, float, float, float, float, float, int, float, float, float, float); /*   252     4 */
	/* --- cacheline 4 boundary (256 bytes) --- */
	dlight_t *                 (*CL_AllocDlight)(int); /*   256     4 */
	dlight_t *                 (*CL_AllocElight)(int); /*   260     4 */
	TEMPENTITY *               (*CL_TempEntAlloc)(float *, class model_s *); /*   264     4 */
	TEMPENTITY *               (*CL_TempEntAllocNoModel)(float *); /*   268     4 */
	TEMPENTITY *               (*CL_TempEntAllocHigh)(float *, class model_s *); /*   272     4 */
	TEMPENTITY *               (*CL_TentEntAllocCustom)(float *, class model_s *, int, void (*)(class tempent_s *, float, float)); /*   276     4 */
	void                       (*R_GetPackedColor)(short int *, short int); /*   280     4 */
	short int                  (*R_LookupColor)(unsigned char, unsigned char, unsigned char); /*   284     4 */
	void                       (*R_DecalRemoveAll)(int); /*   288     4 */
	void                       (*R_FireCustomDecal)(int, int, int, float *, int, float); /*   292     4 */

	/* size: 296, cachelines: 5, members: 74 */
	/* last cacheline: 40 bytes */
};
struct SCREENINFO_s {
	int                        iSize;                /*     0     4 */
	int                        iWidth;               /*     4     4 */
	int                        iHeight;              /*     8     4 */
	int                        iFlags;               /*    12     4 */
	int                        iCharHeight;          /*    16     4 */
	short int                  charWidths[256];      /*    20   512 */

	/* size: 532, cachelines: 9, members: 6 */
	/* last cacheline: 20 bytes */
};
struct client_sprite_s {
	char                       szName[64];           /*     0    64 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	char                       szSprite[64];         /*    64    64 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	int                        hspr;                 /*   128     4 */
	int                        iRes;                 /*   132     4 */
	wrect_t                    rc;                   /*   136    16 */

	/* size: 152, cachelines: 3, members: 5 */
	/* last cacheline: 24 bytes */
};
struct hud_player_info_s {
	char *                     name;                 /*     0     4 */
	short int                  ping;                 /*     4     2 */
	byte                       thisplayer;           /*     6     1 */
	byte                       spectator;            /*     7     1 */
	byte                       packetloss;           /*     8     1 */

	/* XXX 3 bytes hole, try to pack */

	char *                     model;                /*    12     4 */
	short int                  topcolor;             /*    16     2 */
	short int                  bottomcolor;          /*    18     2 */
	uint64                     m_nSteamID;           /*    20     8 */

	/* size: 28, cachelines: 1, members: 9 */
	/* sum members: 25, holes: 1, sum holes: 3 */
	/* last cacheline: 28 bytes */
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
struct cmdalias_s {
	class cmdalias_s *         next;                 /*     0     4 */
	char                       name[32];             /*     4    32 */
	char *                     value;                /*    36     4 */

	/* size: 40, cachelines: 1, members: 3 */
	/* last cacheline: 40 bytes */
};
struct cl_enginefuncs_s {
	pfnEngSrc_pfnSPR_Load_t    pfnSPR_Load;          /*     0     4 */
	pfnEngSrc_pfnSPR_Frames_t  pfnSPR_Frames;        /*     4     4 */
	pfnEngSrc_pfnSPR_Height_t  pfnSPR_Height;        /*     8     4 */
	pfnEngSrc_pfnSPR_Width_t   pfnSPR_Width;         /*    12     4 */
	pfnEngSrc_pfnSPR_Set_t     pfnSPR_Set;           /*    16     4 */
	pfnEngSrc_pfnSPR_Draw_t    pfnSPR_Draw;          /*    20     4 */
	pfnEngSrc_pfnSPR_DrawHoles_t pfnSPR_DrawHoles;   /*    24     4 */
	pfnEngSrc_pfnSPR_DrawAdditive_t pfnSPR_DrawAdditive; /*    28     4 */
	pfnEngSrc_pfnSPR_EnableScissor_t pfnSPR_EnableScissor; /*    32     4 */
	pfnEngSrc_pfnSPR_DisableScissor_t pfnSPR_DisableScissor; /*    36     4 */
	pfnEngSrc_pfnSPR_GetList_t pfnSPR_GetList;       /*    40     4 */
	pfnEngSrc_pfnFillRGBA_t    pfnFillRGBA;          /*    44     4 */
	pfnEngSrc_pfnGetScreenInfo_t pfnGetScreenInfo;   /*    48     4 */
	pfnEngSrc_pfnSetCrosshair_t pfnSetCrosshair;     /*    52     4 */
	pfnEngSrc_pfnRegisterVariable_t pfnRegisterVariable; /*    56     4 */
	pfnEngSrc_pfnGetCvarFloat_t pfnGetCvarFloat;     /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	pfnEngSrc_pfnGetCvarString_t pfnGetCvarString;   /*    64     4 */
	pfnEngSrc_pfnAddCommand_t  pfnAddCommand;        /*    68     4 */
	pfnEngSrc_pfnHookUserMsg_t pfnHookUserMsg;       /*    72     4 */
	pfnEngSrc_pfnServerCmd_t   pfnServerCmd;         /*    76     4 */
	pfnEngSrc_pfnClientCmd_t   pfnClientCmd;         /*    80     4 */
	pfnEngSrc_pfnGetPlayerInfo_t pfnGetPlayerInfo;   /*    84     4 */
	pfnEngSrc_pfnPlaySoundByName_t pfnPlaySoundByName; /*    88     4 */
	pfnEngSrc_pfnPlaySoundByIndex_t pfnPlaySoundByIndex; /*    92     4 */
	pfnEngSrc_pfnAngleVectors_t pfnAngleVectors;     /*    96     4 */
	pfnEngSrc_pfnTextMessageGet_t pfnTextMessageGet; /*   100     4 */
	pfnEngSrc_pfnDrawCharacter_t pfnDrawCharacter;   /*   104     4 */
	pfnEngSrc_pfnDrawConsoleString_t pfnDrawConsoleString; /*   108     4 */
	pfnEngSrc_pfnDrawSetTextColor_t pfnDrawSetTextColor; /*   112     4 */
	pfnEngSrc_pfnDrawConsoleStringLen_t pfnDrawConsoleStringLen; /*   116     4 */
	pfnEngSrc_pfnConsolePrint_t pfnConsolePrint;     /*   120     4 */
	pfnEngSrc_pfnCenterPrint_t pfnCenterPrint;       /*   124     4 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	pfnEngSrc_GetWindowCenterX_t GetWindowCenterX;   /*   128     4 */
	pfnEngSrc_GetWindowCenterY_t GetWindowCenterY;   /*   132     4 */
	pfnEngSrc_GetViewAngles_t  GetViewAngles;        /*   136     4 */
	pfnEngSrc_SetViewAngles_t  SetViewAngles;        /*   140     4 */
	pfnEngSrc_GetMaxClients_t  GetMaxClients;        /*   144     4 */
	pfnEngSrc_Cvar_SetValue_t  Cvar_SetValue;        /*   148     4 */
	pfnEngSrc_Cmd_Argc_t       Cmd_Argc;             /*   152     4 */
	pfnEngSrc_Cmd_Argv_t       Cmd_Argv;             /*   156     4 */
	pfnEngSrc_Con_Printf_t     Con_Printf;           /*   160     4 */
	pfnEngSrc_Con_DPrintf_t    Con_DPrintf;          /*   164     4 */
	pfnEngSrc_Con_NPrintf_t    Con_NPrintf;          /*   168     4 */
	pfnEngSrc_Con_NXPrintf_t   Con_NXPrintf;         /*   172     4 */
	pfnEngSrc_PhysInfo_ValueForKey_t PhysInfo_ValueForKey; /*   176     4 */
	pfnEngSrc_ServerInfo_ValueForKey_t ServerInfo_ValueForKey; /*   180     4 */
	pfnEngSrc_GetClientMaxspeed_t GetClientMaxspeed; /*   184     4 */
	pfnEngSrc_CheckParm_t      CheckParm;            /*   188     4 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	pfnEngSrc_Key_Event_t      Key_Event;            /*   192     4 */
	pfnEngSrc_GetMousePosition_t GetMousePosition;   /*   196     4 */
	pfnEngSrc_IsNoClipping_t   IsNoClipping;         /*   200     4 */
	pfnEngSrc_GetLocalPlayer_t GetLocalPlayer;       /*   204     4 */
	pfnEngSrc_GetViewModel_t   GetViewModel;         /*   208     4 */
	pfnEngSrc_GetEntityByIndex_t GetEntityByIndex;   /*   212     4 */
	pfnEngSrc_GetClientTime_t  GetClientTime;        /*   216     4 */
	pfnEngSrc_V_CalcShake_t    V_CalcShake;          /*   220     4 */
	pfnEngSrc_V_ApplyShake_t   V_ApplyShake;         /*   224     4 */
	pfnEngSrc_PM_PointContents_t PM_PointContents;   /*   228     4 */
	pfnEngSrc_PM_WaterEntity_t PM_WaterEntity;       /*   232     4 */
	pfnEngSrc_PM_TraceLine_t   PM_TraceLine;         /*   236     4 */
	pfnEngSrc_CL_LoadModel_t   CL_LoadModel;         /*   240     4 */
	pfnEngSrc_CL_CreateVisibleEntity_t CL_CreateVisibleEntity; /*   244     4 */
	pfnEngSrc_GetSpritePointer_t GetSpritePointer;   /*   248     4 */
	pfnEngSrc_pfnPlaySoundByNameAtLocation_t pfnPlaySoundByNameAtLocation; /*   252     4 */
	/* --- cacheline 4 boundary (256 bytes) --- */
	pfnEngSrc_pfnPrecacheEvent_t pfnPrecacheEvent;   /*   256     4 */
	pfnEngSrc_pfnPlaybackEvent_t pfnPlaybackEvent;   /*   260     4 */
	pfnEngSrc_pfnWeaponAnim_t  pfnWeaponAnim;        /*   264     4 */
	pfnEngSrc_pfnRandomFloat_t pfnRandomFloat;       /*   268     4 */
	pfnEngSrc_pfnRandomLong_t  pfnRandomLong;        /*   272     4 */
	pfnEngSrc_pfnHookEvent_t   pfnHookEvent;         /*   276     4 */
	pfnEngSrc_Con_IsVisible_t  Con_IsVisible;        /*   280     4 */
	pfnEngSrc_pfnGetGameDirectory_t pfnGetGameDirectory; /*   284     4 */
	pfnEngSrc_pfnGetCvarPointer_t pfnGetCvarPointer; /*   288     4 */
	pfnEngSrc_Key_LookupBinding_t Key_LookupBinding; /*   292     4 */
	pfnEngSrc_pfnGetLevelName_t pfnGetLevelName;     /*   296     4 */
	pfnEngSrc_pfnGetScreenFade_t pfnGetScreenFade;   /*   300     4 */
	pfnEngSrc_pfnSetScreenFade_t pfnSetScreenFade;   /*   304     4 */
	pfnEngSrc_VGui_GetPanel_t  VGui_GetPanel;        /*   308     4 */
	pfnEngSrc_VGui_ViewportPaintBackground_t VGui_ViewportPaintBackground; /*   312     4 */
	pfnEngSrc_COM_LoadFile_t   COM_LoadFile;         /*   316     4 */
	/* --- cacheline 5 boundary (320 bytes) --- */
	pfnEngSrc_COM_ParseFile_t  COM_ParseFile;        /*   320     4 */
	pfnEngSrc_COM_FreeFile_t   COM_FreeFile;         /*   324     4 */
	class triangleapi_s *      pTriAPI;              /*   328     4 */
	class efx_api_s *          pEfxAPI;              /*   332     4 */
	class event_api_s *        pEventAPI;            /*   336     4 */
	class demo_api_s *         pDemoAPI;             /*   340     4 */
	class net_api_s *          pNetAPI;              /*   344     4 */
	class IVoiceTweak_s *      pVoiceTweak;          /*   348     4 */
	pfnEngSrc_IsSpectateOnly_t IsSpectateOnly;       /*   352     4 */
	pfnEngSrc_LoadMapSprite_t  LoadMapSprite;        /*   356     4 */
	pfnEngSrc_COM_AddAppDirectoryToSearchPath_t COM_AddAppDirectoryToSearchPath; /*   360     4 */
	pfnEngSrc_COM_ExpandFilename_t COM_ExpandFilename; /*   364     4 */
	pfnEngSrc_PlayerInfo_ValueForKey_t PlayerInfo_ValueForKey; /*   368     4 */
	pfnEngSrc_PlayerInfo_SetValueForKey_t PlayerInfo_SetValueForKey; /*   372     4 */
	pfnEngSrc_GetPlayerUniqueID_t GetPlayerUniqueID; /*   376     4 */
	pfnEngSrc_GetTrackerIDForPlayer_t GetTrackerIDForPlayer; /*   380     4 */
	/* --- cacheline 6 boundary (384 bytes) --- */
	pfnEngSrc_GetPlayerForTrackerID_t GetPlayerForTrackerID; /*   384     4 */
	pfnEngSrc_pfnServerCmdUnreliable_t pfnServerCmdUnreliable; /*   388     4 */
	pfnEngSrc_GetMousePos_t    pfnGetMousePos;       /*   392     4 */
	pfnEngSrc_SetMousePos_t    pfnSetMousePos;       /*   396     4 */
	pfnEngSrc_SetMouseEnable_t pfnSetMouseEnable;    /*   400     4 */
	pfnEngSrc_GetFirstCVarPtr_t GetFirstCvarPtr;     /*   404     4 */
	pfnEngSrc_GetFirstCmdFunctionHandle_t GetFirstCmdFunctionHandle; /*   408     4 */
	pfnEngSrc_GetNextCmdFunctionHandle_t GetNextCmdFunctionHandle; /*   412     4 */
	pfnEngSrc_GetCmdFunctionName_t GetCmdFunctionName; /*   416     4 */
	pfnEngSrc_GetClientOldTime_t hudGetClientOldTime; /*   420     4 */
	pfnEngSrc_GetServerGravityValue_t hudGetServerGravityValue; /*   424     4 */
	pfnEngSrc_GetModelByIndex_t hudGetModelByIndex;  /*   428     4 */
	pfnEngSrc_pfnSetFilterMode_t pfnSetFilterMode;   /*   432     4 */
	pfnEngSrc_pfnSetFilterColor_t pfnSetFilterColor; /*   436     4 */
	pfnEngSrc_pfnSetFilterBrightness_t pfnSetFilterBrightness; /*   440     4 */
	pfnEngSrc_pfnSequenceGet_t pfnSequenceGet;       /*   444     4 */
	/* --- cacheline 7 boundary (448 bytes) --- */
	pfnEngSrc_pfnSPR_DrawGeneric_t pfnSPR_DrawGeneric; /*   448     4 */
	pfnEngSrc_pfnSequencePickSentence_t pfnSequencePickSentence; /*   452     4 */
	pfnEngSrc_pfnDrawString_t  pfnDrawString;        /*   456     4 */
	pfnEngSrc_pfnDrawStringReverse_t pfnDrawStringReverse; /*   460     4 */
	pfnEngSrc_LocalPlayerInfo_ValueForKey_t LocalPlayerInfo_ValueForKey; /*   464     4 */
	pfnEngSrc_pfnVGUI2DrawCharacter_t pfnVGUI2DrawCharacter; /*   468     4 */
	pfnEngSrc_pfnVGUI2DrawCharacterAdd_t pfnVGUI2DrawCharacterAdd; /*   472     4 */
	pfnEngSrc_COM_GetApproxWavePlayLength COM_GetApproxWavePlayLength; /*   476     4 */
	pfnEngSrc_pfnGetCareerUI_t pfnGetCareerUI;       /*   480     4 */
	pfnEngSrc_Cvar_Set_t       Cvar_Set;             /*   484     4 */
	pfnEngSrc_pfnIsPlayingCareerMatch_t pfnIsCareerMatch; /*   488     4 */
	pfnEngSrc_pfnPlaySoundVoiceByName_t pfnPlaySoundVoiceByName; /*   492     4 */
	pfnEngSrc_pfnPrimeMusicStream_t pfnPrimeMusicStream; /*   496     4 */
	pfnEngSrc_GetAbsoluteTime_t GetAbsoluteTime;     /*   500     4 */
	pfnEngSrc_pfnProcessTutorMessageDecayBuffer_t pfnProcessTutorMessageDecayBuffer; /*   504     4 */
	pfnEngSrc_pfnConstructTutorMessageDecayBuffer_t pfnConstructTutorMessageDecayBuffer; /*   508     4 */
	/* --- cacheline 8 boundary (512 bytes) --- */
	pfnEngSrc_pfnResetTutorMessageDecayData_t pfnResetTutorMessageDecayData; /*   512     4 */
	pfnEngSrc_pfnPlaySoundByNameAtPitch_t pfnPlaySoundByNameAtPitch; /*   516     4 */
	pfnEngSrc_pfnFillRGBABlend_t pfnFillRGBABlend;   /*   520     4 */
	pfnEngSrc_pfnGetAppID_t    pfnGetAppID;          /*   524     4 */
	pfnEngSrc_pfnGetAliases_t  pfnGetAliasList;      /*   528     4 */
	pfnEngSrc_pfnVguiWrap2_GetMouseDelta_t pfnVguiWrap2_GetMouseDelta; /*   532     4 */
	pfnEngSrc_pfnFilteredClientCmd_t pfnFilteredClientCmd; /*   536     4 */

	/* size: 540, cachelines: 9, members: 135 */
	/* last cacheline: 28 bytes */
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
struct screenfade_s {
	float                      fadeSpeed;            /*     0     4 */
	float                      fadeEnd;              /*     4     4 */
	float                      fadeTotalEnd;         /*     8     4 */
	float                      fadeReset;            /*    12     4 */
	byte                       fader;                /*    16     1 */
	byte                       fadeg;                /*    17     1 */
	byte                       fadeb;                /*    18     1 */
	byte                       fadealpha;            /*    19     1 */
	int                        fadeFlags;            /*    20     4 */

	/* size: 24, cachelines: 1, members: 9 */
	/* last cacheline: 24 bytes */
};
struct event_api_s {
	int                        version;              /*     0     4 */
	void                       (*EV_PlaySound)(int, float *, int, const char  *, float, float, int, int); /*     4     4 */
	void                       (*EV_StopSound)(int, int, const char  *); /*     8     4 */
	int                        (*EV_FindModelIndex)(const char  *); /*    12     4 */
	int                        (*EV_IsLocal)(int);   /*    16     4 */
	int                        (*EV_LocalPlayerDucking)(void); /*    20     4 */
	void                       (*EV_LocalPlayerViewheight)(float *); /*    24     4 */
	void                       (*EV_LocalPlayerBounds)(int, float *, float *); /*    28     4 */
	int                        (*EV_IndexFromTrace)(class pmtrace_s *); /*    32     4 */
	class physent_s *          (*EV_GetPhysent)(int); /*    36     4 */
	void                       (*EV_SetUpPlayerPrediction)(int, int); /*    40     4 */
	void                       (*EV_PushPMStates)(void); /*    44     4 */
	void                       (*EV_PopPMStates)(void); /*    48     4 */
	void                       (*EV_SetSolidPlayers)(int); /*    52     4 */
	void                       (*EV_SetTraceHull)(int); /*    56     4 */
	void                       (*EV_PlayerTrace)(float *, float *, int, int, class pmtrace_s *); /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	void                       (*EV_WeaponAnimation)(int, int); /*    64     4 */
	short unsigned int         (*EV_PrecacheEvent)(int, const char  *); /*    68     4 */
	void                       (*EV_PlaybackEvent)(int, const class edict_s  *, short unsigned int, float, float *, float *, float, float, int, int, int, int); /*    72     4 */
	const char  *              (*EV_TraceTexture)(int, float *, float *); /*    76     4 */
	void                       (*EV_StopAllSounds)(int, int); /*    80     4 */
	void                       (*EV_KillEvents)(int, const char  *); /*    84     4 */

	/* size: 88, cachelines: 2, members: 22 */
	/* last cacheline: 24 bytes */
};
struct physent_s {
	char                       name[32];             /*     0    32 */
	int                        player;               /*    32     4 */
	class Vector              origin;                /*    36    12 */
	class model_s *            model;                /*    48     4 */
	class model_s *            studiomodel;          /*    52     4 */
	class Vector              mins;                  /*    56    12 */
	/* --- cacheline 1 boundary (64 bytes) was 4 bytes ago --- */
	class Vector              maxs;                  /*    68    12 */
	int                        info;                 /*    80     4 */
	class Vector              angles;                /*    84    12 */
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
	class Vector              vuser1;                /*   176    12 */
	class Vector              vuser2;                /*   188    12 */
	/* --- cacheline 3 boundary (192 bytes) was 8 bytes ago --- */
	class Vector              vuser3;                /*   200    12 */
	class Vector              vuser4;                /*   212    12 */
	void physent_s(class physent_s *); /* linkage=_ZN9physent_sC4Ev */


	/* size: 224, cachelines: 4, members: 33 */
	/* sum members: 222, holes: 1, sum holes: 2 */
	/* last cacheline: 32 bytes */
};
class CCoreTriangleEffect {
	int ()(void) * *           _vptr.CCoreTriangleEffect; /*     0     4 */
private:

	int                        m_iRenderFlags;       /*     4     4 */
	float                      m_flNextPVSCheck;     /*     8     4 */
	bool                       m_bInPVS;             /*    12     1 */

	/* XXX 3 bytes hole, try to pack */

	int                        m_iCollisionFlags;    /*    16     4 */
	float                      m_flPlayerDistance;   /*    20     4 */
	float                      m_flSize;             /*    24     4 */
	float                      m_flScaleSpeed;       /*    28     4 */
	float                      m_flContractSpeed;    /*    32     4 */
	float                      m_flStretchX;         /*    36     4 */
	float                      m_flStretchY;         /*    40     4 */
	float                      m_flBrightness;       /*    44     4 */
	float                      m_flFadeSpeed;        /*    48     4 */
	float                      m_flTimeCreated;      /*    52     4 */
	float                      m_flDieTime;          /*    56     4 */
	float                      m_flGravity;          /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	float                      m_flAfterDampGrav;    /*    64     4 */
	float                      m_flDampingVelocity;  /*    68     4 */
	float                      m_flDampingTime;      /*    72     4 */
	int                        m_iFramerate;         /*    76     4 */
	int                        m_iNumFrames;         /*    80     4 */
	int                        m_iFrame;             /*    84     4 */
	int                        m_iRendermode;        /*    88     4 */
	class Vector              m_vOrigin;             /*    92    12 */
	class Vector              m_vAngles;             /*   104    12 */
	class Vector              m_vAVelocity;          /*   116    12 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	class Vector              m_vVelocity;           /*   128    12 */
	class Vector              m_vLowLeft;            /*   140    12 */
	class Vector              m_vLowRight;           /*   152    12 */
	class Vector              m_vTopLeft;            /*   164    12 */
	class Vector              m_vColor;              /*   176    12 */
	float                      m_flMass;             /*   188     4 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	class model_s *            m_pTexture;           /*   192     4 */
	float                      m_flBounceFactor;     /*   196     4 */
	char                       m_szClassname[32];    /*   200    32 */
	bool                       m_bInWater;           /*   232     1 */
	bool                       m_bAffectedByForce;   /*   233     1 */

	/* XXX 2 bytes hole, try to pack */

	int                        m_iAfterDampFlags;    /*   236     4 */
protected:

	float                      m_flOriginalSize;     /*   240     4 */
	class Vector              m_vOriginalAngles;     /*   244    12 */
	/* --- cacheline 4 boundary (256 bytes) --- */
	float                      m_flOriginalBrightness; /*   256     4 */
	class Vector              m_vPrevOrigin;         /*   260    12 */
	float                      m_flNextCollisionTime; /*   272     4 */
	void ~CCoreTriangleEffect(class CCoreTriangleEffect *, int); /* linkage=_ZN19CCoreTriangleEffectD4Ev */

	void CCoreTriangleEffect(class CCoreTriangleEffect *, class CCoreTriangleEffect &); /* linkage=_ZN19CCoreTriangleEffectC4EOS_ */

	void CCoreTriangleEffect(class CCoreTriangleEffect *, const class CCoreTriangleEffect  &); /* linkage=_ZN19CCoreTriangleEffectC4ERKS_ */

	void CCoreTriangleEffect(class CCoreTriangleEffect *); /* linkage=_ZN19CCoreTriangleEffectC4Ev */

	void * operator new(size_t); /* linkage=_ZN19CCoreTriangleEffectnwEj */

	virtual void Think(class CCoreTriangleEffect *, float); /* linkage=_ZN19CCoreTriangleEffect5ThinkEf */

	virtual bool CheckVisibility(class CCoreTriangleEffect *); /* linkage=_ZN19CCoreTriangleEffect15CheckVisibilityEv */

	virtual void Draw(class CCoreTriangleEffect *); /* linkage=_ZN19CCoreTriangleEffect4DrawEv */

	virtual void Animate(class CCoreTriangleEffect *, float); /* linkage=_ZN19CCoreTriangleEffect7AnimateEf */

	virtual void AnimateAndDie(class CCoreTriangleEffect *, float); /* linkage=_ZN19CCoreTriangleEffect13AnimateAndDieEf */

	virtual void Expand(class CCoreTriangleEffect *, float); /* linkage=_ZN19CCoreTriangleEffect6ExpandEf */

	virtual void Contract(class CCoreTriangleEffect *, float); /* linkage=_ZN19CCoreTriangleEffect8ContractEf */

	virtual void Fade(class CCoreTriangleEffect *, float); /* linkage=_ZN19CCoreTriangleEffect4FadeEf */

	virtual void Spin(class CCoreTriangleEffect *, float); /* linkage=_ZN19CCoreTriangleEffect4SpinEf */

	virtual void CalculateVelocity(class CCoreTriangleEffect *, float); /* linkage=_ZN19CCoreTriangleEffect17CalculateVelocityEf */

	virtual void CheckCollision(class CCoreTriangleEffect *, float); /* linkage=_ZN19CCoreTriangleEffect14CheckCollisionEf */

	virtual void Touch(class CCoreTriangleEffect *, class Vector, class Vector, int); /* linkage=_ZN19CCoreTriangleEffect5TouchE6VectorS0_i */

	virtual void Die(class CCoreTriangleEffect *); /* linkage=_ZN19CCoreTriangleEffect3DieEv */

	virtual void InitializeSprite(class CCoreTriangleEffect *, class Vector, class Vector, class model_s *, float, float); /* linkage=_ZN19CCoreTriangleEffect16InitializeSpriteE6VectorS0_P7model_sff */

	virtual void Force(class CCoreTriangleEffect *); /* linkage=_ZN19CCoreTriangleEffect5ForceEv */

	void SetLightFlag(class CCoreTriangleEffect *, int); /* linkage=_ZN19CCoreTriangleEffect12SetLightFlagEi */

	void SetCullFlag(class CCoreTriangleEffect *, int); /* linkage=_ZN19CCoreTriangleEffect11SetCullFlagEi */

	int GetRenderFlags(class CCoreTriangleEffect *); /* linkage=_ZN19CCoreTriangleEffect14GetRenderFlagsEv */

	bool GetParticlePVS(class CCoreTriangleEffect *); /* linkage=_ZN19CCoreTriangleEffect14GetParticlePVSEv */

	void SetParticlePVS(class CCoreTriangleEffect *, bool); /* linkage=_ZN19CCoreTriangleEffect14SetParticlePVSEb */

	float GetNextPVSCheck(class CCoreTriangleEffect *); /* linkage=_ZN19CCoreTriangleEffect15GetNextPVSCheckEv */

	void SetNextPVSCheck(class CCoreTriangleEffect *, float); /* linkage=_ZN19CCoreTriangleEffect15SetNextPVSCheckEf */

	void SetCollisionFlags(class CCoreTriangleEffect *, int); /* linkage=_ZN19CCoreTriangleEffect17SetCollisionFlagsEi */

	void ClearCollisionFlags(class CCoreTriangleEffect *, int); /* linkage=_ZN19CCoreTriangleEffect19ClearCollisionFlagsEi */

	int GetCollisionFlags(class CCoreTriangleEffect *); /* linkage=_ZN19CCoreTriangleEffect17GetCollisionFlagsEv */

	void SetRenderFlag(class CCoreTriangleEffect *, int); /* linkage=_ZN19CCoreTriangleEffect13SetRenderFlagEi */

	float GetPlayerDistance(class CCoreTriangleEffect *); /* linkage=_ZN19CCoreTriangleEffect17GetPlayerDistanceEv */

	void SetPlayerDistance(class CCoreTriangleEffect *, float); /* linkage=_ZN19CCoreTriangleEffect17SetPlayerDistanceEf */

	bool CheckSize(int); /* linkage=_ZN19CCoreTriangleEffect9CheckSizeEi */

	/* vtable has 15 entries: {
	   [0] = Think(_ZN19CCoreTriangleEffect5ThinkEf), 
	   [1] = CheckVisibility(_ZN19CCoreTriangleEffect15CheckVisibilityEv), 
	   [2] = Draw(_ZN19CCoreTriangleEffect4DrawEv), 
	   [3] = Animate(_ZN19CCoreTriangleEffect7AnimateEf), 
	   [4] = AnimateAndDie(_ZN19CCoreTriangleEffect13AnimateAndDieEf), 
	   [5] = Expand(_ZN19CCoreTriangleEffect6ExpandEf), 
	   [6] = Contract(_ZN19CCoreTriangleEffect8ContractEf), 
	   [7] = Fade(_ZN19CCoreTriangleEffect4FadeEf), 
	   [8] = Spin(_ZN19CCoreTriangleEffect4SpinEf), 
	   [9] = CalculateVelocity(_ZN19CCoreTriangleEffect17CalculateVelocityEf), 
	   [10] = CheckCollision(_ZN19CCoreTriangleEffect14CheckCollisionEf), 
	   [11] = Touch(_ZN19CCoreTriangleEffect5TouchE6VectorS0_i), 
	   [12] = Die(_ZN19CCoreTriangleEffect3DieEv), 
	   [13] = InitializeSprite(_ZN19CCoreTriangleEffect16InitializeSpriteE6VectorS0_P7model_sff), 
	   [14] = Force(_ZN19CCoreTriangleEffect5ForceEv), 
	} */
	/* size: 276, cachelines: 5, members: 43 */
	/* sum members: 271, holes: 2, sum holes: 5 */
	/* last cacheline: 20 bytes */
};
struct eventnode_s {
	event_args_t *             data;                 /*     0     4 */
	class eventnode_s *        prev;                 /*     4     4 */
	class eventnode_s *        next;                 /*     8     4 */

	/* size: 12, cachelines: 1, members: 3 */
	/* last cacheline: 12 bytes */
};
class CBaseParticle : public CCoreTriangleEffect {
public:

	/* class CCoreTriangleEffect <ancestor>; */      /*     0   276 */

	/* XXX last struct has 2 holes */
	void CBaseParticle(class CBaseParticle *, class CBaseParticle &); /* linkage=_ZN13CBaseParticleC4EOS_ */

	void CBaseParticle(class CBaseParticle *, const class CBaseParticle  &); /* linkage=_ZN13CBaseParticleC4ERKS_ */

	void CBaseParticle(class CBaseParticle *); /* linkage=_ZN13CBaseParticleC4Ev */

	virtual void Think(class CBaseParticle *, float); /* linkage=_ZN13CBaseParticle5ThinkEf */

	virtual void Draw(class CBaseParticle *); /* linkage=_ZN13CBaseParticle4DrawEv */

	virtual void Animate(class CBaseParticle *, float); /* linkage=_ZN13CBaseParticle7AnimateEf */

	virtual void AnimateAndDie(class CBaseParticle *, float); /* linkage=_ZN13CBaseParticle13AnimateAndDieEf */

	virtual void Expand(class CBaseParticle *, float); /* linkage=_ZN13CBaseParticle6ExpandEf */

	virtual void Contract(class CBaseParticle *, float); /* linkage=_ZN13CBaseParticle8ContractEf */

	virtual void Fade(class CBaseParticle *, float); /* linkage=_ZN13CBaseParticle4FadeEf */

	virtual void Spin(class CBaseParticle *, float); /* linkage=_ZN13CBaseParticle4SpinEf */

	virtual void CalculateVelocity(class CBaseParticle *, float); /* linkage=_ZN13CBaseParticle17CalculateVelocityEf */

	virtual void CheckCollision(class CBaseParticle *, float); /* linkage=_ZN13CBaseParticle14CheckCollisionEf */

	virtual void Touch(class CBaseParticle *, class Vector, class Vector, int); /* linkage=_ZN13CBaseParticle5TouchE6VectorS0_i */

	virtual void Die(class CBaseParticle *); /* linkage=_ZN13CBaseParticle3DieEv */

	virtual void Force(class CBaseParticle *); /* linkage=_ZN13CBaseParticle5ForceEv */

	virtual bool CheckVisibility(class CBaseParticle *); /* linkage=_ZN13CBaseParticle15CheckVisibilityEv */

	virtual void InitializeSprite(class CBaseParticle *, class Vector, class Vector, class model_s *, float, float); /* linkage=_ZN13CBaseParticle16InitializeSpriteE6VectorS0_P7model_sff */

	void * operator new(size_t); /* linkage=_ZN13CBaseParticlenwEj */

	void * operator new(size_t, const class nothrow_t  &); /* linkage=_ZN13CBaseParticlenwEjRKSt9nothrow_t */

	/* vtable has 15 entries: {
	   [0] = Think(_ZN13CBaseParticle5ThinkEf), 
	   [2] = Draw(_ZN13CBaseParticle4DrawEv), 
	   [3] = Animate(_ZN13CBaseParticle7AnimateEf), 
	   [4] = AnimateAndDie(_ZN13CBaseParticle13AnimateAndDieEf), 
	   [5] = Expand(_ZN13CBaseParticle6ExpandEf), 
	   [6] = Contract(_ZN13CBaseParticle8ContractEf), 
	   [7] = Fade(_ZN13CBaseParticle4FadeEf), 
	   [8] = Spin(_ZN13CBaseParticle4SpinEf), 
	   [9] = CalculateVelocity(_ZN13CBaseParticle17CalculateVelocityEf), 
	   [10] = CheckCollision(_ZN13CBaseParticle14CheckCollisionEf), 
	   [11] = Touch(_ZN13CBaseParticle5TouchE6VectorS0_i), 
	   [12] = Die(_ZN13CBaseParticle3DieEv), 
	   [14] = Force(_ZN13CBaseParticle5ForceEv), 
	   [1] = CheckVisibility(_ZN13CBaseParticle15CheckVisibilityEv), 
	   [13] = InitializeSprite(_ZN13CBaseParticle16InitializeSpriteE6VectorS0_P7model_sff), 
	} */
	/* size: 276, cachelines: 5, members: 1 */
	/* member types with holes: 1, total: 2 */
	/* last cacheline: 20 bytes */
};
class IParticleMan : public IBaseInterface {
public:

	/* class IBaseInterface      <ancestor>; */      /*     0     4 */
	void IParticleMan(class IParticleMan *); /* linkage=_ZN12IParticleManC4Ev */

protected:

	virtual void ~IParticleMan(class IParticleMan *, int); /* linkage=_ZN12IParticleManD4Ev */

	virtual void SetUp(class IParticleMan *, cl_enginefunc_t *); /* linkage=_ZN12IParticleMan5SetUpEP16cl_enginefuncs_s */

	virtual void Update(class IParticleMan *); /* linkage=_ZN12IParticleMan6UpdateEv */

	virtual void SetVariables(class IParticleMan *, float, class Vector); /* linkage=_ZN12IParticleMan12SetVariablesEf6Vector */

	virtual void ResetParticles(class IParticleMan *); /* linkage=_ZN12IParticleMan14ResetParticlesEv */

	virtual void ApplyForce(class IParticleMan *, class Vector, class Vector, float, float, float); /* linkage=_ZN12IParticleMan10ApplyForceE6VectorS0_fff */

	virtual void AddCustomParticleClassSize(class IParticleMan *, long unsigned int); /* linkage=_ZN12IParticleMan26AddCustomParticleClassSizeEm */

	virtual class CBaseParticle * CreateParticle(class IParticleMan *, class Vector, class Vector, class model_s *, float, float, const char  *); /* linkage=_ZN12IParticleMan14CreateParticleE6VectorS0_P7model_sffPKc */

	virtual char * RequestNewMemBlock(class IParticleMan *, int); /* linkage=_ZN12IParticleMan18RequestNewMemBlockEi */

	virtual void CoreInitializeSprite(class IParticleMan *, class CCoreTriangleEffect *, class Vector, class Vector, class model_s *, float, float); /* linkage=_ZN12IParticleMan20CoreInitializeSpriteEP19CCoreTriangleEffect6VectorS2_P7model_sff */

	virtual void CoreThink(class IParticleMan *, class CCoreTriangleEffect *, float); /* linkage=_ZN12IParticleMan9CoreThinkEP19CCoreTriangleEffectf */

	virtual void CoreDraw(class IParticleMan *, class CCoreTriangleEffect *); /* linkage=_ZN12IParticleMan8CoreDrawEP19CCoreTriangleEffect */

	virtual void CoreAnimate(class IParticleMan *, class CCoreTriangleEffect *, float); /* linkage=_ZN12IParticleMan11CoreAnimateEP19CCoreTriangleEffectf */

	virtual void CoreAnimateAndDie(class IParticleMan *, class CCoreTriangleEffect *, float); /* linkage=_ZN12IParticleMan17CoreAnimateAndDieEP19CCoreTriangleEffectf */

	virtual void CoreExpand(class IParticleMan *, class CCoreTriangleEffect *, float); /* linkage=_ZN12IParticleMan10CoreExpandEP19CCoreTriangleEffectf */

	virtual void CoreContract(class IParticleMan *, class CCoreTriangleEffect *, float); /* linkage=_ZN12IParticleMan12CoreContractEP19CCoreTriangleEffectf */

	virtual void CoreFade(class IParticleMan *, class CCoreTriangleEffect *, float); /* linkage=_ZN12IParticleMan8CoreFadeEP19CCoreTriangleEffectf */

	virtual void CoreSpin(class IParticleMan *, class CCoreTriangleEffect *, float); /* linkage=_ZN12IParticleMan8CoreSpinEP19CCoreTriangleEffectf */

	virtual void CoreCalculateVelocity(class IParticleMan *, class CCoreTriangleEffect *, float); /* linkage=_ZN12IParticleMan21CoreCalculateVelocityEP19CCoreTriangleEffectf */

	virtual void CoreCheckCollision(class IParticleMan *, class CCoreTriangleEffect *, float); /* linkage=_ZN12IParticleMan18CoreCheckCollisionEP19CCoreTriangleEffectf */

	virtual void CoreTouch(class IParticleMan *, class CCoreTriangleEffect *, class Vector, class Vector, int); /* linkage=_ZN12IParticleMan9CoreTouchEP19CCoreTriangleEffect6VectorS2_i */

	virtual void CoreDie(class IParticleMan *, class CCoreTriangleEffect *); /* linkage=_ZN12IParticleMan7CoreDieEP19CCoreTriangleEffect */

	virtual void CoreForce(class IParticleMan *, class CCoreTriangleEffect *); /* linkage=_ZN12IParticleMan9CoreForceEP19CCoreTriangleEffect */

	virtual bool CoreCheckVisibility(class IParticleMan *, class CCoreTriangleEffect *); /* linkage=_ZN12IParticleMan19CoreCheckVisibilityEP19CCoreTriangleEffect */

	virtual void SetRender(class IParticleMan *, int); /* linkage=_ZN12IParticleMan9SetRenderEi */

	/* vtable has 24 entries: {
	   [2] = SetUp(_ZN12IParticleMan5SetUpEP16cl_enginefuncs_s), 
	   [3] = Update(_ZN12IParticleMan6UpdateEv), 
	   [4] = SetVariables(_ZN12IParticleMan12SetVariablesEf6Vector), 
	   [5] = ResetParticles(_ZN12IParticleMan14ResetParticlesEv), 
	   [6] = ApplyForce(_ZN12IParticleMan10ApplyForceE6VectorS0_fff), 
	   [7] = AddCustomParticleClassSize(_ZN12IParticleMan26AddCustomParticleClassSizeEm), 
	   [8] = CreateParticle(_ZN12IParticleMan14CreateParticleE6VectorS0_P7model_sffPKc), 
	   [9] = RequestNewMemBlock(_ZN12IParticleMan18RequestNewMemBlockEi), 
	   [10] = CoreInitializeSprite(_ZN12IParticleMan20CoreInitializeSpriteEP19CCoreTriangleEffect6VectorS2_P7model_sff), 
	   [11] = CoreThink(_ZN12IParticleMan9CoreThinkEP19CCoreTriangleEffectf), 
	   [12] = CoreDraw(_ZN12IParticleMan8CoreDrawEP19CCoreTriangleEffect), 
	   [13] = CoreAnimate(_ZN12IParticleMan11CoreAnimateEP19CCoreTriangleEffectf), 
	   [14] = CoreAnimateAndDie(_ZN12IParticleMan17CoreAnimateAndDieEP19CCoreTriangleEffectf), 
	   [15] = CoreExpand(_ZN12IParticleMan10CoreExpandEP19CCoreTriangleEffectf), 
	   [16] = CoreContract(_ZN12IParticleMan12CoreContractEP19CCoreTriangleEffectf), 
	   [17] = CoreFade(_ZN12IParticleMan8CoreFadeEP19CCoreTriangleEffectf), 
	   [18] = CoreSpin(_ZN12IParticleMan8CoreSpinEP19CCoreTriangleEffectf), 
	   [19] = CoreCalculateVelocity(_ZN12IParticleMan21CoreCalculateVelocityEP19CCoreTriangleEffectf), 
	   [20] = CoreCheckCollision(_ZN12IParticleMan18CoreCheckCollisionEP19CCoreTriangleEffectf), 
	   [21] = CoreTouch(_ZN12IParticleMan9CoreTouchEP19CCoreTriangleEffect6VectorS2_i), 
	   [22] = CoreDie(_ZN12IParticleMan7CoreDieEP19CCoreTriangleEffect), 
	   [23] = CoreForce(_ZN12IParticleMan9CoreForceEP19CCoreTriangleEffect), 
	   [24] = CoreCheckVisibility(_ZN12IParticleMan19CoreCheckVisibilityEP19CCoreTriangleEffect), 
	   [25] = SetRender(_ZN12IParticleMan9SetRenderEi), 
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
struct model_s {
	char                       name[64];             /*     0    64 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	qboolean                   needload;             /*    64     4 */
	modtype_t                  type;                 /*    68     4 */
	int                        numframes;            /*    72     4 */
	synctype_t                 synctype;             /*    76     4 */
	int                        flags;                /*    80     4 */
	class Vector              mins;                  /*    84    12 */
	class Vector              maxs;                  /*    96    12 */
	float                      radius;               /*   108     4 */
	int                        firstmodelsurface;    /*   112     4 */
	int                        nummodelsurfaces;     /*   116     4 */
	int                        numsubmodels;         /*   120     4 */
	dmodel_t *                 submodels;            /*   124     4 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	int                        numplanes;            /*   128     4 */
	mplane_t *                 planes;               /*   132     4 */
	int                        numleafs;             /*   136     4 */
	class mleaf_s *            leafs;                /*   140     4 */
	int                        numvertexes;          /*   144     4 */
	struct {
		class Vector position;           /*     0    12 */
		void (class  *);

	} * vertexes; /*   148     4 */
	int                        numedges;             /*   152     4 */
	medge_t *                  edges;                /*   156     4 */
	int                        numnodes;             /*   160     4 */
	mnode_t *                  nodes;                /*   164     4 */
	int                        numtexinfo;           /*   168     4 */
	mtexinfo_t *               texinfo;              /*   172     4 */
	int                        numsurfaces;          /*   176     4 */
	msurface_t *               surfaces;             /*   180     4 */
	int                        numsurfedges;         /*   184     4 */
	int *                      surfedges;            /*   188     4 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	int                        numclipnodes;         /*   192     4 */
	dclipnode_t *              clipnodes;            /*   196     4 */
	int                        nummarksurfaces;      /*   200     4 */
	msurface_t * *             marksurfaces;         /*   204     4 */
	hull_t                     hulls[4];             /*   208   160 */
	/* --- cacheline 5 boundary (320 bytes) was 48 bytes ago --- */
	int                        numtextures;          /*   368     4 */
	texture_t * *              textures;             /*   372     4 */
	byte *                     visdata;              /*   376     4 */
	color24 *                  lightdata;            /*   380     4 */
	/* --- cacheline 6 boundary (384 bytes) --- */
	char *                     entities;             /*   384     4 */
	cache_user_t               cache;                /*   388     4 */
	void model_s(class model_s *); /* linkage=_ZN7model_sC4Ev */


	/* size: 392, cachelines: 7, members: 40 */
	/* last cacheline: 8 bytes */
};
struct mleaf_s {
	int                        contents;             /*     0     4 */
	int                        visframe;             /*     4     4 */
	short int                  minmaxs[6];           /*     8    12 */
	class mnode_s *            parent;               /*    20     4 */
	byte *                     compressed_vis;       /*    24     4 */
	class efrag_s *            efrags;               /*    28     4 */
	msurface_t * *             firstmarksurface;     /*    32     4 */
	int                        nummarksurfaces;      /*    36     4 */
	int                        key;                  /*    40     4 */
	byte                       ambient_sound_level[4]; /*    44     4 */

	/* size: 48, cachelines: 1, members: 10 */
	/* last cacheline: 48 bytes */
};
struct mnode_s {
	int                        contents;             /*     0     4 */
	int                        visframe;             /*     4     4 */
	short int                  minmaxs[6];           /*     8    12 */
	class mnode_s *            parent;               /*    20     4 */
	mplane_t *                 plane;                /*    24     4 */
	class mnode_s *            children[2];          /*    28     8 */
	short unsigned int         firstsurface;         /*    36     2 */
	short unsigned int         numsurfaces;          /*    38     2 */

	/* size: 40, cachelines: 1, members: 8 */
	/* last cacheline: 40 bytes */
};
struct client_data_s {
	class Vector              origin;                /*     0    12 */
	class Vector              viewangles;            /*    12    12 */
	int                        iWeaponBits;          /*    24     4 */
	float                      fov;                  /*    28     4 */
	void client_data_s(class client_data_s *); /* linkage=_ZN13client_data_sC4Ev */


	/* size: 32, cachelines: 1, members: 4 */
	/* last cacheline: 32 bytes */
};
struct triangleapi_s {
	int                        version;              /*     0     4 */
	void                       (*RenderMode)(int);   /*     4     4 */
	void                       (*Begin)(int);        /*     8     4 */
	void                       (*End)(void);         /*    12     4 */
	void                       (*Color4f)(float, float, float, float); /*    16     4 */
	void                       (*Color4ub)(unsigned char, unsigned char, unsigned char, unsigned char); /*    20     4 */
	void                       (*TexCoord2f)(float, float); /*    24     4 */
	void                       (*Vertex3fv)(float *); /*    28     4 */
	void                       (*Vertex3f)(float, float, float); /*    32     4 */
	void                       (*Brightness)(float); /*    36     4 */
	void                       (*CullFace)(TRICULLSTYLE); /*    40     4 */
	int                        (*SpriteTexture)(class model_s *, int); /*    44     4 */
	int                        (*WorldToScreen)(float *, float *); /*    48     4 */
	void                       (*Fog)(float *, float, float, int); /*    52     4 */
	void                       (*ScreenToWorld)(float *, float *); /*    56     4 */
	void                       (*GetMatrix)(int, float *); /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	int                        (*BoxInPVS)(float *, float *); /*    64     4 */
	void                       (*LightAtPoint)(float *, float *); /*    68     4 */
	void                       (*Color4fRendermode)(float, float, float, float, int); /*    72     4 */
	void                       (*FogParams)(float, int); /*    76     4 */

	/* size: 80, cachelines: 2, members: 20 */
	/* last cacheline: 16 bytes */
};
struct demo_api_s {
	int                        (*IsRecording)(void); /*     0     4 */
	int                        (*IsPlayingback)(void); /*     4     4 */
	int                        (*IsTimeDemo)(void);  /*     8     4 */
	void                       (*WriteBuffer)(int, unsigned char *); /*    12     4 */

	/* size: 16, cachelines: 1, members: 4 */
	/* last cacheline: 16 bytes */
};
struct HUDLIST {
	class CHudBase *           p;                    /*     0     4 */
	class HUDLIST *            pNext;                /*     4     4 */

	/* size: 8, cachelines: 1, members: 2 */
	/* last cacheline: 8 bytes */
};
class CHudBase {
	int ()(void) * *           _vptr.CHudBase;       /*     0     4 */
	POSITION                   m_pos;                /*     4     8 */
	int                        m_type;               /*    12     4 */
	int                        m_iFlags;             /*    16     4 */
	void CHudBase(class CHudBase *, const class CHudBase  &); /* linkage=_ZN8CHudBaseC4ERKS_ */

	void CHudBase(class CHudBase *); /* linkage=_ZN8CHudBaseC4Ev */

	virtual void ~CHudBase(class CHudBase *, int); /* linkage=_ZN8CHudBaseD4Ev */

	virtual int Init(class CHudBase *); /* linkage=_ZN8CHudBase4InitEv */

	virtual int VidInit(class CHudBase *); /* linkage=_ZN8CHudBase7VidInitEv */

	virtual int Draw(class CHudBase *, float); /* linkage=_ZN8CHudBase4DrawEf */

	virtual void Think(class CHudBase *); /* linkage=_ZN8CHudBase5ThinkEv */

	virtual void Reset(class CHudBase *); /* linkage=_ZN8CHudBase5ResetEv */

	virtual void InitHUDData(class CHudBase *); /* linkage=_ZN8CHudBase11InitHUDDataEv */

	/* vtable has 6 entries: {
	   [2] = Init(_ZN8CHudBase4InitEv), 
	   [3] = VidInit(_ZN8CHudBase7VidInitEv), 
	   [4] = Draw(_ZN8CHudBase4DrawEf), 
	   [5] = Think(_ZN8CHudBase5ThinkEv), 
	   [6] = Reset(_ZN8CHudBase5ResetEv), 
	   [7] = InitHUDData(_ZN8CHudBase11InitHUDDataEv), 
	} */
	/* size: 20, cachelines: 1, members: 4 */
	/* last cacheline: 20 bytes */
};
struct overviewInfo_s {
	char                       map[64];              /*     0    64 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	class Vector              origin;                /*    64    12 */
	float                      zoom;                 /*    76     4 */
	int                        layers;               /*    80     4 */
	float                      layersHeights[1];     /*    84     4 */
	char                       layersImages[1][255]; /*    88   255 */

	/* XXX 1 byte hole, try to pack */

	/* --- cacheline 5 boundary (320 bytes) was 24 bytes ago --- */
	qboolean                   rotated;              /*   344     4 */
	int                        insetWindowX;         /*   348     4 */
	int                        insetWindowY;         /*   352     4 */
	int                        insetWindowHeight;    /*   356     4 */
	int                        insetWindowWidth;     /*   360     4 */
	void overviewInfo_s(class overviewInfo_s *); /* linkage=_ZN14overviewInfo_sC4Ev */


	/* size: 364, cachelines: 6, members: 11 */
	/* sum members: 363, holes: 1, sum holes: 1 */
	/* last cacheline: 44 bytes */
};
struct overviewEntity_s {
	HANDLE_SPRITE              hSprite;              /*     0     4 */
	class cl_entity_s *        entity;               /*     4     4 */
	double                     killTime;             /*     8     8 */

	/* size: 16, cachelines: 1, members: 3 */
	/* last cacheline: 16 bytes */
};
struct cameraWayPoint_s {
	float                      time;                 /*     0     4 */
	class Vector              position;              /*     4    12 */
	class Vector              angle;                 /*    16    12 */
	float                      fov;                  /*    28     4 */
	int                        flags;                /*    32     4 */
	void cameraWayPoint_s(class cameraWayPoint_s *); /* linkage=_ZN16cameraWayPoint_sC4Ev */


	/* size: 36, cachelines: 1, members: 5 */
	/* last cacheline: 36 bytes */
};
struct extra_player_info_t {
	short int                  frags;                /*     0     2 */
	short int                  deaths;               /*     2     2 */
	short int                  playerclass;          /*     4     2 */
	short int                  health;               /*     6     2 */
	bool                       dead;                 /*     8     1 */

	/* XXX 1 byte hole, try to pack */

	short int                  teamnumber;           /*    10     2 */
	char                       teamname[16];         /*    12    16 */

	/* size: 28, cachelines: 1, members: 7 */
	/* sum members: 27, holes: 1, sum holes: 1 */
	/* last cacheline: 28 bytes */
};
class CHud {
private:

	class HUDLIST *            m_pHudList;           /*     0     4 */
	HANDLE_SPRITE              m_hsprLogo;           /*     4     4 */
	int                        m_iLogo;              /*     8     4 */
	client_sprite_t *          m_pSpriteList;        /*    12     4 */
	int                        m_iSpriteCount;       /*    16     4 */
	int                        m_iSpriteCountAllRes; /*    20     4 */
	float                      m_flMouseSensitivity; /*    24     4 */
	int                        m_iConcussionEffect;  /*    28     4 */
	HANDLE_SPRITE              m_hsprCursor;         /*    32     4 */
	float                      m_flTime;             /*    36     4 */
	float                      m_fOldTime;           /*    40     4 */
	double                     m_flTimeDelta;        /*    44     8 */
	class Vector              m_vecOrigin;           /*    52    12 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	class Vector              m_vecAngles;           /*    64    12 */
	int                        m_iKeyBits;           /*    76     4 */
	int                        m_iHideHUDDisplay;    /*    80     4 */
	int                        m_iFOV;               /*    84     4 */
	int                        m_Teamplay;           /*    88     4 */
	int                        m_iRes;               /*    92     4 */
	cvar_t *                   m_pCvarStealMouse;    /*    96     4 */
	cvar_t *                   m_pCvarDraw;          /*   100     4 */
	int                        m_iFontHeight;        /*   104     4 */
	HANDLE_SPRITE *            m_rghSprites;         /*   108     4 */
	wrect_t *                  m_rgrcRects;          /*   112     4 */
	char *                     m_rgszSpriteNames;    /*   116     4 */
	class cvar_s *             default_fov;          /*   120     4 */
	class CHudAmmo            m_Ammo;                /*   124     0 */

	/* XXX 40 bytes hole, try to pack */

	/* --- cacheline 2 boundary (128 bytes) was 36 bytes ago --- */
	class CHudHealth          m_Health;              /*   164     0 */

	/* XXX 256 bytes hole, try to pack */

	/* --- cacheline 6 boundary (384 bytes) was 36 bytes ago --- */
	class CHudSpectator       m_Spectator;           /*   420  5980 */

	/* XXX last struct has 1 hole */

	/* --- cacheline 100 boundary (6400 bytes) --- */
	class CHudGeiger          m_Geiger;              /*  6400     0 */

	/* XXX 24 bytes hole, try to pack */

	class CHudBattery         m_Battery;             /*  6424     0 */

	/* XXX 52 bytes hole, try to pack */

	/* --- cacheline 101 boundary (6464 bytes) was 12 bytes ago --- */
	class CHudTrain           m_Train;               /*  6476     0 */

	/* XXX 28 bytes hole, try to pack */

	class CHudFlashlight      m_Flash;               /*  6504     0 */

	/* XXX 64 bytes hole, try to pack */

	/* --- cacheline 102 boundary (6528 bytes) was 40 bytes ago --- */
	class CHudMessage         m_Message;             /*  6568     0 */

	/* XXX 236 bytes hole, try to pack */

	/* --- cacheline 106 boundary (6784 bytes) was 20 bytes ago --- */
	class CHudStatusBar       m_StatusBar;           /*  6804     0 */

	/* XXX 836 bytes hole, try to pack */

	/* --- cacheline 119 boundary (7616 bytes) was 24 bytes ago --- */
	class CHudDeathNotice     m_DeathNotice;         /*  7640     0 */

	/* XXX 24 bytes hole, try to pack */

	class CHudSayText         m_SayText;             /*  7664     0 */

	/* XXX 28 bytes hole, try to pack */

	/* --- cacheline 120 boundary (7680 bytes) was 12 bytes ago --- */
	class CHudMenu            m_Menu;                /*  7692     0 */

	/* XXX 36 bytes hole, try to pack */

	class CHudAmmoSecondary   m_AmmoSecondary;       /*  7728     0 */

	/* XXX 44 bytes hole, try to pack */

	/* --- cacheline 121 boundary (7744 bytes) was 28 bytes ago --- */
	class CHudTextMessage     m_TextMessage;         /*  7772     0 */

	/* XXX 20 bytes hole, try to pack */

	class CHudStatusIcons     m_StatusIcons;         /*  7792     0 */

	/* XXX 212 bytes hole, try to pack */

	/* --- cacheline 125 boundary (8000 bytes) was 4 bytes ago --- */
	class CHudBenchmark       m_Benchmark;           /*  8004     0 */

	/* XXX 88 bytes hole, try to pack */

	/* --- cacheline 126 boundary (8064 bytes) was 28 bytes ago --- */
	SCREENINFO                 m_scrinfo;            /*  8092   532 */
	/* --- cacheline 134 boundary (8576 bytes) was 48 bytes ago --- */
	int                        m_iWeaponBits;        /*  8624     4 */
	int                        m_fPlayerDead;        /*  8628     4 */
	int                        m_iIntermission;      /*  8632     4 */
	int                        m_HUD_number_0;       /*  8636     4 */
	int DrawHudNumber(class CHud *, int, int, int, int, int, int, int); /* linkage=_ZN4CHud13DrawHudNumberEiiiiiii */

	int DrawHudString(class CHud *, int, int, int, char *, int, int, int); /* linkage=_ZN4CHud13DrawHudStringEiiiPciii */

	int DrawHudStringReverse(class CHud *, int, int, int, char *, int, int, int); /* linkage=_ZN4CHud20DrawHudStringReverseEiiiPciii */

	int DrawHudNumberString(class CHud *, int, int, int, int, int, int, int); /* linkage=_ZN4CHud19DrawHudNumberStringEiiiiiii */

	int GetNumWidth(class CHud *, int, int); /* linkage=_ZN4CHud11GetNumWidthEii */

	HANDLE_SPRITE GetSprite(class CHud *, int); /* linkage=_ZN4CHud9GetSpriteEi */

	wrect_t & GetSpriteRect(class CHud *, int); /* linkage=_ZN4CHud13GetSpriteRectEi */

	int GetSpriteIndex(class CHud *, const char  *); /* linkage=_ZN4CHud14GetSpriteIndexEPKc */

	void Init(class CHud *); /* linkage=_ZN4CHud4InitEv */

	void VidInit(class CHud *); /* linkage=_ZN4CHud7VidInitEv */

	void Think(class CHud *); /* linkage=_ZN4CHud5ThinkEv */

	int Redraw(class CHud *, float, int); /* linkage=_ZN4CHud6RedrawEfi */

	int UpdateClientData(class CHud *, client_data_t *, float); /* linkage=_ZN4CHud16UpdateClientDataEP13client_data_sf */

	void CHud(class CHud *); /* linkage=_ZN4CHudC4Ev */

	void ~CHud(class CHud *, int); /* linkage=_ZN4CHudD4Ev */

	int MsgFunc_Damage(class CHud *, const char  *, int, void *); /* linkage=_ZN4CHud14MsgFunc_DamageEPKciPv */

	int MsgFunc_GameMode(class CHud *, const char  *, int, void *); /* linkage=_ZN4CHud16MsgFunc_GameModeEPKciPv */

	int MsgFunc_Logo(class CHud *, const char  *, int, void *); /* linkage=_ZN4CHud12MsgFunc_LogoEPKciPv */

	int MsgFunc_ResetHUD(class CHud *, const char  *, int, void *); /* linkage=_ZN4CHud16MsgFunc_ResetHUDEPKciPv */

	void MsgFunc_InitHUD(class CHud *, const char  *, int, void *); /* linkage=_ZN4CHud15MsgFunc_InitHUDEPKciPv */

	void MsgFunc_ViewMode(class CHud *, const char  *, int, void *); /* linkage=_ZN4CHud16MsgFunc_ViewModeEPKciPv */

	int MsgFunc_SetFOV(class CHud *, const char  *, int, void *); /* linkage=_ZN4CHud14MsgFunc_SetFOVEPKciPv */

	int MsgFunc_Concuss(class CHud *, const char  *, int, void *); /* linkage=_ZN4CHud15MsgFunc_ConcussEPKciPv */

	void AddHudElem(class CHud *, class CHudBase *); /* linkage=_ZN4CHud10AddHudElemEP8CHudBase */

	float GetSensitivity(class CHud *); /* linkage=_ZN4CHud14GetSensitivityEv */


	/* size: 8640, cachelines: 135, members: 47 */
	/* sum members: 6652, holes: 15, sum holes: 1988 */
	/* member types with holes: 1, total: 1 */
};
class CHudSpectator : public CHudBase {
public:

	/* class CHudBase            <ancestor>; */      /*     0    20 */
	int                        m_iDrawCycle;         /*    20     4 */
	client_textmessage_t       m_HUDMessages[8];     /*    24   352 */
	/* --- cacheline 5 boundary (320 bytes) was 56 bytes ago --- */
	char                       m_HUDMessageText[8][128]; /*   376  1024 */
	/* --- cacheline 21 boundary (1344 bytes) was 56 bytes ago --- */
	int                        m_lastHudMessage;     /*  1400     4 */
	overviewInfo_t             m_OverviewData;       /*  1404   364 */
	/* --- cacheline 27 boundary (1728 bytes) was 40 bytes ago --- */
	overviewEntity_t           m_OverviewEntities[128]; /*  1768  2048 */
	/* --- cacheline 59 boundary (3776 bytes) was 40 bytes ago --- */
	int                        m_iObserverFlags;     /*  3816     4 */
	int                        m_iSpectatorNumber;   /*  3820     4 */
	float                      m_mapZoom;            /*  3824     4 */
	class Vector              m_mapOrigin;           /*  3828    12 */
	/* --- cacheline 60 boundary (3840 bytes) --- */
	cvar_t *                   m_drawnames;          /*  3840     4 */
	cvar_t *                   m_drawcone;           /*  3844     4 */
	cvar_t *                   m_drawstatus;         /*  3848     4 */
	cvar_t *                   m_autoDirector;       /*  3852     4 */
	cvar_t *                   m_pip;                /*  3856     4 */
	qboolean                   m_chatEnabled;        /*  3860     4 */
	qboolean                   m_IsInterpolating;    /*  3864     4 */
	int                        m_ChaseEntity;        /*  3868     4 */
	int                        m_WayPoint;           /*  3872     4 */
	int                        m_NumWayPoints;       /*  3876     4 */
	class Vector              m_cameraOrigin;        /*  3880    12 */
	class Vector              m_cameraAngles;        /*  3892    12 */
	/* --- cacheline 61 boundary (3904 bytes) --- */
	class CInterpolation      m_WayInterpolation;    /*  3904     0 */

	/* XXX 76 bytes hole, try to pack */
private:


	/* --- cacheline 62 boundary (3968 bytes) was 12 bytes ago --- */
	class Vector              m_vPlayerPos[64];      /*  3980   768 */
	/* --- cacheline 74 boundary (4736 bytes) was 12 bytes ago --- */
	HANDLE_SPRITE              m_hsprPlayerBlue;     /*  4748     4 */
	HANDLE_SPRITE              m_hsprPlayerRed;      /*  4752     4 */
	HANDLE_SPRITE              m_hsprPlayer;         /*  4756     4 */
	HANDLE_SPRITE              m_hsprCamera;         /*  4760     4 */
	HANDLE_SPRITE              m_hsprPlayerDead;     /*  4764     4 */
	HANDLE_SPRITE              m_hsprViewcone;       /*  4768     4 */
	HANDLE_SPRITE              m_hsprUnkownMap;      /*  4772     4 */
	HANDLE_SPRITE              m_hsprBeam;           /*  4776     4 */
	HANDLE_SPRITE              m_hCrosshair;         /*  4780     4 */
	wrect_t                    m_crosshairRect;      /*  4784    16 */
	/* --- cacheline 75 boundary (4800 bytes) --- */
	class model_s *            m_MapSprite;          /*  4800     4 */
	float                      m_flNextObserverInput; /*  4804     4 */
	float                      m_FOV;                /*  4808     4 */
	float                      m_zoomDelta;          /*  4812     4 */
	float                      m_moveDelta;          /*  4816     4 */
	int                        m_lastPrimaryObject;  /*  4820     4 */
	int                        m_lastSecondaryObject; /*  4824     4 */
	cameraWayPoint_t           m_CamPath[32];        /*  4828  1152 */
	void CHudSpectator(class CHudSpectator *, class CHudSpectator &); /* linkage=_ZN13CHudSpectatorC4EOS_ */

	void CHudSpectator(class CHudSpectator *, const class CHudSpectator  &); /* linkage=_ZN13CHudSpectatorC4ERKS_ */

	void CHudSpectator(class CHudSpectator *); /* linkage=_ZN13CHudSpectatorC4Ev */

	virtual void Reset(class CHudSpectator *); /* linkage=_ZN13CHudSpectator5ResetEv */

	int ToggleInset(class CHudSpectator *, bool); /* linkage=_ZN13CHudSpectator11ToggleInsetEb */

	void CheckSettings(class CHudSpectator *); /* linkage=_ZN13CHudSpectator13CheckSettingsEv */

	virtual void InitHUDData(class CHudSpectator *); /* linkage=_ZN13CHudSpectator11InitHUDDataEv */

	bool AddOverviewEntityToList(class CHudSpectator *, HANDLE_SPRITE, cl_entity_t *, double); /* linkage=_ZN13CHudSpectator23AddOverviewEntityToListEiP11cl_entity_sd */

	void DeathMessage(class CHudSpectator *, int); /* linkage=_ZN13CHudSpectator12DeathMessageEi */

	bool AddOverviewEntity(class CHudSpectator *, int, class cl_entity_s *, const char  *); /* linkage=_ZN13CHudSpectator17AddOverviewEntityEiP11cl_entity_sPKc */

	void CheckOverviewEntities(class CHudSpectator *); /* linkage=_ZN13CHudSpectator21CheckOverviewEntitiesEv */

	void DrawOverview(class CHudSpectator *); /* linkage=_ZN13CHudSpectator12DrawOverviewEv */

	void DrawOverviewEntities(class CHudSpectator *); /* linkage=_ZN13CHudSpectator20DrawOverviewEntitiesEv */

	void GetMapPosition(class CHudSpectator *, float *); /* linkage=_ZN13CHudSpectator14GetMapPositionEPf */

	void DrawOverviewLayer(class CHudSpectator *); /* linkage=_ZN13CHudSpectator17DrawOverviewLayerEv */

	void LoadMapSprites(class CHudSpectator *); /* linkage=_ZN13CHudSpectator14LoadMapSpritesEv */

	bool ParseOverviewFile(class CHudSpectator *); /* linkage=_ZN13CHudSpectator17ParseOverviewFileEv */

	bool IsActivePlayer(class CHudSpectator *, cl_entity_t *); /* linkage=_ZN13CHudSpectator14IsActivePlayerEP11cl_entity_s */

	void SetModes(class CHudSpectator *, int, int); /* linkage=_ZN13CHudSpectator8SetModesEii */

	void HandleButtonsDown(class CHudSpectator *, int); /* linkage=_ZN13CHudSpectator17HandleButtonsDownEi */

	void HandleButtonsUp(class CHudSpectator *, int); /* linkage=_ZN13CHudSpectator15HandleButtonsUpEi */

	void FindNextPlayer(class CHudSpectator *, bool); /* linkage=_ZN13CHudSpectator14FindNextPlayerEb */

	void FindPlayer(class CHudSpectator *, const char  *); /* linkage=_ZN13CHudSpectator10FindPlayerEPKc */

	void DirectorMessage(class CHudSpectator *, int, void *); /* linkage=_ZN13CHudSpectator15DirectorMessageEiPv */

	void SetSpectatorStartPosition(class CHudSpectator *); /* linkage=_ZN13CHudSpectator25SetSpectatorStartPositionEv */

	virtual int Init(class CHudSpectator *); /* linkage=_ZN13CHudSpectator4InitEv */

	virtual int VidInit(class CHudSpectator *); /* linkage=_ZN13CHudSpectator7VidInitEv */

	virtual int Draw(class CHudSpectator *, float); /* linkage=_ZN13CHudSpectator4DrawEf */

	void AddWaypoint(class CHudSpectator *, float, class Vector, class Vector, float, int); /* linkage=_ZN13CHudSpectator11AddWaypointEf6VectorS0_fi */

	void SetCameraView(class CHudSpectator *, class Vector, class Vector, float); /* linkage=_ZN13CHudSpectator13SetCameraViewE6VectorS0_f */

	float GetFOV(class CHudSpectator *); /* linkage=_ZN13CHudSpectator6GetFOVEv */

	bool GetDirectorCamera(class CHudSpectator *, class Vector &, class Vector &); /* linkage=_ZN13CHudSpectator17GetDirectorCameraER6VectorS1_ */

	void SetWayInterpolation(class CHudSpectator *, cameraWayPoint_t *, cameraWayPoint_t *, cameraWayPoint_t *, cameraWayPoint_t *); /* linkage=_ZN13CHudSpectator19SetWayInterpolationEP16cameraWayPoint_sS1_S1_S1_ */

	virtual void ~CHudSpectator(class CHudSpectator *, int); /* linkage=_ZN13CHudSpectatorD4Ev */

	/* vtable has 5 entries: {
	   [6] = Reset(_ZN13CHudSpectator5ResetEv), 
	   [7] = InitHUDData(_ZN13CHudSpectator11InitHUDDataEv), 
	   [2] = Init(_ZN13CHudSpectator4InitEv), 
	   [3] = VidInit(_ZN13CHudSpectator7VidInitEv), 
	   [4] = Draw(_ZN13CHudSpectator4DrawEf), 
	} */
	/* size: 5980, cachelines: 94, members: 43 */
	/* sum members: 5904, holes: 1, sum holes: 76 */
	/* last cacheline: 28 bytes */
} __attribute__((__packed__));
struct hull_s {
	dclipnode_t *              clipnodes;            /*     0     4 */
	mplane_t *                 planes;               /*     4     4 */
	int                        firstclipnode;        /*     8     4 */
	int                        lastclipnode;         /*    12     4 */
	class Vector              clip_mins;             /*    16    12 */
	class Vector              clip_maxs;             /*    28    12 */
	void hull_s(class hull_s *); /* linkage=_ZN6hull_sC4Ev */


	/* size: 40, cachelines: 1, members: 6 */
	/* last cacheline: 40 bytes */
};
struct mplane_s {
	class Vector              normal;                /*     0    12 */
	float                      dist;                 /*    12     4 */
	byte                       type;                 /*    16     1 */
	byte                       signbits;             /*    17     1 */
	byte                       pad[2];               /*    18     2 */
	void mplane_s(class mplane_s *); /* linkage=_ZN8mplane_sC4Ev */


	/* size: 20, cachelines: 1, members: 5 */
	/* last cacheline: 20 bytes */
};
struct texture_s {
	char                       name[16];             /*     0    16 */
	unsigned int               width;                /*    16     4 */
	unsigned int               height;               /*    20     4 */
	int                        anim_total;           /*    24     4 */
	int                        anim_min;             /*    28     4 */
	int                        anim_max;             /*    32     4 */
	class texture_s *          anim_next;            /*    36     4 */
	class texture_s *          alternate_anims;      /*    40     4 */
	unsigned int               offsets[4];           /*    44    16 */
	unsigned int               paloffset;            /*    60     4 */

	/* size: 64, cachelines: 1, members: 10 */
};
struct msurface_s {
	int                        visframe;             /*     0     4 */
	int                        dlightframe;          /*     4     4 */
	int                        dlightbits;           /*     8     4 */
	mplane_t *                 plane;                /*    12     4 */
	int                        flags;                /*    16     4 */
	int                        firstedge;            /*    20     4 */
	int                        numedges;             /*    24     4 */
	class surfcache_s *        cachespots[4];        /*    28    16 */
	short int                  texturemins[2];       /*    44     4 */
	short int                  extents[2];           /*    48     4 */
	mtexinfo_t *               texinfo;              /*    52     4 */
	byte                       styles[4];            /*    56     4 */
	color24 *                  samples;              /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	decal_t *                  pdecals;              /*    64     4 */

	/* size: 68, cachelines: 2, members: 14 */
	/* last cacheline: 4 bytes */
};
struct decal_s {
	decal_t *                  pnext;                /*     0     4 */
	msurface_t *               psurface;             /*     4     4 */
	short int                  dx;                   /*     8     2 */
	short int                  dy;                   /*    10     2 */
	short int                  texture;              /*    12     2 */
	byte                       scale;                /*    14     1 */
	byte                       flags;                /*    15     1 */
	short int                  entityIndex;          /*    16     2 */

	/* size: 20, cachelines: 1, members: 8 */
	/* padding: 2 */
	/* last cacheline: 20 bytes */
};
struct cache_user_s {
	void *                     data;                 /*     0     4 */

	/* size: 4, cachelines: 1, members: 1 */
	/* last cacheline: 4 bytes */
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
struct KeyValueData_s {
	char *                     szClassName;          /*     0     4 */
	char *                     szKeyName;            /*     4     4 */
	char *                     szValue;              /*     8     4 */
	int32                      fHandled;             /*    12     4 */

	/* size: 16, cachelines: 1, members: 4 */
	/* last cacheline: 16 bytes */
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

	virtual void KeyValue(class CBaseEntity *, class KeyValueData_s *); /* linkage=_ZN11CBaseEntity8KeyValueEP14KeyValueData_s */

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

	int IsAlly(class CBaseEntity *, class CBaseEntity *); /* linkage=_ZN11CBaseEntity6IsAllyEPS_ */

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
struct WayPoint_t {
	class Vector              vecLocation;           /*     0    12 */
	int                        iType;                /*    12     4 */
	void WayPoint_t(class WayPoint_t *); /* linkage=_ZN10WayPoint_tC4Ev */


	/* size: 16, cachelines: 1, members: 2 */
	/* last cacheline: 16 bytes */
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
class CBaseMonster : public CBaseToggle {
	enum {
		SCRIPT_PLAYING      = 0,
		SCRIPT_WAIT         = 1,
		SCRIPT_CLEANUP      = 2,
		SCRIPT_WALK_TO_MARK = 3,
		SCRIPT_RUN_TO_MARK  = 4,
	};

public:

	/* class CBaseToggle         <ancestor>; */      /*     0  1300 */

	/* XXX last struct has embedded flexible array(s) */
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

	static TYPEDESCRIPTION            m_SaveData[0]; /*     0     0 */
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
	/* flexible array members: middle: 1 */
	/* last cacheline: 60 bytes */
};
class CGrenade : public CBaseMonster {
	enum {
		SATCHEL_DETONATE = 0,
		SATCHEL_RELEASE  = 1,
	};

public:

	/* class CBaseMonster        <ancestor>; */      /*     0  1724 */

	/* XXX last struct has a flexible array, embedded flexible array(s) */

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

	virtual int setBirthdayModel(class CGrenade *); /* linkage=_ZN8CGrenade16setBirthdayModelEv */

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
	/* padding: 2 */
	/* flexible array members: end: 1, middle: 1 */
	/* last cacheline: 24 bytes */
};
class CBasePlayer : public CBaseMonster {
public:

	/* class CBaseMonster        <ancestor>; */      /*     0  1724 */

	/* XXX last struct has a flexible array, embedded flexible array(s) */

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

	static TYPEDESCRIPTION            m_playerSaveData[0]; /*     0     0 */
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
	/* sum members: 3786, holes: 1, sum holes: 2 */
	/* flexible array members: end: 1, middle: 1 */
	/* last cacheline: 12 bytes */
};
class CCrowbar : public CBasePlayerWeapon {
public:

	/* class CBasePlayerWeapon   <ancestor>; */      /*     0  1268 */

	/* XXX last struct has embedded flexible array(s) */

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
	/* flexible array members: middle: 1 */
	/* last cacheline: 48 bytes */
};
class CBasePlayerWeapon : public CBasePlayerItem {
public:

	/* class CBasePlayerItem     <ancestor>; */      /*     0  1180 */

	/* XXX last struct has embedded flexible array(s) */

	static TYPEDESCRIPTION            m_SaveData[0]; /*     0     0 */
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
	/* flexible array members: middle: 1 */
	/* last cacheline: 52 bytes */
};
class CBasePlayerAmmo : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0  1140 */

	/* XXX last struct has 1 hole */
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
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 52 bytes */
};
class CBasePlayerItem : public CBaseAnimating {
public:

	/* class CBaseAnimating      <ancestor>; */      /*     0  1168 */

	/* XXX last struct has embedded flexible array(s) */

	static TYPEDESCRIPTION            m_SaveData[0]; /*     0     0 */
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
	/* flexible array members: middle: 1 */
	/* last cacheline: 28 bytes */
};
class CBaseAnimating : public CBaseDelay {
public:

	/* class CBaseDelay          <ancestor>; */      /*     0  1148 */

	/* XXX last struct has a flexible array */

	static TYPEDESCRIPTION            m_SaveData[0]; /*     0     0 */
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
	/* flexible array members: end: 1 */
	/* last cacheline: 16 bytes */
};
class CBaseToggle : public CBaseAnimating {
public:

	/* class CBaseAnimating      <ancestor>; */      /*     0  1168 */

	/* XXX last struct has embedded flexible array(s) */

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

	static TYPEDESCRIPTION            m_SaveData[0]; /*     0     0 */
	string_t                   m_sMaster;            /*  1296     4 */
	void CBaseToggle(class CBaseToggle *, class CBaseToggle &); /* linkage=_ZN11CBaseToggleC4EOS_ */

	void CBaseToggle(class CBaseToggle *, const class CBaseToggle  &); /* linkage=_ZN11CBaseToggleC4ERKS_ */

	void CBaseToggle(class CBaseToggle *); /* linkage=_ZN11CBaseToggleC4Ev */

	virtual void KeyValue(class CBaseToggle *, class KeyValueData_s *); /* linkage=_ZN11CBaseToggle8KeyValueEP14KeyValueData_s */

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
	/* flexible array members: middle: 1 */
	/* last cacheline: 20 bytes */
};
class CLaserSpot : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0  1140 */

	/* XXX last struct has 1 hole */
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
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 52 bytes */
};
class CTFRpgRocket : public CGrenade {
public:

	/* class CGrenade            <ancestor>; */      /*     0  1752 */

	/* XXX last struct has embedded flexible array(s), 2 bytes of padding */

	/* --- cacheline 27 boundary (1728 bytes) was 24 bytes ago --- */
	int                        m_iTrail;             /*  1752     4 */
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
	/* paddings: 1, sum paddings: 2 */
	/* flexible array members: middle: 1 */
	/* last cacheline: 28 bytes */
};
class CTFIncendiaryCRocket : public CGrenade {
public:

	/* class CGrenade            <ancestor>; */      /*     0  1752 */

	/* XXX last struct has embedded flexible array(s), 2 bytes of padding */

	/* --- cacheline 27 boundary (1728 bytes) was 24 bytes ago --- */
	int                        m_iTrail;             /*  1752     4 */
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
	/* paddings: 1, sum paddings: 2 */
	/* flexible array members: middle: 1 */
	/* last cacheline: 28 bytes */
};
class CBaseDelay : public CBaseEntity {
public:

	/* class CBaseEntity         <ancestor>; */      /*     0  1140 */

	/* XXX last struct has 1 hole */

	/* --- cacheline 17 boundary (1088 bytes) was 52 bytes ago --- */
	float                      m_flDelay;            /*  1140     4 */
	int                        m_iszKillTarget;      /*  1144     4 */

	/* Bitfield combined with previous fields */

	static TYPEDESCRIPTION            m_SaveData[0]; /*     0     0 */
	void CBaseDelay(class CBaseDelay *, class CBaseDelay &); /* linkage=_ZN10CBaseDelayC4EOS_ */

	void CBaseDelay(class CBaseDelay *, const class CBaseDelay  &); /* linkage=_ZN10CBaseDelayC4ERKS_ */

	void CBaseDelay(class CBaseDelay *); /* linkage=_ZN10CBaseDelayC4Ev */

	virtual void KeyValue(class CBaseDelay *, class KeyValueData_s *); /* linkage=_ZN10CBaseDelay8KeyValueEP14KeyValueData_s */

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
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 60 bytes */
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
struct local_state_s {
	entity_state_t             playerstate;          /*     0   340 */
	/* --- cacheline 5 boundary (320 bytes) was 20 bytes ago --- */
	clientdata_t               client;               /*   340   476 */
	/* --- cacheline 12 boundary (768 bytes) was 48 bytes ago --- */
	weapon_data_t              weapondata[64];       /*   816  5632 */
	void local_state_s(class local_state_s *); /* linkage=_ZN13local_state_sC4Ev */


	/* size: 6448, cachelines: 101, members: 3 */
	/* last cacheline: 48 bytes */
};
class CHLVoiceStatusHelper : public IVoiceStatusHelper {
public:

	/* class IVoiceStatusHelper  <ancestor>; */      /*     0     4 */
	void CHLVoiceStatusHelper(class CHLVoiceStatusHelper *, class CHLVoiceStatusHelper &); /* linkage=_ZN20CHLVoiceStatusHelperC4EOS_ */

	void CHLVoiceStatusHelper(class CHLVoiceStatusHelper *, const class CHLVoiceStatusHelper  &); /* linkage=_ZN20CHLVoiceStatusHelperC4ERKS_ */

	void CHLVoiceStatusHelper(class CHLVoiceStatusHelper *); /* linkage=_ZN20CHLVoiceStatusHelperC4Ev */

	virtual void GetPlayerTextColor(class CHLVoiceStatusHelper *, int, int *); /* linkage=_ZN20CHLVoiceStatusHelper18GetPlayerTextColorEiPi */

	virtual void UpdateCursorState(class CHLVoiceStatusHelper *); /* linkage=_ZN20CHLVoiceStatusHelper17UpdateCursorStateEv */

	virtual int GetAckIconHeight(class CHLVoiceStatusHelper *); /* linkage=_ZN20CHLVoiceStatusHelper16GetAckIconHeightEv */

	virtual bool CanShowSpeakerLabels(class CHLVoiceStatusHelper *); /* linkage=_ZN20CHLVoiceStatusHelper20CanShowSpeakerLabelsEv */

	virtual void ~CHLVoiceStatusHelper(class CHLVoiceStatusHelper *, int); /* linkage=_ZN20CHLVoiceStatusHelperD4Ev */

	/* vtable has 4 entries: {
	   [2] = GetPlayerTextColor(_ZN20CHLVoiceStatusHelper18GetPlayerTextColorEiPi), 
	   [3] = UpdateCursorState(_ZN20CHLVoiceStatusHelper17UpdateCursorStateEv), 
	   [4] = GetAckIconHeight(_ZN20CHLVoiceStatusHelper16GetAckIconHeightEv), 
	   [5] = CanShowSpeakerLabels(_ZN20CHLVoiceStatusHelper20CanShowSpeakerLabelsEv), 
	} */
	/* size: 4, cachelines: 1, members: 1 */
	/* last cacheline: 4 bytes */
};
class IVoiceStatusHelper {
	int ()(void) * *           _vptr.IVoiceStatusHelper; /*     0     4 */
	void IVoiceStatusHelper(class IVoiceStatusHelper *, const class IVoiceStatusHelper  &); /* linkage=_ZN18IVoiceStatusHelperC4ERKS_ */

	void IVoiceStatusHelper(class IVoiceStatusHelper *); /* linkage=_ZN18IVoiceStatusHelperC4Ev */

	virtual void ~IVoiceStatusHelper(class IVoiceStatusHelper *, int); /* linkage=_ZN18IVoiceStatusHelperD4Ev */

	virtual void GetPlayerTextColor(class IVoiceStatusHelper *, int, int *); /* linkage=_ZN18IVoiceStatusHelper18GetPlayerTextColorEiPi */

	virtual void UpdateCursorState(class IVoiceStatusHelper *); /* linkage=_ZN18IVoiceStatusHelper17UpdateCursorStateEv */

	virtual int GetAckIconHeight(class IVoiceStatusHelper *); /* linkage=_ZN18IVoiceStatusHelper16GetAckIconHeightEv */

	virtual bool CanShowSpeakerLabels(class IVoiceStatusHelper *); /* linkage=_ZN18IVoiceStatusHelper20CanShowSpeakerLabelsEv */

	/* vtable has 4 entries: {
	   [2] = GetPlayerTextColor(_ZN18IVoiceStatusHelper18GetPlayerTextColorEiPi), 
	   [3] = UpdateCursorState(_ZN18IVoiceStatusHelper17UpdateCursorStateEv), 
	   [4] = GetAckIconHeight(_ZN18IVoiceStatusHelper16GetAckIconHeightEv), 
	   [5] = CanShowSpeakerLabels(_ZN18IVoiceStatusHelper20CanShowSpeakerLabelsEv), 
	} */
	/* size: 4, cachelines: 1, members: 1 */
	/* last cacheline: 4 bytes */
};
struct POINT_s {
	int                        x;                    /*     0     4 */
	int                        y;                    /*     4     4 */

	/* size: 8, cachelines: 1, members: 2 */
	/* last cacheline: 8 bytes */
};
struct kbutton_s {
	int                        down[2];              /*     0     8 */
	int                        state;                /*     8     4 */

	/* size: 12, cachelines: 1, members: 2 */
	/* last cacheline: 12 bytes */
};
struct SDL_Keysym {
	SDL_Scancode               scancode;             /*     0     4 */
	SDL_Keycode                sym;                  /*     4     4 */
	Uint16                     mod;                  /*     8     2 */

	/* XXX 2 bytes hole, try to pack */

	Uint32                     unused;               /*    12     4 */

	/* size: 16, cachelines: 1, members: 4 */
	/* sum members: 14, holes: 1, sum holes: 2 */
	/* last cacheline: 16 bytes */
};
struct SDL_CommonEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */

	/* size: 8, cachelines: 1, members: 2 */
	/* last cacheline: 8 bytes */
};
struct SDL_DisplayEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	Uint32                     display;              /*     8     4 */
	Uint8                      event;                /*    12     1 */
	Uint8                      padding1;             /*    13     1 */
	Uint8                      padding2;             /*    14     1 */
	Uint8                      padding3;             /*    15     1 */
	Sint32                     data1;                /*    16     4 */

	/* size: 20, cachelines: 1, members: 8 */
	/* last cacheline: 20 bytes */
};
struct SDL_WindowEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	Uint32                     windowID;             /*     8     4 */
	Uint8                      event;                /*    12     1 */
	Uint8                      padding1;             /*    13     1 */
	Uint8                      padding2;             /*    14     1 */
	Uint8                      padding3;             /*    15     1 */
	Sint32                     data1;                /*    16     4 */
	Sint32                     data2;                /*    20     4 */

	/* size: 24, cachelines: 1, members: 9 */
	/* last cacheline: 24 bytes */
};
struct SDL_KeyboardEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	Uint32                     windowID;             /*     8     4 */
	Uint8                      state;                /*    12     1 */
	Uint8                      repeat;               /*    13     1 */
	Uint8                      padding2;             /*    14     1 */
	Uint8                      padding3;             /*    15     1 */
	SDL_Keysym                 keysym;               /*    16    16 */

	/* size: 32, cachelines: 1, members: 8 */
	/* last cacheline: 32 bytes */
};
struct SDL_TextEditingEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	Uint32                     windowID;             /*     8     4 */
	char                       text[32];             /*    12    32 */
	Sint32                     start;                /*    44     4 */
	Sint32                     length;               /*    48     4 */

	/* size: 52, cachelines: 1, members: 6 */
	/* last cacheline: 52 bytes */
};
struct SDL_TextInputEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	Uint32                     windowID;             /*     8     4 */
	char                       text[32];             /*    12    32 */

	/* size: 44, cachelines: 1, members: 4 */
	/* last cacheline: 44 bytes */
};
struct SDL_MouseMotionEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	Uint32                     windowID;             /*     8     4 */
	Uint32                     which;                /*    12     4 */
	Uint32                     state;                /*    16     4 */
	Sint32                     x;                    /*    20     4 */
	Sint32                     y;                    /*    24     4 */
	Sint32                     xrel;                 /*    28     4 */
	Sint32                     yrel;                 /*    32     4 */

	/* size: 36, cachelines: 1, members: 9 */
	/* last cacheline: 36 bytes */
};
struct SDL_MouseButtonEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	Uint32                     windowID;             /*     8     4 */
	Uint32                     which;                /*    12     4 */
	Uint8                      button;               /*    16     1 */
	Uint8                      state;                /*    17     1 */
	Uint8                      clicks;               /*    18     1 */
	Uint8                      padding1;             /*    19     1 */
	Sint32                     x;                    /*    20     4 */
	Sint32                     y;                    /*    24     4 */

	/* size: 28, cachelines: 1, members: 10 */
	/* last cacheline: 28 bytes */
};
struct SDL_MouseWheelEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	Uint32                     windowID;             /*     8     4 */
	Uint32                     which;                /*    12     4 */
	Sint32                     x;                    /*    16     4 */
	Sint32                     y;                    /*    20     4 */
	Uint32                     direction;            /*    24     4 */
	float                      preciseX;             /*    28     4 */
	float                      preciseY;             /*    32     4 */

	/* size: 36, cachelines: 1, members: 9 */
	/* last cacheline: 36 bytes */
};
struct SDL_JoyAxisEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	SDL_JoystickID             which;                /*     8     4 */
	Uint8                      axis;                 /*    12     1 */
	Uint8                      padding1;             /*    13     1 */
	Uint8                      padding2;             /*    14     1 */
	Uint8                      padding3;             /*    15     1 */
	Sint16                     value;                /*    16     2 */
	Uint16                     padding4;             /*    18     2 */

	/* size: 20, cachelines: 1, members: 9 */
	/* last cacheline: 20 bytes */
};
struct SDL_JoyBallEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	SDL_JoystickID             which;                /*     8     4 */
	Uint8                      ball;                 /*    12     1 */
	Uint8                      padding1;             /*    13     1 */
	Uint8                      padding2;             /*    14     1 */
	Uint8                      padding3;             /*    15     1 */
	Sint16                     xrel;                 /*    16     2 */
	Sint16                     yrel;                 /*    18     2 */

	/* size: 20, cachelines: 1, members: 9 */
	/* last cacheline: 20 bytes */
};
struct SDL_JoyHatEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	SDL_JoystickID             which;                /*     8     4 */
	Uint8                      hat;                  /*    12     1 */
	Uint8                      value;                /*    13     1 */
	Uint8                      padding1;             /*    14     1 */
	Uint8                      padding2;             /*    15     1 */

	/* size: 16, cachelines: 1, members: 7 */
	/* last cacheline: 16 bytes */
};
struct SDL_JoyButtonEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	SDL_JoystickID             which;                /*     8     4 */
	Uint8                      button;               /*    12     1 */
	Uint8                      state;                /*    13     1 */
	Uint8                      padding1;             /*    14     1 */
	Uint8                      padding2;             /*    15     1 */

	/* size: 16, cachelines: 1, members: 7 */
	/* last cacheline: 16 bytes */
};
struct SDL_JoyDeviceEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	Sint32                     which;                /*     8     4 */

	/* size: 12, cachelines: 1, members: 3 */
	/* last cacheline: 12 bytes */
};
struct SDL_ControllerAxisEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	SDL_JoystickID             which;                /*     8     4 */
	Uint8                      axis;                 /*    12     1 */
	Uint8                      padding1;             /*    13     1 */
	Uint8                      padding2;             /*    14     1 */
	Uint8                      padding3;             /*    15     1 */
	Sint16                     value;                /*    16     2 */
	Uint16                     padding4;             /*    18     2 */

	/* size: 20, cachelines: 1, members: 9 */
	/* last cacheline: 20 bytes */
};
struct SDL_ControllerButtonEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	SDL_JoystickID             which;                /*     8     4 */
	Uint8                      button;               /*    12     1 */
	Uint8                      state;                /*    13     1 */
	Uint8                      padding1;             /*    14     1 */
	Uint8                      padding2;             /*    15     1 */

	/* size: 16, cachelines: 1, members: 7 */
	/* last cacheline: 16 bytes */
};
struct SDL_ControllerDeviceEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	Sint32                     which;                /*     8     4 */

	/* size: 12, cachelines: 1, members: 3 */
	/* last cacheline: 12 bytes */
};
struct SDL_ControllerTouchpadEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	SDL_JoystickID             which;                /*     8     4 */
	Sint32                     touchpad;             /*    12     4 */
	Sint32                     finger;               /*    16     4 */
	float                      x;                    /*    20     4 */
	float                      y;                    /*    24     4 */
	float                      pressure;             /*    28     4 */

	/* size: 32, cachelines: 1, members: 8 */
	/* last cacheline: 32 bytes */
};
struct SDL_ControllerSensorEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	SDL_JoystickID             which;                /*     8     4 */
	Sint32                     sensor;               /*    12     4 */
	float                      data[3];              /*    16    12 */

	/* size: 28, cachelines: 1, members: 5 */
	/* last cacheline: 28 bytes */
};
struct SDL_AudioDeviceEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	Uint32                     which;                /*     8     4 */
	Uint8                      iscapture;            /*    12     1 */
	Uint8                      padding1;             /*    13     1 */
	Uint8                      padding2;             /*    14     1 */
	Uint8                      padding3;             /*    15     1 */

	/* size: 16, cachelines: 1, members: 7 */
	/* last cacheline: 16 bytes */
};
struct SDL_TouchFingerEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	SDL_TouchID                touchId;              /*     8     8 */
	SDL_FingerID               fingerId;             /*    16     8 */
	float                      x;                    /*    24     4 */
	float                      y;                    /*    28     4 */
	float                      dx;                   /*    32     4 */
	float                      dy;                   /*    36     4 */
	float                      pressure;             /*    40     4 */
	Uint32                     windowID;             /*    44     4 */

	/* size: 48, cachelines: 1, members: 10 */
	/* last cacheline: 48 bytes */
};
struct SDL_MultiGestureEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	SDL_TouchID                touchId;              /*     8     8 */
	float                      dTheta;               /*    16     4 */
	float                      dDist;                /*    20     4 */
	float                      x;                    /*    24     4 */
	float                      y;                    /*    28     4 */
	Uint16                     numFingers;           /*    32     2 */
	Uint16                     padding;              /*    34     2 */

	/* size: 36, cachelines: 1, members: 9 */
	/* last cacheline: 36 bytes */
} __attribute__((__packed__));
struct SDL_DollarGestureEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	SDL_TouchID                touchId;              /*     8     8 */
	SDL_GestureID              gestureId;            /*    16     8 */
	Uint32                     numFingers;           /*    24     4 */
	float                      error;                /*    28     4 */
	float                      x;                    /*    32     4 */
	float                      y;                    /*    36     4 */

	/* size: 40, cachelines: 1, members: 8 */
	/* last cacheline: 40 bytes */
};
struct SDL_DropEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	char *                     file;                 /*     8     4 */
	Uint32                     windowID;             /*    12     4 */

	/* size: 16, cachelines: 1, members: 4 */
	/* last cacheline: 16 bytes */
};
struct SDL_SensorEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	Sint32                     which;                /*     8     4 */
	float                      data[6];              /*    12    24 */

	/* size: 36, cachelines: 1, members: 4 */
	/* last cacheline: 36 bytes */
};
struct SDL_QuitEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */

	/* size: 8, cachelines: 1, members: 2 */
	/* last cacheline: 8 bytes */
};
struct SDL_UserEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	Uint32                     windowID;             /*     8     4 */
	Sint32                     code;                 /*    12     4 */
	void *                     data1;                /*    16     4 */
	void *                     data2;                /*    20     4 */

	/* size: 24, cachelines: 1, members: 6 */
	/* last cacheline: 24 bytes */
};
struct SDL_SysWMEvent {
	Uint32                     type;                 /*     0     4 */
	Uint32                     timestamp;            /*     4     4 */
	SDL_SysWMmsg *             msg;                  /*     8     4 */

	/* size: 12, cachelines: 1, members: 3 */
	/* last cacheline: 12 bytes */
};
union SDL_Event {
	Uint32                     type;               /*     0     4 */
	SDL_CommonEvent            common;             /*     0     8 */
	SDL_DisplayEvent           display;            /*     0    20 */
	SDL_WindowEvent            window;             /*     0    24 */
	SDL_KeyboardEvent          key;                /*     0    32 */
	SDL_TextEditingEvent       edit;               /*     0    52 */
	SDL_TextInputEvent         text;               /*     0    44 */
	SDL_MouseMotionEvent       motion;             /*     0    36 */
	SDL_MouseButtonEvent       button;             /*     0    28 */
	SDL_MouseWheelEvent        wheel;              /*     0    36 */
	SDL_JoyAxisEvent           jaxis;              /*     0    20 */
	SDL_JoyBallEvent           jball;              /*     0    20 */
	SDL_JoyHatEvent            jhat;               /*     0    16 */
	SDL_JoyButtonEvent         jbutton;            /*     0    16 */
	SDL_JoyDeviceEvent         jdevice;            /*     0    12 */
	SDL_ControllerAxisEvent    caxis;              /*     0    20 */
	SDL_ControllerButtonEvent  cbutton;            /*     0    16 */
	SDL_ControllerDeviceEvent  cdevice;            /*     0    12 */
	SDL_ControllerTouchpadEvent ctouchpad;         /*     0    32 */
	SDL_ControllerSensorEvent  csensor;            /*     0    28 */
	SDL_AudioDeviceEvent       adevice;            /*     0    16 */
	SDL_SensorEvent            sensor;             /*     0    36 */
	SDL_QuitEvent              quit;               /*     0     8 */
	SDL_UserEvent              user;               /*     0    24 */
	SDL_SysWMEvent             syswm;              /*     0    12 */
	SDL_TouchFingerEvent       tfinger;            /*     0    48 */
	SDL_MultiGestureEvent      mgesture;           /*     0    36 */
	SDL_DollarGestureEvent     dgesture;           /*     0    40 */
	SDL_DropEvent              drop;               /*     0    16 */
	Uint8                      padding[56];        /*     0    56 */
};
struct WEAPON {
	char                       szName[128];          /*     0   128 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	int                        iAmmoType;            /*   128     4 */
	int                        iAmmo2Type;           /*   132     4 */
	int                        iMax1;                /*   136     4 */
	int                        iMax2;                /*   140     4 */
	int                        iSlot;                /*   144     4 */
	int                        iSlotPos;             /*   148     4 */
	int                        iFlags;               /*   152     4 */
	int                        iId;                  /*   156     4 */
	int                        iClip;                /*   160     4 */
	int                        iCount;               /*   164     4 */
	HANDLE_SPRITE              hActive;              /*   168     4 */
	wrect_t                    rcActive;             /*   172    16 */
	HANDLE_SPRITE              hInactive;            /*   188     4 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	wrect_t                    rcInactive;           /*   192    16 */
	HANDLE_SPRITE              hAmmo;                /*   208     4 */
	wrect_t                    rcAmmo;               /*   212    16 */
	HANDLE_SPRITE              hAmmo2;               /*   228     4 */
	wrect_t                    rcAmmo2;              /*   232    16 */
	HANDLE_SPRITE              hCrosshair;           /*   248     4 */
	wrect_t                    rcCrosshair;          /*   252    16 */
	/* --- cacheline 4 boundary (256 bytes) was 12 bytes ago --- */
	HANDLE_SPRITE              hAutoaim;             /*   268     4 */
	wrect_t                    rcAutoaim;            /*   272    16 */
	HANDLE_SPRITE              hZoomedCrosshair;     /*   288     4 */
	wrect_t                    rcZoomedCrosshair;    /*   292    16 */
	HANDLE_SPRITE              hZoomedAutoaim;       /*   308     4 */
	wrect_t                    rcZoomedAutoaim;      /*   312    16 */

	/* size: 328, cachelines: 6, members: 27 */
	/* last cacheline: 8 bytes */
};
class CHudAmmo : public CHudBase {
public:

	/* class CHudBase            <ancestor>; */      /*     0    20 */
private:

	float                      m_fFade;              /*    20     4 */
	RGBA                       m_rgba;               /*    24     4 */
	class WEAPON *             m_pWeapon;            /*    28     4 */
	int                        m_HUD_bucket0;        /*    32     4 */
	int                        m_HUD_selection;      /*    36     4 */
	void CHudAmmo(class CHudAmmo *, class CHudAmmo &); /* linkage=_ZN8CHudAmmoC4EOS_ */

	void CHudAmmo(class CHudAmmo *, const class CHudAmmo  &); /* linkage=_ZN8CHudAmmoC4ERKS_ */

	void CHudAmmo(class CHudAmmo *); /* linkage=_ZN8CHudAmmoC4Ev */

	virtual int Init(class CHudAmmo *); /* linkage=_ZN8CHudAmmo4InitEv */

	virtual int VidInit(class CHudAmmo *); /* linkage=_ZN8CHudAmmo7VidInitEv */

	virtual int Draw(class CHudAmmo *, float); /* linkage=_ZN8CHudAmmo4DrawEf */

	virtual void Think(class CHudAmmo *); /* linkage=_ZN8CHudAmmo5ThinkEv */

	virtual void Reset(class CHudAmmo *); /* linkage=_ZN8CHudAmmo5ResetEv */

	int DrawWList(class CHudAmmo *, float); /* linkage=_ZN8CHudAmmo9DrawWListEf */

	int MsgFunc_CurWeapon(class CHudAmmo *, const char  *, int, void *); /* linkage=_ZN8CHudAmmo17MsgFunc_CurWeaponEPKciPv */

	int MsgFunc_WeaponList(class CHudAmmo *, const char  *, int, void *); /* linkage=_ZN8CHudAmmo18MsgFunc_WeaponListEPKciPv */

	int MsgFunc_AmmoX(class CHudAmmo *, const char  *, int, void *); /* linkage=_ZN8CHudAmmo13MsgFunc_AmmoXEPKciPv */

	int MsgFunc_AmmoPickup(class CHudAmmo *, const char  *, int, void *); /* linkage=_ZN8CHudAmmo18MsgFunc_AmmoPickupEPKciPv */

	int MsgFunc_WeapPickup(class CHudAmmo *, const char  *, int, void *); /* linkage=_ZN8CHudAmmo18MsgFunc_WeapPickupEPKciPv */

	int MsgFunc_ItemPickup(class CHudAmmo *, const char  *, int, void *); /* linkage=_ZN8CHudAmmo18MsgFunc_ItemPickupEPKciPv */

	int MsgFunc_HideWeapon(class CHudAmmo *, const char  *, int, void *); /* linkage=_ZN8CHudAmmo18MsgFunc_HideWeaponEPKciPv */

	void SlotInput(class CHudAmmo *, int); /* linkage=_ZN8CHudAmmo9SlotInputEi */

	void UserCmd_Slot1(class CHudAmmo *); /* linkage=_ZN8CHudAmmo13UserCmd_Slot1Ev */

	void UserCmd_Slot2(class CHudAmmo *); /* linkage=_ZN8CHudAmmo13UserCmd_Slot2Ev */

	void UserCmd_Slot3(class CHudAmmo *); /* linkage=_ZN8CHudAmmo13UserCmd_Slot3Ev */

	void UserCmd_Slot4(class CHudAmmo *); /* linkage=_ZN8CHudAmmo13UserCmd_Slot4Ev */

	void UserCmd_Slot5(class CHudAmmo *); /* linkage=_ZN8CHudAmmo13UserCmd_Slot5Ev */

	void UserCmd_Slot6(class CHudAmmo *); /* linkage=_ZN8CHudAmmo13UserCmd_Slot6Ev */

	void UserCmd_Slot7(class CHudAmmo *); /* linkage=_ZN8CHudAmmo13UserCmd_Slot7Ev */

	void UserCmd_Slot8(class CHudAmmo *); /* linkage=_ZN8CHudAmmo13UserCmd_Slot8Ev */

	void UserCmd_Slot9(class CHudAmmo *); /* linkage=_ZN8CHudAmmo13UserCmd_Slot9Ev */

	void UserCmd_Slot10(class CHudAmmo *); /* linkage=_ZN8CHudAmmo14UserCmd_Slot10Ev */

	void UserCmd_Close(class CHudAmmo *); /* linkage=_ZN8CHudAmmo13UserCmd_CloseEv */

	void UserCmd_NextWeapon(class CHudAmmo *); /* linkage=_ZN8CHudAmmo18UserCmd_NextWeaponEv */

	void UserCmd_PrevWeapon(class CHudAmmo *); /* linkage=_ZN8CHudAmmo18UserCmd_PrevWeaponEv */

	virtual void ~CHudAmmo(class CHudAmmo *, int); /* linkage=_ZN8CHudAmmoD4Ev */

	/* vtable has 5 entries: {
	   [2] = Init(_ZN8CHudAmmo4InitEv), 
	   [3] = VidInit(_ZN8CHudAmmo7VidInitEv), 
	   [4] = Draw(_ZN8CHudAmmo4DrawEf), 
	   [5] = Think(_ZN8CHudAmmo5ThinkEv), 
	   [6] = Reset(_ZN8CHudAmmo5ResetEv), 
	} */
	/* size: 40, cachelines: 1, members: 6 */
	/* last cacheline: 40 bytes */
};
class WeaponsResource {
private:

	struct WEAPON              rgWeapons[32];        /*     0 10496 */
	/* --- cacheline 164 boundary (10496 bytes) --- */
	class WEAPON *             rgSlots[6][6];        /* 10496   144 */
	/* --- cacheline 166 boundary (10624 bytes) was 16 bytes ago --- */
	int                        riAmmo[32];           /* 10640   128 */
	/* --- cacheline 168 boundary (10752 bytes) was 16 bytes ago --- */
	int                        iOldWeaponBits;       /* 10768     4 */
	void Init(class WeaponsResource *); /* linkage=_ZN15WeaponsResource4InitEv */

	void Reset(class WeaponsResource *); /* linkage=_ZN15WeaponsResource5ResetEv */

	class WEAPON * GetWeapon(class WeaponsResource *, int); /* linkage=_ZN15WeaponsResource9GetWeaponEi */

	void AddWeapon(class WeaponsResource *, class WEAPON *); /* linkage=_ZN15WeaponsResource9AddWeaponEP6WEAPON */

	void PickupWeapon(class WeaponsResource *, class WEAPON *); /* linkage=_ZN15WeaponsResource12PickupWeaponEP6WEAPON */

	void DropWeapon(class WeaponsResource *, class WEAPON *); /* linkage=_ZN15WeaponsResource10DropWeaponEP6WEAPON */

	void DropAllWeapons(class WeaponsResource *); /* linkage=_ZN15WeaponsResource14DropAllWeaponsEv */

	class WEAPON * GetWeaponSlot(class WeaponsResource *, int, int); /* linkage=_ZN15WeaponsResource13GetWeaponSlotEii */

	void LoadWeaponSprites(class WeaponsResource *, class WEAPON *); /* linkage=_ZN15WeaponsResource17LoadWeaponSpritesEP6WEAPON */

	void LoadAllWeaponSprites(class WeaponsResource *); /* linkage=_ZN15WeaponsResource20LoadAllWeaponSpritesEv */

	class WEAPON * GetFirstPos(class WeaponsResource *, int); /* linkage=_ZN15WeaponsResource11GetFirstPosEi */

	void SelectSlot(class WeaponsResource *, int, int, int); /* linkage=_ZN15WeaponsResource10SelectSlotEiii */

	class WEAPON * GetNextActivePos(class WeaponsResource *, int, int); /* linkage=_ZN15WeaponsResource16GetNextActivePosEii */

	int HasAmmo(class WeaponsResource *, class WEAPON *); /* linkage=_ZN15WeaponsResource7HasAmmoEP6WEAPON */

	AMMO GetAmmo(class WeaponsResource *, int); /* linkage=_ZN15WeaponsResource7GetAmmoEi */

	void SetAmmo(class WeaponsResource *, int, int); /* linkage=_ZN15WeaponsResource7SetAmmoEii */

	int CountAmmo(class WeaponsResource *, int); /* linkage=_ZN15WeaponsResource9CountAmmoEi */

	HANDLE_SPRITE * GetAmmoPicFromWeapon(class WeaponsResource *, int, wrect_t &); /* linkage=_ZN15WeaponsResource20GetAmmoPicFromWeaponEiR6rect_s */


	/* size: 10772, cachelines: 169, members: 4 */
	/* last cacheline: 20 bytes */
};
class HistoryResource {
	struct HIST_ITEM {
		int                        type;                 /*     0     4 */
		float                      DisplayTime;          /*     4     4 */
		int                        iCount;               /*     8     4 */
		int                        iId;                  /*    12     4 */

		/* size: 16, cachelines: 1, members: 4 */
		/* last cacheline: 16 bytes */
	};

private:

	struct HIST_ITEM           rgAmmoHistory[12];    /*     0   192 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	int                        iHistoryGap;          /*   192     4 */
	int                        iCurrentHistorySlot;  /*   196     4 */
	void Init(class HistoryResource *); /* linkage=_ZN15HistoryResource4InitEv */

	void Reset(class HistoryResource *); /* linkage=_ZN15HistoryResource5ResetEv */

	void AddToHistory(class HistoryResource *, int, int, int); /* linkage=_ZN15HistoryResource12AddToHistoryEiii */

	void AddToHistory(class HistoryResource *, int, const char  *, int); /* linkage=_ZN15HistoryResource12AddToHistoryEiPKci */

	void CheckClearHistory(class HistoryResource *); /* linkage=_ZN15HistoryResource17CheckClearHistoryEv */

	int DrawAmmoHistory(class HistoryResource *, float); /* linkage=_ZN15HistoryResource15DrawAmmoHistoryEf */


	/* size: 200, cachelines: 4, members: 3 */
	/* last cacheline: 8 bytes */
};
class CHudAmmoSecondary : public CHudBase {
	enum {
		MAX_SEC_AMMO_VALUES = 4,
	};

public:

	/* class CHudBase            <ancestor>; */      /*     0    20 */
private:

	int                        m_HUD_ammoicon;       /*    20     4 */
	int                        m_iAmmoAmounts[4];    /*    24    16 */
	float                      m_fFade;              /*    40     4 */
	void CHudAmmoSecondary(class CHudAmmoSecondary *, class CHudAmmoSecondary &); /* linkage=_ZN17CHudAmmoSecondaryC4EOS_ */

	void CHudAmmoSecondary(class CHudAmmoSecondary *, const class CHudAmmoSecondary  &); /* linkage=_ZN17CHudAmmoSecondaryC4ERKS_ */

	void CHudAmmoSecondary(class CHudAmmoSecondary *); /* linkage=_ZN17CHudAmmoSecondaryC4Ev */

	virtual int Init(class CHudAmmoSecondary *); /* linkage=_ZN17CHudAmmoSecondary4InitEv */

	virtual int VidInit(class CHudAmmoSecondary *); /* linkage=_ZN17CHudAmmoSecondary7VidInitEv */

	virtual void Reset(class CHudAmmoSecondary *); /* linkage=_ZN17CHudAmmoSecondary5ResetEv */

	virtual int Draw(class CHudAmmoSecondary *, float); /* linkage=_ZN17CHudAmmoSecondary4DrawEf */

	int MsgFunc_SecAmmoVal(class CHudAmmoSecondary *, const char  *, int, void *); /* linkage=_ZN17CHudAmmoSecondary18MsgFunc_SecAmmoValEPKciPv */

	int MsgFunc_SecAmmoIcon(class CHudAmmoSecondary *, const char  *, int, void *); /* linkage=_ZN17CHudAmmoSecondary19MsgFunc_SecAmmoIconEPKciPv */

	virtual void ~CHudAmmoSecondary(class CHudAmmoSecondary *, int); /* linkage=_ZN17CHudAmmoSecondaryD4Ev */

	/* vtable has 4 entries: {
	   [2] = Init(_ZN17CHudAmmoSecondary4InitEv), 
	   [3] = VidInit(_ZN17CHudAmmoSecondary7VidInitEv), 
	   [6] = Reset(_ZN17CHudAmmoSecondary5ResetEv), 
	   [4] = Draw(_ZN17CHudAmmoSecondary4DrawEf), 
	} */
	/* size: 44, cachelines: 1, members: 4 */
	/* last cacheline: 44 bytes */
};
class HistoryResource {
	struct HIST_ITEM {
		int                        type;                 /*     0     4 */
		float                      DisplayTime;          /*     4     4 */
		int                        iCount;               /*     8     4 */
		int                        iId;                  /*    12     4 */

		/* size: 16, cachelines: 1, members: 4 */
		/* last cacheline: 16 bytes */
	};

private:

	struct HIST_ITEM           rgAmmoHistory[12];    /*     0   192 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	int                        iHistoryGap;          /*   192     4 */
	int                        iCurrentHistorySlot;  /*   196     4 */
	void Init(class HistoryResource *); /* linkage=_ZN15HistoryResource4InitEv */

	void Reset(class HistoryResource *); /* linkage=_ZN15HistoryResource5ResetEv */

	void AddToHistory(class HistoryResource *, int, int, int); /* linkage=_ZN15HistoryResource12AddToHistoryEiii */

	void AddToHistory(class HistoryResource *, int, const char  *, int); /* linkage=_ZN15HistoryResource12AddToHistoryEiPKci */

	void CheckClearHistory(class HistoryResource *); /* linkage=_ZN15HistoryResource17CheckClearHistoryEv */

	int DrawAmmoHistory(class HistoryResource *, float); /* linkage=_ZN15HistoryResource15DrawAmmoHistoryEf */


	/* size: 200, cachelines: 4, members: 3 */
	/* last cacheline: 8 bytes */
};
class CHudBattery : public CHudBase {
public:

	/* class CHudBase            <ancestor>; */      /*     0    20 */
private:

	HANDLE_SPRITE              m_hSprite1;           /*    20     4 */
	HANDLE_SPRITE              m_hSprite2;           /*    24     4 */
	wrect_t *                  m_prc1;               /*    28     4 */
	wrect_t *                  m_prc2;               /*    32     4 */
	int                        m_iBat;               /*    36     4 */
	int                        m_iBatMax;            /*    40     4 */
	float                      m_fFade;              /*    44     4 */
	int                        m_iHeight;            /*    48     4 */
	void CHudBattery(class CHudBattery *, class CHudBattery &); /* linkage=_ZN11CHudBatteryC4EOS_ */

	void CHudBattery(class CHudBattery *, const class CHudBattery  &); /* linkage=_ZN11CHudBatteryC4ERKS_ */

	void CHudBattery(class CHudBattery *); /* linkage=_ZN11CHudBatteryC4Ev */

	virtual int Init(class CHudBattery *); /* linkage=_ZN11CHudBattery4InitEv */

	virtual int VidInit(class CHudBattery *); /* linkage=_ZN11CHudBattery7VidInitEv */

	virtual int Draw(class CHudBattery *, float); /* linkage=_ZN11CHudBattery4DrawEf */

	int MsgFunc_Battery(class CHudBattery *, const char  *, int, void *); /* linkage=_ZN11CHudBattery15MsgFunc_BatteryEPKciPv */

	virtual void ~CHudBattery(class CHudBattery *, int); /* linkage=_ZN11CHudBatteryD4Ev */

	/* vtable has 3 entries: {
	   [2] = Init(_ZN11CHudBattery4InitEv), 
	   [3] = VidInit(_ZN11CHudBattery7VidInitEv), 
	   [4] = Draw(_ZN11CHudBattery4DrawEf), 
	} */
	/* size: 52, cachelines: 1, members: 9 */
	/* last cacheline: 52 bytes */
};
class CHudDeathNotice : public CHudBase {
public:

	/* class CHudBase            <ancestor>; */      /*     0    20 */
private:

	int                        m_HUD_d_skull;        /*    20     4 */
	void CHudDeathNotice(class CHudDeathNotice *, class CHudDeathNotice &); /* linkage=_ZN15CHudDeathNoticeC4EOS_ */

	void CHudDeathNotice(class CHudDeathNotice *, const class CHudDeathNotice  &); /* linkage=_ZN15CHudDeathNoticeC4ERKS_ */

	void CHudDeathNotice(class CHudDeathNotice *); /* linkage=_ZN15CHudDeathNoticeC4Ev */

	virtual int Init(class CHudDeathNotice *); /* linkage=_ZN15CHudDeathNotice4InitEv */

	virtual void InitHUDData(class CHudDeathNotice *); /* linkage=_ZN15CHudDeathNotice11InitHUDDataEv */

	virtual int VidInit(class CHudDeathNotice *); /* linkage=_ZN15CHudDeathNotice7VidInitEv */

	virtual int Draw(class CHudDeathNotice *, float); /* linkage=_ZN15CHudDeathNotice4DrawEf */

	int MsgFunc_DeathMsg(class CHudDeathNotice *, const char  *, int, void *); /* linkage=_ZN15CHudDeathNotice16MsgFunc_DeathMsgEPKciPv */

	virtual void ~CHudDeathNotice(class CHudDeathNotice *, int); /* linkage=_ZN15CHudDeathNoticeD4Ev */

	/* vtable has 4 entries: {
	   [2] = Init(_ZN15CHudDeathNotice4InitEv), 
	   [7] = InitHUDData(_ZN15CHudDeathNotice11InitHUDDataEv), 
	   [3] = VidInit(_ZN15CHudDeathNotice7VidInitEv), 
	   [4] = Draw(_ZN15CHudDeathNotice4DrawEf), 
	} */
	/* size: 24, cachelines: 1, members: 2 */
	/* last cacheline: 24 bytes */
};
struct DeathNoticeItem {
	char                       szKiller[64];         /*     0    64 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	char                       szVictim[64];         /*    64    64 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	int                        iId;                  /*   128     4 */
	int                        iSuicide;             /*   132     4 */
	int                        iTeamKill;            /*   136     4 */
	int                        iNonPlayerKill;       /*   140     4 */
	float                      flDisplayTime;        /*   144     4 */
	float *                    KillerColor;          /*   148     4 */
	float *                    VictimColor;          /*   152     4 */

	/* size: 156, cachelines: 3, members: 9 */
	/* last cacheline: 28 bytes */
};
struct mstudioevent_s {
	int                        frame;                /*     0     4 */
	int                        event;                /*     4     4 */
	int                        type;                 /*     8     4 */
	char                       options[64];          /*    12    64 */

	/* size: 76, cachelines: 2, members: 4 */
	/* last cacheline: 12 bytes */
};
struct ref_params_s {
	float                      vieworg[3];           /*     0    12 */
	float                      viewangles[3];        /*    12    12 */
	float                      forward[3];           /*    24    12 */
	float                      right[3];             /*    36    12 */
	float                      up[3];                /*    48    12 */
	float                      frametime;            /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	float                      time;                 /*    64     4 */
	int                        intermission;         /*    68     4 */
	int                        paused;               /*    72     4 */
	int                        spectator;            /*    76     4 */
	int                        onground;             /*    80     4 */
	int                        waterlevel;           /*    84     4 */
	float                      simvel[3];            /*    88    12 */
	float                      simorg[3];            /*   100    12 */
	float                      viewheight[3];        /*   112    12 */
	float                      idealpitch;           /*   124     4 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	float                      cl_viewangles[3];     /*   128    12 */
	int                        health;               /*   140     4 */
	float                      crosshairangle[3];    /*   144    12 */
	float                      viewsize;             /*   156     4 */
	float                      punchangle[3];        /*   160    12 */
	int                        maxclients;           /*   172     4 */
	int                        viewentity;           /*   176     4 */
	int                        playernum;            /*   180     4 */
	int                        max_entities;         /*   184     4 */
	int                        demoplayback;         /*   188     4 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	int                        hardware;             /*   192     4 */
	int                        smoothing;            /*   196     4 */
	class usercmd_s *          cmd;                  /*   200     4 */
	class movevars_s *         movevars;             /*   204     4 */
	int                        viewport[4];          /*   208    16 */
	int                        nextView;             /*   224     4 */
	int                        onlyClientDraw;       /*   228     4 */

	/* size: 232, cachelines: 4, members: 33 */
	/* last cacheline: 40 bytes */
};
struct netadr_s {
	netadrtype_t               type;                 /*     0     4 */
	unsigned char              ip[4];                /*     4     4 */
	unsigned char              ipx[10];              /*     8    10 */
	short unsigned int         port;                 /*    18     2 */

	/* size: 20, cachelines: 1, members: 4 */
	/* last cacheline: 20 bytes */
};
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
class CClientExports : public IGameClientExports {
public:

	/* class IGameClientExports  <ancestor>; */      /*     0     4 */
	void CClientExports(class CClientExports *, class CClientExports &); /* linkage=_ZN14CClientExportsC4EOS_ */

	void CClientExports(class CClientExports *, const class CClientExports  &); /* linkage=_ZN14CClientExportsC4ERKS_ */

	void CClientExports(class CClientExports *); /* linkage=_ZN14CClientExportsC4Ev */

	virtual const char  * GetServerHostName(class CClientExports *); /* linkage=_ZN14CClientExports17GetServerHostNameEv */

	virtual bool IsPlayerGameVoiceMuted(class CClientExports *, int); /* linkage=_ZN14CClientExports22IsPlayerGameVoiceMutedEi */

	virtual void MutePlayerGameVoice(class CClientExports *, int); /* linkage=_ZN14CClientExports19MutePlayerGameVoiceEi */

	virtual void UnmutePlayerGameVoice(class CClientExports *, int); /* linkage=_ZN14CClientExports21UnmutePlayerGameVoiceEi */

	virtual void ~CClientExports(class CClientExports *, int); /* linkage=_ZN14CClientExportsD4Ev */

	/* vtable has 4 entries: {
	   [2] = GetServerHostName(_ZN14CClientExports17GetServerHostNameEv), 
	   [3] = IsPlayerGameVoiceMuted(_ZN14CClientExports22IsPlayerGameVoiceMutedEi), 
	   [4] = MutePlayerGameVoice(_ZN14CClientExports19MutePlayerGameVoiceEi), 
	   [5] = UnmutePlayerGameVoice(_ZN14CClientExports21UnmutePlayerGameVoiceEi), 
	} */
	/* size: 4, cachelines: 1, members: 1 */
	/* last cacheline: 4 bytes */
};
class IGameClientExports : public IBaseInterface {
public:

	/* class IBaseInterface      <ancestor>; */      /*     0     4 */
	void IGameClientExports(class IGameClientExports *, class IGameClientExports &); /* linkage=_ZN18IGameClientExportsC4EOS_ */

	void IGameClientExports(class IGameClientExports *, const class IGameClientExports  &); /* linkage=_ZN18IGameClientExportsC4ERKS_ */

	void IGameClientExports(class IGameClientExports *); /* linkage=_ZN18IGameClientExportsC4Ev */

	virtual const char  * GetServerHostName(class IGameClientExports *); /* linkage=_ZN18IGameClientExports17GetServerHostNameEv */

	virtual bool IsPlayerGameVoiceMuted(class IGameClientExports *, int); /* linkage=_ZN18IGameClientExports22IsPlayerGameVoiceMutedEi */

	virtual void MutePlayerGameVoice(class IGameClientExports *, int); /* linkage=_ZN18IGameClientExports19MutePlayerGameVoiceEi */

	virtual void UnmutePlayerGameVoice(class IGameClientExports *, int); /* linkage=_ZN18IGameClientExports21UnmutePlayerGameVoiceEi */

	virtual void ~IGameClientExports(class IGameClientExports *, int); /* linkage=_ZN18IGameClientExportsD4Ev */

	/* vtable has 4 entries: {
	   [2] = GetServerHostName(_ZN18IGameClientExports17GetServerHostNameEv), 
	   [3] = IsPlayerGameVoiceMuted(_ZN18IGameClientExports22IsPlayerGameVoiceMutedEi), 
	   [4] = MutePlayerGameVoice(_ZN18IGameClientExports19MutePlayerGameVoiceEi), 
	   [5] = UnmutePlayerGameVoice(_ZN18IGameClientExports21UnmutePlayerGameVoiceEi), 
	} */
	/* size: 4, cachelines: 1, members: 1 */
	/* last cacheline: 4 bytes */
};
class CHudFlashlight : public CHudBase {
public:

	/* class CHudBase            <ancestor>; */      /*     0    20 */
private:

	HANDLE_SPRITE              m_hSprite1;           /*    20     4 */
	HANDLE_SPRITE              m_hSprite2;           /*    24     4 */
	HANDLE_SPRITE              m_hBeam;              /*    28     4 */
	wrect_t *                  m_prc1;               /*    32     4 */
	wrect_t *                  m_prc2;               /*    36     4 */
	wrect_t *                  m_prcBeam;            /*    40     4 */
	float                      m_flBat;              /*    44     4 */
	int                        m_iBat;               /*    48     4 */
	int                        m_fOn;                /*    52     4 */
	float                      m_fFade;              /*    56     4 */
	int                        m_iWidth;             /*    60     4 */
	void CHudFlashlight(class CHudFlashlight *, class CHudFlashlight &); /* linkage=_ZN14CHudFlashlightC4EOS_ */

	void CHudFlashlight(class CHudFlashlight *, const class CHudFlashlight  &); /* linkage=_ZN14CHudFlashlightC4ERKS_ */

	void CHudFlashlight(class CHudFlashlight *); /* linkage=_ZN14CHudFlashlightC4Ev */

	virtual int Init(class CHudFlashlight *); /* linkage=_ZN14CHudFlashlight4InitEv */

	virtual int VidInit(class CHudFlashlight *); /* linkage=_ZN14CHudFlashlight7VidInitEv */

	virtual int Draw(class CHudFlashlight *, float); /* linkage=_ZN14CHudFlashlight4DrawEf */

	virtual void Reset(class CHudFlashlight *); /* linkage=_ZN14CHudFlashlight5ResetEv */

	int MsgFunc_Flashlight(class CHudFlashlight *, const char  *, int, void *); /* linkage=_ZN14CHudFlashlight18MsgFunc_FlashlightEPKciPv */

	int MsgFunc_FlashBat(class CHudFlashlight *, const char  *, int, void *); /* linkage=_ZN14CHudFlashlight16MsgFunc_FlashBatEPKciPv */

	virtual void ~CHudFlashlight(class CHudFlashlight *, int); /* linkage=_ZN14CHudFlashlightD4Ev */

	/* vtable has 4 entries: {
	   [2] = Init(_ZN14CHudFlashlight4InitEv), 
	   [3] = VidInit(_ZN14CHudFlashlight7VidInitEv), 
	   [4] = Draw(_ZN14CHudFlashlight4DrawEf), 
	   [6] = Reset(_ZN14CHudFlashlight5ResetEv), 
	} */
	/* size: 64, cachelines: 1, members: 12 */
};
struct r_studio_interface_s {
	int                        version;              /*     0     4 */
	int                        (*StudioDrawModel)(int); /*     4     4 */
	int                        (*StudioDrawPlayer)(int, class entity_state_s *); /*     8     4 */

	/* size: 12, cachelines: 1, members: 3 */
	/* last cacheline: 12 bytes */
};
struct engine_studio_api_s {
	void *                     (*Mem_Calloc)(int, size_t); /*     0     4 */
	void *                     (*Cache_Check)(class cache_user_s *); /*     4     4 */
	void                       (*LoadCacheFile)(char *, class cache_user_s *); /*     8     4 */
	class model_s *            (*Mod_ForName)(const char  *, int); /*    12     4 */
	void *                     (*Mod_Extradata)(class model_s *); /*    16     4 */
	class model_s *            (*GetModelByIndex)(int); /*    20     4 */
	class cl_entity_s *        (*GetCurrentEntity)(void); /*    24     4 */
	class player_info_s *      (*PlayerInfo)(int);   /*    28     4 */
	class entity_state_s *     (*GetPlayerState)(int); /*    32     4 */
	class cl_entity_s *        (*GetViewEntity)(void); /*    36     4 */
	void                       (*GetTimes)(int *, double *, double *); /*    40     4 */
	class cvar_s *             (*GetCvar)(const char  *); /*    44     4 */
	void                       (*GetViewInfo)(float *, float *, float *, float *); /*    48     4 */
	class model_s *            (*GetChromeSprite)(void); /*    52     4 */
	void                       (*GetModelCounters)(int * *, int * *); /*    56     4 */
	void                       (*GetAliasScale)(float *, float *); /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	float * * * *              (*StudioGetBoneTransform)(void); /*    64     4 */
	float * * * *              (*StudioGetLightTransform)(void); /*    68     4 */
	float * * *                (*StudioGetAliasTransform)(void); /*    72     4 */
	float * * *                (*StudioGetRotationMatrix)(void); /*    76     4 */
	void                       (*StudioSetupModel)(int, void * *, void * *); /*    80     4 */
	int                        (*StudioCheckBBox)(void); /*    84     4 */
	void                       (*StudioDynamicLight)(class cl_entity_s *, class alight_s *); /*    88     4 */
	void                       (*StudioEntityLight)(class alight_s *); /*    92     4 */
	void                       (*StudioSetupLighting)(class alight_s *); /*    96     4 */
	void                       (*StudioDrawPoints)(void); /*   100     4 */
	void                       (*StudioDrawHulls)(void); /*   104     4 */
	void                       (*StudioDrawAbsBBox)(void); /*   108     4 */
	void                       (*StudioDrawBones)(void); /*   112     4 */
	void                       (*StudioSetupSkin)(void *, int); /*   116     4 */
	void                       (*StudioSetRemapColors)(int, int); /*   120     4 */
	class model_s *            (*SetupPlayerModel)(int); /*   124     4 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	void                       (*StudioClientEvents)(void); /*   128     4 */
	int                        (*GetForceFaceFlags)(void); /*   132     4 */
	void                       (*SetForceFaceFlags)(int); /*   136     4 */
	void                       (*StudioSetHeader)(void *); /*   140     4 */
	void                       (*SetRenderModel)(class model_s *); /*   144     4 */
	void                       (*SetupRenderer)(int); /*   148     4 */
	void                       (*RestoreRenderer)(void); /*   152     4 */
	void                       (*SetChromeOrigin)(void); /*   156     4 */
	int                        (*IsHardware)(void);  /*   160     4 */
	void                       (*GL_StudioDrawShadow)(void); /*   164     4 */
	void                       (*GL_SetRenderMode)(int); /*   168     4 */
	void                       (*StudioSetRenderamt)(int); /*   172     4 */
	void                       (*StudioSetCullState)(int); /*   176     4 */
	void                       (*StudioRenderShadow)(int, float *, float *, float *, float *); /*   180     4 */

	/* size: 184, cachelines: 3, members: 46 */
	/* last cacheline: 56 bytes */
};
struct alight_s {
	int                        ambientlight;         /*     0     4 */
	int                        shadelight;           /*     4     4 */
	class Vector              color;                 /*     8    12 */
	float *                    plightvec;            /*    20     4 */
	void alight_s(class alight_s *); /* linkage=_ZN8alight_sC4Ev */


	/* size: 24, cachelines: 1, members: 4 */
	/* last cacheline: 24 bytes */
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
struct player_info_s {
	int                        userid;               /*     0     4 */
	char                       userinfo[256];        /*     4   256 */
	/* --- cacheline 4 boundary (256 bytes) was 4 bytes ago --- */
	char                       name[32];             /*   260    32 */
	int                        spectator;            /*   292     4 */
	int                        ping;                 /*   296     4 */
	int                        packet_loss;          /*   300     4 */
	char                       model[64];            /*   304    64 */
	/* --- cacheline 5 boundary (320 bytes) was 48 bytes ago --- */
	int                        topcolor;             /*   368     4 */
	int                        bottomcolor;          /*   372     4 */
	int                        renderframe;          /*   376     4 */
	int                        gaitsequence;         /*   380     4 */
	/* --- cacheline 6 boundary (384 bytes) --- */
	float                      gaitframe;            /*   384     4 */
	float                      gaityaw;              /*   388     4 */
	class Vector              prevgaitorigin;        /*   392    12 */
	customization_t            customdata;           /*   404   164 */
	void player_info_s(class player_info_s *); /* linkage=_ZN13player_info_sC4Ev */


	/* size: 568, cachelines: 9, members: 15 */
	/* last cacheline: 56 bytes */
};
class CGameStudioModelRenderer : public CStudioModelRenderer {
public:

	/* class CStudioModelRenderer <ancestor>; */     /*     0     0 */
	void CGameStudioModelRenderer(class CGameStudioModelRenderer *, class CGameStudioModelRenderer &); /* linkage=_ZN24CGameStudioModelRendererC4EOS_ */

	void CGameStudioModelRenderer(class CGameStudioModelRenderer *, const class CGameStudioModelRenderer  &); /* linkage=_ZN24CGameStudioModelRendererC4ERKS_ */

	void CGameStudioModelRenderer(class CGameStudioModelRenderer *); /* linkage=_ZN24CGameStudioModelRendererC4Ev */

	virtual void ~CGameStudioModelRenderer(class CGameStudioModelRenderer *, int); /* linkage=_ZN24CGameStudioModelRendererD4Ev */


	/* size: 16556, cachelines: 259, members: 1 */
	/* padding: 16556 */
	/* last cacheline: 44 bytes */
};
class CHudGeiger : public CHudBase {
public:

	/* class CHudBase            <ancestor>; */      /*     0    20 */
private:

	int                        m_iGeigerRange;       /*    20     4 */
	void CHudGeiger(class CHudGeiger *, class CHudGeiger &); /* linkage=_ZN10CHudGeigerC4EOS_ */

	void CHudGeiger(class CHudGeiger *, const class CHudGeiger  &); /* linkage=_ZN10CHudGeigerC4ERKS_ */

	void CHudGeiger(class CHudGeiger *); /* linkage=_ZN10CHudGeigerC4Ev */

	virtual int Init(class CHudGeiger *); /* linkage=_ZN10CHudGeiger4InitEv */

	virtual int VidInit(class CHudGeiger *); /* linkage=_ZN10CHudGeiger7VidInitEv */

	virtual int Draw(class CHudGeiger *, float); /* linkage=_ZN10CHudGeiger4DrawEf */

	int MsgFunc_Geiger(class CHudGeiger *, const char  *, int, void *); /* linkage=_ZN10CHudGeiger14MsgFunc_GeigerEPKciPv */

	virtual void ~CHudGeiger(class CHudGeiger *, int); /* linkage=_ZN10CHudGeigerD4Ev */

	/* vtable has 3 entries: {
	   [2] = Init(_ZN10CHudGeiger4InitEv), 
	   [3] = VidInit(_ZN10CHudGeiger7VidInitEv), 
	   [4] = Draw(_ZN10CHudGeiger4DrawEf), 
	} */
	/* size: 24, cachelines: 1, members: 2 */
	/* last cacheline: 24 bytes */
};
class CHudHealth : public CHudBase {
public:

	/* class CHudBase            <ancestor>; */      /*     0    20 */
	int                        m_iHealth;            /*    20     4 */
	int                        m_HUD_dmg_bio;        /*    24     4 */
	int                        m_HUD_cross;          /*    28     4 */
	float                      m_fAttackFront;       /*    32     4 */
	float                      m_fAttackRear;        /*    36     4 */
	float                      m_fAttackLeft;        /*    40     4 */
	float                      m_fAttackRight;       /*    44     4 */
	float                      m_fFade;              /*    48     4 */
private:

	HANDLE_SPRITE              m_hSprite;            /*    52     4 */
	HANDLE_SPRITE              m_hDamage;            /*    56     4 */
	DAMAGE_IMAGE               m_dmg[12];            /*    60   192 */
	/* --- cacheline 3 boundary (192 bytes) was 60 bytes ago --- */
	int                        m_bitsDamage;         /*   252     4 */
	void CHudHealth(class CHudHealth *, class CHudHealth &); /* linkage=_ZN10CHudHealthC4EOS_ */

	void CHudHealth(class CHudHealth *, const class CHudHealth  &); /* linkage=_ZN10CHudHealthC4ERKS_ */

	void CHudHealth(class CHudHealth *); /* linkage=_ZN10CHudHealthC4Ev */

	virtual int Init(class CHudHealth *); /* linkage=_ZN10CHudHealth4InitEv */

	virtual int VidInit(class CHudHealth *); /* linkage=_ZN10CHudHealth7VidInitEv */

	virtual int Draw(class CHudHealth *, float); /* linkage=_ZN10CHudHealth4DrawEf */

	virtual void Reset(class CHudHealth *); /* linkage=_ZN10CHudHealth5ResetEv */

	int MsgFunc_Health(class CHudHealth *, const char  *, int, void *); /* linkage=_ZN10CHudHealth14MsgFunc_HealthEPKciPv */

	int MsgFunc_Damage(class CHudHealth *, const char  *, int, void *); /* linkage=_ZN10CHudHealth14MsgFunc_DamageEPKciPv */

	void GetPainColor(class CHudHealth *, int &, int &, int &); /* linkage=_ZN10CHudHealth12GetPainColorERiS0_S0_ */

	int DrawPain(class CHudHealth *, float); /* linkage=_ZN10CHudHealth8DrawPainEf */

	int DrawDamage(class CHudHealth *, float); /* linkage=_ZN10CHudHealth10DrawDamageEf */

	void CalcDamageDirection(class CHudHealth *, class Vector); /* linkage=_ZN10CHudHealth19CalcDamageDirectionE6Vector */

	void UpdateTiles(class CHudHealth *, float, long int); /* linkage=_ZN10CHudHealth11UpdateTilesEfl */

	virtual void ~CHudHealth(class CHudHealth *, int); /* linkage=_ZN10CHudHealthD4Ev */

	/* vtable has 4 entries: {
	   [2] = Init(_ZN10CHudHealth4InitEv), 
	   [3] = VidInit(_ZN10CHudHealth7VidInitEv), 
	   [4] = Draw(_ZN10CHudHealth4DrawEf), 
	   [6] = Reset(_ZN10CHudHealth5ResetEv), 
	} */
	/* size: 256, cachelines: 4, members: 13 */
};
struct model_s {
	char                       name[64];             /*     0    64 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	qboolean                   needload;             /*    64     4 */
	int                        type;                 /*    68     4 */
	int                        numframes;            /*    72     4 */
	int                        synctype;             /*    76     4 */
	int                        flags;                /*    80     4 */
	class Vector              mins;                  /*    84    12 */
	class Vector              maxs;                  /*    96    12 */
	void model_s(class model_s *); /* linkage=_ZN7model_sC4Ev */


	/* size: 108, cachelines: 2, members: 8 */
	/* last cacheline: 44 bytes */
};
struct con_nprint_s {
	int                        index;                /*     0     4 */
	float                      time_to_live;         /*     4     4 */
	float                      color[3];             /*     8    12 */

	/* size: 20, cachelines: 1, members: 3 */
	/* last cacheline: 20 bytes */
};
struct net_api_s {
	void                       (*InitNetworking)(void); /*     0     4 */
	void                       (*Status)(class net_status_s *); /*     4     4 */
	void                       (*SendRequest)(int, int, int, double, class netadr_s *, net_api_response_func_t); /*     8     4 */
	void                       (*CancelRequest)(int); /*    12     4 */
	void                       (*CancelAllRequests)(void); /*    16     4 */
	char *                     (*AdrToString)(class netadr_s *); /*    20     4 */
	int                        (*CompareAdr)(class netadr_s *, class netadr_s *); /*    24     4 */
	int                        (*StringToAdr)(char *, class netadr_s *); /*    28     4 */
	const char  *              (*ValueForKey)(const char  *, const char  *); /*    32     4 */
	void                       (*RemoveKey)(char *, const char  *); /*    36     4 */
	void                       (*SetValueForKey)(char *, const char  *, const char  *, int); /*    40     4 */

	/* size: 44, cachelines: 1, members: 11 */
	/* last cacheline: 44 bytes */
};
class CHudBenchmark : public CHudBase {
public:

	/* class CHudBase            <ancestor>; */      /*     0    20 */
private:

	float                      m_fDrawTime;          /*    20     4 */
	float                      m_fDrawScore;         /*    24     4 */
	float                      m_fAvgScore;          /*    28     4 */
	float                      m_fSendTime;          /*    32     4 */
	float                      m_fReceiveTime;       /*    36     4 */
	int                        m_nFPSCount;          /*    40     4 */
	float                      m_fAverageFT;         /*    44     4 */
	float                      m_fAvgFrameRate;      /*    48     4 */
	int                        m_nSentFinish;        /*    52     4 */
	float                      m_fStageStarted;      /*    56     4 */
	float                      m_StoredLatency;      /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	float                      m_StoredPacketLoss;   /*    64     4 */
	int                        m_nStoredHopCount;    /*    68     4 */
	int                        m_nTraceDone;         /*    72     4 */
	int                        m_nObjects;           /*    76     4 */
	int                        m_nScoreComputed;     /*    80     4 */
	int                        m_nCompositeScore;    /*    84     4 */
	void CHudBenchmark(class CHudBenchmark *, class CHudBenchmark &); /* linkage=_ZN13CHudBenchmarkC4EOS_ */

	void CHudBenchmark(class CHudBenchmark *, const class CHudBenchmark  &); /* linkage=_ZN13CHudBenchmarkC4ERKS_ */

	void CHudBenchmark(class CHudBenchmark *); /* linkage=_ZN13CHudBenchmarkC4Ev */

	virtual int Init(class CHudBenchmark *); /* linkage=_ZN13CHudBenchmark4InitEv */

	virtual int VidInit(class CHudBenchmark *); /* linkage=_ZN13CHudBenchmark7VidInitEv */

	virtual int Draw(class CHudBenchmark *, float); /* linkage=_ZN13CHudBenchmark4DrawEf */

	void SetScore(class CHudBenchmark *, float); /* linkage=_ZN13CHudBenchmark8SetScoreEf */

	virtual void Think(class CHudBenchmark *); /* linkage=_ZN13CHudBenchmark5ThinkEv */

	void StartNextSection(class CHudBenchmark *, int); /* linkage=_ZN13CHudBenchmark16StartNextSectionEi */

	int MsgFunc_Bench(class CHudBenchmark *, const char  *, int, void *); /* linkage=_ZN13CHudBenchmark13MsgFunc_BenchEPKciPv */

	void CountFrame(class CHudBenchmark *, float); /* linkage=_ZN13CHudBenchmark10CountFrameEf */

	int GetObjects(class CHudBenchmark *); /* linkage=_ZN13CHudBenchmark10GetObjectsEv */

	void SetCompositeScore(class CHudBenchmark *); /* linkage=_ZN13CHudBenchmark17SetCompositeScoreEv */

	void Restart(class CHudBenchmark *); /* linkage=_ZN13CHudBenchmark7RestartEv */

	int Bench_ScoreForValue(class CHudBenchmark *, int, float); /* linkage=_ZN13CHudBenchmark19Bench_ScoreForValueEif */

	virtual void ~CHudBenchmark(class CHudBenchmark *, int); /* linkage=_ZN13CHudBenchmarkD4Ev */

	/* vtable has 4 entries: {
	   [2] = Init(_ZN13CHudBenchmark4InitEv), 
	   [3] = VidInit(_ZN13CHudBenchmark7VidInitEv), 
	   [4] = Draw(_ZN13CHudBenchmark4DrawEf), 
	   [5] = Think(_ZN13CHudBenchmark5ThinkEv), 
	} */
	/* size: 88, cachelines: 2, members: 18 */
	/* last cacheline: 24 bytes */
};
struct net_response_s {
	int                        error;                /*     0     4 */
	int                        context;              /*     4     4 */
	int                        type;                 /*     8     4 */
	netadr_t                   remote_address;       /*    12    20 */
	double                     ping;                 /*    32     8 */
	void *                     response;             /*    40     4 */

	/* size: 44, cachelines: 1, members: 6 */
	/* last cacheline: 44 bytes */
} __attribute__((__packed__));
struct net_status_s {
	int                        connected;            /*     0     4 */
	netadr_t                   local_address;        /*     4    20 */
	netadr_t                   remote_address;       /*    24    20 */
	int                        packet_loss;          /*    44     4 */
	double                     latency;              /*    48     8 */
	double                     connection_time;      /*    56     8 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	double                     rate;                 /*    64     8 */

	/* size: 72, cachelines: 2, members: 7 */
	/* last cacheline: 8 bytes */
};
struct trace_options_s {
	unsigned char              ucTTL;                /*     0     1 */
	unsigned char              a[7];                 /*     1     7 */

	/* size: 8, cachelines: 1, members: 2 */
	/* last cacheline: 8 bytes */
};
struct kblist_s {
	class kblist_s *           next;                 /*     0     4 */
	kbutton_t *                pkey;                 /*     4     4 */
	char                       name[32];             /*     8    32 */

	/* size: 40, cachelines: 1, members: 3 */
	/* last cacheline: 40 bytes */
};
class CInterpolation {
	int ()(void) * *           _vptr.CInterpolation; /*     0     4 */
protected:

	class Vector              m_StartPoint;          /*     4    12 */
	class Vector              m_EndPoint;            /*    16    12 */
	class Vector              m_StartAngle;          /*    28    12 */
	class Vector              m_EndAngle;            /*    40    12 */
	class Vector              m_Center;              /*    52    12 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	float                      m_StartFov;           /*    64     4 */
	float                      m_EndFov;             /*    68     4 */
	bool                       m_SmoothStart;        /*    72     1 */
	bool                       m_SmoothEnd;          /*    73     1 */
	void CInterpolation(class CInterpolation *, const class CInterpolation  &); /* linkage=_ZN14CInterpolationC4ERKS_ */

	void CInterpolation(class CInterpolation *); /* linkage=_ZN14CInterpolationC4Ev */

	virtual void ~CInterpolation(class CInterpolation *, int); /* linkage=_ZN14CInterpolationD4Ev */

	void SetWaypoints(class CInterpolation *, class Vector *, class Vector, class Vector, class Vector *); /* linkage=_ZN14CInterpolation12SetWaypointsEP6VectorS0_S0_S1_ */

	void SetViewAngles(class CInterpolation *, class Vector, class Vector); /* linkage=_ZN14CInterpolation13SetViewAnglesE6VectorS0_ */

	void SetFOVs(class CInterpolation *, float, float); /* linkage=_ZN14CInterpolation7SetFOVsEff */

	void SetSmoothing(class CInterpolation *, bool, bool); /* linkage=_ZN14CInterpolation12SetSmoothingEbb */

	void Interpolate(class CInterpolation *, float, class Vector &, class Vector &, float *); /* linkage=_ZN14CInterpolation11InterpolateEfR6VectorS1_Pf */

	void BezierInterpolatePoint(class CInterpolation *, float, class Vector &); /* linkage=_ZN14CInterpolation22BezierInterpolatePointEfR6Vector */

	void InterpolateAngle(class CInterpolation *, float, class Vector &); /* linkage=_ZN14CInterpolation16InterpolateAngleEfR6Vector */


	/* size: 76, cachelines: 2, members: 10 */
	/* padding: 2 */
	/* last cacheline: 12 bytes */
};
class CHudMenu : public CHudBase {
public:

	/* class CHudBase            <ancestor>; */      /*     0    20 */
	int                        m_fMenuDisplayed;     /*    20     4 */
	int                        m_bitsValidSlots;     /*    24     4 */
	float                      m_flShutoffTime;      /*    28     4 */
	int                        m_fWaitingForMore;    /*    32     4 */
	void CHudMenu(class CHudMenu *, class CHudMenu &); /* linkage=_ZN8CHudMenuC4EOS_ */

	void CHudMenu(class CHudMenu *, const class CHudMenu  &); /* linkage=_ZN8CHudMenuC4ERKS_ */

	void CHudMenu(class CHudMenu *); /* linkage=_ZN8CHudMenuC4Ev */

	virtual int Init(class CHudMenu *); /* linkage=_ZN8CHudMenu4InitEv */

	virtual void InitHUDData(class CHudMenu *); /* linkage=_ZN8CHudMenu11InitHUDDataEv */

	virtual int VidInit(class CHudMenu *); /* linkage=_ZN8CHudMenu7VidInitEv */

	virtual void Reset(class CHudMenu *); /* linkage=_ZN8CHudMenu5ResetEv */

	virtual int Draw(class CHudMenu *, float); /* linkage=_ZN8CHudMenu4DrawEf */

	int MsgFunc_ShowMenu(class CHudMenu *, const char  *, int, void *); /* linkage=_ZN8CHudMenu16MsgFunc_ShowMenuEPKciPv */

	void SelectMenuItem(class CHudMenu *, int); /* linkage=_ZN8CHudMenu14SelectMenuItemEi */

	virtual void ~CHudMenu(class CHudMenu *, int); /* linkage=_ZN8CHudMenuD4Ev */

	/* vtable has 5 entries: {
	   [2] = Init(_ZN8CHudMenu4InitEv), 
	   [7] = InitHUDData(_ZN8CHudMenu11InitHUDDataEv), 
	   [3] = VidInit(_ZN8CHudMenu7VidInitEv), 
	   [6] = Reset(_ZN8CHudMenu5ResetEv), 
	   [4] = Draw(_ZN8CHudMenu4DrawEf), 
	} */
	/* size: 36, cachelines: 1, members: 5 */
	/* last cacheline: 36 bytes */
};
struct message_parms_t {
	client_textmessage_t *     pMessage;             /*     0     4 */
	float                      time;                 /*     4     4 */
	int                        x;                    /*     8     4 */
	int                        y;                    /*    12     4 */
	int                        totalWidth;           /*    16     4 */
	int                        totalHeight;          /*    20     4 */
	int                        width;                /*    24     4 */
	int                        lines;                /*    28     4 */
	int                        lineLength;           /*    32     4 */
	int                        length;               /*    36     4 */
	int                        r;                    /*    40     4 */
	int                        g;                    /*    44     4 */
	int                        b;                    /*    48     4 */
	int                        text;                 /*    52     4 */
	int                        fadeBlend;            /*    56     4 */
	float                      charTime;             /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	float                      fadeTime;             /*    64     4 */

	/* size: 68, cachelines: 2, members: 17 */
	/* last cacheline: 4 bytes */
};
class CHudMessage : public CHudBase {
public:

	/* class CHudBase            <ancestor>; */      /*     0    20 */
private:

	client_textmessage_t *     m_pMessages[16];      /*    20    64 */
	/* --- cacheline 1 boundary (64 bytes) was 20 bytes ago --- */
	float                      m_startTime[16];      /*    84    64 */
	/* --- cacheline 2 boundary (128 bytes) was 20 bytes ago --- */
	struct message_parms_t     m_parms;              /*   148    68 */
	/* --- cacheline 3 boundary (192 bytes) was 24 bytes ago --- */
	float                      m_gameTitleTime;      /*   216     4 */
	client_textmessage_t *     m_pGameTitle;         /*   220     4 */
	int                        m_HUD_title_life;     /*   224     4 */
	int                        m_HUD_title_half;     /*   228     4 */
	bool                       m_bEndAfterMessage;   /*   232     1 */
	void CHudMessage(class CHudMessage *, class CHudMessage &); /* linkage=_ZN11CHudMessageC4EOS_ */

	void CHudMessage(class CHudMessage *, const class CHudMessage  &); /* linkage=_ZN11CHudMessageC4ERKS_ */

	void CHudMessage(class CHudMessage *); /* linkage=_ZN11CHudMessageC4Ev */

	virtual int Init(class CHudMessage *); /* linkage=_ZN11CHudMessage4InitEv */

	virtual int VidInit(class CHudMessage *); /* linkage=_ZN11CHudMessage7VidInitEv */

	virtual int Draw(class CHudMessage *, float); /* linkage=_ZN11CHudMessage4DrawEf */

	int MsgFunc_HudText(class CHudMessage *, const char  *, int, void *); /* linkage=_ZN11CHudMessage15MsgFunc_HudTextEPKciPv */

	int MsgFunc_HudTextPro(class CHudMessage *, const char  *, int, void *); /* linkage=_ZN11CHudMessage18MsgFunc_HudTextProEPKciPv */

	int MsgFunc_GameTitle(class CHudMessage *, const char  *, int, void *); /* linkage=_ZN11CHudMessage17MsgFunc_GameTitleEPKciPv */

	float FadeBlend(class CHudMessage *, float, float, float, float); /* linkage=_ZN11CHudMessage9FadeBlendEffff */

	int XPosition(class CHudMessage *, float, int, int); /* linkage=_ZN11CHudMessage9XPositionEfii */

	int YPosition(class CHudMessage *, float, int); /* linkage=_ZN11CHudMessage9YPositionEfi */

	void MessageAdd(class CHudMessage *, const char  *, float); /* linkage=_ZN11CHudMessage10MessageAddEPKcf */

	void MessageAdd(class CHudMessage *, client_textmessage_t *); /* linkage=_ZN11CHudMessage10MessageAddEP20client_textmessage_s */

	void MessageDrawScan(class CHudMessage *, client_textmessage_t *, float); /* linkage=_ZN11CHudMessage15MessageDrawScanEP20client_textmessage_sf */

	void MessageScanStart(class CHudMessage *); /* linkage=_ZN11CHudMessage16MessageScanStartEv */

	void MessageScanNextChar(class CHudMessage *); /* linkage=_ZN11CHudMessage19MessageScanNextCharEv */

	virtual void Reset(class CHudMessage *); /* linkage=_ZN11CHudMessage5ResetEv */

	virtual void ~CHudMessage(class CHudMessage *, int); /* linkage=_ZN11CHudMessageD4Ev */

	/* vtable has 4 entries: {
	   [2] = Init(_ZN11CHudMessage4InitEv), 
	   [3] = VidInit(_ZN11CHudMessage7VidInitEv), 
	   [4] = Draw(_ZN11CHudMessage4DrawEf), 
	   [6] = Reset(_ZN11CHudMessage5ResetEv), 
	} */
	/* size: 236, cachelines: 4, members: 9 */
	/* padding: 3 */
	/* last cacheline: 44 bytes */
};
class CHudSayText : public CHudBase {
public:

	/* class CHudBase            <ancestor>; */      /*     0    20 */
private:

	class cvar_s *             m_HUD_saytext;        /*    20     4 */
	class cvar_s *             m_HUD_saytext_time;   /*    24     4 */
	void CHudSayText(class CHudSayText *, class CHudSayText &); /* linkage=_ZN11CHudSayTextC4EOS_ */

	void CHudSayText(class CHudSayText *, const class CHudSayText  &); /* linkage=_ZN11CHudSayTextC4ERKS_ */

	void CHudSayText(class CHudSayText *); /* linkage=_ZN11CHudSayTextC4Ev */

	virtual int Init(class CHudSayText *); /* linkage=_ZN11CHudSayText4InitEv */

	virtual void InitHUDData(class CHudSayText *); /* linkage=_ZN11CHudSayText11InitHUDDataEv */

	virtual int VidInit(class CHudSayText *); /* linkage=_ZN11CHudSayText7VidInitEv */

	virtual int Draw(class CHudSayText *, float); /* linkage=_ZN11CHudSayText4DrawEf */

	int MsgFunc_SayText(class CHudSayText *, const char  *, int, void *); /* linkage=_ZN11CHudSayText15MsgFunc_SayTextEPKciPv */

	void SayTextPrint(class CHudSayText *, const char  *, int, int); /* linkage=_ZN11CHudSayText12SayTextPrintEPKcii */

	void EnsureTextFitsInOneLineAndWrapIfHaveTo(class CHudSayText *, int); /* linkage=_ZN11CHudSayText38EnsureTextFitsInOneLineAndWrapIfHaveToEi */

	virtual void ~CHudSayText(class CHudSayText *, int); /* linkage=_ZN11CHudSayTextD4Ev */

	/* vtable has 4 entries: {
	   [2] = Init(_ZN11CHudSayText4InitEv), 
	   [7] = InitHUDData(_ZN11CHudSayText11InitHUDDataEv), 
	   [3] = VidInit(_ZN11CHudSayText7VidInitEv), 
	   [4] = Draw(_ZN11CHudSayText4DrawEf), 
	} */
	/* size: 28, cachelines: 1, members: 3 */
	/* last cacheline: 28 bytes */
};
class CHudStatusIcons : public CHudBase {
	enum {
		MAX_ICONSPRITENAME_LENGTH = 24,
		MAX_ICONSPRITES           = 4,
	};

	struct {
		char                       szSpriteName[24];     /*     0    24 */
		HANDLE_SPRITE              spr;                  /*    24     4 */
		wrect_t                    rc;                   /*    28    16 */
		unsigned char              r;                    /*    44     1 */
		unsigned char              g;                    /*    45     1 */
		unsigned char              b;                    /*    46     1 */

		/* size: 48, cachelines: 1, members: 6 */
		/* padding: 1 */
		/* last cacheline: 48 bytes */
	};

public:

	/* class CHudBase            <ancestor>; */      /*     0    20 */
private:

	struct {
		char               szSpriteName[24];     /*    20    24 */
		HANDLE_SPRITE      spr;                  /*    44     4 */
		wrect_t            rc;                   /*    48    16 */
		/* --- cacheline 1 boundary (64 bytes) --- */
		unsigned char      r;                    /*    64     1 */
		unsigned char      g;                    /*    65     1 */
		unsigned char      b;                    /*    66     1 */
	} m_IconList[4]; /*    20   192 */
	void CHudStatusIcons(class CHudStatusIcons *, class CHudStatusIcons &); /* linkage=_ZN15CHudStatusIconsC4EOS_ */

	void CHudStatusIcons(class CHudStatusIcons *, const class CHudStatusIcons  &); /* linkage=_ZN15CHudStatusIconsC4ERKS_ */

	void CHudStatusIcons(class CHudStatusIcons *); /* linkage=_ZN15CHudStatusIconsC4Ev */

	virtual int Init(class CHudStatusIcons *); /* linkage=_ZN15CHudStatusIcons4InitEv */

	virtual int VidInit(class CHudStatusIcons *); /* linkage=_ZN15CHudStatusIcons7VidInitEv */

	virtual void Reset(class CHudStatusIcons *); /* linkage=_ZN15CHudStatusIcons5ResetEv */

	virtual int Draw(class CHudStatusIcons *, float); /* linkage=_ZN15CHudStatusIcons4DrawEf */

	int MsgFunc_StatusIcon(class CHudStatusIcons *, const char  *, int, void *); /* linkage=_ZN15CHudStatusIcons18MsgFunc_StatusIconEPKciPv */

	void EnableIcon(class CHudStatusIcons *, char *, unsigned char, unsigned char, unsigned char); /* linkage=_ZN15CHudStatusIcons10EnableIconEPchhh */

	void DisableIcon(class CHudStatusIcons *, char *); /* linkage=_ZN15CHudStatusIcons11DisableIconEPc */

	virtual void ~CHudStatusIcons(class CHudStatusIcons *, int); /* linkage=_ZN15CHudStatusIconsD4Ev */

	/* vtable has 4 entries: {
	   [2] = Init(_ZN15CHudStatusIcons4InitEv), 
	   [3] = VidInit(_ZN15CHudStatusIcons7VidInitEv), 
	   [6] = Reset(_ZN15CHudStatusIcons5ResetEv), 
	   [4] = Draw(_ZN15CHudStatusIcons4DrawEf), 
	} */
	/* size: 212, cachelines: 4, members: 2 */
	/* last cacheline: 20 bytes */
};
class CHudStatusBar : public CHudBase {
	enum {
		MAX_STATUSTEXT_LENGTH = 128,
		MAX_STATUSBAR_VALUES  = 8,
		MAX_STATUSBAR_LINES   = 3,
	};

public:

	/* class CHudBase            <ancestor>; */      /*     0    20 */
protected:

	char                       m_szStatusText[3][128]; /*    20   384 */
	/* --- cacheline 6 boundary (384 bytes) was 20 bytes ago --- */
	char                       m_szStatusBar[3][128]; /*   404   384 */
	/* --- cacheline 12 boundary (768 bytes) was 20 bytes ago --- */
	int                        m_iStatusValues[8];   /*   788    32 */
	int                        m_bReparseString;     /*   820     4 */
	float *                    m_pflNameColors[3];   /*   824    12 */
	void CHudStatusBar(class CHudStatusBar *, class CHudStatusBar &); /* linkage=_ZN13CHudStatusBarC4EOS_ */

	void CHudStatusBar(class CHudStatusBar *, const class CHudStatusBar  &); /* linkage=_ZN13CHudStatusBarC4ERKS_ */

	void CHudStatusBar(class CHudStatusBar *); /* linkage=_ZN13CHudStatusBarC4Ev */

	virtual int Init(class CHudStatusBar *); /* linkage=_ZN13CHudStatusBar4InitEv */

	virtual int VidInit(class CHudStatusBar *); /* linkage=_ZN13CHudStatusBar7VidInitEv */

	virtual int Draw(class CHudStatusBar *, float); /* linkage=_ZN13CHudStatusBar4DrawEf */

	virtual void Reset(class CHudStatusBar *); /* linkage=_ZN13CHudStatusBar5ResetEv */

	void ParseStatusString(class CHudStatusBar *, int); /* linkage=_ZN13CHudStatusBar17ParseStatusStringEi */

	int MsgFunc_StatusText(class CHudStatusBar *, const char  *, int, void *); /* linkage=_ZN13CHudStatusBar18MsgFunc_StatusTextEPKciPv */

	int MsgFunc_StatusValue(class CHudStatusBar *, const char  *, int, void *); /* linkage=_ZN13CHudStatusBar19MsgFunc_StatusValueEPKciPv */

	virtual void ~CHudStatusBar(class CHudStatusBar *, int); /* linkage=_ZN13CHudStatusBarD4Ev */

	/* vtable has 4 entries: {
	   [2] = Init(_ZN13CHudStatusBar4InitEv), 
	   [3] = VidInit(_ZN13CHudStatusBar7VidInitEv), 
	   [4] = Draw(_ZN13CHudStatusBar4DrawEf), 
	   [6] = Reset(_ZN13CHudStatusBar5ResetEv), 
	} */
	/* size: 836, cachelines: 14, members: 6 */
	/* last cacheline: 4 bytes */
};
class CStudioModelRenderer {
	int ()(void) * *           _vptr.CStudioModelRenderer; /*     0     4 */
	double                     m_clTime;             /*     4     8 */
	double                     m_clOldTime;          /*    12     8 */
	int                        m_fDoInterp;          /*    20     4 */
	int                        m_fGaitEstimation;    /*    24     4 */
	int                        m_nFrameCount;        /*    28     4 */
	cvar_t *                   m_pCvarHiModels;      /*    32     4 */
	cvar_t *                   m_pCvarDeveloper;     /*    36     4 */
	cvar_t *                   m_pCvarDrawEntities;  /*    40     4 */
	cl_entity_t *              m_pCurrentEntity;     /*    44     4 */
	model_t *                  m_pRenderModel;       /*    48     4 */
	player_info_t *            m_pPlayerInfo;        /*    52     4 */
	int                        m_nPlayerIndex;       /*    56     4 */
	float                      m_flGaitMovement;     /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	struct {
		int        id;                   /*     0     4 */
		int        version;              /*     4     4 */
		char       name[64];             /*     8    64 */
		int        length;               /*    72     4 */
		class Vector eyeposition;        /*    76    12 */
		class Vector min;                /*    88    12 */
		class Vector max;                /*   100    12 */
		class Vector bbmin;              /*   112    12 */
		class Vector bbmax;              /*   124    12 */
		/* --- cacheline 2 boundary (128 bytes) was 8 bytes ago --- */
		int        flags;                /*   136     4 */
		int        numbones;             /*   140     4 */
		int        boneindex;            /*   144     4 */
		int        numbonecontrollers;   /*   148     4 */
		int        bonecontrollerindex;  /*   152     4 */
		int        numhitboxes;          /*   156     4 */
		int        hitboxindex;          /*   160     4 */
		int        numseq;               /*   164     4 */
		int        seqindex;             /*   168     4 */
		int        numseqgroups;         /*   172     4 */
		int        seqgroupindex;        /*   176     4 */
		int        numtextures;          /*   180     4 */
		int        textureindex;         /*   184     4 */
		int        texturedataindex;     /*   188     4 */
		/* --- cacheline 3 boundary (192 bytes) --- */
		int        numskinref;           /*   192     4 */
		int        numskinfamilies;      /*   196     4 */
		int        skinindex;            /*   200     4 */
		int        numbodyparts;         /*   204     4 */
		int        bodypartindex;        /*   208     4 */
		int        numattachments;       /*   212     4 */
		int        attachmentindex;      /*   216     4 */
		int        soundtable;           /*   220     4 */
		int        soundindex;           /*   224     4 */
		int        soundgroups;          /*   228     4 */
		int        soundgroupindex;      /*   232     4 */
		int        numtransitions;       /*   236     4 */
		int        transitionindex;      /*   240     4 */
		void (class  *);

	} * m_pStudioHeader; /*    64     4 */
	mstudiobodyparts_t *       m_pBodyPart;          /*    68     4 */
	mstudiomodel_t *           m_pSubModel;          /*    72     4 */
	int                        m_nTopColor;          /*    76     4 */
	int                        m_nBottomColor;       /*    80     4 */
	model_t *                  m_pChromeSprite;      /*    84     4 */
	int                        m_nCachedBones;       /*    88     4 */
	char                       m_nCachedBoneNames[128][32]; /*    92  4096 */
	/* --- cacheline 65 boundary (4160 bytes) was 28 bytes ago --- */
	float                      m_rgCachedBoneTransform[128][3][4]; /*  4188  6144 */
	/* --- cacheline 161 boundary (10304 bytes) was 28 bytes ago --- */
	float                      m_rgCachedLightTransform[128][3][4]; /* 10332  6144 */
	/* --- cacheline 257 boundary (16448 bytes) was 28 bytes ago --- */
	float                      m_fSoftwareXScale;    /* 16476     4 */
	float                      m_fSoftwareYScale;    /* 16480     4 */
	float                      m_vUp[3];             /* 16484    12 */
	float                      m_vRight[3];          /* 16496    12 */
	float                      m_vNormal[3];         /* 16508    12 */
	/* --- cacheline 258 boundary (16512 bytes) was 8 bytes ago --- */
	float                      m_vRenderOrigin[3];   /* 16520    12 */
	int *                      m_pStudioModelCount;  /* 16532     4 */
	int *                      m_pModelsDrawn;       /* 16536     4 */
	float *                    m_protationmatrix;    /* 16540     4 */
	float *                    m_paliastransform;    /* 16544     4 */
	float *                    m_pbonetransform;     /* 16548     4 */
	float *                    m_plighttransform;    /* 16552     4 */
	void CStudioModelRenderer(class CStudioModelRenderer *, const class CStudioModelRenderer  &); /* linkage=_ZN20CStudioModelRendererC4ERKS_ */

	void CStudioModelRenderer(class CStudioModelRenderer *); /* linkage=_ZN20CStudioModelRendererC4Ev */

	virtual void ~CStudioModelRenderer(class CStudioModelRenderer *, int); /* linkage=_ZN20CStudioModelRendererD4Ev */

	virtual void Init(class CStudioModelRenderer *); /* linkage=_ZN20CStudioModelRenderer4InitEv */

	virtual int StudioDrawModel(class CStudioModelRenderer *, int); /* linkage=_ZN20CStudioModelRenderer15StudioDrawModelEi */

	virtual int StudioDrawPlayer(class CStudioModelRenderer *, int, entity_state_t *); /* linkage=_ZN20CStudioModelRenderer16StudioDrawPlayerEiP14entity_state_s */

	virtual mstudioanim_t * StudioGetAnim(class CStudioModelRenderer *, model_t *, class  *); /* linkage=_ZN20CStudioModelRenderer13StudioGetAnimEP7model_sP16mstudioseqdesc_t */

	virtual void StudioSetUpTransform(class CStudioModelRenderer *, int); /* linkage=_ZN20CStudioModelRenderer20StudioSetUpTransformEi */

	virtual void StudioSetupBones(class CStudioModelRenderer *); /* linkage=_ZN20CStudioModelRenderer16StudioSetupBonesEv */

	virtual void StudioCalcAttachments(class CStudioModelRenderer *); /* linkage=_ZN20CStudioModelRenderer21StudioCalcAttachmentsEv */

	virtual void StudioSaveBones(class CStudioModelRenderer *); /* linkage=_ZN20CStudioModelRenderer15StudioSaveBonesEv */

	virtual void StudioMergeBones(class CStudioModelRenderer *, model_t *); /* linkage=_ZN20CStudioModelRenderer16StudioMergeBonesEP7model_s */

	virtual float StudioEstimateInterpolant(class CStudioModelRenderer *); /* linkage=_ZN20CStudioModelRenderer25StudioEstimateInterpolantEv */

	virtual float StudioEstimateFrame(class CStudioModelRenderer *, class  *); /* linkage=_ZN20CStudioModelRenderer19StudioEstimateFrameEP16mstudioseqdesc_t */

	virtual void StudioFxTransform(class CStudioModelRenderer *, cl_entity_t *, float *); /* linkage=_ZN20CStudioModelRenderer17StudioFxTransformEP11cl_entity_sPA4_f */

	virtual void StudioSlerpBones(class CStudioModelRenderer *, vec4_t *, float *, vec4_t *, float *, float); /* linkage=_ZN20CStudioModelRenderer16StudioSlerpBonesEPA4_fPA3_fS1_S3_f */

	virtual void StudioCalcBoneAdj(class CStudioModelRenderer *, float, float *, const byte  *, const byte  *, byte); /* linkage=_ZN20CStudioModelRenderer17StudioCalcBoneAdjEfPfPKhS2_h */

	virtual void StudioCalcBoneQuaterion(class CStudioModelRenderer *, int, float, mstudiobone_t *, mstudioanim_t *, float *, float *); /* linkage=_ZN20CStudioModelRenderer23StudioCalcBoneQuaterionEifP13mstudiobone_tP13mstudioanim_tPfS4_ */

	virtual void StudioCalcBonePosition(class CStudioModelRenderer *, int, float, mstudiobone_t *, mstudioanim_t *, float *, float *); /* linkage=_ZN20CStudioModelRenderer22StudioCalcBonePositionEifP13mstudiobone_tP13mstudioanim_tPfS4_ */

	virtual void StudioCalcRotations(class CStudioModelRenderer *, float *, vec4_t *, class  *, mstudioanim_t *, float); /* linkage=_ZN20CStudioModelRenderer19StudioCalcRotationsEPA3_fPA4_fP16mstudioseqdesc_tP13mstudioanim_tf */

	virtual void StudioRenderModel(class CStudioModelRenderer *); /* linkage=_ZN20CStudioModelRenderer17StudioRenderModelEv */

	virtual void StudioRenderFinal(class CStudioModelRenderer *); /* linkage=_ZN20CStudioModelRenderer17StudioRenderFinalEv */

	virtual void StudioRenderFinal_Software(class CStudioModelRenderer *); /* linkage=_ZN20CStudioModelRenderer26StudioRenderFinal_SoftwareEv */

	virtual void StudioRenderFinal_Hardware(class CStudioModelRenderer *); /* linkage=_ZN20CStudioModelRenderer26StudioRenderFinal_HardwareEv */

	virtual void StudioPlayerBlend(class CStudioModelRenderer *, class  *, int *, float *); /* linkage=_ZN20CStudioModelRenderer17StudioPlayerBlendEP16mstudioseqdesc_tPiPf */

	virtual void StudioEstimateGait(class CStudioModelRenderer *, entity_state_t *); /* linkage=_ZN20CStudioModelRenderer18StudioEstimateGaitEP14entity_state_s */

	virtual void StudioProcessGait(class CStudioModelRenderer *, entity_state_t *); /* linkage=_ZN20CStudioModelRenderer17StudioProcessGaitEP14entity_state_s */

	int ReturnDiguisedClass(class CStudioModelRenderer *, int); /* linkage=_ZN20CStudioModelRenderer19ReturnDiguisedClassEi */

	/* vtable has 24 entries: {
	   [2] = Init(_ZN20CStudioModelRenderer4InitEv), 
	   [3] = StudioDrawModel(_ZN20CStudioModelRenderer15StudioDrawModelEi), 
	   [4] = StudioDrawPlayer(_ZN20CStudioModelRenderer16StudioDrawPlayerEiP14entity_state_s), 
	   [5] = StudioGetAnim(_ZN20CStudioModelRenderer13StudioGetAnimEP7model_sP16mstudioseqdesc_t), 
	   [6] = StudioSetUpTransform(_ZN20CStudioModelRenderer20StudioSetUpTransformEi), 
	   [7] = StudioSetupBones(_ZN20CStudioModelRenderer16StudioSetupBonesEv), 
	   [8] = StudioCalcAttachments(_ZN20CStudioModelRenderer21StudioCalcAttachmentsEv), 
	   [9] = StudioSaveBones(_ZN20CStudioModelRenderer15StudioSaveBonesEv), 
	   [10] = StudioMergeBones(_ZN20CStudioModelRenderer16StudioMergeBonesEP7model_s), 
	   [11] = StudioEstimateInterpolant(_ZN20CStudioModelRenderer25StudioEstimateInterpolantEv), 
	   [12] = StudioEstimateFrame(_ZN20CStudioModelRenderer19StudioEstimateFrameEP16mstudioseqdesc_t), 
	   [13] = StudioFxTransform(_ZN20CStudioModelRenderer17StudioFxTransformEP11cl_entity_sPA4_f), 
	   [14] = StudioSlerpBones(_ZN20CStudioModelRenderer16StudioSlerpBonesEPA4_fPA3_fS1_S3_f), 
	   [15] = StudioCalcBoneAdj(_ZN20CStudioModelRenderer17StudioCalcBoneAdjEfPfPKhS2_h), 
	   [16] = StudioCalcBoneQuaterion(_ZN20CStudioModelRenderer23StudioCalcBoneQuaterionEifP13mstudiobone_tP13mstudioanim_tPfS4_), 
	   [17] = StudioCalcBonePosition(_ZN20CStudioModelRenderer22StudioCalcBonePositionEifP13mstudiobone_tP13mstudioanim_tPfS4_), 
	   [18] = StudioCalcRotations(_ZN20CStudioModelRenderer19StudioCalcRotationsEPA3_fPA4_fP16mstudioseqdesc_tP13mstudioanim_tf), 
	   [19] = StudioRenderModel(_ZN20CStudioModelRenderer17StudioRenderModelEv), 
	   [20] = StudioRenderFinal(_ZN20CStudioModelRenderer17StudioRenderFinalEv), 
	   [21] = StudioRenderFinal_Software(_ZN20CStudioModelRenderer26StudioRenderFinal_SoftwareEv), 
	   [22] = StudioRenderFinal_Hardware(_ZN20CStudioModelRenderer26StudioRenderFinal_HardwareEv), 
	   [23] = StudioPlayerBlend(_ZN20CStudioModelRenderer17StudioPlayerBlendEP16mstudioseqdesc_tPiPf), 
	   [24] = StudioEstimateGait(_ZN20CStudioModelRenderer18StudioEstimateGaitEP14entity_state_s), 
	   [25] = StudioProcessGait(_ZN20CStudioModelRenderer17StudioProcessGaitEP14entity_state_s), 
	} */
	/* size: 16556, cachelines: 259, members: 36 */
	/* last cacheline: 44 bytes */
} __attribute__((__packed__));
class CHudTextMessage : public CHudBase {
public:

	/* class CHudBase            <ancestor>; */      /*     0    20 */
	void CHudTextMessage(class CHudTextMessage *, class CHudTextMessage &); /* linkage=_ZN15CHudTextMessageC4EOS_ */

	void CHudTextMessage(class CHudTextMessage *, const class CHudTextMessage  &); /* linkage=_ZN15CHudTextMessageC4ERKS_ */

	void CHudTextMessage(class CHudTextMessage *); /* linkage=_ZN15CHudTextMessageC4Ev */

	virtual int Init(class CHudTextMessage *); /* linkage=_ZN15CHudTextMessage4InitEv */

	char * LocaliseTextString(const char  *, char *, int); /* linkage=_ZN15CHudTextMessage18LocaliseTextStringEPKcPci */

	char * BufferedLocaliseTextString(const char  *); /* linkage=_ZN15CHudTextMessage26BufferedLocaliseTextStringEPKc */

	char * LookupString(class CHudTextMessage *, const char  *, int *); /* linkage=_ZN15CHudTextMessage12LookupStringEPKcPi */

	int MsgFunc_TextMsg(class CHudTextMessage *, const char  *, int, void *); /* linkage=_ZN15CHudTextMessage15MsgFunc_TextMsgEPKciPv */

	virtual void ~CHudTextMessage(class CHudTextMessage *, int); /* linkage=_ZN15CHudTextMessageD4Ev */

	/* vtable has 1 entries: {
	   [2] = Init(_ZN15CHudTextMessage4InitEv), 
	} */
	/* size: 20, cachelines: 1, members: 1 */
	/* last cacheline: 20 bytes */
};
class CHudTrain : public CHudBase {
public:

	/* class CHudBase            <ancestor>; */      /*     0    20 */
private:

	HANDLE_SPRITE              m_hSprite;            /*    20     4 */
	int                        m_iPos;               /*    24     4 */
	void CHudTrain(class CHudTrain *, class CHudTrain &); /* linkage=_ZN9CHudTrainC4EOS_ */

	void CHudTrain(class CHudTrain *, const class CHudTrain  &); /* linkage=_ZN9CHudTrainC4ERKS_ */

	void CHudTrain(class CHudTrain *); /* linkage=_ZN9CHudTrainC4Ev */

	virtual int Init(class CHudTrain *); /* linkage=_ZN9CHudTrain4InitEv */

	virtual int VidInit(class CHudTrain *); /* linkage=_ZN9CHudTrain7VidInitEv */

	virtual int Draw(class CHudTrain *, float); /* linkage=_ZN9CHudTrain4DrawEf */

	int MsgFunc_Train(class CHudTrain *, const char  *, int, void *); /* linkage=_ZN9CHudTrain13MsgFunc_TrainEPKciPv */

	virtual void ~CHudTrain(class CHudTrain *, int); /* linkage=_ZN9CHudTrainD4Ev */

	/* vtable has 3 entries: {
	   [2] = Init(_ZN9CHudTrain4InitEv), 
	   [3] = VidInit(_ZN9CHudTrain7VidInitEv), 
	   [4] = Draw(_ZN9CHudTrain4DrawEf), 
	} */
	/* size: 28, cachelines: 1, members: 3 */
	/* last cacheline: 28 bytes */
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
struct pitchdrift_s {
	float                      pitchvel;             /*     0     4 */
	int                        nodrift;              /*     4     4 */
	float                      driftmove;            /*     8     4 */
	double                     laststop;             /*    12     8 */

	/* size: 20, cachelines: 1, members: 4 */
	/* last cacheline: 20 bytes */
} __attribute__((__packed__));
class CClassMenuPanel : public CMenuPanel {
	enum {
		STRLENMAX_PLAYERSONTEAM = 128,
	};

public:

	/* class CMenuPanel          <ancestor>; */      /*     0   212 */
private:

	/* --- cacheline 3 boundary (192 bytes) was 20 bytes ago --- */
	class CTransparentPanel *  m_pClassInfoPanel[12]; /*   212    48 */
	/* --- cacheline 4 boundary (256 bytes) was 4 bytes ago --- */
	class Label *              m_pPlayers[12];       /*   260    48 */
	class ClassButton *        m_pButtons[12];       /*   308    48 */
	/* --- cacheline 5 boundary (320 bytes) was 36 bytes ago --- */
	class CommandButton *      m_pCancelButton;      /*   356     4 */
	class ScrollPanel *        m_pScrollPanel;       /*   360     4 */
	class CImageLabel *        m_pClassImages[64][12]; /*   364  3072 */
	/* --- cacheline 53 boundary (3392 bytes) was 44 bytes ago --- */
	int                        m_iCurrentInfo;       /*  3436     4 */
	char                       m_sPlayersOnTeamString[128]; /*  3440   128 */
	void CClassMenuPanel(class CClassMenuPanel *, class CClassMenuPanel &); /* linkage=_ZN15CClassMenuPanelC4EOS_ */

	void CClassMenuPanel(class CClassMenuPanel *, const class CClassMenuPanel  &); /* linkage=_ZN15CClassMenuPanelC4ERKS_ */

	void CClassMenuPanel(class CClassMenuPanel *, int, int, int, int, int, int); /* linkage=_ZN15CClassMenuPanelC4Eiiiiii */

	virtual bool SlotInput(class CClassMenuPanel *, int); /* linkage=_ZN15CClassMenuPanel9SlotInputEi */

	virtual void Open(class CClassMenuPanel *); /* linkage=_ZN15CClassMenuPanel4OpenEv */

	virtual void Update(class CClassMenuPanel *); /* linkage=_ZN15CClassMenuPanel6UpdateEv */

	virtual void SetActiveInfo(class CClassMenuPanel *, int); /* linkage=_ZN15CClassMenuPanel13SetActiveInfoEi */

	virtual void Initialize(class CClassMenuPanel *); /* linkage=_ZN15CClassMenuPanel10InitializeEv */

	virtual void Reset(class CClassMenuPanel *); /* linkage=_ZN15CClassMenuPanel5ResetEv */

	/* vtable has 6 entries: {
	   [130] = SlotInput(_ZN15CClassMenuPanel9SlotInputEi), 
	   [128] = Open(_ZN15CClassMenuPanel4OpenEv), 
	   [132] = Update(_ZN15CClassMenuPanel6UpdateEv), 
	   [131] = SetActiveInfo(_ZN15CClassMenuPanel13SetActiveInfoEi), 
	   [133] = Initialize(_ZN15CClassMenuPanel10InitializeEv), 
	   [127] = Reset(_ZN15CClassMenuPanel5ResetEv), 
	} */
	/* size: 3568, cachelines: 56, members: 9 */
	/* last cacheline: 48 bytes */
};
class CMenuPanel : public CTransparentPanel {
public:

	/* class CTransparentPanel   <ancestor>; */      /*     0   192 */

	/* XXX last struct has 1 hole */
private:


	/* --- cacheline 3 boundary (192 bytes) --- */
	class CMenuPanel *         m_pNextMenu;          /*   192     4 */
	int                        m_iMenuID;            /*   196     4 */
	int                        m_iRemoveMe;          /*   200     4 */
	int                        m_iIsActive;          /*   204     4 */
	float                      m_flOpenTime;         /*   208     4 */
	void ~CMenuPanel(class CMenuPanel *, int); /* linkage=_ZN10CMenuPanelD4Ev */

	void CMenuPanel(class CMenuPanel *, class CMenuPanel &); /* linkage=_ZN10CMenuPanelC4EOS_ */

	void CMenuPanel(class CMenuPanel *, const class CMenuPanel  &); /* linkage=_ZN10CMenuPanelC4ERKS_ */

	void CMenuPanel(class CMenuPanel *, int, int, int, int, int); /* linkage=_ZN10CMenuPanelC4Eiiiii */

	void CMenuPanel(class CMenuPanel *, int, int, int, int, int, int); /* linkage=_ZN10CMenuPanelC4Eiiiiii */

	virtual void Reset(class CMenuPanel *); /* linkage=_ZN10CMenuPanel5ResetEv */

	void SetNextMenu(class CMenuPanel *, class CMenuPanel *); /* linkage=_ZN10CMenuPanel11SetNextMenuEPS_ */

	void SetMenuID(class CMenuPanel *, int); /* linkage=_ZN10CMenuPanel9SetMenuIDEi */

	void SetActive(class CMenuPanel *, int); /* linkage=_ZN10CMenuPanel9SetActiveEi */

	virtual void Open(class CMenuPanel *); /* linkage=_ZN10CMenuPanel4OpenEv */

	virtual void Close(class CMenuPanel *); /* linkage=_ZN10CMenuPanel5CloseEv */

	int ShouldBeRemoved(class CMenuPanel *); /* linkage=_ZN10CMenuPanel15ShouldBeRemovedEv */

	class CMenuPanel * GetNextMenu(class CMenuPanel *); /* linkage=_ZN10CMenuPanel11GetNextMenuEv */

	int GetMenuID(class CMenuPanel *); /* linkage=_ZN10CMenuPanel9GetMenuIDEv */

	int IsActive(class CMenuPanel *); /* linkage=_ZN10CMenuPanel8IsActiveEv */

	float GetOpenTime(class CMenuPanel *); /* linkage=_ZN10CMenuPanel11GetOpenTimeEv */

	virtual bool SlotInput(class CMenuPanel *, int); /* linkage=_ZN10CMenuPanel9SlotInputEi */

	virtual void SetActiveInfo(class CMenuPanel *, int); /* linkage=_ZN10CMenuPanel13SetActiveInfoEi */

	/* vtable has 5 entries: {
	   [127] = Reset(_ZN10CMenuPanel5ResetEv), 
	   [128] = Open(_ZN10CMenuPanel4OpenEv), 
	   [129] = Close(_ZN10CMenuPanel5CloseEv), 
	   [130] = SlotInput(_ZN10CMenuPanel9SlotInputEi), 
	   [131] = SetActiveInfo(_ZN10CMenuPanel13SetActiveInfoEi), 
	} */
	/* size: 212, cachelines: 4, members: 6 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 20 bytes */
};
class CTransparentPanel : public Panel {

	/* XXX 188 bytes hole, try to pack */
public:


	/* class Panel               <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 2 boundary (128 bytes) was 60 bytes ago --- */
	int                        m_iTransparency;      /*   188     4 */
	void ~CTransparentPanel(class CTransparentPanel *, int); /* linkage=_ZN17CTransparentPanelD4Ev */

	void CTransparentPanel(class CTransparentPanel *, class CTransparentPanel &); /* linkage=_ZN17CTransparentPanelC4EOS_ */

	void CTransparentPanel(class CTransparentPanel *, const class CTransparentPanel  &); /* linkage=_ZN17CTransparentPanelC4ERKS_ */

	void CTransparentPanel(class CTransparentPanel *, int, int, int, int, int); /* linkage=_ZN17CTransparentPanelC4Eiiiii */

	virtual void paintBackground(class CTransparentPanel *); /* linkage=_ZN17CTransparentPanel15paintBackgroundEv */

	/* vtable has 1 entries: {
	   [111] = paintBackground(_ZN17CTransparentPanel15paintBackgroundEv), 
	} */
	/* size: 192, cachelines: 3, members: 2 */
	/* sum members: 4, holes: 1, sum holes: 188 */
};
class CMenuHandler_TextWindow : public ActionSignal {
public:

	/* class ActionSignal        <ancestor>; */      /*     0     4 */
private:

	int                        m_iState;             /*     4     4 */
	void CMenuHandler_TextWindow(class CMenuHandler_TextWindow *, class CMenuHandler_TextWindow &); /* linkage=_ZN23CMenuHandler_TextWindowC4EOS_ */

	void CMenuHandler_TextWindow(class CMenuHandler_TextWindow *, const class CMenuHandler_TextWindow  &); /* linkage=_ZN23CMenuHandler_TextWindowC4ERKS_ */

	void CMenuHandler_TextWindow(class CMenuHandler_TextWindow *, int); /* linkage=_ZN23CMenuHandler_TextWindowC4Ei */

	virtual void actionPerformed(class CMenuHandler_TextWindow *, class Panel *); /* linkage=_ZN23CMenuHandler_TextWindow15actionPerformedEPN4vgui5PanelE */

	/* vtable has 1 entries: {
	   [0] = actionPerformed(_ZN23CMenuHandler_TextWindow15actionPerformedEPN4vgui5PanelE), 
	} */
	/* size: 8, cachelines: 1, members: 2 */
	/* last cacheline: 8 bytes */
};
class CMenuHandler_StringCommand : public ActionSignal {
public:

	/* class ActionSignal        <ancestor>; */      /*     0     4 */
protected:

	char                       m_pszCommand[256];    /*     4   256 */
	/* --- cacheline 4 boundary (256 bytes) was 4 bytes ago --- */
	int                        m_iCloseVGUIMenu;     /*   260     4 */
	void ~CMenuHandler_StringCommand(class CMenuHandler_StringCommand *, int); /* linkage=_ZN26CMenuHandler_StringCommandD4Ev */

	void CMenuHandler_StringCommand(class CMenuHandler_StringCommand *, class CMenuHandler_StringCommand &); /* linkage=_ZN26CMenuHandler_StringCommandC4EOS_ */

	void CMenuHandler_StringCommand(class CMenuHandler_StringCommand *, const class CMenuHandler_StringCommand  &); /* linkage=_ZN26CMenuHandler_StringCommandC4ERKS_ */

	void CMenuHandler_StringCommand(class CMenuHandler_StringCommand *, char *); /* linkage=_ZN26CMenuHandler_StringCommandC4EPc */

	void CMenuHandler_StringCommand(class CMenuHandler_StringCommand *, char *, int); /* linkage=_ZN26CMenuHandler_StringCommandC4EPci */

	virtual void actionPerformed(class CMenuHandler_StringCommand *, class Panel *); /* linkage=_ZN26CMenuHandler_StringCommand15actionPerformedEPN4vgui5PanelE */

	/* vtable has 1 entries: {
	   [0] = actionPerformed(_ZN26CMenuHandler_StringCommand15actionPerformedEPN4vgui5PanelE), 
	} */
	/* size: 264, cachelines: 5, members: 3 */
	/* last cacheline: 8 bytes */
};
class ConsolePanel : public Panel {

	/* XXX 188 bytes hole, try to pack */
public:


	/* class Panel               <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 2 boundary (128 bytes) was 60 bytes ago --- */
	class TextGrid *           _textGrid;            /*   188     4 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	class TextEntry *          _textEntry;           /*   192     4 */
	void ConsolePanel(class ConsolePanel *, class ConsolePanel &); /* linkage=_ZN12ConsolePanelC4EOS_ */

	void ConsolePanel(class ConsolePanel *, const class ConsolePanel  &); /* linkage=_ZN12ConsolePanelC4ERKS_ */

	void ConsolePanel(class ConsolePanel *, int, int, int, int); /* linkage=_ZN12ConsolePanelC4Eiiii */

	virtual void setSize(class ConsolePanel *, int, int); /* linkage=_ZN12ConsolePanel7setSizeEii */

	virtual int print(class ConsolePanel *, const char  *); /* linkage=_ZN12ConsolePanel5printEPKc */

	virtual int vprintf(class ConsolePanel *, const char  *, va_list); /* linkage=_ZN12ConsolePanel7vprintfEPKcPc */

	virtual int printf(class ConsolePanel *, const char  *, ...); /* linkage=_ZN12ConsolePanel6printfEPKcz */

	virtual void doExecCommand(class ConsolePanel *); /* linkage=_ZN12ConsolePanel13doExecCommandEv */

	/* vtable has 5 entries: {
	   [2] = setSize(_ZN12ConsolePanel7setSizeEii), 
	   [127] = print(_ZN12ConsolePanel5printEPKc), 
	   [128] = vprintf(_ZN12ConsolePanel7vprintfEPKcPc), 
	   [129] = printf(_ZN12ConsolePanel6printfEPKcz), 
	   [130] = doExecCommand(_ZN12ConsolePanel13doExecCommandEv), 
	} */
	/* size: 196, cachelines: 4, members: 3 */
	/* sum members: 8, holes: 1, sum holes: 188 */
	/* last cacheline: 4 bytes */
};
class ControlConfigPanel : public Panel {

	/* XXX 188 bytes hole, try to pack */
public:


	/* class Panel               <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 2 boundary (128 bytes) was 60 bytes ago --- */
	class HeaderPanel *        _headerPanel;         /*   188     4 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	class TablePanel *         _tablePanel;          /*   192     4 */
	class ScrollPanel *        _scrollPanel;         /*   196     4 */
	class Dar<char*>          _cvarDar;              /*   200    12 */
	class Dar<char*>          _descDar;              /*   212    12 */
	class Label *              _actionLabel;         /*   224     4 */
	class Label *              _keyButtonLabel;      /*   228     4 */
	class Label *              _alternateLabel;      /*   232     4 */
	void ControlConfigPanel(class ControlConfigPanel *, class ControlConfigPanel &); /* linkage=_ZN18ControlConfigPanelC4EOS_ */

	void ControlConfigPanel(class ControlConfigPanel *, const class ControlConfigPanel  &); /* linkage=_ZN18ControlConfigPanelC4ERKS_ */

	void ControlConfigPanel(class ControlConfigPanel *, int, int, int, int); /* linkage=_ZN18ControlConfigPanelC4Eiiii */

	void AddCVar(class ControlConfigPanel *, const char  *, const char  *); /* linkage=_ZN18ControlConfigPanel7AddCVarEPKcS1_ */

	void AddCVarFromInputStream(class ControlConfigPanel *, class InputStream *); /* linkage=_ZN18ControlConfigPanel22AddCVarFromInputStreamEPN4vgui11InputStreamE */

	int GetCVarCount(class ControlConfigPanel *); /* linkage=_ZN18ControlConfigPanel12GetCVarCountEv */

	void GetCVar(class ControlConfigPanel *, int, char *, int, char *, int); /* linkage=_ZN18ControlConfigPanel7GetCVarEiPciS0_i */

	void GetCVarBind(class ControlConfigPanel *, const char  *, char *, int, char *, int); /* linkage=_ZN18ControlConfigPanel11GetCVarBindEPKcPciS2_i */

	void SetCVarBind(class ControlConfigPanel *, const char  *, const char  *, const char  *); /* linkage=_ZN18ControlConfigPanel11SetCVarBindEPKcS1_S1_ */


	/* size: 236, cachelines: 4, members: 9 */
	/* sum members: 48, holes: 1, sum holes: 188 */
	/* last cacheline: 44 bytes */
};
class CMenuHandler_StringCommandClassSelect : public CMenuHandler_StringCommand {
public:

	/* class CMenuHandler_StringCommand <ancestor>; */ /*     0   264 */
	void CMenuHandler_StringCommandClassSelect(class CMenuHandler_StringCommandClassSelect *, char *); /* linkage=_ZN37CMenuHandler_StringCommandClassSelectC4EPc */

	void CMenuHandler_StringCommandClassSelect(class CMenuHandler_StringCommandClassSelect *, char *, int); /* linkage=_ZN37CMenuHandler_StringCommandClassSelectC4EPci */

	virtual void actionPerformed(class CMenuHandler_StringCommandClassSelect *, class Panel *); /* linkage=_ZN37CMenuHandler_StringCommandClassSelect15actionPerformedEPN4vgui5PanelE */

	/* vtable has 1 entries: {
	   [0] = actionPerformed(_ZN37CMenuHandler_StringCommandClassSelect15actionPerformedEPN4vgui5PanelE), 
	} */
	/* size: 264, cachelines: 5, members: 1 */
	/* last cacheline: 8 bytes */
};
class CHandler_MenuButtonOver : public InputSignal {
public:

	/* class InputSignal         <ancestor>; */      /*     0     4 */
private:

	int                        m_iButton;            /*     4     4 */
	class CMenuPanel *         m_pMenuPanel;         /*     8     4 */
	void CHandler_MenuButtonOver(class CHandler_MenuButtonOver *, class CMenuPanel *, int); /* linkage=_ZN23CHandler_MenuButtonOverC4EP10CMenuPaneli */

	virtual void cursorEntered(class CHandler_MenuButtonOver *, class Panel *); /* linkage=_ZN23CHandler_MenuButtonOver13cursorEnteredEPN4vgui5PanelE */

	virtual void cursorMoved(class CHandler_MenuButtonOver *, int, int, class Panel *); /* linkage=_ZN23CHandler_MenuButtonOver11cursorMovedEiiPN4vgui5PanelE */

	virtual void mousePressed(class CHandler_MenuButtonOver *, enum MouseCode, class Panel *); /* linkage=_ZN23CHandler_MenuButtonOver12mousePressedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void mouseReleased(class CHandler_MenuButtonOver *, enum MouseCode, class Panel *); /* linkage=_ZN23CHandler_MenuButtonOver13mouseReleasedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void mouseDoublePressed(class CHandler_MenuButtonOver *, enum MouseCode, class Panel *); /* linkage=_ZN23CHandler_MenuButtonOver18mouseDoublePressedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void cursorExited(class CHandler_MenuButtonOver *, class Panel *); /* linkage=_ZN23CHandler_MenuButtonOver12cursorExitedEPN4vgui5PanelE */

	virtual void mouseWheeled(class CHandler_MenuButtonOver *, int, class Panel *); /* linkage=_ZN23CHandler_MenuButtonOver12mouseWheeledEiPN4vgui5PanelE */

	virtual void keyPressed(class CHandler_MenuButtonOver *, enum KeyCode, class Panel *); /* linkage=_ZN23CHandler_MenuButtonOver10keyPressedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyTyped(class CHandler_MenuButtonOver *, enum KeyCode, class Panel *); /* linkage=_ZN23CHandler_MenuButtonOver8keyTypedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyReleased(class CHandler_MenuButtonOver *, enum KeyCode, class Panel *); /* linkage=_ZN23CHandler_MenuButtonOver11keyReleasedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyFocusTicked(class CHandler_MenuButtonOver *, class Panel *); /* linkage=_ZN23CHandler_MenuButtonOver14keyFocusTickedEPN4vgui5PanelE */

	/* vtable has 11 entries: {
	   [1] = cursorEntered(_ZN23CHandler_MenuButtonOver13cursorEnteredEPN4vgui5PanelE), 
	   [0] = cursorMoved(_ZN23CHandler_MenuButtonOver11cursorMovedEiiPN4vgui5PanelE), 
	   [3] = mousePressed(_ZN23CHandler_MenuButtonOver12mousePressedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [5] = mouseReleased(_ZN23CHandler_MenuButtonOver13mouseReleasedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [4] = mouseDoublePressed(_ZN23CHandler_MenuButtonOver18mouseDoublePressedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [2] = cursorExited(_ZN23CHandler_MenuButtonOver12cursorExitedEPN4vgui5PanelE), 
	   [6] = mouseWheeled(_ZN23CHandler_MenuButtonOver12mouseWheeledEiPN4vgui5PanelE), 
	   [7] = keyPressed(_ZN23CHandler_MenuButtonOver10keyPressedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [8] = keyTyped(_ZN23CHandler_MenuButtonOver8keyTypedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [9] = keyReleased(_ZN23CHandler_MenuButtonOver11keyReleasedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [10] = keyFocusTicked(_ZN23CHandler_MenuButtonOver14keyFocusTickedEPN4vgui5PanelE), 
	} */
	/* size: 12, cachelines: 1, members: 3 */
	/* last cacheline: 12 bytes */
};
class CTFSlider : public Slider {
public:

	/* class Slider              <ancestor>; */      /*     0     0 */
	void CTFSlider(class CTFSlider *, class CTFSlider &); /* linkage=_ZN9CTFSliderC4EOS_ */

	void CTFSlider(class CTFSlider *, const class CTFSlider  &); /* linkage=_ZN9CTFSliderC4ERKS_ */

	void CTFSlider(class CTFSlider *, int, int, int, int, bool); /* linkage=_ZN9CTFSliderC4Eiiiib */

	virtual void paintBackground(class CTFSlider *); /* linkage=_ZN9CTFSlider15paintBackgroundEv */

	/* vtable has 1 entries: {
	   [111] = paintBackground(_ZN9CTFSlider15paintBackgroundEv), 
	} */
	/* size: 252, cachelines: 4, members: 1 */
	/* padding: 252 */
	/* last cacheline: 60 bytes */
};
class CTFScrollButton : public CommandButton {
public:

	/* class CommandButton       <ancestor>; */      /*     0   304 */

	/* XXX last struct has 3 bytes of padding, 3 holes */
private:


	/* --- cacheline 4 boundary (256 bytes) was 48 bytes ago --- */
	class BitmapTGA *          m_pTGA;               /*   304     4 */
	void CTFScrollButton(class CTFScrollButton *, class CTFScrollButton &); /* linkage=_ZN15CTFScrollButtonC4EOS_ */

	void CTFScrollButton(class CTFScrollButton *, const class CTFScrollButton  &); /* linkage=_ZN15CTFScrollButtonC4ERKS_ */

	void CTFScrollButton(class CTFScrollButton *, int, const char  *, int, int, int, int); /* linkage=_ZN15CTFScrollButtonC4EiPKciiii */

	virtual void paint(class CTFScrollButton *); /* linkage=_ZN15CTFScrollButton5paintEv */

	virtual void paintBackground(class CTFScrollButton *); /* linkage=_ZN15CTFScrollButton15paintBackgroundEv */

	/* vtable has 2 entries: {
	   [112] = paint(_ZN15CTFScrollButton5paintEv), 
	   [111] = paintBackground(_ZN15CTFScrollButton15paintBackgroundEv), 
	} */
	/* size: 308, cachelines: 5, members: 2 */
	/* member types with holes: 1, total: 3 */
	/* paddings: 1, sum paddings: 3 */
	/* last cacheline: 52 bytes */
};
class CommandButton : public Button {

	/* XXX 240 bytes hole, try to pack */
public:


	/* class Button              <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 3 boundary (192 bytes) was 48 bytes ago --- */
	int                        m_iPlayerClass;       /*   240     4 */
	bool                       m_bFlat;              /*   244     1 */

	/* XXX 3 bytes hole, try to pack */

	class CCommandMenu *       m_pSubMenu;           /*   248     4 */
	class CCommandMenu *       m_pParentMenu;        /*   252     4 */
	/* --- cacheline 4 boundary (256 bytes) --- */
	class CommandLabel *       m_pSubLabel;          /*   256     4 */
	char                       m_sMainText[32];      /*   260    32 */
	char                       m_cBoundKey;          /*   292     1 */

	/* XXX 3 bytes hole, try to pack */

	SchemeHandle_t             m_hTextScheme;        /*   296     4 */
	bool                       m_bNoHighlight;       /*   300     1 */
	void ~CommandButton(class CommandButton *, int); /* linkage=_ZN13CommandButtonD4Ev */

	void CommandButton(class CommandButton *, class CommandButton &); /* linkage=_ZN13CommandButtonC4EOS_ */

	void CommandButton(class CommandButton *, const class CommandButton  &); /* linkage=_ZN13CommandButtonC4ERKS_ */

	void RecalculateText(class CommandButton *); /* linkage=_ZN13CommandButton15RecalculateTextEv */

	void CommandButton(class CommandButton *, const char  *, int, int, int, int, bool, bool); /* linkage=_ZN13CommandButtonC4EPKciiiibb */

	void CommandButton(class CommandButton *, const char  *, int, int, int, int, bool); /* linkage=_ZN13CommandButtonC4EPKciiiib */

	void CommandButton(class CommandButton *, int, const char  *, int, int, int, int, bool); /* linkage=_ZN13CommandButtonC4EiPKciiiib */

	void Init(class CommandButton *); /* linkage=_ZN13CommandButton4InitEv */

	void AddSubMenu(class CommandButton *, class CCommandMenu *); /* linkage=_ZN13CommandButton10AddSubMenuEP12CCommandMenu */

	void AddSubLabel(class CommandButton *, class CommandLabel *); /* linkage=_ZN13CommandButton11AddSubLabelEP12CommandLabel */

	virtual int IsNotValid(class CommandButton *); /* linkage=_ZN13CommandButton10IsNotValidEv */

	void UpdateSubMenus(class CommandButton *, int); /* linkage=_ZN13CommandButton14UpdateSubMenusEi */

	int GetPlayerClass(class CommandButton *); /* linkage=_ZN13CommandButton14GetPlayerClassEv */

	class CCommandMenu * GetSubMenu(class CommandButton *); /* linkage=_ZN13CommandButton10GetSubMenuEv */

	class CCommandMenu * getParentMenu(class CommandButton *); /* linkage=_ZN13CommandButton13getParentMenuEv */

	void setParentMenu(class CommandButton *, class CCommandMenu *); /* linkage=_ZN13CommandButton13setParentMenuEP12CCommandMenu */

	virtual void paint(class CommandButton *); /* linkage=_ZN13CommandButton5paintEv */

	virtual void setText(class CommandButton *, const char  *); /* linkage=_ZN13CommandButton7setTextEPKc */

	virtual void paintBackground(class CommandButton *); /* linkage=_ZN13CommandButton15paintBackgroundEv */

	void cursorEntered(class CommandButton *); /* linkage=_ZN13CommandButton13cursorEnteredEv */

	void cursorExited(class CommandButton *); /* linkage=_ZN13CommandButton12cursorExitedEv */

	void setBoundKey(class CommandButton *, char); /* linkage=_ZN13CommandButton11setBoundKeyEc */

	char getBoundKey(class CommandButton *); /* linkage=_ZN13CommandButton11getBoundKeyEv */

	/* vtable has 4 entries: {
	   [152] = IsNotValid(_ZN13CommandButton10IsNotValidEv), 
	   [112] = paint(_ZN13CommandButton5paintEv), 
	   [153] = setText(_ZN13CommandButton7setTextEPKc), 
	   [111] = paintBackground(_ZN13CommandButton15paintBackgroundEv), 
	} */
	/* size: 304, cachelines: 5, members: 10 */
	/* sum members: 55, holes: 3, sum holes: 246 */
	/* padding: 3 */
	/* last cacheline: 48 bytes */
};
class CCommandMenu : public Panel {

	/* XXX 188 bytes hole, try to pack */
public:


	/* class Panel               <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 2 boundary (128 bytes) was 60 bytes ago --- */
	class CCommandMenu *       m_pParentMenu;        /*   188     4 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	int                        m_iXOffset;           /*   192     4 */
	int                        m_iYOffset;           /*   196     4 */
	class CommandButton *      m_aButtons[100];      /*   200   400 */
	/* --- cacheline 9 boundary (576 bytes) was 24 bytes ago --- */
	int                        m_iButtons;           /*   600     4 */
	int                        m_iDirection;         /*   604     4 */
	float                      m_flButtonSizeY;      /*   608     4 */
	int                        m_iSpectCmdMenu;      /*   612     4 */
	void CCommandMenu(class CCommandMenu *, class CCommandMenu *, int, int, int, int); /* linkage=_ZN12CCommandMenuC4EPS_iiii */

	void CCommandMenu(class CCommandMenu *, class CCommandMenu *, int, int, int, int, int); /* linkage=_ZN12CCommandMenuC4EPS_iiiii */

	void AddButton(class CCommandMenu *, class CommandButton *); /* linkage=_ZN12CCommandMenu9AddButtonEP13CommandButton */

	bool RecalculateVisibles(class CCommandMenu *, int, bool); /* linkage=_ZN12CCommandMenu19RecalculateVisiblesEib */

	void RecalculatePositions(class CCommandMenu *, int); /* linkage=_ZN12CCommandMenu20RecalculatePositionsEi */

	void MakeVisible(class CCommandMenu *, class CCommandMenu *); /* linkage=_ZN12CCommandMenu11MakeVisibleEPS_ */

	class CCommandMenu * GetParentMenu(class CCommandMenu *); /* linkage=_ZN12CCommandMenu13GetParentMenuEv */

	int GetXOffset(class CCommandMenu *); /* linkage=_ZN12CCommandMenu10GetXOffsetEv */

	int GetYOffset(class CCommandMenu *); /* linkage=_ZN12CCommandMenu10GetYOffsetEv */

	int GetDirection(class CCommandMenu *); /* linkage=_ZN12CCommandMenu12GetDirectionEv */

	int GetNumButtons(class CCommandMenu *); /* linkage=_ZN12CCommandMenu13GetNumButtonsEv */

	class CommandButton * FindButtonWithSubmenu(class CCommandMenu *, class CCommandMenu *); /* linkage=_ZN12CCommandMenu21FindButtonWithSubmenuEPS_ */

	void ClearButtonsOfArmedState(class CCommandMenu *); /* linkage=_ZN12CCommandMenu24ClearButtonsOfArmedStateEv */

	void RemoveAllButtons(class CCommandMenu *); /* linkage=_ZN12CCommandMenu16RemoveAllButtonsEv */

	bool KeyInput(class CCommandMenu *, int); /* linkage=_ZN12CCommandMenu8KeyInputEi */

	virtual void paintBackground(class CCommandMenu *); /* linkage=_ZN12CCommandMenu15paintBackgroundEv */

	/* vtable has 1 entries: {
	   [111] = paintBackground(_ZN12CCommandMenu15paintBackgroundEv), 
	} */
	/* size: 616, cachelines: 10, members: 9 */
	/* sum members: 428, holes: 1, sum holes: 188 */
	/* last cacheline: 40 bytes */
};
class CImageLabel : public Label {

	/* XXX 208 bytes hole, try to pack */
public:


	/* class Label               <ancestor>; */      /*     0     0 */
	/* --- cacheline 3 boundary (192 bytes) was 16 bytes ago --- */
	class BitmapTGA *          m_pTGA;               /*   208     4 */
	void CImageLabel(class CImageLabel *, class CImageLabel &); /* linkage=_ZN11CImageLabelC4EOS_ */

	void CImageLabel(class CImageLabel *, const class CImageLabel  &); /* linkage=_ZN11CImageLabelC4ERKS_ */

	void LoadImage(class CImageLabel *, const char  *); /* linkage=_ZN11CImageLabel9LoadImageEPKc */

	void CImageLabel(class CImageLabel *, const char  *, int, int); /* linkage=_ZN11CImageLabelC4EPKcii */

	void CImageLabel(class CImageLabel *, const char  *, int, int, int, int); /* linkage=_ZN11CImageLabelC4EPKciiii */

	virtual int getImageTall(class CImageLabel *); /* linkage=_ZN11CImageLabel12getImageTallEv */

	virtual int getImageWide(class CImageLabel *); /* linkage=_ZN11CImageLabel12getImageWideEv */

	virtual void paintBackground(class CImageLabel *); /* linkage=_ZN11CImageLabel15paintBackgroundEv */

	/* vtable has 3 entries: {
	   [139] = getImageTall(_ZN11CImageLabel12getImageTallEv), 
	   [140] = getImageWide(_ZN11CImageLabel12getImageWideEv), 
	   [111] = paintBackground(_ZN11CImageLabel15paintBackgroundEv), 
	} */
	/* size: 212, cachelines: 4, members: 2 */
	/* sum members: 4, holes: 1, sum holes: 208 */
	/* last cacheline: 20 bytes */
};
class ClassButton : public CommandButton {
public:

	/* class CommandButton       <ancestor>; */      /*     0   304 */

	/* XXX last struct has 3 bytes of padding, 3 holes */
protected:


	/* --- cacheline 4 boundary (256 bytes) was 48 bytes ago --- */
	int                        m_iPlayerClass;       /*   304     4 */
	void ClassButton(class ClassButton *, int, const char  *, int, int, int, int, bool); /* linkage=_ZN11ClassButtonC4EiPKciiiib */

	virtual int IsNotValid(class ClassButton *); /* linkage=_ZN11ClassButton10IsNotValidEv */

	/* vtable has 1 entries: {
	   [152] = IsNotValid(_ZN11ClassButton10IsNotValidEv), 
	} */
	/* size: 308, cachelines: 5, members: 2 */
	/* member types with holes: 1, total: 3 */
	/* paddings: 1, sum paddings: 3 */
	/* last cacheline: 52 bytes */
};
class CommandLabel : public Label {

	/* XXX 208 bytes hole, try to pack */
public:


	/* class Label               <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 3 boundary (192 bytes) was 16 bytes ago --- */
	int                        m_iState;             /*   208     4 */
	void CommandLabel(class CommandLabel *, const char  *, int, int, int, int); /* linkage=_ZN12CommandLabelC4EPKciiii */

	void PushUp(class CommandLabel *); /* linkage=_ZN12CommandLabel6PushUpEv */

	void PushDown(class CommandLabel *); /* linkage=_ZN12CommandLabel8PushDownEv */


	/* size: 212, cachelines: 4, members: 2 */
	/* sum members: 4, holes: 1, sum holes: 208 */
	/* last cacheline: 20 bytes */
};
class CTFScrollPanel : public ScrollPanel {
public:

	/* class ScrollPanel         <ancestor>; */      /*     0     0 */
	void CTFScrollPanel(class CTFScrollPanel *, class CTFScrollPanel &); /* linkage=_ZN14CTFScrollPanelC4EOS_ */

	void CTFScrollPanel(class CTFScrollPanel *, const class CTFScrollPanel  &); /* linkage=_ZN14CTFScrollPanelC4ERKS_ */

	void CTFScrollPanel(class CTFScrollPanel *, int, int, int, int); /* linkage=_ZN14CTFScrollPanelC4Eiiii */


	/* size: 208, cachelines: 4, members: 1 */
	/* padding: 208 */
	/* last cacheline: 16 bytes */
};
class CHandler_CommandButtonHighlight : public CHandler_ButtonHighlight {
public:

	/* class CHandler_ButtonHighlight <ancestor>; */ /*     0     8 */
private:

	class CommandButton *      m_pCommandButton;     /*     8     4 */
	void CHandler_CommandButtonHighlight(class CHandler_CommandButtonHighlight *, class CHandler_CommandButtonHighlight &); /* linkage=_ZN31CHandler_CommandButtonHighlightC4EOS_ */

	void CHandler_CommandButtonHighlight(class CHandler_CommandButtonHighlight *, const class CHandler_CommandButtonHighlight  &); /* linkage=_ZN31CHandler_CommandButtonHighlightC4ERKS_ */

	void CHandler_CommandButtonHighlight(class CHandler_CommandButtonHighlight *, class CommandButton *); /* linkage=_ZN31CHandler_CommandButtonHighlightC4EP13CommandButton */

	virtual void cursorEntered(class CHandler_CommandButtonHighlight *, class Panel *); /* linkage=_ZN31CHandler_CommandButtonHighlight13cursorEnteredEPN4vgui5PanelE */

	virtual void cursorExited(class CHandler_CommandButtonHighlight *, class Panel *); /* linkage=_ZN31CHandler_CommandButtonHighlight12cursorExitedEPN4vgui5PanelE */

	/* vtable has 2 entries: {
	   [1] = cursorEntered(_ZN31CHandler_CommandButtonHighlight13cursorEnteredEPN4vgui5PanelE), 
	   [2] = cursorExited(_ZN31CHandler_CommandButtonHighlight12cursorExitedEPN4vgui5PanelE), 
	} */
	/* size: 12, cachelines: 1, members: 2 */
	/* last cacheline: 12 bytes */
};
class CHandler_ButtonHighlight : public InputSignal {
public:

	/* class InputSignal         <ancestor>; */      /*     0     4 */
private:

	class Button *             m_pButton;            /*     4     4 */
	void ~CHandler_ButtonHighlight(class CHandler_ButtonHighlight *, int); /* linkage=_ZN24CHandler_ButtonHighlightD4Ev */

	void CHandler_ButtonHighlight(class CHandler_ButtonHighlight *, class CHandler_ButtonHighlight &); /* linkage=_ZN24CHandler_ButtonHighlightC4EOS_ */

	void CHandler_ButtonHighlight(class CHandler_ButtonHighlight *, const class CHandler_ButtonHighlight  &); /* linkage=_ZN24CHandler_ButtonHighlightC4ERKS_ */

	void CHandler_ButtonHighlight(class CHandler_ButtonHighlight *, class Button *); /* linkage=_ZN24CHandler_ButtonHighlightC4EPN4vgui6ButtonE */

	virtual void cursorEntered(class CHandler_ButtonHighlight *, class Panel *); /* linkage=_ZN24CHandler_ButtonHighlight13cursorEnteredEPN4vgui5PanelE */

	virtual void cursorExited(class CHandler_ButtonHighlight *, class Panel *); /* linkage=_ZN24CHandler_ButtonHighlight12cursorExitedEPN4vgui5PanelE */

	virtual void mousePressed(class CHandler_ButtonHighlight *, enum MouseCode, class Panel *); /* linkage=_ZN24CHandler_ButtonHighlight12mousePressedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void mouseReleased(class CHandler_ButtonHighlight *, enum MouseCode, class Panel *); /* linkage=_ZN24CHandler_ButtonHighlight13mouseReleasedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void cursorMoved(class CHandler_ButtonHighlight *, int, int, class Panel *); /* linkage=_ZN24CHandler_ButtonHighlight11cursorMovedEiiPN4vgui5PanelE */

	virtual void mouseDoublePressed(class CHandler_ButtonHighlight *, enum MouseCode, class Panel *); /* linkage=_ZN24CHandler_ButtonHighlight18mouseDoublePressedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void mouseWheeled(class CHandler_ButtonHighlight *, int, class Panel *); /* linkage=_ZN24CHandler_ButtonHighlight12mouseWheeledEiPN4vgui5PanelE */

	virtual void keyPressed(class CHandler_ButtonHighlight *, enum KeyCode, class Panel *); /* linkage=_ZN24CHandler_ButtonHighlight10keyPressedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyTyped(class CHandler_ButtonHighlight *, enum KeyCode, class Panel *); /* linkage=_ZN24CHandler_ButtonHighlight8keyTypedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyReleased(class CHandler_ButtonHighlight *, enum KeyCode, class Panel *); /* linkage=_ZN24CHandler_ButtonHighlight11keyReleasedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyFocusTicked(class CHandler_ButtonHighlight *, class Panel *); /* linkage=_ZN24CHandler_ButtonHighlight14keyFocusTickedEPN4vgui5PanelE */

	/* vtable has 11 entries: {
	   [1] = cursorEntered(_ZN24CHandler_ButtonHighlight13cursorEnteredEPN4vgui5PanelE), 
	   [2] = cursorExited(_ZN24CHandler_ButtonHighlight12cursorExitedEPN4vgui5PanelE), 
	   [3] = mousePressed(_ZN24CHandler_ButtonHighlight12mousePressedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [5] = mouseReleased(_ZN24CHandler_ButtonHighlight13mouseReleasedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [0] = cursorMoved(_ZN24CHandler_ButtonHighlight11cursorMovedEiiPN4vgui5PanelE), 
	   [4] = mouseDoublePressed(_ZN24CHandler_ButtonHighlight18mouseDoublePressedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [6] = mouseWheeled(_ZN24CHandler_ButtonHighlight12mouseWheeledEiPN4vgui5PanelE), 
	   [7] = keyPressed(_ZN24CHandler_ButtonHighlight10keyPressedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [8] = keyTyped(_ZN24CHandler_ButtonHighlight8keyTypedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [9] = keyReleased(_ZN24CHandler_ButtonHighlight11keyReleasedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [10] = keyFocusTicked(_ZN24CHandler_ButtonHighlight14keyFocusTickedEPN4vgui5PanelE), 
	} */
	/* size: 8, cachelines: 1, members: 2 */
	/* last cacheline: 8 bytes */
};
class CMessageWindowPanel : public CMenuPanel {
public:

	/* class CMenuPanel          <ancestor>; */      /*     0   212 */
private:

	/* --- cacheline 3 boundary (192 bytes) was 20 bytes ago --- */
	class CTransparentPanel *  m_pBackgroundPanel;   /*   212     4 */
	void CMessageWindowPanel(class CMessageWindowPanel *, class CMessageWindowPanel &); /* linkage=_ZN19CMessageWindowPanelC4EOS_ */

	void CMessageWindowPanel(class CMessageWindowPanel *, const class CMessageWindowPanel  &); /* linkage=_ZN19CMessageWindowPanelC4ERKS_ */

	void CMessageWindowPanel(class CMessageWindowPanel *, const char  *, const char  *, int, int, int, int, int, int); /* linkage=_ZN19CMessageWindowPanelC4EPKcS1_iiiiii */


	/* size: 216, cachelines: 4, members: 2 */
	/* last cacheline: 24 bytes */
};
class CSchemeManager {
	class CScheme {
		enum {
			SCHEME_NAME_LENGTH   = 32,
			FONT_NAME_LENGTH     = 48,
			FONT_FILENAME_LENGTH = 64,
		};

		char                       schemeName[32];       /*     0    32 */
		char                       fontName[48];         /*    32    48 */
		/* --- cacheline 1 boundary (64 bytes) was 16 bytes ago --- */
		int                        fontSize;             /*    80     4 */
		int                        fontWeight;           /*    84     4 */
		class Font *               font;                 /*    88     4 */
		int                        ownFontPointer;       /*    92     4 */
		byte                       fgColor[4];           /*    96     4 */
		byte                       bgColor[4];           /*   100     4 */
		byte                       armedFgColor[4];      /*   104     4 */
		byte                       armedBgColor[4];      /*   108     4 */
		byte                       mousedownFgColor[4];  /*   112     4 */
		byte                       mousedownBgColor[4];  /*   116     4 */
		byte                       borderColor[4];       /*   120     4 */
		void CScheme(class CScheme *); /* linkage=_ZN14CSchemeManager7CSchemeC4Ev */

		void ~CScheme(class CScheme *, int); /* linkage=_ZN14CSchemeManager7CSchemeD4Ev */


		/* size: 124, cachelines: 2, members: 13 */
		/* last cacheline: 60 bytes */
	};

	int ()(void) * *           _vptr.CSchemeManager; /*     0     4 */
private:

	class CScheme *            m_pSchemeList;        /*     4     4 */
	int                        m_iNumSchemes;        /*     8     4 */
	int                        m_xRes;               /*    12     4 */
	void CSchemeManager(class CSchemeManager *, const class CSchemeManager  &); /* linkage=_ZN14CSchemeManagerC4ERKS_ */

	void CSchemeManager(class CSchemeManager *, int, int); /* linkage=_ZN14CSchemeManagerC4Eii */

	virtual void ~CSchemeManager(class CSchemeManager *, int); /* linkage=_ZN14CSchemeManagerD4Ev */

	SchemeHandle_t getSchemeHandle(class CSchemeManager *, const char  *); /* linkage=_ZN14CSchemeManager15getSchemeHandleEPKc */

	class Font * getFont(class CSchemeManager *, SchemeHandle_t); /* linkage=_ZN14CSchemeManager7getFontEi */

	void getFgColor(class CSchemeManager *, SchemeHandle_t, int &, int &, int &, int &); /* linkage=_ZN14CSchemeManager10getFgColorEiRiS0_S0_S0_ */

	void getBgColor(class CSchemeManager *, SchemeHandle_t, int &, int &, int &, int &); /* linkage=_ZN14CSchemeManager10getBgColorEiRiS0_S0_S0_ */

	void getFgArmedColor(class CSchemeManager *, SchemeHandle_t, int &, int &, int &, int &); /* linkage=_ZN14CSchemeManager15getFgArmedColorEiRiS0_S0_S0_ */

	void getBgArmedColor(class CSchemeManager *, SchemeHandle_t, int &, int &, int &, int &); /* linkage=_ZN14CSchemeManager15getBgArmedColorEiRiS0_S0_S0_ */

	void getFgMousedownColor(class CSchemeManager *, SchemeHandle_t, int &, int &, int &, int &); /* linkage=_ZN14CSchemeManager19getFgMousedownColorEiRiS0_S0_S0_ */

	void getBgMousedownColor(class CSchemeManager *, SchemeHandle_t, int &, int &, int &, int &); /* linkage=_ZN14CSchemeManager19getBgMousedownColorEiRiS0_S0_S0_ */

	void getBorderColor(class CSchemeManager *, SchemeHandle_t, int &, int &, int &, int &); /* linkage=_ZN14CSchemeManager14getBorderColorEiRiS0_S0_S0_ */

	class CScheme * getSafeScheme(class CSchemeManager *, SchemeHandle_t); /* linkage=_ZN14CSchemeManager13getSafeSchemeEi */


	/* size: 16, cachelines: 1, members: 4 */
	/* last cacheline: 16 bytes */
};
struct team_info_t {
	char                       name[16];             /*     0    16 */
	short int                  frags;                /*    16     2 */
	short int                  deaths;               /*    18     2 */
	short int                  ping;                 /*    20     2 */
	short int                  packetloss;           /*    22     2 */
	short int                  ownteam;              /*    24     2 */
	short int                  players;              /*    26     2 */
	int                        already_drawn;        /*    28     4 */
	int                        scores_overriden;     /*    32     4 */
	int                        teamnumber;           /*    36     4 */

	/* size: 40, cachelines: 1, members: 10 */
	/* last cacheline: 40 bytes */
};
class SBColumnInfo {
	char *                     m_pTitle;             /*     0     4 */
	int                        m_Width;              /*     4     4 */
	enum Alignment             m_Alignment;          /*     8     4 */

	/* size: 12, cachelines: 1, members: 3 */
	/* last cacheline: 12 bytes */
};
class CLabelHeader : public Label {

	/* XXX 208 bytes hole, try to pack */
public:


	/* class Label               <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 3 boundary (192 bytes) was 16 bytes ago --- */
	class CTextImage2 *        _dualImage;           /*   208     4 */
	int                        _row;                 /*   212     4 */
	int                        _gap;                 /*   216     4 */
	int                        _offset[2];           /*   220     8 */
	bool                       _useFgColorAsImageColor; /*   228     1 */
	void CLabelHeader(class CLabelHeader *, const class CLabelHeader  &); /* linkage=_ZN12CLabelHeaderC4ERKS_ */

	void CLabelHeader(class CLabelHeader *); /* linkage=_ZN12CLabelHeaderC4Ev */

	void ~CLabelHeader(class CLabelHeader *, int); /* linkage=_ZN12CLabelHeaderD4Ev */

	void setRow(class CLabelHeader *, int); /* linkage=_ZN12CLabelHeader6setRowEi */

	void setFgColorAsImageColor(class CLabelHeader *, bool); /* linkage=_ZN12CLabelHeader22setFgColorAsImageColorEb */

	virtual void setText(class CLabelHeader *, int, const char  *); /* linkage=_ZN12CLabelHeader7setTextEiPKc */

	virtual void setText(class CLabelHeader *, const char  *); /* linkage=_ZN12CLabelHeader7setTextEPKc */

	void setText2(class CLabelHeader *, const char  *); /* linkage=_ZN12CLabelHeader8setText2EPKc */

	virtual void getTextSize(class CLabelHeader *, int &, int &); /* linkage=_ZN12CLabelHeader11getTextSizeERiS0_ */

	virtual void setFgColor(class CLabelHeader *, int, int, int, int); /* linkage=_ZN12CLabelHeader10setFgColorEiiii */

	virtual void setFgColor(class CLabelHeader *, enum SchemeColor); /* linkage=_ZN12CLabelHeader10setFgColorEN4vgui6Scheme11SchemeColorE */

	virtual void setFont(class CLabelHeader *, class Font *); /* linkage=_ZN12CLabelHeader7setFontEPN4vgui4FontE */

	void setFont2(class CLabelHeader *, class Font *); /* linkage=_ZN12CLabelHeader8setFont2EPN4vgui4FontE */

	void setTextOffset(class CLabelHeader *, int, int); /* linkage=_ZN12CLabelHeader13setTextOffsetEii */

	virtual void paint(class CLabelHeader *); /* linkage=_ZN12CLabelHeader5paintEv */

	virtual void paintBackground(class CLabelHeader *); /* linkage=_ZN12CLabelHeader15paintBackgroundEv */

	void calcAlignment(class CLabelHeader *, int, int, int &, int &); /* linkage=_ZN12CLabelHeader13calcAlignmentEiiRiS0_ */

	/* vtable has 8 entries: {
	   [128] = setText(_ZN12CLabelHeader7setTextEiPKc), 
	   [139] = setText(_ZN12CLabelHeader7setTextEPKc), 
	   [132] = getTextSize(_ZN12CLabelHeader11getTextSizeERiS0_), 
	   [73] = setFgColor(_ZN12CLabelHeader10setFgColorEiiii), 
	   [71] = setFgColor(_ZN12CLabelHeader10setFgColorEN4vgui6Scheme11SchemeColorE), 
	   [131] = setFont(_ZN12CLabelHeader7setFontEPN4vgui4FontE), 
	   [112] = paint(_ZN12CLabelHeader5paintEv), 
	   [111] = paintBackground(_ZN12CLabelHeader15paintBackgroundEv), 
	} */
	/* size: 232, cachelines: 4, members: 6 */
	/* sum members: 21, holes: 1, sum holes: 208 */
	/* padding: 3 */
	/* last cacheline: 40 bytes */
};
class CTextImage2 : public Image {

	/* XXX 36 bytes hole, try to pack */
public:


	/* class Image               <ancestor>; */      /*     0     0 */
private:

	class TextImage *          _image[2];            /*    36     8 */
	void CTextImage2(class CTextImage2 *, const class CTextImage2  &); /* linkage=_ZN11CTextImage2C4ERKS_ */

	void CTextImage2(class CTextImage2 *); /* linkage=_ZN11CTextImage2C4Ev */

	void ~CTextImage2(class CTextImage2 *, int); /* linkage=_ZN11CTextImage2D4Ev */

	class TextImage * GetImage(class CTextImage2 *, int); /* linkage=_ZN11CTextImage28GetImageEi */

	virtual void getSize(class CTextImage2 *, int &, int &); /* linkage=_ZN11CTextImage27getSizeERiS0_ */

	virtual void doPaint(class CTextImage2 *, class Panel *); /* linkage=_ZN11CTextImage27doPaintEPN4vgui5PanelE */

	virtual void setPos(class CTextImage2 *, int, int); /* linkage=_ZN11CTextImage26setPosEii */

	virtual void setColor(class CTextImage2 *, class Color); /* linkage=_ZN11CTextImage28setColorEN4vgui5ColorE */

	void setColor2(class CTextImage2 *, class Color); /* linkage=_ZN11CTextImage29setColor2EN4vgui5ColorE */

	/* vtable has 4 entries: {
	   [2] = getSize(_ZN11CTextImage27getSizeERiS0_), 
	   [23] = doPaint(_ZN11CTextImage27doPaintEPN4vgui5PanelE), 
	   [0] = setPos(_ZN11CTextImage26setPosEii), 
	   [3] = setColor(_ZN11CTextImage28setColorEN4vgui5ColorE), 
	} */
	/* size: 44, cachelines: 1, members: 2 */
	/* sum members: 8, holes: 1, sum holes: 36 */
	/* last cacheline: 44 bytes */
};
class ScorePanel : public Panel, public CDefaultInputSignal {

	/* XXX 188 bytes hole, try to pack */
public:


	/* class Panel               <ancestor>; */      /*     0     0 */
	/* --- cacheline 2 boundary (128 bytes) was 60 bytes ago --- */
	/* class CDefaultInputSignal <ancestor>; */      /*   188     4 */
private:

	/* --- cacheline 3 boundary (192 bytes) --- */
	class Label               m_TitleLabel;          /*   192     0 */

	/* XXX 208 bytes hole, try to pack */

	/* --- cacheline 6 boundary (384 bytes) was 16 bytes ago --- */
	class CGrid               m_HeaderGrid;          /*   400     0 */

	/* XXX 224 bytes hole, try to pack */

	/* --- cacheline 9 boundary (576 bytes) was 48 bytes ago --- */
	class CLabelHeader        m_HeaderLabels[8];     /*   624  1856 */
	/* --- cacheline 38 boundary (2432 bytes) was 48 bytes ago --- */
	class CLabelHeader *       m_pCurrentHighlightLabel; /*  2480     4 */
	int                        m_iHighlightRow;      /*  2484     4 */
	class CListBox            m_PlayerList;          /*  2488     0 */

	/* XXX 872 bytes hole, try to pack */

	/* --- cacheline 52 boundary (3328 bytes) was 32 bytes ago --- */
	class CGrid               m_PlayerGrids[74];     /*  3360     0 */

	/* XXX 16576 bytes hole, try to pack */

	/* --- cacheline 311 boundary (19904 bytes) was 32 bytes ago --- */
	class CLabelHeader        m_PlayerEntries[8][74]; /* 19936 137344 */
	class HitTestPanel : public Panel {
	public:

		/* class Panel               <ancestor>; */      /*     0     0 */
		void ~HitTestPanel(class HitTestPanel *, int); /* linkage=_ZN10ScorePanel12HitTestPanelD4Ev */

		void HitTestPanel(class HitTestPanel *, class HitTestPanel &); /* linkage=_ZN10ScorePanel12HitTestPanelC4EOS0_ */

		void HitTestPanel(class HitTestPanel *, const class HitTestPanel  &); /* linkage=_ZN10ScorePanel12HitTestPanelC4ERKS0_ */

		void HitTestPanel(class HitTestPanel *); /* linkage=_ZN10ScorePanel12HitTestPanelC4Ev */

		virtual void internalMousePressed(class HitTestPanel *, enum MouseCode); /* linkage=_ZN10ScorePanel12HitTestPanel20internalMousePressedEN4vgui9MouseCodeE */

		/* vtable has 1 entries: {
		   [117] = internalMousePressed(_ZN10ScorePanel12HitTestPanel20internalMousePressedEN4vgui9MouseCodeE), 
		} */
		/* size: 188, cachelines: 3, members: 1 */
		/* padding: 188 */
		/* last cacheline: 60 bytes */
	};

	/* --- cacheline 2457 boundary (157248 bytes) was 32 bytes ago --- */
	class HitTestPanel        m_HitTestPanel;        /* 157280   188 */

	/* XXX last struct has 188 bytes of padding */

	/* --- cacheline 2460 boundary (157440 bytes) was 28 bytes ago --- */
	class CommandButton *      m_pCloseButton;       /* 157468     4 */
	class BitmapTGA *          m_pTrackerIcon;       /* 157472     4 */
	int                        m_iNumTeams;          /* 157476     4 */
	int                        m_iPlayerNum;         /* 157480     4 */
	int                        m_iShowscoresHeld;    /* 157484     4 */
	int                        m_iRows;              /* 157488     4 */
	int                        m_iSortedRows[74];    /* 157492   296 */
	/* --- cacheline 2465 boundary (157760 bytes) was 28 bytes ago --- */
	int                        m_iIsATeam[74];       /* 157788   296 */
	/* --- cacheline 2470 boundary (158080 bytes) was 4 bytes ago --- */
	bool                       m_bHasBeenSorted[64]; /* 158084    64 */
	/* --- cacheline 2471 boundary (158144 bytes) was 4 bytes ago --- */
	int                        m_iLastKilledBy;      /* 158148     4 */
	int                        m_fLastKillTime;      /* 158152     4 */
	void ScorePanel(class ScorePanel *, class ScorePanel &); /* linkage=_ZN10ScorePanelC4EOS_ */

	void ScorePanel(class ScorePanel *, const class ScorePanel  &); /* linkage=_ZN10ScorePanelC4ERKS_ */

	class CLabelHeader * GetPlayerEntry(class ScorePanel *, int, int); /* linkage=_ZN10ScorePanel14GetPlayerEntryEii */

	void ScorePanel(class ScorePanel *, int, int, int, int); /* linkage=_ZN10ScorePanelC4Eiiii */

	void Update(class ScorePanel *); /* linkage=_ZN10ScorePanel6UpdateEv */

	void SortTeams(class ScorePanel *); /* linkage=_ZN10ScorePanel9SortTeamsEv */

	void SortPlayers(class ScorePanel *, int, char *); /* linkage=_ZN10ScorePanel11SortPlayersEiPc */

	void RebuildTeams(class ScorePanel *); /* linkage=_ZN10ScorePanel12RebuildTeamsEv */

	void FillGrid(class ScorePanel *); /* linkage=_ZN10ScorePanel8FillGridEv */

	void DeathMsg(class ScorePanel *, int, int); /* linkage=_ZN10ScorePanel8DeathMsgEii */

	void Initialize(class ScorePanel *); /* linkage=_ZN10ScorePanel10InitializeEv */

	void Open(class ScorePanel *); /* linkage=_ZN10ScorePanel4OpenEv */

	void MouseOverCell(class ScorePanel *, int, int); /* linkage=_ZN10ScorePanel13MouseOverCellEii */

	virtual void mousePressed(class ScorePanel *, enum MouseCode, class Panel *); /* linkage=_ZN10ScorePanel12mousePressedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void cursorMoved(class ScorePanel *, int, int, class Panel *); /* linkage=_ZN10ScorePanel11cursorMovedEiiPN4vgui5PanelE */

	/* tag__fprintf: const_type tag not supported! */;

	/* vtable has 2 entries: {
	   [127] = mousePressed(_ZN10ScorePanel12mousePressedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [128] = cursorMoved(_ZN10ScorePanel11cursorMovedEiiPN4vgui5PanelE), 
	} */
	/* size: 158156, cachelines: 2472, members: 22 */
	/* sum members: 140088, holes: 5, sum holes: 18068 */
	/* paddings: 1, sum paddings: 188 */
	/* last cacheline: 12 bytes */
};
class CMenuHandler_StringCommandWatch : public CMenuHandler_StringCommand {
public:

	/* class CMenuHandler_StringCommand <ancestor>; */ /*     0   264 */
	void CMenuHandler_StringCommandWatch(class CMenuHandler_StringCommandWatch *, class CMenuHandler_StringCommandWatch &); /* linkage=_ZN31CMenuHandler_StringCommandWatchC4EOS_ */

	void CMenuHandler_StringCommandWatch(class CMenuHandler_StringCommandWatch *, const class CMenuHandler_StringCommandWatch  &); /* linkage=_ZN31CMenuHandler_StringCommandWatchC4ERKS_ */

	void CMenuHandler_StringCommandWatch(class CMenuHandler_StringCommandWatch *, char *); /* linkage=_ZN31CMenuHandler_StringCommandWatchC4EPc */

	void CMenuHandler_StringCommandWatch(class CMenuHandler_StringCommandWatch *, char *, int); /* linkage=_ZN31CMenuHandler_StringCommandWatchC4EPci */

	virtual void actionPerformed(class CMenuHandler_StringCommandWatch *, class Panel *); /* linkage=_ZN31CMenuHandler_StringCommandWatch15actionPerformedEPN4vgui5PanelE */

	/* vtable has 1 entries: {
	   [0] = actionPerformed(_ZN31CMenuHandler_StringCommandWatch15actionPerformedEPN4vgui5PanelE), 
	} */
	/* size: 264, cachelines: 5, members: 1 */
	/* last cacheline: 8 bytes */
};
class ServerBrowser : public CTransparentPanel {
public:

	/* class CTransparentPanel   <ancestor>; */      /*     0   192 */

	/* XXX last struct has 1 hole */
private:


	/* --- cacheline 3 boundary (192 bytes) --- */
	class HeaderPanel *        _headerPanel;         /*   192     4 */
	class TablePanel *         _tablePanel;          /*   196     4 */
	class CommandButton *      _connectButton;       /*   200     4 */
	class CommandButton *      _refreshButton;       /*   204     4 */
	class CommandButton *      _broadcastRefreshButton; /*   208     4 */
	class CommandButton *      _stopButton;          /*   212     4 */
	class CommandButton *      _sortButton;          /*   216     4 */
	class CommandButton *      _cancelButton;        /*   220     4 */
	class CommandButton *      _pingButton;          /*   224     4 */
	void ServerBrowser(class ServerBrowser *, class ServerBrowser &); /* linkage=_ZN13ServerBrowserC4EOS_ */

	void ServerBrowser(class ServerBrowser *, const class ServerBrowser  &); /* linkage=_ZN13ServerBrowserC4ERKS_ */

	void ServerBrowser(class ServerBrowser *, int, int, int, int); /* linkage=_ZN13ServerBrowserC4Eiiii */

	virtual void setSize(class ServerBrowser *, int, int); /* linkage=_ZN13ServerBrowser7setSizeEii */

	/* vtable has 1 entries: {
	   [2] = setSize(_ZN13ServerBrowser7setSizeEii), 
	} */
	/* size: 228, cachelines: 4, members: 10 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 36 bytes */
};
class CSBLabel : public Label {

	/* XXX 208 bytes hole, try to pack */
public:


	/* class Label               <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 3 boundary (192 bytes) was 16 bytes ago --- */
	char                       m_szSortKey[64];      /*   208    64 */
	/* --- cacheline 4 boundary (256 bytes) was 16 bytes ago --- */
	class ServerBrowserTablePanel * m_pBrowser;      /*   272     4 */
	void CSBLabel(class CSBLabel *, class CSBLabel &); /* linkage=_ZN8CSBLabelC4EOS_ */

	void CSBLabel(class CSBLabel *, const class CSBLabel  &); /* linkage=_ZN8CSBLabelC4ERKS_ */

	void CSBLabel(class CSBLabel *, char *, char *); /* linkage=_ZN8CSBLabelC4EPcS0_ */

	void setTable(class CSBLabel *, class ServerBrowserTablePanel *);


	/* size: 276, cachelines: 5, members: 3 */
	/* sum members: 68, holes: 1, sum holes: 208 */
	/* last cacheline: 20 bytes */
};
class LabelSortInputHandler : public InputSignal {
public:

	/* class InputSignal         <ancestor>; */      /*     0     4 */
private:

	class ServerBrowserTablePanel * m_pBrowser;      /*     4     4 */
	char                       m_szSortKey[64];      /*     8    64 */
	void LabelSortInputHandler(class LabelSortInputHandler *, class LabelSortInputHandler &); /* linkage=_ZN21LabelSortInputHandlerC4EOS_ */

	void LabelSortInputHandler(class LabelSortInputHandler *, const class LabelSortInputHandler  &); /* linkage=_ZN21LabelSortInputHandlerC4ERKS_ */

	void LabelSortInputHandler(class LabelSortInputHandler *, class ServerBrowserTablePanel *, char *);

	virtual void cursorMoved(class LabelSortInputHandler *, int, int, class Panel *); /* linkage=_ZN21LabelSortInputHandler11cursorMovedEiiPN4vgui5PanelE */

	virtual void cursorEntered(class LabelSortInputHandler *, class Panel *); /* linkage=_ZN21LabelSortInputHandler13cursorEnteredEPN4vgui5PanelE */

	virtual void cursorExited(class LabelSortInputHandler *, class Panel *); /* linkage=_ZN21LabelSortInputHandler12cursorExitedEPN4vgui5PanelE */

	virtual void mousePressed(class LabelSortInputHandler *, enum MouseCode, class Panel *); /* linkage=_ZN21LabelSortInputHandler12mousePressedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void mouseDoublePressed(class LabelSortInputHandler *, enum MouseCode, class Panel *); /* linkage=_ZN21LabelSortInputHandler18mouseDoublePressedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void mouseReleased(class LabelSortInputHandler *, enum MouseCode, class Panel *); /* linkage=_ZN21LabelSortInputHandler13mouseReleasedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void mouseWheeled(class LabelSortInputHandler *, int, class Panel *); /* linkage=_ZN21LabelSortInputHandler12mouseWheeledEiPN4vgui5PanelE */

	virtual void keyPressed(class LabelSortInputHandler *, enum KeyCode, class Panel *); /* linkage=_ZN21LabelSortInputHandler10keyPressedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyTyped(class LabelSortInputHandler *, enum KeyCode, class Panel *); /* linkage=_ZN21LabelSortInputHandler8keyTypedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyReleased(class LabelSortInputHandler *, enum KeyCode, class Panel *); /* linkage=_ZN21LabelSortInputHandler11keyReleasedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyFocusTicked(class LabelSortInputHandler *, class Panel *); /* linkage=_ZN21LabelSortInputHandler14keyFocusTickedEPN4vgui5PanelE */

	/* vtable has 11 entries: {
	   [0] = cursorMoved(_ZN21LabelSortInputHandler11cursorMovedEiiPN4vgui5PanelE), 
	   [1] = cursorEntered(_ZN21LabelSortInputHandler13cursorEnteredEPN4vgui5PanelE), 
	   [2] = cursorExited(_ZN21LabelSortInputHandler12cursorExitedEPN4vgui5PanelE), 
	   [3] = mousePressed(_ZN21LabelSortInputHandler12mousePressedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [4] = mouseDoublePressed(_ZN21LabelSortInputHandler18mouseDoublePressedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [5] = mouseReleased(_ZN21LabelSortInputHandler13mouseReleasedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [6] = mouseWheeled(_ZN21LabelSortInputHandler12mouseWheeledEiPN4vgui5PanelE), 
	   [7] = keyPressed(_ZN21LabelSortInputHandler10keyPressedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [8] = keyTyped(_ZN21LabelSortInputHandler8keyTypedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [9] = keyReleased(_ZN21LabelSortInputHandler11keyReleasedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [10] = keyFocusTicked(_ZN21LabelSortInputHandler14keyFocusTickedEPN4vgui5PanelE), 
	} */
	/* size: 72, cachelines: 2, members: 3 */
	/* last cacheline: 8 bytes */
};
class BuildButton : public CommandButton {

	/* XXX 304 bytes hole, try to pack */
	enum Buildings {
		DISPENSER        = 0,
		SENTRYGUN        = 1,
		ENTRY_TELEPORTER = 2,
		EXIT_TELEPORTER  = 3,
	};

public:


	/* class CommandButton       <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 4 boundary (256 bytes) was 48 bytes ago --- */
	int                        m_iBuildState;        /*   304     4 */
	int                        m_iBuildData;         /*   308     4 */
	void BuildButton(class BuildButton *, class BuildButton &); /* linkage=_ZN11BuildButtonC4EOS_ */

	void BuildButton(class BuildButton *, const class BuildButton  &); /* linkage=_ZN11BuildButtonC4ERKS_ */

	void BuildButton(class BuildButton *, int, int, const char  *, int, int, int, int); /* linkage=_ZN11BuildButtonC4EiiPKciiii */

	virtual int IsNotValid(class BuildButton *); /* linkage=_ZN11BuildButton10IsNotValidEv */

	/* vtable has 1 entries: {
	   [152] = IsNotValid(_ZN11BuildButton10IsNotValidEv), 
	} */
	/* size: 312, cachelines: 5, members: 3 */
	/* sum members: 8, holes: 1, sum holes: 304 */
	/* last cacheline: 56 bytes */
};
class CDragNDropHandler : public InputSignal {
public:

	/* class InputSignal         <ancestor>; */      /*     0     4 */
private:

	class DragNDropPanel *     m_pPanel;             /*     4     4 */
	bool                       m_bDragging;          /*     8     1 */

	/* XXX 3 bytes hole, try to pack */

	int                        m_iaDragOrgPos[2];    /*    12     8 */
	int                        m_iaDragStart[2];     /*    20     8 */
	void CDragNDropHandler(class CDragNDropHandler *, class CDragNDropHandler &); /* linkage=_ZN17CDragNDropHandlerC4EOS_ */

	void CDragNDropHandler(class CDragNDropHandler *, const class CDragNDropHandler  &); /* linkage=_ZN17CDragNDropHandlerC4ERKS_ */

	void CDragNDropHandler(class CDragNDropHandler *, class DragNDropPanel *); /* linkage=_ZN17CDragNDropHandlerC4EP14DragNDropPanel */

	virtual void cursorMoved(class CDragNDropHandler *, int, int, class Panel *); /* linkage=_ZN17CDragNDropHandler11cursorMovedEiiPN4vgui5PanelE */

	virtual void mousePressed(class CDragNDropHandler *, enum MouseCode, class Panel *); /* linkage=_ZN17CDragNDropHandler12mousePressedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void mouseReleased(class CDragNDropHandler *, enum MouseCode, class Panel *); /* linkage=_ZN17CDragNDropHandler13mouseReleasedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void mouseDoublePressed(class CDragNDropHandler *, enum MouseCode, class Panel *); /* linkage=_ZN17CDragNDropHandler18mouseDoublePressedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void cursorEntered(class CDragNDropHandler *, class Panel *); /* linkage=_ZN17CDragNDropHandler13cursorEnteredEPN4vgui5PanelE */

	virtual void cursorExited(class CDragNDropHandler *, class Panel *); /* linkage=_ZN17CDragNDropHandler12cursorExitedEPN4vgui5PanelE */

	virtual void mouseWheeled(class CDragNDropHandler *, int, class Panel *); /* linkage=_ZN17CDragNDropHandler12mouseWheeledEiPN4vgui5PanelE */

	virtual void keyPressed(class CDragNDropHandler *, enum KeyCode, class Panel *); /* linkage=_ZN17CDragNDropHandler10keyPressedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyTyped(class CDragNDropHandler *, enum KeyCode, class Panel *); /* linkage=_ZN17CDragNDropHandler8keyTypedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyReleased(class CDragNDropHandler *, enum KeyCode, class Panel *); /* linkage=_ZN17CDragNDropHandler11keyReleasedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyFocusTicked(class CDragNDropHandler *, class Panel *); /* linkage=_ZN17CDragNDropHandler14keyFocusTickedEPN4vgui5PanelE */

	/* vtable has 11 entries: {
	   [0] = cursorMoved(_ZN17CDragNDropHandler11cursorMovedEiiPN4vgui5PanelE), 
	   [3] = mousePressed(_ZN17CDragNDropHandler12mousePressedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [5] = mouseReleased(_ZN17CDragNDropHandler13mouseReleasedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [4] = mouseDoublePressed(_ZN17CDragNDropHandler18mouseDoublePressedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [1] = cursorEntered(_ZN17CDragNDropHandler13cursorEnteredEPN4vgui5PanelE), 
	   [2] = cursorExited(_ZN17CDragNDropHandler12cursorExitedEPN4vgui5PanelE), 
	   [6] = mouseWheeled(_ZN17CDragNDropHandler12mouseWheeledEiPN4vgui5PanelE), 
	   [7] = keyPressed(_ZN17CDragNDropHandler10keyPressedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [8] = keyTyped(_ZN17CDragNDropHandler8keyTypedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [9] = keyReleased(_ZN17CDragNDropHandler11keyReleasedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [10] = keyFocusTicked(_ZN17CDragNDropHandler14keyFocusTickedEPN4vgui5PanelE), 
	} */
	/* size: 28, cachelines: 1, members: 5 */
	/* sum members: 25, holes: 1, sum holes: 3 */
	/* last cacheline: 28 bytes */
};
class DragNDropPanel : public Panel {

	/* XXX 187 bytes hole, try to pack */
public:


	/* class Panel               <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 2 boundary (128 bytes) was 59 bytes ago --- */
	bool                       m_bBeingDragged;      /*   187     1 */
	class LineBorder *         m_pBorder;            /*   188     4 */
	void ~DragNDropPanel(class DragNDropPanel *, int); /* linkage=_ZN14DragNDropPanelD4Ev */

	void DragNDropPanel(class DragNDropPanel *, class DragNDropPanel &); /* linkage=_ZN14DragNDropPanelC4EOS_ */

	void DragNDropPanel(class DragNDropPanel *, const class DragNDropPanel  &); /* linkage=_ZN14DragNDropPanelC4ERKS_ */

	void DragNDropPanel(class DragNDropPanel *, int, int, int, int); /* linkage=_ZN14DragNDropPanelC4Eiiii */

	virtual void setDragged(class DragNDropPanel *, bool); /* linkage=_ZN14DragNDropPanel10setDraggedEb */

	/* vtable has 1 entries: {
	   [127] = setDragged(_ZN14DragNDropPanel10setDraggedEb), 
	} */
	/* size: 192, cachelines: 3, members: 3 */
	/* sum members: 5, holes: 1, sum holes: 187 */
};
class TeamFortressViewport : public Panel {

	/* XXX 188 bytes hole, try to pack */
public:


	/* class Panel               <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 2 boundary (128 bytes) was 60 bytes ago --- */
	class Cursor *             _cursorNone;          /*   188     4 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	class Cursor *             _cursorArrow;         /*   192     4 */
	int                        m_iInitialized;       /*   196     4 */
	class CCommandMenu *       m_pCommandMenus[80];  /*   200   320 */
	/* --- cacheline 8 boundary (512 bytes) was 8 bytes ago --- */
	class CCommandMenu *       m_pCurrentCommandMenu; /*   520     4 */
	float                      m_flMenuOpenTime;     /*   524     4 */
	float                      m_flScoreBoardLastUpdated; /*   528     4 */
	float                      m_flSpectatorPanelLastUpdated; /*   532     4 */
	int                        m_iNumMenus;          /*   536     4 */
	int                        m_iCurrentTeamNumber; /*   540     4 */
	int                        m_iCurrentPlayerClass; /*   544     4 */
	int                        m_iUser1;             /*   548     4 */
	int                        m_iUser2;             /*   552     4 */
	int                        m_iUser3;             /*   556     4 */
	class CSchemeManager      m_SchemeManager;       /*   560     0 */

	/* XXX 16 bytes hole, try to pack */

	/* --- cacheline 9 boundary (576 bytes) --- */
	int                        m_iGotAllMOTD;        /*   576     4 */
	char                       m_szMOTD[1536];       /*   580  1536 */
	/* --- cacheline 33 boundary (2112 bytes) was 4 bytes ago --- */
	class CommandButton *      m_pTeamButtons[6];    /*  2116    24 */
	class CommandButton *      m_pDisguiseButtons[5]; /*  2140    20 */
	class BuildButton *        m_pBuildButtons[3];   /*  2160    12 */
	class BuildButton *        m_pBuildActiveButtons[3]; /*  2172    12 */
	/* --- cacheline 34 boundary (2176 bytes) was 8 bytes ago --- */
	class ServerBrowser *      m_pServerBrowser;     /*  2184     4 */
	int                        m_iAllowSpectators;   /*  2188     4 */
	int                        m_iValidClasses[5];   /*  2192    20 */
	int                        m_iIsFeigning;        /*  2212     4 */
	int                        m_iIsSettingDetpack;  /*  2216     4 */
	int                        m_iNumberOfTeams;     /*  2220     4 */
	int                        m_iBuildState;        /*  2224     4 */
	int                        m_iRandomPC;          /*  2228     4 */
	char                       m_sTeamNames[5][32];  /*  2232   160 */
	/* --- cacheline 37 boundary (2368 bytes) was 24 bytes ago --- */
	char                       m_sDetpackStrings[3][32]; /*  2392    96 */
	/* --- cacheline 38 boundary (2432 bytes) was 56 bytes ago --- */
	char                       m_sMapName[64];       /*  2488    64 */
	/* --- cacheline 39 boundary (2496 bytes) was 56 bytes ago --- */
	class CMenuPanel *         m_pCurrentMenu;       /*  2552     4 */
	class CTeamMenuPanel *     m_pTeamMenu;          /*  2556     4 */
	/* --- cacheline 40 boundary (2560 bytes) --- */
	int                        m_StandardMenu;       /*  2560     4 */
	int                        m_SpectatorOptionsMenu; /*  2564     4 */
	int                        m_SpectatorCameraMenu; /*  2568     4 */
	int                        m_PlayerMenu;         /*  2572     4 */
	class CClassMenuPanel *    m_pClassMenu;         /*  2576     4 */
	class ScorePanel *         m_pScoreBoard;        /*  2580     4 */
	class SpectatorPanel *     m_pSpectatorPanel;    /*  2584     4 */
	char                       m_szServerName[64];   /*  2588    64 */
	void TeamFortressViewport(class TeamFortressViewport *, class TeamFortressViewport &); /* linkage=_ZN20TeamFortressViewportC4EOS_ */

	void TeamFortressViewport(class TeamFortressViewport *, const class TeamFortressViewport  &); /* linkage=_ZN20TeamFortressViewportC4ERKS_ */

	void CreateTeamMenu(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport14CreateTeamMenuEv */

	class CMenuPanel * ShowTeamMenu(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport12ShowTeamMenuEv */

	void CreateClassMenu(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport15CreateClassMenuEv */

	class CMenuPanel * ShowClassMenu(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport13ShowClassMenuEv */

	void CreateSpectatorMenu(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport19CreateSpectatorMenuEv */

	void UpdatePlayerMenu(class TeamFortressViewport *, int); /* linkage=_ZN20TeamFortressViewport16UpdatePlayerMenuEi */

	void TeamFortressViewport(class TeamFortressViewport *, int, int, int, int); /* linkage=_ZN20TeamFortressViewportC4Eiiii */

	void Initialize(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport10InitializeEv */

	int CreateCommandMenu(class TeamFortressViewport *, char *, int, int, bool, float, float, int); /* linkage=_ZN20TeamFortressViewport17CreateCommandMenuEPciibffi */

	void CreateScoreBoard(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport16CreateScoreBoardEv */

	void CreateServerBrowser(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport19CreateServerBrowserEv */

	class CommandButton * CreateCustomButton(class TeamFortressViewport *, char *, char *, int); /* linkage=_ZN20TeamFortressViewport18CreateCustomButtonEPcS0_i */

	class CCommandMenu * CreateDisguiseSubmenu(class TeamFortressViewport *, class CommandButton *, class CCommandMenu *, const char  *, int, int); /* linkage=_ZN20TeamFortressViewport21CreateDisguiseSubmenuEP13CommandButtonP12CCommandMenuPKcii */

	void UpdateCursorState(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport17UpdateCursorStateEv */

	void UpdateCommandMenu(class TeamFortressViewport *, int); /* linkage=_ZN20TeamFortressViewport17UpdateCommandMenuEi */

	void UpdateOnPlayerInfo(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport18UpdateOnPlayerInfoEv */

	void UpdateHighlights(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport16UpdateHighlightsEv */

	void UpdateSpectatorPanel(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport20UpdateSpectatorPanelEv */

	int KeyInput(class TeamFortressViewport *, int, int, const char  *); /* linkage=_ZN20TeamFortressViewport8KeyInputEiiPKc */

	void InputPlayerSpecial(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport18InputPlayerSpecialEv */

	void GetAllPlayersInfo(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport17GetAllPlayersInfoEv */

	void DeathMsg(class TeamFortressViewport *, int, int); /* linkage=_ZN20TeamFortressViewport8DeathMsgEii */

	void ShowCommandMenu(class TeamFortressViewport *, int); /* linkage=_ZN20TeamFortressViewport15ShowCommandMenuEi */

	void InputSignalHideCommandMenu(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport26InputSignalHideCommandMenuEv */

	void HideCommandMenu(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport15HideCommandMenuEv */

	void SetCurrentCommandMenu(class TeamFortressViewport *, class CCommandMenu *); /* linkage=_ZN20TeamFortressViewport21SetCurrentCommandMenuEP12CCommandMenu */

	void SetCurrentMenu(class TeamFortressViewport *, class CMenuPanel *); /* linkage=_ZN20TeamFortressViewport14SetCurrentMenuEP10CMenuPanel */

	void ShowScoreBoard(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport14ShowScoreBoardEv */

	void HideScoreBoard(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport14HideScoreBoardEv */

	bool IsScoreBoardVisible(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport19IsScoreBoardVisibleEv */

	bool AllowedToPrintText(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport18AllowedToPrintTextEv */

	void ShowVGUIMenu(class TeamFortressViewport *, int); /* linkage=_ZN20TeamFortressViewport12ShowVGUIMenuEi */

	void HideVGUIMenu(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport12HideVGUIMenuEv */

	void HideTopMenu(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport11HideTopMenuEv */

	void ToggleServerBrowser(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport19ToggleServerBrowserEv */

	class CMenuPanel * CreateTextWindow(class TeamFortressViewport *, int); /* linkage=_ZN20TeamFortressViewport16CreateTextWindowEi */

	class CCommandMenu * CreateSubMenu(class TeamFortressViewport *, class CommandButton *, class CCommandMenu *, int, int); /* linkage=_ZN20TeamFortressViewport13CreateSubMenuEP13CommandButtonP12CCommandMenuii */

	int GetValidClasses(class TeamFortressViewport *, int); /* linkage=_ZN20TeamFortressViewport15GetValidClassesEi */

	int GetNumberOfTeams(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport16GetNumberOfTeamsEv */

	int GetIsFeigning(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport13GetIsFeigningEv */

	int GetIsSettingDetpack(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport19GetIsSettingDetpackEv */

	int GetBuildState(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport13GetBuildStateEv */

	int IsRandomPC(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport10IsRandomPCEv */

	char * GetTeamName(class TeamFortressViewport *, int); /* linkage=_ZN20TeamFortressViewport11GetTeamNameEi */

	int GetAllowSpectators(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport18GetAllowSpectatorsEv */

	int MsgFunc_ValClass(class TeamFortressViewport *, const char  *, int, void *); /* linkage=_ZN20TeamFortressViewport16MsgFunc_ValClassEPKciPv */

	int MsgFunc_TeamNames(class TeamFortressViewport *, const char  *, int, void *); /* linkage=_ZN20TeamFortressViewport17MsgFunc_TeamNamesEPKciPv */

	int MsgFunc_Feign(class TeamFortressViewport *, const char  *, int, void *); /* linkage=_ZN20TeamFortressViewport13MsgFunc_FeignEPKciPv */

	int MsgFunc_Detpack(class TeamFortressViewport *, const char  *, int, void *); /* linkage=_ZN20TeamFortressViewport15MsgFunc_DetpackEPKciPv */

	int MsgFunc_VGUIMenu(class TeamFortressViewport *, const char  *, int, void *); /* linkage=_ZN20TeamFortressViewport16MsgFunc_VGUIMenuEPKciPv */

	int MsgFunc_MOTD(class TeamFortressViewport *, const char  *, int, void *); /* linkage=_ZN20TeamFortressViewport12MsgFunc_MOTDEPKciPv */

	int MsgFunc_BuildSt(class TeamFortressViewport *, const char  *, int, void *); /* linkage=_ZN20TeamFortressViewport15MsgFunc_BuildStEPKciPv */

	int MsgFunc_RandomPC(class TeamFortressViewport *, const char  *, int, void *); /* linkage=_ZN20TeamFortressViewport16MsgFunc_RandomPCEPKciPv */

	int MsgFunc_ServerName(class TeamFortressViewport *, const char  *, int, void *); /* linkage=_ZN20TeamFortressViewport18MsgFunc_ServerNameEPKciPv */

	int MsgFunc_ScoreInfo(class TeamFortressViewport *, const char  *, int, void *); /* linkage=_ZN20TeamFortressViewport17MsgFunc_ScoreInfoEPKciPv */

	int MsgFunc_TeamScore(class TeamFortressViewport *, const char  *, int, void *); /* linkage=_ZN20TeamFortressViewport17MsgFunc_TeamScoreEPKciPv */

	int MsgFunc_TeamInfo(class TeamFortressViewport *, const char  *, int, void *); /* linkage=_ZN20TeamFortressViewport16MsgFunc_TeamInfoEPKciPv */

	int MsgFunc_Spectator(class TeamFortressViewport *, const char  *, int, void *); /* linkage=_ZN20TeamFortressViewport17MsgFunc_SpectatorEPKciPv */

	int MsgFunc_AllowSpec(class TeamFortressViewport *, const char  *, int, void *); /* linkage=_ZN20TeamFortressViewport17MsgFunc_AllowSpecEPKciPv */

	int MsgFunc_SpecFade(class TeamFortressViewport *, const char  *, int, void *); /* linkage=_ZN20TeamFortressViewport16MsgFunc_SpecFadeEPKciPv */

	int MsgFunc_ResetFade(class TeamFortressViewport *, const char  *, int, void *); /* linkage=_ZN20TeamFortressViewport17MsgFunc_ResetFadeEPKciPv */

	bool SlotInput(class TeamFortressViewport *, int); /* linkage=_ZN20TeamFortressViewport9SlotInputEi */

	virtual void paintBackground(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport15paintBackgroundEv */

	class CSchemeManager * GetSchemeManager(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport16GetSchemeManagerEv */

	class ScorePanel * GetScoreBoard(class TeamFortressViewport *); /* linkage=_ZN20TeamFortressViewport13GetScoreBoardEv */

	void * operator new(size_t); /* linkage=_ZN20TeamFortressViewportnwEj */

	/* vtable has 1 entries: {
	   [111] = paintBackground(_ZN20TeamFortressViewport15paintBackgroundEv), 
	} */
	/* size: 2652, cachelines: 42, members: 43 */
	/* sum members: 2448, holes: 2, sum holes: 204 */
	/* last cacheline: 28 bytes */
};
class CViewPortInputHandler : public InputSignal {
public:

	/* class InputSignal         <ancestor>; */      /*     0     4 */
	bool                       bPressed;             /*     4     1 */
	void CViewPortInputHandler(class CViewPortInputHandler *, class CViewPortInputHandler &); /* linkage=_ZN21CViewPortInputHandlerC4EOS_ */

	void CViewPortInputHandler(class CViewPortInputHandler *, const class CViewPortInputHandler  &); /* linkage=_ZN21CViewPortInputHandlerC4ERKS_ */

	void CViewPortInputHandler(class CViewPortInputHandler *); /* linkage=_ZN21CViewPortInputHandlerC4Ev */

	virtual void cursorMoved(class CViewPortInputHandler *, int, int, class Panel *); /* linkage=_ZN21CViewPortInputHandler11cursorMovedEiiPN4vgui5PanelE */

	virtual void cursorEntered(class CViewPortInputHandler *, class Panel *); /* linkage=_ZN21CViewPortInputHandler13cursorEnteredEPN4vgui5PanelE */

	virtual void cursorExited(class CViewPortInputHandler *, class Panel *); /* linkage=_ZN21CViewPortInputHandler12cursorExitedEPN4vgui5PanelE */

	virtual void mousePressed(class CViewPortInputHandler *, enum MouseCode, class Panel *); /* linkage=_ZN21CViewPortInputHandler12mousePressedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void mouseReleased(class CViewPortInputHandler *, enum MouseCode, class Panel *); /* linkage=_ZN21CViewPortInputHandler13mouseReleasedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void mouseDoublePressed(class CViewPortInputHandler *, enum MouseCode, class Panel *); /* linkage=_ZN21CViewPortInputHandler18mouseDoublePressedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void mouseWheeled(class CViewPortInputHandler *, int, class Panel *); /* linkage=_ZN21CViewPortInputHandler12mouseWheeledEiPN4vgui5PanelE */

	virtual void keyPressed(class CViewPortInputHandler *, enum KeyCode, class Panel *); /* linkage=_ZN21CViewPortInputHandler10keyPressedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyTyped(class CViewPortInputHandler *, enum KeyCode, class Panel *); /* linkage=_ZN21CViewPortInputHandler8keyTypedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyReleased(class CViewPortInputHandler *, enum KeyCode, class Panel *); /* linkage=_ZN21CViewPortInputHandler11keyReleasedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyFocusTicked(class CViewPortInputHandler *, class Panel *); /* linkage=_ZN21CViewPortInputHandler14keyFocusTickedEPN4vgui5PanelE */

	/* vtable has 11 entries: {
	   [0] = cursorMoved(_ZN21CViewPortInputHandler11cursorMovedEiiPN4vgui5PanelE), 
	   [1] = cursorEntered(_ZN21CViewPortInputHandler13cursorEnteredEPN4vgui5PanelE), 
	   [2] = cursorExited(_ZN21CViewPortInputHandler12cursorExitedEPN4vgui5PanelE), 
	   [3] = mousePressed(_ZN21CViewPortInputHandler12mousePressedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [5] = mouseReleased(_ZN21CViewPortInputHandler13mouseReleasedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [4] = mouseDoublePressed(_ZN21CViewPortInputHandler18mouseDoublePressedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [6] = mouseWheeled(_ZN21CViewPortInputHandler12mouseWheeledEiPN4vgui5PanelE), 
	   [7] = keyPressed(_ZN21CViewPortInputHandler10keyPressedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [8] = keyTyped(_ZN21CViewPortInputHandler8keyTypedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [9] = keyReleased(_ZN21CViewPortInputHandler11keyReleasedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [10] = keyFocusTicked(_ZN21CViewPortInputHandler14keyFocusTickedEPN4vgui5PanelE), 
	} */
	/* size: 8, cachelines: 1, members: 2 */
	/* padding: 3 */
	/* last cacheline: 8 bytes */
};
class SpectToggleButton : public CommandButton, public InputSignal {

	/* XXX 304 bytes hole, try to pack */
public:


	/* class CommandButton       <ancestor>; */      /*     0     0 */
	/* --- cacheline 4 boundary (256 bytes) was 48 bytes ago --- */
	/* class InputSignal         <ancestor>; */      /*   304     4 */
private:

	class cvar_s *             m_cvar;               /*   308     4 */
	class CImageLabel *        pLabelOn;             /*   312     4 */
	void SpectToggleButton(class SpectToggleButton *, class SpectToggleButton &); /* linkage=_ZN17SpectToggleButtonC4EOS_ */

	void SpectToggleButton(class SpectToggleButton *, const class SpectToggleButton  &); /* linkage=_ZN17SpectToggleButtonC4ERKS_ */

	void SpectToggleButton(class SpectToggleButton *, const char  *, const char  *, int, int, int, int, bool); /* linkage=_ZN17SpectToggleButtonC4EPKcS1_iiiib */

	virtual void cursorEntered(class SpectToggleButton *, class Panel *); /* linkage=_ZN17SpectToggleButton13cursorEnteredEPN4vgui5PanelE */

	virtual void cursorExited(class SpectToggleButton *, class Panel *); /* linkage=_ZN17SpectToggleButton12cursorExitedEPN4vgui5PanelE */

	virtual void mousePressed(class SpectToggleButton *, enum MouseCode, class Panel *); /* linkage=_ZN17SpectToggleButton12mousePressedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void cursorMoved(class SpectToggleButton *, int, int, class Panel *); /* linkage=_ZN17SpectToggleButton11cursorMovedEiiPN4vgui5PanelE */

	virtual void mouseDoublePressed(class SpectToggleButton *, enum MouseCode, class Panel *); /* linkage=_ZN17SpectToggleButton18mouseDoublePressedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void mouseReleased(class SpectToggleButton *, enum MouseCode, class Panel *); /* linkage=_ZN17SpectToggleButton13mouseReleasedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void mouseWheeled(class SpectToggleButton *, int, class Panel *); /* linkage=_ZN17SpectToggleButton12mouseWheeledEiPN4vgui5PanelE */

	virtual void keyPressed(class SpectToggleButton *, enum KeyCode, class Panel *); /* linkage=_ZN17SpectToggleButton10keyPressedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyTyped(class SpectToggleButton *, enum KeyCode, class Panel *); /* linkage=_ZN17SpectToggleButton8keyTypedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyReleased(class SpectToggleButton *, enum KeyCode, class Panel *); /* linkage=_ZN17SpectToggleButton11keyReleasedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyFocusTicked(class SpectToggleButton *, class Panel *); /* linkage=_ZN17SpectToggleButton14keyFocusTickedEPN4vgui5PanelE */

	virtual void paintBackground(class SpectToggleButton *); /* linkage=_ZN17SpectToggleButton15paintBackgroundEv */

	virtual void paint(class SpectToggleButton *); /* linkage=_ZN17SpectToggleButton5paintEv */

	/* vtable has 13 entries: {
	   [154] = cursorEntered(_ZN17SpectToggleButton13cursorEnteredEPN4vgui5PanelE), 
	   [155] = cursorExited(_ZN17SpectToggleButton12cursorExitedEPN4vgui5PanelE), 
	   [156] = mousePressed(_ZN17SpectToggleButton12mousePressedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [157] = cursorMoved(_ZN17SpectToggleButton11cursorMovedEiiPN4vgui5PanelE), 
	   [158] = mouseDoublePressed(_ZN17SpectToggleButton18mouseDoublePressedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [159] = mouseReleased(_ZN17SpectToggleButton13mouseReleasedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [160] = mouseWheeled(_ZN17SpectToggleButton12mouseWheeledEiPN4vgui5PanelE), 
	   [161] = keyPressed(_ZN17SpectToggleButton10keyPressedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [162] = keyTyped(_ZN17SpectToggleButton8keyTypedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [163] = keyReleased(_ZN17SpectToggleButton11keyReleasedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [164] = keyFocusTicked(_ZN17SpectToggleButton14keyFocusTickedEPN4vgui5PanelE), 
	   [111] = paintBackground(_ZN17SpectToggleButton15paintBackgroundEv), 
	   [112] = paint(_ZN17SpectToggleButton5paintEv), 
	} */
	/* size: 316, cachelines: 5, members: 4 */
	/* sum members: 12, holes: 1, sum holes: 304 */
	/* last cacheline: 60 bytes */
};
class ToggleCommandButton : public CommandButton, public InputSignal {

	/* XXX 304 bytes hole, try to pack */
public:


	/* class CommandButton       <ancestor>; */      /*     0     0 */
	/* --- cacheline 4 boundary (256 bytes) was 48 bytes ago --- */
	/* class InputSignal         <ancestor>; */      /*   304     4 */
private:

	class cvar_s *             m_cvar;               /*   308     4 */
	class CImageLabel *        pLabelOn;             /*   312     4 */
	class CImageLabel *        pLabelOff;            /*   316     4 */
	void ToggleCommandButton(class ToggleCommandButton *, class ToggleCommandButton &); /* linkage=_ZN19ToggleCommandButtonC4EOS_ */

	void ToggleCommandButton(class ToggleCommandButton *, const class ToggleCommandButton  &); /* linkage=_ZN19ToggleCommandButtonC4ERKS_ */

	void ToggleCommandButton(class ToggleCommandButton *, const char  *, const char  *, int, int, int, int, bool); /* linkage=_ZN19ToggleCommandButtonC4EPKcS1_iiiib */

	virtual void cursorEntered(class ToggleCommandButton *, class Panel *); /* linkage=_ZN19ToggleCommandButton13cursorEnteredEPN4vgui5PanelE */

	virtual void cursorExited(class ToggleCommandButton *, class Panel *); /* linkage=_ZN19ToggleCommandButton12cursorExitedEPN4vgui5PanelE */

	virtual void mousePressed(class ToggleCommandButton *, enum MouseCode, class Panel *); /* linkage=_ZN19ToggleCommandButton12mousePressedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void cursorMoved(class ToggleCommandButton *, int, int, class Panel *); /* linkage=_ZN19ToggleCommandButton11cursorMovedEiiPN4vgui5PanelE */

	virtual void mouseDoublePressed(class ToggleCommandButton *, enum MouseCode, class Panel *); /* linkage=_ZN19ToggleCommandButton18mouseDoublePressedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void mouseReleased(class ToggleCommandButton *, enum MouseCode, class Panel *); /* linkage=_ZN19ToggleCommandButton13mouseReleasedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void mouseWheeled(class ToggleCommandButton *, int, class Panel *); /* linkage=_ZN19ToggleCommandButton12mouseWheeledEiPN4vgui5PanelE */

	virtual void keyPressed(class ToggleCommandButton *, enum KeyCode, class Panel *); /* linkage=_ZN19ToggleCommandButton10keyPressedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyTyped(class ToggleCommandButton *, enum KeyCode, class Panel *); /* linkage=_ZN19ToggleCommandButton8keyTypedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyReleased(class ToggleCommandButton *, enum KeyCode, class Panel *); /* linkage=_ZN19ToggleCommandButton11keyReleasedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyFocusTicked(class ToggleCommandButton *, class Panel *); /* linkage=_ZN19ToggleCommandButton14keyFocusTickedEPN4vgui5PanelE */

	virtual void paint(class ToggleCommandButton *); /* linkage=_ZN19ToggleCommandButton5paintEv */

	/* vtable has 12 entries: {
	   [154] = cursorEntered(_ZN19ToggleCommandButton13cursorEnteredEPN4vgui5PanelE), 
	   [155] = cursorExited(_ZN19ToggleCommandButton12cursorExitedEPN4vgui5PanelE), 
	   [156] = mousePressed(_ZN19ToggleCommandButton12mousePressedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [157] = cursorMoved(_ZN19ToggleCommandButton11cursorMovedEiiPN4vgui5PanelE), 
	   [158] = mouseDoublePressed(_ZN19ToggleCommandButton18mouseDoublePressedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [159] = mouseReleased(_ZN19ToggleCommandButton13mouseReleasedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [160] = mouseWheeled(_ZN19ToggleCommandButton12mouseWheeledEiPN4vgui5PanelE), 
	   [161] = keyPressed(_ZN19ToggleCommandButton10keyPressedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [162] = keyTyped(_ZN19ToggleCommandButton8keyTypedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [163] = keyReleased(_ZN19ToggleCommandButton11keyReleasedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [164] = keyFocusTicked(_ZN19ToggleCommandButton14keyFocusTickedEPN4vgui5PanelE), 
	   [112] = paint(_ZN19ToggleCommandButton5paintEv), 
	} */
	/* size: 320, cachelines: 5, members: 5 */
	/* sum members: 16, holes: 1, sum holes: 304 */
};
class TeamOnlyCommandButton : public CommandButton {

	/* XXX 304 bytes hole, try to pack */
public:


	/* class CommandButton       <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 4 boundary (256 bytes) was 48 bytes ago --- */
	int                        m_iTeamNum;           /*   304     4 */
	void TeamOnlyCommandButton(class TeamOnlyCommandButton *, class TeamOnlyCommandButton &); /* linkage=_ZN21TeamOnlyCommandButtonC4EOS_ */

	void TeamOnlyCommandButton(class TeamOnlyCommandButton *, const class TeamOnlyCommandButton  &); /* linkage=_ZN21TeamOnlyCommandButtonC4ERKS_ */

	void TeamOnlyCommandButton(class TeamOnlyCommandButton *, int, const char  *, int, int, int, int, bool); /* linkage=_ZN21TeamOnlyCommandButtonC4EiPKciiiib */

	virtual int IsNotValid(class TeamOnlyCommandButton *); /* linkage=_ZN21TeamOnlyCommandButton10IsNotValidEv */

	/* vtable has 1 entries: {
	   [152] = IsNotValid(_ZN21TeamOnlyCommandButton10IsNotValidEv), 
	} */
	/* size: 308, cachelines: 5, members: 2 */
	/* sum members: 4, holes: 1, sum holes: 304 */
	/* last cacheline: 52 bytes */
};
class MapButton : public CommandButton {

	/* XXX 301 bytes hole, try to pack */
public:


	/* class CommandButton       <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 4 boundary (256 bytes) was 45 bytes ago --- */
	char                       m_szMapName[256];     /*   301   256 */
	void MapButton(class MapButton *, class MapButton &); /* linkage=_ZN9MapButtonC4EOS_ */

	void MapButton(class MapButton *, const class MapButton  &); /* linkage=_ZN9MapButtonC4ERKS_ */

	void MapButton(class MapButton *, const char  *, const char  *, int, int, int, int); /* linkage=_ZN9MapButtonC4EPKcS1_iiii */

	virtual int IsNotValid(class MapButton *); /* linkage=_ZN9MapButton10IsNotValidEv */

	/* vtable has 1 entries: {
	   [152] = IsNotValid(_ZN9MapButton10IsNotValidEv), 
	} */
	/* size: 560, cachelines: 9, members: 2 */
	/* sum members: 256, holes: 1, sum holes: 301 */
	/* padding: 3 */
	/* last cacheline: 48 bytes */
};
class DetpackButton : public CommandButton {

	/* XXX 304 bytes hole, try to pack */
public:


	/* class CommandButton       <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 4 boundary (256 bytes) was 48 bytes ago --- */
	int                        m_iDetpackState;      /*   304     4 */
	void DetpackButton(class DetpackButton *, class DetpackButton &); /* linkage=_ZN13DetpackButtonC4EOS_ */

	void DetpackButton(class DetpackButton *, const class DetpackButton  &); /* linkage=_ZN13DetpackButtonC4ERKS_ */

	void DetpackButton(class DetpackButton *, int, const char  *, int, int, int, int); /* linkage=_ZN13DetpackButtonC4EiPKciiii */

	virtual int IsNotValid(class DetpackButton *); /* linkage=_ZN13DetpackButton10IsNotValidEv */

	/* vtable has 1 entries: {
	   [152] = IsNotValid(_ZN13DetpackButton10IsNotValidEv), 
	} */
	/* size: 308, cachelines: 5, members: 2 */
	/* sum members: 4, holes: 1, sum holes: 304 */
	/* last cacheline: 52 bytes */
};
class DisguiseButton : public CommandButton {

	/* XXX 304 bytes hole, try to pack */
public:


	/* class CommandButton       <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 4 boundary (256 bytes) was 48 bytes ago --- */
	int                        m_iValidTeamsBits;    /*   304     4 */
	int                        m_iThisTeam;          /*   308     4 */
	void DisguiseButton(class DisguiseButton *, class DisguiseButton &); /* linkage=_ZN14DisguiseButtonC4EOS_ */

	void DisguiseButton(class DisguiseButton *, const class DisguiseButton  &); /* linkage=_ZN14DisguiseButtonC4ERKS_ */

	void DisguiseButton(class DisguiseButton *, int, const char  *, int, int, int, int); /* linkage=_ZN14DisguiseButtonC4EiPKciiii */

	virtual int IsNotValid(class DisguiseButton *); /* linkage=_ZN14DisguiseButton10IsNotValidEv */

	/* vtable has 1 entries: {
	   [152] = IsNotValid(_ZN14DisguiseButton10IsNotValidEv), 
	} */
	/* size: 312, cachelines: 5, members: 3 */
	/* sum members: 8, holes: 1, sum holes: 304 */
	/* last cacheline: 56 bytes */
};
class SpectateButton : public CommandButton {
public:

	/* class CommandButton       <ancestor>; */      /*     0     0 */
	void SpectateButton(class SpectateButton *, class SpectateButton &); /* linkage=_ZN14SpectateButtonC4EOS_ */

	void SpectateButton(class SpectateButton *, const class SpectateButton  &); /* linkage=_ZN14SpectateButtonC4ERKS_ */

	void SpectateButton(class SpectateButton *, const char  *, int, int, int, int, bool); /* linkage=_ZN14SpectateButtonC4EPKciiiib */

	virtual int IsNotValid(class SpectateButton *); /* linkage=_ZN14SpectateButton10IsNotValidEv */

	/* vtable has 1 entries: {
	   [152] = IsNotValid(_ZN14SpectateButton10IsNotValidEv), 
	} */
	/* size: 304, cachelines: 5, members: 1 */
	/* padding: 304 */
	/* last cacheline: 48 bytes */
};
class FeignButton : public CommandButton {

	/* XXX 304 bytes hole, try to pack */
public:


	/* class CommandButton       <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 4 boundary (256 bytes) was 48 bytes ago --- */
	int                        m_iFeignState;        /*   304     4 */
	void FeignButton(class FeignButton *, class FeignButton &); /* linkage=_ZN11FeignButtonC4EOS_ */

	void FeignButton(class FeignButton *, const class FeignButton  &); /* linkage=_ZN11FeignButtonC4ERKS_ */

	void FeignButton(class FeignButton *, int, const char  *, int, int, int, int); /* linkage=_ZN11FeignButtonC4EiPKciiii */

	virtual int IsNotValid(class FeignButton *); /* linkage=_ZN11FeignButton10IsNotValidEv */

	/* vtable has 1 entries: {
	   [152] = IsNotValid(_ZN11FeignButton10IsNotValidEv), 
	} */
	/* size: 308, cachelines: 5, members: 2 */
	/* sum members: 4, holes: 1, sum holes: 304 */
	/* last cacheline: 52 bytes */
};
class TeamButton : public CommandButton {

	/* XXX 304 bytes hole, try to pack */
public:


	/* class CommandButton       <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 4 boundary (256 bytes) was 48 bytes ago --- */
	int                        m_iTeamNumber;        /*   304     4 */
	void TeamButton(class TeamButton *, class TeamButton &); /* linkage=_ZN10TeamButtonC4EOS_ */

	void TeamButton(class TeamButton *, const class TeamButton  &); /* linkage=_ZN10TeamButtonC4ERKS_ */

	void TeamButton(class TeamButton *, int, const char  *, int, int, int, int); /* linkage=_ZN10TeamButtonC4EiPKciiii */

	virtual int IsNotValid(class TeamButton *); /* linkage=_ZN10TeamButton10IsNotValidEv */

	/* vtable has 1 entries: {
	   [152] = IsNotValid(_ZN10TeamButton10IsNotValidEv), 
	} */
	/* size: 308, cachelines: 5, members: 2 */
	/* sum members: 4, holes: 1, sum holes: 304 */
	/* last cacheline: 52 bytes */
};
class CMenuHandler_SpectateFollow : public ActionSignal {
public:

	/* class ActionSignal        <ancestor>; */      /*     0     4 */
protected:

	char                       m_szplayer[256];      /*     4   256 */
	void CMenuHandler_SpectateFollow(class CMenuHandler_SpectateFollow *, class CMenuHandler_SpectateFollow &); /* linkage=_ZN27CMenuHandler_SpectateFollowC4EOS_ */

	void CMenuHandler_SpectateFollow(class CMenuHandler_SpectateFollow *, const class CMenuHandler_SpectateFollow  &); /* linkage=_ZN27CMenuHandler_SpectateFollowC4ERKS_ */

	void CMenuHandler_SpectateFollow(class CMenuHandler_SpectateFollow *, char *); /* linkage=_ZN27CMenuHandler_SpectateFollowC4EPc */

	virtual void actionPerformed(class CMenuHandler_SpectateFollow *, class Panel *); /* linkage=_ZN27CMenuHandler_SpectateFollow15actionPerformedEPN4vgui5PanelE */

	/* vtable has 1 entries: {
	   [0] = actionPerformed(_ZN27CMenuHandler_SpectateFollow15actionPerformedEPN4vgui5PanelE), 
	} */
	/* size: 260, cachelines: 5, members: 2 */
	/* last cacheline: 4 bytes */
};
class CMenuHandler_ToggleCvar : public ActionSignal {
public:

	/* class ActionSignal        <ancestor>; */      /*     0     4 */
private:

	class cvar_s *             m_cvar;               /*     4     4 */
	void CMenuHandler_ToggleCvar(class CMenuHandler_ToggleCvar *, class CMenuHandler_ToggleCvar &); /* linkage=_ZN23CMenuHandler_ToggleCvarC4EOS_ */

	void CMenuHandler_ToggleCvar(class CMenuHandler_ToggleCvar *, const class CMenuHandler_ToggleCvar  &); /* linkage=_ZN23CMenuHandler_ToggleCvarC4ERKS_ */

	void CMenuHandler_ToggleCvar(class CMenuHandler_ToggleCvar *, char *); /* linkage=_ZN23CMenuHandler_ToggleCvarC4EPc */

	virtual void actionPerformed(class CMenuHandler_ToggleCvar *, class Panel *); /* linkage=_ZN23CMenuHandler_ToggleCvar15actionPerformedEPN4vgui5PanelE */

	/* vtable has 1 entries: {
	   [0] = actionPerformed(_ZN23CMenuHandler_ToggleCvar15actionPerformedEPN4vgui5PanelE), 
	} */
	/* size: 8, cachelines: 1, members: 2 */
	/* last cacheline: 8 bytes */
};
class CMenuHandler_PopupSubMenuInput : public InputSignal {
public:

	/* class InputSignal         <ancestor>; */      /*     0     4 */
private:

	class CCommandMenu *       m_pSubMenu;           /*     4     4 */
	class Button *             m_pButton;            /*     8     4 */
	void CMenuHandler_PopupSubMenuInput(class CMenuHandler_PopupSubMenuInput *, class CMenuHandler_PopupSubMenuInput &); /* linkage=_ZN30CMenuHandler_PopupSubMenuInputC4EOS_ */

	void CMenuHandler_PopupSubMenuInput(class CMenuHandler_PopupSubMenuInput *, const class CMenuHandler_PopupSubMenuInput  &); /* linkage=_ZN30CMenuHandler_PopupSubMenuInputC4ERKS_ */

	void CMenuHandler_PopupSubMenuInput(class CMenuHandler_PopupSubMenuInput *, class Button *, class CCommandMenu *); /* linkage=_ZN30CMenuHandler_PopupSubMenuInputC4EPN4vgui6ButtonEP12CCommandMenu */

	virtual void cursorMoved(class CMenuHandler_PopupSubMenuInput *, int, int, class Panel *); /* linkage=_ZN30CMenuHandler_PopupSubMenuInput11cursorMovedEiiPN4vgui5PanelE */

	virtual void cursorEntered(class CMenuHandler_PopupSubMenuInput *, class Panel *); /* linkage=_ZN30CMenuHandler_PopupSubMenuInput13cursorEnteredEPN4vgui5PanelE */

	virtual void cursorExited(class CMenuHandler_PopupSubMenuInput *, class Panel *); /* linkage=_ZN30CMenuHandler_PopupSubMenuInput12cursorExitedEPN4vgui5PanelE */

	virtual void mousePressed(class CMenuHandler_PopupSubMenuInput *, enum MouseCode, class Panel *); /* linkage=_ZN30CMenuHandler_PopupSubMenuInput12mousePressedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void mouseDoublePressed(class CMenuHandler_PopupSubMenuInput *, enum MouseCode, class Panel *); /* linkage=_ZN30CMenuHandler_PopupSubMenuInput18mouseDoublePressedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void mouseReleased(class CMenuHandler_PopupSubMenuInput *, enum MouseCode, class Panel *); /* linkage=_ZN30CMenuHandler_PopupSubMenuInput13mouseReleasedEN4vgui9MouseCodeEPNS0_5PanelE */

	virtual void mouseWheeled(class CMenuHandler_PopupSubMenuInput *, int, class Panel *); /* linkage=_ZN30CMenuHandler_PopupSubMenuInput12mouseWheeledEiPN4vgui5PanelE */

	virtual void keyPressed(class CMenuHandler_PopupSubMenuInput *, enum KeyCode, class Panel *); /* linkage=_ZN30CMenuHandler_PopupSubMenuInput10keyPressedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyTyped(class CMenuHandler_PopupSubMenuInput *, enum KeyCode, class Panel *); /* linkage=_ZN30CMenuHandler_PopupSubMenuInput8keyTypedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyReleased(class CMenuHandler_PopupSubMenuInput *, enum KeyCode, class Panel *); /* linkage=_ZN30CMenuHandler_PopupSubMenuInput11keyReleasedEN4vgui7KeyCodeEPNS0_5PanelE */

	virtual void keyFocusTicked(class CMenuHandler_PopupSubMenuInput *, class Panel *); /* linkage=_ZN30CMenuHandler_PopupSubMenuInput14keyFocusTickedEPN4vgui5PanelE */

	/* vtable has 11 entries: {
	   [0] = cursorMoved(_ZN30CMenuHandler_PopupSubMenuInput11cursorMovedEiiPN4vgui5PanelE), 
	   [1] = cursorEntered(_ZN30CMenuHandler_PopupSubMenuInput13cursorEnteredEPN4vgui5PanelE), 
	   [2] = cursorExited(_ZN30CMenuHandler_PopupSubMenuInput12cursorExitedEPN4vgui5PanelE), 
	   [3] = mousePressed(_ZN30CMenuHandler_PopupSubMenuInput12mousePressedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [4] = mouseDoublePressed(_ZN30CMenuHandler_PopupSubMenuInput18mouseDoublePressedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [5] = mouseReleased(_ZN30CMenuHandler_PopupSubMenuInput13mouseReleasedEN4vgui9MouseCodeEPNS0_5PanelE), 
	   [6] = mouseWheeled(_ZN30CMenuHandler_PopupSubMenuInput12mouseWheeledEiPN4vgui5PanelE), 
	   [7] = keyPressed(_ZN30CMenuHandler_PopupSubMenuInput10keyPressedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [8] = keyTyped(_ZN30CMenuHandler_PopupSubMenuInput8keyTypedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [9] = keyReleased(_ZN30CMenuHandler_PopupSubMenuInput11keyReleasedEN4vgui7KeyCodeEPNS0_5PanelE), 
	   [10] = keyFocusTicked(_ZN30CMenuHandler_PopupSubMenuInput14keyFocusTickedEPN4vgui5PanelE), 
	} */
	/* size: 12, cachelines: 1, members: 3 */
	/* last cacheline: 12 bytes */
};
class SpectButton : public CommandButton {
public:

	/* class CommandButton       <ancestor>; */      /*     0     0 */
	void SpectButton(class SpectButton *, class SpectButton &); /* linkage=_ZN11SpectButtonC4EOS_ */

	void SpectButton(class SpectButton *, const class SpectButton  &); /* linkage=_ZN11SpectButtonC4ERKS_ */

	void SpectButton(class SpectButton *, int, const char  *, int, int, int, int); /* linkage=_ZN11SpectButtonC4EiPKciiii */

	virtual void paintBackground(class SpectButton *); /* linkage=_ZN11SpectButton15paintBackgroundEv */

	virtual void paint(class SpectButton *); /* linkage=_ZN11SpectButton5paintEv */

	/* vtable has 2 entries: {
	   [111] = paintBackground(_ZN11SpectButton15paintBackgroundEv), 
	   [112] = paint(_ZN11SpectButton5paintEv), 
	} */
	/* size: 304, cachelines: 5, members: 1 */
	/* padding: 304 */
	/* last cacheline: 48 bytes */
};
class SpectatorPanel : public Panel {

	/* XXX 188 bytes hole, try to pack */
public:


	/* class Panel               <ancestor>; */      /*     0     0 */
	/* --- cacheline 2 boundary (128 bytes) was 60 bytes ago --- */
	class DropDownButton *     m_OptionButton;       /*   188     4 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	class CImageButton *       m_PrevPlayerButton;   /*   192     4 */
	class CImageButton *       m_NextPlayerButton;   /*   196     4 */
	class DropDownButton *     m_CamButton;          /*   200     4 */
	class CTransparentPanel *  m_TopBorder;          /*   204     4 */
	class CTransparentPanel *  m_BottomBorder;       /*   208     4 */
	class ColorButton *        m_InsetViewButton;    /*   212     4 */
	class DropDownButton *     m_BottomMainButton;   /*   216     4 */
	class CImageLabel *        m_TimerImage;         /*   220     4 */
	class Label *              m_BottomMainLabel;    /*   224     4 */
	class Label *              m_CurrentTime;        /*   228     4 */
	class Label *              m_ExtraInfo;          /*   232     4 */
	class Panel *              m_Separator;          /*   236     4 */
	class Label *              m_TeamScores[2];      /*   240     8 */
	class CImageLabel *        m_TopBanner;          /*   248     4 */
	bool                       m_menuVisible;        /*   252     1 */
	bool                       m_insetVisible;       /*   253     1 */
	void SpectatorPanel(class SpectatorPanel *, const class SpectatorPanel  &); /* linkage=_ZN14SpectatorPanelC4ERKS_ */

	void SpectatorPanel(class SpectatorPanel *, int, int, int, int); /* linkage=_ZN14SpectatorPanelC4Eiiii */

	virtual void ~SpectatorPanel(class SpectatorPanel *, int); /* linkage=_ZN14SpectatorPanelD4Ev */

	void ActionSignal(class SpectatorPanel *, int); /* linkage=_ZN14SpectatorPanel12ActionSignalEi */

	void Initialize(class SpectatorPanel *); /* linkage=_ZN14SpectatorPanel10InitializeEv */

	void Update(class SpectatorPanel *); /* linkage=_ZN14SpectatorPanel6UpdateEv */

	void EnableInsetView(class SpectatorPanel *, bool); /* linkage=_ZN14SpectatorPanel15EnableInsetViewEb */

	void ShowMenu(class SpectatorPanel *, bool); /* linkage=_ZN14SpectatorPanel8ShowMenuEb */


	/* size: 256, cachelines: 4, members: 18 */
	/* sum members: 66, holes: 1, sum holes: 188 */
	/* padding: 2 */
};
class DropDownButton : public ColorButton {
public:

	/* class ColorButton         <ancestor>; */      /*     0   320 */

	/* XXX last struct has 1 hole */
private:


	/* --- cacheline 5 boundary (320 bytes) --- */
	class CImageLabel *        m_pOpenButton;        /*   320     4 */
	void DropDownButton(class DropDownButton *, class DropDownButton &); /* linkage=_ZN14DropDownButtonC4EOS_ */

	void DropDownButton(class DropDownButton *, const class DropDownButton  &); /* linkage=_ZN14DropDownButtonC4ERKS_ */

	void DropDownButton(class DropDownButton *, const char  *, int, int, int, int, bool, bool); /* linkage=_ZN14DropDownButtonC4EPKciiiibb */

	virtual void setVisible(class DropDownButton *, bool); /* linkage=_ZN14DropDownButton10setVisibleEb */

	/* vtable has 1 entries: {
	   [9] = setVisible(_ZN14DropDownButton10setVisibleEb), 
	} */
	/* size: 324, cachelines: 6, members: 2 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 4 bytes */
};
class CImageButton : public ColorButton {
public:

	/* class ColorButton         <ancestor>; */      /*     0   320 */

	/* XXX last struct has 1 hole */
private:


	/* --- cacheline 5 boundary (320 bytes) --- */
	class CImageLabel *        m_pOpenButton;        /*   320     4 */
	void CImageButton(class CImageButton *, class CImageButton &); /* linkage=_ZN12CImageButtonC4EOS_ */

	void CImageButton(class CImageButton *, const class CImageButton  &); /* linkage=_ZN12CImageButtonC4ERKS_ */

	void CImageButton(class CImageButton *, const char  *, int, int, int, int, bool, bool); /* linkage=_ZN12CImageButtonC4EPKciiiibb */

	virtual void setVisible(class CImageButton *, bool); /* linkage=_ZN12CImageButton10setVisibleEb */

	/* vtable has 1 entries: {
	   [9] = setVisible(_ZN12CImageButton10setVisibleEb), 
	} */
	/* size: 324, cachelines: 6, members: 2 */
	/* member types with holes: 1, total: 1 */
	/* last cacheline: 4 bytes */
};
class ColorButton : public CommandButton {

	/* XXX 304 bytes hole, try to pack */
public:


	/* class CommandButton       <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 4 boundary (256 bytes) was 48 bytes ago --- */
	class Color *              ArmedColor;           /*   304     4 */
	class Color *              UnArmedColor;         /*   308     4 */
	class Color *              ArmedBorderColor;     /*   312     4 */
	class Color *              UnArmedBorderColor;   /*   316     4 */
	void ~ColorButton(class ColorButton *, int); /* linkage=_ZN11ColorButtonD4Ev */

	void ColorButton(class ColorButton *, class ColorButton &); /* linkage=_ZN11ColorButtonC4EOS_ */

	void ColorButton(class ColorButton *, const class ColorButton  &); /* linkage=_ZN11ColorButtonC4ERKS_ */

	void ColorButton(class ColorButton *, const char  *, int, int, int, int, bool, bool); /* linkage=_ZN11ColorButtonC4EPKciiiibb */

	virtual void paintBackground(class ColorButton *); /* linkage=_ZN11ColorButton15paintBackgroundEv */

	virtual void paint(class ColorButton *); /* linkage=_ZN11ColorButton5paintEv */

	void setArmedColor(class ColorButton *, int, int, int, int); /* linkage=_ZN11ColorButton13setArmedColorEiiii */

	void setUnArmedColor(class ColorButton *, int, int, int, int); /* linkage=_ZN11ColorButton15setUnArmedColorEiiii */

	void setArmedBorderColor(class ColorButton *, int, int, int, int); /* linkage=_ZN11ColorButton19setArmedBorderColorEiiii */

	void setUnArmedBorderColor(class ColorButton *, int, int, int, int); /* linkage=_ZN11ColorButton21setUnArmedBorderColorEiiii */

	/* vtable has 2 entries: {
	   [111] = paintBackground(_ZN11ColorButton15paintBackgroundEv), 
	   [112] = paint(_ZN11ColorButton5paintEv), 
	} */
	/* size: 320, cachelines: 5, members: 5 */
	/* sum members: 16, holes: 1, sum holes: 304 */
};
class CSpectatorHandler_Command : public ActionSignal {
public:

	/* class ActionSignal        <ancestor>; */      /*     0     4 */
private:

	class SpectatorPanel *     m_pFather;            /*     4     4 */
	int                        m_cmd;                /*     8     4 */
	void CSpectatorHandler_Command(class CSpectatorHandler_Command *, class CSpectatorHandler_Command &); /* linkage=_ZN25CSpectatorHandler_CommandC4EOS_ */

	void CSpectatorHandler_Command(class CSpectatorHandler_Command *, const class CSpectatorHandler_Command  &); /* linkage=_ZN25CSpectatorHandler_CommandC4ERKS_ */

	void CSpectatorHandler_Command(class CSpectatorHandler_Command *, class SpectatorPanel *, int); /* linkage=_ZN25CSpectatorHandler_CommandC4EP14SpectatorPaneli */

	virtual void actionPerformed(class CSpectatorHandler_Command *, class Panel *); /* linkage=_ZN25CSpectatorHandler_Command15actionPerformedEPN4vgui5PanelE */

	/* vtable has 1 entries: {
	   [0] = actionPerformed(_ZN25CSpectatorHandler_Command15actionPerformedEPN4vgui5PanelE), 
	} */
	/* size: 12, cachelines: 1, members: 3 */
	/* last cacheline: 12 bytes */
};
class CTeamMenuPanel : public CMenuPanel {
public:

	/* class CMenuPanel          <ancestor>; */      /*     0   212 */
	/* --- cacheline 3 boundary (192 bytes) was 20 bytes ago --- */
	class ScrollPanel *        m_pScrollPanel;       /*   212     4 */
	class CTransparentPanel *  m_pTeamWindow;        /*   216     4 */
	class Label *              m_pMapTitle;          /*   220     4 */
	class TextPanel *          m_pBriefing;          /*   224     4 */
	class TextPanel *          m_pTeamInfoPanel[6];  /*   228    24 */
	class CommandButton *      m_pButtons[6];        /*   252    24 */
	/* --- cacheline 4 boundary (256 bytes) was 20 bytes ago --- */
	bool                       m_bUpdatedMapName;    /*   276     1 */

	/* XXX 3 bytes hole, try to pack */

	class CommandButton *      m_pCancelButton;      /*   280     4 */
	class CommandButton *      m_pSpectateButton;    /*   284     4 */
	int                        m_iCurrentInfo;       /*   288     4 */
	void CTeamMenuPanel(class CTeamMenuPanel *, class CTeamMenuPanel &); /* linkage=_ZN14CTeamMenuPanelC4EOS_ */

	void CTeamMenuPanel(class CTeamMenuPanel *, const class CTeamMenuPanel  &); /* linkage=_ZN14CTeamMenuPanelC4ERKS_ */

	void CTeamMenuPanel(class CTeamMenuPanel *, int, int, int, int, int, int); /* linkage=_ZN14CTeamMenuPanelC4Eiiiiii */

	virtual bool SlotInput(class CTeamMenuPanel *, int); /* linkage=_ZN14CTeamMenuPanel9SlotInputEi */

	virtual void Open(class CTeamMenuPanel *); /* linkage=_ZN14CTeamMenuPanel4OpenEv */

	virtual void Update(class CTeamMenuPanel *); /* linkage=_ZN14CTeamMenuPanel6UpdateEv */

	virtual void SetActiveInfo(class CTeamMenuPanel *, int); /* linkage=_ZN14CTeamMenuPanel13SetActiveInfoEi */

	virtual void paintBackground(class CTeamMenuPanel *); /* linkage=_ZN14CTeamMenuPanel15paintBackgroundEv */

	virtual void Initialize(class CTeamMenuPanel *); /* linkage=_ZN14CTeamMenuPanel10InitializeEv */

	virtual void Reset(class CTeamMenuPanel *); /* linkage=_ZN14CTeamMenuPanel5ResetEv */

	/* vtable has 7 entries: {
	   [130] = SlotInput(_ZN14CTeamMenuPanel9SlotInputEi), 
	   [128] = Open(_ZN14CTeamMenuPanel4OpenEv), 
	   [132] = Update(_ZN14CTeamMenuPanel6UpdateEv), 
	   [131] = SetActiveInfo(_ZN14CTeamMenuPanel13SetActiveInfoEi), 
	   [111] = paintBackground(_ZN14CTeamMenuPanel15paintBackgroundEv), 
	   [133] = Initialize(_ZN14CTeamMenuPanel10InitializeEv), 
	   [127] = Reset(_ZN14CTeamMenuPanel5ResetEv), 
	} */
	/* size: 292, cachelines: 5, members: 11 */
	/* sum members: 289, holes: 1, sum holes: 3 */
	/* last cacheline: 36 bytes */
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
class CVoiceBanMgr {
	class BannedPlayer {
		char                       m_PlayerID[16];       /*     0    16 */
		class BannedPlayer *       m_pPrev;              /*    16     4 */
		class BannedPlayer *       m_pNext;              /*    20     4 */

		/* size: 24, cachelines: 1, members: 3 */
		/* last cacheline: 24 bytes */
	};

protected:

	class BannedPlayer        m_PlayerHash[256];     /*     0  6144 */
	void CVoiceBanMgr(class CVoiceBanMgr *); /* linkage=_ZN12CVoiceBanMgrC4Ev */

	void ~CVoiceBanMgr(class CVoiceBanMgr *, int); /* linkage=_ZN12CVoiceBanMgrD4Ev */

	bool Init(class CVoiceBanMgr *, const char  *); /* linkage=_ZN12CVoiceBanMgr4InitEPKc */

	void Term(class CVoiceBanMgr *); /* linkage=_ZN12CVoiceBanMgr4TermEv */

	void SaveState(class CVoiceBanMgr *, const char  *); /* linkage=_ZN12CVoiceBanMgr9SaveStateEPKc */

	bool GetPlayerBan(class CVoiceBanMgr *, const char  *); /* linkage=_ZN12CVoiceBanMgr12GetPlayerBanEPKc */

	void SetPlayerBan(class CVoiceBanMgr *, const char  *, bool); /* linkage=_ZN12CVoiceBanMgr12SetPlayerBanEPKcb */

	void ForEachBannedPlayer(class CVoiceBanMgr *, void (*)(char *)); /* linkage=_ZN12CVoiceBanMgr19ForEachBannedPlayerEPFvPcE */

	void Clear(class CVoiceBanMgr *); /* linkage=_ZN12CVoiceBanMgr5ClearEv */

	class BannedPlayer * InternalFindPlayerSquelch(class CVoiceBanMgr *, const char  *); /* linkage=_ZN12CVoiceBanMgr25InternalFindPlayerSquelchEPKc */

	class BannedPlayer * AddBannedPlayer(class CVoiceBanMgr *, const char  *); /* linkage=_ZN12CVoiceBanMgr15AddBannedPlayerEPKc */


	/* size: 6144, cachelines: 96, members: 1 */
};
class CVoiceLabel {
	class Label *              m_pLabel;             /*     0     4 */
	class Label *              m_pBackground;        /*     4     4 */
	class ImagePanel *         m_pIcon;              /*     8     4 */
	int                        m_clientindex;        /*    12     4 */

	/* size: 16, cachelines: 1, members: 4 */
	/* last cacheline: 16 bytes */
};
class CVoiceStatus : public CHudBase, public CDefaultInputSignal {
	enum {
		MAX_VOICE_SPEAKERS = 7,
	};

public:

	/* class CHudBase            <ancestor>; */      /*     0    20 */
	/* class CDefaultInputSignal <ancestor>; */      /*    20     4 */
	float                      m_LastUpdateServerState; /*    24     4 */
	int                        m_bServerModEnable;   /*    28     4 */
	class Panel * *            m_pParentPanel;       /*    32     4 */
	CPlayerBitVec              m_VoicePlayers;       /*    36     4 */
	CPlayerBitVec              m_AudiblePlayers;     /*    40     4 */
	CPlayerBitVec              m_VoiceEnabledPlayers; /*    44     4 */
	CPlayerBitVec              m_ServerBannedPlayers; /*    48     4 */
	struct cl_entity_s         m_VoiceHeadModels[32]; /*    52 96000 */
	/* --- cacheline 1500 boundary (96000 bytes) was 52 bytes ago --- */
	class IVoiceStatusHelper * m_pHelper;            /* 96052     4 */
	double                     m_BlinkTimer;         /* 96056     8 */
	/* --- cacheline 1501 boundary (96064 bytes) --- */
	class BitmapTGA *          m_pScoreboardNeverSpoken; /* 96064     4 */
	class BitmapTGA *          m_pScoreboardNotSpeaking; /* 96068     4 */
	class BitmapTGA *          m_pScoreboardSpeaking; /* 96072     4 */
	class BitmapTGA *          m_pScoreboardSpeaking2; /* 96076     4 */
	class BitmapTGA *          m_pScoreboardSquelch; /* 96080     4 */
	class BitmapTGA *          m_pScoreboardBanned;  /* 96084     4 */
	class Label *              m_pBanButtons[32];    /* 96088   128 */
	/* --- cacheline 1503 boundary (96192 bytes) was 24 bytes ago --- */
	bool                       m_bInSquelchMode;     /* 96216     1 */

	/* XXX 3 bytes hole, try to pack */

	HANDLE_SPRITE              m_VoiceHeadModel;     /* 96220     4 */
	float                      m_VoiceHeadModelHeight; /* 96224     4 */
	class Image *              m_pSpeakerLabelIcon;  /* 96228     4 */
	class BitmapTGA *          m_pLocalBitmap;       /* 96232     4 */
	class BitmapTGA *          m_pAckBitmap;         /* 96236     4 */
	class ImagePanel *         m_pLocalLabel;        /* 96240     4 */
	bool                       m_bTalking;           /* 96244     1 */
	bool                       m_bServerAcked;       /* 96245     1 */

	/* XXX 2 bytes hole, try to pack */

	class CVoiceBanMgr        m_BanMgr;              /* 96248  6144 */
	/* --- cacheline 1599 boundary (102336 bytes) was 56 bytes ago --- */
	bool                       m_bBanMgrInitialized; /* 102392     1 */

	/* XXX 3 bytes hole, try to pack */

	class CVoiceLabel         m_Labels[7];           /* 102396   112 */
	/* --- cacheline 1601 boundary (102464 bytes) was 44 bytes ago --- */
	char *                     m_pchGameDir;         /* 102508     4 */
	void CVoiceStatus(class CVoiceStatus *, const class CVoiceStatus  &); /* linkage=_ZN12CVoiceStatusC4ERKS_ */

	void CVoiceStatus(class CVoiceStatus *); /* linkage=_ZN12CVoiceStatusC4Ev */

	virtual void ~CVoiceStatus(class CVoiceStatus *, int); /* linkage=_ZN12CVoiceStatusD4Ev */

	virtual int Init(class CVoiceStatus *, class IVoiceStatusHelper *, class Panel * *); /* linkage=_ZN12CVoiceStatus4InitEP18IVoiceStatusHelperPPN4vgui5PanelE */

	virtual int VidInit(class CVoiceStatus *); /* linkage=_ZN12CVoiceStatus7VidInitEv */

	void Frame(class CVoiceStatus *, double); /* linkage=_ZN12CVoiceStatus5FrameEd */

	void UpdateSpeakerStatus(class CVoiceStatus *, int, qboolean); /* linkage=_ZN12CVoiceStatus19UpdateSpeakerStatusEii */

	void UpdateSpeakerImage(class CVoiceStatus *, class Label *, int); /* linkage=_ZN12CVoiceStatus18UpdateSpeakerImageEPN4vgui5LabelEi */

	void CreateEntities(class CVoiceStatus *); /* linkage=_ZN12CVoiceStatus14CreateEntitiesEv */

	void HandleVoiceMaskMsg(class CVoiceStatus *, int, void *); /* linkage=_ZN12CVoiceStatus18HandleVoiceMaskMsgEiPv */

	void HandleReqStateMsg(class CVoiceStatus *, int, void *); /* linkage=_ZN12CVoiceStatus17HandleReqStateMsgEiPv */

	void StartSquelchMode(class CVoiceStatus *); /* linkage=_ZN12CVoiceStatus16StartSquelchModeEv */

	void StopSquelchMode(class CVoiceStatus *); /* linkage=_ZN12CVoiceStatus15StopSquelchModeEv */

	bool IsInSquelchMode(class CVoiceStatus *); /* linkage=_ZN12CVoiceStatus15IsInSquelchModeEv */

	bool IsPlayerBlocked(class CVoiceStatus *, int); /* linkage=_ZN12CVoiceStatus15IsPlayerBlockedEi */

	bool IsPlayerAudible(class CVoiceStatus *, int); /* linkage=_ZN12CVoiceStatus15IsPlayerAudibleEi */

	void SetPlayerBlockedState(class CVoiceStatus *, int, bool); /* linkage=_ZN12CVoiceStatus21SetPlayerBlockedStateEib */

	class CVoiceLabel * FindVoiceLabel(class CVoiceStatus *, int); /* linkage=_ZN12CVoiceStatus14FindVoiceLabelEi */

	class CVoiceLabel * GetFreeVoiceLabel(class CVoiceStatus *); /* linkage=_ZN12CVoiceStatus17GetFreeVoiceLabelEv */

	void RepositionLabels(class CVoiceStatus *); /* linkage=_ZN12CVoiceStatus16RepositionLabelsEv */

	void FreeBitmaps(class CVoiceStatus *); /* linkage=_ZN12CVoiceStatus11FreeBitmapsEv */

	void UpdateServerState(class CVoiceStatus *, bool); /* linkage=_ZN12CVoiceStatus17UpdateServerStateEb */

	void UpdateBanButton(class CVoiceStatus *, int); /* linkage=_ZN12CVoiceStatus15UpdateBanButtonEi */

	/* vtable has 2 entries: {
	   [8] = Init(_ZN12CVoiceStatus4InitEP18IVoiceStatusHelperPPN4vgui5PanelE), 
	   [3] = VidInit(_ZN12CVoiceStatus7VidInitEv), 
	} */
	/* size: 102512, cachelines: 1602, members: 32 */
	/* sum members: 102504, holes: 3, sum holes: 8 */
	/* last cacheline: 48 bytes */
};
class CHudServers {
	struct request_s {
		class request_s *          next;                 /*     0     4 */
		netadr_t                   remote_address;       /*     4    20 */
		int                        context;              /*    24     4 */

		/* size: 28, cachelines: 1, members: 3 */
		/* last cacheline: 28 bytes */
	};

	struct server_s {
		class server_s *           next;                 /*     0     4 */
		netadr_t                   remote_address;       /*     4    20 */
		char *                     info;                 /*    24     4 */
		int                        ping;                 /*    28     4 */

		/* size: 32, cachelines: 1, members: 4 */
		/* last cacheline: 32 bytes */
	};

private:

	char                       m_szToken[1024];      /*     0  1024 */
	/* --- cacheline 16 boundary (1024 bytes) --- */
	int                        m_nRequesting;        /*  1024     4 */
	int                        m_nDone;              /*  1028     4 */
	double                     m_dStarted;           /*  1032     8 */
	typedef struct request_s request_t;

	request_t *                m_pServerList;        /*  1040     4 */
	request_t *                m_pActiveList;        /*  1044     4 */
	typedef struct server_s server_t;

	server_t *                 m_pServers;           /*  1048     4 */
	int                        m_nServerCount;       /*  1052     4 */
	int                        m_nActiveQueries;     /*  1056     4 */
	int                        m_nQuerying;          /*  1060     4 */
	double                     m_fElapsed;           /*  1064     8 */
	request_t *                m_pPingRequest;       /*  1072     4 */
	request_t *                m_pRulesRequest;      /*  1076     4 */
	request_t *                m_pPlayersRequest;    /*  1080     4 */
	void CHudServers(class CHudServers *); /* linkage=_ZN11CHudServersC4Ev */

	void ~CHudServers(class CHudServers *, int); /* linkage=_ZN11CHudServersD4Ev */

	void Think(class CHudServers *, double); /* linkage=_ZN11CHudServers5ThinkEd */

	void QueryThink(class CHudServers *); /* linkage=_ZN11CHudServers10QueryThinkEv */

	int isQuerying(class CHudServers *); /* linkage=_ZN11CHudServers10isQueryingEv */

	int LoadMasterAddresses(class CHudServers *, int, int *, netadr_t *); /* linkage=_ZN11CHudServers19LoadMasterAddressesEiPiP8netadr_s */

	void RequestList(class CHudServers *); /* linkage=_ZN11CHudServers11RequestListEv */

	void RequestBroadcastList(class CHudServers *, int); /* linkage=_ZN11CHudServers20RequestBroadcastListEi */

	void ServerPing(class CHudServers *, int); /* linkage=_ZN11CHudServers10ServerPingEi */

	void ServerRules(class CHudServers *, int); /* linkage=_ZN11CHudServers11ServerRulesEi */

	void ServerPlayers(class CHudServers *, int); /* linkage=_ZN11CHudServers13ServerPlayersEi */

	void CancelRequest(class CHudServers *); /* linkage=_ZN11CHudServers13CancelRequestEv */

	int CompareServers(class CHudServers *, server_t *, server_t *); /* linkage=_ZN11CHudServers14CompareServersEPNS_8server_sES1_ */

	void ClearServerList(class CHudServers *, server_t * *); /* linkage=_ZN11CHudServers15ClearServerListEPPNS_8server_sE */

	void ClearRequestList(class CHudServers *, request_t * *); /* linkage=_ZN11CHudServers16ClearRequestListEPPNS_9request_sE */

	void AddServer(class CHudServers *, server_t * *, server_t *); /* linkage=_ZN11CHudServers9AddServerEPPNS_8server_sES1_ */

	void RemoveServerFromList(class CHudServers *, request_t * *, request_t *); /* linkage=_ZN11CHudServers20RemoveServerFromListEPPNS_9request_sES1_ */

	request_t * FindRequest(class CHudServers *, int, request_t *); /* linkage=_ZN11CHudServers11FindRequestEiPNS_9request_sE */

	int ServerListSize(class CHudServers *); /* linkage=_ZN11CHudServers14ServerListSizeEv */

	char * GetServerInfo(class CHudServers *, int); /* linkage=_ZN11CHudServers13GetServerInfoEi */

	int GetServerCount(class CHudServers *); /* linkage=_ZN11CHudServers14GetServerCountEv */

	void SortServers(class CHudServers *, const char  *); /* linkage=_ZN11CHudServers11SortServersEPKc */

	void ListResponse(class CHudServers *, class net_response_s *); /* linkage=_ZN11CHudServers12ListResponseEP14net_response_s */

	void ServerResponse(class CHudServers *, class net_response_s *); /* linkage=_ZN11CHudServers14ServerResponseEP14net_response_s */

	void PingResponse(class CHudServers *, class net_response_s *); /* linkage=_ZN11CHudServers12PingResponseEP14net_response_s */

	void RulesResponse(class CHudServers *, class net_response_s *); /* linkage=_ZN11CHudServers13RulesResponseEP14net_response_s */

	void PlayersResponse(class CHudServers *, class net_response_s *); /* linkage=_ZN11CHudServers15PlayersResponseEP14net_response_s */

	server_t * GetServer(class CHudServers *, int); /* linkage=_ZN11CHudServers9GetServerEi */


	/* size: 1084, cachelines: 17, members: 14 */
	/* last cacheline: 60 bytes */
} __attribute__((__packed__));
class BufferWriter {
protected:

	unsigned char *            m_buffer;             /*     0     4 */
	int                        m_remaining;          /*     4     4 */
	bool                       m_overflow;           /*     8     1 */

	/* XXX 3 bytes hole, try to pack */

	int                        m_overallLength;      /*    12     4 */
	void BufferWriter(class BufferWriter *); /* linkage=_ZN12BufferWriterC4Ev */

	void BufferWriter(class BufferWriter *, unsigned char *, int); /* linkage=_ZN12BufferWriterC4EPhi */

	void Init(class BufferWriter *, unsigned char *, int); /* linkage=_ZN12BufferWriter4InitEPhi */

	void WriteByte(class BufferWriter *, unsigned char); /* linkage=_ZN12BufferWriter9WriteByteEh */

	void WriteLong(class BufferWriter *, int); /* linkage=_ZN12BufferWriter9WriteLongEi */

	void WriteString(class BufferWriter *, const char  *); /* linkage=_ZN12BufferWriter11WriteStringEPKc */

	bool HasOverflowed(class BufferWriter *); /* linkage=_ZN12BufferWriter13HasOverflowedEv */

	int GetSpaceUsed(class BufferWriter *); /* linkage=_ZN12BufferWriter12GetSpaceUsedEv */


	/* size: 16, cachelines: 1, members: 4 */
	/* sum members: 13, holes: 1, sum holes: 3 */
	/* last cacheline: 16 bytes */
};
class MemoryInputStream : public InputStream {
public:

	/* class InputStream         <ancestor>; */      /*     0     4 */
	uchar *                    m_pData;              /*     4     4 */
	int                        m_DataLen;            /*     8     4 */
	int                        m_ReadPos;            /*    12     4 */
	void ~MemoryInputStream(class MemoryInputStream *, int); /* linkage=_ZN17MemoryInputStreamD4Ev */

	void MemoryInputStream(class MemoryInputStream *, class MemoryInputStream &); /* linkage=_ZN17MemoryInputStreamC4EOS_ */

	void MemoryInputStream(class MemoryInputStream *, const class MemoryInputStream  &); /* linkage=_ZN17MemoryInputStreamC4ERKS_ */

	void MemoryInputStream(class MemoryInputStream *); /* linkage=_ZN17MemoryInputStreamC4Ev */

	virtual void seekStart(class MemoryInputStream *, bool &); /* linkage=_ZN17MemoryInputStream9seekStartERb */

	virtual void seekRelative(class MemoryInputStream *, int, bool &); /* linkage=_ZN17MemoryInputStream12seekRelativeEiRb */

	virtual void seekEnd(class MemoryInputStream *, bool &); /* linkage=_ZN17MemoryInputStream7seekEndERb */

	virtual int getAvailable(class MemoryInputStream *, bool &); /* linkage=_ZN17MemoryInputStream12getAvailableERb */

	virtual uchar readUChar(class MemoryInputStream *, bool &); /* linkage=_ZN17MemoryInputStream9readUCharERb */

	virtual void readUChar(class MemoryInputStream *, uchar *, int, bool &); /* linkage=_ZN17MemoryInputStream9readUCharEPhiRb */

	virtual void close(class MemoryInputStream *, bool &); /* linkage=_ZN17MemoryInputStream5closeERb */

	/* vtable has 7 entries: {
	   [0] = seekStart(_ZN17MemoryInputStream9seekStartERb), 
	   [1] = seekRelative(_ZN17MemoryInputStream12seekRelativeEiRb), 
	   [2] = seekEnd(_ZN17MemoryInputStream7seekEndERb), 
	   [3] = getAvailable(_ZN17MemoryInputStream12getAvailableERb), 
	   [4] = readUChar(_ZN17MemoryInputStream9readUCharERb), 
	   [5] = readUChar(_ZN17MemoryInputStream9readUCharEPhiRb), 
	   [6] = close(_ZN17MemoryInputStream5closeERb), 
	} */
	/* size: 16, cachelines: 1, members: 4 */
	/* last cacheline: 16 bytes */
};
class ScrollBarButton : public Button {

	/* XXX 240 bytes hole, try to pack */
public:


	/* class Button              <ancestor>; */      /*     0     0 */
private:

	/* --- cacheline 3 boundary (192 bytes) was 48 bytes ago --- */
	class LineBorder          m_Border;              /*   240     0 */
	void ScrollBarButton(class ScrollBarButton *, class ScrollBarButton &); /* linkage=_ZN15ScrollBarButtonC4EOS_ */

	void ScrollBarButton(class ScrollBarButton *, const class ScrollBarButton  &); /* linkage=_ZN15ScrollBarButtonC4ERKS_ */

	void ScrollBarButton(class ScrollBarButton *, const char  *, int, int, int, int); /* linkage=_ZN15ScrollBarButtonC4EPKciiii */

	virtual void paintBackground(class ScrollBarButton *); /* linkage=_ZN15ScrollBarButton15paintBackgroundEv */

	/* vtable has 1 entries: {
	   [111] = paintBackground(_ZN15ScrollBarButton15paintBackgroundEv), 
	} */
	/* size: 308, cachelines: 5, members: 2 */
	/* padding: 68 */
	/* last cacheline: 52 bytes */
};
class CVoiceBanMgr {
	class BannedPlayer {
		char                       m_PlayerID[16];       /*     0    16 */
		class BannedPlayer *       m_pPrev;              /*    16     4 */
		class BannedPlayer *       m_pNext;              /*    20     4 */

		/* size: 24, cachelines: 1, members: 3 */
		/* last cacheline: 24 bytes */
	};

protected:

	class BannedPlayer        m_PlayerHash[256];     /*     0  6144 */
	void CVoiceBanMgr(class CVoiceBanMgr *); /* linkage=_ZN12CVoiceBanMgrC4Ev */

	void ~CVoiceBanMgr(class CVoiceBanMgr *, int); /* linkage=_ZN12CVoiceBanMgrD4Ev */

	bool Init(class CVoiceBanMgr *, const char  *); /* linkage=_ZN12CVoiceBanMgr4InitEPKc */

	void Term(class CVoiceBanMgr *); /* linkage=_ZN12CVoiceBanMgr4TermEv */

	void SaveState(class CVoiceBanMgr *, const char  *); /* linkage=_ZN12CVoiceBanMgr9SaveStateEPKc */

	bool GetPlayerBan(class CVoiceBanMgr *, const char  *); /* linkage=_ZN12CVoiceBanMgr12GetPlayerBanEPKc */

	void SetPlayerBan(class CVoiceBanMgr *, const char  *, bool); /* linkage=_ZN12CVoiceBanMgr12SetPlayerBanEPKcb */

	void ForEachBannedPlayer(class CVoiceBanMgr *, void (*)(char *)); /* linkage=_ZN12CVoiceBanMgr19ForEachBannedPlayerEPFvPcE */

	void Clear(class CVoiceBanMgr *); /* linkage=_ZN12CVoiceBanMgr5ClearEv */

	class BannedPlayer * InternalFindPlayerSquelch(class CVoiceBanMgr *, const char  *); /* linkage=_ZN12CVoiceBanMgr25InternalFindPlayerSquelchEPKc */

	class BannedPlayer * AddBannedPlayer(class CVoiceBanMgr *, const char  *); /* linkage=_ZN12CVoiceBanMgr15AddBannedPlayerEPKc */


	/* size: 6144, cachelines: 96, members: 1 */
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
