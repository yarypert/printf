#include "Libft.h"

wchar_t		ft_getwchar(wchar_t c)
{
	if (c <= 0x7F)
		return(c);
	else if		 (c <= 0x7FF)
	{
		c = (c >> 6) + 0xC0;
		c = (c & 0x3F) + 0x80;
	}
	else if (c <= 0xFFFF)
	{
		c = (c >> 12) + 0xE0;
		c = ((c >> 6) & 0x3F) + 0x80;
		c = (c & 0x3F) + 0x80;
	}
	else if (c <= 0x10FFFF)
	{
		c = (c >> 18) + 0xF0;
		c = ((c >> 12) & 0x3F) + 0x80;
		c = ((c >> 6) & 0x3F) + 0x80;
		c = (c & 0x3F) + 0x80;
	}
	return(c);
}
