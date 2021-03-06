
#ifndef	_DMS_STRUCT_DEF_H
#define	_DMS_STRUCT_DEF_H


#include	"../inc/os_type_def.h"
#include	"../inc/dms_std.h"
#include	"../inc/ems_init_def.h"



#define	DATABASE_VERSION_SIZE	12
#define	DATABASE_NAME_SIZE		12
#define DATABASE_LONGNAME_SIZE  36
#define	STATION_NAME_SIZE		12
#define STATION_LONGNAME_SIZE   24
#define STATION_COMMENT_SIZE	24
#define	STATION_EXLONGNAME_SIZE	24
#define STATION_EXCOMMENT_SIZE	24
#define	GROUP_NAME_SIZE	        12
#define GROUP_LONGNAME_SIZE     24
#define GROUP_COMMENT_SIZE		24
#define GROUP_TYPENAME_SIZE     12
#define GROUP_EXCOMMENT_SIZE	24
#define GROUP_EXLONGNAME_SIZE   24
#define	RECORD_NAME_SIZE		8	//12
#define RECORD_LONGNAME_SIZE    24
#define RECORD_EXLONGNAME_SIZE  24
#define	ENTRY_NAME_SIZE	        20 //16
#define ENTRY_LONGNAME_SIZE     64  //40
#define ENTRY_EXLONGNAME_SIZE   64
#define DSP_FILENAME_SIZE		24		/* relative display file name maxium length */		
#define ANLG_UNIT_NAME_SIZE     8
#define TERMINAL_NO_SIZE        16  //12
#define CABINET_NO_SIZE        12
#define UNIT_NO_SIZE			8
#define SLOT_NO_SIZE			8  //4
#define CHANNEL_NO_SIZE        16
#define	USR_NAME_SIZE			8
#define POINT_NAME_SIZE		STATION_NAME_SIZE+GROUP_NAME_SIZE+RECORD_NAME_SIZE+ENTRY_NAME_SIZE  //=52
#define POINT_LONGNAME_SIZE	STATION_LONGNAME_SIZE+GROUP_LONGNAME_SIZE+ENTRY_LONGNAME_SIZE
#define POINT_EXLONGNAME_SIZE	STATION_EXLONGNAME_SIZE+GROUP_EXLONGNAME_SIZE+ENTRY_EXLONGNAME_SIZE

#define	MAX_CURVE_SEG_NUM		288
#define	MAX_ALM_MSG_SIZE		36
#define	MAX_CMD_MSG_SIZE		36
#define	MAX_MSG_GROUP_NUM		32 //8
#define	MAX_IND_STATE_NUM		16		/* bit0~3 */
#define	MAX_CMD_OPER_TYPE_NUM	64		/* bit0~7 */

#define MAX_IOGROUP_COMMENT_SIZE	32
#define MAX_IOGROUP_EXCOMMENT_SIZE	64
#define MAX_IOGROUP_NUM				256

typedef	struct
{
	USHORT	 ms;
	UCHAR	 second;
	UCHAR    minute;
	UCHAR    hour;
	UCHAR    day;
	UCHAR    month;
	USHORT   year;		
} DATE_TIME;		


// typedef struct
// {
// #ifdef	_BIG_ENDIAN_
// 	UCHAR	res:2;
// 	UCHAR	alm:3;
// 	UCHAR	cmd:3;
// #else
// 	UCHAR	cmd:3;
// 	UCHAR	alm:3;
// 	UCHAR	res:2;
// #endif
// } MSG_SELECTOR;

typedef struct
{
	UCHAR	cmd;
	UCHAR	alm;
} MSG_SELECTOR;


typedef struct
{
#ifdef	_BIG_ENDIAN_
	USHORT	res3:2;
	USHORT	tagState:2;
	USHORT	res2:1;
	USHORT	almRepeat:1;
	USHORT	noUpdate:1;
	USHORT	ctrlLock:1;
	USHORT	almNoAck:1;
	USHORT	almEnable:1;
	USHORT	scanEnable:1;
	USHORT	res1:2;
	USHORT	viewPoint:3;
#else
	USHORT	viewPoint:3;
	USHORT	res1:2;
	USHORT	scanEnable:1;
	USHORT	almEnable:1;
	USHORT	almNoAck:1;
	USHORT	ctrlLock:1;
	USHORT	noUpdate:1;
	USHORT	almRepeat:1;
	USHORT	res2:1;
	USHORT	tagState:2;
	USHORT	res3:2;
#endif
} IOST;



