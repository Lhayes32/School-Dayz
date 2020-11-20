library(car)
scatterplotMatrix(~mpg+cyl+disp+drat+wt+qsec+vs, data=mtcars,
                  main="Three Cylinder Options") 


