#include "stdafx.h"
#include <cppunit/extensions/TestFactoryRegistry.h>
#include "SMProviderSuite.h"
#include "SMProviderTestSuite.h"

namespace SPT
{
	CppUnit::Test* suite()
	{
		CppUnit::TestFactoryRegistry& registry = 
			CppUnit::TestFactoryRegistry::getRegistry(SMProvideSuiteName());
		return registry.makeTest();
	}
}