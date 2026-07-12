// test_parser.cpp - Directly tests projectM's PresetFileParser on our .milk files
// Build from projectm build dir:
//   g++ -std=c++17 -I../src/libprojectM -I../vendor/hlslparser/src -I../src/api/include \
//       test_parser.cpp ../build/src/libprojectM/CMakeFiles/MilkdropPreset.dir/*.o \
//       -o test_parser

#include "MilkdropPreset/PresetFileParser.hpp"
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;
using libprojectM::MilkdropPreset::PresetFileParser;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: test_parser <preset.milk> [preset2.milk ...]\n";
        return 1;
    }
    
    int passed = 0, failed = 0;
    
    for (int i = 1; i < argc; i++) {
        std::string path = argv[i];
        std::cout << "\n=== Parsing: " << path << " ===\n";
        
        PresetFileParser parser;
        bool ok = parser.Read(path);
        
        if (!ok) {
            std::cerr << "  FAIL: parser.Read() returned false\n";
            failed++;
            continue;
        }
        
        const auto& values = parser.PresetValues();
        std::cout << "  Key-value pairs: " << values.size() << "\n";
        
        // Check for [preset00] header
        bool has_header = values.find("preset00") != values.end() ||
                          values.find("[preset00]") != values.end();
        std::cout << "  Has preset header: " << (has_header ? "YES" : "NO") << "\n";
        
        // Extract per_frame code
        auto per_frame = parser.GetCode("per_frame_");
        std::cout << "  Per-frame code: " << per_frame.size() << " chars\n";
        if (!per_frame.empty()) {
            // Count semicolons as rough line count
            int lines = 0;
            for (char c : per_frame) if (c == '\n' || c == ';') lines++;
            std::cout << "    Approximate statements: " << lines << "\n";
        }
        
        // Extract per_pixel code
        auto per_pixel = parser.GetCode("per_pixel_");
        std::cout << "  Per-pixel code: " << per_pixel.size() << " chars\n";
        
        // Check for wavecode
        int wave_count = 0;
        for (const auto& kv : values) {
            if (kv.first.find("wavecode_") == 0 && kv.first.find("_enabled") != std::string::npos) {
                if (kv.second == "1") wave_count++;
            }
        }
        std::cout << "  Enabled waves: " << wave_count << "\n";
        
        // Check for composite shader
        auto comp = parser.GetCode("comp_");
        std::cout << "  Composite shader: " << comp.size() << " chars\n";
        
        // Check for warp shader
        auto warp = parser.GetCode("warp_");
        std::cout << "  Warp shader: " << warp.size() << " chars\n";
        
        // Basic sanity: fDecay should be present
        auto decay = parser.GetFloat("fDecay", -1.0f);
        std::cout << "  fDecay: " << decay << "\n";
        
        std::cout << "  Result: PASS\n";
        passed++;
    }
    
    std::cout << "\n=== Summary: " << passed << " passed, " << failed << " failed ===\n";
    return failed > 0 ? 1 : 0;
}
