#include "stdafx.h"

#include "MessageAnalyzer.h"

MessageAnalyzer::MessageAnalyzer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);



	//�趨��ʼֵ��������

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


	//��ȡ�ļ���
	QString FilePath = ui.lineEdit->text();




	//���ļ���ע�⣺ʹ��ANSI��ǰ�漸��ɾ��
	wifstream in;

	try {
		in = OpenInFile(FilePath.toStdString());
	}
	catch (runtime_error err) {
		ui.textEdit->setText(err.what());
		return;
	}

	//��������Ϣ
	textout << "Time : " << GetStrTime() << endl
		<< Rule << endl
		<< "MaxLength = " << MaxLength << endl
		<< "WordNumber = " << WordNumber[0] << endl
		<< "LimitCount = " << LimitCount[0] << endl
		<< "LimitPrintNumber = " << LimitPrintNumber << endl
		<< "TextType : " << typeid(TextType).name() << endl
		<< "FilePath : " << FilePath << endl;



	//��ȡ�ļ�


	statusout << "���ڶ�ȡ��Ϣ��¼����";

	Frequency<TextType> f(WordNumber, LimitCount, in);

	
	in.close();


	//out << _T("��Ϣ������") << size(vecText) << endl;
	textout << "TextNum : " << f.vecMsg.size() << endl
		<< "CharNum : " << f.charNum << endl;

	//for (auto m : vecText) wcout << m.name <<'|' << endl;






	//ͳ��Ƶ��




	vector<pair<wstring, int>> vecF;
	for (int i = 1; i <= MaxLength; ++i) {


		statusout << toQStr("����ͳ�Ƴ���Ƶ�ʽϸߵ�") + toQStr(i) + toQStr("�ִʡ���");


		f.GetFPeak(vecF,  i);

		if (!vecF.empty()) {


			textout << Rule << endl
				<< _T("����Ƶ�ʽϸߵ�") << i << _T("�ִʣ�") << endl << endl;

			int PrintNumber = 0;

			for (auto p : vecF) {

				//�����жϣ�����������ַ���

				wstring str = p.first;
				if (isUseless(str)) continue;

				//����ѭ��������
				if (PrintNumber <= LimitPrintNumber) {
					++PrintNumber;

					double count = p.second;


					textout << str << '\t' << count << '\t'
						<< toQStr(count * 1000 / f.charNum, 'f', 3) << "��" << endl;

				}
				else
					break;

			}
		}
		else {


			textout << "�Ҳ���Ƶ�ʽϸߵ�" << i << "�ִʣ�" << endl;

			break;
		}





		statusout << TimingEnd();

	}



	//out = OpenOutFile(WorkingPath, FilePath.toStdString());
	//out.close();


}

