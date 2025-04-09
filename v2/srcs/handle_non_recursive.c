#include "../include/ls.h"

void handle_non_recursive(t_data *data) {
    DIR *dir;
    struct dirent *entry;
    t_file **files = malloc(sizeof(t_file *) * 1024);
    int file_count = 0;

    for (int i = 0; i < data->nb_args; i++) {
        dir = opendir(data->args[i]);
        if (!dir) {
            perror(data->args[i]);
            continue;
        }

        while ((entry = readdir(dir)) != NULL) {
            if (!has_flag(data, 'a') && entry->d_name[0] == '.') {
                continue;
            }

            t_file *file = malloc(sizeof(t_file));
            file->name = ft_strdup(entry->d_name);
            file->path = ft_strdup(data->args[i]);
            file->is_dir = (entry->d_type == DT_DIR);

            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s/%s", data->args[i], entry->d_name);
            stat(full_path, &file->info);

            files[file_count++] = file;
        }

        closedir(dir);
    }

    if (has_flag(data, 't')) {
        sort_by_time(files, file_count);
    }
    if (has_flag(data, 'r')) {
        reverse_files(files, file_count);
    }

    if (has_flag(data, 'l')) {
        print_detailed(files, file_count);
    } else {
        print_simple(files, file_count);
    }

    for (int i = 0; i < file_count; i++) {
        free(files[i]->name);
        free(files[i]->path);
        free(files[i]);
    }
    free(files);
}