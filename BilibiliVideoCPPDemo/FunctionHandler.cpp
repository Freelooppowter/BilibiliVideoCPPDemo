#include<iostream>

using namespace std;

//函数指针数据类型 Calc为名称
//1、首先书写 (*函数指针名称)
//2、再加上 (参数类型 参数名称[,参数类型 参数名称])
//3、最后在前面加上返回值类型
//4、然后在前面加上 typedef 定义为一种类型
typedef int(*Calc)(int a, int b);
int Add(int a, int b)
{
	int result = a + b;
	return result;
}

int Sub(int a, int b)
{
	int result = a - b;
	return result;
}

int main()
{
	int x = 100;
	int y = 50;
	int z = 0;
	//1、直接调用（通过函数名来调用函数，Cpu通过函数名直接获得函数所在地址并开始执行并返回）
	z = Add(x, y);
	printf("%d+%d=%d\n", x, y, z);
	z = Sub(x, y);
	printf("%d-%d=%d\n", x, y, z);
	cout << "---------------" << endl;
	//2、函数间接调用（通过指向函数的指针调用函数，函数指针作为一种变量，存储的就是函数名所对应的地址，Cpu通过函数指针获得函数所在地址并开始执行并返回）
	Calc funcPoint1 = &Add;
	Calc funcPoint2 = &Sub;

	//一切皆地址：程序的本质就是数据加算法，数据存储在变量里，变量的本质就是以变量名所对应的内存地址为起点的一段内存，这段内存中存储变量的数据，
	//内存大小是由变量的数据类型决定；函数代表算法，函数本质也是地址，是指以函数名所对应的内存地址为起点的一段内存，
	//这段内存中存储的不是某个值，而是一组机器语言的指令，Cpu按照这组指令一条条去执行，然后完成所需要的功能。
	cout << funcPoint1 << endl;
	cout << funcPoint2 << endl;
	z = funcPoint1(x, y);
	printf("%d+%d=%d\n", x, y, z);
	z = funcPoint2(x, y);
	printf("%d-%d=%d\n", x, y, z);
	cout << "Hello world" << endl;

	system("pause");

	return 0;

}