// Array.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "ArrayClass.h"
#include "Errors.h"
#include "TestClass.h"

int main()
{ 

// Tseting 
#pragma region Int_Testing

    Array<int> newArr;

    try
    {
        for (int i = 1; i < 100; i++)
        {
            newArr.pushBack(i);
            newArr.pushBack(12 * i);
        }

    }
    catch (Error& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    newArr.sort();
    newArr.print();

    try
    {
        std::cout << newArr.find(12) << std::endl;
        std::cout << newArr.find(1111) << std::endl;
    }
    catch (Error& e)
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }


    try
    {
        for (int i = 0; i < newArr.size(); i += 8)
        {
            std::cout << newArr.index(i) << std::endl;
        }
        std::cout << newArr.index(newArr.size() + 1) << std::endl;
    }
    catch (Error& e)
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }


    newArr.saveToFile("pliktestowyInt.txt");

    Array<int> intArray = intArray.loadFromFile<int>("pliktestowyInt.txt");

    std::cout << " //////////////// From file //////////////////////" << std::endl;
    intArray.print();


#pragma endregion

    

#pragma region char_Testing

    Array<char> charArr;

    try
    {
        for (int i = 97; i < 123; i++)
        {
            charArr.pushBack(i);
        }

    }
    catch (Error& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    charArr.print();

    try
    {
        for (int i = 123; i > 96; i--)
        {
            charArr.pushBack(i);
        }

    }
    catch (Error& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    charArr.sort();
    charArr.print();

    try
    {
        std::cout << charArr.find('a') << std::endl;
        std::cout << charArr.find('4') << std::endl;
    }
    catch (Error& e)
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    try
    {
        for (int i = 0; i < charArr.size(); i += 3)
        {
            std::cout << charArr.index(i) << std::endl;
        }

        std::cout << charArr.index(newArr.size()+1) << std::endl;
    }
    catch (Error& e)
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    charArr.saveToFile("pliktestowyChar.txt");


    Array<char> charArray = charArray.loadFromFile<char>("pliktestowyChar.txt");

    std::cout << " //////////////// From file //////////////////////" << std::endl;
    charArray.print();

#pragma endregion
    
#pragma region bool_Testing

    Array<bool> boolArr;

    try
    {
        for (int i = 0; i < 21; i++)
        {
            if (i % 2 == 0)
            {
                boolArr.pushBack(true);
            }
            else
            {
                boolArr.pushBack(false);
            }
            
        }

    }
    catch (Error& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    boolArr.print();
    
    boolArr.sort();
   
    boolArr.print();

    try
    {
        std::cout << boolArr.find(false) << std::endl;
        std::cout << boolArr.find(true) << std::endl;
    }
    catch (Error& e)
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << boolArr.index(1) << std::endl;

        std::cout << boolArr.index(boolArr.size() + 1) << std::endl;
    }
    catch (Error& e)
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }


    boolArr.saveToFile("pliktestowyBool.txt");


    Array<bool> boolArray = boolArray.loadFromFile<bool>("pliktestowyBool.txt");

    std::cout << " //////////////// From file //////////////////////" << std::endl;
    boolArray.print();


#pragma endregion

#pragma region class_Testing

    int intValues[] = {
        42, 17, 99, 23, 56,
        8, 4, 12, 33, 7,
        18, 6, 14, 29, 50
    };

    std::string Pets[] = {
        "Dog", "Cat", "Elephant", "Lion", "Monkey",
        "Giraffe", "Kangaroo", "Penguin", "Tiger", "Zebra",
        "Panda", "Koala", "Hippopotamus", "Gorilla", "Polar_Bear"
    };

    std::string humanNames[] = {
        "Emma", "Liam", "Olivia", "Noah", "Ava",
        "Sophia", "Jackson", "Isabella", "Lucas", "Mia",
        "Amelia", "Ethan", "Harper", "Alexander", "Ella"
    };

    float floatValues[] = {
       3.14f, 2.718f, 1.618f, 0.99f, 4.20f,
       2.5f, 7.77f, 6.66f, 9.8f, 5.55f,
       3.33f, 1.11f, 8.88f, 4.44f, 0.123f
    };

    TestClass newTestClass(15,"Szymon","Dog",22.3f);

    Array<TestClass> classArr;

    std::cout << "Class Testing \n";

    for (int i = 0; i < 15; i++)
    {

        classArr.pushBack(TestClass(intValues[i], humanNames[i], Pets[i], floatValues[i]) );
    }

    classArr.print();

    classArr.sort();

    classArr.print();

    try
    {
        std::cout << classArr.find(TestClass(intValues[3], humanNames[3], Pets[3], floatValues[3])) << std::endl;
        std::cout << classArr.find(TestClass(15, "Szymon", "Dog", 22.3f)) << std::endl;
    }
    catch (Error& e)
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << classArr.index(1) << std::endl;

        std::cout << classArr.index(classArr.size() + 1) << std::endl;
    }
    catch (Error& e)
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    classArr.saveToFile("pliktestowyClass.txt");

    std::cout << classArr.size() << std::endl;

    Array<TestClass> classArray = classArray.loadFromFile<TestClass>("pliktestowyClass.txt");

    std::cout << " //////////////// From file //////////////////////" << std::endl;

    std::cout << classArray.size() << std::endl;

    classArray.print();


#pragma endregion


    
}


