#include "FileManager.h"

FileManager::FileManager()
{
    identifierFound = false;
}

FileManager::~FileManager() {}

void FileManager::LoadContent(const char *filename,
                              std::vector<std::vector<std::string> > &attributes,
                              std::vector<std::vector<std::string> > &contents)
{
    std::string line,newLine;
    std::ifstream openfile(filename);
    if(openfile.is_open())
    {
        while(!openfile.eof())
        {
            std::stringstream str;
            std::getline(openfile, line);

            if(line.find("Load=")!= std::string::npos)
            {
                type = Atrributes;
                line = line.erase(0, line.find("=")+1);
                tempAttributes.clear();
            }
            else
            {
                type = Contents;
                tempContents.clear();
            }
            str<<line;

            while(std::getline(str, newLine,']'))
            {
                newLine.erase(std::remove(newLine.begin(),newLine.end(), '['), newLine.end());
                std::string erasi =  " \t\n\r";
                newLine.erase(newLine.find_last_not_of(erasi)+1);

                if(type == Atrributes)
                    tempAttributes.push_back(newLine);
                else
                    tempContents.push_back(newLine);

            }
            if(type == Contents && tempContents.size()>0 )
            {
                attributes.push_back(tempAttributes);
                contents.push_back(tempContents);
            }
        }
    }
}

void FileManager::LoadContent(const char *filename,
                              std::vector<std::vector<std::string> > &attributes,
                              std::vector<std::vector<std::string> > &contents,std::string identifier)
{
    std::string line,newLine;
    std::ifstream openfile(filename);
    if(openfile.is_open())
    {
        while(!openfile.eof())
        {
            std::stringstream str;
            std::getline(openfile, line);

            if(line.find("EndLoad=")!=std::string::npos&&line.find(identifier)!= std::string::npos)
            {
                identifierFound = false;
                break;
            }
            else if(line.find("Load=")!=std::string::npos&&line.find(identifier)!=std::string::npos)
            {
                identifierFound = true;
                continue;
            }


            if(identifierFound)
            {
                if(line.find("Load=")!= std::string::npos)
                {

                    type = Atrributes;
                    line = line.erase(0, line.find("=")+1);
                    tempAttributes.clear();
                }
                else
                {

                    type = Contents;
                    tempContents.clear();
                }
                str<<line;


                while(std::getline(str, newLine,']'))
                {
                    newLine.erase(std::remove(newLine.begin(),newLine.end(), '['), newLine.end());
                    std::string erasi =  " \t\n\r";
                    newLine.erase(newLine.find_last_not_of(erasi)+1);

                    if(type == Atrributes)
                    {
                        tempAttributes.push_back(newLine);

                    }
                    else
                        tempContents.push_back(newLine);

                }
                if(type == Contents && tempContents.size()>0 )
                {
                    attributes.push_back(tempAttributes);
                    contents.push_back(tempContents);
                }
            }
        }
    }
}

