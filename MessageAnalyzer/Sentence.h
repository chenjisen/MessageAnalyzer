#pragma once



using std::wstring;
using std::vector;
using std::wifstream;

class Sentence
{
public:
	wstring text;

	static pair<vector<Sentence>,int> GetVec(wifstream& in, unsigned int MaxSize = UINT_MAX);

protected:
	void GetText(const wstring& str);

private:


	void clear();

};


