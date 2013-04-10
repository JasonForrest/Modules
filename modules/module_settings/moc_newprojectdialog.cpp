/****************************************************************************
** Meta object code from reading C++ file 'newprojectdialog.h'
**
** Created: Wed 10. Apr 00:06:39 2013
**      by: The Qt Meta Object Compiler version 67 (Qt 5.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "newprojectdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newprojectdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Ui__NewProjectDialog_t {
    QByteArrayData data[7];
    char stringdata[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Ui__NewProjectDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Ui__NewProjectDialog_t qt_meta_stringdata_Ui__NewProjectDialog = {
    {
QT_MOC_LITERAL(0, 0, 20),
QT_MOC_LITERAL(1, 21, 14),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 11),
QT_MOC_LITERAL(4, 49, 11),
QT_MOC_LITERAL(5, 61, 7),
QT_MOC_LITERAL(6, 69, 16)
    },
    "Ui::NewProjectDialog\0enableOkButton\0"
    "\0setSettings\0modeToggled\0checked\0"
    "openFolderDialog\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ui__NewProjectDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a,
       3,    0,   35,    2, 0x0a,
       4,    1,   36,    2, 0x0a,
       6,    0,   39,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,

       0        // eod
};

void Ui::NewProjectDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewProjectDialog *_t = static_cast<NewProjectDialog *>(_o);
        switch (_id) {
        case 0: _t->enableOkButton(); break;
        case 1: _t->setSettings(); break;
        case 2: _t->modeToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->openFolderDialog(); break;
        default: ;
        }
    }
}

const QMetaObject Ui::NewProjectDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Ui__NewProjectDialog.data,
      qt_meta_data_Ui__NewProjectDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *Ui::NewProjectDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ui::NewProjectDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ui__NewProjectDialog.stringdata))
        return static_cast<void*>(const_cast< NewProjectDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Ui::NewProjectDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
