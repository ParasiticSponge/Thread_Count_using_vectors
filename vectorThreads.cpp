#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using std::cout;
using std::thread;
using std::vector;

vector<int> threads;
int countFactor;

std::mutex dataLock;
void count(const int pLowerLimit, const int pUpperLimit)
{
	dataLock.lock();
	for (int i = pLowerLimit; i < pUpperLimit; i++)
	{
		cout << threads[i] << "\n";
	}
	dataLock.unlock();
}

void main()
{
	threads.push_back(1);
	threads.push_back(2);
	threads.push_back(3);
	threads.push_back(4);
	threads.push_back(5);
	threads.push_back(6);
	threads.push_back(7);
	threads.push_back(8);
	threads.push_back(9);
	threads.push_back(10);

	int maxNum = 50;
	for (int i = 2; i < maxNum; i++) //avoid dividing the number by 1 and itself, continue up from 2
		if (threads.size() % i == 0)
			countFactor = i;
		else
			countFactor = threads.size();

	int THREAD_COUNT = threads.size()/countFactor; //find the best thread divisor
	thread* myThreads = new thread[THREAD_COUNT];
	int lowLimit = 0; //good
	int upperLimit = THREAD_COUNT;

	for (int i = 0; i < THREAD_COUNT; i++) //from 0 to thread divisor
	{
		*myThreads = thread(count, lowLimit, upperLimit); //from 0 
		myThreads->join();

		myThreads++;
		lowLimit += THREAD_COUNT;
		upperLimit += THREAD_COUNT;
	}

	//for (int i = 0; i < THREAD_COUNT; i++) //from 0 to thread divisor
	//{
	//	*myThreads = thread(count, lowLimit, upperLimit); //from 0 
	//	myThreads->join();

	//	myThreads++;
	//	lowLimit += THREAD_COUNT;
	//	upperLimit += THREAD_COUNT;
	//}

	//delete[] myThreads;
}