// chapter_6.1.5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#pragma warning (disable:4996)

#include <iostream>

//堆内存溢出
void heap_buffer_overflow()
{
    char* str = new char[5];
    strcpy(str, "hello");
    delete[]str;
}
//堆栈缓冲区溢出
void stack_buffer_overflow(int i)
{
    char x[10];
    memset(x, 0, 10);
    int res = x[i];
}
//两次释放内存
void double_free()
{
    char* p = new char[5];
    //do something
    delete[]p;
    //do something
    delete[]p;
}
//释放后继续使用
void heap_use_after_free()
{
    char* x = (char*)malloc(10 * sizeof(char));
    free(x);
    char c= x[5]; 
}
//内存分配、释放不匹配
void alloc_delloc_mismatch()
{
    char* pstr = new char[5];
    delete pstr;
    
    char* pstr2 =(char*) malloc(10);
    delete[]pstr2;

    char* pstr3 = new char[10];
    free(pstr3);
}
int main()
{
	//alloc_delloc_mismatch();   
	//heap_buffer_overflow();
    //stack_buffer_overflow(15);   
    //double_free(); 
	return 0;
}
