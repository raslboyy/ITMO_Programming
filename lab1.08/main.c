#include <stdio.h>
#include <string.h>

#define INPUT_BUF_SIZE 256

char buf[INPUT_BUF_SIZE];

struct Pair_strings {
  char first[256];
  char second[256];
  int firstSize;
  int secondSize;
};

void update_sizes(struct Pair_strings *strings) {
  strings->firstSize = strlen(strings->first);
  strings->secondSize = strlen(strings->second);
}

void print_pair_strings(struct Pair_strings strings) {
  printf("%s\n%s\n", strings.first, strings.second);
}

void read_strings(struct Pair_strings *strings) {
  fgets(buf, INPUT_BUF_SIZE, stdin);
  sscanf(buf, "%s", strings->first);
  fgets(buf, INPUT_BUF_SIZE, stdin);
  sscanf(buf, "%s", strings->second);
  update_sizes(strings);
}

void compare(struct Pair_strings strings) {
  int resultCompareString = strcmp(strings.first, strings.second);
  if (resultCompareString < 0)
    printf("%s < %s\n", strings.first, strings.second);
  else if (resultCompareString == 0)
    printf("%s = %s\n", strings.first, strings.second);
  else
    printf("%s > %s\n", strings.first, strings.second);
}

int copy_elements(struct Pair_strings *strings) {
  int n;
  fgets(buf, INPUT_BUF_SIZE, stdin);
  sscanf(buf, "%d", &n);
  if (n > strings->secondSize) return -1;
  for (int i = strings->firstSize; i - strings->firstSize < n; i++)
    strings->first[i] = strings->second[i - strings->firstSize];
  strings->first[strings->firstSize + n] = '\0';
  strings->firstSize += n;
  update_sizes(strings);
  return 0;
}

int find_last(struct Pair_strings strings, char letter) {
  for (int i = strings.firstSize - 1; i >= 0; i--)
    if (strings.first[i] == letter) return i;
  return -1;
}

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int size_segment_not_containing(struct Pair_strings strings) {
  int ascii[256];
  for (int i = 0; i < strings.secondSize; i++) ascii[strings.second[i]]++;
  int maxSegment = 0;
  for (int l = 0, r = 0; r < strings.firstSize; l = ++r) {
    while (l < strings.firstSize && ascii[strings.first[l]] != 0) l++;
    r = l;
    while (r < strings.firstSize && ascii[strings.first[r]] == 0) r++;
    maxSegment = max(maxSegment, r - l);
  }
  return maxSegment;
}

void print_lexemes(struct Pair_strings strings) {
  int ascii[256];
  for (int i = 0; i < strings.secondSize; i++) ascii[strings.second[i]]++;
  for (int l = 0, r = 0; r < strings.firstSize; l = ++r) {
    while (l < strings.firstSize && ascii[strings.first[l]] != 0) l++;
    r = l;
    while (r < strings.firstSize && ascii[strings.first[r]] == 0) {
      printf("%c", strings.first[r]);
      r++;
    }
    printf("\n");
  }
}

int main() {
  struct Pair_strings strings;
  read_strings(&strings);

  compare(strings);

  if (copy_elements(&strings) == -1)
    printf("Error!\n");
  else
    print_pair_strings(strings);

  fgets(buf, INPUT_BUF_SIZE, stdin);
  char letterForFindLast;
  sscanf(buf, "%c", &letterForFindLast);
  int resultFindLast = find_last(strings, letterForFindLast);
  if (resultFindLast == -1)
    printf("\"%c\" not found\n", letterForFindLast);
  else
    printf("%d\n", resultFindLast);

  printf("%d\n", size_segment_not_containing(strings));

  print_lexemes(strings);

  return 0;
}
