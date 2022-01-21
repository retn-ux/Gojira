#ifndef __GOJIRA_GARRAY_H__
#define __GOJIRA_GARRAY_H__
#include <vector>

#include "../include/GojiraDefs.h"

template<typename E>
using GArray = std::vector<E>;
using GByteArray = GArray<Byte>;

#define array_append(container,data)\
	container.push_back(data);

#define array_ptr_append(container,data)\
	container->push_back(data);

#define array_muti_append(container,data,size)\
	for(size_t i=0;i<size;i++){\
		container.push_back(data[i]);\
	}

#define array_ptr_muti_append(container,data,size)\
	for(size_t i=0;i<size;i++){\
		container->push_back(data[i]);\
	}

#endif