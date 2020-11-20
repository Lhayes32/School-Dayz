x1 <- runif(100, 0, 1000)

arr1 <- array(x1, dim=c(1, 100, 1))



for(i in 1:length(arr1)) {
	j <- i
	while( j > 1 && arr1[j - 1] > arr1[j] )
	{
		b <- arr1[j-1]
		arr1[j-1] <- arr1[j]
		arr1[j] <- b
		j <- j - 1
	}
}

arr1