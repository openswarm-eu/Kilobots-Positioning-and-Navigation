/****************************************************************************
** Meta object code from reading C++ file 'kilobotexperiment.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/kilobotexperiment.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kilobotexperiment.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KiloDataRetrieval_t {
    QByteArrayData data[7];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KiloDataRetrieval_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KiloDataRetrieval_t qt_meta_stringdata_KiloDataRetrieval = {
    {
QT_MOC_LITERAL(0, 0, 17), // "KiloDataRetrieval"
QT_MOC_LITERAL(1, 18, 25), // "DataRetrievalProcessEnded"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 16), // "broadcastMessage"
QT_MOC_LITERAL(4, 62, 17), // "kilobot_broadcast"
QT_MOC_LITERAL(5, 80, 36), // "SeekInformationAboutKilobotRe..."
QT_MOC_LITERAL(6, 117, 25) // "std::vector<lightColour>&"

    },
    "KiloDataRetrieval\0DataRetrievalProcessEnded\0"
    "\0broadcastMessage\0kilobot_broadcast\0"
    "SeekInformationAboutKilobotResponses\0"
    "std::vector<lightColour>&"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KiloDataRetrieval[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    1,   30,    2, 0x06 /* Public */,
       5,    1,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 6,    2,

       0        // eod
};

void KiloDataRetrieval::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KiloDataRetrieval *_t = static_cast<KiloDataRetrieval *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DataRetrievalProcessEnded(); break;
        case 1: _t->broadcastMessage((*reinterpret_cast< kilobot_broadcast(*)>(_a[1]))); break;
        case 2: _t->SeekInformationAboutKilobotResponses((*reinterpret_cast< std::vector<lightColour>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (KiloDataRetrieval::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KiloDataRetrieval::DataRetrievalProcessEnded)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (KiloDataRetrieval::*_t)(kilobot_broadcast );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KiloDataRetrieval::broadcastMessage)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (KiloDataRetrieval::*_t)(std::vector<lightColour> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KiloDataRetrieval::SeekInformationAboutKilobotResponses)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject KiloDataRetrieval::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KiloDataRetrieval.data,
      qt_meta_data_KiloDataRetrieval,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KiloDataRetrieval::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KiloDataRetrieval::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KiloDataRetrieval.stringdata0))
        return static_cast<void*>(const_cast< KiloDataRetrieval*>(this));
    return QObject::qt_metacast(_clname);
}

