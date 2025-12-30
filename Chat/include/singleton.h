#pragma once

#include <memory>
#include <iostream>
#include <mutex>

// 通过模板来获取某个类的单例
template <typename T>
class Singleton{
protected:
    Singleton() = default;
    // 删除拷贝构造和赋值构造
    Singleton(const Singleton<T>&) = delete;
    Singleton<T>& operator = (const Singleton<T>&) = delete;
    static std::shared_ptr<T> _m_instance;

public:
    // C++11开始，线程安全
    static std::shared_ptr<T> GetInstance(){

        static std::once_flag s_flag;
        std::call_once(s_flag, []() {
            _m_instance = std::shared_ptr<T>(new T); 
            // _m_instance = std::make_shared<T>();  // 若类型T 的构造函数是非 public类型，使用该种方法创建会发生错误,因为此时构造不发生在Singleton<T>的作用域内
            });
        return _m_instance;
    }

    void PrintAddress(){
        std::cout << _m_instance.get() << std::endl;
    }

    ~Singleton(){
        std::cout << "this is singleton destruct !!!" << std::endl;
    }

};

template <typename T>
std::shared_ptr<T> Singleton<T>::_m_instance = nullptr;