#pragma once
#include <iostream>
#include <string>
#include <map>
#include <queue>

namespace Registry
{
    class Content
    {
    public:
        Content(std::string name);
        ~Content();
        std::string getName();
        virtual void load();
        virtual void unload();
    protected:
        std::string name;
        bool loaded;
    };

    class ContentRegistry
    {
    public:
        Content* getContentByName(std::string name);
        void registerContent(Content* content);
        void unregisterContent(Content* content);
        std::queue<Content*>* makeQueue();
    private:
        std::map<std::string, Content*> content;
    };

    extern ContentRegistry master;
};
