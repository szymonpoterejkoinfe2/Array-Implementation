#include <string>
#include <iostream>

#pragma once
#ifndef TESTCLASS_H
#define TESTCLASS_H

class TestClass
{
	int number;
	std::string name;
	std::string pet;
	float temperature;

public:
	TestClass();

	TestClass(int number, std::string name, std::string pet, float temperature);

	friend std::ostream& operator<<(std::ostream& os, const TestClass& testClass);

	friend std::istream& operator>>(std::istream& s_in, TestClass& testClass);

	bool operator < (const TestClass& testClass);

	bool operator > (const TestClass& testClass);

	bool operator == (const TestClass& testClass);
};

#endif