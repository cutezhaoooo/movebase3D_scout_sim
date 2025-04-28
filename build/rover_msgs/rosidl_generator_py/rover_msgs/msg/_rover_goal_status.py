# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rover_msgs:msg/RoverGoalStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RoverGoalStatus(type):
    """Metaclass of message 'RoverGoalStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'PENDING': 0,
        'ACTIVE': 1,
        'PREEMPTED': 2,
        'SUCCEEDED': 3,
        'ABORTED': 4,
        'REJECTED': 5,
        'PREEMPTING': 6,
        'RECALLING': 7,
        'RECALLED': 8,
        'LOST': 9,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rover_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rover_msgs.msg.RoverGoalStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__rover_goal_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__rover_goal_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__rover_goal_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__rover_goal_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__rover_goal_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'PENDING': cls.__constants['PENDING'],
            'ACTIVE': cls.__constants['ACTIVE'],
            'PREEMPTED': cls.__constants['PREEMPTED'],
            'SUCCEEDED': cls.__constants['SUCCEEDED'],
            'ABORTED': cls.__constants['ABORTED'],
            'REJECTED': cls.__constants['REJECTED'],
            'PREEMPTING': cls.__constants['PREEMPTING'],
            'RECALLING': cls.__constants['RECALLING'],
            'RECALLED': cls.__constants['RECALLED'],
            'LOST': cls.__constants['LOST'],
        }

    @property
    def PENDING(self):
        """Message constant 'PENDING'."""
        return Metaclass_RoverGoalStatus.__constants['PENDING']

    @property
    def ACTIVE(self):
        """Message constant 'ACTIVE'."""
        return Metaclass_RoverGoalStatus.__constants['ACTIVE']

    @property
    def PREEMPTED(self):
        """Message constant 'PREEMPTED'."""
        return Metaclass_RoverGoalStatus.__constants['PREEMPTED']

    @property
    def SUCCEEDED(self):
        """Message constant 'SUCCEEDED'."""
        return Metaclass_RoverGoalStatus.__constants['SUCCEEDED']

    @property
    def ABORTED(self):
        """Message constant 'ABORTED'."""
        return Metaclass_RoverGoalStatus.__constants['ABORTED']

    @property
    def REJECTED(self):
        """Message constant 'REJECTED'."""
        return Metaclass_RoverGoalStatus.__constants['REJECTED']

    @property
    def PREEMPTING(self):
        """Message constant 'PREEMPTING'."""
        return Metaclass_RoverGoalStatus.__constants['PREEMPTING']

    @property
    def RECALLING(self):
        """Message constant 'RECALLING'."""
        return Metaclass_RoverGoalStatus.__constants['RECALLING']

    @property
    def RECALLED(self):
        """Message constant 'RECALLED'."""
        return Metaclass_RoverGoalStatus.__constants['RECALLED']

    @property
    def LOST(self):
        """Message constant 'LOST'."""
        return Metaclass_RoverGoalStatus.__constants['LOST']


class RoverGoalStatus(metaclass=Metaclass_RoverGoalStatus):
    """
    Message class 'RoverGoalStatus'.

    Constants:
      PENDING
      ACTIVE
      PREEMPTED
      SUCCEEDED
      ABORTED
      REJECTED
      PREEMPTING
      RECALLING
      RECALLED
      LOST
    """

    __slots__ = [
        '_x',
        '_y',
        '_z',
        '_orientation_x',
        '_orientation_y',
        '_orientation_z',
        '_orientation_w',
        '_status',
        '_goal_id',
        '_text',
    ]

    _fields_and_field_types = {
        'x': 'double',
        'y': 'double',
        'z': 'double',
        'orientation_x': 'double',
        'orientation_y': 'double',
        'orientation_z': 'double',
        'orientation_w': 'double',
        'status': 'uint8',
        'goal_id': 'uint8',
        'text': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.x = kwargs.get('x', float())
        self.y = kwargs.get('y', float())
        self.z = kwargs.get('z', float())
        self.orientation_x = kwargs.get('orientation_x', float())
        self.orientation_y = kwargs.get('orientation_y', float())
        self.orientation_z = kwargs.get('orientation_z', float())
        self.orientation_w = kwargs.get('orientation_w', float())
        self.status = kwargs.get('status', int())
        self.goal_id = kwargs.get('goal_id', int())
        self.text = kwargs.get('text', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.z != other.z:
            return False
        if self.orientation_x != other.orientation_x:
            return False
        if self.orientation_y != other.orientation_y:
            return False
        if self.orientation_z != other.orientation_z:
            return False
        if self.orientation_w != other.orientation_w:
            return False
        if self.status != other.status:
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.text != other.text:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._y = value

    @builtins.property
    def z(self):
        """Message field 'z'."""
        return self._z

    @z.setter
    def z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._z = value

    @builtins.property
    def orientation_x(self):
        """Message field 'orientation_x'."""
        return self._orientation_x

    @orientation_x.setter
    def orientation_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'orientation_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'orientation_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._orientation_x = value

    @builtins.property
    def orientation_y(self):
        """Message field 'orientation_y'."""
        return self._orientation_y

    @orientation_y.setter
    def orientation_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'orientation_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'orientation_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._orientation_y = value

    @builtins.property
    def orientation_z(self):
        """Message field 'orientation_z'."""
        return self._orientation_z

    @orientation_z.setter
    def orientation_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'orientation_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'orientation_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._orientation_z = value

    @builtins.property
    def orientation_w(self):
        """Message field 'orientation_w'."""
        return self._orientation_w

    @orientation_w.setter
    def orientation_w(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'orientation_w' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'orientation_w' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._orientation_w = value

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'status' field must be an unsigned integer in [0, 255]"
        self._status = value

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'goal_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'goal_id' field must be an unsigned integer in [0, 255]"
        self._goal_id = value

    @builtins.property
    def text(self):
        """Message field 'text'."""
        return self._text

    @text.setter
    def text(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'text' field must be of type 'str'"
        self._text = value
