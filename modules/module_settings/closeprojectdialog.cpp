#include "closeprojectdialog.h"
#include <QtGui/qtreewidgetitemiterator.h>

namespace Ui
{
    CloseProjectDialog::CloseProjectDialog(QWidget *parent)
        : QDialog(parent)
        , _closeProjectDialogForm(new Ui::FormCloseProjectDialog)
        , _result(OQSettings::DR_CANCEL)
    {
        _closeProjectDialogForm->setupUi(this);

        setModal(true);

		_closeProjectDialogForm->buttonYes->setEnabled(false);
		_closeProjectDialogForm->buttonNo->setEnabled(false);
		_closeProjectDialogForm->buttonRemoveProject->setEnabled(true);

		_closeProjectDialogForm->checkboxCheckAll->setChecked(false);

        connect(_closeProjectDialogForm->buttonYes, SIGNAL(clicked()), this, SLOT(yes()));
        connect(_closeProjectDialogForm->buttonNo, SIGNAL(clicked()), this, SLOT(no()));
        connect(_closeProjectDialogForm->buttonCancel, SIGNAL(clicked()), this, SLOT(cancel()));

        connect(_closeProjectDialogForm->checkboxCheckAll, SIGNAL(toggled(bool)), this, SLOT(checkAllProjects(bool)));
		connect(_closeProjectDialogForm->buttonRemoveProject, SIGNAL(clicked()), this, SLOT(removeSelectedProject()));

		_closableProjects.clear();
	}

	CloseProjectDialog::~CloseProjectDialog()
	{
		delete _closeProjectDialogForm;
		_closeProjectDialogForm = NULL;

		_closableProjects.clear();
	}

	void CloseProjectDialog::resetUi()
	{
		_closeProjectDialogForm->buttonYes->setEnabled(false);
		_closeProjectDialogForm->buttonNo->setEnabled(false);
		_closeProjectDialogForm->buttonRemoveProject->setEnabled(true);
		_closableProjects.clear();
		_closeProjectDialogForm->checkboxCheckAll->setChecked(false);
		_closeProjectDialogForm->treeProjects->clear();
	}

	void CloseProjectDialog::removeSelectedProject()
	{
		QList<QTreeWidgetItem*> list = _closeProjectDialogForm->treeProjects->selectedItems();

		if (list.size() == 1)
		{
			_closeProjectDialogForm->buttonRemoveProject->setEnabled(false);
			return;
		}

		for (QList<QTreeWidgetItem*>::Iterator it = list.begin(); it != list.end(); ++it)
		{
			if (list.size() == 1)
			{
				_closeProjectDialogForm->buttonRemoveProject->setEnabled(false);
				break;
			}

			delete *it;
			*it = NULL;
		}
	}

	void CloseProjectDialog::enableYesNoButtons()
	{
		if (chekcStateOfClosableProjects())
		{
			_closeProjectDialogForm->buttonYes->setEnabled(true);
			_closeProjectDialogForm->buttonNo->setEnabled(true);
		}
		else
		{
			_closeProjectDialogForm->buttonYes->setEnabled(false);
			_closeProjectDialogForm->buttonNo->setEnabled(false);
		}
	}

    void CloseProjectDialog::yes()
    {
        _result = OQSettings::DR_YES;
		Q_EMIT removeProjectPages();
        hide();
    }

    void CloseProjectDialog::no()
    {
        _result = OQSettings::DR_NO;
		Q_EMIT removeProjectPages();
        hide();
    }

    void CloseProjectDialog::cancel()
    {
        _result = OQSettings::DR_CANCEL;
        hide();
    }

    int CloseProjectDialog::showDialog(std::vector<std::string> const& names)
    {
		resetUi();

		createList(names);
        exec();

		for (int i = 0; i < _closeProjectDialogForm->treeProjects->topLevelItemCount(); i++)
		{
			bool checked = (bool)_closeProjectDialogForm->treeProjects->topLevelItem(i)->checkState(0);

			if (checked)
			{
				_closableProjects.push_back(names[i]);
			}
		}

        return _result;
    }

	bool CloseProjectDialog::chekcStateOfClosableProjects() const
	{
		for (int i = 0; i < _closeProjectDialogForm->treeProjects->topLevelItemCount(); i++)
		{
			if (_closeProjectDialogForm->treeProjects->topLevelItem(i)->checkState(0) == Qt::Checked)
			{
				return true;
			}
		}

		return false;
	}

	void CloseProjectDialog::createList(std::vector<std::string> const& names)
	{
		_closeProjectDialogForm->treeProjects->clear();

		for (size_t i = 0; i < names.size(); i++)
		{
			QTreeWidgetItem *itm = new QTreeWidgetItem();
			itm->setText(0, names[i].c_str());
			itm->setFlags(itm->flags() | Qt::ItemIsUserCheckable);
			itm->setCheckState(0, Qt::Unchecked);
			connect(_closeProjectDialogForm->treeProjects, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(enableYesNoButtons()));
			_closeProjectDialogForm->treeProjects->addTopLevelItem(itm);
		}

		if (names.size() == 1)
		{
			_closeProjectDialogForm->buttonRemoveProject->setEnabled(false);
		}
	}

    void CloseProjectDialog::checkAllProjects(bool checked)
	{
        Qt::CheckState state;

        if (checked)
        {
            state = Qt::Checked;
        }
        else
        {
            state = Qt::Unchecked;
        }

		for (int i = 0; i < _closeProjectDialogForm->treeProjects->topLevelItemCount(); i++)
		{
            _closeProjectDialogForm->treeProjects->topLevelItem(i)->setCheckState(0, state);
		}
	}
}
