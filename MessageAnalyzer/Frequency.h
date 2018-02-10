#pragma once

using std::vector;
using std::map;
using std::pair;
using std::wstring;
using std::wifstream;
using std::move;

template<class T>
bool CmpPair(const pair<T, int>& left, const pair<T, int>& right);
template<class T>
void SortTop(vector<pair<T, int>>& vec, const unsigned int n);
vector<pair<wstring, int>> SortMap(const map<wstring, int>& m);
vector<pair<wstring, int>> SortTopMap(const map<wstring, int>& m, const unsigned int n);
map<wstring, int> VecToMapNo(const vector<pair<wchar_t, int>>& vec);
map<wstring, int> VecToMapNo(const vector<pair<wstring, int>>& vec);
bool isUseless(wchar_t ch);
bool isUseless(wstring str);

template<typename T>
class Frequency
{

private:

	enum WordSide { Left, Right };

	//static const

	vector<unsigned int> WordNumber;
	vector<int> vecLimitCount;

	vector<pair<wstring, int>> Count(const map<wstring, int>& FPeakShort, unsigned int length);
	vector<pair<wstring, int>> ChCount(unsigned int length);

	vector<pair<int, int>> ANSICount();

public:

	vector<T> vecMsg;	//vector of messages

	int charNum;

	Frequency(const vector<unsigned int>& wn, const vector<int>& vlc, wifstream& in)
		:WordNumber(wn), vecLimitCount(vlc)
	{
		pair<vector<T>,int>& temp=T::GetVec(in);
		charNum = temp.second;
		vecMsg = move(temp.first);
	}


	void GetFPeak(vector<pair<wstring, int>>& vecFPeak, int length)
	{
		map<wstring, int> FPeakShort = VecToMapNo(vecFPeak);
		if (length == 1)
			vecFPeak = ChCount(length);
		else 
			vecFPeak = Count(FPeakShort, length);
	}

};



template<class T>
vector<pair<wstring, int>> Frequency<T>::Count(const map<wstring, int>& FPeakShort, unsigned int length)
{

	const unsigned int shortLength = length - 1;
	vector<map<wchar_t, int>> mapCount[2];
	mapCount[Left].resize(WordNumber[shortLength]);
	mapCount[Right].resize(WordNumber[shortLength]);

	int LimitCount = vecLimitCount[length];

	for (auto m : vecMsg) {
		wstring text = m.text;
		if (text.length() >= length) {

			for (auto ch_iter = text.begin();
				ch_iter != text.end() - shortLength + 1;
				++ch_iter) {
				int pos = ch_iter - text.begin();
				auto findShort = FPeakShort.find(text.substr(pos, shortLength));
				if (findShort != FPeakShort.end()) {  //找到高频字
													  //防止越界			
					if (ch_iter >= text.begin() + 1)
						++(mapCount[Left][findShort->second])[*(ch_iter - 1)];
					if (ch_iter <= text.end() - 1 - shortLength)
						++(mapCount[Right][findShort->second])[*(ch_iter + shortLength)];
				}
			}

		}

	}

	map<wstring, int> mapFPeakLong;
	for (auto chPair : FPeakShort) {
		for (WordSide side : {Left, Right}) {
			for (auto chSidePair : mapCount[side][chPair.second]) {
				if (chSidePair.second > LimitCount) {
					wstring longString;
					if (side == Left)
						longString = wstring({ chSidePair.first }) + chPair.first;
					else
						longString = chPair.first + wstring({ chSidePair.first });

					mapFPeakLong.insert(make_pair(longString, chSidePair.second));
				}
			}
		}
	}

	return SortTopMap(mapFPeakLong, WordNumber[length]);

}

template<class T>
vector<pair<wstring, int>> Frequency<T>::ChCount(unsigned int length)
{
	vector<int> vecF(65535);
	vector<pair<wstring, int>> vecFPeak;
	vecFPeak.reserve(WordNumber[1]);
	int LimitCount = vecLimitCount[length];

	for (auto m : vecMsg) {
		for (wchar_t ch : m.text) {
			++vecF[(int)ch];  //用map的时间是用vector的2~3倍
		}
	}

	for (size_t i = 0; i < vecF.size(); ++i) {
		if (vecF[i] > LimitCount) {   //提高效率
			vecFPeak.push_back(make_pair(wstring({ (wchar_t)i }), vecF[i]));
		}
	}

	SortTop(vecFPeak, WordNumber[1]);
	return vecFPeak;
}

template<class T>
vector<pair<int, int>> Frequency<T>::ANSICount()
{
	vector<int> vecF(65535);
	vector<pair<int, int>> vecFPeak;
	vecFPeak.reserve(65535);

	for (auto m : vecMsg) {
		for (wchar_t ch : m.text) {
			++vecF[(int)ch];
		}
	}

	for (size_t i = 0; i < vecF.size(); ++i) {
		if (vecF[i] > 0) {   //提高效率
			vecFPeak.push_back(make_pair(i, vecF[i]));
		}
	}

	return vecFPeak;
}