typedef struct
{
#ifdef	_BIG_ENDIAN_
	GULONG	hdbPeriod:3;
	GULONG	res:4;
	GULONG	normalState:1;
	GULONG	offAlm:1;
	GULONG	onAlm:1;
	GULONG	hdbCurve:1;
	GULONG	hdbRec:1;
	GULONG	cascade:1;
	GULONG	lcuVirtual:1;
	GULONG	sysVirtual:1;
	GULONG	doublePt:1;
	GULONG	normalClose:1;
	GULONG	audAlm:1;
	GULONG	faultRec:1;
	GULONG	keySignal:1;
	GULONG	trendAlm:1;
	GULONG	soe:1;
	GULONG	ctrl:1;
	GULONG	fail:1;
	GULONG	fault:1;
	GULONG	statistic:1;
	GULONG	almCba:1;
	GULONG	procType:5;
#else
	GULONG	procType:5;
	GULONG	almCba:1;
	GULONG	statistic:1;
	GULONG	fault:1;
	GULONG	fail:1;
	GULONG	ctrl:1;
	GULONG	soe:1;
	GULONG	trendAlm:1;
	GULONG	keySignal:1;
	GULONG	faultRec:1;
	GULONG	audAlm:1;
	GULONG	normalClose:1;
	GULONG	doublePt:1;
	GULONG	sysVirtual:1;
	GULONG	lcuVirtual:1;
	GULONG	cascade:1;
	GULONG	hdbRec:1;
	GULONG	hdbCurve:1;
	GULONG	onAlm:1;
	GULONG	offAlm:1;
	GULONG	normalState:1;
	GULONG	res:4;
	GULONG	hdbPeriod:3;
#endif
} IOATTR;



typedef struct
{
	CHAR	cabinet_no[CABINET_NO_SIZE];
    CHAR	unit_no[UNIT_NO_SIZE];       	
    CHAR	slot_no[SLOT_NO_SIZE];		
    CHAR	channel_no[CHANNEL_NO_SIZE];	        
    CHAR	terminal_no[TERMINAL_NO_SIZE];		
} HARD_ADDR;


typedef	struct
{
    UCHAR	stn_id;
	UCHAR	dev_id;         
	UCHAR	data_type;      
	UCHAR	update_src;
	USHORT	pt_id;       
} POINTER;


typedef struct
{
#ifdef	_BIG_ENDIAN_
	USHORT	chan_fail:1;
	USHORT	ctrl_block:1;
	USHORT	overflow:1;
	USHORT	res:1;
	USHORT	sim_flag:1;
	USHORT	alm_type:3;
	USHORT	trend_state:4;
	USHORT	lmt_state:4;
#else
	USHORT	lmt_state:4;
	USHORT	trend_state:4;
	USHORT	alm_type:3;
	USHORT	sim_flag:1;
	USHORT	res:1;
	USHORT	overflow:1;
	USHORT	ctrl_block:1;
	USHORT	chan_fail:1;
#endif
} ANLG_STATUS;

typedef	struct
{
	ANLG_STATUS	status;		
 	GLONG	data;
} ANLG_DATA;


typedef	struct
{
#ifdef	_BIG_ENDIAN_
	USHORT	chan_fail:1;
	USHORT	man_set:1;
	USHORT	res3:1;
	USHORT	fault_tag:1;
	USHORT	sim_flag:1;
	USHORT	alm_type:3;
	USHORT	state:4;
	USHORT	rt_state:4;
#else
	USHORT	rt_state:4;
	USHORT	state:4;
	USHORT	alm_type:3;
	USHORT	sim_flag:1;
	USHORT	fault_tag:1;
	USHORT	res3:1;
	USHORT	man_set:1;
	USHORT	chan_fail:1;
#endif
} IND_DATA;


