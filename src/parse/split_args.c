/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:58:20 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 22:54:10 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

static char	*join(char **dst, char **src)
{
	char	**out;
	int		i;
	int		j;
	int		nd;
	int		ns;

	nd = count(dst);
	ns = count(src);
	out = (char **)malloc(sizeof(char *) * (nd + ns + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < nd)
	{
		out[i] = dst[i];
		i++;
	}
	j = 0;
	while (j < ns)
		out[i++] = src[j++];
	out[i] = NULL;
	free(dst);
	free(src);
	return (out);
}

char	**split_args(int argc, char **argv)
{
	char	**tokens;
	char	**parts;
	int		i;

	tokens = (char *)malloc(sizeof(char *));
	if (!tokens)
		return (NULL);
	tokens[0] = NULL;
	i = 1;
	while (i < argc)
	{
		parts = ft_split(argv[i], ' ');
		if (!parts)
			return (free_split(tokens), NULL);
		tokens = join(tokens, parts);
		if (!tokens)
			return (NULL);
		i++;
	}
	return (tokens);
}
