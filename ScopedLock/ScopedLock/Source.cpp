////#include <chrono>
////#include <functional>
////#include <iostream>
////#include <mutex>
////#include <string>
////#include <thread>
////#include <vector>
////using namespace std::chrono_literals;
////
////struct Employee
////{
////    std::vector<std::string> lunch_partners;
////    std::string id;
////    std::mutex m;
////    Employee(std::string id) : id(id) {}
////    std::string partners() const
////    {
////        std::string ret = "Employee " + id + " has lunch partners: ";
////        for (const auto& partner : lunch_partners)
////            ret += partner + " ";
////        return ret;
////    }
////};
////
////void send_mail(Employee&, Employee&)
////{
////    // simulate a time-consuming messaging operation
////    std::this_thread::sleep_for(1s);
////}
////
////void assign_lunch_partner(Employee& e1, Employee& e2)
////{
////    static std::mutex io_mutex;
////    {
////        std::lock_guard<std::mutex> lk(io_mutex);
////        std::cout << e1.id << " and " << e2.id << " are waiting for locks" << std::endl;
////    }
////
////    {
////        // use std::scoped_lock to acquire two locks without worrying about
////        // other calls to assign_lunch_partner deadlocking us
////        // and it also provides a convenient RAII-style mechanism
////
////        std::scoped_lock lock(e1.m, e2.m);
////
////        // Equivalent code 1 (using std::lock and std::lock_guard)
////        // std::lock(e1.m, e2.m);
////        // std::lock_guard<std::mutex> lk1(e1.m, std::adopt_lock);
////        // std::lock_guard<std::mutex> lk2(e2.m, std::adopt_lock);
////
////        // Equivalent code 2 (if unique_locks are needed, e.g. for condition variables)
////        // std::unique_lock<std::mutex> lk1(e1.m, std::defer_lock);
////        // std::unique_lock<std::mutex> lk2(e2.m, std::defer_lock);
////        // std::lock(lk1, lk2);
////        {
////            std::lock_guard<std::mutex> lk(io_mutex);
////            std::cout << e1.id << " and " << e2.id << " got locks" << std::endl;
////        }
////        e1.lunch_partners.push_back(e2.id);
////        e2.lunch_partners.push_back(e1.id);
////    }
////
////    send_mail(e1, e2);
////    send_mail(e2, e1);
////}
////
////int main()
////{
////    Employee alice("Alice"), bob("Bob"), christina("Christina"), dave("Dave");
////
////    // assign in parallel threads because mailing users about lunch assignments
////    // takes a long time
////    std::vector<std::thread> threads;
////    threads.emplace_back(assign_lunch_partner, std::ref(alice), std::ref(bob));
////    threads.emplace_back(assign_lunch_partner, std::ref(christina), std::ref(bob));
////    threads.emplace_back(assign_lunch_partner, std::ref(christina), std::ref(alice));
////    threads.emplace_back(assign_lunch_partner, std::ref(dave), std::ref(bob));
////
////    for (auto& thread : threads)
////        thread.join();
////    std::cout << alice.partners() << '\n' << bob.partners() << '\n'
////        << christina.partners() << '\n' << dave.partners() << '\n';
////}
//
//#include <iostream>
//#include <mutex>
//#include <string>
//#include <thread>
//
//
//
//std::mutex mute;
//
//void f1(int num)
//{
//
//
//	const std::scoped_lock<std::mutex> lc(mute);
//
////	const std::lock_guard<std::mutex> lock(mute);
//	for (int i = 0; i < 10; i++)
//	{
//		std::cout << "\n Running thread " << num << " for " << i << " th time.";
//	}
//	std::cout << "\n\n";
//}
//
//int main()
//{
//	std::thread t1(f1, 1);
//	std::thread t2(f1, 2);
//
//	
//
//	std::cout << "thread 1 : " << t1.joinable() << '\n';
//	std::cout << "thread 2 : " << t2.joinable() << '\n';
//
//	if (t1.joinable()) t1.join();
//	if (t2.joinable()) t2.join();
//
//
//
//	std::cout << "\n\n\n";
//	return 0;
//}