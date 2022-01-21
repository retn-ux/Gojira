#ifndef __GOJIRA_GSHAREDPOINT_H__
#define __GOJIRA_GSHAREDPOINT_H__
#include "../include/GojiraDefs.h"
#include "../include/GContainer.h"

class GSharedElement {
public:
	GSharedElement() {}
	virtual void release() = 0;
	virtual ~GSharedElement() {}

};


class GSharedResource {
public:
	GSharedResource();
	GSharedResource(GSharedElement* right);
	GSharedResource(const GSharedResource& right);
	GSharedResource(GSharedResource&& right);
	~GSharedResource();
private:
	GSharedElement* coreElement;
};


#endif