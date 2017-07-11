#ifndef _READ_H_
#define _READ_H_

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;


class CRead
{
public:
	CRead(void);
	~CRead(void);
    //vector<string> *a[9];
	vector<vector <string>> a;
	void ReadFile(const char *path);

private:
	char *m_path;
	vector <string> b;
	
	
};


#endif