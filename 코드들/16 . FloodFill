#include <iostream>
using namespace std;
#include <fstream>



void printMap(char map[][100], int W, int H)
{
	cout << "==================================" << endl;
	for (int j = 0; j < H; j++)
	{
		for (int i = 0; i < W; i++)
			cout << map[j][i];
		cout << endl;
	}
	cout << "==================================" << endl;
}

class MyPaint {
public:
	int m_x;
	int m_y;
	int m_prevC;
	int m_newC;
	MyPaint(int x, int y, char prevC, char newC) :
		m_x(x), m_y(y), m_prevC(prevC), m_newC(newC) {};
};

#include <list>
void FloodFill(char map[][100], int W, int H,
			   int x, int y, char prevC, char newC)
{
	std::list<MyPaint> paintStack;
	paintStack.push_back(MyPaint(x, y, prevC, newC));

	while (paintStack.empty() != true)
	{
		cout << "Current Stack Size : " << paintStack.size() << endl;

		MyPaint p = paintStack.back();
		paintStack.pop_back();

		if (p.m_x<0 || p.m_x>W - 1) continue;
		if (p.m_y<0 || p.m_y>H - 1) continue;
		if (map[p.m_y][p.m_x] != p.m_prevC) continue;
		
		map[p.m_y][p.m_x] = p.m_newC;
		printMap(map, W, H);

		paintStack.push_back(MyPaint(p.m_x+1, p.m_y, p.m_prevC, p.m_newC));
		paintStack.push_back(MyPaint(p.m_x-1, p.m_y, p.m_prevC, p.m_newC));
		paintStack.push_back(MyPaint(p.m_x, p.m_y+1, p.m_prevC, p.m_newC));
		paintStack.push_back(MyPaint(p.m_x, p.m_y-1, p.m_prevC, p.m_newC));
	}
}

int main()
{
	ifstream fin;
	fin.open("map.txt");

	char map[100][100];

	int W, H;
	fin >> W >> H;
	cout << W << ", " << H << endl;

	for (int j = 0; j < H; j++)
	{
		for (int i = 0; i < W; i++)
		{
			fin >> map[j][i];
			cout << map[j][i];
		}
		cout << endl;
	}
	fin.close();

	int x = W / 2;
	int y = H / 2;
	char prevC = map[y][x];
	char newC = 'O';
	
	FloodFill(map, W, H, x, y, prevC, newC);
	return 0;
}


