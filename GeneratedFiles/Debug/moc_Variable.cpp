/****************************************************************************
** Meta object code from reading C++ file 'Variable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Variable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Variable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Traverser_t {
    QByteArrayData data[14];
    char stringdata[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Traverser_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Traverser_t qt_meta_stringdata_Traverser = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 10),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 7),
QT_MOC_LITERAL(4, 30, 13),
QT_MOC_LITERAL(5, 44, 8),
QT_MOC_LITERAL(6, 53, 5),
QT_MOC_LITERAL(7, 59, 11),
QT_MOC_LITERAL(8, 71, 9),
QT_MOC_LITERAL(9, 81, 5),
QT_MOC_LITERAL(10, 87, 4),
QT_MOC_LITERAL(11, 92, 7),
QT_MOC_LITERAL(12, 100, 5),
QT_MOC_LITERAL(13, 106, 6)
    },
    "Traverser\0isGenerate\0\0success\0"
    "changesucceed\0curstate\0clear\0PrintFlight\0"
    "QString[]\0route\0move\0Flight*\0still\0"
    "arrive\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Traverser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06,
       3,    1,   67,    2, 0x06,
       4,    1,   70,    2, 0x06,
       5,    1,   73,    2, 0x06,
       6,    0,   76,    2, 0x06,
       7,    3,   77,    2, 0x06,
       9,    3,   84,    2, 0x06,
      10,    2,   91,    2, 0x06,
      12,    0,   96,    2, 0x06,
      13,    0,   97,    2, 0x06,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Traverser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Traverser *_t = static_cast<Traverser *>(_o);
        switch (_id) {
        case 0: _t->isGenerate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->success((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->changesucceed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->curstate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->clear(); break;
        case 5: _t->PrintFlight((*reinterpret_cast< QString(*)[]>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 6: _t->route((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->move((*reinterpret_cast< Flight*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->still(); break;
        case 9: _t->arrive(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Traverser::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Traverser::isGenerate)) {
                *result = 0;
            }
        }
        {
            typedef void (Traverser::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Traverser::success)) {
                *result = 1;
            }
        }
        {
            typedef void (Traverser::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Traverser::changesucceed)) {
                *result = 2;
            }
        }
        {
            typedef void (Traverser::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Traverser::curstate)) {
                *result = 3;
            }
        }
        {
            typedef void (Traverser::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Traverser::clear)) {
                *result = 4;
            }
        }
        {
            typedef void (Traverser::*_t)(QString [], int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Traverser::PrintFlight)) {
                *result = 5;
            }
        }
        {
            typedef void (Traverser::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Traverser::route)) {
                *result = 6;
            }
        }
        {
            typedef void (Traverser::*_t)(Flight * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Traverser::move)) {
                *result = 7;
            }
        }
        {
            typedef void (Traverser::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Traverser::still)) {
                *result = 8;
            }
        }
        {
            typedef void (Traverser::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Traverser::arrive)) {
                *result = 9;
            }
        }
    }
}

const QMetaObject Traverser::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Traverser.data,
      qt_meta_data_Traverser,  qt_static_metacall, 0, 0}
};


const QMetaObject *Traverser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Traverser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Traverser.stringdata))
        return static_cast<void*>(const_cast< Traverser*>(this));
    return QObject::qt_metacast(_clname);
}

int Traverser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Traverser::isGenerate(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Traverser::success(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Traverser::changesucceed(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Traverser::curstate(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Traverser::clear()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Traverser::PrintFlight(QString _t1[], int _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Traverser::route(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Traverser::move(Flight * _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Traverser::still()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void Traverser::arrive()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}
QT_END_MOC_NAMESPACE
