#include "stdafx.h"

using std::min;

template<class T>
bool CmpPair(const pair<T, int>& left, const pair<T, int>& right)
{
	return left.second > right.second;
}

template<class T>
void SortTop(vector<pair<T, int>>& vec, const unsigned int n)
{
	unsigned int mapsize = min(n, (unsigned int)vec.size());
	partial_sort(vec.begin(), vec.begin() + mapsize, vec.end(), CmpPair<T>);
	vec.resize(mapsize);
}

vector<pair<wstring, int>> SortMap(const map<wstring, int>& m)
{
	vector<pair<wstring, int>> vp;
	for (auto p : m) {
		vp.push_back(p);
	}
	sort(vp.begin(), vp.end(), CmpPair<wstring>);
	return vp;
}

vector<pair<wstring, int>> SortTopMap(const map<wstring, int>& m, const unsigned int n)
{
	vector<pair<wstring, int>> vp;
	vp.reserve(m.size());
	for (auto p : m) {
		vp.push_back(p);
	}
	SortTop(vp, n);
	return vp;
}

map<wstring, int> VecToMapNo(const vector<pair<wchar_t, int>>& vec)
{
	map<wstring, int> m;
	for (auto iterP = vec.begin(); iterP != vec.end(); ++iterP) {
		m.insert(make_pair(wstring({ iterP->first }), iterP - vec.begin()));
	}
	return m;
}

map<wstring, int> VecToMapNo(const vector<pair<wstring, int>>& vec)
{
	map<wstring, int> m;
	for (auto iterP = vec.begin(); iterP != vec.end(); ++iterP) {
		m.insert(make_pair(iterP->first, iterP - vec.begin()));
	}
	return m;
}

bool isUseless(wchar_t ch)
{

	if (ch == _T('£¬') || ch == _T('¡¡') || ch == _T(' ') 
		|| ch == L'-' || ch == L'¡£') 
		return true;

	return false;
}

bool isUseless(wstring str)
{
	for (wchar_t ch : str) {
		if (isUseless(ch))
			return true;
	}
	return false;
}



