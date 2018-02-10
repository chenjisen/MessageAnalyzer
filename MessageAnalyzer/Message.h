#pragma once

#include"Sentence.h"

using std::wstring;
using std::vector;
using std::wifstream;


class Message:public Sentence
{

public:

	wstring day; //yyyy-mm-dd
	wstring time; //hh:mm:ss 
	wstring name;

	static pair<vector<Message>,int> GetVec(wifstream& in, unsigned int MaxSize = UINT_MAX);

private:

	void GetInfo(const wstring& str);
	static bool isInfo(const wstring& str);

	void clear();
};
