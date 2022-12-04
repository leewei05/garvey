#include <stdio.h>

int is_whitespace(char c){
  if (c == '\n' || c == '\t' || c == ' '){
    return 1;
  }
  return 0;
}

int main(int argc, char **argv){
  if (argc > 0 && !argv[1]){
    printf("Please enter filename.");
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  if(!fp){
    printf("File opening failed");
    return 1;
  }

  int c;
  while ((c = fgetc(fp)) != EOF){
    putchar(c);
  }

  fclose(fp);
  return 0;
}
