/****************************************************************************
** Meta object code from reading C++ file 'uispreadsheet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ExcelBasico/uispreadsheet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uispreadsheet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UISpreadsheet_t {
    QByteArrayData data[7];
    char stringdata[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_UISpreadsheet_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_UISpreadsheet_t qt_meta_stringdata_UISpreadsheet = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 8),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 16),
QT_MOC_LITERAL(4, 41, 12),
QT_MOC_LITERAL(5, 54, 17),
QT_MOC_LITERAL(6, 72, 4)
    },
    "UISpreadsheet\0modified\0\0somethingChanged\0"
    "updateStatus\0QTableWidgetItem*\0item\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UISpreadsheet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    0,   30,    2, 0x08,
       4,    1,   31,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void UISpreadsheet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UISpreadsheet *_t = static_cast<UISpreadsheet *>(_o);
        switch (_id) {
        case 0: _t->modified(); break;
        case 1: _t->somethingChanged(); break;
        case 2: _t->updateStatus((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UISpreadsheet::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UISpreadsheet::modified)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject UISpreadsheet::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_UISpreadsheet.data,
      qt_meta_data_UISpreadsheet,  qt_static_metacall, 0, 0}
};


const QMetaObject *UISpreadsheet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UISpreadsheet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UISpreadsheet.stringdata))
        return static_cast<void*>(const_cast< UISpreadsheet*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int UISpreadsheet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void UISpreadsheet::modified()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
