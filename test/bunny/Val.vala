namespace bunny {
    /**
     * Val
     *  
     * a Variant style type to hold a primitive value 
     */

    public class Val : Object {
        public G_TYPE type;
        public char charValue;
        public bool boolValue;
        public int intValue;
        public uint uintValue;
        public long longValue;
        public ulong ulongValue;
        public int64 int64Value;
        public uint64 uint64Value;
        public float floatValue;
        public double doubleValue;
        public string stringValue;

        public Val() {
        }
        public bool eq(Val other) {
            if (type == other.type) {
                switch(type) {
                    case G_TYPE.G_TYPE_CHAR: return charValue == other.charValue;
                    case G_TYPE.G_TYPE_BOOLEAN: return boolValue == other.boolValue;
                    case G_TYPE.G_TYPE_INT: return intValue == other.intValue;
                    case G_TYPE.G_TYPE_UINT: return uintValue == other.uintValue;
                    case G_TYPE.G_TYPE_LONG: return longValue == other.longValue;
                    case G_TYPE.G_TYPE_ULONG: return ulongValue == other.ulongValue;
                    case G_TYPE.G_TYPE_INT64: return int64Value == other.int64Value;
                    case G_TYPE.G_TYPE_UINT64: return uint64Value == other.uint64Value;
                    case G_TYPE.G_TYPE_FLOAT: return floatValue == other.floatValue;
                    case G_TYPE.G_TYPE_DOUBLE: return doubleValue == other.doubleValue;
                    case G_TYPE.G_TYPE_STRING: return stringValue == other.stringValue;
                    default: return false;
                }
            } else {
                return false;
            }

        }
        public bool ne(Val other) {
            if (type == other.type) {
                switch(type) {
                    case G_TYPE.G_TYPE_CHAR: return charValue != other.charValue;
                    case G_TYPE.G_TYPE_BOOLEAN: return boolValue != other.boolValue;
                    case G_TYPE.G_TYPE_INT: return intValue != other.intValue;
                    case G_TYPE.G_TYPE_UINT: return uintValue != other.uintValue;
                    case G_TYPE.G_TYPE_LONG: return longValue != other.longValue;
                    case G_TYPE.G_TYPE_ULONG: return ulongValue != other.ulongValue;
                    case G_TYPE.G_TYPE_INT64: return int64Value != other.int64Value;
                    case G_TYPE.G_TYPE_UINT64: return uint64Value != other.uint64Value;
                    case G_TYPE.G_TYPE_FLOAT: return floatValue != other.floatValue;
                    case G_TYPE.G_TYPE_DOUBLE: return doubleValue != other.doubleValue;
                    case G_TYPE.G_TYPE_STRING: return stringValue != other.stringValue;
                    default: return false;
                }
            } else {
                return false;
            }
        }
        public bool le(Val other) {
            if (type == other.type) {
                switch(type) {
                    case G_TYPE.G_TYPE_CHAR: return charValue <= other.charValue;
                    case G_TYPE.G_TYPE_INT: return intValue <= other.intValue;
                    case G_TYPE.G_TYPE_UINT: return uintValue <= other.uintValue;
                    case G_TYPE.G_TYPE_LONG: return longValue <= other.longValue;
                    case G_TYPE.G_TYPE_ULONG: return ulongValue <= other.ulongValue;
                    case G_TYPE.G_TYPE_INT64: return int64Value <= other.int64Value;
                    case G_TYPE.G_TYPE_UINT64: return uint64Value <= other.uint64Value;
                    case G_TYPE.G_TYPE_FLOAT: return floatValue <= other.floatValue;
                    case G_TYPE.G_TYPE_DOUBLE: return doubleValue <= other.doubleValue;
                    case G_TYPE.G_TYPE_STRING: return stringValue <= other.stringValue;
                    default: return false;
                }
            } else {
                return false;
            }
        }
        public bool lt(Val other) {
            if (type == other.type) {
                switch(type) {
                    case G_TYPE.G_TYPE_CHAR: return charValue < other.charValue;
                    case G_TYPE.G_TYPE_INT: return intValue < other.intValue;
                    case G_TYPE.G_TYPE_UINT: return uintValue < other.uintValue;
                    case G_TYPE.G_TYPE_LONG: return longValue < other.longValue;
                    case G_TYPE.G_TYPE_ULONG: return ulongValue < other.ulongValue;
                    case G_TYPE.G_TYPE_INT64: return int64Value < other.int64Value;
                    case G_TYPE.G_TYPE_UINT64: return uint64Value < other.uint64Value;
                    case G_TYPE.G_TYPE_FLOAT: return floatValue < other.floatValue;
                    case G_TYPE.G_TYPE_DOUBLE: return doubleValue < other.doubleValue;
                    case G_TYPE.G_TYPE_STRING: return stringValue < other.stringValue;
                    default: return false;
                }
            } else {
                return false;
            }
        }
        
        public bool ge(Val other) {
            if (type == other.type) {
                switch(type) {
                    case G_TYPE.G_TYPE_CHAR: return charValue >= other.charValue;
                    case G_TYPE.G_TYPE_INT: return intValue >= other.intValue;
                    case G_TYPE.G_TYPE_UINT: return uintValue >= other.uintValue;
                    case G_TYPE.G_TYPE_LONG: return longValue >= other.longValue;
                    case G_TYPE.G_TYPE_ULONG: return ulongValue >= other.ulongValue;
                    case G_TYPE.G_TYPE_INT64: return int64Value >= other.int64Value;
                    case G_TYPE.G_TYPE_UINT64: return uint64Value >= other.uint64Value;
                    case G_TYPE.G_TYPE_FLOAT: return floatValue >= other.floatValue;
                    case G_TYPE.G_TYPE_DOUBLE: return doubleValue >= other.doubleValue;
                    case G_TYPE.G_TYPE_STRING: return stringValue >= other.stringValue;
                    default: return false;
                }
            } else {
                return false;
            }
        }
        public bool gt(Val other) {
            if (type == other.type) {
                switch(type) {
                    case G_TYPE.G_TYPE_CHAR: return charValue > other.charValue;
                    case G_TYPE.G_TYPE_INT: return intValue > other.intValue;
                    case G_TYPE.G_TYPE_UINT: return uintValue > other.uintValue;
                    case G_TYPE.G_TYPE_LONG: return longValue > other.longValue;
                    case G_TYPE.G_TYPE_ULONG: return ulongValue > other.ulongValue;
                    case G_TYPE.G_TYPE_INT64: return int64Value > other.int64Value;
                    case G_TYPE.G_TYPE_UINT64: return uint64Value > other.uint64Value;
                    case G_TYPE.G_TYPE_FLOAT: return floatValue > other.floatValue;
                    case G_TYPE.G_TYPE_DOUBLE: return doubleValue > other.doubleValue;
                    case G_TYPE.G_TYPE_STRING: return stringValue > other.stringValue;
                    default: return false;
                }
            } else {
                return false;
            }
        }
        public static Val Bool(bool value) {
            var v = new Val();
            v.boolValue = value;
            v.type = G_TYPE.G_TYPE_BOOLEAN;
            return v;
        }
        
        public static Val Char(char value) {
            var v = new Val();
            v.charValue = value;
            v.type = G_TYPE.G_TYPE_CHAR;
            return v;
        }
        
        public static Val Int(int value) {
            var v = new Val();
            v.intValue = value;
            v.type = G_TYPE.G_TYPE_INT;
            return v;
        }
        
        public static Val Uint(uint value) {
            var v = new Val();
            v.uintValue = value;
            v.type = G_TYPE.G_TYPE_UINT;
            return v;
        }
        
        public static Val Long(long value) {
            var v = new Val();
            v.longValue = value;
            v.type = G_TYPE.G_TYPE_LONG;
            return v;
        }
        
        public static Val Ulong(ulong value) {
            var v = new Val();
            v.ulongValue = value;
            v.type = G_TYPE.G_TYPE_ULONG;
            return v;
        }
        
        public static Val Int64(int64 value) {
            var v = new Val();
            v.int64Value = value;
            v.type = G_TYPE.G_TYPE_INT64;
            return v;
        }
        
        public static Val Uint64(uint64 value) {
            var v = new Val();
            v.uint64Value = value;
            v.type = G_TYPE.G_TYPE_UINT64;
            return v;
        }
        
        public static Val Float(float value) {
            var v = new Val();
            v.floatValue = value;
            v.type = G_TYPE.G_TYPE_FLOAT;
            return v;
        }

        public static Val String(string value) {
            var v = new Val();
            v.stringValue = value;
            v.type = G_TYPE.G_TYPE_STRING;
            return v;
        }

        public static Val Double(double value) {
            var v = new Val();
            v.doubleValue = value;
            v.type = G_TYPE.G_TYPE_DOUBLE;
            return v;
        }

    }
    public enum G_TYPE {

        G_TYPE_INVALID,
        G_TYPE_NONE,
        G_TYPE_INTERFACE,
        G_TYPE_CHAR,
        G_TYPE_UCHAR,
        G_TYPE_BOOLEAN,
        G_TYPE_INT,
        G_TYPE_UINT,
        G_TYPE_LONG,
        G_TYPE_ULONG,
        G_TYPE_INT64,
        G_TYPE_UINT64,
        G_TYPE_ENUM,
        G_TYPE_FLAGS,
        G_TYPE_FLOAT,
        G_TYPE_DOUBLE,
        G_TYPE_STRING,
        G_TYPE_POINTER,
        G_TYPE_BOXED,
        G_TYPE_PARAM,
        G_TYPE_OBJECT,
        G_TYPE_VARIANT
        
    }
    
}
