#include "stdafx.h"

void Sentence::GetText(const wstring & str)
{
	text = str;
}

void Sentence::clear()
{
	text.clear();
}

pair<vector<Sentence>, int>  Sentence::GetVec(wifstream& in, unsigned int MaxSize)
{

	vector<Sentence> vecSent;
	Sentence sent;
	wstring str; //默认为空
	int charNum = 0;

	while (getline(in, str)) {


		//判断结束数量

		sent.GetText(str);

		//无用字符不计入字数
		for (wchar_t ch : str) {
			if (!isUseless(ch))
				++charNum;
		}

		vecSent.push_back(sent);

		if (vecSent.size() >= MaxSize)
			return make_pair(vecSent, charNum);
	}

	return make_pair(vecSent, charNum);
}


