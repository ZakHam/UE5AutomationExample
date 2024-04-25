using EpicGames.BuildGraph;
using EpicGames.Core;
using System.Collections.Generic;
using System.Xml;

namespace AutomationExample.Automation;

public class CustomTaskParameters
{
	[TaskParameter]
	public string Target;
	
	[TaskParameter(Optional=true)]
	public string Arguments;
}

[TaskElement("CustomTask", typeof(CustomTaskParameters))]
public class CustomTask : BgTaskImpl
{
	/// <summary>
	/// Parameters for the task
	/// </summary>
	CustomTaskParameters Parameters;

	/// <summary>
	/// Construct a custom task
	/// </summary>
	/// <param name="InParameters">Parameters for this task</param>
	public CustomTask(CustomTaskParameters InParameters)
	{
		Parameters = InParameters;
	}

	/// <summary>
	/// Execute the task.
	/// </summary>
	/// <param name="Job">Information about the current job</param>
	/// <param name="BuildProducts">Set of build products produced by this node.</param>
	/// <param name="TagNameToFileSet">Mapping from tag names to the set of files they include</param>
	public override Task ExecuteAsync(JobContext Job, HashSet<FileReference> BuildProducts, Dictionary<string, HashSet<FileReference>> TagNameToFileSet)
	{
		Log.Logger.LogInfo("Running custom task with input: {Parameters}", Parameters);
		return Task.CompletedTask;
	}

	/// <summary>
	/// Output this task out to an XML writer.
	/// </summary>
	public override void Write(XmlWriter Writer)
	{
		Write(Writer, Parameters);
	}

	/// <summary>
	/// Find all the tags which are used as inputs to this task
	/// </summary>
	/// <returns>The tag names which are read by this task</returns>
	public override IEnumerable<string> FindConsumedTagNames()
	{
		yield break;
	}

	/// <summary>
	/// Find all the tags which are modified by this task
	/// </summary>
	/// <returns>The tag names which are modified by this task</returns>
	public override IEnumerable<string> FindProducedTagNames()
	{
		return FindTagNamesFromList(Parameters.Tag);
	}
}