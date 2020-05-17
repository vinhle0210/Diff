//
//  util.c
//  diff
//
//  Created by William McCarthy on 5/9/19.
//  Copyright © 2019 William McCarthy. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include "util.h"

#define BUFLEN 256


char* yesorno(int condition) { return condition == 0 ? "no" : "YES"; }

FILE* openfile(const char* filename, const char* openflags) {
  FILE* f;
  if ((f = fopen(filename, openflags)) == NULL) {  printf("can't open '%s'\n", filename);  exit(1); }
  return f;
}

void printline(void) {
  for (int i = 0; i < 10; ++i) { printf("=========="); }
  printf("\n");
}


void printleft(const char* left) {
  char buf[BUFLEN];
  
  strcpy(buf, left);
  int j = 0, len = (int)strlen(buf) - 1;
  for (j = 0; j <= 48 - len ; ++j) { buf[len + j] = ' '; }
  buf[len + j++] = '<';
  buf[len + j++] = '\0';
  printf("%s\n", buf);
}

void printright(const char* right) {
  if (right == NULL) { return; }
  printf("%50s %s", ">", right);
}

void printboth(const char* left_right) {
  char buf[BUFLEN];
  size_t len = strlen(left_right);
  if (len > 0) { strncpy(buf, left_right, len); }
  buf[len - 1] = '\0';
  printf("%-50s %s", buf, left_right);
}

void print_left_column(const char* left) {
  char buf[BUFLEN];
  size_t len = strlen(left);
  if (len > 0) { strncpy(buf, left, len); }
  buf[len - 1] = '\0';
  printf("%-47s (\n", buf);
}
void print_different(const char* left, const char* right){
  if (right == NULL || left == NULL) { return; }
  char buf[BUFLEN];
  size_t len = strlen(left);
  if (len > 0) { strncpy(buf, left, len); }
  buf[len - 1] = '\0';
  printf("%-47s |  %s",buf, right);
}
void print_add(const char* string){
  printf("+%s", string);
}
void print_subtract(const char* string){
  printf("-%s", string);
}
void print_line(const char* string){
  printf("%s", string);
}
void print_line_num(int start, int stop, const char* string){
  if(strcmp(string, "left" == 0)){
    printf("*** %d,%d ****", start, stop);
  }
  else if(strcmp(string, "right") == 0){
    printf("--- %d, %d ----", start, stop);
  }
  else{
    fprintf(stderr,"only print left or right");
    return;
  }
}