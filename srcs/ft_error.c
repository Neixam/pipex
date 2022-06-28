#include "ft_error.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_error(char *err, t_data *instance, int test)
{
	if (!test)
		return ;
	perror(err);
	destroy_data(instance);
	exit(1);
}
