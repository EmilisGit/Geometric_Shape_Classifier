function [shape, confidence] = predictNet(x,y)
%#codegen
  %% Image processing
    % Determine the dimmensions of the image
    maxX = max(x);
    maxY = max(y);
    minX = min(x);
    minY = min(y);
    width = maxX - minX + 1;
    height = maxY - minY + 1;
    
    % Create an empty image
    image = zeros(height, width);
    
    % Convert the coordinates to image pixels
    pixelX = x - minX + 1;
    pixelY = y - minY + 1;
    
    % Set the corresponding pixels in the image to black
    for i = 1:numel(x)
        image(pixelY(i), pixelX(i)) = 1;
    end
    %% Dilation operation
    % using dilation, we can thicken the line of the shape
    % scale_ratio deals with different sized images, since the input
    % for the strel function is a fixed amount of pixels
    scale_ratio = fix(0.02 * max(width, height)); 
    se = strel('disk', scale_ratio); 
    dilImage = imdilate(image, se);
    % inverse the color
    image = ~dilImage;
    %% Resize the image to the specified size using bilinear interpolation
    image = imresize(image,[28,28], 'bilinear');
    image = double(image);
    %% Prediction

    persistent net;
    if isempty(net)
        net = coder.loadDeepLearningNetwork('saved_weights.mat', 'net');
    end
    % prediction
    prediction = predict(net, image);
    [~, classIndex] = max(prediction);
  
    shape = classIndex - 1;
    confidence = prediction(classIndex);
end