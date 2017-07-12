#ifndef _CTRLPROTOCOL_H_
#define _CTRLPROTOCOL_H_

#include "iflytype.h"
#include "camera.h"

#ifdef WIN32
#include "winsock2.h"
#include <ws2tcpip.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <errno.h>
#include <semaphore.h>
#endif

#ifdef WIN32
#define SOCKHANDLE		SOCKET
#else
#define SOCKHANDLE		int
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WIN32
#define INFINITE						0xffffffff
#endif

#define CTRL_PROTOCOL_SERVERPORT		6610					//服务器端口
#define CTRL_PROTOCOL_MAXLINKNUM		256

#define CTRL_PROTOCOL_CONNECT_BLOCK		INFINITE				//连接方式:阻塞
#define CTRL_PROTOCOL_CONNECT_DEFAULT	3000					//缺省连接时间:3秒

#define CTRL_VERSION					0x0100

#define CTRL_COMMAND					0
#define CTRL_NOTIFY						1
#define CTRL_ACK						2

//命令类型
#define CTRL_CMD_BASE					10000
#define CTRL_CMD_STARTVIDEOMONITOR		CTRL_CMD_BASE+0			//开始视频监控
#define CTRL_CMD_STOPVIDEOMONITOR		CTRL_CMD_BASE+1			//停止视频监控
#define CTRL_CMD_STARTAUDIOMONITOR		CTRL_CMD_BASE+2			//开始音频监控
#define CTRL_CMD_STOPAUDIOMONITOR		CTRL_CMD_BASE+3			//停止音频监控

#define CTRL_CMD_STARTFILEPLAY			CTRL_CMD_BASE+5			//开始远程文件回放
#define CTRL_CMD_STOPFILEPLAY			CTRL_CMD_BASE+6			//停止远程文件回放
#define CTRL_CMD_STARTTIMEPLAY			CTRL_CMD_BASE+7			//开始远程时间回放
#define CTRL_CMD_STOPTIMEPLAY			CTRL_CMD_BASE+8			//停止远程时间回放
#define CTRL_CMD_FASTPLAY				CTRL_CMD_BASE+9			//快放
#define CTRL_CMD_SLOWPLAY				CTRL_CMD_BASE+10		//慢放
#define CTRL_CMD_SETPLAYRATE			CTRL_CMD_BASE+11		//设置播放速率
#define CTRL_CMD_PAUSEPLAY				CTRL_CMD_BASE+12		//暂停
#define CTRL_CMD_RESUMEPLAY				CTRL_CMD_BASE+13		//恢复
#define CTRL_CMD_SINGLEPLAY				CTRL_CMD_BASE+14		//帧进
#define CTRL_CMD_FASTBACKPLAY			CTRL_CMD_BASE+15		//快退
#define CTRL_CMD_PLAYPREV				CTRL_CMD_BASE+16		//上一段
#define CTRL_CMD_PLAYNEXT				CTRL_CMD_BASE+17		//下一段
#define CTRL_CMD_PLAYSEEK				CTRL_CMD_BASE+18		//seek
#define CTRL_CMD_PLAYMUTE				CTRL_CMD_BASE+19		//静音
#define CTRL_CMD_PLAYPROGRESS			CTRL_CMD_BASE+20		//播放进度
#define CTRL_CMD_STARTVOIP				CTRL_CMD_BASE+21		//开始语音队讲		07-07-27
#define CTRL_CMD_STOPVOIP				CTRL_CMD_BASE+22		//停止语音队讲		07-07-27
#define CTRL_CMD_UPDATE					CTRL_CMD_BASE+23		//远程软件升级		07-07-27
#define CTRL_CMD_REBOOT					CTRL_CMD_BASE+24		//远程重启			07-07-27
#define CTRL_CMD_OSD_CHANNEL    		CTRL_CMD_BASE+25		//远程通道位置设置	07-07-27
#define CTRL_CMD_OSD_TIME				CTRL_CMD_BASE+26		//远程时间位置设置	07-07-27
#define CTRL_CMD_MASK					CTRL_CMD_BASE+27		//远程遮盖区域设置	07-07-31
#define CTRL_CMD_PICTURE_ADJUST			CTRL_CMD_BASE+28		//画质调节，包括亮度 色度 对比度及饱和度07-07-31

