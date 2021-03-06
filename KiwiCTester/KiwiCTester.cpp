// KiwiCTester.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../KiwiC/KiwiC.h"
#include <windows.h>
#include <locale.h>

int main()
{
	system("chcp 65001");
	_wsetlocale(LC_ALL, L"korean");
	PKIWI kw = kiwi_init("../ModelGenerator/", -1);
	kiwi_prepare(kw);
	PKIWIRESULT kr = kiwi_analyze(kw, "이것은 테스트입니다.", 5);
	int size = kiwiResult_getSize(kr);
	for (int i = 0; i < size; i++)
	{
		printf("%g\t", kiwiResult_getProb(kr, i));
		int num = kiwiResult_getWordNum(kr, i);
		for (int j = 0; j < num; j++)
		{
			wprintf(L"%s/%s\t", kiwiResult_getWordFormW(kr, i, j), kiwiResult_getWordTagW(kr, i, j));
		}
		printf("\n");
	}
	kiwiResult_close(kr);
	kiwi_close(kw);
	getchar();
    return 0;
}

