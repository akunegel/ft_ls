#include "../include/ls.h"

void get_method(t_data *data, int argc, char **argv) {
	if (data->nb_flags == 0 && argc > 1) {
		for (int i = 1; i < argc; i++) {
			if (ft_basic_ls(argv[i]) == false) {
				write(1, "ls: ", 4);
				write(1, argv[i], ft_strlen(argv[i]));
				write(1, ": No such file or directory\n", 28);
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

	parse_args(data, argc, argv); // get args and flags
	get_method(data, argc, argv);

	//print_data(data); // for debug ! must be removed

	return 0;
}