#define CTRL_CMD_STARTRECDOWNLOAD		CTRL_CMD_BASE+30		//开始下载录像文件
#define CTRL_CMD_STOPRECDOWNLOAD		CTRL_CMD_BASE+31		//停止下载录像文件
#define CTRL_CMD_MDAREA					CTRL_CMD_BASE+32		//设置移动侦测区域
#define CTRL_CMD_CAMERA					CTRL_CMD_BASE+33		//云台控制

#define CTRL_CMD_NETCONFIG				CTRL_CMD_BASE+34		//远程网络配置
#define CTRL_CMD_TIMESET_PARAMSH		CTRL_CMD_BASE+35		//遮挡报警远程布防
#define CTRL_CMD_TIMESET_PARAMVL		CTRL_CMD_BASE+36		//视频丢失远程布防
#define CTRL_CMD_TIMESET_PARAMMD		CTRL_CMD_BASE+37		//移动侦测远程布防
#define CTRL_CMD_EXCEPTION				CTRL_CMD_BASE+38		//远程异常设置
#define CTRL_CMD_MOTION_ALARM			CTRL_CMD_BASE+39		//远程移动侦测处理
#define CTRL_CMD_REC_SETTIME			CTRL_CMD_BASE+40		//录像启动设置
#define CTRL_CMD_ALARMSET				CTRL_CMD_BASE+41		//报警设置
#define CTRL_CMD_ALARMIN_SETTIME		CTRL_CMD_BASE+42		//报警输入布防
#define CTRL_CMD_ALARMIN_MANAGE			CTRL_CMD_BASE+43		//报警输入处理
#define CTRL_CMD_ALARMIN_PTZ			CTRL_CMD_BASE+44		//报警输入PTZ联动
#define CTRL_CMD_ALARMOUT_SET			CTRL_CMD_BASE+45		//报警输出设置
#define CTRL_CMD_IMAGSET_PARAM			CTRL_CMD_BASE+46		//远程图像设置参数设置
#define CTRL_CMD_RECORDSET_PARAM		CTRL_CMD_BASE+47		//远程录像设置参数设置
#define CTRL_CMD_LOGIN					CTRL_CMD_BASE+48		//远程登录命令
#define CTRL_CMD_USERQUERY				CTRL_CMD_BASE+49		//远程用户信息管理
#define CTRL_CMD_USEREDIT				CTRL_CMD_BASE+50		//远程用户编辑 
#define CTRL_CMD_YUNTAISET				CTRL_CMD_BASE+51		//远程云台参数设置
#define CTRL_CMD_SYSPARAM				CTRL_CMD_BASE+52		//远程系统参数查询
#define CTRL_CMD_SYSINFO				CTRL_CMD_BASE+53		//远程系统信息查询
#define CTRL_CMD_HDDINFO				CTRL_CMD_BASE+54		//远程硬盘信息查询
#define CTRL_CMD_CLRALARM				CTRL_CMD_BASE+55		//远程清除报警
#define CTRL_CMD_ONLINE					CTRL_CMD_BASE+56		//远程在线用户查询
#define CTRL_CMD_EDITPASS				CTRL_CMD_BASE+57		//远程修改登录用户密码

#define CTRL_CMD_USER_ADD				CTRL_CMD_BASE+60		//远程用户添加
#define CTRL_CMD_USER_MODIFY			CTRL_CMD_BASE+61		//远程用户修改
#define CTRL_CMD_USER_DEL				CTRL_CMD_BASE+62		//远程用户删除
#define CTRL_CMD_LOG					CTRL_CMD_BASE+63		//远程日志查询
#define CTRL_CMD_HANDREC				CTRL_CMD_BASE+64		//远程手动录像

