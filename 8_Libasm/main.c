#include "libasm.h"

void		test_ft_strdup(void)
{
	char	*str;
	char	*new;

	str = "hello string duplicate!";
	printf("=======================FT=======================\n");
	new = ft_strdup(str);
	printf("RET: %s$ RADDR: %p STR: %s$ SADDR: %p\n", new, new, str, str);
	free(new);
	new = (char *)0;
	printf("=======================STD======================\n");
	new = strdup(str);
	printf("RET: %s$ RADDR: %p STR: %s$ SADDR: %p\n", new, new, str, str);
	printf("\n");
	free(new);
	new = (char *)0;
	str = "";
	printf("=======================FT=======================\n");
	new = ft_strdup(str);
	printf("RET: %s$ RADDR: %p STR: %s$ SADDR: %p\n", new, new, str, str);
	free(new);
	new = (char *)0;
	printf("=======================STD======================\n");
	new = strdup(str);
	printf("RET: %s$ RADDR: %p STR: %s$ SADDR: %p\n", new, new, str, str);
	printf("\n");
	free(new);
	new = (char *)0;
	/*SEGFAULT
	str = (char *)0;
	printf("=======================FT=======================\n");
	new = ft_strdup(str);
	printf("RET: %s$ RADDR: %p STR: %s$ SADDR: %p\n", new, new, str, str);
	free(new);
	new = (char *)0;
	str = (char *)0;
	printf("=======================STD======================\n");
	new = strdup(str);
	printf("RET: %s$ RADDR: %p STR: %s$ SADDR: %p\n", new, new, str, str);
	printf("\n");
	*/
}

void		test_ft_read(void)
{
	int		fd;
	int		buf_size;
	char	buf[42];

	fd = 0;
	buf_size = 42;
	printf("=======================FT=======================\n");
	bzero(buf, 42);
	printf("RET: %zd BUF: %s$", ft_read(fd, buf, buf_size), buf);
	printf("=======================STD======================\n");
	bzero(buf, 42);
	printf("RET: %zd BUF: %s$", read(fd, buf, buf_size), buf);
	fd = -1;
	buf_size = 42;
	printf("=======================FT=======================\n");
	bzero(buf, 42);
	printf("RET: %zd BUF: %s$", ft_read(fd, buf, buf_size), buf);
	perror("FT  ");
	printf("=======================STD======================\n");
	bzero(buf, 42);
	printf("RET: %zd BUF: %s$", read(fd, buf, buf_size), buf);
	perror("STD ");
	fd = 0;
	buf_size = -1;
	printf("=======================FT=======================\n");
	bzero(buf, 42);
	printf("RET: %zd BUF: %s$", ft_read(fd, buf, buf_size), buf);
	perror("FT  ");
	printf("=======================STD======================\n");
	bzero(buf, 42);
	printf("RET: %zd BUF: %s$", read(fd, buf, buf_size), buf);
	perror("STD ");
}

void		test_ft_write(void)
{
	int		fd;
	size_t	buf_size;
	char	*buf;

	fd = 1;
	buf = "hello write!";
	buf_size = 12;
	printf("=======================FT=======================\n");
	printf(" RET: %zd\n", ft_write(fd, buf, buf_size));
	printf("=======================STD======================\n");
	printf(" RET: %zd\n", write(fd, buf, buf_size));
	printf("\n");
	fd = 3;
	buf = "hello write!";
	buf_size = 12;
	printf("=======================FT=======================\n");
	printf(" RET: %zd\n", ft_write(fd, buf, buf_size));
	perror("FT  ");
	printf("=======================STD======================\n");
	printf(" RET: %zd\n", write(fd, buf, buf_size));
	perror("STD ");
	printf("\n");
	fd = 1;
	buf = (char *)0;
	buf_size = 12;
	printf("=======================FT=======================\n");
	printf(" RET: %zd\n", ft_write(fd, buf, buf_size));
	perror("FT  ");
	printf("=======================STD======================\n");
	printf(" RET: %zd\n", write(fd, buf, buf_size));
	perror("STD ");
	printf("\n");
	fd = 1;
	buf = "hello write!";
	buf_size = -1;
	printf("=======================FT=======================\n");
	printf(" RET: %zd\n", ft_write(fd, buf, buf_size));
	perror("FT  ");
	printf("=======================STD======================\n");
	printf(" RET: %zd\n", write(fd, buf, buf_size));
	perror("STD ");
	printf("\n");
}

