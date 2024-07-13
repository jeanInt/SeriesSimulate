#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char *key;
    char *value;
} JsonPair;

void parseObject(char *input) {
    char *start = input;
    while (*start != '\0') {

        char *keyStart = start;
        char *keyEnd = strchr(keyStart, ':');
        if (keyEnd == NULL) {
            printf("Invalid JSON format: missing key\n");
            return;
        }
        int keyLength = keyEnd - keyStart;

        char key[keyLength + 1];
        strncpy(key, keyStart, keyLength);
        key[keyLength] = '\0';

        char *valueStart = keyEnd + 1;
        char *valueEnd = strchr(valueStart, ',');
        if (valueEnd == NULL) {
            printf("Invalid JSON format: missing value\n");
            return;
        }
        int valueLength = valueEnd - valueStart;
        char value[valueLength + 1];
        strncpy(value, valueStart, valueLength);
        value[valueLength] = '\0';

        printf("Key: %s, Value: %s\n", key, value);

        start = valueEnd + 1;
    }
}

// Function to find the next comma or end of string.
char* findCommaOrEnd(char* str) {
    while (*str != '\0') {
        if (*str == ',') break;
        str++;
    }
    if (*str == '\0') return NULL;
   /* if (*str != '\0') {
        printf("str:'%c'\n",*str);
    }*/
    return str;
}

// Function to parse and print TLV data.
void parseTlv(char* data) {
    char* tagStart = data;
    char* tagEnd = findCommaOrEnd(tagStart);
    char* lengthStart = tagEnd + 1;
    char* lengthEnd = findCommaOrEnd(lengthStart);
    char* valueStart = lengthEnd ;
    
    // Check if there is a comma after valueStart to ensure proper TLV format.
    if (*valueStart != ',') {
        printf("Invalid TLV format.\n");
        return;
    }
    valueStart++; // Move past the comma.
    
    // Use strtol for more robust integer parsing, and check for errors.
    char* endptr;
    long length = strtol(lengthStart, &endptr, 10);
    if (endptr == lengthStart || *endptr != ',') {
        printf("Invalid length format.\n");
        return;
    }
    
    // Validate length to prevent buffer overflows.
    char* dataEnd = data + strlen(data);
    if (valueStart + length > dataEnd) {
        printf("TLV length exceeds data bounds.\n");
        return;
    }
    
    // Calculate valueEnd with the checked length.
    char* valueEnd = valueStart + length;
    
    printf("Tag: '%s', Length: %ld, Value: '%.*s'\n", tagStart, length, (int)length, valueStart);

    parseObject(valueStart);
}

int main() {
    //const char * tlvData = "reportChar,37,{\"opener\":{\"current\":40,\"target\":65}}";
     printf("input tlv infomation\n"); 
    char tlvData[50];
    scanf("%s",tlvData);
    parseTlv(tlvData);

     system("pause"); // Removed for compatibility with non-Windows systems.
    return 0;
}