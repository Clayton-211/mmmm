#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	cout<<"enter how many student in a class ";
	cin>>num;
	
	int rollno[num];
	cout<<"enter roll no of all "<<num<<" students";
	int i;
	for(i=0;i<num;i++)
	{
		cin>>rollno[i];
	}
	cout<<"present students are: ";
	for(i=0;i<num;i++)
	{
		cout<<rollno[i]<<" ";
	}
	
	int x;
	char ch;
	do
	{
		
	cout<<"enter a roll no that you want check: ";
	cin>>x;
	
	for(i=0;i<num;i++)
	{
		if(rollno[i]==x)
		{
			cout<<"is present";
			break;
		}
		
	}
	if(i==num)
	{
		cout<<"is absent";
	}
	cout<<"\n"<<"do u want to continue y or n : ";
	cin>>ch;
	
}while(ch=='y');
	

    cout<<"binary search";
    int n;
    cout<<"\nenter how many student in a class ";
	cin>>n;
	
    int arr[n];
    cout<<"enter roll no of all student: ";
    
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"present student in sorted order are: ";
	sort(arr,arr+n);
	for(i=0;i<n;i++)
	{   
		cout<<arr[i]<<" ";
	}
	
	int start=0,mid,key;
	int end=n-1;
	int match=0;
	
char what;
	do{
	    
	    cout<<"\nenter the roll no you want to search ";
	    cin>>key;
	    while(start<=end)
		{
	        mid=(start+end)/2;
	        if(arr[mid]==key)
			{
	            match=1;
	            break;
	         
	        }
	        else if(key<arr[mid])
			{
	            end=mid-1;   
	        }
	        else
			{
	            start=mid+1;
	        }
	        
	        
	    }
	    if(match==1)
		{
	        cout<<"student is present\n";
	    }
	    else
		{
	        cout<<"student is absent\n";
	    }
	    
	    cout<<"do you want to check again(y/n) ";
	    
	    cin>>what;
	} while(what == 'y');
	
	return 0;
	
}	
