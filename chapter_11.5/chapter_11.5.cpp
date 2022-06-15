// chapter_11.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void test_fun(int i)
{
    std::cout << i << std::endl;
}
void test_temp_break_point()
{
    for (int i = 0; i < 10; i++)
    {
        test_fun(i);
    }
}
void depend_break_point()
{
    int i = 100;
    test_fun(i);
}

int main()
{    
    test_temp_break_point();
    depend_break_point();
}
