/********************************************************************************
** Form generated from reading UI file 'newprojectdialog.ui'
**
** Created: Sun 14. Apr 20:17:36 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMNEWPROJECTDIALOG_H
#define UI_FORMNEWPROJECTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormNewProjectDialog
{
public:
    QGridLayout *dialogLayout;
    QVBoxLayout *centralWidget;
    QGridLayout *layoutPathToProjectFolder;
    QLineEdit *editPathToProjectFolder;
    QPushButton *buttonPathToProjectFolder;
    QLabel *labelPathToProjectFolder;
    QLabel *labelProjectName;
    QLineEdit *editProjectName;
    QLabel *labelProjectType;
    QComboBox *comboboxProjectType;
    QGridLayout *layoutSettings;
    QSpacerItem *horizontalSpacer_0;
    QComboBox *comboboxSceernSize;
    QLabel *labelScreenSize;
    QLabel *labelCurrentOS;
    QCheckBox *checkbox3DMode;
    QWidget *widgetScreenSizeByhand;
    QGridLayout *gridLayout;
    QLabel *labelScreenSizeHeight;
    QLabel *labelScreenSizeX;
    QCheckBox *checkboxScreenSizeByHand;
    QLabel *labelScreenSizeWidth;
    QSpacerItem *horizontalSpacer_1;
    QSpinBox *spinboxScreenSizeWidth;
    QSpinBox *spinboxScreenSizeHeight;
    QComboBox *comboboxCurrentOS;
    QHBoxLayout *layoutOkCancel;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;

    void setupUi(QDialog *FormNewProjectDialog)
    {
        if (FormNewProjectDialog->objectName().isEmpty())
            FormNewProjectDialog->setObjectName(QString::fromUtf8("FormNewProjectDialog"));
        FormNewProjectDialog->setWindowModality(Qt::WindowModal);
        FormNewProjectDialog->resize(420, 325);
        FormNewProjectDialog->setMinimumSize(QSize(420, 325));
        FormNewProjectDialog->setMaximumSize(QSize(420, 327));
        dialogLayout = new QGridLayout(FormNewProjectDialog);
        dialogLayout->setObjectName(QString::fromUtf8("dialogLayout"));
        centralWidget = new QVBoxLayout();
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutPathToProjectFolder = new QGridLayout();
        layoutPathToProjectFolder->setObjectName(QString::fromUtf8("layoutPathToProjectFolder"));
        editPathToProjectFolder = new QLineEdit(FormNewProjectDialog);
        editPathToProjectFolder->setObjectName(QString::fromUtf8("editPathToProjectFolder"));
        editPathToProjectFolder->setMaximumSize(QSize(290, 16777215));
        editPathToProjectFolder->setReadOnly(true);

        layoutPathToProjectFolder->addWidget(editPathToProjectFolder, 3, 0, 1, 1);

        buttonPathToProjectFolder = new QPushButton(FormNewProjectDialog);
        buttonPathToProjectFolder->setObjectName(QString::fromUtf8("buttonPathToProjectFolder"));

        layoutPathToProjectFolder->addWidget(buttonPathToProjectFolder, 3, 1, 1, 1);

        labelPathToProjectFolder = new QLabel(FormNewProjectDialog);
        labelPathToProjectFolder->setObjectName(QString::fromUtf8("labelPathToProjectFolder"));

        layoutPathToProjectFolder->addWidget(labelPathToProjectFolder, 2, 0, 1, 1);

        labelProjectName = new QLabel(FormNewProjectDialog);
        labelProjectName->setObjectName(QString::fromUtf8("labelProjectName"));

        layoutPathToProjectFolder->addWidget(labelProjectName, 0, 0, 1, 1);

        editProjectName = new QLineEdit(FormNewProjectDialog);
        editProjectName->setObjectName(QString::fromUtf8("editProjectName"));
        editProjectName->setMaximumSize(QSize(290, 16777215));

        layoutPathToProjectFolder->addWidget(editProjectName, 1, 0, 1, 1);

        labelProjectType = new QLabel(FormNewProjectDialog);
        labelProjectType->setObjectName(QString::fromUtf8("labelProjectType"));
        labelProjectType->setEnabled(true);

        layoutPathToProjectFolder->addWidget(labelProjectType, 0, 1, 1, 1);

        comboboxProjectType = new QComboBox(FormNewProjectDialog);
        comboboxProjectType->setObjectName(QString::fromUtf8("comboboxProjectType"));
        comboboxProjectType->setEnabled(false);
        comboboxProjectType->setMinimumSize(QSize(100, 0));

        layoutPathToProjectFolder->addWidget(comboboxProjectType, 1, 1, 1, 1);


        centralWidget->addLayout(layoutPathToProjectFolder);

        layoutSettings = new QGridLayout();
        layoutSettings->setObjectName(QString::fromUtf8("layoutSettings"));
        horizontalSpacer_0 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutSettings->addItem(horizontalSpacer_0, 2, 1, 1, 1);

        comboboxSceernSize = new QComboBox(FormNewProjectDialog);
        comboboxSceernSize->setObjectName(QString::fromUtf8("comboboxSceernSize"));

        layoutSettings->addWidget(comboboxSceernSize, 3, 0, 1, 1);

        labelScreenSize = new QLabel(FormNewProjectDialog);
        labelScreenSize->setObjectName(QString::fromUtf8("labelScreenSize"));

        layoutSettings->addWidget(labelScreenSize, 2, 0, 1, 1);

        labelCurrentOS = new QLabel(FormNewProjectDialog);
        labelCurrentOS->setObjectName(QString::fromUtf8("labelCurrentOS"));

        layoutSettings->addWidget(labelCurrentOS, 0, 0, 1, 1);

        checkbox3DMode = new QCheckBox(FormNewProjectDialog);
        checkbox3DMode->setObjectName(QString::fromUtf8("checkbox3DMode"));
        checkbox3DMode->setEnabled(false);

        layoutSettings->addWidget(checkbox3DMode, 5, 0, 1, 1);

        widgetScreenSizeByhand = new QWidget(FormNewProjectDialog);
        widgetScreenSizeByhand->setObjectName(QString::fromUtf8("widgetScreenSizeByhand"));
        widgetScreenSizeByhand->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(widgetScreenSizeByhand);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(3);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelScreenSizeHeight = new QLabel(widgetScreenSizeByhand);
        labelScreenSizeHeight->setObjectName(QString::fromUtf8("labelScreenSizeHeight"));

        gridLayout->addWidget(labelScreenSizeHeight, 1, 3, 1, 1);

        labelScreenSizeX = new QLabel(widgetScreenSizeByhand);
        labelScreenSizeX->setObjectName(QString::fromUtf8("labelScreenSizeX"));

        gridLayout->addWidget(labelScreenSizeX, 2, 2, 1, 1);

        checkboxScreenSizeByHand = new QCheckBox(widgetScreenSizeByhand);
        checkboxScreenSizeByHand->setObjectName(QString::fromUtf8("checkboxScreenSizeByHand"));

        gridLayout->addWidget(checkboxScreenSizeByHand, 0, 0, 1, 1);

        labelScreenSizeWidth = new QLabel(widgetScreenSizeByhand);
        labelScreenSizeWidth->setObjectName(QString::fromUtf8("labelScreenSizeWidth"));

        gridLayout->addWidget(labelScreenSizeWidth, 1, 0, 1, 1);

        horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_1, 1, 5, 1, 1);

        spinboxScreenSizeWidth = new QSpinBox(widgetScreenSizeByhand);
        spinboxScreenSizeWidth->setObjectName(QString::fromUtf8("spinboxScreenSizeWidth"));
        spinboxScreenSizeWidth->setEnabled(false);
        spinboxScreenSizeWidth->setMinimumSize(QSize(50, 0));
        spinboxScreenSizeWidth->setMaximumSize(QSize(50, 16777215));
        spinboxScreenSizeWidth->setMinimum(320);
        spinboxScreenSizeWidth->setMaximum(2048);
        spinboxScreenSizeWidth->setValue(320);

        gridLayout->addWidget(spinboxScreenSizeWidth, 2, 0, 1, 1);

        spinboxScreenSizeHeight = new QSpinBox(widgetScreenSizeByhand);
        spinboxScreenSizeHeight->setObjectName(QString::fromUtf8("spinboxScreenSizeHeight"));
        spinboxScreenSizeHeight->setEnabled(false);
        spinboxScreenSizeHeight->setMinimumSize(QSize(50, 0));
        spinboxScreenSizeHeight->setMaximumSize(QSize(50, 16777215));
        spinboxScreenSizeHeight->setMinimum(240);
        spinboxScreenSizeHeight->setMaximum(1536);

        gridLayout->addWidget(spinboxScreenSizeHeight, 2, 3, 1, 1);


        layoutSettings->addWidget(widgetScreenSizeByhand, 4, 0, 1, 1);

        comboboxCurrentOS = new QComboBox(FormNewProjectDialog);
        comboboxCurrentOS->setObjectName(QString::fromUtf8("comboboxCurrentOS"));

        layoutSettings->addWidget(comboboxCurrentOS, 1, 0, 1, 1);


        centralWidget->addLayout(layoutSettings);

        layoutOkCancel = new QHBoxLayout();
        layoutOkCancel->setObjectName(QString::fromUtf8("layoutOkCancel"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutOkCancel->addItem(horizontalSpacer);

        buttonOk = new QPushButton(FormNewProjectDialog);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));

        layoutOkCancel->addWidget(buttonOk);

        buttonCancel = new QPushButton(FormNewProjectDialog);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));

        layoutOkCancel->addWidget(buttonCancel);


        centralWidget->addLayout(layoutOkCancel);


        dialogLayout->addLayout(centralWidget, 0, 0, 1, 1);


        retranslateUi(FormNewProjectDialog);

        QMetaObject::connectSlotsByName(FormNewProjectDialog);
    } // setupUi

    void retranslateUi(QDialog *FormNewProjectDialog)
    {
        FormNewProjectDialog->setWindowTitle(QApplication::translate("FormNewProjectDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        buttonPathToProjectFolder->setText(QApplication::translate("FormNewProjectDialog", "Folder...", 0, QApplication::UnicodeUTF8));
        labelPathToProjectFolder->setText(QApplication::translate("FormNewProjectDialog", "Path to project folder:", 0, QApplication::UnicodeUTF8));
        labelProjectName->setText(QApplication::translate("FormNewProjectDialog", "Project name:", 0, QApplication::UnicodeUTF8));
        labelProjectType->setText(QApplication::translate("FormNewProjectDialog", "Project type:", 0, QApplication::UnicodeUTF8));
        labelScreenSize->setText(QApplication::translate("FormNewProjectDialog", "Screen size:", 0, QApplication::UnicodeUTF8));
        labelCurrentOS->setText(QApplication::translate("FormNewProjectDialog", "Current OS:", 0, QApplication::UnicodeUTF8));
        checkbox3DMode->setText(QApplication::translate("FormNewProjectDialog", "3D", 0, QApplication::UnicodeUTF8));
        labelScreenSizeHeight->setText(QApplication::translate("FormNewProjectDialog", "Height", 0, QApplication::UnicodeUTF8));
        labelScreenSizeX->setText(QApplication::translate("FormNewProjectDialog", "x", 0, QApplication::UnicodeUTF8));
        checkboxScreenSizeByHand->setText(QApplication::translate("FormNewProjectDialog", "Other", 0, QApplication::UnicodeUTF8));
        labelScreenSizeWidth->setText(QApplication::translate("FormNewProjectDialog", "Width", 0, QApplication::UnicodeUTF8));
        buttonOk->setText(QApplication::translate("FormNewProjectDialog", "Ok", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("FormNewProjectDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FormNewProjectDialog: public Ui_FormNewProjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMNEWPROJECTDIALOG_H
