#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds 
{
	bool openFile(const char filename[]);
    void closeFile();
    int noOfRecords();

	//reads input and store it in a character array,
	bool read(char* code);

	//reads input and assign the value to int reference
	bool read(int& pop);

}
#endif // !SDDS_FILE_H_