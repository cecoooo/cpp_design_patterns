#include "plugin_loader.hpp"

#include <dlfcn.h>
#include <stdexcept>
#include <string>

using RegisterPluginFn = void (*)(ResourceFactory&);

PluginLoader::~PluginLoader()
{
    for (void* handle : handles)
    {
        if (handle)
        {
            dlclose(handle);
        }
    }
}

void PluginLoader::loadPlugin(const std::string& path, ResourceFactory& factory)
{
    void* handle = dlopen(path.c_str(), RTLD_NOW);
    if (!handle)
    {
        throw std::runtime_error(std::string("dlopen failed: ") + dlerror());
    }

    dlerror();

    auto registerFn =
        reinterpret_cast<RegisterPluginFn>(dlsym(handle, "registerPlugin"));

    const char* error = dlerror();
    if (error != nullptr)
    {
        dlclose(handle);
        throw std::runtime_error(std::string("dlsym failed: ") + error);
    }

    registerFn(factory);
    handles.push_back(handle);
}