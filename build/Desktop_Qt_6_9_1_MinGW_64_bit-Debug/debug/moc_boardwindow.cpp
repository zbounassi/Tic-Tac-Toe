/****************************************************************************
** Meta object code from reading C++ file 'boardwindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../boardwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'boardwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN11boardwindowE_t {};
} // unnamed namespace

template <> constexpr inline auto boardwindow::qt_create_metaobjectdata<qt_meta_tag_ZN11boardwindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "boardwindow",
        "backToMenu",
        "",
        "hideChoices",
        "showPlayArea",
        "resetBoxes",
        "setArea",
        "playerTurn",
        "getDifficulty",
        "cpuTurn",
        "on_area1_clicked",
        "on_area2_clicked",
        "on_area3_clicked",
        "on_area4_clicked",
        "on_area5_clicked",
        "on_area6_clicked",
        "on_area7_clicked",
        "on_area8_clicked",
        "on_area9_clicked",
        "legalMoveCheck",
        "pos",
        "endGame",
        "getPlayer",
        "std::string",
        "checkWinner",
        "boardFull",
        "on_goFirst_clicked",
        "on_goSecond_clicked",
        "on_replayConfirm_clicked",
        "on_replayDeny_clicked",
        "on_gameExitButton_clicked",
        "on_gameExitConfirm_clicked",
        "on_gameExitDeny_clicked",
        "on_closeProgram_clicked",
        "on_menuExit_clicked",
        "showWinTracker",
        "clearTrackers",
        "getPlayerNames",
        "on_nameConfirm_clicked",
        "on_performChange_clicked",
        "on_doNotChange_clicked",
        "changeSidesOffer"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'backToMenu'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'hideChoices'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'showPlayArea'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'resetBoxes'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'setArea'
        QtMocHelpers::SlotData<void(int)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Slot 'playerTurn'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'getDifficulty'
        QtMocHelpers::SlotData<int()>(8, 2, QMC::AccessPrivate, QMetaType::Int),
        // Slot 'cpuTurn'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_area1_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_area2_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_area3_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_area4_clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_area5_clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_area6_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_area7_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_area8_clicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_area9_clicked'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'legalMoveCheck'
        QtMocHelpers::SlotData<bool(int)>(19, 2, QMC::AccessPrivate, QMetaType::Bool, {{
            { QMetaType::Int, 20 },
        }}),
        // Slot 'endGame'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'getPlayer'
        QtMocHelpers::SlotData<std::string()>(22, 2, QMC::AccessPrivate, 0x80000000 | 23),
        // Slot 'checkWinner'
        QtMocHelpers::SlotData<bool()>(24, 2, QMC::AccessPrivate, QMetaType::Bool),
        // Slot 'boardFull'
        QtMocHelpers::SlotData<bool()>(25, 2, QMC::AccessPrivate, QMetaType::Bool),
        // Slot 'on_goFirst_clicked'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_goSecond_clicked'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_replayConfirm_clicked'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_replayDeny_clicked'
        QtMocHelpers::SlotData<void()>(29, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_gameExitButton_clicked'
        QtMocHelpers::SlotData<void()>(30, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_gameExitConfirm_clicked'
        QtMocHelpers::SlotData<void()>(31, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_gameExitDeny_clicked'
        QtMocHelpers::SlotData<void()>(32, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_closeProgram_clicked'
        QtMocHelpers::SlotData<void()>(33, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_menuExit_clicked'
        QtMocHelpers::SlotData<void()>(34, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'showWinTracker'
        QtMocHelpers::SlotData<void()>(35, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'clearTrackers'
        QtMocHelpers::SlotData<void()>(36, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'getPlayerNames'
        QtMocHelpers::SlotData<void()>(37, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_nameConfirm_clicked'
        QtMocHelpers::SlotData<void()>(38, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_performChange_clicked'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_doNotChange_clicked'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'changeSidesOffer'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<boardwindow, qt_meta_tag_ZN11boardwindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject boardwindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11boardwindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11boardwindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11boardwindowE_t>.metaTypes,
    nullptr
} };

void boardwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<boardwindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->backToMenu(); break;
        case 1: _t->hideChoices(); break;
        case 2: _t->showPlayArea(); break;
        case 3: _t->resetBoxes(); break;
        case 4: _t->setArea((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->playerTurn(); break;
        case 6: { int _r = _t->getDifficulty();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->cpuTurn(); break;
        case 8: _t->on_area1_clicked(); break;
        case 9: _t->on_area2_clicked(); break;
        case 10: _t->on_area3_clicked(); break;
        case 11: _t->on_area4_clicked(); break;
        case 12: _t->on_area5_clicked(); break;
        case 13: _t->on_area6_clicked(); break;
        case 14: _t->on_area7_clicked(); break;
        case 15: _t->on_area8_clicked(); break;
        case 16: _t->on_area9_clicked(); break;
        case 17: { bool _r = _t->legalMoveCheck((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 18: _t->endGame(); break;
        case 19: { std::string _r = _t->getPlayer();
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = std::move(_r); }  break;
        case 20: { bool _r = _t->checkWinner();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 21: { bool _r = _t->boardFull();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 22: _t->on_goFirst_clicked(); break;
        case 23: _t->on_goSecond_clicked(); break;
        case 24: _t->on_replayConfirm_clicked(); break;
        case 25: _t->on_replayDeny_clicked(); break;
        case 26: _t->on_gameExitButton_clicked(); break;
        case 27: _t->on_gameExitConfirm_clicked(); break;
        case 28: _t->on_gameExitDeny_clicked(); break;
        case 29: _t->on_closeProgram_clicked(); break;
        case 30: _t->on_menuExit_clicked(); break;
        case 31: _t->showWinTracker(); break;
        case 32: _t->clearTrackers(); break;
        case 33: _t->getPlayerNames(); break;
        case 34: _t->on_nameConfirm_clicked(); break;
        case 35: _t->on_performChange_clicked(); break;
        case 36: _t->on_doNotChange_clicked(); break;
        case 37: _t->changeSidesOffer(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (boardwindow::*)()>(_a, &boardwindow::backToMenu, 0))
            return;
    }
}

const QMetaObject *boardwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *boardwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11boardwindowE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int boardwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 38)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 38;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 38)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 38;
    }
    return _id;
}

// SIGNAL 0
void boardwindow::backToMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
