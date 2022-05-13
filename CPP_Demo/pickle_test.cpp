//  参考GitHub：https://github.com/Usama-Azad/Pickle-in-Cpp
#pragma once

#include<iostream>
#include <vector>
#include<array>
#include <string>
#include <windows.h>
#include <cassert>
#include"pickle.h"
using namespace std;

#include<iostream>
#include<array>
#include"pickle.h"
using namespace std;

int main_mean_dump()
{
	std::vector<float> mean_file_vector;// (550 * 3136);
	std::string file_path = "E:\\AIDeploy\\Env\\DemoData\\anomaly\\onnxs3\\features_mean.txt";
	std::ifstream meanFile;
	meanFile.open(file_path.data());   //将文件流对象与文件连接起来 
	assert(meanFile.is_open());   //若失败,则输出错误消息,并终止程序运行 
	std::string s;
	while (getline(meanFile, s))
	{
		mean_file_vector.push_back(std::stof(s));
	}
	meanFile.close();             //关闭文件输入流 
	auto myArray = new std::array<float, 550 * 3136>;
	myArray->at(0) = 1;

	for (long int i = 0; i < 550 * 3136; i++)
		myArray->at(i) = mean_file_vector[i];


	usa::Pickle pickle;

	pickle.dump("mean", *myArray);

	return 0;
}
int main_mean_load()
{

	static std::array<float, 550 * 3136> myNewArray;

	usa::Pickle pickle;

	pickle.load("mean", myNewArray);

	//for (auto i : myNewArray)
	//	cout << i << endl;

	return 0;
}

int main_std_dump()
{
	std::vector<float> std_file_vector;// (550 * 3136);
	std::string file_path = "E:\\AIDeploy\\Env\\DemoData\\anomaly\\onnxs3\\features_std.txt";
	std::ifstream stdFile;
	stdFile.open(file_path.data());   //将文件流对象与文件连接起来 
	assert(stdFile.is_open());   //若失败,则输出错误消息,并终止程序运行 
	std::string s;
	for (int i = 0; i < 3136; i++) {
		auto myArray = new std::array<float, 550 * 550>;
		for (int j = 0; j < 550 * 550; j++) {
			getline(stdFile, s);
			myArray->at(j) = std::stof(s);
		}
		usa::Pickle pickle;

		pickle.dump(std::to_string(i), *myArray);
	}
	return 0;
}
int main_std_load()
{

	static std::array<float, 550*550> myNewArray;

	usa::Pickle pickle;

	pickle.load("E:\\AIDeploy\\Env\\DemoData\\anomaly\\onnxs3\\std\\0", myNewArray);

	/*for (auto i : myNewArray)
		cout << i << endl;*/

	return 0;
}
