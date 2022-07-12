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


    // ע������������֧�� C++23 �� #elifdef/#elifndef ָ�����ѡ�񡰲��ڴ����飨����������
#ifdef CPU
    std::cout << "4: no1\n";
    #elifdef GPU
        std::cout << "4: no2\n";
    #elifndef RAM
        std::cout << "4: yes\n"; // �ڴ��Ŀ�
#else
    std::cout << "4: no!\n"; // ��������δ֪��ָ��ڴ���ѡ��˿�
                             // ��ֱ�Ӵ� "#ifdef CPU" ���������� "#else" ��
#endif

// Ϊ�޸������⣬���ǿ��������Եؽ���֧�� C++23 ָ�� #elifdef/#elifndef
// �Ŷ��� ELIFDEF_SUPPORTED �ꡣ
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
        std::cout << "4: yes\n"; // �ڴ��Ŀ�
#else
    std::cout << "4: no3\n";
#endif
#else // ��֧�� #elifdef ʱʹ����׸�ľ� `#elif defined`
#ifdef CPU
    std::cout << "4: no1\n";
#elif defined GPU
    std::cout << "4: no2\n";
#elif !defined RAM
    std::cout << "4: yes\n"; // �ڴ��Ŀ�
#else
    std::cout << "4: no3\n";
#endif
#endif
}