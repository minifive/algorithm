#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;
#define  testNUM 10 //要求测试页面
#define  MaxFrame 100 //产生的随机数范围为0-9
struct LRUframe
{
	int ID;
	int count;//标记使用时间域，count越大表示最近使用
	LRUframe()
	{
		ID = -1;
		count = 0;
	}
};
struct ARBframe 
{
	int ID;
	__int8 Regist;//8位寄存器
	int Reference;//引用位
	ARBframe()//初始化
	{
		ID = -1;
		Regist = 0;
		Reference = 0;
	}
};
int counterLRU(int MaxmemoryFrame, int Testnum,int Rand);
int stackLRU(int MaxmemoryFrame, int Testnum, int Rand);
int additionalBit(int MaxmemoryFrane, int Testnum, int Rand);
int SecondChance(int MaxmemoryFrane, int Testnum, int Rand);
int main(){
	float *Error =new float[4];
	int Rand = time(0);
	int maxmemoryframe = 2;
	int testnum = 10;
	Error[0] = counterLRU(maxmemoryframe, testnum, Rand);
	Error[1] = stackLRU(maxmemoryframe, testnum, Rand);
	Error[2] = additionalBit(maxmemoryframe, testnum, Rand);
	Error[3] = SecondChance(maxmemoryframe, testnum, Rand);
	cout << "Error rate num for countLRU:" << Error[0] / testnum << endl;
	cout << "Error rate num for stackLRU:" << Error[1] / testnum << endl;
	cout << "Error rate num for additionalBit;" << Error[2] / testnum << endl;
	cout << "Error rate num for SecondChance:" << Error[3] / testnum << endl;
	return 0;
}



int counterLRU(int MaxmemoryFrame, int Testnum,int Rand){
	int CPUtime = 0;//cpu时钟计数器。
	int lastuse = 0;
	int Errornum = 0;
	srand(Rand);
	LRUframe*frames = new LRUframe[MaxmemoryFrame];
	while (Testnum--)
	{
		CPUtime++;
		LRUframe newf;
		newf.ID =rand() % MaxFrame;
		int i = 0;
		for (; i < MaxmemoryFrame; i++)
		{
			if (frames[i].ID == newf.ID)//在内存帧中找到
				break;
			if (frames[i].count < frames[lastuse].count)
				lastuse = i;
		}
		if (i < MaxmemoryFrame)//请求帧在内存中找到
			frames[i].count = CPUtime;//更新其使用时间域为最新
		else
		{
			Errornum=Errornum+1;
			frames[lastuse].ID = newf.ID;//将lastuse替换掉
			frames[lastuse].count = CPUtime;
		}
	}
	delete[]frames;
	return Errornum;
}


int stackLRU(int MaxmemoryFrame, int Testnum, int Rand){
	vector<int>buffer;
	vector<int>::iterator itr = buffer.begin();
	int Errornum = 0;
	srand(Rand);
	while (Testnum--)
	{
		int newf = rand() % MaxFrame;
		int i = 0;
		for (; i < buffer.size(); i++)
		{
			if (buffer[i] == newf)
			{
				itr = buffer.begin();
				buffer.erase(itr+i);//擦除原有记录并重新push到头部
				buffer.push_back(newf);
				if (buffer.size() > MaxmemoryFrame)//每次push新的数都判断栈大小是否超出范围
				{
					itr = buffer.begin();
					buffer.erase(itr);//若超出则删除栈底元素；
				}
				break;
			}
		}
		if (i==buffer.size())//没找到
		{
			Errornum++;
			buffer.push_back(newf);
			if (buffer.size() > MaxmemoryFrame)//每次push新的数都判断栈大小是否超出范围
			{
				itr = buffer.begin();
				buffer.erase(itr);//若超出则删除栈底元素；
			}
		}
	}//end while;
	return Errornum;
}


int additionalBit(int MaxmemoryFrane, int Testnum, int Rand){
	srand(Rand);
	int Errornum = 0;
	ARBframe *frames = new ARBframe[MaxmemoryFrane];
	int lastused = 0;
	int count = 0;
	while (Testnum--)
	{
		int newf = rand() % MaxFrame;
		int i = 0;
		for (; i < MaxmemoryFrane;i++)
		{
			if (frames[i].ID == newf)
				break;
			if (frames[i].Regist < frames[lastused].Regist)//8位寄存器数值小的为LRU
				lastused = i;
		}
		if (i<MaxmemoryFrane)//find
		{
			frames[i].Reference = 1;//设置其引用位为1
		}
		else{
			Errornum++;
			frames[lastused].ID = newf;//替换掉最久未使用的值
			frames[lastused].Reference = 1;
		}
		if (count==5)//每5次更新一下8位寄存器
		{
			count = 0;
			for (int i = 0; i < MaxmemoryFrane;i++)
			{
				frames[i].Regist = (frames[i].Regist >> 1)+ (frames[i].Reference << 7); //寄存器值右移一位加上引用位左移7位
			}
		}
	}//end of while
	return Errornum;
}


int SecondChance(int MaxmemoryFrane, int Testnum, int Rand){
	srand(Rand);
	ARBframe *frames = new ARBframe[MaxmemoryFrane];
	int Errornum = 0;
	int lastused = 0;
	while (Testnum--)
	{
		int newf = rand() % MaxFrame;
		int i = 0;
		for (; i < MaxmemoryFrane; i++)
		{
			if (frames[i].ID == newf)
				break;
		}
		if (i < MaxmemoryFrane){
			frames[i].Reference = 1;
		}
		else{
			Errornum++;
			while (frames[lastused].Reference!=0)//找到第一个引用为为0时结束
			{
				frames[lastused].Reference = 0;//当引用位为1时 给第二次机会
				lastused = (lastused++) % MaxmemoryFrane;//环形查找
			}
			frames[lastused].ID = newf;//替换
		}
	}
	return Errornum;
}