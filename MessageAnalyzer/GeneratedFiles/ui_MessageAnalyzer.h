/********************************************************************************
** Form generated from reading UI file 'MessageAnalyzer.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEANALYZER_H
#define UI_MESSAGEANALYZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageAnalyzerClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MessageAnalyzerClass)
    {
        if (MessageAnalyzerClass->objectName().isEmpty())
            MessageAnalyzerClass->setObjectName(QStringLiteral("MessageAnalyzerClass"));
        MessageAnalyzerClass->resize(600, 400);
        centralWidget = new QWidget(MessageAnalyzerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 54, 12));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 10, 113, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 10, 75, 23));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 40, 301, 301));
        MessageAnalyzerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MessageAnalyzerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        MessageAnalyzerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MessageAnalyzerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MessageAnalyzerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MessageAnalyzerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MessageAnalyzerClass->setStatusBar(statusBar);

        retranslateUi(MessageAnalyzerClass);
        QObject::connect(pushButton, SIGNAL(clicked()), MessageAnalyzerClass, SLOT(buttonClicked()));

        QMetaObject::connectSlotsByName(MessageAnalyzerClass);
    } // setupUi

    void retranslateUi(QMainWindow *MessageAnalyzerClass)
    {
        MessageAnalyzerClass->setWindowTitle(QApplication::translate("MessageAnalyzerClass", "MessageAnalyzer", nullptr));
        label->setText(QApplication::translate("MessageAnalyzerClass", "TextLabel", nullptr));
        pushButton->setText(QApplication::translate("MessageAnalyzerClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessageAnalyzerClass: public Ui_MessageAnalyzerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEANALYZER_H
