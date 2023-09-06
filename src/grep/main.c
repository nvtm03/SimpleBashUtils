#include "main.h"

int main(int argc, char *argv[]) {
  if (argc > 2) {
    struct options flags = {0};
    parser(argc, argv, &flags);
    if (!flags.e && !flags.f) {
      strcat(flags.pattern, argv[optind]);
      ++optind;
    }
    int number_files = argc - optind;
    if (number_files > 1) flags.several_files = 1;
    if (flags.f) {
      for (; optind < argc; ++optind) {
        FILE *fp_f;
        fp_f = fopen(flags.filename_flag_f, "r");
        if (fp_f) {
          size_t temp_size = 0;
          char *temp_pattern = NULL;
          while (getline(&temp_pattern, &temp_size, fp_f) > 0) {
            flags.pattern[0] = '\0';
            char *idx_n = strchr(temp_pattern, '\n');
            *idx_n = '\0';
            strcat(flags.pattern, temp_pattern);
            grep(argv[optind], flags);
          }
          free(temp_pattern);
          fclose(fp_f);

        } else {
          fprintf(stderr, "grep: %s: No such file or directory\n", optarg);
        }
      }
    } else {
      for (; optind < argc; ++optind) {
        grep(argv[optind], flags);
      }
    }
  } else {
    fprintf(stderr, "no template");
  }

  return 0;
}

void parser(int argc, char *argv[], struct options *flags) {
  int current_flag = getopt_long(argc, argv, "e:ivclnhsf:o", 0, NULL);

  while (current_flag > 0) {
    flags->flag = 1;
    if (current_flag == 'e') {
      flags->e++;
      if (flags->e > 1) strcat(flags->pattern, "|");
      strcat(flags->pattern, optarg);
    }
    if (current_flag == 'i') flags->i = 1;
    if (current_flag == 'v') flags->v = 1;
    if (current_flag == 'c') flags->c = 1;
    if (current_flag == 'l') flags->l = 1;
    if (current_flag == 'n') flags->n = 1;
    if (current_flag == 'h') flags->h = 1;
    if (current_flag == 's') flags->s = 1;
    if (current_flag == 'f') {
      flags->f = 1;
      strcat(flags->filename_flag_f, optarg);
    }
    if (current_flag == 'o') flags->o = 1;
    current_flag = getopt_long(argc, argv, "e:ivclnhsf:o", 0, NULL);
  }
}

void grep(char *filename, struct options flags) {
  FILE *fp = fopen(filename, "r");
  regex_t regex;
  char *temp_line = NULL;
  int success;
  size_t len_getline;
  int compare = 0;
  if (flags.v) compare = REG_NOMATCH;
  int regex_flag = REG_EXTENDED;
  int count_str = 0;
  int count_flag_c = 0;
  if (fp) {
    if (flags.i) regex_flag = REG_ICASE;
    regcomp(&regex, flags.pattern, regex_flag);
    while (getline(&temp_line, &len_getline, fp) > 0) {
      success = regexec(&regex, temp_line, 0, NULL, 0);
      ++count_str;
      if (strchr(temp_line, '\n') == NULL) strcat(temp_line, "\n");
      if (success == compare) {
        ++count_flag_c;
        if (flags.o) {
          char *result = strstr(temp_line, flags.pattern);
          int count = 0;
          int flag_sev_files_before = flags.several_files;
          while (result) {
            if (count > 0) flags.several_files = 0;
            *result = '\t';
            result = strstr(temp_line, flags.pattern);
            print_string(flags, filename, flags.pattern, count_str);
            ++count;
          }
          flags.several_files = flag_sev_files_before;
        } else if (flags.l) {
          ++flags.l;
        } else {
          print_string(flags, filename, temp_line, count_str);
        }
      }
    }
    if (flags.c) {
      if (flags.several_files) printf("%s:", filename);
      printf("%d\n", count_flag_c);
    }
    if (flags.l > 1) printf("%s\n", filename);
    fclose(fp);
    regfree(&regex);
  } else {
    if (!flags.s) {
      fprintf(stderr, "grep: %s: No such file or directory\n", filename);
    }
  }
  free(temp_line);
}

void print_string(struct options flags, char *filename, char *temp_line,
                  int count_str) {
  if (!flags.c) {
    if (!flags.h) {
      if (flags.several_files) printf("%s:", filename);
    }
    if (flags.n) printf("%d:", count_str);
    printf("%s", temp_line);
    if (flags.o) printf("\n");
  }
}
