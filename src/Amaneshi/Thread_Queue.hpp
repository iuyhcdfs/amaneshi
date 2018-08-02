#pragma once
// queues will just have a bunch of tasks
// tasks will finish a job
// jobs will have some form of continuation

// to make this elegant though...
#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>
#include "Thread_Task.hpp"

namespace amaneshi 
{
	namespace thread
	{
		// some ways
		// threads try to consume their queue. wait if nothing there.
		class Task;

		class TaskPool
		{
		protected:
			std::string Name;
			std::mutex Mutex;
			std::condition_variable CV;
			TaskPool() {};
			virtual ~TaskPool() = 0;
		public:
			virtual Task * Consume(void) = 0;
			virtual void Produce(Task * task) = 0;
		};

		class TaskQueue : public TaskPool
		{
		protected:
			std::queue<Task*> Queue;
		public:
			TaskQueue();
			Task * Consume(void);
			void Produce(Task * task);
		};

		// class TaskBuffer : public TaskPool {};

	}
}