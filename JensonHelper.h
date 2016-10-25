#ifndef JENSONHELPER_H
#define JENSONHELPER_H

#define STANDARD_GETSET(TYPE, MEMBERNAME) \
    private: TYPE _##MEMBERNAME; \
    public: \
    TYPE MEMBERNAME() const { \
        return _##MEMBERNAME; \
    }; \
    void set##MEMBERNAME(TYPE value) { \
        _##MEMBERNAME = value; \
    }

// Convenience macro for POCO objects
#define STANDARD_PROPERTY_GETSET(TYPE, MEMBERNAME) \
    Q_PROPERTY(TYPE MEMBERNAME READ MEMBERNAME WRITE set##MEMBERNAME CONSTANT) \
    STANDARD_GETSET(TYPE, MEMBERNAME)

#define QOBJECT_GETSET(TYPE, MEMBERNAME) \
    private: TYPE* _##MEMBERNAME = nullptr; \
    public: \
    TYPE* MEMBERNAME() const { \
        return _##MEMBERNAME; \
    }; \
    void set##MEMBERNAME(TYPE* value) { \
        if (_##MEMBERNAME != nullptr) \
        { \
            _##MEMBERNAME->deleteLater(); \
            _##MEMBERNAME = nullptr; \
        } \
        _##MEMBERNAME = value; \
        _##MEMBERNAME->setParent(this); \
    }

#define QOBJECT_PROPERTY_GETSET(TYPE, MEMBERNAME) \
    Q_PROPERTY(TYPE* MEMBERNAME READ MEMBERNAME WRITE set##MEMBERNAME CONSTANT) \
    QOBJECT_GETSET(TYPE, MEMBERNAME)

#endif // JENSONHELPER_H