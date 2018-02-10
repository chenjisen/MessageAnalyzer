#include "stdafx.h"

#include "MessageAnalyzer.h"

MessageAnalyzer::MessageAnalyzer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);



	//设定初始值，测试用

	ui.lineEdit->setText(QString(R"(D:\WordCounter\testR_fornewtest.txt)"));

}



void MessageAnalyzer::buttonClicked()
{
	const QString Rule = "\n-------------------------------------------\n";

	const unsigned int MaxLength = 5;
	const vector<unsigned int> WordNumber(MaxLength + 1, 1000);
	const vector<int> LimitCount(MaxLength + 1, 4);

	const int LimitPrintNumber = 100;

	//const unsigned int MaxSize = UINT_MAX;
	//const unsigned int MaxSize = 1000;

	typedef Message TextType;

	//const string WorkingPath = "d:\\WordCounter\\";

	TimingBegin();



	textstream textout(ui.textEdit);
	statusstream statusout(ui.statusBar);


	//读取文件名
	QString FilePath = ui.lineEdit->text();




	//打开文件，注意：使用ANSI；前面几行删掉
	wifstream in;

	try {
		in = OpenInFile(FilePath.toStdString());
	}
	catch (runtime_error err) {
		ui.textEdit->setText(err.what());
		return;
	}

	//输出相关信息
	textout << "Time : " << GetStrTime() << endl
		<< Rule << endl
		<< "MaxLength = " << MaxLength << endl
		<< "WordNumber = " << WordNumber[0] << endl
		<< "LimitCount = " << LimitCount[0] << endl
		<< "LimitPrintNumber = " << LimitPrintNumber << endl
		<< "TextType : " << typeid(TextType).name() << endl
		<< "FilePath : " << FilePath << endl;



	//读取文件


	statusout << "正在读取消息记录……";

	Frequency<TextType> f(WordNumber, LimitCount, in);

	
	in.close();


	//out << _T("消息数量：") << size(vecText) << endl;
	textout << "TextNum : " << f.vecMsg.size() << endl
		<< "CharNum : " << f.charNum << endl;

	//for (auto m : vecText) wcout << m.name <<'|' << endl;






	//统计频率




	vector<pair<wstring, int>> vecF;
	for (int i = 1; i <= MaxLength; ++i) {


		statusout << toQStr("正在统计出现频率较高的") + toQStr(i) + toQStr("字词……");


		f.GetFPeak(vecF,  i);

		if (!vecF.empty()) {


			textout << Rule << endl
				<< _T("出现频率较高的") << i << _T("字词：") << endl << endl;

			int PrintNumber = 0;

			for (auto p : vecF) {

				//符号判断，不输出无用字符串

				wstring str = p.first;
				if (isUseless(str)) continue;

				//继续循环的条件
				if (PrintNumber <= LimitPrintNumber) {
					++PrintNumber;

					double count = p.second;


					textout << str << '\t' << count << '\t'
						<< toQStr(count * 1000 / f.charNum, 'f', 3) << "‰" << endl;

				}
				else
					break;

			}
		}
		else {


			textout << "找不到频率较高的" << i << "字词！" << endl;

			break;
		}





		statusout << TimingEnd();

	}



	//out = OpenOutFile(WorkingPath, FilePath.toStdString());
	//out.close();


}

