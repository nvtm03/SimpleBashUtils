#include "main.h"

int main(int argc, char *argv[]) {
  struct options flags = {0};
  parser(argc, argv, &flags);
  int exitCode = open_file(argc, argv, flags);
  return exitCode;
}

void parser(int argc, char *argv[], struct options *flags) {
  static struct option longopts[] = {
      {"number-nonblank", 0, NULL, 'b'},
      {"number", 0, NULL, 'n'},
      {"squeeze-blank", 0, NULL, 's'},
      {NULL, 0, NULL, 0},

  };
  int current_flag = getopt_long(argc, argv, "+bevEnstT", longopts, NULL);
  while (current_flag > 0) {
    if (current_flag == 'b') flags->b = 1;
    if (current_flag == 'n') flags->n = 1;
    if (current_flag == 's') flags->s = 1;
    if (current_flag == 'v') flags->v = 1;
    if (current_flag == 'E') flags->e = 1;
    if (current_flag == 'T') flags->t = 1;
    if (current_flag == 'e') {
      flags->e = 1;
      flags->v = 1;
    }
    if (current_flag == 't') {
      flags->t = 1;
      flags->v = 1;
    }
    current_flag = getopt_long(argc, argv, "+bevEnstT", longopts, NULL);
  }
  if (flags->b == 1 && flags->n == 1) flags->n = 0;
}

int open_file(int argc, char *argv[], struct options flags) {
  int exitCode = 0;
  for (char **filename = &argv[1], **end = &argv[argc]; filename != end;
       ++filename) {
    if (**filename == '-') continue;
    FILE *fp = NULL;
    if (fp == NULL && (fp = fopen(*filename, "r")) == NULL) {
      fprintf(stderr, "Cannot open file.\n");
      exitCode = 1;
    } else {
      print_file(fp, flags);
      fclose(fp);
    }
  }
  return exitCode;
}

void print_symbol(int current_symbol, struct options flags) {
  if (flags.v) {
    if (current_symbol == 10) {
      printf("\n");
    } else if (current_symbol == 9) {
      if (flags.t) {
        printf("^I");
      } else {
        printf("%c", current_symbol);
      }
    } else if (current_symbol >= 0 && current_symbol <= 31)
      printf("^%c", current_symbol + 64);
    else if (current_symbol >= 33 && current_symbol <= 126)
      printf("%c", current_symbol);
    else if (current_symbol >= 127 && current_symbol <= 159)
      printf("M-^%c", current_symbol - 64);
    else
      printf("%c", current_symbol);
  } else {
    printf("%c", current_symbol);
  }
}

void print_file(FILE *fp, struct options flags) {
  int count_lines = 0;
  int last_symbol = '\n';
  int current_symbol = 0;
  int flag_s = 0;
  while (fread(&current_symbol, 1, 1, fp) > 0) {
    int flag_print = 0;
    if (last_symbol == '\n') {
      if (flags.s) {
        if (current_symbol == '\n') {
          if (flag_s) {
            continue;
          }
          flag_s = 1;
        } else {
          flag_s = 0;
        }
      }

      if (flags.b) {
        if (current_symbol != '\n') {
          printf("%6d\t", ++count_lines);
        }
      } else if (flags.n) {
        printf("%6d\t", ++count_lines);
      }
    }

    if (flags.e) {
      if (current_symbol == '\n') {
        flag_print = 1;
        printf("$\n");
      }
    }

    if (flag_print == 0) print_symbol(current_symbol, flags);
    last_symbol = current_symbol;
  }
}
