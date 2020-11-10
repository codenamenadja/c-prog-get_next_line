/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 12:40:39 by jihhan            #+#    #+#             */
/*   Updated: 2020/11/10 13:40:09 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"


int get_next_line(int fd, char **line)
{
    static char         buf[BUFFER_SIZE] = {0};
    static char         *buf_pt = NULL;
    static size_t       pt = 0; 
    ssize_t             rb;
    ssize_t             pos;

    if (pt == 63)
    {
        ft_readlines(line, pt);
        return (-1);
    }

    if (buf_pt && *buf_pt)
    {
        pos = ft_strchr(buf_pt, '\n');
        ft_str_store(line+pt, buf_pt, pos);
        pt++;
        if (pos == BUFFER_SIZE)
        {
            buf_pt = NULL;
            return (1);
        }
        if (pos != -1)
        {
            buf_pt += (pos + 1); // must point right after \n.
            return (1);
        }
    }

    rb = 0;
    while (rb < BUFFER_SIZE)
        buf[rb++] = 0;
    buf_pt = NULL;
    while ((rb = read(fd, buf, BUFFER_SIZE)) >= 0) //eof + first running
    {
        if (!rb)
        {
            ft_readlines(line, pt);
            return (0);
        }
        buf_pt = buf;
        pos = ft_strchr(buf_pt, '\n');
        ft_str_store(line+pt, buf_pt, pos);
        pt++;
        if (pos)
        {
            buf_pt += pos;
            return (1);
        }
        buf_pt = NULL;
    }
    return (-1);
}

#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    int fd;
    char **line;
    int ret;

    if (argc == 2)
        fd = open(*(argv + 1), O_RDONLY);
    else 
        fd = STDIN_FILENO;

    if (fd < 0)
    {
        write(STDOUT_FILENO, "non opend\n", 10);
        return EXIT_FAILURE;
    }
    line = malloc(sizeof(char *) * 64);
    *(line + 63) = NULL;

    while ((ret = get_next_line(fd, line)) == 1);
    if (ret == -1)
        write(STDOUT_FILENO, "Error\n", 6);
    if (!ret)    
        write(STDOUT_FILENO, "Passed\n", 7);
    if (fd)
        close(fd);
    exit(0);
}
