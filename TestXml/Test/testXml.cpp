#include "pch.h"
#include "XML.h"

class TestClassXML :public ::testing::Test {
public:
	XML xml;
};

TEST_F(TestClassXML, TestLoadXML) {    //This test checks the file download.
	ASSERT_TRUE(xml.LoadXMl());
}

TEST_F(TestClassXML, TestSaveXML) {  //This test checks the file save.
	ASSERT_TRUE(xml.SaveXML());
}
