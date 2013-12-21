#ifndef SCENENODE_HPP_
#define SCENENODE_HPP_

#include <vector>

class SceneNode
{
public:
	typedef std::unique_ptr<SceneNode > Ptr;

	SceneNode();

	void attachChild(Ptr);
	Ptr detachChild(const SceneNode&);

private:
	SceneNode* mParent;
	std::vector<Ptr> mChildren;
};

#endif /* SCENENODE_HPP_ */
