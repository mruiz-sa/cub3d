/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:26:52 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/11 11:13:34 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

int	skip(char *str, int start)
{
	int	i;

	i = start;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}
