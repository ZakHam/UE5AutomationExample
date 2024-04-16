#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

/** A simple automation test is a test that performs exactly 1 test using the provided params. These are good for tests
 *  like making sure a function returns the expected values when given param x **/
IMPLEMENT_SIMPLE_AUTOMATION_TEST(AlwaysPassTest, "AutomationExample.Tests.AlwaysPassTest",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool AlwaysPassTest::RunTest(const FString& Parameters)
{
	return true;
}

/** A complex automation test will run a test for each name and parameter set output by the GetTests function. These
 *  are useful for performing tests across multiple implementations of an interface for example, or testing a function
 *  with each value in an enumeration. **/
IMPLEMENT_COMPLEX_AUTOMATION_TEST(ComplexExampleTest, "AutomationExample.Tests.ComplexExampleTest",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

void ComplexExampleTest::GetTests(TArray<FString>& OutBeautifiedNames, TArray<FString>& OutTestCommands) const
{
	for (int i = 0; i < 5; ++i)
	{
		OutBeautifiedNames.Add(FString::Format(TEXT("ComplexTest{0}"), {i}));
		OutTestCommands.Add(FString::Format(TEXT("{0}"), {i}));
	}
}

bool ComplexExampleTest::RunTest(const FString& Parameters)
{
	static int32 Test_Count = 0;
	if (const int32 ParamValue = FCString::Atoi(*Parameters);
		ParamValue != Test_Count)
	{
		Test_Count++;
		return false;
	}

	Test_Count++;
	return true;
}



#endif // WITH_DEV_AUTOMATION_TESTS
