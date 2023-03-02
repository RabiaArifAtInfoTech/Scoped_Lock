#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

template<class Mutex>
class Scoped_lock
{
	Mutex *mute;
	bool  muteLocked;

public:
	Scoped_lock() {
		std::cout << "\nDefault Constructor of Scoped_lock is called\n";
		mute = 0;
		muteLocked = false;
	}
	//explicit Scoped_lock(Mutex& mute1) : mute(&mute1), muteLocked(false) {
	explicit Scoped_lock(Mutex& mute1) {
		//std::cout << "\nConstructor of Scoped_lock is called\n";
		mute = &mute1;
		
		muteLocked = false;

		mute->lock();
		
		std::cout << "\nConstructor of Scoped_lock is called\n";
		muteLocked = true;
	}
	~Scoped_lock() {
		std::cout << "\nDestructor of Scoped_lock is called\n";
		if(muteLocked)
			mute->unlock();
		
	}
};
 
mutex mute1;

void f1(int num)
{
	Scoped_lock<mutex> lc(mute1);
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

	if (t1.joinable()) 
		t1.join();
	if (t2.joinable()) 
		t2.join();

	/*std::cout << t1.get_id() << std::endl;
	std::cout << t2.get_id() << std::endl;*/


	std::cout << "\n\n\n";
	return 0;
}