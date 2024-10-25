#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>

class FileIO{
public:
	std::string File;
	std::string Path;

	std::ofstream oFile;
	std::ifstream iFile;

	std::string Mode;
	bool Append;
	bool IsOpen;
	
	

	FileIO();
	FileIO(std::string file);
	~FileIO();

	bool Open();
	bool Open(std::string file);
	void Close();
	void NoSpaces();
	
	int I();
	std::string S();
	float F();
	double D();
		
	void Read(std::string &Str);
	FileIO& operator>>(std::string &Str);

	void Read(int &num);
	FileIO& operator>>(int &num);

	void Read(float &num);
	FileIO& operator>>(float &num);

	void Read(double &num);
	FileIO& operator>>(double &num);

	void Write(std::string Str);
	FileIO& operator<<(std::string);
	FileIO& operator<(std::string Str);

	void Write(int num);
	FileIO& operator<<(int num);

	void Write(float num);
	FileIO& operator<<(float num);

	void Write(double num);
	FileIO& operator<<(double num);

	bool Good();
	bool End();
};
FileIO::FileIO(){
	Append = false;
	Mode = "Input";
	IsOpen = false;
}

FileIO::FileIO(std::string file){
	Append = false;
	Mode = "Input";
	IsOpen = false;

	Open(file);
}

void FileIO::NoSpaces(){
	std::replace(Path.begin(), Path.end(), ' ', '_');
	std::replace(File.begin(), File.end(), ' ', '_');
}

bool FileIO::Open(){
	std::string FullPath = Path + File;
	if(Mode == "Input"){
		iFile.open(FullPath.c_str());
		IsOpen = iFile.is_open();
	}
	else{
		if(Append){
			oFile.open(FullPath.c_str(), std::ofstream::out | std::ofstream::app);
			IsOpen = oFile.is_open();
		}
		else{
			oFile.open(FullPath.c_str(), std::ofstream::out);
			IsOpen = oFile.is_open();
		}
	}

	if(IsOpen){
		std::cout << FullPath << " Is Open for " << Mode << std::endl;
	}
	else{
		std::cout << FullPath << " did not Open\n";
	}
	return IsOpen;
}

bool FileIO::Open(std::string file){
	File = file;
	return Open();
}

void FileIO::Close(){
	if(Mode == "Input")iFile.close();
	else oFile.close();
	IsOpen = false;
	std::cout << File << " is Closed" << std::endl;
}

void FileIO::Read(std::string &Str){
	Mode = "Input";
	if(not IsOpen)Open();

	std::string Input;
	std::string Line_With_Spaces;
	bool GoodLine;
		do{
			iFile >> Input;
			if(Input.at(0) == '\n' or Input.at(0) == '/' or Input.at(0) == '#'){
				GoodLine = false;
				getline(iFile, Input);
			}
			else if(Input.at(0) == '"'){
				Line_With_Spaces = Input;
				while(Line_With_Spaces.at(Line_With_Spaces.length()-1) != '"'){
					iFile >> Input;
					Line_With_Spaces += " " + Input;
				}
				//Line_With_Spaces += Input;
				//Remove the "s
				Line_With_Spaces.erase(std::remove(Line_With_Spaces.begin(), Line_With_Spaces.end(), '"'));
				Line_With_Spaces.erase(std::remove(Line_With_Spaces.begin(), Line_With_Spaces.end(), '"'));
				Input = Line_With_Spaces;
				GoodLine = true;
			}
			else GoodLine = true;

		}while (not GoodLine);
		Str = Input;
}

FileIO& FileIO::operator>>(std::string &Str){Read(Str); return *this;}

void FileIO::Read(int &num){
	std::string Input;
	Read(Input);
	num = std::stoi(Input);
}

FileIO& FileIO::operator>>(int &num){Read(num); return *this;}

void FileIO::Read(float &num){
	std::string Input;
	Read(Input);
	num = std::stof(Input);
}

FileIO& FileIO::operator>>(float &num){Read(num); return *this;}

void FileIO::Read(double &num){
	std::string Input;
	Read(Input);
	num = std::stod(Input);
}

FileIO& FileIO::operator>>(double &num){Read(num); return *this;}

void FileIO::Write(std::string Str){
	Mode = "Output";
	if(not IsOpen)Open();
	oFile << Str;
}

FileIO& FileIO::operator<<(std::string Str){
	if(Append){
		Append = false;
		if(IsOpen){Close();}
		Open();
	}

	Write(Str);
	return *this;
}

FileIO& FileIO::operator<(std::string Str){
	if(not Append){
		Append = true;
		if(IsOpen){Close();}
		Open();
	}

	Write(Str);
	return *this;
}

void FileIO::Write(int num){
	oFile << num;
}

FileIO& FileIO::operator<<(int num){Write(num); return *this;}

void FileIO::Write(float num){
	oFile << num;
}

FileIO& FileIO::operator<<(float num){Write(num); return *this;}

void FileIO::Write(double num){
	oFile << num;
}

FileIO& FileIO::operator<<(double num){Write(num); return *this;}

bool FileIO::End(){
	return iFile.eof();
}

bool FileIO::Good(){
	return iFile.good();
}

FileIO::~FileIO(){
	if(IsOpen)Close();
}

int FileIO::I(){
	int i;
	Read(i);
	return i;
}

std::string FileIO::S(){
	std::string Input;
	Read(Input);
	return Input;
}

float FileIO::F(){
	std::string Input;
	Read(Input);
	return std::stof(Input);
}

double FileIO::D(){
	std::string Input;
	Read(Input);
	return std::stod(Input);
}