#include <Windows.h>
#include <stdio.h>

#ifndef _DEBUG
int main();
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	return main();
}
#endif

int main()
{
	printf("testing");
	while(1);
	return 0;
}