#include "../include/ls.h"

void get_flags(t_data *data, int argc, char **argv) {
    int i = 1;
    int c = 0;
    
    while (argv[i] && ft_strlen(argv[i]) >= 2 && argv[i][0] == '-') {
        c++;
        i++;
    }

    i = 1;
    int fc = 0;
    char tmp[1024];
    data->nb_argv_flags = c;

    while (argv[i] && ft_strlen(argv[i]) >= 2 && argv[i][0] == '-') {
        int j = 1;
        while (argv[i][j]) {
            if (argv[i][j] == 'a' || argv[i][j] == 'r' || argv[i][j] == 'R' || argv[i][j] == 't' || argv[i][j] == 'l') {
                int k = 0;
                bool diff = true;

                while (tmp[k]) {
                    if (tmp[k] == argv[i][j])
                        diff = false;
                    k++;
                }

                if (diff == true) {
                    fc++;
                    tmp[ft_strlen(tmp)] = argv[i][j];
                    tmp[ft_strlen(tmp)] = '\0';
                }
            } else {
                write(1, "ls: invalid option '", 20);
                write(1, argv[i], ft_strlen(argv[i]));
                write(1, "'\n", 2);
                write(1, "usage: ls [-altrR] [file ...]", 29);

                ft_clean_exit(data);
            }
            j++;
        }
        i++;
    }

    data->flags = ft_strdup(tmp);
    data->nb_flags = fc;
}

void get_args(t_data *data, int argc, char **argv, bool hasFlags) {
    if (hasFlags == true) {
        int i = 1;
        int c = 0;

        while (argv[i] && ft_strlen(argv[i]) >= 2 && argv[i][0] == '-') {
            c++;
            i++;
        }

        data->nb_args = argc - 1 - c;
        data->args = malloc(sizeof(char *) * data->nb_args);
        
        int j = c + 1;
        i = 0;
        while (argv[j]) {
            data->args[i] = ft_strdup(argv[j]);
            i++;
            j++;
        }
    } else {
        data->nb_args = argc - 1;
        data->args = malloc(sizeof(char *) * data->nb_args);

        int i = 1;
        while (argv[i]) {
            data->args[i - 1] = ft_strdup(argv[i]);
            i++;
        }
    }
}

void parse_args(t_data *data, int argc, char **argv) {
    if (argc == 1) {
        data->nb_args = 0;
        data->nb_flags = 0;
        ft_basic_ls(".", 2, false);
    } else {
        if (ft_strlen(argv[1]) > 1 && argv[1][0] == '-') {
            get_flags(data, argc, argv);
            get_args(data, argc, argv, true);
        } else {
            data->nb_flags = 0;
            get_args(data, argc, argv, false);
        }
    }
}