#include "Thread_Task.hpp"

void amaneshi::thread::Task::SignalChildren()
{
	for (Task* Child : this->ChildTasks) {
		Child->ClearOneParent();
	}
}

amaneshi::thread::Task::Task()
{
	this->Name = "";
	this->PendingParents = 0;
}

void amaneshi::thread::Task::BlockIfPendingParents()
{
		std::unique_lock<std::mutex> lock(this->Mutex);
	if (this->PendingParents > 0) {
		this->CV.wait(lock);
		
	}
}

void amaneshi::thread::Task::ClearOneParent()
{
	this->PendingParents--;
	if (this->PendingParents == 0) {
		std::unique_lock<std::mutex> lock(this->Mutex);
		this->CV.notify_one();
	}
}

int amaneshi::thread::Task::RemainingParents()
{
	// David: can you inline atomic access?...
	return this->PendingParents;
}

