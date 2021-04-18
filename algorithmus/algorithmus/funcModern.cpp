#include "pch.h"
#include "funcModern.h"
#include "BinaryTree.h"

#include <string>
#include <typeinfo>
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

#define DEBUG 1

// define debug macro
#if (DEBUG == 1)
	#define DLOG(x) printf("[%s(line:%d)] %s\n", __FUNCTION__, __LINE__, (x))
#else 
	#define DLOG(x) 
#endif


template<typename I, typename J, typename K>
K add(I i, J j)
{
	return i + j;
}

template<typename I, typename J>
auto add2(I i, J j) -> decltype(i+j)
{
	return i + j;
}


template<typename I>
void myfunc(I i)
{
	if (typeid(i) == typeid(int))
	{
		printf("%d ", (int)i);
	}
	else if (typeid(i) == typeid(float))
	{
		printf("%f ", (float)i);
	}
	else
	{
		printf("%d ", i);
	}
}

funcModern::funcModern()
{
}

funcModern::~funcModern()
{
}

void funcModern::init()
{
	DLOG("");

	for_each_loop();
}


void funcModern::macroKeyword()
{
	DLOG("hello\n");

	// 문자열 리터럴(string literal), 큰 따옴표로 둘러싼 문자의 연속체

	// 컴파일시 파일명을 나타내는 문자열 리터럴로 치환
	// D:\Projects\superngine\algorithmus\algorithmus\algorithmus\funcModern.cpp
	printf("__FILE__ : %s\n", __FILE__);
	// macroKeyword
	printf("__func__ : %s\n", __func__);
	// funcModern::macroKeyword 
	printf("__FUNCTION__ : %s\n", __FUNCTION__);
	// 소스코드 라인번호로 치환
	printf("__LINE__ : %d\n", __LINE__);
}

void funcModern::autoKeyword()
{
	// auto, 초기화에 선언된 변수의 실제 타입을 추론하기 위해 사용된다

	auto a = 1;
	auto b = 1.0f;
	auto c = a + b;
	auto d = { b, c };

	printf("type of a : %s\n", typeid(a).name());
	printf("type of b : %s\n", typeid(b).name());
	printf("type of c : %s\n", typeid(c).name());
	printf("type of d : %s\n", typeid(d).name());
}

void funcModern::decltypeKeyword()
{

	// decltype, 어떤 객체타입을 기반으로 다른 객체 타입을 지정할 수 있다
	// auto 와 decltype을 조합하면 더 간단한 방식으로 템플릿 코드를 작성할수 있다
	/*
	const int func1();
	const int& func2();
	int i;

	struct X
	{
		double d;
	};

	const BinaryTree* x = new BinaryTree();
	// func1()타입을 사용해서
	// const int변수를 선언한다
	decltype(func1()) f1;

	// fucn2()타입을 사용하서
	// const int& 변수를 선언한다
	decltype(func2()) f2;

	// i 타입을 사용해서 
	// int 변수를 선언한다
	decltype(i) i1;
	*/

	// auto 와 decltype을 조합하면 더 간단한 방식으로 템플릿 코드를 작성할수 있다
	auto d1 = add<int, float, int>(2, 2.5f);
	auto d2 = add2<int, float>(2, 2.5f);
	std::cout << "result add :" << d1 << std::endl;
	std::cout << "result add2 :" << d2 << std::endl;
}

void funcModern::nullptrKeyword()
{
	// nullptr, NULL매크로를 대체한다
	// 이제 NULL매크로를 사용할 떄, 0을 지칭하는 것인지 아니면 null포인터를 지칭하는 것인지 모호했던 경우를 피할수 있다
}

