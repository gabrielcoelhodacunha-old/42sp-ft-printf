#include "../include/ft_printf.h"

static size_t	determine_len(unsigned int un, size_t base_len);
static void		convert(unsigned int un, char *str, size_t len,
				t_uitoa_base *args);

char	*ft_uitoa_base(unsigned int un, char *base)
{
	t_uitoa_base	args;
	size_t		len;

	args.base_len = ft_strlen(base);
	len = determine_len(un, args.base_len);
	args.str = malloc((len + 1) * sizeof(char));
	if (!args.str)
		return (NULL);
	convert(un, base, len - 1, &args);
	args.str[len] = '\0';
	return (args.str);
}

static void	convert(unsigned int un, char *base, size_t len,
			t_uitoa_base *args)
{
	if (un >= args->base_len)
		convert(un / args->base_len, base, len - 1, args);
	args->str[len] = base[un % args->base_len];
}

static size_t	determine_len(unsigned int un, size_t base_len)
{
	size_t len;

	len = 1;
	while (un >= base_len)
	{
		un /= base_len;
		len++;
	}
	return (len);
}
