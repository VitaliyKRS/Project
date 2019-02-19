#pragma once
#include  <memory>

enum class Access {
	ALL,
	READONLY,
	READ_EDIT
};

class Auditor
{
public:
	virtual Access access() = 0;
	Auditor();
	virtual ~Auditor();
};

class AllPermission : public Auditor {
public:
	Access access()override;
};

class ReadOnly : public Auditor {
public:
	Access access()override;
};

class ReadEdit : public Auditor {
public:
	Access access()override;
};