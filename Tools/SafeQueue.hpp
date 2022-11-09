
#pragma once

#include <mutex>
#include <queue>

namespace drasil
{
    template <typename T>
    class SafeQueue
    {
    public:
        SafeQueue() = default;
        ~SafeQueue() = default;

        void Push(T item)
        {
            std::lock_guard<std::mutex> lock(mMutex);
            mQueue.push(item);
        }

        T Pop()
        {
            std::lock_guard<std::mutex> lock(mMutex);
            T item = mQueue.front();
            mQueue.pop();
            return item;
        }

        bool Empty()
        {
            std::lock_guard<std::mutex> lock(mMutex);
            return mQueue.empty();
        }

    private:
        std::queue<T> mQueue;
        std::mutex mMutex;
    };
}
