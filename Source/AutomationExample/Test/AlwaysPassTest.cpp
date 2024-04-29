/** Using this definition guard will stop tests being compiled into release builds **/
#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

/** A simple automation test is a test that performs exactly 1 test using the provided params. These are good for tests
 *  like making sure a function returns the expected values when given param x **/
IMPLEMENT_SIMPLE_AUTOMATION_TEST(AlwaysPassTest, "AutomationExample.Tests.AlwaysPassTest",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

/** Each test declaration must include a definition of RunTest which defines the logic to perform as part of the test.
 *  A return of true indicates that the test successfully passed **/
bool AlwaysPassTest::RunTest(const FString& Parameters)
{
	return true;
}

/** A complex automation test will run a test for each name and parameter pair output by the GetTests function. These
 *  are useful for performing tests across multiple implementations of an interface for example, or testing a function
 *  with each value in an enumeration. **/
IMPLEMENT_COMPLEX_AUTOMATION_TEST(ComplexExampleTest, "AutomationExample.Tests.ComplexExampleTest",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

/**
 * GetTests returns an array of tests and their respective arguments.
 * It can be used for things like testing all classes that implement a specific interface, all values of an enum etc.
 * @param OutBeautifiedNames The names of the tests to run
 * @param OutTestCommands The input parameters to pass to the generated tests
 */
void ComplexExampleTest::GetTests(TArray<FString>& OutBeautifiedNames, TArray<FString>& OutTestCommands) const
{
	for (int i = 0; i < 5; ++i)
	{
		OutBeautifiedNames.Add(FString::Format(TEXT("ComplexTest{0}"), {i}));
		OutTestCommands.Add(FString::Format(TEXT("{0};{1}"), {i, i + 1}));
	}
}

/** As with simple automation tests, RunTest must define the behaviour of the test being run **/
bool ComplexExampleTest::RunTest(const FString& Parameters)
{
	TArray<FString> Inputs;
	Parameters.ParseIntoArray(Inputs, TEXT(";"));

	if (Inputs.Num() == 2)
	{
		const int32 Param1 = FCString::Atoi(*Inputs[0]);
		const int32 Param2 = FCString::Atoi(*Inputs[1]);
		if (Param1 + 1 == Param2)
		{
			return true;
		}
	}

	UE_LOG(LogTemp, Error, TEXT("Error running test, wrong input parameters: %s"), *Parameters);
	return false;
}

#endif // WITH_DEV_AUTOMATION_TESTS
