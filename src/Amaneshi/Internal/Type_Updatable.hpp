#pragma once


namespace amaneshi
{
	namespace type
	{
		class Updatable
		{
		protected:
			Updatable();
		public:
			virtual void Update() = 0;
		};
	}
}