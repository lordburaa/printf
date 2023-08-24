#include "main.h"
/**
 * get_flags - clacualte
 * @format: for
 * @k: take parameter
 * Return: flags
 */
int get_flags(const char *format, int *k)
{
	int l, curr;
	int flag = 0;
	const char fg_ch[] = {'-', '+', '0', '#', ' ', '\0'};
	const int fg_arr[] = {F_MIN, F_PL, F_ZERO, F_HASH, F_HASH, F_SPACE, 0};

	for (curr = *k + 1; format[curr] != '\0'; curr++)
	{
		for (l = 0; fg_ch[l] != '\0'; l++)
		{
			if (format[curr] == fg_ch[l])
			{
				flag |= fg_ar[l];
				break;

			}
			if (fg_ch[l] == 0)
				break;
		}
		*k = curr - 1;
		return (flag);
	}
}
