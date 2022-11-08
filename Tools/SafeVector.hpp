
#pragma once

#include <mutex>
#include <vector>

template <typename T>
class SafeVector
{
public:
    SafeVector() = default;
    ~SafeVector() = default;

    void Push(T item)
    {
        std::lock_guard<std::mutex> lock(mMutex);
        mVector.push_back(item);
    }

    void Remove(T item)
    {
        std::lock_guard<std::mutex> lock(mMutex);
        mVector.erase(std::remove(mVector.begin(), mVector.end(), item),
                      mVector.end());
    }

    // operator []
    T& operator[](int index)
    {
        std::lock_guard<std::mutex> lock(mMutex);
        return mVector[index];
    }

    // size
    int Size()
    {
        std::lock_guard<std::mutex> lock(mMutex);
        return mVector.size();
    }

    // find
    int Find(T item)
    {
        std::lock_guard<std::mutex> lock(mMutex);
        auto it = std::find(mVector.begin(), mVector.end(), item);
        if (it != mVector.end())
        {
            return std::distance(mVector.begin(), it);
        }
        return -1;
    }

private:
    std::vector<T> mVector;
    std::mutex mMutex;
};