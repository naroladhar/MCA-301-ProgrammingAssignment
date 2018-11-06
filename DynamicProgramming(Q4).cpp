#include <iostream>
using namespace std;
 int res(int*x , int *revenue , int n , int M) 
 {
    int table[M+1];
    table[0] = 0;
    int j = 0;
    for ( int i = 1 ; i <= M; i++) 
	{
        if( j < n) 
		{
            if( x[j] != i) 
			{
                table[i] = table[i-1];
            }
            else {
                if ( i <=5) 
				{
                    table[i] = max(table[i-1] , revenue[j]);
                 }
                else
				{
                	
                    table[i] = max(revenue[j] + table[i - 6] , table[i-1]);
                }
                j++;
            }
        }
        else {
            table[i] = table[i-1];
        }
    }
    return table[M];
}
 int main() 
 {
    int M , n,x[200],revenue[200];
    cout << "\nEnter M\t:\t";
    cin >> M;
    cout << "\nEnter n\t:\t";
    cin >> n;
    for ( int i = 0; i < n; i++)
	{
      cin >> x[i];
	}
    for ( int i = 0; i < n; i++ ) 
	{
      cin >> revenue[i];
    }
    cout << res( x , revenue , n , M);
    return 0;
}
