/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_logdialog_t {
    QByteArrayData data[5];
    char stringdata[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_logdialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_logdialog_t qt_meta_stringdata_logdialog = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 7),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 4),
QT_MOC_LITERAL(4, 24, 6)
    },
    "logdialog\0newname\0\0name\0accept\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_logdialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   27,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void logdialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        logdialog *_t = static_cast<logdialog *>(_o);
        switch (_id) {
        case 0: _t->newname((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->accept(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (logdialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&logdialog::newname)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject logdialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_logdialog.data,
      qt_meta_data_logdialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *logdialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *logdialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_logdialog.stringdata))
        return static_cast<void*>(const_cast< logdialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int logdialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void logdialog::newname(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_strategydialog_t {
    QByteArrayData data[8];
    char stringdata[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_strategydialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_strategydialog_t qt_meta_stringdata_strategydialog = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 8),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 6),
QT_MOC_LITERAL(4, 32, 6),
QT_MOC_LITERAL(5, 39, 10),
QT_MOC_LITERAL(6, 50, 10),
QT_MOC_LITERAL(7, 61, 10)
    },
    "strategydialog\0ischosen\0\0choose\0accept\0"
    "setchoose1\0setchoose2\0setchoose3\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_strategydialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06,
       3,    1,   47,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   50,    2, 0x0a,
       5,    0,   51,    2, 0x0a,
       6,    0,   52,    2, 0x0a,
       7,    0,   53,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void strategydialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        strategydialog *_t = static_cast<strategydialog *>(_o);
        switch (_id) {
        case 0: _t->ischosen((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->choose((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->accept(); break;
        case 3: _t->setchoose1(); break;
        case 4: _t->setchoose2(); break;
        case 5: _t->setchoose3(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (strategydialog::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&strategydialog::ischosen)) {
                *result = 0;
            }
        }
        {
            typedef void (strategydialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&strategydialog::choose)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject strategydialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_strategydialog.data,
      qt_meta_data_strategydialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *strategydialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *strategydialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_strategydialog.stringdata))
        return static_cast<void*>(const_cast< strategydialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int strategydialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void strategydialog::ischosen(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void strategydialog::choose(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_changedialog_t {
    QByteArrayData data[8];
    char stringdata[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_changedialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_changedialog_t qt_meta_stringdata_changedialog = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 12),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 12),
QT_MOC_LITERAL(4, 40, 6),
QT_MOC_LITERAL(5, 47, 16),
QT_MOC_LITERAL(6, 64, 16),
QT_MOC_LITERAL(7, 81, 16)
    },
    "changedialog\0changechoose\0\0change_infor\0"
    "accept\0setchangechoose1\0setchangechoose2\0"
    "setchangechoose3\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_changedialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06,
       3,    3,   47,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   54,    2, 0x0a,
       5,    0,   55,    2, 0x0a,
       6,    0,   56,    2, 0x0a,
       7,    0,   57,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void changedialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        changedialog *_t = static_cast<changedialog *>(_o);
        switch (_id) {
        case 0: _t->changechoose((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->change_infor((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->accept(); break;
        case 3: _t->setchangechoose1(); break;
        case 4: _t->setchangechoose2(); break;
        case 5: _t->setchangechoose3(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (changedialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&changedialog::changechoose)) {
                *result = 0;
            }
        }
        {
            typedef void (changedialog::*_t)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&changedialog::change_infor)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject changedialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_changedialog.data,
      qt_meta_data_changedialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *changedialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *changedialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_changedialog.stringdata))
        return static_cast<void*>(const_cast< changedialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int changedialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void changedialog::changechoose(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void changedialog::change_infor(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_citydialog_t {
    QByteArrayData data[8];
    char stringdata[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_citydialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_citydialog_t qt_meta_stringdata_citydialog = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 7),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 10),
QT_MOC_LITERAL(4, 31, 10),
QT_MOC_LITERAL(5, 42, 10),
QT_MOC_LITERAL(6, 53, 10),
QT_MOC_LITERAL(7, 64, 6)
    },
    "citydialog\0setcity\0\0setchoose1\0"
    "setchoose2\0setchoose3\0setchoose4\0"
    "accept\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_citydialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    0,   49,    2, 0x0a,
       4,    0,   50,    2, 0x0a,
       5,    0,   51,    2, 0x0a,
       6,    0,   52,    2, 0x0a,
       7,    0,   53,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void citydialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        citydialog *_t = static_cast<citydialog *>(_o);
        switch (_id) {
        case 0: _t->setcity((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->setchoose1(); break;
        case 2: _t->setchoose2(); break;
        case 3: _t->setchoose3(); break;
        case 4: _t->setchoose4(); break;
        case 5: _t->accept(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (citydialog::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&citydialog::setcity)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject citydialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_citydialog.data,
      qt_meta_data_citydialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *citydialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *citydialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_citydialog.stringdata))
        return static_cast<void*>(const_cast< citydialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int citydialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void citydialog::setcity(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