void funcModern::begin_end()
{
	// 모던c++ 이전에는 어떤 시퀀스를 순회하려면 각 컨테이너의 bein(), end() 멤버함수를 호출했다
	// 배열이라면 인덱스를 사용해서 내부의 요소를 순회할 수 있다
	// C++11 부터는 반복자(literator)를 반환하는 비멤버함수 begin(), end()함수가 제공된다
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };

	printf("sizeof(arr) : %d\n", sizeof(arr) );
	printf("sizeof(arr[0]) : %d\n", sizeof(arr[0]) );

	for (unsigned int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("classic : s%d\n", arr[i]);
	}

	// 비 멤버함수 begin(), end()
	for (auto i = std::begin(arr); i != std::end(arr); i++)
	{
		// 주소를 가져온다
		printf("begin-end : %d\n", *i);
	}

	// 범위 기반 for 루프
	// 컬렉션안의 요소 개수를 신경쓰지 않고 각 요소에 어떤 작업을 해야하거나
	// 배열 인덱스 범위의 초과 여부를 걱정하지 않고 각요소에 접근 하고 싶을떄
	for (auto i : arr )
	{
		// 값을 가져온다
		printf("new %d\n", i);
	}
}

void funcModern::std_array()
{
	// std::array, 크기를 변경할 수 없는 컴파일 타임 객체
	// array 와 성능은 동일하나, 친숙한 값 의미론을 사용하고
	// 반복자를 기반으로 하는 STL 알고리즘을 사용하기도 좋다
	std::array<int, 10> arr = { 0,1,2,3,4,5,6,7,8,9 };

	for (auto v : arr)
	{
		printf("%d ", v);
	}

	printf("\n");
	// 값 바꾸기;
	arr[0] = 10;
	arr[3] = 13;

	for (auto v : arr)
	{
		printf("%d ", v);
	}
}

void funcModern::std_vector()
{
	printf("[first]");
	std::vector<int> vec = { 0,1,2 };
	for (auto v : vec)
	{
		printf("%d ", v);
	}

	// 특정 인덱스 요소의 참조를 반환하는 at()함수
	// 인덱스가 컨테이너 범위를 벗어나면
	// [999] -> undefined behavior 를 유발한다
	// .at(999) -> out_of_range 예외를 던진다
	vec.at(0) = -1;

	vec.push_back(3);
	vec.push_back(4);

	printf("[second]");
	for (auto v : vec)
	{
		printf("%d ", v);
	}

}


void funcModern::for_each_loop()
{
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	int findValue = 10;

	// 범위 안의 원소들중에 조건을 만족하는 원소를 찾는다
	// find_if 범위 안(first 부터 last 전까지) 의 원소들 중(조건)과 일치하는 원소를 가리키는 반복자를 반환합니다
	// 만일 일치하는 원소가 없다면 last를 리턴합니다
	// 조건과 일치한다는 뜻은 원소를 인자로 전달하여 호출하였을떄 true를 반환한다는 의미입니다
	auto v = find_if(begin(vec), end(vec), [findValue](auto x) { return x == findValue; });
	if (v != end(vec))
		printf("find_if(%d), %d\n", findValue, *v);
	else
		printf("cant find_if(%d)\n", findValue);

	//	find_if_not 범위 안(first 부터 last 전까지) 의 원소들 중(조건)과 일치하지 않는 원소를 가리키는 반복자를 반환합니다
	auto v2 = find_if_not(begin(vec), end(vec), [findValue](auto x) { return x == findValue; });
	while (v2 != end(vec))
	{
		if (v2 != end(vec))
		{
			printf("find_if_not(%d), %d\n", findValue, *v2);
			// 반복문이므로, 다음 내용을 찾으려면 주소를 이동한다
			v2 = find_if_not(++v2, end(vec), [findValue](auto x) { return x == findValue; });
		}
		else
			printf("cant find_if_not(%d)\n", findValue);
	}

	auto v3 = find(begin(vec), end(vec), findValue );
	if (v3 != end(vec))
		printf("find(%d), %d\n", findValue, *v3);
	else
		printf("cant find(%d)\n", findValue);



	// for_each, 범위 내의 원소들 각각에 대해 전달된 함수를 실행시킵니다
	for_each(vec.begin(), vec.end(), myfunc<int>);
	
	//for_each(vec.begin(), vec.end(), [](const int& v) { printf("chk %d", v); });
}