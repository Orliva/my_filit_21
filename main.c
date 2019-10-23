//#include <filit.h>
#include "libft/libft.h"
#include <stdio.h>

void	print_error(void)
{
	char c[] = "Errors";
	int	i;

	i = 0;
	while (i < 7)
		write(1, &c[i++], 1);
	exit(-1);
}

void	print_text(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		write(1, &line[i], 1);
		i++;
	}
		write(1, "\n", 1);
}
///////////////Выделяет память и возвращает указатель на нее
char	**dinam_mall(int fd, char **line)
{
	int		i;
	int		count_line;////////////текущее количество линий

	i = 0;
	count_line = 0;
/////////////////Малоки нужны из за того что изначально(в мэйне) line = NULL
//т.е. если не замалочить, то gnl всегда будет выдавать -1
	line = (char **)malloc((sizeof (char *)) * 1);
	line[0] = (char *)malloc((sizeof (char)) * 5);
	if (get_next_line(fd, line) == -1)////////проверяем может ли читать файл
	{
		ft_strdel(line);
		exit(-1);///////если не может, то выйти из программы (и потом возможно что то надо написать)
	}
	while(get_next_line(fd, line))/////читаем пока читается
	{
		count_line = 0;//////каждый раз начинаем количество линий с нуля
		ft_strdel(line);//////////Удаляем то, что было в line до этого момента
		line = (char **)malloc((sizeof (char *)) * (i + 1));//////малочим i+1 строк (+ 1 на нулевую строку)
		while (count_line++ < i)/////////теперь малочим длинну самих строк
			line[count_line] = (char *)malloc((sizeof (char)) * 5);///////4 на '.' или '#' и 1 на '\0'
		i++;
	}
	/////////общая логика такая
	//читаем файл по 1 строке за раз, если там еще есть строки то убираем старые и выделяем память на все старые + 1
	//так пока не дойдем до конца файла
	return (line);
}

int	main(int argc, char **argv)
{
	char	**line;
	int		fd;
	int		i;

	i = 0;
	line = NULL;
	if (argc == 2)//////Если передали 1 аргумент, то
	{
		if ((fd = open(argv[1], O_RDONLY, S_IREAD)) == -1)////////прочитали дескриптор, и проверили файл на открывание
			print_error();//////ошибка если файл не открывается
		line = dinam_mall(fd, line);/////////////Выделяем память для line(см функцию)
		close(fd);///////Нужен из за того, что в dinam_mall происходит чтение файла по дескриптору,
		////////////////Там он читается до конца, и приходится получить дескриптор еще раз 
		/////////////// т.е закрыть и открыть еще раз тот же файл
		fd = open(argv[1], O_RDONLY, S_IREAD);
		while (get_next_line(fd, &line[i]))////////////построчно прочитали get_line'ом
//		{
//			print_text(line[i]); ///////проверка того, что находится в line
				i++;
//		}
	}
	else
		print_error();////////////Если не 1 аргумент передали, то выведи что-то там...
	ft_strdel(line); //////////////Можно убирать(нужна была , чтобы не убить компьютер вовремя написания)
	return (0);
}
