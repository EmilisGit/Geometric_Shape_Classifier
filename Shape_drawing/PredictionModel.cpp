#include "PredictionModel.h"

void PredictionModel::RunModel(Path& path) {
	x = path.getXPointsAsDouble();
	y = path.getYPointsAsDouble();
	predictNet(x, y, &shape, &confidence);
	std::cout << "predictNet outputs:\n";

	if(shape == 0)
		std::cout << "Shape : Circle" << std::endl;
	else if(shape == 1)
		std::cout << "Shape : Square" << std::endl;
	else std::cout <<"Shape : Triangle" <<std::endl;
	std::cout << "Confidence : " << confidence << std::endl;
	/*
	* For testing purposes
	* 
	std::cout << "X Points:";
	for (const auto& x : path.getXPointsAsDouble()) {
		std::cout << " " << x;
	}
	std::cout << std::endl;

	std::cout << "Y Points:";
	for (const auto& y : path.getYPointsAsDouble()) {
		std::cout << " " << y;
	}
	std::cout << std::endl;
	*/
}