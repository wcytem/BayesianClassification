#include "Datadeal.h"

Datadeal::Datadeal(void)
{
	for (int i=0 ;i<8 ; i++)
	{
		Dw[i]=0;Dma[i]=0;Df[i]=0;Da[i]=0;
        Dp[i]=0;Dd[i]=0;Dmu[i]=0;Ds[i]=0;
		Di[i]=0;Dg[i]=0;
	}
	m=0;
}

Datadeal::~Datadeal(void)
{
}

void Datadeal::Deal(const string *p,const char *path)
{ 
	float w_value=0,ma_value=0,f_value=0,a_value=1,p_value=1,
		  d_value=1,mu_value=1,s_value=1,i_value=1,g_value=1,
	      w_por=1.0,ma_por=1.0,f_por=1.0,a_por=1.0,p_por=1.0,
		  d_por=1.0,mu_por=1.0,s_por=1.0,i_por=1.0,g_por=1.0;
	CRead M;
	M.ReadFile(path);
	//N.ReadFile("C:\\Users\\wcytem\\Desktop\\test1.txt");
	for (int i=0 ; i<M.a[8].size() ; i++)
	{
		if (M.a[8][i]=="WWW")
		{ 
			w_value++;
			for (int j=0; j<8; j++)
			{
				if (*(p+j)==M.a[j][i])
				{
					Dw[j]++;
				}
			}
		}
		if (M.a[8][i]=="FTP-DATA"||M.a[8][i]=="FTP-CONTROL"||M.a[8][i]=="FTP-PASV")
		{ 
			f_value++;
			for (int j=0; j<8; j++)
			{
				if (*(p+j)==M.a[j][i])
				{
					Df[j]++;
				}
			}
		}
		if (M.a[8][i]=="MAIL")
		{ 
			ma_value++;
			for (int j=0; j<8; j++)
			{
				if (*(p+j)==M.a[j][i])
				{
					Dma[j]++;
				}
			}
		}
		if (M.a[8][i]=="ATTACK")
		{ 
			a_value++;
			for (int j=0; j<8; j++)
			{
				if (*(p+j)==M.a[j][i])
				{
					Da[j]++;
				}
			}
		}
		if (M.a[8][i]=="P2P")
		{ 
			p_value++;
			for (int j=0; j<8; j++)
			{
				if (*(p+j)==M.a[j][i])
				{
					Dp[j]++;
				}
			}
		}
		if (M.a[8][i]=="DATABASE")
		{ 
			d_value++;
			for (int j=0; j<8; j++)
			{
				if (*(p+j)==M.a[j][i])
				{
					Dd[j]++;
				}
			}
		}
		if (M.a[8][i]=="MULTIMEDIA")
		{ 
			mu_value++;
			for (int j=0; j<8; j++)
			{
				if (*(p+j)==M.a[j][i])
				{
					Dmu[j]++;
				}
			}
		}
		if (M.a[8][i]=="SERVICES")
		{ 
			s_value++;
			for (int j=0; j<8; j++)
			{
				if (*(p+j)==M.a[j][i])
				{
					Ds[j]++;
				}
			}
		}
		if (M.a[8][i]=="INTERACTIVE")
		{ 
			i_value++;
			for (int j=0; j<8; j++)
			{
				if (*(p+j)==M.a[j][i])
				{
					Di[j]++;
				}
			}
		}
		if (M.a[8][i]=="GAMES")
		{ 
			g_value++;
			for (int j=0; j<8; j++)
			{
				if (*(p+j)==M.a[j][i])
				{
					Dg[j]++;
				}
			}
		}
	}
	for (int i=0 ;i<8 ;i++)
	{
		if (Dw[i]==0)
		{
			Dw[i]=0.1;
		}
		if (Df[i]==0)
		{
			Df[i]=0.1;
		}
		if (Dma[i]==0)
		{
			Dma[i]=0.1;
		}
		if (Da[i]==0)
		{
			Da[i]=0.1;
		}
		if (Dp[i]==0)
		{
			Dp[i]=0.1;
		}
		if (Dd[i]==0)
		{
			Dd[i]=0.1;
		}
		if (Dmu[i]==0)
		{
			Dmu[i]=0.1;
		}
		if (Ds[i]==0)
		{
			Ds[i]=0.1;
		}
		if (Di[i]==0)
		{
			Di[i]=0.1;
		}
		if (Dg[i]==0)
		{
			Dg[i]=0.1;
		}
	}
    // for (int i=0 ;i<8 ;i++ )
	//	 cout<<Dw[i]<<"--"<<Df[i]<<"--"<<Dma[i]<<"--"<<Da[i]<<endl;
	m++;
	cout<<w_value+f_value+ma_value+p_value+d_value+a_value+mu_value+s_value+i_value+g_value<<"--"<<m<<endl;
	cout<<w_value<<"--"<<f_value<<"--"<<ma_value<<"--"<<p_value<<"--"<<d_value<<"--"<<a_value<<endl;
    for (int i=0 ;i<8 ;i++ )
    {
		Dw[i]=Dw[i]/w_value;Df[i]=Df[i]/f_value;Dma[i]=Dma[i]/ma_value;Da[i]=Da[i]/a_value;Dp[i]=Dp[i]/p_value;
		Dd[i]=Dd[i]/d_value;Ds[i]=Ds[i]/s_value;Dmu[i]=Dmu[i]/mu_value;Di[i]=Di[i]/i_value;Dg[i]=Dg[i]/g_value;
		w_por*=Dw[i];f_por*=Df[i];ma_por*=Dma[i];a_por*=Df[i];p_por*=Dp[i];
		d_por*=Dd[i];s_por*=Ds[i];mu_por*=Dmu[i];i_por*=Di[i];g_por*=Dg[i];

    }
	w_por*=w_value/M.a[8].size();f_por*=f_value/M.a[8].size();ma_por*=ma_value/M.a[8].size();a_por*=a_value/M.a[8].size();
	p_por*=p_value/M.a[8].size();d_por*=d_value/M.a[8].size();mu_por*=mu_value/M.a[8].size();s_por*=s_value/M.a[8].size();
	i_por*=i_value/M.a[8].size();
	//cout<<w_por<<"--"<<f_por<<"--"<<ma_por<<"--"<<a_por<<endl;
	if (w_por>f_por&&w_por>ma_por&&w_por>a_por&&w_por>p_por&&w_por>d_por&&w_por>mu_por&&w_por>s_por&&w_por>i_por&&w_por>g_por)
	{
		result="WWW";
	}
	if (f_por>w_por&&f_por>ma_por&&f_por>a_por&&f_por>p_por&&f_por>d_por&&f_por>mu_por&&f_por>s_por&&f_por>i_por&&f_por>g_por)
	{
		result="FTP";
	}
	if (ma_por>w_por&&ma_por>f_por&&ma_por>a_por&&ma_por>p_por&&ma_por>d_por&&ma_por>mu_por&&ma_por>s_por&&ma_por>i_por&&ma_por>g_por)
	{
		result="MAIL";
	}
	if (a_por>w_por&&a_por>f_por&&a_por>ma_por&&a_por>p_por&&a_por>d_por&&a_por>mu_por&&a_por>s_por&&a_por>i_por&&a_por>g_por)
	{
		result="ATTACK";
	}
	if (p_por>w_por&&p_por>f_por&&p_por>ma_por&&p_por>a_por&&p_por>d_por&&p_por>mu_por&&p_por>s_por&&p_por>i_por&&p_por>g_por)
	{
		result="P2P";
	}
	if (d_por>w_por&&d_por>f_por&&d_por>ma_por&&d_por>a_por&&d_por>p_por&&d_por>mu_por&&d_por>s_por&&d_por>i_por&&d_por>g_por)
	{
		result="DATABASE";
	}
	if (mu_por>w_por&&mu_por>f_por&&mu_por>ma_por&&mu_por>a_por&&mu_por>p_por&&mu_por>d_por&&mu_por>s_por&&mu_por>i_por&&mu_por>g_por)
	{
		result="MULTIMEDIA";
	}
	if (s_por>w_por&&s_por>f_por&&s_por>ma_por&&s_por>a_por&&s_por>p_por&&s_por>mu_por&&s_por>d_por&&s_por>i_por&&s_por>g_por)
	{
		result="SERVICES";
	}
	if (i_por>w_por&&i_por>f_por&&i_por>ma_por&&i_por>a_por&&i_por>p_por&&i_por>mu_por&&i_por>d_por&&i_por>s_por&&i_por>g_por)
	{
		result="INTERACTIVE";
	}
	if (g_por>w_por&&g_por>f_por&&g_por>ma_por&&g_por>a_por&&g_por>p_por&&g_por>mu_por&&g_por>d_por&&g_por>s_por&&g_por>i_por)
	{
		result="GAMES";
	}
	if (w_por==0 && f_por==0 && ma_por==0 )
	{
		result="error";
	}
	for (int i=0 ;i<8 ; i++)
	{
		Dw[i]=0;Dma[i]=0;Df[i]=0;Da[i]=0;
		Dp[i]=0;Dd[i]=0;Dmu[i]=0;Ds[i]=0;
		Di[i]=0;Dg[i]=0;
	}
}