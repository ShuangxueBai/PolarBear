//! Polar Bear
#ifndef POLAR_BEAR_DEFINE_H
#define POLAR_BEAR_DEFINE_H

#define POLAR_BEAR_BEGIN namespace PolarBear {
#define POLAR_BEAR_END }
#define POLAR_BEAR_USE_NAMESPACE using namespace PolarBear

#define PB_DELETE_PTR(x) do { if(x){ delete x; } x = nullptr; }while (0)         

#define PB_DELETE_ARRAY(x) do { if(x) { delete[] x; } x = nullptr; }while (0)

#define PB_TEXT(s) #s

#define PB_INTERFACE struct

#define PB_DECLARE_NO_COPY(classname) \
	classname(const classname& other) = delete; \
	classname& operator=(const classname& other) = delete;

#define PB_DECLARE_NO_MOVE(classname) \
	classname(classname&& other) = delete; \
	classname& operator=(classname&& other) = delete;

#define PB_DECLARE_NO_COPY_MOVE(classname) \
    PB_DECLARE_NO_COPY(classname) \
    PB_DECLARE_NO_MOVE(classname)

#define PB_DECLARE_CLASS_SET_PROPERTY(type, name) \
    inline void set##name##(const type##& value);

#define PB_DECLARE_CLASS_GET_PROPERTY(type, name) \
    inline const type get##name##();

#define PB_DECLARE_CLASS_GET_PROPERTY_REF(type, name) \
    inline type##& get##name##();

#define PB_DECLARE_CLASS_GET_PROPERTY_PTR(type, name) \
    inline type##* get##name##();


#define PB_CLASS_SET_PROPERTY(type, name) \
    void set##name##(const type##& value) { _##name## = value; }

#define PB_CLASS_GET_PROPERTY(type, name) \
    const type get##name##() { return _##name##; }

#define PB_CLASS_GET_PROPERTY_REF(type, name) \
    type##& get##name##() { return _##name##; }

#define PB_CLASS_GET_PROPERTY_PTR(type, name) \
    type##* get##name##() { return &_##name##; }

#define PB_DECLARE_CLASS(className) class className
#define PB_DECLARE_STRUCT(structName) struct structName



#endif
