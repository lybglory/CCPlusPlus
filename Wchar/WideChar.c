#include <stdio.h>
#include <stdlib.h>
#include <locale.h>//设置本地化
void main(){
	wchar_t wchr = L'婵';
	printf("宽字符大小=%d\n",sizeof(wchr));
	setlocale(LC_ALL,"chs");	//简体中文
	wprintf(L"%wc",wchr);		//汉字当作一个字符
}