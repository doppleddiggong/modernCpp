#include "pch.h"
#include "header.h"
#include "mordenCpp.h"

#include <string>

mordenCpp::mordenCpp()
{
}


mordenCpp::~mordenCpp()
{
}


template<typename T, typename U>
auto add_template(T&& x, U && y)
{
	return forward<T>(x) + forward<U>(y);
}

auto add_function(int a, int b)
{
	return a + b;
}

template <typename TBuilder>
auto MakeAndProcessObject(const TBuilder& builder)
{
	auto val = builder.makeObject();
	// process...
	return val;
}

struct Builder
{
	static string makeObject()
	{
		return string("hello");
	}
};


void mordenCpp::init()
{
	//// auto 키워드 
	//autoKeyword();

	//// 범위기반 for문
	//rangeBasedFor();

	//// 유니폼 초기화
	//uniformInitialization();

	//// decltype 키워드
	//decltypeKeyword();

	// 우측 참조값
	//rvalueReference();

	// push_back_emplace_back의 생성자, 소멸자 호출 비교
	//push_back_emplace_back();

	int64_t bitNum = 1234567890;
	string strBitNum = std::to_string(bitNum);

	bool bTrue = true;
	bool bFalse = false;

	printf("[%lld]{%s}", bitNum, strBitNum.c_str());

	printf("{%s}/{%s}", std::to_string(bTrue).c_str(), std::to_string(bFalse).c_str());
}

// auto 키워드 sample
void mordenCpp::autoKeyword()
{
	vector<int> vInt;
	for (auto i = 0; i < 10; ++i) {
		vInt.push_back(i);
	}

	// C++03 표준
	cout << "C++03 standard" << endl;
	vector<int>::iterator it = vInt.begin();
	while (it != vInt.end())
	{
		cout << *it << endl;
		it++;
	}

	// C++11, auto 키워드
	cout << "C++11 standard" << endl;
	auto it2 = vInt.begin();
	while (it2 != vInt.end())
	{
		cout << *it2 << endl;
		it2++;
	}
}

// 범위기반 for문 sample
void mordenCpp::rangeBasedFor()
{
	// C++11, 범위기반 for문
	int arr[5] = { 0,1,2,3,4 };
	for (int i : arr)
	{
		cout << i << endl;
	}

	vector<int> vInt;
	for (auto i = 0; i < 10; ++i) {
		vInt.push_back(i);
	}

	// C++ 03
	for (vector<int>::const_iterator it2 = vInt.begin(); it2 != vInt.end(); ++it2)
	{
		cout << *it2 << endl;
	}

	// C++ 11, 범위기반 for문 
	for (auto i : vInt)
	{
		cout << i << endl;
	}
}

// 유니폼 초기화
void mordenCpp::uniformInitialization()
{
	// C++03
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	// C++11, 유니폼 초기화
	vector<int> v2{ 1, 2, 3, 4 };

	Person p1(20, "Tom");
	Person p2(19, "Jane");

	vector<Person> vec{
		{21, "Smith"},
		{39, "John"},
	};

	for_each(vec.begin(), vec.end(), [](Person p)
	{
		printf("[%d]{%s}", p.getAge(), p.getName().c_str());
	});
}

// decltype 키워드
void mordenCpp::decltypeKeyword()
{
	auto i = add_template(1, 2);
	auto j = add_function(1, 2);

	Builder builder;
	auto a = MakeAndProcessObject(builder);

	printf("%d", i);
	printf("%d", j);
	printf("%d", a);
}

// 우측참조값
void mordenCpp::rvalueReference()
{
	int i = 1;
	A* aa = Factory<A>(i); //ok , collapsing 에 따라 U& arg 형으로 변환됩니다.
	B* bb = Factory<B>(1); //ok , collapsing 에 따라 U&& arg 형으로 변환됩니다.
}

void mordenCpp::push_back_emplace_back()
{
	std::vector<Item> iVector;
	cout << "push_back 호출" << endl;
	iVector.push_back(Item(3));

	cout << "emplac_back 호출" << endl;
	iVector.emplace_back(3);
}