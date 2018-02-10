#pragma once


#include"StringConversion.h"

class textstream 
{
private:
	QTextEdit * text;

	QString buffer;




public:

	textstream(QTextEdit* t) :text(t) {}
	textstream(const textstream& right) :text(right.text) {}

	textstream& operator<<(textstream& (*op)(textstream&))
	{
		return (*op)(*this);
	}


	//ֱ��endl�����
	template<typename T>
	textstream& operator<<(const T & right)
	{
		buffer.append(toQStr(right));
		return *this;
	}

	friend textstream& endl(textstream & ts);
};

//���������
inline textstream& endl(textstream& ts)
{
	ts.text->append(ts.buffer);
	ts.buffer.clear();
	return ts;
}