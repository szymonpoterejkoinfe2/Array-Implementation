#include "Errors.h"
#include <iostream>
#include <fstream>
#include <memory>

#pragma once
#ifndef ARRAY_H
#define ARRAY_H

template <class T>
class Array
{
	int arraySize;
	std::unique_ptr<T[]> buffer;

public:
	// General constructor
	Array() {
		arraySize = 0;
		buffer = nullptr;
	}

	// Copy constructor
	Array(const Array<T>& toCopy)
	{
		arraySize = toCopy.arraySize;
		buffer = std::make_unique<T[]>(arraySize);

		for (int i = 0; i < arraySize; i++)
		{
			buffer[i] = toCopy.buffer[i];
		}
	}

	// Move constructor
	Array(Array<T>&& toMove) noexcept : arraySize(toMove.arraySize), buffer(std::move(toMove.buffer))
	{
		toMove.arraySize = 0;
	}

	
	//Size getter
	int size()
	{
		return 	arraySize;
	}

	// Assigment operator
	Array<T>& operator=(const Array<T>& other)
	{
		if (this != &other)  // Check for self-assignment
		{

			delete[] buffer;

			arraySize = other.arraySize;
			buffer = new T[arraySize];
			for (int i = 0; i < arraySize; i++)
			{
				buffer[i] = other.buffer[i];
			}
		}
		return *this;
	}

	// Move operator
	Array<T>& operator=(Array<T>&& other) noexcept
	{
		if (this != &other)  // Check for self-assignment
		{

			delete[] buffer;

			arraySize = other.arraySize;
			buffer = other.buffer;

			other.arraySize = 0;
			other.buffer = nullptr;
		}
		return *this;
	}


	//Loading from file
	template<typename Type>
	Array<Type> loadFromFile(std::string filePath)
	{
		
		std::ifstream inputFile(filePath);

		Array<Type> tempArr;

		if (inputFile)
		{
			Type data;

			while (inputFile >> data)
			{
				tempArr.pushBack(data);
			}

			inputFile.close();
		}
		else {
			throw Error("Unable to open file");
		}

		return tempArr;
	}

	// Add element to array
	void pushBack(T data)
	{
		const int arrayLength = arraySize;

		arraySize++;

		std::unique_ptr<T[]> tempBuffer(new T[arraySize]);

		if (arrayLength > 0)
		{
			for (int index = 0; index < arrayLength; index++)
			{
				tempBuffer[index] = buffer[index];
			}
		}

		tempBuffer[arrayLength] = data;

		buffer = std::move(tempBuffer);

		std::cout << "Data added to array \n";

	}

	// Remove element from array
	void popBack()
	{
		if (arraySize > 0)
		{
			arraySize--;

			// Check if the array is empty before attempting to create a new buffer
			if (arraySize > 0) {
				std::unique_ptr<T[]> tempBuffer(new T[arraySize]);

				for (int index = 0; index < arraySize; index++)
				{
					tempBuffer[index] = buffer[index];
				}

				buffer = std::move(tempBuffer);

				std::cout << "Data deleted from array\n";
			}
			else
			{
				buffer.reset();
				std::cout << "Data deleted from array, array is now empty\n";
			}
		}
		else
		{
			throw Error("Can't delete object from empty array");
		}
	}

	// Find print array
	void print()
	{
		const int arrayLength = arraySize;

		if (arrayLength > 0)
		{
			for (int index = 0; index < arrayLength; index++)
			{
				std::cout << buffer[index] << std::endl;
			}
		}
		else
		{
			throw Error("Can't print empty array");
		}
	}

	// Sort elements in array
	void sort()
	{
		const int arrayLength = arraySize;

		if (arrayLength > 1)
		{
			for (int i = 0; i < arrayLength - 1; i++)
			{
				for (int j = 0; j < arrayLength - i - 1; j++)
				{
					if (buffer[j] > buffer[j + 1])
					{
						// Swap buffer[j] and buffer[j+1]
						T temp = buffer[j];
						buffer[j] = buffer[j + 1];
						buffer[j + 1] = temp;
					}
				}
			}
			std::cout << "Array sorted successfully \n";
		}
		else if (arrayLength == 0)
		{
			throw Error("Can't sort empty array");
		}
		else
		{
			std::cout << "Array has only one element, it is already sorted \n";
		}


	}

	// saving Array to a file;
	void saveToFile(std::string filePath)
	{
		std::ofstream outputFile(filePath);

		const int arrayLength = arraySize;

		if (arrayLength > 0)
		{
			if (outputFile)
			{

				for (int index = 0; index < arrayLength; index++)
				{
					outputFile << buffer[index] << "\n";
				}

			}
			else {
				throw Error("Unable to open file for writing");
			}
			
		}
		else
		{
			throw Error("Can't save empty array");
		}

		outputFile.close();
	}

	// Find element in array
	T find(T data)
	{
		const int arrayLength = arraySize;

		if (arrayLength > 0)
		{
			for (int index = 0; index < arrayLength; index++)
			{
				if (buffer[index] == data)
				{
					return buffer[index];
				}
			}
		}
		
		throw Error("No such object in array");

	}

	// Take index element of array
	T index(const int &index)
	{
		if (index >= 0 && index < arraySize)
		{
			return buffer[index];
		}
		else
		{
			throw Error("Index out of range");
		}
	}

};

#endif