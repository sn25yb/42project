#include "object.h"

t_objs	get_num_objs(char c)
{
	const char	id[10] = " wbckLAFHR";
	int			index;

	index = 10;
	while (--index > 0)
	{
		if (id[index] == c)
			return (index);
	}
	return (index);
}
