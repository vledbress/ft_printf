#include "ft_printf.h"



// You have to implement the following conversions:
// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

static void	ft_print_str(char *str)
{
	if (!str)
		ft_putstr("(null)");
	else
		ft_putstr(str);
}

// va_list	Тип для хранения информации о списке аргументов
// va_start(ap, last)	Инициализирует доступ к аргументам
// va_arg(ap, type)	Извлекает следующий аргумент указанного типа
// va_end(ap)	Завершает работу со списком аргументов


static void	ft_putnbr(int num)
{
	long long int	dummy;

	dummy = num;
	if (num < 0)
	{
		ft_putchar('-');
		dummy = -dummy;
	}
	if (dummy >= 10)
		ft_putnbr(dummy / 10);
	ft_putchar((dummy % 10) + '0');
}

static size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static void	ft_putunbr_base(unsigned int num, char *base)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (num >= base_len)
		ft_putunbr_base(num / 16, base);
	ft_putchar(base[num % 16]);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	char	letter;

	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			letter = *(++format);
			if (letter == 'c')
				ft_putchar((char)va_arg(args, int));
			else if (letter == 's')
				ft_print_str(va_arg(args, char *));
			else if (letter == 'd' || letter == 'i')
				ft_putnbr(va_arg(args, int));
			else if (letter == 'x')
				ft_putunbr_base(va_arg(args, unsigned int), "0123456789abcdef");
			else if (letter == 'X')
				ft_putunbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
		}
		else 
			ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (0);
}