#define CTRL_CMD_LOGINOFF				CTRL_CMD_BASE+67		//注销用户登录
#define CTRL_CMD_NETQUERY				CTRL_CMD_BASE+68		//查询网络设置
#define CTRL_CMD_HANDINFO				CTRL_CMD_BASE+69
#define CTRL_CMD_EXCEPINFO				CTRL_CMD_BASE+70
#define CTRL_CMD_YUNTAIINFO				CTRL_CMD_BASE+71
#define CTRL_CMD_IMAGINFO				CTRL_CMD_BASE+72
#define CTRL_CMD_RECINFO				CTRL_CMD_BASE+73
#define CTRL_CMD_SYSPARA_INFO			CTRL_CMD_BASE+74
#define CTRL_CMD_SYSTIME_FIRST			CTRL_CMD_BASE+75
#define CTRL_CMD_SYSTIME_SEND			CTRL_CMD_BASE+76
#define CTRL_CMD_ALARMSET_FIRST			CTRL_CMD_BASE+77
#define CTRL_CMD_SHTIME_FIRST			CTRL_CMD_BASE+78
#define CTRL_CMD_VLTIME_FIRST			CTRL_CMD_BASE+79
#define CTRL_CMD_MDTIME_FIRST			CTRL_CMD_BASE+80
#define CTRL_CMD_MDSET_FIRST			CTRL_CMD_BASE+81
#define CTRL_CMD_RECSTART_FIRST			CTRL_CMD_BASE+82
#define CTRL_CMD_INSET_FIRST			CTRL_CMD_BASE+83
#define CTRL_CMD_INDISPOSE_FIRST		CTRL_CMD_BASE+84
#define CTRL_CMD_INPTZ_FIRST			CTRL_CMD_BASE+85
#define CTRL_CMD_OUTSET_FIRST			CTRL_CMD_BASE+86
#define CTRL_CMD_RECSEARCH				CTRL_CMD_BASE+87			//回放查询07-07-30
#define CTRL_CMD_USER_SEND				CTRL_CMD_BASE+88			//07-07-30
#define CTRL_CMD_LAYIN					CTRL_CMD_BASE+89			//远程导入07-08-02
#define CTRL_CMD_LAYOUT					CTRL_CMD_BASE+90			//远程导出07-08-02
#define CTRL_CMD_PRESET_SAVE			CTRL_CMD_BASE+91		//预置点添加
#define CTRL_CMD_PRESET_DEL				CTRL_CMD_BASE+92		//预置点删除
#define CTRL_CMD_CRUISEPOS_ADD			CTRL_CMD_BASE+93		//巡航路径号添加
#define CTRL_CMD_CRUISEPOS_DEL			CTRL_CMD_BASE+94		//巡航路径号删除
#define CTRL_CMD_CRUISE_START			CTRL_CMD_BASE+95			//开始巡航
#define CTRL_CMD_CRUISE_STOP			CTRL_CMD_BASE+96			//结束巡航
#define CTRL_CMD_TRACKPATTERN_START		CTRL_CMD_BASE+97	//记录轨迹
#define CTRL_CMD_TRACKPATTERN_STOP		CTRL_CMD_BASE+98	//结束记录
#define CTRL_CMD_TRACK_START		CTRL_CMD_BASE+99				//开始轨迹
#define CTRL_CMD_TRACK_STOP		CTRL_CMD_BASE+100					//停止轨迹
#define CTRL_CMD_RESOLUTION   CTRL_CMD_BASE+101					//图像分辨率
#define CTRL_CMD_MULTICAST		CTRL_CMD_BASE+102				 //请求组播地址

//事件通知类型
#define CTRL_NOTIFY_BASE				20000
#define	CTRL_NOTIFY_CONNLOST			CTRL_NOTIFY_BASE+0		//断链消息
#define	CTRL_NOTIFY_HEARTBEAT_REQ		CTRL_NOTIFY_BASE+1		//心跳请求
#define	CTRL_NOTIFY_HEARTBEAT_RESP		CTRL_NOTIFY_BASE+2		//心跳回复
#define CTRL_NOTIFY_PLAYEND				CTRL_NOTIFY_BASE+3		//放像结束
#define CTRL_NOTIFY_PLAYPROGRESS		CTRL_NOTIFY_BASE+4		//放像进度通知

