# Geometric_Shape_Classifier
A program that recognises hand drawn triangles, squares and circles, that utilises Matlab coder generated prediction function.

The program opens a SDL window, on which a user can draw. Any drawn object will be classified using the PredincNet prediction function generated using Matlab coder app. The prediction function is made by training a convolutional neural network and saving it's weights.

To run this project, it is necessary to have Matlab and to include it's libraries in MATLAB/bin/win64 folder. The predictNet dll and it's dependancies are provided in the predictNet_V2 folder. The Matlab ML model and function is also provided.