typedef	struct
{
#ifdef	_BIG_ENDIAN_
	USHORT	chan_fail:1;
	USHORT	man_set:1;
	USHORT	res1:3;
	USHORT	alm_type:3;
	USHORT	option:8;
#else
	USHORT	option:8;
	USHORT	alm_type:3;
	USHORT	res1:3;
	USHORT	man_set:1;
	USHORT	chan_fail:1;
#endif
} IMP_STATUS;


typedef struct
{
    GULONG	day;
    GULONG	month;
    GULONG	year;
} IMP_DATA;


typedef struct
{
    FLOAT	day;
    FLOAT	month;
    FLOAT	year;
} IMP_FLOAT_DATA;


typedef struct
{
	FLOAT	PT;		
	FLOAT	CT;		
    FLOAT	ENG_CVT;
	GULONG	CONSTANT;
	GULONG	DAY_RATE;
	GULONG	YEAR_RATE;
} IMP_ENG_PARA;



typedef struct
{
	USHORT	norm_open;
	USHORT	norm_close;
	USHORT	fault_open;
	USHORT	fault_close;
} STC_DATA;



typedef struct
{
	FLOAT	D_BAND;
	FLOAT	ENG_CVT;
	FLOAT	HI_RANGE;		
	FLOAT	LO_RANGE;		
	FLOAT	ZERO;			
	FLOAT	COMPSATE;
	FLOAT	HI_CODE;
	FLOAT	LO_CODE;
} ANA_ENG_PARA;



typedef struct
{
	FLOAT	HI_ALARM; 
	FLOAT	HI_WARN;
	FLOAT	HI_RECOVER;
	FLOAT	LO_ALARM;
	FLOAT	LO_WARN;
	FLOAT	LO_RECOVER;
	FLOAT	TR_WARN;
	FLOAT	TR_RECOVER;
} LMT_PARA;


typedef struct
{
	USHORT	max_no;
	USHORT	min_no;
	USHORT	max_rate_no;
	USHORT	min_rate_no;
	FLOAT	max_value;
	FLOAT	min_value;
	FLOAT	avg_value;
	FLOAT	std_value;
	FLOAT   max_rate;
	FLOAT   min_rate;
} CHARA_DATA;


typedef struct
{
	FLOAT	value[MAX_CURVE_SEG_NUM];
} CURVE_DATA;



typedef	struct
{
#ifdef	_BIG_ENDIAN_
	USHORT		src:4;
	USHORT		result:2;
	USHORT		state:2;
	USHORT		opr:8;
#else
	USHORT		opr:8;
	USHORT		state:2;
	USHORT		result:2;
	USHORT		src:4;
#endif
} COMMAND_STATUS;


typedef	struct
{
#ifdef	_BIG_ENDIAN_
	USHORT		condt1:1;
	USHORT		condt0:1;
	USHORT		remote:1;
	USHORT		lculm:1;
	USHORT		localm:1;
	USHORT		ma:2;
	USHORT		c1:1;
	USHORT		c0:1;
	USHORT		a1:1;
	USHORT		a0:1;
	USHORT		p1:1;
	USHORT		p0:1;
	USHORT		swgf_n:1;
	USHORT		condc1:1;
	USHORT		condc0:1;
#else
	USHORT		condc0:1;
	USHORT		condc1:1;
	USHORT		swgf_n:1;
	USHORT		p0:1;
	USHORT		p1:1;
	USHORT		a0:1;
	USHORT		a1:1;
	USHORT		c0:1;
	USHORT		c1:1;
	USHORT		ma:2;
	USHORT		localm:1;
	USHORT		lculm:1;
	USHORT		remote:1;
	USHORT		condt0:1;
	USHORT		condt1:1;
#endif
} FB_STATUS1;



typedef	struct
{
#ifdef	_BIG_ENDIAN_
	USHORT		res:11;
	USHORT		posd1:1;
	USHORT		posd0:1;
	USHORT		orderm:1;
	USHORT		q1:1;
	USHORT		q0:1;
#else
	USHORT		q0:1;
	USHORT		q1:1;
	USHORT		orderm:1;
	USHORT		posd0:1;
	USHORT		posd1:1;
	USHORT		res:11;
#endif
} FB_STATUS2;


