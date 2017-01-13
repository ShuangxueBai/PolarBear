#ifndef POLAR_BEAR_NODE_H
#define POLAR_BEAR_NODE_H

#include <vector>
#include "PBdefine.h"
#include "scene/_sceneExport.h"
#include "base/PBbase.h"

POLAR_BEAR_BEGIN

enum class PBnodeType
{
	nt_actor = 0,
	nt_element,
	nt_prop,
	nt_count
};


class PBresource;
class SCENE_EXT PBnode : public PBobject
{
public:
	PBnode();
	virtual ~PBnode();
	
	virtual PBnodeType getType() = 0;
	virtual void draw() = 0;

	void setEnableDraw(bool enable = true) { _isDraw = enable; }
	void setResource(PBresource* pResource);

	void addNode(PBnode* node);
	void removeNode(PBnode* node);

	const size_t getNodeCount() { return _nodes.size(); }


protected:

	bool _isDraw;
	std::string _id;

	PBrefPtr<PBmotion> _motion;
	PBrefPtr<PBresource> _resource;
	std::vector<PBrefPtr<PBnode>> _nodes;
};


POLAR_BEAR_END

#endif