// Export every function's decompiled C to a JSON-lines file.
// Usage (headless): -postScript ExportDecomp.java <out.jsonl>
//@category tfc-decomp

import java.io.FileWriter;
import java.io.PrintWriter;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

public class ExportDecomp extends GhidraScript {

	private static String json(String s) {
		StringBuilder b = new StringBuilder("\"");
		for (char c : s.toCharArray()) {
			switch (c) {
				case '"': b.append("\\\""); break;
				case '\\': b.append("\\\\"); break;
				case '\n': b.append("\\n"); break;
				case '\r': break;
				case '\t': b.append("\\t"); break;
				default:
					if (c < 0x20) b.append(String.format("\\u%04x", (int) c));
					else b.append(c);
			}
		}
		return b.append('"').toString();
	}

	@Override
	public void run() throws Exception {
		String out = getScriptArgs()[0];
		DecompInterface ifc = new DecompInterface();
		ifc.setOptions(new DecompileOptions());
		ifc.toggleCCode(true);
		ifc.openProgram(currentProgram);

		int done = 0, failed = 0;
		try (PrintWriter w = new PrintWriter(new FileWriter(out))) {
			FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
			while (it.hasNext() && !monitor.isCancelled()) {
				Function f = it.next();
				if (f.isThunk() || f.isExternal()) continue;
				DecompileResults r = ifc.decompileFunction(f, 120, monitor);
				String code = r.decompileCompleted()
					? r.getDecompiledFunction().getC()
					: "/* decompile failed: " + r.getErrorMessage() + " */";
				if (!r.decompileCompleted()) failed++;
				w.println("{\"addr\":" + json(f.getEntryPoint().toString())
					+ ",\"name\":" + json(f.getName(true))
					+ ",\"sig\":" + json(f.getPrototypeString(false, false))
					+ ",\"code\":" + json(code) + "}");
				if (++done % 500 == 0) println("decompiled " + done);
			}
		}
		ifc.dispose();
		println("done: " + done + " functions, " + failed + " failed -> " + out);
	}
}
