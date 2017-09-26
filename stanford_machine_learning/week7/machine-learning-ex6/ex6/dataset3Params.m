function [C, sigma] = dataset3Params(X, y, Xval, yval)
%DATASET3PARAMS returns your choice of C and sigma for Part 3 of the exercise
%where you select the optimal (C, sigma) learning parameters to use for SVM
%with RBF kernel
%   [C, sigma] = DATASET3PARAMS(X, y, Xval, yval) returns your choice of C and
%   sigma. You should complete this function to return the optimal C and
%   sigma based on a cross-validation set.
%

% You need to return the following variables correctly.
C = 1;
sigma = 0.3;

% ====================== YOUR CODE HERE ======================
% Instructions: Fill in this function to return the optimal C and sigma
%               learning parameters found using the cross validation set.
%               You can use svmPredict to predict the labels on the cross
%               validation set. For example,
%                   predictions = svmPredict(model, Xval);
%               will return the predictions on the cross validation set.
%
%  Note: You can compute the prediction error using
%        mean(double(predictions ~= yval))
%

values = [0.01 0.03 0.05 0.1 0.2 0.3 0.5 0.7 1 3 5 7 10 15 20 25 30];
error_min = inf;

fprintf('Calculating optimal C and sigma. This might take a while.\n');
fprintf('Take it easy ang go get me a cup of coffee !!\n');

for C_i = values
  for sigma_i = values

    fprintf('Calculating for C=%f and sigma=%f\n\n', C_i, sigma_i);
    model = svmTrain(X, y, C_i, @(x1, x2) gaussianKernel(x1, x2, sigma_i));
    err   = mean(double(svmPredict(model, Xval) ~= yval));
    if( err <= error_min )

      C = C_i;
      sigma = sigma_i;
      error_min = err;
      fprintf('\n\nFound a new min %f for  C=%f and sigma=%f\n\n',error_min, C_i, sigma_i);

    end

  end
end

fprintf('\n\nError min %f found for  C=%f and sigma=%f\n\n',error_min, C, sigma);
% =========================================================================

end
