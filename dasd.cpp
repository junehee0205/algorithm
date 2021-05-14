
#include <iostream> //  C++에선 <iostream>에 정의되어 있는 std::를 이용해서 입출력을 사용한다.

int main() {
    // 배열 포인터 : 배열을 가리키는 포인터. 연속적인 메모리만 가리킬 수 있다.
    // 포인터 배열 : 배열에 메모리 주소 값을 저장할 수 있는 배열. 즉 포인터들이 배열이다.

    /*
        1. ptr == &ptr[0]
        2. *ptr = ptr[0]
        3. ptr + 1 = ptr 에 sizeof(*ptr)을 더한 값
    */

    int arr[5] = {1,2,3,4,5};

    int(*ptr_arr)[5]; // int형 타입의 인덱스를 5개 가지고 있는 배열을 가리키는 배열 포인터를 선언
    ptr_arr = &arr;

    printf("\n***** 배열 포인터 *****\n");

    // 배열의 주소를 가진 포인터는 +1 / -1 연산으로 어느 원소든 쉽게 접근이 가능하다.
    // 포인터에 1을 더했지만 주소는 배열의 단위인 int(4byte) 만큼 더해진 것을 확인할 수 있다.
    std::cout << "arr[0] 주소 값 :: " << *ptr_arr << "\n";
    std::cout << "arr[1] 주소 값 :: " << *(ptr_arr + 1) << "\n";
    std::cout << "arr[2] 주소 값 :: " << *(ptr_arr + 2) << "\n";
    std::cout << "arr[3] 주소 값 :: " << *(ptr_arr + 3) << "\n";
    std::cout << "arr[4] 주소 값 :: " << *(ptr_arr + 4) << "\n\n";

    // 입력은 std::cin >> "변수" ,  출력을 std::cout << "변수 or 문자열", 문자열 변경은 std::endl;로 사용

    for (int i = 0; i < 5; i++) {
        printf("arr[%d] 주소 값 :: %p\n",i, ptr_arr[i]);
    }
    printf("\n");

    for (int i = 0; i < 5; i++) {
        printf("%d\n", (*ptr_arr)[i]);
    }

    // 포인터 배열
    int* ptr[5]; // 포인터 배열 선언

    for (int i = 0; i < 5; i++) {
        ptr[i] = &arr[i];
    }

    printf("\n***** 포인터 배열 *****\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] 주소 값 :: %p\n", i, ptr[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("arr[%d] 값 :: %d\n", i, *ptr[i]);
    }
    printf("\n");


    printf("\n***** 2차원 배열을 포인터에 넣기 *********\n");
     
    // 2차원 배열을 포인터에 넣기

    int Arr[2][3] = { {1,2,3},{4,5,6} };

    // 포인터 선언 : 자료형 (*포인터이름)[가로크기]
    int (*Ptr)[3] = Arr; // Ptr 은 행 전체를 가리키는 포인터 (가로크기가 4인 배열을 가리키는 포인터)

    printf("%p\n", *Ptr);
    printf("%p\n", *Arr);
    printf("%d\n", Ptr[1][1]);
    printf("%d\n", sizeof(Arr)); // 결과 : 4 X 5 = 20
    printf("%d\n", sizeof(Ptr));  // 결과 : 4
    printf("\n");

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", Ptr[i][j]);
        }
        printf("\n");
    }

    printf("**************\n");
    for (int(*row)[3] = Arr; row < Arr + 2; row++) {
        for (int *col = *row; col < *row + 3; col++) {
            printf("%d ", *col);
        }
        printf("\n");
    }
 
} 