//应答类型
#define CTRL_SUCCESS					0						//成功
#define CTRL_FAILED_BASE				30000					//错误码偏移量
#define CTRL_FAILED_USER				CTRL_FAILED_BASE+1		//不存在的用户名
#define CTRL_FAILED_PASSWORD			CTRL_FAILED_BASE+2		//密码错误
#define CTRL_FAILED_COMMAND				CTRL_FAILED_BASE+3		//未认可的命令
#define CTRL_FAILED_PARAM				CTRL_FAILED_BASE+4		//无效参数
#define CTRL_FAILED_OUTOFMEMORY			CTRL_FAILED_BASE+5		//内存不足
#define CTRL_FAILED_RESOURCE			CTRL_FAILED_BASE+6		//资源不足
#define CTRL_FAILED_FILENOTEXIST		CTRL_FAILED_BASE+7		//文件不存在
#define CTRL_FAILED_DATABASE			CTRL_FAILED_BASE+8		//数据库错误
#define CTRL_FAILED_RELOGIN				CTRL_FAILED_BASE+9		//重复登录
#define CTRL_FAILED_BAUDLIMIT			CTRL_FAILED_BASE+10		//每一路通道最多支持5路实时监控			
#define CTRL_FAILED_CREATESOCKET		CTRL_FAILED_BASE+11		//创建套结字失败
#define CTRL_FAILED_CONNECT				CTRL_FAILED_BASE+12		//网络连接失败
#define CTRL_FAILED_BIND				CTRL_FAILED_BASE+13		//绑定失败
#define CTRL_FAILED_LISTEN				CTRL_FAILED_BASE+14		//侦听失败
#define CTRL_FAILED_NETSND				CTRL_FAILED_BASE+15		//网络发送出错
#define CTRL_FAILED_NETRCV				CTRL_FAILED_BASE+16		//网络接收出错
#define CTRL_FAILED_TIMEOUT				CTRL_FAILED_BASE+17		//网络连接超时
#define CTRL_FAILED_CHNERROR			CTRL_FAILED_BASE+18		//超出通道限制
#define CTRL_FAILED_DEVICEBUSY			CTRL_FAILED_BASE+19		//设备正在忙
#define CTRL_FAILED_WRITEFLASH			CTRL_FAILED_BASE+20		//烧写flash出错
#define CTRL_FAILED_VERIFY				CTRL_FAILED_BASE+21		//校验错
#define CTRL_FAILED_CONFLICT			CTRL_FAILED_BASE+22		//系统资源冲突
#define CTRL_FAILED_BUSY				CTRL_FAILED_BASE+23		//系统正在忙
#define CTRL_FAILED_LINKLIMIT			CTRL_FAILED_BASE+24		//已达到连接上限
#define CTRL_FAILED_UNKNOWN				CTRL_FAILED_BASE+9999	//未知错误

#define CTRL_CONNECTION_NULL			0x0
#define CTRL_CONNECTION_TCPCLIENT		0x1
#define CTRL_CONNECTION_TCPSERVER		0x2

#pragma pack( push, 1 )

typedef struct
{
	u8 data[6];
}CPGuid;

typedef struct
{
	u32         ip;
	u16			port;
	CPGuid		guid;
	SOCKHANDLE	sockfd;
	u8			conntype;
	u8          newmsgcome;
	u8          nolnkcount;
}ifly_cp_t,*CPHandle;

typedef struct
{
	u32 length;							//消息长度
	u16 type;							//消息类型
	u16 event;							//消息名
	u16 number;							//流水号
	u16 version;						//版本号
}ifly_cp_header_t;

typedef struct							//07-07-23 
{										//单独的页面提交时，添加登录后的用户名一起提交
	char usrname[12];
}ifly_usrname_header;

typedef struct
{
	u16 startID;						//07-07-28
	u16 max_return;
}ifly_remusr_send_t;

typedef struct							//远程手动录像结构
{
	u8 chan_rec[4];
	u8 allrec;
	u8 allstop;
}ifly_hand_rec_t;

//远程日志查询
typedef struct
{
	u8  query_mode;						//查询方式
	u8  main_type;						//主类型
	u8  slave_type;						//次类型
	u16 max_return;						//最大返回数
	u16 startID;						//返回从第一条记录开始
	u32 start_time;						//开始时间
	u32 end_time;						//结束时间	
}ifly_research_log_t;

typedef struct
{
	u32  startTime;
	char main[64];						//主类型
	char slave[64];						//次类型
}ifly_log_back_t;

