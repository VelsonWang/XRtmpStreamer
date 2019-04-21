
#include "XFilter.h"
#include "XBilateralFilter.h"
#include <iostream>

using namespace std;

bool XFilter::Set(std::string key, double value)
{
	if (paras.find(key) == paras.end())
	{
		cout << "para " << key << " is not support!" << endl;
		return false;
	}
	paras[key] = value;
	return true;
}

XFilter * XFilter::Get(XFilterType t)
{
	static XBilateralFilter xbf;
	switch (t)
	{
	case XBILATERAL: //双边滤波
		return &xbf;
		break;
	default:
		break;
	}
	return 0;

}

XFilter::XFilter()
{
}


XFilter::~XFilter()
{
}
