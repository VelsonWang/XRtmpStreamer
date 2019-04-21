#ifndef XFILTER_H
#define XFILTER_H


enum XFilterType
{
	XBILATERAL //双边滤波
};

namespace cv
{
class Mat;
}

#include <string>
#include <map>

class XFilter
{
public:
	static XFilter * Get(XFilterType t = XBILATERAL);
	virtual bool Filter(cv::Mat *src, cv::Mat *des) = 0 ;
	virtual bool Set(std::string key, double value);
	virtual ~XFilter();

protected:
	std::map<std::string, double>paras;
	XFilter();
};

#endif


