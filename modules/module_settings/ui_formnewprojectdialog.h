/********************************************************************************
** Form generated from reading UI file 'newprojectdialog.ui'
**
** Created: Tue 9. Apr 01:34:57 2013
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMNEWPROJECTDIALOG_H
#define UI_FORMNEWPROJECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
            FormNewProjectDialog->setObjectName(QStringLiteral("FormNewProjectDialog"));
        FormNewProjectDialog->setWindowModality(Qt::WindowModal);
        FormNewProjectDialog->resize(420, 325);
        FormNewProjectDialog->setMinimumSize(QSize(420, 325));
        FormNewProjectDialog->setMaximumSize(QSize(420, 327));
        dialogLayout = new QGridLayout(FormNewProjectDialog);
        dialogLayout->setObjectName(QStringLiteral("dialogLayout"));
        centralWidget = new QVBoxLayout();
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutPathToProjectFolder = new QGridLayout();
        layoutPathToProjectFolder->setObjectName(QStringLiteral("layoutPathToProjectFolder"));
        editPathToProjectFolder = new QLineEdit(FormNewProjectDialog);
        editPathToProjectFolder->setObjectName(QStringLiteral("editPathToProjectFolder"));
        editPathToProjectFolder->setMaximumSize(QSize(290, 16777215));
        editPathToProjectFolder->setReadOnly(true);

        layoutPathToProjectFolder->addWidget(editPathToProjectFolder, 3, 0, 1, 1);

        buttonPathToProjectFolder = new QPushButton(FormNewProjectDialog);
        buttonPathToProjectFolder->setObjectName(QStringLiteral("buttonPathToProjectFolder"));

        layoutPathToProjectFolder->addWidget(buttonPathToProjectFolder, 3, 1, 1, 1);

        labelPathToProjectFolder = new QLabel(FormNewProjectDialog);
        labelPathToProjectFolder->setObjectName(QStringLiteral("labelPathToProjectFolder"));

        layoutPathToProjectFolder->addWidget(labelPathToProjectFolder, 2, 0, 1, 1);

        labelProjectName = new QLabel(FormNewProjectDialog);
        labelProjectName->setObjectName(QStringLiteral("labelProjectName"));

        layoutPathToProjectFolder->addWidget(labelProjectName, 0, 0, 1, 1);

        editProjectName = new QLineEdit(FormNewProjectDialog);
        editProjectName->setObjectName(QStringLiteral("editProjectName"));
        editProjectName->setMaximumSize(QSize(290, 16777215));

        layoutPathToProjectFolder->addWidget(editProjectName, 1, 0, 1, 1);

        labelProjectType = new QLabel(FormNewProjectDialog);
        labelProjectType->setObjectName(QStringLiteral("labelProjectType"));
        labelProjectType->setEnabled(true);

        layoutPathToProjectFolder->addWidget(labelProjectType, 0, 1, 1, 1);

        comboboxProjectType = new QComboBox(FormNewProjectDialog);
        comboboxProjectType->setObjectName(QStringLiteral("comboboxProjectType"));
        comboboxProjectType->setEnabled(false);
        comboboxProjectType->setMinimumSize(QSize(100, 0));

        layoutPathToProjectFolder->addWidget(comboboxProjectType, 1, 1, 1, 1);


        centralWidget->addLayout(layoutPathToProjectFolder);

        layoutSettings = new QGridLayout();
        layoutSettings->setObjectName(QStringLiteral("layoutSettings"));
        horizontalSpacer_0 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutSettings->addItem(horizontalSpacer_0, 2, 1, 1, 1);

        comboboxSceernSize = new QComboBox(FormNewProjectDialog);
        comboboxSceernSize->setObjectName(QStringLiteral("comboboxSceernSize"));

        layoutSettings->addWidget(comboboxSceernSize, 3, 0, 1, 1);

        labelScreenSize = new QLabel(FormNewProjectDialog);
        labelScreenSize->setObjectName(QStringLiteral("labelScreenSize"));

        layoutSettings->addWidget(labelScreenSize, 2, 0, 1, 1);

        labelCurrentOS = new QLabel(FormNewProjectDialog);
        labelCurrentOS->setObjectName(QStringLiteral("labelCurrentOS"));

        layoutSettings->addWidget(labelCurrentOS, 0, 0, 1, 1);

        checkbox3DMode = new QCheckBox(FormNewProjectDialog);
        checkbox3DMode->setObjectName(QStringLiteral("checkbox3DMode"));
        checkbox3DMode->setEnabled(false);

        layoutSettings->addWidget(checkbox3DMode, 5, 0, 1, 1);

        widgetScreenSizeByhand = new QWidget(FormNewProjectDialog);
        widgetScreenSizeByhand->setObjectName(QStringLiteral("widgetScreenSizeByhand"));
        widgetScreenSizeByhand->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(widgetScreenSizeByhand);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(3);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelScreenSizeHeight = new QLabel(widgetScreenSizeByhand);
        labelScreenSizeHeight->setObjectName(QStringLiteral("labelScreenSizeHeight"));

        gridLayout->addWidget(labelScreenSizeHeight, 1, 3, 1, 1);

        labelScreenSizeX = new QLabel(widgetScreenSizeByhand);
        labelScreenSizeX->setObjectName(QStringLiteral("labelScreenSizeX"));

        gridLayout->addWidget(labelScreenSizeX, 2, 2, 1, 1);

        checkboxScreenSizeByHand = new QCheckBox(widgetScreenSizeByhand);
        checkboxScreenSizeByHand->setObjectName(QStringLiteral("checkboxScreenSizeByHand"));

        gridLayout->addWidget(checkboxScreenSizeByHand, 0, 0, 1, 1);

        labelScreenSizeWidth = new QLabel(widgetScreenSizeByhand);
        labelScreenSizeWidth->setObjectName(QStringLiteral("labelScreenSizeWidth"));

        gridLayout->addWidget(labelScreenSizeWidth, 1, 0, 1, 1);

        horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_1, 1, 5, 1, 1);

        spinboxScreenSizeWidth = new QSpinBox(widgetScreenSizeByhand);
        spinboxScreenSizeWidth->setObjectName(QStringLiteral("spinboxScreenSizeWidth"));
        spinboxScreenSizeWidth->setEnabled(false);
        spinboxScreenSizeWidth->setMinimumSize(QSize(50, 0));
        spinboxScreenSizeWidth->setMaximumSize(QSize(50, 16777215));
        spinboxScreenSizeWidth->setMinimum(320);
        spinboxScreenSizeWidth->setMaximum(2048);
        spinboxScreenSizeWidth->setValue(320);

        gridLayout->addWidget(spinboxScreenSizeWidth, 2, 0, 1, 1);

        spinboxScreenSizeHeight = new QSpinBox(widgetScreenSizeByhand);
        spinboxScreenSizeHeight->setObjectName(QStringLiteral("spinboxScreenSizeHeight"));
        spinboxScreenSizeHeight->setEnabled(false);
        spinboxScreenSizeHeight->setMinimumSize(QSize(50, 0));
        spinboxScreenSizeHeight->setMaximumSize(QSize(50, 16777215));
        spinboxScreenSizeHeight->setMinimum(240);
        spinboxScreenSizeHeight->setMaximum(1536);

        gridLayout->addWidget(spinboxScreenSizeHeight, 2, 3, 1, 1);


        layoutSettings->addWidget(widgetScreenSizeByhand, 4, 0, 1, 1);

        comboboxCurrentOS = new QComboBox(FormNewProjectDialog);
        comboboxCurrentOS->setObjectName(QStringLiteral("comboboxCurrentOS"));

        layoutSettings->addWidget(comboboxCurrentOS, 1, 0, 1, 1);


        centralWidget->addLayout(layoutSettings);

        layoutOkCancel = new QHBoxLayout();
        layoutOkCancel->setObjectName(QStringLiteral("layoutOkCancel"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutOkCancel->addItem(horizontalSpacer);

        buttonOk = new QPushButton(FormNewProjectDialog);
        buttonOk->setObjectName(QStringLiteral("buttonOk"));

        layoutOkCancel->addWidget(buttonOk);

        buttonCancel = new QPushButton(FormNewProjectDialog);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));

        layoutOkCancel->addWidget(buttonCancel);


        centralWidget->addLayout(layoutOkCancel);


        dialogLayout->addLayout(centralWidget, 0, 0, 1, 1);


        retranslateUi(FormNewProjectDialog);

        QMetaObject::connectSlotsByName(FormNewProjectDialog);
    } // setupUi

    void retranslateUi(QDialog *FormNewProjectDialog)
    {
        FormNewProjectDialog->setWindowTitle(QApplication::translate("FormNewProjectDialog", "Dialog", 0));
        buttonPathToProjectFolder->setText(QApplication::translate("FormNewProjectDialog", "Folder...", 0));
        labelPathToProjectFolder->setText(QApplication::translate("FormNewProjectDialog", "Path to project folder:", 0));
        labelProjectName->setText(QApplication::translate("FormNewProjectDialog", "Project name:", 0));
        labelProjectType->setText(QApplication::translate("FormNewProjectDialog", "Project type:", 0));
        labelScreenSize->setText(QApplication::translate("FormNewProjectDialog", "Screen size:", 0));
        labelCurrentOS->setText(QApplication::translate("FormNewProjectDialog", "Current OS:", 0));
        checkbox3DMode->setText(QApplication::translate("FormNewProjectDialog", "3D", 0));
        labelScreenSizeHeight->setText(QApplication::translate("FormNewProjectDialog", "Height", 0));
        labelScreenSizeX->setText(QApplication::translate("FormNewProjectDialog", "x", 0));
        checkboxScreenSizeByHand->setText(QApplication::translate("FormNewProjectDialog", "Other", 0));
        labelScreenSizeWidth->setText(QApplication::translate("FormNewProjectDialog", "Width", 0));
        buttonOk->setText(QApplication::translate("FormNewProjectDialog", "Ok", 0));
        buttonCancel->setText(QApplication::translate("FormNewProjectDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class FormNewProjectDialog: public Ui_FormNewProjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMNEWPROJECTDIALOG_H
