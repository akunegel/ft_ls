#include "../include/ls.h"

int main(int argc, char **argv) {
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data) {
		return 0;
	}

	parse_args(data, argc, argv);

	/* if (has_flag(data, 'R')) {
        handle_recursive(data);
    } else {
        handle_non_recursive(data);
    } */
   
	print_data(data); // for debug ! must be removed

	clean_exit(data);
	return 0;
}