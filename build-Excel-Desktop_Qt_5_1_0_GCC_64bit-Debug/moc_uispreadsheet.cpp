/****************************************************************************
** Meta object code from reading C++ file 'uispreadsheet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../EXCEL/uispreadsheet.h"
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
    QByteArrayData data[18];
    char stringdata[185];
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
QT_MOC_LITERAL(3, 24, 3),
QT_MOC_LITERAL(4, 28, 4),
QT_MOC_LITERAL(5, 33, 5),
QT_MOC_LITERAL(6, 39, 3),
QT_MOC_LITERAL(7, 43, 16),
QT_MOC_LITERAL(8, 60, 19),
QT_MOC_LITERAL(9, 80, 11),
QT_MOC_LITERAL(10, 92, 18),
QT_MOC_LITERAL(11, 111, 6),
QT_MOC_LITERAL(12, 118, 8),
QT_MOC_LITERAL(13, 127, 3),
QT_MOC_LITERAL(14, 131, 19),
QT_MOC_LITERAL(15, 151, 2),
QT_MOC_LITERAL(16, 154, 12),
QT_MOC_LITERAL(17, 167, 16)
    },
    "UISpreadsheet\0modified\0\0cut\0copy\0paste\0"
    "del\0selectCurrentRow\0selectCurrentColumn\0"
    "recalculate\0setAutoRecalculate\0recalc\0"
    "findNext\0str\0Qt::CaseSensitivity\0cs\0"
    "findPrevious\0somethingChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UISpreadsheet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    0,   75,    2, 0x0a,
       4,    0,   76,    2, 0x0a,
       5,    0,   77,    2, 0x0a,
       6,    0,   78,    2, 0x0a,
       7,    0,   79,    2, 0x0a,
       8,    0,   80,    2, 0x0a,
       9,    0,   81,    2, 0x0a,
      10,    1,   82,    2, 0x0a,
      12,    2,   85,    2, 0x0a,
      16,    2,   90,    2, 0x0a,
      17,    0,   95,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 14,   13,   15,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 14,   13,   15,
    QMetaType::Void,

       0        // eod
};

void UISpreadsheet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UISpreadsheet *_t = static_cast<UISpreadsheet *>(_o);
        switch (_id) {
        case 0: _t->modified(); break;
        case 1: _t->cut(); break;
        case 2: _t->copy(); break;
        case 3: _t->paste(); break;
        case 4: _t->del(); break;
        case 5: _t->selectCurrentRow(); break;
        case 6: _t->selectCurrentColumn(); break;
        case 7: _t->recalculate(); break;
        case 8: _t->setAutoRecalculate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->findNext((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< Qt::CaseSensitivity(*)>(_a[2]))); break;
        case 10: _t->findPrevious((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< Qt::CaseSensitivity(*)>(_a[2]))); break;
        case 11: _t->somethingChanged(); break;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void UISpreadsheet::modified()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