typedef struct
{
	UCHAR	ioGroup;
	CHAR	comment[MAX_IOGROUP_COMMENT_SIZE];
#ifdef	EXTEND_LANGUAGE_SYSTEM
	CHAR	exComment[MAX_IOGROUP_EXCOMMENT_SIZE];
#endif
	UINT	ioGroupStatus;
} IOGROUP_INFO;

typedef struct  
{
	UCHAR		num;
	IOGROUP_INFO	iogroup[MAX_IOGROUP_NUM];
}IOGROUP_DEF;



/*--- DATABASE.OUT structure - first block ---*/
typedef struct				
{
	CHAR	version[DATABASE_VERSION_SIZE];
	CHAR    dbName[DATABASE_NAME_SIZE];
	CHAR    dbLongname[DATABASE_LONGNAME_SIZE];
	GULONG  stn_num;
	GULONG	grp_sum;
	GULONG	rec_sum;
	GULONG	imp_sum;
	GULONG	anlg_sum;
	GULONG	status_sum;
	GULONG	calc_sum;
	GULONG	chara_sum;
	GULONG	curve_sum;
	GULONG	devobj_sum;
	DATE_TIME  gen_date_time;		/* generate time */
} DB_HEAD_BLOCK;


/*--- Table Names ---*/

typedef struct                                  /* station structure */
{
    CHAR	stnName[STATION_NAME_SIZE];
    CHAR	stnLongname[STATION_LONGNAME_SIZE];
	CHAR	stnComment[STATION_COMMENT_SIZE];
#ifdef	EXTEND_LANGUAGE_SYSTEM
	CHAR	stnExLongname[STATION_EXLONGNAME_SIZE];
	CHAR	stnExComment[STATION_EXCOMMENT_SIZE];
#endif
    UCHAR   stnType;
    UCHAR   stnId;
	UCHAR	sysLcuId;
    GULONG	grp_num;                        /* Number of groups in the station	*/
    GULONG  grp_offset;                     /* Offset of first group in the station	*/
} STATION_ENTRY;


/*--- Group Names ---*/

typedef	struct					/* group structure */
{
	CHAR	grpName[GROUP_NAME_SIZE];	
	CHAR	grpLongname[GROUP_LONGNAME_SIZE]; 
	CHAR	grpComment[GROUP_COMMENT_SIZE];
	CHAR	grpTypeName[GROUP_TYPENAME_SIZE];
#ifdef	EXTEND_LANGUAGE_SYSTEM
	CHAR	grpExLongname[GROUP_EXLONGNAME_SIZE];
	CHAR	grpExComment[GROUP_EXCOMMENT_SIZE];
#endif
	UCHAR	grpId;
	UCHAR	sysLcuFlag;
	GULONG	rec_num;			/* Number of records in the group	*/
	GULONG	rec_offset;			/* Offset of first record in the group	*/
	GULONG	hash_key;
	IOGROUP_DEF	iogroup_def;
} GROUP_ENTRY;


/*--- Record descriptors ---*/

typedef	struct					/* record structure */
{
	UCHAR	recType;
	USHORT	hash_pn;			/*hash prime number*/
	GULONG	entry_num;			/* Number of entries in the record	*/
	GULONG	entry_offset;		/* Offset of first entry in the record	*/
} RECORD_ENTRY;




/*--- Entry Descriptors ---*/

typedef	struct		/* Entry descriptor - fixed portion */
{
	CHAR		entryName[ENTRY_NAME_SIZE];	/* Entry's name	*/
	CHAR		entryLongname[ENTRY_LONGNAME_SIZE];	/* Entry's longname	*/
#ifdef	EXTEND_LANGUAGE_SYSTEM
	CHAR		entryExLongname[ENTRY_EXLONGNAME_SIZE];
#endif
	CHAR		dsp_filename[DSP_FILENAME_SIZE];
    HARD_ADDR	hard_addr;
	USHORT		io_group;
	IOST		iost;
	IOATTR		ioattr;
	POINTER		pair_pt;
 	USHORT		ctrl_addr;
	MSG_SELECTOR msg_sel;
	UCHAR		update_src;
	USHORT		hash_index;
	USHORT		hash_next;
	GULONG		hash_key;
} ENTRY_FIXED;



