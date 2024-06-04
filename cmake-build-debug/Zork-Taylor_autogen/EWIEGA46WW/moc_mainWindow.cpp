/****************************************************************************
** Meta object code from reading C++ file 'mainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "showIntroRoom"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "showRoom1"
QT_MOC_LITERAL(4, 36, 9), // "showRoom2"
QT_MOC_LITERAL(5, 46, 12), // "showTourRoom"
QT_MOC_LITERAL(6, 59, 13), // "showFinalRoom"
QT_MOC_LITERAL(7, 73, 8), // "showRoom"
QT_MOC_LITERAL(8, 82, 4), // "Room"
QT_MOC_LITERAL(9, 87, 4), // "room"
QT_MOC_LITERAL(10, 92, 16), // "createTourLayout"
QT_MOC_LITERAL(11, 109, 16), // "showSpecificRoom"
QT_MOC_LITERAL(12, 126, 9), // "albumName"
QT_MOC_LITERAL(13, 136, 17), // "newAlbumImagePath"
QT_MOC_LITERAL(14, 154, 17), // "handleButtonClick"
QT_MOC_LITERAL(15, 172, 8), // "buttonId"
QT_MOC_LITERAL(16, 181, 21), // "handleTourButtonClick"
QT_MOC_LITERAL(17, 203, 9), // "goToRoom1"
QT_MOC_LITERAL(18, 213, 8), // "exitGame"
QT_MOC_LITERAL(19, 222, 9) // "startGame"

    },
    "MainWindow\0showIntroRoom\0\0showRoom1\0"
    "showRoom2\0showTourRoom\0showFinalRoom\0"
    "showRoom\0Room\0room\0createTourLayout\0"
    "showSpecificRoom\0albumName\0newAlbumImagePath\0"
    "handleButtonClick\0buttonId\0"
    "handleTourButtonClick\0goToRoom1\0"
    "exitGame\0startGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    1,   84,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    2,   88,    2, 0x08 /* Private */,
      14,    1,   93,    2, 0x08 /* Private */,
      16,    1,   96,    2, 0x08 /* Private */,
      17,    0,   99,    2, 0x08 /* Private */,
      18,    0,  100,    2, 0x08 /* Private */,
      19,    0,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   12,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showIntroRoom(); break;
        case 1: _t->showRoom1(); break;
        case 2: _t->showRoom2(); break;
        case 3: _t->showTourRoom(); break;
        case 4: _t->showFinalRoom(); break;
        case 5: _t->showRoom((*reinterpret_cast< const Room(*)>(_a[1]))); break;
        case 6: _t->createTourLayout(); break;
        case 7: _t->showSpecificRoom((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->handleButtonClick((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->handleTourButtonClick((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->goToRoom1(); break;
        case 11: _t->exitGame(); break;
        case 12: _t->startGame(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
