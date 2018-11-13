#pragma once
using namespace std;
#include <iostream>
class Task
{
	int ID;
	int Time;
public:
	Task();
	Task(int ID, int _Time);
	int GetTime();
	int GetID();
	void TimeStep();
	Task & operator=(const Task &b);
	
	friend istream& operator >> (istream &in, Task &v)
	{
		in >> v.ID;
		return in;
	}
	friend ostream& operator<<(ostream &out, const Task &v)
	{
		out << " Time: " << v.Time << ' ';
		return out;
	}
};
class Q {
	Task *q;
	int Size;
	int Top;
	int End;
public:
	Q();
	Q(int Size);
	//Q(const Q &b);
	bool Isempty();
	bool Isfull();
	void Push(Task a);
	Task Pop();
};
Q::Q(int _Size)
{
	q = new Task[Size];
	Size = _Size;
	End = Size - 1;
	Top = 0;
}
Q::Q()
{
	q = new Task[Size];
	Size = 10;
	End = Size - 1;
	Top = 0;
}
/*Q::Q(const Q&b)
{
	Size = b.Size;
	End = b.End;
	Top = b.Top;
	 q = new Task[Size];
	if (q==NULL)
	{
		throw - 2;
	}
	int i = Top;
	while (i != End + 1)
	{
		q[i] = b.q[i];
		i = (i + 1) % Size;
	}
}*/
bool Q::Isempty()
{
	return (Top == (End + 1) % Size);
}
bool Q::Isfull()
{
	return(Top == (End + 2) % Size);
}
void Q::Push(Task a)
{
	if (Isfull())
	{
		throw - 2;
	}
	End = (End + 1) % Size;
	q[End] = a;

}
Task Q::Pop()
{
	if (Isempty())
	{
		throw - 2;
	}
	Task w = q[Top];
	Top = ((Top + 1) % Size);
	return w;
}
Task::Task()
{
	ID = rand() % 100;
	Time = (rand() % 15) + 1;

}
Task::Task(int _ID, int _Time)
{
	ID = _ID;
	Time = _Time;

}
int Task::GetTime()
{
	return Time;
}
int Task::GetID()
{
	return ID;
}
void  Task::TimeStep()
{
	Time = Time - 1;
}
Task&Task:: operator=(const Task &b)
{
	if (this == &b) return *this;
	ID = b.ID;
	Time = b.Time;
	return *this;
}


