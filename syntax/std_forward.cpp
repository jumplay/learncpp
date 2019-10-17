#include <iostream>
#include <string>

void Set(std::string &s)
{
    std::cout << "copy" << std::endl;
}

void Set(std::string &&s)
{
    std::cout << "move" << std::endl;
}

template <typename T>
void Set1(T &&t)
{
    Set(t);
}

template <typename T>
void Set2(T &&t)
{
    Set(std::forward<T>(t));
}

void Run()
{
    Set1("a");
    Set2("a");
    std::string s = "a";
    Set1(s);
    Set2(s);
    Set1(std::move(s));
    Set2(std::move(s));
    // output
    /*
    move
    move
    copy
    copy
    copy
    move
    */
}

int main()
{
    Run();
    
    return 0;
}

