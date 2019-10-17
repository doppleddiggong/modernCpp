#include "pch.h"
#include "header.h"
#include "PointerTest.h"

PointerTest::PointerTest() { }
PointerTest::~PointerTest() {}

void PointerTest::init()
{
	printf("PointerTest::init()\n");

	int a = 3;
	int *p = &a;
	int *pNull = NULL;

	printf("&P의 주소 : %d\n", &p);
	printf("&a의 주소 : %d\n", &a);

	printf("*p의 값 : %d\n", *p);
	printf("(*(&a))의 값 : %d\n", (*(&a)) );

	printf("pNull의 값 : %d\n", pNull );
	printf("&pNull의 값 : %d\n", &pNull);
}
