int counter;
bool sudoku_backtracking_recursive(int **sudoku);
bool sudoku_forwardchecking_recursive(int **sudoku);
bool sudoku_mrv_recursive(int **sudoku);
bool sudoku_forwardchecking_valid_board(int **sudoku);
bool sudoku_empty_location(int **sudoku,int *x,int *y);
bool sudoku_empty_location_mrv(int **sudoku,int *x,int *y);

int sudoku_backtracking(int **sudoku)
{
	// access the sudoku using "sudoku[y][x]"
	// y between 0 and 9
	// x between 0 and 9
	// function must return the number of permutations performed
	
	counter = 0;
	sudoku_backtracking_recursive(sudoku);
	return counter;
}

bool sudoku_backtracking_recursive(int **sudoku)
{
	counter++;
	int x,y;
	
	if(!sudoku_empty_location(sudoku,&x,&y))
	{
		return true;
	}

	for(int i=1;i<=9;i++)
	{
		if(can_yx_be_z(sudoku,y,x,i))
		{
			sudoku[y][x] = i;
			if(sudoku_backtracking_recursive(sudoku))
			{
				return true;
			}
			sudoku[y][x] = 0;
		}
	}
	return false;
}



int sudoku_forwardchecking(int **sudoku)
{
	// access the sudoku using "sudoku[y][x]"
	// y between 0 and 9
	// x between 0 and 9
	// function must return the number of permutations performed

	counter = 0;
	sudoku_forwardchecking_recursive(sudoku);
	return counter;
}

bool sudoku_forwardchecking_recursive(int **sudoku)
{
	counter++;
	int x,y,index;
	bool check,check2;
	
	if(!sudoku_empty_location(sudoku,&x,&y))
	{
		return true;
	}


	for(int i=1;i<=9;i++)
	{
		if(can_yx_be_z(sudoku,y,x,i))
		{
			sudoku[y][x] = i;
			if(sudoku_forwardchecking_valid_board(sudoku))
			{
				if(sudoku_forwardchecking_recursive(sudoku))
				{
					return true;
				}
			}
			sudoku[y][x] = 0;

		}
	}
	return false;
}

bool sudoku_forwardchecking_valid_board(int **sudoku)
{
	bool check = false;
	for(int col=0;col<9;col++)
	{
		for(int row=0;row<9;row++)
		{
			if(sudoku[col][row]==0)
			{
				check = false;
				for(int z=1;z<=9;z++)
				{
					if(can_yx_be_z(sudoku,col,row,z))
						{ 
							check = true; 
						}
				}
				if(check == false)
				{ 
					return false; 
				}
			}
		}
	}
	return true;
}

bool sudoku_empty_location(int **sudoku,int *x,int *y)
{
	for(int j=0;j<9;j++)
	{
		for(int i=0;i<9;i++)
		{
			if(sudoku[j][i]==0)
			{
				*x = i;
				*y = j;
				return true;
			}
		}
	}
	return false;
}

int sudoku_mrv(int **sudoku)
{
	// PUT YOUR CODE HERE
	// access the sudoku using "sudoku[y][x]"
	// y between 0 and 9
	// x between 0 and 9
	// function must return the number of permutations performed

	counter = 0;
	sudoku_mrv_recursive(sudoku);
	return counter;
}

bool sudoku_mrv_recursive(int **sudoku)
{
	counter++;
	int x,y;
	
	if(!sudoku_empty_location_mrv(sudoku,&x,&y))
	{
		return true;
	}

	for(int i=1;i<=9;i++)
	{
		if(can_yx_be_z(sudoku,y,x,i))
		{
			sudoku[y][x] = i;
			if(sudoku_forwardchecking_valid_board(sudoku))
			{
				if(sudoku_mrv_recursive(sudoku))
				{
					return true;
				}
			}
			sudoku[y][x] = 0;
		}
	}
	return false;
}


bool sudoku_empty_location_mrv(int **sudoku,int *x,int *y)
{
	int minx,miny,count,mincount = 100;
	for(int j=0;j<9;j++)
	{
		for(int i=0;i<9;i++)
		{
			if(sudoku[j][i]==0)
			{
				count = 0;
				for(int z=1;z<=9;z++)
				{
					if(can_yx_be_z(sudoku,j,i,z))
					{
						count++;
					}
				}
				if(count<mincount)
				{
					minx = i;
					miny = j;
					mincount = count;
				}
			}
		}
	}
	if(mincount==100)
	{
		return false;
	}
	else
	{
		*x = minx;
		*y = miny;
		return true;
	}
}









// bool all_domains[279] = {false};
// bool all_domains_copy[279] = {false};

	// for(int k=0;k<279;k++)
	// {
	// 	all_domains[k] = false;
	// }

	// int index;
	// for(int j=0;j<9;j++)
	// {
	// 	for(int i=0;i<9;i++)
	// 	{
	// 		if(sudoku[j][i]==0)
	// 		{
	// 			index = 9*(9*j+i);
	// 			for(int z=1;z<=9;z++)
	// 			{
	// 				if(can_yx_be_z(sudoku,j,i,z))
	// 				{
	// 					all_domains[index+z-1] = true;
	// 				}
	// 			}
	// 		}
	// 	}
	// }




// memcpy(all_domains, all_domains_copy, sizeof(all_domains));
			// for(int k=0;k<9;k++)
			// {
			// 	all_domains[9*(9*y+k)+i-1] = false;
			// 	all_domains[9*(9*k+x)+i-1] = false;
			// 	all_domains[9*(9*((y/3)*3+k/3)+((x/3)*3+k%3))+i-1] = false;
			// }

			// check2 = true;
			// for(int col=0;col<9;col++)
			// {
			// 	for(int row=0;row<9;row++)
			// 	{
			// 		if(sudoku[col][row]==0)
			// 		{
			// 			index = 9*(9*col+row);
			// 			check = false;
			// 			for(int z=1;z<=9;z++)
			// 			{
			// 				if(all_domains[index+z-1] == true)
			// 					{check = true;}
			// 			}
			// 			if(check==false)
			// 				{check2 = false;}
			// 		}
			// 	}
			// }
			// if(check2)
			// {
			// 	if(sudoku_backtracking_recursive(sudoku))
			// 	{
			// 		return true;
			// 	}
			// }
			// sudoku[y][x] = 0;
			// memcpy(all_domains_copy, all_domains, sizeof(all_domains_copy));





