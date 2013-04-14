#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "ui_formmainwindow.h"
#include "newprojectdialog.h"
#include "qogrewidget.h"

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

	public Q_SLOTS:
		void newProjectDialog();
		void openProjectDialog();
		void saveProjectDialog();
		void saveAsProjectDialog();
		void quitEditor();
		void addPageForAddedProject(std::string name);
		void removePagesForRemovedProjects();
		void removePageForRemovedActiveProject();

	protected:
		virtual void addPage(std::string const& name);
		void removePage(std::string const& name);
		QWidget *pageTemplate(std::string const& name);

    protected:
        FormMainWindow *_mainWindowForm;
		NewProjectDialog *_newProjectDialog;

		OQSettings::SettingsManager *_settingsManager;
		OQSettings::ErrorMessanger *_errorMessanger;
    };
}

#endif // MAINWINDOW_H
