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
	wstring str; //Ĭ��Ϊ��
	int charNum = 0;

	while (getline(in, str)) {


		//�жϽ�������

		sent.GetText(str);

		//�����ַ�����������
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


