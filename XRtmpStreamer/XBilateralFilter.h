#ifndef XBILATERALFILTER_H
#define XBILATERALFILTER_H

#include "XFilter.h"

class XBilateralFilter : public XFilter
{
public:
	XBilateralFilter();
	bool Filter(cv::Mat *src, cv::Mat *des);
	virtual ~XBilateralFilter();
};

#endif


