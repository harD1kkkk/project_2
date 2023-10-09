#include "FileManagerChild.h"

// Constructor, which takes the initial path and initializes the current_path field
FileManagerChild::FileManagerChild(string start_path) {

    current_path = fs::path(start_path);

    if (!fs::exists(current_path)) {

        cerr << "Starting path does not exist: " << start_path << "\n";
    }
}

// Show a list of available drives
void FileManagerChild::showDrives() {
    for (const auto& entry : fs::directory_iterator("/")) {
        if (entry.is_directory()) {
            cout << entry.path().filename() << "\n";
        }
    }
}

// Show the contents of the current directory
void FileManagerChild::showDirectory() {
    for (const auto& entry : fs::directory_iterator(current_path)) {
        cout << entry.path().filename() << "\n";
    }
}

// Create a new directory in the current directory with the specified name
void FileManagerChild::createDiractory(string dir_name) {
    fs::path new_dir = current_path / dir_name;
    if (fs::create_directory(new_dir)) {
        cout << "Catalog: " << dir_name << "Directory created successfully.\n";
    }
    else {
        cerr << "Catalog creation error!" << dir_name << "\n";
    }
}

// Create a new file in the current directory with the specified name
void FileManagerChild::createFile(string file_name) {
    fs::path new_file = current_path / file_name;
    ofstream file(new_file);
    if (file.is_open()) {
        cout << "File: " << file_name << " Created successfully.\n";
        file.close();
    }
    else {
        cerr << "File creation failed!" << file_name << "\n";
    }
}

// Remove a directory or file from the current directory with the specified name
void FileManagerChild::remove(string name) {
    fs::path target = current_path / name;
    try {
        fs::remove_all(target);
        cout << "Element removed successfully." << endl;
    }
    catch (fs::filesystem_error& ex) {
        
        cout << ex.what() << endl;
    }
}

// Rename a directory or file in the current directory
void FileManagerChild::rename(string old_name, string new_name) {
    fs::path old_path = current_path / old_name;
    fs::path new_path = current_path / new_name;
    try {
        fs::rename(old_path, new_path);
        cout << "Element renamed successfully." << endl;
    }
    catch (fs::filesystem_error& ex) {
        cout << ex.what() << endl;
    }
}

// Copy a directory or file from the current directory to another location
void FileManagerChild::copy(string source, string destination) {
    fs::path src = current_path / source;
    fs::path dst = current_path / destination;
    try {
        fs::copy(src, dst, fs::copy_options::recursive);
        cout << "Element copied successfully." << endl;
    }
    catch (fs::filesystem_error& ex) {
        cout << ex.what() << endl;
    }
}

// Move a directory or file from the current directory to another location
void FileManagerChild::move(string source, string destination) {
    fs::path src = current_path / source;
    fs::path dst = current_path / destination;
    try {
        fs::rename(src, dst);
        cout << "Element moved successfully." << endl;
    }
    catch (fs::filesystem_error& ex) {
        cout << ex.what() << endl;
    }
}

// Get the size of a directory or file with the specified name in the current directory
uintmax_t FileManagerChild::size(string name) {
    fs::path target = current_path / name;
    if (fs::exists(target)) {
        try {
            if (fs::is_regular_file(target)) {
                return fs::file_size(target);
            }

            else if (fs::is_directory(target)) {
                uintmax_t total_size = 0;
                for (const auto& entry : fs::recursive_directory_iterator(target)) {
                    if (fs::is_regular_file(entry)) {
                        total_size += fs::file_size(entry);
                    }
                }
                return total_size;
            }
        }
        catch (const std::exception& ex) {
            cerr << "Size calculation error! " << name << ": " << ex.what() << "\n";
        }
    }
    else {
        cerr << "File or directory! " << name << " does not exist.\n";
    }
}

// Search for files and directories matching the specified mask (regular expression)
void FileManagerChild::search(string mask) {
    regex re(mask);
    int count = 0;
    for (const auto& entry : fs::recursive_directory_iterator(current_path)) {
        string name = entry.path().filename().string();
        if (regex_match(name, re)) {
            cout << entry.path().string() << '\n';
            count++;
        }
    }
    cout << "Found " << count << " elements matching the mask " << mask << '\n';
} 