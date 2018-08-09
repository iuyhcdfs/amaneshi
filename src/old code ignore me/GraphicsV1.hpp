#pragma once


namespace amaneshi {

	// V1 renderable: literally draw the thing
	class Renderable {
	public:
		virtual void Render() = 0;
	};

} // namespace amaneshi