#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using std::cout;
using std::thread;
using std::vector;

vector<int> imageFiles;
int threads;

std::mutex dataLock;
void count(const int pLowerLimit, const int pUpperLimit)
{
	dataLock.lock();
	for (int i = pLowerLimit; i < pUpperLimit; i++)
	{
		cout << imageFiles[i] << "\n";
	}
	dataLock.unlock();
}

void main()
{
	imageFiles.push_back(1);
	imageFiles.push_back(2);
	imageFiles.push_back(3);
	imageFiles.push_back(4);
	imageFiles.push_back(5);
	imageFiles.push_back(6);
	imageFiles.push_back(7);
	imageFiles.push_back(8);
	imageFiles.push_back(9);
	imageFiles.push_back(10);
	imageFiles.push_back(1);
	imageFiles.push_back(2);
	imageFiles.push_back(3);
	imageFiles.push_back(4);
	imageFiles.push_back(5);
	imageFiles.push_back(6);
	imageFiles.push_back(7);
	imageFiles.push_back(8);
	imageFiles.push_back(9);
	imageFiles.push_back(10);

	int maxNum = 50;
	for (int i = 2; i < maxNum; i++) //avoid dividing the number by 1, continue up from 2
		//if the remainder of a number divided by the thread size is 0
		//also making sure it doesn't divide by itself
		if (imageFiles.size() % i == 0 && i != imageFiles.size())
		{
			threads = i;
			cout << threads << "\n\n";
		}
		/*else if (imageFiles.size() % i > 0)
			threads = imageFiles.size();*/

	cout << "\n\n";

	int THREAD_COUNT = threads; //find the best number divided by the vector size
	//cout << "There are " << THREAD_COUNT << " files per thread count\n";
	
	//thread myThreads[5]; //make 5 threads
	thread* myThreads = new thread[THREAD_COUNT];

	int lowLimit = 0;

	//upperLimit = 2
	//upper limit is how many values should be stored in each thread, evenly distributed between threads.
	int upperLimit = imageFiles.size() / threads;

	//keep a variable that stores the count of each thread to increase by after each iteration of the loop
	const int increasingLimit = upperLimit;

	for (int i = 0; i < THREAD_COUNT; i++) //from 0 to 5
	{
		*myThreads = thread(count, lowLimit, upperLimit); //from [0] to [1]
		cout << "\n\n";
		myThreads->join();

		//move onto the next thread
		myThreads++;

		lowLimit += increasingLimit; //add 2 to lowerLimit
		upperLimit += increasingLimit; //add 2 to upperLimit
	}
}