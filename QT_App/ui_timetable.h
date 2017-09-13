/********************************************************************************
** Form generated from reading UI file 'timetable.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMETABLE_H
#define UI_TIMETABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Timetable
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QGroupBox *groupBox_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Timetable)
    {
        if (Timetable->objectName().isEmpty())
            Timetable->setObjectName(QStringLiteral("Timetable"));
        Timetable->resize(800, 480);
        centralWidget = new QWidget(Timetable);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 41, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(280, 0, 71, 16));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(60, 0, 211, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lineEdit->setFont(font);
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(330, 0, 201, 20));
        lineEdit_2->setFont(font);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(580, 0, 201, 21));
        QFont font1;
        font1.setItalic(true);
        label_3->setFont(font1);

        verticalLayout->addWidget(groupBox);

        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(false);
        font2.setWeight(50);
        tableWidget->setFont(font2);
        tableWidget->setStyleSheet(QStringLiteral(""));
        tableWidget->setTextElideMode(Qt::ElideMiddle);

        verticalLayout->addWidget(tableWidget);

        tableWidget_2 = new QTableWidget(centralWidget);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setFont(font2);

        verticalLayout->addWidget(tableWidget_2);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 0, 101, 31));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 0, 101, 31));

        verticalLayout->addWidget(groupBox_2);

        Timetable->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Timetable);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 27));
        Timetable->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Timetable);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Timetable->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Timetable);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Timetable->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEdit);
        label_2->setBuddy(lineEdit_2);
#endif // QT_NO_SHORTCUT

        retranslateUi(Timetable);

        QMetaObject::connectSlotsByName(Timetable);
    } // setupUi

    void retranslateUi(QMainWindow *Timetable)
    {
        Timetable->setWindowTitle(QApplication::translate("Timetable", "Timetable", 0));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Timetable", "Date:", 0));
        label_2->setText(QApplication::translate("Timetable", "Room:", 0));
        lineEdit->setText(QApplication::translate("Timetable", "06/09/2017", 0));
        lineEdit_2->setText(QApplication::translate("Timetable", "08-06-02", 0));
        label_3->setText(QString());
        groupBox_2->setTitle(QString());
        pushButton->setText(QApplication::translate("Timetable", "Back", 0));
        pushButton_2->setText(QApplication::translate("Timetable", "Next", 0));
    } // retranslateUi

};

namespace Ui {
    class Timetable: public Ui_Timetable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMETABLE_H
