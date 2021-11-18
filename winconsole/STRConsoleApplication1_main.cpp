#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include <memory>
#pragma warning(disable:4996)

char* mystrcpy(char* s1, const char* s2)
{
	int i = 0;
	while ((s1[i] = s2[i]) != '\0'){
		i++;
	}
	return s1;
}

void sexec(char* buf, char* buf2)
{
	mystrcpy(buf, buf2);
}

void cmain(){
	char w[128];
	char a[6];
	char ss[256] = {};
	char ss2[256] = "atest";
	int i;
	memcpy(ss, ss2, sizeof(ss2));
	//for (i = 0; i < 3; i++)
	{
		printf("", a);
		gets(w);
		//mystrcpy(a, ss);
		sexec(a, ss);
	}
	//for (i = 0; i < 3; i++)
	{
		puts(a); 		/* puts( & a[i][0] ); ‚Æ‘‚¢‚Ä‚à‚æ‚¢ */
	}

}

void wmain(){
	wchar_t* ws = L"Test";
	char ms[100] = {};
	int len;
	int size;
	size = wcslen(ws);
	len = wcstombs(ms, ws, size);
	printf(" %d %s ", len, ms);
}

void main(){
	wmain();
}