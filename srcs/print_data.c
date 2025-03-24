#include "../include/ls.h"

void print_data(t_data *data) {
    printf("flags: %s\n", data->flags);
    printf("nb_flags: %d\n", data->nb_flags);
    printf("nb_args: %d\n", data->nb_args);
    
    int i = 0;
    printf("args:\n");
    while (data->args[i]) {
        printf("%s\n", data->args[i]);
        i++;
    }
}