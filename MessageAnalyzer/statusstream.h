#pragma once

#include"StringConversion.h"

class statusstream
{
private:

	QStatusBar* status;


public:

	statusstream(QStatusBar* s) :status(s) {}
	statusstream(const statusstream& right) :status(right.status) {}

	statusstream& operator<<(statusstream& (*op)(statusstream&))
	{
		return (*op)(*this);
	}

	template<typename T>
	statusstream& operator<<(const T & right)
	{
		status->showMessage(toQStr(right));
		return *this;
	}

	//Çå¿Õ

	friend statusstream& endl(statusstream & ss)
	{
	ss.status->clearMessage();
	return ss;
}
};

//inline statusstream& endl(statusstream& ss)
