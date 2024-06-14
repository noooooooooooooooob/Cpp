#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string name;						// member variables
	int num;
	float score;

public:									// visibility
										// member functions
	void setStudentData(string na, int nu, float sc)
	{
		name = na;
		num = nu;
		score = sc;
	}
	void printStudent()
	{
		cout << "[" << num << "] Name:" << name
			<< "Score = " << score << endl;
	}
};



int main()
{
	Student a;					// instance (object)
	Student b;
	//a.name = "Park";

	a.setStudentData("Kim", 2300000, 30.0f);
	b.setStudentData("Lee", 2300001, 70.0f);
	a.printStudent();
	b.printStudent();

	return 0;
}



/*
#include <iostream>
using namespace std;


void mySwap(int *a, int *b)			// call by pointer
//int *a = &p;						// call by reference
//int *b = &q;
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//void func(int arr[], int n)
void func(int *arr, int n)
{
	for (int i = 0; i <n; i++)
		arr[i] = i * 3;
}
void func2(int *arr, int row, int col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			//arr[i][j] = i + j;
			int index = i * col + j;
			arr[index] = i + j;
		}
}
int main()
{
	const int size = 10;
	int a[size];
	func(a, size);
	const int row = 10;
	const int col = 5;
	int m[row][col];
	//  m[i][j] <- m + col*i + j
	func2(&m[0][0], row, col);


	int p = 50;
	int q = 10;
	mySwap(&p, &q);
	cout << "p=" << p << ", q=" << q << endl;

	return 0;
}
*/
