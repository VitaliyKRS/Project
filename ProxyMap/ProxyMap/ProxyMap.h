#pragma once
#include "Auditor.h"
#include <map>
#include <memory>
#include <iostream>



template<class Key,class Data>
class ProxyMap{
	std::map<Key, Data> mMap;
	std::shared_ptr<Auditor> mAud;
public:
	ProxyMap() = delete;
	ProxyMap(const ProxyMap&) = delete;
	ProxyMap operator=(const ProxyMap&) = delete;
	
	ProxyMap(std::shared_ptr<Auditor> _auditor);

	bool write(std::pair<Key, Data> _pair);
	bool write(Key _key, Data _data);
	void readAll();
	void readKey(Key _key);
	bool remove(Key _key);
};

template<class Key, class Data>
inline ProxyMap<Key, Data>::ProxyMap(std::shared_ptr<Auditor> _auditor)
{
	this->mAud = _auditor;
}

template<class Key, class Data>
inline bool ProxyMap<Key, Data>::write(std::pair<Key, Data> _pair)
{
	if (mAud->access() == Access::READONLY) {
		return false;
	}
	mMap.insert(_pair);
	return false;
}

template<class Key, class Data>
inline bool ProxyMap<Key, Data>::write(Key _key, Data _data)
{
	if (mAud->access() == Access::READONLY) {
		return false;
	}
	mMap.insert(std::make_pair(_key, _data));
	return true;
}

template<class Key, class Data>
inline void ProxyMap<Key, Data>::readAll()
{
	for (const auto& it : mMap) {
		std::cout << it.first << " " << it.second << std::endl;
	}
}

template<class Key, class Data>
inline void ProxyMap<Key, Data>::readKey(Key _key)
{
	auto data = mMap.find(_key);
	if (data != mMap.end()) {
		std::cout << data->first << " " << data->second << std::endl;
	}
}

template<class Key, class Data>
inline bool ProxyMap<Key, Data>::remove(Key _key)
{
	if (mAud->access() != Access::ALL) {
		return false;
	}
	auto data = mMap.find(_key);
	if (data != mMap.end()) {
		mMap.erase(data);
	}
	return true;
}

