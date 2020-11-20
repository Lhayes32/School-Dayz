library(car)
scatterplotMatrix(~mpg+disp+drat+wt|cyl, data=mtcars,
                   main="Three Cylinder Options")



