#include <stdio.h>
#include <time.h>

int main() {
  FILE *file_handler = fopen("output.txt", "w");
  time_t current_time = time(NULL);
  for (int i = 0; i < 10; i++, current_time += 60 * 60 * 24) {
    struct tm *current_day = localtime(&current_time);
    fprintf(file_handler, "%02d.%02d.%04d\n", current_day->tm_mday,
            current_day->tm_mon + 1, current_day->tm_year + 1900);
  }

  return 0;
}