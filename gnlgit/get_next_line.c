#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*dest;
	int			i;

	i = 1;
	dest = NULL;
	if (BUFFER_SIZE == 0 || fd < 0)
		return (0);
	if (ft_check(buff) == 1)
	{
		ft_buf_cut(buff);
		dest = ft_join(dest, buff);
	}
	while (i > 0 && ft_check(buff) == 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
		{
			free(dest);
			return (NULL);
		}
		buff[i] = '\0';
		dest = ft_join(dest, buff);
	}
	return (dest);
}

int	main(void)
{
	int	i;

	i = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	// if(test)
	// {
	// 	printf("%s", test);
	// 	free(test);
	// }
	return (0);
}

