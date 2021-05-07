#include "stdafx.h"

// DELETE THIS COMMENT BLOCK OR USE WHAT IS IN IT!
// Use the following line to make a windows program with main startup (rather than a console program)
// Remove the /entry part if you want to use WinMain instead...
//
//#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup")
//
//
// This is the syntax for including libraries:
//
//#pragma comment(lib,"comctl32.lib")

std::string GetLastErrorAsString(DWORD error)
{
    if (error == 0) {
        return std::string(); //No error message has been recorded
    }

    LPSTR messageBuffer = nullptr;

    //Ask Win32 to give us the string version of that message ID.
    //The parameters we pass in, tell Win32 to create the buffer that holds the message for us (because we don't yet know how long the message string will be).
    size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, error, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

    //Copy the error message into a std::string.
    std::string message(messageBuffer, size);

    //Free the Win32's string's buffer.
    LocalFree(messageBuffer);

    return message;
}

#define P(x)  error = GetLastErrorAsString(x); std::cout << error << std::endl;



int main()
{
    std::string error;

    P(WSAEWOULDBLOCK);
    P(WSAEINPROGRESS);
    P(WSAEALREADY);
    P(WSAENOTSOCK);
    P(WSAEDESTADDRREQ);
    P(WSAEMSGSIZE);
    P(WSAEPROTOTYPE);
    P(WSAENOPROTOOPT);
    P(WSAEPROTONOSUPPORT);
    P(WSAESOCKTNOSUPPORT);
    P(WSAEOPNOTSUPP);
    P(WSAEPFNOSUPPORT);
    P(WSAEAFNOSUPPORT);
    P(WSAEADDRINUSE);
    P(WSAEADDRNOTAVAIL);
    P(WSAENETDOWN);
    P(WSAENETUNREACH);
    P(WSAENETRESET);
    P(WSAECONNABORTED);
    P(WSAECONNRESET);
    P(WSAENOBUFS);
    P(WSAEISCONN);
    P(WSAENOTCONN);
    P(WSAESHUTDOWN);
    P(WSAETOOMANYREFS);
    P(WSAETIMEDOUT);
    P(WSAECONNREFUSED);
    P(WSAELOOP);
    P(WSAENAMETOOLONG);
    P(WSAEHOSTDOWN);
    P(WSAEHOSTUNREACH);
    P(WSAENOTEMPTY);
    P(WSAEPROCLIM);
    P(WSAEUSERS);
    P(WSAEDQUOT);
    P(WSAESTALE);
    P(WSAEREMOTE);
}
