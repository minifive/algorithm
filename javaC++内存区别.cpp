#include<iostream>
#include <string>
using namespace std;
//JAVA��
//A a = new A();
//ΪA���󴴽���һ��ʵ���������ڴ��п���������ռ䣺һ��ռ��ڶ��������new A�������������һ��ռ��ڶ�ջ��Ҳ����ջ�����a��a��ֵΪnew A�������������ڴ��ַ����Ϊjava��JVM�����У�����a �������ڴ��ַ��һ�������������ʵ�ڴ�ĵ�ַ��
//
//Object o; // ��������һ�����ã�����������Object������ֵΪnull����û��ָ���κζ��󣬸����÷����ڴ��ջ�����С�
//
//o = new Object(); // new Object()�䣬ʵ������һ�����󣬾����ڶ���������һ�������ռ�������Ÿö���
//= // �������������oָ���˶���Ҳ����˵��ջ�б�ʾ����o���ڴ��ַ�����ݸ�д����Object�����ڶ��еĵ�ַ��
//
//C++��
//C++ ���ֱ�Ӷ����࣬��classA a; a ����ջ�ϣ�Ҳ��ζ�Ÿ����˶���a��ջ�У������classA a = new classA�ʹ��ڶ���
class persen{
public: 
	string name;
	int age;
	void print(){
		cout << name << " " << age;
	}
};

//void main()
//{
//	persen p1,p2;
//	p1.name = "1";
//	p1.age = 30;
//	p2.name = "2";
//	p1.print();
//
//}