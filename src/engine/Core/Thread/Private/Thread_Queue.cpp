#include "Thread_Queue.hpp"

amaneshi::thread::TaskQueue::TaskQueue()
{
	this->Name = "";
}

amaneshi::thread::TaskQueue::~TaskQueue()
{
}

amaneshi::thread::Task * amaneshi::thread::TaskQueue::Consume(void)
{
	std::unique_lock<std::mutex> lock(this->Mutex);
	if (this->Queue.size() == 0) {
		this->CV.wait(lock);
	}
	Task * popped = this->Queue.front();
	this->Queue.pop();
	return popped;
}

void amaneshi::thread::TaskQueue::Produce(Task * task)
{
	std::unique_lock<std::mutex> lock(this->Mutex);
	Queue.push(task);
	lock.unlock();
	this->CV.notify_one();
}
