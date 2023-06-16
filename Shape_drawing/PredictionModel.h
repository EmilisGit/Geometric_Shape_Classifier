#pragma once

#include "SDL.h"
#include "Path.h"
#include "PredictNet.h"

/**
 * @class PredictionModel
 * @brief Represents a prediction model for shapes
 */
class PredictionModel {
private:
    coder::array<double, 2U> x; ///< Input x-coordinates for the prediction model
    coder::array<double, 2U> y; ///< Input y-coordinates for the prediction model
    coder::array<double, 2U> output; ///< Output of the prediction model
    double shape = 0; ///< Predicted shape
    float confidence = 0; ///< Confidence score of the prediction
    Path path; ///< Path object to use for prediction
public:
    /**
     * @brief Default constructor for the PredictionModel class
     */
    PredictionModel() {};

    /**
     * @brief Runs the prediction model on the given path
     * @param path Reference to the Path object for prediction
     */
    void RunModel(Path& path);
};
