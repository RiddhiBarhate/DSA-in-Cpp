int trailingZerosInFactorial(int n)
{
	if(n == 0)
		return 0;

	int count = 0;

	for(int i = 5; n/i > 0; i *= 5){
		count += n/i;
	}

	return count;
}