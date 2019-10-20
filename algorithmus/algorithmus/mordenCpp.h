#pragma once
class mordenCpp
{
public:
	mordenCpp();
	~mordenCpp();

	void init();

	// auto 키워드 sample
	void autoKeyword();
	// 범위기반 for문 sample
	void rangeBasedFor();
	// 유니폼 초기화
	void uniformInitialization();
	// decltype 키워드
	void decltypeKeyword();
	// 우측참조값
	void rvalueReference();
	// push_back_emplace_back 의 비교
	void push_back_emplace_back();


	class Person
	{
	private:
		int age;
		string name;
	public:
		Person(const int a, const string& n) : age(a), name(n) {}
		int getAge() { return age; }
		string getName() { return name; }
	};

	class Item
	{
	private:
		int m_nx;
	
	public:
		Item(const int _n) : m_nx(_n)
		{
			cout << "일반 생성자 호출" << endl;
		}

		Item(const Item& rhs) : m_nx(rhs.m_nx)
		{
			cout << "복사 생성자 호출" << endl;
		}

		Item(const Item&& rhs) : m_nx(std::move(rhs.m_nx))
		{
			cout << "이동 생성자 호출" << endl;
		}

		~Item() { cout << "소멸자 호출" << endl; }
	};


	class A
	{
	public:
		A(int& _a) { }
	};

	class B
	{
	public:
		B(const int& _b) { }    // 이런, Factory 템플릿은 이 생성자에 절때 들어오지 않아요!
	};



	template <typename T, typename U>
	T* Factory(U&& arg) {
		return new T(arg);
	}

};