typedef struct
{
	DATE_TIME	update_time;
    IND_DATA	status;
    DATE_TIME   change_time;
	STC_DATA	stc;
} ENTRY_STAT_VAL;


typedef struct
{
	DATE_TIME	update_time;		
	ANLG_DATA	value;
    FLOAT       fValue;
    CHAR        unitName[ANLG_UNIT_NAME_SIZE];
    ANA_ENG_PARA    eng_para;
    LMT_PARA    lmt_para;
} ENTRY_ANLG_VAL;


typedef struct
{
	DATE_TIME	update_time;		
    GULONG	    rt_value;
    GLONG	    base_value;	
	IMP_STATUS	status;
    FLOAT		d_accum;
	IMP_ENG_PARA	eng_para;
	IMP_DATA	init;
	IMP_DATA	last;
	IMP_DATA	peak;
	IMP_DATA	valley;
	IMP_DATA	normal;			
	IMP_DATA	sum;			
	IMP_DATA	ppeak;			
} ENTRY_IMP_VAL;


typedef struct
{
	DATE_TIME	update_time;		
    CHARA_DATA  chara_data;
	CHAR		start_pt_name[POINT_NAME_SIZE];
	UCHAR		pt_num;
} ENTRY_CHARA_VAL;



typedef struct
{
	DATE_TIME	update_time;		
	USHORT		seg_num;
    ANA_ENG_PARA    eng_para;
    CURVE_DATA	data;
} ENTRY_CURVE_VAL;



typedef struct
{
	DATE_TIME	update_time;		
	DATE_TIME	cmd_time;		
	CHAR		usr_name[USR_NAME_SIZE];
    UCHAR		host_id;
	COMMAND_STATUS	status;
	union
	{
		GLONG	iValue;
		FLOAT	fValue;
	}data;
	FB_STATUS1	fb_status1;
	FB_STATUS2	fb_status2;
	USHORT		param;
} ENTRY_DEVOBJ_VAL;

typedef struct  
{
	FLOAT		x,y,z;
}TIME_PT_COORDS;

typedef struct
{
	DATE_TIME	update_time;		
	TIME_PT_COORDS		coords;
	GULONG		value_sec;		
	USHORT		value_ms;
	COMMAND_STATUS	status;
	CHAR		usr_name[USR_NAME_SIZE];
	UCHAR		host_id;
} ENTRY_TIME_VAL;



typedef struct
{
	struct
	{
		CHAR		def[MAX_IND_STATE_NUM][MAX_ALM_MSG_SIZE];
#ifdef	EXTEND_LANGUAGE_SYSTEM
		CHAR		Exdef[MAX_IND_STATE_NUM][MAX_ALM_MSG_SIZE];
#endif
	} group[MAX_MSG_GROUP_NUM];
} MSG_DEF;


typedef struct
{
	UCHAR	cmdType;
	struct
	{
		CHAR		def[MAX_CMD_OPER_TYPE_NUM][MAX_CMD_MSG_SIZE];
#ifdef	EXTEND_LANGUAGE_SYSTEM
		CHAR		Exdef[MAX_CMD_OPER_TYPE_NUM][MAX_CMD_MSG_SIZE];
#endif
	} group[MAX_MSG_GROUP_NUM];
} CMD_MSG;

/* *************************************************** */
/* The following are used for DBS_COMMON shared memory */
/* *************************************************** */




#define STATION_ENTRY_NUMBER	10
#define	GROUP_ENTRY_NUM_PER_STATION	36	
#define GROUP_ENTRY_NUMBER	200	
#define	RECORD_ENTRY_NUMBER	10*GROUP_ENTRY_NUMBER	
#define	ENTRY_IMP_NUMBER	5000	
#define	ENTRY_ANLG_NUMBER	40000	
#define ENTRY_STATUS_NUMBER	150000	
#define	ENTRY_CHARA_NUMBER	5000	
#define ENTRY_CALC_NUMBER	5000	
#define ENTRY_CURVE_NUMBER	1000	
#define ENTRY_DEVOBJ_NUMBER	5000	
#define ENTRY_TIME_NUMBER	2000//1000	

