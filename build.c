#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Paths and filenames
#define SRC_DIR "src"
#define BUILD_DIR "build"
#define BIN_DIR "bin"
#define INCLUDE_DIR "include"
#define TARGET "./bin/UGDC-Engine"

// Compiler and flags
#define CC "gcc"
#define CXX "g++"
#define CFLAGS "-Wall -Wextra -std=c11 -MMD -Wno-unused-parameter"
#define CXXFLAGS "-Wall -Wextra -std=c++17 -MMD -Wno-unused-parameter"


void build(void) {
    // Create the build and bin directories
    printf("Creating build directory...\n");
    system("mkdir -p build");
    printf("Creating bin directory...\n");
    system("mkdir -p bin");

    // Find all .cpp files and store them in a temporary file
    system("find src -name '*.cpp' > cfiles.txt");

    // Open the temporary file
    FILE *cfiles = fopen("cfiles.txt", "r");
    if (!cfiles) {
        perror("Failed to open cfiles.txt");
        return;
    }

    // Collect all .cpp files for a single compilation
    char cmd[1024] = {0};
    sprintf(cmd, "%s %s -I%s -o %s/UGDC-Engine ", CXX, CXXFLAGS, INCLUDE_DIR, BIN_DIR);

    char line[256];
    while (fgets(line, sizeof(line), cfiles)) {
        line[strcspn(line, "\n")] = 0; // Remove newline character
        strcat(cmd, line);
        strcat(cmd, " ");
    }

    fclose(cfiles);
    system("rm cfiles.txt"); // Clean up temporary file

    // Compile all source files into the final binary
    printf("Compiling source files...\n");
    if (system(cmd) != 0) {
        printf("Compilation failed.\n");
        return;
    }

    printf("Compilation successful. Binary created at %s.\n", TARGET);
}

void clean(void) {
    // Remove the build directory
    printf("Cleaning build directory...\n");
    char cmd[256];
    sprintf(cmd, "rm -rf %s", BUILD_DIR);
    system(cmd);

    // Remove the bin directory
    printf("Cleaning bin directory...\n");
    sprintf(cmd, "rm -rf %s", BIN_DIR);
    system(cmd);
}

void run(void) {
    char cmd[256];
    sprintf(cmd, "./%s", TARGET);
    system(cmd);
}

int main(int argc, char *argv[]) {
    
    bool hasArg = false;

    if (argc > 1) {
        hasArg = true;
    } else {
        printf("No arguments provided.\n");
    }

    if (strcmp(argv[1], "clean") == 0) {
        clean();
        return 0;
    } else if (strcmp(argv[1], "run") == 0) {
        run();
        return 0;
    } 

    // Run the build process
    build();

    printf("Build completed successfully.\n");
    return 0;
}

