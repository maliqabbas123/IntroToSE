#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<string>

using namespace std;

#define Rows 18
#define Cols 19

char Grid[Rows][Cols];

int loop = 10;
char grid[10][10];
string str[15];

void initializeGrid()
{
	for(int i=0;i<loop;i++)
    {
        for(int j=0;j<loop;j++)
        {
			grid[i][j] = '-';
		}
	}
}

void ReadFromFile()
{
	ifstream fin;
	fin.open("Input.txt");
	int count = 0;
	while(!fin.eof())
	{
		fin>>str[count]; 
		count++;	
	}
	fin.close();
}

void display(int n)
{
	if(n==1)
	{
		for(int i = 0 ; i<loop ; i++)
		{
			for(int j = 0; j < loop ; j++)
			{
				cout<<grid[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	if(n==0)
	{
		for(int i = 0 ; i<loop ; i++)
		{
			cout<<str[i];
			cout<<endl;
		}
	}

}

void sorting()
{
	string sort;
	for(int i = 0 ; i < loop-1 ; i++)
	{
		for(int j = i + 1 ; j < loop ; j++)
		{
			int len1 = 0 , len2 = 0;
			len1 =str[i].length();
			len2 =str[j].length();
			
			if(len1 < len2)   	
			{
				sort = str[i];
				str[i] = str[j];
				str[j] = sort;
			}
		}
	}
}

bool Diagonal(string inputword){
	int Row = 0 , Col = 0 , limit = 0;
	bool test = false;
	limit = (11 - inputword.length());
	Row = rand() % limit;
	Col = rand() % limit;
	int temp = Col , temp2 = Row , temp3 = 0;
	while(temp3 < inputword.length())
	{
		if(inputword[temp3] == grid[temp2][temp])
		{
			test = true;
		}
		else if(grid[temp2][temp] == '-')
		{
			test = true;
		}
		else
		{
			test = false;
		}
		temp++;
		temp2++;
		temp3++;
	}
	
	if(test != 0)
	{
		for(int i=0; inputword[i] != '\0'; i++, Row++, Col++)
		{
			grid[Row][Col] = inputword[i];	
		}
	}
	
	return test;
}

bool Horizontal(string inputword){
	
	int Row = 0 , Col = 0 , limit = 0;
	bool test = false;
	limit = (11 - inputword.length());
	Col = rand() % limit;
	Row = rand() % 10;
	
	int temp1 = Col , temp2 = 0;
	while(temp2 < inputword.length())
	{
		if(inputword[temp2] == grid[Row][temp1])
		{
			test = true;
		}
		else if(grid[Row][temp1] == '-')
		{
			test = true;
		}
		else
		{
			test = false;
		}
		temp1++;
		temp2++;
	}
	
	if(test != 0)
	{
		for(int i = 0 ; inputword[i] != '\0' ; i++)
		{
			grid[Row][Col] = inputword[i];
			Col++;	
		}
	}
	
	return test;
}

bool Vertical(string inputword ){
	
	int Row = 0 , Col = 0 , limit = 0;
	bool test = false;
	limit = (11 - inputword.length());
	
	Row = rand() % limit;
	Col = rand() % 10;
		
	int temp1 = Row , temp2 = 0  ;
	while(temp2 < inputword.length())
	{
		if(inputword[temp2] == grid[temp1][Col])
		{
			test = true;
		}
		else if(grid[temp1][Col] == '-')
		{
			test = true;
		}
		else
		{
			test = false;
		}
		temp1++;
		temp2++;
	}
	
	if(test != 0)
	{
		for(int i = 0 ; inputword[i] != '\0' ; i++)
		{
			grid[Row][Col] = inputword[i];
			Row++;	
		}
	}
	
	return test;
		
}

void Random()
{
	int put = 0;

	for(int i = 0 ; i < loop ; )
	{
		put = rand() % 3;
		if(put == 0)
		{
			if(Vertical(str[i]) == true)
			{
				i++;
			}
		}
		if(put == 2)
		{
			if(Diagonal(str[i]) == true)
			{
				i++;
			}
		}
		if(put == 1)
		{
			if(Horizontal(str[i]) == true)
			{
				i++;
			}
		}
	}
}

void GridSetter()
{
	for(int i = 0 ; i < loop ; i++)
	{	
		for(int j = 0 ; j < loop ; j++)
		{
			if(grid[i][j] == '-')
			{
			 	while(!(grid[i][j]>=97 && grid[i][j]<=122))
				{
						grid[i][j] = rand();
			    }
			}
		}
	}	
}

void Output()
{
	ofstream out("output.txt");
	for(int i = 0 ; i < loop ; i++)
	{
		for(int j = 0 ; j < loop ; j++)
		{
			out<<grid[i][j]<<" ";
		}
		out<<endl;
	}
	out.close();
}

void GridCreation()
{
	ReadFromFile();
	initializeGrid();
	cout<<"\n\ninitialized Grid is an under\n\n";
	display(1);
	cout<<"\n\nread from input is an under\n";
	display(0);
	sorting();
	Random();
	GridSetter();
	cout<<"\n\nFinal Grid is as under\n\n";
	display(1);
	Output();
}

void ReadDataFromFile()
{
	ifstream fin("Grid.txt"); 
		 		 		 
	for( int i = 0 ; i < Rows ; i++)
		{
			for(int j = 0 ; j < Cols ; j++)
			{
				fin>>Grid[i][j] ; 
			}
		}
	fin.close();
}

bool Horizontal( string str ,  ofstream& out){
	
	int len = 0;
	bool test = false; 
	len = str.length(); 
	
	for(int i = 0 ; i < Rows ; i++) 
	{
		for(int j = 0 ; j < Cols ; j++)
		{                                       
			if(Grid[i][j] == str[0])
			{
				int k = 1 ; 
				while(k < len)
				{
					if(Grid[i][j+k] != str[k]) 
					{
						test = false;
						break;
					}
					else
					{
						test = true;
					}
					k++;
				}
				
				if(test != false) 
				{
					out << endl << str << " FROM (" << i << ", " << j << ") TO (" << i << ", " << j + len - 1 << ") \n";	
					return test;
				}
			}
		}
	}
	return test;	
} 

bool reverseHorizontal(string str  , ofstream& out){
	
	int len = 0;
	bool test = false;  
	len = str.length();
	
	for(int i = 0 ; i < Rows ; i++ ) 
	{
		for(int j = Cols - 1 ; j >= 0 ; j--)  
		{
			if(Grid[i][j] == str[0]) 
			{
				int k = 1 ;
				while( k < len ) 
				{
					if(Grid[i][j-k] != str[k]) 
					{
						test = false;
						break;	
					}
					else
					{
						test = true;
					}
					k++;
				}
				
				if(test != false) 
				{
					out << endl << str << " FROM (" << i << ", " << j << ") TO (" << i << ", " << j - len + 1 << ") \n";	
					return test;
				}
			}
		}
	}
	
	return test;
}   

bool Vertical( string str , ofstream& out){
	int len = 0;
	bool test = false;
	len = str.length();
	
	for(int i = 0 ; i < Cols ; i++)
	{
		for(int j = 0 ; j < Rows ; j++)
		{
			if(Grid[i][j] == str[0])
			{
				int k = 1 ;
				while( k < len )
				{
					if(Grid[i + k][j] != str[k]) 
					{
						test = false;
						break;
					}
					else
					{
						test = true;
					}
					k++;
				}
				
				if(test != false)
				{
					out << endl << str << " FROM (" << i << ", " << j << ") TO (" << i + len - 1 << ", " << j << ")\n";	
					return test;
				}
			}
		}
	}

	return test;
}

bool reverseVertical( string str , ofstream& out){
	
	int len = 0;
	bool test = false;
	len = str.length();
	
	for(int i = 0 ; i < Cols ; i++)
	{
		for(int j = Rows - 1 ; j >= 0 ; j--)
		{
			if(Grid[i][j] == str[0])
			{
				int k = 1 ;
				while( k < len )
				{
					if(Grid[i - k][j] != str[k]) 
					{
						test = false;
						break;
					}
					else
					{
						test = true;
					}
					k++;
				}
				
				if(test != false)
				{
					out << endl << str << " FROM (" << i << ", " << j << ") TO (" << i - len + 1 << ", " << j << ")\n";	
					return test;
				}
			}
		}
	}
	
	return test;
}

bool DiagonalRight( string str , ofstream& out){
	
	int len = 0;
	bool test = false;
	len = str.length();
	
	for(int i = 0 ; i < Cols ; i++)
	{
		for(int j = 0 ; j < Rows ; j++)
		{
			if(Grid[i][j] == str[0])
			{
				int k = 1 ;
				while( k < len )
				{
					if(Grid[i + k][j + k] != str[k]) 
					{
						test = false;
						break;
					}
					else
					{
						test = true;
					}
					k++;
				}
				
				if(test != false)
				{
					out << endl << str << " FROM (" << i << ", " << j << ") TO (" << i + len - 1 << ", " << j + len - 1 << ")\n";	
					return test;
				}
			}
		}
	}
	
	return test;
	
}

bool DiagonalLeft( string str , ofstream& out){
	
	int len = 0;
	bool test = false;
	len = str.length();
	
	for(int i = 0 ; i < Cols ; i++)
	{
		for(int j = 0 ; j < Rows ; j++)
		{
			if(Grid[i][j] == str[0])
			{
				int k = 1 ;
				while( k < len )
				{
					if(Grid[i - k][j - k] != str[k])  
					{
						test = false;
						break;
					}
					else
					{
						test = true;
					}
					k++;
				}
				
				if(test != false)
				{
					out << endl << str << " FROM (" << i << ", " << j << ") TO (" << i - len + 1 << ", " << j - len + 1 << ")\n";	
					return test;
				}
			}
		}
	}
	
	return test;
	
}

void displayGrid(char arr[Rows][Cols])
{
	for(int i = 0 ; i < Rows ; i++)
            {
				for(int j = 0 ; j < Cols ; j++)
            	{
                	cout<<arr[i][j]<<" "; 
        		}
        		cout<<endl;
        	}
}

void checking(string WordsList[], int n)
{
	ofstream Write("Out.txt");
	bool check = 0 ,IsWord = 0;
	
	for(int counter = 0; counter < n ; counter++){
		
		check = false;  
		
		IsWord = Vertical( WordsList[counter] , Write);
		if(IsWord != false )
		{
			check = true;
		}
		
		IsWord = reverseVertical( WordsList[counter] , Write);
		if(IsWord != false )
		{
			check = true;
		}
		
		IsWord =  Horizontal( WordsList[counter], Write);
		if(IsWord != false )
		{
			check = true;
		}
		
		IsWord =  reverseHorizontal( WordsList[counter] , Write);
		if(IsWord != false )
		{
			check = true;
		}
		
		IsWord = DiagonalLeft( WordsList[counter] , Write);
		if(IsWord != false )
		{
			check = true;
		}
		
		IsWord = DiagonalRight( WordsList[counter] , Write);
		if(IsWord != false )
		{
			check = true;
		}		
	
		if(check != true && IsWord  != true ) 
		{
			cout<<endl;
			Write<<WordsList[counter]<<" No Such Word Found "<<" "; 
			cout<<WordsList[counter]<<" No Such Word Found "<<" "; 
		}
	}
	Write.close();
}

void WordSearch()
{
	ReadDataFromFile();	
				 
	displayGrid(Grid);
		
	int num = 0;
    cout<<"\n\nEnter number of Words you want to search\t";
	cin>>num;
	
	string ListofWords[num];
	
	for(int i = 0 ; i < num ; i++)
	{
		cout<<"\n\nEnter a word\t";
		cin>>ListofWords[i];	
	}		
		        	
	checking(ListofWords , num );


}

int main()
{
	char choice;
	cout<<"Press \nG for Creating Grid \nS for Searching Words From Grid \nQ for Quitting\n";
	cin>>choice;
	if(choice == 'G')
	{
		GridCreation();
		return 0;
	}
	else if(choice == 'S')
	{
		WordSearch();
		return 0;
	}
	else if(choice == 'Q')
	{
		cout<<"Quitting";
		return 0;
	}
	else
	{
		cout<<"Invalid Entry";
		return 0;
	}
	system("pause");
}