//远程登录
typedef struct
{
	char username[12];
	char loginpass[12];
	u32	 ipAddr;
}ifly_loginpara_t;

typedef struct
{
	char username[12];
	char loginpass[12];
}ifly_logininfo_t;

typedef struct
{
	char usrname[12];
	char remote_privilege[16];
}ifly_remusr_limit;
/*****************/
//07-07-11
typedef struct
{
	int link_online;
}ifly_link_online;
//远程用户返回信息结构
typedef struct
{
	char name[12];
	char password[12];
	char local_privilege[16];
	char remote_privilege[16];
	char mac_address[18];
}ifly_userinfo_t;

//远程用户编辑参数结构
typedef struct
{
	char name[12];						//用户名
	char passwd[12];					//密码
	char confirm[12];					//校正密码
	char macaddr[18];					//物理地址
	u32  index;							//用户权限
	u32  rcamer;						//远程云台权限
	u32  rrec;							//远程录像权限
	u32  rplay;							//远程回放权限
	u32  rsetpara;						//远程设置参数
	u32  rlog;							//远程日志权限
	u32  rtool;							//远程工具权限
	u32  rpreview;						//远程预览权限
	u32  ralarm;						//远程报警权限
	u32  rvoip;							//语音对讲权限
	u32  lcamer;						//本地云台权限
	u32  lrec;							//本地录像权限
	u32  lplay;							//本地回放权限
	u32  lsetpara;						//本地设置参数
	u32  llog;							//本地日志权限
	u32  ltool;							//本地工具权限
}ifly_useredit_t;

//远程用户删除参数结构
typedef struct
{
	u32  user_index;					//当前删除用户记录
	char name[12];						//当前欲删除用户名
}ifly_userdel_t;

//远程用户密码修改参数
typedef struct 
{
	char name[12];
	char oldpass[12];
	char newpass[12];
	char confirm[12];
}ifly_editpass_t;

//远程返回硬盘信息结构
typedef	struct 
{
	s64  capability;//Byte
	s64  freesize;//Byte
}ifly_remhdd_t;

/********************/
//07-07-03
typedef struct
{
	u8 hdd_exist[2];
}ifly_hdd_desc_t;

//远程系统信息返回 
typedef struct
{
	char devicename[32];
	char devicemodel[32];
	char deviceser[32];
	char version[64];
}ifly_recsysinfo_t;

//远程系统参数结构 added by kmli
typedef struct
{
	u16	 device_id;
	char device_name[32];
	u8	 flag_overlap;
	u32	 time;
	u8	 lock_time;
	u8	 switch_time;
	u8	 flag_statusdisp;
	u8	 video_format;
	u8	 vga_solution;
}ifly_syspara_send_t;

//远程云台设置
typedef struct
{
	u8	 channel_no;
	u16  address;
	u8   baud_ratesel;
	u8   data_bitsel;
	u8   stop_bitsel;
	u8   crccheck;
	u8   flow_control;
	u8   protocol;
}ifly_yuntai_send_t;

//远程监控
typedef struct
{
	u32 dwIp;		//本地ip
	u16 wPort;		//接收数据的端口
	u8  byChn;		//通道号，基址为0
}ifly_monitor_param_t;

//按文件远程回放
typedef struct
{
	u32  dwIp;			//接收媒体数据的ip
	u16  wVideoPort;	//接收视频数据的端口
	u16  wAudioPort;	//接收音频数据的端口
	char filename[64];	//回放的文件
	u32	 offset;		//文件偏移
}ifly_remote_playback_t;

typedef struct
{
	u32  id;
}ifly_play_handle_t;

typedef struct
{
	u32  curpos;
	u32  totaltime;
}ifly_play_progress_t;

typedef struct
{
	u32  dwIp;			//接收文件数据的ip
	u16  wPort;			//接收文件数据的端口
	char filename[64];	//下载的文件
	u32	 offset;		//文件偏移
	u32  size;			//文件大小
}ifly_remote_download_t;

typedef struct
{
	u32  id;
}ifly_download_handle_t;

