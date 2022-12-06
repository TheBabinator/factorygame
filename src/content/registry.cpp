#include "content/registry.hpp"

namespace Registry
{
    ContentRegistry master;

    Content::Content(std::string contentName)
    {
        name = contentName;
        master.registerContent(this);
    }

    Content::~Content()
    {
        master.unregisterContent(this);
        unload();
    }

    std::string Content::getName()
    {
        return name;
    }

    void Content::load()
    {
        std::cout << "loading content " << name << std::endl;
    }

    void Content::unload()
    {
        std::cout << "unloading content " << name << std::endl;
    }

    void ContentRegistry::registerContent(Content* addedContent)
    {
        std::string name = addedContent->getName();
        std::cout << "registering content " << name << std::endl;
        content[name] = addedContent;
    }

    void ContentRegistry::unregisterContent(Content* removedContent)
    {
        std::string name = removedContent->getName();
        std::cout << "unregistering content " << name << std::endl;
        content[name] = nullptr;
    }

    Content* ContentRegistry::getContentByName(std::string name)
    {
        return content[name];
    }

    std::queue<Content*>* ContentRegistry::makeQueue()
    {
        std::queue<Content*>* queue = new std::queue<Content*>();
        for (std::map<std::string, Content*>::iterator i = content.begin(); i != content.end(); ++ i)
        {
            queue->push(i->second);
        }
        return queue;
    }
};

