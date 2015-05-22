#pragma warning (disable : 4786)
#include <map>
#include <string>
#include <iostream>

class CIniFile  
{
public:
        CIniFile(const std::string &filename);
        CIniFile(const char * buf, unsigned long size)
        {
                FromString(buf,size);
        };
        virtual ~CIniFile();
        static long GetIniFileInt(
                const char * lpAppName,  // section name
                const char * lpKeyName,  // key name
                long nDefault,       // return value if key name not found
                const char * lpFileName  // initialization file name
                );
        
        static unsigned long GetIniFileString(
                const char *  lpAppName,        // section name
                const char *  lpKeyName,        // key name
                const char *  lpDefault,        // default string
                char *  lpReturnedString,  // destination buffer
                unsigned long nSize,              // size of destination buffer
                const char *  lpFileName        // initialization file name
                );
        
        long GetIniFileInt(
                const char * section,  // section name
                const char * key,  // key name
                long defaultvalue       // return value if key name not found
                );

        unsigned long GetIniFileString(
                const char *  section,        // section name
                const char *  key,        // key name
                const char *  defaultstring,        // default string
                char *  destination,  // destination buffer
                unsigned long size              // size of destination buffer
                );
private:
        void FromString(const char * buf, unsigned long size);
        typedef std::map<const std::string, std::string> KEY_VALUE;
        typedef std::map< const std::string, KEY_VALUE > SECTION_KEY ;
        SECTION_KEY _buf;
};

