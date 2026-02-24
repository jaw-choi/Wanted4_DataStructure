#include <iostream>
#include <time.h>

//cam random화할때 (흔들떄 쓰면좋을듯)

//나눗셈을 활용한 랜덤.
int RandomRange(int min, int max)
{
    int diff = (max - min) + 1;

    return (diff * rand()) / (RAND_MAX + 1) + min;
}

//나눗셈을 활용한 랜덤(부동소수형-float).
float RandomPercent()
{
    // 0~1 사이의 부동소수형 값을 반환하는 랜덤 함수.
    return rand() / static_cast<float>(RAND_MAX);
}

//범위를 지정해 사용하는 랜덤 함수(부동소수형).
float RandomRange(float min, float max)
{
    // min - max 사이의 차 구하기.
    int diff = max - min;
    return RandomPercent() * diff + min;
}

int main()
{
    // 종자값(seed) 설정.
    srand(static_cast<unsigned int>(time(nullptr)));

    std::cout << "Random: " << RandomRange(1.f,10.f) << "\n";
    std::cout << "Random: " << RandomRange(1.f,10.f) << "\n";
    std::cout << "Random: " << RandomRange(1.f,10.f) << "\n";
    std::cout << "Random: " << RandomRange(1,100) << "\n";
    std::cout << "Random: " << RandomRange(1,100) << "\n";

    return 0;
}