typedef struct
{
	char filename[64];	//文件名
	u32  size;			//文件长度
	u32  verify;		//校验和
	u16  version;		//文件版本号
	u16  reserved;
}ifly_remote_upload_t;
/*********************/
//07-08-02
/*typedef struct
{
	char filename[64];
	u32  size;
	u16  reserved;
}ifly_remote_layin_t;*/		//远程导入
typedef struct
{
	u32 dwIp;
	u16 wPort;
}ifly_remote_layout_head;
typedef struct
{
	char filename[64];
	u32  size;
	u16  reserved;
}ifly_remote_layout_t;		//远程导入导出
/*********************/
typedef struct
{
	u32 dwIp;
	u16 wPort;
}ifly_voip_t;

//远程回放查询的输入结构
typedef struct
{
	u8   channel_no;
	u8   type;
	u32  start_time;
	u32  end_time;
	u32  card_no;
	u8   mask;
	u16  startID;			//返回的第一条记录,从1开始
	u16  max_return;		//每次返回的最大记录数
}ifly_recsearch_param_t;

//远程回放返回的信息结构
typedef struct
{
	u8   channel_no;
	u8   type;
	u32  start_time;
	u32  end_time;
	u8   image_format;//3:cif;4:4cif
	u8   stream_flag;//0:视频流;1:音频流
	u32	 size;
	u32  offset;
	char filename[64];
}ifly_recfileinfo_t;

typedef struct
{
	u16   sum;		//总记录数
	u16   startID;	//开始的记录，基址为1。当无返回数据时，startID的值为0
	u16   endID;	//结束的记录，基址为1。当endID和startID相等时，表示之返回一条记录
}ifly_recfile_desc_t;

typedef struct
{
	char mac_address[18];
	u32  ip_address;
	u16  server_port;
	u32	 net_mask;
	u32	 net_gateway;
	u32	 dns;
	u32	 multicast_address;
	u32	 admin_host;
	u16	 host_port;
	u16	 http_port;
	u8	 flag_pppoe;
	char user_name[64];
	char passwd[64];
	char pwdcheck[64];
}ifly_network_t;

//远程图像设置输入结构
typedef struct 
{
	u8   channel_no;								//通道号
	char channelname[32];							//通道名
	//与位置相关的
	u8   flag_name;									//名称位置显示
	//时间相关的
	u8   flag_time;									//时间位置显示
	u8   flag_mask;									//遮盖
	u8   overlay;									//遮挡报警
	u8   lost;										//视频丢失
	u8   motion;									//移动侦测
	//处理方式
	char record_channel[16];						//触发的录像通道
	u8   flag_buzz;									//声音报警
	u8   flag_send;									//上传中心
	char alarm_out[16];								//触发报警输出
}ifly_imagset_t;


//OSD位置设置 07-07-27
typedef struct 
{
	u8		channel_no;								//通道名
	u8		flag_name;								//名称位置是否显示
	u16	 	x;										//名称位置左上角x坐标
	u16  	y;										//名称位置左上角y坐标
}ifly_channelset_t;

typedef struct 
{
	u8		channel_no;								//通道名
	u8		flag_time;								//时间位置是否显示
	u16	 	x;										//时间位置左上角x坐标
	u16  	y;										//时间位置左上角y坐标
}ifly_timeset_t;

//遮盖区域 07-08-01
typedef struct  
{
	u8		channel_no;								//通道号
	u8		flag_mask;								//是否显示
	u8		mask_index;								//遮盖区域索引		
	u32		x;										//遮盖区域左上x坐标
	u32		y;										//遮盖区域左上y坐标
	u32   	width;									//遮盖区域宽度
	u32   	height;									//遮盖区域高度
}ifly_maskset_t;
//图像设置画质调节07-08-01
typedef	struct  
{
	u8		channel_no;								//通道号
	u8		flag;									//调节标志 0-3
	u8		val;									//调节值
}ifly_picset_t;

typedef struct										//遮挡，视频丢失，移动侦测布防参数结构
{
	u8  channel_no;									//通道号
	u8  week;										//日期
	u8  flag_alltime;								//是否全天布防						
	u32 starttime[4];								//时间段1~4的起始时间
	u32 endtime[4];									//时间段1~4的终止时间
}ifly_valid_t;

