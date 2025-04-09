#include "../include/ls.h"

bool ft_basic_ls(const char *file, int argc, bool reverse) {
    DIR *d;

    d = opendir(file);
    if (d == NULL)
        return false;

    struct dirent *e;
    char *files[1024];
    int count = 0;

    while ((e = readdir(d)) != NULL) {
        files[count] = ft_strdup(e->d_name);
        count++;
    }
    closedir(d);

    bubble_sort(files, count);

    bool wrote = false;
    bool had_files = false;
    if (argc > 2) {
        write(1, file, ft_strlen(file));
        write(1, ":\n", 2);
    }
    if (reverse == false) {
        for (int i = 0; i < count; i++) {
            if (files[i][0] != '.') {
                write(1, files[i], ft_strlen(files[i]));
                write(1, "    ", 4);
                wrote = true;
            }
            had_files = true;
            free(files[i]);
        }
    } else {
        for (int i = count - 1; i >= 0; i--) {
            if (files[i][0] != '.') {
                write(1, files[i], ft_strlen(files[i]));
                write(1, "    ", 4);
                wrote = true;
            }
            had_files = true;
            free(files[i]);
        }
    }

    if (wrote == true)
        write(1, "\n", 1);

    return had_files;
}