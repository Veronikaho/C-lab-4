#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * reverseWords(char * in, char *out)	//�������, ���������������� ����� �� in � ������������ �� � out
{
	char *arrp[64];	//������ ���������� �� char
	int flag = 0;
	int count = 0;	//���������� ���� == ���������� ��������� *arrp[]
	if (in[strlen(in) - 1] == '\n')
	{
		in[strlen(in) - 1] = '\0';	//�������� '\n' �� '\0'
	}
	//-----------------------------------------------------------------

	//������� � ���������� ������ ������� ���� ���� � ������ ����������
	for (int i = 0; in[i] != 0; i++)
	{
		if (in[i] != ' ' && flag == 0)
		{
			flag = 1;
			arrp[count] = &in[i];
			count++;
		}
		else if (in[i] == ' ' && flag == 1)
		{
			flag = 0;
		}
	}
	//-----------------------------------------------------------------
	//��������� ������������ ����� ������	
	int k = 0;	//������������ ��� �������� ������(�������) � �������� �������...

	for (int i = count - 1; i >= 0; i--)
	{
		for (int j = 0; arrp[i][j] != ' ' && arrp[i][j] != '\0'; j++)
		{
			out[k] = arrp[i][j];
			k++;
			if (((arrp[i][j + 1] == ' ') || (arrp[i][j + 1] == '\0')) && (i - 1 >= 0))
			{
				out[k] = ' ';
				k++;
			}
			else if (((arrp[i][j + 1] == ' ') || (arrp[i][j + 1] == '\0')) && (i - 1 < 0))
			{
				out[k] = '\0';
			}
		}
	}
	//-----------------------------------------------------------------
	return out;
}




