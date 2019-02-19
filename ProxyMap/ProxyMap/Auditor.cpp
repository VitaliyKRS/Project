#include "Auditor.h"



Auditor::Auditor()
{
}


Auditor::~Auditor()
{
}

Access AllPermission::access()
{
	return Access::ALL;
}

Access ReadOnly::access()
{
	return Access::READONLY;
}

Access ReadEdit::access()
{
	return Access::READ_EDIT;
}
