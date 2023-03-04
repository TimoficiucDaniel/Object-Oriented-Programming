
#include "Service.h"

void Service::readFiles() {
    r.readFiles();
}

Service::Service() {
    this->readFiles();
}

void Service::sortFilesByName() {
    for(int i =0; i< r.files.size();i++)
        for(int j= i;j< r.files.size();j++)
            if(r.files[i].name>r.files[j].name)
                std::swap(r.files[i],r.files[j]);
}

bool Service::notRevised(int i) {
    if(r.files[i].status =="not_revised")
        return true;
    return false;
}

bool Service::checkIfValidFile(std::string name) {
    if(name.empty())
        return false;
    for(int i=0;i<r.files.size();i++)
    {
        if(r.files[i].name==name)
            return false;
    }
    return true;
}

void Service::addFile(std::string name,std::string creator) {
    SourceFile s(name,"not_revised",creator,"None");
    r.add(s);
}
