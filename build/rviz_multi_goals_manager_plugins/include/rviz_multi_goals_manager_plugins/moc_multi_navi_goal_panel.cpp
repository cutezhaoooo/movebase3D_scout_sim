/****************************************************************************
** Meta object code from reading C++ file 'multi_navi_goal_panel.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/rviz_plungins/rviz_multi_goals_manager_plugins/include/rviz_multi_goals_manager_plugins/multi_navi_goal_panel.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multi_navi_goal_panel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rviz_multi_goals_manager_plugins__MultiNaviGoalsPanel_t {
    QByteArrayData data[29];
    char stringdata0[464];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rviz_multi_goals_manager_plugins__MultiNaviGoalsPanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rviz_multi_goals_manager_plugins__MultiNaviGoalsPanel_t qt_meta_stringdata_rviz_multi_goals_manager_plugins__MultiNaviGoalsPanel = {
    {
QT_MOC_LITERAL(0, 0, 53), // "rviz_multi_goals_manager_plug..."
QT_MOC_LITERAL(1, 54, 13), // "setMaxNumGoal"
QT_MOC_LITERAL(2, 68, 0), // ""
QT_MOC_LITERAL(3, 69, 10), // "maxNumGoal"
QT_MOC_LITERAL(4, 80, 9), // "writePose"
QT_MOC_LITERAL(5, 90, 24), // "geometry_msgs::msg::Pose"
QT_MOC_LITERAL(6, 115, 4), // "pose"
QT_MOC_LITERAL(7, 120, 8), // "markPose"
QT_MOC_LITERAL(8, 129, 31), // "geometry_msgs::msg::PoseStamped"
QT_MOC_LITERAL(9, 161, 10), // "deleteMark"
QT_MOC_LITERAL(10, 172, 11), // "changeEvent"
QT_MOC_LITERAL(11, 184, 13), // "initPoseTable"
QT_MOC_LITERAL(12, 198, 15), // "updatePoseTable"
QT_MOC_LITERAL(13, 214, 9), // "startNavi"
QT_MOC_LITERAL(14, 224, 9), // "goalCntCB"
QT_MOC_LITERAL(15, 234, 18), // "statusGlobalPoseCB"
QT_MOC_LITERAL(16, 253, 32), // "rover_msgs::msg::RoverGoalStatus"
QT_MOC_LITERAL(17, 286, 10), // "poseStatus"
QT_MOC_LITERAL(18, 297, 17), // "statusLocalPoseCB"
QT_MOC_LITERAL(19, 315, 10), // "checkCycle"
QT_MOC_LITERAL(20, 326, 12), // "completeNavi"
QT_MOC_LITERAL(21, 339, 9), // "cycleNavi"
QT_MOC_LITERAL(22, 349, 9), // "checkGoal"
QT_MOC_LITERAL(23, 359, 41), // "std::vector<action_msgs::msg:..."
QT_MOC_LITERAL(24, 401, 11), // "status_list"
QT_MOC_LITERAL(25, 413, 15), // "checkGoalStatus"
QT_MOC_LITERAL(26, 429, 12), // "globalStatus"
QT_MOC_LITERAL(27, 442, 11), // "localStatus"
QT_MOC_LITERAL(28, 454, 9) // "startSpin"

    },
    "rviz_multi_goals_manager_plugins::MultiNaviGoalsPanel\0"
    "setMaxNumGoal\0\0maxNumGoal\0writePose\0"
    "geometry_msgs::msg::Pose\0pose\0markPose\0"
    "geometry_msgs::msg::PoseStamped\0"
    "deleteMark\0changeEvent\0initPoseTable\0"
    "updatePoseTable\0startNavi\0goalCntCB\0"
    "statusGlobalPoseCB\0rover_msgs::msg::RoverGoalStatus\0"
    "poseStatus\0statusLocalPoseCB\0checkCycle\0"
    "completeNavi\0cycleNavi\0checkGoal\0"
    "std::vector<action_msgs::msg::GoalStatus>\0"
    "status_list\0checkGoalStatus\0globalStatus\0"
    "localStatus\0startSpin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rviz_multi_goals_manager_plugins__MultiNaviGoalsPanel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x0a /* Public */,
       4,    1,  102,    2, 0x0a /* Public */,
       7,    1,  105,    2, 0x0a /* Public */,
       9,    0,  108,    2, 0x0a /* Public */,
      10,    0,  109,    2, 0x09 /* Protected */,
      11,    0,  110,    2, 0x09 /* Protected */,
      12,    0,  111,    2, 0x09 /* Protected */,
      13,    0,  112,    2, 0x09 /* Protected */,
      14,    1,  113,    2, 0x09 /* Protected */,
      15,    1,  116,    2, 0x09 /* Protected */,
      18,    1,  119,    2, 0x09 /* Protected */,
      19,    0,  122,    2, 0x09 /* Protected */,
      20,    0,  123,    2, 0x09 /* Protected */,
      21,    0,  124,    2, 0x09 /* Protected */,
      22,    1,  125,    2, 0x09 /* Protected */,
      25,    2,  128,    2, 0x09 /* Protected */,
      28,    0,  133,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    6,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 23,   24,
    QMetaType::Bool, 0x80000000 | 16, 0x80000000 | 16,   26,   27,
    QMetaType::Void,

       0        // eod
};

