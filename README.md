# Array Implementation

## Description

The Array Project is a C++ project that provides a dynamic array implementation with features such as adding, removing, sorting elements, and saving/loading from/to a file.

## Table of Contents

- [Usage](#usage)
- [Features](#features)

## Usage 

    #include "Array.h"
    #include "TestClass.h"

    int main() {
        // Create an Array of TestClass objects
        Array<TestClass> testArray;

        // Populate the array with TestClass objects
        testArray.pushBack(TestClass(1, "Alice", "Dog", 25.5));
        testArray.pushBack(TestClass(3, "Bob", "Cat", 22.0));
        testArray.pushBack(TestClass(2, "Charlie", "Bird", 28.3));

        // Print the original array
        std::cout << "Original Array:\n";
        testArray.print();

        // Save the array to a file
        testArray.saveToFile("testArray.txt");
        std::cout << "Array saved to testArray.txt\n";

        // Clear the array
        testArray.popBack();
        testArray.popBack();
        testArray.popBack();

        // Load the array from the file
        testArray = testArray.loadFromFile<TestClass>("testArray.txt");
        std::cout << "Array loaded from testArray.txt\n";

        // Print the loaded array
        std::cout << "Loaded Array:\n";
        testArray.print();

        return 0;
    }

## Features
- Dynamic Array: The project includes a dynamic array implementation for various data types.
- File Loading: Supports loading data from a file into the array.
- Sorting: Implements a sorting algorithm for arranging elements in the array.
- Exception Handling: Utilizes exception handling for error scenarios.
- Object Serialization: Provides serialization of custom objects like the TestClass.
- Smart Pointers: Smart pointers, specifically std::unique_ptr, are employed for memory management.
