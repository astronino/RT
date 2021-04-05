/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:46:34 by yoelguer          #+#    #+#             */
/*   Updated: 2021/02/09 18:46:38 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void		f_light(char **str, int j, t_data_light *light)
{
	int		k;

	k = 0;
	if (j == 0)
		init_vect(&light->position, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 1)
		init_vect(&light->direction, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 2)
		init_vect(&light->color, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 3)
		light->intensity = ft_atof(str[k]);
	if (j == 4)
		light->angle = ft_atof(str[k]);
	if (j == 5)
		light->type = ft_atof(str[k]);
}

int			s_light(char **table, int i, t_data_light *light)
{
	int		j;
	int		k;
	char	**str;

	j = 0;
	while (table[i] && j < 6)
	{
		k = 0;
		str = ft_strsplit(table[i], ' ');
		if (f_str(str, j, 2) == -1)
			return (-1);
		f_light(str, j, light);
		j++;
		i++;
	}
	return (0);
}

int			ft_light(char **table, t_all *data)
{
	int		i;
	char	**aray;
	t_data_light *light;

	i = 0;
	aray = table;
	light = data->light;
	while (table[i])
	{
		if (ft_strcmp("light", table[i]) == 0)
		{
			if (s_light(aray, i + 1, light) < 0)
				return (-1);
			ft_alloc_light(&light->next);
			light = light->next;
		}
		i++;
	}
	return (0);
}
