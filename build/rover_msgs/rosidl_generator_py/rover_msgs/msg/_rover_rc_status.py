# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rover_msgs:msg/RoverRCStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RoverRCStatus(type):
    """Metaclass of message 'RoverRCStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'rover_msgs.msg.RoverRCStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__rover_rc_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__rover_rc_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__rover_rc_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__rover_rc_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__rover_rc_status

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RoverRCStatus(metaclass=Metaclass_RoverRCStatus):
    """Message class 'RoverRCStatus'."""

    __slots__ = [
        '_header',
        '_connect',
        '_ch1',
        '_ch2',
        '_ch3',
        '_ch4',
        '_ch5',
        '_ch6',
        '_ch7',
        '_ch8',
        '_ch9',
        '_ch10',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'connect': 'boolean',
        'ch1': 'int8',
        'ch2': 'int8',
        'ch3': 'int8',
        'ch4': 'int8',
        'ch5': 'int8',
        'ch6': 'int8',
        'ch7': 'int8',
        'ch8': 'int8',
        'ch9': 'int8',
        'ch10': 'int8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.connect = kwargs.get('connect', bool())
        self.ch1 = kwargs.get('ch1', int())
        self.ch2 = kwargs.get('ch2', int())
        self.ch3 = kwargs.get('ch3', int())
        self.ch4 = kwargs.get('ch4', int())
        self.ch5 = kwargs.get('ch5', int())
        self.ch6 = kwargs.get('ch6', int())
        self.ch7 = kwargs.get('ch7', int())
        self.ch8 = kwargs.get('ch8', int())
        self.ch9 = kwargs.get('ch9', int())
        self.ch10 = kwargs.get('ch10', int())

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
        if self.header != other.header:
            return False
        if self.connect != other.connect:
            return False
        if self.ch1 != other.ch1:
            return False
        if self.ch2 != other.ch2:
            return False
        if self.ch3 != other.ch3:
            return False
        if self.ch4 != other.ch4:
            return False
        if self.ch5 != other.ch5:
            return False
        if self.ch6 != other.ch6:
            return False
        if self.ch7 != other.ch7:
            return False
        if self.ch8 != other.ch8:
            return False
        if self.ch9 != other.ch9:
            return False
        if self.ch10 != other.ch10:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def connect(self):
        """Message field 'connect'."""
        return self._connect

    @connect.setter
    def connect(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'connect' field must be of type 'bool'"
        self._connect = value

    @builtins.property
    def ch1(self):
        """Message field 'ch1'."""
        return self._ch1

    @ch1.setter
    def ch1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ch1' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'ch1' field must be an integer in [-128, 127]"
        self._ch1 = value

    @builtins.property
    def ch2(self):
        """Message field 'ch2'."""
        return self._ch2

    @ch2.setter
    def ch2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ch2' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'ch2' field must be an integer in [-128, 127]"
        self._ch2 = value

    @builtins.property
    def ch3(self):
        """Message field 'ch3'."""
        return self._ch3

    @ch3.setter
    def ch3(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ch3' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'ch3' field must be an integer in [-128, 127]"
        self._ch3 = value

    @builtins.property
    def ch4(self):
        """Message field 'ch4'."""
        return self._ch4

    @ch4.setter
    def ch4(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ch4' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'ch4' field must be an integer in [-128, 127]"
        self._ch4 = value

    @builtins.property
    def ch5(self):
        """Message field 'ch5'."""
        return self._ch5

    @ch5.setter
    def ch5(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ch5' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'ch5' field must be an integer in [-128, 127]"
        self._ch5 = value

    @builtins.property
    def ch6(self):
        """Message field 'ch6'."""
        return self._ch6

    @ch6.setter
    def ch6(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ch6' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'ch6' field must be an integer in [-128, 127]"
        self._ch6 = value

    @builtins.property
    def ch7(self):
        """Message field 'ch7'."""
        return self._ch7

    @ch7.setter
    def ch7(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ch7' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'ch7' field must be an integer in [-128, 127]"
        self._ch7 = value

    @builtins.property
    def ch8(self):
        """Message field 'ch8'."""
        return self._ch8

    @ch8.setter
    def ch8(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ch8' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'ch8' field must be an integer in [-128, 127]"
        self._ch8 = value

    @builtins.property
    def ch9(self):
        """Message field 'ch9'."""
        return self._ch9

    @ch9.setter
    def ch9(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ch9' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'ch9' field must be an integer in [-128, 127]"
        self._ch9 = value

    @builtins.property
    def ch10(self):
        """Message field 'ch10'."""
        return self._ch10

    @ch10.setter
    def ch10(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ch10' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'ch10' field must be an integer in [-128, 127]"
        self._ch10 = value
