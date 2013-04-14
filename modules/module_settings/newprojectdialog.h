#ifndef NEW_PROJECT_DIALOG_H
#define NEW_PROJECT_DIALOG_H

#include "ui_formnewprojectdialog.h"
#include "windowsettings.h"
#include <QtGui/qfiledialog.h>

struct xml_string_writer: pugi::xml_writer
{
	std::string result;

	virtual void write(const void* data, size_t size)
	{
		result += std::string(static_cast<const char*>(data), size);
	}
};

namespace Ui
{
    class NewProjectDialog : public QDialog
    {
        Q_OBJECT

	public:
		typedef std::map<std::string, QPoint> allSizes;

    public:
        explicit NewProjectDialog(QWidget *parent = 0);
        ~NewProjectDialog();

		void showDialog();

	public Q_SLOTS:
		void enableOkButton();
		void setSettings();
		void modeToggled(bool checked);
		void openFolderDialog();

	Q_SIGNALS:
		void addProjectPage(std::string);
	
	private:
		void resetFields();

    private:
        FormNewProjectDialog *_newProjectDialogForm;
		allSizes _sizes;
    };
}

#endif // MYDIALOG_H
