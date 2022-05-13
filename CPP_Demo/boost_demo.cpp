#pragma once
#include <boost/lexical_cast.hpp>     
#include <iostream>   

using namespace std;
using namespace boost;

int main_boost_demo() {

	double a = lexical_cast<double>("3.1415926");
	string str = lexical_cast<string>("3.1415926");
	cout << "This is a number: " << a << endl;
	cout << "This is a string: " << str << endl;
	int b = 0;
	try {
		b = lexical_cast<int>("neo");
	}
	catch (bad_lexical_cast& e) {
		cout << e.what() << endl;
	}

	return 0;
}
