/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun 14. Apr 20:17:09 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ui__MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      35,   15,   15,   15, 0x0a,
      55,   15,   15,   15, 0x0a,
      75,   15,   15,   15, 0x0a,
      97,   15,   15,   15, 0x0a,
     115,  110,   15,   15, 0x0a,
     151,   15,   15,   15, 0x0a,
     183,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Ui__MainWindow[] = {
    "Ui::MainWindow\0\0newProjectDialog()\0"
    "openProjectDialog()\0saveProjectDialog()\0"
    "saveAsProjectDialog()\0quitEditor()\0"
    "name\0addPageForAddedProject(std::string)\0"
    "removePagesForRemovedProjects()\0"
    "removePageForRemovedActiveProject()\0"
};

void Ui::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->newProjectDialog(); break;
        case 1: _t->openProjectDialog(); break;
        case 2: _t->saveProjectDialog(); break;
        case 3: _t->saveAsProjectDialog(); break;
        case 4: _t->quitEditor(); break;
        case 5: _t->addPageForAddedProject((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 6: _t->removePagesForRemovedProjects(); break;
        case 7: _t->removePageForRemovedActiveProject(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Ui::MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Ui::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Ui__MainWindow,
      qt_meta_data_Ui__MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ui::MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ui::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ui::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ui__MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Ui::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
