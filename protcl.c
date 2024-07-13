#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *key;
    int value;
} SwitchInfo;

typedef struct {
    char *type;
    int length;
    SwitchInfo switch_info;
} TlvInfo;

// º¯ÊýÉùÃ÷
int parse_tlv(const char *data, TlvInfo *tlv);
int parse_json_switch(const char *json, SwitchInfo *info);

int parse_tlv(const char *data, TlvInfo *tlv) {
    char *token;
    char *saveptr;

    // Split the TLV into its components
    token = strtok_r((char *)data, ",", &saveptr);
    if (!token) return 0;
    tlv->type = strdup(token);

    token = strtok_r(NULL, ",", &saveptr);
    if (!token) return 0;
    tlv->length = atoi(token);

    // The rest of the string is the value
    token = strtok_r(NULL, "", &saveptr);
    if (!token) return 0;

    // Parse the JSON value
    if (!parse_json_switch(token, &tlv->switch_info)) {
        return 0;
    }

    return 1;
}int parse_json_switch(const char *json, SwitchInfo *info) {
    char *p = (char *)json;

    // Skip over opening brace
    p = strchr(p, '{');
    if (!p) return 0;
    p++;

    // Look for "switch"
    while (*p && *p != '}') {
        if (strncmp(p, "\"switch\"", 8) == 0) {
            p += 8; // Skip past "switch"
            if (*p++ != ':') return 0; // Expecting colon after "switch"

            // Parse value
            if (*p == '{') {
                p++; // Skip opening brace
                while (*p && *p != '}') {
                    if (strncmp(p, "\"on\"", 4) == 0) {
                        p += 4; // Skip past "on"
                        if (*p++ != ':') return 0; // Expecting colon after "on"

                        // Parse integer value
                        if (*p >= '0' && *p <= '9') {
                            info->value = atoi(p);
                            p = strchr(p, '}'); // Find closing brace
                            if (p) {
                                p++; // Skip closing brace
                                info->key = strdup("on");
                                return 1;
                            }
                        }
                    }
                    p = strchr(p, ','); // Find next comma
                    if (p) p++; // Skip comma
                }
            }
        }
        p = strchr(p, ','); // Find next comma
        if (p) p++; // Skip comma
    }

    return 0;
}

int main() {
    const char *data = "reportChar,19,{\"switch\":{\"on\":1}}";
    TlvInfo tlv;
    memset(&tlv, 0, sizeof(TlvInfo));

    if (parse_tlv(data, &tlv)) {
        printf("Type: %s, Length: %d, Switch on: %d\n", tlv.type, tlv.length, tlv.switch_info.value);
    } else {
        printf("Failed to parse TLV data.\n");
    }

    return 0;
}