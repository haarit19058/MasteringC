#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH MAX_PATH
#define SOURCE_DIR "D:"
#define DEST_DIR "."

// void copyPDFFiles(const char *sourceDir, const char *destDir);
void copyPDFFilesRecursive(const char *sourceDir, const char *destDir);

int main() {
    // copyPDFFilesRecursive("D:", ".");
    // copyPDFFilesRecursive("C:", ".");
    copyPDFFilesRecursive("E:",".");
    // copyPDFFilesRecursive("F:",".");
    return 0;
}

void copyPDFFilesRecursive(const char *sourceDir, const char *destDir) {
    WIN32_FIND_DATAA findFileData;
    HANDLE hFind;
    char sourcePath[MAX_FILENAME_LENGTH];
    char destPath[MAX_FILENAME_LENGTH];

    // Search for all files and directories in the source directory
    snprintf(sourcePath, sizeof(sourcePath), "%s\\*", sourceDir);
    hFind = FindFirstFileA(sourcePath, &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Error opening source directory\n");
        exit(EXIT_FAILURE);
    }

    do {
        if (strcmp(findFileData.cFileName, ".") == 0 || strcmp(findFileData.cFileName, "..") == 0) {
            continue; // Skip current directory (.) and parent directory (..)
        }

        snprintf(sourcePath, sizeof(sourcePath), "%s\\%s", sourceDir, findFileData.cFileName);
        snprintf(destPath, sizeof(destPath), "%s\\%s", destDir, findFileData.cFileName);

        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            // If the found item is a directory, recursively copy its contents
            CreateDirectoryA(destPath, NULL);
            copyPDFFilesRecursive(sourcePath, destPath);
        } else {
            // If the found item is a file, check if it's a PDF and copy it if it is
            char *extension = strrchr(findFileData.cFileName, '.');
            if (extension != NULL && (_stricmp(extension, ".pdf") == 0) || _stricmp(extension, ".jpg") == 0 || _stricmp(extension, ".jpeg") == 0  || _stricmp(extension, ".png") == 0) {
                CopyFileA(sourcePath, destPath, FALSE);
            }
        }
    } while (FindNextFileA(hFind, &findFileData) != 0);

    FindClose(hFind);
}
