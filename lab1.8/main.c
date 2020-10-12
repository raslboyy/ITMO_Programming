#include <stdio.h>
#include <string.h>

#define INPUT_BUF_SIZE 256

char buf[INPUT_BUF_SIZE];

struct PairString {
    char first[256];
    char second[256];
    int firstSize;
    int secondSize;
};

void updateSizes(struct PairString *strings) {
    strings->firstSize = strlen(strings->first);
    strings->secondSize = strlen(strings->second);
}

void printPairString(struct PairString strings) {
    printf("%s\n%s\n", strings.first, strings.second);
}

void readStrings(struct PairString *strings) {
    fgets(buf, INPUT_BUF_SIZE, stdin);
    sscanf(buf, "%s", strings->first);
    fgets(buf, INPUT_BUF_SIZE, stdin);
    sscanf(buf, "%s", strings->second);
    updateSizes(strings);
}

void compare(struct PairString strings) {
    int resultCompareString = strcmp(strings.first, strings.second);
    if (resultCompareString < 0)
        printf("%s < %s\n", strings.first, strings.second);
    else if (resultCompareString == 0)
        printf("%s = %s\n", strings.first, strings.second);
    else
        printf("%s > %s\n", strings.first, strings.second);
}

int copyElements(struct PairString *strings) {
    int n;
    fgets(buf, INPUT_BUF_SIZE, stdin);
    sscanf(buf, "%d", &n);
    if (n > strings->secondSize)
        return -1;
    for (int i = strings->firstSize; i - strings->firstSize < n; i++)
        strings->first[i] = strings->second[i - strings->firstSize];
    strings->first[strings->firstSize + n] = '\0';
    strings->firstSize += n;
    updateSizes(strings);
    return 0;
}

int findLast(struct PairString strings, char letter) {
    for (int i = strings.firstSize - 1; i >= 0; i--)
        if (strings.first[i] == letter)
            return i;
    return -1;
}

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int sizeSegmentNotContaining(struct PairString strings) {
    int ascii[256] = {};
    for (int i = 0; i < strings.secondSize; i++)
        ascii[strings.second[i]]++;
    int maxSegment = 0;
    for (int l = 0, r = 0; r < strings.firstSize; l = ++r) {
        while (l < strings.firstSize && ascii[strings.first[l]] != 0)
            l++;
        r = l;
        while (r < strings.firstSize && ascii[strings.first[r]] == 0)
            r++;
        maxSegment = max(maxSegment, r - l);
    }
    return maxSegment;
}

void printLexemes(struct PairString strings){
    int ascii[256] = {};
    for (int i = 0; i < strings.secondSize; i++)
        ascii[strings.second[i]]++;
    for (int l = 0, r = 0; r < strings.firstSize; l = ++r) {
        while (l < strings.firstSize && ascii[strings.first[l]] != 0)
            l++;
        r = l;
        while (r < strings.firstSize && ascii[strings.first[r]] == 0) {
            printf("%c", strings.first[r]);
            r++;
        }
        printf("\n");
    }
}

int main() {

    struct PairString strings;
    readStrings(&strings);

     compare(strings);

    if (copyElements(&strings) == -1)
        printf("Error!\n");
    else
        printPairString(strings);

    fgets(buf, INPUT_BUF_SIZE, stdin);
    char letterForFindLast;
    sscanf(buf, "%c", &letterForFindLast);
    int resultFindLast = findLast(strings, letterForFindLast);
    if (resultFindLast == -1)
        printf("\"%c\" not found\n", letterForFindLast);
    else
        printf("%d\n", resultFindLast);

    printf("%d\n", sizeSegmentNotContaining(strings));

    printLexemes(strings);

    return 0;
}
