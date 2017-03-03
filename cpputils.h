#include <dirent.h>
#include <stdio.h>
#include <string.h>


class CppUtils
{
private:
    static DIR* cpputils_curr_open_dir;
    static char* filename;
public:
    
//
// Open and iterate through directory contents
//
//    if( CppUtils::openDir( "/path/to/dir" ) )
//    {
//        while( const char* p = CppUtils::iterDir() )
//        {
//            printf("\n FILE: %s", p);
//        }
//        CppUtils::closeDir();
//    }
//
    static int openDir(const char *path)
    {
        closeDir();
        cpputils_curr_open_dir = opendir(path);
        return(cpputils_curr_open_dir == 0?0:1);
    }
    static void closeDir()
    {
        if( cpputils_curr_open_dir )
        {
            closedir(cpputils_curr_open_dir);
        }
    }
    static const char* iterDir()
    {
        struct dirent *dir;
        if ( cpputils_curr_open_dir )
        {
            dir = readdir(cpputils_curr_open_dir);
            if( dir != 0 )
            {
                strcpy(filename, dir->d_name );
                return filename;
            }
        }
        return 0;
    }
};
