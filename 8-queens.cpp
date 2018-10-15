#include <bits/stdc++.h>

using namespace std;
#define push_back pb
#define make_pair mp

vector<int> mutation(vector<int> array)				
{
	int d1 = rand()%8;						
	int d2 =rand()%8;
//to generate random 	

	while(d2 == d1);
	{
		d2 = rand()%8 ;
	}

	int temp = array[d2];							
	array[d2] = array[d1];
	array[d1] = temp;
	return array;									
}

vector<pair<int,vector<int>>> population(void)	
{
	vector<pair<int,vector<int>>> v;
	for (int k = 0; k<100; ++k){	
		vector<int> a;
		int b[8] = {0};							
		for(int i =0; i<8; i++){	
			int x = rand()%8;
			if(b[x] == 0){
				a.pb(x);
				b[x] = 1;
			}
			else	i--;
		}												

		pair<int,vector<int>> p = mp(check(a),a);	
		v.pb(p);							
	}
	
	return v;									
}



// function to check condition for 8 queen 
int check(vector<int> a)					
{
	int check = 0;
	for(int i =0; i<8; i++){
		for(int j = i+1; j<8;j++)
		{
			if((abs(a[j]-a[i]) == (j-i)))		
				check++;
		}
	}
	return check;								
}


int main()
{
	srand(time(0));									
	
	vector<pair<int,vector<int>>> v = population();	
	int counter =0;
	do
	{
		int a[101] = {0};
		vector<pair<int,vector<int>>> v1;
		for(int i = 0; i<5; i++)					
		{
			int x = rand()%100;
			if(a[x] == 0)
			{
				a[x] = 1;
				v1.pb(v[x]);
			}
			else
				i--;
		}

		sort(v1.begin(), v1.end());					
		vector<int> p1,p2;
		p1 = v1[0].second;
		p2 = v1[1].second;
		

		int cp = rand()%7+1;			
		
		vector<int> c1,c2;
		for(int i =0; i< cp; i++)		
		{
			c1.pb(p1[i]);
			c2.pb(p2[i]);
		}
		
		int j1 =cp, j2 = cp;	
		
		for(int i = cp;i<8;i++)			
		{
			while(find(c1.begin(), c1.end(), p2[j1]) != c1.end() )	
				j1 = (j1+1)%8;   
			c1.pb(p2[j1]);
			j1 = (j1+1)%8;

			while(find(c2.begin(), c2.end(), p1[j2]) != c2.end() )  
				j2 = (j2+1)%8;   
			c2.pb(p1[j2]);
			j2 = (j2+1)%8; 
		}
		

		int do_mutation = rand()%100;	// to select random 2 rows from 100 				
		if(do_mutation<80)
		{
			c1 = mutation(c1);
		}
		
		do_mutation = rand()%100;						
		if(do_mutation<80)
		{
			c2 = mutation(c2);
		}

		pair<int,vector<int>> p = mp(penalty(c1),c1);	

		sort(v.begin(), v.end());
		int pos = upper_bound(v.begin(), v.end(), p) - v.begin();	
		if(pos != 99)	v[pos] = p;									

		p = mp(penalty(c2),c2);							
		pos = upper_bound(v.begin(), v.end(), p) - v.begin();	
		if(pos != 99)	v[pos] = p;								
		
		counter++;
	
	}while(v[0].first != 0 && counter <10000);					
		cout<<"Practise Assigment-1  8-queens problem "<<endl;
		cout << "Total population Size: 100"<< endl; 
		cout << "Recombination probability: 100%" << endl;
		
		cout << "Randomly selection: Best 2 out of random 5"<< endl;
		
		cout << "Mutation probability: 80%" << endl; 
		cout << "Survival selection: Replace worst" << endl;
		if(v[0].first == 0)
			cout<<"Output after " << counter <<" number of generations!" << endl; 
		else
			cout <<"Could not achieve solution! "<< endl;

		for(int j =0; j<8; j++)
			cout <<(v[0].second)[j]<< " ";						
		


		cout<<"----->penalty: " << v[0].first << endl;	
}
