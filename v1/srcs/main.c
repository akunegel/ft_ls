#include "../include/ls.h"

void get_method(t_data *data, int argc, char **argv) {
	if (data->nb_flags == 0 && argc > 1) {
		for (int i = 1; i < argc; i++) {
			if (ft_basic_ls(argv[i], argc, false) == false) {
				write(1, "ls: ", 4);
				write(1, argv[i], ft_strlen(argv[i]));
				write(1, ": No such file or directory\n", 28);
			}
			if (i != argc - 1) {
				write(1, "\n", 1);
			}
		}
	} else if (data->nb_flags == 1 && has_flag(data, 'r')) {
		for (int i = data->nb_argv_flags + 1; i < argc; i++) {
			if (argc > 2) {
				if (ft_basic_ls(argv[i], argc, true) == false) {
					write(1, "ls: ", 4);
					write(1, argv[i], ft_strlen(argv[i]));
					write(1, ": No such file or directory\n", 28);
				}
				if (i != argc - 1) {
					write(1, "\n", 1);
				}
			} else {
				if (ft_basic_ls(".", argc, true) == false) {
					write(1, "ls: ", 4);
					write(1, argv[i], ft_strlen(argv[i]));
					write(1, ": No such file or directory\n", 28);
				}
			}
		}
	}
}

int main(int argc, char **argv) {
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data) {
		return 0;
	}

	parse_args(data, argc, argv);
	get_method(data, argc, argv);

	//print_data(data); // for debug ! must be removed
	ft_clean_exit(data);

	return 0;
}