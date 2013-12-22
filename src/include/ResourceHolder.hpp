#ifndef RESOURCEHOLDER_HPP_
#define RESOURCEHOLDER_HPP_

#include <map>
#include <string>
#include <cassert>
#include <iostream>
#include "StringHelpers.hpp"

template <typename Resource, typename Identifier>
class ResourceHolder {
public:
	// Load resources
	void load(Identifier, const std::string&);

	template <typename Parameter>
	void load(Identifier, const std::string&, const Parameter& secondParameter);

	// Get resources
	Resource& get(Identifier);
	const Resource& get(Identifier) const;

private:
	// Store resource in the container
	void insertResource(Identifier, std::unique_ptr<Resource>);

private:
	// Resources container
	std::map<Identifier, std::unique_ptr<Resource> > mResourceMap;
};

// Implementation

template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& fileName) {
	std::unique_ptr<Resource> resource(new Resource());

	if (!resource->loadFromFile(fileName)) {
		throw std::runtime_error("ResourceHolder::load - failed to load " + fileName);
	}

	insertResource(id, std::move(resource));
}

template<typename Resource, typename Identifier>
template<typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& fileName, const Parameter& secondParameter) {
	std::unique_ptr<Resource> resource(new Resource());

	if (!resource->loadFromFile(fileName, secondParameter)) {
		throw std::runtime_error("ResourceHolder::load - failed to load " + fileName);
	}

	insertResource(id, std::move(resource));
}

template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::insertResource(Identifier id, std::unique_ptr<Resource> resource) {
	auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
	assert(inserted.second);
}

template<typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) {
	auto found = mResourceMap.find(id);
	assert(found != mResourceMap.end());

	return *found->second;
}

template<typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const {
	auto found = mResourceMap.find(id);
	assert(found != mResourceMap.end());

	return *found->second;
}

#endif /* RESOURCEHOLDER_HPP_ */
