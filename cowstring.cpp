#include "cowstring.h"
#include <cstring>
#include <iostream>

namespace cow

{

String::String()
: _ptr(nullptr)
, _size(0)
, _capacity(0)
, isRealCopy(true)
{
    std::cout << "String::String()" << std::endl;
}

String::String(char *c_str)
: _ptr(nullptr)
, _size(strlen(c_str))
, _capacity(_size * 2)
, isRealCopy(true)
{
    _ptr = new char[_capacity+1]{};
    strncpy(_ptr, c_str, _capacity);
    std::cout << "String::String(char *c_str)" << std::endl;
}

String::String(const String &other)
: _ptr(nullptr)
, _size(other._size)
, _capacity(other._capacity)
, isRealCopy(false)
{
    _ptr = other._ptr;
    std::cout << "String::String(const String &other)" << std::endl;
    /*if(other._ptr)
    {
        //_ptr = new char[_capacity + 1]{};
        //strncpy(_ptr, other._ptr, _size);
        std::cout << "String::String(const String &other)" << std::endl;

    }*/
    
}

String::String(String &&other)
: _ptr(other._ptr)
, _size(other._size)
, _capacity(other._capacity)
, isRealCopy(other.isRealCopy)
{

    other._size = 0;
    other._capacity = 0;
    other._ptr = nullptr;
    std::cout << "String::String(String &&other)" << std::endl;
}

String::~String()
{
    _size = 0;
    _capacity = 0;
    delete[] _ptr;

    std::cout << "String::~String()" << std::endl;
}

const char* String::c_str() 
{
    return _ptr;
}

int64_t String::size()
{
    return _size;
}

String& String::_append(const String& other)
{
    if(!other._ptr)
        return *this;

    _size += other._size;
    
    if(_capacity < _size)
    {
        _capacity = _size*2;
        char* tmp_ptr = _ptr;
        _ptr = new char[_capacity+1]{};
        strncpy(_ptr, tmp_ptr, _size);
        delete [] tmp_ptr;
    }
    
    strncat(_ptr,other._ptr,other._size);
    return *this;

}

String& String::append(const String& other)
{
    if(isRealCopy)
        return _append(other);
    else
    {
        create_copy();
        return _append(other);

    }
}

void String::create_copy()
{
    char* tmp_ptr = _ptr;
    _ptr = new char[_capacity + 1]{};
    strncpy(_ptr, tmp_ptr, _size);
    isRealCopy = true;

}
} // namespace pn