typedef struct										//远程移动侦测报警处理参数结构
{
	u8 channel_no;									//通道号
	u8 recchan[4];									//触发的录像通道
	u8 flag_buzz;									//是否声音报警
	u8 flag_send;									//是否上传中心
	u8 alarmout;									//是否触发报警输出
	u8 alarm_out[4];								//具体某路的报警输出
}ifly_motion_t; 

typedef struct										//远程异常处理页面参数结构
{
	u8 exceptiontype;								//异常类型
	u8 flag_display;								//是否屏上显示
	u8 flag_buzz;									//是否声音报警
	u8 flag_send;									//是否上传中心
	u8 alarmout;									//是否触发报警输出
	u8 alarm_out[4];								//具体某路的报警输出
}ifly_exceptioninfo_t;

typedef struct										//远程录像配置页面参数结构
{
	u8   channelno;									//通道号
	char channelname[32];							//通道名
	u8   code_type;									//视频类型
	u8   video_resolution;							//分辨率
	u8   bit_type;									//位率类型
	u32  bit_max;									//位率上限
	u8   quality;									//图像质量
	u8   frame_rate;								//视频帧率
	u16  pre_record;								//预录时间
	u16  post_record;								//录像延时
	u8   flag_record;								//是否启动录像
}ifly_recordinfo_t;

typedef struct										//远程录像设置页面参数结构
{
	u8  channelno;									//通道号
	u8  week;										//日期
	u8  flag_alltime;								//是否全天布防
	u8  alltype;									//全天布防时，录像类型
	u32 start_time[4];								//时间段1~4的起始时间
	u32 end_time[4];								//时间段1~4的终止时间
	u8  type[4];									//时间段1~4的录像类型
}ifly_recordtime_t;

typedef struct										//远程报警设置页面
{
	u8  inid;										//报警输入量 
	u8  typein;										//报警输入类型
	u8  flag_deal;									//是否触发报警输入处理
	u8  copyin;
	u8  in_copy;									//是否选择报警量的复制
	u8  outid;										//选择报警输出
	u8  typeout;									//报警输出类型 
	u8  out_copy;									//报警输出复制
	u8  copyout;
	u16 delay;										//报警输出延时	
}ifly_alarmset_t;

typedef struct										//远程ptz联动
{
	u8 inid;										//报警输入量
	u8 channo;										//通道号
	u8 flag_preset;									//预置点
	u8 preset;
	u8 flag_cruise;									//巡航点
	u8 cruise;
	u8 flag_track;									//轨迹
}ifly_alarmin_ptz;

typedef struct										//报警布防
{
	u8  id;											//选择报警量
	u8  week;										//日期	
	u8  flag_alltime;								//全天布防
	u32 starttime[4];								//时间段1~4的起始时间
	u32 endtime[4];									//时间段1~4的终止时间
}ifly_alarm_settime;

#define MD_ROW			12
#define MD_COL			16
#define MD_MIN_SENSE	0							//最不灵敏
#define MD_MAX_SENSE	5							//最灵敏

typedef struct
{
	u8   channel_no;
	u8   flag;  //是否开启移动侦测
	u8   sense;	//灵敏度 MD_MIN_SENSE-MD_MAX_SENSE
	u8   block[MD_ROW*MD_COL];//非0选中 0不选中
}ifly_md_param_t;

typedef struct
{
	u8   channel_no;
	u8	 byCmdId;	//摄象头控制命令类型
	u8	 abyParam[MAX_PARAM_NUM];//参数
	u8   byCtrlWay;	//摄象头正反向控制方式 CAM_CTRLWAY_GENERAL:正向;CAM_CTRLWAY_REVERSE:反向
}ifly_camera_ctrl_t;

typedef struct  
{
	u16		width;
	u16   height;
}ifly_pic_resolution_t;		//主机发送给客户端的图像分辨率

typedef struct
{
	u8   channel_no;
}ifly_need_resolution_t;	//本通道需要主机发送图像分辨率

#pragma pack( pop )

typedef u16 (*pMESSAGE_CB)(CPHandle cph,u16 event,u8 *pbyMsgBuf,int msgLen,u8 *pbyAckBuf,int *pAckLen,void* pContext);
void SetMsgCallBack(pMESSAGE_CB pCB,void *pContext);

