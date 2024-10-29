#ifndef OBJECT_H
# define OBJECT_H

typedef enum e_objs
{
	no_obj,
	wotou,
	boots,
	carrot,
	kangbao,
	LEBAO,
	AIBAO,
	FUBAO,
	HUIBAO,
	RUIBAO,
}	t_objs;

t_objs	get_num_objs(char c);

# endif