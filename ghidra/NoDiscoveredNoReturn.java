// Pre-analysis: turn off "Non-Returning Functions - Discovered". The 25th
// client.so is built without -fPIC; its unrelocated calls point into their
// own instruction, which makes that analyzer mark operator new (and others)
// as noreturn and cut every function short at its first allocation.
//@category tfc-decomp

import ghidra.app.script.GhidraScript;

public class NoDiscoveredNoReturn extends GhidraScript {
	@Override
	public void run() throws Exception {
		setAnalysisOption(currentProgram, "Non-Returning Functions - Discovered", "false");
		println("disabled Non-Returning Functions - Discovered");
	}
}