u16  CPLibInit(u16 wPort);
u16  CPLibCleanup();

//连接服务器
CPHandle CPConnect(u32 dwServerIp, u16 wServerPort, u32 dwTimeOut, u16 *pwErrorCode);
//清处连接
u16  CleanCPHandle(CPHandle cph);
//发送事件通知
u16  CPPost(CPHandle cph, u16 event, const void *content, int length);
//发送命令
u16  CPSend(CPHandle cph, u16 event, const void *content, int length, void* ackbuf, int ackbuflen, int *realacklen, u32 dwTimeOut);

//得到TCP连接的本地ip地址与端口 07-07-27 ??
BOOL GetCPHandleLocalAddr(CPHandle cph, struct sockaddr_in *pAddr);

//发送NAT探测包	07-07-27 ??
BOOL SendSTUNPacket(u32 dwLocalIpAddr, u16 wLocalPort, u32 dwRemoteIpAddr, u16 wRemotePort, u8 *pbyBuf, u32 dwBufLen);

u16  GetTransactionNum();

u16  StartNetMonitor(ifly_monitor_param_t mp,u32 dwServerIp,u16 wServerPort,u32 dwTimeOut);
u16  StopNetMonitor(ifly_monitor_param_t mp,u32 dwServerIp,u16 wServerPort,u32 dwTimeOut);

u16  StartAudioNetMonitor(ifly_monitor_param_t mp,u32 dwServerIp,u16 wServerPort,u32 dwTimeOut);
u16  StopAudioNetMonitor(ifly_monitor_param_t mp,u32 dwServerIp,u16 wServerPort,u32 dwTimeOut);

u16  StartRemotePlay(ifly_remote_playback_t rp,u32 dwServerIp,u16 wServerPort,u32 dwTimeOut);
u16  StopRemotePlay(ifly_remote_playback_t rp,u32 dwServerIp,u16 wServerPort,u32 dwTimeOut);

/***************************************************************************************************************/
//发送交互命令给主机，并返回控制处理的最终结果
//交互过程为：
//	1.client端将要发送的参数按特定的格式打包，然后调用本函数
//	2.server端接收到请求后，进行相应的处理
//	3.server根据处理结果返回对应的信息给client，并关闭socket 连接！

//输入参数：
//	dwHostIp：主机的IP地址
//	dwTimeOut：交互的超时时间
//	pBuf：发送的数据头及真正的数据信息，例如网络监控中，pBuf = ifly_cp_header_t + ifly_monitor_param_t
//	dwBufLen：pBuf的长度
//返回值：
//	0：调用成功
//	其它：调用失败
/***************************************************************************************************************/
u16  SendToHost(u32 dwHostIp, u32 dwTimeOut, void *pBuf, u32 dwBufLen);

/***************************************************************************************************************/
//发送交互命令给主机，并需要从主机获得额外的信息
//交互过程为：
//	1.client端将要发送的参数按特定的格式打包，然后调用本函数
//	2.server端接收到请求后，进行相应的处理
//	3.server根据处理结果返回对应的信息给client，并关闭socket 连接！

//输入参数：
//	dwHostIp：主机的IP地址
//	dwTimeOut：交互的超时时间
//	pinBuf：发送的数据头及真正的数据信息，例如网络监控中，pinBuf = ifly_cp_header_t + ifly_monitor_param_t
//	dwinBufLen：pinBuf的长度
//	dwoutBufLen：poutBuf最大长度，防止内存溢出
//输出参数：
//	poutBuf：从主机接收的数据头及真正的数据信息，例如远程回放查询中，poutBuf = ifly_cp_header_t + 查询的结果
//	dwoutBufLen：实际接收到的buf的长度
//返回值：
//	0：调用成功
//	其它：调用失败
//注意：
//	主机应根据输入的dwoutBufLen来控制返回给client的最大数据，否则可能导致数据溢出
/***************************************************************************************************************/
u16  SendToHost2(u32 dwHostIp, u32 dwTimeOut, void *pinBuf, u32 dwinBufLen, void *poutBuf, u32 *dwoutBufLen);

#ifdef __cplusplus
}
#endif

#endif
