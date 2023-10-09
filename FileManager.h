#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <regex>
using namespace std;
namespace fs = std::filesystem;

class FileManager
{
protected:
	fs::path current_path;
public:
	void virtual showDrives() = 0;
	void virtual showDirectory() = 0;

	void virtual createDiractory(string dir_name) = 0;
	void virtual createFile(string file_name) = 0;

	void virtual remove(string name) = 0;
	void virtual rename(string old_name, string new_name) = 0;
	void virtual move(string source, string destination) = 0;
	void virtual copy(string source, string destination) = 0;
	uintmax_t virtual size(string name) = 0;
	void virtual search(string mask) = 0;
};