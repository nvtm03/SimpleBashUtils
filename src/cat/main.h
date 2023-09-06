#ifndef SIMPLEBASHUTILITS_MAIN_H
#define SIMPLEBASHUTILITS_MAIN_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

struct options {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
};

void parser(int argc, char *argv[], struct options *flags);
void print_file(FILE *fp, struct options flags);
void print_symbol(int current_symbol, struct options flags);
int open_file(int argc, char *argv[], struct options flags);

#endif  // SIMPLEBASHUTILITS_MAIN_H
