# Unreal Engine Automation Example
This repository aims to serve as a base for setting up automation in your Unreal Engine projects.  
It contains examples of functional and automation tests, as well as some associated build graph for building and running them.

## Testing
The C++ automation tests can be found in `Source/AutomationExample/Test/AlwaysPassTest.cpp`  
The functional tests are found in `Content/AutomationExample/BP_ExampleFunctionalTest.uasset`

These can be run from within the editor using the session frontend, or from the command line using Gauntlet:

```bash
.\RunUAT.bat RunUnreal \
    -Project="AutomationExample" \
    -Build="Editor" \
    -Test="UE.TargetAutomation" \
    -RunTest="AutomationExample.Tests."
```

## Build Graph
Some example build graph scripts can be located in `Build/Graph/`. These provide a very simple overview
of the functionality of build graph. They can be run using UAT:

```bash
.\RunUAT.bat BuildGraph \
    -Script="Build/Graph/BuildGraphExample.xml" \
    -Target="{Target from the build graph} \
    {Other optional params}
```
