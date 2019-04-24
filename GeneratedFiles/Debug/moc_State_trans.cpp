/****************************************************************************
** Meta object code from reading C++ file 'State_trans.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../State_trans.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'State_trans.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_transThread_t {
    QByteArrayData data[4];
    char stringdata[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_transThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_transThread_t qt_meta_stringdata_transThread = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 7),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 7)
    },
    "transThread\0newTime\0\0newDate\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_transThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06,
       3,    1,   27,    2, 0x06,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void transThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        transThread *_t = static_cast<transThread *>(_o);
        switch (_id) {
        case 0: _t->newTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->newDate((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (transThread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&transThread::newTime)) {
                *result = 0;
            }
        }
        {
            typedef void (transThread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&transThread::newDate)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject transThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_transThread.data,
      qt_meta_data_transThread,  qt_static_metacall, 0, 0}
};


const QMetaObject *transThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *transThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_transThread.stringdata))
        return static_cast<void*>(const_cast< transThread*>(this));
    return QThread::qt_metacast(_clname);
}

int transThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void transThread::newTime(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void transThread::newDate(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
