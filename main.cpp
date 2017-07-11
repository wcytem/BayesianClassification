#include "Read.h"
#include "Datadeal.h"

int main()
{ 
	CRead N;
    Datadeal D;
	float C_value=0;
	string *str,str1[8];
	int lengh=0;
   // N.ReadFile("C:\\Users\\wcytem\\Desktop\\test1.txt");
    N.ReadFile("C:\\Users\\wcytem\\Desktop\\test1.txt");
	lengh=N.a[8].size();
	for (int j=0 ;j<lengh ;j++)
	{
		for (int i=0 ;i<8 ;i++)
		{
			str1[i]=N.a[i][j];
		}
		str=str1;
		D.Deal(str,"C:\\Users\\wcytem\\Desktop\\wen.txt");
		cout<<D.result<<endl;
		if (D.result=="FTP")
		{ 
			if (N.a[8][j]=="FTP-DATA"||N.a[8][j]=="FTP-CONTROL"||N.a[8][j]=="FTP-PASV")
			{
				C_value++;
			}
		}
		else
		{
            if (D.result==N.a[8][j])
            {
				C_value++;
            }
		}
	}
	cout<<"正确率为："<<C_value/lengh<<endl;
	system("pause");
	return 0;
}

