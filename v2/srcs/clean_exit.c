#include "../include/ls.h"

void clean_exit(t_data *data) {
	if (data->args) {
		for (int i = 0; data->args[i]; i++) {
			free(data->args[i]);
		}
		free(data->args);
	}

	if (data->flags) {
		free(data->flags);
	}

	if (data) {
		free(data);
	}

	exit(0);
}