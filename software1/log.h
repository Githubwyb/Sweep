/*
 * log.h
 *
 *  Created on: 2018-4-12
 *      Author: wyb
 */

#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>

#define LOG_DEBUG(fmt, ...) printf("[D][%s:%d %s] "fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);printf("\r\n")
#define LOG_INFO(fmt, ...) printf("[I][%s:%d %s] "fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);printf("\r\n")
#define LOG_ERROR(fmt, ...) printf("[E][%s:%d %s] "fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);printf("\r\n")

void log_hex(const char* data, int length);

#endif /* LOG_H_ */
