#ifndef CLOSE_PROJECT_DIALOG_H
#define CLOSE_PROJECT_DIALOG_H

#include "ui_formcloseprojectdialog.h"
#include <QtGui/qmessagebox.h>

namespace OQSettings
{
	enum DIALOG_RESULT
	{
		DR_CANCEL = 0,
		DR_NO,
		DR_YES,
		DR_OK
	};
}

namespace Ui
{
    class CloseProjectDialog : public QDialog
    {
        Q_OBJECT

    public:
        explicit CloseProjectDialog(QWidget *parent = 0);
        ~CloseProjectDialog();

        int showDialog(std::vector<std::string> const& names);

		//getters
		inline std::vector<std::string> const& getClosableProjects() const
		{
			return _closableProjects;
		}

	public Q_SLOTS:
		void removeSelectedProject();
        void checkAllProjects(bool checked);
		void enableYesNoButtons();
        void yes();
        void no();
        void cancel();

	Q_SIGNALS:
		void removeProjectPages();

	private:
		void createList(std::vector<std::string> const& names);
		bool chekcStateOfClosableProjects() const;
		void resetUi();

    private:
		FormCloseProjectDialog *_closeProjectDialogForm;
		std::vector<std::string> _closableProjects;
        int _result;
    };
}

#endif