#define	MAX_PROCTYPE_NUM	32
#define	MAX_CMDTYPE_NUM		64


#define DB_BLOCK_SIZE	        512		/* data base block size */
#define DB_HEAD_BLOCK_SIZE      ((sizeof(DB_HEAD_BLOCK)+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE
#define STATION_UNION_SIZE      ((sizeof(STATION_ENTRY)*STATION_ENTRY_NUMBER+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE 
#define GROUP_UNION_SIZE        ((sizeof(GROUP_ENTRY)*GROUP_ENTRY_NUMBER+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE	
#define RECORD_UNION_SIZE       ((sizeof(RECORD_ENTRY)*RECORD_ENTRY_NUMBER+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE
#define ENTRYFIXED_IMP_SIZE		((sizeof(ENTRY_FIXED)*ENTRY_IMP_NUMBER+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE
#define ENTRYFIXED_ANLG_SIZE	((sizeof(ENTRY_FIXED)*ENTRY_ANLG_NUMBER+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE
#define ENTRYFIXED_STATUS_SIZE	((sizeof(ENTRY_FIXED)*ENTRY_STATUS_NUMBER+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE
#define ENTRYFIXED_CALC_SIZE	((sizeof(ENTRY_FIXED)*ENTRY_CALC_NUMBER+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE
#define ENTRYFIXED_CHARA_SIZE	((sizeof(ENTRY_FIXED)*ENTRY_CHARA_NUMBER+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE
#define ENTRYFIXED_CURVE_SIZE	((sizeof(ENTRY_FIXED)*ENTRY_CURVE_NUMBER+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE
#define ENTRYFIXED_DEVOBJ_SIZE	((sizeof(ENTRY_FIXED)*ENTRY_DEVOBJ_NUMBER+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE
#define	ENTRY_VAR_IMP_SIZE		((sizeof(ENTRY_IMP_VAL)*ENTRY_IMP_NUMBER+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE
#define	ENTRY_VAR_ANLG_SIZE		((sizeof(ENTRY_ANLG_VAL)*ENTRY_ANLG_NUMBER+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE
#define	ENTRY_VAR_STATUS_SIZE	((sizeof(ENTRY_STAT_VAL)*ENTRY_STATUS_NUMBER+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE
#define	ENTRY_VAR_CALC_SIZE		((sizeof(ENTRY_ANLG_VAL)*ENTRY_CALC_NUMBER+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE
#define	ENTRY_VAR_CHARA_SIZE	((sizeof(ENTRY_CHARA_VAL)*ENTRY_CHARA_NUMBER+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE 
#define	ENTRY_VAR_CURVE_SIZE	((sizeof(ENTRY_CURVE_VAL)*ENTRY_CURVE_NUMBER+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE 
#define	ENTRY_VAR_DEVOBJ_SIZE	((sizeof(ENTRY_DEVOBJ_VAL)*ENTRY_DEVOBJ_NUMBER+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE 

#define ENTRYFIXED_TIME_SIZE	((sizeof(ENTRY_FIXED)*ENTRY_TIME_NUMBER+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE
#define	ENTRY_VAR_TIME_SIZE	((sizeof(ENTRY_DEVOBJ_VAL)*ENTRY_TIME_NUMBER+DB_BLOCK_SIZE-1)/DB_BLOCK_SIZE)*DB_BLOCK_SIZE 


