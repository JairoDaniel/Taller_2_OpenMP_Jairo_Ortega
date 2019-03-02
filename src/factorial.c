
int factorial(int x){
	if(x==0)
		return 1;
	else if (x==1)
		return 1;
	else {
		int acc =1;
		while(x!=1){
			acc=acc*x;
			x--;
		}
		return acc;
	}
}