# cpputils
Simple utility functions for my C/C++ projects mostly in POSIX environments.

Simple to use:
DIRECTORY FILES ITERATION EXAMPLE:
#include "cpputils.h"

void foo()
{
    if( CppUtils::openDir( "/path/to/dir" ) )
    {
        while( const char* p = CppUtils::iterDir() )
        {
            printf("\n FILE: %s", p);
        }
        CppUtils::closeDir();
    }
}
