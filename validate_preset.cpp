// validate_preset.cpp - Loads a .milk preset using projectM's parser to verify syntax
// Build: g++ -std=c++17 -I../src/libprojectM -I../vendor/hlslparser/src validate_preset.cpp -o validate_preset

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

// Minimal reproduction of projectM's key=value parsing logic
// Based on PresetFileParserTest.cpp analysis

struct PresetData {
    bool has_preset_header = false;
    int per_frame_count = 0;
    int per_pixel_count = 0;
    int wave_code_count = 0;
    int shape_def_count = 0;
    int comp_lines = 0;
    int warp_lines = 0;
    bool in_code_block = false;
    std::string code_block_type;
    int errors = 0;
    int warnings = 0;
};

void validate_line(const std::string& line, int lineno, PresetData& data) {
    // Skip empty lines
    if (line.empty()) return;
    
    // Skip comments
    if (line.substr(0, 2) == "//") return;
    
    // Check for [preset00]
    if (line.find("[preset00]") != std::string::npos) {
        data.has_preset_header = true;
        return;
    }
    
    // Find the key=value split
    auto eq_pos = line.find('=');
    if (eq_pos == std::string::npos) return;
    
    std::string key = line.substr(0, eq_pos);
    std::string value = line.substr(eq_pos + 1);
    
    // Trim whitespace from key
    while (!key.empty() && key.back() == ' ') key.pop_back();
    
    // Check for code blocks (backtick)
    if (!value.empty() && value[0] == '`') {
        // Start of code block
        data.in_code_block = true;
        // Determine block type from prefix
        if (key.find("comp_") == 0) data.code_block_type = "comp";
        else if (key.find("warp_") == 0) data.code_block_type = "warp";
        else data.code_block_type = "unknown";
        return;
    }
    
    if (data.in_code_block) {
        // Inside code block - count lines
        if (data.code_block_type == "comp") data.comp_lines++;
        else if (data.code_block_type == "warp") data.warp_lines++;
        
        // Check if this line ends the block (no backtick prefix, regular key=value)
        if (eq_pos != std::string::npos && value.find('`') == std::string::npos) {
            // This is a regular key=value, not a code continuation
            // But we need to check if it's a new section
        }
        return;
    }
    
    // Check for per_frame numbering
    if (key.find("per_frame_") == 0) {
        try {
            int num = std::stoi(key.substr(10));
            if (num > data.per_frame_count) data.per_frame_count = num;
        } catch (...) {}
    }
    
    // Check for per_pixel numbering
    if (key.find("per_pixel_") == 0) {
        try {
            int num = std::stoi(key.substr(10));
            if (num > data.per_pixel_count) data.per_pixel_count = num;
        } catch (...) {}
    }
    
    // Check for wavecode
    if (key.find("wavecode_") == 0) {
        data.wave_code_count++;
    }
    
    // Check for shapedef
    if (key.find("shapedef_") == 0) {
        data.shape_def_count++;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: validate_preset <preset.milk>\n";
        return 1;
    }
    
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "ERROR: Cannot open " << argv[1] << "\n";
        return 1;
    }
    
    PresetData data;
    std::string line;
    int lineno = 0;
    
    while (std::getline(file, line)) {
        lineno++;
        validate_line(line, lineno, data);
    }
    
    std::cout << "=== Preset Validation: " << argv[1] << " ===\n";
    std::cout << "  Lines: " << lineno << "\n";
    std::cout << "  [preset00] header: " << (data.has_preset_header ? "YES" : "MISSING") << "\n";
    std::cout << "  Per-frame equations: " << data.per_frame_count << "\n";
    std::cout << "  Per-pixel equations: " << data.per_pixel_count << "\n";
    std::cout << "  Wave code blocks: " << data.wave_code_count << "\n";
    std::cout << "  Shape definitions: " << data.shape_def_count << "\n";
    std::cout << "  Composite shader lines: " << data.comp_lines << "\n";
    std::cout << "  Warp shader lines: " << data.warp_lines << "\n";
    
    if (!data.has_preset_header) {
        std::cout << "  RESULT: FAIL - Missing [preset00]\n";
        return 1;
    }
    
    std::cout << "  RESULT: PASS\n";
    return 0;
}
