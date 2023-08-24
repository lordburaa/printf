#include "main.h"
/**
 * get_flags - clacualte
 * @format: for
 * @k: take parameter
 * Return: flags
 */
int get_flags(const char *format, int *k)
{
	int k, curr;
	int flag = 0;
	const char fg_ch[] = {'-', '+', '0', '#', ' ', '\0'};
	const int fg_ar[] = {F_MIN, F_PL, F_ZERO, F_HASH, F_HASH, F_SPACE, 0};

	for (curr = *k + 1; format[curr] != '\0'; curr++)
	{
		for (k = 0; fg_ch[k] != '\0'; k++)
		{
			if (format[curr] == fg_ch[k])
			{
				flag |= fg_ar[k];
				break;

			}
			if (fg_ch[k] == 0)
				break;
		}
		*k = curr - 1;
		return (flag);
	}
}
