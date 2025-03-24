#pragma once

#include <unistd.h>
#include <stdbool.h> 
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h> // Printf remove after

typedef struct s_file {
    char *name;
    char *owner_grp;
    char *owner_usr;
    int links;
    char date[13];
    char info[12];
} t_file;

typedef struct s_repo {
    char *name;
    t_file *files;
    char *owner_grp;
    char *owner_usr;
    int links;
    char date[13];
    char info[12];
} t_repo;

typedef struct s_data {
    char *flags; // v
    int nb_flags; // v
    int nb_args; // v
    char **args; // v
    t_repo *repos; // f
} t_data;


// parse_args.c
void parse_args(t_data *data, int argc, char **argv);

// ft_ls.c
bool ft_basic_ls(const char *file);

// print_data.c
void print_data(t_data *data); // For debug must be removed

// utils.c
int ft_strlen(const char *str);
char *ft_strdup(char *str);
void bubble_sort(char **arr, int n);

// ft_clean_exit.c
void ft_clean_exit(t_data *data);
