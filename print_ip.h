#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <tuple>


void print_ip(const std::string& ip)
{
    std::cout << ip << std::endl;
}

template<typename T, typename U = typename std::enable_if<std::is_integral<T>::value, void>::type>
void print_ip(const T& ip)
{
    int ip_copy = static_cast<int>(ip);

    std::cout << ((ip_copy >> 24) & 0xFF) << "."
              << ((ip_copy >> 16) & 0xFF) << "."
              << ((ip_copy >> 8) & 0xFF) << "."
              << ((ip_copy >> 0) & 0xFF) << std::endl;
}

template<typename T>
struct is_container 
{
    static const bool value = false;
};

template<typename U>
struct is_container<std::vector<U>> 
{
    static const bool value = true;
};

template<typename U>
struct is_container<std::list<U>> 
{
    static const bool value = true;
};

template<typename T, typename U = typename std::enable_if<is_container<T>::value, void>::type>
void print_ip(T&& ip)
{
    auto i = 0u;

    for (auto it = ip.begin(); it != ip.end(); ++it) 
    {
        std::cout << *it;

        if (i < sizeof(int) - 1) 
            std::cout << '.';
        else 
            std::cout << std::endl;

        i++;
    }
}

template <typename... Args>
void print_ip(const std::tuple<Args...>& ip)
{
    using T0 = typename std::tuple_element<0, std::tuple<Args...> >::type;
    using T1 = typename std::tuple_element<1, std::tuple<Args...> >::type;
    using T2 = typename std::tuple_element<2, std::tuple<Args...> >::type;
    using T3 = typename std::tuple_element<3, std::tuple<Args...> >::type;

    std::cout << std::get<0>(ip) << ".";
    std::cout << std::get<1>(ip) << ".";
    std::cout << std::get<2>(ip) << ".";
    std::cout << std::get<3>(ip) << std::endl;
}