#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

char* readable(int size) {
  char* readable =(char *)malloc(sizeof(size));
  int i = 0;
  const char* units[] = {"B", "KB", "MB", "GB"};
  while(size > 1024) {
    size /= 1024;
    i++;
  }

  sprintf(readable, "%d%s", size, units[i]);
  return readable;
}

int main() {
  DIR * current_dir;
  char dir[] = ".";
  current_dir = opendir(dir);
  struct dirent *entry;
  printf("----------------------------------------------\n");
  printf("Current directory: %s\n", dir);

  struct stat s_buff;
  stat(dir, &s_buff);
  printf("Total directory size: %s\n", readable(s_buff.st_size));
  printf("----------------------------------------------\n");

  printf("Content: (* = directory)\n");
  //readdir returns null when everything is read
  while ((entry = readdir(current_dir))) {
    if (entry->d_type == 4) { //directory = 4
      printf("*%s\n", entry->d_name);
    } else if (entry->d_type == 8) { //directory = 8
      printf("%s\n", entry->d_name);
    }
  }
  closedir(current_dir);
}
