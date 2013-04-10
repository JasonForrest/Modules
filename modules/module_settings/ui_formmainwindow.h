/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 31. Mar 22:29:13 2013
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMMAINWINDOW_H
#define UI_FORMMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormMainWindow
{
public:
    QAction *actionNew;
    QAction *actionSaveAs;
    QAction *actionExit;
    QAction *actionSave;
    QAction *actionOpen;
    QWidget *centralWidget;
    QGridLayout *centralLayout;
    QWidget *mainWidget;
    QGridLayout *mainWidgetLayout;
    QGridLayout *mainWidgetWorkPlaceLayout;
    QScrollArea *workPlaceScrollArea;
    QWidget *workPlaceScrollAreaWidget;
    QMenuBar *mainMenuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *mainStatusBar;

    void setupUi(QMainWindow *FormMainWindow)
    {
        if (FormMainWindow->objectName().isEmpty())
            FormMainWindow->setObjectName(QStringLiteral("FormMainWindow"));
        FormMainWindow->resize(886, 674);
        actionNew = new QAction(FormMainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionSaveAs = new QAction(FormMainWindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionExit = new QAction(FormMainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSave = new QAction(FormMainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setEnabled(true);
        actionOpen = new QAction(FormMainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpen->setEnabled(true);
        centralWidget = new QWidget(FormMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralLayout = new QGridLayout(centralWidget);
        centralLayout->setSpacing(6);
        centralLayout->setContentsMargins(11, 11, 11, 11);
        centralLayout->setObjectName(QStringLiteral("centralLayout"));
        mainWidget = new QWidget(centralWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidgetLayout = new QGridLayout(mainWidget);
        mainWidgetLayout->setSpacing(6);
        mainWidgetLayout->setContentsMargins(11, 11, 11, 11);
        mainWidgetLayout->setObjectName(QStringLiteral("mainWidgetLayout"));
        mainWidgetWorkPlaceLayout = new QGridLayout();
        mainWidgetWorkPlaceLayout->setSpacing(6);
        mainWidgetWorkPlaceLayout->setObjectName(QStringLiteral("mainWidgetWorkPlaceLayout"));
        workPlaceScrollArea = new QScrollArea(mainWidget);
        workPlaceScrollArea->setObjectName(QStringLiteral("workPlaceScrollArea"));
        workPlaceScrollArea->setWidgetResizable(false);
        workPlaceScrollAreaWidget = new QWidget();
        workPlaceScrollAreaWidget->setObjectName(QStringLiteral("workPlaceScrollAreaWidget"));
        workPlaceScrollAreaWidget->setGeometry(QRect(0, 0, 256, 256));
        workPlaceScrollArea->setWidget(workPlaceScrollAreaWidget);

        mainWidgetWorkPlaceLayout->addWidget(workPlaceScrollArea, 0, 0, 1, 1);


        mainWidgetLayout->addLayout(mainWidgetWorkPlaceLayout, 0, 0, 1, 1);


        centralLayout->addWidget(mainWidget, 0, 0, 1, 1);

        FormMainWindow->setCentralWidget(centralWidget);
        mainMenuBar = new QMenuBar(FormMainWindow);
        mainMenuBar->setObjectName(QStringLiteral("mainMenuBar"));
        mainMenuBar->setGeometry(QRect(0, 0, 886, 21));
        menuFile = new QMenu(mainMenuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        FormMainWindow->setMenuBar(mainMenuBar);
        mainToolBar = new QToolBar(FormMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FormMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        mainStatusBar = new QStatusBar(FormMainWindow);
        mainStatusBar->setObjectName(QStringLiteral("mainStatusBar"));
        FormMainWindow->setStatusBar(mainStatusBar);

        mainMenuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(FormMainWindow);

        QMetaObject::connectSlotsByName(FormMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FormMainWindow)
    {
        FormMainWindow->setWindowTitle(QApplication::translate("FormMainWindow", "MainWindow", 0));
        actionNew->setText(QApplication::translate("FormMainWindow", "New...", 0));
        actionSaveAs->setText(QApplication::translate("FormMainWindow", "Save as...", 0));
        actionExit->setText(QApplication::translate("FormMainWindow", "Exit", 0));
        actionSave->setText(QApplication::translate("FormMainWindow", "Save", 0));
        actionOpen->setText(QApplication::translate("FormMainWindow", "Open...", 0));
        menuFile->setTitle(QApplication::translate("FormMainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class FormMainWindow: public Ui_FormMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMMAINWINDOW_H
