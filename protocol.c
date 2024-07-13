#include <stdio.h>
#include <stdlib.h>

/**
 * strncpy函数的实现，用于将源字符串src的前n个字符复制到目标字符串dest中。
 * 与标准库函数strncpy行为相同，但增加了对末尾null字符的处理，确保目标字符串始终以null字符结尾。
 * 
 * @param dest 目标字符串，即复制结果存放的位置。
 * @param src 源字符串，从中复制字符。
 * @param n 指定复制的字符数。
 * @return 返回目标字符串dest的指针。
 */
char* my_strncpy(char *dest, const char *src, size_t n) {
    char *d = dest;
    while(n-- > 0 && (*d++ = *src++));
    while(n-- > 0)
        char* my_strncpy(char *dest, const char *src, size_t n) {
    char *d = dest;
    const char *s = src;
    size_t i;

    // Copy characters until either the end of source or the limit is reached.
    for (i = 0; i < n && (*d = *s) != '\0'; ++d, ++s);

    // If we didn't reach the end of the source string, terminate the destination.
    if (*s == '\0') {
        *d = '\0'; // Ensure null termination.
    }

    // Fill the rest with zeros if necessary.
    for (; i < n; ++i) {
        *d++ = '\0';
    }

    return dest;
}
    return dest;
}

/**
 * strchr函数的实现，用于在字符串str中查找字符character首次出现的位置。
 * 如果找到，返回指向该字符的指针；如果未找到，返回NULL。
 * 
 * @param str 待搜索的字符串。
 * @param character 要查找的字符。
 * @return 如果找到字符character，则返回指向它的指针；否则返回NULL。
 */
char* my_strchr(const char *str, int character) {
    while (*str != '\0') {
        if (*str == (char)character) {
            return (char*)str;
        }
        str++;
    }
    return NULL;
}

/**
 * 解析JSON对象
 * @param input 输入的JSON字符串
 * 遍历输入字符串，寻找键值对，如果缺少键或值，则输出错误信息并返回
 */
void parseObject(const char *input) {
    const char *start = input;
    while (*start != '\0') {

        const char *keyStart = start;
        const char *keyEnd = my_strchr(keyStart, ':');
        if (keyEnd == NULL) {
            printf("Invalid JSON format: missing key\n");
            return;
        }
        int keyLength = keyEnd - keyStart;

        char key[keyLength + 1];
        my_strncpy(key, keyStart, keyLength);
        key[keyLength] = '\0';

        const char *valueStart = keyEnd + 1;
        const char *valueEnd = my_strchr(valueStart, ',');
        if (valueEnd == NULL) {
            printf("Invalid JSON format: missing value\n");
            return;
        }
        int valueLength = valueEnd - valueStart;
        char value[valueLength + 1];
        my_strncpy(value, valueStart, valueLength);
        value[valueLength] = '\0';

        printf("Key: %s, Value: %s\n", key, value);

        start = valueEnd + 1;
    }
}

/**
 * 解析JSON数组
 * @param input 输入的JSON数组字符串
 * 遍历输入字符串，寻找数组元素，如果缺少元素，则输出错误信息并返回
 */
void parseArray(const char *input) {
    const char *start = input;
    while (*start != '\0') {

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

        printf("Value: %s\n", value);

        start = valueEnd + 1;
    }
}

int main() {
    char input[] = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    parseObject(input);

    char arrayInput[] = "[\"apple\",\"banana\",\"cherry\"]";
    parseArray(arrayInput);

    system("pause");
    return 0;
}