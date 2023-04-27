
#pragma once

#ifdef _WIN32
// include HMODULE
#include <Windows.h>
#endif

#ifdef __unix__
#include <dlfcn.h>
#endif

#include <stdexcept>
#include <string>
// include runtime error

namespace drasil
{
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
#ifdef _WIN32
            m_handle = LoadLibrary(path.c_str());
            if (!m_handle)
                throw std::runtime_error(
                    "DynamicLoader: Failed to open library");
#endif

#ifdef __unix__
            m_handle = dlopen(path.c_str(), RTLD_LAZY);
            if (!m_handle)
                throw std::runtime_error(
                    "DynamicLoader: Failed to open library");
#endif
        }

        template <typename T>
        T GetFunction(const std::string& name)
        {
            T func;
            if (!m_handle)
                throw std::runtime_error("DynamicLoader: No library loaded");

#ifdef __unix__
            void* ptr = dlsym(m_handle, name.c_str());

            if (!ptr)
                throw std::runtime_error("DynamicLoader: Function not found");
            func = reinterpret_cast<T>(ptr);
#endif

#ifdef _WIN32
            func = reinterpret_cast<T>(GetProcAddress(m_handle, name.c_str()));
#endif

            return func;
        }

        void Close()
        {
            if (m_handle)
            {
#ifdef __unix__
                dlclose(m_handle);
#endif

#ifdef _WIN32
                FreeLibrary(m_handle);
#endif
            }
            m_handle = nullptr;
        }

    private:
#ifdef _WIN32
        HMODULE m_handle;
#endif

#ifdef __unix__
        void* m_handle;
#endif
    };

}  // namespace drasil
