//- Copyright (c) 2008-2009 James Grenning --- All rights reserved
//- For exclusive use by participants in Renaissance Software Consulting training courses.
//- Cannot be used by attendees to train others without written permission.
//- www.renaissancesoftware.net james@renaissancesoftware.net


#include "CppUTest/CommandLineTestRunner.h"

int main(int ac, char** av)
{
    MemoryLeakWarningPlugin::turnOnThreadSafeNewDeleteOverloads();
    MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
    //MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
    return CommandLineTestRunner::RunAllTests(ac, av);
}

