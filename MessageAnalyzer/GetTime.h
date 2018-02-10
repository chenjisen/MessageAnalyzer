#pragma once

#include <ctime>

#include"StringConversion.h"

static double timer;



inline void TimingBegin()
{
	timer = clock(); 
}

inline QString TimingEnd()
{
	
	return(toQStr("”√ ±")+ toQStr( (clock() - timer) / (double)CLOCKS_PER_SEC )+ toQStr( "√Î"));
}



inline QString GetStrTime()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	QString strMinute = toQStr(sys.wMinute),
		strSecond = toQStr(sys.wSecond);

	if (strMinute.length() == 1) strMinute = L'0' + strMinute;
	if (strSecond.length() == 1) strSecond = L'0' + strSecond;


	return toQStr(sys.wYear) + toQStr('/')
		+ toQStr(sys.wMonth) + toQStr('/')
		+ toQStr(sys.wDay) + toQStr('\t')
		+ toQStr(sys.wHour) + toQStr(':')
		+ strMinute + toQStr(':')
		+ strSecond;
}