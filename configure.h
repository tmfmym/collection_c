/*
 * configure.h
 *
 *  Created on: 2012/11/05
 *      Author: tomofumi
 */
 
#ifndef CONFIGURE_H_
#define CONFIGURE_H_

#define FALSE 0
#define TRUE 1

#define INDEXOUTOFBOUNDSEXCEPTION "IndexOutOfBoundsException: at"
#define NULLPOINTEREXCEPTION "NullPointerException: at"
#define CANNOTALLOCATEMEMORY "error:Cannot allocate memory at %s\n"

/* ログレベル */
#ifndef LOG_LEVEL
#define LOG_LEVEL 40
#endif

#endif /* CONFIGURE_H_ */
