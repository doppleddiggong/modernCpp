// algorithmus.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "header.h"

// 문자열 포맷 출력
// string test_message = format_string("%d %lf %s %#x\n", 10, 10.5, "test message", 12345678);
string format_string(const std::string fmt, ...)
{
	int size = ((int)fmt.size()) * 2;
	string buffer;
	va_list ap;
	while (1)
	{
		buffer.resize(size);
		va_start(ap, fmt);
		int n = vsnprintf((char*)buffer.data(), size, fmt.c_str(), ap);
		va_end(ap);
		if (n > -1 && n < size)
		{
			buffer.resize(n);
			return buffer;
		}
		if (n > -1)
			size = n + 1;
		else size *= 2;
	}
	return buffer;
}


int main()
{
	printf("main\n");

	// 포인터와 레퍼런스, 주소간의 확인을 위한 테스트 코드
	//PointerTest *pPtTest = new PointerTest();
	//pPtTest->init();

	BinaryTree *binaryTree = new BinaryTree();
	binaryTree->init();
}
