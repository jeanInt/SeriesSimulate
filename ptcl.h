#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    STATE_COMMAND_SEARCH,   // 命令搜索状态
    STATE_BATCH_OPEN,       // 批量打开状态
    STATE_CMD_KEY_SEARCH,   // 命令键搜索状态
    STATE_CMD_KEY_READ,     // 命令键读取状态
    STATE_CMD_VAL_OPEN,     // 命令值打开状态
    STATE_CMD_VAL_READ,     // 命令值读取状态
    STATE_CMD_VAL_CLOSE,    // 命令值关闭状态
    STATE_CMD_END           // 命令结束状态
    // ...其他状态（如果需要的话）
} ParseState;

typedef enum {
    LIGHT_MODE_NOTMOD = 0,  // 未定义
    LIGHT_MODE_WARM,        // 暖光
    LIGHT_MODE_SUNLIGHT,    // 日光
    LIGHT_MODE_COOL,        // 冷光
    LIGHT_MODE_NIGHTLIGHT,  // 夜光灯
    LIGHT_MODE_COMFORTABLE, // 舒适
    LIGHT_MODE_TV,          // 电视
    LIGHT_MODE_FOCUS,       // 焦点
    LIGHT_MODE_GALLERY      // 画廊
} litemod;

typedef enum {
    SWITCH_OFF = 0,     // 关闭
    SWITCH_ON           // 打开
} swit;


typedef enum {
    COLOUR_MODE_NOTMOD = 0, // 未定义
    COLOUR_MODE_CANDLE,     // 烛光
    COLOUR_MODE_ROMAN,      // 罗马
    COLOUR_MODE_UNION,      // 聚会
    COLOUR_MODE_FESTIVAL,   // 节日
    COLOUR_MODE_WARMTH,     // 温暖
    COLOUR_MODE_CINIMA,     // 影院
    COLOUR_MODE_COMFORTABLE,// 舒适
    COLOUR_MODE_PARTY,      // 聚会
    COLOUR_MODE_CLUB,       // 俱乐部
    COLOUR_MODE_BREATHE,    // 呼吸
    COLOUR_MODE_OCEAN,      // 海洋
    COLOUR_MODE_FOREST      // 森林
} colormod;

typedef enum {
    TIME_UPDAT = 0, // 检查更新
    TIME_NEW,       // 新增
    TIME_DELETE     // 删除
} tmract;

typedef enum {
    UPDATE_CHECKE_VER = 0,  // 检查更新
    START_UPDATE            // 开始更新
} updatact;

typedef enum {
    STREN_INTENSITY_0 = 20, // 强度0
    STREN_INTENSITY_1 = 40, // 强度1
    STREN_INTENSITY_2 = 60, // 强度2
    STREN_INTENSITY_3 = 80, // 强度3
    STREN_INTENSITY_4 = 100 // 强度4
} inten;

typedef struct {
    tmract action;   //动作
    unsigned char enable;   //使能定时器
    unsigned char start;    //开始时间
    unsigned char end;      //结束时间
    unsigned char week;     //定时器一周重复时间
} timer;    // 定义结构体timer,不完整

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char white;    //白光无用，因为有cct变量
} colour;   // 定义结构体colour,完整

typedef struct {
    updatact action;    //检查更新
    unsigned char version[8];   //版本号    
} update;

typedef struct {
    char cmd[30]; // 命令名称，最长名称幻彩变速,以下是命令可能对应的值
    litemod lightMode;
    swit switch_on;
    unsigned char brightness;
    unsigned int  cct;
    colormod ColorfulLightingMode;
    unsigned char Phantomcolorvariablespeed;    //幻彩变速
    unsigned char GradientDuration; //渐变时长
    inten   netInfo_intensity;    //信号强度
    timer   tmr;
    colour  color;
    update  updat;
} Params;