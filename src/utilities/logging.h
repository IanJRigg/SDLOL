#ifndef LOGGING_H
#define LOGGING_H

#include <iostream>

#define NORMAL   "\x1B[0m"
#define RED      "\x1B[91m"
#define GREEN    "\x1B[92m"
#define YELLOW   "\x1B[93m"
#define BLUE     "\x1B[94m"
#define MAGENTA  "\x1B[95m"
#define CYAN     "\x1B[96m"
#define WHITE    "\x1B[97m"

#define LOG(output) std::cout << __func__ << "(): " << output << std::endl;
#define LOG_ERROR(output) std::cerr << __func__ << "(): " << RED << output << NORMAL << std::endl;

#endif