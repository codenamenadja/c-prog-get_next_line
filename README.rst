GET_NEXT_LINE
=============

allowed functions: read, malloc, free
line is somthing what already result of read.
so, in this function all have to do is to determine, line is EOF or NOT LINE, or LINE.
line is multi lines in char pointer array.
and forwarding in line must be headed at get_next_line_utils.c file. 
calling this function in a loop will eventually loops through line by line.
at the end, will be EOF. 1 call -> 1 line.

this function must be able to handle input -fd with file or STDIN
COMPILE with flag -D BUFFER_SIZE=xx
read and save to BUFFER_SIZED buf, and loops, buf must except for newline.

gcc defining opition

``-D name=definition``
   content of def are tokenized and prcessed as if ther appeard during,  
   translation phases three in #define directive.
   if wish to define function like definition, write its arguments list, with
   surrouding parentheses before the equals sign
   -D'name(args...)=definition' works.
   in main routine call printf("%d", BUFFER_SIZE) works.

functions
---------

1. if buf_pt is NULL? YES NULL
   0. clear buf
   1. read til BUFFERSIZE to buf.
      2. less than BUFFERSIZE?
         - less(EOF) but not 0 or match
            - ft_strchr('\n');
               - if found? set buf_pt to next malloc and return 1;
               - malloc til buf_pt or full, continue.
         - 0(exit program)

2. if buf_pt is NULL? NO NOT NULL
   1. ft_strchr('\n');
      - found
         - malloc and set buf_pt to next return 1.
      - nonfound
         - malloc and set buf_pt = NULL and continue

.. code-block:: c

   #ifndef __FT_GET_NEXT_LINE__
   #define __FT_GET_NEXT_LINE__
   #include <unistd.h>
   int     get_next_line(int fd, char **line);
   ssize_t ft_strchr(char *src, char key);
   ssize_t ft_str_store(char **dest, char *buf, ssize_t rb);
   size_t ft_readlines(char **line, size_t pt);
   #endif

processing inputs
-----------------

1. redirection

2. stdin

When you use the ``<`` symbol on the command line,
The OS reads the file for that and gives the contents to your program via ``stdin``

.. code-block:: c

   int main(){
       char line[256];
       FILE *fp = stdin;
       while(fgets(line, sizeof(line), fp) != NULL)
           printf("%s", line);
       
   }
