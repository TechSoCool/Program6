// Sterling Gerard
// Date: April 6, 20222
// Objectice: Design a class that has an array of floating-point numbers.
// The constructor should accept an integer argument and dynamically allocate
// the array to hold that many numbers. The destructor should free the memory held
// by the array.

#include<iostream>
#include<iomanip>

using namespace std;

class FloatingNumberArray {
	private:
		float* aptr; //pointer pointing to the array
		int aSize; // array Size
		float max, min, avg;
	public:
		FloatingNumberArray(int); // Constructor accept int argument
		~FloatingNumberArray(); // Destructor

		int size() const // arrary size
		{
			return aSize;
		}
		void storeNum(float num, int element); 
		float getNum(int element);
		float getHigh();
		float getLow();
		float getAvg();
};

// Constructor Floating Number Array class
// array and allocates memory for it 
FloatingNumberArray::FloatingNumberArray(int s) 
{
	aSize = s;
	aptr = new float[s];
	for (int cnt = 0; cnt < aSize; cnt++)
		*(aptr + cnt) = 0;
}

// Destructor for Floating Number Array class
FloatingNumberArray::~FloatingNumberArray()
{
	if (aSize > 0)
		delete[] aptr;
}

// Store Number 
void FloatingNumberArray::storeNum(float num, int element)
{
	if (element < aSize)
		*(aptr + element) = num;
}

// Get Number
float FloatingNumberArray::getNum(int element)
{
	return *(aptr + element);
}

// Get Highest
float FloatingNumberArray::getHigh()
{
	float high = *(aptr + 0);
	for (int i = 0; i < aSize; i++)
		if (high < *(aptr + i))
			high = *(aptr + i);
		return high;
}

// Get Lowest
float FloatingNumberArray::getLow()
{
	float low = *(aptr + 0);
	for (int i = 0; i < aSize; i++)
		if (low > *(aptr + i))
			low = *(aptr + i);
		return low;
}

// Get Average
float FloatingNumberArray::getAvg()
{
	float avg = 0;
	for (int i = 0; i < aSize; i++)
		avg += *(aptr + i);
		avg = avg / aSize;
		return avg;
}

//+++++++++++++++++Main Program++++++++++++++++++
int main() {

	const int Size = 10; // size of the array

	// Define Floating Number array with 10 elements

	// call functions
	FloatingNumberArray table(Size);
	table.storeNum(1, 0);
	table.storeNum(3, 1);
	table.storeNum(7, 2);
	table.storeNum(2, 3);

	// Display values
	cout << "Highest Value: " << table.getHigh() << endl;
	cout << "Lowest Value:  " << table.getLow() << endl;
	cout << "Average:       " << table.getAvg() << endl;

	system("pause");
	return 0;
}