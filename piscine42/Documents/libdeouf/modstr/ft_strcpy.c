/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 15:20:09 by acouturi          #+#    #+#             */
/*   Updated: 2016/07/11 17:10:20 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *arc)
{
	int i;

	i = 0;
	while (arc[i] != '\0')
	{
		dest[i] = arc[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
