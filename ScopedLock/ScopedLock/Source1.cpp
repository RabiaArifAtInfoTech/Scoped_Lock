#include<iostream>
#include<thread>
#include<mutex>
#include<boost/interprocess/sync/scoped_lock.hpp>
using namespace std;
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>
#include <iostream>

class Scoped_lock1
{
	std::mutex *mute;
	bool  muteLocked;

public:
	Scoped_lock1() {
		std::cout << "\nDefault Constructor of Scoped_lock is called\n";
		mute = 0;
		muteLocked = false;
	}
	Scoped_lock1(std::mutex& mute1) {
		//std::cout << "\nConstructor of Scoped_lock is called\n";
		mute = &mute1;
		
		muteLocked = false;

		mute->lock();
		
		std::cout << "\nConstructor of Scoped_lock is called of " << this << "\n";
		std::cout << "\nConstructor of Scoped_lock is called\n";
		muteLocked = true;
	}
	~Scoped_lock1() {
		std::cout << "\nDestructor of Scoped_lock is called\n";
		if (muteLocked) {
			mute->unlock();
			std::cout << "\nmutex unlock \n";
		}
	}
};
 
std::mutex mute1;

void f1(int num)
{

    //boost::mutex::scoped_lock sp(std::mutex);
	//std::scoped_lock<std::mutex> sp(std::mutex);
	//std::scoped_lock<std::mutex> sp1(mute1);
	
	//custom class ......// working .........how ? .......... i dont know ;)
	
	//mute1.lock();
	//Scoped_lock1 lc(std::mutex);

	Scoped_lock1 lc(mute1);


	for (int i = 0; i < 10; i++)
	{
		std::cout << "\n Running thread " << num << " for " << i << " th time.";
	}
	std::cout << "\n\n";
}

int main()
{
	std::thread t1(f1, 1);
	std::thread t2(f1, 2);

	/*t1.join();

	t2.join();*/

	/*t1.detach();

	t2.detach();*/

	std::cout << "thread 1 : " << t1.joinable() << '\n';
	std::cout << "thread 2 : " << t2.joinable() << '\n';
	
	std::thread t3(f1, 3);
	
	std::cout << t1.get_id() << std::endl;
	std::cout << t2.get_id() << std::endl;
	std::cout << t3.get_id() << std::endl;
	if(t3.joinable())
		t3.join();

	if (t1.joinable()) 
		t1.join();
	if (t2.joinable()) 
		t2.join();

	

	


	std::cout << "\n\n\n";
	return 0;
}