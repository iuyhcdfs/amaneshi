#pragma once

// look. its more important to have something working
// clearly adapted from https://www.gdcvault.com/play/1012321/Task-based-Multithreading-How-to

// what they said:
	// tasks delegate the divisible chunks of a job 
	// tasks should be stateless
	// tasks are job+context

#include <string>
#include <atomic>
#include <functional>
#include <vector>
#include <mutex>
#include <condition_variable>

namespace amaneshi
{
	namespace thread
	{
		class Task 
		{
		protected:
			std::string Name;
			std::atomic<int> PendingParents;
			std::vector<Task*> ChildTasks;
			void SignalChildren();
			std::mutex Mutex;
			std::condition_variable CV;
			Task();
			virtual ~Task() = 0;

		public:
			std::function<void(void)> Work;
			void BlockIfPendingParents();
			void ClearOneParent();
			int RemainingParents();

			void operator() (void) { this->Work(); }
		};
	}
}