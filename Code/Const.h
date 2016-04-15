#ifndef CONST_H
#define CONST_H

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
	(std::ostringstream() << std::dec << x)).str()

#define DEBUG 0

#define READ 0
#define WRITE 1
#define APPEND 2

#define LM 0
#define LC 1
#define LB 2
#define RM 3
#define RC 4
#define RB 5

#endif