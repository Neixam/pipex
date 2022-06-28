#include "data.h"
#include <unistd.h>

void	destroy_data(t_data *instance)
{
	if (!instance)
		return ;
	if (instance->fd_in > 2)
		close(instance->fd_in);
	if (instance->fd_out > 2)
		close(instance->fd_out);
	free_cmds(&instance->cmds);
	if (instance->paths)
		ft_free_tab(instance->paths);
}

t_data	init_data(char **env)
{
	t_data	ret;

	ret.fd_in = 0;
	ret.fd_out = 0;
	ret.env = env;
	ret.cmds = init_cmds();
	ret.paths = 0;
	return (ret);
}
