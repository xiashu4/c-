#define ABCD 2
#include <iostream>

int main()
{

#ifdef ABCD
    std::cout << "1: yes\n";
#else
    std::cout << "1: no\n";
#endif

#ifndef ABCD
    std::cout << "2: no1\n";
#elif ABCD == 2
    std::cout << "2: yes\n";
#else
    std::cout << "2: no2\n";
#endif

#if !defined(DCBA) && (ABCD < 2*4-3)
    std::cout << "3: yes\n";
#endif


    // 注意若编译器不支持 C++23 的 #elifdef/#elifndef 指令则会选择“不期待”块（见后述）。
#ifdef CPU
    std::cout << "4: no1\n";
    #elifdef GPU
        std::cout << "4: no2\n";
    #elifndef RAM
        std::cout << "4: yes\n"; // 期待的块
#else
    std::cout << "4: no!\n"; // 由于跳过未知的指令不期待地选择此块
                             // 并直接从 "#ifdef CPU" “跳”到此 "#else" 块
#endif

// 为修复此问题，我们可以条件性地仅若支持 C++23 指令 #elifdef/#elifndef
// 才定义 ELIFDEF_SUPPORTED 宏。
#if 0
    #elifndef UNDEFINED_MACRO
#define ELIFDEF_SUPPORTED
#else
#endif

#ifdef ELIFDEF_SUPPORTED
#ifdef CPU
    std::cout << "4: no1\n";
    #elifdef GPU
        std::cout << "4: no2\n";
    #elifndef RAM
        std::cout << "4: yes\n"; // 期待的块
#else
    std::cout << "4: no3\n";
#endif
#else // 不支持 #elifdef 时使用累赘的旧 `#elif defined`
#ifdef CPU
    std::cout << "4: no1\n";
#elif defined GPU
    std::cout << "4: no2\n";
#elif !defined RAM
    std::cout << "4: yes\n"; // 期待的块
#else
    std::cout << "4: no3\n";
#endif
#endif
}