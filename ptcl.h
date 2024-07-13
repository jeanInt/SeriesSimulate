#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    STATE_COMMAND_SEARCH,   // ��������״̬
    STATE_BATCH_OPEN,       // ������״̬
    STATE_CMD_KEY_SEARCH,   // ���������״̬
    STATE_CMD_KEY_READ,     // �������ȡ״̬
    STATE_CMD_VAL_OPEN,     // ����ֵ��״̬
    STATE_CMD_VAL_READ,     // ����ֵ��ȡ״̬
    STATE_CMD_VAL_CLOSE,    // ����ֵ�ر�״̬
    STATE_CMD_END           // �������״̬
    // ...����״̬�������Ҫ�Ļ���
} ParseState;

typedef enum {
    LIGHT_MODE_NOTMOD = 0,  // δ����
    LIGHT_MODE_WARM,        // ů��
    LIGHT_MODE_SUNLIGHT,    // �չ�
    LIGHT_MODE_COOL,        // ���
    LIGHT_MODE_NIGHTLIGHT,  // ҹ���
    LIGHT_MODE_COMFORTABLE, // ����
    LIGHT_MODE_TV,          // ����
    LIGHT_MODE_FOCUS,       // ����
    LIGHT_MODE_GALLERY      // ����
} litemod;

typedef enum {
    SWITCH_OFF = 0,     // �ر�
    SWITCH_ON           // ��
} swit;


typedef enum {
    COLOUR_MODE_NOTMOD = 0, // δ����
    COLOUR_MODE_CANDLE,     // ���
    COLOUR_MODE_ROMAN,      // ����
    COLOUR_MODE_UNION,      // �ۻ�
    COLOUR_MODE_FESTIVAL,   // ����
    COLOUR_MODE_WARMTH,     // ��ů
    COLOUR_MODE_CINIMA,     // ӰԺ
    COLOUR_MODE_COMFORTABLE,// ����
    COLOUR_MODE_PARTY,      // �ۻ�
    COLOUR_MODE_CLUB,       // ���ֲ�
    COLOUR_MODE_BREATHE,    // ����
    COLOUR_MODE_OCEAN,      // ����
    COLOUR_MODE_FOREST      // ɭ��
} colormod;

typedef enum {
    TIME_UPDAT = 0, // ������
    TIME_NEW,       // ����
    TIME_DELETE     // ɾ��
} tmract;

typedef enum {
    UPDATE_CHECKE_VER = 0,  // ������
    START_UPDATE            // ��ʼ����
} updatact;

typedef enum {
    STREN_INTENSITY_0 = 20, // ǿ��0
    STREN_INTENSITY_1 = 40, // ǿ��1
    STREN_INTENSITY_2 = 60, // ǿ��2
    STREN_INTENSITY_3 = 80, // ǿ��3
    STREN_INTENSITY_4 = 100 // ǿ��4
} inten;

typedef struct {
    tmract action;   //����
    unsigned char enable;   //ʹ�ܶ�ʱ��
    unsigned char start;    //��ʼʱ��
    unsigned char end;      //����ʱ��
    unsigned char week;     //��ʱ��һ���ظ�ʱ��
} timer;    // ����ṹ��timer,������

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char white;    //�׹����ã���Ϊ��cct����
} colour;   // ����ṹ��colour,����

typedef struct {
    updatact action;    //������
    unsigned char version[8];   //�汾��    
} update;

typedef struct {
    char cmd[30]; // �������ƣ�����ƻòʱ���,������������ܶ�Ӧ��ֵ
    litemod lightMode;
    swit switch_on;
    unsigned char brightness;
    unsigned int  cct;
    colormod ColorfulLightingMode;
    unsigned char Phantomcolorvariablespeed;    //�òʱ���
    unsigned char GradientDuration; //����ʱ��
    inten   netInfo_intensity;    //�ź�ǿ��
    timer   tmr;
    colour  color;
    update  updat;
} Params;