#include <iostream>
#include <SFML/Graphics.hpp>
#include "List.h"
using namespace std;

//int main()
//{
//	cout << " Work with tamlate" << endl;
//	//int *a = new int[10];
//	//cout << _msize(a);
//	//best_list::List<int>lis(12);
//	//lis.push_back(32);
//	//lis.push_back(32);
//	//cout<< lis.pop_back() <<endl;
//	//cout<< lis.pop_back() << endl;
//	//best_list::IterList<int> it = lis.begin();
//	//lis.erase(it);
//	//lis.push_back(12);
//	//lis.push_back(455);	
//	//lis.erase(lis.end());
//	//cout << lis.pop_back();
//
//	best_list::List<sf::Vector2i> chekpoint;
//	for (int i = 128; i < 256; i+= 32)
//	{
//		chekpoint.push_back(sf::Vector2i(i + 23, 3243 - i));
//	}
////	auto dd = chekpoint.begin();
//	auto prob = chekpoint;
//	chekpoint = prob;
//	auto dd = prob.begin();
//	for (dd ;  dd!= prob.end();)
//	{
//
//		sf::Vector2i vec = (*dd);
//		cout << "{" << vec.x << "|" << vec.y << "}" << endl;
//		auto d  = dd;
//		++dd;
//		prob.erase(d);
//		
//	}
//
//	chekpoint.clear();
//	cout << chekpoint.size();
//	return 0;
//}