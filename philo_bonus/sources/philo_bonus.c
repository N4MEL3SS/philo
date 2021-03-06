/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:31:24 by celadia           #+#    #+#             */
/*   Updated: 2022/05/04 07:31:24 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_all	info;

	if (argc != 5 && argc != 6)
		ft_error(ERROR_ARG_COUNT);
	if (parser(argc, argv, &data))
		ft_error(ERROR_ARG_INVAL);
	sema_init(&info, &data);
	process_init(&info);
	ft_free_all(&info, EXIT_SUCCESS);
	return (0);
}
