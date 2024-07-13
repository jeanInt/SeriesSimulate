#include "ptcl.h"

const char *LightBelt_sid_cmd_key[] = {
    "lightMode",
    "switch",
    "timer",
    "colour",
    "brightness",
    "cct",
    "ColorfulLightingMode",
    "Phantomcolorvariablespeed",
    "GradientDuration",
    "netInfo",
    "update"
};

const char *timer_cid_cmd_key[] = {
    "action",
    "num",
    "timer",
    "enable",
    "sid",
    "start",
    "para",
    "end",
    "id",
    "week",
    "paraValue"
};

const char *colour_cid_cmd_key[] = {
    "green",
    "blue",
    "white",
    "red"
};

const char *netInfo_cid_cmd_key[] = {
    "intensity",
    "IP",
    "BSSID",
    "SSID",
    "RSSI"
};

const char *update_cid_cmd_key[] = {
    "action",
    "version",
    "introduction",
    "progress",
    "bootTime"
};