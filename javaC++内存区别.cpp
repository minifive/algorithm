#include<iostream>
#include <string>
using namespace std;
//JAVA：
//A a = new A();
//为A对象创建了一个实例，但在内存中开辟了两块空间：一块空间在堆区，存放new A（）这个对象；另一块空间在堆栈，也就是栈，存放a，a的值为new A（）这个对象的内存地址。因为java在JVM中运行，所以a 描述的内存地址不一定是这个对象真实内存的地址。
//
//Object o; // 这是声明一个引用，它的类型是Object，他的值为null，还没有指向任何对象，该引用放在内存的栈区域中。
//
//o = new Object(); // new Object()句，实例化了一个对象，就是在堆中申请了一块连续空间用来存放该对象。
//= // 运算符，将引向o指向了对象。也就是说将栈中表示引用o的内存地址的内容改写成了Object对象在堆中的地址。
//
//C++：
//C++ 如果直接定义类，如classA a; a 存在栈上（也意味着复制了对象a在栈中），如果classA a = new classA就存在堆中
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