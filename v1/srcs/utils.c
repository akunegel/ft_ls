#include "../include/ls.h"

int ft_strlen(const char *str) {
    int i = 0;
    
    while (str[i]) {
        i++;
    }

    return i;
}

char *ft_strdup(char *str) {
    char *new = malloc(sizeof(str));
    
    for (int i = 0; str[i]; i++) 
        new[i] = str[i];
    
    new[ft_strlen(str)] = '\0';
    
    return new;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void bubble_sort(char **arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ft_strcmp(arr[j], arr[j + 1]) > 0) {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

bool has_flag(t_data *data, char flag) {
    for (int i = 0; data->flags[i]; i++) {
        if (data->flags[i] == flag)
            return true;
    }
    return false;
}