int KiloDataRetrieval::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void KiloDataRetrieval::DataRetrievalProcessEnded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void KiloDataRetrieval::broadcastMessage(kilobot_broadcast _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KiloDataRetrieval::SeekInformationAboutKilobotResponses(std::vector<lightColour> & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_KilobotExperiment_t {
    QByteArrayData data[46];
    char stringdata0[719];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KilobotExperiment_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KilobotExperiment_t qt_meta_stringdata_KilobotExperiment = {
    {
QT_MOC_LITERAL(0, 0, 17), // "KilobotExperiment"
QT_MOC_LITERAL(1, 18, 19), // "updateKilobotStates"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 23), // "getInitialKilobotStates"
QT_MOC_LITERAL(4, 63, 18), // "experimentComplete"
QT_MOC_LITERAL(5, 82, 9), // "saveImage"
QT_MOC_LITERAL(6, 92, 15), // "saveVideoFrames"
QT_MOC_LITERAL(7, 108, 13), // "signalKilobot"
QT_MOC_LITERAL(8, 122, 15), // "kilobot_message"
QT_MOC_LITERAL(9, 138, 16), // "broadcastMessage"
QT_MOC_LITERAL(10, 155, 17), // "kilobot_broadcast"
QT_MOC_LITERAL(11, 173, 15), // "setTrackingType"
QT_MOC_LITERAL(12, 189, 21), // "sendBroadcastingState"
QT_MOC_LITERAL(13, 211, 10), // "drawCircle"
QT_MOC_LITERAL(14, 222, 3), // "pos"
QT_MOC_LITERAL(15, 226, 1), // "r"
QT_MOC_LITERAL(16, 228, 3), // "col"
QT_MOC_LITERAL(17, 232, 9), // "thickness"
QT_MOC_LITERAL(18, 242, 11), // "std::string"
QT_MOC_LITERAL(19, 254, 4), // "text"
QT_MOC_LITERAL(20, 259, 11), // "transparent"
QT_MOC_LITERAL(21, 271, 8), // "drawLine"
QT_MOC_LITERAL(22, 280, 22), // "std::vector<cv::Point>"
QT_MOC_LITERAL(23, 303, 13), // "clearDrawings"
QT_MOC_LITERAL(24, 317, 25), // "drawCircleOnRecordedImage"
QT_MOC_LITERAL(25, 343, 28), // "clearDrawingsOnRecordedImage"
QT_MOC_LITERAL(26, 372, 10), // "initialise"
QT_MOC_LITERAL(27, 383, 14), // "stopExperiment"
QT_MOC_LITERAL(28, 398, 3), // "run"
QT_MOC_LITERAL(29, 402, 28), // "setRuntimeIdentificationLock"
QT_MOC_LITERAL(30, 431, 4), // "lock"
QT_MOC_LITERAL(31, 436, 31), // "SendDataRetrievalProcessMessage"
QT_MOC_LITERAL(32, 468, 3), // "msg"
QT_MOC_LITERAL(33, 472, 31), // "toggleDataRetrievalProcessEnded"
QT_MOC_LITERAL(34, 504, 43), // "InformDataRetrievalProcessAbo..."
QT_MOC_LITERAL(35, 548, 25), // "std::vector<lightColour>&"
QT_MOC_LITERAL(36, 574, 11), // "AllMsgsSent"
QT_MOC_LITERAL(37, 586, 17), // "GetMsgsQueueState"
QT_MOC_LITERAL(38, 604, 5), // "state"
QT_MOC_LITERAL(39, 610, 23), // "updateStateRequiredCode"
QT_MOC_LITERAL(40, 634, 8), // "Kilobot*"
QT_MOC_LITERAL(41, 643, 7), // "kilobot"
QT_MOC_LITERAL(42, 651, 7), // "Kilobot"
QT_MOC_LITERAL(43, 659, 11), // "kilobotCopy"
QT_MOC_LITERAL(44, 671, 29), // "setupInitialStateRequiredCode"
QT_MOC_LITERAL(45, 701, 17) // "signalKilobotExpt"

    },
    "KilobotExperiment\0updateKilobotStates\0"
    "\0getInitialKilobotStates\0experimentComplete\0"
    "saveImage\0saveVideoFrames\0signalKilobot\0"
    "kilobot_message\0broadcastMessage\0"
    "kilobot_broadcast\0setTrackingType\0"
    "sendBroadcastingState\0drawCircle\0pos\0"
    "r\0col\0thickness\0std::string\0text\0"
    "transparent\0drawLine\0std::vector<cv::Point>\0"
    "clearDrawings\0drawCircleOnRecordedImage\0"
    "clearDrawingsOnRecordedImage\0initialise\0"
    "stopExperiment\0run\0setRuntimeIdentificationLock\0"
    "lock\0SendDataRetrievalProcessMessage\0"
    "msg\0toggleDataRetrievalProcessEnded\0"
    "InformDataRetrievalProcessAboutRobotsColors\0"
    "std::vector<lightColour>&\0AllMsgsSent\0"
    "GetMsgsQueueState\0state\0updateStateRequiredCode\0"
    "Kilobot*\0kilobot\0Kilobot\0kilobotCopy\0"
    "setupInitialStateRequiredCode\0"
    "signalKilobotExpt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KilobotExperiment[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  149,    2, 0x06 /* Public */,
       3,    0,  150,    2, 0x06 /* Public */,
       4,    0,  151,    2, 0x06 /* Public */,
       5,    1,  152,    2, 0x06 /* Public */,
       6,    2,  155,    2, 0x06 /* Public */,
       7,    1,  160,    2, 0x06 /* Public */,
       9,    1,  163,    2, 0x06 /* Public */,
      11,    1,  166,    2, 0x06 /* Public */,
      12,    1,  169,    2, 0x06 /* Public */,
      13,    6,  172,    2, 0x06 /* Public */,
      13,    5,  185,    2, 0x26 /* Public | MethodCloned */,
      21,    5,  196,    2, 0x06 /* Public */,
      23,    0,  207,    2, 0x06 /* Public */,
      24,    5,  208,    2, 0x06 /* Public */,
      25,    0,  219,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      26,    1,  220,    2, 0x0a /* Public */,
      27,    0,  223,    2, 0x0a /* Public */,
      28,    0,  224,    2, 0x0a /* Public */,
      29,    1,  225,    2, 0x0a /* Public */,
      31,    1,  228,    2, 0x0a /* Public */,
      33,    0,  231,    2, 0x0a /* Public */,
      34,    1,  232,    2, 0x0a /* Public */,
      36,    0,  235,    2, 0x0a /* Public */,
      37,    1,  236,    2, 0x0a /* Public */,
      39,    2,  239,    2, 0x0a /* Public */,
      44,    2,  244,    2, 0x0a /* Public */,
      45,    1,  249,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt,    2,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Float, QMetaType::QColor, QMetaType::Int, 0x80000000 | 18, QMetaType::Bool,   14,   15,   16,   17,   19,   20,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Float, QMetaType::QColor, QMetaType::Int, 0x80000000 | 18,   14,   15,   16,   17,   19,
    QMetaType::Void, 0x80000000 | 22, QMetaType::QColor, QMetaType::Int, 0x80000000 | 18, QMetaType::Bool,   14,   16,   17,   19,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Float, QMetaType::QColor, QMetaType::Int, 0x80000000 | 18,   14,   15,   16,   17,   19,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void, 0x80000000 | 10,   32,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 35,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   38,
    QMetaType::Void, 0x80000000 | 40, 0x80000000 | 42,   41,   43,
    QMetaType::Void, 0x80000000 | 40, 0x80000000 | 42,   41,   43,
    QMetaType::Void, 0x80000000 | 8,   32,

       0        // eod
};

void KilobotExperiment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KilobotExperiment *_t = static_cast<KilobotExperiment *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateKilobotStates(); break;
        case 1: _t->getInitialKilobotStates(); break;
        case 2: _t->experimentComplete(); break;
        case 3: _t->saveImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->saveVideoFrames((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 5: _t->signalKilobot((*reinterpret_cast< kilobot_message(*)>(_a[1]))); break;
        case 6: _t->broadcastMessage((*reinterpret_cast< kilobot_broadcast(*)>(_a[1]))); break;
        case 7: _t->setTrackingType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->sendBroadcastingState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->drawCircle((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< std::string(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6]))); break;
        case 10: _t->drawCircle((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< std::string(*)>(_a[5]))); break;
        case 11: _t->drawLine((*reinterpret_cast< std::vector<cv::Point>(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< std::string(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 12: _t->clearDrawings(); break;
        case 13: _t->drawCircleOnRecordedImage((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< std::string(*)>(_a[5]))); break;
        case 14: _t->clearDrawingsOnRecordedImage(); break;
        case 15: _t->initialise((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->stopExperiment(); break;
        case 17: _t->run(); break;
        case 18: _t->setRuntimeIdentificationLock((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->SendDataRetrievalProcessMessage((*reinterpret_cast< kilobot_broadcast(*)>(_a[1]))); break;
        case 20: _t->toggleDataRetrievalProcessEnded(); break;
        case 21: _t->InformDataRetrievalProcessAboutRobotsColors((*reinterpret_cast< std::vector<lightColour>(*)>(_a[1]))); break;
        case 22: _t->AllMsgsSent(); break;
        case 23: _t->GetMsgsQueueState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->updateStateRequiredCode((*reinterpret_cast< Kilobot*(*)>(_a[1])),(*reinterpret_cast< Kilobot(*)>(_a[2]))); break;
        case 25: _t->setupInitialStateRequiredCode((*reinterpret_cast< Kilobot*(*)>(_a[1])),(*reinterpret_cast< Kilobot(*)>(_a[2]))); break;
        case 26: _t->signalKilobotExpt((*reinterpret_cast< kilobot_message(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 24:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Kilobot* >(); break;
            }
            break;
        case 25:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Kilobot* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (KilobotExperiment::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KilobotExperiment::updateKilobotStates)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (KilobotExperiment::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KilobotExperiment::getInitialKilobotStates)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (KilobotExperiment::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KilobotExperiment::experimentComplete)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (KilobotExperiment::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KilobotExperiment::saveImage)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (KilobotExperiment::*_t)(QString , unsigned int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KilobotExperiment::saveVideoFrames)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (KilobotExperiment::*_t)(kilobot_message );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KilobotExperiment::signalKilobot)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (KilobotExperiment::*_t)(kilobot_broadcast );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KilobotExperiment::broadcastMessage)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (KilobotExperiment::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KilobotExperiment::setTrackingType)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (KilobotExperiment::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KilobotExperiment::sendBroadcastingState)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (KilobotExperiment::*_t)(QPointF , float , QColor , int , std::string , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KilobotExperiment::drawCircle)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (KilobotExperiment::*_t)(std::vector<cv::Point> , QColor , int , std::string , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KilobotExperiment::drawLine)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (KilobotExperiment::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KilobotExperiment::clearDrawings)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (KilobotExperiment::*_t)(QPointF , float , QColor , int , std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KilobotExperiment::drawCircleOnRecordedImage)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (KilobotExperiment::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KilobotExperiment::clearDrawingsOnRecordedImage)) {
                *result = 14;
                return;
            }
        }
    }
}

const QMetaObject KilobotExperiment::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KilobotExperiment.data,
      qt_meta_data_KilobotExperiment,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KilobotExperiment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KilobotExperiment::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KilobotExperiment.stringdata0))
        return static_cast<void*>(const_cast< KilobotExperiment*>(this));
    return QObject::qt_metacast(_clname);
}

int KilobotExperiment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void KilobotExperiment::updateKilobotStates()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void KilobotExperiment::getInitialKilobotStates()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void KilobotExperiment::experimentComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void KilobotExperiment::saveImage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void KilobotExperiment::saveVideoFrames(QString _t1, unsigned int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void KilobotExperiment::signalKilobot(kilobot_message _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void KilobotExperiment::broadcastMessage(kilobot_broadcast _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void KilobotExperiment::setTrackingType(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void KilobotExperiment::sendBroadcastingState(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void KilobotExperiment::drawCircle(QPointF _t1, float _t2, QColor _t3, int _t4, std::string _t5, bool _t6)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 11
void KilobotExperiment::drawLine(std::vector<cv::Point> _t1, QColor _t2, int _t3, std::string _t4, bool _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void KilobotExperiment::clearDrawings()
{
    QMetaObject::activate(this, &staticMetaObject, 12, Q_NULLPTR);
}

// SIGNAL 13
void KilobotExperiment::drawCircleOnRecordedImage(QPointF _t1, float _t2, QColor _t3, int _t4, std::string _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void KilobotExperiment::clearDrawingsOnRecordedImage()
{
    QMetaObject::activate(this, &staticMetaObject, 14, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
