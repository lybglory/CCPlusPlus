#include <stdio.h>
#include <stdlib.h>
#include <locale.h>//���ñ��ػ�
#include <Windows.h>
void main(){
	wchar_t wchr = L'�';
	printf("���ַ���С=%d\n",sizeof(wchr));
	setlocale(LC_ALL,"chs");	//��������
	wprintf(L"%wc",wchr);		//���ֵ���һ���ַ�
	MessageBox(0, TEXT("Aswer"), TEXT("Commit"), 0);
}