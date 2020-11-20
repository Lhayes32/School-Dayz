sum <- 0

for(i in 1:20){
	for(j in 1:5){
		sum <- sum + ((i^4) / (3 + j))
	}
}

sum