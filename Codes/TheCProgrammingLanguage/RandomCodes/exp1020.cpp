#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

namespace fs = std::filesystem;

const std::string SOURCE_DIR = "D:/"; // Change this to your source directory
const std::string DEST_DIR = ".";      // Change this to your destination directory

void copyPDFFiles(const std::string& sourceDir, const std::string& destDir);
void copyPDFFilesRecursive(const std::string& sourceDir, const std::string& destDir);

int main() {
    copyPDFFilesRecursive(SOURCE_DIR, DEST_DIR);
    return 0;
}

void copyPDFFiles(const std::string& sourceDir, const std::string& destDir) {
    copyPDFFilesRecursive(sourceDir, destDir);
}

void copyPDFFilesRecursive(const std::string& sourceDir, const std::string& destDir) {
    for (const auto& entry : fs::directory_iterator(sourceDir)) {
        const auto& path = entry.path();
        const std::string& filename = path.filename().string();
        const std::string& sourcePath = path.string();

        if (fs::is_directory(path)) {
            std::string newDestDir = destDir + "/" + filename;
            fs::create_directory(newDestDir);
            copyPDFFilesRecursive(sourcePath, newDestDir);
        } else if (filename.ends_with(".pdf")) {
            std::string destPath = destDir + "/" + filename;
            fs::copy_file(sourcePath, destPath, fs::copy_options::overwrite_existing);
        }
    }
}
