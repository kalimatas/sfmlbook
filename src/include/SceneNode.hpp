#ifndef SCENENODE_HPP_
#define SCENENODE_HPP_

#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/NonCopyable.hpp>

class SceneNode
	: public sf::Transformable,
	  public sf::Drawable,
	  private sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode > Ptr;

public:
	SceneNode();

	void attachChild(Ptr);
	Ptr detachChild(const SceneNode&);

private:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
	void drawChildren(sf::RenderTarget&, sf::RenderStates) const;

private:
	SceneNode* mParent;
	std::vector<Ptr> mChildren;
};

#endif /* SCENENODE_HPP_ */
