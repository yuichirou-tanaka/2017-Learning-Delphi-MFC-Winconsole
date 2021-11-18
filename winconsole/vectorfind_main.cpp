#include <vector>

using namespace std;

struct data1{
	int i;
	data1(){
		i = 1;
	}
};
struct data2{
	data1 *ptr;
	data2(data1* iptr) :ptr(iptr){}
	bool operator==(const data2& right) const {
		return ptr == right.ptr;
	}
};

void main(){
	data1 p1, p2, p3;
	p2.i = 2;
	p3.i = 3;

	data2 d2p1(&p1);
	data2 d2p2(&p2);

	vector<data2> v;


	v.push_back(d2p1);
	v.push_back(data2(&p2));
	v.push_back(data2(&p3));

	{

		vector<data2>::iterator itr = find(v.begin(), v.end(), d2p1);
		if (itr != v.end()){
			printf("sonzai");
		}
		else{
			printf("none");
		}

		v.erase(itr);
	}

	{
		vector<data2>::iterator itr = find(v.begin(), v.end(), d2p2);
		if (itr != v.end()){
			printf("sonzai");
		}
		else{
			printf("none");
		}
		v.erase(itr);
	}


}