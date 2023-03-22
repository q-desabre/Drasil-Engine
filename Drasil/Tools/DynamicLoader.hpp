
#pragma once

#include <dlfcn.h>
#include <string>

class DynamicLoader
{
public:
    DynamicLoader() { m_handle = nullptr; }

    DynamicLoader(const std::string& path)
    {
        Close();
        Open(path);
    }

    ~DynamicLoader() { Close(); }

    void Open(const std::string& path)
    {
        Close();
        m_handle = dlopen(path.c_str(), RTLD_LAZY);
        if (!m_handle)
            throw std::runtime_error("DynamicLoader: Failed to open library");
    }

    template <typename T>
    T GetFunction(const std::string& name)
    {
        if (!m_handle)
            throw std::runtime_error("DynamicLoader: No library loaded");
        void* ptr = dlsym(m_handle, name.c_str());
        if (!ptr)
            throw std::runtime_error("DynamicLoader: Function not found");
        T func = reinterpret_cast<T>(ptr);
        return func;
    }

    void Close()
    {
        if (m_handle)
            dlclose(m_handle);
        m_handle = nullptr;
    }

private:
    void* m_handle;
};
