#include "pch.h"
#include "ProxyMap.h"

TEST(access_readOnly, tryWrite) {
  ProxyMap<int, char> map{ std::make_shared<ReadOnly>() };
  EXPECT_FALSE(map.write(1,'a'));
}

TEST(access_readOnly, tryRemove) {
  ProxyMap<int, char> map{ std::make_shared<ReadOnly>() };
  EXPECT_FALSE(map.remove(1));
}


TEST(access_readEdit, tryEdit) {
	ProxyMap<int, char> map{ std::make_shared<ReadEdit>() };
	EXPECT_TRUE(map.write(1, 'a'));
}

TEST(access_readEdit, tryRemove) {
	ProxyMap<int, char> map{ std::make_shared<ReadEdit>() };
	EXPECT_FALSE(map.remove(1));
}

TEST(access_all, tryEdit) {
	ProxyMap<int, char> map{ std::make_shared<AllPermission>() };
	EXPECT_TRUE(map.write(1, 'a'));
}

TEST(access_all, tryRemove) {
	ProxyMap<int, char> map{ std::make_shared<AllPermission>() };
	EXPECT_TRUE(map.remove(1));
}

