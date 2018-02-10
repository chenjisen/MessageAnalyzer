#pragma once

using std::string;

inline QString toQStr(const string & right) { return QString::fromStdString(right); }

inline QString toQStr(const QString & right) { return right; }

inline QString toQStr(const wstring & right) { return QString::fromStdWString(right); }

inline QString toQStr(const wchar_t * right) { return QString::fromWCharArray(right); }

inline QString toQStr(const char* right) { return QString::fromLocal8Bit(right); }

inline QString toQStr(char right) { return QString(right); }




inline QString toQStr(size_t right) { return QString::number(right); }

inline QString toQStr(int right) { return QString::number(right); }

inline QString toQStr(unsigned int right) { return QString::number(right); }

inline QString toQStr(double right, char f = 'g', int prec = 6) { return QString::number(right, f, prec); }



inline wstring toWStr(const string &str)
{
	wstring wstr(str.length(), L' ');
	int nLen = (int)str.length();
	int nResult = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)str.c_str(),
		nLen, (LPWSTR)wstr.c_str(), nLen);
	return wstr;
}

inline wstring toWStr(const QString& str)
{
	return toWStr(str.toStdString());
}

