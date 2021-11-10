//#include <iostream>
//#include <thread>
//#include <mutex>
//using std::cout;
//using std::thread;
//
//std::mutex dataLock;
//void count(const int pLowerLimit, const int pUpperLimit)
//{
//	for (int i = pLowerLimit; i < pUpperLimit; i++)
//	{
//		cout << i << "\n";
//	}
//	//dataLock.lock();
//	//dataLock.unlock();
//}
//
//void main()
//{
//	const int THREAD_COUNT = 10;
//	int numberCount = 100;
//	thread* myThreads = new thread[THREAD_COUNT];
//	int lowLimit = 0;
//	int upperLimit = THREAD_COUNT;
//	for (int i = 0; i < THREAD_COUNT; i++)
//	{
//		*myThreads = thread(count, lowLimit, upperLimit);
//		myThreads->join();
//		myThreads++;
//		//auto lowerUpperLimit = []{
//		//  //lowLimit = 10;//};
//		lowLimit += THREAD_COUNT;
//		upperLimit += THREAD_COUNT;
//	}
//	delete[] myThreads;
//}