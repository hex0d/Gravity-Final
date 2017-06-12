#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

class FileManager
{
public:
    FileManager();
    virtual ~FileManager();
    void LoadContent(const char *filename,
                     std::vector<std::vector<std::string> > &attributes,
                     std::vector<std::vector<std::string> > &contents);
    void LoadContent(const char *filename,
                     std::vector<std::vector<std::string> > &attributes,
                     std::vector<std::vector<std::string> > &contents,std::string identifier);

protected:

private:
    enum LoadType {Atrributes,Contents};
    int type;
    bool identifierFound;
    std::vector<std::string> tempContents;
    std::vector<std::string> tempAttributes;
};
