#ifndef __FT_GET_NEXT_LINE__
#define __FT_GET_NEXT_LINE__
#include <unistd.h>
int     get_next_line(int fd, char **line);
ssize_t ft_strchr(char *src, char key);
ssize_t ft_str_store(char **dest, char *buf, ssize_t rb);
size_t ft_readlines(char **line, size_t pt);
#endif
