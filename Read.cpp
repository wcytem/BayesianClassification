#include "Read.h"

CRead::CRead(void)
{
	m_path="C:\\Users\\wcytem\\Desktop\\test.txt";

	for(int idx = 0; idx < 9; ++idx)
	{
		//a[idx] = new vector<string>;
		a.push_back(b);
	}
}

CRead::~CRead(void)
{
}

void CRead::ReadFile(const char *path)
{
	int index=0,i=0,j=0,m=0,c_value=0;
	char b[50];
	memset(b,0,50);
	char *Buf = new char[2000];
	
	ifstream myFile;
	//myFile.open("C:\\Users\\wcytem\\Desktop\\wen.txt");
	myFile.open(path);
	//myFile>>Buf;
	//cout<<Buf<<endl;
	if(myFile.fail())
	{return 1;}
	else
	{
		while(!myFile.eof())
		{   c_value=0;
			memset(Buf,0,2000);
		  myFile.getline(Buf, 2000);
		  //cout<<Buf<<endl;
		 if(*Buf<='9' && *Buf>='0')
		{ 
			while(*(Buf+index)!='\0')
		
			{  // cout<<*(Buf+index)<<endl;
			  if(*(Buf+index)!=',')
			   {  
				  b[j]=*(Buf+index);
				  //cout<<b<<endl;
				  j++;
				}
			  else
			   {   
				  c_value++;
				  if (c_value==1||c_value==38||c_value==60||c_value==79||c_value==96||c_value==101||c_value==143||c_value==188)
				  {
				     a[i].push_back(b);
					  i++; 
				  }
				  //a[i].push_back(b);
				  //	cout<<a.at();
				  memset(b,0,50);
				  j=0;
				  //i++;
			   }
		      index++;
		     }
		  if(*Buf != '\0')
		   {
			 a[i].push_back(b);
			 memset(b,0,50);
		   }
	    }
		j=0;
		i=0;
		index=0;

		}
	}
	myFile.close();

}