#include "pch.h"

#include "Dynamic/Dynamic.h"
#include "Static/Static.h"
#include "Functional/Functional.h"


int main() { 

	Dynamic::exec();
	Static::exec();
	Functional::exec();

	return 0; 
}