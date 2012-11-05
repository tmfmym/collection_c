/*
 * logger.h
 * ロガーもどき
 *
 *  Created on: 2012/11/03
 *      Author: tomofumi
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdio.h>

/* デバックログを出力 */
#if LOG_LEVEL > 30
#define LOGGER_DEBUG(...) printf(__VA_ARGS__)
#else
#define LOGGER_DEBUG(...)
#endif

/* インフォログを出力 */
#if LOG_LEVEL > 20
#define LOGGER_INFO(...) printf(__VA_ARGS__)
#else
#define LOGGER_INFO(...)
#endif

#if LOG_LEVEL > 10
#define LOGGER_WARNING(...) printf(__VA_ARGS__)
#else
#define LOGGER_WARNING(...)
#endif

#if LOG_LEVEL > 0
#define LOGGER_ERROR(...) printf(__VA_ARGS__)
#else
#define LOGGER_ERROR(...)
#endif

#endif /* LOGGER_H_ */