void		test_ft_strcmp(void)
{
	char	*s1;
	char	*s2;

	s1 = "12345";
	s2 = "12345";
	printf("=======================FT=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", ft_strcmp(s1, s2), s1, s2);
	printf("=======================STD=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", strcmp(s1, s2), s1, s2);
	printf("\n");
	s1 = "12";
	s2 = "123";
	printf("=======================FT=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", ft_strcmp(s1, s2), s1, s2);
	printf("=======================STD=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", strcmp(s1, s2), s1, s2);
	printf("\n");
	s1 = "123";
	s2 = "12";
	printf("=======================FT=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", ft_strcmp(s1, s2), s1, s2);
	printf("=======================STD=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", strcmp(s1, s2), s1, s2);
	printf("\n");
	s1 = "22345";
	s2 = "12345";
	printf("=======================FT=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", ft_strcmp(s1, s2), s1, s2);
	printf("=======================STD=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", strcmp(s1, s2), s1, s2);
	printf("\n");
	s1 = "12345";
	s2 = "22345";
	printf("=======================FT=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", ft_strcmp(s1, s2), s1, s2);
	printf("=======================STD=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", strcmp(s1, s2), s1, s2);
	printf("\n");
	s1 = "12A45";
	s2 = "12345";
	printf("=======================FT=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", ft_strcmp(s1, s2), s1, s2);
	printf("=======================STD=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", strcmp(s1, s2), s1, s2);
	printf("\n");
	s1 = "12345";
	s2 = "12A45";
	printf("=======================FT=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", ft_strcmp(s1, s2), s1, s2);
	printf("=======================STD=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", strcmp(s1, s2), s1, s2);
	printf("\n");
	s1 = "\xff\xff";
	s2 = "\xff";
	printf("=======================FT=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", ft_strcmp(s1, s2), s1, s2);
	printf("=======================STD=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", strcmp(s1, s2), s1, s2);
	printf("\n");
	s1 = "\xff";
	s2 = "\xff\xff";
	printf("=======================FT=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", ft_strcmp(s1, s2), s1, s2);
	printf("=======================STD=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", strcmp(s1, s2), s1, s2);
	printf("\n");
	s1 = "\xff";
	s2 = "\xff";
	printf("=======================FT=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", ft_strcmp(s1, s2), s1, s2);
	printf("=======================STD=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", strcmp(s1, s2), s1, s2);
	printf("\n");
	s1 = "this is string.";
	s2 = "";
	printf("=======================FT=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", ft_strcmp(s1, s2), s1, s2);
	printf("=======================STD=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", strcmp(s1, s2), s1, s2);
	printf("\n");
	s1 = "";
	s2 = "this is string.";
	printf("=======================FT=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", ft_strcmp(s1, s2), s1, s2);
	printf("=======================STD=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", strcmp(s1, s2), s1, s2);
	printf("\n");
	s1 = "";
	s2 = "";
	printf("=======================FT=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", ft_strcmp(s1, s2), s1, s2);
	printf("=======================STD=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", strcmp(s1, s2), s1, s2);
	printf("\n");
	s1 = (char *)0;
	s2 = (char *)0;
	printf("=======================FT=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", ft_strcmp(s1, s2), s1, s2);
	printf("=======================STD=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", strcmp(s1, s2), s1, s2);
	printf("\n");
	/* SEGFAULT
	s1 = "this is string.";
	s2 = (char *)0;
	printf("=======================FT=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", ft_strcmp(s1, s2), s1, s2);
	printf("=======================STD=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", strcmp(s1, s2), s1, s2);
	printf("\n");
	s1 = (char *)0;
	s2 = "this is string.";
	printf("=======================FT=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", ft_strcmp(s1, s2), s1, s2);
	printf("=======================STD=======================\n");
	printf("RET: %d$ S1: %s$ S2: %s$\n", strcmp(s1, s2), s1, s2);
	printf("\n");
	*/
}

void		test_ft_strcpy(void)
{
	char	*str;
	char	buf[42];

	str = "hello string copy!";
	printf("=======================FT=======================\n");
	bzero(buf, 42);
	printf("RET: %s$ S: %s$\n", ft_strcpy(buf, str), buf);
	printf("=======================STD=======================\n");
	bzero(buf, 42);
	printf("RET: %s$ S: %s$\n", strcpy(buf, str), buf);
	printf("\n");
	str = "";
	printf("=======================FT=======================\n");
	bzero(buf, 42);
	printf("RET: %s$ S: %s$\n", ft_strcpy(buf, str), buf);
	printf("=======================STD=======================\n");
	bzero(buf, 42);
	printf("RET: %s$ S: %s$\n", strcpy(buf, str), buf);
	printf("\n");
	/* SEGFAULT
	str = (char *)0;
	printf("=======================FT=======================\n");
	bzero(buf, 42);
	printf("RET: %s$ S: %s$\n", ft_strcpy(buf, str), buf);
	printf("=======================STD=======================\n");
	bzero(buf, 42);
	printf("RET: %s$ S: %s$\n", strcpy(buf, str), buf);
	printf("\n");
	*/
}

void		test_ft_strlen(void)
{
	char	*str;

	str = "this is string length test.";
	printf("=======================FT=======================\n");
	printf("RET: %zd S: %s$\n", ft_strlen(str), str);
	printf("=======================STD=======================\n");
	printf("RET: %zd S: %s$\n", strlen(str), str);
	printf("\n");
	str = "";
	printf("=======================FT=======================\n");
	printf("RET: %zd S: %s$\n", ft_strlen(str), str);
	printf("=======================STD=======================\n");
	printf("RET: %zd S: %s$\n", strlen(str), str);
	printf("\n");
	/* SEGFAULT
	str = (char *)0;
	printf("=======================FT=======================\n");
	printf("RET: %zd S: %s$\n", ft_strlen(str), str);
	printf("=======================STD=======================\n");
	printf("RET: %zd\n", strlen(0));
	printf("RET: %zd S: %s$\n", strlen(str), str);
	printf("\n");
	*/
}

int		main(void)
{
	printf("\n\nFT_STRLEN\n");
	test_ft_strlen();
	sleep(1);
	printf("\n\nFT_STRCPY\n");
	test_ft_strcpy();
	sleep(1);
	printf("\n\nFT_STRCMP\n");
	test_ft_strcmp();
	sleep(1);
	printf("\n\nFT_WRITE\n");
	test_ft_write();
	sleep(1);
	printf("\n\nFT_READ\n");
	test_ft_read();
	sleep(1);
	printf("\n\nFT_STRDUP\n");
	test_ft_strdup();
	return (0);
}
