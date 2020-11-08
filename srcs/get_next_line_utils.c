/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:45:06 by jihhan            #+#    #+#             */
/*   Updated: 2020/11/08 14:46:00 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

ssize_t     ft_strchr(char *src, char key)
{
    char    *src_pt;
    ssize_t rb;

    rb = 0;
    src_pt = src;

    while (*(src_pt + rb) != key)
    {
        if (*(src_pt + rb) == 0 || rb == (BUFFER_SIZE - 1))
            return (-1);
        rb++;
    }

    return (rb);
}

ssize_t     ft_str_store(char **dest, char *buf, ssize_t rb)
{
    if (rb == -1)
        rb = BUFFER_SIZE;
    if (!rb)
    {
        *dest = NULL;
        return (rb);
    }
    
    *dest = strndup(buf, rb);
    return (rb);
}

size_t     ft_readlines(char **line, size_t pt)
{
    size_t     rl;
    
    rl = 0;

    while (rl < pt)
    {
        if (*(line + rl) == NULL)
        {
            rl++;
            write(STDOUT_FILENO, "NULL\n", 5);
            continue;
        }
        write(STDOUT_FILENO, *(line + rl), strlen(*(line + rl)));
        free(*(line + rl));
        rl++;
    }
    free(line);
    return (rl);
}
