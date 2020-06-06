#include <malloc.h>
#include <string.h>

struct NODE
{
	int  ID;
	char Name[40];
	int age;
	NODE* prev;
	NODE *next;
};
struct NODE *node_head = NULL;
int member_id = 0;
void add_member()
{
	struct NODE *new_node = (NODE*)malloc(sizeof(NODE));
	new_node->next = NULL;
	NODE* prev_node = node_head->prev;
	if(prev_node)
	{
		prev_node->next = new_node;
		new_node->prev = prev_node;
		node_head->prev = new_node;

	}
	else
	{
		node_head->next = new_node;
		new_node->prev = node_head;
		node_head->prev = new_node;
	}
	new_node->ID = member_id++;
	printf("请输入会员姓名,然后按回车\n");
	scanf("%s",new_node->Name);
	printf("请输入会员年龄,然后按回车\n");
	scanf("%d",&new_node->age);

	printf("添加新会员成功\n");

}
class test_1
{
public:
	test_1(){x=10;y=100;}
	virtual ~test_1(){}
	virtual void test_fun()
	{
		printf("test_1 test_fun\n");
	}
private:
	int x;
	int y;
	
};
class test_2:public test_1
{
public:
	test_2(){}
	virtual ~test_2(){}
	virtual void test_fun()
	{
		printf("test_2 test_fun\n");
	}

};
void test_fun(int i)
{
	printf("i is %d\n",i);
}
void test_fun(const char* str)
{
	printf("str is %s\n",str);
}
void test_fun_x()
{
	printf("test fun x\n");
}
void test_loop()
{
	for(int i=0;i<1000;i++)
	{
		printf("i is %d\n",i);
	}
	printf("exit the loop\n");
}

void cond_fun_test(int a,const char *str)
{
	int x = a * a;
	printf("a is %d,x is %d,str is %s\n",a,x,str);
	x *=2;
	printf("quit fun\n");
}
void print_arr_test()
{
	int iarr[]={0,1,2,3,4,5,6,7,8,9};
	const char *strarr[]={"this","is","a","test","string"};
	for(unsigned long i=0;i<sizeof(iarr)/sizeof(int);i++)
	{
		printf("%d ",iarr[i]);
	}
	for(int i=0;i<5;i++)
	{
		printf("%s ",strarr[i]);
	}
	printf("arr test done\n");
}
int main(int argc,char* argv[])
{
	print_arr_test();

	cond_fun_test(10,"test");
	//test_loop();
	
	
	for(int i=0;i<10;i++)
	{
		printf("execute test_fun_x\n");
		test_fun_x();
	}
	
	test_fun(10);
	test_fun("test");
	test_1 *test = new test_1();
	test->test_fun();
	test_1 *test2 = new test_2();
	test2->test_fun();
	printf("传入的参数信息为:\n");
	for(int i=0;i<argc;i++)
	{
		printf("参数 %d=%s\n",i,argv[i]);
	}
	node_head = (struct NODE*)malloc(sizeof(NODE));
	node_head->next = node_head->prev= NULL;
	printf("会员管理系统\n1:录入会员信息\nq:退出\n");
	while(true)
	{
		switch(getchar())
		{
		case '1':
			add_member();
			break;
		case 'q':
			return 0;
		default:
			break;
		}
	}	
	return 0;
}

