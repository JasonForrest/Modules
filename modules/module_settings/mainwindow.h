#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "ui_formmainwindow.h"
#include "newprojectdialog.h"

#include <QtWidgets\qplaintextedit.h>

namespace Ui
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

	private:
		void closeEvent(QCloseEvent *cevent);

	public slots:
		void newProjectDialog();
		void openProjectDialog();
		void saveProjectDialog();
		void saveAsProjectDialog();
		void quitEditor();

    protected:
        FormMainWindow *_mainWindowForm;
		NewProjectDialog *_newProjectDialog;

		OQSettings::SettingsManager *_settingsManager;
		OQSettings::ErrorMessanger *_errorMessanger;

	public:
		QPlainTextEdit *_tempEdit;
    };
}

#endif // MAINWINDOW_H
