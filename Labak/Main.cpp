#include"Q.h"

int main()
{
	Q turn(10);
	Task p1(1, 1);
	Task p2(2, 2);
	Task p3(3, 3);
	Task p4(4, 4);
	Task p5(5, 5);
	turn.Push(p1);
	turn.Push(p2);
	turn.Push(p3);
	turn.Push(p4);
	turn.Push(p5);

	int corn[100];
	int corn1[100];
	int i = 0;
	int j = 0;
	Task A = turn.Pop();
	int t=0;
	t = A.GetTime();
	for (int k = 0; k < t; k++)
	{
		corn[k] = A.GetID();
	}
	i = t - 1;

    A = turn.Pop();
	t = A.GetTime();
	for (int k = 0; k < t; k++)
	{
		corn1[k] = A.GetID();
	}
	j = t - 1;

	int k = 0;
	while (turn.Isempty() == false)
	{
		A = turn.Pop();
		t = A.GetTime();
		if (i > j)
		{
			j++;
			for (k = j; k < (j + t); k++)
			{
				corn1[k] = A.GetID();
			}
			j = k - 1;
		}
		else
		{
			i++;
			for (k = i; k < (i + t); k++)
			{
				corn[k] = A.GetID();
			}
			i = k - 1;
		}
	}

	cout << "core0: ";
	for (int h = 0; h <= i; h++)
	{
		cout << "t" << corn[h] << " ";
	}
	cout << endl << "core1: ";
	for (int h = 0; h <= j; h++)
	{
		cout << "t" << corn1[h] << " ";
	}
	cout << endl;

	return 0;
}






