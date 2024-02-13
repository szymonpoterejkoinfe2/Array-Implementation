#include <iostream>
#include "TestClass.h"

TestClass::TestClass() {}

TestClass::TestClass(int number, std::string name, std::string pet, float temperature) {

	this->number = number;
	this->name = name;
	this->pet = pet;
	this->temperature = temperature;

}


std::ostream& operator<<(std::ostream& os, const TestClass& testClass)
{
	os << testClass.number << "\t" << testClass.name << "\t" << testClass.pet << "\t" << testClass.temperature;
	return os;
}

std::istream& operator>>(std::istream& s_in, TestClass& testClass)
{
	s_in >> testClass.number >> testClass.name >> testClass.pet >> testClass.temperature;
	return s_in;
}

bool TestClass:: operator < (const TestClass& testClass)
{
	return number < testClass.number;
}

bool TestClass::operator > (const TestClass& testClass)
{
	return number > testClass.number;
}

bool TestClass::operator == (const TestClass& testClass)
{
	return number == testClass.number && name == testClass.name && pet == testClass.pet && temperature == testClass.temperature;              
}