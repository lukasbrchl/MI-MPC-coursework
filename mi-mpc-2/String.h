#ifndef STRING_H
#define STRING_H

#include <iosfwd>

class String {
public:
    String();

    String(const String &);

    String &operator=(const String &);

    String(const char *);

    ~String();

    void swap(String &);

    friend std::ostream &operator<<(std::ostream &, const String &);

private:
    class Impl;

    Impl *pimpl_;
};

#endif