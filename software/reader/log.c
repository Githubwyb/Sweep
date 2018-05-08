/*
 * log.c
 *
 *  Created on: 2018-4-12
 *      Author: Dell
 */
#include "log.h"


/*
 * The hex log is in the following format:
 *
 *     0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F      0123456789ABCDEF
 * 01  aa 55 01 00 00 00 25 00 38 36 35 30 36 37 30 32     .U....%.86506702
 * 02  30 34 39 30 31 36 38 30 00 00 00 00 00 00 00 00     04901680........
 * 03  00 00 00 00 00 00 00 00 00 00 00 00                 ............
 *
 */
void log_hex(const char* data, int length)
{
    int i = 0, j = 0;

    printf("    ");
    for (i  = 0; i < 16; i++)
    {
        printf("%X  ", i);
    }
    printf("    ");
    for (i = 0; i < 16; i++)
    {
        printf("%X", i);
    }

    printf("\r\n");

    for (i = 0; i < length; i += 16)
    {
        printf("%02d  ", i / 16 + 1);
        for (j = i; j < i + 16 && j < length; j++)
        {
            printf("%02x ", data[j] & 0xff);
        }
        if (j == length && length % 16)
        {
            for (j = 0; j < (16 - length % 16); j++)
            {
                printf("   ");
            }
        }
        printf("    ");
        for (j = i; j < i + 16 && j < length; j++)
        {
            if (data[j] < 32 || data[j] >= 127)
            {
                printf(".");
            }
            else
            {
                printf("%c", data[j] & 0xff);
            }
        }

        printf("\r\n");
    }
}
