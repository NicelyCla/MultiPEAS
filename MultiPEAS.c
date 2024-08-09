#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void execute_command(const char *process_name, const char *command_to_run) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    char command[8192];
    char filename[256];

    // Create the file name for the current process
    snprintf(filename, sizeof(filename), "%s.txt", process_name);

    // Create the command with output redirection
    snprintf(command, sizeof(command), "cmd.exe /c %s", command_to_run);

    // Clear the structures
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Create the process that will execute the command
    if (!CreateProcess(NULL,   // Module name (NULL to use the command directly)
        command,               // Command to execute
        NULL,                  // Process security attributes
        NULL,                  // Thread security attributes
        FALSE,                 // Inherit handles
        0,                     // Process creation flags
        NULL,                  // Process environment
        NULL,                  // Current working directory
        &si,                   // Startup information
        &pi)                   // Process information
    ) {
        printf("Process creation %s failed (%d).\n", process_name, GetLastError());
        return;
    }

    // Wait for the process to finish
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

int main() {
    char process_name[50];
    char command[8192];
    FILE *file = fopen("all_checks.txt", "r");

    if (file == NULL) {
        printf("Error opening file test.txt\n");
        return 1;
    }

    int process_count = 1;
    while (fgets(command, sizeof(command), file)) {
        // Remove the trailing newline character, if present
        command[strcspn(command, "\n")] = 0;

        // Generate the process name as "process_number"
        snprintf(process_name, sizeof(process_name), "process_%d", process_count);

        // Execute the command
        execute_command(process_name, command);

        process_count++;
    }

    fclose(file);
    return 0;
}
