#include<stdbool.h>

int compareVersion(char *version1, char *version2){
    int index1 = 0;
    int index2 = 0;

    while (true){
        while (version1[index1] == '0') index1++;
        while (version2[index2] == '0') index2++;

        int edition1 = 0;
        int edition2 = 0;

        while (version1[index1] != '\0' && version1[index1] != '.') edition1 = 10 * edition1 + (version1[index1++] - '0');
        while (version2[index2] != '\0' && version2[index2] != '.') edition2 = 10 * edition2 + (version2[index2++] - '0');

        if (edition1 > edition2) return 1;
        else if (edition1 < edition2) return -1;
        else if (version1[index1] == '\0' && version2[index2] == '\0') return 0;

        if (version1[index1]) index1++;
        if (version2[index2]) index2++;
    }
}