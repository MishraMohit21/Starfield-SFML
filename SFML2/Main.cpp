#include "Starfield.h"




int main()
{
	srand(static_cast<unsigned>(time(NULL)));

	Starfield starfield;

	while (starfield.running()) {

		starfield.update();
		//starfield.updateStar();
		starfield.render();
	}

	
	return 0;
}