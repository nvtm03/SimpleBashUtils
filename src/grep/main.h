#ifndef SIMPLEBASHUTILITS_MAIN_H
#define SIMPLEBASHUTILITS_MAIN_H

#define _GNU_SOURCE
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct options {
  int regex_flag;
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  char pattern[4096];
  size_t size_pattern;
  int several_files;
  char filename_flag_f[1024];
  int flag;
};

void parser(int argc, char *argv[], struct options *flags);
void grep(char *filename, struct options flags);
void print_string(struct options flags, char *filename, char *temp_line,
                  int count_str);

#endif  // SIMPLEBASHUTILITS_MAIN_H
