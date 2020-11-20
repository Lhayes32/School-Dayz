thing <- NULL
j <- 1

tmpFn <- function(xVec) {
	if(xVec < 0) {
		xVec <- ((xVec^2) + (2 * xVec) + 3)
	}
	if((xVec <= xVec) & (xVec < 2)){
		xVec <- xVec + 3
	}
	if(2 <= xVec){
		xVec <- ((xVec^2) + (4 * xVec) - 7)
	}

	return(xVec)
}

for(i in -3:3){	
	thing[j] <- tmpFn(i)
	j <- j + 1	
}

thing