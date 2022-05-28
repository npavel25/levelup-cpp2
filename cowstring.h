#ifndef COWSTRING_H
#define COWSTRING_H

#include <cinttypes>


namespace cow
{

    class String
    {
    public:
        String();
        String(char *c_str);
        String(const String &);
        String(String &&);
        ~String();

        const char* c_str();
        int64_t size();
        String& append(const String&);

    private:

        String& _append(const String&); //old append
        void create_copy();

        char* _ptr;
        int64_t _size;
        int64_t _capacity;
        bool isRealCopy;
    };

} // namespace

#endif // COWSTRING_H
