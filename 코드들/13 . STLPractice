#include <iostream>
using namespace std;

#include <vector>
#include <list>
#include <algorithm>

bool myCompare(const int& a, const int& b)
{
	if (a > b) return true;
	else return false;
}

class MyStudent {
public:
	enum SORT_OP { NUM_DSC = 0, NUM_ASC, NAME_DSC, NAME_ASC };
	static SORT_OP sort_mode;

	int m_num;
	string m_name;
	MyStudent(int n, string name) {
		m_num = n;
		m_name = name;
	}
	bool operator<(const MyStudent& in) {
		if (m_num < in.m_num) return true;
		return false;
	}
	static bool compare(const MyStudent& a, const MyStudent& b) {
		bool out = false;
		switch (sort_mode) {
		case NUM_DSC: if (a.m_num > b.m_num) out = true; break;
		case NUM_ASC: if (a.m_num < b.m_num) out = true; break;
		case NAME_DSC: if (a.m_name > b.m_name) out = true; break;
		case NAME_ASC: if (a.m_name < b.m_name) out = true; break;
		default:											break;
		}
		return out;
	}
};
MyStudent::SORT_OP MyStudent::sort_mode = MyStudent::NAME_DSC;


ostream & operator<<(ostream& o, const MyStudent& in) {
	o << "[" << in.m_num << "] " << in.m_name;
	return o;
}

int main()
{
	std::list <MyStudent> brr;
	brr.push_back(MyStudent(3, "Kim"));
	brr.push_back(MyStudent(10, "Lee"));
	brr.push_back(MyStudent(5, "Park"));
	brr.push_back(MyStudent(7, "Choi"));

	MyStudent::sort_mode = MyStudent::NUM_DSC;
	brr.sort(MyStudent::compare);						

	for (auto& e : brr)
		cout << e << endl;


	vector<int> arr;
	for (int i = 0; i < 10; i++)
		arr.push_back(rand() % 100);
	arr.pop_back();
//	arr.push_front(100);
//	arr.pop_front();

//	arr.sort(myCompare);

	std::sort(arr.begin(), arr.end(), myCompare);		//  a < b
//	std::reverse(arr.begin(), arr.end());

	for (auto& e : arr)
		cout << e << endl;

/*
	auto it = arr.begin();	 //  ݺ   
	while (it != arr.end())
	{
		if ((*it) % 2 == 0) it = arr.erase(it);
		else {
			cout << (*it) << endl;
//			if ((*it) < 50) arr.insert(it, 101);
			it++;
		}
	}
*/

/*
	for (auto it = arr.begin(); it != arr.end(); it++)
		cout << (*it) << endl;
	
	for (auto & e : arr)
		e *= 10;

	for (auto e : arr)
		cout << e << endl;
*/
/*
	for (int i = 0; i < arr.size(); i++)
		//cout << arr[i] << endl;
		cout << arr.at(i) << endl;
*/
	return 0;
}
