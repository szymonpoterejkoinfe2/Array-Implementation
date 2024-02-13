#include <iostream>
#include <exception>
#include <string>

#pragma once
#ifndef ERRORS_H
#define ERRORS_H

class Error : public std::exception
{
	std::string errorMessage ;

public:
	Error(std::string message) { errorMessage = message; }

	const char* what()
    {
        return errorMessage.c_str();
    }
};





#endif