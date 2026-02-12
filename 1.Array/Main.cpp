#include <iostream>
#include <cassert>
#include <vector>

// 템플릿으로 배열 만들기.
template<typename T,size_t size = 10> // size_t => unsigned long long

class Array {
public:
    size_t Size() const {
        return size;
    }

    T& operator[](size_t index) {
        
        // 어써트( 꼭 검증이 필요한 구문에 활용).
        // 디버그 모드에서만 동작.
        assert(index < 0 || index >= size);//아래 구문과 동일
        //if (index < 0 || index >= size) 
        //{
        //    __debugbreak();
        //}
        
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

private:
    T data[size] = {};
};


int main() {
    
        
    Array<int,10> array; // size = 10
    //std::cout << array.Size();
    //std::cout << array[0];
    
    //const auto& arrayReference = array;

    std::vector<int> a;
    std::cout << a.size() << " " << sizeof(a) << " " << a.capacity() << std::endl;
                                        //왜 sizeof(a) 32?? 
                                        //=> x64bit 환경이라서 8바이트 포인터 4개 = 32바이트

    return 0;
}