#ifndef _Datadeal_H_
#define _Datadeal_H_

#include "Read.h"
class Datadeal
{
public:
	Datadeal(void);
	~Datadeal(void);
	void Deal(const string *p,const char *path);
	string result;
private:
	float Dw[8],Df[8],Dma[8],Da[8],Dp[8],Dd[8],Dmu[8],Ds[8],Di[8],Dg[8];
	int m;
};
#endif