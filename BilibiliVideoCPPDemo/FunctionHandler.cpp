#include<iostream>

using namespace std;

//����ָ���������� CalcΪ����
//1��������д (*����ָ������)
//2���ټ��� (�������� ��������[,�������� ��������])
//3�������ǰ����Ϸ���ֵ����
//4��Ȼ����ǰ����� typedef ����Ϊһ������
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
	//1��ֱ�ӵ��ã�ͨ�������������ú�����Cpuͨ��������ֱ�ӻ�ú������ڵ�ַ����ʼִ�в����أ�
	z = Add(x, y);
	printf("%d+%d=%d\n", x, y, z);
	z = Sub(x, y);
	printf("%d-%d=%d\n", x, y, z);
	cout << "---------------" << endl;
	//2��������ӵ��ã�ͨ��ָ������ָ����ú���������ָ����Ϊһ�ֱ������洢�ľ��Ǻ���������Ӧ�ĵ�ַ��Cpuͨ������ָ���ú������ڵ�ַ����ʼִ�в����أ�
	Calc funcPoint1 = &Add;
	Calc funcPoint2 = &Sub;

	//һ�нԵ�ַ������ı��ʾ������ݼ��㷨�����ݴ洢�ڱ���������ı��ʾ����Ա���������Ӧ���ڴ��ַΪ����һ���ڴ棬����ڴ��д洢���������ݣ�
	//�ڴ��С���ɱ������������;��������������㷨����������Ҳ�ǵ�ַ����ָ�Ժ���������Ӧ���ڴ��ַΪ����һ���ڴ棬
	//����ڴ��д洢�Ĳ���ĳ��ֵ������һ��������Ե�ָ�Cpu��������ָ��һ����ȥִ�У�Ȼ���������Ҫ�Ĺ��ܡ�
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