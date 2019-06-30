/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:05:05 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/23 17:31:41 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_list		*ft_new_char_list(void const *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content || !content_size)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = (char*)malloc(sizeof(char) * content_size + 1)))
		{
			free(new);
			return (NULL);
		}
		else
		{
			ft_strcpy(new->content, content);
			new->content_size = content_size;
		}
	}
	new->next = NULL;
	return (new);
}

void		push_back_list(const char *line, t_list **des)
{
	t_list *tmp;

	if (!line || !des)
		return ;
	if (!*des)
	{
		*des = ft_new_char_list(line, ft_strlen(line));
		return ;
	}
	tmp = *des;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
		{
			tmp->next = ft_new_char_list(line, ft_strlen(line));
			printf("%s\n", (char*)tmp->next->content);
			return ;
		}
		tmp = tmp->next;
	}
}

void		push_back_light(t_light *src, t_light **des)
{
	t_light *tmp;

	if (!src || !des)
		return ;
	if (!*des)
	{
		*des = src;
		return ;
	}
	tmp = *des;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
		{
			tmp->next = src;
			return ;
		}
		tmp = tmp->next;
	}
}

void		push_back_obj(t_obj *src, t_obj **des)
{
	t_obj	*tmp;

	if (!src || !des)
		return ;
	if (!*des)
	{
		*des = src;
		return ;
	}
	tmp = *des;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
		{
			tmp->next = src;
			return ;
		}
		tmp = tmp->next;
	}
}

void		ft_map(double_t *var, double_t min, double_t max)
{
	*var = (*var > max) ? max : *var;
	*var = (*var < min) ? min : *var;
}
