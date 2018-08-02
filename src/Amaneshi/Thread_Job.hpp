#pragma once

// amaneshi jobs contain the context of a series of tasks if needed
// THIS STOPS A UGLY MESS OF CONTINUATIONS

// that is all.

#include "Thread_Queue.hpp"
#include "Thread_Task.hpp"

namespace amaneshi
{
	namespace thread
	{

		/*
		so on an abstract sense da heck is a job

		job's gotta have the sequence

		job might deal with carryover data
		say the game state is an ongoing job
		and its in tandem with the rendering thang

		in terms of execution...
		we can put the task into the queue
		and once the work's done
		report back and we'll decide what to do next.

		we dont decide when our work gets done
		but we enforce the order and such


		is there some othe rway to do this hmm
		*/

		class Job 
		{
		protected:

		public:
			virtual void Post() = 0;
			void Pause();
			void Resume();
		};
	}
}