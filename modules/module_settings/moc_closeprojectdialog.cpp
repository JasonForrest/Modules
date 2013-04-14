/****************************************************************************
** Meta object code from reading C++ file 'closeprojectdialog.h'
**
** Created: Sun 14. Apr 20:17:07 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "closeprojectdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'closeprojectdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ui__CloseProjectDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   23,   23,   23, 0x0a,
      77,   69,   23,   23, 0x0a,
     100,   23,   23,   23, 0x0a,
     121,   23,   23,   23, 0x0a,
     127,   23,   23,   23, 0x0a,
     132,   23,   23,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Ui__CloseProjectDialog[] = {
    "Ui::CloseProjectDialog\0\0removeProjectPages()\0"
    "removeSelectedProject()\0checked\0"
    "checkAllProjects(bool)\0enableYesNoButtons()\0"
    "yes()\0no()\0cancel()\0"
};

void Ui::CloseProjectDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CloseProjectDialog *_t = static_cast<CloseProjectDialog *>(_o);
        switch (_id) {
        case 0: _t->removeProjectPages(); break;
        case 1: _t->removeSelectedProject(); break;
        case 2: _t->checkAllProjects((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->enableYesNoButtons(); break;
        case 4: _t->yes(); break;
        case 5: _t->no(); break;
        case 6: _t->cancel(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Ui::CloseProjectDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Ui::CloseProjectDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Ui__CloseProjectDialog,
      qt_meta_data_Ui__CloseProjectDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ui::CloseProjectDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ui::CloseProjectDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ui::CloseProjectDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ui__CloseProjectDialog))
        return static_cast<void*>(const_cast< CloseProjectDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Ui::CloseProjectDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Ui::CloseProjectDialog::removeProjectPages()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
