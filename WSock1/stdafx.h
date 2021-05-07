#include <WinSock2.h>
#include <windows.h>
#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <thread>
#include <future>
#include <deque>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <locale>
#include <functional>
// basic exception handler class:
struct QException : public std::exception
{
    QException(std::string msg) : std::exception(msg.c_str()) {}
    QException(char *msg) : std::exception(msg) {}
    virtual ~QException() {}
};
