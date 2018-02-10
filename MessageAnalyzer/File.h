#pragma once

using std::locale;
using std::runtime_error;
using std::wofstream;



inline wifstream OpenInFile(const string& FilePath)
{


	string strInFilePath = FilePath;
	wifstream file(strInFilePath.c_str());
	if (!file)
		throw runtime_error("Open in file error!");
	file.imbue(locale("chs"));

	return file;
}

inline wofstream OpenOutFile(const string& WorkingPath, const string& FileName)
{

	string strOutFilePath;// = WorkingPath + FileName + string("_Outcome.txt");
	wofstream file(strOutFilePath.c_str());
	if (!file)
		throw runtime_error("Open out file error!");
	file.imbue(locale("chs"));
	return file;
}