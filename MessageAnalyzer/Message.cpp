#include "stdafx.h"

#include<iostream>

using std::runtime_error;
using std::wcin;
using std::wcout;
using std::cout;
using std::endl;
using std::make_pair;

void Message::GetInfo(const wstring& str)
{
	wstring s = str;
	if (s[0] != _T('2'))
		throw runtime_error("Day error!");
	else {
		//处理时间格式问题 (h)h:mm:ss
		if (s[12] == _T(':'))
			s.insert(11, _T("0"));

		day.assign(s, 0, 10);
		bool isDay = day[4] == _T('-') && day[7] == _T('-');
		time.assign(s, 11, 8);
		bool isTime = time[2] == _T(':') && time[5] == _T(':');
		name.assign(s, 20, s.length() - 20);

		if (!isDay || !isTime)
			throw runtime_error("Info error!");
	}

}



void Message::clear()
{
	day.clear();
	time.clear();
	name.clear();
	text.clear();
}

bool Message::isInfo(const wstring& str)
{
	wstring s = str;
	if (s.length() <= 19 || s[0] != _T('2')) {
		return false;
	}
	else {
		//处理时间格式问题 (h)h:mm:ss
		if (s[12] == _T(':'))
			s.insert(11, _T("0"));
		wstring day, time, name;
		day.assign(s, 0, 10);
		bool isDay = day[4] == _T('-') && day[7] == _T('-');
		time.assign(s, 11, 8);
		bool isTime = time[2] == _T(':') && time[5] == _T(':');
		return isDay && isTime;
	}
}

pair<vector<Message>,int> Message::GetVec(wifstream& in, unsigned int MaxSize)
{

	vector<Message> vecMsg;
	Message m;
	wstring text, state, str; //默认为空
	int charNum = 0;
							  //第一条消息
	do
		if (!getline(in, str)) return make_pair(vecMsg, charNum);
	while (!Message::isInfo(str));


	while (true) {
		m.clear();

		//获得时间、昵称，如：yyyy-mm-dd (h)h:mm:ss 甲
		try {
			m.GetInfo(str);
		}
		catch (runtime_error err) {
			cout << err.what();
			wcout << str << endl << m.day << endl << m.time << endl
				<< m.name << endl << m.text << endl;
			system("pause");
		}

		//判断是否达到最大数量
		if (vecMsg.size() >= MaxSize)
			return make_pair(vecMsg, charNum);

		//输出状态
		if (m.day != state) {
			state = m.day;
			wcout << state << endl;
		}

		//读取消息文本
		str.clear();
		do {
			text += str;
			//读取字符串，循环结束条件
			if (!getline(in, str)) {
				m.GetText(text);
				charNum += text.length();
				vecMsg.push_back(m);
				return make_pair(vecMsg, charNum);
			}
		} while (!Message::isInfo(str));

		//获得消息文本
		m.GetText(text);
		charNum += text.length();

		if (m.name != wstring(L"毅芳")) //这行是临时代码，按照name来过滤
			vecMsg.push_back(m);


		text.clear();

	}
	return make_pair(vecMsg, charNum);
}

