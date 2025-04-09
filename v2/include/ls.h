#pragma once

#include <unistd.h>
#include <stdbool.h> 
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h> // Printf remove after
#include <sys/stat.h>

typedef struct s_file {
    char *name;
    char *path;
    struct stat info;
    bool is_dir;
} t_file;

typedef struct s_data {
    char *flags;
    int nb_flags;
    int nb_args;
    int nb_argv_flags;
    char **args;
    t_file **files;
} t_data;


// debug.c
void print_data(t_data *data); // debug only !

// parse_args.c
void parse_args(t_data *data, int argc, char **argv);


// utils.c
int	ft_strcmp(const char *s1, const char *s2);
char *ft_strdup(char *str);
int ft_strlen(const char *str);
bool has_flag(t_data *data, char flag);

// clean_exit.c
void clean_exit(t_data *data);