void rviz_multi_goals_manager_plugins::MultiNaviGoalsPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MultiNaviGoalsPanel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setMaxNumGoal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->writePose((*reinterpret_cast< geometry_msgs::msg::Pose(*)>(_a[1]))); break;
        case 2: _t->markPose((*reinterpret_cast< const geometry_msgs::msg::PoseStamped(*)>(_a[1]))); break;
        case 3: _t->deleteMark(); break;
        case 4: _t->changeEvent(); break;
        case 5: _t->initPoseTable(); break;
        case 6: _t->updatePoseTable(); break;
        case 7: _t->startNavi(); break;
        case 8: _t->goalCntCB((*reinterpret_cast< const geometry_msgs::msg::PoseStamped(*)>(_a[1]))); break;
        case 9: _t->statusGlobalPoseCB((*reinterpret_cast< const rover_msgs::msg::RoverGoalStatus(*)>(_a[1]))); break;
        case 10: _t->statusLocalPoseCB((*reinterpret_cast< const rover_msgs::msg::RoverGoalStatus(*)>(_a[1]))); break;
        case 11: _t->checkCycle(); break;
        case 12: _t->completeNavi(); break;
        case 13: _t->cycleNavi(); break;
        case 14: { bool _r = _t->checkGoal((*reinterpret_cast< std::vector<action_msgs::msg::GoalStatus>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->checkGoalStatus((*reinterpret_cast< rover_msgs::msg::RoverGoalStatus(*)>(_a[1])),(*reinterpret_cast< rover_msgs::msg::RoverGoalStatus(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->startSpin(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject rviz_multi_goals_manager_plugins::MultiNaviGoalsPanel::staticMetaObject = { {
    QMetaObject::SuperData::link<rviz_common::Panel::staticMetaObject>(),
    qt_meta_stringdata_rviz_multi_goals_manager_plugins__MultiNaviGoalsPanel.data,
    qt_meta_data_rviz_multi_goals_manager_plugins__MultiNaviGoalsPanel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *rviz_multi_goals_manager_plugins::MultiNaviGoalsPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rviz_multi_goals_manager_plugins::MultiNaviGoalsPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rviz_multi_goals_manager_plugins__MultiNaviGoalsPanel.stringdata0))
        return static_cast<void*>(this);
    return rviz_common::Panel::qt_metacast(_clname);
}

int rviz_multi_goals_manager_plugins::MultiNaviGoalsPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = rviz_common::Panel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
