#ifndef _BAIDU_SHUTTLE_IO_H_
#define _BAIDU_SHUTTLE_IO_H_
#include <string>
#include "proto/shuttle.pb.h"

namespace baidu {
namespace shuttle {

class FileReader {
public:
    class Iterator {
    public:
        virtual bool Done() = 0;
        virtual void Next() = 0;
        virtual const std::string& Key() = 0;
        virtual const std::string& Value() = 0;
        virtual Status Error() = 0;
        virtual const std::string GetFileName() = 0;
        virtual ~Iterator() { }
    };
    virtual Status Open(const std::string& path, FileSystem::Parama param) = 0;
    virtual Iterator* Scan(const std::string& start_key, const std::string& end_key) = 0;
    virtual Status Close() = 0;
    virtual std::string GetFileName() = 0;
    virtual ~FileReader() { }
};

class FileWriter {
public:
    virtual Status Open(const std::string& path, FileSystem::Param param) = 0;
    virtual Status Put(const std::string& key, const std::string& value) = 0;
    virtual Status Close() = 0;
    virtual ~FileWriter() { }
};

}
}

#endif
