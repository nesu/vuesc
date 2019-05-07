#ifndef METHODREGISTRY_H
#define METHODREGISTRY_H

#include <unordered_map>

class MethodRegistry
{
    private:
        std::unordered_map<std::string, MethodDeclaration*> method_decl_set;

    public:
        MethodDeclaration* get(std::string named, MethodDeclaration* defaulted = nullptr);
        void insert(std::string named, MethodDeclaration * method_decl);
        void remove(std::string named);
};

#endif // !METHODREGISTRY_H
