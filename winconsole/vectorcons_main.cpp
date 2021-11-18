// vector_front.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

//
//template<typename T>
//void pop_front(std::vector<T>& vec)
//{
//	if (vec.empty())return;
//	vec.front() = std::move(vec.back());
//	vec.pop_back();
//}

template <typename V>
void pop_front(V & v)
{
	if (v.empty())return;
	//assert(!v.empty());
	v.erase(v.begin());
}

int main()
{
	using namespace std;
	vector <int> v1;

	v1.push_back(10);
	v1.push_back(11);
	v1.push_back(12);
	v1.push_back(13);

	int& i = v1.front();
	const int& ii = v1.front();

	cout << "The first integer of v1 is " << i << endl;
	// by incrementing i, we move the the front reference to the second element
	//i++;

	//v1.pop_back();
	i = v1.back();

	pop_front(v1);


	i = v1.front();

	cout << "v1 is " << i << endl;


}