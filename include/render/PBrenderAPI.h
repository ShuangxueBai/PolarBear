//!Polar Bear
#ifndef POLAR_BEAR_RENDER_API_H
#define POLAR_BEAR_RENDER_API_H

#define PB_RETURN_SINGLE_INSTANCE(pInstance, className) \
	  if(nullptr == pInstance) \
         pInstance = new className##(); \
      return pInstance;\

struct PBrenderAPI 
{

	virtual void init() = 0;
	virtual void destroy() = 0;

	virtual ~PBrenderAPI(){}

};





#endif