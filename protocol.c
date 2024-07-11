#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h> // 添加这一行来声明system函数
// 解析 JSON 对象
void parseObject(const char *input) {
    const char *start = input;
    while (*start != '\0') {
        // 查找键
        const char *keyStart = start;
        const char *keyEnd = strchr(keyStart, ':');
        if (keyEnd == NULL) {
            printf("Invalid JSON format: missing key\n");
            return;
        }
        int keyLength = keyEnd - keyStart;
        char key[keyLength + 1];
        strncpy(key, keyStart, keyLength);
        key[keyLength] = '\0';

        // 查找值
        const char *valueStart = keyEnd + 1;
        const char *valueEnd = strchr(valueStart, ',');
        if (valueEnd == NULL) {
            printf("Invalid JSON format: missing value\n");
            return;
        }
        int valueLength = valueEnd - valueStart;
        char value[valueLength + 1];
        strncpy(value, valueStart, valueLength);
        value[valueLength] = '\0';

        // 处理键值对
        printf("Key: %s, Value: %s\n", key, value);

        // 移动到下一个键值对
        start = valueEnd + 1;
    }
}

// 解析 JSON 数组
void parseArray(const char *input) {
    const char *start = input;
    while (*start != '\0') {
        // 查找值
        const char *valueStart = start;
        const char *valueEnd = strchr(valueStart, ',');
        if (valueEnd == NULL) {
            printf("Invalid JSON format: missing value\n");
            return;
        }
        int valueLength = valueEnd - valueStart;
        char value[valueLength + 1];
        strncpy(value, valueStart, valueLength);
        value[valueLength] = '\0';

        // 处理值
        printf("Value: %s\n", value);

        // 移动到下一个值
        start = valueEnd + 1;
    }
}

int main() {
    char input[] = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    parseObject(input);

    char arrayInput[] = "[\"apple\",\"banana\",\"cherry\"]";
    parseArray(arrayInput);

    system("pause");    // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}
