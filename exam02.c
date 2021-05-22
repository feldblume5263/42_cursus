char		*gnl_join(char *line, char buff)
{
	char	*ret;
	int		size;

	size = 0;
	while (line[size])
		size++;
	if (!(ret = (char *)malloc(sizeof(char) * (size + 2))))
		return (0);
	size = -1;
	while (line[++size])
		ret[size] = line[size];
	ret[size] = buff;
	ret[size + 1] = '\0';
	free(line);
	line = NULL;
	return (ret);
}

int			get_next_line(char **line)
{
	char	*buff;
	int		flag;

	buff = (char *)malloc(sizeof(char) * 2);
	if (!buff || !line || !(*line = (char *)malloc(sizeof(char) * 1)))
		return (-1);
	*line[0] = '\0';
	while ((flag = read(0, buff, 1)) > 0)
	{
		if (buff[0] == '\n')
			break;
		*line = gnl_join(*line, buff[0]);
	}
	free(buff);
	buff = NULL;
	return (flag);
}

int			main(void)
{
	char	*line;
	int		flag;

	while ((flag = get_next_line(&line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	line = NULL;
	return (0);
}