typedef struct
{
    union   
	{
        CHAR            spare[DB_HEAD_BLOCK_SIZE];
        DB_HEAD_BLOCK   head;
    } Head_Union;

    union   
	{
        CHAR            spare[STATION_UNION_SIZE];
        STATION_ENTRY   StationEntry[STATION_ENTRY_NUMBER];
    } Station_Union;

	union   
	{
        CHAR            spare[GROUP_UNION_SIZE];
        GROUP_ENTRY     GroupEntry[GROUP_ENTRY_NUMBER];
	} Group_Union;

	union   
	{
        CHAR            spare[RECORD_UNION_SIZE];
        RECORD_ENTRY    RecordEntry[RECORD_ENTRY_NUMBER];
	} Record_Union;

	union   
	{
        CHAR            spare[ENTRYFIXED_ANLG_SIZE];
        ENTRY_FIXED     EntryFixed[ENTRY_ANLG_NUMBER];
	} EntryFixed_Anlg_Union;

    union   
	{
		CHAR            spare[ENTRYFIXED_IMP_SIZE];
		ENTRY_FIXED     EntryFixed[ENTRY_IMP_NUMBER];
	} EntryFixed_Imp_Union;

    union   
	{
		CHAR            spare[ENTRYFIXED_STATUS_SIZE];
		ENTRY_FIXED     EntryFixed[ENTRY_STATUS_NUMBER];
	} EntryFixed_Status_Union;

    union   
	{
        CHAR            spare[ENTRYFIXED_CALC_SIZE];
        ENTRY_FIXED     EntryFixed[ENTRY_CALC_NUMBER];
	} EntryFixed_Calc_Union;

    union   
	{
        CHAR            spare[ENTRYFIXED_CHARA_SIZE];
        ENTRY_FIXED     EntryFixed[ENTRY_CHARA_NUMBER];
	} EntryFixed_Chara_Union;

    union   
	{
        CHAR            spare[ENTRYFIXED_CURVE_SIZE];
        ENTRY_FIXED     EntryFixed[ENTRY_CURVE_NUMBER];
	} EntryFixed_Curve_Union;

    union   
	{
        CHAR            spare[ENTRYFIXED_DEVOBJ_SIZE];
        ENTRY_FIXED     EntryFixed[ENTRY_DEVOBJ_NUMBER];
	} EntryFixed_DevObj_Union;

    union   
	{
        CHAR            spare[ENTRYFIXED_TIME_SIZE];
        ENTRY_FIXED     EntryFixed[ENTRY_TIME_NUMBER];
	} EntryFixed_Time_Union;
	
	union	
	{
		CHAR            spare[ENTRY_VAR_ANLG_SIZE];
		ENTRY_ANLG_VAL	EntryVariable[ENTRY_ANLG_NUMBER];
	} EntryVar_Anlg_Union;

	union	
	{
		CHAR            spare[ENTRY_VAR_IMP_SIZE];
		ENTRY_IMP_VAL	EntryVariable[ENTRY_IMP_NUMBER];
	} EntryVar_Imp_Union;

	union	
	{
		CHAR			spare[ENTRY_VAR_STATUS_SIZE];
		ENTRY_STAT_VAL	EntryVariable[ENTRY_STATUS_NUMBER];
	} EntryVar_Status_Union;

	union	
	{
		CHAR            spare[ENTRY_VAR_CALC_SIZE];
		ENTRY_ANLG_VAL	EntryVariable[ENTRY_CALC_NUMBER];
	} EntryVar_Calc_Union;

	union	
	{
		CHAR            spare[ENTRY_VAR_CHARA_SIZE];
		ENTRY_CHARA_VAL	EntryVariable[ENTRY_CHARA_NUMBER];
	} EntryVar_Chara_Union;

	union	
	{
		CHAR            spare[ENTRY_VAR_CURVE_SIZE];
		ENTRY_CURVE_VAL	EntryVariable[ENTRY_CURVE_NUMBER];
	} EntryVar_Curve_Union;

	union	
	{
		CHAR            spare[ENTRY_VAR_DEVOBJ_SIZE];
		ENTRY_DEVOBJ_VAL	EntryVariable[ENTRY_DEVOBJ_NUMBER];
	} EntryVar_DevObj_Union;

	union	
	{
		CHAR            spare[ENTRY_VAR_TIME_SIZE];
		ENTRY_TIME_VAL	EntryVariable[ENTRY_TIME_NUMBER];
	} EntryVar_Time_Union;
	
	MSG_DEF				msg_def[MAX_PROCTYPE_NUM];
	CMD_MSG 			cmd_msg[MAX_CMDTYPE_NUM];

} DBS_GBL_COMMON;



#endif  /*_DMS_STRUCT_DEF_H*/

