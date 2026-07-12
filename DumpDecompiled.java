// Ghidra headless script - dumps all decompiled functions to a file
// @category Analysis
//
// Usage (headless):
//   analyzeHeadless <project_dir> <project_name> \
//     -process <file> -noanalysis \
//     -scriptPath <dir> -postScript DumpDecompiled.java <output_dir>
//
// Args:
//   <output_dir>  Directory to write decompiled_*.txt (default: same dir as DLL)

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;

public class DumpDecompiled extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String progName = currentProgram.getName();
        String stem = progName.replace(".dll", "").replace(".DLL", "");

        String outputDir;
        if (args.length >= 1) {
            outputDir = args[0];
        } else {
            // Default: directory of the program's executable path
            File exePath = new File(currentProgram.getExecutablePath());
            outputDir = exePath.getParent();
        }

        File outDir = new File(outputDir);
        if (!outDir.exists()) {
            outDir.mkdirs();
        }

        String outputPath = outputDir + File.separator + "decompiled_" + stem + ".txt";
        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(currentProgram);

        PrintWriter pw = new PrintWriter(new FileWriter(outputPath));
        pw.println("=== DECOMPILED FUNCTIONS: " + progName + " ===\n");

        int count = 0;
        FunctionIterator funcs = currentProgram.getFunctionManager().getFunctions(true);
        while (funcs.hasNext()) {
            Function func = funcs.next();
            String name = func.getName();
            var addr = func.getEntryPoint();
            DecompileResults result = decomp.decompileFunction(func, 30, monitor);
            pw.println("======================================================================");
            pw.println("// Function: " + name + " @ " + addr);
            pw.println("======================================================================");
            if (result != null && result.decompileCompleted()) {
                String c_code = result.getDecompiledFunction().getC();
                pw.println(c_code != null ? c_code : "// <no decompilation>");
            } else {
                pw.println("// <decompilation failed>");
            }
            pw.println("\n");
            count++;
        }

        pw.println("\n=== TOTAL: " + count + " functions ===");
        pw.flush();
        pw.close();
        println("Dumped " + count + " functions to " + outputPath);
        decomp.dispose();
    }
}
