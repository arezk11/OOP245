#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

#define DATAFILE "PCpopulationsComplete.csv"
namespace sdds {

	struct Population 
	{
		char* m_code;
		int m_pop;

	};

	void sort();

	//loads data into a Population object.
        //and takes a reference to a Population object as a parameter.
	bool load(Population& pop);
	
	//loads data from a file with the given filename.
	bool load(const char filename[]);

	//displays information about a Population object.
	void display(const Population& pop);

	//displays information about the Population objects.
	void display();

	//eallocates memory used by the Population objects.
	void deallocateMemory();

}
#endif // SDDS_POPULATION_H_
