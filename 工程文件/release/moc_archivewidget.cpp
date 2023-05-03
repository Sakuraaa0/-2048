/****************************************************************************
** Meta object code from reading C++ file 'archivewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../2048/2048/archivewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'archivewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_archivewidget_t {
    QByteArrayData data[7];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_archivewidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_archivewidget_t qt_meta_stringdata_archivewidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "archivewidget"
QT_MOC_LITERAL(1, 14, 10), // "returngame"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "savegame"
QT_MOC_LITERAL(4, 35, 8), // "readgame"
QT_MOC_LITERAL(5, 44, 10), // "deletegame"
QT_MOC_LITERAL(6, 55, 8) // "dClicked"

    },
    "archivewidget\0returngame\0\0savegame\0"
    "readgame\0deletegame\0dClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_archivewidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,
       6,    0,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void archivewidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<archivewidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returngame(); break;
        case 1: _t->savegame(); break;
        case 2: _t->readgame(); break;
        case 3: _t->deletegame(); break;
        case 4: _t->dClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (archivewidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&archivewidget::returngame)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (archivewidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&archivewidget::savegame)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (archivewidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&archivewidget::readgame)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (archivewidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&archivewidget::deletegame)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (archivewidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&archivewidget::dClicked)) {
                *result = 4;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject archivewidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_archivewidget.data,
    qt_meta_data_archivewidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *archivewidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *archivewidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_archivewidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int archivewidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void archivewidget::returngame()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void archivewidget::savegame()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void archivewidget::readgame()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void archivewidget::deletegame()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void archivewidget::dClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
