#include "Thread_Queue.hpp"

amaneshi::thread::TaskQueue::TaskQueue()
{
	this->Name = "";
}

amaneshi::thread::Task * amaneshi::thread::TaskQueue::Consume(void)
{
	std::unique_lock<std::mutex> lock(this->Mutex);
	if (Queue.size == 0) {
		this->CV.wait(lock);
	}
	Task * popped = Queue.front();
	Queue.pop();
	return popped;
}

void amaneshi::thread::TaskQueue::Produce(Task * task)
{
	std::unique_lock<std::mutex> lock(this->Mutex);
	Queue.push(task);
}
