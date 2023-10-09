#pragma once
#include "FileManager.h"

class FileManagerChild : public FileManager {
public:
    // Constructor, which takes the initial path and initializes the current_path field
    FileManagerChild(string start_path);

    // Method, which shows the contents of the drives
    void showDrives() override;

    // Method, which shows the contents of the current folder
    void showDirectory() override;

    // Method, which creates a folder with the given name in the current folder
    void createDiractory(string dir_name) override;

    // Method, which creates a file with the given name in the current folder
    void createFile(string file_name) override;

    // Method, which deletes a folder or a file with the given name in the current folder
    void remove(string name) override;

    // Method, which renames a folder or a file with the given old and new names in the current folder
    void rename(string old_name, string new_name) override;

    // Method, which copies a folder or a file with the given source and destination
    void copy(string source, string destination) override;

    // Method, which moves a folder or a file with the given source and destination
    void move(string source, string destination) override;

    // Method, which calculates the size of a folder or a file with the given name in the current folder
    uintmax_t size(string name)  override;

    // Method, which performs a search by mask (with subfolder search) in the current folder
    void search(string mask)  override;
};