#include <Windows.h>

#include <vector>

#include <iostream>
#include <map>
#include <algorithm>

#include <memory>

typedef struct _ObjData{
	int testobj;
	_ObjData(int iobj) :testobj(iobj){

	}


}ObjData;
typedef std::shared_ptr<ObjData>	spObjData;
typedef std::map<unsigned int, spObjData>	vKeyObj;

using namespace std;
typedef std::map<BYTE, unsigned int>	vKey;
;

// vector‚Ì—v‘f‚ğ‡”Ô‚É•\¦
void printMap(vKey &m){
	cout << "size = " << m.size() << endl;
	for (vKey::iterator it = m.begin();
		it != m.end();
		++it){
		printf("[%d]:%d \n", it->first, it->second);

		//cout << it->first << ", "<< it->second << endl;
	}
	cout << endl << endl;
}
void printMap(vKeyObj &m){
	cout << "size = " << m.size() << endl;
	for (vKeyObj::iterator it = m.begin();
		it != m.end();
		++it){
		printf("[%d]:%d \n", it->first, it->second);

		//cout << it->first << ", "<< it->second << endl;
	}
	cout << endl << endl;
}

void main1(){
	
	vKey			m_key;
	m_key.clear();

	m_key.insert(std::make_pair(33, 9));
	m_key.insert(std::make_pair(32,2));
	m_key.insert(std::make_pair(35, 3));
	m_key.insert(std::make_pair(1, 1));
	//m_key[0] = 0;
	//m_key[1] = 1;
	
	printMap(m_key);
	//printf("key size = %d \n", m_key.size());
	//for(int i = 0; i < m_key.size();i++){
	//	printf("[%d]:%d \n", i, m_key[i]);
	//}

	m_key.erase(32);

	printMap(m_key);
	printf("key size = %d \n", m_key.size());
	for(int i = 0; i < m_key.size();i++){
		printf("[%d]:%d \n", i, m_key[i]);
	}

	if (m_key.empty()) {
		printf("empty\n");
	}
	if (m_key.find(0) == m_key.end()) {
		printf("no find 1\n");
	} else {
		printf("find 1\n");
	}

}
//void main2(){
//
//	vKeyObj			m_key;
//	m_key.clear();
//
//	unsigned int id = 33;
//	/*std std::make_shared<ObjData>(new ObjData(10)
//	m_key.insert(std::make_pair(id,)));
//	*///m_key.insert(std::make_pair(32, 2));
//	//m_key.insert(std::make_pair(35, 3));
//	//m_key.insert(std::make_pair(1, 1));
//	//m_key[0] = 0;
//	//m_key[1] = 1;
//
//	//printMap(m_key);
//	//printf("key size = %d \n", m_key.size());
//	//for(int i = 0; i < m_key.size();i++){
//	//	printf("[%d]:%d \n", i, m_key[i]);
//	//}
//
//	//m_key.erase(32);
//
//	//printMap(m_key);
//	//printf("key size = %d \n", m_key.size());
//	//for (int i = 0; i < m_key.size(); i++){
//	//	printf("[%d]:%d \n", i, m_key[i]);
//	//}
//
//	//if (m_key.empty()) {
//	//	printf("empty\n");
//	//}
//	//if (m_key.find(0) == m_key.end()) {
//	//	printf("no find 1\n");
//	//}
//	//else {
//	//	printf("find 1\n");
//	//}
//
//}

void main(){
	main1();
}
